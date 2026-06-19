# Blocker Summary

Last updated: 2026-03-14

This document catalogs the root-cause blockers preventing further progress on the Ruffle AVM1 test suite. Each blocker maps to one or more plans in `blocked/`.

---

## Active Blockers

### ~~Blocker 1: Font Metrics / Text Layout Accuracy~~ — RESOLVED

**Resolved 2026-03-14.** All font metrics tests now pass (TEXTFIELD_PLAN complete, 62/62). Key fixes:
1. Preserve `_tf_leading` from `setTextFormat`/`setNewTextFormat` when `htmlText` is set (don't overwrite with HTML-parsed default)
2. Include line terminator character's font height in per-line max (matching Ruffle's `newspan()` before `fixup_line()`)
3. Skip trailing empty line from text height calculation (matching Ruffle's `is_line_empty && last_line` skip)
4. Per-line font height tracking, word wrap improvements, tab stop indent handling (edittext_scroll, edittext_newlines, edittext_tab_stops)

| Test | Match | Lines Off |
|------|-------|-----------|
| edittext_bullet | 30/30 | 0 |
| edittext_scroll | 54/54 | 0 |
| edittext_newlines | 30/30 | 0 |
| edittext_tab_stops | 60/60 | 0 |

---

### ~~Blocker 2: SWF6 HTML Paragraph Semantics~~ — RESOLVED

**Resolved 2026-03-14.** SWF≤6 non-multiline mode already preserved paragraph breaks like multiline, but the HTML serializer's trailing marker emission (empty `<B></B>`, `<FONT COLOR="..."></FONT>` runs) and empty paragraph font attribute inheritance were gated on `is_multiline` only. Changed three conditions to `(is_multiline || swf_version < 7)`.

| Test | Match | Lines Off |
|------|-------|-----------|
| edittext_html_swf6 | 5377/5377 | 0 |

---

### ~~Blocker 3: Heap-Allocated Activation Scopes (Closure Variable Capture)~~ — RECLASSIFIED

**Reclassified 2026-03-15.** The test previously attributed to this blocker (`coerce_to_object_monkeypatch`) does NOT actually fail due to closure variable capture. The addProperty getter closures in that test **work correctly** — the failures are due to:
1. `actionNewObject` constructor lookup skipping `__proto__` chain addProperty getters (~3 lines)
2. Failed auto-boxing falling back to root MovieClip instead of `_global` (~55 lines, cascade)

These were fixed without architecture changes. See `complete/COERCE_TO_OBJECT_MONKEYPATCH.md` for details.

**General blocker remains valid** for other patterns: our stack-based variable storage does mean local variables are lost after function return. Any test with closures that capture outer locals (the `addGetter` pattern below) would fail. However, no current failing test is blocked by this.

```actionscript
function addGetter(obj, name, val) {
    obj.addProperty(name, function() { return val; }, null);
    // 'val' must survive after addGetter returns — ours returns undefined
}
```

**Potential path via upstream merge:** Upstream's `feature/objects-and-functions` PR ([SWFModernRuntime PR #3](https://github.com/SWFRecomp/SWFModernRuntime/pull/3)) implements activation scopes as heap-allocated `ASObject*` ([line 21](https://github.com/PeerInfinity/SWFModernRuntime/blob/96f3ac8/src/actionmodern/action.c#L21), [lines 52-55](https://github.com/PeerInfinity/SWFModernRuntime/blob/96f3ac8/src/actionmodern/action.c#L52-L55)). Currently pre-allocated in a static 16-slot array (reused by depth). **Update (March 17):** LittleCube added concurrent GC with cycle detection (`f02311c`) — refcounting is now integrated into stack operations (PUSH_OBJ retains, POP releases). Per-call scope allocation is still needed for closure capture, but the refcounting/freeing foundation is in place. See `SWFRecompDocs/merge/upstream-downstream-merge-plan-2024-12.md` (March 2026 updates).

| Test | Match | Lines Off | Actual Blocker |
|------|-------|-----------|----------------|
| coerce_to_object_monkeypatch | **129/129** | **0** | **FIXED** (eac9ba9f) — constructor lookup + `this` fallback |

**Plans affected**: TYPE_COERCION_ADVANCED_PLAN — completed, plan in `complete/`

---

### ~~Blocker 4: Global Constructor Enumeration Order + Missing Globals~~ — RESOLVED

**Resolved 2026-04-02.** Ruffle vs Flash difference reclassified; Flash-spec baselines created. All 3 global_*_decls tests now pass via `--expected-suffix=flash`. Ruffle versions moved to `ignored_tests.txt`. See `complete/GLOBALS_PLAN.md` and `complete/GLOBALS_ALIGNMENT_PLAN.md`.

**Impact**: 3 tests, ~11,000+ lines (but low value — tests enumerate all globals)

Tests `global_proto_decls`, `global_proto_decls_delete`, and `global_instance_decls` enumerate every global object and its properties via `for-in`. Key remaining issues:

1. ~~**constructor DONT_ENUM conflict**~~ — **RECLASSIFIED (2026-04-01)** as a Ruffle vs Flash difference, not a fixable flag issue. Ruffle makes Object.prototype methods ENUMERABLE by default (Flash uses DONT_ENUM). Ruffle also sets `constructor` as an own property on all objects (Flash inherits it). See `RUFFLE_VS_FLASH_DIFFERENCES.md`. This accounts for ~550+ lines per test of permanent Ruffle-specific mismatch.
2. **flash.* constructor own_props order** — Some flash.automation constructors expect different property insertion orders, causing cascading misalignment in proto_decls_delete
3. **Missing properties** — Key constants (20), Mouse/Accessibility methods, StageCapture.prototype methods, Object.prototype.constructor, Function.prototype apply/call
4. ~~**registerGeomMethod function_registry pollution**~~ (global_instance_decls) — **FIXED** (79f6c1c2). Prototype methods (Rectangle.contains) were shadowing user-defined functions in lookupFunctionByName. Test's `contains` helper now works correctly. Remaining gaps: missing DONT_DELETE on instance __proto__, missing instance-specific properties

**Progress (2026-04-01, session 4):** AsBroadcaster shared functions now have own_props + selective prototype creation. global_proto_decls improved 552→742 lines.

| Test | Match | Lines Off |
|------|-------|-----------|
| global_proto_decls | ~742/4497 | ~3755 |
| global_proto_decls_delete | ~287/4158 | ~3871 |
| global_instance_decls | 23/758 | ~735 |

**Plans blocked**: GLOBALS_PLAN (Phases 8c-4 through 8d)

---

### Blocker 5: Pixel-Level Shape Hit Testing — **RESOLVED (accepted diffs)**

**Impact**: 1 test, 9 accepted diff lines (329/338 pass)

`movieclip_hittest_shapeflag` tests shape-accurate hit testing. All 4 VECTOR_PATH_HITTEST_PLAN phases complete: path data emission, fill winding number, stroke distance, morph interpolated paths. Remaining 9 diffs are permanent (Noto Sans vs Flash fonts 7 lines, morph boundary precision 1 line, Drawing API tessellation 1 line). Added to ACCEPTED_DIFFS.md and ignored_tests.txt.

| Test | Match | Lines Off |
|------|-------|-----------|
| movieclip_hittest_shapeflag | 329/338 | 9 (accepted) |

**Plans completed**: VECTOR_PATH_HITTEST_PLAN (moved to complete/)

---

### Blocker 6: LoadMovie Remaining Gaps

**Impact**: ~2 tests blocked on image loading or sandbox types

Core loadMovie infrastructure is complete (35/37 tests pass). Remaining gaps:

| Gap | Tests | Status |
|-----|-------|--------|
| Image decoding via loadMovie | movieclip_state_values (39/114) | Infeasible in NO_GRAPHICS — in ACCEPTED_DIFFS |
| Remote sandbox type | sandbox_type_remote (1/3) | Needs multi-SWF with remote sandbox |

**Resolved 2026-03-14:**
- ~~Shape bounds in NO_GRAPHICS~~ — movieclip_invalid_get_bounds_6/7 now 10/10 each. Fix: include child SWF transform_data in movie wrappers, cache transforms on DisplayObject at placement time, getBounds fallback scans root display_list for child movie entries.
- ~~`convertString` signature regression~~ — NOT A REAL BLOCKER. Multi-SWF tests pass (register_class 66/66, mcl_events_swf_version 232/232). `convertString` is purely internal to action.c.

**Plans blocked**: LOADMOVIE_MULTI_SWF_PLAN (image loading), LOADMOVIE_REMAINING_PLAN (sandbox)

---

### Blocker 7: Network / External Infrastructure

**Impact**: ~30 tests in `ignored_tests.txt`

Tests requiring HTTP requests, file dialogs, audio/video streaming, or browser JavaScript bridge. Not implementable in NO_GRAPHICS trace-only mode without major infrastructure additions.

| Category | Tests | Examples |
|----------|-------|---------|
| FileReference | 8 | file_reference_browse_cancel, file_reference_upload_success |
| Sound loading | 5 | sound_id3, sound_load_start |
| NetConnection/NetStream | 5 | netstream_play_flv, netconnection_close |
| HTTP form/load | 5 | form_loader_encoding_*, load_vars, stylesheet_load |
| getURL | 1 | geturl (POST parameters) |
| LocalConnection | 1 | localconnection (579 lines, full protocol) |

**Plans blocked**: IGNORED_INFRASTRUCTURE_TESTS

---

### Blocker 8: TextField Clone Property Accessors — RESOLVED

**Resolved 2026-03-14.** Three fixes:
1. `_alpha` quantization through 8.8 fixed-point (Flash stores alpha as int16, not raw float)
2. StyleSheet setter resets `hscroll=0` and `scroll=1` when a stylesheet is assigned
3. Device font name: `tf_get_defaults` now skips builtin Noto Sans fallback (font_id=0) and keeps "Times New Roman" default for device fonts

| Test | Match | Lines Off | Notes |
|------|-------|-----------|-------|
| clone_sprite_edittext | 94/94 | 0 | **PASS** |
| clone_sprite_edittext_dynamic | 79/86 | 7 | All 7 diffs are pre-existing textfield autoSize/dimension bugs on ORIGINAL textfield, not clone-specific |

**Plans blocked**: None (CLONE_DUPLICATE_PLAN moved to `complete/`; remaining diffs tracked under TEXTFIELD_PLAN)

---

### Blocker 9: Duplicate onPress Dispatch

**Impact**: 1 test, 4 extra lines

`string_paths_eval` fires `onPress` handler twice (from both clip event and AS2 handler paths), producing 8 lines of output instead of 4.

**Plans blocked**: TELLTARGET_PLAN (1 remaining test)

---

### Blocker 10: Display-list child name vs `var x=` timeline variable are conflated

**Impact**: 1 test (`sound_setters`), and any test that renames a clip held in a
same-named local variable.

**Root cause (diagnosed 2026-06-19).** In Flash there are *two independent*
bindings for a created clip:
1. the **display-list child** (looked up by current instance name) — it *moves*
   when you set `mc._name`;
2. the **timeline variable** created by an explicit `var mc = ...` assignment —
   it holds a reference and is *untouched* by a rename.

`sound_setters` does `var mc = createEmptyMovieClip("mc", 1); new Sound(mc)`. The
Sound captures the path `_level0.mc`. The test then renames the clip to
`"changed"`, mutates volume/pan/transform, renames back to `"mc"`, and expects the
mutations to have taken effect (the Sound stays bound to the clip via the
surviving `var mc`). A control case in the same test uses
`var mcr = createEmptyMovieClip("mc2", 2)` (var name ≠ instance name) and expects
the rename-period mutations *not* to persist — because there is no variable
`mc2`, only the display-list child that moved away.

Our runtime conflates the two: `createEmptyMovieClip` registers the clip in
**both** `parent->dynamic_props[name]` *and* `var_map[name]`
(`action.c` ~66450-66516), and the `_name` setter clobbers **both** old-name
entries to `undefined` on rename (`action.c` ~47346-47393). That clobber destroys
the user's `var mc`, so the later `mc._name = "mc"` is a no-op on `undefined` and
the clip is never restored → `getVolume()` returns `undefined` for the rest of the
test.

**Why it's not a quick fix.** The clobber is load-bearing for
`from_gnash/misc-swfc.all/soft_reference_test1` (expects `typeof(oldname) ==
'undefined'` after a rename), gnash `case-v6` (case-insensitive name table), and
the gnash `MovieClip-vN` soft-reference suite — all currently `ruffle_matched`.
The correct fix is to stop `createEmptyMovieClip` from registering a *variable*
(it should only create a display-list-child binding, resolved via `dynamic_props`
with a GetVariable fallback) and to stop the rename from clobbering `var_map`.
That is an architectural change to instance-vs-variable binding that touches many
tests and cannot be validated locally (full-suite, multi-suite). Deferred until it
can be done behind a full CI run. Single test, no `output.ruffle.txt`, so only a
full Flash PASS counts.

**Plan**: `blocked/INSTANCE_NAME_VS_VARIABLE_BINDING_PLAN.md` (3 phases: stop
instance-name auto-registration in `var_map`; fix the `_name` setter to not
clobber `var_map` and delete-not-undef the moved `dynamic_props` key; validate via
full CI).

---

## Resolved Blockers

| Blocker | When | Key Result |
|---------|------|------------|
| TextField clone property accessors (#8) | 2026-03-14 | clone_sprite_edittext 94/94 PASS; dynamic 79/86 (remaining = autoSize bugs) |
| SWF6 HTML paragraph semantics (#2) | 2026-03-14 | edittext_html_swf6 5377/5377 PASS |
| Font metrics / text layout accuracy (#1) | 2026-03-14 | edittext_bullet 30/30 PASS |
| Per-movie `_global` isolation | 2026-03-10 | CANCELLED — Ruffle shares `_global` |
| MTASC class / recompiler infra | 2026-03-07 | All tests pass |
| MC removal lifecycle / call() | 2026-03-05 | All tests pass |
| condenseWhite sentinels | 2026-03-12 | Both tests pass |
| StyleSheet CSS parser | 2026-03-04 | edittext_stylesheet 325/325 |
| swf*_global_funcs parsing | 2026-03-03 | All 3 tests pass |
| Dynamic object focus | 2026-03-13 | focus_mouse_focusable 8/8 PASS |

---

## Plans by Directory

### `complete/` — All planned work done

| Plan | Tests | Pass Rate | Resolution |
|------|-------|-----------|------------|
| TEXTFIELD_PLAN | 62 | **62/62** | All 7 phases done; font metrics fixed (edittext_scroll 54/54, edittext_newlines 30/30, edittext_tab_stops 60/60) |
| HTML_TEXT_REMAINING_WORK | 10 | **10/10** | All HTML text tests PASS (SWF6 fixed 2026-03-14) |
| CLONE_DUPLICATE_PLAN | 8 | **7/8** | Clone infrastructure complete; 7 remaining lines = textfield autoSize bugs |
| MOVIECLIP_PLAN | 54 | **49/54** | All 10 phases done; remaining 5 tests blocked on loadMovie/image loading |

### `blocked/` — Genuinely blocked, no actionable steps

| Plan | Tests | Pass Rate | Primary Blocker |
|------|-------|-----------|----------------|
| TYPE_COERCION_ADVANCED_PLAN | 2 | 1/2 | ~~Closure capture (Blocker 3)~~ Reclassified — constructor lookup + `this` fallback (actionable) |
| GLOBALS_PLAN | 31 | 28/31 | Enumeration order + missing globals (Blocker 4) |
| HIT_TESTING_PLAN | 17 | 13/17 | Pixel shape testing (Blocker 5) |
| BITMAP_DATA_PLAN | 17 | 15/17 | Premultiply precision, PRNG mismatch, filter clone crash |
| LOADMOVIE_MULTI_SWF_PLAN | 17 | 14/17 | Image loading + network (Blocker 6) |
| LOADMOVIE_REMAINING_PLAN | 5 | 3/5 | Image loading (Blocker 6), accepted diffs |
| IGNORED_INFRASTRUCTURE_TESTS | 23 | 0/23 | Network/external infra (Blocker 7) |
| TELLTARGET_PLAN | 22 | 19/22 | Duplicate onPress (Blocker 9), 2 accepted/ignored |
| UNCOVERED_SMALL_TESTS_PLAN | 19 | 13/19 | 0 actionable; 6 blocked on external features |
