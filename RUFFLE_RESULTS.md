# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `61229899ae49`  
**Date:** 2026-04-30 20:27 UTC  
**Total duration:** 2h10m32s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 642 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 118 | 190 | 62.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 58 | 102 | 56.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **910** | **1116** | **81.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,873 | 114,769 | 92.2% |
| from_gnash/actionscript.all | 15,065 | 16,957 | 88.8% |
| from_gnash/misc-ming.all | 2,781 | 4,577 | 60.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 304 | 499 | 60.9% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,428** | **138,851** | **90.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 12 |
| from_gnash/misc-ming.all | 31 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 8 |
| from_gnash/misc-swfmill.all | 2 |
| from_shumway | 26 |
| from_shumway/avm1 | 1 |
| **Total** | **115** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 5 | - |

**from_gnash/misc-ming.all — newly passing:** `DepthLimitsTest`

*Comparing `f62d59c41f02` → `61229899ae49`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 598/642 (93.1%)
- **Duration:** 1h00m18s across 30 shards
- **Lines:** 105,873/114,769 matching (92.2%)
- **Avg test duration:** 5.6s — slowest: `movieclip_invalid_get_bounds_7` (25.3s)

### from_gnash/actionscript.all

- **Pass:** 118/190 (62.1%)
- **Duration:** 17m28s across 30 shards
- **Lines:** 15,065/16,957 matching (88.8%)
- **Avg test duration:** 5.5s — slowest: `MovieClip-v5` (30.5s)

### from_gnash/misc-ming.all

- **Pass:** 58/102 (56.9%)
- **Duration:** 25m59s across 30 shards
- **Lines:** 2,781/4,577 matching (60.8%)
- **Avg test duration:** 15.2s — slowest: `masks_test` (33.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.8s — slowest: `TextFieldTest` (18.7s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4m09s across 30 shards
- **Lines:** 304/499 matching (60.9%)
- **Avg test duration:** 15.5s — slowest: `action_execution_order_test10` (20.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.2s — slowest: `trace-as2/this` (18.7s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 13m23s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 8.7s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (21.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.8s — slowest: `rollover` (17.9s)
