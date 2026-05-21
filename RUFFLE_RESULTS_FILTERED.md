# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `4cd8df042cbd`  
**Date:** 2026-05-21 00:20 UTC  
**Total duration:** 2h45m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 620 | 96.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 128 | 240 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 64 | 108 | 59.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **943** | **1134** | **83.2%** | |

*67 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,195 | 96,675 | 99.5% |
| from_gnash/actionscript.all | 28,640 | 32,100 | 89.2% |
| from_gnash/misc-ming.all | 3,985 | 5,179 | 76.9% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **130,632** | **135,929** | **96.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 14 | 6 |
| from_gnash/actionscript.all | 25 | 87 |
| from_gnash/misc-ming.all | 18 | 26 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 7 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **59** | **132** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | getvariable-v7 | 95% |
| from_gnash/actionscript.all | getvariable-v8 | 95% |
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | Object-v7 | 90% |
| from_gnash/actionscript.all | Object-v8 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| avm1 | string_paths_other | 89% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test9 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Object-v6 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| avm1 | sound_getters | 84% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 83% |
| from_gnash/actionscript.all | MovieClip-v8 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/620 (96.8%)
- **Ignored:** 41 tests
- **Duration:** 1h08m33s across 30 shards
- **Lines:** 96,195/96,675 matching (99.5%)
- **Avg test duration:** 6.2s — slowest: `movieclip_invalid_get_bounds_6` (27.6s)

### from_gnash/actionscript.all

- **Pass:** 128/240 (53.3%)
- **Ignored:** 3 tests
- **Duration:** 33m47s across 30 shards
- **Lines:** 28,640/32,100 matching (89.2%)
- **Avg test duration:** 8.3s — slowest: `MovieClip-v8` (55.1s)

### from_gnash/misc-ming.all

- **Pass:** 64/108 (59.3%)
- **Ignored:** 2 tests
- **Duration:** 32m56s across 30 shards
- **Lines:** 3,985/5,179 matching (76.9%)
- **Avg test duration:** 17.8s — slowest: `matrix_test` (81.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m22s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.8s — slowest: `enum` (22.7s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 5m07s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 15.8s — slowest: `movieclip_destruction_test1` (23.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m27s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.3s — slowest: `background` (22.2s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m40s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.5s — slowest: `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` (22.1s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m59s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.9s — slowest: `label` (21.7s)
