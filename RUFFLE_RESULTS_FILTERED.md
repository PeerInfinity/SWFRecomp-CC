# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `78fee9e13f85`  
**Date:** 2026-11-24 16:56 UTC  
**Total duration:** 11h38m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 750 | 773 | 97.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1287 | 1312 | 98.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 71 | 110 | 64.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 14 | 20 | 70.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 243 | 243 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4546** | **4793** | **94.8%** | |

*62 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 116,182 | 119,591 | 97.1% |
| avm2 | 157,638 | 159,038 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,595 | 32,104 | 95.3% |
| from_gnash/misc-ming.all | 4,310 | 5,206 | 82.8% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 511 | 585 | 87.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,362 | 2,409 | 98.0% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,965 | 1,965 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **402,309** | **410,189** | **98.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault |
|-------|-----------------:|----------------:|----------:|
| audio | 1 | - | - |
| avm1 | 5 | 17 | 1 |
| avm2 | 1 | 24 | - |
| fonts | - | 1 | - |
| from_avmplus | - | 39 | - |
| from_gnash/actionscript.all | - | 92 | - |
| from_gnash/misc-ming.all | 7 | 32 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 1 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 1 | 8 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 1 | 1 | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | - | - | - |
| timeline | - | 3 | - |
| visual | - | 2 | - |
| **Total** | **17** | **229** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | action_execution_order_test12 | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

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
- **Avg test duration:** 15.4s — slowest: `g711_event_alaw` (23.4s)

### avm1

- **Pass:** 750/773 (97.0%)
- **Ignored:** 15 tests
- **Duration:** 1h15m18s across 30 shards
- **Lines:** 116,182/119,591 matching (97.1%)
- **Avg test duration:** 5.7s — slowest: `mcl_target_gif89a` (32.9s)

### avm2

- **Pass:** 1287/1312 (98.1%)
- **Ignored:** 34 tests
- **Duration:** 3h45m14s across 30 shards
- **Lines:** 157,638/159,038 matching (99.1%)
- **Avg test duration:** 9.9s — slowest: `away3d_advanced_shallow_water_demo` (104.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.2s — slowest: `device_font_list` (30.8s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 2h56m15s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (56.8s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 29m32s across 30 shards
- **Lines:** 30,595/32,104 matching (95.3%)
- **Avg test duration:** 7.3s — slowest: `MovieClip-v8` (54.0s)

### from_gnash/misc-ming.all

- **Pass:** 71/110 (64.5%)
- **Ignored:** 1 tests
- **Duration:** 33m20s across 30 shards
- **Lines:** 4,310/5,206 matching (82.8%)
- **Avg test duration:** 18.0s — slowest: `matrix_test` (77.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.4s — slowest: `exception` (24.8s)

### from_gnash/misc-swfc.all

- **Pass:** 14/20 (70.0%)
- **Ignored:** 1 tests
- **Duration:** 5m26s across 30 shards
- **Lines:** 511/585 matching (87.4%)
- **Avg test duration:** 16.2s — slowest: `movieclip_destruction_test1` (27.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m45s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.2s — slowest: `trace-as2/super` (24.6s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 43m41s across 30 shards
- **Lines:** 2,362/2,409 matching (98.0%)
- **Avg test duration:** 11.1s — slowest: `acid/acid-large` (67.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.5s — slowest: `label` (25.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 50s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.8s — slowest: `empty_url` (24.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.4s — slowest: `avm1_sprite_sc_ignored` (18.1s)

### regression

- **Pass:** 243/243 (100%)
- **Duration:** 47m28s across 30 shards
- **Lines:** 1,965/1,965 matching (100%)
- **Avg test duration:** 11.7s — slowest: `avm2_bitmapdata_draw_textfield` (35.8s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.4s — slowest: `draw_to_bitmap_data_unconfigured` (24.6s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.3s — slowest: `lzma_length_too_long` (23.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m45s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.8s — slowest: `text_caret_placement_align` (32.3s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m59s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.1s — slowest: `frame_script_construct` (31.4s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m55s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (111.8s)
