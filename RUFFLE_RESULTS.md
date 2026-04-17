# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b3deda13c6a9`  
**Date:** 2026-04-17 16:55 UTC  
**Total duration:** 1h47m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 577 | 641 | 90.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 106 | 190 | 55.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 60 | 92 | 65.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **828** | **1115** | **74.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 84,035 | 114,746 | 73.2% |
| from_gnash/actionscript.all | 13,631 | 16,957 | 80.4% |
| from_gnash/misc-ming.all | 2,120 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 222 | 499 | 44.5% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 661 | 1,276 | 51.8% |
| from_shumway/avm1 | 484 | 491 | 98.6% |
| **Total** | **101,371** | **138,792** | **73.0%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error |
|-------|--------------:|-----------------:|---------------:|
| avm1 | 1 | 56 | 2 |
| from_gnash/actionscript.all | - | 57 | - |
| from_gnash/misc-ming.all | 1 | 73 | - |
| from_gnash/misc-mtasc.all | - | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | - |
| from_shumway | - | 31 | - |
| from_shumway/avm1 | - | 2 | - |
| **Total** | **2** | **233** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| from_gnash/actionscript.all | Number-v6 | 97% |
| from_gnash/actionscript.all | Number-v7 | 97% |
| from_gnash/actionscript.all | Number-v8 | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v5 | 93% |
| from_gnash/actionscript.all | Selection-v6 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 91% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 90% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 90% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 89% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 89% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 89% |
| from_gnash/actionscript.all | array-v5 | 88% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_shumway | avm1/moviecliploader | 86% |
| from_shumway/avm1 | moviecliploader | 86% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| avm1 | bitmap_data_thorough/getColorBoundsRect | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/actionscript.all | Matrix-v6 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | get_frame_number_test | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test11 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 3 | - | 139 |
| from_shumway | - | - | 5 | - |
| from_shumway/avm1 | - | - | 5 | - |

**avm1 — newly failing:** `movieclip_invalid_get_bounds_1`, `movieclip_invalid_get_bounds_2`, `string_paths_eval2`

*Comparing `0d3478bc7418` → `b3deda13c6a9`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 577/641 (90.0%)
- **Duration:** 51m00s across 30 shards
- **Lines:** 84,035/114,746 matching (73.2%)
- **Avg test duration:** 4.7s — slowest: `as2_oop` (19.0s)

### from_gnash/actionscript.all

- **Pass:** 106/190 (55.8%)
- **Duration:** 11m04s across 30 shards
- **Lines:** 13,631/16,957 matching (80.4%)
- **Avg test duration:** 3.4s — slowest: `Accessibility-v8` (17.8s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 21m27s across 30 shards
- **Lines:** 2,120/4,541 matching (46.7%)
- **Avg test duration:** 12.6s — slowest: `matrix_test` (19.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m36s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 10.6s — slowest: `enum` (17.2s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m41s across 30 shards
- **Lines:** 222/499 matching (44.5%)
- **Avg test duration:** 13.8s — slowest: `soft_reference_test1` (16.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m44s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 15.8s — slowest: `background` (18.7s)

### from_shumway

- **Pass:** 60/92 (65.2%)
- **Duration:** 11m48s across 30 shards
- **Lines:** 661/1,276 matching (51.8%)
- **Avg test duration:** 7.6s — slowest: `avm1timeline1` (16.3s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 484/491 matching (98.6%)
- **Avg test duration:** 2.1s — slowest: `text-bind` (16.3s)
