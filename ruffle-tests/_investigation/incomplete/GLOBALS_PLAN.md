# Global Functions/Objects Implementation Plan
<!-- TESTS: globals_swf5, globals_swf6, globals_swf7, globals_swf8, global_swf5_6_7_8_9, global_swf6_7_8, global_instance_decls, global_proto_decls, global_proto_decls_delete, swf5_global_funcs, swf6_global_funcs, swf7_global_funcs, math_min_max, parse_int, parse_float, is_finite, is_finite_swf6, primitive_type_globals, printjob_props_swf5, printjob_props_swf6, printjob_props_swf7, context_menu, context_menu_item, localconnection_properties, sound_props_swf5, sound_props_swf6, native_objects_swf6, native_objects_swf7, native_objects_swf8, native_subclasses, as_set_prop_flags -->

Last updated: 2026-03-13

## Status: INCOMPLETE — Phases 1-7 COMPLETE, Phase 8 in progress

**29 of 30 tests PASSING.** 3 tests remain with output mismatches. 1 test is a candidate for ACCEPTED_DIFFS (timezone).

### Current Pass Rates (2026-03-13)

| Test | Lines | Pass Rate | Status | Notes |
|------|-------|-----------|--------|-------|
| globals_swf5 | 304/304 | 100% | **PASS** | |
| globals_swf6 | 304/304 | 100% | **PASS** | |
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
| native_objects_swf6 | 84/84 | 100% | **PASS** | |
| native_objects_swf7 | 84/84 | 100% | **PASS** | |
| native_objects_swf8 | 84/84 | 100% | **PASS** | |
| as_set_prop_flags | 79/79 | 100% | **PASS** | |
| global_swf6_7_8 | 15/15 | 100% | **PASS** | |
| swf5_global_funcs | 232/232 | 100% | **PASS** | |
| swf6_global_funcs | 232/232 | 100% | **PASS** | |
| swf7_global_funcs | 232/232 | 100% | **PASS** | |
| global_swf5_6_7_8_9 | 1145/1145 | 100% | **PASS** | |
| native_subclasses | 190/191 | 99% | **FAIL** | 1 line: timezone in Date.toString() |
| global_proto_decls | FAIL | ~0% | **FAIL** | Registration order + missing globals |
| global_proto_decls_delete | FAIL | ~0% | **FAIL** | Same as global_proto_decls |
| global_instance_decls | FAIL | ~0% | **FAIL** | Same + DONT_DELETE flags on instances |

### Remaining Failing Tests

| Test | Diff Lines | Root Cause |
|------|-----------|------------|
| native_subclasses | 1 | Timezone-dependent Date.toString() output |
| global_proto_decls | ~8973 | Global registration order + ~20 missing globals |
| global_proto_decls_delete | ~8000+ | Same root cause as global_proto_decls |
| global_instance_decls | ~700+ | Same + missing DONT_DELETE flags on `__proto__` + instance property issues |

---

## Plan for Remaining Tests

### native_subclasses — Candidate for ACCEPTED_DIFFS

The sole failing line is timezone-dependent:
```
- super(123456): Thu Jan 1 05:47:03 GMT+0545 1970
+ super(123456): Wed Dec 31 17:02:03 GMT-0700 1969
```
Both represent the same epoch timestamp (123456ms from epoch), formatted with different system timezones. This is platform-dependent C `strftime` behavior, not a logic bug. Should be added to `ACCEPTED_DIFFS.md` under the "Platform UB / environment-dependent" category.

### global_proto_decls / global_proto_decls_delete / global_instance_decls — Phase 8

These three tests are tightly coupled. They all enumerate `_global` properties using `for-in` (LIFO order) and check property flags. Fixing them requires three sub-phases:

#### Phase 8a: Match global registration order

The expected enumeration order (LIFO, so last-registered appears first) is:

