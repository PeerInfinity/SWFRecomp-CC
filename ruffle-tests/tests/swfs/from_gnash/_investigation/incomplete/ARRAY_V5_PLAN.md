# array-v5 Investigation Plan
<!-- TESTS: array-v5 -->

Last updated: 2026-03-29

## Status: IN PROGRESS — 440/560 lines match (78.6%), 112 remaining failures

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

## Remaining Failures (112 lines, categorized)

### Category A: typeof(f) == "undefined" (3 lines)
**Lines**: 34-36 — `typeof(f)` where `f = Array.prototype.concat`
**Root cause**: Variable `f` assigned via SWF5 Dejagnu harness interaction; the variable reference doesn't preserve the function.
**Complexity**: High (deep runtime interaction)

### Category B: Standalone prototype method calls (25 lines)
**Lines**: 157-159, 161-163, 173, 176, 179-196 — pop(), concat(), slice() called via `.call()` in SWF5
**Root cause**: SWF5 doesn't support Function.prototype.call/apply. `builtin_array_method` returns undefined.
**Complexity**: High — SWF5 limitation, would need to add SWF5 call/apply to builtin_array_method

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
**Root cause**: Dual Array constructor (`g_array_constructor` vs `g_ctors[1]`), different prototype_obj.

### Category H: __resolve + toString override (7 lines)
**Lines**: 544-550, 557

### Other (2 lines)
**Line 132**: `int(-2147483649)` wrapping behavior

## Key Finding: Dual Array Constructor
Two separate Array constructors exist (`g_array_constructor` from `actionGetVariable` and `g_ctors[1]` from `ensureGlobalInit`). They have different `prototype_obj` pointers until both are initialized. This can cause `instanceof` mismatches.

## Recommended Next Steps

1. **Accept Gnash-specific sort diffs** — Category C sort lines (~50) confirmed as algorithm-dependent. Consider adding to accepted diffs.
2. **Fix dual Array constructors** — Category G, ~4 lines. Moderate effort.
3. **Accept ASSetPropFlags limitation** — Categories D (partial) and F. ASSetPropFlags on arrays is unimplemented.
4. **Categories B+E blocked on SWF5** — 43 lines. Would need SWF5-compatible array method dispatch.
5. **Category H needs __resolve on arrays** — 7 lines.

## Test Details

| Metric | Value |
|--------|-------|
| Expected output | 560 lines |
| Current matching | ~440 lines (78.6%) |
| Remaining failures | ~112 lines |
| Compilation time | ~72 seconds |
| Script size | 70,731 lines (script_2.c) |
| SWF version | 5 |
| num_frames | 30 |
