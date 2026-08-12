# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `bf585e4486b6`  
**Date:** 2026-08-12 23:11 UTC  
**Total duration:** 12h10m44s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 674 | 696 | 96.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1121 | 1184 | 94.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1514 | 1572 | 96.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 135 | 239 | 56.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 191 | 207 | 92.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 2 | 3 | 66.7% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 141 | 144 | 97.9% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4046** | **4380** | **92.4%** | |

*110 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 109,489 | 112,904 | 97.0% |
| avm2 | 115,281 | 135,513 | 85.1% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,403 | 85,970 | 99.3% |
| from_gnash/actionscript.all | 29,444 | 31,544 | 93.3% |
| from_gnash/misc-ming.all | 4,047 | 5,206 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,492 | 1,770 | 84.3% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 8 | 14 | 57.1% |
| mixed_avm | 26 | 53 | 49.1% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **348,859** | **376,912** | **92.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 9 | 13 | - |
| avm2 | 59 | 4 | - |
| fonts | - | - | - |
| from_avmplus | 3 | 54 | 1 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 9 | 7 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 1 | - | - |
| mixed_avm | 7 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 1 | - |
| text | 1 | - | - |
| timeline | 2 | 3 | - |
| visual | 1 | 2 | - |
| **Total** | **118** | **215** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
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
| mixed_avm | avm2_loads_avm1_v9 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.1s — slowest: `stream_incomplete_loop` (21.7s)

### avm1

- **Pass:** 674/696 (96.8%)
- **Ignored:** 22 tests
- **Duration:** 1h35m11s across 30 shards
- **Lines:** 109,489/112,904 matching (97.0%)
- **Avg test duration:** 7.8s — slowest: `define_font_glyph_table_order` (48.2s)

### avm2

- **Pass:** 1121/1184 (94.7%)
- **Ignored:** 56 tests
- **Duration:** 3h41m53s across 30 shards
- **Lines:** 115,281/135,513 matching (85.1%)
- **Avg test duration:** 10.6s — slowest: `away3d_advanced_shallow_water_demo` (89.3s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 21.1s — slowest: `embed_matching/fallback_preferences` (29.0s)

### from_avmplus

- **Pass:** 1514/1572 (96.3%)
- **Ignored:** 2 tests
- **Duration:** 3h20m37s across 30 shards
- **Lines:** 85,403/85,970 matching (99.3%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_002` (58.1s)

### from_gnash/actionscript.all

- **Pass:** 135/239 (56.5%)
- **Ignored:** 4 tests
- **Duration:** 39m41s across 30 shards
- **Lines:** 29,444/31,544 matching (93.3%)
- **Avg test duration:** 9.6s — slowest: `MovieClip-v8` (65.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 37m05s across 30 shards
- **Lines:** 4,047/5,206 matching (77.7%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (111.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m14s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.6s — slowest: `levels` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 6m22s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 19.8s — slowest: `gotoFrameLabelAsFunction` (25.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m58s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.9s — slowest: `missing_bitmap` (22.6s)

### from_shumway

- **Pass:** 191/207 (92.3%)
- **Ignored:** 22 tests
- **Duration:** 48m19s across 30 shards
- **Lines:** 1,492/1,770 matching (84.3%)
- **Avg test duration:** 11.7s — slowest: `acid/acid-large` (76.8s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m14s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (22.1s)

### import_assets

- **Pass:** 2/3 (66.7%)
- **Duration:** 46s across 30 shards
- **Lines:** 8/14 matching (57.1%)
- **Avg test duration:** 15.4s — slowest: `avm1_non_swf_import` (22.2s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 26/53 matching (49.1%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (20.8s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 19m10s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 15.9s — slowest: `avm2_timeline_gradients` (47.8s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.3s — slowest: `scissor_rectangle_invalid` (10.4s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 49s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.6s — slowest: `convolution_filter_big_matrix` (21.0s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m46s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.5s — slowest: `auto_size/return` (31.0s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m10s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.7s — slowest: `frame_script_cleanup3` (29.0s)

### visual

- **Pass:** 141/144 (97.9%)
- **Duration:** 32m48s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.6s — slowest: `definefont4` (92.4s)
