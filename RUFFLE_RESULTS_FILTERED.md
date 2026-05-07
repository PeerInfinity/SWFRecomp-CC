# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `f3965a99f783`  
**Date:** 2026-05-07 21:58 UTC  
**Total duration:** 1h54m45s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 603 | 608 | 99.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 65 | 102 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 72 | 76 | 94.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **943** | **1063** | **88.7%** | |

*59 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,564 | 95,875 | 99.7% |
| from_gnash/actionscript.all | 15,365 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 3,726 | 4,577 | 81.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 364 | 492 | 74.0% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 615 | 637 | 96.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **116,374** | **119,300** | **97.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 1 | 4 |
| from_gnash/actionscript.all | 2 | 62 |
| from_gnash/misc-ming.all | 14 | 23 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 1 | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **20** | **100** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 91% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 603/608 (99.2%)
- **Ignored:** 40 tests
- **Duration:** 53m55s across 30 shards
- **Lines:** 95,564/95,875 matching (99.7%)
- **Avg test duration:** 4.9s — slowest: `timeout` (23.2s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 11m41s across 30 shards
- **Lines:** 15,365/16,957 matching (90.6%)
- **Avg test duration:** 3.6s — slowest: `case-v7` (18.6s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 23m40s across 30 shards
- **Lines:** 3,726/4,577 matching (81.4%)
- **Avg test duration:** 13.9s — slowest: `matrix_test` (21.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.2s — slowest: `TextFieldTest` (17.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4m00s across 30 shards
- **Lines:** 364/492 matching (74.0%)
- **Avg test duration:** 14.8s — slowest: `movieclip_destruction_test4` (18.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.2s — slowest: `jump_after_end` (18.2s)

### from_shumway

- **Pass:** 72/76 (94.7%)
- **Ignored:** 16 tests
- **Duration:** 12m53s across 30 shards
- **Lines:** 615/637 matching (96.5%)
- **Avg test duration:** 6.4s — slowest: `gradientTransform` (18.2s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m23s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.4s — slowest: `label` (18.0s)
