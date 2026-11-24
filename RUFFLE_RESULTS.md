# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `78fee9e13f85`  
**Date:** 2026-11-24 16:56 UTC  
**Total duration:** 11h38m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 751 | 788 | 95.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1288 | 1346 | 95.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 71 | 111 | 64.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 243 | 243 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4548** | **4855** | **93.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,298 | 137,755 | 91.0% |
| avm2 | 161,871 | 164,338 | 98.5% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,878 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,317 | 5,248 | 82.3% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 526 | 603 | 87.2% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,965 | 1,965 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **416,020** | **440,501** | **94.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| audio | 1 | - |
| avm1 | 14 | 1 |
| avm2 | 10 | - |
| fonts | - | - |
| from_avmplus | 2 | - |
| from_gnash/actionscript.all | 3 | - |
| from_gnash/misc-ming.all | 8 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 2 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 2 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | - |
| visual | - | - |
| **Total** | **43** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | globals_swf5 | 97% |
| from_gnash/misc-swfc.all | action_execution_order_test12 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 5 |
| from_gnash/misc-ming.all | - | - | 6 | 2 |
| from_gnash/misc-mtasc.all | - | - | 4 | - |
| from_gnash/misc-swfc.all | - | 1 | 3 | 1 |

*Comparing `cceb5133a189` → `78fee9e13f85`*

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

- **Pass:** 751/788 (95.3%)
- **Duration:** 1h15m18s across 30 shards
- **Lines:** 125,298/137,755 matching (91.0%)
- **Avg test duration:** 5.7s — slowest: `mcl_target_gif89a` (32.9s)

### avm2

- **Pass:** 1288/1346 (95.7%)
- **Duration:** 3h45m14s across 30 shards
- **Lines:** 161,871/164,338 matching (98.5%)
- **Avg test duration:** 10.0s — slowest: `away3d_advanced_shallow_water_demo` (104.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.2s — slowest: `device_font_list` (30.8s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 2h56m15s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (56.8s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 29m32s across 30 shards
- **Lines:** 30,878/38,791 matching (79.6%)
- **Avg test duration:** 7.3s — slowest: `MovieClip-v8` (54.0s)

### from_gnash/misc-ming.all

- **Pass:** 71/111 (64.0%)
- **Duration:** 33m20s across 30 shards
- **Lines:** 4,317/5,248 matching (82.3%)
- **Avg test duration:** 18.0s — slowest: `matrix_test` (77.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.4s — slowest: `exception` (24.8s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 5m26s across 30 shards
- **Lines:** 526/603 matching (87.2%)
- **Avg test duration:** 15.5s — slowest: `movieclip_destruction_test1` (27.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m45s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.2s — slowest: `trace-as2/super` (24.6s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 43m41s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.4s — slowest: `acid/acid-large` (67.0s)

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
