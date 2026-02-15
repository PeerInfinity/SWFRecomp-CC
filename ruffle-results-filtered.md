# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 22:16 UTC

**Git SHA**: `b4d13aa356`

**Run Duration**: 50m 2s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **203** (42.1%) |
| Failing | 279 |
| Total expected lines | 77928 |
| Matching lines | 44199 (56.7%) |
| Mismatched lines | 33729 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 271 | 97.1% |
| Segfault | 7 | 2.5% |
| Timeout | 1 | 0.4% |

## Passing Tests

**203 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.9s |  |
| 2 | `action_to_integer` | 28 | 4.8s |  |
| 3 | `add` | 28 | 4.7s |  |
| 4 | `add2` | 354 | 4.9s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.2s |  |
| 6 | `add_swf5` | 28 | 4.2s |  |
| 7 | `array_concat` | 98 | 4.7s |  |
| 8 | `array_constructor` | 30 | 4.7s |  |
| 9 | `array_length` | 42 | 4.3s |  |
| 10 | `array_properties` | 36 | 4.7s |  |
| 11 | `array_slice` | 34 | 4.7s |  |
| 12 | `array_splice` | 207 | 4.9s |  |
| 13 | `array_trivial` | 209 | 4.4s |  |
| 14 | `as1_constructor_v6` | 35 | 4.2s |  |
| 15 | `as1_constructor_v7` | 35 | 4.2s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.6s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 4.2s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.2s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.2s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.7s |  |
| 22 | `as_transformed_flag` | 20 | 4.7s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 4.6s |  |
| 24 | `bitand` | 1058 | 6.9s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.9s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.8s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 4.7s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 4.7s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 5.2s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 5.1s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.7s |  |
| 32 | `bitor` | 1058 | 7.0s |  |
| 33 | `biturshift` | 14 | 5.0s |  |
| 34 | `biturshift_swf8` | 14 | 4.6s |  |
| 35 | `bitxor` | 1058 | 6.6s |  |
| 36 | `call_method_empty_name` | 1 | 4.5s |  |
| 37 | `capabilities_resolution` | 8 | 4.5s |  |
| 38 | `catch_references_registers` | 2 | 4.6s |  |
| 39 | `conflicting_instance_names` | 23 | 4.7s |  |
| 40 | `define_function2` | 8 | 4.6s |  |
| 41 | `define_function2_preload` | 13 | 4.6s |  |
| 42 | `define_function2_preload_order` | 4 | 4.1s |  |
| 43 | `define_function_case_sensitive` | 2 | 4.5s |  |
| 44 | `delete` | 3 | 4.2s |  |
| 45 | `display_object_properties` | 2 | 4.5s |  |
| 46 | `do_init_action` | 3 | 4.6s |  |
| 47 | `edittext_antialiastype` | 296 | 4.9s |  |
| 48 | `edittext_autosize_setter` | 20 | 4.1s |  |
| 49 | `edittext_default_format` | 221 | 4.7s |  |
| 50 | `edittext_default_format_empty` | 95 | 4.6s |  |
| 51 | `edittext_default_format_font_style` | 335 | 4.6s |  |
| 52 | `equals` | 32 | 4.7s |  |
| 53 | `equals2_swf5` | 926 | 5.7s |  |
| 54 | `equals2_swf6` | 926 | 5.7s |  |
| 55 | `equals2_swf7` | 926 | 5.8s |  |
| 56 | `equals_swf4` | 665 | 4.5s |  |
| 57 | `equals_swf4_alt` | 32 | 4.1s |  |
| 58 | `equals_swf5` | 32 | 4.1s |  |
| 59 | `error` | 58 | 4.6s |  |
| 60 | `escape` | 14 | 4.5s |  |
| 61 | `execution_order1` | 5 | 4.6s |  |
| 62 | `execution_order2` | 7 | 4.6s |  |
| 63 | `execution_order3` | 4 | 4.6s |  |
| 64 | `focusrect_mouse_swf8` | 0 | 4.7s |  |
| 65 | `focusrect_mouse_swf9` | 0 | 4.6s |  |
| 66 | `focusrect_swf5` | 6 | 4.3s |  |
| 67 | `getproperty` | 28 | 5.2s |  |
| 68 | `getproperty_swf4` | 28 | 4.4s |  |
| 69 | `getproperty_swf5` | 28 | 4.2s |  |
| 70 | `global_array` | 3 | 5.0s |  |
| 71 | `global_is_bare` | 7 | 5.2s |  |
| 72 | `globals_swf6` | 304 | 4.8s |  |
| 73 | `globals_swf7` | 304 | 4.8s |  |
| 74 | `globals_swf8` | 304 | 5.4s |  |
| 75 | `goto_advance1` | 6 | 5.0s |  |
| 76 | `goto_advance2` | 2 | 5.0s |  |
| 77 | `goto_both_ways1` | 3 | 4.5s |  |
| 78 | `goto_both_ways2` | 3 | 4.2s |  |
| 79 | `goto_execution_order` | 2 | 4.5s |  |
| 80 | `goto_execution_order2` | 2 | 4.6s |  |
| 81 | `goto_frame_number` | 3 | 4.6s |  |
| 82 | `goto_rewind1` | 1 | 4.8s |  |
| 83 | `goto_rewind2` | 3 | 5.0s |  |
| 84 | `goto_rewind3` | 2 | 4.2s |  |
| 85 | `greater_swf6` | 1175 | 6.1s |  |
| 86 | `greater_swf7` | 1175 | 6.2s |  |
| 87 | `greaterthan_swf5` | 1 | 4.2s |  |
| 88 | `greaterthan_swf8` | 1 | 4.6s |  |
| 89 | `has_own_property` | 32 | 4.2s |  |
| 90 | `infinite_recursion_function` | 4 | 4.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 91 | `infinite_recursion_function_in_setter` | 131 | 4.6s |  |
| 92 | `infinite_recursion_virtual_property` | 67 | 4.6s |  |
| 93 | `init_array_invalid` | 4 | 4.5s |  |
| 94 | `init_object_invalid` | 4 | 4.5s |  |
| 95 | `is_finite` | 49 | 4.6s |  |
| 96 | `is_finite_swf6` | 49 | 4.2s |  |
| 97 | `issue_1086` | 1 | 4.1s |  |
| 98 | `issue_1671` | 0 | 4.5s |  |
| 99 | `issue_2166` | 9 | 4.2s |  |
| 100 | `issue_3446` | 1 | 4.6s |  |
| 101 | `issue_4377` | 2 | 4.6s |  |
| 102 | `issue_710` | 4 | 4.1s |  |
| 103 | `issue_768` | 3 | 4.7s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 104 | `lessthan` | 41 | 4.7s |  |
| 105 | `lessthan2_swf5` | 1226 | 6.4s |  |
| 106 | `lessthan2_swf6` | 1226 | 6.5s |  |
| 107 | `lessthan2_swf7` | 1226 | 6.4s |  |
| 108 | `lessthan_swf4` | 902 | 4.9s |  |
| 109 | `lessthan_swf4_alt` | 41 | 4.2s |  |
| 110 | `lessthan_swf5` | 41 | 4.2s |  |
| 111 | `logical_ops_swf4` | 90 | 4.2s |  |
| 112 | `logical_ops_swf8` | 108 | 4.7s |  |
| 113 | `looping` | 6 | 4.6s |  |
| 114 | `mask_reapply` | 0 | 4.6s |  |
| 115 | `mask_with_drawing` | 0 | 4.7s |  |
| 116 | `math_min_max` | 101 | 4.9s |  |
| 117 | `matrix` | 171 | 5.0s |  |
| 118 | `movieclip_begin_gradient_fill` | 0 | 5.1s |  |
| 119 | `movieclip_blend_mode_property` | 35 | 4.7s |  |
| 120 | `movieclip_default_state` | 69 | 4.8s |  |
| 121 | `movieclip_line_gradient_style` | 0 | 5.3s |  |
| 122 | `movieclip_name_from_timeline` | 13 | 4.9s |  |
| 123 | `movieclip_prototype_extension` | 5 | 4.3s |  |
| 124 | `nested_textfields_in_buttons` | 0 | 4.7s |  |
| 125 | `netstream_play_flv_screen` | 0 | 17.6s |  |
| 126 | `new_method_wrap` | 4 | 4.7s |  |
| 127 | `new_object_wrap` | 4 | 4.6s |  |
| 128 | `o` | 3 | 4.6s |  |
| 129 | `object_constructor` | 33 | 4.7s |  |
| 130 | `object_function` | 32 | 4.6s |  |
| 131 | `object_string_coerce_swf5` | 62 | 4.2s |  |
| 132 | `point` | 175 | 5.0s |  |
| 133 | `primitive_instanceof` | 37 | 4.6s |  |
| 134 | `prototype_delete` | 12 | 4.7s |  |
| 135 | `rectangle` | 745 | 5.4s |  |
| 136 | `recursive_prototypes` | 0 | 4.2s |  |
| 137 | `sandbox_type_local_file` | 1 | 4.3s |  |
| 138 | `set_variable_scope` | 58 | 4.8s |  |
| 139 | `single_frame` | 1 | 4.7s |  |
| 140 | `sound_start_load` | 0 | 4.8s |  |
| 141 | `stage_object_properties_get_var` | 5 | 4.8s |  |
| 142 | `strictequals_swf6` | 902 | 6.0s |  |
| 143 | `strictly_equals` | 7 | 4.7s |  |
| 144 | `string_coercion` | 117 | 4.6s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 145 | `string_methods` | 285 | 5.3s |  |
| 146 | `string_methods_negative_args` | 240 | 4.4s |  |
| 147 | `string_methods_swfv5` | 275 | 4.9s |  |
| 148 | `string_ops_swf6` | 95 | 4.8s |  |
| 149 | `string_paths_keyevents` | 0 | 4.7s |  |
| 150 | `string_paths_timer` | 0 | 4.7s |  |
| 151 | `swf4_actions_bool` | 96 | 4.4s |  |
| 152 | `swf4_bool` | 4 | 4.3s |  |
| 153 | `swf5_encoding` | 3 | 4.2s |  |
| 154 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.6s |  |
| 155 | `text_format` | 1146 | 4.9s |  |
| 156 | `text_format_display` | 21 | 4.7s |  |
| 157 | `text_format_font_max_length` | 2 | 4.6s |  |
| 158 | `text_format_rounding_swf7` | 840 | 4.3s |  |
| 159 | `text_format_rounding_swf8` | 840 | 4.8s |  |
| 160 | `textfield_background_color` | 11 | 4.6s |  |
| 161 | `textfield_border_color` | 11 | 4.6s |  |
| 162 | `textfield_maxchars` | 3 | 4.6s |  |
| 163 | `textfield_properties` | 44 | 4.7s |  |
| 164 | `textfield_text` | 7 | 4.6s |  |
| 165 | `textfield_variable` | 81 | 4.4s |  |
| 166 | `this_swf7` | 41 | 4.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 167 | `timeline_function_def` | 7 | 4.3s |  |
| 168 | `try_finally_simple` | 16 | 4.8s |  |
| 169 | `typeof` | 22 | 4.8s |  |
| 170 | `typeof_globals` | 7 | 4.2s |  |
| 171 | `uncaught_exception` | 1 | 4.8s |  |
| 172 | `uncaught_exception_bubbled` | 1 | 4.7s |  |
| 173 | `undefined_to_string_swf6` | 4 | 4.2s |  |
| 174 | `unescape` | 43 | 4.8s |  |
| 175 | `use_hand_cursor` | 8 | 4.8s |  |
| 176 | `variable_args` | 5 | 4.4s |  |
| 177 | `waitforframe` | 7 | 4.3s |  |
| 178 | `waitforframe2` | 16 | 4.4s |  |
| 179 | `with_return` | 2 | 4.8s |  |
| 180 | `xml` | 15 | 4.9s |  |
| 181 | `xml_append_child` | 28 | 4.8s |  |
| 182 | `xml_append_child_with_parent` | 20 | 4.3s |  |
| 183 | `xml_attributes_read` | 4 | 4.8s |  |
| 184 | `xml_cdata` | 11 | 4.8s |  |
| 185 | `xml_clone_expandos` | 19 | 4.7s |  |
| 186 | `xml_first_last_child` | 8 | 4.8s |  |
| 187 | `xml_has_child_nodes` | 3 | 4.8s |  |
| 188 | `xml_idmap` | 21 | 5.0s |  |
| 189 | `xml_ignore_comments` | 21 | 4.8s |  |
| 190 | `xml_ignore_white` | 34 | 4.8s |  |
| 191 | `xml_insert_before` | 20 | 4.3s |  |
| 192 | `xml_inspect_createmethods` | 15 | 4.4s |  |
| 193 | `xml_inspect_doctype` | 7 | 4.3s |  |
| 194 | `xml_inspect_parsexml` | 62 | 4.4s |  |
| 195 | `xml_inspect_xmldecl` | 7 | 4.3s |  |
| 196 | `xml_namespaces` | 203 | 4.7s |  |
| 197 | `xml_parent_and_child` | 5 | 4.7s |  |
| 198 | `xml_remove_node` | 22 | 4.3s |  |
| 199 | `xml_reparenting` | 14 | 4.3s |  |
| 200 | `xml_siblings` | 10 | 4.7s |  |
| 201 | `xml_to_string_comment` | 1 | 5.2s |  |
| 202 | `xml_unescaping` | 23 | 4.5s |  |
| 203 | `xmlnode_proto` | 1 | 5.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**91 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 |  |
| 2 | `textfield_props_swf7` | 99.0% | 208 | 210 | 2 |  |
| 3 | `textfield_props_swf8` | 99.0% | 208 | 210 | 2 |  |
| 4 | `math_swf6` | 98.5% | 522 | 530 | 8 |  |
| 5 | `math_swf7` | 98.5% | 522 | 530 | 8 |  |
| 6 | `math_swf8` | 98.5% | 522 | 530 | 8 |  |
| 7 | `globals_swf5` | 95.4% | 290 | 304 | 14 |  |
| 8 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 10 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 11 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 12 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 13 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 14 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 15 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 16 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 17 | `arguments` | 83.5% | 106 | 127 | 21 |  |
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
| 32 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 33 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 34 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 35 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 36 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 37 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 38 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 39 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 40 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 41 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 42 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 43 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 44 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 45 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 46 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 47 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 48 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 49 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 50 | `sound_props_swf5` | 65.2% | 45 | 69 | 24 |  |
| 51 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 52 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 53 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 54 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 55 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 56 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 57 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 58 | `color` | 61.4% | 35 | 57 | 22 |  |
| 59 | `with` | 61.2% | 30 | 49 | 19 |  |
| 60 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 61 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 62 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 63 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 64 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 65 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 66 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 67 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 68 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 69 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 70 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 71 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 72 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 73 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 74 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 75 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 76 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 77 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 78 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 79 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 |  |
| 80 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 81 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 82 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 84 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 85 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 86 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 87 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 88 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 89 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 90 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**7 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `enumerate` | 6.1s |  |
| 2 | `function_base_clip_removed` | 6.7s |  |
| 3 | `goto_methods` | 6.8s |  |
| 4 | `init_object_order` | 6.8s |  |
| 5 | `register_and_init_order` | 7.1s |  |
| 6 | `register_class` | 7.1s |  |
| 7 | `try_catch_finally` | 11.7s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 14.8s |  |

