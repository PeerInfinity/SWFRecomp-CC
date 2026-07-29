# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `72fdc5e933a6`  
**Date:** 2026-07-29 03:45 UTC  
**Total duration:** 9h19m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 641 | 674 | 95.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 795 | 994 | 80.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1458 | 1574 | 92.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 148 | 183 | 80.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 136 | 143 | 95.1% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **3565** | **4137** | **86.2%** | |

*330 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 104,236 | 107,877 | 96.6% |
| avm2 | 98,579 | 126,695 | 77.8% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,214 | 85,996 | 99.1% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,220 | 1,624 | 75.1% |
| from_shumway/avm1 | 480 | 480 | 100% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **325,761** | **362,734** | **89.8%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | ruffle_matched | runtime_error |
|-------|-----------------:|-------------:|----------------:|---------------:|
| audio | 2 | - | - | - |
| avm1 | 21 | - | 12 | - |
| avm2 | 194 | - | 2 | 3 |
| fonts | 3 | - | - | - |
| from_avmplus | 61 | - | 51 | 4 |
| from_gnash/actionscript.all | 9 | - | 95 | - |
| from_gnash/misc-ming.all | 13 | - | 28 | - |
| from_gnash/misc-mtasc.all | - | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | - | 5 | - |
| from_gnash/misc-swfmill.all | - | - | 1 | - |
| from_shumway | 27 | - | 8 | - |
| from_shumway/avm1 | - | - | - | - |
| import_assets | 2 | - | - | - |
| mixed_avm | 8 | - | - | - |
| regression | - | - | - | - |
| stage3d | 4 | - | - | - |
| swf | - | - | 1 | - |
| text | 2 | - | - | - |
| timeline | 2 | - | 3 | - |
| visual | 6 | 1 | - | - |
| **Total** | **356** | **1** | **208** | **7** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| from_avmplus | as3/AMF/AMFSerializer | 99% |
| avm2 | stylesheet_transform | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | loader_method | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm2 | loader_load | 97% |
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
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | displayobject_hittestpoint_root | 85% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.7s — slowest: `stream_incomplete_loop` (20.9s)

### avm1

- **Pass:** 641/674 (95.1%)
- **Ignored:** 43 tests
- **Duration:** 1h14m34s across 30 shards
- **Lines:** 104,236/107,877 matching (96.6%)
- **Avg test duration:** 6.1s — slowest: `movieclip_invalid_get_bounds_7` (50.2s)

### avm2

- **Pass:** 795/994 (80.0%)
- **Ignored:** 227 tests
- **Duration:** 2h45m26s across 30 shards
- **Lines:** 98,579/126,695 matching (77.8%)
- **Avg test duration:** 7.4s — slowest: `bitmapdata_accuracy` (42.3s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 17.7s — slowest: `device_font_kerning` (25.3s)

### from_avmplus

- **Pass:** 1458/1574 (92.6%)
- **Duration:** 2h21m31s across 30 shards
- **Lines:** 85,214/85,996 matching (99.1%)
- **Avg test duration:** 5.3s — slowest: `ecma3/Statements/eregress_74474_003` (64.7s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 34m23s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 8.4s — slowest: `MovieClip-v8` (70.2s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 33m02s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 17.7s — slowest: `matrix_test` (76.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.2s — slowest: `exception` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m46s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 18.1s — slowest: `movieclip_destruction_test2` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m25s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.2s — slowest: `missing_bitmap` (20.9s)

### from_shumway

- **Pass:** 148/183 (80.9%)
- **Ignored:** 46 tests
- **Duration:** 39m51s across 30 shards
- **Lines:** 1,220/1,624 matching (75.1%)
- **Avg test duration:** 9.5s — slowest: `acid/acid-large` (77.2s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m32s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.6s — slowest: `label` (20.8s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 43s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.3s — slowest: `avm1_non_swf_import` (21.1s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 44s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 4.0s — slowest: `avm2_loads_avm1_loads_into_root` (5.8s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 14m47s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 12.6s — slowest: `avm2_timeline_gradients` (25.8s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 34s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.8s — slowest: `scissor_rectangle_invalid` (8.1s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 42s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 8.3s — slowest: `convolution_filter_big_matrix` (20.1s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 17.7s — slowest: `text_caret_placement_leading` (25.8s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m48s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 13.4s — slowest: `frame_script_cleanup2` (25.5s)

### visual

- **Pass:** 136/143 (95.1%)
- **Duration:** 26m49s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 11.2s — slowest: `definefont4` (90.2s)
