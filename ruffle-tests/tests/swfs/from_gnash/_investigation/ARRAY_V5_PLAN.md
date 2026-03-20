# array-v5 Investigation Plan
<!-- TESTS: array-v5 -->

Last updated: 2026-03-19

## Status: INVESTIGATED — root causes identified, not yet fixed

---

## Overview

The `array-v5` test exercises extensive Array operations (560 expected lines) and crashes with `heap_alloc(16) failed - out of memory` after producing ~108 lines. Compilation takes ~72 seconds due to the massive `script_2.c` (70,731 lines). The test is marked `known_failure = true` in its `test.toml`.

## Root Causes (Three Categories)

### 1. Missing Array.prototype Methods (Primary — blocks majority of test)

`typeof(Array.prototype.concat/join/pop/push/reverse/shift/slice/sort/sortOn/splice/unshift)` all return `'undefined'` instead of `'function'`. Only `toString` is present on the prototype.

**Impact**: Lines 13-23 (typeof checks), lines 34-36 (method existence), and most downstream assertions fail because calling undefined methods produces no results.

**Fix**: Register all Array.prototype methods as ASFunction objects. Many of these methods already exist as internal C implementations (the AVM1 suite exercises them successfully via direct array operations), but they're not exposed as callable properties on `Array.prototype`.

**Estimated effort**: Medium. The runtime has `actionArraySort`, `actionArrayJoin`, etc. — need to wrap them in ASFunction objects and register on the prototype, similar to how Math methods are registered on `g_math_object`.

### 2. Array.toString Returns `[object Object]` (lines 54, 72-74)

`a.toString()` returns `[object Object]` instead of comma-separated values. The Array type falls through to `Object.prototype.toString` rather than using `Array.prototype.toString`.

**Root cause**: Same as #1 — `Array.prototype.toString` is not properly bound. The existing `toString` that "works" (line 24) may be testing the typeof, not actually calling it.

**Fix**: Ensure Array instances' prototype chain correctly resolves `toString` to the array-specific implementation that returns comma-separated values.

### 3. OOM After ~108 Lines (Heap Exhaustion)

After producing ~108 lines of output, `heap_alloc(16)` fails. The test performs hundreds of array operations (create, splice, sort, concat, etc.) that allocate strings and array elements. With a 1 GB heap, this suggests either:

- **Memory leak**: Array elements or string concatenation results not being freed during operations
- **Fragmentation**: Many small allocations leaving the heap in a fragmented state
- **Exponential growth**: Some array operation creating unexpectedly large intermediate results

**Investigation needed**: Run with heap tracking to identify which operations are consuming the most memory. The fact that it fails at 16 bytes (not a large allocation) strongly suggests fragmentation or leak rather than genuinely needing more memory.

**Fix complexity**: Depends on root cause. Could be a simple free() in the right place, or could require a more fundamental allocation strategy change.

## Recommended Fix Order

### Phase 1: Array.prototype Method Registration (est. +200 lines matching)

Register all standard Array.prototype methods as ASFunction objects:

```
concat, join, pop, push, reverse, shift, slice, sort, sortOn, splice, unshift, toString
```

Implementation pattern — same as Math object:
1. Create static `g_array_funcs[12]` ASFunction array
2. Create `g_array_prototype` singleton ASObject
3. Lazy init via `initArrayPrototype()`
4. Register each method as an ASFunction with a Function2Ptr that dispatches to the existing C implementation
5. Set `Array.prototype = g_array_prototype` and ensure new arrays get `__proto__ = g_array_prototype`

### Phase 2: Sort Algorithm Fixes (est. +20 lines matching)

- `Array.DESCENDING` flag produces reversed order
- Custom comparator `this` binding is wrong (`object` instead of `undefined`)
- `sortOn` results are reversed

### Phase 3: OOM Investigation (est. enables remaining ~250 lines)

Profile heap usage during the test to find the leak. Likely candidates:
- `actionArraySplice` not freeing removed elements
- `actionAdd2` string concatenation creating temporary strings that aren't freed
- Array resize operations not freeing old backing arrays

## Dependencies

- No dependencies on other fixes
- Shares patterns with the AVM1 suite's Array tests (which pass) — can reference those implementations

## Test Details

| Metric | Value |
|--------|-------|
| Expected output | 560 lines |
| Current output | ~108 lines (then OOM) |
| Match rate | ~46/560 (8.2%) |
| Compilation time | ~72 seconds |
| Script size | 70,731 lines (script_2.c) |
| SWF version | 5 |
| num_frames | 30 |
