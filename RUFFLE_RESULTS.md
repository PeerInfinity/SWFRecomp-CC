# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8d0881a2c69b`  
**Date:** 2026-04-11 18:55 UTC  
**Total duration:** 5h29m22s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 579 | 620 | 93.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 88 | 190 | 46.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 9 | 58 | 15.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 18 | 23 | 78.3% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **731** | **977** | **74.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 82,682 | 91,594 | 90.3% |
| from_gnash/actionscript.all | 12,839 | 16,957 | 75.7% |
| from_gnash/misc-ming.all | 1,669 | 3,388 | 49.3% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 224 | 499 | 44.9% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 138 | 311 | 44.4% |
| **Total** | **97,785** | **113,265** | **86.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 41 | - |
| from_gnash/actionscript.all | 102 | - |
| from_gnash/misc-ming.all | 49 | - |
| from_gnash/misc-mtasc.all | 2 | - |
| from_gnash/misc-swfc.all | 13 | 1 |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | 30 | - |
| from_shumway/avm1 | 5 | - |
| **Total** | **245** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_filters | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | Math-v7 | 98% |
| from_gnash/actionscript.all | Math-v8 | 98% |
| avm1 | mcl_replace_root_swf7_to_swf5 | 98% |
| avm1 | mcl_replace_root_swf7_to_swf6 | 98% |
| from_gnash/actionscript.all | Math-v5 | 98% |
| from_gnash/actionscript.all | Math-v6 | 98% |
| from_gnash/actionscript.all | Inheritance-v8 | 98% |
| avm1 | movieclip_library_state_values | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| from_gnash/actionscript.all | ops-v8 | 97% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | delete-v7 | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v7 | 94% |
| from_gnash/actionscript.all | Number-v8 | 94% |
| from_gnash/actionscript.all | delete-v5 | 92% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| from_gnash/actionscript.all | Selection-v6 | 90% |
| from_gnash/actionscript.all | Number-v6 | 90% |
| from_gnash/actionscript.all | Number-v5 | 89% |
| from_gnash/actionscript.all | delete-v6 | 88% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 87% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 86% |
| from_gnash/actionscript.all | LocalConnection-v6 | 86% |
| from_gnash/actionscript.all | LocalConnection-v7 | 86% |
| from_gnash/actionscript.all | LocalConnection-v8 | 86% |
| from_gnash/actionscript.all | Inheritance-v5 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | System-v7 | 83% |
| from_gnash/actionscript.all | System-v8 | 83% |
| from_gnash/actionscript.all | System-v6 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | array-v5 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 2 | - |
| from_shumway/avm1 | 1 | - | 1 | - |

**from_shumway/avm1 — newly passing:** `nativeinheritance`

*Comparing `6d3c6fd07155` → `8d0881a2c69b`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 579/620 (93.4%)
- **Duration:** 3h22m21s across 30 shards
- **Lines:** 82,682/91,594 matching (90.3%)
- **Avg test duration:** 19.5s — slowest: `movieclip_invalid_get_bounds_6` (45.1s)

### from_gnash/actionscript.all

- **Pass:** 88/190 (46.3%)
- **Duration:** 1h10m46s across 30 shards
- **Lines:** 12,839/16,957 matching (75.7%)
- **Avg test duration:** 22.3s — slowest: `array-v5` (45.6s)

### from_gnash/misc-ming.all

- **Pass:** 9/58 (15.5%)
- **Duration:** 20m47s across 30 shards
- **Lines:** 1,669/3,388 matching (49.3%)
- **Avg test duration:** 21.5s — slowest: `matrix_test` (67.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m00s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 20.0s — slowest: `levels` (21.1s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m22s across 30 shards
- **Lines:** 224/499 matching (44.9%)
- **Avg test duration:** 20.1s — slowest: `opcode_guard_test2` (21.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m31s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 19.3s — slowest: `missing_bitmap` (19.9s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 15m07s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 19.2s — slowest: `bitmapbuttons` (20.5s)

### from_shumway/avm1

- **Pass:** 18/23 (78.3%)
- **Duration:** 7m25s across 30 shards
- **Lines:** 138/311 matching (44.4%)
- **Avg test duration:** 19.3s — slowest: `text-bind` (20.6s)