```
TextSnapshot, PrintJob, MovieClipLoader, LocalConnection, textRenderer,
flash.automation.*, flash.external.ExternalInterface, flash.net.*,
flash.geom.*, flash.filters.*, flash.display.BitmapData,
Stage, Selection, Key, Mouse, Sound, XML, XMLNode, LoadVars,
CustomActions, TextField.StyleSheet, TextField, Video, Button, MovieClip,
Date, Error, SharedObject, Microphone, Camera, NetStream, NetConnection,
Color, AsBroadcaster, XMLSocket, ...
Math, Array, String, Date, Boolean, Number,
clearRequestHeaders, addRequestHeader, showRedrawRegions,
setTimeout, clearInterval, clearTimeout, setInterval,
isFinite, isNaN, updateAfterEvent, trace, parseFloat, parseInt,
unescape, escape, ASSetNativeAccessor, ASSetNative, ASSetPropFlags,
RemoteLSOUsage, AssetCache, AsSetupError, Error,
ContextMenu, ContextMenuItem, SharedObject, ...
Infinity, NaN, enableDebugConsole, Function, Object, ASconstructor, ASnative
```

**Work required:**
1. Audit `ensureGlobalInit()` in `action.c` — identify current registration order
2. Reorder all `setVariableWithValue`/`registerGeomMethod` calls to match Ruffle's expected LIFO sequence
3. Registration must happen in REVERSE of the enumeration order above (since `for-in` is LIFO, first-registered appears last)

#### Phase 8b: Add missing global stubs (~15 globals)

These globals exist in Flash Player but we don't register them yet:

| Global | Type | Notes |
|--------|------|-------|
| `ASnative` | function | Internal Flash function dispatcher (undocumented) |
| `ASconstructor` | function | Internal constructor dispatcher (undocumented) |
| `enableDebugConsole` | function | Debug-mode function (stub/no-op) |
| `ASSetNative` | function | Native method registration (undocumented) |
| `ASSetNativeAccessor` | function | Native accessor registration (undocumented) |
| `showRedrawRegions` | function | Debug visual (stub/no-op) |
| `addRequestHeader` | function | HTTP header management (stub) |
| `clearRequestHeaders` | function | HTTP header management (stub) |
| `RemoteLSOUsage` | object | Remote shared object config (stub) |
| `AssetCache` | object | Asset caching (stub) |
| `AsSetupError` | object | Setup error type (stub) |
| `textRenderer` | object | Text rendering config; instances should be `undefined` type |
| `Infinity` | number | Must be registered as a property (not just a value) |
| `setTimeout` | function | Already implemented in timer system, may just need registration |
| `clearTimeout` | function | Already implemented in timer system, may just need registration |

Most can be no-op function stubs or empty objects. `ASnative` and `ASconstructor` are the most complex — they're Flash's internal dispatch tables that map numeric IDs to native functions. A basic implementation would handle the most common IDs.

#### Phase 8c: Property flags (DONT_ENUM, DONT_DELETE, READ_ONLY)

After registration order is correct, set property flags on globals and their prototypes:

1. **DONT_DELETE on `__proto__`**: Every constructed instance should have `__proto__` marked DONT_DELETE. Currently missing — affects global_instance_decls.
2. **DONT_DELETE on constructor/prototype**: Global constructors should have their `__proto__`, `constructor`, and `prototype` properties marked DONT_DELETE.
3. **DONT_ENUM on prototype**: Constructor `.prototype` property should be DONT_ENUM (already partially done for some globals).
4. **READ_ONLY + DONT_DELETE on instance properties**: Some instance properties (e.g., PrintJob's paperHeight/paperWidth/pageHeight/pageWidth/orientation) need all three flags.

This requires a property flag system on ASObject properties (may already exist via ASSetPropFlags infrastructure).

#### Phase 8d: Instance construction differences

Some globals have special instance behavior in global_instance_decls:
- `textRenderer`: instance should be `undefined`, not `[object Object]`
- `flash.automation.Configuration`: instance should be `[[AutomationConfiguration]]` with specific toString
- `flash.automation.ActionGenerator`/`StageCapture`: instances should be `undefined`

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
| 8a | Match global registration order | TODO |
| 8b | Add ~15 missing global stubs | TODO |
| 8c | Property flags (DONT_ENUM, DONT_DELETE, READ_ONLY) | TODO |
| 8d | Instance construction differences | TODO |
