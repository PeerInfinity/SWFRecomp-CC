# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `8fb3a99ec4dd`  
**Date:** 2026-04-27 02:49 UTC  
**Total duration:** 10m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 592 | 600 | 98.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 46 | 102 | 45.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **887** | **1072** | **82.7%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,874 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,757 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,473 | 4,541 | 54.5% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 262 | 499 | 52.5% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **113,761** | **119,128** | **95.5%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | - | 4 | 4 |
| from_gnash/actionscript.all | - | 22 | 55 |
| from_gnash/misc-ming.all | 1 | 43 | 12 |
| from_gnash/misc-mtasc.all | - | 1 | 1 |
| from_gnash/misc-swfc.all | - | 8 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | - | 26 | 2 |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **106** | **78** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | tell_target_invalid_swf6 | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| avm1 | attach_movie | 93% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 83% |
| from_gnash/actionscript.all | HitTest-v8 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| avm1 | default_names | 81% |
| from_gnash/actionscript.all | HitTest-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v7 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 592/600 (98.7%)
- **Ignored:** 41 tests
- **Duration:** 5m34s across 30 shards
- **Lines:** 94,874/95,093 matching (99.8%)
- **Avg test duration:** 0.5s — slowest: `movieclip_invalid_get_bounds_6` (25.0s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 14,757/16,957 matching (87.0%)
- **Avg test duration:** 0.7s — slowest: `BitmapData-v8` (1.1s)

### from_gnash/misc-ming.all

- **Pass:** 46/102 (45.1%)
- **Duration:** 1m03s across 30 shards
- **Lines:** 2,473/4,541 matching (54.5%)
- **Avg test duration:** 0.6s — slowest: `matrix_test` (3.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 4s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 0.4s — slowest: `levels` (0.4s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 8s across 30 shards
- **Lines:** 262/499 matching (52.5%)
- **Avg test duration:** 0.4s — slowest: `action_execution_order_test10` (0.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 8s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 0.4s — slowest: `trace-as2/root_onload` (0.4s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 43s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 0.4s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (0.7s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 20s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.4s — slowest: `setinterval` (0.7s)
