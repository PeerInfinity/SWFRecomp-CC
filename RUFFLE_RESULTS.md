# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6beabb40c149`  
**Date:** 2026-05-11 21:23 UTC  
**Total duration:** 5m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 651 | 92.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 66 | 102 | 64.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **948** | **1125** | **84.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,105 | 114,995 | 92.3% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,774 | 4,577 | 82.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **127,291** | **139,077** | **91.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 1 |
| from_gnash/misc-ming.all | 12 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **66** |

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
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `ce31587cf186` → `6beabb40c149`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 605/651 (92.9%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 106,105/114,995 matching (92.3%)
- **Avg test duration:** 0.2s — slowest: `edittext_newline_stripping` (6.5s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 55s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 0.2s — slowest: `LocalConnection-v6` (0.5s)

### from_gnash/misc-ming.all

- **Pass:** 66/102 (64.7%)
- **Duration:** 36s across 30 shards
- **Lines:** 3,774/4,577 matching (82.5%)
- **Avg test duration:** 0.3s — slowest: `matrix_test` (4.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.2s — slowest: `levels` (0.3s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 0.2s — slowest: `movieclip_destruction_test1` (0.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 4s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.2s — slowest: `trace-as2/shortstack` (0.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 23s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 0.2s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (0.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 11s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.2s — slowest: `depth` (0.3s)
