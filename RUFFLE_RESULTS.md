# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c6be20a88416`  
**Date:** 2026-10-03 17:31 UTC  
**Total duration:** 10h19m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 703 | 738 | 95.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1222 | 1283 | 95.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 213 | 229 | 93.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 101 | 101 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4266** | **4592** | **92.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 120,399 | 132,402 | 90.9% |
| avm2 | 155,241 | 157,885 | 98.3% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,558 | 38,791 | 78.8% |
| from_gnash/misc-ming.all | 4,227 | 5,248 | 80.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,395 | 2,484 | 96.4% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 838 | 838 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **402,646** | **427,518** | **94.2%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 15 | - |
| avm2 | 20 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 8 | - |
| from_gnash/misc-ming.all | 10 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 4 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | - |
| visual | - | - |
| **Total** | **69** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 2 | - | 751 |
| from_gnash/actionscript.all | - | 1 | - | - |
| from_shumway | - | 1 | - | 1 |

**avm1 — newly failing:** `point`, `rectangle`

**from_shumway — newly failing:** `as3-loader/bug1157243/empty`

*Comparing `7755698f8329` → `c6be20a88416`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.1s — slowest: `g711_event_alaw` (23.2s)

### avm1

- **Pass:** 703/738 (95.3%)
- **Duration:** 54m04s across 30 shards
- **Lines:** 120,399/132,402 matching (90.9%)
- **Avg test duration:** 4.3s — slowest: `netstream_play_flv_screen` (29.6s)

### avm2

- **Pass:** 1222/1283 (95.2%)
- **Duration:** 3h24m48s across 30 shards
- **Lines:** 155,241/157,885 matching (98.3%)
- **Avg test duration:** 9.5s — slowest: `away3d_advanced_shallow_water_demo` (101.2s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m48s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 21.0s — slowest: `device_font_list` (30.2s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h03m40s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 6.9s — slowest: `ecma3/Statements/eregress_74474_003` (56.5s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 24m47s across 30 shards
- **Lines:** 30,558/38,791 matching (78.8%)
- **Avg test duration:** 6.1s — slowest: `MovieClip-v8` (42.2s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 27m09s across 30 shards
- **Lines:** 4,227/5,248 matching (80.5%)
- **Avg test duration:** 14.6s — slowest: `matrix_test` (79.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m02s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.5s — slowest: `exception` (24.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m27s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 16.3s — slowest: `swf4opcode` (24.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m29s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.4s — slowest: `missing_bitmap` (24.5s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 41m57s across 30 shards
- **Lines:** 2,395/2,484 matching (96.4%)
- **Avg test duration:** 10.9s — slowest: `acid/acid-large` (79.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m01s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.5s — slowest: `label` (21.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 39s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 12.8s — slowest: `empty_url` (23.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 6.4s — slowest: `avm1_sprite_sc_ignored` (21.9s)

### regression

- **Pass:** 101/101 (100%)
- **Duration:** 21m37s across 30 shards
- **Lines:** 838/838 matching (100%)
- **Avg test duration:** 12.8s — slowest: `avm2_typed_value_ops` (47.0s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.5s — slowest: `sampler_odd_size` (11.2s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 22s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 3.1s — slowest: `lzma_length_too_long` (12.7s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m34s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 19.4s — slowest: `auto_size/height` (29.6s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m01s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 14.2s — slowest: `frame_script_cleanup` (29.5s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 30m20s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.3s — slowest: `definefont4` (121.7s)
