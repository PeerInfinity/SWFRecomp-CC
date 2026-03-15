# Blocker Summary

Last updated: 2026-03-14

This document catalogs the root-cause blockers preventing further progress on the Ruffle AVM1 test suite. Each blocker maps to one or more plans in `blocked/`.

---

## Active Blockers

### ~~Blocker 1: Font Metrics / Text Layout Accuracy~~ — RESOLVED

**Resolved 2026-03-14.** Three fixes:
1. Preserve `_tf_leading` from `setTextFormat`/`setNewTextFormat` when `htmlText` is set (don't overwrite with HTML-parsed default)
2. Include line terminator character's font height in per-line max (matching Ruffle's `newspan()` before `fixup_line()`)
3. Skip trailing empty line from text height calculation (matching Ruffle's `is_line_empty && last_line` skip)

| Test | Match | Lines Off |
|------|-------|-----------|
| edittext_bullet | 30/30 | 0 |

---

### ~~Blocker 2: SWF6 HTML Paragraph Semantics~~ — RESOLVED

**Resolved 2026-03-14.** SWF≤6 non-multiline mode already preserved paragraph breaks like multiline, but the HTML serializer's trailing marker emission (empty `<B></B>`, `<FONT COLOR="..."></FONT>` runs) and empty paragraph font attribute inheritance were gated on `is_multiline` only. Changed three conditions to `(is_multiline || swf_version < 7)`.

| Test | Match | Lines Off |
|------|-------|-----------|
| edittext_html_swf6 | 5377/5377 | 0 |

---

### Blocker 3: Heap-Allocated Activation Scopes (Closure Variable Capture)

**Impact**: 1 test, ~109 lines. **NOT FEASIBLE** to fix.

Our runtime uses stack-based variables. When an inner function captures an outer function's local variable, the variable is gone after the outer function returns. Flash/Ruffle use heap-allocated activation records that persist as long as any closure references them.

```actionscript
function addGetter(obj, name, val) {
    obj.addProperty(name, function() { return val; }, null);
    // 'val' must survive after addGetter returns — ours returns undefined
}
```

Fixing requires a fundamental rewrite of the variable storage model.

| Test | Match | Lines Off |
|------|-------|-----------|
| coerce_to_object_monkeypatch | ~20/129 | ~109 |

**Plans blocked**: TYPE_COERCION_ADVANCED_PLAN

---

### Blocker 4: Global Constructor Enumeration Order + Missing Globals

**Impact**: 3 tests, ~11,000+ lines (but low value — tests enumerate all globals)

Tests `global_proto_decls`, `global_proto_decls_delete`, and `global_instance_decls` enumerate every global object and its properties via `for-in`. Key remaining issues:

1. **constructor DONT_ENUM conflict** — `constructor` on built-in prototypes is DONT_ENUM in our code but expected ENUMERABLE; making it ENUMERABLE breaks 7+ passing tests
2. **flash.* constructor own_props order** — Some flash.automation constructors expect different property insertion orders, causing cascading misalignment in proto_decls_delete
3. **Missing properties** — Key constants (20), Mouse/Accessibility methods, StageCapture.prototype methods, Object.prototype.constructor, Function.prototype apply/call
4. ~~**registerGeomMethod function_registry pollution**~~ (global_instance_decls) — **FIXED** (79f6c1c2). Prototype methods (Rectangle.contains) were shadowing user-defined functions in lookupFunctionByName. Test's `contains` helper now works correctly. Remaining gaps: missing DONT_DELETE on instance __proto__, missing instance-specific properties

**Progress (2026-03-14, 20b44c31):** Fixed `actionDelete` for ASFunction (was silently succeeding), added DONT_DELETE on built-in prototype/constructor props, created prototype_obj + own_props for all flash.* stub constructors. global_proto_decls improved 77→82 lines, global_instance_decls improved 1→4 lines.

| Test | Match | Lines Off |
|------|-------|-----------|
| global_proto_decls | 82/4487 | ~4405 |
| global_proto_decls_delete | 47/4115 | ~4068 |
| global_instance_decls | 4/760 | ~756 |

**Plans blocked**: GLOBALS_PLAN (Phases 8c-4 through 8d)

---

### Blocker 5: Pixel-Level Shape Hit Testing

**Impact**: 1 test, ~29 lines

`movieclip_hittest_shapeflag` tests shape-accurate hit testing (not just bounding box). Our triangulation approach has edge cases: stroke precision, curve approximation, device-font text, morph complex shapes.

**Progress (2026-03-14):** Fixed clip-depth masking (2 lines), setMask masking (1 line), added glyph-level text hit testing (no visible effect — device fonts). Reduced from 32 → 29 diff lines.

Remaining categories: device-font text (11 lines — no font outline data in SWF), curve/stroke precision (10 lines — triangulation approximation), drawing API bounds (4 lines), stroke-only morphs (4 lines).

| Test | Match | Lines Off |
|------|-------|-----------|
| movieclip_hittest_shapeflag | ~309/338 | ~29 |

**Plans blocked**: HIT_TESTING_PLAN

---

### Blocker 6: LoadMovie Remaining Gaps

**Impact**: ~4 tests blocked on image loading, sandbox types, or shape bounds in NO_GRAPHICS mode

Core loadMovie infrastructure is complete (33/35 tests pass). Remaining gaps:

| Gap | Tests | Status |
|-----|-------|--------|
| Image decoding via loadMovie | movieclip_state_values (39/114) | Infeasible in NO_GRAPHICS — in ACCEPTED_DIFFS |
| Remote sandbox type | sandbox_type_remote (1/3) | Needs multi-SWF with remote sandbox |
| Shape bounds in NO_GRAPHICS | movieclip_invalid_get_bounds_6/7 (9/10 each) | Need child SWF shape data after load |
| `convertString` signature regression | All multi-SWF tests | Pre-existing compile failure in multi-SWF builds |

**Plans blocked**: LOADMOVIE_MULTI_SWF_PLAN, LOADMOVIE_REMAINING_PLAN, HIT_TESTING_PLAN

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

### Blocker 8: TextField Clone Property Accessors

**Impact**: 2 tests, ~165 lines

When a TextField is cloned via `duplicateMovieClip`, the clone's MC doesn't have TextField property accessors wired up (`multiline`, `password`, `text`, `textColor`, `autoSize`, etc. all return `undefined`).

| Test | Match | Lines Off |
|------|-------|-----------|
| clone_sprite_edittext | ~26/94 | ~137 |
| clone_sprite_edittext_dynamic | ~52/86 | ~69 |

**Plans blocked**: CLONE_DUPLICATE_PLAN (Phase 2)

---

### Blocker 9: Duplicate onPress Dispatch

**Impact**: 1 test, 4 extra lines

`string_paths_eval` fires `onPress` handler twice (from both clip event and AS2 handler paths), producing 8 lines of output instead of 4.

**Plans blocked**: TELLTARGET_PLAN (1 remaining test)

---

## Resolved Blockers

| Blocker | When | Key Result |
|---------|------|------------|
| SWF6 HTML paragraph semantics | 2026-03-14 | edittext_html_swf6 5377/5377 PASS |
| Font metrics / text layout accuracy | 2026-03-14 | edittext_bullet 30/30 PASS |
| Per-movie `_global` isolation | 2026-03-10 | CANCELLED — Ruffle shares `_global` |
| MTASC class / recompiler infra | 2026-03-07 | All tests pass |
| MC removal lifecycle / call() | 2026-03-05 | All tests pass |
| condenseWhite sentinels | 2026-03-12 | Both tests pass |
| StyleSheet CSS parser | 2026-03-04 | edittext_stylesheet 325/325 |
| swf*_global_funcs parsing | 2026-03-03 | All 3 tests pass |
| Dynamic object focus | 2026-03-13 | focus_mouse_focusable 8/8 PASS |

---

## Plans by Directory

### `blocked/` — Genuinely blocked, no actionable steps

| Plan | Tests | Pass Rate | Primary Blocker |
|------|-------|-----------|----------------|
| TEXTFIELD_PLAN | 62 | 58/62 | Font metrics (Blocker 1, resolved) + SWF6 HTML (Blocker 2, resolved) |
| HTML_TEXT_REMAINING_WORK | 10 | 10/10 | RESOLVED — SWF6 HTML serialization (Blocker 2) |
| TYPE_COERCION_ADVANCED_PLAN | 2 | 1/2 | Closure capture (Blocker 3) |
| GLOBALS_PLAN | 31 | 28/31 | Enumeration order + missing globals (Blocker 4) |
| HIT_TESTING_PLAN | 17 | 12/17 | Pixel shape testing (Blocker 5) + loadMovie (Blocker 6) |
| LOADMOVIE_MULTI_SWF_PLAN | 2 | 0/2 | Image loading + convertString regression (Blocker 6) |
| LOADMOVIE_REMAINING_PLAN | 5 | 3/5 | Image loading (Blocker 6), accepted diffs |
| IGNORED_INFRASTRUCTURE_TESTS | 29 | 0/29 | Network/external infra (Blocker 7) |
| CLONE_DUPLICATE_PLAN | 8 | 5/8 | TextField clone accessors (Blocker 8) |
| TELLTARGET_PLAN | 22 | 19/22 | Duplicate onPress (Blocker 9), 2 accepted/ignored |

### `incomplete/` — Have actionable work remaining

| Plan | Tests | Pass Rate | Next Step |
|------|-------|-----------|-----------|
| MOVIECLIP_PLAN | 54 | 43/54 | Phase 10: AS-level event dispatch + ordering |
| BITMAP_DATA_PLAN | 17 | 8/17 | Phase 1: Pixel buffer + properties + pixel ops |
| UNCOVERED_SMALL_TESTS_PLAN | 19 | 11/19 | Fix A/B: Removed MC listener/timer cleanup |
| GLOBALS_PLAN | 31 | 28/31 | Phase 8c-4+: Missing properties, flags, instance construction |
| CLONE_DUPLICATE_PLAN | 8 | 5/8 | Phase 2: TextField clone properties |
