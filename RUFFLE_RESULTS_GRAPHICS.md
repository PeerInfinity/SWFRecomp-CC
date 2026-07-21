# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `63ca22e398c4`  
**Date:** 2026-07-21 23:49 UTC  
**Total duration:** 5h45m12s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 611 | 687 | 88.9% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 790 | 1174 | 67.3% ⚠️ | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| from_gnash/actionscript.all | 130 | 235 | 55.3% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 66 | 107 | 61.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 6 | 8 | 75.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 10 | 19 | 52.6% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 70 | 89 | 78.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 44 | 45 | 97.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 57 | 57 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1802** | **2440** | **73.9%** | |

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
| avm1 | 111,277 | 126,610 | 87.9% |
| avm2 | 99,710 | 146,921 | 67.9% |
| from_gnash/actionscript.all | 29,694 | 38,111 | 77.9% |
| from_gnash/misc-ming.all | 3,990 | 5,159 | 77.3% |
| from_gnash/misc-mtasc.all | 194 | 214 | 90.7% |
| from_gnash/misc-swfc.all | 426 | 568 | 75.0% |
| from_gnash/misc-swfmill.all | 90 | 92 | 97.8% |
| from_shumway | 862 | 1,256 | 68.6% |
| from_shumway/avm1 | 476 | 478 | 99.6% |
| regression | 399 | 399 | 100% |
| **Total** | **247,118** | **319,808** | **77.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 58 | - | 1 | - |
| avm2 | 357 | 3 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **463** | **3** | **1** | **1** |

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
| from_gnash/actionscript.all | array-v5 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | parse_int | 98% |
| avm2 | error_tostring_more | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | string_concat_fromcharcode | 97% |
| avm2 | movieclip_hittest | 97% |
| avm2 | xml_basic | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
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
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
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
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `93299b884de8` → `63ca22e398c4`*

## Per-Suite Details

### avm1

- **Pass:** 611/687 (88.9%)
- **Duration:** 1h19m57s across 29 shards
- **Lines:** 111,277/126,610 matching (87.9%)
- **Avg test duration:** 6.9s — slowest: `assetnative` (32.5s)

### avm2

- **Pass:** 790/1174 (67.3%)
- **Duration:** 2h35m07s across 29 shards
- **Lines:** 99,710/146,921 matching (67.9%)
- **Avg test duration:** 7.9s — slowest: `away3d_advanced_shallow_water_demo` (80.7s)

### from_gnash/actionscript.all

- **Pass:** 130/235 (55.3%)
- **Duration:** 33m42s across 29 shards
- **Lines:** 29,694/38,111 matching (77.9%)
- **Avg test duration:** 8.5s — slowest: `MovieClip-v8` (66.3s)

### from_gnash/misc-ming.all

- **Pass:** 66/107 (61.7%)
- **Duration:** 33m03s across 29 shards
- **Lines:** 3,990/5,159 matching (77.3%)
- **Avg test duration:** 18.5s — slowest: `matrix_test` (108.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m03s across 29 shards
- **Lines:** 194/214 matching (90.7%)
- **Avg test duration:** 15.3s — slowest: `function_test` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 10/19 (52.6%)
- **Duration:** 5m35s across 29 shards
- **Lines:** 426/568 matching (75.0%)
- **Avg test duration:** 17.6s — slowest: `movieclip_destruction_test2` (23.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m12s across 29 shards
- **Lines:** 90/92 matching (97.8%)
- **Avg test duration:** 19.5s — slowest: `background` (21.8s)

### from_shumway

- **Pass:** 70/89 (78.7%)
- **Duration:** 14m13s across 29 shards
- **Lines:** 862/1,256 matching (68.6%)
- **Avg test duration:** 9.5s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (22.9s)

### from_shumway/avm1

- **Pass:** 44/45 (97.8%)
- **Duration:** 1m54s across 29 shards
- **Lines:** 476/478 matching (99.6%)
- **Avg test duration:** 2.5s — slowest: `text-bind` (23.1s)

### regression

- **Pass:** 57/57 (100%)
- **Duration:** 13m22s across 29 shards
- **Lines:** 399/399 matching (100%)
- **Avg test duration:** 14.0s — slowest: `avm2_tolerant_verify_quarantine` (33.9s)
