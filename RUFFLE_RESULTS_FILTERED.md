# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `d48ebaec6db3`  
**Date:** 2026-05-01 21:45 UTC  
**Total duration:** 1h02m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 599 | 607 | 98.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 122 | 190 | 64.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **922** | **1079** | **85.4%** | |

*42 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,603 | 95,859 | 99.7% |
| from_gnash/actionscript.all | 15,243 | 16,957 | 89.9% |
| from_gnash/misc-ming.all | 2,815 | 4,577 | 61.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,375** | **119,930** | **96.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 4 | 4 |
| from_gnash/actionscript.all | 8 | 60 |
| from_gnash/misc-ming.all | 27 | 14 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 7 | 3 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **71** | **86** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/actionscript.all | Global-v7 | 96% |
| from_gnash/actionscript.all | Global-v8 | 96% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
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
- **Duration:** 27m13s across 30 shards
- **Lines:** 95,603/95,859 matching (99.7%)
- **Avg test duration:** 2.4s — slowest: `textfield_variable` (20.8s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 5m58s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 1.8s — slowest: `array-v5` (26.6s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 12m51s across 30 shards
- **Lines:** 2,815/4,577 matching (61.5%)
- **Avg test duration:** 7.5s — slowest: `masks_test` (28.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 4.6s — slowest: `TextFieldTest` (18.1s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 1m57s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 7.3s — slowest: `movieclip_destruction_test4` (19.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 2m43s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 9.0s — slowest: `initaction_in_definesprite` (19.0s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 9m45s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 6.3s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (20.2s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m07s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.0s — slowest: `label` (18.6s)
