# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `e707c6896265`  
**Date:** 2026-05-05 02:00 UTC  
**Total duration:** 2h19m40s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 601 | 607 | 99.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 64 | 102 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 7 | 15 | 46.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **932** | **1078** | **86.5%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,636 | 95,859 | 99.8% |
| from_gnash/actionscript.all | 15,370 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 2,907 | 4,577 | 63.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 353 | 492 | 71.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,672** | **119,923** | **96.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 2 | 4 |
| from_gnash/actionscript.all | 2 | 62 |
| from_gnash/misc-ming.all | 20 | 18 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **52** | **94** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 87% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 601/607 (99.0%)
- **Ignored:** 40 tests
- **Duration:** 1h02m24s across 30 shards
- **Lines:** 95,636/95,859 matching (99.8%)
- **Avg test duration:** 5.7s — slowest: `movieclip_invalid_get_bounds_7` (25.8s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 21m04s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 6.6s — slowest: `MovieClip-v5` (33.5s)

### from_gnash/misc-ming.all

- **Pass:** 64/102 (62.7%)
- **Duration:** 28m41s across 30 shards
- **Lines:** 2,907/4,577 matching (63.5%)
- **Avg test duration:** 16.8s — slowest: `matrix_test` (100.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.5s — slowest: `hello` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 4m17s across 30 shards
- **Lines:** 353/492 matching (71.7%)
- **Avg test duration:** 15.8s — slowest: `action_execution_order_test10` (19.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m14s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.4s — slowest: `tags_after_last_showframe` (19.3s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m02s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.1s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (20.3s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m45s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.9s — slowest: `label` (17.6s)
