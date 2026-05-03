# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `06991d472ec7`  
**Date:** 2026-05-03 04:26 UTC  
**Total duration:** 2h23m07s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 599 | 607 | 98.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 62 | 102 | 60.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 7 | 15 | 46.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **926** | **1078** | **85.9%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,603 | 95,859 | 99.7% |
| from_gnash/actionscript.all | 15,351 | 16,957 | 90.5% |
| from_gnash/misc-ming.all | 2,829 | 4,577 | 61.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 332 | 492 | 67.5% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,521** | **119,923** | **96.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 4 | 4 |
| from_gnash/actionscript.all | 5 | 61 |
| from_gnash/misc-ming.all | 24 | 16 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 4 | 4 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **62** | **90** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | Global-v7 | 96% |
| from_gnash/actionscript.all | Global-v8 | 96% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
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
- **Duration:** 1h04m44s across 30 shards
- **Lines:** 95,603/95,859 matching (99.7%)
- **Avg test duration:** 5.9s — slowest: `movieclip_invalid_get_bounds_6` (25.6s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 21m37s across 30 shards
- **Lines:** 15,351/16,957 matching (90.5%)
- **Avg test duration:** 6.8s — slowest: `String-v8` (32.6s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 28m45s across 30 shards
- **Lines:** 2,829/4,577 matching (61.8%)
- **Avg test duration:** 16.9s — slowest: `matrix_test` (96.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `inheritance` (18.5s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 4m27s across 30 shards
- **Lines:** 332/492 matching (67.5%)
- **Avg test duration:** 16.5s — slowest: `movieclip_destruction_test4` (21.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m22s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.9s — slowest: `jump_after_end` (19.2s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m01s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.1s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (20.4s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m55s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.1s — slowest: `label` (19.0s)
