# add2 Test Investigation
<!-- TESTS: add2 -->

<!-- PLAN_META
id: add2
status: complete
dependencies: []
blockers: []
-->

## Test Overview

The `add2` test exercises `actionAdd2` (SWF5+ type-aware `+` operator) across a comprehensive
matrix of type combinations: numbers, booleans, strings, undefined, null, MovieClip (`_level0`),
plain objects, and objects with custom `valueOf`/`toString`.

A `testAdd(a, b)` function is called for each pair. It calls `ToPrimitive` on each operand
(checking for a `name` property to print a label), performs `a + b` and `b + a`, and traces the
results.

### SWFRecomp result: PASS (fixed in commit 79c7aee)

Previously: 86/118 blocks match (72.9%)

---

## Issues Found and Fixed

### 1. `_root` variable resolves to `undefined` instead of MovieClip (14 blocks)

The bytecode pushes `"_root"` and calls `actionGetVariable`. The runtime returned `undefined`
instead of the root MovieClip reference. In Flash, `_root` converts to the string `"_level0"`.

**Fix**: Added `"_root"` and `"_level0"` to the special variable handling in `actionGetVariable`,
returning `ACTION_STACK_VALUE_MOVIECLIP` with `&root_movieclip`. Also separated MovieClip from
Object/Array in `convertString` so it renders as `"_level0"` instead of `"[object Object]"`.

### 2-5. actionAdd2 ToPrimitive semantics (18 blocks combined)

Issues 2-5 all stemmed from the same architectural problem: the original `actionAdd2` checked
raw stack types to decide string-vs-numeric BEFORE calling valueOf/toString on objects.

**Fix**: Complete rewrite of `actionAdd2`. See "Flash Add2 Algorithm" below for details.

---

## Flash Add2 Algorithm (key finding)

Flash's `+` operator does NOT follow a clean "ToPrimitive → check → convert" flow. It has a
more nuanced algorithm that was discovered by analyzing the side-effect trace patterns:

### Algorithm

1. **Pop both operands** from the stack (right = top, left = second)
2. **Call valueOf on each object operand** (right first, then left — Flash's evaluation order)
3. **Check if string path**: if either raw type OR valueOf result is a string → string concatenation
4. **String path** — for each operand:
   - Non-object: `convertString` directly
   - Object with primitive valueOf result: convert that primitive to string
   - Object with non-primitive valueOf result: call `toString`. If returns STRING → use it.
     Otherwise → `"[type Object]"` fallback
   - Object with no valueOf: `convertString` on original → `"[object Object]"`
5. **Numeric path** — for each operand:
   - Object with primitive valueOf result: use that result (no second valueOf call)
   - Object with non-primitive valueOf or no valueOf: push ORIGINAL and `convertFloat`
     (which calls valueOf again — this is the "double valueOf" behavior)
   - Non-object: push and `convertFloat` normally

### Key observations

- **valueOf is called in the initial check phase** (step 2), and if it returned a non-primitive,
  **valueOf is called AGAIN** in the numeric path via `convertFloat`. This "double valueOf" is
  intentional Flash behavior, observable via side effects.
- **valueOf returning a primitive skips the second call**: if valueOf returned a primitive (even
  non-numeric like `undefined`), the numeric path uses that result directly — no second valueOf.
- **String path uses toString as fallback**: when valueOf returned non-primitive AND toString
  returns a non-string → `"[type Object]"`. When no valueOf exists at all → `"[object Object]"`.
- **Evaluation order is right-to-left**: for `a + b`, valueOf(b) is called first, then valueOf(a).

### Evidence from test output

```
// objValue1 + objValue3 (valueOf returns Object, valueOf returns 1)
objValue3.valueOf        ← step 2: valueOf(right=objValue3) → Object (non-primitive)
objValue1.valueOf        ← step 2: valueOf(left=objValue1) → 1 (primitive)
objValue3.valueOf        ← step 5: numeric path, convertFloat on original → valueOf again
NaN                      ← 1 + NaN = NaN

// objValue2 + objValue3 (valueOf returns "xyz", valueOf returns Object)
objValue3.valueOf        ← step 2: valueOf(right=objValue3) → Object (non-primitive)
objValue2.valueOf        ← step 2: valueOf(left=objValue2) → "xyz" (string!)
objValue3.toString       ← step 4: string path, toString fallback for non-primitive valueOf
xyz[type Object]         ← "xyz" + "[type Object]" (toString returned non-string)
```

---

## Helper functions added

- `objectCallValueOf(app_context, obj_var, &found)` — calls just valueOf, returns raw result
  (even non-primitive). Sets `found=1` if valueOf existed and was called.
- `objectCallToString(app_context, obj_var)` — calls just toString, returns raw result.

These are distinct from `objectToPrimitive` which does the full valueOf→toString chain. The
Add2 operator needs them separately because:
- It needs to know if valueOf was found (to distinguish `[type Object]` vs `[object Object]`)
- It needs valueOf results before deciding string-vs-numeric path
- It may need to call valueOf again in the numeric path (via convertFloat on original)

---

## Other runtime issues discovered

### convertString STACK_TOP_N bug

When `convertString` converts a non-string type (F32, boolean, etc.) to STRING, it writes the
string pointer to `STACK_TOP_VALUE` but does NOT update `STACK_TOP_N` (the length field at
SP+8). The PUSH macro also doesn't initialize SP+8 for non-string types. This means reading
`STACK_TOP_N` after convertString on a converted value gives garbage data.

**Rule**: Always use `strlen()` to get string length after `convertString`, never `STACK_TOP_N`,
unless the value was originally pushed as a STRING type (which sets N correctly via PUSH_STR_ID).

### MovieClip string representation

MovieClip should convert to `"_level0"` in string context, not `"[object Object]"`. Fixed by
separating `ACTION_STACK_VALUE_MOVIECLIP` from the Object/Array case in `convertString`.
