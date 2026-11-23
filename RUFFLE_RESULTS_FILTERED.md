# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `876e6670414e`  
**Date:** 2026-11-23 02:55 UTC  
**Total duration:** 9h33m32s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 745 | 766 | 97.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1283 | 1305 | 98.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 14 | 19 | 73.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 131 | 131 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4423** | **4666** | **94.8%** | |

*62 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 116,171 | 119,566 | 97.2% |
| avm2 | 157,341 | 158,700 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,601 | 32,104 | 95.3% |
| from_gnash/misc-ming.all | 4,256 | 5,206 | 81.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 476 | 562 | 84.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,362 | 2,409 | 98.0% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,183 | 1,183 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **401,132** | **409,021** | **98.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 4 | 17 |
| avm2 | 1 | 21 |
| fonts | - | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | - | 92 |
| from_gnash/misc-ming.all | 7 | 34 |
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
| **Total** | **15** | **228** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m03s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 12.7s — slowest: `stream_incomplete_loop` (18.2s)

### avm1

- **Pass:** 745/766 (97.3%)
- **Ignored:** 15 tests
- **Duration:** 57m51s across 30 shards
- **Lines:** 116,171/119,566 matching (97.2%)
- **Avg test duration:** 4.4s — slowest: `netstream_play_flv_screen` (39.1s)

### avm2

- **Pass:** 1283/1305 (98.3%)
- **Ignored:** 34 tests
- **Duration:** 3h10m32s across 30 shards
- **Lines:** 157,341/158,700 matching (99.1%)
- **Avg test duration:** 8.5s — slowest: `away3d_advanced_shallow_water_demo` (78.3s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 16.2s — slowest: `embed_matching/fallback_preferences` (24.1s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 2h42m09s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 6.1s — slowest: `ecma3/Statements/eregress_74474_002` (61.5s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 22m53s across 30 shards
- **Lines:** 30,601/32,104 matching (95.3%)
- **Avg test duration:** 5.7s — slowest: `MovieClip-v8` (51.7s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 24m31s across 30 shards
- **Lines:** 4,256/5,206 matching (81.8%)
- **Avg test duration:** 13.2s — slowest: `matrix_test` (85.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 8.7s — slowest: `implementsOpTest` (18.5s)

### from_gnash/misc-swfc.all

- **Pass:** 14/19 (73.7%)
- **Ignored:** 1 tests
- **Duration:** 4m28s across 30 shards
- **Lines:** 476/562 matching (84.7%)
- **Avg test duration:** 14.0s — slowest: `sound` (23.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m31s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 13.6s — slowest: `zeroframe_definesprite` (22.9s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 38m53s across 30 shards
- **Lines:** 2,362/2,409 matching (98.0%)
- **Avg test duration:** 9.8s — slowest: `acid/acid-large` (65.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m36s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.0s — slowest: `text-bind` (17.9s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 38s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 12.6s — slowest: `avm1_non_swf_import` (18.7s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m04s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.4s — slowest: `avm1_sprite_sc_ignored` (15.0s)

### regression

- **Pass:** 131/131 (100%)
- **Duration:** 22m14s across 30 shards
- **Lines:** 1,183/1,183 matching (100%)
- **Avg test duration:** 10.2s — slowest: `avm2_parent_child_render` (28.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.2s — slowest: `draw_to_bitmap_data_unconfigured` (22.4s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 24s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 3.4s — slowest: `lzma_length_too_long` (17.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m01s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 15.1s — slowest: `text_caret_placement_scroll` (23.8s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m00s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 14.1s — slowest: `swf_9_frame_script_dynamic_goto` (24.4s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 28m38s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.3s — slowest: `definefont4` (84.6s)
