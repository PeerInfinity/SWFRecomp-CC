# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `13b40eabb012`  
**Date:** 2026-11-25 20:23 UTC  
**Total duration:** 11h52m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 755 | 777 | 97.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1292 | 1312 | 98.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 71 | 110 | 64.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 14 | 20 | 70.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 254 | 254 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4569** | **4808** | **95.0%** | |

*59 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 116,314 | 119,712 | 97.2% |
| avm2 | 157,800 | 159,038 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,595 | 32,104 | 95.3% |
| from_gnash/misc-ming.all | 4,311 | 5,206 | 82.8% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 511 | 585 | 87.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,030 | 2,030 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **402,676** | **410,375** | **98.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 3 | 19 |
| avm2 | - | 20 |
| fonts | - | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | - | 92 |
| from_gnash/misc-ming.all | 8 | 31 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 1 | 5 |
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
| **Total** | **13** | **226** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | action_execution_order_test12 | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m35s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 19.1s — slowest: `g711_event_mulaw` (26.1s)

### avm1

- **Pass:** 755/777 (97.2%)
- **Ignored:** 12 tests
- **Duration:** 1h02m56s across 30 shards
- **Lines:** 116,314/119,712 matching (97.2%)
- **Avg test duration:** 4.8s — slowest: `netstream_play_flv_screen` (43.8s)

### avm2

- **Pass:** 1292/1312 (98.5%)
- **Ignored:** 34 tests
- **Duration:** 3h48m26s across 30 shards
- **Lines:** 157,800/159,038 matching (99.2%)
- **Avg test duration:** 10.1s — slowest: `away3d_advanced_shallow_water_demo` (86.6s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m55s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.4s — slowest: `device_font_no_ink` (32.3s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 3h32m15s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_003` (63.9s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 22m28s across 30 shards
- **Lines:** 30,595/32,104 matching (95.3%)
- **Avg test duration:** 5.6s — slowest: `MovieClip-v8` (53.0s)

### from_gnash/misc-ming.all

- **Pass:** 71/110 (64.5%)
- **Ignored:** 1 tests
- **Duration:** 25m14s across 30 shards
- **Lines:** 4,311/5,206 matching (82.8%)
- **Avg test duration:** 13.7s — slowest: `matrix_test` (78.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m56s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.9s — slowest: `function_test` (26.6s)

### from_gnash/misc-swfc.all

- **Pass:** 14/20 (70.0%)
- **Ignored:** 1 tests
- **Duration:** 5m31s across 30 shards
- **Lines:** 511/585 matching (87.4%)
- **Avg test duration:** 16.4s — slowest: `edittext_test1` (28.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 7m13s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 21.6s — slowest: `trace-as2/root_onload` (28.9s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 46m18s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 11.8s — slowest: `acid/acid-large` (85.3s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m31s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.2s — slowest: `label` (25.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.2s — slowest: `empty_url` (19.3s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.7s — slowest: `avm1_sprite_sc_ignored` (25.9s)

### regression

- **Pass:** 254/254 (100%)
- **Duration:** 46m22s across 30 shards
- **Lines:** 2,030/2,030 matching (100%)
- **Avg test duration:** 10.9s — slowest: `avm2_layer_group_filtered_child` (37.3s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.8s — slowest: `draw_to_bitmap_data_unconfigured` (24.6s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 31s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 4.5s — slowest: `convolution_filter_big_matrix` (19.2s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m35s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.0s — slowest: `text_caret_placement_align` (34.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 8.5s — slowest: `frame_label_count_oom` (18.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m17s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.4s — slowest: `definefont4` (85.4s)
