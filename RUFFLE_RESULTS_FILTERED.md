# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `1e21fdb6aad6`  
**Date:** 2026-05-08 02:38 UTC  
**Total duration:** 1h55m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 608 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 65 | 101 | 64.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 72 | 76 | 94.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **944** | **1062** | **88.9%** | |

*60 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,697 | 95,875 | 99.8% |
| from_gnash/actionscript.all | 15,377 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 3,715 | 4,559 | 81.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 381 | 492 | 77.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 615 | 637 | 96.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **116,525** | **119,282** | **97.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | - | 4 |
| from_gnash/actionscript.all | 1 | 63 |
| from_gnash/misc-ming.all | 13 | 23 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 1 | 6 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 1 | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **16** | **102** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 93% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/608 (99.3%)
- **Ignored:** 40 tests
- **Duration:** 54m23s across 30 shards
- **Lines:** 95,697/95,875 matching (99.8%)
- **Avg test duration:** 5.0s — slowest: `global_swf5_6_7_8_9` (22.4s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 11m46s across 30 shards
- **Lines:** 15,377/16,957 matching (90.7%)
- **Avg test duration:** 3.7s — slowest: `Mouse-v5` (21.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/101 (64.4%)
- **Ignored:** 1 tests
- **Duration:** 23m32s across 30 shards
- **Lines:** 3,715/4,559 matching (81.5%)
- **Avg test duration:** 13.8s — slowest: `matrix_test` (21.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.2s — slowest: `implementsOpTest` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4m01s across 30 shards
- **Lines:** 381/492 matching (77.4%)
- **Avg test duration:** 14.6s — slowest: `mouse_drag_test` (18.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m08s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.1s — slowest: `tags_after_last_showframe` (22.3s)

### from_shumway

- **Pass:** 72/76 (94.7%)
- **Ignored:** 16 tests
- **Duration:** 13m09s across 30 shards
- **Lines:** 615/637 matching (96.5%)
- **Avg test duration:** 6.6s — slowest: `avm1/text-bind` (22.7s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m23s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.4s — slowest: `text-bind` (18.2s)
