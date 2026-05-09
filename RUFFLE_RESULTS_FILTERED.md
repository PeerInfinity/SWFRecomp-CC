# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `b1237cc26e00`  
**Date:** 2026-05-09 21:07 UTC  
**Total duration:** 2h25m42s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 608 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 66 | 100 | 66.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **946** | **1061** | **89.2%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,697 | 95,875 | 99.8% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,746 | 4,517 | 82.9% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 381 | 492 | 77.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **116,578** | **119,240** | **97.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | - | 4 |
| from_gnash/actionscript.all | 1 | 63 |
| from_gnash/misc-ming.all | 10 | 24 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 1 | 6 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **12** | **103** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/608 (99.3%)
- **Ignored:** 40 tests
- **Duration:** 1h05m51s across 30 shards
- **Lines:** 95,697/95,875 matching (99.8%)
- **Avg test duration:** 6.0s — slowest: `movieclip_invalid_get_bounds_6` (25.1s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 21m45s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 6.8s — slowest: `String-v8` (32.9s)

### from_gnash/misc-ming.all

- **Pass:** 66/100 (66.0%)
- **Ignored:** 2 tests
- **Duration:** 29m20s across 30 shards
- **Lines:** 3,746/4,517 matching (82.9%)
- **Avg test duration:** 17.2s — slowest: `matrix_test` (93.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m19s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.4s — slowest: `function_test` (20.4s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4m28s across 30 shards
- **Lines:** 381/492 matching (77.4%)
- **Avg test duration:** 16.6s — slowest: `swf4opcode` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m26s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.1s — slowest: `trace-as2/this` (19.4s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m33s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.3s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (20.4s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m56s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.1s — slowest: `text-bind` (18.8s)
