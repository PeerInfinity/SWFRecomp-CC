# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `7ad4e0419427`  
**Date:** 2026-07-25 22:42 UTC  
**Total duration:** 8h12m46s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 638 | 717 | 89.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 840 | 1218 | 69.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1426 | 1574 | 90.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
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
| **Total** | **3586** | **4463** | **80.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 115,828 | 131,176 | 88.3% |
| avm2 | 103,855 | 151,151 | 68.7% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 84,065 | 85,933 | 97.8% |
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
| **Total** | **342,795** | **418,815** | **81.8%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|-------------:|---------------:|------------------:|---------:|
| audio | 2 | - | - | - | - |
| avm1 | 61 | - | - | 1 | - |
| avm2 | 347 | - | 4 | - | 1 |
| fonts | 3 | - | - | - | - |
| from_avmplus | 78 | - | 16 | 2 | 3 |
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
| **Total** | **609** | **1** | **21** | **3** | **4** |

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
| from_avmplus | 5 | - | 17 | - |

**from_avmplus — newly passing:** `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion`, `ecma3/JSON/e15_12_0`, `ecma3/JSON/e15_12_2`, `ecma3/JSON/e15_12_3`, `ecma3/JSON/regress`

*Comparing `2b244c01b173` → `7ad4e0419427`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.8s — slowest: `g711_event_alaw` (22.1s)

### avm1

- **Pass:** 638/717 (89.0%)
- **Duration:** 46m46s across 30 shards
- **Lines:** 115,828/131,176 matching (88.3%)
- **Avg test duration:** 3.9s — slowest: `netstream_play_flv_screen` (38.3s)

### avm2

- **Pass:** 840/1218 (69.0%)
- **Duration:** 2h34m07s across 30 shards
- **Lines:** 103,855/151,151 matching (68.7%)
- **Avg test duration:** 7.5s — slowest: `away3d_advanced_shallow_water_demo` (77.3s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 12.2s — slowest: `embed_matching/fallback_preferences` (27.0s)

### from_avmplus

- **Pass:** 1426/1574 (90.6%)
- **Duration:** 2h34m19s across 30 shards
- **Lines:** 84,065/85,933 matching (97.8%)
- **Avg test duration:** 5.8s — slowest: `ecma3/Statements/eregress_74474_003` (74.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 23m57s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 5.9s — slowest: `MovieClip-v8` (66.7s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 24m22s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 13.1s — slowest: `matrix_test` (114.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m07s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.1s — slowest: `exception` (22.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 3m56s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 11.8s — slowest: `movieclip_destruction_test1` (22.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.5s — slowest: `mixed-bytecode-as2` (21.6s)

### from_shumway

- **Pass:** 159/229 (69.4%)
- **Duration:** 37m18s across 30 shards
- **Lines:** 1,541/2,484 matching (62.0%)
- **Avg test duration:** 9.7s — slowest: `acid/acid-large` (77.0s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m09s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.7s — slowest: `text-bind` (22.4s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 24s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 8.1s — slowest: `empty_url` (21.3s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 42s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 3.8s — slowest: `avm2_loads_avm1_loads_into_root` (6.1s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 6m00s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 5.1s — slowest: `avm2_timeline_gradients` (25.8s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 36s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 7.1s — slowest: `sampler_odd_size` (9.0s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 9s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 1.8s — slowest: `swf_length_too_short_no_second_frame` (2.1s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 16.2s — slowest: `text_caret_placement_leading` (26.5s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 5.1s — slowest: `swf_9_frame_script_cleanup_goto` (6.2s)

### visual

- **Pass:** 134/142 (94.4%)
- **Duration:** 26m04s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 11.0s — slowest: `definefont4` (87.3s)
