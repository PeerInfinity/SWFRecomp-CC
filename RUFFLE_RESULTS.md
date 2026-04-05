# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `bb4ebc9a2da5`  
**Date:** 2026-04-05 20:14 UTC  
**Total duration:** 5h20m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 571 | 620 | 92.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 76 | 190 | 40.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 8 | 58 | 13.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 6 | 9 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **703** | **977** | **72.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 81,321 | 91,594 | 88.8% |
| from_gnash/actionscript.all | 12,458 | 16,957 | 73.5% |
| from_gnash/misc-ming.all | 1,646 | 3,388 | 48.6% |
| from_gnash/misc-mtasc.all | 170 | 231 | 73.6% |
| from_gnash/misc-swfc.all | 223 | 499 | 44.7% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **95,996** | **113,265** | **84.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 46 | - | 2 | 1 |
| from_gnash/actionscript.all | 114 | - | - | - |
| from_gnash/misc-ming.all | 49 | - | 1 | - |
| from_gnash/misc-mtasc.all | 3 | - | - | - |
| from_gnash/misc-swfc.all | 13 | 1 | - | - |
| from_gnash/misc-swfmill.all | 3 | - | - | - |
| from_shumway | 30 | - | - | - |
| from_shumway/avm1 | 10 | 1 | - | - |
| **Total** | **268** | **2** | **3** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
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
| from_gnash/actionscript.all | Color-v6 | 96% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| avm1 | native_objects_swf7 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| from_gnash/actionscript.all | Selection-v6 | 90% |
| avm1 | native_objects_swf8 | 90% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | Error-v6 | 87% |
| from_gnash/actionscript.all | Error-v7 | 87% |
| from_gnash/actionscript.all | Error-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/misc-mtasc.all | inheritance | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | Error-v5 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | Inheritance-v5 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_shumway/avm1 | nativeinheritance | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | System-v7 | 82% |
| from_gnash/actionscript.all | System-v8 | 82% |
| from_gnash/actionscript.all | System-v6 | 82% |
| from_gnash/actionscript.all | Number-v7 | 81% |
| from_gnash/actionscript.all | Number-v8 | 81% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 9 | - |
| from_gnash/misc-mtasc.all | 1 | - | 4 | - |

**from_gnash/misc-mtasc.all — newly passing:** `super_test1`

*Comparing `efe5336fbda2` → `bb4ebc9a2da5`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 571/620 (92.1%)
- **Duration:** 3h17m05s across 30 shards
- **Lines:** 81,321/91,594 matching (88.8%)
- **Avg test duration:** 19.0s — slowest: `timeout` (48.5s)

### from_gnash/actionscript.all

- **Pass:** 76/190 (40.0%)
- **Duration:** 1h09m12s across 30 shards
- **Lines:** 12,458/16,957 matching (73.5%)
- **Avg test duration:** 21.8s — slowest: `array-v5` (44.6s)

### from_gnash/misc-ming.all

- **Pass:** 8/58 (13.8%)
- **Duration:** 20m22s across 30 shards
- **Lines:** 1,646/3,388 matching (48.6%)
- **Avg test duration:** 21.0s — slowest: `matrix_test` (70.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 6/9 (66.7%)
- **Duration:** 2m55s across 30 shards
- **Lines:** 170/231 matching (73.6%)
- **Avg test duration:** 19.4s — slowest: `levels` (22.2s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m09s across 30 shards
- **Lines:** 223/499 matching (44.7%)
- **Avg test duration:** 19.3s — slowest: `movieclip_destruction_test2` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m20s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 18.5s — slowest: `initaction_in_definesprite` (19.8s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 14m36s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 18.6s — slowest: `lzma` (20.1s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m12s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 18.7s — slowest: `text-bind` (20.4s)
