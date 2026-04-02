# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `393783ad9c69`  
**Date:** 2026-04-02 19:37 UTC  
**Total duration:** 4h36m18s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 563 | 566 | 99.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 5 | 181 | 2.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 17 | 17 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **608** | **801** | **75.9%** | |

*93 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 71,405 | 71,435 | 99.96% |
| from_gnash/actionscript.all | 1,699 | 15,444 | 11.0% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 35 | 100% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **73,282** | **87,254** | **84.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 3 | - |
| from_gnash/actionscript.all | 176 | - |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | - | - |
| from_shumway/avm1 | 10 | 1 |
| **Total** | **192** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | movieclip_hittest_shapeflag | 96% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Key-v5 | 92% |
| from_gnash/actionscript.all | Selection-v7 | 88% |
| from_gnash/actionscript.all | Selection-v8 | 88% |
| from_gnash/actionscript.all | Selection-v6 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_shumway/avm1 | nativeinheritance | 83% |
| from_gnash/actionscript.all | System-v6 | 82% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 3 | 3 | 100% |

## Per-Suite Details

### avm1

- **Pass:** 563/566 (99.5%)
- **Ignored:** 54 tests
- **Duration:** 3h05m35s across 30 shards
- **Lines:** 71,405/71,435 matching (99.96%)
- **Avg test duration:** 17.8s — slowest: `movieclip_invalid_get_bounds_7` (42.5s)

### from_gnash/actionscript.all

- **Pass:** 5/181 (2.8%)
- **Ignored:** 9 tests
- **Duration:** 1h05m52s across 30 shards
- **Lines:** 1,699/15,444 matching (11.0%)
- **Avg test duration:** 20.6s — slowest: `array-v5` (45.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m07s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 17.6s — slowest: `afunc_dict` (19.2s)

### from_shumway

- **Pass:** 17/17 (100%)
- **Ignored:** 30 tests
- **Duration:** 13m51s across 30 shards
- **Lines:** 35/35 matching (100%)
- **Avg test duration:** 17.8s — slowest: `MaskTest` (20.4s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 6m52s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 17.9s — slowest: `watch` (21.5s)
