# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 04:26 UTC

**Git SHA**: `688277072b`

**Run Duration**: 31m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **122** (19.8%) |
| Failing | 494 |
| Total expected lines | 89690 |
| Matching lines | 33293 (37.1%) |
| Mismatched lines | 56397 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 484 | 98.0% |
| Timeout | 4 | 0.8% |
| Runtime Segfault | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**122 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.6s |  |
| 2 | `action_to_integer` | 28 | 2.6s |  |
| 3 | `add` | 28 | 2.6s |  |
| 4 | `add2` | 354 | 2.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.6s |  |
| 6 | `add_swf5` | 28 | 2.5s |  |
| 7 | `array_concat` | 98 | 2.7s |  |
| 8 | `array_constructor` | 30 | 2.6s |  |
| 9 | `array_properties` | 36 | 2.5s |  |
| 10 | `array_slice` | 34 | 2.7s |  |
| 11 | `array_splice` | 207 | 3.3s |  |
| 12 | `array_trivial` | 209 | 3.0s |  |
| 13 | `as1_constructor_v6` | 35 | 2.6s |  |
| 14 | `as1_constructor_v7` | 35 | 2.6s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.4s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.5s |  |
| 17 | `as_set_prop_flags_version_swf6` | 1 | 2.5s |  |
| 18 | `as_set_prop_flags_version_swf7` | 1 | 2.5s |  |
| 19 | `as_set_prop_flags_version_swf8` | 1 | 2.5s |  |
| 20 | `as_set_prop_flags_version_swf9` | 1 | 2.5s |  |
| 21 | `bad_swf_tag_past_eof` | 0 | 2.4s |  |
| 22 | `bitand` | 1058 | 9.2s |  |
| 23 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 24 | `bitmap_data_fillrect` | 0 | 2.6s |  |
| 25 | `bitmap_data_perlinnoise` | 0 | 3.2s |  |
| 26 | `bitmap_data_pixeldissolve_image` | 0 | 3.0s |  |
| 27 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.5s |  |
| 28 | `bitor` | 1058 | 9.3s |  |
| 29 | `biturshift` | 14 | 2.4s |  |
| 30 | `biturshift_swf8` | 14 | 2.3s |  |
| 31 | `bitxor` | 1058 | 8.9s |  |
| 32 | `call_method_empty_name` | 1 | 2.3s |  |
| 33 | `catch_references_registers` | 2 | 2.3s |  |
| 34 | `define_function2` | 8 | 2.3s |  |
| 35 | `define_function_case_sensitive` | 2 | 2.3s |  |
| 36 | `delete` | 3 | 2.4s |  |
| 37 | `divide_swf4` | 107 | 2.5s |  |
| 38 | `do_init_action` | 3 | 2.3s |  |
| 39 | `equals` | 32 | 2.5s |  |
| 40 | `equals2_swf5` | 926 | 10.7s |  |
| 41 | `equals2_swf6` | 926 | 10.7s |  |
| 42 | `equals2_swf7` | 926 | 10.7s |  |
| 43 | `equals_swf4` | 665 | 6.1s |  |
| 44 | `equals_swf4_alt` | 32 | 2.5s |  |
| 45 | `equals_swf5` | 32 | 2.5s |  |
| 46 | `error` | 58 | 2.6s |  |
| 47 | `escape` | 14 | 2.5s |  |
| 48 | `execution_order3` | 4 | 2.5s |  |
| 49 | `focusrect_mouse_swf8` | 0 | 2.4s |  |
| 50 | `focusrect_mouse_swf9` | 0 | 2.5s |  |
| 51 | `focusrect_swf5` | 6 | 2.7s |  |
| 52 | `getproperty` | 28 | 2.5s |  |
| 53 | `getproperty_swf4` | 28 | 2.5s |  |
| 54 | `getproperty_swf5` | 28 | 2.5s |  |
| 55 | `global_array` | 3 | 2.5s |  |
| 56 | `global_is_bare` | 7 | 2.5s |  |
| 57 | `goto_advance2` | 2 | 2.5s |  |
| 58 | `goto_both_ways1` | 3 | 2.8s |  |
| 59 | `goto_both_ways2` | 3 | 2.5s |  |
| 60 | `goto_execution_order` | 2 | 2.5s |  |
| 61 | `goto_execution_order2` | 2 | 2.5s |  |
| 62 | `goto_rewind1` | 1 | 2.5s |  |
| 63 | `goto_rewind2` | 3 | 2.5s |  |
| 64 | `goto_rewind3` | 2 | 2.5s |  |
| 65 | `greater_swf6` | 1175 | 11.9s |  |
| 66 | `greater_swf7` | 1175 | 11.9s |  |
| 67 | `greaterthan_swf5` | 1 | 2.5s |  |
| 68 | `greaterthan_swf8` | 1 | 2.5s |  |
| 69 | `has_own_property` | 32 | 2.6s |  |
| 70 | `infinite_recursion_function` | 4 | 2.5s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 71 | `infinite_recursion_function_in_setter` | 131 | 2.5s |  |
| 72 | `infinite_recursion_virtual_property` | 67 | 2.5s |  |
| 73 | `init_array_invalid` | 4 | 2.5s |  |
| 74 | `init_object_invalid` | 4 | 2.5s |  |
| 75 | `issue_1086` | 1 | 2.5s |  |
| 76 | `issue_1671` | 0 | 2.5s |  |
| 77 | `issue_3446` | 1 | 2.5s |  |
| 78 | `issue_4377` | 2 | 2.5s |  |
| 79 | `issue_768` | 3 | 2.5s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 80 | `lessthan` | 41 | 2.6s |  |
| 81 | `lessthan2_swf5` | 1226 | 12.6s |  |
| 82 | `lessthan2_swf6` | 1226 | 12.5s |  |
| 83 | `lessthan2_swf7` | 1226 | 12.6s |  |
| 84 | `lessthan_swf4` | 902 | 8.4s |  |
| 85 | `lessthan_swf4_alt` | 41 | 2.6s |  |
| 86 | `lessthan_swf5` | 41 | 2.7s |  |
| 87 | `logical_ops_swf4` | 90 | 2.6s |  |
| 88 | `logical_ops_swf8` | 108 | 2.7s |  |
| 89 | `looping` | 6 | 2.5s |  |
| 90 | `mask_reapply` | 0 | 2.5s |  |
| 91 | `mask_with_drawing` | 0 | 2.5s |  |
| 92 | `movieclip_begin_gradient_fill` | 0 | 3.2s |  |
| 93 | `movieclip_line_gradient_style` | 0 | 3.0s |  |
| 94 | `movieclip_prototype_extension` | 5 | 2.4s |  |
| 95 | `nested_textfields_in_buttons` | 0 | 2.4s |  |
| 96 | `netstream_play_flv_screen` | 0 | 29.1s |  |
| 97 | `new_object_enumerate` | 7 | 2.5s |  |
| 98 | `object_constructor` | 33 | 2.5s |  |
| 99 | `object_function` | 32 | 2.5s |  |
| 100 | `object_string_coerce_swf5` | 62 | 2.5s |  |
| 101 | `primitive_instanceof` | 37 | 2.5s |  |
| 102 | `prototype_delete` | 12 | 2.5s |  |
| 103 | `sandbox_type_local_network` | 1 | 2.4s |  |
| 104 | `single_frame` | 1 | 2.4s |  |
| 105 | `sound_start_load` | 0 | 2.5s |  |
| 106 | `strictequals_swf6` | 902 | 9.0s |  |
| 107 | `strictly_equals` | 7 | 2.5s |  |
| 108 | `string_coercion` | 117 | 3.1s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 109 | `string_paths_keyevents` | 0 | 2.5s |  |
| 110 | `string_paths_timer` | 0 | 2.5s |  |
| 111 | `swf4_actions_bool` | 96 | 2.6s |  |
| 112 | `swf4_bool` | 4 | 2.5s |  |
| 113 | `swf4_function_calls` | 7 | 2.5s |  |
| 114 | `swf5_encoding` | 3 | 4.2s |  |
| 115 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.3s |  |
| 116 | `this_swf7` | 41 | 2.4s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 117 | `timeline_function_def` | 7 | 2.4s |  |
| 118 | `try_finally_simple` | 16 | 2.4s |  |
| 119 | `typeof_globals` | 7 | 2.3s |  |
| 120 | `undefined_to_string_swf6` | 4 | 2.3s |  |
| 121 | `unescape` | 43 | 2.5s |  |
| 122 | `with_return` | 2 | 2.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**94 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 2 | `get_variable_in_scope` | 89.7% | 26 | 29 | 3 |  |
| 3 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 4 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 5 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 6 | `stage_object_children` | 79.5% | 66 | 83 | 17 |  |
| 7 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 8 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 9 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 10 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 11 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 12 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 13 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 14 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 15 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 16 | `point` | 70.9% | 124 | 175 | 51 |  |
| 17 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 18 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 19 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 20 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 21 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 22 | `define_function2_preload` | 69.2% | 9 | 13 | 4 |  |
| 23 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 24 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 25 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 26 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 27 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 28 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 29 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 30 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 31 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 32 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 33 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 34 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 35 | `o` | 66.7% | 2 | 3 | 1 |  |
| 36 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 37 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 38 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 39 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 40 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 42 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 43 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 44 | `with` | 63.3% | 31 | 49 | 18 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 46 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 47 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 48 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 49 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 50 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 52 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 53 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 54 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 55 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 56 | `stage_object_properties_get_var` | 60.0% | 3 | 5 | 2 |  |
| 57 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 58 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 59 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 60 | `as_set_prop_flags_version` | 58.1% | 18 | 31 | 13 |  |
| 61 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 62 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 63 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 64 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 65 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 66 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 67 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 68 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 69 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 70 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 71 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 72 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 73 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 74 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 75 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 76 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 77 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 78 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 79 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 80 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 81 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 82 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 83 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 84 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 85 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 88 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 89 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 90 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 91 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 92 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 94 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 8.7s |  |
| 2 | `duplicate_movie_clip_drawing` | 3.7s |  |
| 3 | `path_string` | 5.0s |  |
| 4 | `swf4_actions_coercion_order` | 4.7s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.3s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.3s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.5s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.5s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.5s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 13.1s |  |

