# Gnash Test Suite Status

Last updated: 2026-03-29

## Quick Summary

| Sub-suite | Tests | Passing | Rate | Filtered | Filtered Rate | Ignored |
|-----------|-------|---------|------|----------|---------------|---------|
| **actionscript.all** | 190 | ~61 | ~32.1% | ~61/181 | **~33.7%** | 9 |
| **misc-swfmill.all** | 14 | 11 | 78.6% | — | — | — |
| **Total** | 204 | ~72 | ~35.3% | — | — | — |

Note: counts estimated from local testing (pending CI run). New passes: Color-v5/v7/v8 (+3).

Filtered results exclude 9 tests with all-accepted diffs (Math-v5/v6/v7/v8, ops-v8, Error-v5/v6/v7/v8) — see `ACCEPTED_DIFFS.md`. Remaining 3 misc-swfmill failures (dict_event, tags_after_last_showframe, jump_to_prev_block) are blocked on architectural limitations — see `incomplete/MISC_SWFMILL_PLAN.md`.

### Latest fixes (2026-03-29)
- **Sort HOLE comparison (SWF < 7)** — HOLE elements now compare as empty string during sort for SWF5/6, matching Flash behavior where sparse array holes sort to the beginning.
- **Array.concat densification** — HOLE elements converted to UNDEFINED in concat results, matching Flash behavior.
- **Array.splice densification** — Remaining HOLE elements converted to UNDEFINED after splice, with proper enumeration key tracking.
- **sortOn UNIQUESORT fix** — UNIQUESORT without RETURNINDEXEDARRAY now correctly sorts in-place (was incorrectly returning index array). Fixes ~17 `tostr(r)` failures in array-v5.
- array-v5 improved from ~418/560 (74.6%) to ~440/560 (78.6%)

### Latest fixes (2026-03-27)
- **Color target toString() resolution** — Color.getRGB/getTransform/setRGB/setTransform now call toString() on object targets at each method invocation (Flash behavior). Fixes Color-v5.
- **Dynamic MC color transform** — Added color transform storage (cx_ra..cx_ab) to MovieClip struct. Dynamic MCs (createEmptyMovieClip) now support Color.getTransform/setTransform. Fixes Color-v5/v7/v8.
- **_alpha / Color transform dual quantization** — `_alpha` getter uses roundf quantization; `cx_aa` (Color.getTransform) uses integer truncation matching Flash's setTransform behavior. Fixes remaining Color-v7/v8 `trans2.aa` failures.
- Color-v6 improved from 93% to 97% (4 remaining failures: `typeof(c) == 'undefined'` for non-constructable Color in SWF6+).

### Latest fixes (2026-03-26)
- **XMLSocket.connect returns false** — All 4 XMLSocket tests now PASS (v5/v6/v7/v8). `connect()` stub changed from returning undefined to returning false.

## Related Documents

| Document | Purpose |
|----------|---------|
| `FAILING_TESTS_BY_FEATURE.md` | All failures categorized by root cause / feature area |
| `REMAINING_FAILURES_ANALYSIS.md` | Detailed tiered analysis with estimated fix effort |
| `INHERITANCE_SEGFAULT_PLAN.md` | Inheritance-v7/v8 segfault investigation (FIXED) |
| `TRY_FINALLY_PLAN.md` | Try-v6/v7/v8 OOM crash investigation (FIXED) |
| `ARRAY_V5_PLAN.md` | array-v5 OOM crash investigation (root causes identified) |
| `MISC_SWFMILL_PLAN.md` | All 6 misc-swfmill failures (root causes identified) |
| `BLOCKER_SUMMARY.md` | Active and resolved blockers preventing progress |
| `ACCEPTED_DIFFS.md` | Tests where our output is more correct than Gnash's expected output |

## Test Structure

Gnash tests are organized as `ClassName-vN` where N is the SWF version (5-8). The same ActionScript class is tested across multiple SWF versions, so fixes often apply to 3-4 tests at once. All 190 actionscript.all tests include `Dejagnu.swf` as a child movie (SWF5 test harness).

---

## Critical Finding: Dejagnu.swf SWF5 Init Poisons Object.prototype

