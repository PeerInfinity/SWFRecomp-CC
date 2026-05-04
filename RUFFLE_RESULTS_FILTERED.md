# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `9e3e903e0754`  
**Date:** 2026-05-04 04:30 UTC  
**Total duration:** 2h23m48s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 585 | 607 | 96.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 0 | 190 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 7 | 15 | 46.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **787** | **1078** | **73.0%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,693 | 94,949 | 99.7% |
| from_gnash/actionscript.all | 0 | 0 | 0% |
| from_gnash/misc-ming.all | 2,784 | 4,493 | 62.0% |
| from_gnash/misc-mtasc.all | 162 | 163 | 99.4% |
| from_gnash/misc-swfc.all | 332 | 492 | 67.5% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **99,166** | **101,904** | **97.3%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | 14 | 4 | 4 |
| from_gnash/actionscript.all | 190 | - | - |
| from_gnash/misc-ming.all | 3 | 21 | 17 |
| from_gnash/misc-mtasc.all | 1 | - | 1 |
| from_gnash/misc-swfc.all | - | 4 | 4 |
| from_gnash/misc-swfmill.all | - | - | 1 |
| from_shumway | - | 25 | 2 |
| from_shumway/avm1 | - | - | - |
| **Total** | **208** | **54** | **29** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-ming.all | matrix_test | 85% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 585/607 (96.4%)
- **Ignored:** 40 tests
- **Duration:** 1h04m37s across 30 shards
- **Lines:** 94,693/94,949 matching (99.7%)
- **Avg test duration:** 5.9s — slowest: `movieclip_invalid_get_bounds_6` (25.1s)

### from_gnash/actionscript.all

- **Pass:** 0/190 (0%)
- **Duration:** 21m45s across 30 shards
- **Avg test duration:** 6.8s — slowest: `String-v8` (35.8s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 29m05s across 30 shards
- **Lines:** 2,784/4,493 matching (62.0%)
- **Avg test duration:** 17.1s — slowest: `matrix_test` (99.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m16s across 30 shards
- **Lines:** 162/163 matching (99.4%)
- **Avg test duration:** 15.1s — slowest: `implementsOpTest` (20.0s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 4m22s across 30 shards
- **Lines:** 332/492 matching (67.5%)
- **Avg test duration:** 16.2s — slowest: `opcode_guard_test2` (19.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m19s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.7s — slowest: `dict_override` (18.9s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m32s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.4s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (21.7s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m48s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.9s — slowest: `text-bind` (17.7s)
