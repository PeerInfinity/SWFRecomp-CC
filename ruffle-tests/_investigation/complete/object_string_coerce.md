# object_string_coerce_swf5 / object_string_coerce_swf6 Investigation
<!-- TESTS: object_string_coerce_swf5, object_string_coerce_swf6 -->

## Test Overview

Both tests exercise object-to-string coercion in `trace()` and Add2 (`+` concat) with various
combinations of `valueOf` and `toString` returning String, undefined, or Object ({}).

Tests both plain Objects and Date objects (which have different ToPrimitive hint order).

- **SWF5**: `object_string_coerce_swf5` — 62/62 lines match (actual=65, 3 extra lines)
- **SWF6**: `object_string_coerce_swf6` — 46/68 lines match (actual=65)

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

### SWF6: Date ToPrimitive toString-first in Add2 (SWF6+)

**Status: READY TO IMPLEMENT** (SWF5 already passes, SWF6 is the only remaining issue)

Multiple sections where the Date-specific ToPrimitive order is wrong for Add2:

```
// Date with toString -> String, valueOf -> String
// trace("" + date_obj) — should call toString first (Date hint)
Expected: toString called / toString
Actual:   valueOf called / valueOf
```

**Root cause:** Date objects need toString-first ToPrimitive hint for Add2 in SWF6+,
but our runtime always uses valueOf-first. The `isDateObject` check and `g_swf_version >= 6`
guard are needed.

**Fix plan:**
1. Add `isDateObject(ActionVar*)` helper that checks `obj.__proto__ == g_date_prototype`
2. In `actionAdd2`, for object operands: if `isDateObject` && `g_swf_version >= 6`,
   call `objectCallToString` instead of `objectCallValueOf`
3. This matches the ECMAScript Date `[[DefaultValue]]` string-hint behavior

**Verified expected behavior for each section (actionAdd2 with "" + date):**
- toString→String, valueOf→String: call toString (1st), get "toString", use it → "toString"
- toString→undefined, valueOf→String: call toString (1st), toString is undefined (not callable)
  → a_vo=undefined, a_vo_is_prim=true → convert undefined → "undefined"
- toString→{}, valueOf→String: call toString (1st), get {} (object), a_vo_found=1;
  then string concat path calls toString again (2nd call) → {} → "[type Object]"
- toString→{}, valueOf→undefined: same as above, two toString calls → "[type Object]"
- toString→{}, valueOf→{}: same, two toString calls → "[type Object]"

**SWF5 not affected:** g_swf_version=5 < 6, so `isDateObject && g_swf_version>=6` = false
→ Date objects in SWF5 use valueOf-first (current behavior, already correct)

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
