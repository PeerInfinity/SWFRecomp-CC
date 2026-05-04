# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `5eeacc250d10`  
**Date:** 2026-05-04 20:04 UTC  
**Total duration:** 1h55m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 601 | 607 | 99.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 63 | 102 | 61.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 7 | 15 | 46.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **931** | **1078** | **86.4%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,636 | 95,859 | 99.8% |
| from_gnash/actionscript.all | 15,370 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 2,859 | 4,577 | 62.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 351 | 492 | 71.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,622** | **119,923** | **96.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 2 | 4 |
| from_gnash/actionscript.all | 2 | 62 |
| from_gnash/misc-ming.all | 21 | 18 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **53** | **94** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 85% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 601/607 (99.0%)
- **Ignored:** 40 tests
- **Duration:** 54m07s across 30 shards
- **Lines:** 95,636/95,859 matching (99.8%)
- **Avg test duration:** 4.9s — slowest: `bitmapdata_applyfilter_colormatrix` (19.2s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 11m42s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 3.6s — slowest: `Random-v7` (18.2s)

### from_gnash/misc-ming.all

- **Pass:** 63/102 (61.8%)
- **Duration:** 23m43s across 30 shards
- **Lines:** 2,859/4,577 matching (62.5%)
- **Avg test duration:** 13.9s — slowest: `matrix_test` (22.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m00s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.4s — slowest: `function_test` (18.0s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 4m01s across 30 shards
- **Lines:** 351/492 matching (71.3%)
- **Avg test duration:** 14.9s — slowest: `gotoFrameLabelAsFunction` (17.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.2s — slowest: `trace-as2/this` (18.4s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m55s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.4s — slowest: `gradientTransform` (18.2s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m25s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.4s — slowest: `duplicateMovieClip/dontremove` (18.6s)
