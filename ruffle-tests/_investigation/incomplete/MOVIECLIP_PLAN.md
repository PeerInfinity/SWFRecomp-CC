# MovieClip Features Implementation Plan
<!-- TESTS: movieclip_default_state, movieclip_blend_mode_property, movieclip_focusenabled, movieclip_lockroot, movieclip_depth_methods, movieclip_get_instance_at_depth, create_empty_movie_clip, default_names, place_and_lookup, placeobject_occupied_depth, attach_movie, attach_movie_stop, export_assets, movieclip_init_object, empty_movieclip_can_attach_movies, duplicate_movie_clip, clone_sprite_types, remove_movie_clip, rewind_depth, clip_events, clip_event_propagation_order, on_construct, clip_constructors, do_init_action_child, execution_order4, movieclip_getbounds, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8, movieclip_hittest, movieclip_hittest_shapeflag, local_to_global, custom_clip_methods, movieclip_state_values, movieclip_library_state_values, movieclip_methods_with_loaded_image, movieclip_create_text_field, movieclip_gettextsnapshot, movieclip_setmask, clone_sprite_edittext, clone_sprite_edittext_dynamic, duplicate_movie_clip_drawing, unload, unload_clip_event, unload_nested_child, removed_base_clip_tell_target, removed_clip_halts_script, removed_target_clip_scope, stage_object_children, swf7_case_sensitive, movieclip_name_from_timeline, register_class, register_and_init_order -->

Last updated: 2026-03-13

## Status: Phases 1-9 COMPLETE — Phase 10 actionable, remaining tests blocked

**43 of 54 tests PASSING.** Phase 10 (AS-level event dispatch) is actionable. Remaining 10 failures are blocked on loadMovie, pixel-level hit testing, TextField cloning, or edge-case lifecycle issues.

### Implementation Commits
- `c616aeb` — Implement MovieClip Phase 1: properties, prototype, transform, blendMode
- (subsequent) — Depth methods, createEmptyMovieClip, duplicateMovieClip, removeMovieClip, localToGlobal/globalToLocal
- `f0cb91ca` — Implement ExportAssets + attachMovie (Phase 4)
- `feedc1a8` — Fix attachMovie: deferred init dedup, sprite child persistence, tagDefineSprite ordering
- `508d8950` — Fix create_empty_movie_clip + movieclip_init_object: enterFrame timing and sync constructor

### Phase Completion

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | MovieClip prototype + missing properties | **DONE** |
| 2 | Depth methods | **DONE** |
| 3 | createEmptyMovieClip + display list | **DONE** |
| 4 | ExportAssets + attachMovie | **DONE** |
| 5 | duplicateMovieClip + removeMovieClip | **DONE** |
| 6 | Clip events + construction order | **DONE** |
| 7 | getBounds / getRect | **DONE** |
| 8 | hitTest | **DONE** |
| 9 | localToGlobal / globalToLocal + others | **DONE** |
| 10 | AS-level event dispatch + ordering | **TODO** |

### Test Results (2026-03-13)

**43 PASS:**

