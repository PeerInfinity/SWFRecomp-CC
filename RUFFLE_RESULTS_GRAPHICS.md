# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `7c3cfdcb7bbe`  
**Date:** 2026-11-25 05:10 UTC  
**Total duration:** 11h05m51s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 754 | 788 | 95.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1293 | 1346 | 96.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 71 | 111 | 64.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 254 | 254 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4569** | **4866** | **93.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,316 | 137,755 | 91.0% |
| avm2 | 162,033 | 164,338 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,878 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,318 | 5,248 | 82.3% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 526 | 603 | 87.2% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,030 | 2,030 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **416,273** | **440,566** | **94.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 12 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 8 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 1 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **38** |

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

*No changes since last run.*

*Comparing `8f4f6e395305` → `7c3cfdcb7bbe`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 16.7s — slowest: `stream_incomplete_loop` (19.5s)

### avm1

- **Pass:** 754/788 (95.7%)
- **Duration:** 1h00m36s across 30 shards
- **Lines:** 125,316/137,755 matching (91.0%)
- **Avg test duration:** 4.6s — slowest: `netstream_play_flv_screen` (36.3s)

### avm2

- **Pass:** 1293/1346 (96.1%)
- **Duration:** 3h32m44s across 30 shards
- **Lines:** 162,033/164,338 matching (98.6%)
- **Avg test duration:** 9.4s — slowest: `away3d_advanced_shallow_water_demo` (74.3s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m52s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.1s — slowest: `embed_matching/fallback_preferences` (26.9s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h14m27s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.4s — slowest: `ecma3/Statements/eregress_74474_003` (59.0s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 21m47s across 30 shards
- **Lines:** 30,878/38,791 matching (79.6%)
- **Avg test duration:** 5.3s — slowest: `MovieClip-v8` (54.5s)

### from_gnash/misc-ming.all

- **Pass:** 71/111 (64.0%)
- **Duration:** 23m41s across 30 shards
- **Lines:** 4,318/5,248 matching (82.3%)
- **Avg test duration:** 12.8s — slowest: `matrix_test` (78.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.6s — slowest: `inheritance` (25.6s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 5m14s across 30 shards
- **Lines:** 526/603 matching (87.2%)
- **Avg test duration:** 14.9s — slowest: `movieclip_destruction_test3` (27.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m50s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `registers` (27.0s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 42m13s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 11.0s — slowest: `acid/acid-large` (67.5s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `label` (25.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 41s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.7s — slowest: `avm1_non_swf_import` (19.6s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m29s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (19.1s)

### regression

- **Pass:** 254/254 (100%)
- **Duration:** 44m30s across 30 shards
- **Lines:** 2,030/2,030 matching (100%)
- **Avg test duration:** 10.5s — slowest: `avm2_graphics_runtime` (32.8s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m31s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.4s — slowest: `draw_to_bitmap_data_unconfigured` (25.1s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 31s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 4.4s — slowest: `convolution_filter_big_matrix` (19.8s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m40s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.3s — slowest: `text_caret_placement_align` (34.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 2m17s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 8.0s — slowest: `frame_label_count_oom` (19.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 35m00s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.9s — slowest: `definefont4` (107.2s)
