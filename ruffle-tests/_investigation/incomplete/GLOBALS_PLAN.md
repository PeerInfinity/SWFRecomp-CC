# Global Functions/Objects Implementation Plan
<!-- TESTS: globals_swf5, globals_swf6, globals_swf7, globals_swf8, global_swf5_6_7_8_9, global_swf6_7_8, global_instance_decls, global_proto_decls, global_proto_decls_delete, swf5_global_funcs, swf6_global_funcs, swf7_global_funcs, math_min_max, parse_int, parse_float, is_finite, is_finite_swf6, primitive_type_globals, printjob_props_swf5, printjob_props_swf6, printjob_props_swf7, context_menu, context_menu_item, localconnection_properties, sound_props_swf5, sound_props_swf6, native_objects_swf6, native_objects_swf7, native_objects_swf8, native_subclasses, as_set_prop_flags -->

Last updated: 2026-03-13

## Status: INCOMPLETE — Phases 1-8b DONE, Phase 8c in progress

**28 of 31 tests PASSING.** 3 tests remain with output mismatches. Unblocking plan below.

### Current Pass Rates (2026-03-13, CI run on 530c6389)

| Test | Lines | Pass Rate | Status | Notes |
|------|-------|-----------|--------|-------|
| globals_swf5 | 304/304 | 100% | **PASS** | Newly passing (was 296/304) |
| globals_swf6 | 304/304 | 100% | **PASS** | Newly passing (was 301/304) |
| globals_swf7 | 304/304 | 100% | **PASS** | |
| globals_swf8 | 304/304 | 100% | **PASS** | |
| math_min_max | 101/101 | 100% | **PASS** | |
| is_finite | 49/49 | 100% | **PASS** | |
| is_finite_swf6 | 49/49 | 100% | **PASS** | |
| parse_float | PASS | 100% | **PASS** | |
| parse_int | 64/64 | 100% | **PASS** | |
| primitive_type_globals | 557/557 | 100% | **PASS** | |
| printjob_props_swf5 | PASS | 100% | **PASS** | |
| printjob_props_swf6 | PASS | 100% | **PASS** | |
| printjob_props_swf7 | PASS | 100% | **PASS** | |
| sound_props_swf5 | PASS | 100% | **PASS** | |
| sound_props_swf6 | PASS | 100% | **PASS** | |
| localconnection_properties | PASS | 100% | **PASS** | |
| context_menu | 40/40 | 100% | **PASS** | |
| context_menu_item | 42/42 | 100% | **PASS** | |
| native_objects_swf6 | 83/84 | 99% | **FAIL** | Pre-existing: `new TextField()` returns native (should be undefined in SWF6) |
| native_objects_swf7 | 84/84 | 100% | **PASS** | |
| native_objects_swf8 | 84/84 | 100% | **PASS** | |
| as_set_prop_flags | 79/79 | 100% | **PASS** | |
| global_swf6_7_8 | 15/15 | 100% | **PASS** | |
| swf5_global_funcs | 232/232 | 100% | **PASS** | |
| swf6_global_funcs | 232/232 | 100% | **PASS** | |
| swf7_global_funcs | 232/232 | 100% | **PASS** | |
| global_swf5_6_7_8_9 | 1145/1145 | 100% | **PASS** | Newly passing (was 1115/1145) |
| native_subclasses | PASS | 100% | **PASS** | Timezone issue resolved in CI |
| global_proto_decls | 20/4497 | ~0% | **FAIL** | Phase 8c |
| global_proto_decls_delete | 0/4158 | 0% | **FAIL** | Phase 8c |
| global_instance_decls | 12/758 | ~2% | **FAIL** | Phase 8d |

---

## Plan for Remaining Tests (Phase 8c–8d)

### Architecture Background

In our runtime, `ASFunction` is a C struct with fields `prototype_obj` and `own_props` — it is NOT an `ASObject`. In Flash/Ruffle, functions ARE objects: they have `__proto__`, `constructor`, `prototype` as own enumerable properties, and `for-in` walks their prototype chain (Function.prototype → Object.prototype).

