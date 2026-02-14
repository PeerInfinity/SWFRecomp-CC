# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-14 01:20 UTC

**Git SHA**: `03e795d08e`

**Run Duration**: 33m 44s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **145** (23.4%) |
| Failing | 474 |
| Total expected lines | 91286 |
| Matching lines | 34059 (37.3%) |
| Mismatched lines | 57227 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 464 | 97.9% |
| Runtime Segfault | 5 | 1.1% |
| Timeout | 3 | 0.6% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**145 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.6s |  |
| 2 | `action_to_integer` | 28 | 2.6s |  |
| 3 | `add` | 28 | 2.7s |  |
| 4 | `add2` | 354 | 3.0s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.6s |  |
| 6 | `add_swf5` | 28 | 2.7s |  |
| 7 | `array_concat` | 98 | 2.8s |  |
| 8 | `array_constructor` | 30 | 2.7s |  |
| 9 | `array_length` | 42 | 2.8s |  |
| 10 | `array_properties` | 36 | 2.7s |  |
| 11 | `array_slice` | 34 | 2.7s |  |
| 12 | `array_splice` | 207 | 3.4s |  |
| 13 | `array_trivial` | 209 | 3.2s |  |
| 14 | `as1_constructor_v6` | 35 | 2.7s |  |
| 15 | `as1_constructor_v7` | 35 | 2.7s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.6s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.6s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.6s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.6s |  |
| 22 | `as_transformed_flag` | 20 | 2.7s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.5s |  |
| 24 | `bitand` | 1058 | 9.4s |  |
| 25 | `bitmap_data_colortransform` | 0 | 2.9s |  |
| 26 | `bitmap_data_fillrect` | 0 | 2.8s |  |
| 27 | `bitmap_data_perlinnoise` | 0 | 3.3s |  |
| 28 | `bitmap_data_pixeldissolve_image` | 0 | 3.1s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 30 | `bitor` | 1058 | 9.6s |  |
| 31 | `biturshift` | 14 | 2.9s |  |
| 32 | `biturshift_swf8` | 14 | 2.7s |  |
| 33 | `bitxor` | 1058 | 9.4s |  |
| 34 | `call_method_empty_name` | 1 | 2.7s |  |
| 35 | `catch_references_registers` | 2 | 2.7s |  |
| 36 | `define_function2` | 8 | 2.7s |  |
| 37 | `define_function2_preload` | 13 | 2.7s |  |
| 38 | `define_function2_preload_order` | 4 | 2.7s |  |
| 39 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 40 | `delete` | 3 | 2.8s |  |
| 41 | `display_object_properties` | 2 | 2.6s |  |
| 42 | `divide_swf4` | 107 | 2.9s |  |
| 43 | `do_init_action` | 3 | 2.7s |  |
| 44 | `equals` | 32 | 2.8s |  |
| 45 | `equals2_swf5` | 926 | 11.0s |  |
| 46 | `equals2_swf6` | 926 | 10.9s |  |
| 47 | `equals2_swf7` | 926 | 11.0s |  |
| 48 | `equals_swf4` | 665 | 6.3s |  |
| 49 | `equals_swf4_alt` | 32 | 2.8s |  |
| 50 | `equals_swf5` | 32 | 2.8s |  |
| 51 | `error` | 58 | 2.9s |  |
| 52 | `escape` | 14 | 2.7s |  |
| 53 | `execution_order1` | 5 | 2.7s |  |
| 54 | `execution_order2` | 7 | 2.8s |  |
| 55 | `execution_order3` | 4 | 2.7s |  |
| 56 | `focusrect_mouse_swf8` | 0 | 2.6s |  |
| 57 | `focusrect_mouse_swf9` | 0 | 2.6s |  |
| 58 | `focusrect_swf5` | 6 | 2.8s |  |
| 59 | `get_variable_in_scope` | 29 | 2.8s |  |
| 60 | `getproperty` | 28 | 2.7s |  |
| 61 | `getproperty_swf4` | 28 | 2.7s |  |
| 62 | `getproperty_swf5` | 28 | 2.7s |  |
| 63 | `global_array` | 3 | 2.6s |  |
| 64 | `global_is_bare` | 7 | 2.7s |  |
| 65 | `goto_advance1` | 6 | 2.7s |  |
| 66 | `goto_advance2` | 2 | 2.7s |  |
| 67 | `goto_both_ways1` | 3 | 3.0s |  |
| 68 | `goto_both_ways2` | 3 | 2.7s |  |
| 69 | `goto_execution_order` | 2 | 2.6s |  |
| 70 | `goto_execution_order2` | 2 | 2.7s |  |
| 71 | `goto_frame_number` | 3 | 2.8s |  |
| 72 | `goto_rewind1` | 1 | 2.8s |  |
| 73 | `goto_rewind2` | 3 | 2.8s |  |
| 74 | `goto_rewind3` | 2 | 2.7s |  |
| 75 | `greater_swf6` | 1175 | 11.7s |  |
| 76 | `greater_swf7` | 1175 | 11.8s |  |
| 77 | `greaterthan_swf5` | 1 | 2.7s |  |
| 78 | `greaterthan_swf8` | 1 | 2.7s |  |
| 79 | `has_own_property` | 32 | 2.8s |  |
| 80 | `infinite_recursion_function` | 4 | 2.7s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 81 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 82 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 83 | `init_array_invalid` | 4 | 2.7s |  |
| 84 | `init_object_invalid` | 4 | 2.7s |  |
| 85 | `issue_1086` | 1 | 2.7s |  |
| 86 | `issue_1671` | 0 | 2.7s |  |
| 87 | `issue_3446` | 1 | 2.7s |  |
| 88 | `issue_4377` | 2 | 2.7s |  |
| 89 | `issue_710` | 4 | 2.8s |  |
| 90 | `issue_768` | 3 | 2.8s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 91 | `lessthan` | 41 | 2.8s |  |
| 92 | `lessthan2_swf5` | 1226 | 12.6s |  |
| 93 | `lessthan2_swf6` | 1226 | 12.5s |  |
| 94 | `lessthan2_swf7` | 1226 | 12.6s |  |
| 95 | `lessthan_swf4` | 902 | 8.3s |  |
| 96 | `lessthan_swf4_alt` | 41 | 2.9s |  |
| 97 | `lessthan_swf5` | 41 | 2.8s |  |
| 98 | `logical_ops_swf4` | 90 | 2.8s |  |
| 99 | `logical_ops_swf8` | 108 | 2.8s |  |
| 100 | `looping` | 6 | 2.7s |  |
| 101 | `mask_reapply` | 0 | 2.7s |  |
| 102 | `mask_with_drawing` | 0 | 2.7s |  |
| 103 | `movieclip_begin_gradient_fill` | 0 | 3.3s |  |
| 104 | `movieclip_line_gradient_style` | 0 | 3.3s |  |
| 105 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 106 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 107 | `nested_textfields_in_buttons` | 0 | 2.7s |  |
| 108 | `netstream_play_flv_screen` | 0 | 30.1s |  |
| 109 | `new_method_wrap` | 4 | 2.7s |  |
| 110 | `new_object_enumerate` | 7 | 2.7s |  |
| 111 | `new_object_wrap` | 4 | 2.7s |  |
| 112 | `o` | 3 | 2.7s |  |
| 113 | `object_constructor` | 33 | 2.8s |  |
| 114 | `object_function` | 32 | 2.8s |  |
| 115 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 116 | `primitive_instanceof` | 37 | 2.8s |  |
| 117 | `prototype_delete` | 12 | 2.7s |  |
| 118 | `recursive_prototypes` | 0 | 2.7s |  |
| 119 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 120 | `set_variable_scope` | 58 | 2.8s |  |
| 121 | `single_frame` | 1 | 2.6s |  |
| 122 | `sound_start_load` | 0 | 2.7s |  |
| 123 | `stage_object_properties_get_var` | 5 | 2.6s |  |
| 124 | `strictequals_swf6` | 902 | 8.8s |  |
| 125 | `strictly_equals` | 7 | 2.7s |  |
| 126 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 127 | `string_paths_keyevents` | 0 | 2.7s |  |
| 128 | `string_paths_timer` | 0 | 2.7s |  |
| 129 | `swf4_actions_bool` | 96 | 2.8s |  |
| 130 | `swf4_bool` | 4 | 2.7s |  |
| 131 | `swf4_function_calls` | 7 | 2.8s |  |
| 132 | `swf5_encoding` | 3 | 2.6s |  |
| 133 | `swf7_case_sensitive` | 44 | 2.7s |  |
| 134 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.6s |  |
| 135 | `this_swf7` | 41 | 2.6s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 136 | `timeline_function_def` | 7 | 2.7s |  |
| 137 | `try_finally_simple` | 16 | 2.7s |  |
| 138 | `typeof` | 22 | 2.7s |  |
| 139 | `typeof_globals` | 7 | 2.6s |  |
| 140 | `undefined_to_string_swf6` | 4 | 2.6s |  |
| 141 | `unescape` | 43 | 2.8s |  |
| 142 | `variable_args` | 5 | 2.8s |  |
| 143 | `waitforframe` | 7 | 2.7s |  |
| 144 | `waitforframe2` | 16 | 2.7s |  |
| 145 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**91 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21 | 23 | 2 |  |
| 2 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 3 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 4 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 5 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 6 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 7 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 8 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 9 | `use_hand_cursor` | 75.0% | 6 | 8 | 2 |  |
| 10 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 11 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 13 | `textfield_background_color` | 72.7% | 8 | 11 | 3 |  |
| 14 | `textfield_border_color` | 72.7% | 8 | 11 | 3 |  |
| 15 | `textfield_properties` | 72.7% | 32 | 44 | 12 |  |
| 16 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 17 | `point` | 70.9% | 124 | 175 | 51 |  |
| 18 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 19 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 20 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 21 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 22 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 23 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 24 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 25 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 26 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 27 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 28 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 30 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 31 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 32 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 33 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 34 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 35 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 36 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 37 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 38 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 39 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 40 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 42 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 43 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 44 | `with` | 61.2% | 30 | 49 | 19 |  |
| 45 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 46 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 47 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 48 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 49 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 50 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 52 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 53 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 54 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 55 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 56 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 57 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 58 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 60 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 61 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 62 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 63 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 64 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 65 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 66 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 67 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 68 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 69 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 70 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 71 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 72 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 73 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 74 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 75 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 76 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 77 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 78 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 79 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 80 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 81 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 82 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 84 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 85 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 86 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 87 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 88 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 89 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 90 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 91 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.8s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 3 | `goto_methods` | 5.3s |  |
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
| 1 | `parse_float` | runtime timeout (>10s) | 13.8s |  |
| 2 | `timeout` | runtime timeout (>10s) | 14.2s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.2s |  |

