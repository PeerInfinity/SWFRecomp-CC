# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `469c895d05e9`  
**Date:** 2026-04-30 23:01 UTC  
**Total duration:** 2h22m44s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 642 | 93.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 118 | 190 | 62.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 59 | 102 | 57.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **911** | **1116** | **81.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,821 | 114,769 | 92.2% |
| from_gnash/actionscript.all | 15,065 | 16,957 | 88.8% |
| from_gnash/misc-ming.all | 2,802 | 4,577 | 61.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,401** | **138,851** | **90.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 36 |
| from_gnash/actionscript.all | 12 |
| from_gnash/misc-ming.all | 29 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | 2 |
| from_shumway | 26 |
| from_shumway/avm1 | 1 |
| **Total** | **113** |

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
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| avm1 | tab_ordering_properties | 82% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 52 |
| from_gnash/misc-ming.all | - | - | 6 | - |
| from_gnash/misc-swfc.all | 1 | - | 4 | - |

**avm1 — newly failing:** `tab_ordering_properties`

**from_gnash/misc-swfc.all — newly passing:** `movieclip_destruction_test2`

*Comparing `19cc9a8d78d6` → `469c895d05e9`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/642 (93.0%)
- **Duration:** 1h04m30s across 30 shards
- **Lines:** 105,821/114,769 matching (92.2%)
- **Avg test duration:** 6.0s — slowest: `netstream_play_flv_screen` (33.4s)

### from_gnash/actionscript.all

- **Pass:** 118/190 (62.1%)
- **Duration:** 21m33s across 30 shards
- **Lines:** 15,065/16,957 matching (88.8%)
- **Avg test duration:** 6.7s — slowest: `String-v8` (33.2s)

### from_gnash/misc-ming.all

- **Pass:** 59/102 (57.8%)
- **Duration:** 28m33s across 30 shards
- **Lines:** 2,802/4,577 matching (61.2%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (102.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.3s — slowest: `implementsOpTest` (20.5s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m22s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 16.3s — slowest: `gotoFrameLabelAsFunction` (19.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m16s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.5s — slowest: `dict_event` (18.3s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 14m01s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 9.1s — slowest: `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` (21.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 2m26s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 3.0s — slowest: `duplicateMovieClip/dontremove` (18.4s)
