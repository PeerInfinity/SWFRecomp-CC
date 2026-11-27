# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `0224aaf25632`  
**Date:** 2026-11-27 22:24 UTC  
**Total duration:** 11h25m03s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 776 | 783 | 99.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1311 | 1324 | 99.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1567 | 1572 | 99.7% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 181 | 240 | 75.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 76 | 110 | 69.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 17 | 20 | 85.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 217 | 223 | 97.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 338 | 338 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4773** | **4910** | **97.2%** | |

*50 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 117,172 | 120,277 | 97.4% |
| avm2 | 161,629 | 162,765 | 99.3% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,944 | 85,970 | 99.97% |
| from_gnash/actionscript.all | 30,894 | 32,104 | 96.2% |
| from_gnash/misc-ming.all | 4,161 | 5,206 | 79.9% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 550 | 585 | 94.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,368 | 2,409 | 98.3% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,530 | 3,530 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **409,459** | **416,167** | **98.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 3 | 4 |
| avm2 | 1 | 12 |
| fonts | - | 1 |
| from_avmplus | - | 5 |
| from_gnash/actionscript.all | - | 59 |
| from_gnash/misc-ming.all | 7 | 27 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 3 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 6 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | 1 |
| visual | - | 2 |
| **Total** | **13** | **124** |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 15.4s — slowest: `g711_event_mulaw` (24.1s)

### avm1

- **Pass:** 776/783 (99.1%)
- **Ignored:** 8 tests
- **Duration:** 1h05m44s across 30 shards
- **Lines:** 117,172/120,277 matching (97.4%)
- **Avg test duration:** 5.0s — slowest: `netstream_play_flv_screen` (32.9s)

### avm2

- **Pass:** 1311/1324 (99.0%)
- **Ignored:** 29 tests
- **Duration:** 3h34m58s across 30 shards
- **Lines:** 161,629/162,765 matching (99.3%)
- **Avg test duration:** 9.5s — slowest: `away3d_advanced_shallow_water_demo` (83.8s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.3s — slowest: `embed_matching/fallback_preferences` (33.8s)

### from_avmplus

- **Pass:** 1567/1572 (99.7%)
- **Ignored:** 2 tests
- **Duration:** 2h56m28s across 30 shards
- **Lines:** 85,944/85,970 matching (99.97%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (70.0s)

### from_gnash/actionscript.all

- **Pass:** 181/240 (75.4%)
- **Ignored:** 3 tests
- **Duration:** 25m32s across 30 shards
- **Lines:** 30,894/32,104 matching (96.2%)
- **Avg test duration:** 6.3s — slowest: `MovieClip-v8` (56.4s)

### from_gnash/misc-ming.all

- **Pass:** 76/110 (69.1%)
- **Ignored:** 1 tests
- **Duration:** 30m32s across 30 shards
- **Lines:** 4,161/5,206 matching (79.9%)
- **Avg test duration:** 16.4s — slowest: `matrix_test` (103.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m04s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 13.8s — slowest: `TextFieldTest` (27.2s)

### from_gnash/misc-swfc.all

- **Pass:** 17/20 (85.0%)
- **Ignored:** 1 tests
- **Duration:** 4m48s across 30 shards
- **Lines:** 550/585 matching (94.0%)
- **Avg test duration:** 14.3s — slowest: `action_execution_order_test10` (26.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m54s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.7s — slowest: `afunc_dict` (24.7s)

### from_shumway

- **Pass:** 217/223 (97.3%)
- **Ignored:** 6 tests
- **Duration:** 42m44s across 30 shards
- **Lines:** 2,368/2,409 matching (98.3%)
- **Avg test duration:** 10.8s — slowest: `acid/acid-large` (57.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.2s — slowest: `text-bind` (20.9s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.7s — slowest: `avm1_non_swf_import` (25.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 58s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 4.8s — slowest: `avm2_loads_avm1` (8.7s)

### regression

- **Pass:** 338/338 (100%)
- **Duration:** 1h03m13s across 30 shards
- **Lines:** 3,530/3,530 matching (100%)
- **Avg test duration:** 11.2s — slowest: `avm2_goto_catchup_scale` (33.9s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.5s — slowest: `draw_to_bitmap_data_unconfigured` (31.5s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.1s — slowest: `lzma_length_too_long` (24.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m38s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.1s — slowest: `text_caret_placement_leading` (32.4s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 4m58s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 17.5s — slowest: `missing_frame_scripts` (31.5s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m53s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (84.9s)
