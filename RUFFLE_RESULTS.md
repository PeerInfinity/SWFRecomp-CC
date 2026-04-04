# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `57ba121d1486`  
**Date:** 2026-04-04 17:24 UTC  
**Total duration:** 5h17m05s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 572 | 620 | 92.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 68 | 190 | 35.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 7 | 58 | 12.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 4 | 9 | 44.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **693** | **977** | **70.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 81,332 | 91,594 | 88.8% |
| from_gnash/actionscript.all | 12,423 | 16,957 | 73.3% |
| from_gnash/misc-ming.all | 1,643 | 3,388 | 48.5% |
| from_gnash/misc-mtasc.all | 163 | 231 | 70.6% |
| from_gnash/misc-swfc.all | 223 | 499 | 44.7% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **95,962** | **113,265** | **84.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 45 | - | 2 | 1 |
| from_gnash/actionscript.all | 122 | - | - | - |
| from_gnash/misc-ming.all | 50 | - | 1 | - |
| from_gnash/misc-mtasc.all | 5 | - | - | - |
| from_gnash/misc-swfc.all | 13 | 1 | - | - |
| from_gnash/misc-swfmill.all | 3 | - | - | - |
| from_shumway | 30 | - | - | - |
| from_shumway/avm1 | 10 | 1 | - | - |
| **Total** | **278** | **2** | **3** | **1** |

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
| from_gnash/actionscript.all | Color-v6 | 96% |
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
| from_gnash/misc-mtasc.all | function_test | 88% |
| from_gnash/actionscript.all | Selection-v6 | 88% |
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
| avm1 | - | - | 3 | - |
| from_gnash/actionscript.all | - | - | - | 2 |
| from_gnash/misc-ming.all | - | 1 | - | 3 |

**from_gnash/misc-ming.all — newly failing:** `getTimer_test`

*Comparing `4b79110d60c6` → `57ba121d1486`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 1 | 3 | 33.3% |

## Per-Suite Details

### avm1

- **Pass:** 572/620 (92.3%)
- **Duration:** 3h15m01s across 30 shards
- **Lines:** 81,332/91,594 matching (88.8%)
- **Avg test duration:** 18.8s — slowest: `timeout` (48.3s)

### from_gnash/actionscript.all

- **Pass:** 68/190 (35.8%)
- **Duration:** 1h08m10s across 30 shards
- **Lines:** 12,423/16,957 matching (73.3%)
- **Avg test duration:** 21.5s — slowest: `array-v5` (43.3s)

### from_gnash/misc-ming.all

- **Pass:** 7/58 (12.1%)
- **Duration:** 20m02s across 30 shards
- **Lines:** 1,643/3,388 matching (48.5%)
- **Avg test duration:** 20.7s — slowest: `matrix_test` (67.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 4/9 (44.4%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 163/231 matching (70.6%)
- **Avg test duration:** 19.2s — slowest: `levels` (20.3s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m06s across 30 shards
- **Lines:** 223/499 matching (44.7%)
- **Avg test duration:** 19.1s — slowest: `swf4opcode` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m17s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 18.3s — slowest: `tags_after_last_showframe` (19.3s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 14m25s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 18.4s — slowest: `as3-interfaces` (20.0s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m08s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 18.6s — slowest: `externalinterface` (21.3s)
