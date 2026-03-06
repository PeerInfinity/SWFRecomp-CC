# Blocker Summary

Last updated: 2026-03-05

This document catalogs the root-cause blockers preventing further progress on the Ruffle AVM1 test suite. Each blocker is a missing infrastructure feature or architectural limitation that blocks one or more plans in `blocked/`.

Current pass rate: **392/619 (63.3%)** filtered. 22 plans in `blocked/`, 2 in `incomplete/`.

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

## Blocker 3: MTASC Class / Recompiler Infrastructure

**Impact**: 1-2 tests across 2 plans (PARTIALLY RESOLVED)

MTASC-compiled tests use class syntax with a `main()` static entry point pattern (`_root.main()` or `Test.main()`). Our recompiler handles most bytecode correctly but has gaps with MTASC-specific patterns:

| Gap | Detail | Tests Blocked |
|-----|--------|---------------|
| ~~Class constructor dispatch~~ | ~~RESOLVED~~ — interface_implements_op was NOT an MTASC/recompiler issue. Fixed 3 bugs in actionImplementsOp runtime: repeat-call lockout, non-object prototype skip, MOVIECLIP interface support. Plus: Function.call() FUNCTION thisArg, addProperty getter on FUNCTION.prototype. Now 47/47 PASS. | ~~interface_implements_op~~ |
| `_root.main()` entry point | MTASC convention for class entry; needs class→root binding | mcl_loadclip_replace_root |
| ~~Nested function recompilation~~ | ~~RESOLVED~~ (commit 55fb0205). object_resolve now passes 39/39. | ~~object_resolve~~ |

**Plans blocked**: ROOT_REPLACEMENT_PLAN (mcl_loadclip_replace_root)

---

## Blocker 4: Font Metrics / Text Layout Accuracy

**Impact**: 5 tests, ~80 lines

TextField textWidth/textHeight computations are close but off by a few pixels. The root causes are interconnected:

- **Word wrap algorithm**: Doesn't perfectly match Flash's line-breaking decisions for mixed-font text
- **Line height calculation**: Mixed-font lines compute height differently (max ascent + max descent vs per-glyph)
- **Bullet/tab indent**: Bullet point indent width and tab stop positions slightly wrong
- **Letter spacing with word wrap**: `letterSpacing` affects character advance but our wrap calculation doesn't account for it

| Test | Match | Lines Off | Issue |
|------|-------|-----------|-------|
| edittext_scroll | 52/54 | 2 | maxscroll/bottomScroll with mixed fonts |
| edittext_newlines | 23/30 | 7 | textWidth/textHeight accuracy |
| edittext_bullet | 18/30 | 12 | Bullet indent width |
| edittext_tab_stops | 45/60 | 15 | Tab stop computation (ignored) |
| ~~device_font_spacing~~ | ~~46/91~~ **91/91 PASS** | ~~45~~ 0 | ~~Letter spacing + word wrap~~ RESOLVED |

**Plans blocked**: TEXTFIELD_PLAN (4 tests)

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

## Blocker 6: condenseWhite Paragraph Break Architecture

**Impact**: 2 tests, ~65 lines

