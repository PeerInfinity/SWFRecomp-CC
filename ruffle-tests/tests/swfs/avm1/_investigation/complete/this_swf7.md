# this_swf7 Test Investigation
<!-- TESTS: this_swf7 -->

<!-- PLAN_META
id: this_swf7
status: complete
phases:
  - id: 1
    name: "actionTrace MovieClip → _level0 (fixed)"
    status: complete
  - id: 2
    name: "actionTypeOf MovieClip → \"movieclip\" (fixed)"
    status: complete
  - id: 3
    name: "Object.prototype.toString → \"[object Object]\" (fixed)"
    status: complete
  - id: 4
    name: "Extra output lines: with block scoping (fixed)"
    status: complete
  - id: 5
    name: "trace(this) in `new f()` context (fixed)"
    status: complete
  - id: 6
    name: "trace(this) in `f()` call context (fixed)"
    status: complete
dependencies: []
blockers: []
-->

## Test Overview

Tests `this` keyword behavior in SWF7 (case-sensitive mode). Checks `this` value, typeof, and
case-sensitivity (`this` vs `tHiS` vs `THIS`) across contexts: main timeline, function call,
`new` constructor, `with` block, and `SetTarget`.

### Status: COMPLETE — 41/41 lines match (100%)

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

### 4. Extra output lines: with block scoping (fixed)

The `with` block was producing duplicate output — code ran both inside and after the `with`
block. Fixed so `with` correctly scopes execution and code runs exactly once inside the block,
matching Flash's 6 output blocks (not 8).

### 5. trace(this) in `new f()` context (fixed)

Objects created by `actionNewObject` for non-named constructors (type-1 DefineFunction) now
get `__proto__` → Object.prototype linked, so `trace(new f())` correctly prints `[object Object]`.

### 6. trace(this) in `f()` call context (fixed)

Plain function calls now set `this` to the calling context (root MovieClip `_level0` for
top-level calls), so `trace(this)` inside a plain function call correctly prints `_level0`.

---

## Final Result

Test passes 41/41 lines as of 2026-02-20.
