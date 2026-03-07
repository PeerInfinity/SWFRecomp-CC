# Primitive Coercion addProperty Plan
<!-- TESTS: coerce_to_primitive_resolve -->

Last updated: 2026-03-06

## Status: ACTIONABLE — not blocked

### Overview

When ActionScript coerces an object to a number or string (e.g., `obj + 0` or `String(obj)`), it looks for `valueOf` and `toString` methods. Currently, `convertFloat` and `convertString` use `getPropertyWithPrototype()` which only finds direct/inherited properties — not addProperty virtual getters.

If an object has `addProperty("valueOf", getter, null)`, the getter is never invoked during coercion.

**Test**: `coerce_to_primitive_resolve` — 7/17 (41%). Lines 8-13 fail because obj2's addProperty-defined valueOf/toString are never called.

### Root Cause

In `convertFloat` (action.c ~line 15577):
```c
ActionVar* valueOf_prop = getPropertyWithPrototype(obj, "valueOf", 7);
```

This looks up `valueOf` as a direct property or inherited property, but does NOT check for addProperty getters (which are stored as `PropertyEntry` structs with `getter`/`setter` function pointers, found via `findPropertyStruct` or `findPropertyStructWithPrototype`).

Similarly, `convertString` (wherever it handles OBJECT types) likely has the same issue.

### Flash Semantics

In Flash Player, `addProperty("valueOf", fn, null)` creates a virtual property that behaves identically to a direct property assignment `obj.valueOf = fn` for coercion purposes. The getter should be invoked, and its return value used as the valueOf function, which is then called.

The test shows:
```
// obj2: methods as properties (via addProperty)
valueOf property called!     <- addProperty getter invoked
valueOf called!              <- returned valueOf function invoked
obj2 as num: 1               <- result of valueOf()
toString property called!    <- addProperty getter invoked
toString called!             <- returned toString function invoked
[obj as string]              <- result of toString()
```

### Fix

**Phase 1: convertFloat addProperty support** (~15 lines)

After the `getPropertyWithPrototype` check fails (or returns non-function), also check for addProperty getters:

```c
// In convertFloat, OBJECT/ARRAY case:
ActionVar* valueOf_prop = getPropertyWithPrototype(obj, "valueOf", 7);

// If not found as direct property, check addProperty getter
if (valueOf_prop == NULL) {
    PropertyEntry* pe = findPropertyStructWithPrototype(obj, "valueOf", 7);
    if (pe != NULL && pe->getter != NULL) {
        ActionVar getter_result = invokePropertyGetter(app_context,
            (ASFunction*)pe->getter, (void*)obj);
        if (getter_result.type == ACTION_STACK_VALUE_FUNCTION) {
            // The getter returned the actual valueOf function — invoke it
            // ... (push to stack, call, use result)
        }
    }
}
```

Key subtlety: The addProperty getter returns the *valueOf function itself*, not the coerced value. We must then call that returned function to get the primitive value.

**Phase 2: convertString addProperty support** (~15 lines)

Same pattern for `toString` lookup in `convertString`.

**Phase 3: __resolve fallback** (lines 15-17)

The test also has obj3 which uses `__resolve` to dynamically provide valueOf/toString. Lines 15-17 expect:
```
obj3 as num: NaN
[type Object]
```
This means __resolve should NOT be invoked during coercion (NaN = no valueOf found, [type Object] = default toString). This is likely already correct behavior since we don't invoke __resolve during convertFloat/convertString.

### Expected Outcome

| Phase | Lines Gained | Test Result |
|-------|-------------|-------------|
| Phase 1 | +3 (valueOf lines) | 10/17 |
| Phase 2 | +3 (toString lines) | 13/17 |
| Phase 3 | +0 (verify already correct) | 13/17 |
| Lines 14, "None" | +4 (positional) | 17/17 |

### Dependencies

None — `findPropertyStructWithPrototype` and `invokePropertyGetter` already exist and work correctly (used in GetMember and SetMember paths).

### Risks

- Must ensure the two-step invocation (call getter → get function → call function) doesn't cause stack corruption. Save/restore stack state around getter invocation.
- Must handle the case where the addProperty getter returns a non-function (just use the returned value directly if it's a primitive).
- Test also exercises `__resolve` fallback (obj3) — verify we don't accidentally start invoking __resolve during coercion.
