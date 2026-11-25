# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `10a5b515a03a`  
**Date:** 2026-11-25 21:42 UTC  
**Total duration:** 12h45m25s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 766 | 777 | 98.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1294 | 1312 | 98.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1544 | 1572 | 98.2% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 167 | 240 | 69.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 71 | 110 | 64.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 15 | 20 | 75.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 262 | 262 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4623** | **4816** | **96.0%** | |

*59 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 116,605 | 119,712 | 97.4% |
| avm2 | 157,803 | 159,038 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,582 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,707 | 32,104 | 95.6% |
| from_gnash/misc-ming.all | 4,311 | 5,206 | 82.8% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 514 | 585 | 87.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,102 | 2,102 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **403,199** | **410,447** | **98.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 4 | 7 |
| avm2 | - | 18 |
| fonts | - | 1 |
| from_avmplus | 1 | 27 |
| from_gnash/actionscript.all | 5 | 68 |
| from_gnash/misc-ming.all | 8 | 31 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **19** | **174** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_avmplus | ecma3/JSON/AS3Types | 96% |
| avm1 | boxed_primitives | 96% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 21.2s — slowest: `aac` (24.5s)

### avm1

- **Pass:** 766/777 (98.6%)
- **Ignored:** 12 tests
- **Duration:** 1h21m30s across 30 shards
- **Lines:** 116,605/119,712 matching (97.4%)
- **Avg test duration:** 6.2s — slowest: `goto_advance2` (44.1s)

### avm2

- **Pass:** 1294/1312 (98.6%)
- **Ignored:** 34 tests
- **Duration:** 4h06m41s across 30 shards
- **Lines:** 157,803/159,038 matching (99.2%)
- **Avg test duration:** 10.9s — slowest: `away3d_advanced_shallow_water_demo` (84.5s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.3s — slowest: `embed_matching/fallback_preferences` (26.2s)

### from_avmplus

- **Pass:** 1544/1572 (98.2%)
- **Ignored:** 2 tests
- **Duration:** 3h25m32s across 30 shards
- **Lines:** 85,582/85,970 matching (99.5%)
- **Avg test duration:** 7.8s — slowest: `ecma3/Statements/eregress_74474_002` (65.8s)

### from_gnash/actionscript.all

- **Pass:** 167/240 (69.6%)
- **Ignored:** 3 tests
- **Duration:** 28m41s across 30 shards
- **Lines:** 30,707/32,104 matching (95.6%)
- **Avg test duration:** 7.1s — slowest: `MovieClip-v8` (45.0s)

### from_gnash/misc-ming.all

- **Pass:** 71/110 (64.5%)
- **Ignored:** 1 tests
- **Duration:** 32m31s across 30 shards
- **Lines:** 4,311/5,206 matching (82.8%)
- **Avg test duration:** 17.5s — slowest: `matrix_test` (103.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.0s — slowest: `function_test` (20.4s)

### from_gnash/misc-swfc.all

- **Pass:** 15/20 (75.0%)
- **Ignored:** 1 tests
- **Duration:** 4m45s across 30 shards
- **Lines:** 514/585 matching (87.9%)
- **Avg test duration:** 14.1s — slowest: `soft_reference_test1` (27.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m02s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.1s — slowest: `trace-as2/shortstack` (27.3s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 47m39s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 12.0s — slowest: `acid/acid-large` (68.6s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m28s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `hitarea` (25.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.2s — slowest: `empty_url` (19.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.1s — slowest: `avm1_sprite_sc_ignored` (19.5s)

### regression

- **Pass:** 262/262 (100%)
- **Duration:** 52m05s across 30 shards
- **Lines:** 2,102/2,102 matching (100%)
- **Avg test duration:** 11.9s — slowest: `avm2_activation_vtable_bounded` (57.4s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.6s — slowest: `draw_to_bitmap_data_unconfigured` (25.3s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.6s — slowest: `convolution_filter_big_matrix` (19.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m35s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.9s — slowest: `auto_size/height` (30.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.3s — slowest: `swf_9_frame_script_dynamic_goto_2` (36.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m29s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.5s — slowest: `definefont4` (93.3s)
