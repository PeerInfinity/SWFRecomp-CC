# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `b2070f86f917`  
**Date:** 2026-05-02 16:20 UTC  
**Total duration:** 1h52m10s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 599 | 607 | 98.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 62 | 102 | 60.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **925** | **1079** | **85.7%** | |

*42 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,603 | 95,859 | 99.7% |
| from_gnash/actionscript.all | 15,347 | 16,957 | 90.5% |
| from_gnash/misc-ming.all | 2,828 | 4,577 | 61.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 331 | 499 | 66.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,515** | **119,930** | **96.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 4 | 4 |
| from_gnash/actionscript.all | 6 | 60 |
| from_gnash/misc-ming.all | 25 | 15 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 7 | 3 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **67** | **87** |

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
| from_gnash/actionscript.all | MovieClip-v5 | 86% |
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
- **Duration:** 53m07s across 30 shards
- **Lines:** 95,603/95,859 matching (99.7%)
- **Avg test duration:** 4.8s — slowest: `lessthan` (20.8s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 11m19s across 30 shards
- **Lines:** 15,347/16,957 matching (90.5%)
- **Avg test duration:** 3.5s — slowest: `NetStream-v7` (19.8s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 22m51s across 30 shards
- **Lines:** 2,828/4,577 matching (61.8%)
- **Avg test duration:** 13.4s — slowest: `matrix_test` (21.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.5s — slowest: `hello` (17.5s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 3m57s across 30 shards
- **Lines:** 331/499 matching (66.3%)
- **Avg test duration:** 14.8s — slowest: `submoviegetvar` (20.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m04s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 16.8s — slowest: `trace-as2/shortstack` (20.0s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m31s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.1s — slowest: `avm1/mouse-transparency` (18.8s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m24s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.4s — slowest: `duplicateMovieClip/dontremove` (17.7s)