**Root cause**: All 190 Gnash tests load `Dejagnu.swf` (SWF version 5) via `actionImportAssets`. During import, `g_swf_version` is temporarily set to 5. If `getObjectPrototype()` is called for the first time during Dejagnu's init, the `if (g_swf_version >= 6)` guard at action.c:4732 prevents installation of `hasOwnProperty`, `isPropertyEnumerable`, `isPrototypeOf`, `watch`, and `unwatch`. Since Object.prototype is a singleton, these methods are permanently missing for the rest of execution.

**Impact**: This single bug causes ~33+ `hasOwnProperty` failures across Video, NetStream, Color, AsBroadcaster, Selection, Inheritance, and other test groups. It also breaks `instanceof` checks that depend on prototype chain methods.

**Fix**: Remove or restructure the `if (g_swf_version >= 6)` guard in `getObjectPrototype()`. Flash handles version-gating via ASSetPropFlags visibility masks, not by omitting methods. The methods should always be installed.

**Estimated improvement**: Fixing this alone should resolve 20+ tests' remaining diffs and could push the pass rate from 38 to 50+ tests.

---

## Segfaults (13 tests)

### Bug 1: Child Movie Transform Buffer Overflow (all 13 tests)

All Gnash tests include `Dejagnu.swf` as a child movie with 24 transforms (`Dejagnu_transform_data[24][16]`), but parent test SWFs typically have only 4 transforms. When the child sprite's frame function runs via `exec_sprite_frame` → `tagPlaceObject2` → `ng_cache_transform`, it uses the parent's `transform_data` array (because `g_active_transform_data` is NULL — only set during loadMovie, not direct sprite placement). Child transform indices (up to 23) overflow the parent's 4-entry array.

**Fix**: Set `g_active_transform_data` to the child's transform array in `exec_sprite_frame`, not just in the loadMovie path.

**Impact**: case-v5/v6/v7/v8 (4 tests) and HitTest-v6/v7/v8 (3 tests) would likely become output_mismatch or pass with just this fix.

### Bug 2: Try/Catch OOM via Infinite Loop (Try-v6/v7/v8) — FIXED

**Root cause**: Two bugs in exception handling:

1. **Runtime infinite loop**: `actionThrow` and `actionTryEnd` did not clear `has_jmp_buf` on exception handler frames before longjmp. For try-finally (no catch), where `actionCatchEnter` is never called, the handler's `has_jmp_buf` stayed set. When `actionTryEnd` in a nested try-catch inside the finally re-propagated a pending exception, it longjmp'd back to the same already-handled frame, creating an infinite loop that exhausted the heap.

2. **Recompiler: return inside finally skipped cleanup**: `actionReturn` inside a finally block emitted a direct C `return` without calling `actionTryEnd` or clearing the pending exception, leaving stale exception state after function return.

**Fix**: (1) Clear `has_jmp_buf` before longjmp in both `actionThrow` and `actionTryEnd`. (2) Recompiler emits `actionClearException` + `actionTryEnd` before return inside finally blocks.

Note: Try-v5 does not exist (only v6/v7/v8).

### Bug 3: NULL Property Name — ASArray/ASObject Cast (toString_valueOf-v5/v6)

During `actionAdd2` on two ARRAY values, `convertFloat` calls `getPropertyWithPrototype(obj, "valueOf", 7)`. The code at action.c:18042-18043 casts `ASArray*` to `ASObject*`, but these are different structs. The ASArray's `length` field is misinterpreted as `num_properties`, and iterating "properties" dereferences garbage, hitting a NULL `name` pointer.

**Fix**: In `convertFloat` (and similar sites), ARRAY type should use `arr->props` sub-object for property lookups, not cast to ASObject.

### Summary Table

| Test Group | Versions | Primary Bug | Secondary Bug | Fix Complexity |
|------------|----------|-------------|---------------|----------------|
| case | v5, v6, v7, v8 | Transform overflow | — | Low |
| HitTest | v6, v7, v8 | Transform overflow | — | Low |
| Try | v5, v6, v7, v8 | Transform overflow | OOM string concat | Medium |
| toString_valueOf | v5, v6 | Transform overflow | ASArray/ASObject cast | Medium |

---

## Compile Failures (35 tests)

### Category 1: `s16` Label Overflow (28 tests) — EASY FIX

