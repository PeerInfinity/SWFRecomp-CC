# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-13 23:54 UTC

**Git SHA**: `74ae275df6`

**Run Duration**: 36m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **141** (22.8%) |
| Failing | 478 |
| Total expected lines | 88506 |
| Matching lines | 27645 (31.2%) |
| Mismatched lines | 60861 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 401 | 83.9% |
| Runtime Segfault | 72 | 15.1% |
| Timeout | 3 | 0.6% |
| Runtime Error | 2 | 0.4% |

## Passing Tests

**141 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 2.9s |  |
| 2 | `action_to_integer` | 28 | 2.7s |  |
| 3 | `add` | 28 | 2.9s |  |
| 4 | `add2` | 354 | 3.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 2.8s |  |
| 6 | `add_swf5` | 28 | 2.8s |  |
| 7 | `array_concat` | 98 | 2.9s |  |
| 8 | `array_constructor` | 30 | 2.8s |  |
| 9 | `array_length` | 42 | 2.9s |  |
| 10 | `array_properties` | 36 | 2.8s |  |
| 11 | `array_slice` | 34 | 2.9s |  |
| 12 | `array_splice` | 207 | 3.5s |  |
| 13 | `array_trivial` | 209 | 3.3s |  |
| 14 | `as1_constructor_v6` | 35 | 2.8s |  |
| 15 | `as1_constructor_v7` | 35 | 2.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 2.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 2.8s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 2.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 2.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 2.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 2.7s |  |
| 22 | `bad_swf_tag_past_eof` | 0 | 2.6s |  |
| 23 | `bitand` | 1058 | 9.6s |  |
| 24 | `bitmap_data_colortransform` | 0 | 3.0s |  |
| 25 | `bitmap_data_fillrect` | 0 | 2.9s |  |
| 26 | `bitmap_data_perlinnoise` | 0 | 3.4s |  |
| 27 | `bitmap_data_pixeldissolve_image` | 0 | 3.2s |  |
| 28 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.7s |  |
| 29 | `bitor` | 1058 | 9.6s |  |
| 30 | `biturshift` | 14 | 3.0s |  |
| 31 | `biturshift_swf8` | 14 | 2.8s |  |
| 32 | `bitxor` | 1058 | 9.3s |  |
| 33 | `call_method_empty_name` | 1 | 2.7s |  |
| 34 | `catch_references_registers` | 2 | 2.7s |  |
| 35 | `define_function2` | 8 | 2.7s |  |
| 36 | `define_function2_preload` | 13 | 2.7s |  |
| 37 | `define_function2_preload_order` | 4 | 2.7s |  |
| 38 | `define_function_case_sensitive` | 2 | 2.7s |  |
| 39 | `delete` | 3 | 2.8s |  |
| 40 | `display_object_properties` | 2 | 2.7s |  |
| 41 | `divide_swf4` | 107 | 2.9s |  |
| 42 | `do_init_action` | 3 | 2.8s |  |
| 43 | `equals` | 32 | 2.8s |  |
| 44 | `equals2_swf5` | 926 | 11.0s |  |
| 45 | `equals2_swf6` | 926 | 11.1s |  |
| 46 | `equals2_swf7` | 926 | 11.0s |  |
| 47 | `equals_swf4` | 665 | 6.3s |  |
| 48 | `equals_swf4_alt` | 32 | 2.8s |  |
| 49 | `equals_swf5` | 32 | 2.8s |  |
| 50 | `error` | 58 | 2.9s |  |
| 51 | `escape` | 14 | 2.7s |  |
| 52 | `execution_order1` | 5 | 2.7s |  |
| 53 | `execution_order3` | 4 | 2.7s |  |
| 54 | `focusrect_mouse_swf8` | 0 | 2.6s |  |
| 55 | `focusrect_mouse_swf9` | 0 | 2.7s |  |
| 56 | `focusrect_swf5` | 6 | 2.9s |  |
| 57 | `get_variable_in_scope` | 29 | 2.8s |  |
| 58 | `getproperty` | 28 | 2.7s |  |
| 59 | `getproperty_swf4` | 28 | 2.7s |  |
| 60 | `getproperty_swf5` | 28 | 2.7s |  |
| 61 | `global_array` | 3 | 2.7s |  |
| 62 | `global_is_bare` | 7 | 2.7s |  |
| 63 | `goto_advance1` | 6 | 2.7s |  |
| 64 | `goto_both_ways1` | 3 | 3.0s |  |
| 65 | `goto_both_ways2` | 3 | 2.8s |  |
| 66 | `goto_execution_order` | 2 | 2.7s |  |
| 67 | `goto_execution_order2` | 2 | 2.7s |  |
| 68 | `goto_frame_number` | 3 | 2.8s |  |
| 69 | `goto_rewind1` | 1 | 2.8s |  |
| 70 | `goto_rewind3` | 2 | 2.7s |  |
| 71 | `greater_swf6` | 1175 | 11.8s |  |
| 72 | `greater_swf7` | 1175 | 11.8s |  |
| 73 | `greaterthan_swf5` | 1 | 2.7s |  |
| 74 | `greaterthan_swf8` | 1 | 2.7s |  |
| 75 | `has_own_property` | 32 | 2.8s |  |
| 76 | `infinite_recursion_function` | 4 | 2.7s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 77 | `infinite_recursion_function_in_setter` | 131 | 2.7s |  |
| 78 | `infinite_recursion_virtual_property` | 67 | 2.7s |  |
| 79 | `init_array_invalid` | 4 | 2.7s |  |
| 80 | `init_object_invalid` | 4 | 2.7s |  |
| 81 | `issue_1086` | 1 | 2.7s |  |
| 82 | `issue_1671` | 0 | 2.7s |  |
| 83 | `issue_3446` | 1 | 2.7s |  |
| 84 | `issue_4377` | 2 | 2.8s |  |
| 85 | `issue_710` | 4 | 2.7s |  |
| 86 | `issue_768` | 3 | 2.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 87 | `lessthan` | 41 | 2.8s |  |
| 88 | `lessthan2_swf5` | 1226 | 12.4s |  |
| 89 | `lessthan2_swf6` | 1226 | 12.3s |  |
| 90 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 91 | `lessthan_swf4` | 902 | 8.1s |  |
| 92 | `lessthan_swf4_alt` | 41 | 2.8s |  |
| 93 | `lessthan_swf5` | 41 | 2.8s |  |
| 94 | `logical_ops_swf4` | 90 | 2.9s |  |
| 95 | `logical_ops_swf8` | 108 | 2.9s |  |
| 96 | `looping` | 6 | 2.7s |  |
| 97 | `mask_reapply` | 0 | 2.7s |  |
| 98 | `mask_with_drawing` | 0 | 2.8s |  |
| 99 | `movieclip_begin_gradient_fill` | 0 | 3.5s |  |
| 100 | `movieclip_line_gradient_style` | 0 | 3.3s |  |
| 101 | `movieclip_name_from_timeline` | 13 | 2.7s |  |
| 102 | `movieclip_prototype_extension` | 5 | 2.7s |  |
| 103 | `nested_textfields_in_buttons` | 0 | 2.6s |  |
| 104 | `netstream_play_flv_screen` | 0 | 30.1s |  |
| 105 | `new_method_wrap` | 4 | 2.7s |  |
| 106 | `new_object_enumerate` | 7 | 2.7s |  |
| 107 | `new_object_wrap` | 4 | 2.6s |  |
| 108 | `o` | 3 | 2.6s |  |
| 109 | `object_constructor` | 33 | 2.8s |  |
| 110 | `object_function` | 32 | 2.8s |  |
| 111 | `object_string_coerce_swf5` | 62 | 2.9s |  |
| 112 | `primitive_instanceof` | 37 | 2.8s |  |
| 113 | `prototype_delete` | 12 | 2.8s |  |
| 114 | `recursive_prototypes` | 0 | 2.6s |  |
| 115 | `sandbox_type_local_network` | 1 | 2.7s |  |
| 116 | `set_variable_scope` | 58 | 2.8s |  |
| 117 | `single_frame` | 1 | 2.6s |  |
| 118 | `sound_start_load` | 0 | 2.7s |  |
| 119 | `stage_object_properties_get_var` | 5 | 2.8s |  |
| 120 | `strictequals_swf6` | 902 | 9.0s |  |
| 121 | `strictly_equals` | 7 | 2.8s |  |
| 122 | `string_coercion` | 117 | 3.4s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 123 | `string_paths_keyevents` | 0 | 2.8s |  |
| 124 | `string_paths_timer` | 0 | 2.7s |  |
| 125 | `swf4_actions_bool` | 96 | 2.9s |  |
| 126 | `swf4_bool` | 4 | 2.8s |  |
| 127 | `swf4_function_calls` | 7 | 2.9s |  |
| 128 | `swf5_encoding` | 3 | 2.7s |  |
| 129 | `swf7_case_sensitive` | 44 | 2.9s |  |
| 130 | `tab_ordering_properties_tab_index_edge_case` | 4 | 2.7s |  |
| 131 | `this_swf7` | 41 | 2.8s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 132 | `timeline_function_def` | 7 | 2.8s |  |
| 133 | `try_finally_simple` | 16 | 2.8s |  |
| 134 | `typeof` | 22 | 2.8s |  |
| 135 | `typeof_globals` | 7 | 2.8s |  |
| 136 | `undefined_to_string_swf6` | 4 | 2.8s |  |
| 137 | `unescape` | 43 | 2.9s |  |
| 138 | `variable_args` | 5 | 3.0s |  |
| 139 | `waitforframe` | 7 | 3.0s |  |
| 140 | `waitforframe2` | 16 | 2.8s |  |
| 141 | `with_return` | 2 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**72 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `as_transformed_flag` | 90.0% | 18 | 20 | 2 |  |
| 2 | `conflicting_instance_names` | 87.0% | 20 | 23 | 3 |  |
| 3 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 4 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 5 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 6 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 7 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 8 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 9 | `goto_rewind2` | 75.0% | 3 | 4 | 1 |  |
| 10 | `xml_first_last_child` | 75.0% | 6 | 8 | 2 |  |
| 11 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 13 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 14 | `point` | 70.9% | 124 | 175 | 51 |  |
| 15 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 16 | `globals_swf6` | 70.1% | 213 | 304 | 91 |  |
| 17 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 18 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 19 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 20 | `globals_swf7` | 69.1% | 210 | 304 | 94 |  |
| 21 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 22 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 23 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 24 | `globals_swf5` | 67.8% | 206 | 304 | 98 |  |
| 25 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 27 | `object_prototypes` | 67.6% | 50 | 74 | 24 |  |
| 28 | `transform` | 67.1% | 47 | 70 | 23 |  |
| 29 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 30 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 31 | `goto_advance2` | 66.7% | 2 | 3 | 1 |  |
| 32 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 33 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 34 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 35 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 38 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 39 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 40 | `with` | 61.2% | 30 | 49 | 19 |  |
| 41 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 42 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 43 | `xml_parent_and_child` | 60.0% | 3 | 5 | 2 |  |
| 44 | `xml_siblings` | 60.0% | 6 | 10 | 4 |  |
| 45 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 46 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 47 | `xml_append_child` | 57.1% | 16 | 28 | 12 |  |
| 48 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 49 | `as_set_prop_flags` | 57.0% | 45 | 79 | 34 |  |
| 50 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 51 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 52 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 53 | `execution_order2` | 55.6% | 5 | 9 | 4 |  |
| 54 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 55 | `edittext_antialiastype` | 55.4% | 164 | 296 | 132 |  |
| 56 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 57 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 58 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 59 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 60 | `xml_clone_expandos` | 52.6% | 10 | 19 | 9 |  |
| 61 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 62 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 63 | `capabilities_resolution` | 50.0% | 4 | 8 | 4 |  |
| 64 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 65 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 66 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 67 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 68 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 69 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 70 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 71 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 72 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**72 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `button_children` | 4.8s |  |
| 2 | `button_key_events` | 5.1s |  |
| 3 | `button_key_events_special` | 5.6s |  |
| 4 | `button_keypress_vs_press` | 4.9s |  |
| 5 | `button_keypress_vs_tab` | 5.1s |  |
| 6 | `button_keypress_vs_textinput` | 4.8s |  |
| 7 | `clone_sprite_edittext` | 5.7s |  |
| 8 | `clone_sprite_types` | 4.7s |  |
| 9 | `device_font_spacing` | 5.0s |  |
| 10 | `duplicate_movie_clip_drawing` | 4.7s |  |
| 11 | `edittext_align` | 5.1s |  |
| 12 | `edittext_autosize` | 5.2s |  |
| 13 | `edittext_autosize_setter` | 4.8s |  |
| 14 | `edittext_bullet` | 5.2s |  |
| 15 | `edittext_default_format` | 5.0s |  |
| 16 | `edittext_default_format_empty` | 5.0s |  |
| 17 | `edittext_default_format_font_style` | 4.9s |  |
| 18 | `edittext_font_size` | 5.0s |  |
| 19 | `edittext_html_align_swf7` | 5.1s |  |
| 20 | `edittext_html_align_swf8` | 5.2s |  |
| 21 | `edittext_html_condensewhite_swf7` | 5.0s |  |
| 22 | `edittext_html_condensewhite_swf8` | 5.1s |  |
| 23 | `edittext_html_entity` | 4.9s |  |
| 24 | `edittext_html_swf6` | 6.6s |  |
| 25 | `edittext_html_swf7` | 6.7s |  |
| 26 | `edittext_html_swf8` | 6.7s |  |
| 27 | `edittext_input_newlines` | 4.8s |  |
| 28 | `edittext_leading` | 4.9s |  |
| 29 | `edittext_letter_spacing` | 4.9s |  |
| 30 | `edittext_margins` | 4.9s |  |
| 31 | `edittext_newline_stripping` | 9.6s |  |
| 32 | `edittext_newlines` | 5.1s |  |
| 33 | `edittext_password_copy` | 4.7s |  |
| 34 | `edittext_programmatic_focus` | 4.7s |  |
| 35 | `edittext_restrict_paste` | 4.7s |  |
| 36 | `edittext_scroll` | 4.9s |  |
| 37 | `edittext_tab_stops` | 5.2s |  |
| 38 | `edittext_tag_indent` | 4.8s |  |
| 39 | `edittext_underline` | 5.0s |  |
| 40 | `edittext_width_height` | 5.0s |  |
| 41 | `focus_keyboard_press` | 4.9s |  |
| 42 | `focus_mouse` | 5.0s |  |
| 43 | `focus_mouse_rollout` | 4.8s |  |
| 44 | `focusrect_property_swf5` | 5.0s |  |
| 45 | `focusrect_property_swf6` | 5.1s |  |
| 46 | `focusrect_property_swf7` | 5.0s |  |
| 47 | `goto_methods` | 5.3s |  |
| 48 | `input_dead_keys_windows` | 4.9s |  |
| 49 | `issue_3522` | 4.7s |  |
| 50 | `native_objects_swf6` | 5.6s |  |
| 51 | `native_objects_swf7` | 5.7s |  |
| 52 | `native_objects_swf8` | 5.8s |  |
| 53 | `netstream_play_flv` | 4.8s |  |
| 54 | `path_string` | 5.1s |  |
| 55 | `remove_movie_clip` | 5.1s |  |
| 56 | `selection` | 5.1s |  |
| 57 | `selection_handlers` | 4.9s |  |
| 58 | `string_paths_hidden` | 4.8s |  |
| 59 | `swf4_actions_coercion_order` | 5.0s |  |
| 60 | `tab_ordering_custom_basic` | 4.8s |  |
| 61 | `tab_ordering_custom_i32_vs_u32` | 4.9s |  |
| 62 | `tab_ordering_custom_m1` | 4.8s |  |
| 63 | `tab_ordering_events` | 5.4s |  |
| 64 | `tab_ordering_events_mouse` | 5.1s |  |
| 65 | `tab_ordering_properties` | 4.9s |  |
| 66 | `tab_ordering_tabbable` | 5.0s |  |
| 67 | `textfield_background_color` | 4.7s |  |
| 68 | `textfield_border_color` | 4.7s |  |
| 69 | `textfield_properties` | 4.9s |  |
| 70 | `textfield_text` | 4.7s |  |
| 71 | `textfield_variable` | 5.2s |  |
| 72 | `use_hand_cursor` | 4.8s |  |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `uncaught_exception` | exit code 1 | 2.8s |  |
| 2 | `uncaught_exception_bubbled` | exit code 1 | 2.8s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `parse_float` | runtime timeout (>10s) | 13.8s |  |
| 2 | `timeout` | runtime timeout (>10s) | 13.0s |  |
| 3 | `try_catch_finally` | runtime timeout (>10s) | 13.2s |  |

