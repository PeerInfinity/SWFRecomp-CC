# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 18:52 UTC

**Git SHA**: `c5804d051f`

**Run Duration**: 44m 57s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **193** (40.0%) |
| Failing | 289 |
| Total expected lines | 77810 |
| Matching lines | 42532 (54.7%) |
| Mismatched lines | 35278 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 282 | 97.6% |
| Segfault | 5 | 1.7% |
| Timeout | 2 | 0.7% |

## Passing Tests

**193 tests passing**

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
| 52 | `equals` | 32 | 4.1s |  |
| 53 | `equals2_swf5` | 926 | 5.9s |  |
| 54 | `equals2_swf6` | 926 | 5.8s |  |
| 55 | `equals2_swf7` | 926 | 5.9s |  |
| 56 | `equals_swf4` | 665 | 4.5s |  |
| 57 | `equals_swf4_alt` | 32 | 4.0s |  |
| 58 | `equals_swf5` | 32 | 4.0s |  |
| 59 | `error` | 58 | 4.1s |  |
| 60 | `escape` | 14 | 4.0s |  |
| 61 | `execution_order1` | 5 | 4.0s |  |
| 62 | `execution_order2` | 7 | 4.1s |  |
| 63 | `execution_order3` | 4 | 4.0s |  |
| 64 | `focusrect_mouse_swf8` | 0 | 4.2s |  |
| 65 | `focusrect_mouse_swf9` | 0 | 4.2s |  |
| 66 | `focusrect_swf5` | 6 | 4.3s |  |
| 67 | `getproperty` | 28 | 4.1s |  |
| 68 | `getproperty_swf4` | 28 | 4.0s |  |
| 69 | `getproperty_swf5` | 28 | 4.0s |  |
| 70 | `global_array` | 3 | 4.1s |  |
| 71 | `global_is_bare` | 7 | 4.0s |  |
| 72 | `goto_advance1` | 6 | 4.1s |  |
| 73 | `goto_advance2` | 2 | 4.1s |  |
| 74 | `goto_both_ways1` | 3 | 5.0s |  |
| 75 | `goto_both_ways2` | 3 | 4.1s |  |
| 76 | `goto_execution_order` | 2 | 4.1s |  |
| 77 | `goto_execution_order2` | 2 | 4.1s |  |
| 78 | `goto_frame_number` | 3 | 4.2s |  |
| 79 | `goto_rewind1` | 1 | 4.1s |  |
| 80 | `goto_rewind2` | 3 | 4.3s |  |
| 81 | `goto_rewind3` | 2 | 4.0s |  |
| 82 | `greater_swf6` | 1175 | 6.1s |  |
| 83 | `greater_swf7` | 1175 | 6.1s |  |
| 84 | `greaterthan_swf5` | 1 | 4.1s |  |
| 85 | `greaterthan_swf8` | 1 | 4.1s |  |
| 86 | `has_own_property` | 32 | 4.1s |  |
| 87 | `infinite_recursion_function` | 4 | 4.1s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 88 | `infinite_recursion_function_in_setter` | 131 | 4.1s |  |
| 89 | `infinite_recursion_virtual_property` | 67 | 4.1s |  |
| 90 | `init_array_invalid` | 4 | 4.0s |  |
| 91 | `init_object_invalid` | 4 | 4.0s |  |
| 92 | `issue_1086` | 1 | 4.0s |  |
| 93 | `issue_1671` | 0 | 4.1s |  |
| 94 | `issue_2166` | 9 | 4.1s |  |
| 95 | `issue_3446` | 1 | 4.0s |  |
| 96 | `issue_4377` | 2 | 4.0s |  |
| 97 | `issue_710` | 4 | 4.0s |  |
| 98 | `issue_768` | 3 | 4.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 99 | `lessthan` | 41 | 4.1s |  |
| 100 | `lessthan2_swf5` | 1226 | 6.2s |  |
| 101 | `lessthan2_swf6` | 1226 | 6.2s |  |
| 102 | `lessthan2_swf7` | 1226 | 6.2s |  |
| 103 | `lessthan_swf4` | 902 | 4.7s |  |
| 104 | `lessthan_swf4_alt` | 41 | 4.0s |  |
| 105 | `lessthan_swf5` | 41 | 4.1s |  |
| 106 | `logical_ops_swf4` | 90 | 4.0s |  |
| 107 | `logical_ops_swf8` | 108 | 4.1s |  |
| 108 | `looping` | 6 | 4.0s |  |
| 109 | `mask_reapply` | 0 | 4.0s |  |
| 110 | `mask_with_drawing` | 0 | 4.0s |  |
| 111 | `math_min_max` | 101 | 4.2s |  |
| 112 | `movieclip_begin_gradient_fill` | 0 | 4.5s |  |
| 113 | `movieclip_blend_mode_property` | 35 | 4.1s |  |
| 114 | `movieclip_default_state` | 69 | 4.2s |  |
| 115 | `movieclip_line_gradient_style` | 0 | 4.3s |  |
| 116 | `movieclip_name_from_timeline` | 13 | 3.9s |  |
| 117 | `movieclip_prototype_extension` | 5 | 3.9s |  |
| 118 | `nested_textfields_in_buttons` | 0 | 3.9s |  |
| 119 | `netstream_play_flv_screen` | 0 | 16.9s |  |
| 120 | `new_method_wrap` | 4 | 3.9s |  |
| 121 | `new_object_wrap` | 4 | 3.9s |  |
| 122 | `o` | 3 | 3.9s |  |
| 123 | `object_constructor` | 33 | 4.0s |  |
| 124 | `object_function` | 32 | 3.9s |  |
| 125 | `object_string_coerce_swf5` | 62 | 3.9s |  |
| 126 | `primitive_instanceof` | 37 | 3.9s |  |
| 127 | `prototype_delete` | 12 | 4.0s |  |
| 128 | `recursive_prototypes` | 0 | 3.9s |  |
| 129 | `sandbox_type_local_file` | 1 | 4.0s |  |
| 130 | `set_variable_scope` | 58 | 4.1s |  |
| 131 | `single_frame` | 1 | 4.0s |  |
| 132 | `sound_start_load` | 0 | 4.0s |  |
| 133 | `stage_object_properties_get_var` | 5 | 4.0s |  |
| 134 | `strictequals_swf6` | 902 | 5.5s |  |
| 135 | `strictly_equals` | 7 | 4.0s |  |
| 136 | `string_coercion` | 117 | 4.3s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 137 | `string_methods_negative_args` | 240 | 4.1s |  |
| 138 | `string_methods_swfv5` | 275 | 4.5s |  |
| 139 | `string_paths_keyevents` | 0 | 4.1s |  |
| 140 | `string_paths_timer` | 0 | 4.0s |  |
| 141 | `swf4_actions_bool` | 96 | 4.0s |  |
| 142 | `swf4_bool` | 4 | 4.0s |  |
| 143 | `swf5_encoding` | 3 | 4.0s |  |
| 144 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.0s |  |
| 145 | `text_format` | 1146 | 4.3s |  |
| 146 | `text_format_display` | 21 | 4.1s |  |
| 147 | `text_format_font_max_length` | 2 | 4.1s |  |
| 148 | `text_format_rounding_swf7` | 840 | 4.2s |  |
| 149 | `text_format_rounding_swf8` | 840 | 4.2s |  |
| 150 | `textfield_background_color` | 11 | 4.1s |  |
| 151 | `textfield_border_color` | 11 | 4.1s |  |
| 152 | `textfield_maxchars` | 3 | 4.1s |  |
| 153 | `textfield_properties` | 44 | 4.1s |  |
| 154 | `textfield_text` | 7 | 4.1s |  |
| 155 | `textfield_variable` | 81 | 4.3s |  |
| 156 | `this_swf7` | 41 | 4.2s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 157 | `timeline_function_def` | 7 | 4.3s |  |
| 158 | `try_finally_simple` | 16 | 4.2s |  |
| 159 | `typeof` | 22 | 4.2s |  |
| 160 | `typeof_globals` | 7 | 4.0s |  |
| 161 | `uncaught_exception` | 1 | 4.0s |  |
| 162 | `uncaught_exception_bubbled` | 1 | 4.0s |  |
| 163 | `undefined_to_string_swf6` | 4 | 4.0s |  |
| 164 | `unescape` | 43 | 4.1s |  |
| 165 | `use_hand_cursor` | 8 | 4.1s |  |
| 166 | `variable_args` | 5 | 4.2s |  |
| 167 | `waitforframe` | 7 | 4.0s |  |
| 168 | `waitforframe2` | 16 | 4.0s |  |
| 169 | `with_return` | 2 | 4.1s |  |
| 170 | `xml` | 15 | 4.1s |  |
| 171 | `xml_append_child` | 28 | 4.1s |  |
| 172 | `xml_append_child_with_parent` | 20 | 4.1s |  |
| 173 | `xml_attributes_read` | 4 | 4.1s |  |
| 174 | `xml_cdata` | 11 | 4.1s |  |
| 175 | `xml_clone_expandos` | 19 | 4.1s |  |
| 176 | `xml_first_last_child` | 8 | 4.1s |  |
| 177 | `xml_has_child_nodes` | 3 | 4.1s |  |
| 178 | `xml_idmap` | 21 | 4.2s |  |
| 179 | `xml_ignore_comments` | 21 | 4.1s |  |
| 180 | `xml_ignore_white` | 34 | 4.1s |  |
| 181 | `xml_insert_before` | 20 | 4.1s |  |
| 182 | `xml_inspect_createmethods` | 15 | 4.1s |  |
| 183 | `xml_inspect_doctype` | 7 | 4.1s |  |
| 184 | `xml_inspect_parsexml` | 62 | 4.2s |  |
| 185 | `xml_inspect_xmldecl` | 7 | 4.2s |  |
| 186 | `xml_namespaces` | 203 | 4.1s |  |
| 187 | `xml_parent_and_child` | 5 | 4.1s |  |
| 188 | `xml_remove_node` | 22 | 4.2s |  |
| 189 | `xml_reparenting` | 14 | 4.2s |  |
| 190 | `xml_siblings` | 10 | 4.1s |  |
| 191 | `xml_to_string_comment` | 1 | 4.0s |  |
| 192 | `xml_unescaping` | 23 | 4.2s |  |
| 193 | `xmlnode_proto` | 1 | 4.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**96 tests** within reach

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
| 53 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 54 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
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
| 69 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 70 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 71 | `parse_float` | 58.1% | 43 | 74 | 31 |  |
| 72 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 73 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 74 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 75 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 76 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 77 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 78 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 79 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 80 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 81 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 82 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 83 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 84 | `globals_swf8` | 51.3% | 156 | 304 | 148 |  |
| 85 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 86 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 87 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 88 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 89 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 90 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 91 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 92 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 93 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 94 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 95 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |

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

