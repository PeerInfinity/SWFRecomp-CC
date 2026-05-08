# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `96a5d81e957c`  
**Date:** 2026-05-08 04:45 UTC  
**Total duration:** 6m11s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 648 | 93.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 65 | 102 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 72 | 92 | 78.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **945** | **1122** | **84.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,095 | 114,983 | 92.3% |
| from_gnash/actionscript.all | 15,377 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 3,729 | 4,577 | 81.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 876 | 1,276 | 68.7% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **127,208** | **139,065** | **91.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 34 |
| from_gnash/actionscript.all | 1 |
| from_gnash/misc-ming.all | 13 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 17 |
| from_shumway/avm1 | 1 |
| **Total** | **68** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 93% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 5 | 11 |

*Comparing `b85626d2fcbf` → `96a5d81e957c`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 605/648 (93.4%)
- **Duration:** 3m37s across 30 shards
- **Lines:** 106,095/114,983 matching (92.3%)
- **Avg test duration:** 0.3s — slowest: `edittext_newline_stripping` (6.2s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 15,377/16,957 matching (90.7%)
- **Avg test duration:** 0.3s — slowest: `Random-v8` (1.1s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 37s across 30 shards
- **Lines:** 3,729/4,577 matching (81.5%)
- **Avg test duration:** 0.3s — slowest: `matrix_test` (4.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.3s — slowest: `hello` (0.7s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 0.2s — slowest: `movieclip_destruction_test1` (0.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.2s — slowest: `trace-as2/this` (0.6s)

### from_shumway

- **Pass:** 72/92 (78.3%)
- **Duration:** 28s across 30 shards
- **Lines:** 876/1,276 matching (68.7%)
- **Avg test duration:** 0.2s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (1.4s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 12s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 0.2s — slowest: `super` (0.5s)
