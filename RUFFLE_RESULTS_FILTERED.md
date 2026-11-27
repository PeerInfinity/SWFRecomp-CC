# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `bfa47037b19e`  
**Date:** 2026-11-26 21:04 UTC  
**Total duration:** 11h01m42s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 770 | 781 | 98.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1303 | 1322 | 98.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
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
| regression | 292 | 292 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4682** | **4860** | **96.3%** | |

*51 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 117,138 | 120,254 | 97.4% |
| avm2 | 161,439 | 162,726 | 99.2% |
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
| regression | 3,005 | 3,005 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **408,435** | **415,580** | **98.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 5 | 6 |
| avm2 | 3 | 16 |
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
| **Total** | **18** | **160** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | native_objects_swf6 | 99% |
| avm1 | globals_swf5 | 97% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 16.6s — slowest: `g711_event_alaw` (25.9s)

### avm1

- **Pass:** 770/781 (98.6%)
- **Ignored:** 9 tests
- **Duration:** 1h02m26s across 30 shards
- **Lines:** 117,138/120,254 matching (97.4%)
- **Avg test duration:** 4.7s — slowest: `netstream_play_flv_screen` (40.6s)

### avm2

- **Pass:** 1303/1322 (98.6%)
- **Ignored:** 29 tests
- **Duration:** 3h33m13s across 30 shards
- **Lines:** 161,439/162,726 matching (99.2%)
- **Avg test duration:** 9.4s — slowest: `away3d_advanced_shallow_water_demo` (110.9s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m34s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.1s — slowest: `device_font_list` (33.4s)

### from_avmplus

- **Pass:** 1549/1572 (98.5%)
- **Ignored:** 2 tests
- **Duration:** 2h55m37s across 30 shards
- **Lines:** 85,606/85,970 matching (99.6%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_002` (66.2s)

### from_gnash/actionscript.all

- **Pass:** 177/240 (73.8%)
- **Ignored:** 3 tests
- **Duration:** 23m58s across 30 shards
- **Lines:** 30,812/32,104 matching (96.0%)
- **Avg test duration:** 5.9s — slowest: `MovieClip-v8` (43.1s)

### from_gnash/misc-ming.all

- **Pass:** 73/110 (66.4%)
- **Ignored:** 1 tests
- **Duration:** 28m06s across 30 shards
- **Lines:** 4,352/5,206 matching (83.6%)
- **Avg test duration:** 15.1s — slowest: `matrix_test` (118.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m01s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 13.5s — slowest: `exception` (26.3s)

### from_gnash/misc-swfc.all

- **Pass:** 15/20 (75.0%)
- **Ignored:** 1 tests
- **Duration:** 4m27s across 30 shards
- **Lines:** 514/585 matching (87.9%)
- **Avg test duration:** 13.3s — slowest: `movieclip_destruction_test1` (28.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m59s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 15.0s — slowest: `missing_bitmap` (26.8s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 44m01s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 11.2s — slowest: `acid/acid-large` (76.3s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.4s — slowest: `text-bind` (24.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 49s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.1s — slowest: `empty_url` (28.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.9s — slowest: `avm1_sprite_sc_ignored` (23.8s)

### regression

- **Pass:** 292/292 (100%)
- **Duration:** 50m44s across 30 shards
- **Lines:** 3,005/3,005 matching (100%)
- **Avg test duration:** 10.4s — slowest: `avm2_activation_vtable_bounded` (32.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.5s — slowest: `draw_to_bitmap_data_unconfigured` (23.9s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 13.3s — slowest: `swf_length_too_short_no_second_frame` (26.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m37s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.1s — slowest: `auto_size/width` (34.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m31s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 15.9s — slowest: `frame_script_button_order` (35.1s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m56s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.1s — slowest: `definefont4` (117.6s)
