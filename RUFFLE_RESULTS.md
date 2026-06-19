# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8889d42798ef`  
**Date:** 2026-06-19 02:30 UTC  
**Total duration:** 2h50m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 625 | 701 | 89.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 10 | 20 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **983** | **1243** | **79.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 114,638 | 130,944 | 87.5% |
| from_gnash/actionscript.all | 30,048 | 38,791 | 77.5% |
| from_gnash/misc-ming.all | 4,042 | 5,248 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **150,841** | **177,656** | **84.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 57 | 4 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 15 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **105** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 85% |
| from_gnash/actionscript.all | TextField-v8 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 24 | - |

*Comparing `d5e320f78aa9` → `8889d42798ef`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 625/701 (89.2%)
- **Duration:** 1h12m10s across 30 shards
- **Lines:** 114,638/130,944 matching (87.5%)
- **Avg test duration:** 6.1s — slowest: `movieclip_invalid_get_bounds_7` (26.0s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 33m59s across 30 shards
- **Lines:** 30,048/38,791 matching (77.5%)
- **Avg test duration:** 8.3s — slowest: `MovieClip-v8` (66.8s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 32m59s across 30 shards
- **Lines:** 4,042/5,248 matching (77.0%)
- **Avg test duration:** 17.8s — slowest: `matrix_test` (99.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.1s — slowest: `implementsOpTest` (20.8s)

### from_gnash/misc-swfc.all

- **Pass:** 10/20 (50.0%)
- **Duration:** 5m42s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 17.1s — slowest: `movieclip_destruction_test1` (22.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m21s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.0s — slowest: `trace-as2/root_onload` (20.8s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m46s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.9s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (23.0s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m43s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.4s — slowest: `label` (20.2s)
