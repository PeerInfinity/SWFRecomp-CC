# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `dbc43c157352`  
**Date:** 2026-11-27 03:57 UTC  
**Total duration:** 10h13m41s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 776 | 783 | 99.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1307 | 1323 | 98.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1564 | 1572 | 99.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 181 | 240 | 75.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 74 | 110 | 67.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 17 | 20 | 85.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 315 | 316 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4737** | **4887** | **96.9%** | |

*50 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 117,172 | 120,277 | 97.4% |
| avm2 | 161,493 | 162,733 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,941 | 85,970 | 99.97% |
| from_gnash/actionscript.all | 30,894 | 32,104 | 96.2% |
| from_gnash/misc-ming.all | 4,357 | 5,206 | 83.7% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 550 | 585 | 94.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,197 | 3,199 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **409,173** | **415,804** | **98.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 3 | 4 |
| avm2 | 1 | 15 |
| fonts | - | 1 |
| from_avmplus | - | 8 |
| from_gnash/actionscript.all | - | 59 |
| from_gnash/misc-ming.all | 8 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 3 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | 1 | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **15** | **135** |

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
- **Duration:** 1m11s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.3s — slowest: `stream_incomplete_loop` (20.0s)

### avm1

- **Pass:** 776/783 (99.1%)
- **Ignored:** 8 tests
- **Duration:** 54m58s across 30 shards
- **Lines:** 117,172/120,277 matching (97.4%)
- **Avg test duration:** 4.1s — slowest: `netstream_play_flv_screen` (33.2s)

### avm2

- **Pass:** 1307/1323 (98.8%)
- **Ignored:** 29 tests
- **Duration:** 3h14m26s across 30 shards
- **Lines:** 161,493/162,733 matching (99.2%)
- **Avg test duration:** 8.6s — slowest: `away3d_advanced_shallow_water_demo` (80.7s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m31s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 16.8s — slowest: `embed_matching/fallback_preferences` (25.3s)

### from_avmplus

- **Pass:** 1564/1572 (99.5%)
- **Ignored:** 2 tests
- **Duration:** 2h43m30s across 30 shards
- **Lines:** 85,941/85,970 matching (99.97%)
- **Avg test duration:** 6.2s — slowest: `ecma3/Statements/eregress_74474_002` (58.5s)

### from_gnash/actionscript.all

- **Pass:** 181/240 (75.4%)
- **Ignored:** 3 tests
- **Duration:** 22m59s across 30 shards
- **Lines:** 30,894/32,104 matching (96.2%)
- **Avg test duration:** 5.7s — slowest: `MovieClip-v8` (50.6s)

### from_gnash/misc-ming.all

- **Pass:** 74/110 (67.3%)
- **Ignored:** 1 tests
- **Duration:** 28m15s across 30 shards
- **Lines:** 4,357/5,206 matching (83.7%)
- **Avg test duration:** 15.2s — slowest: `matrix_test` (84.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 48s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 5.3s — slowest: `implementsOpTest` (19.2s)

### from_gnash/misc-swfc.all

- **Pass:** 17/20 (85.0%)
- **Ignored:** 1 tests
- **Duration:** 5m06s across 30 shards
- **Lines:** 550/585 matching (94.0%)
- **Avg test duration:** 15.2s — slowest: `soft_reference_test1` (21.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m53s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 14.7s — slowest: `jump_to_prev_block` (22.2s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 38m02s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 9.7s — slowest: `acid/acid-large` (69.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.2s — slowest: `hitarea` (19.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.4s — slowest: `empty_url` (19.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.0s — slowest: `avm1_sprite_sc_ignored` (18.7s)

### regression

- **Pass:** 315/316 (99.7%)
- **Duration:** 53m44s across 30 shards
- **Lines:** 3,197/3,199 matching (99.9%)
- **Avg test duration:** 10.2s — slowest: `avm2_timeline_gradients` (27.9s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.5s — slowest: `draw_to_bitmap_data_unconfigured` (25.2s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m01s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 8.7s — slowest: `swf_length_too_short_no_second_frame` (19.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m25s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.1s — slowest: `text_caret_placement_leading` (30.6s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m21s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 15.4s — slowest: `missing_frame_scripts` (30.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 29m28s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.7s — slowest: `definefont4` (94.7s)
