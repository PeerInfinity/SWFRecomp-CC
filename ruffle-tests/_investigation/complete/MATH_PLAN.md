# Math Object Implementation Plan
<!-- TESTS: math_min_max, math_swf6, math_swf7, math_swf8, asnative -->

Last updated: 2026-02-20

## Status: FULLY COMPLETE ✅

All 4 math tests pass (530/530, 101/101). Moved to complete/.

## Final Test Results

| Test | Expected Lines | Matching | Status | Notes |
|------|---------------|----------|--------|-------|
| math_min_max | 101 | 101 (100%) | **PASS** | |
| math_swf6 | 530 | 530 (100%) | **PASS** | |
| math_swf7 | 530 | 530 (100%) | **PASS** | |
| math_swf8 | 530 | 530 (100%) | **PASS** | |
| **Total** | **1691** | **1691 (100%)** | **4/4 pass** | |

## What Was Implemented (all in `SWFModernRuntime/src/actionmodern/action.c`)

### Phase 1: Core Math object (2026-02-15)
- **`g_math_object`**: Static singleton ASObject
- **`coerceMathArgs()`**: Coerces `min(arg_count, 2)` args to f64 via `convertFloat` (handles valueOf)
- **18 builtin functions**: `builtin_math_abs`, `sin`, `cos`, `tan`, `exp`, `log`, `sqrt`, `round`, `floor`, `ceil`, `atan`, `asin`, `acos`, `atan2`, `pow`, `min`, `max`, `random`
- **`initMathObject()`**: Registers all 8 constants + 18 methods on `g_math_object`
- **`_global` registration**: Math registered on the global object
- **`actionGetVariable("Math")`**: Lazy init + push

### Phase 2: ASnative(200, index) dispatch (2026-02-20)
- **`builtin_math_nan_stub()`**: Coerces args (calling valueOf side-effects) then returns NaN — used for invalid Math indices
- **`builtin_asnative()`**: `_global.ASnative(class_id, method_index)` — returns the Math function at `method_index` for class 200, or the NaN stub for out-of-range indices (e.g., index 50)
- **`g_asnative_func`**: Registered as `"ASnative"` on `_global`
- **Forward declaration** added for `initMathObject` to allow `builtin_asnative` to call it before its definition

## Key Behaviors

1. **SWF Version-Dependent null/undefined Coercion**: SWF6 converts null/undefined → 0; SWF7+ → NaN. Handled by `convertFloat()`.
2. **valueOf Coercion**: `coerceMathArgs` coerces `min(arg_count, 2)` args, calling valueOf on objects.
3. **min/max**: 0 args → ±Infinity; 1 arg → NaN; 2+ args → compare first two only.
4. **Math.round(-12.5) = -12**: Uses `floor(x + 0.5)`.
5. **pow(1, NaN) = 1**: Handled by C's `pow()` per IEEE 754.
6. **ASnative(200, n)**: Valid index (0–17) → corresponding Math function; invalid index → NaN stub that still coerces args via valueOf.
7. **Throwing valueOf in Math.min**: Exception propagates correctly out of `coerceMathArgs` → `convertFloat` → caught by surrounding try/catch.

## Notes

- The "throwing valueOf" issue mentioned in the previous plan was already fixed before phase 2 (the `caught: pow` bug was gone; only output shifting caused by the ASnative lines made it look broken).
- The ASnative fix resolved all 8 remaining mismatched lines in each of swf6/7/8 tests at once.
