# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 02:28 UTC

**Git SHA**: `ef611bfba5`

**Run Duration**: 31m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **113** (18.3%) |
| Failing | 503 |
| Total expected lines | 89690 |
| Matching lines | 32619 (36.4%) |
| Mismatched lines | 57071 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 492 | 97.8% |
| Runtime Segfault | 5 | 1.0% |
| Timeout | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**113 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.8s |  |
| 2 | `action_to_integer` | 28 | 2.5s |  |
| 3 | `add` | 28 | 2.5s |  |
| 4 | `add2` | 354 | 2.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.5s |  |
| 6 | `add_swf5` | 28 | 2.5s |  |
| 7 | `array_concat` | 98 | 2.7s |  |
| 8 | `array_constructor` | 30 | 2.5s |  |
| 9 | `array_properties` | 36 | 2.5s |  |
| 10 | `array_slice` | 34 | 2.6s |  |
| 11 | `array_splice` | 207 | 3.3s |  |
| 12 | `array_trivial` | 209 | 3.0s |  |
| 13 | `as1_constructor_v6` | 35 | 2.6s |  |
| 14 | `as1_constructor_v7` | 35 | 2.6s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.4s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.5s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 2.4s |  |
| 18 | `bitand` | 1058 | 9.2s |  |
| 19 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 20 | `bitmap_data_fillrect` | 0 | 2.7s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 3.2s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 3.0s |  |
| 23 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.5s |  |
| 24 | `bitor` | 1058 | 9.4s |  |
| 25 | `biturshift` | 14 | 2.6s |  |
| 26 | `biturshift_swf8` | 14 | 2.4s |  |
| 27 | `bitxor` | 1058 | 9.0s |  |
| 28 | `catch_references_registers` | 2 | 2.4s |  |
| 29 | `define_function_case_sensitive` | 2 | 2.4s |  |
| 30 | `delete` | 3 | 2.5s |  |
| 31 | `divide_swf4` | 107 | 2.7s |  |
| 32 | `do_init_action` | 3 | 2.5s |  |
| 33 | `equals` | 32 | 2.6s |  |
| 34 | `equals2_swf5` | 926 | 10.3s |  |
| 35 | `equals2_swf6` | 926 | 10.3s |  |
| 36 | `equals2_swf7` | 926 | 10.3s |  |
| 37 | `equals_swf4` | 665 | 5.8s |  |
| 38 | `equals_swf4_alt` | 32 | 2.4s |  |
| 39 | `equals_swf5` | 32 | 2.5s |  |
| 40 | `error` | 58 | 2.6s |  |
| 41 | `escape` | 14 | 2.4s |  |
| 42 | `execution_order3` | 4 | 2.4s |  |
| 43 | `focusrect_mouse_swf8` | 0 | 2.4s |  |
| 44 | `focusrect_mouse_swf9` | 0 | 2.4s |  |
| 45 | `focusrect_swf5` | 6 | 2.6s |  |
| 46 | `getproperty` | 28 | 2.4s |  |
| 47 | `getproperty_swf4` | 28 | 2.4s |  |
| 48 | `getproperty_swf5` | 28 | 2.4s |  |
| 49 | `global_array` | 3 | 2.4s |  |
| 50 | `global_is_bare` | 7 | 2.4s |  |
| 51 | `goto_advance2` | 2 | 2.4s |  |
| 52 | `goto_both_ways1` | 3 | 2.7s |  |
| 53 | `goto_both_ways2` | 3 | 2.5s |  |
| 54 | `goto_execution_order` | 2 | 2.4s |  |
| 55 | `goto_execution_order2` | 2 | 2.5s |  |
| 56 | `goto_rewind1` | 1 | 2.5s |  |
| 57 | `goto_rewind2` | 3 | 2.5s |  |
| 58 | `goto_rewind3` | 2 | 2.5s |  |
| 59 | `greater_swf6` | 1175 | 11.8s |  |
| 60 | `greater_swf7` | 1175 | 11.7s |  |
| 61 | `greaterthan_swf5` | 1 | 2.4s |  |
| 62 | `greaterthan_swf8` | 1 | 2.4s |  |
| 63 | `has_own_property` | 32 | 2.6s |  |
| 64 | `infinite_recursion_function` | 4 | 2.5s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 65 | `infinite_recursion_function_in_setter` | 131 | 2.5s |  |
| 66 | `infinite_recursion_virtual_property` | 67 | 2.5s |  |
| 67 | `init_array_invalid` | 4 | 2.4s |  |
| 68 | `init_object_invalid` | 4 | 2.5s |  |
| 69 | `issue_1086` | 1 | 2.4s |  |
| 70 | `issue_1671` | 0 | 2.4s |  |
| 71 | `issue_3446` | 1 | 2.4s |  |
| 72 | `issue_4377` | 2 | 2.4s |  |
| 73 | `issue_768` | 3 | 2.4s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 74 | `lessthan` | 41 | 2.6s |  |
| 75 | `lessthan2_swf5` | 1226 | 12.3s |  |
| 76 | `lessthan2_swf6` | 1226 | 12.4s |  |
| 77 | `lessthan2_swf7` | 1226 | 12.4s |  |
| 78 | `lessthan_swf4` | 902 | 8.1s |  |
| 79 | `lessthan_swf4_alt` | 41 | 2.5s |  |
| 80 | `lessthan_swf5` | 41 | 2.6s |  |
| 81 | `logical_ops_swf4` | 90 | 2.5s |  |
| 82 | `logical_ops_swf8` | 108 | 2.6s |  |
| 83 | `looping` | 6 | 2.5s |  |
| 84 | `mask_reapply` | 0 | 2.5s |  |
| 85 | `mask_with_drawing` | 0 | 2.5s |  |
| 86 | `movieclip_begin_gradient_fill` | 0 | 3.2s |  |
| 87 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 88 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 89 | `nested_textfields_in_buttons` | 0 | 2.3s |  |
| 90 | `netstream_play_flv_screen` | 0 | 30.2s |  |
| 91 | `new_object_enumerate` | 7 | 2.4s |  |
| 92 | `object_function` | 32 | 2.4s |  |
| 93 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 94 | `primitive_instanceof` | 37 | 2.4s |  |
| 95 | `prototype_delete` | 12 | 2.4s |  |
| 96 | `sandbox_type_local_file` | 1 | 2.4s |  |
| 97 | `single_frame` | 1 | 2.4s |  |
| 98 | `sound_start_load` | 0 | 2.4s |  |
| 99 | `strictequals_swf6` | 902 | 8.6s |  |
| 100 | `strictly_equals` | 7 | 2.4s |  |
| 101 | `string_coercion` | 117 | 3.0s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 102 | `string_paths_keyevents` | 0 | 2.4s |  |
| 103 | `string_paths_timer` | 0 | 2.4s |  |
| 104 | `swf4_actions_bool` | 96 | 2.5s |  |
| 105 | `swf4_bool` | 4 | 2.4s |  |
| 106 | `swf5_encoding` | 3 | 4.1s |  |
| 107 | `this_swf7` | 41 | 2.5s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 108 | `timeline_function_def` | 7 | 2.5s |  |
| 109 | `try_finally_simple` | 16 | 2.5s |  |
| 110 | `typeof_globals` | 7 | 2.5s |  |
| 111 | `undefined_to_string_swf6` | 4 | 2.5s |  |
| 112 | `unescape` | 43 | 2.6s |  |
| 113 | `with_return` | 2 | 2.4s |  |

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
| 34 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
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
| 1 | `device_font_spacing` | 11.9s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.6s |  |
| 3 | `enumerate` | 4.6s |  |
| 4 | `path_string` | 4.2s |  |
| 5 | `swf4_actions_coercion_order` | 4.7s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.4s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.5s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 14.2s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.4s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.9s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**492 tests** with output mismatch, sorted by match rate (best first)

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
| 34 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
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
| 107 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 108 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 109 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 110 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 111 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 112 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 113 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 114 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 115 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 116 | `named_shapes` | 35.7% | 5/14 | 14 | 14 |  |
| 117 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 118 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 119 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 120 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 121 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 122 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 123 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 124 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 125 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 126 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 127 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 128 | `define_function2_preload` | 30.8% | 4/13 | 12 | 13 |  |
| 129 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 130 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 131 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 132 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 133 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
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
| 161 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 162 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 163 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 164 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 165 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 166 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 167 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 168 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 169 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 170 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 171 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 172 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 173 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 174 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 175 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 176 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 177 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 178 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 179 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 180 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 181 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 182 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 183 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 184 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 185 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 186 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 187 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 188 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 189 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 190 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 191 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
| 192 | `string_paths_other` | 11.1% | 4/36 | 28 | 36 |  |
| 193 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 194 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 195 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 196 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 197 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 198 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 199 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 200 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 201 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 202 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 203 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 204 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 205 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 206 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 207 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 208 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 209 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 210 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 211 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 212 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 213 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 214 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 215 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 216 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 217 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 218 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 219 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 220 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 221 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 222 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 223 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 224 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 225 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 226 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 227 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 228 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 229 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 230 | `tab_ordering_properties` | 2.7% | 8/293 | 180 | 293 |  |
| 231 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 232 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 233 | `netstream_seek_flv` | 2.0% | 1/50 | 50 | 25 |  |
| 234 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 235 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 236 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 237 | `movieclip_default_state` | 1.4% | 1/69 | 69 | 69 |  |
| 238 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 239 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 240 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 241 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 242 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 243 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 244 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 245 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 246 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 247 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 248 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 249 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 250 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 251 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 252 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 253 | `focusrect_property_swf5` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 254 | `focusrect_property_swf6` | 0.2% | 3/1241 | 1241 | 1237 |  |
| 255 | `focusrect_property_swf7` | 0.2% | 2/1241 | 1241 | 1237 |  |
| 256 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 257 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 258 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 259 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 260 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
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
| 311 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 312 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 314 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 315 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 316 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 317 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 319 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 320 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 321 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 322 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 323 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 324 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 325 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
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
| 352 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 353 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 354 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 355 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 356 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 357 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 358 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 360 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 361 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 362 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 363 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 364 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 365 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 366 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 367 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 368 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 369 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 370 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 371 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 372 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 373 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 374 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 375 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 376 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 377 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 378 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 379 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 380 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 381 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 382 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 383 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 384 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 385 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 386 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 387 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 388 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 389 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 390 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 391 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 392 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 393 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 394 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 395 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 396 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 397 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 398 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 399 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 400 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 401 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 402 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 403 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 404 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 405 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 406 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 407 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 408 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 409 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 410 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 411 | `new_method_wrap` | 0.0% | 0/4 | 4 | 4 |  |
| 412 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 413 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 414 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 415 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 416 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 417 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 418 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 419 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 420 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 421 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 422 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 423 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 424 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 425 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 426 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 427 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 428 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 429 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 430 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 431 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 432 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 433 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 434 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 435 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 436 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 437 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 438 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 439 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 440 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 441 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 442 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 443 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 444 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 445 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 446 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 447 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 448 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 449 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 450 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 451 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 452 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 453 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 454 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 455 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 456 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 457 | `tab_ordering_properties_tab_index_edge_case` | 0.0% | 0/4 | 4 | 4 |  |
| 458 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 459 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 460 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 461 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 462 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 463 | `tell_target_invalid` | 0.0% | 0/6 | 4 | 6 |  |
| 464 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 4 | 5 |  |
| 465 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 466 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 467 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 468 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 469 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 470 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 471 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 472 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 473 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 474 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 475 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 476 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 477 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 478 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 479 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 480 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 481 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 482 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 483 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 484 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 485 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 486 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 487 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 488 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 489 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 490 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 491 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 492 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
