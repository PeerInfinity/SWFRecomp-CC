# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `3a04009d40fa`  
**Date:** 2026-05-24 21:21 UTC  
**Total duration:** 2h13m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 612 | 630 | 97.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 128 | 237 | 54.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 67 | 108 | 62.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **958** | **1141** | **84.0%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,353 | 97,257 | 99.1% |
| from_gnash/actionscript.all | 29,216 | 31,914 | 91.5% |
| from_gnash/misc-ming.all | 4,021 | 5,179 | 77.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **131,402** | **136,325** | **96.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 12 | 6 |
| from_gnash/actionscript.all | 14 | 95 |
| from_gnash/misc-ming.all | 13 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 7 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **41** | **142** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| avm1 | with | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v7 | 89% |
| from_gnash/actionscript.all | MovieClip-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 612/630 (97.1%)
- **Ignored:** 41 tests
- **Duration:** 1h01m15s across 30 shards
- **Lines:** 96,353/97,257 matching (99.1%)
- **Avg test duration:** 5.5s — slowest: `bitxor` (22.1s)

### from_gnash/actionscript.all

- **Pass:** 128/237 (54.0%)
- **Ignored:** 6 tests
- **Duration:** 16m57s across 30 shards
- **Lines:** 29,216/31,914 matching (91.5%)
- **Avg test duration:** 4.1s — slowest: `Global-v6` (26.2s)

### from_gnash/misc-ming.all

- **Pass:** 67/108 (62.0%)
- **Ignored:** 2 tests
- **Duration:** 27m41s across 30 shards
- **Lines:** 4,021/5,179 matching (77.6%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (28.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.4s — slowest: `hello` (19.4s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 4m34s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 13.8s — slowest: `gotoFrameLabelAsFunction` (19.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m06s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.3s — slowest: `func_dict` (19.5s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 13m31s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 6.6s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (19.6s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m46s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.1s — slowest: `label` (18.5s)
