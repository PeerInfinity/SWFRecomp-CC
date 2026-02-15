# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 18:52 UTC

**Git SHA**: `c5804d051f`

**Run Duration**: 44m 57s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **195** (31.5%) |
| Failing | 424 |
| Total expected lines | 91294 |
| Matching lines | 43912 (48.1%) |
| Mismatched lines | 47382 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 417 | 98.3% |
| Runtime Segfault | 5 | 1.2% |
| Timeout | 2 | 0.5% |

## Passing Tests

**195 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.2s |  |
| 2 | `action_to_integer` | 28 | 4.2s |  |
| 3 | `add` | 28 | 4.2s |  |
| 4 | `add2` | 354 | 4.4s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.1s |  |
| 6 | `add_swf5` | 28 | 4.1s |  |
| 7 | `array_concat` | 98 | 4.2s |  |
| 8 | `array_constructor` | 30 | 4.2s |  |
| 9 | `array_length` | 42 | 4.2s |  |
| 10 | `array_properties` | 36 | 4.2s |  |
| 11 | `array_slice` | 34 | 4.2s |  |
| 12 | `array_splice` | 207 | 4.4s |  |
| 13 | `array_trivial` | 209 | 4.3s |  |
| 14 | `as1_constructor_v6` | 35 | 4.2s |  |
| 15 | `as1_constructor_v7` | 35 | 4.2s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.2s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 4.2s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.2s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.2s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.2s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.2s |  |
| 22 | `as_transformed_flag` | 20 | 4.2s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 4.1s |  |
| 24 | `bitand` | 1058 | 6.8s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.4s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.3s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 4.2s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 4.2s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.7s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.6s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.2s |  |
| 32 | `bitor` | 1058 | 6.8s |  |
| 33 | `biturshift` | 14 | 5.0s |  |
| 34 | `biturshift_swf8` | 14 | 4.2s |  |
| 35 | `bitxor` | 1058 | 7.0s |  |
| 36 | `call_method_empty_name` | 1 | 4.2s |  |
| 37 | `capabilities_resolution` | 8 | 4.1s |  |
| 38 | `catch_references_registers` | 2 | 4.2s |  |
| 39 | `conflicting_instance_names` | 23 | 4.3s |  |
| 40 | `define_function2` | 8 | 4.2s |  |
| 41 | `define_function2_preload` | 13 | 4.2s |  |
| 42 | `define_function2_preload_order` | 4 | 4.2s |  |
| 43 | `define_function_case_sensitive` | 2 | 4.2s |  |
| 44 | `delete` | 3 | 4.3s |  |
| 45 | `display_object_properties` | 2 | 4.1s |  |
| 46 | `do_init_action` | 3 | 4.2s |  |
| 47 | `edittext_antialiastype` | 296 | 4.4s |  |
| 48 | `edittext_autosize_setter` | 20 | 4.0s |  |
| 49 | `edittext_default_format` | 221 | 4.2s |  |
| 50 | `edittext_default_format_empty` | 95 | 4.1s |  |
| 51 | `edittext_default_format_font_style` | 335 | 4.1s |  |
| 52 | `edittext_password` | 5 | 4.1s |  |
| 53 | `equals` | 32 | 4.1s |  |
| 54 | `equals2_swf5` | 926 | 5.9s |  |
| 55 | `equals2_swf6` | 926 | 5.8s |  |
| 56 | `equals2_swf7` | 926 | 5.9s |  |
| 57 | `equals_swf4` | 665 | 4.5s |  |
| 58 | `equals_swf4_alt` | 32 | 4.0s |  |
| 59 | `equals_swf5` | 32 | 4.0s |  |
| 60 | `error` | 58 | 4.1s |  |
| 61 | `escape` | 14 | 4.0s |  |
| 62 | `execution_order1` | 5 | 4.0s |  |
| 63 | `execution_order2` | 7 | 4.1s |  |
| 64 | `execution_order3` | 4 | 4.0s |  |
| 65 | `focusrect_mouse_swf8` | 0 | 4.2s |  |
| 66 | `focusrect_mouse_swf9` | 0 | 4.2s |  |
| 67 | `focusrect_swf5` | 6 | 4.3s |  |
| 68 | `getproperty` | 28 | 4.1s |  |
| 69 | `getproperty_swf4` | 28 | 4.0s |  |
| 70 | `getproperty_swf5` | 28 | 4.0s |  |
| 71 | `global_array` | 3 | 4.1s |  |
| 72 | `global_is_bare` | 7 | 4.0s |  |
| 73 | `goto_advance1` | 6 | 4.1s |  |
| 74 | `goto_advance2` | 2 | 4.1s |  |
| 75 | `goto_both_ways1` | 3 | 5.0s |  |
| 76 | `goto_both_ways2` | 3 | 4.1s |  |
| 77 | `goto_execution_order` | 2 | 4.1s |  |
| 78 | `goto_execution_order2` | 2 | 4.1s |  |
| 79 | `goto_frame_number` | 3 | 4.2s |  |
| 80 | `goto_rewind1` | 1 | 4.1s |  |
| 81 | `goto_rewind2` | 3 | 4.3s |  |
| 82 | `goto_rewind3` | 2 | 4.0s |  |
| 83 | `greater_swf6` | 1175 | 6.1s |  |
| 84 | `greater_swf7` | 1175 | 6.1s |  |
| 85 | `greaterthan_swf5` | 1 | 4.1s |  |
| 86 | `greaterthan_swf8` | 1 | 4.1s |  |
| 87 | `has_own_property` | 32 | 4.1s |  |
| 88 | `infinite_recursion_function` | 4 | 4.1s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 89 | `infinite_recursion_function_in_setter` | 131 | 4.1s |  |
| 90 | `infinite_recursion_virtual_property` | 67 | 4.1s |  |
| 91 | `init_array_invalid` | 4 | 4.0s |  |
| 92 | `init_object_invalid` | 4 | 4.0s |  |
| 93 | `issue_1086` | 1 | 4.0s |  |
| 94 | `issue_1671` | 0 | 4.1s |  |
| 95 | `issue_2166` | 9 | 4.1s |  |
| 96 | `issue_3446` | 1 | 4.0s |  |
| 97 | `issue_4377` | 2 | 4.0s |  |
| 98 | `issue_710` | 4 | 4.0s |  |
| 99 | `issue_768` | 3 | 4.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 100 | `lessthan` | 41 | 4.1s |  |
| 101 | `lessthan2_swf5` | 1226 | 6.2s |  |
| 102 | `lessthan2_swf6` | 1226 | 6.2s |  |
| 103 | `lessthan2_swf7` | 1226 | 6.2s |  |
| 104 | `lessthan_swf4` | 902 | 4.7s |  |
| 105 | `lessthan_swf4_alt` | 41 | 4.0s |  |
| 106 | `lessthan_swf5` | 41 | 4.1s |  |
| 107 | `logical_ops_swf4` | 90 | 4.0s |  |
| 108 | `logical_ops_swf8` | 108 | 4.1s |  |
| 109 | `looping` | 6 | 4.0s |  |
| 110 | `mask_reapply` | 0 | 4.0s |  |
| 111 | `mask_with_drawing` | 0 | 4.0s |  |
| 112 | `math_min_max` | 101 | 4.2s |  |
| 113 | `mouse_wheel_enabled` | 2 | 4.1s |  |
| 114 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 115 | `movieclip_blend_mode_property` | 35 | 4.1s |  |
| 116 | `movieclip_default_state` | 69 | 4.2s |  |
| 117 | `movieclip_line_gradient_style` | 0 | 4.3s |  |
| 118 | `movieclip_name_from_timeline` | 13 | 3.9s |  |
| 119 | `movieclip_prototype_extension` | 5 | 3.9s |  |
| 120 | `nested_textfields_in_buttons` | 0 | 3.9s |  |
| 121 | `netstream_play_flv_screen` | 0 | 16.9s |  |
| 122 | `new_method_wrap` | 4 | 3.9s |  |
| 123 | `new_object_wrap` | 4 | 3.9s |  |
| 124 | `o` | 3 | 3.9s |  |
| 125 | `object_constructor` | 33 | 4.0s |  |
| 126 | `object_function` | 32 | 3.9s |  |
| 127 | `object_string_coerce_swf5` | 62 | 3.9s |  |
| 128 | `primitive_instanceof` | 37 | 3.9s |  |
| 129 | `prototype_delete` | 12 | 4.0s |  |
| 130 | `recursive_prototypes` | 0 | 3.9s |  |
| 131 | `sandbox_type_local_file` | 1 | 4.0s |  |
| 132 | `set_variable_scope` | 58 | 4.1s |  |
| 133 | `single_frame` | 1 | 4.0s |  |
| 134 | `sound_start_load` | 0 | 4.0s |  |
| 135 | `stage_object_properties_get_var` | 5 | 4.0s |  |
| 136 | `strictequals_swf6` | 902 | 5.5s |  |
| 137 | `strictly_equals` | 7 | 4.0s |  |
| 138 | `string_coercion` | 117 | 4.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 139 | `string_methods_negative_args` | 240 | 4.1s |  |
| 140 | `string_methods_swfv5` | 275 | 4.5s |  |
| 141 | `string_paths_keyevents` | 0 | 4.1s |  |
| 142 | `string_paths_timer` | 0 | 4.0s |  |
| 143 | `swf4_actions_bool` | 96 | 4.0s |  |
| 144 | `swf4_bool` | 4 | 4.0s |  |
| 145 | `swf5_encoding` | 3 | 4.0s |  |
| 146 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.0s |  |
| 147 | `text_format` | 1146 | 4.3s |  |
| 148 | `text_format_display` | 21 | 4.1s |  |
| 149 | `text_format_font_max_length` | 2 | 4.1s |  |
| 150 | `text_format_rounding_swf7` | 840 | 4.2s |  |
| 151 | `text_format_rounding_swf8` | 840 | 4.2s |  |
| 152 | `textfield_background_color` | 11 | 4.1s |  |
| 153 | `textfield_border_color` | 11 | 4.1s |  |
| 154 | `textfield_maxchars` | 3 | 4.1s |  |
| 155 | `textfield_properties` | 44 | 4.1s |  |
| 156 | `textfield_text` | 7 | 4.1s |  |
| 157 | `textfield_variable` | 81 | 4.3s |  |
| 158 | `this_swf7` | 41 | 4.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 159 | `timeline_function_def` | 7 | 4.3s |  |
| 160 | `try_finally_simple` | 16 | 4.2s |  |
| 161 | `typeof` | 22 | 4.2s |  |
| 162 | `typeof_globals` | 7 | 4.0s |  |
| 163 | `uncaught_exception` | 1 | 4.0s |  |
| 164 | `uncaught_exception_bubbled` | 1 | 4.0s |  |
| 165 | `undefined_to_string_swf6` | 4 | 4.0s |  |
| 166 | `unescape` | 43 | 4.1s |  |
| 167 | `use_hand_cursor` | 8 | 4.1s |  |
| 168 | `variable_args` | 5 | 4.2s |  |
| 169 | `waitforframe` | 7 | 4.0s |  |
| 170 | `waitforframe2` | 16 | 4.0s |  |
| 171 | `with_return` | 2 | 4.1s |  |
| 172 | `xml` | 15 | 4.1s |  |
| 173 | `xml_append_child` | 28 | 4.1s |  |
| 174 | `xml_append_child_with_parent` | 20 | 4.1s |  |
| 175 | `xml_attributes_read` | 4 | 4.1s |  |
| 176 | `xml_cdata` | 11 | 4.1s |  |
| 177 | `xml_clone_expandos` | 19 | 4.1s |  |
| 178 | `xml_first_last_child` | 8 | 4.1s |  |
| 179 | `xml_has_child_nodes` | 3 | 4.1s |  |
| 180 | `xml_idmap` | 21 | 4.2s |  |
| 181 | `xml_ignore_comments` | 21 | 4.1s |  |
| 182 | `xml_ignore_white` | 34 | 4.1s |  |
| 183 | `xml_insert_before` | 20 | 4.1s |  |
| 184 | `xml_inspect_createmethods` | 15 | 4.1s |  |
| 185 | `xml_inspect_doctype` | 7 | 4.1s |  |
| 186 | `xml_inspect_parsexml` | 62 | 4.2s |  |
| 187 | `xml_inspect_xmldecl` | 7 | 4.2s |  |
| 188 | `xml_namespaces` | 203 | 4.1s |  |
| 189 | `xml_parent_and_child` | 5 | 4.1s |  |
| 190 | `xml_remove_node` | 22 | 4.2s |  |
| 191 | `xml_reparenting` | 14 | 4.2s |  |
| 192 | `xml_siblings` | 10 | 4.1s |  |
| 193 | `xml_to_string_comment` | 1 | 4.0s |  |
| 194 | `xml_unescaping` | 23 | 4.2s |  |
| 195 | `xmlnode_proto` | 1 | 4.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**108 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_methods` | 99.3% | 283 | 285 | 2 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208 | 210 | 2 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208 | 210 | 2 |  |
| 5 | `math_swf6` | 98.5% | 522 | 530 | 8 |  |
| 6 | `math_swf7` | 98.5% | 522 | 530 | 8 |  |
| 7 | `math_swf8` | 98.5% | 522 | 530 | 8 |  |
| 8 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 10 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 11 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 12 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 13 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 14 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 15 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 16 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 17 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 18 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 19 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 20 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 21 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 22 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 23 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 24 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 25 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 26 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 27 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 28 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 29 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 30 | `array_sort` | 72.0% | 116 | 161 | 45 |  |
| 31 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 32 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 33 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 34 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 35 | `globals_swf6` | 71.7% | 218 | 304 | 86 |  |
| 36 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 37 | `point` | 70.9% | 124 | 175 | 51 |  |
| 38 | `globals_swf7` | 70.7% | 215 | 304 | 89 |  |
| 39 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 40 | `globals_swf5` | 69.4% | 211 | 304 | 93 |  |
| 41 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 42 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 43 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 44 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 45 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 46 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 47 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 48 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 49 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 50 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 51 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 52 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 53 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 54 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 55 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 56 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 57 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 58 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 59 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 60 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 61 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 62 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 63 | `with` | 61.2% | 30 | 49 | 19 |  |
| 64 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 65 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 66 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 67 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 68 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 69 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 70 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 71 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 72 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 73 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 74 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 75 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 76 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 77 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 78 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 79 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 80 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 81 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 82 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 83 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 84 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 85 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 86 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 87 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 88 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 89 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 90 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 91 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 92 | `globals_swf8` | 51.3% | 156 | 304 | 148 |  |
| 93 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 94 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 95 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 96 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 97 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 98 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 99 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 100 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 101 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 102 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 103 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 104 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 105 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 106 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 107 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 108 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `enumerate` | 5.5s |  |
| 2 | `goto_methods` | 6.5s |  |
| 3 | `init_object_order` | 6.2s |  |
| 4 | `register_and_init_order` | 5.6s |  |
| 5 | `register_class` | 5.4s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 14.3s |  |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 14.3s |  |

## All Output Mismatches

**417 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_methods` | 99.3% | 283/285 | 285 | 285 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208/210 | 210 | 210 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208/210 | 210 | 210 |  |
| 5 | `math_swf6` | 98.5% | 522/530 | 529 | 530 |  |
| 6 | `math_swf7` | 98.5% | 522/530 | 529 | 530 |  |
| 7 | `math_swf8` | 98.5% | 522/530 | 529 | 530 |  |
| 8 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 10 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 11 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 12 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 13 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 14 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 15 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 16 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 17 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 18 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 19 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 20 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 21 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 22 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 23 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 24 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 25 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 26 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 27 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 28 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 29 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 30 | `array_sort` | 72.0% | 116/161 | 161 | 161 |  |
| 31 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 32 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 33 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 34 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 35 | `globals_swf6` | 71.7% | 218/304 | 304 | 304 |  |
| 36 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 37 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 38 | `globals_swf7` | 70.7% | 215/304 | 304 | 304 |  |
| 39 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 40 | `globals_swf5` | 69.4% | 211/304 | 304 | 304 |  |
| 41 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 42 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 43 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 44 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 45 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 46 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 47 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 48 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 49 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 50 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 51 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 52 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 53 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 54 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 55 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 56 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 57 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 58 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 59 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 60 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 61 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 62 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 63 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 64 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 65 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 66 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 67 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 68 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 69 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 70 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 71 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 72 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 73 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 74 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 75 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 76 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 77 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 78 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 79 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 80 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 81 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 82 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 83 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 84 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 85 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 86 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 87 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 88 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 89 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 90 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 91 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 92 | `globals_swf8` | 51.3% | 156/304 | 304 | 304 |  |
| 93 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 94 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 95 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 96 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 97 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 98 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 99 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 100 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 101 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 102 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 103 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 104 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 105 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 106 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 107 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 108 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 109 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 110 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 111 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 112 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 113 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 114 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 115 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 116 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 117 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 118 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 119 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 120 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 121 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 122 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 123 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 124 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 125 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 126 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 127 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 128 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 129 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 130 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 131 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 132 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 133 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 134 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 135 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 136 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 137 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 138 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 139 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 140 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 141 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 142 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 143 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 144 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 145 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 146 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 147 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 148 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 149 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 150 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 151 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 152 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 153 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 154 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 155 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 156 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 157 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 158 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 159 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 160 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 161 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 162 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 163 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 164 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 165 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 166 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 167 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 168 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 169 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 170 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 171 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 172 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 173 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 174 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 175 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 176 | `focusrect_property_swf6` | 13.7% | 169/1237 | 276 | 1237 |  |
| 177 | `focusrect_property_swf7` | 13.6% | 168/1237 | 276 | 1237 |  |
| 178 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 179 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 180 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 181 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 182 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 183 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 184 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 185 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 186 | `xml_socket` | 12.5% | 1/8 | 1 | 8 |  |
| 187 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 188 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 189 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 190 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 191 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 192 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 193 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 194 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 195 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 196 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 197 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 198 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 199 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 200 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 201 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 202 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 203 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 204 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 205 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 206 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 207 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 208 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 209 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 210 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 211 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 212 | `bitmap_data_pixeldissolve` | 6.3% | 68/1075 | 1055 | 1075 |  |
| 213 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 214 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 215 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 216 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 217 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 218 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 219 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 220 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 221 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 222 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 223 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 224 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 225 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 226 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 227 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 228 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 229 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 230 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 231 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 232 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 233 | `focusrect_property_swf5` | 3.6% | 44/1237 | 276 | 1237 |  |
| 234 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 235 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 236 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 237 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 238 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 239 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 240 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 241 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 242 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 243 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 244 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 245 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 246 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 247 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 248 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 249 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 250 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 251 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 252 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 253 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 254 | `global_proto_decls` | 0.1% | 4/4497 | 184 | 4497 |  |
| 255 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 256 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 257 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 258 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 259 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
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
| 271 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 272 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 273 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 274 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 275 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 276 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 277 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 278 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 279 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 280 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 281 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 282 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 283 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 284 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 285 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 286 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 287 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 289 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 292 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 293 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 294 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 295 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 296 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 297 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 298 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 299 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 300 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 301 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 302 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 303 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 304 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 305 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 306 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 307 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 308 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 309 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 310 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 311 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 312 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 313 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 314 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 315 | `global_proto_decls_delete` | 0.0% | 0/4158 | 69 | 4158 |  |
| 316 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 317 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 318 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 319 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 320 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 321 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 322 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 323 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 324 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 326 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 327 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 328 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 329 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 330 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 331 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 332 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 333 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 335 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 336 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 337 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 338 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 339 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 340 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 341 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 342 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 343 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 344 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 345 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 346 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 347 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 348 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 349 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 350 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 351 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 352 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 353 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 354 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 355 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 356 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 357 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 358 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 359 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 360 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 361 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 362 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 363 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 364 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 365 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 366 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 367 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 368 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 369 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 370 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 371 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 372 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 373 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 374 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 375 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 376 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 377 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 378 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 379 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 380 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 381 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 382 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 383 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 384 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 385 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 386 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 387 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 388 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 389 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 390 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 391 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 392 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 393 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 394 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 395 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 396 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 397 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 398 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 399 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 400 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 401 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 402 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 403 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 404 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 405 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 406 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 407 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 408 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 409 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 410 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 411 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 412 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 413 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 414 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 415 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 416 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 417 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
