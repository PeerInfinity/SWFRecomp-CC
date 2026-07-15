# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e05a8fe0d131`  
**Date:** 2026-07-15 03:39 UTC  
**Total duration:** 4h07m55s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 707 | 89.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 829 | 1205 | 68.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 42 | 42 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1865** | **2496** | **74.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,814 | 131,124 | 88.3% |
| avm2 | 102,546 | 149,869 | 68.4% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 262 | 262 | 100% |
| **Total** | **255,148** | **327,967** | **77.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 55 | - | 1 | - |
| avm2 | 347 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **449** | **4** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| avm2 | focusrect_property | 95% |
| avm2 | stylesheet_parse_color | 94% |
| avm2 | mouseevent_constr | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm2 | json_stringify | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
| avm2 | unescape | 89% |
| avm2 | perspective_projection_basic | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm2 | matrix | 83% |
| avm1 | load_vars | 83% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `3b5a6b925a3e` → `e05a8fe0d131`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/707 (89.7%)
- **Duration:** 48m36s across 30 shards
- **Lines:** 115,814/131,124 matching (88.3%)
- **Avg test duration:** 4.1s — slowest: `netstream_play_flv_screen` (35.5s)

### avm2

- **Pass:** 829/1205 (68.8%)
- **Duration:** 2h07m20s across 30 shards
- **Lines:** 102,546/149,869 matching (68.4%)
- **Avg test duration:** 6.3s — slowest: `away3d_advanced_shallow_water_demo` (69.7s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 25m31s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.2s — slowest: `MovieClip-v8` (63.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 18m15s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 9.8s — slowest: `matrix_test` (87.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m44s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.6s — slowest: `function_test` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 3m57s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 11.8s — slowest: `movieclip_destruction_test3` (20.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m43s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.1s — slowest: `zeroframe_definesprite` (20.3s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m11s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.5s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (21.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.1s — slowest: `duplicateMovieClip/dontremove` (20.8s)

### regression

- **Pass:** 42/42 (100%)
- **Duration:** 4m52s across 30 shards
- **Lines:** 262/262 matching (100%)
- **Avg test duration:** 6.9s — slowest: `watch_cross_swf_version` (19.9s)