Our `actionEnumerate2` (the for-in implementation) has separate code paths for OBJECT and FUNCTION types. The OBJECT path walks the `__proto__` chain; the FUNCTION path only iterates `own_props` without chain walking. This causes two problems:

1. Constructor own properties (`__proto__`, `constructor`, `prototype`) are not visible
2. Inherited methods from Object.prototype (watch, valueOf, toString, etc.) are not visible

### Phase 8c-1: Fix actionEnumerate2 prototype chain walking for functions

**What:** In `actionEnumerate2` (line ~26426), change the FUNCTION enumeration to walk the `__proto__` chain from `own_props`, using the same logic as the OBJECT path.

**Where:** `SWFModernRuntime/src/actionmodern/action.c`, `actionEnumerate2`, the `ACTION_STACK_VALUE_FUNCTION` case.

**Current code (simplified):**
```c
// FUNCTION case — only iterates own_props, no chain walking
ASObject* obj = func->own_props;
for (u32 i = 0; i < obj->num_used; i++) {
    if (!(obj->properties[i].flags & PROPERTY_FLAG_ENUMERABLE)) continue;
    PUSH_STR(obj->properties[i].name, obj->properties[i].name_length);
}
```

**Target code:** Copy the prototype chain walking loop from the OBJECT case — walk `own_props.__proto__` → Function.prototype → Object.prototype, pushing enumerable properties and deduplicating.

**Risk:** Low. Makes behavior more Flash-compatible. Any test doing `for (key in func)` will now also see inherited properties — correct Flash behavior. Run all 536 passing tests to verify no regressions.

**Impact:** ~585 lines (9 inherited Object.prototype methods × ~65 globals)

### Phase 8c-2: Populate own_props on every constructor

**What:** After creating each constructor in `ensureGlobalInit()`, allocate `own_props` and set:
- `__proto__` → Function.prototype (version-specific)
- `constructor` → Function constructor
- `prototype` → the function's `prototype_obj` (DONT_ENUM flag)

**Where:** `ensureGlobalInit()` in action.c. Add a helper function like:
```c
static void populateConstructorOwnProps(SWFAppContext* app_context, ASFunction* ctor, ASObject* fn_proto, ASFunction* fn_ctor)
```
Call it for all ~40 constructors (6 core + 18 stub + MovieClip, TextField, TextFormat, XML, XMLNode, Date, Error + new stubs).

