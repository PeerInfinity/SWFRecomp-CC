# Primitive Coercion addProperty Plan
<!-- TESTS: coerce_to_primitive_resolve -->

<!-- PLAN_META
id: PRIMITIVE_COERCION_ADDPROPERTY
status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-03-07

## Status: COMPLETE — coerce_to_primitive_resolve 17/17 PASS

### Overview

When ActionScript coerces an object to a number or string (e.g., `obj + 0` or `String(obj)`), it looks for `valueOf` and `toString` methods. Previously, `objectCallValueOf`, `objectCallToString`, and `convertFloat` used `getPropertyWithPrototype()` which only finds direct/inherited property values — not addProperty virtual getters.

If an object had `addProperty("valueOf", getter, null)`, the getter was never invoked during coercion.

**Test**: `coerce_to_primitive_resolve` — **17/17 PASS** ✅

### Fix Applied

Three coercion functions needed addProperty getter support via `findPropertyStructWithPrototype` + `invokePropertyGetter`:

1. **`objectCallValueOf`** — Primary valueOf coercion used by `actionAdd2`. addProperty getter check placed BEFORE the stored-value fallbacks (critical: the UNDEFINED value from addProperty's marker was caught by the primitive-value check, preventing the getter path from running).

2. **`objectCallToString`** — Primary toString coercion. addProperty getter check placed after the existing `getPropertyWithPrototype` check (works because the existing guard requires FUNCTION type, so UNDEFINED falls through naturally).

3. **`convertFloat`** — Secondary valueOf path for numeric coercion. addProperty getter check after existing valueOf property checks.

Key subtlety: The addProperty getter returns the *valueOf/toString function itself*, not the coerced value. The returned function must then be invoked to get the primitive value (two-step invocation).

Phase 3 (__resolve fallback): Confirmed correct — __resolve is NOT invoked during coercion, matching Flash behavior (obj3: NaN, [type Object]).
