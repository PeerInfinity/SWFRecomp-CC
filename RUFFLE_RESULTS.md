# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f76422459ffa`  
**Date:** 2026-07-12 05:29 UTC  
**Total duration:** 3h38m05s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 727 | 1201 | 60.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1762** | **2490** | **70.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 86,913 | 149,021 | 58.3% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **239,496** | **326,971** | **73.2%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 54 | - | 1 | - |
| avm2 | 448 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **549** | **4** | **1** | **1** |

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
| avm2 | property_is_enumerable_reset | 96% |
| avm2 | focusrect_property | 95% |
| avm2 | stylesheet_parse_color | 94% |
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
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 91 | - | 15960 | - |

**avm2 — newly passing:** `all_classes/security/swf11`, `button_nested_frame`, `cryptscore`, `displayobject_hittestobject`, `edittext_align`, `edittext_antialiastype`, `edittext_autosize`, `edittext_autosize_height_dynamic`, `edittext_autosize_height_input`, `edittext_autosize_lazy_bounds_events`, `edittext_autosize_lazy_bounds_interactions`, `edittext_autosize_lazy_bounds_props`, `edittext_autosize_lazy_bounds_vs_relayout`, `edittext_bottom_scroll_v_basic`, `edittext_bounds_scale`, `edittext_bullet`, `edittext_default_format`, `edittext_default_format_empty`, `edittext_empty_text_format`, `edittext_focus_selection`, `edittext_font_size`, `edittext_format_empty_font`, `edittext_get_line_index_of_char`, `edittext_getcharboundaries`, `edittext_getcharboundaries_missing_glyphs`, `edittext_getcharboundaries_scroll`, `edittext_getlinemetrics`, `edittext_html`, `edittext_html_condensewhite`, `edittext_html_entity`, `edittext_html_font_size_swf12`, `edittext_html_font_size_swf13`, `edittext_html_roundtrip`, `edittext_leading`, `edittext_letter_spacing`, `edittext_line_methods`, `edittext_line_metrics`, `edittext_margins`, `edittext_max_scroll_h_basic`, `edittext_max_scroll_v_basic`, `edittext_newline_stripping`, `edittext_newlines`, `edittext_paragraph_methods`, `edittext_scrollh`, `edittext_set_html_same`, `edittext_set_text_vs_html`, `edittext_stylesheet`, `edittext_stylesheet_custom_tag`, `edittext_stylesheet_display`, `edittext_underline`, `edittext_width_height`, `edittext_wordwrap_word`, `edittext_wrap_breaks`, `empty_bounds`, `focus_remove`, `font_description_clone`, `font_embedded`, `font_enumeratefonts`, `font_enumeratefonts_filter`, `font_hasglyphs`, `get_qualified_super_class_name`, `goto_button_nested_framescript`, `goto_nested_construct_sibling`, `hittest_morph`, `issue_5292`, `movieclip_frameconstruct_skipped`, `movieclip_next_scene`, `movieclip_prev_scene`, `place_object_replace_2`, `register_script_refresh`, `rootless`, `shape_drawrect`, `simplebutton_added_to_stage`, `simplebutton_childevents`, `simplebutton_childevents_nested`, `simplebutton_childevents_sprite`, `simplebutton_childprops`, `simplebutton_childshuffle`, `simplebutton_constr_childevents`, `simplebutton_symbolclass`, `text_engine_fontdescription`, `text_run`, `textfield_unload`, `textformat`, `textformat_display`, `textformat_font_max_length`, `trace`, `uncaught_errors_stringified`

*Comparing `b6fbe84479e3` → `f76422459ffa`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 51m31s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 4.3s — slowest: `netstream_play_flv_screen` (35.4s)

### avm2

- **Pass:** 727/1201 (60.5%)
- **Duration:** 1h29m44s across 30 shards
- **Lines:** 86,913/149,021 matching (58.3%)
- **Avg test duration:** 4.4s — slowest: `away3d_advanced_shallow_water_demo` (65.9s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 27m01s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.6s — slowest: `MovieClip-v8` (66.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 19m37s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 10.5s — slowest: `matrix_test` (101.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.1s — slowest: `hello` (20.7s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m23s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 13.1s — slowest: `movieclip_destruction_test4` (22.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.5s — slowest: `trace-as2/arguments` (21.9s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m06s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.1s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (22.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.3s — slowest: `duplicateMovieClip/dontremove` (20.1s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 5m09s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.5s — slowest: `onconstruct_cross_swf_version` (21.8s)
