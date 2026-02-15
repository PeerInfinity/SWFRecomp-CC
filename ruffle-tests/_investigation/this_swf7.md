# this_swf7 Test Investigation
<!-- TESTS: this_swf7 -->

## Test Overview

Tests `this` keyword behavior in SWF7 (case-sensitive mode). Checks `this` value, typeof, and
case-sensitivity (`this` vs `tHiS` vs `THIS`) across contexts: main timeline, function call,
`new` constructor, `with` block, and `SetTarget`.

### SWFRecomp result: FAIL — 37/41 lines match (actual=55), 4 lines differ + 14 extra lines

---

## Fixes Applied

### 1. actionTrace MovieClip → _level0 (fixed)

Same fix as issue_768: separated MOVIECLIP from OBJECT in actionTrace.

### 2. actionTypeOf MovieClip → "movieclip" (fixed)

Separated MOVIECLIP case in actionTypeOf:
```c
case ACTION_STACK_VALUE_MOVIECLIP:
    type_str = "movieclip";
    break;
```

### 3. Object.prototype.toString → "[object Object]" (fixed)

Created global Object.prototype with built-in toString returning `[object Object]`.
User-created objects (via `new` or `InitObject`) get `__proto__` set to Object.prototype.
This makes `trace(new f())` print `[object Object]` instead of `[type Object]`.

---

## Remaining Issues

### 1. Extra output lines: 55 actual vs 41 expected (14 extra lines)

Our output has 8 blocks of ~7 lines. Expected has 6 blocks.

The script uses `with(o)` and `with(_root)` blocks. Our runtime appears to execute code
both inside and after each `with` block, producing 2 extra blocks of ~7 lines each.

**Possible causes:**
- `with` implementation doesn't correctly scope execution (running code both inside
  and after `with` that Flash would only run once)
- The `with(_root)` block may change `this` resolution differently in Flash

### 2. trace(this) in `new f()` context (1 line)

```
Expected: [object Object]   (this = newly created Object)
Actual:   [type Object]
```

The `new f()` constructor context creates a new object for `this`, but it doesn't have
Object.prototype set as `__proto__`, so trace falls back to `[type Object]` instead of
getting `[object Object]` from Object.prototype.toString.

**Root cause:** The object created by `actionNewObject` for non-named constructors
(type-1 DefineFunction) may not be getting `__proto__` → Object.prototype linked.

### 3. trace(this) in `f()` call context (1 line)

```
Expected: _level0            (this = root MovieClip in function call)
Actual:   [type Object]
```

When calling a function normally (not as constructor), `this` should be the root
MovieClip (`_level0`). Our runtime may be providing a different `this` value or
the function's `this` is not properly set to the calling context.

---

## Fix priority

1. **Extra output lines**: `with` block scoping produces duplicate output — needs
   investigation into how ActionWith interacts with the execution model
2. **new f() this object**: Ensure objects created by `new` for DefineFunction constructors
   get `__proto__` → Object.prototype
3. **f() call this**: Ensure plain function calls set `this` to the calling context
   (root MovieClip for top-level calls)
