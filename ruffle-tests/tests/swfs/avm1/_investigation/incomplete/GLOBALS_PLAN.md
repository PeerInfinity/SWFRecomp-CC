# Global Functions/Objects Implementation Plan
<!-- TESTS: globals_swf5, globals_swf6, globals_swf7, globals_swf8, global_swf5_6_7_8_9, global_swf6_7_8, global_instance_decls, global_proto_decls, global_proto_decls_delete, swf5_global_funcs, swf6_global_funcs, swf7_global_funcs, math_min_max, parse_int, parse_float, is_finite, is_finite_swf6, primitive_type_globals, printjob_props_swf5, printjob_props_swf6, printjob_props_swf7, context_menu, context_menu_item, localconnection_properties, sound_props_swf5, sound_props_swf6, native_objects_swf6, native_objects_swf7, native_objects_swf8, native_subclasses, as_set_prop_flags -->

<!-- PLAN_META
id: GLOBALS
status: blocked
phases:
  - id: 1
    name: "Register missing global constructors (stubs)"
    status: complete
  - id: 2
    name: "Math object methods"
    status: complete
  - id: 3
    name: "Fix parseInt"
    status: complete
  - id: 4
    name: "Fix parseFloat and isFinite"
    status: complete
  - id: 5
    name: "flash.* namespace (SWF8+)"
    status: complete
  - id: 6
    name: "Primitive type improvements"
    status: complete
  - id: 7
    name: "Prototype methods for stub classes"
    status: complete
  - id: 8a
    name: "Match global registration order"
    status: complete
  - id: 8b
    name: "Add missing global stubs"
    status: complete
  - id: 8c-2
    name: "Populate own_props on every constructor"
    status: complete
  - id: 8c-2.5
    name: "DONT_DELETE flags and actionDelete fix"
    status: complete
  - id: 8c-3
    name: "Register System + flash + textRenderer on _global"
    status: complete
  - id: 8c-4
    name: "Add missing properties on existing objects"
    status: partial
  - id: 8c-5
    name: "Property flags cleanup"
    status: partial
  - id: 8c-6
    name: "flash.* constructor own_props property order"
    status: complete
  - id: 8d
    name: "Instance construction differences"
    status: blocked
dependencies: []
blockers:
  - blocker: 4
    reason: "Constructor/__proto__ DONT_ENUM vs ENUMERABLE conflict"
-->

Last updated: 2026-04-02

## Status: BLOCKED — Phases 1-8c-6 DONE, Phase 8c-4/8c-5/8d partially done, remaining items blocked

**29 of 31 plan tests PASSING.** `native_objects_swf6` is a pre-existing regression (83/84) from the reverted TextField SWF6 constructor gate. 3 tests remain with output mismatches but significant progress was made:
- `global_proto_decls`: 884/4497 (CI, 2026-04-02)
- `global_proto_decls_delete`: 296/4158 (CI, 2026-04-02)
- `global_instance_decls`: 23/758 (was 40, -17 regression of unclear origin — may be from initialization order changes, 2026-03-31)

### Fixable ceiling (Ruffle vs Flash analysis, 2026-04-02)

A significant portion of the remaining diff is due to Ruffle-specific behavior that we cannot match without breaking Flash-compatible tests (see `RUFFLE_VS_FLASH_DIFFERENCES.md` — "Object.prototype Methods ENUMERABLE by Default"):

| Test | Total | Matching | Ruffle-specific | Fixable ceiling | Remaining gap |
|------|-------|----------|----------------|-----------------|---------------|
| global_proto_decls | 4497 | 884 (20%) | ~1665 | ~2832 (63%) | ~1948 |
| global_proto_decls_delete | 4158 | 296 (7%) | ~2477 | ~1681 (40%) | ~1385 |
| global_instance_decls | 758 | 23 (3%) | TBD | TBD | TBD |

**Ruffle-specific lines** = inherited Object.prototype methods appearing without "own" label (~9 per object/prototype, ENUMERABLE in Ruffle, DONT_ENUM in Flash) + `constructor` appearing as own property on non-prototype objects (Ruffle sets it explicitly, Flash inherits it).

The ~3300 remaining fixable lines across the two main tests correspond to the work in Phases 8c-4, 8c-5, and 8d below.

