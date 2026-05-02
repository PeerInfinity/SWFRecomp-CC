# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `8e7fae4eae64`  
**Date:** 2026-05-02 02:23 UTC  
**Total duration:** 4m42s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 599 | 607 | 98.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 122 | 190 | 64.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 62 | 102 | 60.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **923** | **1079** | **85.5%** | |

*42 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,603 | 95,859 | 99.7% |
| from_gnash/actionscript.all | 15,243 | 16,957 | 89.9% |
| from_gnash/misc-ming.all | 2,825 | 4,577 | 61.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 331 | 499 | 66.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,408** | **119,930** | **96.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 4 | 4 |
| from_gnash/actionscript.all | 8 | 60 |
| from_gnash/misc-ming.all | 26 | 14 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 7 | 3 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **70** | **86** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/actionscript.all | Global-v7 | 96% |
| from_gnash/actionscript.all | Global-v8 | 96% |
| from_gnash/misc-swfc.all | swf4opcode | 95% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 91% |
| from_gnash/misc-ming.all | matrix_test | 85% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 599/607 (98.7%)
- **Ignored:** 40 tests
- **Duration:** 2m36s across 30 shards
- **Lines:** 95,603/95,859 matching (99.7%)
- **Avg test duration:** 0.2s — slowest: `edittext_newline_stripping` (6.7s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 52s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 0.2s — slowest: `ContextMenu-v7` (0.4s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 33s across 30 shards
- **Lines:** 2,825/4,577 matching (61.7%)
- **Avg test duration:** 0.3s — slowest: `matrix_test` (4.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.2s — slowest: `hello` (0.4s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4s across 30 shards
- **Lines:** 331/499 matching (66.3%)
- **Avg test duration:** 0.2s — slowest: `action_execution_order_test10` (0.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 4s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.1s — slowest: `missing_bitmap` (0.2s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 22s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 0.2s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (0.7s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 10s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.1s — slowest: `depth` (0.3s)