## All Output Mismatches

**464 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `conflicting_instance_names` | 91.3% | 21/23 | 23 | 23 |  |
| 2 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 3 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 4 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 5 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 6 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 7 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 8 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 9 | `use_hand_cursor` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `textfield_background_color` | 72.7% | 8/11 | 11 | 11 |  |
| 14 | `textfield_border_color` | 72.7% | 8/11 | 11 | 11 |  |
| 15 | `textfield_properties` | 72.7% | 32/44 | 44 | 44 |  |
| 16 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 17 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 18 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 19 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 20 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 21 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 22 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 23 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 24 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 25 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 26 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 27 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 28 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 29 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 30 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 31 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 32 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 33 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 34 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 35 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 36 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 37 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 38 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 39 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 40 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 41 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 42 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 43 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 44 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 45 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 46 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 47 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 48 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 49 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 50 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 51 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 52 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 53 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 54 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 55 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 56 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 57 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 58 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 60 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 61 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 62 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 63 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 64 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 65 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 66 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 67 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 68 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 69 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 70 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 71 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 72 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 73 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 74 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 75 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 76 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 77 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 78 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 79 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 80 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 81 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 82 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 84 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 85 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 86 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 87 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 88 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 89 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 90 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 91 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 92 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 93 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 94 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 95 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 96 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 97 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 98 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 99 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 100 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 101 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 102 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 103 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 104 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 105 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 106 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 107 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 108 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 109 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 110 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 111 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 112 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 113 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 114 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 115 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 116 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 117 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 118 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 119 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 120 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 121 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 122 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 123 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 124 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 125 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 126 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 127 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 128 | `edittext_html_condensewhite_swf7` | 29.9% | 93/311 | 311 | 311 |  |
| 129 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 130 | `edittext_html_condensewhite_swf8` | 28.9% | 90/311 | 311 | 311 |  |
| 131 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 132 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 133 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 134 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 135 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 136 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 137 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 138 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 139 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 140 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 141 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 142 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 143 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 144 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 145 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 146 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 147 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 148 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 149 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 150 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 151 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 152 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 153 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 154 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 155 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 156 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 157 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 158 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 159 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 160 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 161 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 162 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 163 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 164 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 165 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 166 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 167 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 168 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 169 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 170 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 171 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 172 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 173 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 174 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 175 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 176 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 177 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 178 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 179 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 180 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 181 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 182 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 183 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 184 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 185 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 186 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 187 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 188 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 189 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 190 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 191 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 192 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 193 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 194 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 195 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 196 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 197 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 198 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 199 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 200 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 201 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 202 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 203 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 204 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 205 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 206 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 207 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 208 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 209 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 210 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 211 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 212 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 213 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 214 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 215 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 216 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 217 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 218 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 219 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 220 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 221 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 222 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 223 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 224 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 225 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 226 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 227 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 228 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 229 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 230 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 231 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 232 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 233 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 234 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 235 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 236 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 237 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 238 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 239 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 240 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 241 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 242 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 243 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 244 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 245 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 246 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 247 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 248 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 249 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 250 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 251 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 252 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 253 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 254 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 255 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 256 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 257 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 258 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 259 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 260 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 261 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 262 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 263 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 264 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 265 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 266 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 267 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 268 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 269 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 270 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 272 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 273 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 274 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 275 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 276 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 277 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 278 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 279 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 280 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 281 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 283 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 284 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 285 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 286 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 287 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 288 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 289 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 290 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 291 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 292 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 293 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 294 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 295 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 296 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 297 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 298 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 299 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 301 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 302 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 303 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 304 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 305 | `edittext_password` | 0.0% | 0/5 | 5 | 5 |  |
| 306 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 307 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 310 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 311 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 312 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 313 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 314 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 315 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 316 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 317 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 318 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 319 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 320 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 321 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 322 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 323 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 324 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 325 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 326 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 327 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 328 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 329 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 330 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 331 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 332 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 333 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 334 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 335 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 336 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 337 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 338 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 339 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 340 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 341 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 342 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 343 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 344 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 345 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 346 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 347 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 349 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 350 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 351 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 352 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 353 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 354 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 355 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 356 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 357 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 358 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 359 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 360 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 361 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 362 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 363 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 364 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 365 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 366 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 367 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 368 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 369 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 370 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 371 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 372 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 373 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 374 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 375 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 376 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 377 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 378 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 379 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 380 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 381 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 382 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 383 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 384 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 385 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 386 | `native_objects_swf6` | 0.0% | 0/181 | 181 | 84 |  |
| 387 | `native_objects_swf7` | 0.0% | 0/181 | 181 | 84 |  |
| 388 | `native_objects_swf8` | 0.0% | 0/181 | 181 | 84 |  |
| 389 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 390 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 391 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 392 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 393 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 394 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 395 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 396 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 397 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 398 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 399 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 400 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 401 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 402 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 403 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 404 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 405 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 406 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 407 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 408 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 409 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 410 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 411 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 412 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 413 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 414 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 415 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 416 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 417 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 418 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 419 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 420 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 421 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 422 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 423 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 424 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 425 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 426 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 427 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 428 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 429 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 430 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 431 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 432 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 433 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 434 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 435 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 436 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 437 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 438 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 439 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 440 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 441 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 442 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 443 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 444 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 445 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 446 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 447 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 448 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 449 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 450 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 451 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 452 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 453 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 454 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 455 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 456 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 457 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 458 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 459 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 460 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 461 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 462 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 463 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 464 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
