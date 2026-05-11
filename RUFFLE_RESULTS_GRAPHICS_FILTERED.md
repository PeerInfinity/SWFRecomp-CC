# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `ce31587cf186`  
**Date:** 2026-05-11 20:09 UTC  
**Total duration:** 18m02s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 601 | 611 | 98.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 63 | 100 | 63.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 72 | 76 | 94.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **938** | **1064** | **88.2%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,703 | 95,887 | 99.8% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,092 | 4,517 | 68.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 381 | 492 | 77.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,930** | **119,252** | **97.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault | timeout |
|-------|-----------------:|----------------:|---------------:|----------:|---------:|
| avm1 | 3 | 6 | - | - | 1 |
| from_gnash/actionscript.all | 1 | 61 | 3 | - | - |
| from_gnash/misc-ming.all | 13 | 22 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | 2 | - | - | - |
| from_gnash/misc-swfc.all | 1 | 6 | - | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - | - |
| from_shumway | 1 | 3 | - | - | - |
| from_shumway/avm1 | - | - | - | - | - |
| **Total** | **19** | **101** | **3** | **2** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | netstream_seek_flv | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | sound | 99% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 601/611 (98.4%)
- **Ignored:** 40 tests
- **Duration:** 10m42s across 30 shards
- **Lines:** 95,703/95,887 matching (99.8%)
- **Avg test duration:** 0.9s — slowest: `timeout` (30.6s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 0.9s — slowest: `Selection-v6` (1.9s)

### from_gnash/misc-ming.all

- **Pass:** 63/100 (63.0%)
- **Ignored:** 2 tests
- **Duration:** 1m45s across 30 shards
- **Lines:** 3,092/4,517 matching (68.5%)
- **Avg test duration:** 1.0s — slowest: `matrix_test` (5.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.1s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 14s across 30 shards
- **Lines:** 381/492 matching (77.4%)
- **Avg test duration:** 0.8s — slowest: `action_execution_order_test10` (1.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 16s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.8s — slowest: `zeroframe_definesprite` (1.4s)

### from_shumway

- **Pass:** 72/76 (94.7%)
- **Ignored:** 16 tests
- **Duration:** 1m18s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 0.8s — slowest: `timeline/timeline_as2_3` (1.0s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 39s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.8s — slowest: `bitmapdata/loadBitmap` (0.9s)
