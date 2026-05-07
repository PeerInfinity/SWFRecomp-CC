# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f3965a99f783`  
**Date:** 2026-05-07 21:58 UTC  
**Total duration:** 1h54m45s

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
| avm1 | 105,963 | 114,983 | 92.2% |
| from_gnash/actionscript.all | 15,365 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 3,726 | 4,577 | 81.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 371 | 499 | 74.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 876 | 1,276 | 68.7% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **127,044** | **139,065** | **91.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 34 |
| from_gnash/actionscript.all | 2 |
| from_gnash/misc-ming.all | 14 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 3 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 17 |
| from_shumway/avm1 | 1 |
| **Total** | **71** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 91% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | 1 | 1 | 133 |
| from_gnash/actionscript.all | - | 1 | - | 9 |

**avm1 — newly passing:** `native_objects_swf6`

**avm1 — newly failing:** `textfield_props_swf6`

*Comparing `54a9b8fca57e` → `f3965a99f783`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 605/648 (93.4%)
- **Duration:** 53m55s across 30 shards
- **Lines:** 105,963/114,983 matching (92.2%)
- **Avg test duration:** 4.9s — slowest: `timeout` (23.2s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 11m41s across 30 shards
- **Lines:** 15,365/16,957 matching (90.6%)
- **Avg test duration:** 3.6s — slowest: `case-v7` (18.6s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 23m40s across 30 shards
- **Lines:** 3,726/4,577 matching (81.4%)
- **Avg test duration:** 13.9s — slowest: `matrix_test` (21.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.2s — slowest: `TextFieldTest` (17.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m00s across 30 shards
- **Lines:** 371/499 matching (74.3%)
- **Avg test duration:** 15.0s — slowest: `movieclip_destruction_test4` (18.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.2s — slowest: `jump_after_end` (18.2s)

### from_shumway

- **Pass:** 72/92 (78.3%)
- **Duration:** 12m53s across 30 shards
- **Lines:** 876/1,276 matching (68.7%)
- **Avg test duration:** 8.4s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (18.4s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.7s — slowest: `label` (18.0s)