## All Output Mismatches

**401 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `as_transformed_flag` | 90.0% | 18/20 | 20 | 20 |  |
| 2 | `conflicting_instance_names` | 87.0% | 20/23 | 23 | 23 |  |
| 3 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 4 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 5 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 6 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 7 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 8 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 9 | `goto_rewind2` | 75.0% | 3/4 | 4 | 3 |  |
| 10 | `xml_first_last_child` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 12 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 14 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 15 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 16 | `globals_swf6` | 70.1% | 213/304 | 304 | 304 |  |
| 17 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 18 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 19 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 20 | `globals_swf7` | 69.1% | 210/304 | 304 | 304 |  |
| 21 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 22 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 23 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 24 | `globals_swf5` | 67.8% | 206/304 | 304 | 304 |  |
| 25 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 26 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 27 | `object_prototypes` | 67.6% | 50/74 | 73 | 74 |  |
| 28 | `transform` | 67.1% | 47/70 | 70 | 70 |  |
| 29 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 30 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 31 | `goto_advance2` | 66.7% | 2/3 | 3 | 2 |  |
| 32 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 33 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 34 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 35 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 36 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 37 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 38 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 39 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 40 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 41 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 42 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 43 | `xml_parent_and_child` | 60.0% | 3/5 | 5 | 5 |  |
| 44 | `xml_siblings` | 60.0% | 6/10 | 10 | 10 |  |
| 45 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 46 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 47 | `xml_append_child` | 57.1% | 16/28 | 28 | 28 |  |
| 48 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 49 | `as_set_prop_flags` | 57.0% | 45/79 | 76 | 79 |  |
| 50 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 51 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 52 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 53 | `execution_order2` | 55.6% | 5/9 | 9 | 7 |  |
| 54 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 55 | `edittext_antialiastype` | 55.4% | 164/296 | 296 | 296 |  |
| 56 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 57 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 58 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 59 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 60 | `xml_clone_expandos` | 52.6% | 10/19 | 19 | 19 |  |
| 61 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 62 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 63 | `capabilities_resolution` | 50.0% | 4/8 | 8 | 8 |  |
| 64 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 65 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 66 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 67 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 68 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 69 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 70 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 71 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 72 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 73 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 74 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 75 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 76 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 77 | `text_format_display` | 47.6% | 10/21 | 21 | 21 |  |
| 78 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 79 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 80 | `xml_cdata` | 45.5% | 5/11 | 11 | 11 |  |
| 81 | `globals_swf8` | 44.7% | 136/304 | 304 | 304 |  |
| 82 | `issue_2166` | 44.4% | 4/9 | 9 | 9 |  |
| 83 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 84 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 85 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 86 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 87 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 88 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 89 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 90 | `as2_oop` | 38.5% | 5/13 | 10 | 13 |  |
| 91 | `xml_ignore_white` | 38.2% | 13/34 | 34 | 34 |  |
| 92 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 93 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 94 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 95 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 96 | `init_object_order` | 33.3% | 5/15 | 5 | 15 |  |
| 97 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 98 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 99 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 100 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 101 | `xml_remove_node` | 31.8% | 7/22 | 22 | 22 |  |
| 102 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 103 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 104 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 105 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 106 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 107 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 108 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 109 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 110 | `edittext_align_trailing_spaces_swf7` | 25.0% | 144/576 | 576 | 576 |  |
| 111 | `edittext_align_trailing_spaces_swf8` | 25.0% | 144/576 | 576 | 576 |  |
| 112 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 113 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 114 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 115 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 116 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 117 | `xml_attributes_read` | 25.0% | 1/4 | 3 | 4 |  |
| 118 | `textfield_props_swf5` | 21.1% | 37/175 | 139 | 175 |  |
| 119 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 120 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 121 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 122 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 123 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 124 | `default_names` | 19.2% | 10/52 | 34 | 52 |  |
| 125 | `text_format_rounding_swf8` | 18.9% | 159/840 | 840 | 840 |  |
| 126 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 127 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 128 | `text_format_rounding_swf7` | 17.9% | 150/840 | 840 | 840 |  |
| 129 | `textfield_props_swf6` | 17.6% | 37/210 | 140 | 210 |  |
| 130 | `textfield_props_swf7` | 17.1% | 36/210 | 140 | 210 |  |
| 131 | `textfield_props_swf8` | 17.1% | 36/210 | 140 | 210 |  |
| 132 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 133 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 134 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 135 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 136 | `watch` | 15.4% | 18/117 | 100 | 117 |  |
| 137 | `as2_super_via_manual_prototype` | 15.0% | 6/40 | 16 | 40 |  |
| 138 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 139 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 140 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 141 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 142 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 143 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 144 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 145 | `xml_inspect_doctype` | 14.3% | 1/7 | 7 | 7 |  |
| 146 | `xml_inspect_xmldecl` | 14.3% | 1/7 | 7 | 7 |  |
| 147 | `movieclip_hittest_shapeflag` | 14.2% | 48/338 | 338 | 338 |  |
| 148 | `text_format` | 13.6% | 156/1146 | 1137 | 1146 |  |
| 149 | `register_and_init_order` | 13.4% | 31/231 | 73 | 231 |  |
| 150 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 151 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 152 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 153 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 154 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 155 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 156 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 157 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 158 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 159 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 160 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 161 | `extends_chain` | 11.2% | 15/134 | 114 | 134 |  |
| 162 | `external_interface_toxml_basic` | 11.2% | 20/179 | 179 | 179 |  |
| 163 | `swf5_no_closure` | 10.5% | 2/19 | 11 | 19 |  |
| 164 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 165 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 166 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 167 | `xml_idmap` | 9.5% | 2/21 | 8 | 21 |  |
| 168 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 169 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 170 | `execution_order4` | 8.3% | 1/12 | 9 | 12 |  |
| 171 | `external_interface_toxml_array` | 8.0% | 2/25 | 25 | 25 |  |
| 172 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 173 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 174 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 175 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 176 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 177 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 178 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 179 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 180 | `xml` | 6.7% | 1/15 | 8 | 15 |  |
| 181 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 182 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 183 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 184 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 185 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 186 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 187 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 188 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 189 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 190 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 191 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 192 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 193 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 194 | `bitmap_data` | 4.1% | 46/1126 | 318 | 1126 |  |
| 195 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 196 | `xml_namespaces` | 3.9% | 8/203 | 16 | 203 |  |
| 197 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 198 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 199 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 200 | `xml_inspect_parsexml` | 3.2% | 2/62 | 32 | 62 |  |
| 201 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 202 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 203 | `bitmap_data_threshold` | 2.3% | 4/176 | 38 | 176 |  |
| 204 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 205 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 206 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 207 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 208 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 209 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 210 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 211 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 212 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 213 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 214 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 215 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 216 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 217 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 218 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 219 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 |  |
| 220 | `global_instance_decls` | 0.1% | 1/758 | 81 | 758 |  |
| 221 | `global_proto_decls` | 0.0% | 1/4497 | 20 | 4497 |  |
| 222 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 223 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 224 | `array_sort_random` | 0.0% | 0/443 | 0 | 443 |  |
| 225 | `as2_super_and_this_v6` | 0.0% | 0/97 | 1 | 97 |  |
| 226 | `as2_super_and_this_v8` | 0.0% | 0/85 | 1 | 85 |  |
| 227 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 228 | `asnew` | 0.0% | 0/34 | 0 | 34 |  |
| 229 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `bitmap_data_copypixels` | 0.0% | 0/17 | 0 | 17 |  |
| 231 | `bitmap_data_pixeldissolve` | 0.0% | 0/1075 | 0 | 1075 |  |
| 232 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 233 | `boxed_primitives` | 0.0% | 0/24 | 0 | 24 |  |
| 234 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 235 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 236 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 238 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 239 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 240 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 241 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 242 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 243 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 244 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 245 | `coerce_to_object_monkeypatch` | 0.0% | 0/129 | 0 | 129 |  |
| 246 | `coerce_to_primitive_resolve` | 0.0% | 0/17 | 0 | 17 |  |
| 247 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 248 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 249 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 250 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 251 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 252 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 253 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 254 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 255 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 256 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 257 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 258 | `edittext_password` | 0.0% | 0/5 | 5 | 5 |  |
| 259 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 260 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 261 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 262 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 263 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 264 | `extends_native_type` | 0.0% | 0/11 | 4 | 11 |  |
| 265 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 266 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 267 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 268 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 269 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 270 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 271 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 272 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 273 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 274 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 275 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 276 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 277 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 278 | `function_suppress_and_preload` | 0.0% | 0/28 | 0 | 28 |  |
| 279 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 280 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 281 | `global_proto_decls_delete` | 0.0% | 0/4158 | 14 | 4158 |  |
| 282 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 283 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 284 | `hittest_lockroot` | 0.0% | 0/15 | 0 | 15 |  |
| 285 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 286 | `hittest_winding_rule` | 0.0% | 0/12 | 0 | 12 |  |
| 287 | `instanceof_coercions` | 0.0% | 0/88 | 0 | 88 |  |
| 288 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 289 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 290 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 291 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 292 | `issue_3169` | 0.0% | 0/2 | 0 | 2 |  |
| 293 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 294 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 295 | `loadmovie_fail` | 0.0% | 0/2 | 0 | 2 |  |
| 296 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 297 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 298 | `loadmovienum_cross_version_prototype` | 0.0% | 0/9 | 0 | 9 |  |
| 299 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 300 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 301 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 302 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 303 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 304 | `math_swf6` | 0.0% | 0/530 | 0 | 530 |  |
| 305 | `math_swf7` | 0.0% | 0/530 | 0 | 530 |  |
| 306 | `math_swf8` | 0.0% | 0/530 | 0 | 530 |  |
| 307 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 308 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 309 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 310 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 311 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 313 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 314 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 315 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 316 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 317 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 318 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 320 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 321 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 322 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 323 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 324 | `mouse_wheel_enabled` | 0.0% | 0/2 | 2 | 2 |  |
| 325 | `movieclip_blend_mode_property` | 0.0% | 0/35 | 0 | 35 |  |
| 326 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 327 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 328 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 329 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 330 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 331 | `native_double_construct` | 0.0% | 0/12 | 0 | 12 |  |
| 332 | `native_subclasses` | 0.0% | 0/191 | 0 | 191 |  |
| 333 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 334 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 335 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 336 | `object_resolve` | 0.0% | 0/38 | 0 | 38 |  |
| 337 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 338 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 339 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 340 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 341 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 342 | `prototype_enumerate` | 0.0% | 0/5 | 2 | 5 |  |
| 343 | `register_class_return_value` | 0.0% | 0/16 | 0 | 16 |  |
| 344 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 345 | `register_class_with_sound` | 0.0% | 0/11 | 0 | 11 |  |
| 346 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 347 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 348 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 350 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 351 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 352 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 353 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 354 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 355 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 356 | `stage_object_enumerate` | 0.0% | 0/4 | 0 | 4 |  |
| 357 | `string_methods_negative_args` | 0.0% | 0/240 | 0 | 240 |  |
| 358 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 359 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 360 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 361 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 362 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 363 | `super_edge_cases` | 0.0% | 0/39 | 0 | 39 |  |
| 364 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 365 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 366 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 367 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 368 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 369 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 370 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 371 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 372 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 373 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 374 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 375 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 376 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 377 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 378 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 |  |
| 379 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 |  |
| 380 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 381 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 382 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 383 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 384 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 385 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 386 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 387 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 388 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 389 | `xml_has_child_nodes` | 0.0% | 0/3 | 3 | 3 |  |
| 390 | `xml_ignore_comments` | 0.0% | 0/21 | 0 | 21 |  |
| 391 | `xml_inspect_createmethods` | 0.0% | 0/15 | 5 | 15 |  |
| 392 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 393 | `xml_reparenting` | 0.0% | 0/14 | 0 | 14 |  |
| 394 | `xml_socket` | 0.0% | 0/8 | 0 | 8 |  |
| 395 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 396 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 397 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
| 398 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 399 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
| 400 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 401 | `xmlnode_proto` | 0.0% | 0/1 | 0 | 1 |  |
