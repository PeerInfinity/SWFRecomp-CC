# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f9b8102de811`  
**Date:** 2026-04-14 01:19 UTC  
**Total duration:** 6h21m56s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 580 | 641 | 90.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 95 | 190 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 17 | 102 | 16.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 48 | 92 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 32 | 47 | 68.1% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **795** | **1115** | **71.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 84,183 | 114,746 | 73.4% |
| from_gnash/actionscript.all | 13,008 | 16,957 | 76.7% |
| from_gnash/misc-ming.all | 2,114 | 4,541 | 46.6% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 222 | 499 | 44.5% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 628 | 1,276 | 49.2% |
| from_shumway/avm1 | 451 | 491 | 91.9% |
| **Total** | **100,824** | **138,792** | **72.6%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error |
|-------|--------------:|-----------------:|---------------:|
| avm1 | 1 | 55 | - |
| from_gnash/actionscript.all | - | 74 | - |
| from_gnash/misc-ming.all | 1 | 74 | - |
| from_gnash/misc-mtasc.all | - | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | - |
| from_shumway | - | 43 | - |
| from_shumway/avm1 | - | 14 | - |
| **Total** | **2** | **274** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v7 | 94% |
| from_gnash/actionscript.all | Number-v8 | 94% |
| from_gnash/actionscript.all | TextSnapshot-v6 | 92% |
| from_gnash/actionscript.all | TextSnapshot-v7 | 92% |
| from_gnash/actionscript.all | TextSnapshot-v8 | 92% |
| from_gnash/actionscript.all | Number-v6 | 92% |
| from_gnash/actionscript.all | Selection-v6 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Number-v5 | 89% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 87% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 86% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| avm1 | bitmap_data_thorough/getColorBoundsRect | 84% |
| from_shumway | avm1/property-paths/property-paths-6 | 83% |
| from_shumway/avm1 | property-paths/property-paths-6 | 83% |
| from_gnash/actionscript.all | System-v7 | 83% |
| from_gnash/actionscript.all | System-v8 | 83% |
| from_gnash/actionscript.all | System-v6 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | array-v5 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test11 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | - | 1 | - | 3 |

**from_gnash/misc-ming.all — newly failing:** `getTimer_test`

*Comparing `c3d9506ef0b3` → `f9b8102de811`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 580/641 (90.5%)
- **Duration:** 3h33m30s across 30 shards
- **Lines:** 84,183/114,746 matching (73.4%)
- **Avg test duration:** 19.9s — slowest: `movieclip_invalid_get_bounds_6` (43.5s)

### from_gnash/actionscript.all

- **Pass:** 95/190 (50.0%)
- **Duration:** 1h11m58s across 30 shards
- **Lines:** 13,008/16,957 matching (76.7%)
- **Avg test duration:** 22.7s — slowest: `array-v5` (46.7s)

### from_gnash/misc-ming.all

- **Pass:** 17/102 (16.7%)
- **Duration:** 36m31s across 30 shards
- **Lines:** 2,114/4,541 matching (46.6%)
- **Avg test duration:** 21.4s — slowest: `matrix_test` (72.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m03s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 20.3s — slowest: `TextFieldTest` (21.3s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m25s across 30 shards
- **Lines:** 222/499 matching (44.5%)
- **Avg test duration:** 20.3s — slowest: `opcode_guard_test2` (23.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 5m51s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 19.5s — slowest: `trace-as2/root_onload` (21.1s)

### from_shumway

- **Pass:** 48/92 (52.2%)
- **Duration:** 30m17s across 30 shards
- **Lines:** 628/1,276 matching (49.2%)
- **Avg test duration:** 19.7s — slowest: `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` (22.3s)

### from_shumway/avm1

- **Pass:** 32/47 (68.1%)
- **Duration:** 15m17s across 30 shards
- **Lines:** 451/491 matching (91.9%)
- **Avg test duration:** 19.5s — slowest: `textfield/textfield-text-setters` (21.2s)
