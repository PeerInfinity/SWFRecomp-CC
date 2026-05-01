# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `2e50fd7e454e`  
**Date:** 2026-05-01 23:05 UTC  
**Total duration:** 2h05m27s

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
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,385** | **119,930** | **96.2%** |

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
- **Duration:** 57m47s across 30 shards
- **Lines:** 95,603/95,859 matching (99.7%)
- **Avg test duration:** 5.3s — slowest: `form_loader_encoding_1` (19.8s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 16m15s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 5.1s — slowest: `Math-v5` (29.3s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 25m11s across 30 shards
- **Lines:** 2,825/4,577 matching (61.7%)
- **Avg test duration:** 14.8s — slowest: `NetStream-SquareTest` (27.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.0s — slowest: `enum` (18.4s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m10s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 15.6s — slowest: `swf4opcode` (19.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m08s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.1s — slowest: `mixed-bytecode-as2` (18.3s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 13m16s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.6s — slowest: `invalidClipDepth` (19.7s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m31s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.6s — slowest: `duplicateMovieClip/dontremove` (16.1s)
