# Math Object Implementation Plan

Last updated: 2026-02-14

## Overview

The Math object is a global singleton (not a constructor) with 17 static methods and 8 constants. It's one of the simpler built-in objects to implement because it has no prototype chain complexity, no instance state, and every method is a straightforward mathematical function backed by C's `<math.h>`.

**Current state**: Math object is completely missing. `GetVariable("Math")` falls through to undefined. All 4 tests return `undefined` for every Math method call. 32/101 lines pass on math_min_max (only the comment lines match), 10/530 on math_swf6/7/8.

**Impact**: 4 tests (math_min_max, math_swf6, math_swf7, math_swf8) = 1691 expected lines total. Also partially unblocks globals_swf5/6/7/8 tests (which check `typeof(Math)` → `"object"`).

## Test Inventory

| Test | Expected Lines | Current Match | SWF Version | Notes |
|------|---------------|---------------|-------------|-------|
| math_min_max | 101 | 32 (32%) | 8 | min/max edge cases, valueOf coercion |
| math_swf6 | 530 | 10 (2%) | 6 | All 17 methods, null/undefined → 0 |
| math_swf7 | 530 | 10 (2%) | 7 | All 17 methods, null/undefined → NaN |
| math_swf8 | 530 | 10 (2%) | 8 | Same as SWF7 |

## How the Tests Access Math

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

## Methods and Constants Required

### 13 Unary Methods (one numeric arg)

| Method | C function | Special edge cases |
|--------|-----------|-------------------|
| abs | `fabs(x)` | abs(-0) = 0, abs(NaN) = NaN |
| sin | `sin(x)` | sin(±Infinity) = NaN |
| cos | `cos(x)` | cos(±Infinity) = NaN |
| tan | `tan(x)` | tan(±Infinity) = NaN |
| exp | `exp(x)` | exp(-Infinity) = 0 |
| log | `log(x)` | log(0) = -Infinity, log(-x) = NaN |
| sqrt | `sqrt(x)` | sqrt(-x) = NaN |
| round | `floor(x + 0.5)` | round(-0.5) = 0 (not -1!), round(-12.5) = -12 |
| floor | `floor(x)` | standard |
| ceil | `ceil(x)` | standard |
| atan | `atan(x)` | atan(±Infinity) = ±π/2 |
| asin | `asin(x)` | asin(x) where |x|>1 = NaN |
| acos | `acos(x)` | acos(x) where |x|>1 = NaN |

### 3 Binary Methods (two numeric args)

| Method | C function | Special edge cases |
|--------|-----------|-------------------|
| atan2 | `atan2(y, x)` | Needs exactly 2 args; 1 arg → missing arg is undefined |
| pow | `pow(base, exp)` | pow(x, 0) = 1 for any x; pow(1, NaN) varies |
| min | custom | 0 args → Infinity; 1 arg → NaN; NaN propagates; exactly 2 args |
| max | custom | 0 args → -Infinity; 1 arg → NaN; NaN propagates; exactly 2 args |

### 1 Nullary Method

| Method | Notes |
|--------|-------|
| random | Already implemented (TRandomFast RNG). Returns [0, 1) |

### 8 Constants

| Constant | Value |
|----------|-------|
| PI | 3.14159265358979... |
| E | 2.71828182845905... |
| LN2 | 0.693147180559945... |
| LN10 | 2.30258509299405... |
| LOG2E | 1.44269504088896... |
| LOG10E | 0.434294481903252... |
| SQRT2 | 1.4142135623731... |
| SQRT1_2 | 0.707106781186548... |

The comprehensive tests use `Math.PI` to compute `Math.sin(Math.PI/2)` → 1, so constants must be present.

## Critical Behaviors

### 1. SWF Version-Dependent null/undefined Coercion

The only difference between math_swf6 and math_swf7/8 is how null/undefined convert to numbers:

| Input | SWF6 (< 7) | SWF7+ (≥ 7) |
|-------|------------|-------------|
| null | 0 | NaN |
| undefined | 0 | NaN |

