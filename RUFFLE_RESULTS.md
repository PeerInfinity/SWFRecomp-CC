# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9d4d8742948b`  
**Date:** 2026-04-09 01:53 UTC  
**Total duration:** 5h28m07s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 575 | 620 | 92.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 76 | 190 | 40.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 9 | 58 | 15.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **709** | **977** | **72.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 82,668 | 91,594 | 90.3% |
| from_gnash/actionscript.all | 12,685 | 16,957 | 74.8% |
| from_gnash/misc-ming.all | 1,668 | 3,388 | 49.2% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 223 | 499 | 44.7% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **97,595** | **113,265** | **86.2%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 45 | - |
| from_gnash/actionscript.all | 114 | - |
| from_gnash/misc-ming.all | 49 | - |
| from_gnash/misc-mtasc.all | 2 | - |
| from_gnash/misc-swfc.all | 13 | 1 |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | 30 | - |
| from_shumway/avm1 | 10 | 1 |
| **Total** | **266** | **2** |

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
| from_gnash/actionscript.all | Color-v6 | 98% |
| from_gnash/actionscript.all | Math-v5 | 98% |
| from_gnash/actionscript.all | Math-v6 | 98% |
| avm1 | is_finite | 98% |
| avm1 | is_finite_swf6 | 98% |
| from_gnash/actionscript.all | Inheritance-v8 | 98% |
| avm1 | movieclip_library_state_values | 97% |
| avm1 | swf5_global_funcs | 97% |
| avm1 | swf6_global_funcs | 97% |
| avm1 | swf7_global_funcs | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| from_gnash/actionscript.all | ops-v8 | 97% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| avm1 | function_as_function | 94% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Number-v7 | 91% |
| from_gnash/actionscript.all | Number-v8 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| from_gnash/actionscript.all | Selection-v6 | 90% |
| from_gnash/actionscript.all | Number-v5 | 89% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | Error-v6 | 87% |
| from_gnash/actionscript.all | Error-v7 | 87% |
| from_gnash/actionscript.all | Error-v8 | 87% |
| from_gnash/actionscript.all | Number-v6 | 87% |
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
| avm1 | 2 | 5 | 109 | 20 |
| from_gnash/actionscript.all | - | - | 100 | 1 |
| from_gnash/misc-ming.all | 1 | - | 6 | - |
| from_gnash/misc-swfc.all | - | - | 3 | - |

**avm1 — newly passing:** `equals_swf4`, `lessthan_swf4`

**avm1 — newly failing:** `is_finite`, `is_finite_swf6`, `swf5_global_funcs`, `swf6_global_funcs`, `swf7_global_funcs`

**from_gnash/misc-ming.all — newly passing:** `getTimer_test`

*Comparing `2a4adfc3fdc2` → `9d4d8742948b`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 575/620 (92.7%)
- **Duration:** 3h21m16s across 30 shards
- **Lines:** 82,668/91,594 matching (90.3%)
- **Avg test duration:** 19.4s — slowest: `movieclip_invalid_get_bounds_6` (43.1s)

### from_gnash/actionscript.all

- **Pass:** 76/190 (40.0%)
- **Duration:** 1h10m45s across 30 shards
- **Lines:** 12,685/16,957 matching (74.8%)
- **Avg test duration:** 22.3s — slowest: `array-v5` (44.4s)

### from_gnash/misc-ming.all

- **Pass:** 9/58 (15.5%)
- **Duration:** 20m52s across 30 shards
- **Lines:** 1,668/3,388 matching (49.2%)
- **Avg test duration:** 21.5s — slowest: `matrix_test` (70.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m57s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 19.7s — slowest: `levels` (21.4s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m18s across 30 shards
- **Lines:** 223/499 matching (44.7%)
- **Avg test duration:** 19.9s — slowest: `opcode_guard_test2` (22.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m27s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 19.0s — slowest: `jump_to_prev_block` (20.5s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 15m04s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 19.2s — slowest: `flash_events_Event` (20.5s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m24s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 19.3s — slowest: `watch` (20.5s)