## All Output Mismatches

**271 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 |  |
| 2 | `textfield_props_swf7` | 99.0% | 208/210 | 210 | 210 |  |
| 3 | `textfield_props_swf8` | 99.0% | 208/210 | 210 | 210 |  |
| 4 | `math_swf6` | 98.5% | 522/530 | 529 | 530 |  |
| 5 | `math_swf7` | 98.5% | 522/530 | 529 | 530 |  |
| 6 | `math_swf8` | 98.5% | 522/530 | 529 | 530 |  |
| 7 | `globals_swf5` | 95.4% | 290/304 | 304 | 304 |  |
| 8 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 9 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 10 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 11 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 12 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 13 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 14 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 15 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 16 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 17 | `arguments` | 83.5% | 106/127 | 127 | 127 |  |
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
| 32 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 33 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 34 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 35 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 36 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 37 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 38 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 39 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 40 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 41 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 42 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 43 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 44 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 45 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 46 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 47 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 48 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 49 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 50 | `sound_props_swf5` | 65.2% | 45/69 | 69 | 68 |  |
| 51 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 52 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 53 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 54 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 55 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 56 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 57 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 58 | `color` | 61.4% | 35/57 | 57 | 57 |  |
| 59 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 60 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 61 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 62 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 63 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 64 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 65 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 66 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 67 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 68 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 69 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 70 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 71 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 72 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 73 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 74 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 75 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 76 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 77 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 78 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 79 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 |  |
| 80 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 81 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 82 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 84 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 85 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 86 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 87 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 88 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 90 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 91 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 92 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 93 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 |  |
| 94 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 |  |
| 95 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 96 | `sound_props_swf6` | 44.9% | 31/69 | 69 | 68 |  |
| 97 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 98 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 |  |
| 99 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 100 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 101 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 |  |
| 102 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 103 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 104 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 105 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 106 | `define_local_with_paths` | 38.9% | 21/54 | 37 | 54 |  |
| 107 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 108 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 109 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 110 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 111 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 112 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 113 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 114 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 115 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 |  |
| 116 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 117 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 118 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 119 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 120 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 121 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 122 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 123 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 124 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 125 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 126 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 127 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 128 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 39 | 56 |  |
| 129 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 130 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 131 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 132 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 133 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 134 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 135 | `set_interval` | 18.5% | 5/27 | 17 | 27 |  |
| 136 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 137 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 138 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 139 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 140 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 141 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 142 | `color_transform` | 14.6% | 7/48 | 38 | 48 |  |
| 143 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 144 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 145 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 146 | `printjob_props_swf5` | 13.3% | 6/45 | 36 | 45 |  |
| 147 | `printjob_props_swf6` | 13.3% | 6/45 | 36 | 45 |  |
| 148 | `printjob_props_swf7` | 13.3% | 6/45 | 36 | 45 |  |
| 149 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 150 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 151 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 152 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 153 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 154 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 155 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 156 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 157 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 39 | 56 |  |
| 158 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 159 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 160 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 161 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 162 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 163 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 164 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 165 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 166 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 167 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 168 | `define_local` | 7.4% | 2/27 | 23 | 27 |  |
| 169 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 170 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 171 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 172 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 173 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 174 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 175 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 |  |
| 176 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 177 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 178 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 179 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 180 | `context_menu` | 5.1% | 2/39 | 14 | 39 |  |
| 181 | `context_menu_item` | 4.9% | 2/41 | 10 | 41 |  |
| 182 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 183 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 184 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 185 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 186 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 187 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 188 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 189 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 190 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 191 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 192 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 193 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 194 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 195 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 196 | `global_instance_decls` | 0.3% | 2/758 | 279 | 758 |  |
| 197 | `global_proto_decls` | 0.2% | 9/4497 | 249 | 4497 |  |
| 198 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 199 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 200 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 201 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 202 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 204 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 205 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 206 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 207 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 208 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 209 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 210 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 211 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 212 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 213 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 214 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 215 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 216 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 217 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 218 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 219 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 220 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 221 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 222 | `global_proto_decls_delete` | 0.0% | 0/4158 | 114 | 4158 |  |
| 223 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 224 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 225 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 226 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 227 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 228 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 229 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 230 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 231 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 233 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 234 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 235 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 236 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 237 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 |  |
| 238 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 240 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 241 | `native_objects_swf8` | 0.0% | 0/196 | 196 | 84 |  |
| 242 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 243 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 244 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 245 | `parse_int` | 0.0% | 0/64 | 64 | 64 |  |
| 246 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 247 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 248 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 249 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 250 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 251 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 252 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 253 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 254 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 255 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 256 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 257 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 259 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 261 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 262 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 263 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 264 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 265 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 266 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 267 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 269 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 270 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 271 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
