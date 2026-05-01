# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `ae319d2d373f`  
**Date:** 2026-05-01 02:30 UTC  
**Total duration:** 1h50m57s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 642 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 118 | 190 | 62.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **915** | **1116** | **82.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,873 | 114,769 | 92.2% |
| from_gnash/actionscript.all | 15,065 | 16,957 | 88.8% |
| from_gnash/misc-ming.all | 2,803 | 4,577 | 61.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,457** | **138,851** | **90.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 12 |
| from_gnash/misc-ming.all | 27 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | 2 |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **109** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 83% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 2 | - | 10 | 12 |

**from_gnash/misc-ming.all — newly passing:** `displaylist_depths/displaylist_depths_test8`, `loading/LoadVarsTest`

*Comparing `88cfa5ac2662` → `ae319d2d373f`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 598/642 (93.1%)
- **Duration:** 52m39s across 30 shards
- **Lines:** 105,873/114,769 matching (92.2%)
- **Avg test duration:** 4.9s — slowest: `load_vars` (19.5s)

### from_gnash/actionscript.all

- **Pass:** 118/190 (62.1%)
- **Duration:** 11m12s across 30 shards
- **Lines:** 15,065/16,957 matching (88.8%)
- **Avg test duration:** 3.5s — slowest: `TextFieldHTML-v5` (17.6s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 22m31s across 30 shards
- **Lines:** 2,803/4,577 matching (61.2%)
- **Avg test duration:** 13.2s — slowest: `matrix_test` (20.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m39s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.0s — slowest: `exception` (17.3s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 3m51s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 14.4s — slowest: `submoviegetvar` (17.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m59s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 16.6s — slowest: `background` (18.1s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m08s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 7.9s — slowest: `button3` (17.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.4s — slowest: `rollover` (18.0s)
