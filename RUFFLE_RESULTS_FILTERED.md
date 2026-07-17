# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `c0e0b3493697`  
**Date:** 2026-07-17 05:05 UTC  
**Total duration:** 3h46m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 631 | 663 | 95.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 727 | 983 | 74.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| regression | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| **Total** | **1759** | **2205** | **79.8%** | |

*302 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,053 | 107,692 | 96.6% |
| avm2 | 95,015 | 125,449 | 75.7% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| regression | 298 | 298 | 100% |
| **Total** | **234,477** | **271,983** | **86.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| avm1 | 20 | 12 | - |
| avm2 | 250 | 2 | 4 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 13 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **294** | **148** | **4** |

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
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 631/663 (95.2%)
- **Ignored:** 45 tests
- **Duration:** 36m46s across 30 shards
- **Lines:** 104,053/107,692 matching (96.6%)
- **Avg test duration:** 3.0s — slowest: `movieclip_invalid_get_bounds_6` (26.4s)

### avm2

- **Pass:** 727/983 (74.0%)
- **Ignored:** 227 tests
- **Duration:** 2h04m11s across 30 shards
- **Lines:** 95,015/125,449 matching (75.7%)
- **Avg test duration:** 5.4s — slowest: `bitmapdata_accuracy` (45.8s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 24m52s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 6.0s — slowest: `MovieClip-v8` (67.8s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 15m34s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 8.3s — slowest: `matrix_test` (106.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.6s — slowest: `exception` (21.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 3m26s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 10.2s — slowest: `movieclip_destruction_test1` (22.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m54s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.7s — slowest: `trace-as2/arguments` (21.0s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 10m16s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 4.7s — slowest: `avm1/text-bind` (20.4s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m31s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.5s — slowest: `label` (20.7s)

### regression

- **Pass:** 47/47 (100%)
- **Duration:** 5m17s across 30 shards
- **Lines:** 298/298 matching (100%)
- **Avg test duration:** 6.7s — slowest: `lv_cross_swf_version` (21.1s)
