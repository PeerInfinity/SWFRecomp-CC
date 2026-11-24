# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `cceb5133a189`  
**Date:** 2026-11-24 07:25 UTC  
**Total duration:** 11h36m32s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 750 | 770 | 97.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1288 | 1309 | 98.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 71 | 110 | 64.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 14 | 20 | 70.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 214 | 222 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 204 | 204 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4509** | **4747** | **95.0%** | |

*63 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 116,183 | 119,574 | 97.2% |
| avm2 | 157,725 | 158,966 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,595 | 32,104 | 95.3% |
| from_gnash/misc-ming.all | 4,306 | 5,206 | 82.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 512 | 585 | 87.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,361 | 2,407 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,557 | 1,557 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **401,987** | **409,690** | **98.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 3 | 17 |
| avm2 | - | 21 |
| fonts | - | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | - | 92 |
| from_gnash/misc-ming.all | 7 | 32 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 6 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | 2 |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **11** | **227** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 21.7s — slowest: `aac` (24.3s)

### avm1

- **Pass:** 750/770 (97.4%)
- **Ignored:** 15 tests
- **Duration:** 1h09m43s across 30 shards
- **Lines:** 116,183/119,574 matching (97.2%)
- **Avg test duration:** 5.3s — slowest: `define_font_glyph_table_order` (42.7s)

### avm2

- **Pass:** 1288/1309 (98.4%)
- **Ignored:** 34 tests
- **Duration:** 3h49m30s across 30 shards
- **Lines:** 157,725/158,966 matching (99.2%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (98.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.2s — slowest: `device_font_list` (28.6s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 3h16m40s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_003` (63.4s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 25m52s across 30 shards
- **Lines:** 30,595/32,104 matching (95.3%)
- **Avg test duration:** 6.4s — slowest: `MovieClip-v8` (75.2s)

### from_gnash/misc-ming.all

- **Pass:** 71/110 (64.5%)
- **Ignored:** 1 tests
- **Duration:** 28m04s across 30 shards
- **Lines:** 4,306/5,206 matching (82.7%)
- **Avg test duration:** 15.3s — slowest: `matrix_test` (82.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.2s — slowest: `exception` (22.5s)

### from_gnash/misc-swfc.all

- **Pass:** 14/20 (70.0%)
- **Ignored:** 1 tests
- **Duration:** 4m44s across 30 shards
- **Lines:** 512/585 matching (87.5%)
- **Avg test duration:** 14.1s — slowest: `sound` (24.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m32s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.6s — slowest: `mixed-bytecode-as2` (25.2s)

### from_shumway

- **Pass:** 214/222 (96.4%)
- **Ignored:** 7 tests
- **Duration:** 44m28s across 30 shards
- **Lines:** 2,361/2,407 matching (98.1%)
- **Avg test duration:** 11.3s — slowest: `acid/acid-large` (67.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.9s — slowest: `text-bind` (19.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.5s — slowest: `empty_url` (21.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m19s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.6s — slowest: `avm1_sprite_sc_ignored` (18.2s)

### regression

- **Pass:** 204/204 (100%)
- **Duration:** 37m05s across 30 shards
- **Lines:** 1,557/1,557 matching (100%)
- **Avg test duration:** 10.9s — slowest: `avm2_gc_dynprop_tombstone_purge` (53.7s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.8s — slowest: `draw_to_bitmap_data_unconfigured` (24.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 48s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.8s — slowest: `convolution_filter_big_matrix` (19.5s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m33s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.8s — slowest: `auto_size/height` (29.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m10s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 14.7s — slowest: `frame_script_button_order` (26.5s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 33m08s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.1s — slowest: `definefont4` (83.4s)
