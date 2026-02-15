# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 20:33 UTC

**Git SHA**: `742bdce601`

**Run Duration**: 46m 6s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **194** (40.2%) |
| Failing | 288 |
| Total expected lines | 77810 |
| Matching lines | 42967 (55.2%) |
| Mismatched lines | 34843 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 280 | 97.2% |
| Segfault | 6 | 2.1% |
| Timeout | 2 | 0.7% |

## Passing Tests

**194 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 6.3s |  |
| 2 | `action_to_integer` | 28 | 4.2s |  |
| 3 | `add` | 28 | 4.2s |  |
| 4 | `add2` | 354 | 4.4s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.2s |  |
| 6 | `add_swf5` | 28 | 4.2s |  |
| 7 | `array_concat` | 98 | 4.3s |  |
| 8 | `array_length` | 42 | 4.2s |  |
| 9 | `array_properties` | 36 | 4.2s |  |
| 10 | `array_slice` | 34 | 4.2s |  |
| 11 | `array_splice` | 207 | 4.4s |  |
| 12 | `array_trivial` | 209 | 4.3s |  |
| 13 | `as1_constructor_v6` | 35 | 4.2s |  |
| 14 | `as1_constructor_v7` | 35 | 4.2s |  |
| 15 | `as_broadcaster_initialize` | 10 | 4.2s |  |
| 16 | `as_set_prop_flags_version_swf5` | 1 | 4.1s |  |
| 17 | `as_set_prop_flags_version_swf6` | 1 | 4.2s |  |
| 18 | `as_set_prop_flags_version_swf7` | 1 | 4.2s |  |
| 19 | `as_set_prop_flags_version_swf8` | 1 | 4.2s |  |
| 20 | `as_set_prop_flags_version_swf9` | 1 | 4.2s |  |
| 21 | `as_transformed_flag` | 20 | 4.2s |  |
| 22 | `bad_swf_tag_past_eof` | 0 | 4.1s |  |
| 23 | `bitand` | 1058 | 6.9s |  |
| 24 | `bitmap_data_colortransform` | 0 | 4.4s |  |
| 25 | `bitmap_data_fillrect` | 0 | 4.4s |  |
| 26 | `bitmap_data_max_size_swf10` | 12 | 4.2s |  |
| 27 | `bitmap_data_max_size_swf9` | 10 | 4.2s |  |
| 28 | `bitmap_data_perlinnoise` | 0 | 4.8s |  |
| 29 | `bitmap_data_pixeldissolve_image` | 0 | 4.6s |  |
| 30 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.2s |  |
| 31 | `bitor` | 1058 | 6.9s |  |
| 32 | `biturshift` | 14 | 7.0s |  |
| 33 | `biturshift_swf8` | 14 | 4.3s |  |
| 34 | `bitxor` | 1058 | 7.1s |  |
| 35 | `call_method_empty_name` | 1 | 4.2s |  |
| 36 | `capabilities_resolution` | 8 | 4.2s |  |
| 37 | `catch_references_registers` | 2 | 4.2s |  |
| 38 | `conflicting_instance_names` | 23 | 4.4s |  |
| 39 | `define_function2` | 8 | 4.3s |  |
| 40 | `define_function2_preload` | 13 | 4.3s |  |
| 41 | `define_function2_preload_order` | 4 | 4.2s |  |
| 42 | `define_function_case_sensitive` | 2 | 4.2s |  |
| 43 | `delete` | 3 | 4.4s |  |
| 44 | `display_object_properties` | 2 | 4.2s |  |
| 45 | `do_init_action` | 3 | 4.3s |  |
| 46 | `edittext_antialiastype` | 296 | 4.6s |  |
| 47 | `edittext_autosize_setter` | 20 | 4.2s |  |
| 48 | `edittext_default_format` | 221 | 4.3s |  |
| 49 | `edittext_default_format_empty` | 95 | 4.2s |  |
| 50 | `edittext_default_format_font_style` | 335 | 4.2s |  |
| 51 | `equals` | 32 | 4.2s |  |
| 52 | `equals2_swf5` | 926 | 5.8s |  |
| 53 | `equals2_swf6` | 926 | 5.9s |  |
| 54 | `equals2_swf7` | 926 | 6.1s |  |
| 55 | `equals_swf4` | 665 | 4.5s |  |
| 56 | `equals_swf4_alt` | 32 | 4.1s |  |
| 57 | `equals_swf5` | 32 | 4.1s |  |
| 58 | `error` | 58 | 4.2s |  |
| 59 | `escape` | 14 | 4.2s |  |
| 60 | `execution_order1` | 5 | 4.4s |  |
| 61 | `execution_order2` | 7 | 4.5s |  |
| 62 | `execution_order3` | 4 | 4.3s |  |
| 63 | `focusrect_mouse_swf8` | 0 | 4.3s |  |
| 64 | `focusrect_mouse_swf9` | 0 | 4.2s |  |
| 65 | `focusrect_swf5` | 6 | 4.3s |  |
| 66 | `getproperty` | 28 | 4.2s |  |
| 67 | `getproperty_swf4` | 28 | 4.1s |  |
| 68 | `getproperty_swf5` | 28 | 4.2s |  |
| 69 | `global_array` | 3 | 4.2s |  |
| 70 | `global_is_bare` | 7 | 4.2s |  |
| 71 | `goto_advance1` | 6 | 4.3s |  |
| 72 | `goto_advance2` | 2 | 4.2s |  |
| 73 | `goto_both_ways1` | 3 | 4.3s |  |
| 74 | `goto_both_ways2` | 3 | 4.1s |  |
| 75 | `goto_execution_order` | 2 | 4.1s |  |
| 76 | `goto_execution_order2` | 2 | 4.1s |  |
| 77 | `goto_frame_number` | 3 | 4.1s |  |
| 78 | `goto_rewind1` | 1 | 4.2s |  |
| 79 | `goto_rewind2` | 3 | 4.1s |  |
| 80 | `goto_rewind3` | 2 | 4.0s |  |
| 81 | `greater_swf6` | 1175 | 6.0s |  |
| 82 | `greater_swf7` | 1175 | 6.0s |  |
| 83 | `greaterthan_swf5` | 1 | 4.0s |  |
| 84 | `greaterthan_swf8` | 1 | 4.1s |  |
| 85 | `has_own_property` | 32 | 4.1s |  |
| 86 | `infinite_recursion_function` | 4 | 4.1s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 87 | `infinite_recursion_function_in_setter` | 131 | 4.1s |  |
| 88 | `infinite_recursion_virtual_property` | 67 | 4.1s |  |
| 89 | `init_array_invalid` | 4 | 4.0s |  |
| 90 | `init_object_invalid` | 4 | 4.0s |  |
| 91 | `is_finite` | 49 | 4.1s |  |
| 92 | `is_finite_swf6` | 49 | 4.1s |  |
| 93 | `issue_1086` | 1 | 4.0s |  |
| 94 | `issue_1671` | 0 | 4.0s |  |
| 95 | `issue_2166` | 9 | 4.0s |  |
| 96 | `issue_3446` | 1 | 4.0s |  |
| 97 | `issue_4377` | 2 | 4.0s |  |
| 98 | `issue_710` | 4 | 4.0s |  |
| 99 | `issue_768` | 3 | 4.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 100 | `lessthan` | 41 | 4.1s |  |
| 101 | `lessthan2_swf5` | 1226 | 6.1s |  |
| 102 | `lessthan2_swf6` | 1226 | 6.1s |  |
| 103 | `lessthan2_swf7` | 1226 | 6.1s |  |
| 104 | `lessthan_swf4` | 902 | 4.6s |  |
| 105 | `lessthan_swf4_alt` | 41 | 4.0s |  |
| 106 | `lessthan_swf5` | 41 | 4.0s |  |
| 107 | `logical_ops_swf4` | 90 | 4.3s |  |
| 108 | `logical_ops_swf8` | 108 | 4.4s |  |
| 109 | `looping` | 6 | 4.4s |  |
| 110 | `mask_reapply` | 0 | 4.4s |  |
| 111 | `mask_with_drawing` | 0 | 4.4s |  |
| 112 | `math_min_max` | 101 | 4.4s |  |
| 113 | `movieclip_begin_gradient_fill` | 0 | 4.7s |  |
| 114 | `movieclip_blend_mode_property` | 35 | 4.3s |  |
| 115 | `movieclip_default_state` | 69 | 4.4s |  |
| 116 | `movieclip_line_gradient_style` | 0 | 4.5s |  |
| 117 | `movieclip_name_from_timeline` | 13 | 4.1s |  |
| 118 | `movieclip_prototype_extension` | 5 | 4.0s |  |
| 119 | `nested_textfields_in_buttons` | 0 | 4.1s |  |
| 120 | `netstream_play_flv_screen` | 0 | 16.9s |  |
| 121 | `new_method_wrap` | 4 | 4.0s |  |
| 122 | `new_object_wrap` | 4 | 4.0s |  |
| 123 | `o` | 3 | 4.0s |  |
| 124 | `object_constructor` | 33 | 4.1s |  |
| 125 | `object_function` | 32 | 4.1s |  |
| 126 | `object_string_coerce_swf5` | 62 | 4.1s |  |
| 127 | `primitive_instanceof` | 37 | 4.1s |  |
| 128 | `prototype_delete` | 12 | 4.2s |  |
| 129 | `recursive_prototypes` | 0 | 4.1s |  |
| 130 | `sandbox_type_local_file` | 1 | 4.1s |  |
| 131 | `set_variable_scope` | 58 | 4.2s |  |
| 132 | `single_frame` | 1 | 4.1s |  |
| 133 | `sound_start_load` | 0 | 4.1s |  |
| 134 | `stage_object_properties_get_var` | 5 | 4.1s |  |
| 135 | `strictequals_swf6` | 902 | 5.7s |  |
| 136 | `strictly_equals` | 7 | 4.2s |  |
| 137 | `string_coercion` | 117 | 4.4s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 138 | `string_methods_negative_args` | 240 | 4.2s |  |
| 139 | `string_methods_swfv5` | 275 | 4.6s |  |
| 140 | `string_paths_keyevents` | 0 | 4.2s |  |
| 141 | `string_paths_timer` | 0 | 4.2s |  |
| 142 | `swf4_actions_bool` | 96 | 4.2s |  |
| 143 | `swf4_bool` | 4 | 4.2s |  |
| 144 | `swf5_encoding` | 3 | 4.0s |  |
| 145 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.1s |  |
| 146 | `text_format` | 1146 | 4.3s |  |
| 147 | `text_format_display` | 21 | 4.1s |  |
| 148 | `text_format_font_max_length` | 2 | 4.1s |  |
| 149 | `text_format_rounding_swf7` | 840 | 4.2s |  |
| 150 | `text_format_rounding_swf8` | 840 | 4.3s |  |
| 151 | `textfield_background_color` | 11 | 4.1s |  |
| 152 | `textfield_border_color` | 11 | 4.1s |  |
| 153 | `textfield_maxchars` | 3 | 4.1s |  |
| 154 | `textfield_properties` | 44 | 4.2s |  |
| 155 | `textfield_text` | 7 | 4.1s |  |
| 156 | `textfield_variable` | 81 | 4.3s |  |
| 157 | `this_swf7` | 41 | 4.1s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 158 | `timeline_function_def` | 7 | 4.2s |  |
| 159 | `try_finally_simple` | 16 | 4.2s |  |
| 160 | `typeof` | 22 | 4.1s |  |
| 161 | `typeof_globals` | 7 | 4.0s |  |
| 162 | `uncaught_exception` | 1 | 4.1s |  |
| 163 | `uncaught_exception_bubbled` | 1 | 4.1s |  |
| 164 | `undefined_to_string_swf6` | 4 | 4.1s |  |
| 165 | `unescape` | 43 | 4.1s |  |
| 166 | `use_hand_cursor` | 8 | 4.1s |  |
| 167 | `variable_args` | 5 | 4.2s |  |
| 168 | `waitforframe` | 7 | 4.1s |  |
| 169 | `waitforframe2` | 16 | 4.1s |  |
| 170 | `with_return` | 2 | 4.1s |  |
| 171 | `xml` | 15 | 4.1s |  |
| 172 | `xml_append_child` | 28 | 4.1s |  |
| 173 | `xml_append_child_with_parent` | 20 | 4.1s |  |
| 174 | `xml_attributes_read` | 4 | 4.1s |  |
| 175 | `xml_cdata` | 11 | 4.1s |  |
| 176 | `xml_clone_expandos` | 19 | 4.1s |  |
| 177 | `xml_first_last_child` | 8 | 4.1s |  |
| 178 | `xml_has_child_nodes` | 3 | 4.1s |  |
| 179 | `xml_idmap` | 21 | 4.2s |  |
| 180 | `xml_ignore_comments` | 21 | 4.2s |  |
| 181 | `xml_ignore_white` | 34 | 4.2s |  |
| 182 | `xml_insert_before` | 20 | 4.1s |  |
| 183 | `xml_inspect_createmethods` | 15 | 4.1s |  |
| 184 | `xml_inspect_doctype` | 7 | 4.1s |  |
| 185 | `xml_inspect_parsexml` | 62 | 4.1s |  |
| 186 | `xml_inspect_xmldecl` | 7 | 4.1s |  |
| 187 | `xml_namespaces` | 203 | 4.1s |  |
| 188 | `xml_parent_and_child` | 5 | 4.1s |  |
| 189 | `xml_remove_node` | 22 | 4.1s |  |
| 190 | `xml_reparenting` | 14 | 4.1s |  |
| 191 | `xml_siblings` | 10 | 4.1s |  |
| 192 | `xml_to_string_comment` | 1 | 4.1s |  |
| 193 | `xml_unescaping` | 23 | 4.2s |  |
| 194 | `xmlnode_proto` | 1 | 4.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**97 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_methods` | 99.3% | 283 | 285 | 2 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208 | 210 | 2 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208 | 210 | 2 |  |
| 5 | `math_swf6` | 98.5% | 522 | 530 | 8 |  |
| 6 | `math_swf7` | 98.5% | 522 | 530 | 8 |  |
| 7 | `math_swf8` | 98.5% | 522 | 530 | 8 |  |
| 8 | `array_constructor` | 96.7% | 29 | 30 | 1 |  |
| 9 | `globals_swf6` | 96.4% | 293 | 304 | 11 |  |
| 10 | `globals_swf7` | 96.4% | 293 | 304 | 11 |  |
| 11 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 12 | `globals_swf8` | 94.1% | 286 | 304 | 18 |  |
| 13 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 14 | `globals_swf5` | 91.8% | 279 | 304 | 25 |  |
| 15 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 16 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 17 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 18 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 19 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 20 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 21 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 22 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 23 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 24 | `stage_object_children` | 80.7% | 67 | 83 | 16 |  |
| 25 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 26 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 27 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 28 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 29 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 30 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 31 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 32 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 33 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 34 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 35 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 36 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 37 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 38 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 39 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 40 | `point` | 70.9% | 124 | 175 | 51 |  |
| 41 | `array_sort` | 70.8% | 114 | 161 | 47 |  |
| 42 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 43 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 44 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 45 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 46 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 47 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 48 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 49 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 50 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 51 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 52 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 53 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 54 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 55 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 56 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 57 | `sound_props_swf5` | 65.2% | 45 | 69 | 24 |  |
| 58 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 59 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 60 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 61 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 62 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 63 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 64 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 65 | `with` | 61.2% | 30 | 49 | 19 |  |
| 66 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 67 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 68 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 69 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 70 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 71 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 72 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 73 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 74 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
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
| 86 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 87 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 88 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 89 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 90 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 91 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 92 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 93 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 94 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 95 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 96 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 97 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

## Segfaults

**6 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `enumerate` | 6.1s |  |
| 2 | `function_base_clip_removed` | 6.4s |  |
| 3 | `goto_methods` | 6.3s |  |
| 4 | `init_object_order` | 6.2s |  |
| 5 | `register_and_init_order` | 6.7s |  |
| 6 | `register_class` | 6.5s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 14.3s |  |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 14.4s |  |

## All Output Mismatches

**280 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_methods` | 99.3% | 283/285 | 285 | 285 |  |
| 2 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 |  |
| 3 | `textfield_props_swf7` | 99.0% | 208/210 | 210 | 210 |  |
| 4 | `textfield_props_swf8` | 99.0% | 208/210 | 210 | 210 |  |
| 5 | `math_swf6` | 98.5% | 522/530 | 529 | 530 |  |
| 6 | `math_swf7` | 98.5% | 522/530 | 529 | 530 |  |
| 7 | `math_swf8` | 98.5% | 522/530 | 529 | 530 |  |
| 8 | `array_constructor` | 96.7% | 29/30 | 30 | 30 |  |
| 9 | `globals_swf6` | 96.4% | 293/304 | 304 | 304 |  |
| 10 | `globals_swf7` | 96.4% | 293/304 | 304 | 304 |  |
| 11 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 12 | `globals_swf8` | 94.1% | 286/304 | 304 | 304 |  |
| 13 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 14 | `globals_swf5` | 91.8% | 279/304 | 304 | 304 |  |
| 15 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 16 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 17 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 18 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 19 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 20 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 21 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 22 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 23 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 24 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 |  |
| 25 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 26 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 27 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 28 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 29 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 30 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 31 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 33 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 34 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 35 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 36 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 37 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 38 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 39 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 40 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 41 | `array_sort` | 70.8% | 114/161 | 161 | 161 |  |
| 42 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 43 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 44 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 45 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 46 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 47 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 48 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 49 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 50 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 51 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 52 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 53 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 54 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 55 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 56 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 57 | `sound_props_swf5` | 65.2% | 45/69 | 69 | 68 |  |
| 58 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 59 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 60 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 61 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 62 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 63 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 64 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 65 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 66 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 67 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 68 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 69 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 70 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 71 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 72 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 73 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 74 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
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
| 86 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 87 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 88 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 90 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 91 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 92 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 93 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 94 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 95 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 96 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 97 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 98 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 99 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 100 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 |  |
| 101 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 102 | `sound_props_swf6` | 44.9% | 31/69 | 69 | 68 |  |
| 103 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 104 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 105 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 106 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 107 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 108 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 109 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 110 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 111 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 112 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 113 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 114 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 115 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 116 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 117 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 118 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 119 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 120 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 121 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 122 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 123 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 124 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 125 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 126 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 127 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 128 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 129 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 130 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 131 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 132 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 133 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 134 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 135 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 39 | 56 |  |
| 136 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 137 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 138 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 139 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 140 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 141 | `external_interface_toxml_basic` | 19.0% | 34/179 | 179 | 179 |  |
| 142 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 143 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 144 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 145 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 146 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 147 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 148 | `color_transform` | 14.6% | 7/48 | 38 | 48 |  |
| 149 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 150 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 151 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 152 | `printjob_props_swf5` | 13.3% | 6/45 | 36 | 45 |  |
| 153 | `printjob_props_swf6` | 13.3% | 6/45 | 36 | 45 |  |
| 154 | `printjob_props_swf7` | 13.3% | 6/45 | 36 | 45 |  |
| 155 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 156 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 157 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 158 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 159 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 160 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 161 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 162 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 163 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 39 | 56 |  |
| 164 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 165 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 166 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 167 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 168 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 169 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 170 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 171 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 172 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 173 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 174 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 175 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 176 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 177 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 178 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 179 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 180 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 181 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 182 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 183 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 184 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 185 | `context_menu` | 5.1% | 2/39 | 14 | 39 |  |
| 186 | `context_menu_item` | 4.9% | 2/41 | 10 | 41 |  |
| 187 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 188 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 189 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 190 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 191 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 192 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 193 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 194 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 195 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 196 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 197 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 198 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 199 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 200 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 201 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 202 | `global_proto_decls` | 0.2% | 9/4497 | 249 | 4497 |  |
| 203 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 204 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 205 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 206 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 207 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 208 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 209 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 211 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 212 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 213 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 214 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 215 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 216 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 217 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 218 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 219 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 220 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 221 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 222 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 223 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 224 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 225 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 226 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 227 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 228 | `global_proto_decls_delete` | 0.0% | 0/4158 | 114 | 4158 |  |
| 229 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 230 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 231 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 232 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 233 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 234 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 235 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 236 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 237 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 238 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 239 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 240 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 241 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 242 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 243 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 244 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 245 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 246 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 247 | `native_objects_swf8` | 0.0% | 0/188 | 188 | 84 |  |
| 248 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 249 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 250 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 251 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 252 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 253 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 254 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 255 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 256 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 257 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 259 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 261 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 262 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 263 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 264 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 265 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 266 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 267 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 269 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 270 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 273 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 274 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 275 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 277 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 278 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 280 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
