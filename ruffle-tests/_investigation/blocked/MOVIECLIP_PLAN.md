# MovieClip Features Implementation Plan
<!-- TESTS: movieclip_default_state, movieclip_blend_mode_property, movieclip_focusenabled, movieclip_lockroot, movieclip_depth_methods, movieclip_get_instance_at_depth, create_empty_movie_clip, default_names, place_and_lookup, placeobject_occupied_depth, attach_movie, attach_movie_stop, export_assets, movieclip_init_object, empty_movieclip_can_attach_movies, duplicate_movie_clip, clone_sprite_types, remove_movie_clip, rewind_depth, clip_events, clip_event_propagation_order, on_construct, clip_constructors, do_init_action_child, execution_order4, movieclip_getbounds, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8, movieclip_hittest, movieclip_hittest_shapeflag, local_to_global, custom_clip_methods, movieclip_state_values, movieclip_library_state_values, movieclip_methods_with_loaded_image, movieclip_create_text_field, movieclip_gettextsnapshot, movieclip_setmask, clone_sprite_edittext, clone_sprite_edittext_dynamic, duplicate_movie_clip_drawing, unload, unload_clip_event, unload_nested_child, removed_base_clip_tell_target, removed_clip_halts_script, removed_target_clip_scope, stage_object_children, swf7_case_sensitive, movieclip_name_from_timeline, register_class, register_and_init_order -->

Last updated: 2026-03-13

## Status: All 10 Phases COMPLETE — remaining tests blocked

**44 of 54 tests PASSING.** All actionable phases complete. Remaining 10 failures are blocked on loadMovie, pixel-level hit testing, TextField cloning, or edge-case lifecycle issues.

### Implementation Commits
- `c616aeb` — Implement MovieClip Phase 1: properties, prototype, transform, blendMode
- (subsequent) — Depth methods, createEmptyMovieClip, duplicateMovieClip, removeMovieClip, localToGlobal/globalToLocal
- `f0cb91ca` — Implement ExportAssets + attachMovie (Phase 4)
- `feedc1a8` — Fix attachMovie: deferred init dedup, sprite child persistence, tagDefineSprite ordering
- `508d8950` — Fix create_empty_movie_clip + movieclip_init_object: enterFrame timing and sync constructor
- `1a6fdaf8` — Phase 10: AS-level onLoad for RegisterClass sprites + mouse event ordering

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
| 10 | AS-level event dispatch + ordering | **DONE** |

### Test Results (2026-03-13)

**44 PASS:**

| Test | Status |
|------|--------|
| clip_event_propagation_order | **PASS** |
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

## Phase 10: AS-Level Event Dispatch + Ordering — COMPLETE

Implemented in `1a6fdaf8`. Key changes:
- AS-level onLoad dispatch for timeline-placed RegisterClass sprites (queued in `process_sprite_init_at_depth`, flushed from `tagShowFrame`)
- Fixed `process_sprite_needs_init` to process depth 0
- Reversed mouse event dispatch order (highest depth first)
- `mc_call_as2_handler_ng` now walks prototype chain via `getPropertyWithPrototype`
- Fixed child_mc_cache duplicate registration in attachMovie
- Fixed allocator mismatch (HCALLOC vs calloc/realloc for sprite display lists)