**Error**: `error: expected ';' before '-' token` (negative label names like `label_-32710`)

**Tests**: BitmapData-v8, Global-v6/v7, Inheritance-v7/v8, Math-v5/v6/v7/v8, Matrix-v6/v7/v8, MovieClip-v5, Number-v5/v6/v7/v8, Point-v8, String-v5/v6/v7/v8, TextSnapshot-v6/v7/v8, array-v5, ops-v8, misc-swfmill/jump_to_prev_block

**Root cause**: In `action.cpp`, labels are generated using `(s16)(ptr - action_buffer_start)` at 8 sites (lines 309, 333, 650, 811, 1201, 1281, 1931, 1945). When bytecode blocks exceed 32KB (Gnash Dejagnu tests are large), offsets wrap to negative numbers.

**Fix**: Change `(s16)` to `(s32)` or `(int)` at all 8 label-generation sites. Pass 1 already uses `s64` for offset calculation.

### Category 2: Duplicate Labels from WITH Blocks (4 tests)

**Error**: `error: duplicate label 'label_91'`

**Tests**: with-v5/v6/v7/v8

**Root cause**: `parseActions()` is called recursively for WITH block bodies with a fresh `action_buffer_start`. Multiple WITH blocks with jump targets at the same relative offset produce identical labels in the same C function scope.

**Fix**: Namespace labels within WITH blocks (e.g., `label_W3_91` instead of `label_91`).

### Category 3: Cross-Frame ConstantPool (2 tests)

**Error**: Truncated C output (exception during Push)

**Tests**: misc-swfmill/dict_cross, misc-swfmill/dict_event

**Root cause**: Frame 1's DoAction defines a ConstantPool; frame 2's DoAction references it. But `constant_pool` is reset per `parseActions` call, so frame 2 has an empty pool and throws on out-of-range constant indices.

**Fix**: Persist ConstantPool across DoAction blocks within the same SWF.

### Category 4: Jump Past End of Actions (1 test)

**Error**: `error: label 'label_121' used but not defined`

**Test**: misc-swfmill/jump_after_end

**Root cause**: SWF bytecode jumps past END_OF_ACTIONS marker. Flash treats this as ending execution. Recompiler emits `goto label_121` but never defines the label.

**Fix**: Replace out-of-bounds gotos with `return;`.

### Priority

| Category | Tests | Fix Difficulty | Impact |
|----------|-------|---------------|--------|
| s16 overflow | 28 | Trivial (type cast change) | HIGH |
| WITH duplicate labels | 4 | Easy (label namespacing) | Medium |
| Cross-frame ConstantPool | 2 | Medium (state management) | Low |
| Jump past end | 1 | Easy (bounds check) | Low |

---

## Near-Passing Tests (>=80% match rate)

### Already identified root causes

| Test | Status | Notes |
|------|--------|-------|
| Boolean-v5/v6/v7/v8 | **PASS** (38/38) | Already passing since Phase 1 fixes |
| Video-v6/v7/v8 | **PASS** (85/85) | Already passing since Phase 1 fixes |
| Selection-v5 | **PASS** (21/21) | Already passing since Phase 1 fixes |
| Stage-v5 | **PASS** (38/38) | Already passing since Phase 1 fixes |
| Color-v5/v7/v8 | **PASS** (134/155/155) | Fixed: toString resolution, dynamic MC CxForm, dual quantization |
| Color-v6 | 161/165 (97.6%) | 4 remaining: `typeof(c) == 'undefined'` for non-constructable Color |
| NetStream-v6/v7/v8 | 72/74 (97.3%) | 2 remaining: `currentFps` not own property on prototype |
| TextFieldHTML-v6/v7/v8 | 86.5% | htmlText getter/text clearing bugs |
| Selection-v6/v7/v8 | ~86% | Selection non-constructable + `_listeners` own property |
| Inheritance-v5/v6 | ~81% | super() chain, Function.__proto__, instanceOf |

### v5-passes-but-v6-fails Pattern

11 classes pass at v5 but fail at v6+. SWF6+ tests exercise `_global.ClassName` access, `hasOwnProperty`, and `instanceof` — all features gated on SWF version 6+. The Dejagnu.swf SWF5 init poison is the primary cause.

