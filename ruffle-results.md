# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 00:46 UTC

**Git SHA**: `b41374d1cd`

**Run Duration**: 30m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **101** (16.4%) |
| Failing | 515 |
| Total expected lines | 89534 |
| Matching lines | 32531 (36.3%) |
| Mismatched lines | 57003 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 500 | 97.1% |
| Runtime Segfault | 9 | 1.7% |
| Timeout | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**101 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.4s |  |
| 2 | `action_to_integer` | 28 | 2.3s |  |
| 3 | `add` | 28 | 2.3s |  |
| 4 | `add2` | 354 | 2.7s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.2s |  |
| 6 | `add_swf5` | 28 | 2.3s |  |
| 7 | `array_concat` | 98 | 2.5s |  |
| 8 | `array_constructor` | 30 | 2.4s |  |
| 9 | `array_properties` | 36 | 2.3s |  |
| 10 | `array_slice` | 34 | 2.4s |  |
| 11 | `array_splice` | 207 | 3.1s |  |
| 12 | `array_trivial` | 209 | 2.8s |  |
| 13 | `as1_constructor_v6` | 35 | 2.4s |  |
| 14 | `as1_constructor_v7` | 35 | 2.4s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.3s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.3s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 2.2s |  |
| 18 | `bitand` | 1058 | 11.6s |  |
| 19 | `bitmap_data_colortransform` | 0 | 2.6s |  |
| 20 | `bitmap_data_fillrect` | 0 | 2.4s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 3.1s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 2.8s |  |
| 23 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.3s |  |
| 24 | `bitor` | 1058 | 11.6s |  |
| 25 | `biturshift` | 14 | 2.5s |  |
| 26 | `biturshift_swf8` | 14 | 2.3s |  |
| 27 | `bitxor` | 1058 | 11.2s |  |
| 28 | `catch_references_registers` | 2 | 2.3s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.3s |  |
| 30 | `delete` | 3 | 2.4s |  |
| 31 | `divide_swf4` | 107 | 2.4s |  |
| 32 | `do_init_action` | 3 | 2.3s |  |
| 33 | `equals` | 32 | 2.5s |  |
| 34 | `equals2_swf5` | 926 | 11.3s |  |
| 35 | `equals2_swf6` | 926 | 11.0s |  |
| 36 | `equals2_swf7` | 926 | 11.3s |  |
| 37 | `equals_swf4` | 665 | 6.3s |  |
| 38 | `equals_swf4_alt` | 32 | 2.4s |  |
| 39 | `equals_swf5` | 32 | 2.4s |  |
| 40 | `error` | 58 | 2.6s |  |
| 41 | `escape` | 14 | 2.4s |  |
| 42 | `focusrect_mouse_swf8` | 0 | 2.3s |  |
| 43 | `focusrect_mouse_swf9` | 0 | 2.3s |  |
| 44 | `getproperty` | 28 | 2.4s |  |
| 45 | `getproperty_swf4` | 28 | 2.3s |  |
| 46 | `getproperty_swf5` | 28 | 2.3s |  |
| 47 | `global_array` | 3 | 2.3s |  |
| 48 | `global_is_bare` | 7 | 2.3s |  |
| 49 | `goto_execution_order` | 2 | 2.4s |  |
| 50 | `goto_rewind1` | 1 | 2.4s |  |
| 51 | `greater_swf6` | 1175 | 11.8s |  |
| 52 | `greater_swf7` | 1175 | 11.9s |  |
| 53 | `greaterthan_swf5` | 1 | 2.4s |  |
| 54 | `greaterthan_swf8` | 1 | 2.4s |  |
| 55 | `has_own_property` | 32 | 2.5s |  |
| 56 | `infinite_recursion_function` | 4 | 2.4s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 57 | `infinite_recursion_function_in_setter` | 131 | 2.4s |  |
| 58 | `infinite_recursion_virtual_property` | 67 | 2.4s |  |
| 59 | `issue_1086` | 1 | 2.4s |  |
| 60 | `issue_1671` | 0 | 2.4s |  |
| 61 | `issue_3446` | 1 | 2.5s |  |
| 62 | `issue_4377` | 2 | 2.4s |  |
| 63 | `issue_768` | 3 | 2.4s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 64 | `lessthan` | 41 | 2.5s |  |
| 65 | `lessthan2_swf5` | 1226 | 12.5s |  |
| 66 | `lessthan2_swf6` | 1226 | 12.5s |  |
| 67 | `lessthan2_swf7` | 1226 | 12.5s |  |
| 68 | `lessthan_swf4` | 902 | 8.1s |  |
| 69 | `lessthan_swf4_alt` | 41 | 2.5s |  |
| 70 | `lessthan_swf5` | 41 | 2.5s |  |
| 71 | `logical_ops_swf4` | 90 | 2.4s |  |
| 72 | `logical_ops_swf8` | 108 | 2.4s |  |
| 73 | `looping` | 6 | 2.3s |  |
| 74 | `mask_reapply` | 0 | 2.3s |  |
| 75 | `mask_with_drawing` | 0 | 2.3s |  |
| 76 | `movieclip_begin_gradient_fill` | 0 | 3.1s |  |
| 77 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 78 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 79 | `nested_textfields_in_buttons` | 0 | 2.3s |  |
| 80 | `new_object_enumerate` | 7 | 2.6s |  |
| 81 | `object_function` | 32 | 2.5s |  |
| 82 | `object_string_coerce_swf5` | 62 | 2.6s |  |
| 83 | `prototype_delete` | 12 | 2.4s |  |
| 84 | `sandbox_type_local_file` | 1 | 2.4s |  |
| 85 | `single_frame` | 1 | 2.4s |  |
| 86 | `sound_start_load` | 0 | 2.4s |  |
| 87 | `strictequals_swf6` | 902 | 9.1s |  |
| 88 | `strictly_equals` | 7 | 2.5s |  |
| 89 | `string_coercion` | 117 | 3.1s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 90 | `string_paths_keyevents` | 0 | 2.4s |  |
| 91 | `string_paths_timer` | 0 | 2.3s |  |
| 92 | `swf4_actions_bool` | 96 | 2.4s |  |
| 93 | `swf4_bool` | 4 | 2.3s |  |
| 94 | `swf5_encoding` | 3 | 2.5s |  |
| 95 | `this_swf7` | 41 | 2.4s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 96 | `timeline_function_def` | 7 | 2.5s |  |
| 97 | `try_finally_simple` | 16 | 2.3s |  |
| 98 | `typeof_globals` | 7 | 2.2s |  |
| 99 | `undefined_to_string_swf6` | 4 | 2.2s |  |
| 100 | `unescape` | 43 | 2.3s |  |
| 101 | `with_return` | 2 | 2.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**101 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `object_constructor` | 97.0% | 32 | 33 | 1 |  |
| 2 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 3 | `primitive_instanceof` | 91.9% | 34 | 37 | 3 |  |
| 4 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 5 | `define_function2` | 87.5% | 7 | 8 | 1 |  |
| 6 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 7 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 8 | `get_variable_in_scope` | 79.3% | 23 | 29 | 6 |  |
| 9 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 10 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 11 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
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
| 22 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 23 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 24 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 25 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 27 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 28 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 29 | `globals_swf6` | 67.1% | 204 | 304 | 100 |  |
| 30 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 31 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 32 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 33 | `goto_both_ways2` | 66.7% | 2 | 3 | 1 |  |
| 34 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 35 | `goto_rewind2` | 66.7% | 2 | 3 | 1 |  |
| 36 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 37 | `o` | 66.7% | 2 | 3 | 1 |  |
| 38 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 39 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 40 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 41 | `globals_swf7` | 66.1% | 201 | 304 | 103 |  |
| 42 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 43 | `globals_swf5` | 64.8% | 197 | 304 | 107 |  |
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
| 67 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 68 | `primitive_type_globals` | 57.3% | 319 | 557 | 238 |  |
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

