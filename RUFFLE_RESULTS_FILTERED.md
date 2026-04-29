# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `3363ff458d52`  
**Date:** 2026-04-29 01:46 UTC  
**Total duration:** 2h17m46s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 600 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 53 | 102 | 52.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **898** | **1072** | **83.8%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,763 | 16,957 | 87.1% |
| from_gnash/misc-ming.all | 2,683 | 4,541 | 59.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 281 | 499 | 56.3% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **114,044** | **119,128** | **95.7%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | - | - | 4 |
| from_gnash/actionscript.all | - | 22 | 55 |
| from_gnash/misc-ming.all | 1 | 35 | 13 |
| from_gnash/misc-mtasc.all | - | - | 2 |
| from_gnash/misc-swfc.all | - | 8 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | - | 26 | 2 |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **93** | **80** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/actionscript.all | HitTest-v8 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v7 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/600 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 1h01m19s across 30 shards
- **Lines:** 94,915/95,093 matching (99.8%)
- **Avg test duration:** 5.6s — slowest: `movieclip_invalid_get_bounds_7` (26.5s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 21m01s across 30 shards
- **Lines:** 14,763/16,957 matching (87.1%)
- **Avg test duration:** 6.6s — slowest: `String-v8` (31.7s)

### from_gnash/misc-ming.all

- **Pass:** 53/102 (52.0%)
- **Duration:** 28m09s across 30 shards
- **Lines:** 2,683/4,541 matching (59.1%)
- **Avg test duration:** 16.5s — slowest: `matrix_test` (98.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.7s — slowest: `exception` (18.6s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4m18s across 30 shards
- **Lines:** 281/499 matching (56.3%)
- **Avg test duration:** 16.1s — slowest: `action_execution_order_test10` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m13s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.4s — slowest: `zeroframe_definesprite` (18.2s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 13m46s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 8.9s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (19.8s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 2m02s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.2s — slowest: `nested-button` (17.7s)
