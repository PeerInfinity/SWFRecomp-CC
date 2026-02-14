# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-14 00:37 UTC

**Git SHA**: `2a88307e79`

**Run Duration**: 34m 17s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **144** (23.3%) |
| Failing | 475 |
| Total expected lines | 91286 |
| Matching lines | 34048 (37.3%) |
| Mismatched lines | 57238 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 465 | 97.9% |
| Runtime Segfault | 5 | 1.1% |
| Timeout | 3 | 0.6% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**144 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.0s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.8s |  |
| 4 | `add2` | 354 | 3.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.8s |  |
| 6 | `add_swf5` | 28 | 2.8s |  |
| 7 | `array_concat` | 98 | 2.9s |  |
| 8 | `array_constructor` | 30 | 2.8s |  |
| 9 | `array_length` | 42 | 2.9s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.9s |  |
| 12 | `array_splice` | 207 | 3.6s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.9s |  |
| 15 | `as1_constructor_v7` | 35 | 2.9s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.8s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.8s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.8s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.8s |  |
| 22 | `as_transformed_flag` | 20 | 2.8s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 24 | `bitand` | 1058 | 9.5s |  |
| 25 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 26 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 27 | `bitmap_data_perlinnoise` | 0 | 3.5s |  |
| 28 | `bitmap_data_pixeldissolve_image` | 0 | 3.2s |  |
| 29 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 30 | `bitor` | 1058 | 9.4s |  |
| 31 | `biturshift` | 14 | 2.8s |  |
| 32 | `biturshift_swf8` | 14 | 2.7s |  |
| 33 | `bitxor` | 1058 | 9.4s |  |
| 34 | `call_method_empty_name` | 1 | 2.7s |  |
| 35 | `catch_references_registers` | 2 | 2.7s |  |
| 36 | `define_function2` | 8 | 2.7s |  |
| 37 | `define_function2_preload` | 13 | 2.7s |  |
| 38 | `define_function2_preload_order` | 4 | 2.7s |  |
| 39 | `define_function_case_sensitive` | 2 | 2.8s |  |
| 40 | `delete` | 3 | 2.8s |  |
| 41 | `divide_swf4` | 107 | 2.9s |  |
| 42 | `do_init_action` | 3 | 2.7s |  |
| 43 | `equals` | 32 | 2.9s |  |
| 44 | `equals2_swf5` | 926 | 11.1s |  |
| 45 | `equals2_swf6` | 926 | 11.2s |  |
| 46 | `equals2_swf7` | 926 | 11.1s |  |
| 47 | `equals_swf4` | 665 | 6.4s |  |
| 48 | `equals_swf4_alt` | 32 | 2.8s |  |
| 49 | `equals_swf5` | 32 | 2.8s |  |
| 50 | `error` | 58 | 2.9s |  |
| 51 | `escape` | 14 | 2.7s |  |
| 52 | `execution_order1` | 5 | 2.8s |  |
| 53 | `execution_order2` | 7 | 2.8s |  |
| 54 | `execution_order3` | 4 | 2.8s |  |
| 55 | `focusrect_mouse_swf8` | 0 | 2.7s |  |
| 56 | `focusrect_mouse_swf9` | 0 | 2.7s |  |
| 57 | `focusrect_swf5` | 6 | 2.9s |  |
| 58 | `get_variable_in_scope` | 29 | 3.0s |  |
| 59 | `getproperty` | 28 | 2.9s |  |
| 60 | `getproperty_swf4` | 28 | 2.8s |  |
| 61 | `getproperty_swf5` | 28 | 2.8s |  |
| 62 | `global_array` | 3 | 2.7s |  |
| 63 | `global_is_bare` | 7 | 2.7s |  |
| 64 | `goto_advance2` | 2 | 2.8s |  |
| 65 | `goto_both_ways1` | 3 | 2.9s |  |
| 66 | `goto_both_ways2` | 3 | 2.8s |  |
| 67 | `goto_execution_order` | 2 | 2.8s |  |
| 68 | `goto_execution_order2` | 2 | 2.8s |  |
| 69 | `goto_frame_number` | 3 | 2.8s |  |
| 70 | `goto_rewind1` | 1 | 3.0s |  |
| 71 | `goto_rewind2` | 3 | 2.8s |  |
| 72 | `goto_rewind3` | 2 | 2.8s |  |
| 73 | `greater_swf6` | 1175 | 11.8s |  |
| 74 | `greater_swf7` | 1175 | 11.6s |  |
| 75 | `greaterthan_swf5` | 1 | 2.7s |  |
| 76 | `greaterthan_swf8` | 1 | 2.8s |  |
| 77 | `has_own_property` | 32 | 2.8s |  |
| 78 | `infinite_recursion_function` | 4 | 2.7s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 79 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 80 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 81 | `init_array_invalid` | 4 | 2.7s |  |
| 82 | `init_object_invalid` | 4 | 2.7s |  |
| 83 | `issue_1086` | 1 | 2.9s |  |
| 84 | `issue_1671` | 0 | 2.8s |  |
| 85 | `issue_1906` | 4 | 2.8s |  |
| 86 | `issue_3446` | 1 | 2.8s |  |
| 87 | `issue_4377` | 2 | 2.8s |  |
| 88 | `issue_710` | 4 | 2.8s |  |
| 89 | `issue_768` | 3 | 2.9s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 90 | `lessthan` | 41 | 2.8s |  |
| 91 | `lessthan2_swf5` | 1226 | 12.6s |  |
| 92 | `lessthan2_swf6` | 1226 | 12.2s |  |
| 93 | `lessthan2_swf7` | 1226 | 11.8s |  |
| 94 | `lessthan_swf4` | 902 | 7.9s |  |
| 95 | `lessthan_swf4_alt` | 41 | 2.9s |  |
| 96 | `lessthan_swf5` | 41 | 2.9s |  |
| 97 | `logical_ops_swf4` | 90 | 2.8s |  |
| 98 | `logical_ops_swf8` | 108 | 3.0s |  |
| 99 | `looping` | 6 | 2.7s |  |
| 100 | `mask_reapply` | 0 | 2.7s |  |
| 101 | `mask_with_drawing` | 0 | 2.7s |  |
| 102 | `movieclip_begin_gradient_fill` | 0 | 3.4s |  |
| 103 | `movieclip_line_gradient_style` | 0 | 3.3s |  |
| 104 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 105 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 106 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 107 | `netstream_play_flv_screen` | 0 | 30.2s |  |
| 108 | `new_method_wrap` | 4 | 2.6s |  |
| 109 | `new_object_enumerate` | 7 | 2.7s |  |
| 110 | `new_object_wrap` | 4 | 2.7s |  |
| 111 | `o` | 3 | 2.6s |  |
| 112 | `object_constructor` | 33 | 2.8s |  |
| 113 | `object_function` | 32 | 2.8s |  |
| 114 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 115 | `primitive_instanceof` | 37 | 2.9s |  |
| 116 | `prototype_delete` | 12 | 2.8s |  |
| 117 | `recursive_prototypes` | 0 | 2.6s |  |
| 118 | `sandbox_type_local_network` | 1 | 2.6s |  |
| 119 | `set_variable_scope` | 58 | 2.8s |  |
| 120 | `single_frame` | 1 | 2.6s |  |
| 121 | `sound_start_load` | 0 | 2.7s |  |
| 122 | `stage_object_properties_get_var` | 5 | 2.7s |  |
| 123 | `strictequals_swf6` | 902 | 9.0s |  |
| 124 | `strictly_equals` | 7 | 2.7s |  |
| 125 | `string_coercion` | 117 | 3.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 126 | `string_paths_keyevents` | 0 | 2.7s |  |
| 127 | `string_paths_timer` | 0 | 2.7s |  |
| 128 | `swf4_actions_bool` | 96 | 2.8s |  |
| 129 | `swf4_bool` | 4 | 2.7s |  |
| 130 | `swf4_function_calls` | 7 | 2.9s |  |
| 131 | `swf5_encoding` | 3 | 2.7s |  |
| 132 | `swf7_case_sensitive` | 44 | 2.9s |  |
| 133 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.7s |  |
| 134 | `this_swf7` | 41 | 2.8s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 135 | `timeline_function_def` | 7 | 2.9s |  |
| 136 | `try_finally_simple` | 16 | 2.7s |  |
| 137 | `typeof` | 22 | 2.7s |  |
| 138 | `typeof_globals` | 7 | 2.7s |  |
| 139 | `undefined_to_string_swf6` | 4 | 2.7s |  |
| 140 | `unescape` | 43 | 2.9s |  |
| 141 | `variable_args` | 5 | 2.8s |  |
| 142 | `waitforframe` | 7 | 2.7s |  |
| 143 | `waitforframe2` | 16 | 2.8s |  |
| 144 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**92 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 2 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 3 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 4 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 5 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 6 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
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
| 34 | `goto_advance1` | 66.7% | 4 | 6 | 2 |  |
| 35 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 36 | `textfield_variable` | 66.7% | 54 | 81 | 27 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 38 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 39 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 40 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 41 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 43 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 44 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 45 | `with` | 61.2% | 30 | 49 | 19 |  |
| 46 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 47 | `edittext_scroll` | 61.1% | 33 | 54 | 21 |  |
| 48 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 49 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 50 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 51 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 52 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 53 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 54 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 55 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 56 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 57 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 58 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 59 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 60 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 61 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 62 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 63 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 64 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 65 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 66 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 67 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 68 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 69 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 70 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 71 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 73 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 74 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 75 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 76 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 77 | `edittext_default_format_font_style` | 52.4% | 176 | 336 | 160 |  |
| 78 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 79 | `edittext_default_format` | 51.4% | 114 | 222 | 108 |  |
| 80 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 81 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 82 | `display_object_properties` | 50.0% | 1 | 2 | 1 |  |
| 83 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 84 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 85 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 86 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 87 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 88 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 89 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 90 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 92 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 12.8s |  |
| 2 | `duplicate_movie_clip_drawing` | 4.8s |  |
| 3 | `goto_methods` | 4.6s |  |
| 4 | `path_string` | 5.2s |  |
| 5 | `swf4_actions_coercion_order` | 5.0s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.7s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.7s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.8s |  |
| 2 | `timeout` | runtime timeout (>10s) | 12.8s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.5s |  |

