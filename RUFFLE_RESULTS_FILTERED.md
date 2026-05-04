# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `71eb98ea5b54`  
**Date:** 2026-05-04 18:24 UTC  
**Total duration:** 2h12m21s

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
| from_gnash/misc-swfc.all | 332 | 492 | 67.5% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,603** | **119,923** | **96.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 2 | 4 |
| from_gnash/actionscript.all | 2 | 62 |
| from_gnash/misc-ming.all | 21 | 18 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 4 | 4 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **54** | **93** |

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
- **Duration:** 1h00m28s across 30 shards
- **Lines:** 95,636/95,859 matching (99.8%)
- **Avg test duration:** 5.5s — slowest: `bitmap_data_thorough/copyPixels` (20.5s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 17m41s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 5.5s — slowest: `String-v8` (36.6s)

### from_gnash/misc-ming.all

- **Pass:** 63/102 (61.8%)
- **Duration:** 26m42s across 30 shards
- **Lines:** 2,859/4,577 matching (62.5%)
- **Avg test duration:** 15.7s — slowest: `NetStream-SquareTest` (30.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.4s — slowest: `function_test` (19.2s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 4m15s across 30 shards
- **Lines:** 332/492 matching (67.5%)
- **Avg test duration:** 15.8s — slowest: `movieclip_destruction_test1` (19.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m17s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.6s — slowest: `dict_cross` (19.7s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m01s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.1s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (21.4s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m44s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.8s — slowest: `duplicateMovieClip/dontremove` (19.0s)
