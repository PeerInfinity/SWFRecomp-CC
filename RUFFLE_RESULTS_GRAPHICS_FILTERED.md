# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `63ca22e398c4`  
**Date:** 2026-07-21 23:49 UTC  
**Total duration:** 5h45m12s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 608 | 642 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 701 | 956 | 73.3% ⚠️ | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 127 | 228 | 55.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 105 | 61.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 6 | 8 | 75.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 10 | 17 | 58.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 70 | 73 | 95.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 42 | 42 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| regression | 57 | 57 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| **Total** | **1704** | **2147** | **79.4%** | |

*293 tests ignored.*

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
| avm1 | 99,515 | 103,177 | 96.5% |
| avm2 | 92,055 | 123,084 | 74.8% |
| from_gnash/actionscript.all | 28,591 | 30,678 | 93.2% |
| from_gnash/misc-ming.all | 3,966 | 5,099 | 77.8% |
| from_gnash/misc-mtasc.all | 194 | 214 | 90.7% |
| from_gnash/misc-swfc.all | 409 | 543 | 75.3% |
| from_gnash/misc-swfmill.all | 90 | 92 | 97.8% |
| from_shumway | 601 | 617 | 97.4% |
| from_shumway/avm1 | 467 | 467 | 100% |
| regression | 399 | 399 | 100% |
| **Total** | **226,287** | **264,370** | **85.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| avm1 | 22 | 12 | - |
| avm2 | 250 | 2 | 3 |
| from_gnash/actionscript.all | 9 | 92 | - |
| from_gnash/misc-ming.all | 13 | 27 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **297** | **143** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| avm2 | stylesheet | 100% |
| avm2 | string_slice_substr_substring | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | parse_float | 99% |
| avm2 | parse_int | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | string_concat_fromcharcode | 97% |
| avm2 | movieclip_hittest | 97% |
| avm2 | xml_basic | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
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
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Per-Suite Details

### avm1

- **Pass:** 608/642 (94.7%)
- **Ignored:** 45 tests
- **Duration:** 1h19m57s across 29 shards
- **Lines:** 99,515/103,177 matching (96.5%)
- **Avg test duration:** 7.0s — slowest: `assetnative` (32.5s)

### avm2

- **Pass:** 701/956 (73.3%)
- **Ignored:** 218 tests
- **Duration:** 2h35m07s across 29 shards
- **Lines:** 92,055/123,084 matching (74.8%)
- **Avg test duration:** 7.2s — slowest: `bitmapdata_accuracy` (47.1s)

### from_gnash/actionscript.all

- **Pass:** 127/228 (55.7%)
- **Ignored:** 7 tests
- **Duration:** 33m42s across 29 shards
- **Lines:** 28,591/30,678 matching (93.2%)
- **Avg test duration:** 8.5s — slowest: `MovieClip-v8` (66.3s)

### from_gnash/misc-ming.all

- **Pass:** 65/105 (61.9%)
- **Ignored:** 2 tests
- **Duration:** 33m03s across 29 shards
- **Lines:** 3,966/5,099 matching (77.8%)
- **Avg test duration:** 18.5s — slowest: `matrix_test` (108.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m03s across 29 shards
- **Lines:** 194/214 matching (90.7%)
- **Avg test duration:** 15.3s — slowest: `function_test` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 10/17 (58.8%)
- **Ignored:** 2 tests
- **Duration:** 5m35s across 29 shards
- **Lines:** 409/543 matching (75.3%)
- **Avg test duration:** 18.3s — slowest: `movieclip_destruction_test2` (23.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m12s across 29 shards
- **Lines:** 90/92 matching (97.8%)
- **Avg test duration:** 19.5s — slowest: `background` (21.8s)

### from_shumway

- **Pass:** 70/73 (95.9%)
- **Ignored:** 16 tests
- **Duration:** 14m13s across 29 shards
- **Lines:** 601/617 matching (97.4%)
- **Avg test duration:** 7.1s — slowest: `gradientTransform` (21.9s)

### from_shumway/avm1

- **Pass:** 42/42 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m54s across 29 shards
- **Lines:** 467/467 matching (100%)
- **Avg test duration:** 2.0s — slowest: `duplicateMovieClip/dontremove` (20.6s)

### regression

- **Pass:** 57/57 (100%)
- **Duration:** 13m22s across 29 shards
- **Lines:** 399/399 matching (100%)
- **Avg test duration:** 14.0s — slowest: `avm2_tolerant_verify_quarantine` (33.9s)