## All Output Mismatches

**465 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 2 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 3 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 4 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 5 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 6 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
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
| 34 | `goto_advance1` | 66.7% | 4/6 | 6 | 6 |  |
| 35 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 36 | `textfield_variable` | 66.7% | 54/81 | 81 | 81 |  |
| 37 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 38 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 39 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 40 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 41 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 42 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 43 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 44 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 45 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 46 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 47 | `edittext_scroll` | 61.1% | 33/54 | 54 | 54 |  |
| 48 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 49 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 50 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 51 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 52 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 53 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 54 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 55 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 56 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 57 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 58 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 59 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 60 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 61 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 62 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 63 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 64 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 65 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 66 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 67 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 68 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 69 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 70 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 71 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 73 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 74 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 75 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 76 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 77 | `edittext_default_format_font_style` | 52.4% | 176/336 | 336 | 335 |  |
| 78 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 79 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 |  |
| 80 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 81 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 82 | `display_object_properties` | 50.0% | 1/2 | 2 | 2 |  |
| 83 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 84 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 85 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 86 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 87 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 89 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 90 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 92 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 93 | `edittext_newline_stripping` | 49.2% | 32/65 | 65 | 64 |  |
| 94 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 95 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 96 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 97 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 98 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 99 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 100 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 101 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 102 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 103 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 104 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 105 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 106 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 107 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 108 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 109 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 110 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 111 | `edittext_html_swf6` | 37.5% | 2014/5377 | 5377 | 5377 |  |
| 112 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 113 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 114 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 115 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 116 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 117 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 118 | `frame_size_translated_negative` | 33.3% | 7/21 | 20 | 21 |  |
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
| 131 | `frame_size_translated_positive` | 28.6% | 6/21 | 20 | 21 |  |
| 132 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 133 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 134 | `edittext_html_swf7` | 25.6% | 1378/5377 | 5377 | 5377 |  |
| 135 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 136 | `edittext_html_swf8` | 25.3% | 1363/5377 | 5377 | 5377 |  |
| 137 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 138 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 139 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 140 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 141 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 142 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 143 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 144 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 145 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 146 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 147 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 |  |
| 148 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 |  |
| 149 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 150 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 151 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 152 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 153 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 154 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 155 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 156 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 157 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 158 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 159 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 160 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 161 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 162 | `focusrect_property_swf5` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 163 | `focusrect_property_swf6` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 164 | `focusrect_property_swf7` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 165 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 166 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 167 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 168 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 169 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 170 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 |  |
| 171 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 172 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 173 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 174 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 175 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 176 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 177 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 178 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 179 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 180 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 181 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 182 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 183 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 184 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 185 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 186 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 187 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
| 188 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 189 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 190 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 191 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 192 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 193 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 194 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 195 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 196 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 197 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 198 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 199 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 200 | `edittext_autosize_setter` | 10.0% | 2/20 | 20 | 20 |  |
| 201 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 202 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 203 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 204 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 205 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 206 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 207 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 208 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 209 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 210 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 211 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 212 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 213 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 214 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 215 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 216 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 217 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 218 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 219 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 220 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 221 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 222 | `edittext_default_format_empty` | 5.3% | 5/95 | 95 | 95 |  |
| 223 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 224 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 225 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 226 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 227 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 228 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 229 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 230 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 231 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 232 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 233 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 234 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 235 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 236 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 237 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 238 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 239 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 240 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 241 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 242 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 243 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 244 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 245 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 246 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 247 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 248 | `tab_ordering_properties` | 1.7% | 5/293 | 180 | 293 |  |
| 249 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 250 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 251 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 252 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 253 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 254 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 255 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 256 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 257 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 258 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 259 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 260 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 261 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 262 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 263 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 264 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 265 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 266 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 267 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 268 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 269 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 270 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 271 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 273 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 274 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 275 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
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
| 287 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 288 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 289 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 290 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 291 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 292 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 293 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 294 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 295 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 296 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 297 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 298 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 299 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 302 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 303 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 304 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 305 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 306 | `edittext_password` | 0.0% | 0/5 | 5 | 5 |  |
| 307 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 308 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 311 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 312 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 313 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 314 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 315 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
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
| 331 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 332 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 333 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 334 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 335 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 336 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 337 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 338 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 339 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 340 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 341 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 342 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 343 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 344 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 345 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 346 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 347 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 350 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 351 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 352 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 353 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 354 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 355 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 356 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 357 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 358 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 360 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 361 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 362 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 363 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 364 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 365 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 366 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 367 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 368 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 369 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 370 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 371 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 372 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 373 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 374 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 375 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 376 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 377 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 378 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 379 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 380 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 381 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 382 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 383 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 384 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 385 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 386 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 387 | `native_objects_swf6` | 0.0% | 0/181 | 181 | 84 |  |
| 388 | `native_objects_swf7` | 0.0% | 0/181 | 181 | 84 |  |
| 389 | `native_objects_swf8` | 0.0% | 0/181 | 181 | 84 |  |
| 390 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 391 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 392 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 393 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 394 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 395 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 396 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 397 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 398 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 399 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 400 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 401 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 402 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 403 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 404 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 405 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 406 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 407 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 408 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 409 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 410 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 411 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 412 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 413 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 414 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 415 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 416 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 417 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 418 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 419 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 420 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 421 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 422 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 423 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 424 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 425 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 426 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 427 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 428 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 429 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 430 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 431 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 432 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 433 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 434 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 435 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 436 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 437 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 438 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 439 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 440 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 441 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 442 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 443 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 444 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 445 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 446 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 447 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 448 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 449 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 450 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 451 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 452 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 453 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 454 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 455 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 456 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 457 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 458 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 459 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 460 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 461 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 462 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 463 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 464 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 465 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
