# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `6de65043250d`  
**Date:** 2026-08-06 06:23 UTC  
**Total duration:** 11h48m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 671 | 694 | 96.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1086 | 1173 | 92.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1511 | 1572 | 96.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 135 | 239 | 56.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 189 | 207 | 91.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 71 | 71 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 139 | 143 | 97.2% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **3998** | **4365** | **91.6%** | |

*109 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 105,272 | 108,744 | 96.8% |
| avm2 | 111,434 | 133,952 | 83.2% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,380 | 85,970 | 99.3% |
| from_gnash/actionscript.all | 29,443 | 31,544 | 93.3% |
| from_gnash/misc-ming.all | 4,047 | 5,206 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,478 | 1,770 | 83.5% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 482 | 482 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 295 | 350 | 84.3% |
| **Total** | **340,623** | **371,190** | **91.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 10 | 13 | - |
| avm2 | 84 | 3 | - |
| fonts | - | - | - |
| from_avmplus | 7 | 53 | 1 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 13 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 9 | 9 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 7 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 1 | - |
| text | 2 | - | - |
| timeline | 2 | 3 | - |
| visual | 2 | 2 | - |
| **Total** | **152** | **214** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | perspective_projection | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.0s — slowest: `stream_incomplete_loop` (23.9s)

### avm1

- **Pass:** 671/694 (96.7%)
- **Ignored:** 24 tests
- **Duration:** 1h29m51s across 30 shards
- **Lines:** 105,272/108,744 matching (96.8%)
- **Avg test duration:** 7.4s — slowest: `movieclip_invalid_get_bounds_6` (50.0s)

### avm2

- **Pass:** 1086/1173 (92.6%)
- **Ignored:** 53 tests
- **Duration:** 3h33m32s across 30 shards
- **Lines:** 111,434/133,952 matching (83.2%)
- **Avg test duration:** 10.3s — slowest: `away3d_advanced_shallow_water_demo` (89.1s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m08s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 21.4s — slowest: `embed_matching/fallback_preferences` (29.8s)

### from_avmplus

- **Pass:** 1511/1572 (96.1%)
- **Ignored:** 2 tests
- **Duration:** 3h15m47s across 30 shards
- **Lines:** 85,380/85,970 matching (99.3%)
- **Avg test duration:** 7.4s — slowest: `ecma3/Statements/eregress_74474_003` (55.6s)

### from_gnash/actionscript.all

- **Pass:** 135/239 (56.5%)
- **Ignored:** 4 tests
- **Duration:** 37m57s across 30 shards
- **Lines:** 29,443/31,544 matching (93.3%)
- **Avg test duration:** 9.2s — slowest: `array-v6` (51.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 36m25s across 30 shards
- **Lines:** 4,047/5,206 matching (77.7%)
- **Avg test duration:** 19.6s — slowest: `matrix_test` (112.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m20s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 22.2s — slowest: `levels` (24.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 6m04s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 18.9s — slowest: `movieclip_destruction_test1` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m48s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.4s — slowest: `dict_event` (23.1s)

### from_shumway

- **Pass:** 189/207 (91.3%)
- **Ignored:** 22 tests
- **Duration:** 47m56s across 30 shards
- **Lines:** 1,478/1,770 matching (83.5%)
- **Avg test duration:** 11.5s — slowest: `acid/acid-large` (82.5s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m16s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (22.2s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 48s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 16.0s — slowest: `avm1_non_swf_import` (23.0s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 7.3s — slowest: `avm1_sprite_sc_ignored` (21.6s)

### regression

- **Pass:** 71/71 (100%)
- **Duration:** 19m04s across 30 shards
- **Lines:** 482/482 matching (100%)
- **Avg test duration:** 16.1s — slowest: `avm2_timeline_gradients` (46.6s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 48s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.6s — slowest: `scissor_rectangle_invalid` (10.9s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 50s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 10.0s — slowest: `swf_length_too_short_no_second_frame` (21.9s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m45s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 20.4s — slowest: `auto_size/return` (31.1s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.2s — slowest: `frame_script_cleanup2` (29.6s)

### visual

- **Pass:** 139/143 (97.2%)
- **Duration:** 31m58s across 30 shards
- **Lines:** 295/350 matching (84.3%)
- **Avg test duration:** 13.4s — slowest: `simple_shapes/heavy_tesselation` (76.0s)