| Test | Status |
|------|--------|
| movieclip_default_state | **PASS** |
| movieclip_blend_mode_property | **PASS** |
| movieclip_focusenabled | **PASS** |
| movieclip_lockroot | **PASS** |
| movieclip_depth_methods | **PASS** |
| movieclip_get_instance_at_depth | **PASS** |
| create_empty_movie_clip | **PASS** |
| default_names | **PASS** |
| place_and_lookup | **PASS** |
| placeobject_occupied_depth | **PASS** |
| attach_movie | **PASS** |
| attach_movie_stop | **PASS** |
| export_assets | **PASS** |
| movieclip_init_object | **PASS** |
| empty_movieclip_can_attach_movies | **PASS** |
| duplicate_movie_clip | **PASS** |
| clone_sprite_types | **PASS** |
| remove_movie_clip | **PASS** |
| rewind_depth | **PASS** |
| clip_events | **PASS** |
| on_construct | **PASS** |
| clip_constructors | **PASS** |
| do_init_action_child | **PASS** |
| execution_order4 | **PASS** |
| movieclip_getbounds | **PASS** |
| movieclip_invalid_get_bounds_1 | **PASS** |
| movieclip_invalid_get_bounds_2 | **PASS** |
| movieclip_invalid_get_bounds_3 | **PASS** |
| movieclip_invalid_get_bounds_4 | **PASS** |
| movieclip_invalid_get_bounds_5 | **PASS** |
| movieclip_invalid_get_bounds_8 | **PASS** |
| movieclip_hittest | **PASS** |
| local_to_global | **PASS** |
| custom_clip_methods | **PASS** |
| stage_object_children | **PASS** |
| swf7_case_sensitive | **PASS** |
| movieclip_name_from_timeline | **PASS** |
| unload | **PASS** |
| unload_clip_event | **PASS** |
| removed_clip_halts_script | **PASS** |
| removed_target_clip_scope | **PASS** |
| movieclip_create_text_field | **PASS** |
| movieclip_gettextsnapshot | **PASS** |
| movieclip_setmask | **PASS** |
| duplicate_movie_clip_drawing | **PASS** |
| register_class | **PASS** |
| register_and_init_order | **PASS** |

### Remaining failures

| Test | Status | Blocker |
|------|--------|---------|
| clip_event_propagation_order | 0/17 | **Phase 10** — AS-level onLoad + mouse event dispatch ordering |
| movieclip_hittest_shapeflag | ~266/339 | Pixel-level shape hit testing (not AABB) |
| movieclip_invalid_get_bounds_6 | FAIL | loadMovie for multi-SWF child bounds |
| movieclip_invalid_get_bounds_7 | FAIL | loadMovie for multi-SWF child bounds |
| movieclip_state_values | ~39/114 | loadMovie for multi-SWF child state comparison |
| movieclip_library_state_values | ~46/78 | `_xmouse` returns 0, `_url` path format |
| movieclip_methods_with_loaded_image | 0/4 | Image loading (loadMovie with PNG) |
| unload_nested_child | 0/5 | Nested child unload event propagation |
| removed_base_clip_tell_target | 0/2 | tellTarget with removed base clip edge case |
| clone_sprite_edittext | ~26/94 | TextField clone infrastructure (CLONE_DUPLICATE_PLAN Phase 2) |
| clone_sprite_edittext_dynamic | ~52/86 | TextField clone infrastructure (CLONE_DUPLICATE_PLAN Phase 2) |

---

## Phase 10: AS-Level Event Dispatch + Ordering

**Goal**: Fix `clip_event_propagation_order` (0/17) by implementing AS-level `onLoad` dispatch for RegisterClass sprites and correct mouse event propagation ordering.

### What the test does

The test uses AS2 classes (`Main extends MovieClip`, `Child extends MovieClip`) registered via `Object.registerClass`. The classes define `onLoad`, `onMouseMove`, `onMouseDown`, and `onMouseUp` as prototype methods — NOT as clip actions.

```actionscript
class Main extends MovieClip {
    function onLoad() {
        trace("Main onLoad");
        attachMovie("child", "child_depth10", 10, {childName: "child_depth10"});
        attachMovie("child", "child_depth20", 20, {childName: "child_depth20"});
        attachMovie("child", "child_depth30", 30, {childName: "child_depth30"});
        trace("Children created");
    }
    function onMouseMove() { trace("Main onMouseMove"); }
    // ... onMouseDown, onMouseUp similarly
}
```

Expected output:
```
Main onLoad              ← AS-level onLoad on timeline-placed RegisterClass sprite
Children created
child_depth10 onLoad     ← AS-level onLoad on attachMovie'd RegisterClass sprite
child_depth20 onLoad
child_depth30 onLoad
child_depth30 onMouseMove  ← highest depth first
child_depth20 onMouseMove
child_depth10 onMouseMove
Main onMouseMove           ← root/parent last
child_depth30 onMouseDown  ← same reverse-depth ordering
...
```

