# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 02:01 UTC

**Git SHA**: `d482f825a7`

**Run Duration**: 31m 37s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **112** (18.2%) |
| Failing | 504 |
| Total expected lines | 89690 |
| Matching lines | 32614 (36.4%) |
| Mismatched lines | 57076 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 493 | 97.8% |
| Runtime Segfault | 5 | 1.0% |
| Timeout | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**112 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.6s |  |
| 2 | `action_to_integer` | 28 | 2.5s |  |
| 3 | `add` | 28 | 2.5s |  |
| 4 | `add2` | 354 | 2.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.4s |  |
| 6 | `add_swf5` | 28 | 2.5s |  |
| 7 | `array_concat` | 98 | 2.7s |  |
| 8 | `array_constructor` | 30 | 2.5s |  |
| 9 | `array_properties` | 36 | 2.5s |  |
| 10 | `array_slice` | 34 | 2.6s |  |
| 11 | `array_splice` | 207 | 3.2s |  |
| 12 | `array_trivial` | 209 | 3.0s |  |
| 13 | `as1_constructor_v6` | 35 | 2.6s |  |
| 14 | `as1_constructor_v7` | 35 | 2.6s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.4s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.5s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 2.4s |  |
| 18 | `bitand` | 1058 | 9.1s |  |
| 19 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 20 | `bitmap_data_fillrect` | 0 | 2.6s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 3.1s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 2.9s |  |
| 23 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.5s |  |
| 24 | `bitor` | 1058 | 9.0s |  |
| 25 | `biturshift` | 14 | 2.7s |  |
| 26 | `biturshift_swf8` | 14 | 2.5s |  |
| 27 | `bitxor` | 1058 | 9.6s |  |
| 28 | `catch_references_registers` | 2 | 2.5s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.4s |  |
| 30 | `delete` | 3 | 2.5s |  |
| 31 | `divide_swf4` | 107 | 2.6s |  |
| 32 | `do_init_action` | 3 | 2.5s |  |
| 33 | `equals` | 32 | 2.6s |  |
| 34 | `equals2_swf5` | 926 | 10.8s |  |
| 35 | `equals2_swf6` | 926 | 10.7s |  |
| 36 | `equals2_swf7` | 926 | 10.7s |  |
| 37 | `equals_swf4` | 665 | 6.0s |  |
| 38 | `equals_swf4_alt` | 32 | 2.5s |  |
| 39 | `equals_swf5` | 32 | 2.5s |  |
| 40 | `error` | 58 | 2.7s |  |
| 41 | `escape` | 14 | 2.5s |  |
| 42 | `focusrect_mouse_swf8` | 0 | 2.4s |  |
| 43 | `focusrect_mouse_swf9` | 0 | 2.4s |  |
| 44 | `focusrect_swf5` | 6 | 2.7s |  |
| 45 | `getproperty` | 28 | 2.5s |  |
| 46 | `getproperty_swf4` | 28 | 2.4s |  |
| 47 | `getproperty_swf5` | 28 | 2.5s |  |
| 48 | `global_array` | 3 | 2.4s |  |
| 49 | `global_is_bare` | 7 | 2.4s |  |
| 50 | `goto_advance2` | 2 | 2.5s |  |
| 51 | `goto_both_ways1` | 3 | 2.7s |  |
| 52 | `goto_both_ways2` | 3 | 2.6s |  |
| 53 | `goto_execution_order` | 2 | 2.5s |  |
| 54 | `goto_execution_order2` | 2 | 2.5s |  |
| 55 | `goto_rewind1` | 1 | 2.5s |  |
| 56 | `goto_rewind2` | 3 | 2.5s |  |
| 57 | `goto_rewind3` | 2 | 2.5s |  |
| 58 | `greater_swf6` | 1175 | 12.0s |  |
| 59 | `greater_swf7` | 1175 | 12.0s |  |
| 60 | `greaterthan_swf5` | 1 | 2.5s |  |
| 61 | `greaterthan_swf8` | 1 | 2.5s |  |
| 62 | `has_own_property` | 32 | 2.6s |  |
| 63 | `infinite_recursion_function` | 4 | 2.5s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 64 | `infinite_recursion_function_in_setter` | 131 | 2.5s |  |
| 65 | `infinite_recursion_virtual_property` | 67 | 2.5s |  |
| 66 | `init_array_invalid` | 4 | 2.5s |  |
| 67 | `init_object_invalid` | 4 | 2.5s |  |
| 68 | `issue_1086` | 1 | 2.5s |  |
| 69 | `issue_1671` | 0 | 2.5s |  |
| 70 | `issue_3446` | 1 | 2.5s |  |
| 71 | `issue_4377` | 2 | 2.5s |  |
| 72 | `issue_768` | 3 | 2.5s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 73 | `lessthan` | 41 | 2.7s |  |
| 74 | `lessthan2_swf5` | 1226 | 12.8s |  |
| 75 | `lessthan2_swf6` | 1226 | 13.0s |  |
| 76 | `lessthan2_swf7` | 1226 | 12.9s |  |
| 77 | `lessthan_swf4` | 902 | 8.7s |  |
| 78 | `lessthan_swf4_alt` | 41 | 2.6s |  |
| 79 | `lessthan_swf5` | 41 | 2.6s |  |
| 80 | `logical_ops_swf4` | 90 | 2.5s |  |
| 81 | `logical_ops_swf8` | 108 | 2.6s |  |
| 82 | `looping` | 6 | 2.5s |  |
| 83 | `mask_reapply` | 0 | 2.5s |  |
| 84 | `mask_with_drawing` | 0 | 2.5s |  |
| 85 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 86 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 87 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 88 | `nested_textfields_in_buttons` | 0 | 2.4s |  |
| 89 | `netstream_play_flv_screen` | 0 | 29.1s |  |
| 90 | `new_object_enumerate` | 7 | 2.4s |  |
| 91 | `object_function` | 32 | 2.5s |  |
| 92 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 93 | `primitive_instanceof` | 37 | 2.5s |  |
| 94 | `prototype_delete` | 12 | 2.5s |  |
| 95 | `sandbox_type_local_file` | 1 | 2.4s |  |
| 96 | `single_frame` | 1 | 2.4s |  |
| 97 | `sound_start_load` | 0 | 2.4s |  |
| 98 | `strictequals_swf6` | 902 | 8.7s |  |
| 99 | `strictly_equals` | 7 | 2.5s |  |
| 100 | `string_coercion` | 117 | 3.0s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 101 | `string_paths_keyevents` | 0 | 2.4s |  |
| 102 | `string_paths_timer` | 0 | 2.4s |  |
| 103 | `swf4_actions_bool` | 96 | 2.5s |  |
| 104 | `swf4_bool` | 4 | 2.4s |  |
| 105 | `swf5_encoding` | 3 | 3.4s |  |
| 106 | `this_swf7` | 41 | 2.5s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 107 | `timeline_function_def` | 7 | 2.5s |  |
| 108 | `try_finally_simple` | 16 | 2.5s |  |
| 109 | `typeof_globals` | 7 | 2.5s |  |
| 110 | `undefined_to_string_swf6` | 4 | 2.4s |  |
| 111 | `unescape` | 43 | 2.6s |  |
| 112 | `with_return` | 2 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**96 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `object_constructor` | 97.0% | 32 | 33 | 1 |  |
| 2 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 3 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 4 | `define_function2` | 87.5% | 7 | 8 | 1 |  |
| 5 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 6 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 7 | `get_variable_in_scope` | 79.3% | 23 | 29 | 6 |  |
| 8 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 9 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 10 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 11 | `execution_order3` | 75.0% | 3 | 4 | 1 |  |
| 12 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 13 | `stage_object_children` | 74.7% | 62 | 83 | 21 |  |
| 14 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 15 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 16 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 17 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 18 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 19 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 20 | `point` | 70.9% | 124 | 175 | 51 |  |
| 21 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 22 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 23 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 24 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 25 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 26 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 27 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 28 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 30 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 31 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 32 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 33 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 34 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 35 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 36 | `o` | 66.7% | 2 | 3 | 1 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 38 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 39 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 40 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 41 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 43 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 44 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 45 | `with` | 63.3% | 31 | 49 | 18 |  |
| 46 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 47 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 48 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 49 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 50 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 51 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 52 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 53 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 54 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 55 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 56 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 57 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 58 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 59 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 60 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 61 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 62 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 63 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 64 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 65 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 66 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 67 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 68 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 69 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 70 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 71 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 72 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 73 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 74 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 75 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 76 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 77 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 78 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 79 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 80 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 81 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 82 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 83 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 84 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 85 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 86 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 88 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 89 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 90 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 91 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 92 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 93 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 94 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 95 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 96 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.0s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.5s |  |
| 3 | `enumerate` | 4.4s |  |
| 4 | `path_string` | 4.9s |  |
| 5 | `swf4_actions_coercion_order` | 4.8s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.5s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.5s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.5s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.6s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.8s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**493 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `object_constructor` | 97.0% | 32/33 | 33 | 33 |  |
| 2 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 3 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 4 | `define_function2` | 87.5% | 7/8 | 8 | 8 |  |
| 5 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 6 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 7 | `get_variable_in_scope` | 79.3% | 23/29 | 29 | 29 |  |
| 8 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 9 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 10 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 11 | `execution_order3` | 75.0% | 3/4 | 3 | 4 |  |
| 12 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 13 | `stage_object_children` | 74.7% | 62/83 | 83 | 83 |  |
| 14 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 15 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 16 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 17 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 18 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 19 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 20 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 21 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 22 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 23 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 24 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 25 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 26 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 27 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 28 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 30 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 31 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 32 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 33 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 35 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 36 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 38 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 39 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 40 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 41 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 43 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 44 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 45 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 46 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 47 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 48 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 49 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 50 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 51 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 52 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 53 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 54 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 55 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 56 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 57 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 58 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 59 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 60 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 61 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 62 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 63 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 64 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 65 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 66 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 67 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 68 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 69 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 70 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 71 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 72 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 73 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 74 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 75 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 76 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 77 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 78 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 79 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 80 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 81 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 82 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 83 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 84 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 85 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 86 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 90 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 91 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 92 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 93 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 94 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 95 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 96 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 97 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 98 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 99 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 100 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 101 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 102 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 103 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 104 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 105 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 106 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 107 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 108 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 109 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 110 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 111 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 112 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 113 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 114 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 115 | `named_shapes` | 35.7% | 5/14 | 14 | 14 |  |
| 116 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 117 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 118 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 119 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 120 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 121 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 122 | `goto_frame_number` | 33.3% | 1/3 | 1 | 3 |  |
| 123 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 124 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 125 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 126 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 127 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 128 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 129 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 130 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 131 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 132 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 133 | `execution_order2` | 28.6% | 2/7 | 4 | 7 |  |
| 134 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 135 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 136 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 137 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 138 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 139 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 140 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 141 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 142 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 143 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 144 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 145 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 146 | `new_object_wrap` | 25.0% | 1/4 | 4 | 4 |  |
| 147 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 148 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 149 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 150 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 151 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 152 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 153 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 154 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 155 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 156 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 157 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 158 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 159 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 160 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 161 | `rewind_depth` | 20.0% | 6/30 | 22 | 30 |  |
| 162 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 2 | 5 |  |
| 163 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 164 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 165 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 166 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 167 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 168 | `tell_target_invalid` | 16.7% | 1/6 | 2 | 6 |  |
| 169 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 170 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 171 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 172 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 173 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 174 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 175 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 176 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 177 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 178 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 179 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 180 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 181 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 182 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 183 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 184 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 185 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 186 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 187 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 188 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 189 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 190 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 191 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 192 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 193 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 194 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 195 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 196 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 197 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 198 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 199 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 200 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 201 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 202 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 203 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 204 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 205 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 206 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 207 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 208 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 209 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 210 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 211 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 212 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 213 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 214 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 215 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 216 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 217 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 218 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 219 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 220 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 221 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 222 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 223 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 224 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 225 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 226 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 227 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 228 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 229 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 230 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 231 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 232 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 233 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 234 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 235 | `netstream_seek_flv` | 2.0% | 1/50 | 50 | 25 |  |
| 236 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 237 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 238 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 239 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 240 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 241 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 242 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 243 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 244 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 245 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 246 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 247 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 248 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 249 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 250 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 251 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 252 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 253 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 254 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 255 | `focusrect_property_swf5` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 256 | `focusrect_property_swf6` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 257 | `focusrect_property_swf7` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 258 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 259 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 260 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 261 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 262 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 263 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 264 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 265 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 266 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 267 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 268 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 269 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 270 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 271 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 272 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 273 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 274 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 275 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 276 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 277 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 278 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 280 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 281 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 282 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 283 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 284 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 285 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 286 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 287 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 288 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 289 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 290 | `call_method_empty_name` | 0.0% | 0/1 | 0 | 1 |  |
| 291 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 292 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 293 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 294 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 295 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 296 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 297 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 298 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 299 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 300 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 301 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 302 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 303 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 304 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 305 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 306 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 307 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 308 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 310 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 311 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 312 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 313 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 314 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 315 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 316 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 317 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 318 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 320 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 321 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 322 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 323 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 324 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 325 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 326 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 327 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 328 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 329 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 330 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 331 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 332 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 333 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 334 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 335 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 336 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 337 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 338 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 339 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 340 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 341 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 342 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 343 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 344 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 345 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 346 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 347 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 348 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 349 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 350 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 351 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 352 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 353 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 354 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 355 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 356 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 357 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 358 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 359 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 360 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 361 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 362 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 363 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 364 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 365 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 366 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 367 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 368 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 369 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 370 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 372 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 373 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 374 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 375 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 376 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 377 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 378 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 379 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 380 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 381 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 382 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 383 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 384 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 385 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 386 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 387 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 388 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 389 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 390 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 391 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 392 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 393 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 394 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 395 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 396 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 397 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 398 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 399 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 400 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 401 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 402 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 403 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 404 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 405 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 406 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 407 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 408 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 409 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 410 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 411 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 412 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 413 | `new_method_wrap` | 0.0% | 0/4 | 4 | 4 |  |
| 414 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 415 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 416 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 417 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 418 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 419 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 420 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 421 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 422 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 423 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 424 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 0 | 2 |  |
| 425 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 426 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 427 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 428 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 429 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 430 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 431 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 432 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 433 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 434 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 435 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 436 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 437 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 438 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 439 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 440 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 441 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 442 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 443 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 444 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 445 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 446 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 447 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 448 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 449 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 450 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 451 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 452 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 453 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 454 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 455 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 456 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 457 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 458 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 459 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 460 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 461 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 462 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 463 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 464 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 465 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 466 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 467 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 468 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 469 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 470 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 471 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 472 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 473 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 474 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 475 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 476 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 477 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 478 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 479 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 480 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 481 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 482 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 483 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 484 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 485 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 486 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 487 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 488 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 489 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 490 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 491 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 492 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 493 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
