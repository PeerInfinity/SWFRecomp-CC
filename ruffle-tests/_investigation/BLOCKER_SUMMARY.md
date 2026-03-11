# Blocker Summary

Last updated: 2026-03-11

This document catalogs the root-cause blockers preventing further progress on the Ruffle AVM1 test suite. Each blocker is a missing infrastructure feature or architectural limitation that blocks one or more plans in `blocked/`.

Current pass rate: **509/618 (82.4%)** total (CI run on a5bc34f5). Image tests: **7/31 strict** (exact pixel match) / **9/31 tolerance pass** (within test.toml limits).

---

## Blocker 1: LoadMovie / Multi-SWF Infrastructure — MOSTLY RESOLVED

**Impact**: Reduced — 31/35 core loadMovie tests pass. Only 4 remaining failures.

Our pipeline compiles SWF→C at build time. `loadMovie` loads external SWFs at runtime, which we handle by pre-compiling child SWFs and linking them via a `MovieEntry` registry with symbol prefix-renaming. Phases 0-5, 7, 8, 10, 13, 14 all implemented. **Phase 6 (per-movie `_global`) CANCELLED** — Ruffle shares `_global` across movies (confirmed 2026-03-10).

| Gap | What's Missing | Tests Blocked | Status |
|-----|----------------|---------------|--------|
| ~~Per-movie `_global`~~ | ~~SWF7+ need separate `_global`~~ | ~~global_swf5_6_7_8_9, loadmovienum_cross_version_prototype~~ | **CANCELLED** (Ruffle shares `_global`) |
| ~~Failed load state~~ | ~~`_framesloaded`/`getBytesTotal` return `-1`~~ | ~~movieclip_state_values~~ | **DONE** |
| ~~Child RegisterClass~~ | ~~Classes registered in child SWF's DoInitAction~~ | ~~register_class, register_class_swf6~~ | **DONE** (export-versioned lookup) |
| ~~MCL cross-version root replace~~ | ~~Closure clearing, _name reset~~ | mcl_replace_root_swf7_to_swf5/swf6 (56/57 each) | **DONE** (1 line accepted diff per test) |
| ~~Mouse events~~ | ~~Mouse dispatch now implemented~~ | ~~root_button_mode~~ | **RESOLVED** — root_button_mode **10/10 PASS** |
| ~~getBounds on loaded clips~~ | ~~getBounds returns undefined after child load~~ | ~~movieclip_invalid_get_bounds_1-8~~ | **MOSTLY RESOLVED** — 6/8 PASS (b5df5477: broadcastMessage MC `this` type, `g_use_new_invalid_bounds` flag, onEnterFrame version switching). Tests 6, 7 each 9/10 (remaining line needs actual shape bounds in NO_GRAPHICS) |
| Cross-movie export isolation | Per-movie char_id and export table scoping | loadmovie_registerclass (27/31) | **ACTIONABLE** (see CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) |

**Plans blocked (reduced)**: HIT_TESTING_PLAN (invalid_get_bounds_6/7 each 9/10 — need shape bounds data in NO_GRAPHICS mode). Multi-SWF tests now visible in filtered results (removed from ignored_tests.txt).

---

## ~~Blocker 2: Per-Movie `_global` Isolation~~ RESOLVED (NEVER NEEDED)

`global_swf5_6_7_8_9` now **1145/1145 PASS**. `loadmovienum_cross_version_prototype` **9/9 PASS**.

**Critical finding (2026-03-10)**: Investigation of Ruffle source code (`~/CC/ruffle/core/src/avm1/runtime.rs`) confirmed that Ruffle does NOT implement per-movie `_global` isolation. The `Avm1` struct has exactly TWO global environments (`env_case_sensitive` for SWF7+, `env_case_insensitive` for SWF≤6), shared across ALL loaded movies. All constructors, prototypes, and singletons are shared. This matches our existing two-group model — per-movie isolation was never needed.

This was previously documented as the "single largest blocker" and "highest architectural complexity" change. The entire LOADMOVIE_MULTI_SWF_PLAN Phase 6 was cancelled.

---

## ~~Blocker 3: MTASC Class / Recompiler Infrastructure~~ MOSTLY RESOLVED

**Impact**: 1 test remaining (mcl_loadclip_replace_root), plus 1 regression

All MTASC-specific issues have been resolved except `mcl_loadclip_replace_root` which needs the `_root.main()` class entry point pattern. This is now a sub-issue of Blocker 1 (LoadMovie).

