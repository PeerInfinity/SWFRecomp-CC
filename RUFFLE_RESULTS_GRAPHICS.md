# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9263f71a0bfa`  
**Date:** 2026-07-28 17:38 UTC  
**Total duration:** 9h07m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 641 | 717 | 89.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 886 | 1221 | 72.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1458 | 1574 | 92.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 166 | 229 | 72.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 136 | 143 | 95.1% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3676** | **4467** | **82.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,171 | 131,176 | 88.6% |
| avm2 | 105,770 | 151,253 | 69.9% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,214 | 85,996 | 99.1% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,619 | 2,484 | 65.2% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **346,283** | **418,980** | **82.6%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error |
|-------|-----------------:|-------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 59 | - | - |
| avm2 | 306 | - | 3 |
| fonts | 3 | - | - |
| from_avmplus | 61 | - | 4 |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 50 | - | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 8 | - | - |
| regression | - | - | - |
| stage3d | 4 | - | - |
| swf | - | - | - |
| text | 6 | - | - |
| timeline | 2 | - | - |
| visual | 6 | 1 | - |
| **Total** | **541** | **1** | **7** |

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
| avm2 | focus_events_mouse_focusable | 98% |
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
| avm2 | selection | 96% |
| text | text_caret_placement_translated_bounds | 96% |
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
| avm2 | edittext_mouse_selection | 92% |
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
| avm2 | 10 | - | 177 | - |

**avm2 — newly passing:** `focus_events_key_basic`, `focusrect_focuslost`, `focusrect_property`, `mouse_wheel_events`, `mouseevent_constr`, `mouseevent_stagexy`, `mouseevent_valueof_tostring`, `tab_ordering_stage_tab_children`, `tab_ordering_stage_tab_children_remove_root`, `tab_ordering_tabbable`

*Comparing `38aa0a3009e5` → `9263f71a0bfa`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.0s — slowest: `stream_incomplete_loop` (22.7s)

### avm1

- **Pass:** 641/717 (89.4%)
- **Duration:** 54m43s across 30 shards
- **Lines:** 116,171/131,176 matching (88.6%)
- **Avg test duration:** 4.5s — slowest: `netstream_play_flv_screen` (38.2s)

### avm2

- **Pass:** 886/1221 (72.6%)
- **Duration:** 2h49m45s across 30 shards
- **Lines:** 105,770/151,253 matching (69.9%)
- **Avg test duration:** 8.3s — slowest: `away3d_advanced_shallow_water_demo` (80.2s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 19.0s — slowest: `device_font_glyph_fallback` (26.6s)

### from_avmplus

- **Pass:** 1458/1574 (92.6%)
- **Duration:** 2h48m58s across 30 shards
- **Lines:** 85,214/85,996 matching (99.1%)
- **Avg test duration:** 6.4s — slowest: `ecma3/Statements/eregress_74474_002` (71.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 23m54s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 5.8s — slowest: `MovieClip-v8` (66.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 22m37s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 12.2s — slowest: `matrix_test` (108.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m34s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.1s — slowest: `TextFieldTest` (22.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m33s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 13.6s — slowest: `action_execution_order_test10` (23.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m49s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.4s — slowest: `trace-as2/arguments` (23.2s)

### from_shumway

- **Pass:** 166/229 (72.5%)
- **Duration:** 41m06s across 30 shards
- **Lines:** 1,619/2,484 matching (65.2%)
- **Avg test duration:** 10.7s — slowest: `acid/acid-large` (78.3s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m11s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.7s — slowest: `label` (22.0s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 45s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.9s — slowest: `avm1_non_swf_import` (21.6s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 54s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 4.8s — slowest: `avm2_loads_avm1` (6.8s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 9m51s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 8.4s — slowest: `avm2_timeline_gradients` (40.5s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 40s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 7.9s — slowest: `scissor_rectangle_invalid` (9.4s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 11s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 2.1s — slowest: `convolution_filter_big_matrix` (2.4s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m31s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 19.2s — slowest: `text_caret_placement_leading` (27.5s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 5.8s — slowest: `frame_script_cleanup2` (7.2s)

### visual

- **Pass:** 136/143 (95.1%)
- **Duration:** 29m40s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 12.4s — slowest: `definefont4` (88.2s)
