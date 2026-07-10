# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `704a9cbbf212`  
**Date:** 2026-07-10 17:22 UTC  
**Total duration:** 2h57m45s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 14 | 14 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1008** | **1262** | **79.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,802 | 130,978 | 88.4% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 111 | 111 | 100% |
| **Total** | **152,439** | **177,801** | **85.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 54 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 14 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| regression | - | - |
| **Total** | **101** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `3593ca852413` → `704a9cbbf212`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 1h14m47s across 30 shards
- **Lines:** 115,802/130,978 matching (88.4%)
- **Avg test duration:** 6.3s — slowest: `netstream_play_flv_screen` (35.5s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 34m05s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 8.4s — slowest: `array-v6` (52.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 33m25s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 18.0s — slowest: `matrix_test` (102.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.0s — slowest: `function_test` (21.7s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m48s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.4s — slowest: `edittext_test1` (22.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m22s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.1s — slowest: `dict_cross` (21.7s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m11s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.2s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (22.1s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m35s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.3s — slowest: `duplicateMovieClip/dontremove` (21.8s)

### regression

- **Pass:** 14/14 (100%)
- **Duration:** 4m22s across 30 shards
- **Lines:** 111/111 matching (100%)
- **Avg test duration:** 18.7s — slowest: `fn_call_builtin_type1_args` (21.2s)
