# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2d40d37996b8`  
**Date:** 2026-11-27 16:08 UTC  
**Total duration:** 11h19m03s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1316 | 1352 | 97.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1564 | 1574 | 99.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 181 | 243 | 74.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 74 | 111 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 318 | 319 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4749** | **4940** | **96.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,761 | 137,880 | 91.2% |
| avm2 | 162,918 | 164,470 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,953 | 85,996 | 99.9% |
| from_gnash/actionscript.all | 31,177 | 38,791 | 80.4% |
| from_gnash/misc-ming.all | 4,365 | 5,248 | 83.2% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,282 | 3,284 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **419,635** | **442,077** | **94.9%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 10 |
| avm2 | 6 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 1 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | 1 |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **35** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | loader_load | 98% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 84% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |

## Changes Since Last Run

*No changes since last run.*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 15.0s — slowest: `stream_incomplete_loop` (23.6s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h05m59s across 30 shards
- **Lines:** 125,761/137,880 matching (91.2%)
- **Avg test duration:** 5.0s — slowest: `netstream_play_flv_screen` (34.4s)

### avm2

- **Pass:** 1316/1352 (97.3%)
- **Duration:** 3h33m53s across 30 shards
- **Lines:** 162,918/164,470 matching (99.1%)
- **Avg test duration:** 9.5s — slowest: `away3d_advanced_shallow_water_demo` (80.8s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m39s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.7s — slowest: `device_font_no_ink` (30.1s)

### from_avmplus

- **Pass:** 1564/1574 (99.4%)
- **Duration:** 2h56m42s across 30 shards
- **Lines:** 85,953/85,996 matching (99.9%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_002` (60.5s)

### from_gnash/actionscript.all

- **Pass:** 181/243 (74.5%)
- **Duration:** 25m05s across 30 shards
- **Lines:** 31,177/38,791 matching (80.4%)
- **Avg test duration:** 6.2s — slowest: `MovieClip-v8` (52.7s)

### from_gnash/misc-ming.all

- **Pass:** 74/111 (66.7%)
- **Duration:** 30m54s across 30 shards
- **Lines:** 4,365/5,248 matching (83.2%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (122.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 11.7s — slowest: `implementsOpTest` (20.3s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 5m03s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 14.4s — slowest: `movieclip_destruction_test3` (26.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m28s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 16.4s — slowest: `registers` (24.5s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 43m50s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 11.5s — slowest: `acid/acid-large` (80.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.3s — slowest: `text-bind` (24.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 41s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.6s — slowest: `avm1_non_swf_import` (19.9s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.3s — slowest: `avm1_sprite_sc_ignored` (18.9s)

### regression

- **Pass:** 318/319 (99.7%)
- **Duration:** 58m36s across 30 shards
- **Lines:** 3,282/3,284 matching (99.9%)
- **Avg test duration:** 11.0s — slowest: `avm2_child_simplebutton` (35.0s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.6s — slowest: `draw_to_bitmap_data_unconfigured` (24.1s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m19s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.3s — slowest: `lzma_length_too_long` (19.3s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m29s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.4s — slowest: `text_caret_placement_leading` (32.5s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m07s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 18.1s — slowest: `missing_frame_scripts` (31.4s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m46s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (97.1s)
