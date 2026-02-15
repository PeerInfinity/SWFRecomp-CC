# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 04:43 UTC

**Git SHA**: `17b33b9720`

**Run Duration**: 45m 41s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **122** (25.3%) |
| Failing | 360 |
| Total expected lines | 76475 |
| Matching lines | 29904 (39.1%) |
| Mismatched lines | 46571 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 306 | 85.0% |
| Segfault | 53 | 14.7% |
| Timeout | 1 | 0.3% |

## Passing Tests

**122 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.2s |  |
| 2 | `action_to_integer` | 28 | 3.8s |  |
| 3 | `add` | 28 | 3.9s |  |
| 4 | `add_swf4` | 28 | 3.8s |  |
| 5 | `add_swf5` | 28 | 3.8s |  |
| 6 | `array_concat` | 98 | 3.9s |  |
| 7 | `array_constructor` | 30 | 3.9s |  |
| 8 | `array_length` | 42 | 4.0s |  |
| 9 | `array_properties` | 36 | 3.9s |  |
| 10 | `array_slice` | 34 | 3.9s |  |
| 11 | `array_splice` | 207 | 4.1s |  |
| 12 | `array_trivial` | 209 | 4.0s |  |
| 13 | `as1_constructor_v6` | 35 | 3.9s |  |
| 14 | `as1_constructor_v7` | 35 | 3.9s |  |
| 15 | `as_broadcaster_initialize` | 10 | 3.9s |  |
| 16 | `as_transformed_flag` | 20 | 3.9s |  |
| 17 | `bad_swf_tag_past_eof` | 0 | 3.8s |  |
| 18 | `bitand` | 1058 | 6.3s |  |
| 19 | `bitmap_data_colortransform` | 0 | 4.1s |  |
| 20 | `bitmap_data_fillrect` | 0 | 4.0s |  |
| 21 | `bitmap_data_perlinnoise` | 0 | 4.4s |  |
| 22 | `bitmap_data_pixeldissolve_image` | 0 | 4.2s |  |
| 23 | `bitor` | 1058 | 6.2s |  |
| 24 | `biturshift` | 14 | 4.2s |  |
| 25 | `biturshift_swf8` | 14 | 3.9s |  |
| 26 | `bitxor` | 1058 | 6.5s |  |
| 27 | `call_method_empty_name` | 1 | 3.9s |  |
| 28 | `capabilities_resolution` | 8 | 3.9s |  |
| 29 | `catch_references_registers` | 2 | 3.9s |  |
| 30 | `conflicting_instance_names` | 23 | 4.0s |  |
| 31 | `define_function2` | 8 | 3.9s |  |
| 32 | `define_function2_preload_order` | 4 | 4.0s |  |
| 33 | `define_function_case_sensitive` | 2 | 3.9s |  |
| 34 | `delete` | 3 | 4.0s |  |
| 35 | `display_object_properties` | 2 | 3.9s |  |
| 36 | `do_init_action` | 3 | 3.9s |  |
| 37 | `edittext_autosize_setter` | 20 | 4.0s |  |
| 38 | `equals` | 32 | 4.0s |  |
| 39 | `equals_swf4` | 665 | 4.3s |  |
| 40 | `equals_swf4_alt` | 32 | 3.9s |  |
| 41 | `equals_swf5` | 32 | 3.9s |  |
| 42 | `escape` | 14 | 3.9s |  |
| 43 | `execution_order1` | 5 | 4.0s |  |
| 44 | `execution_order2` | 7 | 4.0s |  |
| 45 | `execution_order3` | 4 | 3.9s |  |
| 46 | `focusrect_mouse_swf8` | 0 | 3.9s |  |
| 47 | `focusrect_mouse_swf9` | 0 | 3.9s |  |
| 48 | `focusrect_swf5` | 6 | 4.0s |  |
| 49 | `getproperty` | 28 | 3.9s |  |
| 50 | `getproperty_swf4` | 28 | 3.9s |  |
| 51 | `getproperty_swf5` | 28 | 3.9s |  |
| 52 | `global_array` | 3 | 3.9s |  |
| 53 | `global_is_bare` | 7 | 3.9s |  |
| 54 | `goto_advance1` | 6 | 3.9s |  |
| 55 | `goto_advance2` | 2 | 3.9s |  |
| 56 | `goto_both_ways1` | 3 | 4.2s |  |
| 57 | `goto_both_ways2` | 3 | 3.9s |  |
| 58 | `goto_execution_order` | 2 | 3.9s |  |
| 59 | `goto_execution_order2` | 2 | 4.0s |  |
| 60 | `goto_rewind1` | 1 | 4.0s |  |
| 61 | `goto_rewind2` | 3 | 4.0s |  |
| 62 | `goto_rewind3` | 2 | 3.9s |  |
| 63 | `greaterthan_swf5` | 1 | 3.9s |  |
| 64 | `greaterthan_swf8` | 1 | 3.9s |  |
| 65 | `has_own_property` | 32 | 3.9s |  |
| 66 | `infinite_recursion_function` | 4 | 3.9s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 67 | `init_array_invalid` | 4 | 3.9s |  |
| 68 | `init_object_invalid` | 4 | 3.9s |  |
| 69 | `issue_1086` | 1 | 3.9s |  |
| 70 | `issue_2166` | 9 | 3.9s |  |
| 71 | `issue_3446` | 1 | 3.9s |  |
| 72 | `issue_4377` | 2 | 3.9s |  |
| 73 | `issue_710` | 4 | 3.9s |  |
| 74 | `issue_768` | 3 | 3.9s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 75 | `lessthan` | 41 | 3.9s |  |
| 76 | `lessthan_swf4` | 902 | 4.7s |  |
| 77 | `lessthan_swf4_alt` | 41 | 3.9s |  |
| 78 | `lessthan_swf5` | 41 | 3.9s |  |
| 79 | `logical_ops_swf4` | 90 | 4.0s |  |
| 80 | `logical_ops_swf8` | 108 | 4.0s |  |
| 81 | `looping` | 6 | 3.9s |  |
| 82 | `mask_reapply` | 0 | 3.9s |  |
| 83 | `mask_with_drawing` | 0 | 3.9s |  |
| 84 | `movieclip_begin_gradient_fill` | 0 | 4.4s |  |
| 85 | `movieclip_blend_mode_property` | 35 | 4.0s |  |
| 86 | `movieclip_line_gradient_style` | 0 | 4.1s |  |
| 87 | `movieclip_name_from_timeline` | 13 | 3.7s |  |
| 88 | `movieclip_prototype_extension` | 5 | 3.7s |  |
| 89 | `nested_textfields_in_buttons` | 0 | 3.7s |  |
| 90 | `netstream_play_flv_screen` | 0 | 16.6s |  |
| 91 | `new_method_wrap` | 4 | 3.7s |  |
| 92 | `new_object_wrap` | 4 | 3.7s |  |
| 93 | `o` | 3 | 3.7s |  |
| 94 | `primitive_instanceof` | 37 | 3.8s |  |
| 95 | `recursive_prototypes` | 0 | 3.8s |  |
| 96 | `set_variable_scope` | 58 | 3.9s |  |
| 97 | `single_frame` | 1 | 3.9s |  |
| 98 | `sound_start_load` | 0 | 3.9s |  |
| 99 | `stage_object_properties_get_var` | 5 | 3.9s |  |
| 100 | `strictly_equals` | 7 | 4.0s |  |
| 101 | `string_methods_negative_args` | 240 | 4.0s |  |
| 102 | `string_methods_swfv5` | 275 | 4.4s |  |
| 103 | `swf4_actions_bool` | 96 | 4.0s |  |
| 104 | `swf4_bool` | 4 | 3.9s |  |
| 105 | `swf5_encoding` | 3 | 3.9s |  |
| 106 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.9s |  |
| 107 | `textfield_background_color` | 11 | 3.9s |  |
| 108 | `textfield_border_color` | 11 | 3.9s |  |
| 109 | `timeline_function_def` | 7 | 4.0s |  |
| 110 | `try_finally_simple` | 16 | 3.8s |  |
| 111 | `typeof` | 22 | 3.8s |  |
| 112 | `typeof_globals` | 7 | 3.8s |  |
| 113 | `uncaught_exception` | 1 | 3.8s |  |
| 114 | `uncaught_exception_bubbled` | 1 | 3.9s |  |
| 115 | `undefined_to_string_swf6` | 4 | 3.8s |  |
| 116 | `unescape` | 43 | 3.9s |  |
| 117 | `use_hand_cursor` | 8 | 3.8s |  |
| 118 | `variable_args` | 5 | 3.9s |  |
| 119 | `waitforframe` | 7 | 3.8s |  |
| 120 | `waitforframe2` | 16 | 3.9s |  |
| 121 | `with_return` | 2 | 3.9s |  |
| 122 | `xmlnode_proto` | 1 | 3.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**107 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `text_format` | 99.0% | 1134 | 1146 | 12 |  |
| 2 | `string_methods` | 98.9% | 282 | 285 | 3 |  |
| 3 | `edittext_antialiastype` | 98.3% | 291 | 296 | 5 |  |
| 4 | `this_swf7` | 97.6% | 40 | 41 | 1 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 5 | `text_format_rounding_swf7` | 96.4% | 810 | 840 | 30 |  |
| 6 | `edittext_default_format_empty` | 95.8% | 91 | 95 | 4 |  |
| 7 | `textfield_properties` | 95.5% | 42 | 44 | 2 |  |
| 8 | `text_format_rounding_swf8` | 94.3% | 792 | 840 | 48 |  |
| 9 | `object_string_coerce_swf5` | 93.5% | 58 | 62 | 4 |  |
| 10 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 11 | `define_function2_preload` | 92.3% | 12 | 13 | 1 |  |
| 12 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 13 | `edittext_default_format_font_style` | 90.4% | 303 | 335 | 32 |  |
| 14 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 15 | `object_function` | 87.5% | 28 | 32 | 4 |  |
| 16 | `textfield_props_swf8` | 86.7% | 182 | 210 | 28 |  |
| 17 | `xml_inspect_createmethods` | 86.7% | 13 | 15 | 2 |  |
| 18 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 19 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 20 | `textfield_text` | 85.7% | 6 | 7 | 1 |  |
| 21 | `textfield_props_swf6` | 85.2% | 179 | 210 | 31 |  |
| 22 | `error` | 84.5% | 49 | 58 | 9 |  |
| 23 | `textfield_props_swf7` | 84.3% | 177 | 210 | 33 |  |
| 24 | `object_prototypes` | 82.4% | 61 | 74 | 13 |  |
| 25 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 26 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 27 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 28 | `string_coercion` | 79.7% | 94 | 118 | 24 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 29 | `textfield_variable` | 79.0% | 64 | 81 | 17 |  |
| 30 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 31 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 32 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 33 | `edittext_html_align_swf7` | 76.9% | 40 | 52 | 12 |  |
| 34 | `edittext_html_align_swf8` | 76.9% | 40 | 52 | 12 |  |
| 35 | `bitmap_data_max_size_swf10` | 75.0% | 9 | 12 | 3 |  |
| 36 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 37 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 38 | `array_sort` | 72.7% | 117 | 161 | 44 |  |
| 39 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 40 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 41 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 42 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 43 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 44 | `point` | 70.9% | 124 | 175 | 51 |  |
| 45 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 46 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 47 | `bitmap_data_max_size_swf9` | 70.0% | 7 | 10 | 3 |  |
| 48 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 49 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 50 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 51 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 52 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 53 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 54 | `goto_frame_number` | 66.7% | 2 | 3 | 1 |  |
| 55 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 56 | `xml_has_child_nodes` | 66.7% | 2 | 3 | 1 |  |
| 57 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 58 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 59 | `edittext_default_format` | 65.8% | 146 | 222 | 76 |  |
| 60 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 61 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 62 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 63 | `xml_append_child` | 64.3% | 18 | 28 | 10 |  |
| 64 | `xml_cdata` | 63.6% | 7 | 11 | 4 |  |
| 65 | `xml_clone_expandos` | 63.2% | 12 | 19 | 7 |  |
| 66 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 67 | `xml_first_last_child` | 62.5% | 5 | 8 | 3 |  |
| 68 | `object_string_coerce_swf6` | 61.8% | 42 | 68 | 26 |  |
| 69 | `with` | 61.2% | 30 | 49 | 19 |  |
| 70 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 71 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 72 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 73 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 74 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 75 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 76 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 77 | `xml_ignore_white` | 58.8% | 20 | 34 | 14 |  |
| 78 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 79 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 80 | `as_set_prop_flags_version` | 58.1% | 18 | 31 | 13 |  |
| 81 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 82 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 83 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 84 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 85 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 86 | `edittext_hscroll` | 55.6% | 15 | 27 | 12 |  |
| 87 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 88 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 89 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 90 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 91 | `parse_float` | 54.1% | 40 | 74 | 34 |  |
| 92 | `as2_oop` | 53.8% | 7 | 13 | 6 |  |
| 93 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 94 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 95 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 96 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 97 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 |  |
| 98 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 99 | `edittext_html_entity` | 50.0% | 2 | 4 | 2 |  |
| 100 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 101 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 102 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 103 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 104 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 105 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 106 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 107 | `xml_siblings` | 50.0% | 5 | 10 | 5 |  |

