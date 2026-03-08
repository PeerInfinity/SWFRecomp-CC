# Blocker Summary

Last updated: 2026-03-07

This document catalogs the root-cause blockers preventing further progress on the Ruffle AVM1 test suite. Each blocker is a missing infrastructure feature or architectural limitation that blocks one or more plans in `blocked/`.

Current pass rate: **425/477 (89.1%)** filtered, **500/619 (80.8%)** total (CI run on 6e400bd3). 19 plans in `blocked/`, 52 in `complete/`, 0 in `incomplete/`.

---

## Blocker 1: LoadMovie / Multi-SWF Infrastructure

**Impact**: 11 plans, 25+ tests, largest single blocker

Our pipeline compiles SWF→C at build time. `loadMovie` loads external SWFs at runtime, which we handle by pre-compiling child SWFs and linking them via a `MovieEntry` registry with symbol prefix-renaming. Phases 0-5 and 7 are implemented (24/49 tests pass). The remaining gaps:

| Gap | What's Missing | Tests Blocked |
|-----|----------------|---------------|
| Per-movie `_global` | SWF7+ each need separate `_global` with own constructors. We use a two-group model (SWF≤6, SWF7+). See Blocker 2. | global_swf5_6_7_8_9, mcl_events_swf_version, loadmovienum_cross_version_prototype |
| Failed load state | `_framesloaded`/`getBytesTotal`/`getSWFVersion` should return `-1` on failed loads | movieclip_state_values |
| Child URL/version | Loaded MC's `_url` and `getSWFVersion()` should reflect child SWF, not parent | movieclip_library_state_values (76/78), multiple MCL tests |
| Sequential MCL dispatch | Multiple `loadClip` calls should fire events one-per-frame, not all-at-once | mcl_events_swf_version |
| Child RegisterClass | Classes registered in child SWF's DoInitAction need child scope context | register_class (26/67), register_class_swf6 |

**Plans blocked**: LOADMOVIE_PLAN (Phase 6), LOADMOVIE_REMAINING_PLAN (5 tests), CROSS_VERSION_ISOLATION_PLAN, ROOT_REPLACEMENT_PLAN (3 tests), SWF_VERSION_SEMANTICS_PLAN (2 tests), REGISTERCLASS_PLAN (2 tests), BUTTON_PLAN (root_button_mode), HIT_TESTING_PLAN (invalid_get_bounds 1-8), GLOBALS_PLAN (global_swf5_6_7_8_9), UNCOVERED_SMALL_TESTS (sandbox_type_remote, resolve_different_root)

---

## Blocker 2: Per-Movie `_global` Isolation

**Impact**: 4-6 tests directly, precondition for Blocker 1 Phase 6

This is the critical sub-blocker within loadMovie. In Ruffle/Flash, each SWF7+ loaded movie gets its own `_global` object with distinct constructor instances (`Object`, `Array`, `MovieClip`, etc.). Cross-version `instanceof` checks fail when constructor identity doesn't match.

Our two-group model (`g_global_legacy` for SWF≤6, `g_global_modern` for SWF7+) is too coarse. A SWF5 child sharing the legacy `_global` with a SWF6 parent gets constructors it shouldn't have.

**Required change**: Per-`MovieEntry` `_global` allocation. Each loaded movie gets a fresh `_global` populated with version-appropriate constructors. `_global` references in generated code resolve through the current movie's context, not a static global.

**Plans blocked**: CROSS_VERSION_ISOLATION_PLAN (Phase 5), LOADMOVIE_PLAN (Phase 6), ROOT_REPLACEMENT_PLAN (cross-version tests)

---

## ~~Blocker 3: MTASC Class / Recompiler Infrastructure~~ MOSTLY RESOLVED

**Impact**: 1 test remaining (mcl_loadclip_replace_root), plus 1 regression

All MTASC-specific issues have been resolved except `mcl_loadclip_replace_root` which needs the `_root.main()` class entry point pattern. This is now a sub-issue of Blocker 1 (LoadMovie).

| Gap | Detail | Status |
|-----|--------|--------|
| ~~Class constructor dispatch~~ | interface_implements_op 46/47 (was 47/47, regressed — lazy ImplementsOp via valueOf callback) | **REGRESSION** — line 43 `obj instanceof LazyInterfaceA: false` |
| `_root.main()` entry point | MTASC convention for class entry | Blocked by LoadMovie |
| ~~Nested function recompilation~~ | object_resolve 39/39 PASS | **RESOLVED** |

**Plans blocked**: ROOT_REPLACEMENT_PLAN (mcl_loadclip_replace_root)

---

## Blocker 4: Font Metrics / Text Layout Accuracy

**Impact**: 3 tests, ~21 lines

TextField textWidth/textHeight computations are close but off by a few pixels. The root causes are interconnected:

- **Word wrap algorithm**: Doesn't perfectly match Flash's line-breaking decisions for mixed-font text
- **Line height calculation**: Mixed-font lines compute height differently (max ascent + max descent vs per-glyph)
- **Bullet/tab indent**: Bullet point indent width and tab stop positions slightly wrong

