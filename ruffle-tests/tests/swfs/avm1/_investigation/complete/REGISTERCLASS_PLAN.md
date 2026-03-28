# RegisterClass and Export/Registration Implementation Plan

<!-- TESTS: register_class_return_value, register_class, register_class_swf6, register_class_with_sound, register_and_init_order, register_globals_across_frames, register_underflow, attach_movie, attach_movie_stop, export_assets, clip_constructors, on_construct, movieclip_init_object, empty_movieclip_can_attach_movies, do_init_action_child -->

<!-- PLAN_META
id: REGISTERCLASS
status: complete
phases:
  - id: 0
    name: "VM Register Fixes —"
    status: complete
  - id: 1
    name: "ExportAssets Parsing —"
    status: complete
  - id: 2
    name: "attachMovie Implementation —"
    status: complete
  - id: 3
    name: "Object.registerClass —"
    status: complete
  - id: 4
    name: "Constructor Invocation —"
    status: complete
  - id: 5
    name: "DoInitAction Ordering + on(construct) —"
    status: complete
dependencies:
  - plan: THIS_BINDING
    type: requires
    reason: "registerClass requires constructor call infrastructure via this binding"
blockers: []
-->

Last updated: 2026-03-11
Status: **BLOCKED** — moved to blocked/

## Summary

This plan covered implementing `Object.registerClass()`, ExportAssets (tag 56), `attachMovie()`, and the constructor invocation pipeline. All implementable phases are complete. register_and_init_order now fully passes (233/233). Remaining failures are blocked on infrastructure that doesn't exist yet (child SWF loading, button MC typeof).

## Final Test Results (15 tests)

### Passing (14/15)

| Test | Lines | Result |
|------|-------|--------|
| register_class_return_value | 16 | **16/16 PASS** |
| register_globals_across_frames | 12 | **12/12 PASS** |
| register_underflow | 26 | **26/26 PASS** |
| attach_movie | 59 | **PASS** |
| attach_movie_stop | 3 | **PASS** |
| export_assets | 3 | **PASS** |
| clip_constructors | 8 | **8/8 PASS** |
| on_construct | 25 | **25/25 PASS** |
| movieclip_init_object | 5 | **5/5 PASS** |
| empty_movieclip_can_attach_movies | 11 | **PASS** |
| do_init_action_child | 12 | **12/12 PASS** ✅ (cross-version Phase 1+4 + ImportAssets2) |
| register_class_with_sound | 11 | **11/11 PASS** ✅ (fixed by Sound Phase 0) |
| register_and_init_order | 233 | **233/233 PASS** ✅ (fixed 2026-03-11: child constructor ordering + Phase 0 deferred constructors + script_only_mode in attach inits) |

### Failing (1/15)

| Test | Lines | Match | Blocker |
|------|-------|-------|---------|
| register_class | 67 | 26/67 | Lines 27-29: button MC typeof. Lines 31+: child SWF loading (loadMovie) |

## What Was Implemented

### Phase 0: VM Register Fixes — COMPLETE
- `register_globals_across_frames`: Register reset between frames
- `register_underflow`: DefineFunction2 register count scoping

### Phase 1: ExportAssets Parsing — COMPLETE
- Recompiler parses tag 56, emits `tagRegisterExport()` calls
- Runtime symbol table in `tag_stubs.c` with `tagLookupExport()` / `ng_lookupExportName()`

### Phase 2: attachMovie Implementation — COMPLETE
- Full `attachMovie()` dispatch in both CallFunction and CallMethod paths
- Depth validation, initObject application, deferred frame scripts
- `createEmptyMovieClip` infrastructure reused

### Phase 3: Object.registerClass — COMPLETE
- Registry with `g_registered_classes[128]`
- Static method on Object constructor via `registerGeomMethod`
- Return value validation (string first arg, function/null/undefined second arg)
- `Object.registerClass(sym, undefined)` correctly unregisters (fixed 2026-02-28)

### Phase 4: Constructor Invocation — COMPLETE (partial coverage)
- Timeline placement: constructors fire at `tagSetInstanceName` time
- attachMovie: constructors fire synchronously during attachMovie
- Prototype chain: `mc.__proto__` set to `ctor.prototype` correctly
- Default MC prototype: `mc.__proto__` set to `MovieClip.prototype` when no registered class (fixed 2026-02-28)
- Super context pushed for constructor calls
- `__constructor__` set on MC's dynamic_props