**9 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as2_oop` | 3.9s |  |
| 2 | `device_font_spacing` | 12.2s |  |
| 3 | `duplicate_movie_clip_drawing` | 4.4s |  |
| 4 | `enumerate` | 4.6s |  |
| 5 | `extends_chain` | 5.2s |  |
| 6 | `issue_2166` | 4.6s |  |
| 7 | `netstream_play_flv_screen` | 32.9s |  |
| 8 | `path_string` | 4.8s |  |
| 9 | `swf4_actions_coercion_order` | 4.7s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.2s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.2s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.5s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.4s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.6s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**500 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `object_constructor` | 97.0% | 32/33 | 33 | 33 |  |
| 2 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 3 | `primitive_instanceof` | 91.9% | 34/37 | 37 | 37 |  |
| 4 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 5 | `define_function2` | 87.5% | 7/8 | 8 | 8 |  |
| 6 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 7 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 8 | `get_variable_in_scope` | 79.3% | 23/29 | 29 | 29 |  |
| 9 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 10 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 11 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
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
| 22 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 23 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 24 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 25 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 27 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 28 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 29 | `globals_swf6` | 67.1% | 204/304 | 304 | 304 |  |
| 30 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 31 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 32 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 33 | `goto_both_ways2` | 66.7% | 2/3 | 2 | 3 |  |
| 34 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 35 | `goto_rewind2` | 66.7% | 2/3 | 2 | 3 |  |
| 36 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 37 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 38 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 39 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 40 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 41 | `globals_swf7` | 66.1% | 201/304 | 304 | 304 |  |
| 42 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 43 | `globals_swf5` | 64.8% | 197/304 | 304 | 304 |  |
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
| 67 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 68 | `primitive_type_globals` | 57.3% | 319/557 | 555 | 557 |  |
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
| 107 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 108 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 109 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 110 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 111 | `globals_swf8` | 41.8% | 127/304 | 304 | 304 |  |
| 112 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 113 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 114 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 115 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 116 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 117 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 118 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 119 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 120 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 121 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 122 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 123 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 124 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 125 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 126 | `goto_both_ways1` | 33.3% | 1/3 | 1 | 3 |  |
| 127 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 128 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 129 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 130 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 131 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 132 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 133 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 134 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 135 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 136 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 137 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 138 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 139 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 140 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 141 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 142 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 143 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 144 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 145 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 146 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 147 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 148 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 149 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 150 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 151 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 152 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 153 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 154 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 155 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 156 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 157 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 158 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 159 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 160 | `movieclip_lockroot` | 20.7% | 6/29 | 16 | 29 |  |
| 161 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 162 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 163 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 164 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 165 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 166 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 167 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 168 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 169 | `focusrect_swf5` | 16.7% | 1/6 | 1 | 6 |  |
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
| 235 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 236 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 237 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 238 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 239 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 240 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 241 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 242 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 243 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 244 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 245 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 246 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 247 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 248 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 249 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 250 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 251 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 252 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 253 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 254 | `focusrect_property_swf5` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 255 | `focusrect_property_swf6` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 256 | `focusrect_property_swf7` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 257 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 258 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 259 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 260 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 261 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 262 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 263 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 264 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 265 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 266 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 267 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 268 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 269 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 270 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 272 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 273 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 274 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 275 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 276 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 277 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 278 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 279 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 280 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 281 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 282 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 283 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 284 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 285 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 286 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 287 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 288 | `call_method_empty_name` | 0.0% | 0/1 | 0 | 1 |  |
| 289 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 290 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 291 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 292 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 293 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 294 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 295 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 296 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 297 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 298 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 299 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 300 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 301 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 302 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 303 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 304 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 305 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 308 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 309 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 310 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 311 | `edittext_html_roundtrip` | 0.0% | 0/17 | 0 | 17 |  |
| 312 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 313 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 314 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 315 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 316 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 317 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 320 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 321 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 322 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 323 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 324 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 325 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 326 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 327 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 328 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 329 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 330 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 331 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 332 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 333 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 334 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 335 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 336 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 337 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 338 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 339 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 340 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 341 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 342 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 343 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 344 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 345 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 346 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 347 | `global_instance_decls` | 0.0% | 0/758 | 81 | 758 |  |
| 348 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 349 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 350 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 351 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 352 | `goto_execution_order2` | 0.0% | 0/2 | 0 | 2 |  |
| 353 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 354 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 355 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 356 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 357 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 358 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 359 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 360 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 361 | `init_array_invalid` | 0.0% | 0/4 | 0 | 4 |  |
| 362 | `init_object_invalid` | 0.0% | 0/4 | 0 | 4 |  |
| 363 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 364 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 365 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 366 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 367 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 368 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 369 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 370 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 372 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 373 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 374 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 375 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 376 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 377 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 378 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 379 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 380 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 381 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 382 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 383 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 384 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 385 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 386 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 387 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 388 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 389 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 390 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 391 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 392 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 393 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 394 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 395 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 396 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 397 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 398 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 399 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 400 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 401 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 402 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 403 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 404 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 405 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 406 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 407 | `named_shapes` | 0.0% | 0/14 | 0 | 14 |  |
| 408 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 409 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 410 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 411 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 412 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 413 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 414 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 415 | `netstream_seek_flv` | 0.0% | 0/25 | 0 | 25 |  |
| 416 | `new_method_wrap` | 0.0% | 0/4 | 0 | 4 |  |
| 417 | `new_object_wrap` | 0.0% | 0/4 | 0 | 4 |  |
| 418 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 419 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 420 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 421 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 422 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 423 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 424 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 425 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 426 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 427 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 428 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 429 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 430 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 431 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 432 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 433 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 434 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 435 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 436 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 437 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 438 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 439 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 440 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 441 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 442 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 443 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 444 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 445 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 446 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 447 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 448 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 449 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 450 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 451 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 452 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 453 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 454 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 455 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 456 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 457 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 458 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 459 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 460 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 461 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 462 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 463 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 464 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 465 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 466 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 467 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 468 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 469 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 470 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 471 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 472 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 473 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 474 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 475 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 476 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 477 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 478 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 479 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 480 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 481 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 482 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 483 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 484 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 485 | `watch_textfield` | 0.0% | 0/12 | 0 | 12 |  |
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
