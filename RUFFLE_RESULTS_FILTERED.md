# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `ae6fdcb6f946`  
**Date:** 2026-05-24 03:24 UTC  
**Total duration:** 2h11m32s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 609 | 621 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 128 | 237 | 54.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 67 | 108 | 62.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **955** | **1132** | **84.4%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,255 | 96,691 | 99.5% |
| from_gnash/actionscript.all | 29,174 | 31,914 | 91.4% |
| from_gnash/misc-ming.all | 4,021 | 5,179 | 77.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **131,262** | **135,759** | **96.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 6 | 6 |
| from_gnash/actionscript.all | 10 | 99 |
| from_gnash/misc-ming.all | 13 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 7 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **31** | **146** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v7 | 89% |
| from_gnash/actionscript.all | MovieClip-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 609/621 (98.1%)
- **Ignored:** 41 tests
- **Duration:** 58m40s across 30 shards
- **Lines:** 96,255/96,691 matching (99.5%)
- **Avg test duration:** 5.3s — slowest: `assetnativeaccessor_ids` (21.2s)

### from_gnash/actionscript.all

- **Pass:** 128/237 (54.0%)
- **Ignored:** 6 tests
- **Duration:** 16m48s across 30 shards
- **Lines:** 29,174/31,914 matching (91.4%)
- **Avg test duration:** 4.1s — slowest: `Global-v6` (25.5s)

### from_gnash/misc-ming.all

- **Pass:** 67/108 (62.0%)
- **Ignored:** 2 tests
- **Duration:** 27m58s across 30 shards
- **Lines:** 4,021/5,179 matching (77.6%)
- **Avg test duration:** 15.2s — slowest: `matrix_test` (27.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m07s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.1s — slowest: `hello` (20.1s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 4m38s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 14.1s — slowest: `gotoFrameLabelAsFunction` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m09s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.4s — slowest: `dict_callframe` (19.9s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 13m36s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 6.9s — slowest: `avm1/duplicateMovieClip/dontremove` (20.3s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m31s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.2s — slowest: `label` (19.0s)
