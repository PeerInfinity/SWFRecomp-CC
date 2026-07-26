# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `8df2d730c3f0`  
**Date:** 2026-07-26 20:13 UTC  
**Total duration:** 9h12m59s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 635 | 672 | 94.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 744 | 994 | 74.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1457 | 1574 | 92.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 144 | 183 | 78.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 135 | 142 | 95.1% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **3498** | **4134** | **84.6%** | |

*332 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 104,066 | 107,743 | 96.6% |
| avm2 | 95,855 | 126,695 | 75.7% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,107 | 85,995 | 99.0% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,168 | 1,624 | 71.9% |
| from_shumway/avm1 | 480 | 480 | 100% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 16 | 53 | 30.2% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **322,552** | **362,599** | **89.0%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | ruffle_matched | runtime_error | segfault |
|-------|-----------------:|-------------:|----------------:|---------------:|----------:|
| audio | 2 | - | - | - | - |
| avm1 | 25 | - | 12 | - | - |
| avm2 | 245 | - | 2 | 3 | - |
| fonts | 3 | - | - | - | - |
| from_avmplus | 60 | - | 51 | 4 | 2 |
| from_gnash/actionscript.all | 9 | - | 95 | - | - |
| from_gnash/misc-ming.all | 13 | - | 28 | - | - |
| from_gnash/misc-mtasc.all | - | - | 2 | - | - |
| from_gnash/misc-swfc.all | 2 | - | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | 1 | - | - |
| from_shumway | 31 | - | 8 | - | - |
| from_shumway/avm1 | - | - | - | - | - |
| import_assets | 2 | - | - | - | - |
| mixed_avm | 8 | - | - | - | - |
| regression | - | - | - | - | - |
| stage3d | 4 | - | - | - | - |
| swf | - | - | 1 | - | - |
| text | 6 | - | - | - | - |
| timeline | 2 | - | 3 | - | - |
| visual | 6 | 1 | - | - | - |
| **Total** | **418** | **1** | **208** | **7** | **2** |

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
| avm2 | stylesheet_transform | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm2 | focus_events_mouse_focusable | 98% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
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
| from_avmplus | e4x/XML/e13_4_4_28 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
| avm2 | invalid_utf8 | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
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
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| fonts | device_font_glyph_fallback | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.1s — slowest: `g711_event_alaw` (19.5s)

### avm1

- **Pass:** 635/672 (94.5%)
- **Ignored:** 45 tests
- **Duration:** 1h17m45s across 30 shards
- **Lines:** 104,066/107,743 matching (96.6%)
- **Avg test duration:** 6.4s — slowest: `movieclip_invalid_get_bounds_7` (47.9s)

### avm2

- **Pass:** 744/994 (74.8%)
- **Ignored:** 227 tests
- **Duration:** 2h38m08s across 30 shards
- **Lines:** 95,855/126,695 matching (75.7%)
- **Avg test duration:** 7.0s — slowest: `bitmapdata_accuracy` (45.4s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 17.1s — slowest: `device_font_kerning` (24.8s)

### from_avmplus

- **Pass:** 1457/1574 (92.6%)
- **Duration:** 2h14m41s across 30 shards
- **Lines:** 85,107/85,995 matching (99.0%)
- **Avg test duration:** 5.1s — slowest: `ecma3/Statements/eregress_74474_002` (54.8s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 36m28s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 8.8s — slowest: `MovieClip-v8` (69.7s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 34m48s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 18.7s — slowest: `matrix_test` (109.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.9s — slowest: `enum` (21.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m52s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 18.3s — slowest: `swf4opcode` (23.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m12s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.6s — slowest: `zeroframe_definesprite` (22.8s)

### from_shumway

- **Pass:** 144/183 (78.7%)
- **Ignored:** 46 tests
- **Duration:** 40m42s across 30 shards
- **Lines:** 1,168/1,624 matching (71.9%)
- **Avg test duration:** 9.4s — slowest: `acid/acid-large` (66.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m36s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.6s — slowest: `label` (19.1s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 42s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.0s — slowest: `avm1_non_swf_import` (20.6s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 37s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 3.3s — slowest: `avm2_loads_avm1_v9` (5.3s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 15m16s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 13.0s — slowest: `avm2_embed_bytearray` (24.1s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 30s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.0s — slowest: `sampler_odd_size` (7.3s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 40s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 8.0s — slowest: `convolution_filter_big_matrix` (19.2s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m13s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 17.5s — slowest: `text_caret_placement_scroll` (25.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m34s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 12.5s — slowest: `swf_9_frame_script_dynamic_goto` (24.6s)

### visual

- **Pass:** 135/142 (95.1%)
- **Duration:** 26m57s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 11.3s — slowest: `definefont4` (93.3s)
