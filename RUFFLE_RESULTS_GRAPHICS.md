# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `feb8882b09e2`  
**Date:** 2026-08-01 14:06 UTC  
**Total duration:** 11h41m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 672 | 718 | 93.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1080 | 1224 | 88.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1508 | 1574 | 95.8% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 184 | 229 | 80.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 137 | 143 | 95.8% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3978** | **4471** | **89.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,631 | 131,178 | 88.9% |
| avm2 | 118,243 | 151,515 | 78.0% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,384 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,762 | 2,484 | 70.9% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 252 | 350 | 72.0% |
| **Total** | **359,907** | **419,244** | **85.8%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error |
|-------|-----------------:|-------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 28 | - | - |
| avm2 | 117 | - | - |
| fonts | 3 | - | - |
| from_avmplus | 13 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 32 | - | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 8 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | - | - |
| text | 2 | - | - |
| timeline | 2 | - | - |
| visual | 5 | 1 | - |
| **Total** | **246** | **1** | **1** |

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
| avm2 | stylesheet_parse_color | 94% |
| avm2 | bounds_mode | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_shumway | hittesting/hittesting | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| from_avmplus | e4x/Statements/e12_1 | 82% |
| avm2 | number_convert_edge_cases | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |
| from_shumway | avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass | 80% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `07c119c505f9` → `feb8882b09e2`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.3s — slowest: `stream_incomplete_loop` (21.8s)

### avm1

- **Pass:** 672/718 (93.6%)
- **Duration:** 1h31m54s across 30 shards
- **Lines:** 116,631/131,178 matching (88.9%)
- **Avg test duration:** 7.6s — slowest: `movieclip_invalid_get_bounds_6` (54.9s)

### avm2

- **Pass:** 1080/1224 (88.2%)
- **Duration:** 3h29m00s across 30 shards
- **Lines:** 118,243/151,515 matching (78.0%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (75.2s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 19.8s — slowest: `embed_matching/fallback_preferences` (28.3s)

### from_avmplus

- **Pass:** 1508/1574 (95.8%)
- **Duration:** 3h13m14s across 30 shards
- **Lines:** 85,384/85,996 matching (99.3%)
- **Avg test duration:** 7.3s — slowest: `ecma3/Statements/eregress_74474_002` (55.9s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 39m17s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 9.6s — slowest: `MovieClip-v8` (66.2s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 36m48s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 19.8s — slowest: `matrix_test` (105.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m08s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.9s — slowest: `super_test1` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m14s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.7s — slowest: `opcode_guard_test2` (25.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m53s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `tags_after_last_showframe` (24.3s)

### from_shumway

- **Pass:** 184/229 (80.3%)
- **Duration:** 47m32s across 30 shards
- **Lines:** 1,762/2,484 matching (70.9%)
- **Avg test duration:** 12.4s — slowest: `acid/acid-large` (77.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `label` (23.4s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 43s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.2s — slowest: `avm1_non_swf_import` (21.1s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 6.8s — slowest: `avm1_sprite_sc_ignored` (20.8s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 17m02s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 14.5s — slowest: `avm2_timeline_gradients` (28.4s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.6s — slowest: `scissor_rectangle_invalid` (10.3s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 48s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.5s — slowest: `swf_length_too_short_no_second_frame` (21.1s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m28s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 18.9s — slowest: `text_caret_placement_leading` (30.2s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m03s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.3s — slowest: `swf_9_frame_script_cleanup_goto` (31.6s)

### visual

- **Pass:** 137/143 (95.8%)
- **Duration:** 31m42s across 30 shards
- **Lines:** 252/350 matching (72.0%)
- **Avg test duration:** 13.2s — slowest: `definefont4` (73.7s)
