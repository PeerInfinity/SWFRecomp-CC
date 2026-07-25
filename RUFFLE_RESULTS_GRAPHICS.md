# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `5da28a6a5bb0`  
**Date:** 2026-07-25 23:58 UTC  
**Total duration:** 8h18m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 638 | 717 | 89.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 841 | 1218 | 69.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1439 | 1574 | 91.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 159 | 229 | 69.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 134 | 142 | 94.4% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3600** | **4463** | **80.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 115,828 | 131,176 | 88.3% |
| avm2 | 103,987 | 151,151 | 68.8% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 84,458 | 85,989 | 98.2% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,541 | 2,484 | 62.0% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 16 | 53 | 30.2% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **343,320** | **418,871** | **82.0%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|-------------:|---------------:|------------------:|---------:|
| audio | 2 | - | - | - | - |
| avm1 | 61 | - | - | 1 | - |
| avm2 | 347 | - | 3 | - | 1 |
| fonts | 3 | - | - | - | - |
| from_avmplus | 78 | - | 4 | 2 | 2 |
| from_gnash/actionscript.all | 13 | - | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - | - |
| from_shumway | 58 | - | - | - | - |
| from_shumway/avm1 | - | - | - | - | - |
| import_assets | 2 | - | - | - | - |
| mixed_avm | 8 | - | - | - | - |
| regression | - | - | - | - | - |
| stage3d | 4 | - | - | - | - |
| swf | - | - | - | - | - |
| text | 6 | - | - | - | - |
| timeline | 2 | - | - | - | - |
| visual | 6 | 1 | 1 | - | - |
| **Total** | **609** | **1** | **8** | **3** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/ByteArray/ByteArray | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | focus_events_mouse_focusable | 98% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| avm2 | focusrect_property | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| visual | filters/avm1_convolution_initialization | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_avmplus | as3/Definitions/Variable/ConstVariables_custom1 | 94% |
| avm2 | mouseevent_constr | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | ecma3/Function/e15_3_4_3_1 | 93% |
| from_avmplus | regress/bug_420755 | 93% |
| from_avmplus | e4x/XML/e13_4_4_28 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
| avm2 | invalid_utf8 | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | as3/ShellClasses/DictionarySubclass | 91% |
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
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
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
| avm2 | mouse_wheel_events | 81% |
| fonts | device_font_glyph_fallback | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 1 | - | 132 | - |
| from_avmplus | 13 | - | 337 | - |

**avm2 — newly passing:** `domain_memory`

**from_avmplus — newly passing:** `mops/lf32`, `mops/lf64`, `mops/li16`, `mops/li32`, `mops/li8`, `mops/lix16`, `mops/lix8`, `mops/mops_basics`, `mops/sf32`, `mops/sf64`, `mops/si16`, `mops/si32`, `mops/si8`

*Comparing `7ad4e0419427` → `5da28a6a5bb0`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.0s — slowest: `stream_incomplete_loop` (22.5s)

### avm1

- **Pass:** 638/717 (89.0%)
- **Duration:** 46m56s across 30 shards
- **Lines:** 115,828/131,176 matching (88.3%)
- **Avg test duration:** 3.9s — slowest: `netstream_play_flv_screen` (39.7s)

### avm2

- **Pass:** 841/1218 (69.0%)
- **Duration:** 2h40m28s across 30 shards
- **Lines:** 103,987/151,151 matching (68.8%)
- **Avg test duration:** 7.8s — slowest: `away3d_advanced_shallow_water_demo` (81.5s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 12.5s — slowest: `embed_matching/fallback_preferences` (26.5s)

### from_avmplus

- **Pass:** 1439/1574 (91.4%)
- **Duration:** 2h33m19s across 30 shards
- **Lines:** 84,458/85,989 matching (98.2%)
- **Avg test duration:** 5.8s — slowest: `ecma3/Statements/eregress_74474_002` (53.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 23m37s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 5.8s — slowest: `MovieClip-v8` (70.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 23m35s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 12.7s — slowest: `matrix_test` (85.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `implementsOpTest` (22.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 3m50s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 11.5s — slowest: `soft_reference_test1` (22.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m47s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.3s — slowest: `zeroframe_definesprite` (22.8s)

### from_shumway

- **Pass:** 159/229 (69.4%)
- **Duration:** 36m58s across 30 shards
- **Lines:** 1,541/2,484 matching (62.0%)
- **Avg test duration:** 9.6s — slowest: `acid/acid-large` (79.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.6s — slowest: `label` (22.8s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 24s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 8.1s — slowest: `empty_url` (21.0s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 47s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 4.2s — slowest: `avm2_loads_avm1` (6.3s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 7m37s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 6.5s — slowest: `avm2_timeline_gradients` (39.4s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 37s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 7.4s — slowest: `scissor_rectangle_invalid` (9.1s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 10s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 1.9s — slowest: `swf_length_zero` (2.1s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m03s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 16.6s — slowest: `text_caret_placement_align` (28.2s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 5.1s — slowest: `frame_script_cleanup3` (6.6s)

### visual

- **Pass:** 134/142 (94.4%)
- **Duration:** 25m32s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 10.7s — slowest: `definefont4` (86.8s)
