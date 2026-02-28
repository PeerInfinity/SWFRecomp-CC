# RegisterClass and Export/Registration Implementation Plan

<!-- TESTS: register_class_return_value, register_class, register_class_swf6, register_class_with_sound, register_and_init_order, register_globals_across_frames, register_underflow, attach_movie, attach_movie_stop, export_assets, clip_constructors, on_construct, movieclip_init_object, empty_movieclip_can_attach_movies, do_init_action_child -->

Last updated: 2026-02-28
Status: **BLOCKED** — moved to blocked/

## Summary

This plan covered implementing `Object.registerClass()`, ExportAssets (tag 56), `attachMovie()`, and the constructor invocation pipeline. All implementable phases are complete. Remaining failures are blocked on infrastructure that doesn't exist yet (child SWF loading, Sound class, button MC typeof, sprite init ordering).

## Final Test Results (15 tests)

### Passing (10/15)

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

### Failing (5/15)

| Test | Lines | Match | Blocker |
|------|-------|-------|---------|
| register_class | 67 | 26/67 | Lines 27-29: button MC typeof. Lines 31+: child SWF loading (loadMovie) |
| register_class_swf6 | 37 | 2/37 | Entirely depends on child SWF loading |
| register_class_with_sound | 11 | 5/11 | Needs Sound class implementation |
| register_and_init_order | 233 | ~76/233 | Line 35: deep child access during constructor. Lines 133+: child sprite constructor ordering |
| do_init_action_child | 12 | 3/12 | Needs child SWF loading (loadMovie/MovieClipLoader) |

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
**Blocks**: register_class (lines 31+), register_class_swf6 (all), do_init_action_child (9 lines)
**What's needed**: The ability to load external `.swf` files at runtime (`loadMovie`, `MovieClipLoader.loadClip`). The register_class test loads `child.swf` and `child_swf6.swf` which contain their own registerClass calls and prototype checks.
**Plan**: LOADMOVIE_PLAN (already in blocked/)

### 2. Sprite Initialization Ordering
**Blocks**: register_and_init_order (lines 133+)
**What's needed**: When sprite_6 ("a") contains child sprite_5 ("aa", export "aa"), the registered class constructor for "aa" should fire BETWEEN the parent "a" constructor end and parent first frame script. Currently "aa"'s constructor fires too late (after parent frame script).
**Root cause**: Constructor invocation happens at `tagSetInstanceName` during eager init, but child sprites' constructors are deferred to `process_sprite_needs_init`. The ordering needs to be: parent constructor → child constructors (recursive) → parent frame script.
**Difficulty**: HIGH — requires rearchitecting the sprite initialization pipeline to control when child constructors fire relative to parent frame scripts.

### 3. Deep Child Access During Constructor
**Blocks**: register_and_init_order (line 35)
**What's needed**: `this.box.box` should resolve during constructor execution (grandchild display lists need to be initialized when constructor fires at tagSetInstanceName time).
**Root cause**: When constructor fires at tagSetInstanceName, only the immediate children's display list is populated. Grandchildren haven't been placed yet because their parent sprite hasn't executed its tags.
**Difficulty**: HIGH — would require recursive tag execution for child sprites before constructor invocation.

### 4. Sound Class Implementation
**Blocks**: register_class_with_sound (6 lines)
**What's needed**: Sound constructor, Sound.attachSound(), Sound.start(), Sound.stop(). The test registers a class for a sound symbol.
**Plan**: Part of GLOBALS_PLAN (Sound class stub exists but is minimal)

### 5. Button MC typeof
**Blocks**: register_class (lines 27-29, 3 lines)
**What's needed**: `typeof` a button-based MC should return "object" (currently returns "movieclip" or something else). Minor issue, low priority.

## Changes Made (commits)

1. **Default MC prototype in attachMovie** (commit 685ab0b3, 2026-02-28): Both CallFunction and CallMethod attachMovie paths now set `mc.__proto__ = MovieClip.prototype` when no registered class exists. Previously, attached MCs without a registered class had no prototype set, causing `mc.__proto__ === MovieClip.prototype` to fail.

2. **Object.registerClass undefined unregister** (same commit): `Object.registerClass(sym, undefined)` now correctly unregisters (previously only NULL was handled, not UNDEFINED).

3. Earlier commits (from previous sessions): Phase 0-5 implementation including ExportAssets parsing, attachMovie, registerClass registry, constructor invocation at tagSetInstanceName, initVarArray ordering, on(construct) event, clip_constructors fixes, etc.
