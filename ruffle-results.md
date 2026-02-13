# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 06:42 UTC

**Git SHA**: `360cd1250a`

**Run Duration**: 32m 36s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **128** (20.8%) |
| Failing | 488 |
| Total expected lines | 89690 |
| Matching lines | 33321 (37.2%) |
| Mismatched lines | 56369 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 478 | 98.0% |
| Timeout | 4 | 0.8% |
| Runtime Segfault | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**128 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.9s |  |
| 2 | `action_to_integer` | 28 | 2.6s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.0s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.6s |  |
| 6 | `add_swf5` | 28 | 2.6s |  |
| 7 | `array_concat` | 98 | 2.8s |  |
| 8 | `array_constructor` | 30 | 2.7s |  |
| 9 | `array_properties` | 36 | 2.7s |  |
| 10 | `array_slice` | 34 | 2.7s |  |
| 11 | `array_splice` | 207 | 3.4s |  |
| 12 | `array_trivial` | 209 | 3.1s |  |
| 13 | `as1_constructor_v6` | 35 | 2.7s |  |
| 14 | `as1_constructor_v7` | 35 | 2.7s |  |
| 15 | `as_broadcaster_initialize` | 10 | 2.5s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf6` | 1 | 2.6s |  |
| 18 | `as_set_prop_flags_version_swf7` | 1 | 2.6s |  |
| 19 | `as_set_prop_flags_version_swf8` | 1 | 2.6s |  |
| 20 | `as_set_prop_flags_version_swf9` | 1 | 2.6s |  |
| 21 | `bad_swf_tag_past_eof` | 0 | 2.5s |  |
| 22 | `bitand` | 1058 | 9.6s |  |
| 23 | `bitmap_data_colortransform` | 0 | 2.8s |  |
| 24 | `bitmap_data_fillrect` | 0 | 2.7s |  |
| 25 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 26 | `bitmap_data_pixeldissolve_image` | 0 | 3.1s |  |
| 27 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.6s |  |
| 28 | `bitor` | 1058 | 9.6s |  |
| 29 | `biturshift` | 14 | 3.9s |  |
| 30 | `biturshift_swf8` | 14 | 2.6s |  |
| 31 | `bitxor` | 1058 | 9.4s |  |
| 32 | `call_method_empty_name` | 1 | 2.5s |  |
| 33 | `catch_references_registers` | 2 | 2.5s |  |
| 34 | `define_function2` | 8 | 2.5s |  |
| 35 | `define_function_case_sensitive` | 2 | 2.5s |  |
| 36 | `delete` | 3 | 2.6s |  |
| 37 | `divide_swf4` | 107 | 2.8s |  |
| 38 | `do_init_action` | 3 | 2.6s |  |
| 39 | `equals` | 32 | 2.6s |  |
| 40 | `equals2_swf5` | 926 | 10.7s |  |
| 41 | `equals2_swf6` | 926 | 10.9s |  |
| 42 | `equals2_swf7` | 926 | 10.8s |  |
| 43 | `equals_swf4` | 665 | 6.1s |  |
| 44 | `equals_swf4_alt` | 32 | 2.6s |  |
| 45 | `equals_swf5` | 32 | 2.6s |  |
| 46 | `error` | 58 | 2.7s |  |
| 47 | `escape` | 14 | 2.5s |  |
| 48 | `execution_order3` | 4 | 2.5s |  |
| 49 | `focusrect_mouse_swf8` | 0 | 2.5s |  |
| 50 | `focusrect_mouse_swf9` | 0 | 2.5s |  |
| 51 | `focusrect_swf5` | 6 | 2.8s |  |
| 52 | `get_variable_in_scope` | 29 | 2.7s |  |
| 53 | `getproperty` | 28 | 2.6s |  |
| 54 | `getproperty_swf4` | 28 | 2.6s |  |
| 55 | `getproperty_swf5` | 28 | 2.6s |  |
| 56 | `global_array` | 3 | 2.5s |  |
| 57 | `global_is_bare` | 7 | 2.5s |  |
| 58 | `goto_advance2` | 2 | 2.6s |  |
| 59 | `goto_both_ways1` | 3 | 4.0s |  |
| 60 | `goto_both_ways2` | 3 | 2.7s |  |
| 61 | `goto_execution_order` | 2 | 2.6s |  |
| 62 | `goto_execution_order2` | 2 | 2.7s |  |
| 63 | `goto_rewind1` | 1 | 2.7s |  |
| 64 | `goto_rewind2` | 3 | 2.7s |  |
| 65 | `goto_rewind3` | 2 | 2.6s |  |
| 66 | `greater_swf6` | 1175 | 12.3s |  |
| 67 | `greater_swf7` | 1175 | 12.3s |  |
| 68 | `greaterthan_swf5` | 1 | 2.6s |  |
| 69 | `greaterthan_swf8` | 1 | 2.6s |  |
| 70 | `has_own_property` | 32 | 2.8s |  |
| 71 | `infinite_recursion_function` | 4 | 2.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 72 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 73 | `infinite_recursion_virtual_property` | 67 | 2.6s |  |
| 74 | `init_array_invalid` | 4 | 2.6s |  |
| 75 | `init_object_invalid` | 4 | 2.6s |  |
| 76 | `issue_1086` | 1 | 2.6s |  |
| 77 | `issue_1671` | 0 | 2.6s |  |
| 78 | `issue_3446` | 1 | 2.6s |  |
| 79 | `issue_4377` | 2 | 2.6s |  |
| 80 | `issue_710` | 4 | 2.6s |  |
| 81 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 82 | `lessthan` | 41 | 2.8s |  |
| 83 | `lessthan2_swf5` | 1226 | 12.8s |  |
| 84 | `lessthan2_swf6` | 1226 | 12.8s |  |
| 85 | `lessthan2_swf7` | 1226 | 12.8s |  |
| 86 | `lessthan_swf4` | 902 | 8.6s |  |
| 87 | `lessthan_swf4_alt` | 41 | 2.7s |  |
| 88 | `lessthan_swf5` | 41 | 2.7s |  |
| 89 | `logical_ops_swf4` | 90 | 2.7s |  |
| 90 | `logical_ops_swf8` | 108 | 2.7s |  |
| 91 | `looping` | 6 | 2.5s |  |
| 92 | `mask_reapply` | 0 | 2.5s |  |
| 93 | `mask_with_drawing` | 0 | 2.6s |  |
| 94 | `movieclip_begin_gradient_fill` | 0 | 3.2s |  |
| 95 | `movieclip_line_gradient_style` | 0 | 3.1s |  |
| 96 | `movieclip_prototype_extension` | 5 | 2.5s |  |
| 97 | `nested_textfields_in_buttons` | 0 | 2.5s |  |
| 98 | `netstream_play_flv_screen` | 0 | 29.3s |  |
| 99 | `new_method_wrap` | 4 | 2.5s |  |
| 100 | `new_object_enumerate` | 7 | 2.5s |  |
| 101 | `new_object_wrap` | 4 | 2.5s |  |
| 102 | `object_constructor` | 33 | 2.6s |  |
| 103 | `object_function` | 32 | 2.6s |  |
| 104 | `object_string_coerce_swf5` | 62 | 2.6s |  |
| 105 | `primitive_instanceof` | 37 | 2.6s |  |
| 106 | `prototype_delete` | 12 | 2.5s |  |
| 107 | `recursive_prototypes` | 0 | 2.5s |  |
| 108 | `sandbox_type_local_network` | 1 | 2.5s |  |
| 109 | `single_frame` | 1 | 2.5s |  |
| 110 | `sound_start_load` | 0 | 2.6s |  |
| 111 | `stage_object_properties_get_var` | 5 | 2.5s |  |
| 112 | `strictequals_swf6` | 902 | 9.2s |  |
| 113 | `strictly_equals` | 7 | 2.6s |  |
| 114 | `string_coercion` | 117 | 3.2s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 115 | `string_paths_keyevents` | 0 | 2.6s |  |
| 116 | `string_paths_timer` | 0 | 2.6s |  |
| 117 | `swf4_actions_bool` | 96 | 2.7s |  |
| 118 | `swf4_bool` | 4 | 2.6s |  |
| 119 | `swf4_function_calls` | 7 | 2.6s |  |
| 120 | `swf5_encoding` | 3 | 2.7s |  |
| 121 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.5s |  |
| 122 | `this_swf7` | 41 | 2.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 123 | `timeline_function_def` | 7 | 2.6s |  |
| 124 | `try_finally_simple` | 16 | 2.5s |  |
| 125 | `typeof_globals` | 7 | 2.5s |  |
| 126 | `undefined_to_string_swf6` | 4 | 2.5s |  |
| 127 | `unescape` | 43 | 2.6s |  |
| 128 | `with_return` | 2 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**92 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41 | 44 | 3 |  |
| 2 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 3 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 4 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 5 | `stage_object_children` | 79.5% | 66 | 83 | 17 |  |
| 6 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 7 | `movieclip_name_from_timeline` | 76.9% | 10 | 13 | 3 |  |
| 8 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 9 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 10 | `conflicting_instance_names` | 73.9% | 17 | 23 | 6 |  |
| 11 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 13 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 14 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 15 | `point` | 70.9% | 124 | 175 | 51 |  |
| 16 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 17 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 18 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 19 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 20 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 21 | `define_function2_preload` | 69.2% | 9 | 13 | 4 |  |
| 22 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 23 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 24 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 25 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 27 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 28 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 29 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 30 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 31 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 32 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 33 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 34 | `o` | 66.7% | 2 | 3 | 1 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 36 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 37 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 38 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 39 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 40 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 41 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 42 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 43 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 44 | `with` | 61.2% | 30 | 49 | 19 |  |
| 45 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 46 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 47 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 48 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 49 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 50 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 51 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 52 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 53 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 54 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 56 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 57 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 58 | `as_set_prop_flags_version` | 58.1% | 18 | 31 | 13 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 60 | `waitforframe2` | 57.9% | 11 | 19 | 8 |  |
| 61 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 62 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 63 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 64 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 65 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 66 | `swf6_case_insensitive` | 56.8% | 25 | 44 | 19 |  |
| 67 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 68 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 69 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 70 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 71 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 72 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 73 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 74 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 75 | `textfield_variable` | 53.1% | 43 | 81 | 38 |  |
| 76 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 77 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 78 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 79 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 80 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 81 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 82 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 83 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 84 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 85 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 87 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 88 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 89 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 90 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 92 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.1s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.6s |  |
| 3 | `path_string` | 5.0s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

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
| 1 | `parse_float` | runtime timeout (>10s) | 13.6s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.6s |  |
| 3 | `timeout` | runtime timeout (>10s) | 12.7s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 12.9s |  |

## All Output Mismatches

**478 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 93.2% | 41/44 | 44 | 44 |  |
| 2 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 3 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 4 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 5 | `stage_object_children` | 79.5% | 66/83 | 83 | 83 |  |
| 6 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 7 | `movieclip_name_from_timeline` | 76.9% | 10/13 | 13 | 13 |  |
| 8 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 9 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `conflicting_instance_names` | 73.9% | 17/23 | 23 | 23 |  |
| 11 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 14 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 15 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 16 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 17 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 18 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 19 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 20 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 21 | `define_function2_preload` | 69.2% | 9/13 | 13 | 13 |  |
| 22 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 23 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 24 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 25 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 27 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 28 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 29 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 30 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 31 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 32 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 33 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 34 | `o` | 66.7% | 2/3 | 3 | 3 |  |
| 35 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 36 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 37 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 38 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 39 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 40 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 41 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 42 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 43 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 44 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 45 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 46 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 47 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 48 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 49 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 50 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 51 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 52 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 53 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 54 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 55 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 56 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 57 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 58 | `as_set_prop_flags_version` | 58.1% | 18/31 | 29 | 31 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 60 | `waitforframe2` | 57.9% | 11/19 | 19 | 16 |  |
| 61 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 62 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 63 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 64 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 65 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 66 | `swf6_case_insensitive` | 56.8% | 25/44 | 44 | 42 |  |
| 67 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 68 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 69 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 70 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 71 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 72 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 73 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 74 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 75 | `textfield_variable` | 53.1% | 43/81 | 81 | 81 |  |
| 76 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 77 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 78 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 79 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 80 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 81 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 82 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 83 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 84 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 85 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 87 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 89 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 90 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 92 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 93 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 94 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 95 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 96 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 97 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 98 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 99 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 100 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 101 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 102 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 103 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 104 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 105 | `sound_props_swf6` | 41.2% | 28/68 | 68 | 68 |  |
| 106 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 107 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 108 | `sound_props_swf5` | 39.7% | 27/68 | 67 | 68 |  |
| 109 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 110 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 111 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 112 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 113 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 114 | `clone_sprite_types` | 33.3% | 8/24 | 24 | 24 |  |
| 115 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 116 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 117 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 118 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 119 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 120 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 121 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 122 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 123 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 124 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 125 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 126 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 127 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 128 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 129 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 130 | `frame_size_translated_negative` | 28.6% | 6/21 | 20 | 21 |  |
| 131 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 132 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 133 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 134 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 135 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 136 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 137 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 138 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 139 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 140 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 141 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 142 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 143 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 144 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 145 | `remove_movie_clip` | 24.1% | 7/29 | 17 | 29 |  |
| 146 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 147 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 148 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 149 | `stage_object_properties_swf6` | 22.9% | 53/231 | 165 | 231 |  |
| 150 | `stage_object_properties` | 22.0% | 53/241 | 175 | 241 |  |
| 151 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 152 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 153 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 154 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 155 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 156 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 157 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 158 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 159 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 160 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 161 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 162 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 163 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 164 | `execution_order4` | 16.7% | 2/12 | 10 | 12 |  |
| 165 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 166 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
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
| 192 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 193 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 194 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 195 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 196 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 197 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 198 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 199 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 200 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 201 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 202 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 203 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 204 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 205 | `printjob_props_swf5` | 6.7% | 3/45 | 34 | 45 |  |
| 206 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 207 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 208 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 209 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 210 | `textsnapshot_props_swf6` | 5.4% | 3/56 | 38 | 56 |  |
| 211 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 212 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 213 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 214 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 215 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 216 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 217 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 218 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 219 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 220 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 221 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 222 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 223 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 224 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 225 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 226 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 227 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 228 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 229 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 230 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 231 | `netstream_seek_flv` | 2.0% | 1/50 | 50 | 25 |  |
| 232 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 233 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 234 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 235 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 236 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 237 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 238 | `textfield_props_swf6` | 1.0% | 2/210 | 140 | 210 |  |
| 239 | `textfield_props_swf7` | 1.0% | 2/210 | 140 | 210 |  |
| 240 | `textfield_props_swf8` | 1.0% | 2/210 | 140 | 210 |  |
| 241 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 242 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 243 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 244 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 245 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 246 | `tab_ordering_events` | 0.7% | 1/150 | 12 | 150 |  |
| 247 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 248 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 249 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 250 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 251 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 252 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 253 | `global_proto_decls_delete` | 0.0% | 1/4158 | 20 | 4158 |  |
| 254 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 255 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 256 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 257 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 258 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 259 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 260 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 261 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 262 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 263 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 264 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 265 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 266 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 267 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 268 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 269 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 270 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 271 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 272 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 273 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 274 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 275 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 276 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 277 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 279 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 280 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 281 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 282 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 283 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 284 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 285 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 286 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 287 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 288 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 289 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 290 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 291 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 292 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 293 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 294 | `define_function2_preload_order` | 0.0% | 0/4 | 2 | 4 |  |
| 295 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 296 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 297 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 298 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 299 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 301 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 302 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 303 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 304 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 305 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 307 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 308 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 309 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 311 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 312 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 313 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 314 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 315 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 316 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 317 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 318 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 319 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 320 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 321 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 322 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 323 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 324 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 325 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 326 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 327 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 328 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 329 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 330 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 331 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 332 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 333 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 334 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 335 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 336 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 337 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 338 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 339 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 340 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 341 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 342 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 343 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 344 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 345 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 346 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 347 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 348 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 349 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 350 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 351 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 352 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 353 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 354 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 355 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 356 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 357 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 358 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 359 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 360 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 361 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 362 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 363 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 364 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 365 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 366 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 367 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 368 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 369 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 370 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 371 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 372 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 373 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 374 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 375 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 376 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 377 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 378 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 379 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 380 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 381 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 382 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 383 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 384 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 385 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 386 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 387 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 388 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 389 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 390 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 391 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 392 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 393 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 394 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 395 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 396 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 397 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 398 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 399 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 400 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 401 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 402 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 403 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 404 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 405 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 406 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 407 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 408 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 409 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 410 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 411 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 412 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 413 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 414 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 415 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 416 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 417 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 418 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 419 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 420 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 421 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 422 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 423 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 424 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 425 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 426 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 427 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 428 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 429 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 430 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 431 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 432 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 433 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 434 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 435 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 436 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 437 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 438 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 439 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 440 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 441 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 442 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 443 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 444 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 445 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 446 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 447 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 448 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 449 | `tell_target_invalid` | 0.0% | 0/6 | 4 | 6 |  |
| 450 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 4 | 5 |  |
| 451 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 452 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 453 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 454 | `textsnapshot_props_swf5` | 0.0% | 0/56 | 37 | 56 |  |
| 455 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 456 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 457 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 458 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 459 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 460 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 461 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 462 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |
| 463 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 464 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 465 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 466 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 467 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 468 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 469 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 470 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 471 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 472 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 473 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 474 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 475 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 476 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 477 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 478 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