### Why it produces zero output

The test produces no output at all — not even "Main onLoad". The root cause is:

1. The sprite `main_mc` (char_id 4, exported as "main") is placed via `tagPlaceObject2Ratio` in frame_0
2. `Object.registerClass("main", Main)` links the Main class constructor
3. When the sprite is initialized, `actionInvokeRegisteredClassConstructor` fires and sets `__proto__` to `Main.prototype`
4. But the AS-level `onLoad` method on the prototype is **never dispatched** for timeline-placed sprites

The existing `onLoad` dispatch path (`actionFlushPendingOnLoads`) only fires for dynamically-created clips queued via `actionQueuePendingOnLoad` (called from `attachMovie`/`duplicateMovieClip`). Timeline-placed sprites with RegisterClass constructors are not queued.

### Fix: Two distinct issues

#### 10a. AS-level onLoad for timeline-placed RegisterClass sprites

After `actionInvokeRegisteredClassConstructor` fires for a timeline-placed sprite, the runtime must also dispatch the AS-level `onLoad` handler if one exists on the MC's prototype chain.

**Where to hook this**: In `tagShowFrame` (tag_stubs.c) or `ng_exec_sprite_frame` — after a sprite's RegisterClass constructor fires during `needs_init` processing, check for and invoke an `onLoad` method on the MC via `mc_call_as2_handler_ng(app_context, mc, "onLoad", 6, NULL, 0)`.

This already works for `attachMovie`-created clips because `actionQueuePendingOnLoad` + `actionFlushPendingOnLoads` handles them. The gap is timeline placement.

**Important**: The onLoad for `main_mc` must fire BEFORE the children's onLoad (since `main_mc.onLoad` is what creates the children). The children's onLoad should fire in placement order (depth 10, then 20, then 30), which `actionFlushPendingOnLoads` already handles for attachMovie'd clips.

#### 10b. Mouse event dispatch in reverse-depth order

The existing mouse dispatch functions (`actionDispatchMCMouseMoveGlobal`, `actionDispatchMCMouseDown`, `actionDispatchMCMouseUp` in action.c) iterate `child_mc_cache` in forward/insertion order. The test expects **reverse depth order** (highest depth first):

```
child_depth30 onMouseMove  ← depth 30 first
child_depth20 onMouseMove  ← depth 20 second
child_depth10 onMouseMove  ← depth 10 third
Main onMouseMove           ← root last
```

**Fix**: Before dispatching mouse events, sort the eligible MCs by their display list depth in descending order. Options:
1. Sort `child_mc_cache` by depth (descending) before iterating, or
2. Build a temporary sorted array of MCs with mouse handlers, sorted by depth descending
3. Look up each MC's depth via `ng_findDisplayEntryByName(mc->name)` for sorting

The root MC (`main_mc`) should dispatch AFTER all children, regardless of its depth — it's the parent and fires last.

#### 10c. Recursive child dispatch

The test creates children via `attachMovie` on `main_mc`. The mouse events must dispatch to children of `main_mc`, not just top-level children. The existing dispatch already walks `child_mc_cache` which includes nested MCs, but the ordering must respect the nesting hierarchy: all children of a parent dispatch before the parent itself.

### Files to modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag_stubs.c` | After RegisterClass constructor fires in `tagShowFrame` / needs_init processing, dispatch AS-level onLoad |
| `SWFModernRuntime/src/actionmodern/action.c` | Sort mouse event dispatch by depth (descending) in `actionDispatchMCMouseMoveGlobal`, `actionDispatchMCMouseDown`, `actionDispatchMCMouseUp` |

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=clip_event_propagation_order --diff --verbose
```

### Potential side effects

- Other tests using RegisterClass + timeline placement may now fire additional onLoad calls they didn't before. Need to verify `register_and_init_order` (233/233) and `on_construct` (25/25) still pass.
- Changing mouse dispatch ordering could affect `mouse_events` category tests — verify they still pass.
