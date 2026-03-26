# Current Ruffle Test Status

Last updated: 2026-03-15 (evening)

## Quick Summary

- **Pass rate (CI, last run)**: 559/619 (90.3%) total, **549/563 (97.5%) filtered** (CI run on de8b5c0b, 0 regressions)
- **Image test baseline**: **7/31 strict image match** (run_image_tests.py, 0-outlier AND 0-max-diff). **9/31 tolerance pass** (within test.toml limits). Strict passes: focusrect_focuslost, focusrect_mouse_swf8/swf9, focusrect_swf6, frame_size_translated_neg/pos, mask_with_drawing. Tolerance-only: display_object_properties (max_diff=79), mask_reapply (max_diff=1).
- **Main failure types**: output_mismatch (60), timeout (1, ignored)
- **Known regressions**: None. Previous regressions all recovered.
- **Latest fixes (2026-03-15)**:
  - text_blocks_clicks PASS (DefineText bounds for _droptarget)
  - issue_2030 PASS (MC.attachBitmap stub)
  - unload_nested_child PASS (nested MC click fix, recursive child unload detection, deferred UNLOAD in catch_up_mode)
  - target_clip_removed PASS (char_id guard in upgrade_sprite_initialized)
  - issue_2084 PASS (nested attachMovie with registerClass — onLoad queue, initObject ordering)
  - coerce_to_object_monkeypatch PASS (primitive auto-boxing, addProperty getter lookup, this fallback to _global)
  - clone_sprite_edittext_dynamic PASS (TF clone property copy, rotated bounding box)
  - bitmap_data_draw_cliprect PASS (BitmapData.draw() with inverse matrix transform + clipRect)
  - bitmap_data_copypixels PASS (alpha compositing in copyPixels mergeAlpha=true)

## Crashes and Errors

| Test | Status | Notes |
|------|--------|-------|
| timeout | timeout | Infinite loop — needs script execution timeout mechanism |

All previous crashes/segfaults/runtime_errors have been fixed (funky_function_calls, goto_methods, native_objects_swf6/7/8, movieclip_invalid_get_bounds_6/7).

## Near-Passing Tests

| Test | Match | Issue |
|------|-------|-------|
| `edittext_default_format_empty` | ~95/100 (95%) | 5 missing `display = block;` lines — permanent diff (see RUFFLE_VS_FLASH_DIFFERENCES.md) |

All other previously near-passing tests have been fixed. 146 tests were tracked through the near-passing pipeline and are now fully passing — see `SESSION_NOTES.md` and git history for details.

## FrameLabelEntry compile_fail (FIXED)
202 tests had stale `FrameLabelEntry` typedef in generated tagMain.c conflicting with tag.h. Fixed by removing the stale typedefs from all generated files.

## Plan Implementation Status

