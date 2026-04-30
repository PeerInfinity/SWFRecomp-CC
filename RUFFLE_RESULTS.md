# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f62d59c41f02`  
**Date:** 2026-04-30 19:48 UTC  
**Total duration:** 2h06m51s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 642 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 118 | 190 | 62.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 57 | 102 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **909** | **1116** | **81.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,873 | 114,769 | 92.2% |
| from_gnash/actionscript.all | 15,065 | 16,957 | 88.8% |
| from_gnash/misc-ming.all | 2,776 | 4,577 | 60.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 304 | 499 | 60.9% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,423** | **138,851** | **90.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 12 |
| from_gnash/misc-ming.all | 32 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 8 |
| from_gnash/misc-swfmill.all | 2 |
| from_shumway | 26 |
| from_shumway/avm1 | 1 |
| **Total** | **116** |

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
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | 2 | - | 46 | - |

**from_gnash/actionscript.all — newly passing:** `ExternalInterface-v6`, `ExternalInterface-v7`

*Comparing `d26475209e73` → `f62d59c41f02`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 598/642 (93.1%)
- **Duration:** 58m23s across 30 shards
- **Lines:** 105,873/114,769 matching (92.2%)
- **Avg test duration:** 5.4s — slowest: `netstream_play_flv_screen` (33.5s)

### from_gnash/actionscript.all

- **Pass:** 118/190 (62.1%)
- **Duration:** 16m22s across 30 shards
- **Lines:** 15,065/16,957 matching (88.8%)
- **Avg test duration:** 5.1s — slowest: `String-v8` (33.1s)

### from_gnash/misc-ming.all

- **Pass:** 57/102 (55.9%)
- **Duration:** 25m27s across 30 shards
- **Lines:** 2,776/4,577 matching (60.7%)
- **Avg test duration:** 14.9s — slowest: `NetStream-SquareTest` (30.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.4s — slowest: `TextFieldTest` (19.1s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4m14s across 30 shards
- **Lines:** 304/499 matching (60.9%)
- **Avg test duration:** 15.8s — slowest: `action_execution_order_test10` (19.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m15s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.5s — slowest: `missing_bitmap` (18.9s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 13m02s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 8.4s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (19.3s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.8s — slowest: `duplicateMovieClip/dontremove` (18.2s)
