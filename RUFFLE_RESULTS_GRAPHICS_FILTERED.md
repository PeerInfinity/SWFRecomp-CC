# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `a62c4ce61a6c`  
**Date:** 2026-07-31 03:17 UTC  
**Total duration:** 10h05m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 653 | 677 | 96.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 862 | 995 | 86.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1470 | 1574 | 93.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 159 | 183 | 86.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 138 | 143 | 96.5% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **3673** | **4141** | **88.7%** | |

*328 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 105,036 | 108,508 | 96.8% |
| avm2 | 104,448 | 126,701 | 82.4% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,227 | 85,996 | 99.1% |
| from_gnash/actionscript.all | 29,257 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,318 | 1,624 | 81.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 252 | 350 | 72.0% |
| **Total** | **332,764** | **363,371** | **91.6%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | ruffle_matched | runtime_error |
|-------|-----------------:|-------------:|----------------:|---------------:|
| audio | 2 | - | - | - |
| avm1 | 11 | - | 13 | - |
| avm2 | 128 | - | 2 | 3 |
| fonts | 3 | - | - | - |
| from_avmplus | 49 | - | 51 | 4 |
| from_gnash/actionscript.all | 9 | - | 95 | - |
| from_gnash/misc-ming.all | 13 | - | 28 | - |
| from_gnash/misc-mtasc.all | - | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | - | 4 | - |
| from_gnash/misc-swfmill.all | - | - | 1 | - |
| from_shumway | 15 | - | 9 | - |
| from_shumway/avm1 | - | - | - | - |
| import_assets | 2 | - | - | - |
| mixed_avm | 8 | - | - | - |
| regression | - | - | - | - |
| stage3d | - | - | - | - |
| swf | - | - | 1 | - |
| text | 2 | - | - | - |
| timeline | 2 | - | 3 | - |
| visual | 4 | 1 | - | - |
| **Total** | **251** | **1** | **209** | **7** |

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
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | loader_method | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm2 | loader_load | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| avm2 | perspective_projection | 95% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | xml_appendchild_swf_v21 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
| avm2 | invalid_utf8 | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_shumway | avm2/flash/geom/matrix3d/Matrix3DClass | 91% |
| avm2 | place_and_lookup/swf10 | 91% |
| avm2 | place_and_lookup/swf9 | 91% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| avm2 | flash_media_video_setter | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| from_shumway | hittesting/hittesting | 89% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |
| from_shumway | avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass | 80% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.4s — slowest: `g711_event_alaw` (21.3s)

### avm1

- **Pass:** 653/677 (96.5%)
- **Ignored:** 41 tests
- **Duration:** 57m15s across 30 shards
- **Lines:** 105,036/108,508 matching (96.8%)
- **Avg test duration:** 4.7s — slowest: `define_font_glyph_table_order` (43.2s)

### avm2

- **Pass:** 862/995 (86.6%)
- **Ignored:** 227 tests
- **Duration:** 3h15m09s across 30 shards
- **Lines:** 104,448/126,701 matching (82.4%)
- **Avg test duration:** 8.8s — slowest: `bitmapdata_accuracy` (49.8s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 2m03s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 20.6s — slowest: `embed_matching/fallback_preferences` (28.6s)

### from_avmplus

- **Pass:** 1470/1574 (93.4%)
- **Duration:** 3h08m31s across 30 shards
- **Lines:** 85,227/85,996 matching (99.1%)
- **Avg test duration:** 7.1s — slowest: `ecma3/Statements/eregress_74474_002` (74.5s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 23m27s across 30 shards
- **Lines:** 29,257/31,358 matching (93.3%)
- **Avg test duration:** 5.7s — slowest: `MovieClip-v8` (67.6s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 26m57s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 14.5s — slowest: `matrix_test` (112.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m14s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.5s — slowest: `levels` (23.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m00s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 15.3s — slowest: `action_execution_order_test10` (23.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m52s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `tags_after_last_showframe` (22.8s)

### from_shumway

- **Pass:** 159/183 (86.9%)
- **Ignored:** 46 tests
- **Duration:** 41m48s across 30 shards
- **Lines:** 1,318/1,624 matching (81.2%)
- **Avg test duration:** 9.8s — slowest: `acid/acid-large` (64.1s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m12s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.4s — slowest: `label` (21.6s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 46s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 15.2s — slowest: `empty_url` (21.6s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 7.1s — slowest: `avm1_sprite_sc_ignored` (21.1s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 12m21s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 10.5s — slowest: `avm2_timeline_gradients` (42.9s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.7s — slowest: `sampler_odd_size` (10.3s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 30s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 5.9s — slowest: `swf_length_too_short_no_second_frame` (21.4s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m39s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 19.9s — slowest: `text_caret_placement_leading` (28.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 10.0s — slowest: `swf_9_frame_script_button_order` (26.6s)

### visual

- **Pass:** 138/143 (96.5%)
- **Duration:** 29m36s across 30 shards
- **Lines:** 252/350 matching (72.0%)
- **Avg test duration:** 12.4s — slowest: `definefont4` (89.6s)
