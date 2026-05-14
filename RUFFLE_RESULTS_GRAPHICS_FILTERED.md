# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `e12de2387ba2`  
**Date:** 2026-05-14 04:24 UTC  
**Total duration:** 2h14m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 603 | 613 | 98.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 100 | 65.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **942** | **1066** | **88.4%** | |

*62 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,052 | 96,454 | 99.6% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,103 | 4,517 | 68.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 381 | 492 | 77.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **116,290** | **119,819** | **97.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault |
|-------|-----------------:|----------------:|---------------:|----------:|
| avm1 | 4 | 6 | - | - |
| from_gnash/actionscript.all | 1 | 61 | 4 | - |
| from_gnash/misc-ming.all | 11 | 22 | - | 2 |
| from_gnash/misc-mtasc.all | - | 2 | - | - |
| from_gnash/misc-swfc.all | 1 | 6 | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - |
| from_shumway | - | 3 | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **17** | **101** | **4** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 603/613 (98.4%)
- **Ignored:** 41 tests
- **Duration:** 1h05m06s across 30 shards
- **Lines:** 96,052/96,454 matching (99.6%)
- **Avg test duration:** 5.9s — slowest: `timeout` (23.2s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 14m12s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 4.4s — slowest: `targetPath-v5` (20.9s)

### from_gnash/misc-ming.all

- **Pass:** 65/100 (65.0%)
- **Ignored:** 2 tests
- **Duration:** 26m18s across 30 shards
- **Lines:** 3,103/4,517 matching (68.7%)
- **Avg test duration:** 15.3s — slowest: `matrix_test` (23.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.0s — slowest: `function_test` (19.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4m28s across 30 shards
- **Lines:** 381/492 matching (77.4%)
- **Avg test duration:** 16.5s — slowest: `gotoFrameLabelAsFunction` (20.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m38s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.8s — slowest: `dict_callframe` (19.9s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m23s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.5s — slowest: `timeline/timeline_as2_1` (20.7s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 2m13s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.5s — slowest: `duplicateMovieClip/dontremove` (19.9s)
