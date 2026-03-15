# coerce_to_object_monkeypatch — Primitive-to-Object Coercion with Monkeypatched Constructors

**Status**: 71/129 (55%)
**Category**: Primitive coercion / constructor lookup

## Test Overview

Tests that AS2 primitive types (Boolean, Number, String) can have their constructors replaced via `_global.__proto__` addProperty getters, and that auto-boxing (implicit object wrapping) invokes the monkeypatched constructor.

The test:
1. Adds `className` to Number/Boolean/String prototypes
2. Deletes Number/Boolean/String from `_global`
3. Installs addProperty getters on `_global.__proto__` that return custom MyNumber/MyBoolean/MyString classes
4. Tests that `Function.call(primitive)` auto-boxes using the monkeypatched constructor
5. Tests `new "callme"()` (string-as-constructor-name)
6. Tests fallback behavior when Number is deleted, set to `__resolve`, replaced with various non-constructor values

## Two Categories of Failures

### Category 1: `new "string"()` doesn't invoke String getter (lines 49-51, ~2 lines + cascade)

```
Expected:                          Actual:
String getter called!              (missing)
MyString(callme) constructor!      (missing)
result: undefined                  result: undefined
```

**Root cause**: `actionNewObject()` (action.c ~line 33559) converts the constructor name to a string and looks it up directly via `getVariable`/`lookupFunctionByName`. It does NOT check for addProperty getters on `_global.__proto__`. Flash invokes the getter during constructor lookup.

**Fix**: In `actionNewObject`, when resolving the constructor name from `_global`, use `findPropertyStructWithPrototype` or an equivalent that walks the `__proto__` chain and invokes addProperty getters, rather than plain `getVariable`.

### Category 2: Primitive coercion falls back to root MovieClip instead of `_global` (lines 67-70+, ~56 lines)

```
Expected:                          Actual:
coerced: undefined                 coerced: _level0
is _global!                        typeof: movieclip
```

When the Number constructor is deleted and various non-constructor values are substituted, `Function.call(42)` should auto-box 42 as an object. If the constructor lookup fails, Flash falls back to `_global` as `this`. Our code falls back to the root MovieClip (`_level0`).

**Root cause**: `tryAutoBoxPrimitive()` (action.c ~line 5125) returns 0 when auto-boxing fails (no valid constructor found). The caller in `actionCallFunction`/`actionCallMethod` then uses the default `this` which is the current context MovieClip, not `_global`.

**Fix**: When `tryAutoBoxPrimitive()` returns 0 for a primitive `this`, the call dispatch should fall back to `_global` (the global object) rather than the current MovieClip context.

## Cascade Effect

The 58 wrong lines aren't 58 independent bugs — they're mostly the same two issues repeating across different test scenarios (Number deleted, Number=string, Number=BitmapData, Number={}, Number=Boolean, etc.). Fixing Category 2 would fix ~50 lines in one go.

## Files to Modify

- `SWFModernRuntime/src/actionmodern/action.c`:
  - `actionNewObject()` (~line 33559): constructor lookup should check addProperty getters
  - `tryAutoBoxPrimitive()` (~line 5125): verify return value semantics for failed boxing
  - `actionCallFunction` type 2 call path: when `this` is a primitive and auto-boxing fails, use `global_object` instead of current context MC

## Risks

- Changing constructor lookup to invoke getters could affect performance (every `new Foo()` would walk proto chain with getter checks)
- Changing the `this` fallback for failed auto-boxing could affect tests that rely on the current MC-fallback behavior
- The test uses MTASC-compiled code which may exercise code paths differently than hand-written SWF bytecode

## Related Tests

- `funky_function_calls` (56/56 PASS) — Function.call/apply edge cases
- `as2_super_and_this_v6` (PASS) — `this` binding in various contexts
- `swf5_no_closure` (PASS) — `this` context for SWF5 calls