## Segfaults

**53 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmapdata_applyfilter_colormatrix` | 5.8s |  |
| 2 | `create_empty_movie_clip` | 5.8s |  |
| 3 | `device_font_spacing` | 9.1s |  |
| 4 | `duplicate_movie_clip_drawing` | 5.9s |  |
| 5 | `edittext_autosize` | 6.2s |  |
| 6 | `edittext_width_height` | 6.1s |  |
| 7 | `empty_movieclip_can_attach_movies` | 6.0s |  |
| 8 | `enumerate` | 6.0s |  |
| 9 | `equals2_swf5` | 7.8s |  |
| 10 | `equals2_swf6` | 7.8s |  |
| 11 | `equals2_swf7` | 7.8s |  |
| 12 | `global_swf5_6_7_8_9` | 6.2s |  |
| 13 | `global_swf6_7_8` | 6.0s |  |
| 14 | `goto_methods` | 8.4s |  |
| 15 | `greater_swf6` | 7.9s |  |
| 16 | `greater_swf7` | 8.0s |  |
| 17 | `init_object_order` | 6.1s |  |
| 18 | `interface_implements_op` | 6.3s |  |
| 19 | `issue_1671` | 5.9s |  |
| 20 | `issue_2030` | 5.9s |  |
| 21 | `lessthan2_swf5` | 8.1s |  |
| 22 | `lessthan2_swf6` | 8.2s |  |
| 23 | `lessthan2_swf7` | 8.2s |  |
| 24 | `lock_root` | 5.9s |  |
| 25 | `movieclip_default_state` | 6.2s |  |
| 26 | `movieclip_gettextsnapshot` | 6.2s |  |
| 27 | `movieclip_invalid_get_bounds_3` | 5.9s |  |
| 28 | `movieclip_invalid_get_bounds_4` | 5.4s |  |
| 29 | `movieclip_invalid_get_bounds_5` | 5.3s |  |
| 30 | `movieclip_invalid_get_bounds_6` | 5.2s |  |
| 31 | `movieclip_invalid_get_bounds_7` | 5.1s |  |
| 32 | `movieclip_invalid_get_bounds_8` | 5.2s |  |
| 33 | `movieclip_setmask` | 5.2s |  |
| 34 | `movieclip_state_values` | 6.0s |  |
| 35 | `object_constructor` | 5.2s |  |
| 36 | `property_invalid_base_clip` | 5.1s |  |
| 37 | `register_and_init_order` | 5.5s |  |
| 38 | `register_class` | 5.2s |  |
| 39 | `register_class_swf6` | 5.2s |  |
| 40 | `rewind_depth` | 6.2s |  |
| 41 | `sandbox_type_remote` | 6.0s |  |
| 42 | `strictequals_swf6` | 7.4s |  |
| 43 | `string_paths_basic` | 5.9s |  |
| 44 | `string_paths_eval2` | 5.9s |  |
| 45 | `string_paths_keyevents` | 5.9s |  |
| 46 | `string_paths_other` | 6.1s |  |
| 47 | `string_paths_timer` | 5.9s |  |
| 48 | `string_paths_unload` | 6.0s |  |
| 49 | `string_paths_variable_alias` | 5.9s |  |
| 50 | `textfield_cache_as_bitmap` | 5.9s |  |
| 51 | `this_scoping` | 6.0s |  |
| 52 | `try_catch_finally` | 10.4s |  |
| 53 | `unload` | 5.4s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 14.0s |  |

## All Output Mismatches

**306 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `text_format` | 99.0% | 1134/1146 | 1146 | 1146 |  |
| 2 | `string_methods` | 98.9% | 282/285 | 285 | 285 |  |
| 3 | `edittext_antialiastype` | 98.3% | 291/296 | 296 | 296 |  |
| 4 | `this_swf7` | 97.6% | 40/41 | 41 | 41 | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 5 | `text_format_rounding_swf7` | 96.4% | 810/840 | 840 | 840 |  |
| 6 | `edittext_default_format_empty` | 95.8% | 91/95 | 95 | 95 |  |
| 7 | `textfield_properties` | 95.5% | 42/44 | 44 | 44 |  |
| 8 | `text_format_rounding_swf8` | 94.3% | 792/840 | 840 | 840 |  |
| 9 | `object_string_coerce_swf5` | 93.5% | 58/62 | 62 | 62 |  |
| 10 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 11 | `define_function2_preload` | 92.3% | 12/13 | 13 | 13 |  |
| 12 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 13 | `edittext_default_format_font_style` | 90.4% | 303/335 | 335 | 335 |  |
| 14 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 15 | `object_function` | 87.5% | 28/32 | 32 | 32 |  |
| 16 | `textfield_props_swf8` | 86.7% | 182/210 | 210 | 210 |  |
| 17 | `xml_inspect_createmethods` | 86.7% | 13/15 | 15 | 15 |  |
| 18 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 19 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 20 | `textfield_text` | 85.7% | 6/7 | 7 | 7 |  |
| 21 | `textfield_props_swf6` | 85.2% | 179/210 | 210 | 210 |  |
| 22 | `error` | 84.5% | 49/58 | 58 | 58 |  |
| 23 | `textfield_props_swf7` | 84.3% | 177/210 | 210 | 210 |  |
| 24 | `object_prototypes` | 82.4% | 61/74 | 73 | 74 |  |
| 25 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 26 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 27 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 28 | `string_coercion` | 79.7% | 94/118 | 118 | 117 | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 29 | `textfield_variable` | 79.0% | 64/81 | 81 | 81 |  |
| 30 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 31 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 32 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 33 | `edittext_html_align_swf7` | 76.9% | 40/52 | 52 | 52 |  |
| 34 | `edittext_html_align_swf8` | 76.9% | 40/52 | 52 | 52 |  |
| 35 | `bitmap_data_max_size_swf10` | 75.0% | 9/12 | 12 | 12 |  |
| 36 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 37 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 38 | `array_sort` | 72.7% | 117/161 | 161 | 161 |  |
| 39 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 40 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 41 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 42 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 43 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 44 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 45 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 46 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 47 | `bitmap_data_max_size_swf9` | 70.0% | 7/10 | 10 | 10 |  |
| 48 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 49 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 50 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 51 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 52 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 53 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 54 | `goto_frame_number` | 66.7% | 2/3 | 2 | 3 |  |
| 55 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 56 | `xml_has_child_nodes` | 66.7% | 2/3 | 3 | 3 |  |
| 57 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 58 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 59 | `edittext_default_format` | 65.8% | 146/222 | 222 | 221 |  |
| 60 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 61 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 62 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 63 | `xml_append_child` | 64.3% | 18/28 | 28 | 28 |  |
| 64 | `xml_cdata` | 63.6% | 7/11 | 11 | 11 |  |
| 65 | `xml_clone_expandos` | 63.2% | 12/19 | 19 | 19 |  |
| 66 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 67 | `xml_first_last_child` | 62.5% | 5/8 | 8 | 8 |  |
| 68 | `object_string_coerce_swf6` | 61.8% | 42/68 | 64 | 68 |  |
| 69 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 70 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 71 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 72 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 73 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 74 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 75 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 76 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 77 | `xml_ignore_white` | 58.8% | 20/34 | 34 | 34 |  |
| 78 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 79 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 80 | `as_set_prop_flags_version` | 58.1% | 18/31 | 29 | 31 |  |
| 81 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 82 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 83 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 84 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 85 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 86 | `edittext_hscroll` | 55.6% | 15/27 | 27 | 27 |  |
| 87 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 88 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 89 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 90 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 91 | `parse_float` | 54.1% | 40/74 | 74 | 74 |  |
| 92 | `as2_oop` | 53.8% | 7/13 | 13 | 13 |  |
| 93 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 94 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 95 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 96 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 97 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 |  |
| 98 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 99 | `edittext_html_entity` | 50.0% | 2/4 | 4 | 4 |  |
| 100 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 101 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 102 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 103 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 104 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 105 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 106 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 107 | `xml_siblings` | 50.0% | 5/10 | 10 | 10 |  |
| 108 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 109 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 110 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 111 | `textfield_props_swf5` | 48.0% | 84/175 | 141 | 175 |  |
| 112 | `xml_unescaping` | 47.8% | 11/23 | 23 | 23 |  |
| 113 | `frame_size_translated_negative` | 47.6% | 10/21 | 20 | 21 |  |
| 114 | `frame_size_translated_positive` | 47.6% | 10/21 | 20 | 21 |  |
| 115 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 116 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 117 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 118 | `this_swf5` | 43.9% | 18/41 | 41 | 41 |  |
| 119 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 120 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 121 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 122 | `xml_reparenting` | 42.9% | 6/14 | 14 | 14 |  |
| 123 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 124 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 125 | `this_swf6` | 41.5% | 17/41 | 41 | 41 |  |
| 126 | `xml_append_child_with_parent` | 40.0% | 8/20 | 20 | 20 |  |
| 127 | `xml_insert_before` | 40.0% | 8/20 | 20 | 20 |  |
| 128 | `xml_parent_and_child` | 40.0% | 2/5 | 5 | 5 |  |
| 129 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 130 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 131 | `localconnection_properties` | 37.5% | 3/8 | 3 | 8 |  |
| 132 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 133 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 134 | `xml_remove_node` | 36.4% | 8/22 | 22 | 22 |  |
| 135 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 136 | `xml` | 35.5% | 11/31 | 31 | 15 |  |
| 137 | `xml_inspect_parsexml` | 33.9% | 21/62 | 52 | 62 |  |
| 138 | `array_call_method` | 33.3% | 3/9 | 5 | 9 |  |
| 139 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 140 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 141 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 142 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 143 | `prototype_delete` | 33.3% | 4/12 | 12 | 12 |  |
| 144 | `textfield_maxchars` | 33.3% | 1/3 | 3 | 3 |  |
| 145 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 146 | `xml_inspect_doctype` | 30.8% | 4/13 | 13 | 7 |  |
| 147 | `xml_inspect_xmldecl` | 30.8% | 4/13 | 13 | 7 |  |
| 148 | `duplicate_movie_clip` | 30.0% | 6/20 | 14 | 20 |  |
| 149 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 150 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 151 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 152 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 153 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 154 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 155 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 156 | `text_format_display` | 23.8% | 5/21 | 21 | 21 |  |
| 157 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 158 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 159 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 160 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 161 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 162 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 163 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 164 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 165 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 166 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 167 | `xml_attributes_read` | 16.7% | 1/6 | 6 | 4 |  |
| 168 | `movieclip_getbounds` | 15.8% | 33/209 | 209 | 191 |  |
| 169 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 170 | `path_string` | 14.9% | 48/322 | 300 | 322 |  |
| 171 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 172 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 173 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 174 | `xml_namespaces` | 14.3% | 29/203 | 33 | 203 |  |
| 175 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 176 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 177 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 178 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 179 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 180 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 181 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 182 | `watch_virtual_property` | 10.0% | 6/60 | 40 | 60 |  |
| 183 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 184 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 185 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 186 | `add2` | 8.7% | 31/358 | 358 | 354 | [investigation](ruffle-tests/_investigation/add2.md) |
| 187 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 188 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 189 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 190 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 191 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 192 | `hittest_lockroot` | 6.7% | 1/15 | 15 | 15 |  |
| 193 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 194 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 195 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 196 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 197 | `coerce_to_primitive_resolve` | 5.9% | 1/17 | 15 | 17 |  |
| 198 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 199 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 200 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 201 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 202 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 203 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 204 | `xml_idmap` | 4.8% | 1/21 | 9 | 21 |  |
| 205 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 206 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 207 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 208 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 209 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 210 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 211 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 212 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 213 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 214 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 215 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 216 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 217 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 218 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 219 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 220 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 221 | `global_proto_decls` | 0.1% | 4/4497 | 95 | 4497 |  |
| 222 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 223 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 224 | `as_set_prop_flags_version_swf5` | 0.0% | 0/1 | 1 | 1 |  |
| 225 | `as_set_prop_flags_version_swf6` | 0.0% | 0/1 | 1 | 1 |  |
| 226 | `as_set_prop_flags_version_swf7` | 0.0% | 0/1 | 1 | 1 |  |
| 227 | `as_set_prop_flags_version_swf8` | 0.0% | 0/1 | 1 | 1 |  |
| 228 | `as_set_prop_flags_version_swf9` | 0.0% | 0/1 | 1 | 1 |  |
| 229 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 230 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 231 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 232 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 234 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 235 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 236 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 237 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 238 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 239 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 240 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 241 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 242 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 243 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 244 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 245 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 246 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 247 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 248 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 249 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 250 | `global_proto_decls_delete` | 0.0% | 0/4158 | 24 | 4158 |  |
| 251 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 252 | `infinite_recursion_function_in_setter` | 0.0% | 0/131 | 1 | 131 |  |
| 253 | `infinite_recursion_virtual_property` | 0.0% | 0/67 | 2 | 67 |  |
| 254 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 256 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 257 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 258 | `issue_9327` | 0.0% | 0/2 | 2 | 2 |  |
| 259 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 260 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 261 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 262 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 263 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 264 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 265 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 266 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 267 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 268 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 269 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 270 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 271 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 272 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 273 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 274 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 275 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 276 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 277 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 279 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `sandbox_type_local_file` | 0.0% | 0/1 | 1 | 1 |  |
| 281 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 282 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 283 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 284 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 285 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 286 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 287 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 288 | `swf5_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 289 | `swf6_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 290 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 291 | `swf7_global_funcs` | 0.0% | 0/232 | 0 | 232 |  |
| 292 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 293 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 294 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 295 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 296 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 297 | `text_format_font_max_length` | 0.0% | 0/2 | 2 | 2 |  |
| 298 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 299 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 300 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 301 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 302 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 303 | `xml_child_nodes_edge_cases` | 0.0% | 0/4 | 4 | 4 |  |
| 304 | `xml_ignore_comments` | 0.0% | 0/27 | 27 | 21 |  |
| 305 | `xml_to_string` | 0.0% | 0/13 | 5 | 13 |  |
| 306 | `xml_to_string_comment` | 0.0% | 0/1 | 1 | 1 |  |
