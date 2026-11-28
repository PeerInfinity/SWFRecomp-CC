# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9498e80c12e3`  
**Date:** 2026-11-28 00:52 UTC  
**Total duration:** 14h11m12s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1322 | 1353 | 97.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1567 | 1574 | 99.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 182 | 243 | 74.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 76 | 111 | 68.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 218 | 229 | 95.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 344 | 344 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4793** | **4966** | **96.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 127,286 | 137,880 | 92.3% |
| avm2 | 163,183 | 164,501 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,956 | 85,996 | 99.95% |
| from_gnash/actionscript.all | 31,115 | 38,791 | 80.2% |
| from_gnash/misc-ming.all | 4,376 | 5,248 | 83.4% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,414 | 2,484 | 97.2% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,741 | 3,741 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **421,853** | **442,565** | **95.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 9 |
| avm2 | 5 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 7 |
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
| **Total** | **29** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | movieclip_hittest_shapeflag | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm2 | loader_load | 98% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `715a5300c822` → `9498e80c12e3`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.0s — slowest: `g711` (24.2s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h32m22s across 30 shards
- **Lines:** 127,286/137,880 matching (92.3%)
- **Avg test duration:** 7.0s — slowest: `virtual_property_recursion_swf6` (46.6s)

### avm2

- **Pass:** 1322/1353 (97.7%)
- **Duration:** 4h25m17s across 30 shards
- **Lines:** 163,183/164,501 matching (99.2%)
- **Avg test duration:** 11.7s — slowest: `away3d_advanced_shallow_water_demo` (94.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m09s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 21.0s — slowest: `device_font_no_ink` (27.8s)

### from_avmplus

- **Pass:** 1567/1574 (99.6%)
- **Duration:** 3h33m25s across 30 shards
- **Lines:** 85,956/85,996 matching (99.95%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_003` (59.6s)

### from_gnash/actionscript.all

- **Pass:** 182/243 (74.9%)
- **Duration:** 32m33s across 30 shards
- **Lines:** 31,115/38,791 matching (80.2%)
- **Avg test duration:** 8.0s — slowest: `array-v5` (53.4s)

### from_gnash/misc-ming.all

- **Pass:** 76/111 (68.5%)
- **Duration:** 36m09s across 30 shards
- **Lines:** 4,376/5,248 matching (83.4%)
- **Avg test duration:** 19.5s — slowest: `matrix_test` (124.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.4s — slowest: `exception` (21.3s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 5m55s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 16.9s — slowest: `opcode_guard_test2` (26.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `trace-as2/arguments` (25.6s)

### from_shumway

- **Pass:** 218/229 (95.2%)
- **Duration:** 53m28s across 30 shards
- **Lines:** 2,414/2,484 matching (97.2%)
- **Avg test duration:** 14.0s — slowest: `esc` (85.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m35s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.3s — slowest: `text-bind` (26.7s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.5s — slowest: `empty_url` (21.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (20.8s)

### regression

- **Pass:** 344/344 (100%)
- **Duration:** 1h15m46s across 30 shards
- **Lines:** 3,741/3,741 matching (100%)
- **Avg test duration:** 13.2s — slowest: `avm2_layer_group_erase` (41.0s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 13.6s — slowest: `request_matching_profiles` (27.9s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.1s — slowest: `swf_length_too_long` (21.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m43s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.6s — slowest: `auto_size/return` (30.4s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 6m30s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 22.9s — slowest: `swf_9_frame_script_cleanup_goto2` (34.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 44m14s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 17.5s — slowest: `definefont4` (91.0s)
