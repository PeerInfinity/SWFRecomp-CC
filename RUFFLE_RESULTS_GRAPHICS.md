# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `1396f1e10b65`  
**Date:** 2026-11-23 19:43 UTC  
**Total duration:** 12h37m39s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 745 | 781 | 95.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1285 | 1339 | 96.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 70 | 111 | 63.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 170 | 170 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4466** | **4768** | **93.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,274 | 137,730 | 91.0% |
| avm2 | 161,692 | 164,000 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,884 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,284 | 5,248 | 81.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 491 | 603 | 81.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,445 | 1,445 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **415,237** | **439,618** | **94.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 14 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 8 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 2 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **40** |

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
| avm2 | number_tostring | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 2 | - | 17 |
| from_gnash/misc-ming.all | - | - | 2 | 1 |

**avm1 — newly failing:** `hitarea_remove_owner_drag`, `hitarea_sweep`

*Comparing `da9b49b17a0a` → `1396f1e10b65`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 25.0s — slowest: `g711` (33.4s)

### avm1

- **Pass:** 745/781 (95.4%)
- **Duration:** 1h21m55s across 30 shards
- **Lines:** 125,274/137,730 matching (91.0%)
- **Avg test duration:** 6.3s — slowest: `equals_swf4_alt` (53.5s)

### avm2

- **Pass:** 1285/1339 (96.0%)
- **Duration:** 4h02m02s across 30 shards
- **Lines:** 161,692/164,000 matching (98.6%)
- **Avg test duration:** 10.8s — slowest: `away3d_advanced_shallow_water_demo` (86.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 21.7s — slowest: `embed_matching/fallback_preferences` (35.3s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h28m06s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.9s — slowest: `ecma3/Statements/eregress_74474_003` (70.3s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 31m02s across 30 shards
- **Lines:** 30,884/38,791 matching (79.6%)
- **Avg test duration:** 7.6s — slowest: `MovieClip-v8` (54.3s)

### from_gnash/misc-ming.all

- **Pass:** 70/111 (63.1%)
- **Duration:** 34m31s across 30 shards
- **Lines:** 4,284/5,248 matching (81.6%)
- **Avg test duration:** 18.6s — slowest: `matrix_test` (83.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m12s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.7s — slowest: `implementsOpTest` (26.4s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 5m41s across 30 shards
- **Lines:** 491/603 matching (81.4%)
- **Avg test duration:** 16.2s — slowest: `action_execution_order_test12` (27.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 7m11s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 21.6s — slowest: `background` (25.9s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 48m14s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 12.6s — slowest: `acid/acid-large` (67.5s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m27s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `hitarea` (24.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 52s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 17.3s — slowest: `avm1_non_swf_import` (26.9s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.3s — slowest: `avm1_sprite_sc_ignored` (20.0s)

### regression

- **Pass:** 170/170 (100%)
- **Duration:** 37m27s across 30 shards
- **Lines:** 1,445/1,445 matching (100%)
- **Avg test duration:** 13.2s — slowest: `avm2_parent_child_symbol_stride` (38.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 14.0s — slowest: `draw_to_bitmap_data_unconfigured` (32.6s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m02s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 8.8s — slowest: `lzma_length_too_long` (26.0s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 4m12s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 21.0s — slowest: `auto_size/return` (37.8s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m00s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.2s — slowest: `frame_script_cleanup_goto` (33.8s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 35m57s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.3s — slowest: `definefont4` (112.5s)
