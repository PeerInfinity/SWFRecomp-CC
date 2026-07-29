# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `767a301d2bae`  
**Date:** 2026-07-29 01:40 UTC  
**Total duration:** 8h49m50s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 646 | 717 | 90.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 919 | 1221 | 75.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1458 | 1574 | 92.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 131 | 243 | 53.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 168 | 229 | 73.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 136 | 143 | 95.1% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **3716** | **4467** | **83.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,218 | 131,176 | 88.6% |
| avm2 | 107,237 | 151,253 | 70.9% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,214 | 85,996 | 99.1% |
| from_gnash/actionscript.all | 30,340 | 38,791 | 78.2% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,621 | 2,484 | 65.3% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **347,940** | **418,980** | **83.0%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error |
|-------|-----------------:|-------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 54 | - | - |
| avm2 | 273 | - | 3 |
| fonts | 3 | - | - |
| from_avmplus | 61 | - | 4 |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 49 | - | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 8 | - | - |
| regression | - | - | - |
| stage3d | 4 | - | - |
| swf | - | - | - |
| text | 2 | - | - |
| timeline | 2 | - | - |
| visual | 6 | 1 | - |
| **Total** | **497** | **1** | **7** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_avmplus | as3/AMF/AMFSerializer | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | loader_method | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm2 | loader_load | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| visual | filters/avm1_convolution_initialization | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_avmplus | as3/Definitions/Variable/ConstVariables_custom1 | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | ecma3/Function/e15_3_4_3_1 | 93% |
| avm2 | xml_appendchild_swf_v21 | 92% |
| from_avmplus | e4x/XML/e13_4_4_28 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
| avm2 | invalid_utf8 | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | displayobject_hittestpoint_root | 85% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm2 | matrix | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 8 | - | 340 | 13 |
| avm2 | 76 | - | 3248 | 70 |
| from_avmplus | 1 | - | 106 | - |
| from_gnash/actionscript.all | - | - | - | 16 |
| from_shumway | 8 | - | 78 | - |
| mixed_avm | - | - | 3 | - |
| text | 4 | - | 153 | - |

**avm1 — newly passing:** `geturl_opcode_target_normalize`, `geturl_target_normalize`, `localconnection`, `xml_socket`, `xml_socket_close_in_handler`, `xml_socket_connect_null`, `xml_socket_on_data`, `xml_socket_segmented`

**avm2 — newly passing:** `air_datagram_socket`, `av_networking_params`, `cross_api_version_call_older`, `displayobject_set_name_loaded`, `edittext_ime_focus_lost`, `edittext_mouse_selection`, `error_geterrormessage`, `focus_events_key_basic`, `focus_events_key_navigation`, `focus_events_mouse_basic`, `focus_events_mouse_focusable`, `focusrect_focuslost`, `focusrect_property`, `ime_linux_dead_keys`, `jpeg_loader_context`, `loader_bitmap_transparency`, `loader_bytes_unknown_content`, `loader_child_getdefinition`, `loader_duplicate_coerce`, `loader_duplicate_coerce_new_domain`, `loader_error_in_root_ctor`, `loader_events`, `loader_image`, `loader_jpegxr`, `loader_jpegxr_alpha`, `loader_loadbytes_events`, `loader_loadbytes_invalid_png`, `loader_loadbytes_url`, `loader_loaderurl`, `loader_noninteractive_try_click_root`, `loader_reuse`, `loader_unknown_content`, `loader_visibility_interactive`, `loaderinfo_events`, `loaderinfo_loadurl`, `loaderinfo_more`, `loaderinfo_properties_not_loaded`, `mouse_children`, `mouse_pick_dobj_mask`, `mouse_pick_masking`, `mouse_pick_non_interactive_bitmap_mask`, `mouse_pick_non_interactive_dobj_mask`, `mouse_pick_text`, `mouse_wheel_events`, `mouseevent_constr`, `mouseevent_stagexy`, `mouseevent_valueof_tostring`, `navigateToURL_target_normalize`, `net_navigateToURL`, `net_stream_play_options`, `netconnection_close`, `netconnection_properties`, `netstream_client`, `netstream_connect`, `responder_null_callbacks`, `sandbox_type_inherited`, `sandbox_type_local_network`, `selection`, `socket_after_disconnect`, `socket_close`, `socket_connect`, `socket_errors`, `socket_read_big`, `socket_read_little`, `socket_read_write_object`, `socket_write_big`, `socket_write_little`, `stage_loaderinfo_properties`, `tab_ordering_stage_tab_children`, `tab_ordering_stage_tab_children_remove_root`, `tab_ordering_tabbable`, `textbox_click`, `textfield_event`, `url_loader`, `wrong_arg_count`, `xml_socket`

