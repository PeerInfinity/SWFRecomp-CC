# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 20:11 UTC

**Git SHA**: `4f02643fec`

**Run Duration**: 33m 36s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **137** (22.1%) |
| Failing | 482 |
| Total expected lines | 91286 |
| Matching lines | 33503 (36.7%) |
| Mismatched lines | 57783 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 472 | 97.9% |
| Runtime Segfault | 5 | 1.0% |
| Timeout | 3 | 0.6% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**137 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.4s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.7s |  |
| 6 | `add_swf5` | 28 | 2.7s |  |
| 7 | `array_concat` | 98 | 2.9s |  |
| 8 | `array_constructor` | 30 | 2.8s |  |
| 9 | `array_length` | 42 | 2.9s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.9s |  |
| 12 | `array_splice` | 207 | 3.6s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.8s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.8s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.7s |  |
| 22 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 23 | `bitand` | 1058 | 9.8s |  |
| 24 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 25 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 26 | `bitmap_data_perlinnoise` | 0 | 3.5s |  |
| 27 | `bitmap_data_pixeldissolve_image` | 0 | 3.2s |  |
| 28 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 29 | `bitor` | 1058 | 9.5s |  |
| 30 | `biturshift` | 14 | 4.1s |  |
| 31 | `biturshift_swf8` | 14 | 2.7s |  |
| 32 | `bitxor` | 1058 | 10.1s |  |
| 33 | `call_method_empty_name` | 1 | 2.6s |  |
| 34 | `catch_references_registers` | 2 | 2.7s |  |
| 35 | `define_function2` | 8 | 2.7s |  |
| 36 | `define_function2_preload` | 13 | 2.7s |  |
| 37 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 38 | `delete` | 3 | 2.8s |  |
| 39 | `divide_swf4` | 107 | 2.9s |  |
| 40 | `do_init_action` | 3 | 2.7s |  |
| 41 | `equals` | 32 | 2.7s |  |
| 42 | `equals2_swf5` | 926 | 11.1s |  |
| 43 | `equals2_swf6` | 926 | 10.9s |  |
| 44 | `equals2_swf7` | 926 | 10.8s |  |
| 45 | `equals_swf4` | 665 | 6.1s |  |
| 46 | `equals_swf4_alt` | 32 | 2.7s |  |
| 47 | `equals_swf5` | 32 | 2.7s |  |
| 48 | `error` | 58 | 2.8s |  |
| 49 | `escape` | 14 | 2.6s |  |
| 50 | `execution_order3` | 4 | 2.6s |  |
| 51 | `focusrect_mouse_swf8` | 0 | 2.6s |  |
| 52 | `focusrect_mouse_swf9` | 0 | 2.6s |  |
| 53 | `focusrect_swf5` | 6 | 2.8s |  |
| 54 | `get_variable_in_scope` | 29 | 2.7s |  |
| 55 | `getproperty` | 28 | 2.6s |  |
| 56 | `getproperty_swf4` | 28 | 2.6s |  |
| 57 | `getproperty_swf5` | 28 | 2.6s |  |
| 58 | `global_array` | 3 | 2.5s |  |
| 59 | `global_is_bare` | 7 | 2.5s |  |
| 60 | `goto_advance2` | 2 | 2.6s |  |
| 61 | `goto_both_ways1` | 3 | 3.0s |  |
| 62 | `goto_both_ways2` | 3 | 2.6s |  |
| 63 | `goto_execution_order` | 2 | 2.6s |  |
| 64 | `goto_execution_order2` | 2 | 2.6s |  |
| 65 | `goto_frame_number` | 3 | 2.7s |  |
| 66 | `goto_rewind1` | 1 | 2.7s |  |
| 67 | `goto_rewind2` | 3 | 2.7s |  |
| 68 | `goto_rewind3` | 2 | 2.7s |  |
| 69 | `greater_swf6` | 1175 | 12.1s |  |
| 70 | `greater_swf7` | 1175 | 12.0s |  |
| 71 | `greaterthan_swf5` | 1 | 2.6s |  |
| 72 | `greaterthan_swf8` | 1 | 2.6s |  |
| 73 | `has_own_property` | 32 | 2.8s |  |
| 74 | `infinite_recursion_function` | 4 | 2.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 75 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 76 | `infinite_recursion_virtual_property` | 67 | 2.6s |  |
| 77 | `init_array_invalid` | 4 | 2.6s |  |
| 78 | `init_object_invalid` | 4 | 2.6s |  |
| 79 | `issue_1086` | 1 | 2.6s |  |
| 80 | `issue_1671` | 0 | 2.6s |  |
| 81 | `issue_1906` | 4 | 2.8s |  |
| 82 | `issue_3446` | 1 | 2.7s |  |
| 83 | `issue_4377` | 2 | 2.8s |  |
| 84 | `issue_710` | 4 | 2.7s |  |
| 85 | `issue_768` | 3 | 2.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 86 | `lessthan` | 41 | 2.8s |  |
| 87 | `lessthan2_swf5` | 1226 | 12.4s |  |
| 88 | `lessthan2_swf6` | 1226 | 12.6s |  |
| 89 | `lessthan2_swf7` | 1226 | 12.6s |  |
| 90 | `lessthan_swf4` | 902 | 8.4s |  |
| 91 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 92 | `lessthan_swf5` | 41 | 2.7s |  |
| 93 | `logical_ops_swf4` | 90 | 2.7s |  |
| 94 | `logical_ops_swf8` | 108 | 2.8s |  |
| 95 | `looping` | 6 | 2.6s |  |
| 96 | `mask_reapply` | 0 | 2.6s |  |
| 97 | `mask_with_drawing` | 0 | 2.6s |  |
| 98 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 99 | `movieclip_line_gradient_style` | 0 | 3.2s |  |
| 100 | `movieclip_name_from_timeline` | 13 | 2.6s |  |
| 101 | `movieclip_prototype_extension` | 5 | 2.6s |  |
| 102 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 103 | `netstream_play_flv_screen` | 0 | 30.2s |  |
| 104 | `new_method_wrap` | 4 | 2.6s |  |
| 105 | `new_object_enumerate` | 7 | 2.7s |  |
| 106 | `new_object_wrap` | 4 | 2.6s |  |
| 107 | `o` | 3 | 2.6s |  |
| 108 | `object_constructor` | 33 | 2.7s |  |
| 109 | `object_function` | 32 | 2.7s |  |
| 110 | `object_string_coerce_swf5` | 62 | 2.8s |  |
| 111 | `primitive_instanceof` | 37 | 2.7s |  |
| 112 | `prototype_delete` | 12 | 2.7s |  |
| 113 | `recursive_prototypes` | 0 | 2.6s |  |
| 114 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 115 | `single_frame` | 1 | 2.6s |  |
| 116 | `sound_start_load` | 0 | 2.6s |  |
| 117 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 118 | `strictequals_swf6` | 902 | 8.9s |  |
| 119 | `strictly_equals` | 7 | 2.7s |  |
| 120 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 121 | `string_paths_keyevents` | 0 | 2.6s |  |
| 122 | `string_paths_timer` | 0 | 2.6s |  |
| 123 | `swf4_actions_bool` | 96 | 2.8s |  |
| 124 | `swf4_bool` | 4 | 2.6s |  |
| 125 | `swf4_function_calls` | 7 | 3.1s |  |
| 126 | `swf5_encoding` | 3 | 2.6s |  |
| 127 | `swf7_case_sensitive` | 44 | 2.8s |  |
| 128 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.6s |  |
| 129 | `this_swf7` | 41 | 2.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 130 | `timeline_function_def` | 7 | 2.7s |  |
| 131 | `try_finally_simple` | 16 | 2.6s |  |
| 132 | `typeof_globals` | 7 | 2.6s |  |
| 133 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 134 | `unescape` | 43 | 2.7s |  |
| 135 | `waitforframe` | 7 | 2.6s |  |
| 136 | `waitforframe2` | 16 | 2.6s |  |
| 137 | `with_return` | 2 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**87 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 2 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 3 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 4 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 5 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 6 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 7 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 8 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 9 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 10 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 11 | `textfield_text` | 71.4% | 5 | 7 | 2 |  |
| 12 | `point` | 70.9% | 124 | 175 | 51 |  |
| 13 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 14 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 15 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 16 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 17 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 18 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 19 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 20 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 21 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 22 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 23 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 24 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 25 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 26 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 27 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 28 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 29 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 30 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 31 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 32 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 33 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 34 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 35 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 36 | `slash_syntax` | 64.3% | 9 | 14 | 5 |  |
| 37 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 38 | `textfield_background_color` | 63.6% | 7 | 11 | 4 |  |
| 39 | `textfield_border_color` | 63.6% | 7 | 11 | 4 |  |
| 40 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 41 | `with` | 61.2% | 30 | 49 | 19 |  |
| 42 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 43 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 44 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 45 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 46 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 47 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 48 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 49 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 50 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 51 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 53 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 54 | `textfield_properties` | 59.1% | 26 | 44 | 18 |  |
| 55 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 56 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 57 | `edittext_scroll` | 57.4% | 31 | 54 | 23 |  |
| 58 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 59 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 60 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 61 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 62 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 63 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 64 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 65 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 66 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 67 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 68 | `textfield_variable` | 54.3% | 44 | 81 | 37 |  |
| 69 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 70 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 71 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 72 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 73 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 74 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 75 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 76 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 77 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 78 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 79 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 80 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 81 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 82 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 83 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 84 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 85 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 87 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `define_local` | 4.8s |  |
| 2 | `device_font_spacing` | 12.2s |  |
| 3 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 4 | `path_string` | 5.2s |  |
| 5 | `swf4_actions_coercion_order` | 5.0s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.6s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.6s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.7s |  |
| 2 | `timeout` | runtime timeout (>10s) | 12.7s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.0s |  |

