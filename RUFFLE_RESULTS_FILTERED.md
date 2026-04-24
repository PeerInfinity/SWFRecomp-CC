# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `d4c3b8d81d50`  
**Date:** 2026-04-24 17:11 UTC  
**Total duration:** 1h49m38s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 600 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 37 | 102 | 36.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **881** | **1072** | **82.2%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,751 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,277 | 4,541 | 50.1% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 239 | 499 | 47.9% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **113,576** | **119,128** | **95.3%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | - | - | 4 |
| from_gnash/actionscript.all | - | 28 | 49 |
| from_gnash/misc-ming.all | 1 | 54 | 10 |
| from_gnash/misc-mtasc.all | - | 1 | 1 |
| from_gnash/misc-swfc.all | - | 8 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | - | 27 | 2 |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **120** | **70** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
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
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/600 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 51m20s across 30 shards
- **Lines:** 94,915/95,093 matching (99.8%)
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

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m38s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.8s — slowest: `nested-button` (18.6s)
