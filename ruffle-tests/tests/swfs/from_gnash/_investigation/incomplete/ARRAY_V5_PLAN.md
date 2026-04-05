# array-v5 Investigation Plan
<!-- TESTS: array-v5 -->

Last updated: 2026-04-04

## Status: IN PROGRESS — 448/560 lines match (80.0%), 112 remaining failures

---

## Overview

The `array-v5` test exercises extensive Array operations (560 expected lines). Compilation takes ~72 seconds due to the massive `script_2.c` (70,731 lines). The test is marked `known_failure = true` in its `test.toml`.

## Progress Summary

| Date | Match Rate | Notes |
|------|-----------|-------|
| 2026-03-19 | ~46/560 (8.2%) | OOM after ~108 lines |
| 2026-03-20 (CI) | 405/560 (72.3%) | OOM fixed, Array.prototype methods registered |
| 2026-03-20 (session) | 422/560 (75.4%) | +17 lines: HOLE join, length truncation, array delete |
| 2026-03-29 (session) | 440/560 (78.6%) | +18 lines: HOLE sort, concat/splice densify, sortOn UNIQUESORT fix |
| 2026-04-04 (session) | 448/560 (80.0%) | +8 lines: dual Array constructor prototype unification, sort stability |

## Completed Fixes

### 1. OOM After ~108 Lines — FIXED (prior session)
The heap exhaustion bug was fixed in a prior session. All 560 lines of output now produced.

### 2. Array.prototype Method Registration — DONE (prior session)
All standard Array.prototype methods registered as ASFunction objects on `g_array_prototype`.

### 3. HOLE/Sparse Array join/toString — FIXED (commit 0c3e8470)
Array.join() and toString() now produce empty strings for HOLE (missing) elements. +9 lines.

### 4. Array Length Truncation for Negative Values — FIXED (commit c8449aed)
Setting `arr.length = -1` now properly clears all elements using signed comparison. `getArrayElement()` returns NULL when length is negative (signed). +8 lines.

### 5. actionDelete for Array Elements — FIXED (commit f04b08cc)
`actionDelete` now handles: (a) non-string property names (F64 index → convert to string), (b) ARRAY type objects (marks elements as HOLE). +0 net (masked by prior fixes).

### 6. Sort HOLE Comparison (SWF < 7) — FIXED (commit a2002c9a)
`_sort_compare_vars` now treats HOLE elements as empty string ("") for SWF < 7, matching Flash behavior where sparse array holes sort to the beginning. +4 lines.

### 7. Array.concat Densification — FIXED (commit a2002c9a)
HOLE elements are converted to UNDEFINED when copying into concat result arrays, matching Flash behavior where concat fills sparse array holes. +4 lines.

### 8. Array.splice Densification — FIXED (commit a2002c9a)
After splice operations, remaining HOLE elements are converted to UNDEFINED with proper enumeration key tracking. +3 lines.

### 9. sortOn UNIQUESORT Return Value — FIXED (commit a2002c9a)
`sortOn` with UNIQUESORT (without RETURNINDEXEDARRAY) now correctly sorts in-place and returns the array reference. Previously UNIQUESORT was incorrectly combined with the RETURNINDEXEDARRAY code path, returning an index array instead. +17 lines from `tostr(r)` checks.

### 10. Dual Array Constructor Prototype — FIXED (commit 54f14500)
`g_ctors[1]` (the Array constructor registered on `_global` via `ensureGlobalInit`) now has its `prototype_obj` set to `g_array_prototype`, matching `g_array_constructor_static`. Fixes `constructor ==` checks and some `instanceof` checks. +3 lines.

### 11. builtin_array_method Dispatch Infrastructure — DONE (commit 54f14500)
Added `g_call_this_type` global and dispatch logic in `builtin_array_method` so array prototype methods can forward to `callArrayMethod` when invoked via `Function.prototype.call` in the CallMethod path. Infrastructure is in place but doesn't help array-v5 because SWF5 uses a different bytecode path (see Blocker below).

## Remaining Failures (112 lines, categorized)

### Category A: typeof(f) == "undefined" (3 lines)
**Lines**: 34-36 — `typeof(f)` where `f = Array.prototype.concat`
**Root cause**: Variable `f` assigned via SWF5 Dejagnu harness interaction; the variable reference doesn't preserve the function.
**Complexity**: High (deep runtime interaction)

