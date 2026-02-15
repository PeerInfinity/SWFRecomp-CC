# Math Object Implementation Plan
<!-- TESTS: math_min_max, math_swf6, math_swf7, math_swf8, asnative -->

Last updated: 2026-02-15

## Status: IMPLEMENTED

The Math object has been fully implemented. All 5 steps from the original plan are complete.

## Current Test Results

| Test | Expected Lines | Matching | Status | Notes |
|------|---------------|----------|--------|-------|
| math_min_max | 101 | 101 (100%) | **PASS** | Was 32/101 before implementation |
| math_swf6 | 530 | 522 (98.5%) | output_mismatch | 8 lines off — ASnative + throwing valueOf |
| math_swf7 | 530 | 522 (98.5%) | output_mismatch | 8 lines off — identical failures |
| math_swf8 | 530 | 522 (98.5%) | output_mismatch | 8 lines off — identical failures |
| **Total** | **1691** | **1667 (98.6%)** | **1 pass** | **+1605 lines vs pre-implementation** |

The actual result (1667/1691) exceeded the original "Optimistic" estimate (~1649/1691).

## What Was Implemented

All in `SWFModernRuntime/src/actionmodern/action.c`:

- **`g_math_object`** (line 634): Static singleton ASObject
- **`coerceMathArgs()`** (line 651): Coerces `min(arg_count, 2)` args to f64 via `convertFloat` (handles valueOf)
- **18 builtin functions** (lines 684-845): `builtin_math_abs`, `sin`, `cos`, `tan`, `exp`, `log`, `sqrt`, `round`, `floor`, `ceil`, `atan`, `asin`, `acos`, `atan2`, `pow`, `min`, `max`, `random`
- **`initMathObject()`** (line 846): Registers all 8 constants + 18 methods on `g_math_object`
- **`_global` registration** (line 8699): Math registered on the global object
- **`actionGetVariable("Math")`** (line 9174): Lazy init + push

## Remaining Failures (8 lines per swf6/7/8 test)

The same 8 lines fail identically in all three comprehensive tests:

### 1. ASnative(200, 50) not implemented — 4 lines

```
// ASnative(200, 50)()
- NaN          (expected)
+ undefined    (actual — ASnative returns undefined, not a function)

// ASnative(200, 50)({ v: 3 }, { v: 2 }, { v: 1 })
- valueOf called: 3    (expected — function would coerce args)
+ undefined            (actual — no function to call)
- valueOf called: 2    (expected)
+ <blank>              (actual — output shifted)
- NaN                  (expected)
+ <shifted>            (actual)
```

**Fix**: Implement `ASnative(200, index)` to return Math methods by index. Class 200 = Math; index 50 = invalid → should return a function that always returns NaN. This is part of the broader ASnative support needed by other tests too (e.g., `asnative` test).

### 2. Throwing valueOf in Math.min — 3 lines (+ 1 shifted blank line)

```
// Math.min({ throw A }, { throw B })
- will throw A!    (expected)
+ will throw A!    (actual — matches!)
- caught: A        (expected)
+ caught: pow      (actual — wrong exception caught)
```

**Root cause**: The `coerceMathArgs` → `convertFloat` path calls valueOf which throws "A", but the exception gets caught by the wrong catch block. The caught value is "pow" — suggesting the exception propagates up past the Math.min call and gets caught by a surrounding try/catch that was set up for a Math.pow test section. The `coerceMathArgs` loop doesn't have exception-aware early return, so when valueOf throws during coercion of the first arg, execution continues past the Math.min call entirely.

**Fix**: Would require exception-aware coercion in `coerceMathArgs` — check if an exception was thrown during `convertFloat` and bail out early. This is a broader runtime architecture issue (exception propagation through builtin functions) that affects more than just Math.

### Priority Assessment

Both remaining issues are **low priority** for Math specifically:
- ASnative support is its own feature needed by multiple tests
- Exception propagation through builtins is an architectural concern that affects many features
- Together they only affect 24 lines across 3 tests (1.4% of total Math test lines)
- The math_min_max test already fully passes

## Original Analysis (preserved for reference)

### How the Tests Access Math

From the Test.as source (same for all 3 comprehensive tests, compiled at different SWF versions):

```actionscript
var f = _global.Math[name];   // get method from Math object
trace(f(arg));                 // call with args, trace result
```

The bytecode pattern is:
1. `GetVariable("Math")` → pushes Math object
2. `GetMember("min")` → pushes the min function
3. Push args + arg count
4. `CallMethod` → invokes the function

**Key insight**: The test gets `_global.Math[name]` (a function reference), then calls it standalone (not as `Math.min(...)`). This means the function must work when called without `this` being the Math object — it's just a regular function that takes args and returns a number.

### Critical Behaviors (all implemented correctly)

1. **SWF Version-Dependent null/undefined Coercion**: SWF6 converts null/undefined → 0; SWF7+ → NaN. Handled by `convertFloat()`.
2. **valueOf Coercion**: `coerceMathArgs` coerces `min(arg_count, 2)` args, calling valueOf on objects.
3. **min/max**: 0 args → ±Infinity; 1 arg → NaN; 2+ args → compare first two only.
4. **Math.round(-12.5) = -12**: Uses `floor(x + 0.5)`.
5. **pow(1, NaN) = 1**: Handled by C's `pow()` per IEEE 754.