| Gap | Detail | Status |
|-----|--------|--------|
| ~~Class constructor dispatch~~ | interface_implements_op **47/47 PASS** | **RESOLVED** |
| `_root.main()` entry point | MTASC convention for class entry | Blocked by LoadMovie |
| ~~Nested function recompilation~~ | object_resolve 39/39 PASS | **RESOLVED** |

**Plans blocked**: ROOT_REPLACEMENT_PLAN (mcl_loadclip_replace_root)

---

## Blocker 4: Font Metrics / Text Layout Accuracy

**Impact**: 1 test, ~4 lines (down from 3 tests, ~21 lines)

TextField textWidth/textHeight computations are close but off by a few pixels. Major improvements via mixed-font per-run measurement and bullet indent support:

- ~~**Word wrap algorithm**~~: **RESOLVED** — `ng_measure_substr_mixed_twips()` for per-run font height measurement
- ~~**Line height calculation**~~: **MOSTLY RESOLVED** — `ng_computeScrollMixedFont()` with per-line max font height
- **Bounding box union model**: Ruffle uses baseline-aligned bounding box union for textHeight; we use simpler offset/extent tracking. 3-pixel discrepancy on mixed-font bullet lists.

| Test | Match | Lines Off | Issue |
|------|-------|-----------|-------|
| ~~edittext_scroll~~ | **54/54 PASS** | 0 | **RESOLVED** — per-run mixed-font measurement |
| ~~edittext_newlines~~ | **30/30 PASS** | 0 | **RESOLVED** — mixed-font textHeight path |
| edittext_bullet | 26/30 | 4 | textHeight off by 3px (176 vs 179/197) — Ruffle bounding box union model |
| ~~edittext_tab_stops~~ | 45/60 | 15 | Tab stop computation (ignored — in ignored_tests.txt) |
| ~~device_font_spacing~~ | **91/91 PASS** | 0 | **RESOLVED** |

**Plans blocked**: TEXTFIELD_PLAN (1 test — edittext_bullet 4 remaining lines)

---

## Blocker 5: SWF6 HTML Paragraph Semantics

**Impact**: 1 test, ~1480 lines

SWF6 treats `\n` in HTML text differently from SWF7+. In SWF7+, `\n` inside `<P>` tags creates separate paragraph elements. In SWF6, `\n` is treated as a line break within the same paragraph — no `<P>` splitting occurs. Also different `\r` handling in text storage.

This requires a version-specific HTML parser path — a major refactor of the existing HTML text pipeline.

| Test | Match | Lines Off |
|------|-------|-----------|
| edittext_html_swf6 | 3897/5377 | 1480 |

**Plans blocked**: TEXTFIELD_PLAN, HTML_TEXT_REMAINING_WORK

---

## ~~Blocker 6: condenseWhite Issues~~ RESOLVED

Both tests now **PASS**:
- edittext_html_condensewhite_swf7: **311/311 PASS**
- edittext_html_condensewhite_swf8: **311/311 PASS**

**Fixes applied:**
1. **Sentinel collision**: Replaced `\x01`/`\x02` in-band sentinels with `\xFE`/`\xFF` (invalid UTF-8 bytes that never appear in content)
2. **SWF8 trailing space**: In single-line condenseWhite SWF8, tag break sentinels produce a space (deduplicated with existing trailing spaces). In multiline mode they produce `\r` as before.

---

## ~~Blocker 7: StyleSheet CSS Parser~~ RESOLVED

~~**Impact**: 1 test, ~121 lines~~

`edittext_stylesheet` now **325/325 PASS**. StyleSheet CSS parsing is fully implemented.

---

## Blocker 8: MC Removal Lifecycle / call() Semantics

**Impact**: 1 test remaining across 2 plans (function_base_clip_readded, remove_movie_clip, removed_clip_halts_script, target_clip_removed all RESOLVED)

When MovieClips are removed (`depth = INT_MIN`), operations on them or their closures have incomplete fallback behavior:

