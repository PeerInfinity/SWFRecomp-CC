# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `1f111219fa91`  
**Date:** 2026-04-26 22:53 UTC  
**Total duration:** 5m47s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 546 | 600 | 91.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 0 | 190 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 46 | 102 | 45.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 45 | 97.8% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **726** | **1072** | **67.7%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 88,779 | 88,957 | 99.8% |
| from_gnash/actionscript.all | 0 | 0 | 0% |
| from_gnash/misc-ming.all | 2,434 | 4,402 | 55.3% |
| from_gnash/misc-mtasc.all | 162 | 163 | 99.4% |
| from_gnash/misc-swfc.all | 262 | 499 | 52.5% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 653 | 1,260 | 51.8% |
| from_shumway/avm1 | 471 | 471 | 100% |
| **Total** | **92,808** | **95,803** | **96.9%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | 50 | - | 4 |
| from_gnash/actionscript.all | 190 | - | - |
| from_gnash/misc-ming.all | 6 | 39 | 11 |
| from_gnash/misc-mtasc.all | 1 | - | 1 |
| from_gnash/misc-swfc.all | - | 8 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | 2 | 25 | 2 |
| from_shumway/avm1 | 1 | - | - |
| **Total** | **250** | **74** | **22** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 83% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 546/600 (91.0%)
- **Ignored:** 41 tests
- **Duration:** 3m15s across 30 shards
- **Lines:** 88,779/88,957 matching (99.8%)
- **Avg test duration:** 0.2s — slowest: `edittext_newline_stripping` (6.2s)

### from_gnash/actionscript.all

- **Pass:** 0/190 (0%)
- **Duration:** 55s across 30 shards
- **Avg test duration:** 0.2s — slowest: `String-v8` (0.5s)

### from_gnash/misc-ming.all

- **Pass:** 46/102 (45.1%)
- **Duration:** 43s across 30 shards
- **Lines:** 2,434/4,402 matching (55.3%)
- **Avg test duration:** 0.4s — slowest: `matrix_test` (4.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 162/163 matching (99.4%)
- **Avg test duration:** 0.2s — slowest: `function_test` (0.2s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 5s across 30 shards
- **Lines:** 262/499 matching (52.5%)
- **Avg test duration:** 0.3s — slowest: `sound` (0.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 0.2s — slowest: `dict_cross` (0.2s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 29s across 30 shards
- **Lines:** 653/1,260 matching (51.8%)
- **Avg test duration:** 0.3s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (0.6s)

### from_shumway/avm1

- **Pass:** 44/45 (97.8%)
- **Ignored:** 2 tests
- **Duration:** 12s across 30 shards
- **Lines:** 471/471 matching (100%)
- **Avg test duration:** 0.2s — slowest: `depth` (0.3s)
