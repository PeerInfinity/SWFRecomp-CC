# Current Ruffle Test Status

Last updated: 2026-04-01

## Quick Summary

- **Pass rate (CI, last run)**: 569/620 (91.8%) raw, 563/569 (98.9%) filtered (6 filtered failures)
- **Image test baseline**: **12/31 strict image match** (+4: bitmap_data_fillrect, bitmap_data_perlinnoise, bitmap_data_pixeldissolve_image, bitmapdata_applyfilter_colormatrix). **10/31 tolerance pass** (within test.toml limits).
- **Main failure types**: output_mismatch (51), runtime_segfault (1), timeout (1)
- **Known regressions**: `global_instance_decls` 40→23 (unclear root cause, test at 3% pass rate).
- **Latest fixes (2026-04-01, session 2)**:
  - **global_proto_decls improved (276→512)** — ColorTransform/Point/Rectangle virtual properties, flash.filters (order + 75 virtual props + clone inheritance + __constructor__), BitmapData (own_props order + prototype methods reorder + 4 virtual props), TextRenderer own_props
  - **global_proto_decls_delete improved (255→283)** — filter order alignment, clone on BitmapFilter.prototype (CONFIGURABLE), constructor deleted from subclass prototypes
  - **Gnash misc-mtasc: 4/9 passing** — hello, enum, exception, implementsOpTest all PASS
- **Latest fixes (2026-04-01)**:
  - **color image test PASS** — alpha blend state fix (SrcAlpha→One for alpha channel), max diff 48→1
  - **Stage.width/height initialized to FRAME_WIDTH/FRAME_HEIGHT** — was 0, causing Drawing API layout bugs (movieclip_setmask 202400→10096 outliers)
  - **_global plain property resolution** — actionGetVariable now finds plain properties on _global in root context (enables Gnash misc-mtasc AS2 class resolution)
  - display_object_properties, mask_reapply, frame_size_*, movieclip_create_text_field image tests confirmed passing
  - focusrect_swf5: 9/12 captures pass (3 fail due to focus rect rendering as solid fill instead of outline)
- **Latest fixes (2026-03-31, session 2)**:
  - global_proto_decls improved (250→276) — Point/Matrix/Rectangle/ColorTransform prototype enumeration order, geometry constructor own_props UNDEFINED placeholder fix
  - ensureBuiltinPrototypeProps + ensureCtorOwnProps now handle UNDEFINED placeholders correctly
  - Investigated near-miss tests: native_objects_swf6 (Flash vs Ruffle difference), tab_ordering_properties_tab_index_edge_case (conflicting expectations), movieclip_library_state_values (already accepted diffs)
- **Latest fixes (2026-03-31)**:
  - netconnection_close PASS (39/39) — NetConnection connect/close state machine + onStatus dispatch
  - sound_load_start PASS (3/3) — loadSound with embedded MP3 data registry lookup
  - sound_multiple_load PASS (1/1) — loadSound replaces previous load
  - sound_duration_position_props PASS (290/290) — getPosition, duration/position native getters, onID3/onLoad/onSoundComplete lifecycle
  - global_proto_decls improved (237→250) — Transform.prototype 5 READ_ONLY properties
  - global_proto_decls_delete (255→255) — Transform.prototype CONFIGURABLE flag fix
  - sound_id3_prop improved (1→8), sound_id3 improved (11→17) — bonus from onID3 dispatch
  - Sound playback simulation: processSoundPlayback in frame loop, hasPlayingSounds exit condition
- **Latest fixes (2026-03-29, session 2)**:
  - bitmap_data_fillrect image PASS (0 outliers) — fillRect negative dimensions + removed bare Rectangle global
  - BitmapData.loadBitmap(exportName) — full implementation with defineBitmap char_id metadata, R/B byte swap
  - bitmap_data_colortransform image: 78561→726 outliers — loadBitmap working, remaining 2× precision issue
  - copyPixels alpha bitmap path (6-arg form), merge() method implementation
  - bitmap_data_copypixels: 190726→188581 outliers (partial progress)
- **Latest fixes (2026-03-29, session 1)**:
  - bitmap_data_pixeldissolve PASS (1075/1075) — Feistel network PRNG implementation
  - bitmap_data_perlinnoise image PASS (0 outliers) — W3C SVG feTurbulence port
  - bitmap_data_pixeldissolve_image image PASS (0 outliers) — same Feistel implementation
  - bitmapdata_applyfilter_colormatrix image PASS (0 outliers, max diff 1) — ColorMatrixFilter constructor fix
  - bitmap_filters SEGFAULT→MISMATCH (~496/548) — filter clone, property validation, mc.filters, NULL stub fix
  - Added --asan flag to verify_output.py for crash debugging
- **Latest fixes (2026-03-28)**:
  - movieclip_create_text_field image PASS (0 outliers) — fixed createTextField negative dimension rendering
  - Headless glyph rendering pipeline — device font tessellation via bundled Noto Sans TTF + stb_truetype
  - edittext_tag_indent/edittext_stylesheet: glyphs now render (still fail on text layout/color)
- **Latest fixes (2026-03-26)**:
  - array_constructor PASS (Array.join HOLE→"undefined" fix)
  - array_properties PASS (same fix)
  - external_interface_toxml_basic PASS (same fix)
  - global_array PASS (same fix)
  - tab_ordering_properties PASS (tabIndex coercion, previous fix now confirmed)
  - string_relational_compare: runtime_error→output_mismatch (verify_output.py UTF-8 error handling)
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
| netstream_play_flv_screen | segfault | FLV playback crash |

All previous crashes/segfaults/runtime_errors have been fixed (funky_function_calls, goto_methods, native_objects_swf6/7/8, movieclip_invalid_get_bounds_6/7, bitmap_filters).

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

### Remaining failing tests (filtered: 12 tests)
Remaining failures require:
- **Global enumeration order**: global_proto_decls, global_instance_decls, global_proto_decls_delete (GLOBALS_PLAN Phase 8 blocked)
- **Mouse/input dispatch**: edittext_drag_select, edittext_ime_focus_lost
- **Missing features**: localconnection, asfunction, sandbox_type_remote, displacementmapfilter_mappoint_throw_error
- **Shape-accurate hitTest**: movieclip_hittest_shapeflag (curves/strokes accuracy)
- **Other**: swf5_xml_event_handler_context, movieclip_methods_with_loaded_image

### Remaining blocked work (from blocked/ plans)
- **GLOBALS_PLAN Phase 8** — BLOCKED by enumeration order + missing globals.
- **MC_REMOVAL_LIFECYCLE_PLAN** — call() early termination, SetTarget on removed base_clip.
- **TYPE_COERCION_ADVANCED_PLAN** — coerce_to_object_monkeypatch blocked by closure variable capture (not feasible).

### Dependency Blockers (plans blocking other plans)
- **LOADMOVIE_PLAN**: 32/35 core tests PASS. loadmovie_registerclass PASS. mcl_replace_root accepted diffs.
- **FOCUS_SYSTEM_PLAN**: 7/7 PASS. TAB_ORDERING_PLAN fully complete (16/16).
