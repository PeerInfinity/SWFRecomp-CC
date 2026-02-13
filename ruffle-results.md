# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 01:01 UTC

**Git SHA**: `28a85fbf83`

**Run Duration**: 31m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **105** (17.0%) |
| Failing | 511 |
| Total expected lines | 89690 |
| Matching lines | 32602 (36.3%) |
| Mismatched lines | 57088 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 500 | 97.8% |
| Runtime Segfault | 5 | 1.0% |
| Timeout | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**105 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.6s |  |
| 2 | `action_to_integer` | 28 | 2.5s |  |
| 3 | `add` | 28 | 2.5s |  |
| 4 | `add2` | 354 | 2.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.4s |  |
| 6 | `add_swf5` | 28 | 2.5s |  |
| 7 | `array_concat` | 98 | 2.6s |  |
| 8 | `array_constructor` | 30 | 2.5s |  |
| 9 | `array_properties` | 36 | 2.6s |  |
| 10 | `array_slice` | 34 | 2.6s |  |
| 11 | `array_splice` | 207 | 3.4s |  |
| 12 | `array_trivial` | 209 | 3.0s |  |
| 13 | `as1_constructor_v6` | 35 | 2.6s |  |
| 14 | `as1_constructor_v7` | 35 | 2.6s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.5s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.5s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 2.4s |  |
| 18 | `bitand` | 1058 | 9.5s |  |
| 19 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 20 | `bitmap_data_fillrect` | 0 | 2.7s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 3.0s |  |
| 23 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.5s |  |
| 24 | `bitor` | 1058 | 9.7s |  |
| 25 | `biturshift` | 14 | 2.7s |  |
| 26 | `biturshift_swf8` | 14 | 2.4s |  |
| 27 | `bitxor` | 1058 | 9.3s |  |
| 28 | `catch_references_registers` | 2 | 2.4s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.4s |  |
| 30 | `delete` | 3 | 2.5s |  |
| 31 | `divide_swf4` | 107 | 2.5s |  |
| 32 | `do_init_action` | 3 | 2.4s |  |
| 33 | `equals` | 32 | 2.5s |  |
| 34 | `equals2_swf5` | 926 | 10.8s |  |
| 35 | `equals2_swf6` | 926 | 10.6s |  |
| 36 | `equals2_swf7` | 926 | 10.5s |  |
| 37 | `equals_swf4` | 665 | 5.9s |  |
| 38 | `equals_swf4_alt` | 32 | 2.4s |  |
| 39 | `equals_swf5` | 32 | 2.5s |  |
| 40 | `error` | 58 | 2.6s |  |
| 41 | `escape` | 14 | 2.4s |  |
| 42 | `focusrect_mouse_swf8` | 0 | 2.4s |  |
| 43 | `focusrect_mouse_swf9` | 0 | 2.4s |  |
| 44 | `getproperty` | 28 | 2.4s |  |
| 45 | `getproperty_swf4` | 28 | 2.4s |  |
| 46 | `getproperty_swf5` | 28 | 2.5s |  |
| 47 | `global_array` | 3 | 2.4s |  |
| 48 | `global_is_bare` | 7 | 2.4s |  |
| 49 | `goto_execution_order` | 2 | 2.4s |  |
| 50 | `goto_rewind1` | 1 | 2.5s |  |
| 51 | `greater_swf6` | 1175 | 11.7s |  |
| 52 | `greater_swf7` | 1175 | 11.7s |  |
| 53 | `greaterthan_swf5` | 1 | 2.4s |  |
| 54 | `greaterthan_swf8` | 1 | 2.4s |  |
| 55 | `has_own_property` | 32 | 2.5s |  |
| 56 | `infinite_recursion_function` | 4 | 2.4s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 57 | `infinite_recursion_function_in_setter` | 131 | 2.4s |  |
| 58 | `infinite_recursion_virtual_property` | 67 | 2.4s |  |
| 59 | `init_array_invalid` | 4 | 2.4s |  |
| 60 | `init_object_invalid` | 4 | 2.4s |  |
| 61 | `issue_1086` | 1 | 2.4s |  |
| 62 | `issue_1671` | 0 | 2.4s |  |
| 63 | `issue_3446` | 1 | 2.4s |  |
| 64 | `issue_4377` | 2 | 2.4s |  |
| 65 | `issue_768` | 3 | 2.4s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 66 | `lessthan` | 41 | 2.5s |  |
| 67 | `lessthan2_swf5` | 1226 | 12.1s |  |
| 68 | `lessthan2_swf6` | 1226 | 12.1s |  |
| 69 | `lessthan2_swf7` | 1226 | 12.2s |  |
| 70 | `lessthan_swf4` | 902 | 8.0s |  |
| 71 | `lessthan_swf4_alt` | 41 | 2.5s |  |
| 72 | `lessthan_swf5` | 41 | 2.5s |  |
| 73 | `logical_ops_swf4` | 90 | 2.4s |  |
| 74 | `logical_ops_swf8` | 108 | 2.5s |  |
| 75 | `looping` | 6 | 2.3s |  |
| 76 | `mask_reapply` | 0 | 2.3s |  |
| 77 | `mask_with_drawing` | 0 | 2.4s |  |
| 78 | `movieclip_begin_gradient_fill` | 0 | 3.0s |  |
| 79 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 80 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 81 | `nested_textfields_in_buttons` | 0 | 2.4s |  |
| 82 | `netstream_play_flv_screen` | 0 | 29.5s |  |
| 83 | `new_object_enumerate` | 7 | 2.4s |  |
| 84 | `object_function` | 32 | 2.5s |  |
| 85 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 86 | `primitive_instanceof` | 37 | 2.4s |  |
| 87 | `prototype_delete` | 12 | 2.5s |  |
| 88 | `sandbox_type_local_file` | 1 | 2.2s |  |
| 89 | `single_frame` | 1 | 2.2s |  |
| 90 | `sound_start_load` | 0 | 2.3s |  |
| 91 | `strictequals_swf6` | 902 | 8.0s |  |
| 92 | `strictly_equals` | 7 | 2.3s |  |
| 93 | `string_coercion` | 117 | 2.9s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 94 | `string_paths_keyevents` | 0 | 2.3s |  |
| 95 | `string_paths_timer` | 0 | 2.3s |  |
| 96 | `swf4_actions_bool` | 96 | 2.4s |  |
| 97 | `swf4_bool` | 4 | 2.2s |  |
| 98 | `swf5_encoding` | 3 | 2.6s |  |
| 99 | `this_swf7` | 41 | 2.5s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 100 | `timeline_function_def` | 7 | 2.5s |  |
| 101 | `try_finally_simple` | 16 | 2.5s |  |
| 102 | `typeof_globals` | 7 | 2.5s |  |
| 103 | `undefined_to_string_swf6` | 4 | 2.4s |  |
| 104 | `unescape` | 43 | 2.6s |  |
| 105 | `with_return` | 2 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**101 tests** within reach

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
| 11 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 12 | `stage_object_children` | 74.7% | 62 | 83 | 21 |  |
| 13 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 14 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 16 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 17 | `swf4_function_calls` | 71.4% | 5 | 7 | 2 |  |
| 18 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 19 | `point` | 70.9% | 124 | 175 | 51 |  |
| 20 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 21 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 22 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 23 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 24 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 25 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 26 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 27 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 29 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 30 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 31 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 32 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 33 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 34 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 35 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 36 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 37 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 38 | `o` | 66.7% | 2 | 3 | 1 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 40 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 41 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 42 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 43 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 44 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 45 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 46 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 47 | `with` | 63.3% | 31 | 49 | 18 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 49 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 50 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 51 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 52 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 53 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 54 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 55 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 56 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 57 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 58 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 59 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 60 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 61 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 62 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 63 | `with_variable_scopes` | 58.1% | 25 | 43 | 18 |  |
| 64 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 65 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 66 | `register_underflow` | 57.7% | 15 | 26 | 11 |  |
| 67 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 68 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 69 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 70 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 71 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 72 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 73 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 74 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 75 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 76 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 77 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 78 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 79 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 80 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 81 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 82 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 83 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 84 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 85 | `as_set_prop_flags_version` | 51.6% | 16 | 31 | 15 |  |
| 86 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 87 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 88 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 89 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 90 | `goto_advance2` | 50.0% | 1 | 2 | 1 |  |
| 91 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 92 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 93 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 94 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 95 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 96 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 97 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 98 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 99 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 100 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 101 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 11.9s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.5s |  |
| 3 | `enumerate` | 4.6s |  |
| 4 | `path_string` | 4.9s |  |
| 5 | `swf4_actions_coercion_order` | 4.0s |  |

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
| 1 | `parse_float` | runtime timeout (>10s) | 13.4s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.5s |  |
| 3 | `timeout` | runtime timeout (>10s) | 14.1s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**500 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 12 | `stage_object_children` | 74.7% | 62/83 | 83 | 83 |  |
| 13 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 14 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 16 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 17 | `swf4_function_calls` | 71.4% | 5/7 | 7 | 7 |  |
| 18 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 19 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 20 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 21 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 22 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 23 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 24 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 25 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 26 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 27 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 28 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 29 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 30 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 31 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 32 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 33 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 34 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 35 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 36 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 37 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 38 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 40 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 42 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 43 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 44 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 45 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 46 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 47 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 49 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 50 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 51 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 52 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 53 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 54 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 55 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 56 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 57 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 58 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 59 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 60 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 61 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 62 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 63 | `with_variable_scopes` | 58.1% | 25/43 | 43 | 43 |  |
| 64 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 65 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 66 | `register_underflow` | 57.7% | 15/26 | 26 | 26 |  |
| 67 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 68 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 69 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 70 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 71 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 72 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 73 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 74 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 75 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 76 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 77 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 78 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 79 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 80 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 81 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 82 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 83 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 84 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 85 | `as_set_prop_flags_version` | 51.6% | 16/31 | 29 | 31 |  |
| 86 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 87 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 88 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 90 | `goto_advance2` | 50.0% | 1/2 | 1 | 2 |  |
| 91 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 92 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 93 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 94 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 95 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 96 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 97 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 98 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 99 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 100 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 101 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 102 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 103 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 104 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 105 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 106 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 107 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 108 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 109 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 110 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 111 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 112 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 113 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 114 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 115 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 116 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 117 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 118 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 119 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 120 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 121 | `named_shapes` | 35.7% | 5/14 | 14 | 14 |  |
| 122 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 123 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 124 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 125 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 126 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 127 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 128 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 129 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 130 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 131 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 132 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 133 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 134 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 135 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 136 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 137 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 138 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 139 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 140 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 141 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 142 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 143 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 144 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 145 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 146 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 147 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 148 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 149 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 150 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 151 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 152 | `new_object_wrap` | 25.0% | 1/4 | 4 | 4 |  |
| 153 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 154 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 155 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 156 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 157 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 158 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 159 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 160 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 161 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 162 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 163 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 164 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 165 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 166 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 167 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 168 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 169 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 170 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 171 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 172 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
| 173 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 174 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 175 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 176 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 177 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 178 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 179 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 180 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 181 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 182 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 183 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 184 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 185 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 186 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 187 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 188 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 189 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 190 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 191 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 192 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 193 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 194 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 195 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 196 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 197 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 198 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 199 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 200 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 201 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 202 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 203 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 204 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 205 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 206 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 207 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 208 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 209 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 210 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 211 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 212 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 213 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 214 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 215 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 216 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 217 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 218 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 219 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 220 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 221 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 222 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 223 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 224 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 225 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 226 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 227 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 228 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 229 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 230 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 231 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 232 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 233 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 234 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 235 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 236 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 237 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 238 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 239 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 240 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 241 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 242 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 243 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 244 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 245 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 246 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 247 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 248 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 249 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 250 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 251 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 252 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 253 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 254 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 255 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 256 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 257 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 258 | `focusrect_property_swf5` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 259 | `focusrect_property_swf6` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 260 | `focusrect_property_swf7` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 261 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 262 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 263 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 264 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 265 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 266 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 267 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 268 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 269 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 270 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 271 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 272 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 273 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 274 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 275 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 276 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 277 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 278 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 279 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 280 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 281 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 283 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 284 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 285 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 286 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 287 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 288 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 289 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 290 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 291 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 292 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 293 | `call_method_empty_name` | 0.0% | 0/1 | 0 | 1 |  |
| 294 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 295 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 296 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 297 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 298 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 299 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 300 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 301 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 302 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 303 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 304 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 305 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 306 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 307 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 308 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 309 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 310 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 313 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 314 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 315 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 316 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 317 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 318 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 319 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 320 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 321 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 322 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 323 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 324 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 325 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 326 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 327 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 328 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 329 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 330 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 331 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 332 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 333 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 334 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 335 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 336 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 337 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 338 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 339 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 340 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 341 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 342 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 343 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 344 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 345 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 346 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 347 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 348 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 349 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 350 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 351 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 352 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 353 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 354 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 355 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 356 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 357 | `goto_execution_order2` | 0.0% | 0/2 | 0 | 2 |  |
| 358 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 359 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 360 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 361 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 362 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 363 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 364 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 365 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 366 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 367 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 368 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 369 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 370 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 372 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 373 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 374 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 375 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 376 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 377 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 378 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 379 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 380 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 381 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 382 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 383 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 384 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 385 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 386 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 387 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 388 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 389 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 390 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 391 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 392 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 393 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 394 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 395 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 396 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 397 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 398 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 399 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 400 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 401 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 402 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 403 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 404 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 405 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 406 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 407 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 408 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 409 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 410 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 411 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 412 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 413 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 414 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 415 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 416 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 417 | `netstream_seek_flv` | 0.0% | 0/25 | 0 | 25 |  |
| 418 | `new_method_wrap` | 0.0% | 0/4 | 4 | 4 |  |
| 419 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 420 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 421 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 422 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 423 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 424 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 425 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 426 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 427 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 428 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 429 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 430 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 431 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 432 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 433 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 434 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 435 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 436 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 437 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 438 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 439 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 440 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 441 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 442 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 443 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 444 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 445 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 446 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 447 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 448 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 449 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 450 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 451 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 452 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 453 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 454 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 455 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 456 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 457 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 458 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 459 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 460 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 461 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 462 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 463 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 464 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 465 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 466 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 467 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 468 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 469 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 470 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 471 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 472 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 473 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 474 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 475 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 476 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 477 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 478 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 479 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 480 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 481 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 482 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 483 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 484 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 485 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 486 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 487 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 488 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 489 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 490 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 491 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 492 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 493 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 494 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 495 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 496 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 497 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 498 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 499 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 500 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