## All Output Mismatches

**472 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 2 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 3 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 4 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 5 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 6 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 7 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 8 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 9 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 10 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 11 | `textfield_text` | 71.4% | 5/7 | 7 | 7 |  |
| 12 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 13 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 14 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 15 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 16 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 17 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 18 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 19 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 20 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 21 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 22 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 23 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 24 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 25 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 26 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 27 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 28 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 29 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 30 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 31 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 32 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 33 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 34 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 35 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 36 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 |  |
| 37 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 38 | `textfield_background_color` | 63.6% | 7/11 | 11 | 11 |  |
| 39 | `textfield_border_color` | 63.6% | 7/11 | 11 | 11 |  |
| 40 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 41 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 42 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 43 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 44 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 45 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 46 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 47 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 48 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 49 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 50 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 51 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 52 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 53 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 54 | `textfield_properties` | 59.1% | 26/44 | 44 | 44 |  |
| 55 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 56 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 57 | `edittext_scroll` | 57.4% | 31/54 | 54 | 54 |  |
| 58 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 59 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 60 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 61 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 62 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 63 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 64 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 65 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 66 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 67 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 68 | `textfield_variable` | 54.3% | 44/81 | 81 | 81 |  |
| 69 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 70 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 71 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 72 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 73 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 74 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 75 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 76 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 77 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 78 | `define_function2_preload_order` | 50.0% | 2/4 | 2 | 4 |  |
| 79 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 80 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 81 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 82 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 83 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 84 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 85 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 87 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 89 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 90 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 91 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 92 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 93 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 94 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 95 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 96 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 97 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 98 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 99 | `execution_order2` | 42.9% | 3/7 | 6 | 7 |  |
| 100 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 101 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 102 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 103 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 104 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 105 | `clone_sprite_types` | 37.5% | 9/24 | 24 | 24 |  |
| 106 | `edittext_html_swf6` | 37.3% | 2006/5377 | 5377 | 5377 |  |
| 107 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 108 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 109 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 110 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 111 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 112 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 113 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 114 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 115 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 116 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 117 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 118 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 119 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 120 | `remove_movie_clip` | 31.0% | 9/29 | 17 | 29 |  |
| 121 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 122 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 123 | `edittext_html_condensewhite_swf7` | 29.6% | 92/311 | 311 | 311 |  |
| 124 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 125 | `edittext_html_condensewhite_swf8` | 28.6% | 89/311 | 311 | 311 |  |
| 126 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 127 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 128 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 129 | `edittext_html_swf7` | 25.5% | 1370/5377 | 5377 | 5377 |  |
| 130 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 131 | `edittext_html_swf8` | 25.2% | 1355/5377 | 5377 | 5377 |  |
| 132 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 133 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 134 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 135 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 136 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 137 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 138 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 139 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 140 | `edittext_newline_stripping` | 23.4% | 15/64 | 54 | 64 |  |
| 141 | `stage_object_properties_swf6` | 23.4% | 54/231 | 165 | 231 |  |
| 142 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 143 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 144 | `stage_object_properties` | 22.4% | 54/241 | 175 | 241 |  |
| 145 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 146 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 147 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 148 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 149 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 150 | `target_clip_removed` | 20.0% | 1/5 | 5 | 5 |  |
| 151 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 152 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 153 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 154 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 155 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 156 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 157 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 158 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 159 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 160 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 161 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 162 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 163 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 164 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 165 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 166 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 167 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 168 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 169 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 170 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 171 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 172 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 173 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 174 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 175 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 176 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 177 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 178 | `register_and_init_order` | 13.0% | 30/231 | 54 | 231 |  |
| 179 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 180 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 181 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 182 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 183 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 184 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 185 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 186 | `tell_target` | 10.8% | 4/37 | 33 | 37 |  |
| 187 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 188 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 189 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 190 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 191 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 192 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 193 | `execution_order4` | 8.3% | 1/12 | 7 | 12 |  |
| 194 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 195 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 196 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 197 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 198 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 199 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 200 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 201 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 202 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 203 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 204 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 205 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 206 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 207 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 208 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 209 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 210 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 211 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 212 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 213 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 214 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 215 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 216 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 217 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 218 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 219 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 220 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 221 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 222 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 223 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 224 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 225 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 226 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 227 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 228 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 229 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 230 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 231 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 232 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 233 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 234 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 235 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 236 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 237 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 238 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 239 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 240 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 241 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 242 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 243 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 244 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 245 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 246 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 247 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 248 | `as2_oop` | 0.0% | 0/13 | 0 | 13 |  |
| 249 | `as2_super_and_this_v6` | 0.0% | 0/97 | 0 | 97 |  |
| 250 | `as2_super_and_this_v8` | 0.0% | 0/85 | 0 | 85 |  |
| 251 | `as2_super_via_manual_prototype` | 0.0% | 0/40 | 0 | 40 |  |
| 252 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 253 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 254 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 256 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 257 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 258 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 259 | `button_children` | 0.0% | 0/8 | 0 | 8 |  |
| 260 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 261 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 262 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 263 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 264 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 265 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 266 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 267 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 268 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 269 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 270 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 271 | `call` | 0.0% | 0/63 | 0 | 63 |  |
| 272 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 273 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 274 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 275 | `clone_sprite_edittext` | 0.0% | 0/94 | 94 | 94 |  |
| 276 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 277 | `closure_scope` | 0.0% | 0/7 | 3 | 7 |  |
| 278 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 279 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 280 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 281 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 282 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 283 | `custom_clip_methods` | 0.0% | 0/4 | 1 | 4 |  |
| 284 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 285 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 286 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 287 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 289 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 290 | `edittext_autosize_setter` | 0.0% | 0/20 | 20 | 20 |  |
| 291 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 292 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 293 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 294 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 295 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 296 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 297 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 298 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 301 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 302 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 303 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 304 | `edittext_tag_indent` | 0.0% | 0/31 | 31 | 31 |  |
| 305 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 306 | `execution_order1` | 0.0% | 0/5 | 2 | 5 |  |
| 307 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 308 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 309 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 310 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 311 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 312 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 313 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 314 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 315 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 316 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 317 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 318 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 319 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 320 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 321 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 322 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 323 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 324 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 325 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 326 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 327 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 328 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 329 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 330 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 331 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 332 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 333 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 334 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 335 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 336 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 337 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 338 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 339 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 340 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 341 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 342 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 343 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 344 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 345 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 346 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 347 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 350 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 351 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 352 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 353 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 354 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 355 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 356 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 357 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 358 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 359 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 360 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 361 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 362 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 363 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 364 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 365 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 366 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 367 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 368 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 369 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 370 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 371 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 372 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 373 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 374 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 375 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 376 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 377 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 378 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 379 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 380 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 381 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 382 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 383 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 384 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 385 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 386 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 387 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 388 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 389 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 390 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 391 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 392 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 393 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 394 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 395 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 396 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 397 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 398 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 399 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 400 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 401 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 402 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 403 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 404 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 405 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 406 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 407 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 408 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 409 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 410 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 411 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 412 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 413 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 414 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 415 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 416 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 417 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 418 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 419 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 420 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 421 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 422 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 423 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 424 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 425 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 426 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 427 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 428 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 429 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 430 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 431 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 432 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 433 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 434 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 435 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 436 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 437 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 438 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 439 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 440 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 441 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 442 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 443 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 444 | `tell_target_invalid` | 0.0% | 0/6 | 6 | 6 |  |
| 445 | `tell_target_invalid_swf6` | 0.0% | 0/6 | 6 | 5 |  |
| 446 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 447 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 448 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 449 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 450 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 451 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 452 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 453 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 454 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 455 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 456 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |
| 457 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 458 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 459 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 460 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 461 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 462 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 463 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 464 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 465 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 466 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 467 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 468 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 469 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 470 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 471 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 472 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