### Completed plans
| Plan | Tests Passing |
|------|--------------|
| IMAGE_PLAN_01 | display_object_properties, color (trace); 2/31 image tests |
| DATE_PLAN | 8+ tests; `date` at ~99.2% |
| TRY_CATCH_PLAN | `try_catch_finally` 118/118 |
| MATH_PLAN | 4/4 |
| ENUMERATION_PLAN | 5/5 |
| XML_PLAN | 26/26 active tests |
| ARRAY_METHODS_PLAN | All tests |
| OBJECT_WATCH_PLAN | 4/4 |
| STRING_PLAN (Phases 1-4) | 4/4 method tests + string_ops_swf6 |
| TEXTFIELD_PLAN | 62/62 |
| WITH_SCOPE_PLAN | 2/2 |
| PARSING_FUNCTIONS_PLAN | 3/3 |
| COLOR_OBJECT_PLAN | extends_native_type |
| GEOMETRY_CLASSES_PLAN | transform, local_to_global partial |
| STAGE_PLAN | 7/7 |
| STAGE_FRAME_PROPS_PLAN | 9/9 |
| INPUT_EVENTS_PLAN | 40+ tests |
| SELECTION_PLAN | 454/454 |
| OOP_SUPER_EXTENDS_PLAN | 9/9 |
| REGISTERCLASS_PLAN | 16/16 |
| PROTOTYPE_OBJECT_PLAN | 11/12 (remaining: recompiler MTASC nested function bug) |
| NATIVE_INTROSPECTION_PLAN | 4/5 (remaining: ignored diffs) |
| TIMER_PLAN | 2/3 (timeout deferred) |
| FOCUS_SYSTEM_PLAN | 7/7 |
| TAB_ORDERING_PLAN | 16/16 |
| DRAG_DROP_PLAN | 4/4 |
| LOADVARIABLES_PLAN | 3/4 (remaining: log_fetch infra) |
| ASNATIVE_ASNEW_PLAN | 34/34 + 34/34 |
| BUTTON_PLAN | 14/14 |
| SWF_VERSION_SEMANTICS_PLAN | 5/5 |
| THIS_BINDING_PLAN | 5/5 |
| EXTERNAL_INTERFACE_PLAN (Phases 1-3) | 6/7 (Phase 4 blocked: no JS env) |
| MOUSE_EVENTS_ADVANCED_PLAN | 7 tests |
| LOCKROOT_PLAN | 29/29 |
| PRIMITIVE_COERCION_ADDPROPERTY_PLAN | 17/17 |
| DEFAULT_NAMES_PLAN | 52/52 |
| SCRIPT_HALTING_PLAN | 15/15 + 5/5 + 29/29 |
| CUSTOM_CLIP_METHODS_PLAN | 4/4 |
| GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN | 112/112 |
| FOCUS_FOCUSRECT_PLAN | 4/4 (1237 lines each) |
| SOUND_CLASS_PLAN (Phase 0) | register_class_with_sound, sound |
| UNLOAD_PLAN | 5/6 (unload_nested_child now PASS) |

### Blocked plans
| Plan | Status | Blocker |
|------|--------|---------|
| GLOBALS_PLAN (Phase 8) | 23/30 pass | Enumeration order + 20 missing globals |
| MOVIECLIP_PLAN | 27 tests pass | loadMovie, pixel hitTest |
| CLONE_DUPLICATE_PLAN | 4/8 pass | Textfield mouse events |
| LOADMOVIE_PLAN | 32/35 pass | mcl_replace_root accepted diffs |
| ROOT_REPLACEMENT_PLAN | 1/4 pass | MTASC class support + cross-version scope |
| TELLTARGET_PLAN | 15/17 pass | removed_base_clip_tell_target (Ruffle trace msg), string_paths_reference_launder (Ruffle known_failure) |
| HIT_TESTING_PLAN | 5+ pass | movieclip_hittest_shapeflag (shape accuracy) |
| LOADMOVIE_REMAINING_PLAN | 0/5 | setTimeout, cross-version/__proto__ |

## Recommended Work Order (updated 2026-03-15)

### Actionable — Quick wins (all exhausted)
All previous quick wins have been fixed. See `SESSION_NOTES.md` for details.

### Remaining failing tests (filtered: ~14 tests)
Remaining failures require:
- **Global enumeration order**: global_proto_decls, global_instance_decls, global_proto_decls_delete (GLOBALS_PLAN Phase 8 blocked)
- **Mouse/input dispatch**: edittext_drag_select, edittext_ime_focus_lost
- **Missing features**: localconnection, asfunction, geturl, sandbox_type_remote, displacementmapfilter_mappoint_throw_error
- **Shape-accurate hitTest**: movieclip_hittest_shapeflag (curves/strokes accuracy)
- **Other**: swf5_xml_event_handler_context, watch_virtual_property (Ruffle known_failure), movieclip_methods_with_loaded_image

### Remaining blocked work (from blocked/ plans)
- **GLOBALS_PLAN Phase 8** — BLOCKED by enumeration order + missing globals.
- **MC_REMOVAL_LIFECYCLE_PLAN** — call() early termination, SetTarget on removed base_clip.
- **TYPE_COERCION_ADVANCED_PLAN** — coerce_to_object_monkeypatch blocked by closure variable capture (not feasible).

### Dependency Blockers (plans blocking other plans)
- **LOADMOVIE_PLAN**: 32/35 core tests PASS. loadmovie_registerclass PASS. mcl_replace_root accepted diffs.
- **FOCUS_SYSTEM_PLAN**: 7/7 PASS. TAB_ORDERING_PLAN fully complete (16/16).
