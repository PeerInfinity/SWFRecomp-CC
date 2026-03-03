# Variable/Props Unification Plan — COMPLETE

## Status: PASS (5/5) ✅

`string_paths_variable_scopes` now passes 5/5.

## Overview

The runtime has two separate storage mechanisms for MovieClip properties that are out of sync:

1. **Timeline variables (`var_map`/`var_array`)** — Global hashtable + indexed array, used by `SetVariable`/`GetVariable`
2. **Dynamic properties (`dynamic_props`)** — Per-object ASObject property storage, used by `SetMember`/`GetMember`

## Root Cause (Revised)

The original plan identified the var_map vs dynamic_props asymmetry as the sole issue. In practice, three bugs combined to cause the 0/5 failure:

### Bug 1: SetVariable on root MC doesn't propagate to dynamic_props

SetMember on root MC propagates to var_map (`setVariableByName` at line ~23377), but SetVariable on root MC did NOT propagate to dynamic_props. This meant handlers set via `SetVariable("onEnterFrame", func)` at root level were invisible to `actionDispatchEnterFrameHandlers()` which checks dynamic_props.

**Fix:** Added bidirectional propagation in `actionSetVariable()` after var_map storage — mirrors the existing SetMember→var_map propagation.

**File:** `SWFModernRuntime/src/actionmodern/action.c` (~line 19153)

### Bug 2: attachMovie MCs missing `enterframe_eligible` flag

`ng_fire_pending_attach_inits()` runs the deferred frame function for MCs created via `attachMovie`, but did NOT set `enterframe_eligible = 1` on the display object afterward. The `actionDispatchEnterFrameHandlers()` dispatch requires this flag (set by `process_sprite_init_at_depth` for timeline sprites at line 279 of tag.c).

**Fix:** Added `dobj->enterframe_eligible = 1` in `ng_fire_pending_attach_inits()` after persisting the display list state.

**File:** `SWFModernRuntime/src/libswf/tag_stubs.c` (~line 1078)

### Bug 3: GetVariable resolves removed MC's dynamic_props

After `RemoveSprite` removes a MC (`depth = INT_MIN`), `actionGetVariable()` still checked the removed MC's `dynamic_props` when `g_current_context` pointed to it. This meant variables stored on the removed MC (e.g., `timer = 10`) were still found instead of falling through to root scope (`timer = 5`).

**Fix:** Added `g_current_context->depth != INT_MIN` guard to the non-root context check in `actionGetVariable()`, so removed MCs are skipped and resolution falls through to global scope.

**File:** `SWFModernRuntime/src/actionmodern/action.c` (~line 17773)

## Test Results

| Test | Before | After |
|------|--------|-------|
| `string_paths_variable_scopes` | 0/5 | 5/5 ✅ |

## Regression Guard (all pass)

- `string_paths_basic` ✅
- `string_paths_hidden` ✅
- `path_string` ✅
- `this_scoping` ✅
- `execution_order4` ✅
- `clip_events` ✅
- `create_empty_movie_clip` ✅
- `attach_movie` ✅
- `empty_movieclip_can_attach_movies` ✅
- `movieclip_init_object` ✅
- `init_object_order` ✅
- `register_class_return_value` ✅
- `on_construct` ✅
- `clip_constructors` ✅
- `set_interval` ✅
- `unload` ✅
