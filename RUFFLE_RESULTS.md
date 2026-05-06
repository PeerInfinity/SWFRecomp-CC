# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c5fb3c17b089`  
**Date:** 2026-05-06 21:30 UTC  
**Total duration:** 53m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 648 | 93.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 64 | 102 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 68 | 92 | 73.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **939** | **1122** | **83.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,093 | 114,983 | 92.3% |
| from_gnash/actionscript.all | 15,370 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 3,538 | 4,577 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 371 | 499 | 74.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 687 | 1,276 | 53.8% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **126,802** | **139,065** | **91.2%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 2 |
| from_gnash/misc-ming.all | 19 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 3 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 21 |
| from_shumway/avm1 | 1 |
| **Total** | **81** |

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
| from_gnash/actionscript.all | array-v5 | 92% |
| avm1 | try_catch_stack | 88% |
| from_gnash/misc-ming.all | matrix_test | 87% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 439 | - |

*Comparing `d0fbf9d33042` → `c5fb3c17b089`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/648 (93.2%)
- **Duration:** 24m29s across 30 shards
- **Lines:** 106,093/114,983 matching (92.3%)
- **Avg test duration:** 2.2s — slowest: `movieclip_invalid_get_bounds_6` (25.9s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 6m56s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 2.1s — slowest: `BitmapData-v8` (23.2s)

### from_gnash/misc-ming.all

- **Pass:** 64/102 (62.7%)
- **Duration:** 9m26s across 30 shards
- **Lines:** 3,538/4,577 matching (77.3%)
- **Avg test duration:** 5.5s — slowest: `matrix_test` (101.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 12s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 1.3s — slowest: `implementsOpTest` (2.1s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 371/499 matching (74.3%)
- **Avg test duration:** 8.9s — slowest: `movieclip_destruction_test1` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 3m06s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 10.3s — slowest: `dict_event` (18.9s)

### from_shumway

- **Pass:** 68/92 (73.9%)
- **Duration:** 5m56s across 30 shards
- **Lines:** 687/1,276 matching (53.8%)
- **Avg test duration:** 3.8s — slowest: `avm1/hitarea` (19.1s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 52s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.1s — slowest: `label` (19.1s)
