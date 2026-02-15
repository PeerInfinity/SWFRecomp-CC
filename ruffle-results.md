# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 20:56 UTC

**Git SHA**: `06244c7b7d`

**Run Duration**: 45m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **200** (32.3%) |
| Failing | 419 |
| Total expected lines | 91294 |
| Matching lines | 45024 (49.3%) |
| Mismatched lines | 46270 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 411 | 98.1% |
| Runtime Segfault | 6 | 1.4% |
| Timeout | 2 | 0.5% |

## Passing Tests

**200 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.2s |  |
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
| 12 | `array_splice` | 207 | 4.3s |  |
| 13 | `array_trivial` | 209 | 4.3s |  |
| 14 | `as1_constructor_v6` | 35 | 4.1s |  |
| 15 | `as1_constructor_v7` | 35 | 4.1s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.2s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 4.2s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.2s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.3s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.4s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.3s |  |
| 22 | `as_transformed_flag` | 20 | 4.3s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 4.1s |  |
| 24 | `bitand` | 1058 | 7.2s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.6s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.3s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 4.2s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 4.2s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.8s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.6s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.1s |  |
| 32 | `bitor` | 1058 | 7.0s |  |
| 33 | `biturshift` | 14 | 5.3s |  |
| 34 | `biturshift_swf8` | 14 | 4.1s |  |
| 35 | `bitxor` | 1058 | 6.5s |  |
| 36 | `call_method_empty_name` | 1 | 4.1s |  |
| 37 | `capabilities_resolution` | 8 | 4.0s |  |
| 38 | `catch_references_registers` | 2 | 4.1s |  |
| 39 | `conflicting_instance_names` | 23 | 4.2s |  |
| 40 | `define_function2` | 8 | 4.1s |  |
| 41 | `define_function2_preload` | 13 | 4.1s |  |
| 42 | `define_function2_preload_order` | 4 | 4.1s |  |
| 43 | `define_function_case_sensitive` | 2 | 4.1s |  |
| 44 | `delete` | 3 | 4.1s |  |
| 45 | `display_object_properties` | 2 | 4.0s |  |
| 46 | `do_init_action` | 3 | 4.1s |  |
| 47 | `edittext_antialiastype` | 296 | 5.8s |  |
| 48 | `edittext_autosize_setter` | 20 | 4.1s |  |
| 49 | `edittext_default_format` | 221 | 4.3s |  |
| 50 | `edittext_default_format_empty` | 95 | 4.2s |  |
| 51 | `edittext_default_format_font_style` | 335 | 4.2s |  |
| 52 | `edittext_password` | 5 | 4.2s |  |
| 53 | `equals` | 32 | 4.2s |  |
| 54 | `equals2_swf5` | 926 | 5.9s |  |
| 55 | `equals2_swf6` | 926 | 5.8s |  |
| 56 | `equals2_swf7` | 926 | 5.8s |  |
| 57 | `equals_swf4` | 665 | 4.5s |  |
| 58 | `equals_swf4_alt` | 32 | 4.0s |  |
| 59 | `equals_swf5` | 32 | 4.0s |  |
| 60 | `error` | 58 | 4.1s |  |
| 61 | `escape` | 14 | 4.1s |  |
| 62 | `execution_order1` | 5 | 4.2s |  |
| 63 | `execution_order2` | 7 | 4.2s |  |
| 64 | `execution_order3` | 4 | 4.1s |  |
| 65 | `focusrect_mouse_swf8` | 0 | 4.1s |  |
| 66 | `focusrect_mouse_swf9` | 0 | 4.1s |  |
| 67 | `focusrect_swf5` | 6 | 4.2s |  |
| 68 | `getproperty` | 28 | 4.2s |  |
| 69 | `getproperty_swf4` | 28 | 4.1s |  |
| 70 | `getproperty_swf5` | 28 | 4.1s |  |
| 71 | `global_array` | 3 | 4.2s |  |
| 72 | `global_is_bare` | 7 | 4.2s |  |
| 73 | `globals_swf6` | 304 | 4.5s |  |
| 74 | `globals_swf7` | 304 | 4.5s |  |
| 75 | `globals_swf8` | 304 | 4.5s |  |
| 76 | `goto_advance1` | 6 | 4.2s |  |
| 77 | `goto_advance2` | 2 | 4.3s |  |
| 78 | `goto_both_ways1` | 3 | 4.2s |  |
| 79 | `goto_both_ways2` | 3 | 4.1s |  |
| 80 | `goto_execution_order` | 2 | 4.1s |  |
| 81 | `goto_execution_order2` | 2 | 4.1s |  |
| 82 | `goto_frame_number` | 3 | 4.2s |  |
| 83 | `goto_rewind1` | 1 | 4.2s |  |
| 84 | `goto_rewind2` | 3 | 4.2s |  |
| 85 | `goto_rewind3` | 2 | 4.1s |  |
| 86 | `greater_swf6` | 1175 | 6.1s |  |
| 87 | `greater_swf7` | 1175 | 6.1s |  |
| 88 | `greaterthan_swf5` | 1 | 4.1s |  |
| 89 | `greaterthan_swf8` | 1 | 4.1s |  |
| 90 | `has_own_property` | 32 | 4.2s |  |
| 91 | `infinite_recursion_function` | 4 | 4.1s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 92 | `infinite_recursion_function_in_setter` | 131 | 4.1s |  |
| 93 | `infinite_recursion_virtual_property` | 67 | 4.1s |  |
| 94 | `init_array_invalid` | 4 | 4.1s |  |
| 95 | `init_object_invalid` | 4 | 4.1s |  |
| 96 | `is_finite` | 49 | 4.2s |  |
| 97 | `is_finite_swf6` | 49 | 4.1s |  |
| 98 | `issue_1086` | 1 | 4.0s |  |
| 99 | `issue_1671` | 0 | 4.1s |  |
| 100 | `issue_2166` | 9 | 4.1s |  |
| 101 | `issue_3446` | 1 | 4.1s |  |
| 102 | `issue_4377` | 2 | 4.1s |  |
| 103 | `issue_710` | 4 | 4.0s |  |
| 104 | `issue_768` | 3 | 4.1s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 105 | `lessthan` | 41 | 4.2s |  |
| 106 | `lessthan2_swf5` | 1226 | 6.2s |  |
| 107 | `lessthan2_swf6` | 1226 | 6.2s |  |
| 108 | `lessthan2_swf7` | 1226 | 6.2s |  |
| 109 | `lessthan_swf4` | 902 | 4.7s |  |
| 110 | `lessthan_swf4_alt` | 41 | 4.0s |  |
| 111 | `lessthan_swf5` | 41 | 4.0s |  |
| 112 | `logical_ops_swf4` | 90 | 4.0s |  |
| 113 | `logical_ops_swf8` | 108 | 4.1s |  |
| 114 | `looping` | 6 | 4.1s |  |
| 115 | `mask_reapply` | 0 | 4.1s |  |
| 116 | `mask_with_drawing` | 0 | 4.1s |  |
| 117 | `math_min_max` | 101 | 4.2s |  |
| 118 | `mouse_wheel_enabled` | 2 | 4.1s |  |
| 119 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 120 | `movieclip_blend_mode_property` | 35 | 4.2s |  |
| 121 | `movieclip_default_state` | 69 | 4.3s |  |
| 122 | `movieclip_line_gradient_style` | 0 | 4.5s |  |
| 123 | `movieclip_name_from_timeline` | 13 | 4.1s |  |
| 124 | `movieclip_prototype_extension` | 5 | 4.0s |  |
| 125 | `nested_textfields_in_buttons` | 0 | 4.1s |  |
| 126 | `netstream_play_flv_screen` | 0 | 16.8s |  |
| 127 | `new_method_wrap` | 4 | 4.1s |  |
| 128 | `new_object_wrap` | 4 | 4.1s |  |
| 129 | `o` | 3 | 4.1s |  |
| 130 | `object_constructor` | 33 | 4.1s |  |
| 131 | `object_function` | 32 | 4.1s |  |
| 132 | `object_string_coerce_swf5` | 62 | 4.1s |  |
| 133 | `primitive_instanceof` | 37 | 4.1s |  |
| 134 | `prototype_delete` | 12 | 4.1s |  |
| 135 | `recursive_prototypes` | 0 | 4.0s |  |
| 136 | `sandbox_type_local_file` | 1 | 4.1s |  |
| 137 | `set_variable_scope` | 58 | 4.2s |  |
| 138 | `single_frame` | 1 | 4.1s |  |
| 139 | `sound_start_load` | 0 | 4.2s |  |
| 140 | `stage_object_properties_get_var` | 5 | 4.1s |  |
| 141 | `strictequals_swf6` | 902 | 5.6s |  |
| 142 | `strictly_equals` | 7 | 4.2s |  |
| 143 | `string_coercion` | 117 | 4.4s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 144 | `string_methods_negative_args` | 240 | 4.2s |  |
| 145 | `string_methods_swfv5` | 275 | 4.7s |  |
| 146 | `string_paths_keyevents` | 0 | 4.1s |  |
| 147 | `string_paths_timer` | 0 | 4.2s |  |
| 148 | `swf4_actions_bool` | 96 | 4.1s |  |
| 149 | `swf4_bool` | 4 | 4.1s |  |
| 150 | `swf5_encoding` | 3 | 4.0s |  |
| 151 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.1s |  |
| 152 | `text_format` | 1146 | 4.4s |  |
| 153 | `text_format_display` | 21 | 4.2s |  |
| 154 | `text_format_font_max_length` | 2 | 4.1s |  |
| 155 | `text_format_rounding_swf7` | 840 | 4.2s |  |
| 156 | `text_format_rounding_swf8` | 840 | 4.3s |  |
| 157 | `textfield_background_color` | 11 | 4.1s |  |
| 158 | `textfield_border_color` | 11 | 4.1s |  |
| 159 | `textfield_maxchars` | 3 | 4.2s |  |
| 160 | `textfield_properties` | 44 | 4.2s |  |
| 161 | `textfield_text` | 7 | 4.1s |  |
| 162 | `textfield_variable` | 81 | 4.3s |  |
| 163 | `this_swf7` | 41 | 4.1s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 164 | `timeline_function_def` | 7 | 4.2s |  |
| 165 | `try_finally_simple` | 16 | 4.2s |  |
| 166 | `typeof` | 22 | 4.3s |  |
| 167 | `typeof_globals` | 7 | 4.1s |  |
| 168 | `uncaught_exception` | 1 | 4.1s |  |
| 169 | `uncaught_exception_bubbled` | 1 | 4.1s |  |
| 170 | `undefined_to_string_swf6` | 4 | 4.1s |  |
| 171 | `unescape` | 43 | 4.2s |  |
| 172 | `use_hand_cursor` | 8 | 4.1s |  |
| 173 | `variable_args` | 5 | 4.2s |  |
| 174 | `waitforframe` | 7 | 4.1s |  |
| 175 | `waitforframe2` | 16 | 4.1s |  |
| 176 | `with_return` | 2 | 4.1s |  |
| 177 | `xml` | 15 | 4.2s |  |
| 178 | `xml_append_child` | 28 | 4.1s |  |
| 179 | `xml_append_child_with_parent` | 20 | 4.1s |  |
| 180 | `xml_attributes_read` | 4 | 4.1s |  |
| 181 | `xml_cdata` | 11 | 4.1s |  |
| 182 | `xml_clone_expandos` | 19 | 4.1s |  |
| 183 | `xml_first_last_child` | 8 | 4.1s |  |
| 184 | `xml_has_child_nodes` | 3 | 4.1s |  |
| 185 | `xml_idmap` | 21 | 4.2s |  |
| 186 | `xml_ignore_comments` | 21 | 4.2s |  |
| 187 | `xml_ignore_white` | 34 | 4.2s |  |
| 188 | `xml_insert_before` | 20 | 4.1s |  |
| 189 | `xml_inspect_createmethods` | 15 | 4.2s |  |
| 190 | `xml_inspect_doctype` | 7 | 4.1s |  |
| 191 | `xml_inspect_parsexml` | 62 | 4.2s |  |
| 192 | `xml_inspect_xmldecl` | 7 | 4.1s |  |
| 193 | `xml_namespaces` | 203 | 4.2s |  |
| 194 | `xml_parent_and_child` | 5 | 4.1s |  |
| 195 | `xml_remove_node` | 22 | 4.1s |  |
| 196 | `xml_reparenting` | 14 | 4.2s |  |
| 197 | `xml_siblings` | 10 | 4.1s |  |
| 198 | `xml_to_string_comment` | 1 | 4.1s |  |
| 199 | `xml_unescaping` | 23 | 4.2s |  |
| 200 | `xmlnode_proto` | 1 | 4.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**106 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_methods` | 99.3% | 283 | 285 | 2 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208 | 210 | 2 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208 | 210 | 2 |  |
| 5 | `math_swf6` | 98.5% | 522 | 530 | 8 |  |
| 6 | `math_swf7` | 98.5% | 522 | 530 | 8 |  |
| 7 | `math_swf8` | 98.5% | 522 | 530 | 8 |  |
| 8 | `globals_swf5` | 95.4% | 290 | 304 | 14 |  |
| 9 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 10 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 11 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 12 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 13 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 14 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 15 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 16 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 17 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 18 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 19 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 20 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 21 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 22 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 23 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 24 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 25 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 26 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 28 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 30 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 31 | `array_sort` | 72.7% | 117 | 161 | 44 |  |
| 32 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 33 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 34 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 35 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 36 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 37 | `point` | 70.9% | 124 | 175 | 51 |  |
| 38 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 39 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 40 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 41 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 42 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 43 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 44 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 45 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 46 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 47 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 48 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 49 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 50 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 51 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 52 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 53 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 54 | `sound_props_swf5` | 65.2% | 45 | 69 | 24 |  |
| 55 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 56 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 57 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 58 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 59 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 60 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 61 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 62 | `with` | 61.2% | 30 | 49 | 19 |  |
| 63 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 64 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 65 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 67 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 68 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 69 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 70 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 71 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 72 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 73 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 74 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 75 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 76 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 77 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 78 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 79 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 80 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 81 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 82 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 83 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 84 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 85 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 86 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 87 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 88 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 |  |
| 89 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 90 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 91 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 92 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 93 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 94 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 95 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 96 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 97 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 98 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 99 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 100 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 101 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 102 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 103 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 104 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 105 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 106 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**6 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `enumerate` | 6.1s |  |
| 2 | `function_base_clip_removed` | 6.2s |  |
| 3 | `goto_methods` | 6.3s |  |
| 4 | `init_object_order` | 6.2s |  |
| 5 | `register_and_init_order` | 6.5s |  |
| 6 | `register_class` | 6.3s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 14.3s |  |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 14.4s |  |

## All Output Mismatches

**411 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_methods` | 99.3% | 283/285 | 285 | 285 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208/210 | 210 | 210 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208/210 | 210 | 210 |  |
| 5 | `math_swf6` | 98.5% | 522/530 | 529 | 530 |  |
| 6 | `math_swf7` | 98.5% | 522/530 | 529 | 530 |  |
| 7 | `math_swf8` | 98.5% | 522/530 | 529 | 530 |  |
| 8 | `globals_swf5` | 95.4% | 290/304 | 304 | 304 |  |
| 9 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 10 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 11 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 12 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 13 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 14 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 15 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 16 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 17 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 18 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 19 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 20 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 21 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 22 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 23 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 24 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 25 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 26 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 28 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 30 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 31 | `array_sort` | 72.7% | 117/161 | 161 | 161 |  |
| 32 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 33 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 34 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 35 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 36 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 37 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 38 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 39 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 40 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 41 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 42 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 43 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 44 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 45 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 46 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 47 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 48 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 49 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 50 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 51 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 52 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 53 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 54 | `sound_props_swf5` | 65.2% | 45/69 | 69 | 68 |  |
| 55 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 56 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 57 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 58 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 59 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 60 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 61 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 62 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 63 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 64 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 65 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 66 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 67 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 68 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 69 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 70 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 71 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 72 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 73 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 74 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 75 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 76 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 77 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 78 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 79 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 80 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 81 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 82 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 83 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 84 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 85 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 86 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 87 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 88 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 |  |
| 89 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 90 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 91 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 92 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 93 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 94 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 95 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 96 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 97 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 98 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 99 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 100 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 101 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 102 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 103 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 104 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 105 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 106 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 107 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 108 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 |  |
| 109 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 |  |
| 110 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 111 | `sound_props_swf6` | 44.9% | 31/69 | 69 | 68 |  |
| 112 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 113 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 114 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 115 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 |  |
| 116 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 117 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 118 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 119 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 120 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 121 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 122 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 123 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 124 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 125 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 126 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 127 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 128 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 129 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 130 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 |  |
| 131 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 132 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 133 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 134 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 135 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 136 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 137 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 138 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 139 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 140 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 141 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 142 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 143 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 144 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 145 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 146 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 147 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 148 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 39 | 56 |  |
| 149 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 150 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 151 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 152 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 153 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 154 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 155 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 156 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 157 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 158 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 159 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 160 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 161 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 162 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 163 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 164 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 165 | `color_transform` | 14.6% | 7/48 | 38 | 48 |  |
| 166 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 167 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 168 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 169 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 170 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 171 | `focusrect_property_swf7` | 13.7% | 169/1237 | 276 | 1237 |  |
| 172 | `focusrect_property_swf6` | 13.6% | 168/1237 | 276 | 1237 |  |
| 173 | `printjob_props_swf5` | 13.3% | 6/45 | 36 | 45 |  |
| 174 | `printjob_props_swf6` | 13.3% | 6/45 | 36 | 45 |  |
| 175 | `printjob_props_swf7` | 13.3% | 6/45 | 36 | 45 |  |
| 176 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 177 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 178 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 179 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 180 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 181 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 182 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 183 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 184 | `xml_socket` | 12.5% | 1/8 | 1 | 8 |  |
| 185 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 186 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 187 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 188 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 189 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 190 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 39 | 56 |  |
| 191 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 192 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 193 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 194 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 195 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 196 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 197 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 198 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 199 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 200 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 201 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 202 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 203 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 204 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 205 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 206 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 207 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 208 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 209 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 210 | `bitmap_data_pixeldissolve` | 6.3% | 68/1075 | 1055 | 1075 |  |
| 211 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 212 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 213 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 214 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 215 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 216 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 217 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 218 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 219 | `context_menu` | 5.1% | 2/39 | 14 | 39 |  |
| 220 | `context_menu_item` | 4.9% | 2/41 | 10 | 41 |  |
| 221 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 222 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 223 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 224 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 225 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 226 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 227 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 228 | `focusrect_property_swf5` | 3.5% | 43/1237 | 276 | 1237 |  |
| 229 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 230 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 231 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 232 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 233 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 234 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 235 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 236 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 237 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 238 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 239 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 240 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 241 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 242 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 243 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 244 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 245 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 246 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 247 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 248 | `global_proto_decls` | 0.2% | 9/4497 | 249 | 4497 |  |
| 249 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 250 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 251 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 252 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 253 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 255 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 256 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 257 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 258 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 259 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 260 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 261 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 262 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 263 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 264 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 265 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 266 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 267 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 268 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 269 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 270 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 271 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 272 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 273 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 274 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 275 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 276 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 277 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 278 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 279 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 280 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 281 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 282 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 283 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 284 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 285 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 286 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 287 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 288 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 289 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 290 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 291 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 292 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 293 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 294 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 295 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 296 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 297 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 298 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 299 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 300 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 301 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 302 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 303 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 304 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 305 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 306 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 307 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 308 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 309 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 310 | `global_proto_decls_delete` | 0.0% | 0/4158 | 114 | 4158 |  |
| 311 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 312 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 313 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 314 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 315 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 316 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 317 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 318 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 319 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 320 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 321 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 322 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 323 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 324 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 325 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 326 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 327 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 328 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 329 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 330 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 331 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 332 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 333 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 335 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 336 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 337 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 338 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 339 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 340 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 341 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 342 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 343 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 344 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 345 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 346 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 347 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 348 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 349 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 350 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 351 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 352 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 353 | `native_objects_swf8` | 0.0% | 0/188 | 188 | 84 |  |
| 354 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 355 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 356 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 357 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 358 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 359 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 360 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 361 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 362 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 363 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 364 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 365 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 366 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 367 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 368 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 369 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 370 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 371 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 372 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 373 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 374 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 375 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 376 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 377 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 378 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 379 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 380 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 381 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 382 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 383 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 384 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 385 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 386 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 387 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 388 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 389 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 390 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 391 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 392 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 393 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 394 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 395 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 396 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 397 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 398 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 399 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 400 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 401 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 402 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 403 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 404 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 405 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 406 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 407 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 408 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 409 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 410 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 411 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