**from_avmplus — newly passing:** `ecma3/Exceptions/bug127913`

**from_gnash/actionscript.all — newly failing:** `XMLSocket-v5`, `XMLSocket-v6`, `XMLSocket-v7`, `XMLSocket-v8`

**from_shumway — newly passing:** `as3-interfaces`, `as3-loader/LoaderLoadBytesTest2`, `as3-loader/bug1093712/loader`, `flash_net_URLRequest`, `flash_net_classes`, `hittesting/mask-hit-test`, `image-loading`, `mouse/start_drag_lock`

**text — newly passing:** `text_caret_placement_align`, `text_caret_placement_leading`, `text_caret_placement_scroll`, `text_caret_placement_translated_bounds`

*Comparing `8df2d730c3f0` → `767a301d2bae`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.5s — slowest: `stream_incomplete_loop` (20.9s)

### avm1

- **Pass:** 646/717 (90.1%)
- **Duration:** 59m11s across 30 shards
- **Lines:** 116,218/131,176 matching (88.6%)
- **Avg test duration:** 4.9s — slowest: `define_font_glyph_table_order` (40.7s)

### avm2

- **Pass:** 919/1221 (75.3%)
- **Duration:** 2h42m36s across 30 shards
- **Lines:** 107,237/151,253 matching (70.9%)
- **Avg test duration:** 7.9s — slowest: `away3d_advanced_shallow_water_demo` (77.3s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 18.4s — slowest: `embed_matching/fallback_preferences` (26.3s)

### from_avmplus

- **Pass:** 1458/1574 (92.6%)
- **Duration:** 2h27m45s across 30 shards
- **Lines:** 85,214/85,996 matching (99.1%)
- **Avg test duration:** 5.6s — slowest: `ecma3/Statements/eregress_74474_003` (51.0s)

### from_gnash/actionscript.all

- **Pass:** 131/243 (53.9%)
- **Duration:** 25m54s across 30 shards
- **Lines:** 30,340/38,791 matching (78.2%)
- **Avg test duration:** 6.3s — slowest: `MovieClip-v8` (64.2s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 29m17s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 15.8s — slowest: `matrix_test` (107.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m31s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.8s — slowest: `function_test` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m53s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 14.6s — slowest: `edittext_test1` (23.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m28s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.4s — slowest: `dict_event` (21.5s)

### from_shumway

- **Pass:** 168/229 (73.4%)
- **Duration:** 39m27s across 30 shards
- **Lines:** 1,621/2,484 matching (65.3%)
- **Avg test duration:** 10.3s — slowest: `acid/acid-large` (75.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.0s — slowest: `text-bind` (20.3s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 42s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 13.9s — slowest: `avm1_non_swf_import` (20.5s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 44s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 4.0s — slowest: `avm2_loads_avm1` (5.9s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 11m37s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 9.9s — slowest: `avm2_timeline_gradients` (41.6s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 36s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 7.1s — slowest: `scissor_rectangle` (8.2s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 26s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 5.2s — slowest: `swf_length_too_short_no_second_frame` (20.8s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m16s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 17.8s — slowest: `text_caret_placement_align` (25.4s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 2m30s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 8.8s — slowest: `frame_script_cleanup` (25.6s)

### visual

- **Pass:** 136/143 (95.1%)
- **Duration:** 27m13s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 11.4s — slowest: `definefont4` (91.9s)
