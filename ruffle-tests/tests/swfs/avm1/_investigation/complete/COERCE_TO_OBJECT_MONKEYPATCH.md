# coerce_to_object_monkeypatch — Primitive-to-Object Coercion with Monkeypatched Constructors

**Status**: 129/129 PASS
**Category**: Primitive coercion / constructor lookup
**Completed**: 2026-03-15

## Test Overview

Tests that AS2 primitive types (Boolean, Number, String) can have their constructors replaced via `_global.__proto__` addProperty getters, and that auto-boxing (implicit object wrapping) invokes the monkeypatched constructor.

## Fixes Applied

### Fix 1: `new "string"()` auto-boxing in `actionNewMethod` (Category 1)

When `actionNewMethod` receives a primitive (string/boolean/number) with a blank method name (`new primitive()`), Flash auto-boxes the primitive as a side effect (invoking the monkeypatched constructor), then returns undefined.

**Change**: Added primitive auto-boxing call in `actionNewMethod`'s blank-method-name handler, before the "push undefined" fallback.

### Fix 2: Tri-state `tryAutoBoxPrimitive` return + Function.call/apply `this` fallback (Category 2)

When `Function.call(primitive)` tries to auto-box and fails, Flash's behavior depends on WHY it failed:
- **Built-in stub constructor found** (e.g., original Number): pass primitive as-is (`g_override_this`)
- **No constructor found / non-function found** (e.g., deleted, string, BitmapData, {}): `this` = `_global`
- **User-defined constructor found**: auto-box succeeds, `this` = boxed object

**Change**: `tryAutoBoxPrimitive` now returns tri-state: 1 (auto-boxed), 0 (no valid constructor), -1 (built-in stub found, name matches). Function.call/apply dispatch uses `_global` for return value 0, primitive passthrough for -1.

The built-in stub detection uses name matching (`cf->name == ctor_name`) to distinguish "original Number" from "Number replaced with BitmapData".

### Fix 3: `convertString` broken prototype chain fallback (1 line)

When an object has a non-object `__proto__` (e.g., `true`), `toString` lookup fails because `resolveProtoVar` can't walk through non-object prototypes. Flash returns `"undefined"` for objects without reachable toString. Our code was returning `"[object Object]"`.

**Change**: Simplified `convertString` OBJECT case: when `toString` is not found (`_cs_found == 0`), always return `"undefined"` (SWF7+) or `""` (SWF<7), removing the special-case for global_object (which is now subsumed by the general rule).

## Files Modified

- `SWFModernRuntime/src/actionmodern/action.c`:
  - `tryAutoBoxPrimitive()`: tri-state return, built-in stub name matching
  - `actionNewMethod()`: primitive auto-boxing for `new primitive()`
  - `actionCallMethod()` Function.call/apply: tri-state dispatch
  - `convertString()`: broken prototype chain fallback

## Regression Testing

All related tests verified passing: `funky_function_calls`, `as2_super_and_this_v6/v8`, `swf5_no_closure`, `swf5_to_6_cross_call`, `super_edge_cases`, `object_resolve`, `register_class_return_value`, `register_and_init_order`, `init_object_order`, `unload`, `set_interval`, `bitmap_data`, `clip_events`, `goto_frame`, `goto_frame2`, `selection`.
