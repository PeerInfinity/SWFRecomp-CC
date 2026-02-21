# string_coercion Test Investigation
<!-- TESTS: string_coercion -->

## Status: COMPLETE ✅

**Final result: 117/117 lines match — test PASSES**

Verified 2026-02-20. All fixes applied. Related comparison tests also pass:
- `lessthan2_swf5`, `lessthan2_swf6`, `lessthan2_swf7` — PASS
- `greater_swf6`, `greater_swf7` — PASS

---

## Test Overview

Tests string coercion semantics for `trace()`, Add2 (`+`), comparison operators (Less2, Greater,
StringLess, StringGreater, StringEquals, Equals2), and explicit `.toString()`/`.valueOf()` calls.
SWF version 6.

Creates objects with custom `toString` (via MyClass/EvilToString.prototype) and `valueOf`
(via EvilValueOf.prototype), then tests how they behave in various contexts.

---

## Fixes Applied (all complete)

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

### 8. objectToPrimitive uses getPropertyWithPrototype for valueOf (fixed)

`objectToPrimitive` uses `getPropertyWithPrototype` to walk the prototype chain when
looking for valueOf. This correctly handles:
- `new EvilValueOf("a") < new EvilValueOf("b")`: EvilValueOf.prototype.valueOf found
  via prototype chain → returns primitive string → comparison works ✓
- Bare `{}`: Object.prototype.valueOf returns `this` (non-primitive) → bail → `false` ✓
- `new EvilToString(...)`: Object.prototype.valueOf returns `this` → bail → `false` ✓
  (no "ToString Called" side effects, matching expected output for lines 31-38)

When valueOf returns a non-primitive, objectToPrimitive bails without falling through
to toString — matching Flash's number-hint ToPrimitive behavior for Less2/Greater.

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

### 13. GetVariable("dummy") returns function (fixed)

`dummy` (defined via `actionDefineFunction`) is correctly retrieved as a function.
`trace(dummy)` outputs `[type Function]` as expected (line 112).

### 14. Function.toString() after prototype.toString deleted (fixed)

After `delete dummy.prototype.toString`, `dummy.toString()` returns `undefined` (line 116).
`String(dummy)` still returns `[type Function]` via the built-in string coercion path (line 117).

---

## Key Findings (for reference)

### NaN comparison behavior in Flash

Flash's Less2 (0x48) and Greater (0x67) opcodes return `undefined` for NaN comparisons,
NOT `false` as ECMAScript specifies. This was confirmed by the lessthan2_swf5/6/7 and
greater_swf6/7 tests.

The `false` results in the "string sorting with toString" section (lines 31-38) are NOT
due to NaN→false, but because `objectToPrimitive` bails early when valueOf returns a
non-primitive (Object.prototype.valueOf returns `this` for EvilToString objects which
have no own valueOf).

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
