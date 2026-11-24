# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `005bea42a286`  
**Date:** 2026-11-24 00:12 UTC  
**Total duration:** 10h09m44s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 747 | 781 | 95.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1284 | 1339 | 95.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 70 | 111 | 63.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 171 | 171 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4467** | **4769** | **93.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,291 | 137,730 | 91.0% |
| avm2 | 161,574 | 164,000 | 98.5% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,884 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,289 | 5,248 | 81.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 491 | 603 | 81.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,447 | 1,447 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **415,137** | **439,620** | **94.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 12 |
| avm2 | 10 |
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
| from_shumway | 1 | - | 1 | - |

**from_shumway — newly passing:** `as3-loader/bug1157243/empty`

*Comparing `7e14f54dd961` → `005bea42a286`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.1s — slowest: `stream_incomplete_loop` (18.7s)

### avm1

- **Pass:** 747/781 (95.6%)
- **Duration:** 1h04m09s across 30 shards
- **Lines:** 125,291/137,730 matching (91.0%)
- **Avg test duration:** 4.9s — slowest: `array_prototyping` (32.7s)

### avm2

- **Pass:** 1284/1339 (95.9%)
- **Duration:** 3h18m23s across 30 shards
- **Lines:** 161,574/164,000 matching (98.5%)
- **Avg test duration:** 8.9s — slowest: `away3d_advanced_shallow_water_demo` (78.2s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m35s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.2s — slowest: `device_font_kerning` (31.6s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 2h39m32s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 6.0s — slowest: `ecma3/Statements/eregress_74474_003` (58.9s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 25m19s across 30 shards
- **Lines:** 30,884/38,791 matching (79.6%)
- **Avg test duration:** 6.2s — slowest: `MovieClip-v8` (53.8s)

### from_gnash/misc-ming.all

- **Pass:** 70/111 (63.1%)
- **Duration:** 29m14s across 30 shards
- **Lines:** 4,289/5,248 matching (81.7%)
- **Avg test duration:** 15.8s — slowest: `matrix_test` (80.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m41s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.2s — slowest: `implementsOpTest` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 4m44s across 30 shards
- **Lines:** 491/603 matching (81.4%)
- **Avg test duration:** 13.5s — slowest: `action_execution_order_test12` (25.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m03s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.2s — slowest: `background` (24.3s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 41m13s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 10.8s — slowest: `acid/acid-large` (67.9s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.1s — slowest: `text-bind` (18.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 45s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.0s — slowest: `avm1_non_swf_import` (25.3s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.7s — slowest: `avm1_sprite_sc_ignored` (18.4s)

### regression

- **Pass:** 171/171 (100%)
- **Duration:** 31m52s across 30 shards
- **Lines:** 1,447/1,447 matching (100%)
- **Avg test duration:** 11.2s — slowest: `avm2_parent_child_static_text` (32.5s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.6s — slowest: `draw_to_bitmap_data_unconfigured` (22.1s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m03s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.1s — slowest: `lzma_length_too_long` (24.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m08s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 15.6s — slowest: `auto_size/return` (32.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m30s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 15.9s — slowest: `frame_script_cleanup2` (24.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 30m14s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.0s — slowest: `definefont4` (84.2s)