| Gap | Detail | Tests Blocked |
|-----|--------|---------------|
| ~~Script halting on clip removal~~ | removeMovieClip halts currently executing script. SCRIPT_HALTING_PLAN COMPLETE. | ~~removed_clip_halts_script~~ **15/15 PASS**, ~~target_clip_removed~~ **5/5 PASS** |
| call() early termination | `call()` on a removed base_clip's frame should terminate the calling script. We don't implement script termination. | removed_target_clip_scope (34/35) |
| ~~Dead base_clip re-resolution~~ | ~~RESOLVED~~ — `reResolveDeadBaseClip()` re-resolves via `original_target`. function_base_clip_readded **12/12 PASS**. | ~~function_base_clip_readded~~ |
| ~~SetTarget on removed base_clip~~ | ~~RESOLVED~~ — SetTarget("") with dead base_clip sets `g_settarget_none=1` (GotoFrame/Play/Stop become no-ops). Settarget flags saved/restored around sprite init contexts. | ~~removed_target_clip_scope~~ (was 7→34/35) |
| ~~Ruffle-specific trace~~ | "Target not found: dummy" is Ruffle debug output, not Flash behavior. In ignored_tests.txt. | ~~removed_base_clip_tell_target~~ |
| ~~Script halting regressions~~ | ~~RECOVERED~~ — remove_movie_clip **29/29 PASS** (display list clearing + context reset). removed_clip_halts_script/target_clip_removed recovered via `g_current_executing_func->base_clip` check. | ~~remove_movie_clip~~ **29/29 PASS** |

**Plans blocked**: MC_REMOVAL_LIFECYCLE_PLAN (removed_target_clip_scope 34/35), CALL_SEMANTICS_PLAN (removed_target_clip_scope 34/35)

**Remaining**: removed_target_clip_scope line 21 (`scope = /base2/target2` expected, get `scope = /base2`) — child MC resolution in non-root sprite context. register_and_init_order (146→36/231) regression from script halting is a separate constructor ordering issue (Blocker 11).

---

## Blocker 9: Heap-Allocated Activation Scopes (Closure Variable Capture)

**Impact**: 1 test, ~100 lines. **NOT FEASIBLE** to fix.

Our runtime uses stack-based variables. When an inner function captures an outer function's local variable, the variable is gone after the outer function returns. Flash/Ruffle use heap-allocated activation records that persist as long as any closure references them.

```actionscript
function addGetter(obj, name, val) {
    obj.addProperty(name, function() { return val; }, null);
    // 'val' must survive after addGetter returns
}
```

Our getter returns `undefined` for `val`. Fixing this requires a fundamental rewrite of the variable storage model — replacing stack-based locals with heap-allocated activation frames. This is not feasible within the current architecture.

| Test | Match | Lines Off |
|------|-------|-----------|
| coerce_to_object_monkeypatch | ~29/129 | ~100 |

**Plans blocked**: TYPE_COERCION_ADVANCED_PLAN

---

## Blocker 10: Global Constructor Enumeration Order

**Impact**: 3 tests, ~11,000+ lines (but low value — tests enumerate all globals)

Tests `global_proto_decls`, `global_proto_decls_delete`, and `global_instance_decls` enumerate every global object and its properties via `for-in`. Our global registration order differs from Ruffle's, and we're missing ~20 globals that Ruffle implements (ASnative, ASconstructor, enableDebugConsole, SoundCodec, AsSetupError, AssetCache, RemoteLSOUsage, textRenderer, ASSetNative, ASSetNativeAccessor, etc.).

Matching requires: (1) adding all missing globals as stubs, (2) rewriting the entire `ensureGlobalInit()` registration order to match Ruffle's enumeration sequence.

**Plans blocked**: GLOBALS_PLAN (Phase 8)

---

## Blocker 11: Dynamic Object Creation Edge Cases

**Impact**: 2 tests

`createEmptyMovieClip()` and `createTextField()` work for most cases, but specific edge cases remain:

- `focus_mouse_focusable`: needs runtime `createTextField` with focusability + "Focus changed" `onSetFocus` listener with oldFocus/newFocus args
- Sprite init ordering during `register_and_init_order`: constructor fire order for deeply nested timeline-placed sprites

**Plans blocked**: FOCUS_SYSTEM_PLAN (1 test), REGISTERCLASS_PLAN (register_and_init_order)

---

## ~~Blocker 12: swf*_global_funcs SWF-Version Number Parsing~~ RESOLVED

All three tests now **PASS**:
- swf5_global_funcs: PASS
- swf6_global_funcs: PASS
- swf7_global_funcs: PASS

SWF-version-specific number parsing (hex/octal) has been fully implemented.

---

## Dependency Graph

