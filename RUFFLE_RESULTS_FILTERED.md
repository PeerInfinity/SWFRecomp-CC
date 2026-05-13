# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `066b68ca2a06`  
**Date:** 2026-05-13 03:29 UTC  
**Total duration:** 2h29m11s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 611 | 98.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 66 | 100 | 66.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **946** | **1064** | **88.9%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,707 | 95,887 | 99.8% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,746 | 4,517 | 82.9% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 381 | 492 | 77.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **116,588** | **119,252** | **97.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 1 | 6 |
| from_gnash/actionscript.all | 1 | 63 |
| from_gnash/misc-ming.all | 10 | 24 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 1 | 6 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **13** | **105** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/611 (98.9%)
- **Ignored:** 40 tests
- **Duration:** 1h08m01s across 30 shards
- **Lines:** 95,707/95,887 matching (99.8%)
- **Avg test duration:** 6.2s — slowest: `on_construct` (26.9s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 22m18s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 7.0s — slowest: `String-v8` (33.5s)

### from_gnash/misc-ming.all

- **Pass:** 66/100 (66.0%)
- **Ignored:** 2 tests
- **Duration:** 29m43s across 30 shards
- **Lines:** 3,746/4,517 matching (82.9%)
- **Avg test duration:** 17.4s — slowest: `matrix_test` (92.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.4s — slowest: `enum` (20.6s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4m33s across 30 shards
- **Lines:** 381/492 matching (77.4%)
- **Avg test duration:** 16.9s — slowest: `movieclip_destruction_test1` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m33s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.5s — slowest: `background` (19.7s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m46s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.5s — slowest: `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` (21.4s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m54s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.1s — slowest: `label` (18.6s)
