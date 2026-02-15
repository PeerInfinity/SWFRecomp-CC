# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 20:56 UTC

**Git SHA**: `06244c7b7d`

**Run Duration**: 45m 28s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **198** (41.1%) |
| Failing | 284 |
| Total expected lines | 77810 |
| Matching lines | 43645 (56.1%) |
| Mismatched lines | 34165 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 276 | 97.2% |
| Segfault | 6 | 2.1% |
| Timeout | 2 | 0.7% |

## Passing Tests

**198 tests passing**

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
| 52 | `equals` | 32 | 4.2s |  |
| 53 | `equals2_swf5` | 926 | 5.9s |  |
| 54 | `equals2_swf6` | 926 | 5.8s |  |
| 55 | `equals2_swf7` | 926 | 5.8s |  |
| 56 | `equals_swf4` | 665 | 4.5s |  |
| 57 | `equals_swf4_alt` | 32 | 4.0s |  |
| 58 | `equals_swf5` | 32 | 4.0s |  |
| 59 | `error` | 58 | 4.1s |  |
| 60 | `escape` | 14 | 4.1s |  |
| 61 | `execution_order1` | 5 | 4.2s |  |
| 62 | `execution_order2` | 7 | 4.2s |  |
| 63 | `execution_order3` | 4 | 4.1s |  |
| 64 | `focusrect_mouse_swf8` | 0 | 4.1s |  |
| 65 | `focusrect_mouse_swf9` | 0 | 4.1s |  |
| 66 | `focusrect_swf5` | 6 | 4.2s |  |
| 67 | `getproperty` | 28 | 4.2s |  |
| 68 | `getproperty_swf4` | 28 | 4.1s |  |
| 69 | `getproperty_swf5` | 28 | 4.1s |  |
| 70 | `global_array` | 3 | 4.2s |  |
| 71 | `global_is_bare` | 7 | 4.2s |  |
| 72 | `globals_swf6` | 304 | 4.5s |  |
| 73 | `globals_swf7` | 304 | 4.5s |  |
| 74 | `globals_swf8` | 304 | 4.5s |  |
| 75 | `goto_advance1` | 6 | 4.2s |  |
| 76 | `goto_advance2` | 2 | 4.3s |  |
| 77 | `goto_both_ways1` | 3 | 4.2s |  |
| 78 | `goto_both_ways2` | 3 | 4.1s |  |
| 79 | `goto_execution_order` | 2 | 4.1s |  |
| 80 | `goto_execution_order2` | 2 | 4.1s |  |
| 81 | `goto_frame_number` | 3 | 4.2s |  |
| 82 | `goto_rewind1` | 1 | 4.2s |  |
| 83 | `goto_rewind2` | 3 | 4.2s |  |
| 84 | `goto_rewind3` | 2 | 4.1s |  |
| 85 | `greater_swf6` | 1175 | 6.1s |  |
| 86 | `greater_swf7` | 1175 | 6.1s |  |
| 87 | `greaterthan_swf5` | 1 | 4.1s |  |
| 88 | `greaterthan_swf8` | 1 | 4.1s |  |
| 89 | `has_own_property` | 32 | 4.2s |  |
| 90 | `infinite_recursion_function` | 4 | 4.1s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 91 | `infinite_recursion_function_in_setter` | 131 | 4.1s |  |
| 92 | `infinite_recursion_virtual_property` | 67 | 4.1s |  |
| 93 | `init_array_invalid` | 4 | 4.1s |  |
| 94 | `init_object_invalid` | 4 | 4.1s |  |
| 95 | `is_finite` | 49 | 4.2s |  |
| 96 | `is_finite_swf6` | 49 | 4.1s |  |
| 97 | `issue_1086` | 1 | 4.0s |  |
| 98 | `issue_1671` | 0 | 4.1s |  |
| 99 | `issue_2166` | 9 | 4.1s |  |
| 100 | `issue_3446` | 1 | 4.1s |  |
| 101 | `issue_4377` | 2 | 4.1s |  |
| 102 | `issue_710` | 4 | 4.0s |  |
| 103 | `issue_768` | 3 | 4.1s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 104 | `lessthan` | 41 | 4.2s |  |
| 105 | `lessthan2_swf5` | 1226 | 6.2s |  |
| 106 | `lessthan2_swf6` | 1226 | 6.2s |  |
| 107 | `lessthan2_swf7` | 1226 | 6.2s |  |
| 108 | `lessthan_swf4` | 902 | 4.7s |  |
| 109 | `lessthan_swf4_alt` | 41 | 4.0s |  |
| 110 | `lessthan_swf5` | 41 | 4.0s |  |
| 111 | `logical_ops_swf4` | 90 | 4.0s |  |
| 112 | `logical_ops_swf8` | 108 | 4.1s |  |
| 113 | `looping` | 6 | 4.1s |  |
| 114 | `mask_reapply` | 0 | 4.1s |  |
| 115 | `mask_with_drawing` | 0 | 4.1s |  |
| 116 | `math_min_max` | 101 | 4.2s |  |
| 117 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 118 | `movieclip_blend_mode_property` | 35 | 4.2s |  |
| 119 | `movieclip_default_state` | 69 | 4.3s |  |
| 120 | `movieclip_line_gradient_style` | 0 | 4.5s |  |
| 121 | `movieclip_name_from_timeline` | 13 | 4.1s |  |
| 122 | `movieclip_prototype_extension` | 5 | 4.0s |  |
| 123 | `nested_textfields_in_buttons` | 0 | 4.1s |  |
| 124 | `netstream_play_flv_screen` | 0 | 16.8s |  |
| 125 | `new_method_wrap` | 4 | 4.1s |  |
| 126 | `new_object_wrap` | 4 | 4.1s |  |
| 127 | `o` | 3 | 4.1s |  |
| 128 | `object_constructor` | 33 | 4.1s |  |
| 129 | `object_function` | 32 | 4.1s |  |
| 130 | `object_string_coerce_swf5` | 62 | 4.1s |  |
| 131 | `primitive_instanceof` | 37 | 4.1s |  |
| 132 | `prototype_delete` | 12 | 4.1s |  |
| 133 | `recursive_prototypes` | 0 | 4.0s |  |
| 134 | `sandbox_type_local_file` | 1 | 4.1s |  |
| 135 | `set_variable_scope` | 58 | 4.2s |  |
| 136 | `single_frame` | 1 | 4.1s |  |
| 137 | `sound_start_load` | 0 | 4.2s |  |
| 138 | `stage_object_properties_get_var` | 5 | 4.1s |  |
| 139 | `strictequals_swf6` | 902 | 5.6s |  |
| 140 | `strictly_equals` | 7 | 4.2s |  |
| 141 | `string_coercion` | 117 | 4.4s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 142 | `string_methods_negative_args` | 240 | 4.2s |  |
| 143 | `string_methods_swfv5` | 275 | 4.7s |  |
| 144 | `string_paths_keyevents` | 0 | 4.1s |  |
| 145 | `string_paths_timer` | 0 | 4.2s |  |
| 146 | `swf4_actions_bool` | 96 | 4.1s |  |
| 147 | `swf4_bool` | 4 | 4.1s |  |
| 148 | `swf5_encoding` | 3 | 4.0s |  |
| 149 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.1s |  |
| 150 | `text_format` | 1146 | 4.4s |  |
| 151 | `text_format_display` | 21 | 4.2s |  |
| 152 | `text_format_font_max_length` | 2 | 4.1s |  |
| 153 | `text_format_rounding_swf7` | 840 | 4.2s |  |
| 154 | `text_format_rounding_swf8` | 840 | 4.3s |  |
| 155 | `textfield_background_color` | 11 | 4.1s |  |
| 156 | `textfield_border_color` | 11 | 4.1s |  |
| 157 | `textfield_maxchars` | 3 | 4.2s |  |
| 158 | `textfield_properties` | 44 | 4.2s |  |
| 159 | `textfield_text` | 7 | 4.1s |  |
| 160 | `textfield_variable` | 81 | 4.3s |  |
| 161 | `this_swf7` | 41 | 4.1s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 162 | `timeline_function_def` | 7 | 4.2s |  |
| 163 | `try_finally_simple` | 16 | 4.2s |  |
| 164 | `typeof` | 22 | 4.3s |  |
| 165 | `typeof_globals` | 7 | 4.1s |  |
| 166 | `uncaught_exception` | 1 | 4.1s |  |
| 167 | `uncaught_exception_bubbled` | 1 | 4.1s |  |
| 168 | `undefined_to_string_swf6` | 4 | 4.1s |  |
| 169 | `unescape` | 43 | 4.2s |  |
| 170 | `use_hand_cursor` | 8 | 4.1s |  |
| 171 | `variable_args` | 5 | 4.2s |  |
| 172 | `waitforframe` | 7 | 4.1s |  |
| 173 | `waitforframe2` | 16 | 4.1s |  |
| 174 | `with_return` | 2 | 4.1s |  |
| 175 | `xml` | 15 | 4.2s |  |
| 176 | `xml_append_child` | 28 | 4.1s |  |
| 177 | `xml_append_child_with_parent` | 20 | 4.1s |  |
| 178 | `xml_attributes_read` | 4 | 4.1s |  |
| 179 | `xml_cdata` | 11 | 4.1s |  |
| 180 | `xml_clone_expandos` | 19 | 4.1s |  |
| 181 | `xml_first_last_child` | 8 | 4.1s |  |
| 182 | `xml_has_child_nodes` | 3 | 4.1s |  |
| 183 | `xml_idmap` | 21 | 4.2s |  |
| 184 | `xml_ignore_comments` | 21 | 4.2s |  |
| 185 | `xml_ignore_white` | 34 | 4.2s |  |
| 186 | `xml_insert_before` | 20 | 4.1s |  |
| 187 | `xml_inspect_createmethods` | 15 | 4.2s |  |
| 188 | `xml_inspect_doctype` | 7 | 4.1s |  |
| 189 | `xml_inspect_parsexml` | 62 | 4.2s |  |
| 190 | `xml_inspect_xmldecl` | 7 | 4.1s |  |
| 191 | `xml_namespaces` | 203 | 4.2s |  |
| 192 | `xml_parent_and_child` | 5 | 4.1s |  |
| 193 | `xml_remove_node` | 22 | 4.1s |  |
| 194 | `xml_reparenting` | 14 | 4.2s |  |
| 195 | `xml_siblings` | 10 | 4.1s |  |
| 196 | `xml_to_string_comment` | 1 | 4.1s |  |
| 197 | `xml_unescaping` | 23 | 4.2s |  |
| 198 | `xmlnode_proto` | 1 | 4.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**94 tests** within reach

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
| 51 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 52 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 53 | `sound_props_swf5` | 65.2% | 45 | 69 | 24 |  |
| 54 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 55 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 56 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 57 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 58 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 59 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 60 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 61 | `with` | 61.2% | 30 | 49 | 19 |  |
| 62 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 63 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 64 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 65 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 66 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 67 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 68 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 69 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 70 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 71 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 72 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 74 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 75 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 76 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 77 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 80 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 81 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 82 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 |  |
| 83 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 84 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 85 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 88 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 89 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 90 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 91 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 92 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 93 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 94 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

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

