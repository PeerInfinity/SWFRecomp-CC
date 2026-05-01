# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `900ae800db6b`  
**Date:** 2026-05-01 20:01 UTC  
**Total duration:** 1h54m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 603 | 99.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 122 | 190 | 64.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 16 | 18 | 88.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **920** | **1075** | **85.6%** | |

*42 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,486 | 95,666 | 99.8% |
| from_gnash/actionscript.all | 15,243 | 16,957 | 89.9% |
| from_gnash/misc-ming.all | 2,815 | 4,577 | 61.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,257** | **119,737** | **96.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 1 | 4 |
| from_gnash/actionscript.all | 5 | 63 |
| from_gnash/misc-ming.all | 27 | 14 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 7 | 3 |
| from_gnash/misc-swfmill.all | 1 | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **66** | **89** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
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

- **Pass:** 598/603 (99.2%)
- **Ignored:** 40 tests
- **Duration:** 53m54s across 30 shards
- **Lines:** 95,486/95,666 matching (99.8%)
- **Avg test duration:** 4.9s — slowest: `has_own_property` (19.7s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 11m37s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 3.6s — slowest: `LocalConnection-v5` (18.0s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 23m32s across 30 shards
- **Lines:** 2,815/4,577 matching (61.5%)
- **Avg test duration:** 13.8s — slowest: `matrix_test` (20.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.5s — slowest: `TextFieldTest` (17.6s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m02s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 15.1s — slowest: `movieclip_destruction_test1` (17.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 16/18 (88.9%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.2s — slowest: `initaction_in_definesprite` (17.9s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m31s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.1s — slowest: `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` (18.5s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m55s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.1s — slowest: `duplicateMovieClip/dontremove` (17.4s)
