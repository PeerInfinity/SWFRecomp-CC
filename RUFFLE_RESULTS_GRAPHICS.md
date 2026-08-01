# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `73c786e3fa45`  
**Date:** 2026-08-01 02:48 UTC  
**Total duration:** 12h04m42s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 669 | 718 | 93.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1068 | 1224 | 87.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1501 | 1574 | 95.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 183 | 229 | 79.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 137 | 143 | 95.8% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3955** | **4471** | **88.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,625 | 131,178 | 88.9% |
| avm2 | 118,135 | 151,515 | 78.0% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,359 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,757 | 2,484 | 70.7% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 252 | 350 | 72.0% |
| **Total** | **359,763** | **419,244** | **85.8%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error |
|-------|-----------------:|-------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 31 | - | - |
| avm2 | 128 | - | 1 |
| fonts | 3 | - | - |
| from_avmplus | 20 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 33 | - | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 8 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | - | - |
| text | 2 | - | - |
| timeline | 2 | - | - |
| visual | 5 | 1 | - |
| **Total** | **268** | **1** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| avm2 | perspective_projection | 95% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| avm2 | stylesheet_parse_color | 94% |
| avm2 | bounds_mode | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | xml_appendchild_swf_v21 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_shumway | avm2/flash/geom/matrix3d/Matrix3DClass | 91% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| from_shumway | hittesting/hittesting | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_avmplus | e4x/Expressions/e11_1_2 | 85% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |
| from_shumway | avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 17 | - | 204 | 10 |
| from_avmplus | 8 | - | 18 | - |
| visual | - | 1 | - | - |

**avm2 — newly passing:** `activation_class`, `bitmapdata_zero_size`, `encode_uri_surrogate_pair_invalid`, `flash_media_video_setter`, `font_enumeratefonts_order`, `font_registerfont`, `getouterscope_two_classobjects`, `instantiate_root_character`, `invalid_utf8`, `issue_8630_placeremoveplace`, `loader_method`, `parse_float_swf10`, `stylesheet`, `system_setclipboard_null`, `uncaught_error_basic`, `verify_illegal_opcode`

**from_avmplus — newly passing:** `as3/RuntimeErrors/Error1052InvalidUriPassed`, `e4x/XML/e13_4_4_36`, `ecma3/Exceptions/exception_011_rt`, `ecma3/ObjectObjects/hasOwnProperty`, `ecma3/Statements/e12_10`, `ecma3/String/e15_5_3_2_3`, `ecma3/String/e15_5_4_5_4`, `ecma3/Unicode/utf8count`

**visual — newly failing:** `definefont4`

*Comparing `2ab0c01beab9` → `73c786e3fa45`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.5s — slowest: `stream_incomplete_loop` (23.7s)

### avm1

- **Pass:** 669/718 (93.2%)
- **Duration:** 1h35m50s across 30 shards
- **Lines:** 116,625/131,178 matching (88.9%)
- **Avg test duration:** 7.9s — slowest: `movieclip_invalid_get_bounds_6` (56.6s)

### avm2

- **Pass:** 1068/1224 (87.3%)
- **Duration:** 3h37m42s across 30 shards
- **Lines:** 118,135/151,515 matching (78.0%)
- **Avg test duration:** 10.6s — slowest: `away3d_advanced_shallow_water_demo` (87.4s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 20.9s — slowest: `embed_matching/fallback_preferences` (27.8s)

### from_avmplus

- **Pass:** 1501/1574 (95.4%)
- **Duration:** 3h16m34s across 30 shards
- **Lines:** 85,359/85,996 matching (99.3%)
- **Avg test duration:** 7.4s — slowest: `ecma3/Statements/eregress_74474_003` (61.1s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 40m40s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 10.0s — slowest: `MovieClip-v8` (67.4s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 37m47s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 20.4s — slowest: `matrix_test` (117.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m20s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 22.2s — slowest: `implementsOpTest` (23.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m13s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.6s — slowest: `registerclass_test3` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m55s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.7s — slowest: `dict_event` (22.9s)

### from_shumway

- **Pass:** 183/229 (79.9%)
- **Duration:** 48m59s across 30 shards
- **Lines:** 1,757/2,484 matching (70.7%)
- **Avg test duration:** 12.8s — slowest: `acid/acid-large` (82.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.9s — slowest: `text-bind` (23.6s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 46s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 15.4s — slowest: `avm1_non_swf_import` (22.0s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 7.1s — slowest: `avm1_sprite_sc_ignored` (20.2s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 19m29s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 16.6s — slowest: `avm2_graphics_runtime` (46.2s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.3s — slowest: `scissor_rectangle_invalid` (10.8s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 49s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.7s — slowest: `convolution_filter_big_matrix` (21.3s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m38s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 19.8s — slowest: `auto_size/return` (29.4s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.2s — slowest: `frame_script_cleanup2` (29.3s)

### visual

- **Pass:** 137/143 (95.8%)
- **Duration:** 32m01s across 30 shards
- **Lines:** 252/350 matching (72.0%)
- **Avg test duration:** 13.4s — slowest: `definefont4` (88.9s)
