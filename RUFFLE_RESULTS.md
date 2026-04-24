# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `d4c3b8d81d50`  
**Date:** 2026-04-24 17:11 UTC  
**Total duration:** 1h49m38s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 37 | 102 | 36.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **882** | **1115** | **79.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,735 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,751 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,277 | 4,541 | 50.1% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 239 | 499 | 47.9% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,399** | **138,795** | **89.6%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 35 |
| from_gnash/actionscript.all | - | 28 |
| from_gnash/misc-ming.all | 1 | 54 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 27 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **156** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | LoadVars-v6 | 96% |
| from_gnash/actionscript.all | LoadVars-v7 | 96% |
| from_gnash/actionscript.all | LoadVars-v8 | 96% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/actionscript.all | Selection-v6 | 94% |
| from_gnash/actionscript.all | Selection-v7 | 94% |
| from_gnash/actionscript.all | Selection-v8 | 94% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-swfc.all | - | - | 4 | - |

*Comparing `032524fc0312` → `d4c3b8d81d50`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 51m20s across 30 shards
- **Lines:** 105,735/114,749 matching (92.1%)
- **Avg test duration:** 4.7s — slowest: `tab_ordering_custom_m1` (20.1s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 11m12s across 30 shards
- **Lines:** 14,751/16,957 matching (87.0%)
- **Avg test duration:** 3.5s — slowest: `case-v7` (19.2s)

### from_gnash/misc-ming.all

- **Pass:** 37/102 (36.3%)
- **Duration:** 22m41s across 30 shards
- **Lines:** 2,277/4,541 matching (50.1%)
- **Avg test duration:** 13.3s — slowest: `register_class/RegisterClassTest4` (20.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m36s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 10.7s — slowest: `enum` (17.2s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 3m49s across 30 shards
- **Lines:** 239/499 matching (47.9%)
- **Avg test duration:** 14.3s — slowest: `sound` (17.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m55s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 16.4s — slowest: `tags_after_last_showframe` (18.4s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 12m23s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 8.0s — slowest: `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` (19.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.0s — slowest: `nested-button` (18.6s)