### Category B: Standalone prototype method calls (25 lines)
**Lines**: 157-159, 161-163, 173, 176, 179-196 — pop(), concat(), slice() called via `.call()` in SWF5
**Root cause**: SWF5 `.call()` uses CallFunction bytecode path, not CallMethod. The Function.prototype.call stub (`g_fn_call_func`) has `advanced_func = builtin_noop_func` which returns undefined. The CallMethod "call" handler (which properly dispatches) is not reached.
**Complexity**: High — requires implementing Function.prototype.call dispatch in the CallFunction path or making `builtin_noop_func` non-trivial.
**BLOCKER**: See below.

### Category C: Sort ordering differences (~50 lines)
**Lines**: 103, 106-109, 113-114, 334-342, 351-352, 377-380, 408-431, 450, 456, 459, 461-462
**Root cause**: QuickSort algorithm produces implementation-specific ordering for CASEINSENSITIVE, DESCENDING, and RETURNINDEXEDARRAY. Our sort matches Ruffle's AVM1 tests (array_sort PASSES) but differs from Flash's specific QuickSort partitioning on certain inputs.
**Assessment**: Algorithm-dependent differences. Many are Gnash-specific expected output reflecting Flash's exact sort order.

### Category D: Sparse array operations (10 lines)
**Lines**: 98, 101, 151-154, 252, 485, 491, 493, 495, 499, 503
**Root cause**: Various — gaparray splice return values, sparse reverse, ASSetPropFlags-protected shift/splice
**Note**: Lines 485-506 are about ASSetPropFlags protection during shift/splice (not implemented)

### Category E: Array methods on generic objects (18 lines)
**Lines**: 507-543 — `Array.prototype.method.apply(obj)` on plain objects
**Root cause**: Same as Category B — `builtin_array_method` returns undefined for non-array `this_obj` in SWF5.

### Category F: ASSetPropFlags-protected delete (3 lines)
**Lines**: 278-280 — `! delete c[2]` should return false when protected

### Category G: instanceof Array / constructor (4 lines)
**Lines**: 38, 42, 253-254, 458
**Root cause**: Mixed — lines 38/42 are undefined `a` (Category A overlap). Line 253 `c.constructor` not found. Line 458 `r instanceof Array` where `r` from sortOn has wrong sort order (Category C overlap).
**Partially fixed**: Dual constructor unification (commit 54f14500) improved some lines but 4 remain due to other root causes.

### Category H: __resolve + toString override (7 lines)
**Lines**: 544-550, 557
**Investigation results (2026-04-04)**: The `t` object in the test is an OBJECT type (not ARRAY), so the existing OBJECT __resolve handler already fires for lines 544-545 (now PASS in some runs). Lines 546-550 fail because `t[2] = "om"` doesn't persist when `t` is a plain object accessed via numeric index. Line 557 (`ret == "Array data"`) is a separate toString override issue on an array subclass.

### Other (2 lines)
**Line 132**: `int(-2147483649)` wrapping behavior

## BLOCKER: SWF5 Function.prototype.call/apply Dispatch

**Problem**: When SWF5 code calls `Array.prototype.pop.call(b)`, the bytecode sequence uses GetMember to retrieve the `.call` function from Function.prototype, then invokes it directly. The `.call` function's `advanced_func` is `builtin_noop_func` which returns undefined.

**What's needed**: Either:
1. Make the `g_fn_call_func` advanced_func actually implement Function.prototype.call semantics (extract thisArg, build args, invoke wrapped function), OR
2. Detect in `actionCallFunction` when the function being called IS `g_fn_call_func` and handle it specially

**Impact**: Blocks Category B (25 lines) and Category E (18 lines) = 43 lines total.

**Estimated effort**: Medium-high. Requires careful handling of this-arg extraction, scope management, and multiple function type paths.

## Key Finding: Dual Array Constructor
Two separate Array constructors exist (`g_array_constructor` from `actionGetVariable` and `g_ctors[1]` from `ensureGlobalInit`). They now share the same `prototype_obj` after the fix in commit 54f14500.

## Recommended Next Steps

1. **Accept Gnash-specific sort diffs** — Category C sort lines (~50) confirmed as algorithm-dependent. Consider adding to accepted diffs.
2. **Implement Function.prototype.call** — Category B+E blocker. Would fix 43 lines but requires significant effort.
3. **Accept ASSetPropFlags limitation** — Categories D (partial) and F. ASSetPropFlags on arrays is unimplemented.
4. **Category H deeper investigation** — The `t[2] = "om"` failure on plain objects with numeric properties needs investigation separate from __resolve.

## Test Details

| Metric | Value |
|--------|-------|
| Expected output | 560 lines |
| Current matching | ~448 lines (80.0%) |
| Remaining failures | ~112 lines |
| Compilation time | ~72 seconds |
| Script size | 70,731 lines (script_2.c) |
| SWF version | 5 |
| num_frames | 30 |
