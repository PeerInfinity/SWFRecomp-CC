# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f2ef2ccd66cc`  
**Date:** 2026-04-10 03:16 UTC  
**Total duration:** 5h29m55s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 580 | 620 | 93.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 83 | 190 | 43.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 8 | 58 | 13.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **720** | **977** | **73.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 82,688 | 91,594 | 90.3% |
| from_gnash/actionscript.all | 12,799 | 16,957 | 75.5% |
| from_gnash/misc-ming.all | 1,666 | 3,388 | 49.2% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 223 | 499 | 44.7% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **97,727** | **113,265** | **86.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 40 | - |
| from_gnash/actionscript.all | 107 | - |
| from_gnash/misc-ming.all | 50 | - |
| from_gnash/misc-mtasc.all | 2 | - |
| from_gnash/misc-swfc.all | 13 | 1 |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | 30 | - |
| from_shumway/avm1 | 10 | 1 |
| **Total** | **255** | **2** |

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
| from_gnash/actionscript.all | delete-v8 | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v7 | 94% |
| from_gnash/actionscript.all | Number-v8 | 94% |
| from_gnash/actionscript.all | delete-v7 | 93% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| from_gnash/actionscript.all | Selection-v6 | 90% |
| from_gnash/actionscript.all | delete-v5 | 90% |
| from_gnash/actionscript.all | Number-v6 | 90% |
| from_gnash/actionscript.all | Number-v5 | 89% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | Error-v6 | 87% |
| from_gnash/actionscript.all | Error-v7 | 87% |
| from_gnash/actionscript.all | Error-v8 | 87% |
| from_gnash/actionscript.all | delete-v6 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | LocalConnection-v6 | 86% |
| from_gnash/actionscript.all | LocalConnection-v7 | 86% |
| from_gnash/actionscript.all | LocalConnection-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | Error-v5 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 85% |
| from_gnash/actionscript.all | Inheritance-v5 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_shumway/avm1 | nativeinheritance | 83% |
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
| from_gnash/actionscript.all | 3 | - | 70 | 4 |
| from_gnash/misc-ming.all | - | 1 | - | 3 |

**from_gnash/actionscript.all — newly passing:** `enumerate-v6`, `enumerate-v7`, `enumerate-v8`

**from_gnash/misc-ming.all — newly failing:** `getTimer_test`

*Comparing `a68c40985707` → `f2ef2ccd66cc`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 580/620 (93.5%)
- **Duration:** 3h22m26s across 30 shards
- **Lines:** 82,688/91,594 matching (90.3%)
- **Avg test duration:** 19.5s — slowest: `movieclip_invalid_get_bounds_7` (41.8s)

### from_gnash/actionscript.all

- **Pass:** 83/190 (43.7%)
- **Duration:** 1h11m06s across 30 shards
- **Lines:** 12,799/16,957 matching (75.5%)
- **Avg test duration:** 22.4s — slowest: `array-v5` (45.5s)

### from_gnash/misc-ming.all

- **Pass:** 8/58 (13.8%)
- **Duration:** 20m55s across 30 shards
- **Lines:** 1,666/3,388 matching (49.2%)
- **Avg test duration:** 21.6s — slowest: `matrix_test` (67.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m03s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 20.4s — slowest: `levels` (22.0s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m20s across 30 shards
- **Lines:** 223/499 matching (44.7%)
- **Avg test duration:** 19.9s — slowest: `opcode_guard_test2` (20.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m30s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 19.3s — slowest: `jump_after_end` (20.6s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 15m07s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 19.3s — slowest: `stroke1` (21.5s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m23s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 19.2s — slowest: `loadevent` (21.1s)
