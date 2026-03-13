# Global Functions/Objects Implementation Plan
<!-- TESTS: globals_swf5, globals_swf6, globals_swf7, globals_swf8, global_swf5_6_7_8_9, global_swf6_7_8, global_instance_decls, global_proto_decls, global_proto_decls_delete, swf5_global_funcs, swf6_global_funcs, swf7_global_funcs, math_min_max, parse_int, parse_float, is_finite, is_finite_swf6, primitive_type_globals, printjob_props_swf5, printjob_props_swf6, printjob_props_swf7, context_menu, context_menu_item, localconnection_properties, sound_props_swf5, sound_props_swf6, native_objects_swf6, native_objects_swf7, native_objects_swf8, native_subclasses, as_set_prop_flags -->

Last updated: 2026-03-13

## Status: BLOCKED — Phases 1-8b COMPLETE, Phase 8c-8d blocked on architecture

**28 of 31 tests PASSING.** 3 tests remain with output mismatches, blocked on deep architectural issues.

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
| global_proto_decls | 20/4497 | ~0% | **FAIL** | Blocked: function property enumeration |
| global_proto_decls_delete | 0/4158 | 0% | **FAIL** | Blocked: same as global_proto_decls |
| global_instance_decls | 12/758 | ~2% | **FAIL** | Blocked: same + instance construction |

### Remaining Failing Tests

| Test | Root Cause | Blocker |
|------|-----------|---------|
| native_objects_swf6 | Pre-existing: `new TextField()` returns native object instead of undefined in SWF6. Comment in code (line ~32258) explains this is intentional to pass `textfield_props_swf6`. | Conflicting test expectations — fixing one breaks the other |
| global_proto_decls | Function property enumeration architecture (see Blocker section) | Architectural |
| global_proto_decls_delete | Same root cause as global_proto_decls | Architectural |
| global_instance_decls | Same + instance construction differences | Architectural |

---

## Blocker: ASFunction Property Enumeration

The remaining 3 tests (`global_proto_decls`, `global_proto_decls_delete`, `global_instance_decls`) are blocked on a fundamental architectural issue: **our `for-in` enumeration of ASFunction objects doesn't expose `__proto__`, `constructor`, and `prototype` as own properties**.

### What the test expects

The test uses `ASSetPropFlags(obj, null, 0, 1)` to reveal all properties, then enumerates with `for-in`. For every constructor function (e.g., TextSnapshot), it expects:

```
Testing _global.TextSnapshot
  __proto__, own, type=[object]
  constructor, own, type=[function]
  prototype, own, DONT_ENUM, type=[object]
Testing _global.TextSnapshot.prototype
  ...prototype methods...
  __proto__, own, type=[object]
  constructor, own, type=[function]
```

### What our runtime does

In our runtime, `ASFunction` is a C struct — **not** an `ASObject`. Functions have:
- `own_props` (ASObject*) — only populated for a few constructors (Object, AsBroadcaster, ExternalInterface)
- `prototype_obj` (ASObject*) — the function's `.prototype`
- No `__proto__` or `constructor` properties accessible via `for-in`

When `for-in` encounters an ASFunction, it only enumerates `own_props` contents. The structural fields (`prototype_obj`, the implicit `__proto__` pointing to Function.prototype) are NOT exposed as enumerable properties.

### What would be needed to fix this

1. **Every constructor function** needs `own_props` populated with at least `__proto__`, `constructor`, and `prototype` properties
2. **`for-in` on functions** needs to walk the prototype chain (Function.prototype → Object.prototype) to expose inherited methods (watch, unwatch, addProperty, valueOf, toString, etc.)
3. **Property flags** on these properties must match exactly (e.g., `prototype` must be DONT_ENUM, `__proto__` and `constructor` must not be)
4. **Static objects** (Stage, Key, Mouse, Selection, Accessibility, Math, SoundCodec) need `constructor` as an own property pointing to Object
5. **System object** with ~100 nested properties needs to be registered on `_global` (currently lazy-initialized in getVariable)
6. **flash.automation** namespace (Configuration, ActionGenerator, StageCapture) needs to be added
7. **~20 additional properties** on existing objects (Key constants, Mouse.show/hide, Accessibility.isActive, etc.)

This is a deep architectural change that touches the core object/function model. It's not feasible to fix incrementally without risking regressions across the ~530 passing tests.

### Recommendation

These 3 tests should be moved to the **blocked** investigation category. The work done in Phase 8a/8b (registration order + missing stubs) improved 8 other tests and is valuable on its own. The remaining work requires architectural changes to the ASFunction ↔ ASObject relationship that are too risky for incremental development.

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
| 8c | Property flags (DONT_ENUM, DONT_DELETE, READ_ONLY) | **BLOCKED** — requires ASFunction property enumeration |
| 8d | Instance construction differences | **BLOCKED** — requires ASFunction property enumeration |
