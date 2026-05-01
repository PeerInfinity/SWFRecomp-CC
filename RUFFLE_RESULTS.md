# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `fac77e426d9b`  
**Date:** 2026-05-01 15:43 UTC  
**Total duration:** 1h51m50s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 643 | 93.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 118 | 190 | 62.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **915** | **1117** | **81.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,876 | 114,774 | 92.2% |
| from_gnash/actionscript.all | 15,133 | 16,957 | 89.2% |
| from_gnash/misc-ming.all | 2,815 | 4,577 | 61.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,540** | **138,856** | **90.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 36 |
| from_gnash/actionscript.all | 10 |
| from_gnash/misc-ming.all | 27 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | 2 |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **108** |

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
| from_gnash/actionscript.all | Global-v6 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | 1 | - | 17 | - |

*Comparing `7a1f04a07121` → `fac77e426d9b`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 598/643 (93.0%)
- **Duration:** 52m39s across 30 shards
- **Lines:** 105,876/114,774 matching (92.2%)
- **Avg test duration:** 4.9s — slowest: `mask_reapply` (18.3s)

### from_gnash/actionscript.all

- **Pass:** 118/190 (62.1%)
- **Duration:** 11m18s across 30 shards
- **Lines:** 15,133/16,957 matching (89.2%)
- **Avg test duration:** 3.5s — slowest: `Matrix-v7` (17.6s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 22m59s across 30 shards
- **Lines:** 2,815/4,577 matching (61.5%)
- **Avg test duration:** 13.5s — slowest: `matrix_test` (21.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m44s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.5s — slowest: `hello` (17.5s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 3m58s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 14.9s — slowest: `hello` (17.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m04s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 16.8s — slowest: `background` (17.7s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m09s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 7.9s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (17.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.4s — slowest: `rollover` (17.6s)
