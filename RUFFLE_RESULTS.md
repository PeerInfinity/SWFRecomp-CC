# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b6fbe84479e3`  
**Date:** 2026-07-12 01:06 UTC  
**Total duration:** 3h29m49s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 639 | 1201 | 53.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1674** | **2490** | **67.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 70,953 | 149,021 | 47.6% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **223,536** | **326,971** | **68.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 54 | - | 1 | - |
| avm2 | 539 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **640** | **4** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | textfield_unload | 95% |
| avm2 | focusrect_property | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm2 | json_stringify | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | button_nested_frame | 92% |
| avm2 | place_object_replace_2 | 92% |
| avm2 | simplebutton_childshuffle | 91% |
| avm2 | unescape | 89% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | simplebutton_childprops | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | indexing_delete | 80% |
| avm2 | issue_5292 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 169 | - | 19552 | 21 |

**avm2 — newly passing:** `bitmapdata_copychannel`, `broadcast_event`, `construct_frame_list`, `constructors_vs_timeline`, `displayobject_alpha`, `displayobject_from_enterframe`, `displayobject_height`, `displayobject_invalid_floats`, `displayobject_invalid_props`, `displayobject_mask`, `displayobject_metaData`, `displayobject_name`, `displayobject_name_from_timeline`, `displayobject_parent`, `displayobject_root`, `displayobject_rotation`, `displayobject_subclass`, `displayobject_visible`, `displayobject_width`, `displayobject_x`, `displayobject_y`, `displayobjectcontainer_addchild`, `displayobjectcontainer_addchild_lazy_sprite`, `displayobjectcontainer_addchild_timelinepull0`, `displayobjectcontainer_addchild_timelinepull1`, `displayobjectcontainer_addchild_timelinepull2`, `displayobjectcontainer_addchildat`, `displayobjectcontainer_addchildat_timelinelock0`, `displayobjectcontainer_addchildat_timelinelock1`, `displayobjectcontainer_addchildat_timelinelock2`, `displayobjectcontainer_contains`, `displayobjectcontainer_getchildat`, `displayobjectcontainer_getchildbyname`, `displayobjectcontainer_getchildbyname_wrongcase`, `displayobjectcontainer_getchildindex`, `displayobjectcontainer_removechild`, `displayobjectcontainer_removechild_errors`, `displayobjectcontainer_removechild_timelinemanip_remove1`, `displayobjectcontainer_removechildat`, `displayobjectcontainer_removechildren`, `displayobjectcontainer_setchildindex`, `displayobjectcontainer_stopallmovieclips`, `displayobjectcontainer_swapchildren`, `displayobjectcontainer_swapchildrenat`, `displayobjectcontainer_timelineinstance`, `documentclass`, `edit_text_linkage`, `edittext_mouseenabled`, `event_clone`, `event_clone_error_redispatch`, `event_clone_on_redispatch`, `event_formattostring`, `event_handler_exception`, `event_isdefaultprevented`, `event_target_getter`, `event_target_set`, `event_valueof_tostring`, `eventdispatcher_dispatchevent`, `eventdispatcher_dispatchevent_cancel`, `eventdispatcher_dispatchevent_handlerorder`, `eventdispatcher_dispatchevent_indirect`, `eventdispatcher_interface_invoke`, `eventdispatcher_tostring`, `eventdispatcher_willtrigger`, `framelabel_constr`, `goto_in_constructframe`, `goto_in_scene_last_frame`, `goto_methods`, `goto_methods_swfver10`, `goto_nested_framescript`, `goto_on_orphan`, `graphics_bitmap_fill`, `instantiation_on_enter_frame`, `instantiation_on_enterframe_gotoandstop`, `interactiveobject_enabled`, `issue_8630`, `issue_8630_scriptremove`, `mask_reapply`, `movieclip_addframescript`, `movieclip_child_property`, `movieclip_constr`, `movieclip_currentlabels`, `movieclip_currentlabels_dupes1`, `movieclip_currentlabels_dupes2`, `movieclip_currentlabels_dupes3`, `movieclip_currentscene`, `movieclip_dispatchevent`, `movieclip_dispatchevent_cancel`, `movieclip_dispatchevent_handlerorder`, `movieclip_dispatchevent_selfadd`, `movieclip_dispatchevent_target`, `movieclip_displayevents`, `movieclip_displayevents_constructframegoto`, `movieclip_displayevents_constructframeplay`, `movieclip_displayevents_constructframesymbol`, `movieclip_displayevents_dblhandler`, `movieclip_displayevents_enterframegoto`, `movieclip_displayevents_enterframeplay`, `movieclip_displayevents_enterframesymbol`, `movieclip_displayevents_exitframegoto`, `movieclip_displayevents_exitframeplay`, `movieclip_displayevents_exitframesymbol`, `movieclip_displayevents_looping`, `movieclip_displayevents_stopped`, `movieclip_displayevents_swap`, `movieclip_displayevents_timeline`, `movieclip_goto_during_frame_script`, `movieclip_goto_overwrite`, `movieclip_goto_scene_last_frame_int`, `movieclip_goto_scene_last_frame_label`, `movieclip_gotoandplay`, `movieclip_gotoandstop`, `movieclip_gotoandstop_children`, `movieclip_gotoandstop_framescripts1`, `movieclip_gotoandstop_framescripts2`, `movieclip_gotoandstop_framescripts_self`, `movieclip_gotoandstop_queueing`, `movieclip_next_frame`, `movieclip_play`, `movieclip_prev_frame`, `movieclip_properties`, `movieclip_queued_noop_goto_swf10`, `movieclip_queued_noop_goto_swf9`, `movieclip_scenes`, `movieclip_super_is_symbol`, `movieclip_symbol_constr`, `movieclip_willtrigger`, `nan_scale`, `orphan_movie_complex`, `orphan_movie_reorder`, `parent_early_access_child`, `place_multiple`, `place_object_replace`, `place_object_same_depth_frame`, `remove_child_clear_field`, `remove_dobj`, `scene_constr`, `simplebutton_constr`, `simplebutton_constr_params`, `simplebutton_mouseenabled`, `simplebutton_multi_children`, `simplebutton_structure`, `stage3d_rotating_cube`, `stage_access`, `stage_displayobject_properties`, `stage_framerate_nan`, `stage_framerate_negative`, `stage_framerate_zero`, `stage_invalidate`, `stage_mouseenabled`, `stage_overriden_setters`, `stage_properties`, `stage_properties2`, `swf_10_queued_goto_scripts_construct`, `swf_9_goto_in_enter_frame`, `swf_9_goto_in_enter_frame_simple`, `swf_9_queued_goto_scripts`, `swf_9_queued_goto_scripts_construct`, `swf_wrong_frame_count`, `swf_wrong_frame_count_isplaying`, `symbol_class_conflict`, `timeline_scripts`, `zero_frame_clip`

*Comparing `6841590f69b9` → `b6fbe84479e3`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 50m14s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 4.2s — slowest: `netstream_play_flv_screen` (37.2s)

### avm2

- **Pass:** 639/1201 (53.2%)
- **Duration:** 1h25m52s across 30 shards
- **Lines:** 70,953/149,021 matching (47.6%)
- **Avg test duration:** 4.2s — slowest: `away3d_advanced_shallow_water_demo` (62.4s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 26m05s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.4s — slowest: `MovieClip-v8` (71.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 18m36s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 10.0s — slowest: `matrix_test` (86.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.4s — slowest: `function_test` (22.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m24s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 13.1s — slowest: `movieclip_destruction_test3` (23.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m43s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.1s — slowest: `dict_cross` (22.0s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m19s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.6s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (21.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.2s — slowest: `duplicateMovieClip/dontremove` (22.3s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 4m55s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.1s — slowest: `lv_cross_swf_version` (21.4s)
