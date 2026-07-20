# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `a35afa7b8a05`  
**Date:** 2026-07-20 00:30 UTC  
**Total duration:** 5h06m32s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 635 | 711 | 89.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 823 | 1215 | 67.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 56 | 56 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1873** | **2524** | **74.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,824 | 131,157 | 88.3% |
| avm2 | 103,124 | 151,085 | 68.3% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,048 | 5,248 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 377 | 377 | 100% |
| **Total** | **255,842** | **329,331** | **77.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 58 | - | 1 | - |
| avm2 | 362 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 15 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **469** | **4** | **1** | **1** |

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

*Comparing `bf4f4567137a` → `a35afa7b8a05`*

## Per-Suite Details

### avm1

- **Pass:** 635/711 (89.3%)
- **Duration:** 1h05m26s across 30 shards
- **Lines:** 115,824/131,157 matching (88.3%)
- **Avg test duration:** 5.5s — slowest: `netstream_play_flv_screen` (36.8s)

### avm2

- **Pass:** 823/1215 (67.7%)
- **Duration:** 2h31m13s across 30 shards
- **Lines:** 103,124/151,085 matching (68.3%)
- **Avg test duration:** 7.4s — slowest: `away3d_advanced_shallow_water_demo` (79.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 27m25s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.7s — slowest: `MovieClip-v8` (66.7s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 28m58s across 30 shards
- **Lines:** 4,048/5,248 matching (77.1%)
- **Avg test duration:** 15.6s — slowest: `matrix_test` (99.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.2s — slowest: `implementsOpTest` (21.5s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m00s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 15.0s — slowest: `hello` (22.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m54s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.7s — slowest: `trace-as2/arguments` (21.1s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m28s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.4s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (23.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m11s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.7s — slowest: `label` (21.3s)

### regression

- **Pass:** 56/56 (100%)
- **Duration:** 7m03s across 30 shards
- **Lines:** 377/377 matching (100%)
- **Avg test duration:** 7.5s — slowest: `broadcast_cross_swf_version` (22.5s)