This is already handled by `convertFloat()` in action.c (lines 4852-4877) via `#if SWF_VERSION >= 7`. Since SWF_VERSION is a compile-time constant, the Math builtin functions need to use the same coercion path. The simplest approach: push the arg, call `convertFloat()`, read the result.

### 2. valueOf Coercion on ALL Arguments (Even Unused Ones)

When calling `Math.abs({v: 2}, {v: 1})`, the test expects:
```
valueOf called: 2
valueOf called: 1
2
```

Even though `abs` only uses one argument, ALL arguments have their `valueOf()` called (in order, left to right). This is because Flash coerces all args to numbers eagerly before the function executes. The pattern with 3 args confirms this: only the first 2 are coerced (the function's declared arg count), NOT all 3 — wait, let me recheck:

From the test output for `Math.abs({v: 3}, {v: 2}, {v: 1})`:
```
valueOf called: 3
valueOf called: 2
3
```

Only 2 valueOf calls for 3 args passed. But `Math.abs` takes 1 arg. Let me check `Math.sin({v: 2}, {v: 1})`:
```
valueOf called: 2
valueOf called: 1
0.909297426825682
```

And `Math.sin({v: 3}, {v: 2}, {v: 1})`:
```
valueOf called: 3
valueOf called: 2
0.141120008059867
```

**Pattern**: For N args passed, valueOf is called on the first N-1 args? No — for sin with 2 args, both valueOf are called. For sin with 3 args, first 2 valueOf called. For abs with 2 args, both valueOf called. For abs with 3 args, first 2 valueOf called.

The pattern is: **Flash coerces the first `max(declared_params, passed_args - 1) + 1`... no wait.

Let me look more carefully:
- `abs(obj2, obj1)` → 2 args passed, 2 valueOf calls
- `abs(obj3, obj2, obj1)` → 3 args passed, 2 valueOf calls (first 2 only)
- `sin(obj2, obj1)` → 2 args passed, 2 valueOf calls
- `sin(obj3, obj2, obj1)` → 3 args passed, 2 valueOf calls (first 2 only)
- `min(obj2, obj1)` → 2 args passed, 2 valueOf calls
- `min(obj3, obj2, obj1)` → 3 args passed, 2 valueOf calls (first 2 only)

**Conclusion**: Flash always coerces exactly the first 2 arguments, regardless of how many are passed or how many the function declares. This is specific to Math methods — they each declare a fixed parameter count in Flash's internal ASnative table, and Flash coerces exactly that many args (capped at args passed).

Actually, re-examining: the functions tested with 2/3 args are either unary (abs, sin, cos, etc. — 1 declared param) or binary (min, max, atan2, pow — 2 declared params). With 2 args: both coerced. With 3 args: first 2 coerced.

This means: **coerce min(args_passed, 2) arguments**. For unary functions: the declared param count is 1 but still 2 args get coerced when 2 are passed. So the pattern is actually: **coerce min(args_passed, max(declared_params, 2)) arguments**? But that gives 2 for unary with 2 args (correct) and 2 for unary with 3 args (correct).

Simpler: Flash Math methods internally call `toNumber()` on args[0..N-1] where N = min(num_args, max_expected_args). The "max expected args" for all tested methods appears to be 2.

For simplicity, since the builtin function receives args and arg_count, we should:
1. Coerce `min(arg_count, 2)` arguments to number (calling valueOf as needed)
2. Use the coerced values for computation

### 3. min/max Require Exactly 2 Arguments

Unlike JavaScript's `Math.min(a, b, c, ...)`, Flash's `Math.min` and `Math.max` take exactly 2 args:
- 0 args: min → Infinity, max → -Infinity
- 1 arg: NaN (missing second arg)
- 2 args: compare and return
- 3+ args: ignores args beyond 2nd (but still coerces first 2)

### 4. Math.round(-12.5) = -12 (NOT -13)

Flash's Math.round uses "round half away from zero" for positive numbers but "round half toward zero" for negative numbers:
- `round(12.5)` = 13 (rounds up)
- `round(-12.5)` = -12 (rounds toward zero)

This matches `floor(x + 0.5)` behavior.

### 5. ASnative(200, 50) — Invalid Index

The test calls `ASnative(200, 50)` (class 200 = Math, index 50 = invalid) and expects it to return a function that always returns NaN. We don't need to implement the full ASnative table, but the test expects this to work. For now, this will likely fail (2 lines), which is acceptable.

### 6. Throwing valueOf

The test creates objects whose `valueOf` throws, then calls `Math.min(throwA, throwB)`. Expected:
```
will throw A!
caught: A
```

This means valueOf is called left-to-right and an exception from the first arg stops coercion of the second. This requires the coercion process to propagate exceptions. **This may be hard** if our coercion path doesn't support exception propagation. We can defer this (3 lines).

---

## Implementation Plan

This is a single-phase implementation — the Math object is simple enough to implement all at once.

### Step 1: Create the Math Object in actionGetVariable

Add a `"Math"` case in `actionGetVariable()` (alongside "Array", "String", etc.) that lazily initializes a static `ASObject` with all methods and constants.

```c
else if (var_name_len == 4 && strncmp(var_name, "Math", 4) == 0)
{
    static ASObject* g_math_object = NULL;
    if (g_math_object == NULL)
    {
        g_math_object = allocObject(app_context, 32);
        retainObject(g_math_object);
        initMathObject(app_context, g_math_object);
    }
    PUSH(ACTION_STACK_VALUE_OBJECT, (u64)g_math_object);
    return;
}
```

Also register Math on `_global` in the `_global` init block so `_global.Math[name]` works.

### Step 2: Implement initMathObject()

Register all 17 methods as `ASFunction` objects with `function_type=2` and `advanced_func` pointing to builtin C functions. Register all 8 constants as F64 properties.

```c
static void initMathObject(SWFAppContext* app_context, ASObject* math_obj)
{
    // Constants
    setF64Property(math_obj, "PI", M_PI);
    setF64Property(math_obj, "E", M_E);
    setF64Property(math_obj, "LN2", M_LN2);
    setF64Property(math_obj, "LN10", M_LN10);
    setF64Property(math_obj, "LOG2E", M_LOG2E);
    setF64Property(math_obj, "LOG10E", M_LOG10E);
    setF64Property(math_obj, "SQRT2", M_SQRT2);
    setF64Property(math_obj, "SQRT1_2", M_SQRT1_2);

    // Methods (each is a static ASFunction)
    registerMathMethod(app_context, math_obj, "abs", builtin_math_abs);
    registerMathMethod(app_context, math_obj, "sin", builtin_math_sin);
    // ... etc for all 17 methods
}
```

### Step 3: Implement Argument Coercion Helper

All Math methods share the same argument coercion pattern: coerce up to 2 args to f64 (calling valueOf on objects), using the existing `convertFloat` / stack-based coercion.

```c
// Coerce args[0..min(arg_count,max_args)-1] to f64 in-place
// Returns early with NaN result if coercion throws (future: exception support)
static void coerceMathArgs(SWFAppContext* app_context, ActionVar* args, u32 arg_count, u32 max_args)
{
    u32 n = arg_count < max_args ? arg_count : max_args;
    for (u32 i = 0; i < n; i++)
    {
        // Push arg, convert to float, pop back
        pushVar(app_context, &args[i]);
        convertFloat(app_context);
        popVar(app_context, &args[i]);
    }
}
```

### Step 4: Implement Each Builtin Function

Each function follows the same pattern:

```c
static ActionVar builtin_math_abs(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    coerceMathArgs(app_context, args, arg_count, 2);

    ActionVar ret;
    ret.type = ACTION_STACK_VALUE_F64;

    if (arg_count == 0) {
        double nan = NAN;
        VAL(u64, &ret.data.numeric_value) = VAL(u64, &nan);
        return ret;
    }

    double x = VAL(double, &args[0].data.numeric_value);
    double result = fabs(x);
    VAL(u64, &ret.data.numeric_value) = VAL(u64, &result);
    return ret;
}
```

For min/max:

```c
static ActionVar builtin_math_min(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    coerceMathArgs(app_context, args, arg_count, 2);

    ActionVar ret;
    ret.type = ACTION_STACK_VALUE_F64;

    if (arg_count == 0) {
        double inf = INFINITY;
        VAL(u64, &ret.data.numeric_value) = VAL(u64, &inf);
        return ret;
    }
    if (arg_count == 1) {
        double nan = NAN;
        VAL(u64, &ret.data.numeric_value) = VAL(u64, &nan);
        return ret;
    }

    double a = VAL(double, &args[0].data.numeric_value);
    double b = VAL(double, &args[1].data.numeric_value);
    double result;
    if (isnan(a) || isnan(b)) result = NAN;
    else result = (a < b) ? a : b;
    VAL(u64, &ret.data.numeric_value) = VAL(u64, &result);
    return ret;
}
```

For round (special -0.5 behavior):

```c
static ActionVar builtin_math_round(SWFAppContext* app_context, ActionVar* args, u32 arg_count, ActionVar* registers, void* this_obj)
{
    coerceMathArgs(app_context, args, arg_count, 2);
    // ...
    double x = VAL(double, &args[0].data.numeric_value);
    double result = floor(x + 0.5);  // This gives round(-12.5) = -12, round(12.5) = 13
    VAL(u64, &ret.data.numeric_value) = VAL(u64, &result);
    return ret;
}
```

### Step 5: Register Math on _global

In the `_global` initialization block (actionGetVariable, "\_global" case), add:

```c
// Register Math on _global
initMathObject(app_context, ...);
setProperty(app_context, global_object, "Math", 4, &math_var);
```

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Add `initMathObject()`, 17 `builtin_math_*` functions, coercion helper, `"Math"` case in `actionGetVariable()`, Math registration on `_global` |

No other files need changes. No recompiler changes needed — the bytecode already correctly does `GetVariable("Math")` + `GetMember` + `CallMethod`.

## Expected Results

### Optimistic (all methods correct, coercion correct)

| Test | Before | After | Lines |
|------|--------|-------|-------|
| math_min_max | 32/101 (32%) | ~95/101 (94%) | +63 |
| math_swf6 | 10/530 (2%) | ~518/530 (98%) | +508 |
| math_swf7 | 10/530 (2%) | ~518/530 (98%) | +508 |
| math_swf8 | 10/530 (2%) | ~518/530 (98%) | +508 |
| **Total** | **62/1691** | **~1649/1691** | **+1587** |

The ~12 lines that may not pass:
- ASnative(200, 50) lines (4 lines across tests — needs ASnative support)
- Throwing valueOf lines (3 lines per test — needs exception propagation during coercion)
- Math.random output (1 line per test — uses `#RANDOM#` placeholder, may need special handling in test runner)

### Conservative

Even without valueOf coercion on extra args, throwing valueOf support, or ASnative:

| Test | Estimated | Notes |
|------|-----------|-------|
| math_min_max | ~85/101 | valueOf lines may fail |
| math_swf6 | ~460/530 | valueOf + ASnative + random lines may fail |
| math_swf7 | ~460/530 | Same |
| math_swf8 | ~460/530 | Same |
| **Total** | **~1465/1691 (+1403)** | |

## Implementation Complexity

**Low**. This is one of the simplest features to implement:
- Single file change (action.c)
- No prototype chain complexity
- No instance state
- All math functions map directly to C stdlib
- The argument coercion pattern is uniform across all methods
- The version-dependent behavior (SWF6 vs 7) is already handled by `convertFloat()`

**Estimated effort**: ~200 lines of C code (17 short functions + init + registration + coercion helper).

**Risk**: The valueOf coercion behavior (calling valueOf on extra args) requires pushing to the stack and calling convertFloat, which itself calls valueOf on objects. This should work with the existing infrastructure but needs testing. If it causes issues, we can fall back to simple numeric coercion (no valueOf) and fix it later — this would only affect the "valueOf called: N" trace lines.
