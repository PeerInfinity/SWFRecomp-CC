# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 03:10 UTC

**Git SHA**: `3fb6a61297`

**Run Duration**: 47m 44s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **198** (32.0%) |
| Failing | 421 |
| Total expected lines | 90145 |
| Matching lines | 43493 (48.2%) |
| Mismatched lines | 46652 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 409 | 97.1% |
| Runtime Segfault | 8 | 1.9% |
| Timeout | 4 | 1.0% |

## Passing Tests

**198 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.9s |  |
| 2 | `action_to_integer` | 28 | 4.0s |  |
| 3 | `add` | 28 | 4.2s |  |
| 4 | `add2` | 354 | 4.4s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.0s |  |
| 6 | `add_swf5` | 28 | 4.0s |  |
| 7 | `array_concat` | 98 | 4.2s |  |
| 8 | `array_constructor` | 30 | 4.1s |  |
| 9 | `array_length` | 42 | 4.2s |  |
| 10 | `array_properties` | 36 | 4.1s |  |
| 11 | `array_slice` | 34 | 4.2s |  |
| 12 | `array_splice` | 207 | 4.8s |  |
| 13 | `array_trivial` | 209 | 4.5s |  |
| 14 | `as1_constructor_v6` | 35 | 4.1s |  |
| 15 | `as1_constructor_v7` | 35 | 4.1s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.0s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 4.0s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.1s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.1s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.0s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.0s |  |
| 22 | `as_transformed_flag` | 20 | 4.1s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 3.9s |  |
| 24 | `bitand` | 1058 | 10.9s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.3s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.2s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 4.0s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 4.0s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.7s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.5s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.0s |  |
| 32 | `bitor` | 1058 | 10.9s |  |
| 33 | `biturshift` | 14 | 5.0s |  |
| 34 | `biturshift_swf8` | 14 | 4.0s |  |
| 35 | `bitxor` | 1058 | 10.7s |  |
| 36 | `call_method_empty_name` | 1 | 3.9s |  |
| 37 | `capabilities_resolution` | 8 | 4.0s |  |
| 38 | `catch_references_registers` | 2 | 4.0s |  |
| 39 | `conflicting_instance_names` | 23 | 4.1s |  |
| 40 | `define_function2` | 8 | 4.0s |  |
| 41 | `define_function2_preload` | 13 | 4.0s |  |
| 42 | `define_function2_preload_order` | 4 | 4.0s |  |
| 43 | `define_function_case_sensitive` | 2 | 4.0s |  |
| 44 | `delete` | 3 | 4.1s |  |
| 45 | `display_object_properties` | 2 | 4.0s |  |
| 46 | `divide_swf4` | 107 | 4.1s |  |
| 47 | `do_init_action` | 3 | 4.1s |  |
| 48 | `edittext_antialiastype` | 296 | 4.6s |  |
| 49 | `edittext_autosize_setter` | 20 | 4.0s |  |
| 50 | `edittext_default_format` | 221 | 4.2s |  |
| 51 | `edittext_default_format_empty` | 95 | 4.1s |  |
| 52 | `edittext_default_format_font_style` | 335 | 4.1s |  |
| 53 | `edittext_password` | 5 | 4.0s |  |
| 54 | `equals` | 32 | 4.0s |  |
| 55 | `equals2_swf5` | 926 | 11.8s |  |
| 56 | `equals2_swf6` | 926 | 11.9s |  |
| 57 | `equals2_swf7` | 926 | 12.1s |  |
| 58 | `equals_swf4` | 665 | 7.4s |  |
| 59 | `equals_swf4_alt` | 32 | 3.9s |  |
| 60 | `equals_swf5` | 32 | 4.0s |  |
| 61 | `error` | 58 | 4.1s |  |
| 62 | `escape` | 14 | 3.9s |  |
| 63 | `execution_order1` | 5 | 4.0s |  |
| 64 | `execution_order2` | 7 | 4.0s |  |
| 65 | `execution_order3` | 4 | 3.9s |  |
| 66 | `focusrect_mouse_swf8` | 0 | 3.9s |  |
| 67 | `focusrect_mouse_swf9` | 0 | 3.9s |  |
| 68 | `focusrect_swf5` | 6 | 4.1s |  |
| 69 | `get_variable_in_scope` | 29 | 4.1s |  |
| 70 | `getproperty` | 28 | 4.0s |  |
| 71 | `getproperty_swf4` | 28 | 3.9s |  |
| 72 | `getproperty_swf5` | 28 | 3.9s |  |
| 73 | `global_array` | 3 | 3.9s |  |
| 74 | `global_is_bare` | 7 | 3.9s |  |
| 75 | `goto_advance1` | 6 | 3.9s |  |
| 76 | `goto_advance2` | 2 | 3.9s |  |
| 77 | `goto_both_ways1` | 3 | 4.4s |  |
| 78 | `goto_both_ways2` | 3 | 4.2s |  |
| 79 | `goto_execution_order` | 2 | 4.2s |  |
| 80 | `goto_execution_order2` | 2 | 4.2s |  |
| 81 | `goto_frame_number` | 3 | 4.3s |  |
| 82 | `goto_rewind1` | 1 | 4.3s |  |
| 83 | `goto_rewind2` | 3 | 4.2s |  |
| 84 | `goto_rewind3` | 2 | 4.2s |  |
| 85 | `greater_swf6` | 1175 | 14.0s |  |
| 86 | `greater_swf7` | 1175 | 14.0s |  |
| 87 | `greaterthan_swf5` | 1 | 4.1s |  |
| 88 | `greaterthan_swf8` | 1 | 4.2s |  |
| 89 | `has_own_property` | 32 | 4.3s |  |
| 90 | `infinite_recursion_function` | 4 | 4.2s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 91 | `infinite_recursion_function_in_setter` | 131 | 4.2s |  |
| 92 | `infinite_recursion_virtual_property` | 67 | 4.2s |  |
| 93 | `init_array_invalid` | 4 | 4.1s |  |
| 94 | `init_object_invalid` | 4 | 4.1s |  |
| 95 | `issue_1086` | 1 | 4.1s |  |
| 96 | `issue_1671` | 0 | 4.2s |  |
| 97 | `issue_2166` | 9 | 4.2s |  |
| 98 | `issue_3446` | 1 | 4.0s |  |
| 99 | `issue_4377` | 2 | 4.0s |  |
| 100 | `issue_710` | 4 | 4.0s |  |
| 101 | `issue_768` | 3 | 4.0s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 102 | `lessthan` | 41 | 4.1s |  |
| 103 | `lessthan2_swf5` | 1226 | 13.9s |  |
| 104 | `lessthan2_swf6` | 1226 | 14.2s |  |
| 105 | `lessthan2_swf7` | 1226 | 14.1s |  |
| 106 | `lessthan_swf4` | 902 | 9.8s |  |
| 107 | `lessthan_swf4_alt` | 41 | 4.1s |  |
| 108 | `lessthan_swf5` | 41 | 4.1s |  |
| 109 | `logical_ops_swf4` | 90 | 4.0s |  |
| 110 | `logical_ops_swf8` | 108 | 4.0s |  |
| 111 | `looping` | 6 | 3.9s |  |
| 112 | `mask_reapply` | 0 | 3.9s |  |
| 113 | `mask_with_drawing` | 0 | 3.9s |  |
| 114 | `mouse_wheel_enabled` | 2 | 4.0s |  |
| 115 | `movieclip_begin_gradient_fill` | 0 | 4.6s |  |
| 116 | `movieclip_blend_mode_property` | 35 | 4.0s |  |
| 117 | `movieclip_default_state` | 69 | 4.4s |  |
| 118 | `movieclip_line_gradient_style` | 0 | 4.6s |  |
| 119 | `movieclip_name_from_timeline` | 13 | 4.0s |  |
| 120 | `movieclip_prototype_extension` | 5 | 4.0s |  |
| 121 | `nested_textfields_in_buttons` | 0 | 4.0s |  |
| 122 | `netstream_play_flv_screen` | 0 | 32.7s |  |
| 123 | `new_method_wrap` | 4 | 4.2s |  |
| 124 | `new_object_wrap` | 4 | 4.1s |  |
| 125 | `o` | 3 | 4.0s |  |
| 126 | `object_constructor` | 33 | 4.2s |  |
| 127 | `object_function` | 32 | 4.1s |  |
| 128 | `object_string_coerce_swf5` | 62 | 4.2s |  |
| 129 | `primitive_instanceof` | 37 | 4.2s |  |
| 130 | `prototype_delete` | 12 | 4.1s |  |
| 131 | `recursive_prototypes` | 0 | 4.0s |  |
| 132 | `sandbox_type_local_file` | 1 | 4.0s |  |
| 133 | `set_variable_scope` | 58 | 4.2s |  |
| 134 | `single_frame` | 1 | 4.0s |  |
| 135 | `sound_start_load` | 0 | 4.0s |  |
| 136 | `stage_object_properties_get_var` | 5 | 4.0s |  |
| 137 | `strictequals_swf6` | 902 | 10.2s |  |
| 138 | `strictly_equals` | 7 | 4.0s |  |
| 139 | `string_coercion` | 117 | 4.7s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 140 | `string_methods_negative_args` | 240 | 4.2s |  |
| 141 | `string_paths_keyevents` | 0 | 4.0s |  |
| 142 | `string_paths_timer` | 0 | 4.0s |  |
| 143 | `swf4_actions_bool` | 96 | 4.2s |  |
| 144 | `swf4_bool` | 4 | 4.0s |  |
| 145 | `swf4_function_calls` | 7 | 4.2s |  |
| 146 | `swf5_encoding` | 3 | 4.0s |  |
| 147 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.3s |  |
| 148 | `text_format` | 1146 | 4.5s |  |
| 149 | `text_format_display` | 21 | 4.2s |  |
| 150 | `text_format_font_max_length` | 2 | 4.1s |  |
| 151 | `text_format_rounding_swf7` | 840 | 4.3s |  |
| 152 | `text_format_rounding_swf8` | 840 | 4.3s |  |
| 153 | `textfield_background_color` | 11 | 4.0s |  |
| 154 | `textfield_border_color` | 11 | 4.1s |  |
| 155 | `textfield_maxchars` | 3 | 4.1s |  |
| 156 | `textfield_properties` | 44 | 4.3s |  |
| 157 | `textfield_props_swf6` | 210 | 5.0s |  |
| 158 | `textfield_props_swf7` | 210 | 5.0s |  |
| 159 | `textfield_props_swf8` | 210 | 5.1s |  |
| 160 | `textfield_text` | 7 | 4.0s |  |
| 161 | `textfield_variable` | 81 | 4.5s |  |
| 162 | `this_swf7` | 41 | 4.1s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 163 | `timeline_function_def` | 7 | 4.2s |  |
| 164 | `try_finally_simple` | 16 | 4.0s |  |
| 165 | `typeof` | 22 | 4.0s |  |
| 166 | `typeof_globals` | 7 | 3.9s |  |
| 167 | `uncaught_exception` | 1 | 3.9s |  |
| 168 | `uncaught_exception_bubbled` | 1 | 3.9s |  |
| 169 | `undefined_to_string_swf6` | 4 | 3.9s |  |
| 170 | `unescape` | 43 | 4.0s |  |
| 171 | `use_hand_cursor` | 8 | 3.9s |  |
| 172 | `variable_args` | 5 | 4.0s |  |
| 173 | `waitforframe` | 7 | 3.9s |  |
| 174 | `waitforframe2` | 16 | 4.0s |  |
| 175 | `with_return` | 2 | 3.9s |  |
| 176 | `xml` | 15 | 4.0s |  |
| 177 | `xml_append_child` | 28 | 4.1s |  |
| 178 | `xml_append_child_with_parent` | 20 | 4.0s |  |
| 179 | `xml_attributes_read` | 4 | 3.9s |  |
| 180 | `xml_cdata` | 11 | 3.9s |  |
| 181 | `xml_clone_expandos` | 19 | 4.0s |  |
| 182 | `xml_first_last_child` | 8 | 4.0s |  |
| 183 | `xml_has_child_nodes` | 3 | 3.9s |  |
| 184 | `xml_idmap` | 21 | 4.1s |  |
| 185 | `xml_ignore_white` | 34 | 4.1s |  |
| 186 | `xml_insert_before` | 20 | 4.0s |  |
| 187 | `xml_inspect_createmethods` | 15 | 4.0s |  |
| 188 | `xml_inspect_doctype` | 7 | 4.0s |  |
| 189 | `xml_inspect_parsexml` | 62 | 4.1s |  |
| 190 | `xml_inspect_xmldecl` | 7 | 4.0s |  |
| 191 | `xml_namespaces` | 203 | 4.0s |  |
| 192 | `xml_parent_and_child` | 5 | 4.0s |  |
| 193 | `xml_remove_node` | 22 | 4.0s |  |
| 194 | `xml_reparenting` | 14 | 4.0s |  |
| 195 | `xml_siblings` | 10 | 4.0s |  |
| 196 | `xml_to_string_comment` | 1 | 3.9s |  |
| 197 | `xml_unescaping` | 23 | 4.1s |  |
| 198 | `xmlnode_proto` | 1 | 4.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**101 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `string_methods_swfv5` | 99.6% | 274 | 275 | 1 |  |
| 2 | `string_methods` | 98.2% | 280 | 285 | 5 |  |
| 3 | `edittext_width_height` | 94.2% | 97 | 103 | 6 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 5 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 6 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 7 | `xml_ignore_comments` | 85.7% | 18 | 21 | 3 |  |
| 8 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 9 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 10 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 11 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 12 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 13 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 14 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 15 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 |  |
| 16 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 17 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 18 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 19 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 20 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 21 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 22 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 23 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 24 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 |  |
| 25 | `stage_object_properties` | 71.8% | 173 | 241 | 68 |  |
| 26 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 |  |
| 27 | `transform` | 71.4% | 50 | 70 | 20 |  |
| 28 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 29 | `point` | 70.9% | 124 | 175 | 51 |  |
| 30 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 31 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 32 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 33 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 34 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 35 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 36 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 37 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 38 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 39 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 40 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 |  |
| 41 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 42 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 43 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 44 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 45 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 46 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 47 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 48 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 |  |
| 49 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 50 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 52 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 53 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 54 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 |  |
| 55 | `edittext_autosize` | 62.0% | 44 | 71 | 27 |  |
| 56 | `with` | 61.2% | 30 | 49 | 19 |  |
| 57 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 58 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 59 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 61 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 62 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 63 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 64 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 65 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 66 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 67 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 |  |
| 68 | `focusrect_property_swf6` | 58.0% | 718 | 1237 | 519 |  |
| 69 | `focusrect_property_swf7` | 58.0% | 717 | 1237 | 520 |  |
| 70 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 71 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 72 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 |  |
| 74 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 75 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 76 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 77 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 |  |
| 80 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 81 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 82 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 83 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 84 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 85 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 86 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 87 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 88 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 89 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 90 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 91 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 92 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 93 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 94 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 95 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 96 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 97 | `string_paths_basic` | 50.0% | 2 | 4 | 2 |  |
| 98 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 |  |
| 99 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 100 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 101 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**8 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `device_font_spacing` | 13.2s |  |
| 2 | `duplicate_movie_clip_drawing` | 6.0s |  |
| 3 | `goto_methods` | 6.6s |  |
| 4 | `init_object_order` | 6.4s |  |
| 5 | `path_string` | 6.6s |  |
| 6 | `register_and_init_order` | 6.8s |  |
| 7 | `register_class` | 6.3s |  |
| 8 | `swf4_actions_coercion_order` | 6.1s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**4 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bitmap_data_pixeldissolve` | runtime timeout (>10s) | 15.1s |  |
| 2 | `parse_float` | runtime timeout (>10s) | 15.2s |  |
| 3 | `timeout` | runtime timeout (>10s) | 14.3s |  |
| 4 | `try_catch_finally` | runtime timeout (>10s) | 14.4s |  |

## All Output Mismatches

**409 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `string_methods_swfv5` | 99.6% | 274/275 | 275 | 275 |  |
| 2 | `string_methods` | 98.2% | 280/285 | 285 | 285 |  |
| 3 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 |  |
| 4 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 5 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 6 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 7 | `xml_ignore_comments` | 85.7% | 18/21 | 21 | 21 |  |
| 8 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 9 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 10 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 11 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 12 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 13 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 14 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 15 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 |  |
| 16 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 17 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 18 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 19 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 20 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 21 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 22 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 23 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 24 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 |  |
| 25 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 |  |
| 26 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 |  |
| 27 | `transform` | 71.4% | 50/70 | 70 | 70 |  |
| 28 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 29 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 30 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 31 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 32 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 33 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 34 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 35 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 36 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 37 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 38 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 39 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 40 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 |  |
| 41 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 42 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 43 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 44 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 45 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 46 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 47 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 48 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 |  |
| 49 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 50 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 52 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 53 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 54 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 |  |
| 55 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 |  |
| 56 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 57 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 58 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 59 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 60 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 61 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 62 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 63 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 64 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 65 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 66 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 67 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 |  |
| 68 | `focusrect_property_swf6` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 69 | `focusrect_property_swf7` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 70 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 71 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 72 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 |  |
| 74 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 75 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 76 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 77 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 78 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 |  |
| 79 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 |  |
| 80 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 81 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 82 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 83 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 84 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 85 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 86 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 87 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 88 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 89 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 90 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 91 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 92 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 93 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 94 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 95 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 96 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 97 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 |  |
| 98 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 |  |
| 99 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 100 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 101 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 102 | `edittext_html_swf6` | 49.1% | 2640/5377 | 5377 | 5377 |  |
| 103 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 104 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 105 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 106 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 107 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 108 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 109 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 110 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 111 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 112 | `edittext_html_swf7` | 42.2% | 2268/5377 | 5377 | 5377 |  |
| 113 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 114 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 115 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 116 | `edittext_html_swf8` | 39.4% | 2118/5377 | 5377 | 5377 |  |
| 117 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 118 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 119 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 120 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 121 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 122 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 123 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 124 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 125 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 126 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 127 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 128 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 129 | `string_paths_other` | 30.6% | 11/36 | 28 | 36 |  |
| 130 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 131 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 132 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 133 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 134 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 135 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 136 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 137 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 138 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 139 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 140 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 141 | `edittext_stylesheet` | 24.3% | 79/325 | 325 | 325 |  |
| 142 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 143 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 144 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 145 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 146 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 |  |
| 147 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 148 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 149 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 150 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 151 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 152 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 153 | `focusrect_property_swf5` | 19.3% | 239/1237 | 1236 | 1237 |  |
| 154 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 155 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 156 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 157 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 158 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 159 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 160 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 161 | `unload` | 15.4% | 8/52 | 48 | 52 |  |
| 162 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 163 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 164 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 165 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 166 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 167 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 168 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 169 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 170 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 171 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 172 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 173 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 174 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 175 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 176 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 |  |
| 177 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 178 | `xml_socket` | 12.5% | 1/8 | 1 | 8 |  |
| 179 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 180 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 181 | `load_vars` | 11.4% | 4/35 | 26 | 35 |  |
| 182 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 |  |
| 183 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 184 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 |  |
| 185 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 |  |
| 186 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 187 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 188 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 189 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 190 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 191 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 192 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 193 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 194 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 195 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 196 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 197 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 198 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 199 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 200 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 201 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 202 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 203 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 204 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 205 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 206 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 207 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 208 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 209 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 210 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 211 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 212 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 213 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 214 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 215 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 217 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 218 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 219 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 220 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 |  |
| 221 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 222 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 223 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 224 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 225 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 226 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 |  |
| 227 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 228 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 229 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 230 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 231 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 232 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 233 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 234 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 235 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 236 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 237 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 238 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 239 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 240 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 241 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 242 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 243 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 244 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 245 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 246 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 247 | `global_proto_decls` | 0.1% | 4/4497 | 95 | 4497 |  |
| 248 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 249 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 250 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 251 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 252 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 254 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 255 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 256 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 257 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 258 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 259 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 260 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 261 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 262 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 263 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 264 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 265 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 266 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 267 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 268 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 269 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 270 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 271 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 272 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 273 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 274 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 275 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 277 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 278 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 279 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 281 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 283 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 284 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 285 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 286 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 287 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 288 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 289 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 290 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 291 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 292 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 293 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 294 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 295 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 296 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 297 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 298 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 299 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 300 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 301 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 302 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 303 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 304 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 305 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 306 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 307 | `global_proto_decls_delete` | 0.0% | 0/4158 | 24 | 4158 |  |
| 308 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 309 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 310 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 312 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 313 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 315 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 316 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 317 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 319 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 320 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 321 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 322 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 323 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 324 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 325 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 326 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 327 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 328 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 329 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 330 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 331 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 332 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 333 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 334 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 335 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 336 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 337 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 339 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 340 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 342 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 343 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 344 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 345 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 346 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 347 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 348 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 |  |
| 349 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 |  |
| 350 | `native_objects_swf8` | 0.0% | 0/186 | 186 | 84 |  |
| 351 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 352 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 353 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 354 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 355 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 356 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 357 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 358 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 359 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 360 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 361 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 362 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 363 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 364 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 365 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 366 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 367 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 368 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 369 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 370 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 371 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 372 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 373 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 374 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 375 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 376 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 377 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 378 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 379 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 380 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 381 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 382 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 383 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 384 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 385 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 386 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 387 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 388 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 389 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 390 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 391 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 392 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 393 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 394 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 395 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 396 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 397 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 398 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 399 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 400 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 401 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 402 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 403 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 404 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 405 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 406 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 407 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 408 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 409 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
