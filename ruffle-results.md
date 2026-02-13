# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 07:04 UTC

**Git SHA**: `ced90dd859`

**Run Duration**: 32m 54s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 616 |
| Passing | **129** (20.9%) |
| Failing | 487 |
| Total expected lines | 89690 |
| Matching lines | 33560 (37.4%) |
| Mismatched lines | 56130 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 477 | 97.9% |
| Timeout | 4 | 0.8% |
| Runtime Segfault | 4 | 0.8% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**129 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.3s |  |
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
| 15 | `as_broadcaster_initialize` | 10 | 2.6s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf6` | 1 | 2.6s |  |
| 18 | `as_set_prop_flags_version_swf7` | 1 | 2.6s |  |
| 19 | `as_set_prop_flags_version_swf8` | 1 | 2.6s |  |
| 20 | `as_set_prop_flags_version_swf9` | 1 | 2.6s |  |
| 21 | `bad_swf_tag_past_eof` | 0 | 2.5s |  |
| 22 | `bitand` | 1058 | 9.4s |  |
| 23 | `bitmap_data_colortransform` | 0 | 2.9s |  |
| 24 | `bitmap_data_fillrect` | 0 | 2.8s |  |
| 25 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 26 | `bitmap_data_pixeldissolve_image` | 0 | 3.1s |  |
| 27 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.6s |  |
| 28 | `bitor` | 1058 | 9.3s |  |
| 29 | `biturshift` | 14 | 2.8s |  |
| 30 | `biturshift_swf8` | 14 | 2.6s |  |
| 31 | `bitxor` | 1058 | 10.0s |  |
| 32 | `call_method_empty_name` | 1 | 2.6s |  |
| 33 | `catch_references_registers` | 2 | 2.6s |  |
| 34 | `define_function2` | 8 | 2.7s |  |
| 35 | `define_function_case_sensitive` | 2 | 2.6s |  |
| 36 | `delete` | 3 | 2.7s |  |
| 37 | `divide_swf4` | 107 | 2.8s |  |
| 38 | `do_init_action` | 3 | 2.7s |  |
| 39 | `equals` | 32 | 2.6s |  |
| 40 | `equals2_swf5` | 926 | 11.0s |  |
| 41 | `equals2_swf6` | 926 | 10.9s |  |
| 42 | `equals2_swf7` | 926 | 10.8s |  |
| 43 | `equals_swf4` | 665 | 6.1s |  |
| 44 | `equals_swf4_alt` | 32 | 2.6s |  |
| 45 | `equals_swf5` | 32 | 2.6s |  |
| 46 | `error` | 58 | 2.7s |  |
| 47 | `escape` | 14 | 2.6s |  |
| 48 | `execution_order3` | 4 | 2.6s |  |
| 49 | `focusrect_mouse_swf8` | 0 | 2.6s |  |
| 50 | `focusrect_mouse_swf9` | 0 | 2.6s |  |
| 51 | `focusrect_swf5` | 6 | 2.8s |  |
| 52 | `get_variable_in_scope` | 29 | 2.7s |  |
| 53 | `getproperty` | 28 | 2.6s |  |
| 54 | `getproperty_swf4` | 28 | 2.6s |  |
| 55 | `getproperty_swf5` | 28 | 2.6s |  |
| 56 | `global_array` | 3 | 2.6s |  |
| 57 | `global_is_bare` | 7 | 2.6s |  |
| 58 | `goto_advance2` | 2 | 2.6s |  |
| 59 | `goto_execution_order` | 2 | 2.6s |  |
| 60 | `goto_execution_order2` | 2 | 2.6s |  |
| 61 | `goto_rewind2` | 3 | 2.6s |  |
| 62 | `greater_swf6` | 1175 | 11.8s |  |
| 63 | `greater_swf7` | 1175 | 11.8s |  |
| 64 | `greaterthan_swf5` | 1 | 2.6s |  |
| 65 | `greaterthan_swf8` | 1 | 2.6s |  |
| 66 | `has_own_property` | 32 | 2.7s |  |
| 67 | `infinite_recursion_function` | 4 | 2.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 68 | `infinite_recursion_function_in_setter` | 131 | 2.6s |  |
| 69 | `infinite_recursion_virtual_property` | 67 | 2.6s |  |
| 70 | `init_array_invalid` | 4 | 2.5s |  |
| 71 | `init_object_invalid` | 4 | 2.5s |  |
| 72 | `issue_1086` | 1 | 2.6s |  |
| 73 | `issue_1671` | 0 | 2.6s |  |
| 74 | `issue_1906` | 4 | 2.6s |  |
| 75 | `issue_3446` | 1 | 2.6s |  |
| 76 | `issue_4377` | 2 | 2.6s |  |
| 77 | `issue_710` | 4 | 2.6s |  |
| 78 | `issue_768` | 3 | 2.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 79 | `lessthan` | 41 | 2.7s |  |
| 80 | `lessthan2_swf5` | 1226 | 12.2s |  |
| 81 | `lessthan2_swf6` | 1226 | 12.2s |  |
| 82 | `lessthan2_swf7` | 1226 | 12.2s |  |
| 83 | `lessthan_swf4` | 902 | 8.0s |  |
| 84 | `lessthan_swf4_alt` | 41 | 2.7s |  |
| 85 | `lessthan_swf5` | 41 | 2.7s |  |
| 86 | `logical_ops_swf4` | 90 | 2.6s |  |
| 87 | `logical_ops_swf8` | 108 | 2.7s |  |
| 88 | `looping` | 6 | 2.5s |  |
| 89 | `mask_reapply` | 0 | 2.5s |  |
| 90 | `mask_with_drawing` | 0 | 2.6s |  |
| 91 | `movieclip_begin_gradient_fill` | 0 | 3.2s |  |
| 92 | `movieclip_line_gradient_style` | 0 | 3.1s |  |
| 93 | `movieclip_prototype_extension` | 5 | 2.5s |  |
| 94 | `nested_textfields_in_buttons` | 0 | 2.5s |  |
| 95 | `netstream_play_flv_screen` | 0 | 29.6s |  |
| 96 | `new_method_wrap` | 4 | 2.5s |  |
| 97 | `new_object_enumerate` | 7 | 2.6s |  |
| 98 | `new_object_wrap` | 4 | 2.5s |  |
| 99 | `o` | 3 | 2.5s |  |
| 100 | `object_constructor` | 33 | 2.6s |  |
| 101 | `object_function` | 32 | 2.6s |  |
| 102 | `object_string_coerce_swf5` | 62 | 2.7s |  |
| 103 | `primitive_instanceof` | 37 | 2.6s |  |
| 104 | `prototype_delete` | 12 | 2.6s |  |
| 105 | `recursive_prototypes` | 0 | 2.5s |  |
| 106 | `sandbox_type_local_network` | 1 | 2.5s |  |
| 107 | `single_frame` | 1 | 2.5s |  |
| 108 | `sound_start_load` | 0 | 2.6s |  |
| 109 | `stage_object_properties_get_var` | 5 | 2.5s |  |
| 110 | `strictequals_swf6` | 902 | 8.6s |  |
| 111 | `strictly_equals` | 7 | 2.6s |  |
| 112 | `string_coercion` | 117 | 3.2s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 113 | `string_paths_keyevents` | 0 | 2.5s |  |
| 114 | `string_paths_timer` | 0 | 2.6s |  |
| 115 | `swf4_actions_bool` | 96 | 2.7s |  |
| 116 | `swf4_bool` | 4 | 2.6s |  |
| 117 | `swf4_function_calls` | 7 | 2.6s |  |
| 118 | `swf5_encoding` | 3 | 2.8s |  |
| 119 | `swf7_case_sensitive` | 44 | 2.8s |  |
| 120 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.6s |  |
| 121 | `this_swf7` | 41 | 2.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 122 | `timeline_function_def` | 7 | 2.8s |  |
| 123 | `try_finally_simple` | 16 | 2.6s |  |
| 124 | `typeof_globals` | 7 | 2.5s |  |
| 125 | `undefined_to_string_swf6` | 4 | 2.5s |  |
| 126 | `unescape` | 43 | 2.7s |  |
| 127 | `waitforframe` | 7 | 2.6s |  |
| 128 | `waitforframe2` | 16 | 2.6s |  |
| 129 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**95 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `define_function2_preload` | 92.3% | 12 | 13 | 1 |  |
| 2 | `set_variable_scope` | 87.9% | 51 | 58 | 7 |  |
| 3 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 4 | `movieclip_name_from_timeline` | 84.6% | 11 | 13 | 2 |  |
| 5 | `array_length` | 83.3% | 35 | 42 | 7 |  |
| 6 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 7 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 8 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 9 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 10 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 11 | `goto_both_ways1` | 75.0% | 3 | 4 | 1 |  |
| 12 | `goto_both_ways2` | 75.0% | 3 | 4 | 1 |  |
| 13 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 14 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 16 | `textfield_background_color` | 72.7% | 8 | 11 | 3 |  |
| 17 | `textfield_border_color` | 72.7% | 8 | 11 | 3 |  |
| 18 | `textfield_properties` | 72.7% | 32 | 44 | 12 |  |
| 19 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 20 | `point` | 70.9% | 124 | 175 | 51 |  |
| 21 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 22 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 23 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 24 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 25 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 26 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 27 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 28 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 29 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 30 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 32 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 33 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 34 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 36 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 37 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 38 | `goto_rewind3` | 66.7% | 2 | 3 | 1 |  |
| 39 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 40 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 41 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 42 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 43 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 44 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 45 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 47 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 49 | `with` | 61.2% | 30 | 49 | 19 |  |
| 50 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 51 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 52 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 53 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 54 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 55 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 56 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 57 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 58 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 59 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 60 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 61 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 62 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 63 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 64 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 65 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 66 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 67 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 68 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 69 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 70 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 71 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 72 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 73 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 74 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 75 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 76 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 77 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 78 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 79 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 80 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 81 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 82 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 83 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 84 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 85 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 86 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 87 | `goto_rewind1` | 50.0% | 1 | 2 | 1 |  |
| 88 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 89 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 90 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 91 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 92 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 93 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 94 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 95 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.6s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 3 | `path_string` | 5.1s |  |
| 4 | `swf4_actions_coercion_order` | 4.9s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.5s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.6s |  |

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.6s |  |
| 2 | `placeobject_occupied_depth` | runtime timeout (>10s) | 12.6s |  |
| 3 | `timeout` | runtime timeout (>10s) | 14.2s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 13.0s |  |

## All Output Mismatches

**477 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `define_function2_preload` | 92.3% | 12/13 | 13 | 13 |  |
| 2 | `set_variable_scope` | 87.9% | 51/58 | 58 | 58 |  |
| 3 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 4 | `movieclip_name_from_timeline` | 84.6% | 11/13 | 13 | 13 |  |
| 5 | `array_length` | 83.3% | 35/42 | 42 | 42 |  |
| 6 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 7 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 8 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 9 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 10 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 11 | `goto_both_ways1` | 75.0% | 3/4 | 4 | 3 |  |
| 12 | `goto_both_ways2` | 75.0% | 3/4 | 4 | 3 |  |
| 13 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 14 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 15 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 16 | `textfield_background_color` | 72.7% | 8/11 | 11 | 11 |  |
| 17 | `textfield_border_color` | 72.7% | 8/11 | 11 | 11 |  |
| 18 | `textfield_properties` | 72.7% | 32/44 | 44 | 44 |  |
| 19 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 20 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 21 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 22 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 23 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 24 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 25 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 26 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 27 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 28 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 29 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 30 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 31 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 32 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 33 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 34 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 37 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 38 | `goto_rewind3` | 66.7% | 2/3 | 3 | 2 |  |
| 39 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 40 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 41 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 42 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 43 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 44 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 45 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 47 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 49 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 50 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 51 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 52 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 53 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 54 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 55 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 56 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 57 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 58 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 59 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 60 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 61 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 62 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 63 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 64 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 65 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 66 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 67 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 68 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 69 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 70 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 71 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 72 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 73 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 74 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 75 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 76 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 77 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 78 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 79 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 80 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 81 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 82 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 83 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 84 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 85 | `define_function2_preload_order` | 50.0% | 2/4 | 2 | 4 |  |
| 86 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `goto_rewind1` | 50.0% | 1/2 | 2 | 1 |  |
| 88 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 90 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 91 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 92 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 93 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 94 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 95 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 96 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 97 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 98 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 99 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 100 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 101 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 102 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 103 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 104 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 105 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 106 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 107 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 108 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 109 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 110 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 111 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 112 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 113 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 114 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 115 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 116 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 117 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 118 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 119 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 120 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
| 121 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 122 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 123 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 124 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 125 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 126 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 127 | `remove_movie_clip` | 31.0% | 9/29 | 17 | 29 |  |
| 128 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 129 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 130 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 131 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 132 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 133 | `execution_order2` | 28.6% | 2/7 | 5 | 7 |  |
| 134 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 135 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 136 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 137 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 138 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 139 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 140 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 141 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 142 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 143 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 144 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 145 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 146 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 147 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 148 | `stage_object_properties_swf6` | 23.4% | 54/231 | 165 | 231 |  |
| 149 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 150 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 151 | `stage_object_properties` | 22.4% | 54/241 | 175 | 241 |  |
| 152 | `funky_function_calls` | 21.4% | 12/56 | 32 | 56 |  |
| 153 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 154 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 155 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 156 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 157 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 158 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 159 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 160 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 161 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 162 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 163 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 164 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 165 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 166 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 167 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 168 | `root_global_parent` | 16.7% | 1/6 | 4 | 6 |  |
| 169 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 170 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 171 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 172 | `register_and_init_order` | 15.2% | 35/231 | 68 | 231 |  |
| 173 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 174 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 175 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 176 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 177 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 178 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 179 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 180 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 181 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 182 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 183 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 184 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 185 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 186 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 187 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 188 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 189 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 190 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 191 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 192 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 193 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 194 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 195 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 196 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 197 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 198 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 199 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 200 | `execution_order4` | 8.3% | 1/12 | 5 | 12 |  |
| 201 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 202 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 203 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 204 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 205 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 206 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 207 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 208 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 209 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 210 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 211 | `default_names` | 5.8% | 3/52 | 32 | 52 |  |
| 212 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 213 | `clip_events` | 5.3% | 1/19 | 4 | 19 |  |
| 214 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 215 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 216 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 217 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 218 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 219 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 220 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 221 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 222 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 223 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 224 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 225 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 226 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 227 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 228 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 229 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 230 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 231 | `movieclip_hittest_shapeflag` | 3.0% | 10/338 | 191 | 338 |  |
| 232 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 233 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 234 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 235 | `netstream_seek_flv` | 2.0% | 1/50 | 50 | 25 |  |
| 236 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 237 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 238 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 239 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 240 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 241 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 242 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 243 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 21 | 112 |  |
| 244 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 245 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 246 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 247 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 248 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 249 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 250 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 251 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 252 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 253 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
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
| 285 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 286 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 287 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 288 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 289 | `color` | 0.0% | 0/57 | 0 | 57 |  |
| 290 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 291 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 292 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 293 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 294 | `display_object_properties` | 0.0% | 0/2 | 2 | 2 |  |
| 295 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 296 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 297 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `duplicate_movie_clip` | 0.0% | 0/20 | 0 | 20 |  |
| 299 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 300 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 301 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 302 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 304 | `edittext_password` | 0.0% | 0/5 | 0 | 5 |  |
| 305 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 306 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 307 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 309 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 310 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 311 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 312 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 313 | `execution_order1` | 0.0% | 0/5 | 3 | 5 |  |
| 314 | `extends_chain` | 0.0% | 0/134 | 0 | 134 |  |
| 315 | `extends_native_type` | 0.0% | 0/11 | 0 | 11 |  |
| 316 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 317 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 318 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 319 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 320 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 321 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 322 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 323 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 324 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 326 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 327 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 328 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 329 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 330 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 331 | `function_base_clip` | 0.0% | 0/8 | 0 | 8 |  |
| 332 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 333 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 334 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 335 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 336 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 337 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 338 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 339 | `goto_frame` | 0.0% | 0/12 | 0 | 12 |  |
| 340 | `goto_frame2` | 0.0% | 0/44 | 0 | 44 |  |
| 341 | `goto_label` | 0.0% | 0/17 | 0 | 17 |  |
| 342 | `goto_methods` | 0.0% | 0/40 | 0 | 40 |  |
| 343 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 344 | `hittest_morph` | 0.0% | 0/70 | 0 | 70 |  |
| 345 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 347 | `init_object_order` | 0.0% | 0/15 | 0 | 15 |  |
| 348 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 349 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 350 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 351 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 352 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 353 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 354 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 355 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `issue_9885` | 0.0% | 0/2 | 0 | 2 |  |
| 357 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 358 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 359 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 360 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 361 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 362 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 363 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 364 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 365 | `localconnection` | 0.0% | 0/579 | 0 | 579 |  |
| 366 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 367 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 368 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 369 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 370 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 371 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 372 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 373 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 374 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 375 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 376 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 377 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 378 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 379 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 380 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 381 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 382 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 383 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 384 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 385 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 386 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 387 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 388 | `movieclip_init_object` | 0.0% | 0/5 | 0 | 5 |  |
| 389 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 390 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 391 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 392 | `native_objects_swf6` | 0.0% | 0/84 | 0 | 84 |  |
| 393 | `native_objects_swf7` | 0.0% | 0/84 | 0 | 84 |  |
| 394 | `native_objects_swf8` | 0.0% | 0/84 | 0 | 84 |  |
| 395 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 396 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 397 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 398 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 399 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 400 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 401 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 402 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 403 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 404 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 405 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 406 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 407 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 408 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 409 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 410 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 411 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 412 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 413 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 414 | `selection` | 0.0% | 0/454 | 0 | 454 |  |
| 415 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 416 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 417 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 418 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 419 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 420 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 421 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 422 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 423 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 424 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 425 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 426 | `stylesheet` | 0.0% | 0/283 | 0 | 283 |  |
| 427 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 428 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 429 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 430 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 431 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 432 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 433 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 434 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 435 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 436 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 437 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 438 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 439 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 440 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 441 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 442 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 443 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 444 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 |  |
| 445 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 446 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 447 | `target_path` | 0.0% | 0/14 | 0 | 14 |  |
| 448 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 449 | `tell_target_invalid` | 0.0% | 0/6 | 4 | 6 |  |
| 450 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 4 | 5 |  |
| 451 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 452 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 453 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 454 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 455 | `timer_run_actions` | 0.0% | 0/18 | 0 | 18 |  |
| 456 | `typeof` | 0.0% | 0/22 | 0 | 22 |  |
| 457 | `unload` | 0.0% | 0/52 | 23 | 52 |  |
| 458 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 459 | `unload_nested_child` | 0.0% | 0/5 | 3 | 5 |  |
| 460 | `use_hand_cursor` | 0.0% | 0/8 | 0 | 8 |  |
| 461 | `variable_args` | 0.0% | 0/5 | 5 | 5 |  |
| 462 | `watch` | 0.0% | 0/117 | 0 | 117 |  |
| 463 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 464 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 465 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 466 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 467 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 468 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 469 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 470 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 471 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 472 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 473 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 474 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 475 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 476 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 477 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
