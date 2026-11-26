# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `b030ed745d4f`  
**Date:** 2026-11-25 23:59 UTC  
**Total duration:** 11h50m22s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 768 | 777 | 98.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1299 | 1317 | 98.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1549 | 1572 | 98.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 177 | 240 | 73.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 73 | 110 | 66.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 15 | 20 | 75.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 282 | 282 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4666** | **4841** | **96.4%** | |

*56 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 116,652 | 119,758 | 97.4% |
| avm2 | 161,311 | 162,557 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,606 | 85,970 | 99.6% |
| from_gnash/actionscript.all | 30,812 | 32,104 | 96.0% |
| from_gnash/misc-ming.all | 4,352 | 5,206 | 83.6% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 514 | 585 | 87.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,979 | 2,979 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **407,795** | **414,889** | **98.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 3 | 6 |
| avm2 | 2 | 16 |
| fonts | - | 1 |
| from_avmplus | - | 23 |
| from_gnash/actionscript.all | - | 63 |
| from_gnash/misc-ming.all | 8 | 29 |
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
| **Total** | **15** | **160** |

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
- **Duration:** 1m13s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.7s — slowest: `stream_incomplete_loop` (18.6s)

### avm1

- **Pass:** 768/777 (98.8%)
- **Ignored:** 12 tests
- **Duration:** 1h17m23s across 30 shards
- **Lines:** 116,652/119,758 matching (97.4%)
- **Avg test duration:** 5.9s — slowest: `netstream_play_flv_screen` (40.7s)

### avm2

- **Pass:** 1299/1317 (98.6%)
- **Ignored:** 31 tests
- **Duration:** 3h41m02s across 30 shards
- **Lines:** 161,311/162,557 matching (99.2%)
- **Avg test duration:** 9.7s — slowest: `away3d_advanced_shallow_water_demo` (79.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m56s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.6s — slowest: `device_font_kerning` (33.3s)

### from_avmplus

- **Pass:** 1549/1572 (98.5%)
- **Ignored:** 2 tests
- **Duration:** 2h55m33s across 30 shards
- **Lines:** 85,606/85,970 matching (99.6%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (64.0s)

### from_gnash/actionscript.all

- **Pass:** 177/240 (73.8%)
- **Ignored:** 3 tests
- **Duration:** 29m58s across 30 shards
- **Lines:** 30,812/32,104 matching (96.0%)
- **Avg test duration:** 7.4s — slowest: `array-v5` (55.5s)

### from_gnash/misc-ming.all

- **Pass:** 73/110 (66.4%)
- **Ignored:** 1 tests
- **Duration:** 35m22s across 30 shards
- **Lines:** 4,352/5,206 matching (83.6%)
- **Avg test duration:** 19.1s — slowest: `matrix_test` (109.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.3s — slowest: `TextFieldTest` (24.4s)

### from_gnash/misc-swfc.all

- **Pass:** 15/20 (75.0%)
- **Ignored:** 1 tests
- **Duration:** 5m38s across 30 shards
- **Lines:** 514/585 matching (87.9%)
- **Avg test duration:** 16.8s — slowest: `action_execution_order_test12` (26.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m55s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.8s — slowest: `background` (25.6s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 46m22s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 11.7s — slowest: `acid/acid-large` (65.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.6s — slowest: `text-bind` (25.2s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.7s — slowest: `avm1_non_swf_import` (26.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.8s — slowest: `avm1_sprite_sc_ignored` (18.6s)

### regression

- **Pass:** 282/282 (100%)
- **Duration:** 55m05s across 30 shards
- **Lines:** 2,979/2,979 matching (100%)
- **Avg test duration:** 11.7s — slowest: `avm2_json_roundtrip_bounded` (34.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.0s — slowest: `draw_to_bitmap_data_unconfigured` (30.5s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.9s — slowest: `lzma_length_too_long` (25.8s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m57s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.7s — slowest: `auto_size/return` (33.5s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m18s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 22.2s — slowest: `swf_9_frame_script_dynamic_goto_2` (32.6s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 33m41s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `definefont4` (112.0s)
