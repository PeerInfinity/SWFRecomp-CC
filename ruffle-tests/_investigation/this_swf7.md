# this_swf7 Test Investigation

## Test Overview

Tests `this` keyword behavior in SWF7 (case-sensitive mode). Checks `this` value, typeof, and
case-sensitivity (`this` vs `tHiS` vs `THIS`) across contexts: main timeline, function call,
`new` constructor, `with` block, and `SetTarget`.

### SWFRecomp result: FAIL — 37/41 lines match

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

## Remaining Issues (4 lines differ)

### 1. Extra output lines: 63 actual vs 41 expected (~14 extra lines)

Our output has 8 blocks of ~8 lines. Expected has 6 blocks.

The script uses `with(o)` and `with(_root)` blocks. Our runtime appears to execute code
both inside and after each `with` block, producing 2 extra blocks.

**Possible causes:**
- `with` implementation doesn't correctly scope execution (running code both inside
  and after `with` that Flash would only run once)
- The `with(_root)` block may change `this` resolution differently in Flash

### 2. trace(this) in new f() context

```
Expected: [object Object]   (this = newly created Object)
Actual:   [type Object]
```

The `new f()` constructor context creates a new object for `this`, but somehow it
doesn't have Object.prototype set as `__proto__`, so trace falls back to `[type Object]`
instead of getting `[object Object]` from Object.prototype.toString.

---

## Fix priority

1. **Extra output lines**: Needs investigation into `with` block scoping behavior
2. **new f() this object**: Needs the object created by `new` for non-named constructors
   to have Object.prototype linked via `__proto__`