**276 tests** with output mismatch, sorted by match rate (best first)

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
| 51 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 52 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 53 | `sound_props_swf5` | 65.2% | 45/69 | 69 | 68 |  |
| 54 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 55 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 56 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 57 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 58 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 59 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 60 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 61 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 62 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 63 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 64 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 65 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 66 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 67 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 68 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 69 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 70 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 71 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 72 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 74 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 75 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 76 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 77 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 80 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 81 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 82 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 |  |
| 83 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 84 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 85 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 89 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 90 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 91 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 92 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 93 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 94 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 95 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 96 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 |  |
| 97 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 |  |
| 98 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 99 | `sound_props_swf6` | 44.9% | 31/69 | 69 | 68 |  |
| 100 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 101 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 102 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 103 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 |  |
| 104 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 105 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 106 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 107 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 108 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 109 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 110 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 111 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 112 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 113 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 114 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 115 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 116 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 |  |
| 117 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 118 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 119 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 120 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 121 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 122 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 123 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 124 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 125 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 126 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 127 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 128 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 129 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 130 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 131 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 39 | 56 |  |
| 132 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 133 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 134 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 135 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 136 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 137 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 138 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 139 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 140 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 141 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 142 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 143 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 144 | `color_transform` | 14.6% | 7/48 | 38 | 48 |  |
| 145 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 146 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 147 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 148 | `printjob_props_swf5` | 13.3% | 6/45 | 36 | 45 |  |
| 149 | `printjob_props_swf6` | 13.3% | 6/45 | 36 | 45 |  |
| 150 | `printjob_props_swf7` | 13.3% | 6/45 | 36 | 45 |  |
| 151 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 152 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 153 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 154 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 155 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 156 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 157 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 158 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 159 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 39 | 56 |  |
| 160 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 161 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 162 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 163 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 164 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 165 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 166 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 167 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 168 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 169 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 170 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 171 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 172 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 173 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 174 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 175 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 176 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 177 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 178 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 179 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 180 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 181 | `context_menu` | 5.1% | 2/39 | 14 | 39 |  |
| 182 | `context_menu_item` | 4.9% | 2/41 | 10 | 41 |  |
| 183 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 184 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 185 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 186 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 187 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 188 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 189 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 190 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 191 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 192 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 193 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 194 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 195 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 196 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 197 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 198 | `global_proto_decls` | 0.2% | 9/4497 | 249 | 4497 |  |
| 199 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 200 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 201 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 202 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 203 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 204 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 205 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 206 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 207 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 208 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 209 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 210 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 211 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 212 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 213 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 214 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 215 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 216 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 217 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 218 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 219 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 220 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 221 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 222 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 223 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 224 | `global_proto_decls_delete` | 0.0% | 0/4158 | 114 | 4158 |  |
| 225 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 226 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 227 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 228 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 229 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 231 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 232 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 233 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 234 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 235 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 236 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 237 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 239 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 240 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 242 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 243 | `native_objects_swf8` | 0.0% | 0/188 | 188 | 84 |  |
| 244 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 245 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 246 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 247 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 248 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 249 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 250 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 251 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 252 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 253 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 255 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 256 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 257 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 258 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 259 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 260 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 261 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 262 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 263 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 265 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 266 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 267 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 268 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 269 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 270 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 271 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 272 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 273 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 274 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 275 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 276 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
