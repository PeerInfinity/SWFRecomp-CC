# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `d018fcc20f02`  
**Date:** 2026-05-25 03:01 UTC  
**Total duration:** 45m59s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 612 | 630 | 97.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 128 | 237 | 54.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 66 | 108 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **957** | **1141** | **83.9%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,353 | 97,257 | 99.1% |
| from_gnash/actionscript.all | 29,216 | 31,914 | 91.5% |
| from_gnash/misc-ming.all | 4,008 | 5,179 | 77.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **131,389** | **136,325** | **96.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 12 | 6 |
| from_gnash/actionscript.all | 14 | 95 |
| from_gnash/misc-ming.all | 14 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 7 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **42** | **142** |

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
- **Duration:** 18m53s across 30 shards
- **Lines:** 96,353/97,257 matching (99.1%)
- **Avg test duration:** 1.7s — slowest: `unloadmovienum` (27.1s)

### from_gnash/actionscript.all

- **Pass:** 128/237 (54.0%)
- **Ignored:** 6 tests
- **Duration:** 8m54s across 30 shards
- **Lines:** 29,216/31,914 matching (91.5%)
- **Avg test duration:** 2.1s — slowest: `ops-v5` (28.7s)

### from_gnash/misc-ming.all

- **Pass:** 66/108 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 9m51s across 30 shards
- **Lines:** 4,008/5,179 matching (77.4%)
- **Avg test duration:** 5.2s — slowest: `NetStream-SquareTest` (30.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 4.7s — slowest: `TextFieldTest` (20.7s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 1m09s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 4.0s — slowest: `action_execution_order_test10` (21.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 4.1s — slowest: `afunc_dict` (20.2s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 4m19s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 1.9s — slowest: `timeline/timeline_as2_1` (20.2s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 43s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.9s — slowest: `duplicateMovieClip/dontremove` (20.5s)