## All Output Mismatches

**484 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 2 | `get_variable_in_scope` | 89.7% | 26/29 | 29 | 29 |  |
| 3 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 4 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 5 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 6 | `stage_object_children` | 79.5% | 66/83 | 83 | 83 |  |
| 7 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 8 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 9 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 10 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 12 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 13 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 14 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 15 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 16 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 17 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 18 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 19 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 20 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 21 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 22 | `define_function2_preload` | 69.2% | 9/13 | 13 | 13 |  |
| 23 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 24 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 25 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 26 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 27 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 28 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 29 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 30 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 31 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 32 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 33 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 34 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 35 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 37 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 38 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 39 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 40 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 42 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 43 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 44 | `with` | 63.3% | 31/49 | 47 | 49 |  |
| 45 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 46 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 47 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 48 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 49 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 50 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 52 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 53 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 54 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 55 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 56 | `stage_object_properties_get_var` | 60.0% | 3/5 | 5 | 5 |  |
| 57 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 58 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 59 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 60 | `as_set_prop_flags_version` | 58.1% | 18/31 | 29 | 31 |  |
| 61 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 62 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 63 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 64 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 65 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 66 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 67 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 68 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 69 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 70 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 71 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 72 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 73 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 74 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 75 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 76 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 77 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 78 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 79 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 80 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 81 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 82 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 83 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 84 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 85 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 89 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 90 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 91 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 92 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 94 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 95 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 96 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 97 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 98 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 99 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 100 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 101 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 102 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 103 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 104 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 105 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 106 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 107 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 108 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 109 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 110 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 111 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 112 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 113 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 114 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 115 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 116 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 117 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 118 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 119 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 120 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 121 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 122 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 123 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 124 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 125 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 126 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 127 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 128 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 129 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 130 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 131 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 132 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 133 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 134 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 135 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 136 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 137 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 138 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 139 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 140 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 141 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 142 | `issue_710` | 25.0% | 1/4 | 2 | 4 |  |
| 143 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 144 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 145 | `new_object_wrap` | 25.0% | 1/4 | 4 | 4 |  |
| 146 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 147 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 148 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 149 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 150 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 151 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 152 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 153 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 154 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 155 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 156 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 157 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 158 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 159 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 160 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 161 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 162 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 163 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 164 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 165 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 166 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 167 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 168 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 169 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 170 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 171 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 172 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 173 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 174 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 175 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 176 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 177 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 178 | `waitforframe` | 14.3% | 1/7 | 2 | 7 |  |
| 179 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 180 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 181 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 182 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 |  |
| 183 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 184 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 185 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 186 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 187 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 188 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 189 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 190 | `textfield_props_swf5` | 12.0% | 21/175 | 139 | 175 |  |
| 191 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 192 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 193 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 194 | `printjob_props_swf7` | 11.1% | 5/45 | 35 | 45 |  |
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
| 232 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 233 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 234 | `netstream_seek_flv` | 2.0% | 1/50 | 50 | 25 |  |
| 235 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 236 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 237 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 238 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
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
| 255 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 256 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 257 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 258 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 259 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 260 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 261 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 262 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 263 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 264 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 265 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 266 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 267 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 268 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 269 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 270 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 271 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 272 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 273 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 274 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 275 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 276 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 277 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 278 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 280 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 281 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 282 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 283 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 284 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 285 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 286 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 287 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 288 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 289 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 290 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 291 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 292 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 293 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 294 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 295 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 296 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 297 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 298 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 299 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 300 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 302 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 303 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 304 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 305 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 306 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 307 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 308 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 309 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 310 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 311 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 312 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 313 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 314 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 315 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 316 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 317 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 318 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 319 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 320 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 321 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 322 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 323 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 324 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 325 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 326 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 327 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 328 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 329 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 330 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 331 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 332 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 333 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 334 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 335 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 336 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 337 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 338 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 339 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 340 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 341 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 342 | `global_proto_decls` | 0.0% | 0/4497 | 2 | 4497 |  |
| 343 | `global_proto_decls_delete` | 0.0% | 0/4158 | 2 | 4158 |  |
| 344 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 345 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 346 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 347 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 348 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 349 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 350 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 351 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 352 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 353 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 354 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 355 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 356 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 357 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 358 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 359 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 360 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 361 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 362 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 363 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 364 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 365 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 366 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 367 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 368 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 369 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 370 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 371 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 372 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 373 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 374 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 375 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 376 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 377 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 378 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 379 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 380 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 381 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 382 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 383 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 384 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 385 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 386 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 387 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 388 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 389 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 390 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 391 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 392 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 393 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 394 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 395 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 396 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 397 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 398 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 399 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 400 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 401 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 402 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 403 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 404 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 405 | `new_method_wrap` | 0.0% | 0/4 | 4 | 4 |  |
| 406 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 407 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 408 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 409 | `parse_int` | 0.0% | 0/193 | 193 | 64 |  |
| 410 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 411 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 412 | `recursive_prototypes` | 0.0% | 0/2 | 2 | 0 |  |
| 413 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 414 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 415 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 416 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 417 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 418 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 419 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 420 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 421 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 422 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 423 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 424 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 425 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 426 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 427 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 428 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 429 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 430 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 431 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 432 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 433 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 434 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 435 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 436 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 437 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 438 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 439 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 440 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 441 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 442 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 443 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 444 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 445 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 446 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 447 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 448 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 449 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 450 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 451 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 452 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 453 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 454 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 455 | `tell_target_invalid` | 0.0% | 0/6 | 4 | 6 |  |
| 456 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 4 | 5 |  |
| 457 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 458 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 459 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 460 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 461 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 462 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 463 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 464 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 465 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 466 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 467 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 468 | `variable_args` | 0.0% | 0/5 | 3 | 5 |  |
| 469 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 470 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 471 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 472 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 473 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 474 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 475 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 476 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 477 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 478 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 479 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 480 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 481 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 482 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 483 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 484 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
