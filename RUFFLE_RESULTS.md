# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `3a04009d40fa`  
**Date:** 2026-05-24 21:21 UTC  
**Total duration:** 2h13m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 614 | 671 | 91.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 67 | 110 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **962** | **1211** | **79.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,824 | 116,386 | 91.8% |
| from_gnash/actionscript.all | 29,560 | 38,787 | 76.2% |
| from_gnash/misc-ming.all | 4,035 | 5,239 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,518** | **163,062** | **87.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 46 |
| from_gnash/actionscript.all | 20 |
| from_gnash/misc-ming.all | 15 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **101** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| avm1 | with | 96% |
| from_gnash/actionscript.all | getvariable-v7 | 95% |
| from_gnash/actionscript.all | getvariable-v8 | 95% |
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v7 | 89% |
| from_gnash/actionscript.all | MovieClip-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 6 | - |

*Comparing `b19f307488e3` → `3a04009d40fa`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 614/671 (91.5%)
- **Duration:** 1h01m15s across 30 shards
- **Lines:** 106,824/116,386 matching (91.8%)
- **Avg test duration:** 5.4s — slowest: `bitxor` (22.1s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 16m57s across 30 shards
- **Lines:** 29,560/38,787 matching (76.2%)
- **Avg test duration:** 4.1s — slowest: `Global-v6` (26.2s)

### from_gnash/misc-ming.all

- **Pass:** 67/110 (60.9%)
- **Duration:** 27m41s across 30 shards
- **Lines:** 4,035/5,239 matching (77.0%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (28.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.4s — slowest: `hello` (19.4s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m34s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 14.4s — slowest: `gotoFrameLabelAsFunction` (19.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m06s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.3s — slowest: `func_dict` (19.5s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m31s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.8s — slowest: `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` (19.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.2s — slowest: `text-bind` (19.6s)
