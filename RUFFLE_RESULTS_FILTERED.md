# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `78f4e4cc030b`  
**Date:** 2026-05-21 20:31 UTC  
**Total duration:** 2h12m41s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 620 | 97.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 128 | 240 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 65 | 108 | 60.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **946** | **1134** | **83.4%** | |

*67 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,205 | 96,675 | 99.5% |
| from_gnash/actionscript.all | 28,858 | 32,100 | 89.9% |
| from_gnash/misc-ming.all | 3,988 | 5,179 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **130,863** | **135,929** | **96.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 12 | 6 |
| from_gnash/actionscript.all | 21 | 91 |
| from_gnash/misc-ming.all | 17 | 26 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 7 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **52** | **136** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | getvariable-v7 | 95% |
| from_gnash/actionscript.all | getvariable-v8 | 95% |
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v6 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | MovieClip-v7 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | MovieClip-v8 | 85% |
| avm1 | sound_getters | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 602/620 (97.1%)
- **Ignored:** 41 tests
- **Duration:** 59m45s across 30 shards
- **Lines:** 96,205/96,675 matching (99.5%)
- **Avg test duration:** 5.4s — slowest: `lessthan_swf4` (26.1s)

### from_gnash/actionscript.all

- **Pass:** 128/240 (53.3%)
- **Ignored:** 3 tests
- **Duration:** 16m21s across 30 shards
- **Lines:** 28,858/32,100 matching (89.9%)
- **Avg test duration:** 3.9s — slowest: `Boolean-v7` (20.3s)

### from_gnash/misc-ming.all

- **Pass:** 65/108 (60.2%)
- **Ignored:** 2 tests
- **Duration:** 28m00s across 30 shards
- **Lines:** 3,988/5,179 matching (77.0%)
- **Avg test duration:** 15.2s — slowest: `matrix_test` (23.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `exception` (21.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 4m42s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 14.4s — slowest: `movieclip_destruction_test3` (19.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m15s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.7s — slowest: `dict_callframe` (20.5s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 13m50s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.1s — slowest: `avm1/duplicateMovieClip/dontremove` (19.9s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m31s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.1s — slowest: `duplicateMovieClip/dontremove` (19.9s)
