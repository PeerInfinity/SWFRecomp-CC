# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `1e21fdb6aad6`  
**Date:** 2026-05-08 02:38 UTC  
**Total duration:** 1h55m24s

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
| from_gnash/misc-ming.all | 3,726 | 4,577 | 81.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 876 | 1,276 | 68.7% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **127,205** | **139,065** | **91.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 34 |
| from_gnash/actionscript.all | 1 |
| from_gnash/misc-ming.all | 14 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 17 |
| from_shumway/avm1 | 1 |
| **Total** | **69** |

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

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 3 | - |

*Comparing `46d78af6d585` → `1e21fdb6aad6`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 605/648 (93.4%)
- **Duration:** 54m23s across 30 shards
- **Lines:** 106,095/114,983 matching (92.3%)
- **Avg test duration:** 5.0s — slowest: `global_swf5_6_7_8_9` (22.4s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 11m46s across 30 shards
- **Lines:** 15,377/16,957 matching (90.7%)
- **Avg test duration:** 3.7s — slowest: `Mouse-v5` (21.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 23m32s across 30 shards
- **Lines:** 3,726/4,577 matching (81.4%)
- **Avg test duration:** 13.8s — slowest: `matrix_test` (21.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.2s — slowest: `implementsOpTest` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m01s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 15.0s — slowest: `sound` (21.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m08s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.1s — slowest: `tags_after_last_showframe` (22.3s)

### from_shumway

- **Pass:** 72/92 (78.3%)
- **Duration:** 13m09s across 30 shards
- **Lines:** 876/1,276 matching (68.7%)
- **Avg test duration:** 8.5s — slowest: `avm1/text-bind` (22.7s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.7s — slowest: `text-bind` (18.2s)
