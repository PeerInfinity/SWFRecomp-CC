# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `bfa47037b19e`  
**Date:** 2026-11-26 20:41 UTC  
**Total duration:** 13h08m48s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 770 | 790 | 97.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1309 | 1351 | 96.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1549 | 1574 | 98.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 177 | 243 | 72.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 73 | 111 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 292 | 292 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4689** | **4911** | **95.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,716 | 137,861 | 91.2% |
| avm2 | 162,797 | 164,458 | 99.0% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,618 | 85,996 | 99.6% |
| from_gnash/actionscript.all | 31,095 | 38,791 | 80.2% |
| from_gnash/misc-ming.all | 4,359 | 5,248 | 83.1% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 529 | 603 | 87.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,005 | 3,005 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **418,739** | **441,767** | **94.8%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 12 |
| avm2 | 8 |
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
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **37** |

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
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `ed63ce7c4399` → `bfa47037b19e`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 2m00s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 24.0s — slowest: `aac` (32.3s)

### avm1

- **Pass:** 770/790 (97.5%)
- **Duration:** 1h22m09s across 30 shards
- **Lines:** 125,716/137,861 matching (91.2%)
- **Avg test duration:** 6.2s — slowest: `catch_references_registers` (47.5s)

### avm2

- **Pass:** 1309/1351 (96.9%)
- **Duration:** 4h09m23s across 30 shards
- **Lines:** 162,797/164,458 matching (99.0%)
- **Avg test duration:** 11.0s — slowest: `away3d_advanced_shallow_water_demo` (101.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 21.7s — slowest: `embed_matching/fallback_preferences` (35.8s)

### from_avmplus

- **Pass:** 1549/1574 (98.4%)
- **Duration:** 3h33m47s across 30 shards
- **Lines:** 85,618/85,996 matching (99.6%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_002` (61.6s)

### from_gnash/actionscript.all

- **Pass:** 177/243 (72.8%)
- **Duration:** 29m32s across 30 shards
- **Lines:** 31,095/38,791 matching (80.2%)
- **Avg test duration:** 7.3s — slowest: `MovieClip-v8` (52.6s)

### from_gnash/misc-ming.all

- **Pass:** 73/111 (65.8%)
- **Duration:** 32m27s across 30 shards
- **Lines:** 4,359/5,248 matching (83.1%)
- **Avg test duration:** 17.5s — slowest: `matrix_test` (80.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m09s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 14.3s — slowest: `TextFieldTest` (26.5s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 5m07s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 14.6s — slowest: `action_execution_order_test10` (27.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m53s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `trace-as2/shortstack` (26.3s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 47m50s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 12.5s — slowest: `esc` (89.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m37s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.3s — slowest: `hitarea` (25.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.3s — slowest: `empty_url` (22.3s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.7s — slowest: `avm1_sprite_sc_ignored` (19.8s)

### regression

- **Pass:** 292/292 (100%)
- **Duration:** 59m18s across 30 shards
- **Lines:** 3,005/3,005 matching (100%)
- **Avg test duration:** 12.2s — slowest: `avm2_group_alpha_layer_inner` (36.3s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 13.2s — slowest: `draw_to_bitmap_data_unconfigured` (33.1s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m37s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 13.8s — slowest: `convolution_filter_big_matrix` (25.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 4m02s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 20.1s — slowest: `auto_size/height` (40.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m02s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.3s — slowest: `swf_9_frame_script_dynamic_goto_2` (36.5s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m30s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.5s — slowest: `definefont4` (91.1s)
