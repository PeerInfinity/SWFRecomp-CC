# object_string_coerce_swf5 / object_string_coerce_swf6 Investigation

## Test Overview

Both tests exercise object-to-string coercion in `trace()` and Add2 (`+` concat) with various
combinations of `valueOf` and `toString` returning String, undefined, or Object ({}).

Tests both plain Objects and Date objects (which have different ToPrimitive hint order).

- **SWF5**: `object_string_coerce_swf5` — 63/65 lines match (actual=74, expected=65)
- **SWF6**: `object_string_coerce_swf6` — 47/69 lines match (actual=74, expected=69)

---

## Fixes Applied

### 1. actionTrace calls toString on objects (fixed)

**Was:** actionTrace printed `[type Object]` for all objects without calling any methods.
**Fix:** actionTrace now calls `objectCallToString()` on OBJECT values:
- toString found + returns string → print that string
- toString found + returns non-string → print `[type Object]`
- No toString found → print `[type Object]`

### 2. Object.prototype.toString built-in (fixed)

Created global Object.prototype with built-in toString returning `[object Object]`.
Objects created via `InitObject` or `new Object()` get `__proto__` → Object.prototype.
This makes plain objects trace as `[object Object]` instead of `[type Object]`.

### 3. Prototype chain support (fixed)

Added `__proto__` traversal via `getPropertyWithPrototype()`. Objects created with
user-defined constructors (e.g. `new MyClass()`) get their constructor's prototype
set as `__proto__`, enabling inherited toString/valueOf to be found.

### 4. Add2 toString fallback when valueOf not found (fixed)

When Add2 encounters an object with no valueOf, it now falls back to calling toString
before using `convertString`. This handles cases like `"" + obj` where obj only has
toString defined.

### 5. objectCallValueOf handles valueOf=undefined (fixed)

When valueOf property is explicitly set to `undefined` (not missing, but present as
undefined), objectCallValueOf now correctly returns it as a "found" primitive, matching
Flash's behavior.

---

## Remaining Issues

### SWF5: Extra toString call at end (2 extra lines)

Actual output has 2 extra lines near the end:
```
toString called
[type Object]
```

This appears to be a spurious extra toString invocation. Needs investigation into
whether it's from a Date object section or an extra coercion path.

### SWF6: Date ToPrimitive prefers wrong method (~22 lines)

Multiple sections where the Date-specific ToPrimitive order is wrong:

```
// Date with toString -> String, valueOf -> String
// trace("" + date_obj) — should call toString first (Date hint)
Expected: toString called / toString
Actual:   valueOf called / valueOf
```

**Root cause:** Date objects need toString-first ToPrimitive hint, but our runtime
always uses valueOf-first for Add2/Less2/etc. There's currently no Date object type
distinction or Date-specific ToPrimitive path.

**Fix:** Would require:
1. A Date object type flag or special prototype chain marker
2. ToPrimitive to check for Date-ness and use toString-first hint
3. This is a larger feature — no Date constructor support exists yet

### SWF6: toString→{} fallback chain (several lines)

When toString returns an object (`{}`), Flash falls back to valueOf. When valueOf
also returns an object, it falls back to `[type Object]`. Our fallback chain doesn't
fully match Flash's behavior in these edge cases.

---

## Test Structure

Each test section creates an object with specific valueOf/toString overrides, then:
1. Directly `trace(obj)` — tests trace's string coercion
2. `trace("" + obj)` — tests Add2's string coercion

### Object sections (ToPrimitive: valueOf first for Add2, toString for trace)
- valueOf→String, toString→String
- valueOf→undefined, toString→String
- valueOf→{}, toString→String
- valueOf→{}, toString→undefined
- valueOf→{}, toString→{}

### Date sections (ToPrimitive: toString first for everything — NOT YET IMPLEMENTED)
- toString→String, valueOf→String
- toString→undefined, valueOf→String
- toString→{}, valueOf→String
- toString→{}, valueOf→undefined
- toString→{}, valueOf→{}