**282 tests** with output mismatch, sorted by match rate (best first)

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
| 53 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 54 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
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
| 69 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 70 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 71 | `parse_float` | 58.1% | 43/74 | 74 | 74 |  |
| 72 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 73 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 74 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 75 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 76 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 77 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 78 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 79 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 80 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 81 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 82 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 83 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 84 | `globals_swf8` | 51.3% | 156/304 | 304 | 304 |  |
| 85 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 86 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 87 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 88 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 89 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 90 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 91 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 92 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 93 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 94 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 95 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 97 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 98 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 99 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 100 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 101 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 102 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 103 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 104 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 105 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 106 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 107 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 108 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 109 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 110 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 111 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 112 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 113 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 114 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 115 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 116 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 117 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 118 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 119 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 120 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 121 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 122 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 123 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 124 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 125 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 126 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 127 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 128 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 129 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 130 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 131 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 132 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 133 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 134 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 135 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 136 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 137 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 138 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 139 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 140 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 141 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 142 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 143 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 144 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 145 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 146 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 147 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 148 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 149 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 150 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 151 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 152 | `path_string` | 14.0% | 45/322 | 299 | 322 |  |
| 153 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 154 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 155 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 156 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 157 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 158 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 159 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 160 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 161 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 162 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 163 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 164 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 165 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 166 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 167 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 168 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 169 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 170 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 171 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 172 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 173 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 174 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 175 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 176 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 177 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 178 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 179 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 180 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 181 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 182 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 183 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 184 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 185 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 186 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 187 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 188 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 189 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 190 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 191 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 192 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 193 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 194 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 195 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 196 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 197 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 198 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 199 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 200 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 201 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 202 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 203 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 204 | `global_proto_decls` | 0.1% | 4/4497 | 184 | 4497 |  |
| 205 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 206 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 207 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 208 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 209 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 210 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 211 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 212 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 213 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 214 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 215 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 216 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 |  |
| 217 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 218 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 219 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 220 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 221 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 |  |
| 222 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 223 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 224 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 225 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 226 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 227 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 228 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 229 | `global_proto_decls_delete` | 0.0% | 0/4158 | 69 | 4158 |  |
| 230 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 231 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 232 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 233 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 234 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 236 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 237 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 238 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 240 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 241 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 242 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 243 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 244 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 245 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 246 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 247 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 248 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 249 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 250 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 251 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 252 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 253 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 254 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 255 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 256 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 257 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 258 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 259 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 260 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 261 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 263 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 264 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 265 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 266 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 267 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 268 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 269 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 270 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 271 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 272 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 273 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 274 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 275 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 276 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 277 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 278 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 279 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 280 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 281 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 282 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
