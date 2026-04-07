# Native Objects Updated Tests Plan
<!-- TESTS: native_objects_swf6, native_objects_swf7, native_objects_swf8 -->

<!-- PLAN_META
id: NATIVE_OBJECTS_UPDATED
status: complete
phases:
  - id: 1
    name: "Readonly __proto__ on singletons/globals"
    status: complete
  - id: 2
    name: "Function() without new + NetConnection permanently locked proto"
    status: complete
  - id: 3
    name: "TextField.StyleSheet + FileReference native backing"
    status: complete
  - id: 4
    name: "ExternalInterface new returns object (SWF8)"
    status: complete
dependencies:
  - plan: NATIVE_INTROSPECTION
    type: extends
    reason: "Original plan (84/84) is complete; this covers upstream test updates (84→115 lines)"
blockers: []
-->

Last updated: 2026-04-07

## Status: COMPLETE

### Test Results

| Test | Lines | Result | Notes |
|------|-------|--------|-------|
| native_objects_swf6 | 115 | 114/115 (99%) | 1 accepted diff (SWF6 TextField — RUFFLE_VS_FLASH_DIFFERENCES.md) |
| native_objects_swf7 | 115 | 115/115 (100%) | PASS |
| native_objects_swf8 | 115 | 115/115 (100%) | PASS |

### Implementation Summary

All phases implemented in a single session (2026-04-07):

**Phase 1: Readonly `__proto__` on singletons/globals (8 objects)**
- Added `makeProtoReadOnly()` helper (sets property flags to 0 = no WRITABLE/ENUMERABLE/CONFIGURABLE)
- Applied to: g_accessibility_obj, g_key_obj, g_mouse_obj, g_selection_obj, g_math_object
- Color instances: replaced per-instance flag loop with `makeProtoReadOnly()`
- System.Product: changed constructor from `builtin_noop_func` to `builtin_readonly_proto_ctor`

**Phase 2: Function() without new + NetConnection**
- `Function()` without `new`: allocObject with capacity 4 + setObjectProto (was capacity 0 with no proto)
- NetConnection: added `PROPERTY_FLAG_PERM_READONLY` (0x80) flag that survives ASSetPropFlags.
  actionSetMember checks this bit alongside WRITABLE to block writes permanently.

**Phase 3: TextField.StyleSheet + FileReference native backing**
- StyleSheet: added `builtin_stylesheet_constructor` (type 2) that sets `native_type = NATIVE_STYLESHEET`
- FileReference: added `NATIVE_FILEREF = 22` to NativeType enum. Set in actionNewMethod's ctor_name dispatch
  (same pattern as Sound, LoadVars, etc.). Super() handler also added for subclass support.

**Phase 4: ExternalInterface (SWF8)**
- Changed ExternalInterface from type 1 stub to type 2 with `builtin_noop_func`, so `new` returns an object.

### Key Code Locations

| Component | File | Location |
|-----------|------|----------|
| `makeProtoReadOnly()` | action.c | ~line 6960 |
| `PROPERTY_FLAG_PERM_READONLY` | object.h | line 29 |
| PERM_READONLY check | action.c | actionSetMember ~line 36311 |
| `builtin_readonly_proto_ctor` | action.c | ~line 4401 |
| `builtin_stylesheet_constructor` | action.c | ~line 13989 |
| FileReference native_type | action.c | actionNewMethod ~line 42378 |
| FileReference super() | action.c | actionInitializeNative ~line 44137 |
