# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-15 01:31 UTC

**Git SHA**: `711e25ad1e`

**Run Duration**: 44m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **196** (31.7%) |
| Failing | 423 |
| Total expected lines | 90073 |
| Matching lines | 39481 (43.8%) |
| Mismatched lines | 50592 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 413 | 97.6% |
| Timeout | 5 | 1.2% |
| Runtime Segfault | 5 | 1.2% |

## Passing Tests

**196 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 3.9s |  |
| 2 | `action_to_integer` | 28 | 3.7s |  |
| 3 | `add` | 28 | 3.7s |  |
| 4 | `add2` | 354 | 4.1s | [investigation](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 3.7s |  |
| 6 | `add_swf5` | 28 | 3.7s |  |
| 7 | `array_concat` | 98 | 3.9s |  |
| 8 | `array_constructor` | 30 | 3.8s |  |
| 9 | `array_length` | 42 | 3.9s |  |
| 10 | `array_properties` | 36 | 3.8s |  |
| 11 | `array_slice` | 34 | 3.9s |  |
| 12 | `array_splice` | 207 | 4.5s |  |
| 13 | `array_trivial` | 209 | 4.3s |  |
| 14 | `as1_constructor_v6` | 35 | 3.8s |  |
| 15 | `as1_constructor_v7` | 35 | 3.8s |  |
| 16 | `as_broadcaster_initialize` | 10 | 3.7s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 3.7s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 3.7s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 3.7s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 3.7s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 3.7s |  |
| 22 | `as_transformed_flag` | 20 | 3.8s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 3.6s |  |
| 24 | `bitand` | 1058 | 10.3s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.0s |  |
| 26 | `bitmap_data_fillrect` | 0 | 3.9s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 3.7s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 3.6s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 4.4s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.2s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.7s |  |
| 32 | `bitor` | 1058 | 10.4s |  |
| 33 | `biturshift` | 14 | 4.0s |  |
| 34 | `biturshift_swf8` | 14 | 3.7s |  |
| 35 | `bitxor` | 1058 | 10.6s |  |
| 36 | `call_method_empty_name` | 1 | 3.6s |  |
| 37 | `capabilities_resolution` | 8 | 3.6s |  |
| 38 | `catch_references_registers` | 2 | 3.7s |  |
| 39 | `conflicting_instance_names` | 23 | 3.8s |  |
| 40 | `define_function2` | 8 | 3.6s |  |
| 41 | `define_function2_preload` | 13 | 3.6s |  |
| 42 | `define_function2_preload_order` | 4 | 3.7s |  |
| 43 | `define_function_case_sensitive` | 2 | 3.7s |  |
| 44 | `delete` | 3 | 3.7s |  |
| 45 | `display_object_properties` | 2 | 3.7s |  |
| 46 | `divide_swf4` | 107 | 3.8s |  |
| 47 | `do_init_action` | 3 | 3.7s |  |
| 48 | `edittext_antialiastype` | 296 | 4.4s |  |
| 49 | `edittext_autosize_setter` | 20 | 3.8s |  |
| 50 | `edittext_default_format` | 221 | 4.0s |  |
| 51 | `edittext_default_format_empty` | 95 | 3.8s |  |
| 52 | `edittext_default_format_font_style` | 335 | 3.9s |  |
| 53 | `edittext_password` | 5 | 3.8s |  |
| 54 | `equals` | 32 | 3.8s |  |
| 55 | `equals2_swf5` | 926 | 11.8s |  |
| 56 | `equals2_swf6` | 926 | 12.1s |  |
| 57 | `equals2_swf7` | 926 | 12.1s |  |
| 58 | `equals_swf4` | 665 | 7.3s |  |
| 59 | `equals_swf4_alt` | 32 | 3.8s |  |
| 60 | `equals_swf5` | 32 | 3.7s |  |
| 61 | `error` | 58 | 3.9s |  |
| 62 | `escape` | 14 | 3.7s |  |
| 63 | `execution_order1` | 5 | 3.8s |  |
| 64 | `execution_order2` | 7 | 3.8s |  |
| 65 | `execution_order3` | 4 | 3.7s |  |
| 66 | `focusrect_mouse_swf8` | 0 | 3.9s |  |
| 67 | `focusrect_mouse_swf9` | 0 | 3.9s |  |
| 68 | `focusrect_swf5` | 6 | 4.1s |  |
| 69 | `get_variable_in_scope` | 29 | 4.1s |  |
| 70 | `getproperty` | 28 | 4.0s |  |
| 71 | `getproperty_swf4` | 28 | 4.0s |  |
| 72 | `getproperty_swf5` | 28 | 3.9s |  |
| 73 | `global_array` | 3 | 3.9s |  |
| 74 | `global_is_bare` | 7 | 3.9s |  |
| 75 | `goto_advance1` | 6 | 4.0s |  |
| 76 | `goto_advance2` | 2 | 4.0s |  |
| 77 | `goto_both_ways1` | 3 | 5.3s |  |
| 78 | `goto_both_ways2` | 3 | 3.6s |  |
| 79 | `goto_execution_order` | 2 | 3.6s |  |
| 80 | `goto_execution_order2` | 2 | 3.6s |  |
| 81 | `goto_frame_number` | 3 | 3.7s |  |
| 82 | `goto_rewind1` | 1 | 3.7s |  |
| 83 | `goto_rewind2` | 3 | 3.8s |  |
| 84 | `goto_rewind3` | 2 | 3.6s |  |
| 85 | `greater_swf6` | 1175 | 12.3s |  |
| 86 | `greater_swf7` | 1175 | 12.3s |  |
| 87 | `greaterthan_swf5` | 1 | 3.6s |  |
| 88 | `greaterthan_swf8` | 1 | 3.6s |  |
| 89 | `has_own_property` | 32 | 3.7s |  |
| 90 | `infinite_recursion_function` | 4 | 3.6s | [investigation](ruffle-tests/_investigation/infinite_recursion_function.md) |
| 91 | `infinite_recursion_function_in_setter` | 131 | 3.6s |  |
| 92 | `infinite_recursion_virtual_property` | 67 | 3.6s |  |
| 93 | `init_array_invalid` | 4 | 3.6s |  |
| 94 | `init_object_invalid` | 4 | 3.6s |  |
| 95 | `issue_1086` | 1 | 3.6s |  |
| 96 | `issue_1671` | 0 | 3.6s |  |
| 97 | `issue_2166` | 9 | 3.7s |  |
| 98 | `issue_3446` | 1 | 3.6s |  |
| 99 | `issue_4377` | 2 | 3.6s |  |
| 100 | `issue_710` | 4 | 3.6s |  |
| 101 | `issue_768` | 3 | 3.6s | [investigation](ruffle-tests/_investigation/issue_768.md) |
| 102 | `lessthan` | 41 | 3.7s |  |
| 103 | `lessthan2_swf5` | 1226 | 12.7s |  |
| 104 | `lessthan2_swf6` | 1226 | 12.8s |  |
| 105 | `lessthan2_swf7` | 1226 | 12.8s |  |
| 106 | `lessthan_swf4` | 902 | 8.8s |  |
| 107 | `lessthan_swf4_alt` | 41 | 3.7s |  |
| 108 | `lessthan_swf5` | 41 | 3.7s |  |
| 109 | `logical_ops_swf4` | 90 | 3.8s |  |
| 110 | `logical_ops_swf8` | 108 | 3.8s |  |
| 111 | `looping` | 6 | 3.7s |  |
| 112 | `mask_reapply` | 0 | 3.7s |  |
| 113 | `mask_with_drawing` | 0 | 3.7s |  |
| 114 | `mouse_wheel_enabled` | 2 | 3.7s |  |
| 115 | `movieclip_begin_gradient_fill` | 0 | 4.3s |  |
| 116 | `movieclip_line_gradient_style` | 0 | 4.3s |  |
| 117 | `movieclip_name_from_timeline` | 13 | 3.7s |  |
| 118 | `movieclip_prototype_extension` | 5 | 3.8s |  |
| 119 | `nested_textfields_in_buttons` | 0 | 3.7s |  |
| 120 | `netstream_play_flv_screen` | 0 | 31.7s |  |
| 121 | `new_method_wrap` | 4 | 3.7s |  |
| 122 | `new_object_wrap` | 4 | 3.7s |  |
| 123 | `o` | 3 | 3.7s |  |
| 124 | `object_constructor` | 33 | 3.8s |  |
| 125 | `object_function` | 32 | 3.9s |  |
| 126 | `object_string_coerce_swf5` | 62 | 3.9s |  |
| 127 | `primitive_instanceof` | 37 | 3.8s |  |
| 128 | `prototype_delete` | 12 | 3.8s |  |
| 129 | `recursive_prototypes` | 0 | 3.7s |  |
| 130 | `sandbox_type_local_file` | 1 | 3.5s |  |
| 131 | `set_variable_scope` | 58 | 3.8s |  |
| 132 | `single_frame` | 1 | 3.6s |  |
| 133 | `sound_start_load` | 0 | 3.6s |  |
| 134 | `stage_object_properties_get_var` | 5 | 3.6s |  |
| 135 | `strictequals_swf6` | 902 | 9.5s |  |
| 136 | `strictly_equals` | 7 | 3.6s |  |
| 137 | `string_coercion` | 117 | 4.2s | [investigation](ruffle-tests/_investigation/string_coercion.md) |
| 138 | `string_paths_keyevents` | 0 | 3.6s |  |
| 139 | `string_paths_timer` | 0 | 3.6s |  |
| 140 | `swf4_actions_bool` | 96 | 3.7s |  |
| 141 | `swf4_bool` | 4 | 3.6s |  |
| 142 | `swf4_function_calls` | 7 | 3.8s |  |
| 143 | `swf5_encoding` | 3 | 3.6s |  |
| 144 | `tab_ordering_properties_tab_index_edge_case` | 4 | 3.7s |  |
| 145 | `target_path` | 14 | 3.7s |  |
| 146 | `text_format` | 1146 | 4.1s |  |
| 147 | `text_format_display` | 21 | 3.8s |  |
| 148 | `text_format_font_max_length` | 2 | 3.7s |  |
| 149 | `text_format_rounding_swf7` | 840 | 4.0s |  |
| 150 | `text_format_rounding_swf8` | 840 | 4.0s |  |
| 151 | `textfield_background_color` | 11 | 3.7s |  |
| 152 | `textfield_border_color` | 11 | 3.7s |  |
| 153 | `textfield_maxchars` | 3 | 3.8s |  |
| 154 | `textfield_properties` | 44 | 3.9s |  |
| 155 | `textfield_props_swf6` | 210 | 4.6s |  |
| 156 | `textfield_props_swf7` | 210 | 4.6s |  |
| 157 | `textfield_props_swf8` | 210 | 4.6s |  |
| 158 | `textfield_text` | 7 | 3.7s |  |
| 159 | `textfield_variable` | 81 | 4.2s |  |
| 160 | `this_swf7` | 41 | 3.7s | [investigation](ruffle-tests/_investigation/this_swf7.md) |
| 161 | `timeline_function_def` | 7 | 3.8s |  |
| 162 | `try_finally_simple` | 16 | 3.8s |  |
| 163 | `typeof` | 22 | 3.8s |  |
| 164 | `typeof_globals` | 7 | 3.7s |  |
| 165 | `uncaught_exception` | 1 | 3.7s |  |
| 166 | `uncaught_exception_bubbled` | 1 | 3.7s |  |
| 167 | `undefined_to_string_swf6` | 4 | 3.7s |  |
| 168 | `unescape` | 43 | 3.8s |  |
| 169 | `use_hand_cursor` | 8 | 3.7s |  |
| 170 | `variable_args` | 5 | 3.9s |  |
| 171 | `waitforframe` | 7 | 3.7s |  |
| 172 | `waitforframe2` | 16 | 3.8s |  |
| 173 | `with_return` | 2 | 3.7s |  |
| 174 | `xml` | 15 | 3.7s |  |
| 175 | `xml_append_child` | 28 | 3.9s |  |
| 176 | `xml_append_child_with_parent` | 20 | 3.8s |  |
| 177 | `xml_attributes_read` | 4 | 3.8s |  |
| 178 | `xml_cdata` | 11 | 3.7s |  |
| 179 | `xml_clone_expandos` | 19 | 3.8s |  |
| 180 | `xml_first_last_child` | 8 | 3.8s |  |
| 181 | `xml_has_child_nodes` | 3 | 3.7s |  |
| 182 | `xml_idmap` | 21 | 3.9s |  |
| 183 | `xml_ignore_white` | 34 | 3.9s |  |
| 184 | `xml_insert_before` | 20 | 3.8s |  |
| 185 | `xml_inspect_createmethods` | 15 | 3.8s |  |
| 186 | `xml_inspect_doctype` | 7 | 3.8s |  |
| 187 | `xml_inspect_parsexml` | 62 | 3.8s |  |
| 188 | `xml_inspect_xmldecl` | 7 | 3.8s |  |
| 189 | `xml_namespaces` | 203 | 3.8s |  |
| 190 | `xml_parent_and_child` | 5 | 3.8s |  |
| 191 | `xml_remove_node` | 22 | 3.9s |  |
| 192 | `xml_reparenting` | 14 | 3.8s |  |
| 193 | `xml_siblings` | 10 | 3.8s |  |
| 194 | `xml_to_string_comment` | 1 | 3.7s |  |
| 195 | `xml_unescaping` | 23 | 4.0s |  |
| 196 | `xmlnode_proto` | 1 | 3.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**94 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf7_case_sensitive` | 90.9% | 40 | 44 | 4 |  |
| 2 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 |  |
| 3 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 4 | `xml_ignore_comments` | 85.7% | 18 | 21 | 3 |  |
| 5 | `xml_to_string` | 84.6% | 11 | 13 | 2 |  |
| 6 | `object_prototypes` | 83.8% | 62 | 74 | 12 |  |
| 7 | `stage_object_children` | 81.9% | 68 | 83 | 15 |  |
| 8 | `local_to_global` | 81.6% | 40 | 49 | 9 |  |
| 9 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 |  |
| 10 | `target_clip_removed` | 80.0% | 4 | 5 | 1 |  |
| 11 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 |  |
| 12 | `as2_oop` | 76.9% | 10 | 13 | 3 |  |
| 13 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 |  |
| 14 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 |  |
| 15 | `attach_movie` | 72.9% | 43 | 59 | 16 |  |
| 16 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 |  |
| 17 | `extends_native_type` | 72.7% | 8 | 11 | 3 |  |
| 18 | `matrix` | 71.9% | 123 | 171 | 48 |  |
| 19 | `globals_swf6` | 71.4% | 217 | 304 | 87 |  |
| 20 | `point` | 70.9% | 124 | 175 | 51 |  |
| 21 | `prototype_properties` | 70.6% | 12 | 17 | 5 |  |
| 22 | `globals_swf7` | 70.4% | 214 | 304 | 90 |  |
| 23 | `rectangle` | 69.3% | 516 | 745 | 229 |  |
| 24 | `register_underflow` | 69.2% | 18 | 26 | 8 |  |
| 25 | `globals_swf5` | 69.1% | 210 | 304 | 94 |  |
| 26 | `array_sort` | 68.9% | 111 | 161 | 50 |  |
| 27 | `movieclip_blend_mode_property` | 68.6% | 24 | 35 | 11 |  |
| 28 | `transform` | 68.6% | 48 | 70 | 22 |  |
| 29 | `stage_object_properties` | 68.5% | 165 | 241 | 76 |  |
| 30 | `stage_object_properties_swf6` | 68.4% | 158 | 231 | 73 |  |
| 31 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 |  |
| 32 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 |  |
| 34 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 |  |
| 36 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 37 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 38 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65 | 98 | 33 |  |
| 40 | `is_prototype_of` | 66.3% | 59 | 89 | 30 |  |
| 41 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 42 | `swf6_case_insensitive` | 65.9% | 29 | 44 | 15 |  |
| 43 | `edittext_scroll` | 64.8% | 35 | 54 | 19 |  |
| 44 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 |  |
| 45 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 |  |
| 47 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171 | 275 | 104 |  |
| 49 | `with` | 61.2% | 30 | 49 | 19 |  |
| 50 | `edittext_width_height` | 61.2% | 63 | 103 | 40 |  |
| 51 | `arguments` | 60.6% | 77 | 127 | 50 |  |
| 52 | `string_methods` | 60.4% | 172 | 285 | 113 |  |
| 53 | `edittext_align` | 60.0% | 36 | 60 | 24 |  |
| 54 | `edittext_bullet` | 60.0% | 18 | 30 | 12 |  |
| 55 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 |  |
| 56 | `edittext_margins` | 60.0% | 15 | 25 | 10 |  |
| 57 | `edittext_newlines` | 60.0% | 18 | 30 | 12 |  |
| 58 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 |  |
| 59 | `edittext_underline` | 60.0% | 24 | 40 | 16 |  |
| 60 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 61 | `remove_movie_clip` | 58.6% | 17 | 29 | 12 |  |
| 62 | `boxed_primitives` | 58.3% | 14 | 24 | 10 |  |
| 63 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 64 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 |  |
| 65 | `date` | 57.1% | 3617 | 6335 | 2718 |  |
| 66 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 67 | `with_variable_scopes` | 55.8% | 24 | 43 | 19 |  |
| 68 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 69 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 70 | `edittext_autosize` | 54.9% | 39 | 71 | 32 |  |
| 71 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53 | 99 | 46 |  |
| 73 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 |  |
| 74 | `sound_props_swf5` | 52.9% | 36 | 68 | 32 |  |
| 75 | `xml_getbytes` | 52.9% | 9 | 17 | 8 |  |
| 76 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 77 | `string_methods_negative_args` | 52.7% | 127 | 241 | 114 |  |
| 78 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 79 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 |  |
| 80 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 81 | `globals_swf8` | 51.0% | 155 | 304 | 149 |  |
| 82 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 |  |
| 83 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 84 | `issue_1906` | 50.0% | 2 | 4 | 2 |  |
| 85 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 87 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 88 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 89 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 90 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 91 | `localconnection_properties` | 50.0% | 4 | 8 | 4 |  |
| 92 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 |  |
| 94 | `unloadmovie` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `duplicate_movie_clip_drawing` | 5.7s |  |
| 2 | `goto_methods` | 6.1s |  |
| 3 | `path_string` | 6.3s |  |
| 4 | `swf4_actions_coercion_order` | 5.2s |  |
| 5 | `tab_ordering_tabbable` | 5.9s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**5 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bitmap_data_pixeldissolve` | runtime timeout (>10s) | 14.8s |  |
| 2 | `device_font_spacing` | runtime timeout (>10s) | 13.9s |  |
| 3 | `parse_float` | runtime timeout (>10s) | 14.8s |  |
| 4 | `timeout` | runtime timeout (>10s) | 15.2s |  |
| 5 | `try_catch_finally` | runtime timeout (>10s) | 14.2s |  |

## All Output Mismatches

**413 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf7_case_sensitive` | 90.9% | 40/44 | 44 | 44 |  |
| 2 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 |  |
| 3 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 4 | `xml_ignore_comments` | 85.7% | 18/21 | 21 | 21 |  |
| 5 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 |  |
| 6 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 |  |
| 7 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 |  |
| 8 | `local_to_global` | 81.6% | 40/49 | 49 | 49 |  |
| 9 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 |  |
| 10 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 |  |
| 11 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 |  |
| 12 | `as2_oop` | 76.9% | 10/13 | 13 | 13 |  |
| 13 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 |  |
| 14 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 |  |
| 15 | `attach_movie` | 72.9% | 43/59 | 54 | 59 |  |
| 16 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 |  |
| 17 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 |  |
| 18 | `matrix` | 71.9% | 123/171 | 171 | 171 |  |
| 19 | `globals_swf6` | 71.4% | 217/304 | 304 | 304 |  |
| 20 | `point` | 70.9% | 124/175 | 175 | 175 |  |
| 21 | `prototype_properties` | 70.6% | 12/17 | 17 | 17 |  |
| 22 | `globals_swf7` | 70.4% | 214/304 | 304 | 304 |  |
| 23 | `rectangle` | 69.3% | 516/745 | 745 | 745 |  |
| 24 | `register_underflow` | 69.2% | 18/26 | 26 | 26 |  |
| 25 | `globals_swf5` | 69.1% | 210/304 | 304 | 304 |  |
| 26 | `array_sort` | 68.9% | 111/161 | 161 | 161 |  |
| 27 | `movieclip_blend_mode_property` | 68.6% | 24/35 | 35 | 35 |  |
| 28 | `transform` | 68.6% | 48/70 | 70 | 70 |  |
| 29 | `stage_object_properties` | 68.5% | 165/241 | 241 | 241 |  |
| 30 | `stage_object_properties_swf6` | 68.4% | 158/231 | 231 | 231 |  |
| 31 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 |  |
| 32 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 |  |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 |  |
| 34 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 37 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 38 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 39 | `movieclip_depth_methods` | 66.3% | 65/98 | 98 | 98 |  |
| 40 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 |  |
| 41 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 42 | `swf6_case_insensitive` | 65.9% | 29/44 | 44 | 42 |  |
| 43 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 |  |
| 44 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 |  |
| 45 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 |  |
| 46 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 |  |
| 47 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 |  |
| 48 | `string_methods_swfv5` | 62.2% | 171/275 | 275 | 275 |  |
| 49 | `with` | 61.2% | 30/49 | 47 | 49 |  |
| 50 | `edittext_width_height` | 61.2% | 63/103 | 103 | 103 |  |
| 51 | `arguments` | 60.6% | 77/127 | 92 | 127 |  |
| 52 | `string_methods` | 60.4% | 172/285 | 285 | 285 |  |
| 53 | `edittext_align` | 60.0% | 36/60 | 60 | 60 |  |
| 54 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 |  |
| 55 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 |  |
| 56 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 |  |
| 57 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 |  |
| 58 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 |  |
| 59 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 |  |
| 60 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 61 | `remove_movie_clip` | 58.6% | 17/29 | 29 | 29 |  |
| 62 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 |  |
| 63 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 64 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 |  |
| 65 | `date` | 57.1% | 3617/6335 | 6335 | 6335 |  |
| 66 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 67 | `with_variable_scopes` | 55.8% | 24/43 | 43 | 43 |  |
| 68 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 69 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 70 | `edittext_autosize` | 54.9% | 39/71 | 71 | 71 |  |
| 71 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 |  |
| 72 | `movieclip_focusenabled` | 53.5% | 53/99 | 99 | 99 |  |
| 73 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 |  |
| 74 | `sound_props_swf5` | 52.9% | 36/68 | 67 | 68 |  |
| 75 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 |  |
| 76 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 77 | `string_methods_negative_args` | 52.7% | 127/241 | 241 | 240 |  |
| 78 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 79 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 |  |
| 80 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 81 | `globals_swf8` | 51.0% | 155/304 | 304 | 304 |  |
| 82 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 |  |
| 83 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 84 | `issue_1906` | 50.0% | 2/4 | 4 | 4 |  |
| 85 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 87 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 88 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 89 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 90 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 91 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 |  |
| 92 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 93 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 |  |
| 94 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 |  |
| 95 | `is_finite` | 49.0% | 24/49 | 48 | 49 |  |
| 96 | `is_finite_swf6` | 49.0% | 24/49 | 48 | 49 |  |
| 97 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 98 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 |  |
| 99 | `sound_props_swf6` | 45.6% | 31/68 | 68 | 68 |  |
| 100 | `new_object_enumerate` | 44.4% | 4/9 | 9 | 7 |  |
| 101 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 102 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 |  |
| 103 | `stage_scale_mode` | 43.6% | 17/39 | 38 | 39 |  |
| 104 | `named_shapes` | 42.9% | 6/14 | 14 | 14 |  |
| 105 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 |  |
| 106 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 |  |
| 107 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 108 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 |  |
| 109 | `edittext_html_swf6` | 37.5% | 2016/5377 | 5377 | 5377 |  |
| 110 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 111 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 |  |
| 112 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 |  |
| 113 | `create_empty_movie_clip` | 33.3% | 1/3 | 2 | 3 |  |
| 114 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 |  |
| 115 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 |  |
| 116 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 |  |
| 117 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 118 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 |  |
| 119 | `math_min_max` | 31.7% | 32/101 | 95 | 101 |  |
| 120 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 121 | `edittext_html_condensewhite_swf7` | 30.2% | 94/311 | 311 | 311 |  |
| 122 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 |  |
| 123 | `bitmap_data_hittest` | 29.5% | 39/132 | 131 | 132 |  |
| 124 | `edittext_html_condensewhite_swf8` | 29.3% | 91/311 | 311 | 311 |  |
| 125 | `define_local_with_paths` | 27.8% | 15/54 | 39 | 54 |  |
| 126 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 |  |
| 127 | `enumerate` | 26.6% | 17/64 | 58 | 64 |  |
| 128 | `edittext_html_swf7` | 25.7% | 1380/5377 | 5377 | 5377 |  |
| 129 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 130 | `edittext_html_swf8` | 25.4% | 1365/5377 | 5377 | 5377 |  |
| 131 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 |  |
| 132 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 133 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 134 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 135 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 |  |
| 136 | `string_paths_basic` | 25.0% | 1/4 | 4 | 4 |  |
| 137 | `string_paths_variable_alias` | 25.0% | 1/4 | 4 | 4 |  |
| 138 | `textfield_props_swf5` | 24.0% | 42/175 | 141 | 175 |  |
| 139 | `default_names` | 23.1% | 12/52 | 34 | 52 |  |
| 140 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 |  |
| 141 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 142 | `edittext_stylesheet` | 20.3% | 66/325 | 325 | 325 |  |
| 143 | `add_property` | 20.0% | 3/15 | 15 | 15 |  |
| 144 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 |  |
| 145 | `prototype_enumerate` | 20.0% | 1/5 | 4 | 5 |  |
| 146 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 |  |
| 147 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 148 | `movieclip_default_state` | 18.8% | 13/69 | 69 | 69 |  |
| 149 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 150 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 |  |
| 151 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 152 | `focusrect_property_swf6` | 17.1% | 211/1237 | 1236 | 1237 |  |
| 153 | `focusrect_property_swf7` | 17.0% | 210/1237 | 1236 | 1237 |  |
| 154 | `focusrect_property_swf5` | 16.9% | 209/1237 | 1236 | 1237 |  |
| 155 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 156 | `execution_order4` | 16.7% | 2/12 | 12 | 12 |  |
| 157 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 158 | `string_paths_other` | 16.7% | 6/36 | 28 | 36 |  |
| 159 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 |  |
| 160 | `watch` | 15.4% | 18/117 | 101 | 117 |  |
| 161 | `as_broadcaster` | 14.6% | 6/41 | 25 | 41 |  |
| 162 | `color_transform` | 14.6% | 7/48 | 37 | 48 |  |
| 163 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 164 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 165 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 |  |
| 166 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 |  |
| 167 | `textsnapshot_props_swf5` | 14.3% | 8/56 | 37 | 56 |  |
| 168 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 |  |
| 169 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 170 | `movieclip_getbounds` | 13.1% | 25/191 | 107 | 191 |  |
| 171 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 |  |
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
| 186 | `unload` | 9.6% | 5/52 | 48 | 52 |  |
| 187 | `selection` | 9.3% | 42/454 | 244 | 454 |  |
| 188 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 |  |
| 189 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 |  |
| 190 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 |  |
| 191 | `extends_chain` | 9.0% | 12/134 | 122 | 134 |  |
| 192 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 193 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 194 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 |  |
| 195 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 |  |
| 196 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 197 | `define_local` | 7.4% | 2/27 | 26 | 27 |  |
| 198 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 |  |
| 199 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 200 | `hittest_lockroot` | 6.7% | 1/15 | 15 | 15 |  |
| 201 | `init_object_order` | 6.7% | 1/15 | 5 | 15 |  |
| 202 | `printjob_props_swf6` | 6.7% | 3/45 | 35 | 45 |  |
| 203 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 |  |
| 204 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 205 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 |  |
| 206 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 207 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 208 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 209 | `clip_events` | 5.3% | 1/19 | 5 | 19 |  |
| 210 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 211 | `context_menu` | 5.1% | 2/39 | 11 | 39 |  |
| 212 | `stylesheet` | 4.9% | 14/283 | 123 | 283 |  |
| 213 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 |  |
| 214 | `focus_visibility_change` | 4.4% | 2/45 | 27 | 45 |  |
| 215 | `printjob_props_swf7` | 4.4% | 2/45 | 35 | 45 |  |
| 216 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 217 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 218 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 219 | `hittest_morph` | 4.3% | 3/70 | 30 | 70 |  |
| 220 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 |  |
| 221 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 222 | `this_scoping` | 3.8% | 2/52 | 35 | 52 |  |
| 223 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 |  |
| 224 | `textsnapshot_props_swf6` | 3.6% | 2/56 | 38 | 56 |  |
| 225 | `color` | 3.4% | 2/59 | 59 | 57 |  |
| 226 | `focus_remove` | 3.0% | 1/33 | 15 | 33 |  |
| 227 | `register_class` | 3.0% | 2/66 | 27 | 66 |  |
| 228 | `asnew` | 2.9% | 1/34 | 3 | 34 |  |
| 229 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 |  |
| 230 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 |  |
| 231 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 |  |
| 232 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 233 | `math_swf6` | 1.9% | 10/530 | 458 | 530 |  |
| 234 | `math_swf7` | 1.9% | 10/530 | 458 | 530 |  |
| 235 | `math_swf8` | 1.9% | 10/530 | 458 | 530 |  |
| 236 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 237 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 238 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 239 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 |  |
| 240 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 |  |
| 241 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 242 | `movieclip_gettextsnapshot` | 0.9% | 1/112 | 42 | 112 |  |
| 243 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 |  |
| 244 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 245 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 246 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 |  |
| 247 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 248 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 249 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 |  |
| 250 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 251 | `global_instance_decls` | 0.1% | 1/758 | 141 | 758 |  |
| 252 | `global_proto_decls` | 0.0% | 2/4497 | 93 | 4497 |  |
| 253 | `array_call_method` | 0.0% | 0/9 | 1 | 9 |  |
| 254 | `array_enumerate` | 0.0% | 0/4 | 4 | 4 |  |
| 255 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 256 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 257 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 |  |
| 259 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 260 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 261 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 262 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 263 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 264 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 265 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 266 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 267 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 268 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 269 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 270 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 271 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 |  |
| 272 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 |  |
| 273 | `closure_scope` | 0.0% | 0/7 | 2 | 7 |  |
| 274 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 275 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 276 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 |  |
| 277 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 278 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 279 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 281 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 |  |
| 282 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 |  |
| 283 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 |  |
| 284 | `edittext_input` | 0.0% | 0/1 | 0 | 1 |  |
| 285 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 |  |
| 286 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 |  |
| 287 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 |  |
| 288 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 |  |
| 289 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 |  |
| 290 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 291 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 |  |
| 292 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 |  |
| 293 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 |  |
| 294 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 295 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 296 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 297 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 298 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 299 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 300 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 301 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 302 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 303 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 304 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 305 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 306 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 307 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 308 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 309 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 310 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 311 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 312 | `global_proto_decls_delete` | 0.0% | 0/4158 | 22 | 4158 |  |
| 313 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 |  |
| 314 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 |  |
| 315 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 316 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 317 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 |  |
| 318 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 320 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 321 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 322 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 323 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 324 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 325 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 326 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 327 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 328 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 329 | `localconnection` | 0.0% | 0/579 | 3 | 579 |  |
| 330 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 331 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 332 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 333 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 334 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 335 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 336 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 337 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 338 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 339 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 340 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 341 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 342 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 344 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 345 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `mouse_pos` | 0.0% | 0/665 | 2 | 665 |  |
| 347 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 2 | 260 |  |
| 348 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 |  |
| 349 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 350 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 |  |
| 351 | `movieclip_library_state_values` | 0.0% | 0/78 | 3 | 78 |  |
| 352 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 |  |
| 353 | `native_objects_swf6` | 0.0% | 0/183 | 183 | 84 |  |
| 354 | `native_objects_swf7` | 0.0% | 0/183 | 183 | 84 |  |
| 355 | `native_objects_swf8` | 0.0% | 0/183 | 183 | 84 |  |
| 356 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 357 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 358 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 359 | `object_properties` | 0.0% | 0/31 | 0 | 31 |  |
| 360 | `object_resolve` | 0.0% | 0/38 | 23 | 38 |  |
| 361 | `on_construct` | 0.0% | 0/25 | 0 | 25 |  |
| 362 | `parse_int` | 0.0% | 0/65 | 65 | 64 |  |
| 363 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 |  |
| 364 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 |  |
| 365 | `printjob_props_swf5` | 0.0% | 0/45 | 34 | 45 |  |
| 366 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 |  |
| 367 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 |  |
| 368 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 |  |
| 369 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 370 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 371 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 372 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 373 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 374 | `set_interval` | 0.0% | 0/27 | 18 | 27 |  |
| 375 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 |  |
| 376 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 377 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 378 | `string_ops_swf6` | 0.0% | 0/96 | 96 | 95 |  |
| 379 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 |  |
| 380 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 |  |
| 381 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 |  |
| 382 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 |  |
| 383 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 384 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 |  |
| 385 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 386 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 387 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 388 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 389 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 390 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 391 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 392 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 393 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 394 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 395 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 396 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 397 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 398 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 |  |
| 399 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 |  |
| 400 | `tell_target` | 0.0% | 0/37 | 0 | 37 |  |
| 401 | `tell_target_invalid` | 0.0% | 0/6 | 1 | 6 |  |
| 402 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 1 | 5 |  |
| 403 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 404 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 |  |
| 405 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 |  |
| 406 | `timer_run_actions` | 0.0% | 0/18 | 2 | 18 |  |
| 407 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 |  |
| 408 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 |  |
| 409 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 |  |
| 410 | `xml_load` | 0.0% | 0/2 | 0 | 2 |  |
| 411 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 |  |
| 412 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 |  |
| 413 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 |  |