```
~~Per-movie _global~~ ◄── LoadMovie Phase 6 (RESOLVED — Blocker 2)
       │
       ▼
Cross-version isolation ──► ROOT_REPLACEMENT
       │                    SWF_VERSION_SEMANTICS
       ▼                    ~~GLOBALS (global_swf5_6_7_8_9)~~ RESOLVED
LOADMOVIE_REMAINING ──────► REGISTERCLASS (child SWFs)
                            ~~HIT_TESTING (invalid_get_bounds)~~ MOSTLY RESOLVED (6/8 PASS)
                            BUTTON (root_button_mode)

MTASC class infra ─────────► ROOT_REPLACEMENT (mcl_loadclip_replace_root)
                             (interface_implements_op: RESOLVED, object_resolve: RESOLVED)

Font metrics accuracy ─────► TEXTFIELD (~~scroll~~, ~~newlines~~, bullet 4 lines)

SWF6 HTML model ───────────► TEXTFIELD (edittext_html_swf6)
                             HTML_TEXT_REMAINING_WORK

MC removal lifecycle ──────► CALL_SEMANTICS (removed_target_clip_scope)
                             (function_base_clip_readded: RESOLVED)

Closure capture ───────────► TYPE_COERCION_ADVANCED (NOT FEASIBLE)
```

---

## Actionable vs Architectural

### Actionable (could be tackled with moderate effort)
1. ~~**_lockroot _root resolution**~~ — **RESOLVED**. movieclip_lockroot **29/29 PASS**. See LOCKROOT_PLAN (complete/).
2. ~~**Primitive coercion addProperty**~~ — **RESOLVED**. coerce_to_primitive_resolve **17/17 PASS**. See PRIMITIVE_COERCION_ADDPROPERTY_PLAN (complete/).
3. ~~**Default instance naming**~~ — **RESOLVED**. default_names **52/52 PASS**. See DEFAULT_NAMES_PLAN (complete/).
4. ~~**Script halting on clip removal**~~ — **RESOLVED**. removed_clip_halts_script **15/15 PASS**, target_clip_removed **5/5 PASS**, remove_movie_clip **29/29 PASS**, removed_target_clip_scope **35/35 PASS**. All script halting regressions recovered except register_and_init_order (~16/233, constructor ordering issue).
5. **register_and_init_order regression** — 146→~16/233 from script halting changes. Deep constructor ordering issue, partially overlaps with Blocker 11.
6. ~~**getBounds on loaded clips**~~ — **MOSTLY RESOLVED**. 6/8 tests PASS (movieclip_invalid_get_bounds_1-5, 8). Tests 6, 7 each 9/10 (remaining 1 line needs real shape bounds in NO_GRAPHICS mode).
6. ~~**Font metrics accuracy**~~ — **MOSTLY RESOLVED**. edittext_scroll **54/54 PASS**, edittext_newlines **30/30 PASS**, edittext_bullet 26/30 (4 lines: bounding box model mismatch)
7. **Failed load state values** — Return `-1` for specific MC properties on failed load
8. **Global stubs** — Add 20 missing globals (tedious but straightforward)
9. ~~**interface_implements_op regression**~~ — **RESOLVED** (47/47 PASS)

### Architectural (requires significant design work)
1. ~~**Per-movie `_global` isolation**~~ — **RESOLVED**. Per-version-group Function.prototype. global_swf5_6_7_8_9 **1145/1145 PASS**.
2. **SWF6 HTML paragraph model** — Version-specific HTML parser path
3. **call() early termination** — Script execution abort mechanism

### Not Feasible
1. **Heap-allocated activation scopes** — Would require rewriting the entire variable storage model

---

## Lines at Stake by Blocker

| Blocker | Tests | Lines Blocked | Feasibility |
|---------|-------|---------------|-------------|
| LoadMovie / multi-SWF | 25+ | 2000+ | Moderate (incremental) |
| ~~Per-movie `_global`~~ | ~~4-6~~ | ~~400+~~ | **RESOLVED** |
| ~~MTASC class infra~~ | ~~1~~ | ~~50~~ | **MOSTLY RESOLVED** (1 test left, blocked by LoadMovie) |
| Font metrics | 1 | ~4 | Low (bounding box model mismatch, 3px diff) |
| SWF6 HTML model | 1 | 1480 | Low (complex refactor) |
| ~~condenseWhite~~ | ~~2~~ | ~~17~~ | **RESOLVED** |
| ~~StyleSheet CSS~~ | ~~1~~ | ~~121~~ | **RESOLVED** |
| MC removal lifecycle | 1 | ~1 | Low (1 line remaining: child MC resolution in non-root context) |
| Closure capture | 1 | 100 | Not feasible |
| Global enumeration | 3 | 11000+ | High (tedious) |
| Dynamic creation edges | 2 | 240+ | Moderate |
| ~~swf*_global_funcs~~ | ~~3~~ | ~~165~~ | **RESOLVED** |
