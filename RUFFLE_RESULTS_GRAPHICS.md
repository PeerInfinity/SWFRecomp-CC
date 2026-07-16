# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `a05b56ddf072`  
**Date:** 2026-07-16 22:53 UTC  
**Total duration:** 3h55m05s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 612 | 685 | 89.3% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 793 | 1170 | 67.8% ⚠️ | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| from_gnash/actionscript.all | 131 | 235 | 55.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 67 | 108 | 62.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 72 | 89 | 80.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 45 | 46 | 97.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 44 | 44 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1801** | **2426** | **74.2%** | |

### ⚠️ Incomplete Runs

- **avm1**: 29/30 shards produced results (1 missing)
- **avm2**: 29/30 shards produced results (1 missing)
- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)
- **from_shumway**: 29/30 shards produced results (1 missing)
- **from_shumway/avm1**: 29/30 shards produced results (1 missing)
- **regression**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 113,501 | 128,808 | 88.1% |
| avm2 | 102,577 | 149,334 | 68.7% |
| from_gnash/actionscript.all | 27,728 | 36,033 | 77.0% |
| from_gnash/misc-ming.all | 4,035 | 5,204 | 77.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 848 | 1,207 | 70.3% |
| from_shumway/avm1 | 450 | 452 | 99.6% |
| regression | 276 | 276 | 100% |
| **Total** | **250,157** | **322,220** | **77.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 56 | - | 1 | - |
| avm2 | 347 | 4 | - | 1 |
| from_gnash/actionscript.all | 9 | - | - | - |
| from_gnash/misc-ming.all | 15 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 14 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **446** | **4** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm2 | string_slice_substr_substring | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | parse_float | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | parse_int | 98% |
| avm2 | error_tostring_more | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | string_concat_fromcharcode | 97% |
| avm2 | movieclip_hittest | 97% |
| avm2 | xml_basic | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| avm2 | parse_float_swf10 | 96% |
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
| avm2 | edittext_mouse_selection | 92% |
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

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 1 | - |

*Comparing `aca2a606e973` → `a05b56ddf072`*

## Per-Suite Details

### avm1

- **Pass:** 612/685 (89.3%)
- **Duration:** 44m21s across 29 shards
- **Lines:** 113,501/128,808 matching (88.1%)
- **Avg test duration:** 3.8s — slowest: `netstream_play_flv_screen` (36.2s)

### avm2

- **Pass:** 793/1170 (67.8%)
- **Duration:** 2h05m09s across 29 shards
- **Lines:** 102,577/149,334 matching (68.7%)
- **Avg test duration:** 6.4s — slowest: `away3d_advanced_shallow_water_demo` (74.0s)

### from_gnash/actionscript.all

- **Pass:** 131/235 (55.7%)
- **Duration:** 25m42s across 29 shards
- **Lines:** 27,728/36,033 matching (77.0%)
- **Avg test duration:** 6.5s — slowest: `MovieClip-v8` (64.1s)

### from_gnash/misc-ming.all

- **Pass:** 67/108 (62.0%)
- **Duration:** 16m42s across 29 shards
- **Lines:** 4,035/5,204 matching (77.5%)
- **Avg test duration:** 9.2s — slowest: `matrix_test` (103.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m33s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.4s — slowest: `enum` (21.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 3m12s across 29 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 9.6s — slowest: `action_execution_order_test12` (22.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m51s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.5s — slowest: `background` (22.0s)

### from_shumway

- **Pass:** 72/89 (80.9%)
- **Duration:** 10m53s across 29 shards
- **Lines:** 848/1,207 matching (70.3%)
- **Avg test duration:** 7.3s — slowest: `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` (22.2s)

### from_shumway/avm1

- **Pass:** 45/46 (97.8%)
- **Duration:** 1m57s across 29 shards
- **Lines:** 450/452 matching (99.6%)
- **Avg test duration:** 2.5s — slowest: `text-bind` (21.4s)

### regression

- **Pass:** 44/44 (100%)
- **Duration:** 2m39s across 29 shards
- **Lines:** 276/276 matching (100%)
- **Avg test duration:** 3.6s — slowest: `timer_type1_args` (20.6s)
