# add2 Test Investigation

## Test Overview

The `add2` test exercises `actionAdd2` (SWF5+ type-aware `+` operator) across a comprehensive
matrix of type combinations: numbers, booleans, strings, undefined, null, MovieClip (`_level0`),
plain objects, and objects with custom `valueOf`/`toString`.

A `testAdd(a, b)` function is called for each pair. It calls `ToPrimitive` on each operand
(checking for a `name` property to print a label), performs `a + b` and `b + a`, and traces the
results.

### SWFRecomp result: 86/118 blocks match (72.9%)

---

## Issue Categories

### 1. `_root` variable resolves to `undefined` instead of MovieClip (14 blocks)

The bytecode pushes `"_root"` and calls `actionGetVariable`. The runtime returns `undefined`
instead of the root MovieClip reference. In Flash, `_root` converts to the string `"_level0"`.

**Where the fix goes**: `actionGetVariable` (action.c:3123-3139). The special-variable handling
already checks for `"this"` and returns `root_movieclip`, but `"_root"` is not handled.

**Note**: There's already a check for `"this"` that returns `ACTION_STACK_VALUE_MOVIECLIP`. Need
to add the same for `"_root"` and `"_level0"`.

### 2. Object-to-primitive conversion order is wrong — left-to-right instead of right-to-left (8 blocks)

Flash's `Add2` evaluates `ToPrimitive` on the **right** operand first, then the left. This is
observable when valueOf has side effects (like `trace()`). The current implementation evaluates
left first (deeper on stack).

**Expected order (from test output)**:

```
// objValue1 + objValue2:  prints objValue2.valueOf, then objValue1.valueOf
// objValue2 + objValue1:  prints objValue1.valueOf, then objValue2.valueOf
```

So for `a + b`, Flash calls `ToPrimitive(b)` first, then `ToPrimitive(a)`.

**Where the fix goes**: `actionAdd2` (action.c:1170). The function currently peeks at types,
then branches into string-concat or numeric. The numeric path pops right, converts left, then
converts right. Both paths need to ToPrimitive both operands in right-to-left order BEFORE
deciding string vs numeric.

### 3. String operand bypasses ToPrimitive on the other operand (2 blocks)

When one operand is a string and the other is an object, the current code goes directly to
the string concatenation path (line 1180: `if type_a == STRING || type_b == STRING`). This
converts the object via `convertString` which produces `"[object Object]"` — but it should
instead call `ToPrimitive` first, which would invoke `valueOf` and get a numeric/string result.

**Example**: `objValue1 + "abc"` should call `objValue1.valueOf()` (returns 1), then
`"1" + "abc"` = `"1abc"`. Instead it gets `"[object Object]abc"`.

**Root cause**: The type check at line 1180 happens before `ToPrimitive` is called on objects.
Per the ECMAScript/Flash spec for `Add2`:

1. Call `ToPrimitive(a)` and `ToPrimitive(b)` — right operand first in Flash
2. If EITHER result is a string, do string concatenation
3. Otherwise, do numeric addition

### 4. valueOf returning string triggers numeric path instead of string concat (6 blocks)

`objValue2.valueOf` returns the string `"xyz"`. After `ToPrimitive`, the result is a string.
The current numeric path doesn't re-check types after ToPrimitive — it blindly does
`convertFloat` which turns `"xyz"` into `NaN`.

**Root cause**: Same as #3 — ToPrimitive must happen first, THEN the string-vs-numeric
decision must be made based on the ToPrimitive results.

### 5. No toString fallback when valueOf returns a non-primitive (2 blocks)

`objValue3.valueOf` returns a new empty Object (non-primitive). Per the spec, `ToPrimitive`
should then fall back to `toString()`. The current `objectToPrimitive` function DOES have a
toString fallback (line 272), but the issue is that it's not being reached in the Add2 context
because the string/numeric path decision happens before ToPrimitive.

---

## Root Cause Summary

All issues 2-5 stem from the same architectural problem in `actionAdd2`:

**Current flow:**
1. Peek at raw types on stack
2. If either is STRING → string concat path (convert both via `convertString`)
3. Else → numeric path (convert both via `convertFloat`)

**Correct flow (per ECMAScript/Flash spec):**
1. Pop both operands
2. Call `ToPrimitive` on each (right operand first for Flash evaluation order)
3. If either ToPrimitive result is a string → string concatenation
4. Else → numeric addition

The `objectToPrimitive` function already handles valueOf→toString fallback correctly. It just
needs to be called at the right point in the `actionAdd2` pipeline.

## What Would Be Needed to Fix

### For `_root` / `_level0` (issue 1):
Add `"_root"` and `"_level0"` to the special variable handling in `actionGetVariable`, returning
`ACTION_STACK_VALUE_MOVIECLIP` with `&root_movieclip`. Also need `_root` MovieClip to convert
to string `"_level0"` when used in string context (in `convertString`).

### For ToPrimitive ordering and string-vs-numeric decision (issues 2-5):
Rewrite `actionAdd2` to:
1. Pop right operand (a), pop left operand (b)
2. Call `objectToPrimitive(a)` — this invokes valueOf/toString with proper fallback
3. Call `objectToPrimitive(b)`
4. If either result is a string → concatenate as strings
5. Else → convert both to numbers and add

This requires `objectToPrimitive` to be usable from `actionAdd2`, which it already is (it's
a static function in the same file).
