# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `3f803679d02f`  
**Date:** 2026-11-22 04:48 UTC  
**Total duration:** 11h06m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 740 | 764 | 96.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1281 | 1302 | 98.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 13 | 18 | 72.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 111 | 111 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4396** | **4640** | **94.7%** | |

*64 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 115,895 | 119,408 | 97.1% |
| avm2 | 157,408 | 158,649 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,357 | 32,104 | 94.6% |
| from_gnash/misc-ming.all | 4,245 | 5,206 | 81.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 469 | 555 | 84.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,362 | 2,409 | 98.0% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 974 | 974 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **400,458** | **408,596** | **98.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 7 | 17 |
| avm2 | - | 21 |
| fonts | - | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | 4 | 88 |
| from_gnash/misc-ming.all | 8 | 33 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 1 | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | 2 |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **21** | **223** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | MovieClip-v8 | 96% |
| avm1 | text_format_prototype_lazy | 91% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 21.6s — slowest: `aac` (31.3s)

### avm1

- **Pass:** 740/764 (96.9%)
- **Ignored:** 16 tests
- **Duration:** 1h05m24s across 30 shards
- **Lines:** 115,895/119,408 matching (97.1%)
- **Avg test duration:** 5.0s — slowest: `define_font_glyph_table_order` (40.6s)

### avm2

- **Pass:** 1281/1302 (98.4%)
- **Ignored:** 34 tests
- **Duration:** 3h42m24s across 30 shards
- **Lines:** 157,408/158,649 matching (99.2%)
- **Avg test duration:** 10.0s — slowest: `away3d_advanced_shallow_water_demo` (83.9s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m43s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.2s — slowest: `device_font_glyph_fallback` (30.3s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 3h15m57s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 7.4s — slowest: `ecma3/Statements/eregress_74474_003` (64.0s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 25m47s across 30 shards
- **Lines:** 30,357/32,104 matching (94.6%)
- **Avg test duration:** 6.4s — slowest: `MovieClip-v8` (76.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 26m24s across 30 shards
- **Lines:** 4,245/5,206 matching (81.5%)
- **Avg test duration:** 14.2s — slowest: `matrix_test` (86.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.4s — slowest: `inheritance` (23.2s)

### from_gnash/misc-swfc.all

- **Pass:** 13/18 (72.2%)
- **Ignored:** 2 tests
- **Duration:** 4m36s across 30 shards
- **Lines:** 469/555 matching (84.5%)
- **Avg test duration:** 13.9s — slowest: `movieclip_destruction_test3` (25.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m19s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.0s — slowest: `mixed-bytecode-as2` (25.5s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 43m30s across 30 shards
- **Lines:** 2,362/2,409 matching (98.0%)
- **Avg test duration:** 11.0s — slowest: `acid/acid-large` (67.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.8s — slowest: `hitarea` (18.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 42s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.0s — slowest: `avm1_non_swf_import` (18.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.8s — slowest: `avm2_loads_avm1_v9` (10.2s)

### regression

- **Pass:** 111/111 (100%)
- **Duration:** 23m15s across 30 shards
- **Lines:** 974/974 matching (100%)
- **Avg test duration:** 12.5s — slowest: `avm2_findprop_this_resolution` (53.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.7s — slowest: `draw_to_bitmap_data_unconfigured` (30.1s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 49s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 7.0s — slowest: `convolution_filter_big_matrix` (22.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m47s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.9s — slowest: `auto_size/height` (34.9s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 3m49s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 13.5s — slowest: `missing_frame_scripts` (32.1s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m50s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (113.0s)
