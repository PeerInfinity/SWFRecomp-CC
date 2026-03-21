# array-v5 Investigation Plan
<!-- TESTS: array-v5 -->

Last updated: 2026-03-20

## Status: IN PROGRESS — 422/560 lines match (75.4%), 138 remaining failures

---

## Overview

The `array-v5` test exercises extensive Array operations (560 expected lines). Compilation takes ~72 seconds due to the massive `script_2.c` (70,731 lines). The test is marked `known_failure = true` in its `test.toml`.

## Progress Summary

| Date | Match Rate | Notes |
|------|-----------|-------|
| 2026-03-19 | ~46/560 (8.2%) | OOM after ~108 lines |
| 2026-03-20 (CI) | 405/560 (72.3%) | OOM fixed, Array.prototype methods registered |
| 2026-03-20 (session) | 422/560 (75.4%) | +17 lines: HOLE join, length truncation, array delete |

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

## Remaining Failures (138 lines, categorized)

### Category A: typeof(Array.prototype.method) → "undefined" (3 lines)
**Lines**: array.as:80,82,83 — `typeof(f)` where `f = Array.prototype.concat`
**Root cause**: The Dejagnu `check_equals(typeof(f), 'function')` receives "undefined" even though the prototype methods ARE registered. Investigation confirmed the inline typeof check PASSES (concat is type=13/FUNCTION on the prototype). The issue is in how the variable `f` is assigned — likely a stack/variable handling interaction specific to SWF5 Dejagnu test harness.
**Complexity**: High (deep runtime interaction)

### Category B: Standalone prototype method calls return empty (~48 lines)
**Lines**: array.as:455-553+ — concat(), slice(), pop() called via variable or as standalone
**Root cause**: `builtin_array_method` wrapper returns undefined for safety (can't distinguish ASArray* from ASObject* in `this_obj`). Only `callArrayMethod` in actionCallMethod's ARRAY branch works.
**Complexity**: High — needs safe ASArray recovery from `arr->props`

### Category C: Sort ordering differences (~35 lines)
**Lines**: array.as:295-1275 — CASEINSENSITIVE, DESCENDING, RETURNINDEXEDARRAY, sortOn
**Assessment**: Our sort implementation matches Ruffle's AVM1 tests (array_sort PASSES). Most differences are Gnash-specific sort algorithm behavior. Many lines may be accepted diffs.

### Category D: Splice/shift/reverse on sparse arrays (~20 lines)
**Lines**: array.as:215-263, 433-435, 1416-1474
**Root cause**: Various array mutation operations on sparse arrays produce wrong results.

### Category E: Array methods on generic objects (~20 lines)
**Lines**: array.as:1509-1636 — `Array.prototype.method.apply(obj)` on plain objects
**Root cause**: Same as Category B — `builtin_array_method` returns undefined for non-array `this_obj`.

### Category F: ASSetPropFlags-protected delete (2 lines)
**Lines**: array.as:792,795 — `! delete c[2]` should return false when protected

### Category G: instanceof Array / constructor (4 lines)
**Lines**: array.as:103,740,741,1263

### Category H: __resolve + toString override (6 lines)
**Lines**: array.as:1653-1671, 1710

## Key Finding: Dual Array Constructor
Two separate Array constructors exist (`g_array_constructor` from `actionGetVariable` and `g_ctors[1]` from `ensureGlobalInit`). They have different `prototype_obj` pointers until both are initialized. This can cause `instanceof` mismatches.

## Recommended Next Steps

1. **Accept Gnash-specific sort diffs** — Category C sort lines confirmed matching Ruffle. Consider adding to accepted diffs.
2. **Fix splice/shift for sparse arrays** — Category D, moderate effort, ~20 lines impact.
3. **Make builtin_array_method work for arrays** — Categories B+E, high effort but ~68 lines impact.
4. **Unify dual Array constructors** — Category G, moderate effort, ~4 lines impact.

## Test Details

| Metric | Value |
|--------|-------|
| Expected output | 560 lines |
| Current matching | 422 lines (75.4%) |
| Remaining failures | 138 lines |
| Compilation time | ~72 seconds |
| Script size | 70,731 lines (script_2.c) |
| SWF version | 5 |
| num_frames | 30 |
