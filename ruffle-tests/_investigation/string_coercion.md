# string_coercion Test Investigation

## Test Overview

Tests string coercion semantics for `trace()`, Add2 (`+`), comparison operators (Less2, Greater,
StringLess, StringGreater, StringEquals, Equals2), and explicit `.toString()`/`.valueOf()` calls.
SWF version 6.

Creates objects with custom `toString` (via MyClass/EvilToString.prototype) and `valueOf`
(via EvilValueOf.prototype), then tests how they behave in various contexts.

### SWFRecomp result: FAIL — 103/117 lines match, 14 lines differ

---

## Fixes Applied

### 1. actionTrace calls toString on objects (fixed)

actionTrace now calls `objectCallToString()` on OBJECT values. Custom toString methods
on prototypes are found and invoked, with side effects firing correctly.

### 2. Object.prototype.toString built-in (fixed)

Plain objects (no custom toString) now trace as `[object Object]` via inherited
Object.prototype.toString, matching Flash behavior.

### 3. Prototype chain infrastructure (fixed)

- `ASFunction.prototype_obj` field for constructor prototypes
- `getPropertyWithPrototype()` traverses `__proto__` chain
- `actionNewObject` links `__proto__` from constructor's prototype to new instances
- `actionGetMember` lazily creates function.prototype on first access

### 4. CallMethod prototype chain lookup (fixed)

`actionCallMethod` now uses `getPropertyWithPrototype()` instead of `getProperty()`
for method lookup, so `x.toString()` finds methods defined on the prototype chain.

### 5. Type-1 constructor invocation in actionNewObject (fixed)

Type-1 (DefineFunction) constructors are now properly called during `new`, with `this`
set to the new object and arguments passed on the stack.

### 6. Add2 toString fallback (fixed)

When Add2 encounters an object with no valueOf, it falls back to toString before
using convertString. Handles `"prefix" + obj` where obj only has toString.

### 7. StringLess/StringGreater/StringEquals toString coercion (fixed)

These operators now call `objectCallToString()` on object operands before comparing,
matching Flash's string-hint ToPrimitive behavior.

### 8. Less2/Greater valueOf coercion (fixed)

These operators call `objectCallValueOf()` on object operands, matching Flash's
number-hint ToPrimitive behavior.

### 9. Property array growth bug (fixed)

Fixed integer rounding issue in object.c where `(num_properties * 3) / 2` rounded
down to the same value when capacity was 1, causing zero growth and heap overflow.

---

## Remaining Issues (14 lines differ)

### 1. SetMember doesn't coerce object property names to string (2 lines: 9-10)

```
// y[x] = 5  where x = new MyClass() with toString returning "My toString impl"
// then trace(y["My toString impl"])
Expected: 5                    ← y["My toString impl"] was set to 5
Actual:   undefined            ← property name was not coerced, so key doesn't exist
```

Also causes a missing enumeration output (`My toString impl` from `for...in`).

**Fix:** In `actionSetMember`, when the property name is an OBJECT, call
`objectCallToString()` to coerce it to a string before using it as a key.

### 2. GetVariable("Object") / GetVariable("dummy") → undefined (3 lines: 29, 69, 112)

```
// trace(Object)  — the built-in Object constructor
Expected: [type Function]
Actual:   undefined
```

`Object` is not exposed as a variable via `getVariable`. Similarly, `dummy` (a
user-defined function) is found but may be stored with wrong type or not found
when accessed as a generic variable.

**Note:** `dummy` is defined via `actionDefineFunction` which stores it as
ACTION_STACK_VALUE_FUNCTION. The issue for "Object" is that it's a built-in
constructor handled specially in `actionNewObject` but never registered as a variable.

**Fix for "Object":** Add "Object" to `actionGetVariable`'s special variables,
returning it as ACTION_STACK_VALUE_FUNCTION (similar to how "NaN", "undefined", etc.
are handled).

**Fix for "dummy":** Investigate why `getVariable("dummy")` returns undefined when
it should have been stored by `actionDefineFunction`.

### 3. Less2/Greater NaN comparison pushes undefined instead of false (8 lines: 31-38)

```
// "a" < new EvilToString("b")
// EvilToString has toString but no valueOf
// Less2 tries valueOf → not found → object stays as-is → numeric path → NaN
Expected: false    ← NaN comparison returns false per SWF spec
Actual:   undefined ← our code pushes undefined for NaN
```

In Flash (and per ECMAScript), `x < y` where either is NaN returns `false`, not
`undefined`. Our `actionLess2` pushes `ACTION_STACK_VALUE_UNDEFINED` for NaN cases.

**Fix:** Change the NaN comparison path in `actionLess2` and `actionGreater` to push
`ACTION_STACK_VALUE_BOOLEAN` with value 0 (false) instead of pushing undefined.

**Note:** Less2 does NOT fall back to toString when valueOf is not found (number hint).
The object stays as-is, converts to NaN in the numeric path, and NaN < anything = false.
This is confirmed by the expected output showing no "ToString Called" side effects for
lines 31-38, while lines 39-56 (StringLess/StringGreater) DO show "ToString Called".

### 4. Object.prototype.valueOf not implemented (3 lines: 99-101)

```
// o = {}; trace(o.valueOf() === o)  — valueOf should return this
Expected: true
Actual:   false
```

Flash's Object.prototype has a built-in `valueOf` that returns `this` (the object
itself). When `o.valueOf()` is called on a plain object, it should return the same
object reference, making `o.valueOf() === o` evaluate to `true`.

**Fix:** Add a built-in `valueOf` to Object.prototype (in `getObjectPrototype()`)
that returns the `this` object. This requires the function to receive the object
context — may need to use type-2 function with `this` in register, or set the
"this" variable before calling.

---

## Test Structure

The test defines:
- `MyClass` — empty constructor, `MyClass.prototype.toString` returns "My toString impl"
- `EvilToString(strval)` — constructor stores strval; prototype.toString traces
  "ToString Called" then returns `this.strval`
- `EvilValueOf(strval)` — constructor stores strval; prototype.valueOf traces
  "ValueOf Called" then returns `this.strval`
- `dummy` — empty function (for function toString tests)

Sections tested:
1. MyClass toString: trace, explicit toString(), Add2 concat (lines 1-10)
2. EvilToString with various non-string types: trace side effects (lines 11-25)
3. Regular non-string traces: plain object, array, function (lines 26-29)
4. String sorting with toString: Less2/Greater/StringLess/StringGreater/Equals2 (lines 30-57)
5. EvilValueOf with various non-string types: trace side effects (lines 58-65)
6. Regular non-string traces (again) (lines 66-69)
7. String sorting with valueOf: same operators with EvilValueOf (lines 70-97)
8. valueOf returning this: StrictEquals identity check (lines 98-101)
9. toString call tests: Add2 with custom toString objects (lines 102-109)
10. Function toString tests: trace(func), func.toString(), ToString opcode (lines 110-117)