**Timing dependency:** Function.prototype is created at the END of `ensureGlobalInit()`. So `__proto__` must be set after that point (currently done for Object's own_props at line ~22081). Extend that loop to cover ALL constructors, not just those that already have own_props.

**Risk:** Low. `own_props` is the standard property storage mechanism for functions. GetMember already checks own_props. The `prototype` property in own_props will mirror `prototype_obj`; GetMember's special handling of "prototype" checks own_props first when present.

**Impact:** ~1040 lines (3 own props per constructor × ~65 globals, plus their `Testing _global.X.prototype` blocks)

### Phase 8c-3: Register System and flash objects on _global

**What:** In `ensureGlobalInit()`, eagerly create the System and flash objects and register them on `global_object` (currently they're lazily created in `actionGetVariable` and never appear in _global for-in).

**Where:** `ensureGlobalInit()` Phase B registration section. Use the file-scope statics `g_system_object` and `g_flash_object` already added.

**Details:**
- Call the existing lazy-init code for System/flash from `ensureGlobalInit` (extract into helper functions)
- Register with `setProperty(global_object, "System", ...)` and `setProperty(global_object, "flash", ...)` in the correct LIFO position
- flash is SWF8+ only; System is all versions
- flash.automation namespace (Configuration, ActionGenerator, StageCapture) needs to be added to the flash init

**Risk:** Medium. System and flash init code currently runs inside `actionGetVariable` with function-scope statics. Moving to file-scope statics is already done; the init just needs to be triggered earlier. Must verify that the init doesn't depend on state only available during script execution.

**Impact:** ~300-500 lines (System.capabilities alone has ~40 properties, System.security, System.IME, plus flash.* sub-packages)

### Phase 8c-4: Add missing properties on existing objects

**What:** The test enumerates deep into each object. Several globals are missing expected properties:

| Object | Missing Properties |
|--------|--------------------|
| Key | 20 constants (ALT, ENTER, SPACE, UP, DOWN, LEFT, RIGHT, etc.), `isAccessible` method |
| Mouse | `show`, `hide`, `setTrailer`, `setTrailerPosition`, `setTrailerMode` methods |
| Accessibility | `isActive`, `sendEvent`, `updateProperties` methods |
| Stage | `quality` should be removed (not in expected output for this SWF version) |

**Risk:** Low — just adding properties to existing objects.

**Impact:** ~200 lines

### Phase 8c-5: Property flags cleanup

**What:** Set correct DONT_ENUM / READ_ONLY flags on properties where the test checks them. Key areas:
- AsBroadcaster methods on Stage/Key/Mouse/Selection should be DONT_ENUM
- Stage properties should be READ_ONLY (already done in 8a)
- Constructor `prototype` property should be DONT_ENUM (done in 8c-2)

**Risk:** Low but tedious. Must verify each flag against expected output.

**Impact:** Fixes flag annotations on ~200 lines (doesn't add new lines, just corrects existing ones)

### Estimated total impact of Phase 8c

| Sub-phase | Lines fixed | Cumulative |
|-----------|------------|------------|
| Current | 20/4497 | 20 |
| 8c-1 (chain walking) | ~585 | ~605 |
| 8c-2 (own_props) | ~1040 | ~1645 |
| 8c-3 (System+flash) | ~400 | ~2045 |
| 8c-4 (missing props) | ~200 | ~2245 |
| 8c-5 (flags) | ~200 | ~2445 |

This would bring `global_proto_decls` from 20/4497 (~0%) to roughly 2000-2500/4497 (~50%). Getting to 100% would require additional work (every nested property of every object must match exactly), but 50% represents substantial progress.

### Phase 8d: Instance construction (global_instance_decls)

Deferred until 8c is further along. Requires:
- `__proto__` marked DONT_DELETE on constructed instances
- `__constructor__` set on constructed instances
- Special construction behavior for some types (textRenderer → undefined, flash.automation.Configuration → `[[AutomationConfiguration]]`)

---

## Implementation Commits (historical)

- `3048065` — Implement global constructors/objects, rewrite parseInt, fix isFinite/isNaN (Phases 1, 3-5)
- `c5804d0` — Implement Math object with 17 methods and 8 constants (Phase 2)
- `06244c7` — Set Object.prototype on built-in objects for proper toString inheritance
- (prior) — Phase 6: Number.prototype.toString(radix), Number constants, Boolean/String primitives
- `788d36e` — Phase 7 (partial): native toString for static objects, PrintJob/Sound/LocalConnection prototypes
- `78e5e4e` — Fix Object.prototype.toString threshold: SWF5/6 user objects -> [type Object]
- `f455e3d3` — Add prototype methods for 15 stub classes (Phase 7)
- `5f27cba3` — Add ContextMenu/ContextMenuItem constructors and copy() methods
- `d368848b` — Phase 8a+8b: Reorder _global registration + add ~20 missing global stubs
- `530c6389` — Fix regressions: restore valueOf on _global, remove NaN/Infinity from global_object

## Phase Completion Summary

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | Register missing global constructors (stubs) | **DONE** |
| 2 | Math object methods | **DONE** |
| 3 | Fix parseInt | **DONE** |
| 4 | Fix parseFloat and isFinite | **DONE** |
| 5 | flash.* namespace (SWF8+) | **DONE** |
| 6 | Primitive type improvements (Number/Boolean/String) | **DONE** |
| 7 | Prototype methods for stub classes | **DONE** |
| 8a | Match global registration order | **DONE** |
| 8b | Add ~20 missing global stubs | **DONE** |
| 8c-1 | Fix actionEnumerate2 prototype chain walking for functions | TODO |
| 8c-2 | Populate own_props on every constructor | TODO |
| 8c-3 | Register System + flash on _global | TODO |
| 8c-4 | Add missing properties on existing objects | TODO |
| 8c-5 | Property flags cleanup | TODO |
| 8d | Instance construction differences | TODO (deferred until 8c done) |
