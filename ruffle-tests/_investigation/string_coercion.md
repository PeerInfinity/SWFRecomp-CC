# string_coercion Test Investigation

## Test Overview

Tests string coercion semantics for `trace()`, Add2 (`+`), comparison operators (Less2, Greater,
StringLess, StringGreater, StringEquals, Equals2), and explicit `.toString()`/`.valueOf()` calls.
SWF version 6.

Creates objects with custom `toString` (via MyClass/EvilToString.prototype) and `valueOf`
(via EvilValueOf.prototype), then tests how they behave in various contexts.

### SWFRecomp result: FAIL — 81/117 lines match (actual=108), 36 lines differ

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

### 8. Less2/Greater valueOf coercion (fixed, then partially regressed)

These operators originally called `objectCallValueOf()` on object operands, matching
Flash's number-hint ToPrimitive behavior. This was later changed to `objectToPrimitive()`
with own-property-only lookup to fix lessthan2/greater/equals2 regressions. See
"objectToPrimitive own-only lookup" below for details.

### 9. Property array growth bug (fixed)

Fixed integer rounding issue in object.c where `(num_properties * 3) / 2` rounded
down to the same value when capacity was 1, causing zero growth and heap overflow.

### 10. SetMember object-to-string coercion for property names (fixed)

In `actionSetMember`, when the property name is an OBJECT, `objectCallToString()` is
called to coerce it to a string before using it as a key.

### 11. GetVariable("Object") built-in constructor (fixed)

Added "Object" to `actionGetVariable`'s special variables, returning a placeholder
constructor as ACTION_STACK_VALUE_FUNCTION.

### 12. Object.prototype.valueOf built-in (fixed)

Added built-in `valueOf` to Object.prototype (type-2 function) that returns `this`
(the object itself). Makes `o.valueOf() === o` evaluate to `true` for plain objects.

---

## Remaining Issues (36 lines differ)

### 1. objectToPrimitive uses own-property-only lookup (~18 lines: 71-86, 95-96)

`objectToPrimitive` was changed to use `getProperty` (own-only) instead of
`getPropertyWithPrototype` to fix lessthan2/greater/equals2 regressions. This means
Less2/Greater cannot find `valueOf` on prototype chains (e.g. EvilValueOf.prototype).

```
// new EvilValueOf("a") < new EvilValueOf("b")  — EvilValueOf.prototype.valueOf defined
Expected: ValueOf Called / true     ← valueOf found via prototype, "a" < "b"
Actual:   false                     ← valueOf not found (own-only), bail early
```

The "string sorting with valueOf" section (lines 70-97) expects "ValueOf Called" side
effects from EvilValueOf's prototype valueOf, but objectToPrimitive doesn't find it.

**Correct fix:** `objectToPrimitive` should use `getPropertyWithPrototype` for valueOf
lookup, but should NOT fall back to toString when valueOf returns a non-primitive. This
way:
- Bare `{}`: Object.prototype.valueOf returns `this` (non-primitive) → bail → `false` ✓
- `new EvilValueOf("a")`: EvilValueOf.prototype.valueOf returns `"a"` (primitive) → use ✓
- `new EvilToString("b")`: Object.prototype.valueOf returns `this` → bail → `false` ✓
  (no "ToString Called" side effects, matching expected output lines 31-38)

This would fix both the string_coercion regression AND keep lessthan2/greater/equals2
passing.

### 2. GetVariable("dummy") → undefined (1 line: 112)

```
// trace(dummy)  — user-defined function
Expected: [type Function]
Actual:   undefined
```

`dummy` is defined via `actionDefineFunction` which stores it as
ACTION_STACK_VALUE_FUNCTION. Investigate why `getVariable("dummy")` returns undefined.

### 3. Function.toString() after prototype.toString deleted (2 lines: 116-117)

```
// delete dummy.prototype.toString; trace(dummy.toString())
Expected: undefined / [type Function]
Actual:   (missing lines — output ends at 108 vs 117 expected)
```

After deleting the prototype toString, `dummy.toString()` should return `undefined`
(line 116), then `String(dummy)` should still return `[type Function]` (line 117).
Our output is 9 lines short, suggesting these sections don't execute or produce
different output.

---

## Key Findings

### NaN comparison behavior in Flash

Flash's Less2 (0x48) and Greater (0x67) opcodes return `undefined` for NaN comparisons,
NOT `false` as ECMAScript specifies. This was confirmed by the lessthan2_swf5/6/7 and
greater_swf6/7 tests.

The earlier analysis in this document incorrectly stated NaN comparisons return `false`.
The `false` results in the "string sorting with toString" section (lines 31-38) are NOT
due to NaN→false, but because `objectToPrimitive` bails early when no valueOf is found
on the object (EvilToString has toString but not valueOf — and with own-only lookup,
Object.prototype.valueOf isn't found either).

### Less2/Greater number-hint ToPrimitive

Flash's Less2/Greater use number-hint ToPrimitive:
1. Try valueOf (walking prototype chain)
2. If valueOf returns a primitive → use it
3. If valueOf returns non-primitive (e.g. Object.prototype.valueOf returning `this`) → bail
4. Do NOT fall back to toString (confirmed by no "ToString Called" in expected lines 31-38)

This differs from Add2's string-path ToPrimitive, which does fall back to toString.

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
3. Regular nonstring traces: plain object, array, function (lines 26-29)
4. String sorting with toString: Less2/Greater/StringLess/StringGreater/Equals2 (lines 30-57)
5. EvilValueOf with various non-string types: trace side effects (lines 58-65)
6. Regular nonstring traces (again) (lines 66-69)
7. String sorting with valueOf: same operators with EvilValueOf (lines 70-97)
8. valueOf returning this: StrictEquals identity check (lines 98-101)
9. toString call tests: Add2 with custom toString objects (lines 102-109)
10. Function toString tests: trace(func), func.toString(), ToString opcode (lines 110-117)