---

## Recommended Work Order

### Phase 1: DONE — All compile failures, segfaults, and Object.prototype fixes applied
1. ~~**s16 label overflow**~~ — DONE (all 28 compile failures fixed)
2. ~~**Object.prototype SWF5 guard**~~ — DONE (hasOwnProperty always installed)
3. ~~**Transform buffer overflow**~~ — DONE (all 13 segfaults fixed)
4. ~~**WITH block label namespacing**~~ — DONE (4 compile failures fixed)
5. **ASnative class 101 (Object.prototype methods)** — DONE (2026-03-19). Gnash tests install hasOwnProperty/toString/valueOf/etc. on class prototypes via ASnative(101, N). Without this, ASnative returned undefined which shadowed the prototype chain.
6. **Color prototype unification** — DONE (2026-03-19). `new Color().__proto__` and `Color.prototype` now point to the same object, fixing `instanceof Color`.

### Phase 1b: DONE — Math, ops, Error edge case fixes (2026-03-20)
7. ~~**Math non-constructable**~~ — DONE. `new Math()` returns undefined (not object).
8. ~~**Empty string → NaN in convertFloat**~~ — DONE. `Math.round('')` now returns NaN for SWF5+, matching Flash/Ruffle. Also fixes `is_finite("")` consistency.
9. ~~**Math functions not standalone globals**~~ — DONE. Removed math builtins (acos, sin, etc.) from global function_registry — accessible only via `Math.method()`.
10. ~~**parseStringToNumber Infinity/NaN rejection**~~ — DONE. `Infinity == 'Infinity'` now correctly returns false in equality comparisons (strtod was parsing "Infinity"/"NaN" strings).
11. ~~**Error message coercion**~~ — DONE. `new Error(7.8898)` now coerces argument to string "7.8898".

**Impact**: Math-v5/v6: 6→5 diffs, Math-v7/v8: 7→5 diffs, ops-v8: 11→7 diffs, Error-v5/v6/v7/v8: 7→4 diffs each. All remaining diffs are accepted (Gnash bugs). See `ACCEPTED_DIFFS.md`.

### Phase 2: Prototype and constructor fixes (est. +10-15 tests)
12. ~~**ASArray/ASObject cast in convertFloat**~~ — Already fixed (arr->props sub-object used). toString_valueOf failures are from other causes.
13. ~~**`Object.prototype.constructor` setup**~~ — DONE (2026-03-23). Set constructor → Object on Object.prototype.
14. **Stage/Selection non-constructable** — Stage-v5 already passes. Selection-v6/v7/v8 have deeper issues (Selection indices, _listeners instanceof Array).
15. ~~**Color valueOf in setTransform + constructor target property**~~ — DONE (2026-03-25). Three fixes: (a) Color.setTransform now uses `varToDoubleSWF` (not `varToDoubleSimple`) for param properties, fixing valueOf on Number objects. (b) Color constructor stores raw target argument as own "target" property for all types. (c) Color.setRGB also uses varToDoubleSWF. Color-v5: 14→4 failures, Color-v7/v8: 18→8 failures each.
16. ~~**Try/finally control flow** — Try-v6/v7/v8 runtime errors.~~ **FIXED**
17. ~~**Built-in prototype own toString/valueOf**~~ — DONE (2026-03-23). Number.prototype, String.prototype, Boolean.prototype now have their own valueOf/toString methods distinct from Object.prototype's. Fixed in three locations: primary g_ctors, secondary constructors, and actionGetVariable special handlers.
18. ~~**Function.prototype.apply/call as properties**~~ — DONE (2026-03-23). apply and call registered as own properties on Function.prototype (both primary and secondary version groups).

**Phase 2 impact**: Line-level improvements across 15 tests (51 fewer mismatched lines). toString_valueOf +12 lines each, Number +2 each, String +1-3 each. Note: Boolean/Video/Selection-v5/Stage-v5 were already passing from Phase 1 fixes (CURRENT_STATUS.md was stale).

### Phase 3: Individual test fixes
12. TextFieldHTML htmlText getter
13. Cross-frame ConstantPool persistence
14. More ASnative classes (103=Date, 106=Number, 252=String, etc.)