The HTML parser uses in-band sentinel characters (`\x01`/`\x02`) to mark paragraph breaks for later processing. This collides with literal control characters in input text. SWF8 condenseWhite also needs paragraph-level leading whitespace stripping (different from SWF7's text-node-level approach).

| Test | Match | Lines Off | Issue |
|------|-------|-----------|-------|
| edittext_html_condensewhite_swf7 | 308/311 | 3 | Multiline raw text whitespace |
| edittext_html_condensewhite_swf8 | 249/311 | 62 | Paragraph-level whitespace stripping |

**Plans blocked**: HTML_TEXT_REMAINING_WORK, TEXTFIELD_PLAN

---

## Blocker 7: StyleSheet CSS Parser

**Impact**: 1 test, ~121 lines

`TextField.styleSheet` needs a CSS parser that converts CSS rules to TextFormat objects. Requires: CSS tokenization, property-to-TextFormat mapping, and style application during HTML rendering.

| Test | Match | Lines Off |
|------|-------|-----------|
| edittext_stylesheet | 204/325 | 121 |

**Plans blocked**: TEXTFIELD_PLAN

---

## Blocker 8: MC Removal Lifecycle / call() Semantics

**Impact**: 3 tests across 2 plans

When MovieClips are removed (`depth = INT_MIN`), operations on them or their closures have incomplete fallback behavior:

| Gap | Detail | Tests Blocked |
|-----|--------|---------------|
| call() early termination | `call()` on a removed base_clip's frame should terminate the calling script. We don't implement script termination. | removed_target_clip_scope (16/37) |
| Dead base_clip re-resolution | When a closure's base_clip is removed and a new MC takes the same path, the closure should resolve to the new MC | function_base_clip_readded (10/11) |
| SetTarget on removed base_clip | SetTarget("") should reset to removed base_clip's parent scope, not the target path | removed_target_clip_scope |
| Ruffle-specific trace | "Target not found: dummy" is Ruffle debug output, not Flash behavior | removed_base_clip_tell_target (0/2) |

**Plans blocked**: MC_REMOVAL_LIFECYCLE_PLAN (3 tests), CALL_SEMANTICS_PLAN (removed_target_clip_scope), TELLTARGET_PLAN (3 tests referencing removal behavior)

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

## Blocker 12: swf*_global_funcs SWF-Version Number Parsing

**Impact**: 3 tests, ~165 lines remaining

~~Stack corruption~~ **PARTIALLY RESOLVED**: The garbage values were caused by `varToDouble()` reinterpreting non-numeric types (STRING pointers) as float bits. Fixed by switching to `varToDoubleSimple()`. Also fixed `isNaN`/`isFinite` not being first-class function objects (returned UNDEFINED from GetVariable).

**Remaining**: SWF-version-specific string-to-number conversion differences (67 lines in SWF5, 55 in SWF6, 43 in SWF7). `strtod` parses hex `0x10` → 16, but SWF5 should return NaN. SWF6 has octal parsing (`"010"` → 8). Fixing requires a custom SWF-version-aware `strtod` replacement.

**Plans blocked**: GLOBALS_PLAN (swf5/6/7_global_funcs)

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
                             UNCOVERED_SMALL_TESTS (device_font_spacing)

SWF6 HTML model ───────────► TEXTFIELD (edittext_html_swf6)
                             HTML_TEXT_REMAINING_WORK

MC removal lifecycle ──────► CALL_SEMANTICS (removed_target_clip_scope)
                             TELLTARGET (3 tests)
                             MC_REMOVAL_LIFECYCLE (function_base_clip_readded)

Closure capture ───────────► TYPE_COERCION_ADVANCED (NOT FEASIBLE)
```

---

## Actionable vs Architectural

### Actionable (could be tackled with moderate effort)
1. **Font metrics accuracy** — Incremental improvements to word wrap and line height
2. **Failed load state values** — Return `-1` for specific MC properties on failed load
3. **Sequential MCL dispatch** — Timer-based load event spacing
4. **condenseWhite fixes** — Side-channel paragraph markers instead of in-band sentinels
5. **Global stubs** — Add 20 missing globals (tedious but straightforward)
6. **swf5_global_funcs** — Debug recompiler stack corruption for this specific test

### Architectural (requires significant design work)
1. **Per-movie `_global` isolation** — Move from two-group to per-movie globals
2. **SWF6 HTML paragraph model** — Version-specific HTML parser path
3. **call() early termination** — Script execution abort mechanism
4. **Dead base_clip re-resolution** — Path-based MC lookup on dead closures
5. **StyleSheet CSS parser** — Full CSS tokenizer + property mapping

### Not Feasible
1. **Heap-allocated activation scopes** — Would require rewriting the entire variable storage model

---

## Lines at Stake by Blocker

| Blocker | Tests | Lines Blocked | Feasibility |
|---------|-------|---------------|-------------|
| LoadMovie / multi-SWF | 25+ | 2000+ | Moderate (incremental) |
| Per-movie `_global` | 4-6 | 400+ | Moderate (architectural) |
| MTASC class infra | 1 | 50 | Low (interface_implements_op + object_resolve RESOLVED) |
| Font metrics | 4 | 35 | Moderate (device_font_spacing RESOLVED) |
| SWF6 HTML model | 1 | 1480 | Low (complex refactor) |
| condenseWhite | 2 | 65 | Moderate |
| StyleSheet CSS | 1 | 121 | Moderate |
| MC removal lifecycle | 3 | 120 | Low (deep semantics) |
| Closure capture | 1 | 100 | Not feasible |
| Global enumeration | 3 | 11000+ | High (tedious) |
| Dynamic creation edges | 2 | 240+ | Moderate |
| swf*_global_funcs | 3 | 165 | Moderate (main bugs fixed, SWF-version parsing remains) |
