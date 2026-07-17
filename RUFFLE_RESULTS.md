# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c0e0b3493697`  
**Date:** 2026-07-17 05:05 UTC  
**Total duration:** 3h46m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 708 | 89.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 822 | 1210 | 67.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1863** | **2507** | **74.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,815 | 131,125 | 88.3% |
| avm2 | 102,905 | 149,952 | 68.6% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 298 | 298 | 100% |
| **Total** | **255,544** | **328,087** | **77.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 56 | - | 1 | - |
| avm2 | 358 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **461** | **4** | **1** | **1** |

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
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 13 | - |

*Comparing `0ff10028b52a` → `c0e0b3493697`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/708 (89.5%)
- **Duration:** 36m46s across 30 shards
- **Lines:** 115,815/131,125 matching (88.3%)
- **Avg test duration:** 3.1s — slowest: `netstream_play_flv_screen` (35.4s)

### avm2

- **Pass:** 822/1210 (67.9%)
- **Duration:** 2h04m11s across 30 shards
- **Lines:** 102,905/149,952 matching (68.6%)
- **Avg test duration:** 6.1s — slowest: `away3d_advanced_shallow_water_demo` (72.4s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 24m52s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.1s — slowest: `MovieClip-v8` (67.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 15m34s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 8.4s — slowest: `matrix_test` (106.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.6s — slowest: `exception` (21.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 3m26s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 10.3s — slowest: `movieclip_destruction_test1` (22.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m54s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.7s — slowest: `trace-as2/arguments` (21.0s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 10m16s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 6.6s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (21.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m31s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.9s — slowest: `label` (20.7s)

### regression

- **Pass:** 47/47 (100%)
- **Duration:** 5m17s across 30 shards
- **Lines:** 298/298 matching (100%)
- **Avg test duration:** 6.7s — slowest: `lv_cross_swf_version` (21.1s)