| Test | Match | Lines Off | Issue |
|------|-------|-----------|-------|
| edittext_scroll | 52/54 | 2 | maxscroll/bottomScroll with mixed fonts |
| edittext_newlines | 23/30 | 7 | textWidth/textHeight accuracy |
| edittext_bullet | 18/30 | 12 | Bullet indent width |
| ~~edittext_tab_stops~~ | 45/60 | 15 | Tab stop computation (ignored — in ignored_tests.txt) |
| ~~device_font_spacing~~ | **91/91 PASS** | 0 | **RESOLVED** |

**Plans blocked**: TEXTFIELD_PLAN (3 tests)

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

**Impact**: 2 tests across 2 plans (function_base_clip_readded RESOLVED)

When MovieClips are removed (`depth = INT_MIN`), operations on them or their closures have incomplete fallback behavior:

| Gap | Detail | Tests Blocked |
|-----|--------|---------------|
| ~~Script halting on clip removal~~ | removeMovieClip halts currently executing script. SCRIPT_HALTING_PLAN COMPLETE. | ~~removed_clip_halts_script~~ **15/15 PASS**, ~~target_clip_removed~~ **5/5 PASS** |
| call() early termination | `call()` on a removed base_clip's frame should terminate the calling script. We don't implement script termination. | removed_target_clip_scope (7/35) |
| ~~Dead base_clip re-resolution~~ | ~~RESOLVED~~ — `reResolveDeadBaseClip()` re-resolves via `original_target`. function_base_clip_readded **12/12 PASS**. | ~~function_base_clip_readded~~ |
| SetTarget on removed base_clip | SetTarget("") should reset to removed base_clip's parent scope, not the target path | removed_target_clip_scope |
| ~~Ruffle-specific trace~~ | "Target not found: dummy" is Ruffle debug output, not Flash behavior. In ignored_tests.txt. | ~~removed_base_clip_tell_target~~ |
| Script halting regression | remove_movie_clip regressed 29/29 → 25/29 from script halting changes | remove_movie_clip |

**Plans blocked**: MC_REMOVAL_LIFECYCLE_PLAN (removed_target_clip_scope), CALL_SEMANTICS_PLAN (removed_target_clip_scope)

**Regressions from script halting**: remove_movie_clip (29→25/29), register_and_init_order (146→36/231), removed_target_clip_scope (11→7/35). These need investigation.

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
Per-movie _global ◄──── LoadMovie Phase 6
       │
       ▼
Cross-version isolation ──► ROOT_REPLACEMENT
       │                    SWF_VERSION_SEMANTICS
       ▼                    GLOBALS (global_swf5_6_7_8_9)
LOADMOVIE_REMAINING ──────► REGISTERCLASS (child SWFs)
                            HIT_TESTING (invalid_get_bounds)
                            BUTTON (root_button_mode)

MTASC class infra ─────────► ROOT_REPLACEMENT (mcl_loadclip_replace_root)
                             (interface_implements_op: RESOLVED, object_resolve: RESOLVED)

Font metrics accuracy ─────► TEXTFIELD (scroll, newlines, bullet)

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
4. ~~**Script halting on clip removal**~~ — **RESOLVED** (with regressions). removed_clip_halts_script **15/15 PASS**, target_clip_removed **5/5 PASS**. But remove_movie_clip regressed 29→25/29. See SCRIPT_HALTING_PLAN (complete/).
5. **Script halting regressions** — remove_movie_clip (25/29), register_and_init_order (36/231), removed_target_clip_scope (7/35) regressed from script halting changes. Need investigation.
6. **Font metrics accuracy** — Incremental improvements to word wrap and line height
7. **Failed load state values** — Return `-1` for specific MC properties on failed load
8. **Global stubs** — Add 20 missing globals (tedious but straightforward)
9. **interface_implements_op regression** — Lazy ImplementsOp via valueOf callback broke in b1b89de3

### Architectural (requires significant design work)
1. **Per-movie `_global` isolation** — Move from two-group to per-movie globals
2. **SWF6 HTML paragraph model** — Version-specific HTML parser path
3. **call() early termination** — Script execution abort mechanism

### Not Feasible
1. **Heap-allocated activation scopes** — Would require rewriting the entire variable storage model

---

## Lines at Stake by Blocker

| Blocker | Tests | Lines Blocked | Feasibility |
|---------|-------|---------------|-------------|
| LoadMovie / multi-SWF | 25+ | 2000+ | Moderate (incremental) |
| Per-movie `_global` | 4-6 | 400+ | Moderate (architectural) |
| ~~MTASC class infra~~ | ~~1~~ | ~~50~~ | **MOSTLY RESOLVED** (1 test left, blocked by LoadMovie) |
| Font metrics | 3 | ~21 | Moderate |
| SWF6 HTML model | 1 | 1480 | Low (complex refactor) |
| ~~condenseWhite~~ | ~~2~~ | ~~17~~ | **RESOLVED** |
| ~~StyleSheet CSS~~ | ~~1~~ | ~~121~~ | **RESOLVED** |
| MC removal lifecycle | 1 | ~21 | Low (deep semantics) |
| Closure capture | 1 | 100 | Not feasible |
| Global enumeration | 3 | 11000+ | High (tedious) |
| Dynamic creation edges | 2 | 240+ | Moderate |
| ~~swf*_global_funcs~~ | ~~3~~ | ~~165~~ | **RESOLVED** |