### Phase 5: DoInitAction Ordering + on(construct) — COMPLETE
- Recompiler `initVarArray` ordering fix (before DoInitAction scripts)
- `on(construct)` clip event fires before registered class constructor
- `g_pending_instance_name` mechanism for correct instance name during on(construct)
- `actionSetupRegisteredClassPrototype` sets `__proto__`/`__constructor__` before on(construct)

## Remaining Blockers

### 1. Child SWF Loading (loadMovie)
**Blocks**: register_class (lines 31+), register_class_swf6 (all)
**What's needed**: The ability to load external `.swf` files at runtime (`loadMovie`, `MovieClipLoader.loadClip`). The register_class test loads `child.swf` and `child_swf6.swf` which contain their own registerClass calls and prototype checks.
**Plan**: LOADMOVIE_PLAN (already in blocked/)
**Note**: do_init_action_child is now PASS (12/12) via cross-version Phase 1+4 + ImportAssets2

### 2. Sprite Initialization Ordering — RESOLVED
**Was blocking**: register_and_init_order (lines 133+) — now **233/233 PASS** ✅
**Fixed by**: Three-part fix (commit fe35db71, 2026-03-11):
1. `ng_fire_child_constructors`: Recursively fires child sprite constructors during attachMovie, immediately after the parent's constructor. Ensures children like "box" get constructors before goto catch-up.
2. Phase 0 deferred constructor pass (`ng_fire_deferred_constructors`): In swf_core.c goto processing, fires ALL pending constructors via `g_constructor_only_mode` before Phase 2 scripts.
3. `g_script_only_mode` in `ng_fire_pending_attach_inits`: Prevents tagPlaceObject2's loop-back preservation from clearing `sprite_needs_init` on child sprites during frame function re-run.

### 3. Deep Child Access During Constructor — RESOLVED
**Was blocking**: register_and_init_order (line 35) — now passing ✅
**Fixed by**: `mc->display_obj` linking in `fire_eager_constructors` and tagPlaceObject2's constructor block. Child MCs get their `display_obj` pointer set before constructors fire, enabling `this.box.box` resolution via `sprite_display_list`.

### 4. Sound Class Implementation — RESOLVED
**Was blocking**: register_class_with_sound (6 lines) — now PASS (11/11)
**Fixed by**: Sound Phase 0 (getPan/setPan/getTransform/setTransform, checkInstanceOf for registerClass MCs)

### 5. Button MC typeof
**Blocks**: register_class (lines 27-29, 3 lines)
**What's needed**: `typeof` a button-based MC should return "object" (currently returns "movieclip" or something else). Minor issue, low priority.

## Changes Made (commits)

1. **Default MC prototype in attachMovie** (commit 685ab0b3, 2026-02-28): Both CallFunction and CallMethod attachMovie paths now set `mc.__proto__ = MovieClip.prototype` when no registered class exists. Previously, attached MCs without a registered class had no prototype set, causing `mc.__proto__ === MovieClip.prototype` to fail.

2. **Object.registerClass undefined unregister** (same commit): `Object.registerClass(sym, undefined)` now correctly unregisters (previously only NULL was handled, not UNDEFINED).

3. Earlier commits (from previous sessions): Phase 0-5 implementation including ExportAssets parsing, attachMovie, registerClass registry, constructor invocation at tagSetInstanceName, initVarArray ordering, on(construct) event, clip_constructors fixes, etc.

4. **register_and_init_order constructor ordering fix** (commit fe35db71, 2026-03-11): Three-part fix: (1) `ng_fire_child_constructors` fires child sprite constructors during attachMovie after parent constructor. (2) Phase 0 `ng_fire_deferred_constructors` in goto processing fires all pending constructors before Phase 2 scripts. (3) `g_script_only_mode` in `ng_fire_pending_attach_inits` prevents tagPlaceObject2 loop-back preservation from clearing child `sprite_needs_init`. Also: `g_eager_init_depth` tracking, `g_constructor_only_mode` flag, `display_obj` linking for child MCs.
