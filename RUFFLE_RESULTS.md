# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e70514bf6a0f`  
**Date:** 2026-04-11 23:14 UTC  
**Total duration:** 5h34m23s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 580 | 620 | 93.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 88 | 190 | 46.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 9 | 58 | 15.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 21 | 23 | 91.3% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **735** | **977** | **75.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 82,683 | 91,594 | 90.3% |
| from_gnash/actionscript.all | 12,839 | 16,957 | 75.7% |
| from_gnash/misc-ming.all | 1,669 | 3,388 | 49.3% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 224 | 499 | 44.9% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 303 | 311 | 97.4% |
| **Total** | **97,951** | **113,265** | **86.5%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 40 | - |
| from_gnash/actionscript.all | 102 | - |
| from_gnash/misc-ming.all | 49 | - |
| from_gnash/misc-mtasc.all | 2 | - |
| from_gnash/misc-swfc.all | 13 | 1 |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | 30 | - |
| from_shumway/avm1 | 2 | - |
| **Total** | **241** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
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
| avm1 | 20 | - | 820 | 5 |
| from_gnash/actionscript.all | - | - | 2 | - |
| from_gnash/misc-ming.all | 1 | - | 13 | 1 |
| from_gnash/misc-mtasc.all | - | - | 1 | - |
| from_shumway/avm1 | 2 | - | 148 | - |

**avm1 — newly passing:** `button_keypress`, `call`, `do_init_action_child`, `global_swf5_6_7_8_9`, `global_swf6_7_8`, `interface_implements_op`, `loadmovie_flashvars`, `loadmovienum_cross_version_prototype`, `movieclip_invalid_get_bounds_1`, `movieclip_invalid_get_bounds_2`, `movieclip_invalid_get_bounds_3`, `movieclip_invalid_get_bounds_4`, `movieclip_invalid_get_bounds_5`, `movieclip_invalid_get_bounds_6`, `movieclip_invalid_get_bounds_7`, `movieclip_invalid_get_bounds_8`, `moviecliploader_flashvars`, `on_construct`, `root_button_mode`, `string_paths_variable_scopes`

**from_gnash/misc-ming.all — newly passing:** `unload_movieclip_test1`

**from_shumway/avm1 — newly passing:** `filters`, `levels`

*Comparing `7b73007a454e` → `e70514bf6a0f`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 580/620 (93.5%)
- **Duration:** 3h25m28s across 30 shards
- **Lines:** 82,683/91,594 matching (90.3%)
- **Avg test duration:** 19.8s — slowest: `movieclip_invalid_get_bounds_6` (44.0s)

### from_gnash/actionscript.all

- **Pass:** 88/190 (46.3%)
- **Duration:** 1h11m51s across 30 shards
- **Lines:** 12,839/16,957 matching (75.7%)
- **Avg test duration:** 22.6s — slowest: `array-v5` (45.8s)

### from_gnash/misc-ming.all

- **Pass:** 9/58 (15.5%)
- **Duration:** 21m16s across 30 shards
- **Lines:** 1,669/3,388 matching (49.3%)
- **Avg test duration:** 21.9s — slowest: `matrix_test` (71.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m01s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 20.1s — slowest: `levels` (21.7s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m24s across 30 shards
- **Lines:** 224/499 matching (44.9%)
- **Avg test duration:** 20.2s — slowest: `opcode_guard_test2` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m31s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 19.3s — slowest: `jump_to_prev_block` (20.3s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 15m20s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 19.5s — slowest: `flash_net_SharedObject` (20.6s)

### from_shumway/avm1

- **Pass:** 21/23 (91.3%)
- **Duration:** 7m30s across 30 shards
- **Lines:** 303/311 matching (97.4%)
- **Avg test duration:** 19.5s — slowest: `lookup` (20.6s)
