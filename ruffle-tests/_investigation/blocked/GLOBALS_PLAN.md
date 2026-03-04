# Global Functions/Objects Implementation Plan
<!-- TESTS: globals_swf5, globals_swf6, globals_swf7, globals_swf8, global_swf5_6_7_8_9, global_swf6_7_8, global_instance_decls, global_proto_decls, global_proto_decls_delete, swf5_global_funcs, swf6_global_funcs, swf7_global_funcs, math_min_max, parse_int, parse_float, is_finite, is_finite_swf6, primitive_type_globals, printjob_props_swf5, printjob_props_swf6, printjob_props_swf7, context_menu, context_menu_item, localconnection_properties, sound_props_swf5, sound_props_swf6, native_objects_swf6, native_objects_swf7, native_objects_swf8, native_subclasses, as_set_prop_flags -->

Last updated: 2026-03-03

## Status: BLOCKED — Phases 1-7 COMPLETE, Phase 8 blocked

### Blockers

1. **global_proto_decls / global_proto_decls_delete / global_instance_decls**: These tests enumerate ALL globals and their properties in a specific order using `for-in` (LIFO). Our global registration order differs from Ruffle's, AND Ruffle has ~20 globals we don't implement (ASnative, ASconstructor, enableDebugConsole, SoundCodec, AsSetupError, AssetCache, RemoteLSOUsage, textRenderer, ASSetNative, ASSetNativeAccessor, showRedrawRegions, addRequestHeader, clearRequestHeaders, Infinity-as-property, etc.). Matching requires rewriting the entire ensureGlobalInit order plus adding all missing globals.

2. **swf5_global_funcs**: ~160/232 lines failing. Tests actual behavior of global functions (parseInt with octal, various parsing edge cases), not just existence. The garbage values (-42839.25 etc.) suggest stack corruption or wrong data reads in the recompiled test code. Deep investigation needed.

3. **Phase 8 (property flags)**: Depends on matching global_proto_decls enumeration, which is blocked by #1.

### Implementation Commits
- `3048065` — Implement global constructors/objects, rewrite parseInt, fix isFinite/isNaN (Phases 1, 3-5)
- `c5804d0` — Implement Math object with 17 methods and 8 constants (Phase 2)
- `06244c7` — Set Object.prototype on built-in objects for proper toString inheritance
- (prior) — Phase 6: Number.prototype.toString(radix), Number constants, Boolean/String primitives
- `788d36e` — Phase 7 (partial): native toString for static objects, PrintJob/Sound/LocalConnection prototypes
- `78e5e4e` — Fix Object.prototype.toString threshold: SWF5/6 user objects → [type Object]
- `f455e3d3` — Add prototype methods for 15 stub classes (Phase 7)
- `5f27cba3` — Add ContextMenu/ContextMenuItem constructors and copy() methods

### Current Pass Rates (2026-02-26)

| Test | Lines | Pass Rate | Status | Notes |
|------|-------|-----------|--------|-------|
| globals_swf5 | 304/304 | 100% | **PASS** | |
| globals_swf6 | 304/304 | 100% | **PASS** | |
| globals_swf7 | 304/304 | 100% | **PASS** | |
| globals_swf8 | 304/304 | 100% | **PASS** | |
| math_min_max | 101/101 | 100% | **PASS** | |
| is_finite | 49/49 | 100% | **PASS** | |
| is_finite_swf6 | 49/49 | 100% | **PASS** | |
| parse_float | PASS | 100% | **PASS** | Fixed since last assessment |
| parse_int | 64/64 | 100% | **PASS** | |
| primitive_type_globals | 557/557 | 100% | **PASS** | |
| printjob_props_swf5 | PASS | 100% | **PASS** | |
| printjob_props_swf6 | PASS | 100% | **PASS** | |
| printjob_props_swf7 | PASS | 100% | **PASS** | |
| sound_props_swf5 | PASS | 100% | **PASS** | |
| sound_props_swf6 | PASS | 100% | **PASS** | |
| localconnection_properties | PASS | 100% | **PASS** | |
| context_menu | 40/40 | 100% | **PASS** | Constructor + copy() implemented |
| context_menu_item | 42/42 | 100% | **PASS** | Constructor + copy() implemented |

**23 tests PASSING** out of 30 in scope (updated 2026-03-03).

### Recently Fixed (since last update)

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| native_objects_swf6 | 84/84 | **PASS** ✅ | NativeType tracking, stub constructors |
| native_objects_swf7 | 84/84 | **PASS** ✅ | Same fix as swf6 |
| native_objects_swf8 | 84/84 | **PASS** ✅ | + flash.* filter dispatch |
| as_set_prop_flags | 79/79 | **PASS** ✅ | ASSetPropFlags valueOf/toString coercion |
| global_swf6_7_8 | 15/15 | **PASS** ✅ | Cross-version Phase 1+4 |

### Remaining Failing Tests

| Test | Status | Blocker |
|------|--------|---------|
| global_proto_decls | ~17/4497 | Registration order + 20 missing globals |
| global_proto_decls_delete | ~0/4158 | Same as global_proto_decls |
| global_instance_decls | ~0/758 | Same + instance property defaults |
| swf5_global_funcs | ~37/232 | Stack corruption / recompiled code issues |
| swf6/7_global_funcs | unknown | Same category as swf5_global_funcs |
| native_subclasses | ~165/221 | arguments.slice() + constructor property init |
| global_swf5_6_7_8_9 | 1031/1145 | Per-movie `_global` isolation (CROSS_VERSION_ISOLATION_PLAN) |

### Phase Completion Summary

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | Register missing global constructors (stubs) | **DONE** |
| 2 | Math object methods | **DONE** |
| 3 | Fix parseInt | **DONE** |
| 4 | Fix parseFloat and isFinite | **DONE** |
| 5 | flash.* namespace (SWF8+) | **DONE** |
| 6 | Primitive type improvements (Number/Boolean/String) | **DONE** |
| 7 | Prototype methods for stub classes | **DONE** (all 18 classes + ContextMenu/ContextMenuItem constructors) |
| 8 | Property flags (DONT_ENUM, DONT_DELETE, READ_ONLY) | **BLOCKED** (depends on matching enumeration order) |
