# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `7bef032ea24d`  
**Date:** 2026-05-13 00:24 UTC  
**Total duration:** 2h39m31s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 611 | 98.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 100 | 65.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **944** | **1064** | **88.7%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,707 | 95,887 | 99.8% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,103 | 4,517 | 68.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 381 | 492 | 77.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,945** | **119,252** | **97.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault |
|-------|-----------------:|----------------:|---------------:|----------:|
| avm1 | 1 | 6 | - | - |
| from_gnash/actionscript.all | 1 | 61 | 3 | - |
| from_gnash/misc-ming.all | 11 | 22 | - | 2 |
| from_gnash/misc-mtasc.all | - | 2 | - | - |
| from_gnash/misc-swfc.all | 1 | 6 | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - |
| from_shumway | - | 3 | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **14** | **101** | **3** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 604/611 (98.9%)
- **Ignored:** 40 tests
- **Duration:** 1h13m35s across 30 shards
- **Lines:** 95,707/95,887 matching (99.8%)
- **Avg test duration:** 6.7s — slowest: `equals2_swf6` (27.7s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 23m40s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 7.4s — slowest: `Math-v5` (33.6s)

### from_gnash/misc-ming.all

- **Pass:** 65/100 (65.0%)
- **Ignored:** 2 tests
- **Duration:** 31m09s across 30 shards
- **Lines:** 3,103/4,517 matching (68.7%)
- **Avg test duration:** 18.2s — slowest: `matrix_test` (103.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m22s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.8s — slowest: `hello` (20.4s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4m43s across 30 shards
- **Lines:** 381/492 matching (77.4%)
- **Avg test duration:** 17.5s — slowest: `registerclass_test3` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m49s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 19.3s — slowest: `missing_bitmap` (21.5s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 15m48s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 8.2s — slowest: `button3` (21.4s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 2m23s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.6s — slowest: `text-bind` (21.2s)
