# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `873e520ed49f`  
**Date:** 2026-05-07 16:51 UTC  
**Total duration:** 5m15s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 608 | 99.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 0 | 190 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 64 | 102 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 72 | 76 | 94.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **815** | **1063** | **76.7%** | |

*59 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,684 | 95,875 | 99.8% |
| from_gnash/actionscript.all | 0 | 16,957 | 0% |
| from_gnash/misc-ming.all | 3,583 | 4,577 | 78.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 364 | 492 | 74.0% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 615 | 637 | 96.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **100,986** | **119,300** | **84.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| avm1 | 1 | 4 | 1 |
| from_gnash/actionscript.all | 190 | - | - |
| from_gnash/misc-ming.all | 16 | 22 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 1 | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **210** | **37** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-ming.all | matrix_test | 87% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 602/608 (99.0%)
- **Ignored:** 40 tests
- **Duration:** 2m50s across 30 shards
- **Lines:** 95,684/95,875 matching (99.8%)
- **Avg test duration:** 0.2s — slowest: `edittext_newline_stripping` (6.1s)

### from_gnash/actionscript.all

- **Pass:** 0/190 (0%)
- **Duration:** 1m06s across 30 shards
- **Lines:** 0/16,957 matching (0%)
- **Avg test duration:** 0.3s — slowest: `LoadVars-v6` (0.8s)

### from_gnash/misc-ming.all

- **Pass:** 64/102 (62.7%)
- **Duration:** 35s across 30 shards
- **Lines:** 3,583/4,577 matching (78.3%)
- **Avg test duration:** 0.3s — slowest: `matrix_test` (4.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.2s — slowest: `levels` (0.2s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4s across 30 shards
- **Lines:** 364/492 matching (74.0%)
- **Avg test duration:** 0.2s — slowest: `movieclip_destruction_test1` (0.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 4s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.2s — slowest: `jump_after_end` (0.2s)

### from_shumway

- **Pass:** 72/76 (94.7%)
- **Ignored:** 16 tests
- **Duration:** 25s across 30 shards
- **Lines:** 615/637 matching (96.5%)
- **Avg test duration:** 0.2s — slowest: `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` (0.5s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 10s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.2s — slowest: `depth` (0.3s)
