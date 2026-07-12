# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `ee21078608de`  
**Date:** 2026-07-12 23:36 UTC  
**Total duration:** 3h34m17s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 800 | 1204 | 66.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1835** | **2493** | **73.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 97,904 | 149,868 | 65.3% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **250,487** | **327,818** | **76.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 54 | - | 1 | - |
| avm2 | 377 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **478** | **4** | **1** | **1** |

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
| avm2 | edittext_autosize_lazy_bounds_interactions | 95% |
| avm2 | focusrect_property | 95% |
| avm2 | stylesheet_parse_color | 94% |
| avm2 | mouseevent_constr | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm2 | json_stringify | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | unescape | 89% |
| avm2 | perspective_projection_basic | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | bitmap_subclass | 86% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 48 | 1 | 7960 | 1 |

**avm2 — newly passing:** `asymmetric_key_events`, `avm2_catchup_dobj`, `click_block`, `click_invisible`, `drag_drop`, `edittext_at_point_methods_basic`, `edittext_input_control`, `edittext_mousedown`, `edittext_newline_character`, `edittext_paste_events`, `edittext_paste_maxchars`, `edittext_paste_restrict`, `edittext_restrict`, `edittext_restrict_events`, `edittext_selected_text`, `focus_events_code`, `focus_events_key_same_object`, `focus_events_mixed_key_mouse`, `focus_events_mouse_same_object`, `focus_root_movie`, `focus_stage`, `focusrect`, `issue_17675_edittext_paste_maxchars`, `key_input_80percent`, `key_input_location`, `key_input_numpad`, `mouse_click_events`, `mouse_double_click_events`, `mouse_empty_parent`, `mouse_over_while_dragging`, `mouse_pick_button_mode`, `mouse_sibling`, `movieclip_displayevents_clickgoto`, `movieclip_displayevents_clickgoto2`, `movieclip_displayevents_clickplay`, `movieclip_displayevents_clicksymbol`, `movieclip_drawrect`, `movieclip_text_mousedown`, `package_namespace`, `stage_mousechildren`, `swf_9_versioning`, `tab_ordering_automatic_advanced`, `tab_ordering_automatic_basic`, `tab_ordering_children`, `tab_ordering_custom_basic`, `textfield_focusin_event`, `textfield_input_dead_keys_windows`

**avm2 — newly failing:** `edittext_autosize_lazy_bounds_interactions`

*Comparing `2efd025eaf82` → `ee21078608de`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 51m02s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 4.3s — slowest: `netstream_play_flv_screen` (36.5s)

### avm2

- **Pass:** 800/1204 (66.4%)
- **Duration:** 1h28m31s across 30 shards
- **Lines:** 97,904/149,868 matching (65.3%)
- **Avg test duration:** 4.3s — slowest: `away3d_advanced_shallow_water_demo` (62.6s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 26m24s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.5s — slowest: `MovieClip-v8` (68.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 18m47s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 10.1s — slowest: `matrix_test` (76.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.2s — slowest: `function_test` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m16s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 12.7s — slowest: `movieclip_destruction_test2` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m55s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.7s — slowest: `zeroframe_definesprite` (21.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m45s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.9s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (22.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.2s — slowest: `duplicateMovieClip/dontremove` (20.8s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 4m58s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.2s — slowest: `timer_type1_args` (21.6s)
