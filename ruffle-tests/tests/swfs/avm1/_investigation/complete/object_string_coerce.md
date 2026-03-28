# object_string_coerce_swf5 / object_string_coerce_swf6 Investigation
<!-- TESTS: object_string_coerce_swf5, object_string_coerce_swf6 -->

<!-- PLAN_META
id: object_string_coerce
status: complete
phases:
  - id: 1
    name: "actionTrace calls toString on objects (fixed)"
    status: complete
  - id: 2
    name: "Object.prototype.toString built-in (fixed)"
    status: complete
  - id: 3
    name: "Prototype chain support (fixed)"
    status: complete
  - id: 4
    name: "Add2 toString fallback when valueOf not found (fixed)"
    status: complete
  - id: 5
    name: "objectCallValueOf handles valueOf=undefined (fixed)"
    status: complete
dependencies: []
blockers: []
-->

## Test Overview

Both tests exercise object-to-string coercion in `trace()` and Add2 (`+` concat) with various
combinations of `valueOf` and `toString` returning String, undefined, or Object ({}).

Tests both plain Objects and Date objects (which have different ToPrimitive hint order).

- **SWF5**: `object_string_coerce_swf5` — 62/62 lines match (actual=65, 3 extra lines)
- **SWF6**: `object_string_coerce_swf6` — 68/68 lines match (**PASS**)

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

### SWF5: FIXED

SWF5 now passes (62/62 lines match). The extra 3 lines issue was resolved.

### SWF6: FIXED

SWF6 now passes (68/68 lines match). The Date ToPrimitive toString-first issue was resolved in subsequent work.

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
