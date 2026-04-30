# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `6fe8d0db43ef`  
**Date:** 2026-04-30 15:22 UTC  
**Total duration:** 1h54m10s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 601 | 99.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 57 | 102 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **902** | **1073** | **84.1%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,113 | 99.8% |
| from_gnash/actionscript.all | 14,856 | 16,957 | 87.6% |
| from_gnash/misc-ming.all | 2,776 | 4,577 | 60.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 281 | 499 | 56.3% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **114,230** | **119,184** | **95.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 1 | 4 |
| from_gnash/actionscript.all | 17 | 60 |
| from_gnash/misc-ming.all | 32 | 13 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 8 | 3 |
| from_gnash/misc-swfmill.all | 2 | 1 |
| from_shumway | 26 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **86** | **85** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/601 (99.2%)
- **Ignored:** 41 tests
- **Duration:** 53m57s across 30 shards
- **Lines:** 94,915/95,113 matching (99.8%)
- **Avg test duration:** 4.9s — slowest: `add` (18.8s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 11m33s across 30 shards
- **Lines:** 14,856/16,957 matching (87.6%)
- **Avg test duration:** 3.6s — slowest: `ASnative-v5` (17.9s)

### from_gnash/misc-ming.all

- **Pass:** 57/102 (55.9%)
- **Duration:** 23m20s across 30 shards
- **Lines:** 2,776/4,577 matching (60.7%)
- **Avg test duration:** 13.7s — slowest: `matrix_test` (19.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.5s — slowest: `implementsOpTest` (18.0s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 3m59s across 30 shards
- **Lines:** 281/499 matching (56.3%)
- **Avg test duration:** 14.9s — slowest: `action_execution_order_test10` (18.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m06s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 16.9s — slowest: `dict_override` (17.9s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 12m32s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 8.1s — slowest: `avm1/mouse-transparency` (18.4s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m55s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.1s — slowest: `nested-button` (17.2s)
