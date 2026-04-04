# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `7a348be46a51`  
**Date:** 2026-04-04 01:50 UTC  
**Total duration:** 4h55m49s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 532 | 578 | 92.0% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 60 | 177 | 33.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 8 | 55 | 14.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 4 | 8 | 50.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 10 | 13 | 76.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 15 | 43 | 34.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 10 | 21 | 47.6% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **641** | **911** | **70.4%** | |

### ⚠️ Incomplete Runs

- **avm1**: 28/30 shards produced results (2 missing)
- **from_gnash/actionscript.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-ming.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-mtasc.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-swfc.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-swfmill.all**: 28/30 shards produced results (2 missing)
- **from_shumway**: 28/30 shards produced results (2 missing)
- **from_shumway/avm1**: 28/30 shards produced results (2 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 77,496 | 87,247 | 88.8% |
| from_gnash/actionscript.all | 11,447 | 15,780 | 72.5% |
| from_gnash/misc-ming.all | 1,601 | 3,321 | 48.2% |
| from_gnash/misc-mtasc.all | 140 | 205 | 68.3% |
| from_gnash/misc-swfc.all | 216 | 511 | 42.3% |
| from_gnash/misc-swfmill.all | 22 | 26 | 84.6% |
| from_shumway | 35 | 237 | 14.8% |
| from_shumway/avm1 | 110 | 303 | 36.3% |
| **Total** | **91,067** | **107,630** | **84.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 43 | - | 2 | 1 |
| from_gnash/actionscript.all | 117 | - | - | - |
| from_gnash/misc-ming.all | 46 | - | 1 | - |
| from_gnash/misc-mtasc.all | 4 | - | - | - |
| from_gnash/misc-swfc.all | 13 | 1 | - | - |
| from_gnash/misc-swfmill.all | 3 | - | - | - |
| from_shumway | 28 | - | - | - |
| from_shumway/avm1 | 10 | 1 | - | - |
| **Total** | **264** | **2** | **3** | **1** |

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
| from_gnash/actionscript.all | ops-v8 | 97% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| avm1 | movieclip_hittest_shapeflag | 96% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Key-v5 | 92% |
| avm1 | native_objects_swf7 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| avm1 | native_objects_swf8 | 90% |
| from_gnash/actionscript.all | Selection-v7 | 89% |
| from_gnash/actionscript.all | Selection-v8 | 89% |
| from_gnash/actionscript.all | Selection-v6 | 88% |
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
| avm1 | 2 | - | 20 | - |
| from_gnash/misc-ming.all | - | - | 50 | - |

**avm1 — newly passing:** `asfunction`, `edittext_ime_focus_lost`

*Comparing `8fb3f39023e1` → `7a348be46a51`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 1 | 3 | 33.3% |

## Per-Suite Details

### avm1

- **Pass:** 532/578 (92.0%)
- **Duration:** 3h01m32s across 28 shards
- **Lines:** 77,496/87,247 matching (88.8%)
- **Avg test duration:** 18.8s — slowest: `timeout` (49.1s)

### from_gnash/actionscript.all

- **Pass:** 60/177 (33.9%)
- **Duration:** 1h03m35s across 28 shards
- **Lines:** 11,447/15,780 matching (72.5%)
- **Avg test duration:** 21.5s — slowest: `array-v5` (46.1s)

### from_gnash/misc-ming.all

- **Pass:** 8/55 (14.5%)
- **Duration:** 19m05s across 28 shards
- **Lines:** 1,601/3,321 matching (48.2%)
- **Avg test duration:** 20.8s — slowest: `matrix_test` (72.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 4/8 (50.0%)
- **Duration:** 2m35s across 28 shards
- **Lines:** 140/205 matching (68.3%)
- **Avg test duration:** 19.4s — slowest: `levels` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m08s across 28 shards
- **Lines:** 216/511 matching (42.3%)
- **Avg test duration:** 19.2s — slowest: `action_execution_order_test10` (20.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 10/13 (76.9%)
- **Duration:** 4m02s across 28 shards
- **Lines:** 22/26 matching (84.6%)
- **Avg test duration:** 18.6s — slowest: `afunc_dict` (19.7s)

### from_shumway

- **Pass:** 15/43 (34.9%)
- **Duration:** 13m16s across 28 shards
- **Lines:** 35/237 matching (14.8%)
- **Avg test duration:** 18.5s — slowest: `3_joystick` (19.9s)

### from_shumway/avm1

- **Pass:** 10/21 (47.6%)
- **Duration:** 6m33s across 28 shards
- **Lines:** 110/303 matching (36.3%)
- **Avg test duration:** 18.7s — slowest: `array` (19.9s)