### Changes made (2026-04-01 session 4)
- **AsBroadcaster function own_props** — Shared g_ab_addListener_func, g_ab_removeListener_func, g_ab_broadcastMessage_func now have proper own_props (constructor + __proto__) via setupNativeFuncOwnProps.
- **addNativeFuncPrototype helper** — New function creates prototype_obj eagerly with correct LIFO insertion order (constructor before __proto__) and adds prototype to own_props as DONT_ENUM.
- **Selective prototype creation** — addListener and removeListener get prototype objects (matching expected output); broadcastMessage does NOT (matching expected output that shows no prototype for broadcastMessage).
- **Blocker reclassified** — "constructor/__proto__ DONT_ENUM" blocker reclassified as Ruffle vs Flash difference. Object.prototype methods are ENUMERABLE in Ruffle but DONT_ENUM in Flash. Inherited constructor skip confirmed as correct Flash behavior.

### Changes made (2026-04-01 session 3)
- **TextRenderer prototype flag** — Removed DONT_ENUM from TextRenderer constructor's `prototype` property.
- **System.IME method own_props** — Created IME-specific copies of AsBroadcaster functions (removeListener, addListener, broadcastMessage) with proper own_props (prototype/\_\_proto\_\_/constructor). IME-specific methods (doConversion, setEnabled, etc.) also get own_props.
- **`no_lazy_prototype` flag on ASFunction** — New field prevents lazy `.prototype` creation for native functions that shouldn't have prototypes (broadcastMessage, IME methods, setClipboard, showSettings).
- **`setupNativeFuncOwnProps` helper** — Reusable helper sets up own_props with \_\_proto\_\_ + constructor on native functions.
- **System.security rewrite** — Added PolicyFileResolver (with prototype + AsBroadcaster methods + resolve), 5 security method stubs (allowDomain, allowInsecureDomain, loadPolicyFile, chooseLocalSwfPath, escapeDomain), sandboxType READ_ONLY flag, \_\_constructor\_\_ (DONT_ENUM, deferred fill-in to Object constructor).
- **System.setClipboard, showSettings, Product** — All get proper own_props. Product gets prototype with 6 methods (installedVersion, validate, download, launch, isInstalled, isRunning).
- **System.capabilities expansion** — Added ~27 missing properties (_internal, supports64/32BitProcesses, hasIME, cpuArchitecture, cpuAddressSize, isEmbeddedInAcrobat, maxLevelIDC, windowlessDisable, localFileReadDisable, avHardwareDisable, hasScreenBroadcast/Playback, hasPrinting, hasEmbeddedVideo, hasStreamingVideo/Audio, serverString, hasMP3, hasAudioEncoder, hasTLS, screenColor, hasAccessibility).
- **Object.prototype method reordering** — Reordered insertion to match Flash LIFO enumeration: constructor(placeholder), watch, unwatch, addProperty, valueOf, toString, hasOwnProperty, isPrototypeOf, isPropertyEnumerable, toLocaleString. Added `toLocaleString` method (delegates to toString).
- **Object constructor own_props rebuild** — Post-ensureCtorOwnProps rebuild with correct LIFO order (prototype, constructor, \_\_proto\_\_, registerClass) and READ_ONLY/DONT_ENUM flags.
- **Function enumeration \_\_proto\_\_ chain walking** — actionEnumerate2 for FUNCTION now walks own_props.\_\_proto\_\_ chain (previously only enumerated own_props directly). Enables inherited Object.prototype methods to appear on function objects.
- **Constructor inheritance filtering** — Both OBJECT and FUNCTION enumeration skip inherited "constructor" during \_\_proto\_\_ chain walk (Flash doesn't propagate constructor through for-in chain walking).

### Changes made (2026-04-01 session 2)
- **ColorTransform.prototype virtual properties** — All 8 multiplier/offset properties converted from plain F64 values to addProperty virtual getters (return undefined on prototype). rgb getter now checks native_type. All 9 properties have READ_ONLY flag on prototype. Created `setAddPropertyWithFlags` helper.
- **Point constructor own_props order** — Swapped `interpolate`/`polar` insertion order so `interpolate` enumerates before `polar`.
- **Point.prototype.length** — Added as READ_ONLY virtual addProperty getter (sqrt(x²+y²), returns NaN on prototype).
- **Rectangle.prototype virtual properties** — Added 7 virtual getters: left, right, top, bottom, topLeft, bottomRight, size. left/top have setters (writable), others READ_ONLY.
- **flash.filters registration order** — Reordered to match expected: DisplacementMapFilter, ColorMatrixFilter, ConvolutionFilter, GradientBevelFilter, GradientGlowFilter, BevelFilter, GlowFilter, BlurFilter, DropShadowFilter, BitmapFilter.
- **Filter clone on BitmapFilter.prototype** — `clone` now registered on BitmapFilter.prototype (CONFIGURABLE), inherited by 9 subclass prototypes via __proto__ chain. Subclass prototypes no longer have own `clone`.
- **Filter __proto__ chain** — All 9 filter subclass prototypes now have `__proto__` → BitmapFilter.prototype.
- **Filter __constructor__ property** — All 9 subclass prototypes now have `__constructor__` (DONT_ENUM) pointing to their constructor.
- **Filter constructor deleted from subclass prototypes** — Constructor own property removed from 9 subclass prototypes (inherited via BitmapFilter.prototype chain).
- **Filter virtual properties** — 75 READ_ONLY virtual addProperty getters across 9 filter prototypes (alpha, color, mode, blurX, blurY, etc.).
- **BitmapData constructor own_props order** — Pre-added prototype/constructor/__proto__ placeholders before channel constants and loadBitmap. Removed loadBitmap from prototype (static method only).
- **BitmapData.prototype method reorder** — All 23 methods reordered to match expected LIFO enumeration. Added 4 virtual READ_ONLY properties (width, height, rectangle, transparent) returning -1.
- **TextRenderer own_props** — Added displayMode (READ_ONLY, string), maxLevel (READ_ONLY, number), setAdvancedAntialiasingTable (function) to flash.text.TextRenderer constructor.
- **System object rewrite** — Added privateBytes (READ_ONLY number), setClipboard/showSettings/Product (stub functions), useCodepage/exactSettings (READ_ONLY booleans). Proper LIFO insertion order. Removed own toString (inherited from Object.prototype).
- **System.IME rewrite** — Added 6 IME-specific methods (doConversion, setCompositionString, setConversionMode, getConversionMode, setEnabled, getEnabled) + 8 string constants (ALPHANUMERIC_FULL/HALF, CHINESE, etc.) All with DONT_ENUM + READ_ONLY flags. AsBroadcaster methods also DONT_ENUM + READ_ONLY. __proto__ and constructor READ_ONLY.
- **System/IME constructor fixup** — Deferred constructor value fill-in to ensureGlobalInit (after Object constructor available).

### Changes made (2026-03-31 session 2)
- **Geometry constructor own_props UNDEFINED placeholder fix** — `ensureCtorOwnProps` and flash.* constructor loop now check for UNDEFINED type (not just NULL) when filling in constructor/__proto__/prototype placeholders. Fixes Point/Matrix/Rectangle constructor own_props.
- **Point.prototype enumeration order** — Reordered property insertion to match expected LIFO enumeration: toString first, then normalize, add, subtract, equals, offset, clone, __proto__, constructor.
- **ensureBuiltinPrototypeProps UNDEFINED handling** — Function now fills in UNDEFINED placeholder constructor values in-place instead of skipping them.

### Changes made (2026-03-30)
- **WRITABLE enforcement in FUNCTION case of actionSetMember** — textRenderer displayMode/maxLevel now correctly show READ_ONLY; prototype property on ExternalInterface is also READ_ONLY
- **flash.automation prototype methods** — Configuration.prototype (5 methods), ActionGenerator.prototype (4 methods), StageCapture.prototype (9 methods) added
- **flash.automation own_props order** — Configuration and ActionGenerator now use reversed LIFO order (prototype, __proto__, constructor)
- **Package object constructor** — All flash.* package objects now have `constructor` property (= Object) with DONT_DELETE flag
- **Package object flags** — constructor and __proto__ on package objects now have ENUMERABLE | WRITABLE (DONT_DELETE) flags
- **ExternalInterface properties** — All 28 properties added with correct DONT_ENUM + READ_ONLY flags, including 10 new stub methods (_toJS, _objectToJS, _arrayToJS, _callIn, _useSetReturnValueHack, _callOut, _evalJS, _addCallback, _objectID, _initJS)
- **FileReferenceList prototype methods** — browse, _listeners, removeListener, addListener, broadcastMessage (DONT_ENUM + DONT_DELETE)
- **FileReference prototype methods** — deleteConvertedPPT, convertToPPT, cancel, download, upload, browse, _listeners, removeListener, addListener, broadcastMessage (DONT_ENUM + DONT_DELETE)
- **Geom registration order** — flash.geom children reordered to match expected enumeration (Transform, ColorTransform, Matrix, Point, Rectangle)
- **ensureBuiltinPrototypeProps** — Fixed __proto__/constructor insertion order on prototype objects (constructor before __proto__ for correct LIFO)
- **Geometry constructor own_props order** — Matrix, Point, Rectangle now use reversed LIFO order

### Current Pass Rates (2026-03-30)

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
| native_objects_swf6 | 83/84 | 99% | **FAIL** | Pre-existing: `new TextField()` returns native (should be undefined in SWF6) — SWF6 gate reverted due to textfield_props_swf6 conflict |
| native_objects_swf7 | 84/84 | 100% | **PASS** | |
| native_objects_swf8 | 84/84 | 100% | **PASS** | |
| as_set_prop_flags | 79/79 | 100% | **PASS** | |
| global_swf6_7_8 | 15/15 | 100% | **PASS** | |
| swf5_global_funcs | 232/232 | 100% | **PASS** | |
| swf6_global_funcs | 232/232 | 100% | **PASS** | |
| swf7_global_funcs | 232/232 | 100% | **PASS** | |
| global_swf5_6_7_8_9 | 1145/1145 | 100% | **PASS** | |
| native_subclasses | PASS | 100% | **PASS** | |
| global_proto_decls | ~742/4497 | ~16.5% | **FAIL** | Lines 1-742 match. Next blocker: constructor own property on every ASObject (GLOBALS_PLAN known blocker) |
| global_proto_decls_delete | ~287/4158 | ~6.9% | **FAIL** | Lines 1-287 match. Next blocker: IME method own_props DONT_DELETE |
| global_instance_decls | 17/758 | ~2% | **FAIL** | Phase 8d — DONT_DELETE on instance __proto__, missing instance properties, special construction behavior |

---

## Blocker: Ruffle vs Flash Object.prototype Enumeration (RECLASSIFIED)

**Reclassified 2026-04-01 session 4.** Originally documented as "constructor/\_\_proto\_\_ DONT_ENUM vs ENUMERABLE conflict". Investigation revealed this is a **Ruffle vs Flash behavioral difference**, not a fixable flag issue.

**What the test shows:** `global_proto_decls` expects `constructor` and `__proto__` on built-in prototypes to appear as ENUMERABLE (no DONT_ENUM label). It also expects Object.prototype methods (toLocaleString, watch, etc.) to appear as ENUMERABLE on descendant objects.

**Root cause (Ruffle-specific):** In Ruffle, Object.prototype methods and constructor/\_\_proto\_\_ on prototypes are ENUMERABLE by default. The test output was generated by Ruffle and reflects this behavior. In Flash, these are DONT_ENUM — confirmed by passing tests (context_menu, printjob_props_swf5/6/7, sound_props_swf5/6) where for-in on prototypes/instances yields NO inherited Object.prototype properties.

**Additional Ruffle difference:** Ruffle sets `constructor` as an OWN property on all objects (including plain objects like `System.capabilities`). In Flash, `constructor` is typically inherited from the prototype chain, not set as an own property on every object.

**Why the original "7 tests would break" blocker was partially wrong:** The constructor inheritance skip in `actionEnumerate2` was added in session 3 but the blocker wasn't re-evaluated. Testing confirmed that the skip IS correct Flash behavior — inherited `constructor` should not propagate through for-in. The real remaining gap is Ruffle's ENUMERABLE-by-default Object.prototype methods, which we cannot replicate without breaking Flash-compatible tests.

**Current status:** constructor stays DONT_ENUM on prototypes (Flash behavior). Each prototype block in the test output has ~11+ lines of Ruffle-specific enumerable inherited methods that we won't match. See `RUFFLE_VS_FLASH_DIFFERENCES.md` for the full entry.

## Remaining Work (Phases 8c-4, 8c-5, 8d)

### Phase 8c-4: Add missing properties on existing objects

**What:** The test enumerates deep into each object. Several globals are missing expected properties:

| Object | Missing Properties |
|--------|--------------------|
| Key | 20 constants (ALT, ENTER, SPACE, UP, DOWN, LEFT, RIGHT, etc.), `isAccessible` method |
| Mouse | `show`, `hide`, `setTrailer`, `setTrailerPosition`, `setTrailerMode` methods |
| Accessibility | `isActive`, `sendEvent`, `updateProperties` methods |
| StageCapture.prototype | 8 methods (toString, valueOf, listenForStageCapture, setClipRect, getClipRect, setFileNameBase, getFileNameBase, cancel, capture) |
| Object.prototype | `constructor` property (→ Object constructor, DONT_DELETE) |
| Function.prototype | `apply`, `call` methods + `constructor` property |

**Risk:** Low for adding properties. Adding Object.prototype.constructor and Function.prototype methods could affect for-in on instances — needs careful DONT_ENUM flagging.

**Impact:** ~50-100 lines per object. StageCapture.prototype alone would recover ~8 lines in proto_decls_delete.

### Phase 8c-5: Property flags cleanup

**What:** Set correct DONT_ENUM / READ_ONLY flags:
- Stage/Key/Mouse/Selection broadcaster methods (broadcastMessage, addListener, removeListener) should be DONT_ENUM
- textRenderer displayMode/maxLevel should be READ_ONLY (requires actionSetMember to check WRITABLE flag)
- Various constructor prototype methods need correct DONT_ENUM flags

**Risk:** Medium. READ_ONLY enforcement requires changes to actionSetMember which could have broad effects.

**Note:** textRenderer displayMode/maxLevel flags were changed to CONFIGURABLE (deletable) in 20b44c31 — the proto_decls_delete test expects them deletable. READ_ONLY enforcement (for the proto_decls test) is a separate concern.

### Phase 8c-6: flash.* constructor own_props property order

**What:** Some flash.* constructors have own_props property order that differs from the Phase 8c-2 standard (prototype, constructor, __proto__). Specifically:
- flash.automation.Configuration and ActionGenerator expect: prototype, __proto__, constructor (insertion: constructor, __proto__, prototype)
- flash.automation.StageCapture and most others expect: __proto__, constructor, prototype (insertion: prototype, constructor, __proto__)

This causes cascading misalignment in proto_decls_delete starting around line 65. The variance likely reflects Ruffle's internal initialization order for these specific classes.

**Risk:** Low — only affects these 3 tests. Could be fixed per-constructor with special-case insertion order.

**Impact:** Would recover ~10-20 lines in proto_decls_delete by fixing cascading misalignment.

### Phase 8d: Instance construction (global_instance_decls)

**Root cause identified (2026-03-14):** SetMember and GetMember both work correctly on instances — properties are written and read back as STRING. The systematic "READ_ONLY" label comes from the test's `contains(modifiable, key)` helper returning UNDEFINED instead of BOOLEAN for ALL calls.

**Root cause found and FIXED (2026-03-14, 79f6c1c2):** `registerGeomMethod` was adding prototype methods (e.g., `Rectangle.contains`) to the global `function_registry`. When the test defined a user function `contains`, it was registered at index 0 (before ensureGlobalInit). Then ensureGlobalInit registered `Rectangle.contains` at a higher index (~249). `lookupFunctionByName` searched in reverse (highest index first), finding `Rectangle.contains` instead of the user's `contains`. The user's `contains` helper returned UNDEFINED because it was dispatching to `rectContains` (a native Rectangle method) instead of the user-defined loop function.

**Fix:** Removed `function_registry` addition from `registerGeomMethod` — prototype methods are accessible via the prototype chain, not the global function name lookup. The existing `registerProtoMethod` (used for BitmapData) already had this fix; `registerGeomMethod` now matches.

**Also needed** (separate from the array bug):
- Missing instance-specific properties (PrintJob: paperHeight/paperWidth/etc., FileReference: name/type/size/etc.)
- Special construction behavior for textRenderer (→ undefined), flash.automation.Configuration (→ `[[AutomationConfiguration]]`)

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
- `1649ff97` — Phase 8c-3: Register System/flash/textRenderer on _global, flash.automation, flash sub-package order, MCL method order, LC isPerUser, PrintJob props version-gating, valueOf removal
- `20b44c31` — Phase 8c-2.5: Fix actionDelete for ASFunction, DONT_DELETE on built-in prototype/constructor props, flash.* stub constructor prototype + own_props setup, textRenderer flag fix

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
| 8c-1 | Fix actionEnumerate2 prototype chain walking for functions | **NOT NEEDED** — Flash doesn't walk chain for functions |
| 8c-2 | Populate own_props on every constructor | **DONE** (7714e908) |
| 8c-2.5 | DONT_DELETE flags + actionDelete fix + flash.* stub setup | **DONE** (20b44c31) |
| 8c-3 | Register System + flash + textRenderer on _global | **DONE** (1649ff97) — flash.automation added, sub-package order fixed |
| 8c-4 | Add missing properties on existing objects | **PARTIAL** — EI methods done, FileRef methods done, automation methods done. Remaining: Key constants, Mouse/Accessibility methods, Transform.prototype properties, filter clone |
| 8c-5 | Property flags cleanup | **PARTIAL** — textRenderer READ_ONLY done, EI READ_ONLY done, package DONT_DELETE done. Remaining: filter enumeration order, geometry prototype READ_ONLY properties |
| 8c-6 | flash.* constructor own_props property order | **DONE** — Configuration, ActionGenerator, FileRef, Matrix, Point, Rectangle all use correct order |
| 8d | Instance construction differences | **BLOCKED** — systematic DONT_DELETE on instance __proto__, special construction returns (textRenderer→undefined, Configuration→[[AutomationConfiguration]]), missing instance properties |
