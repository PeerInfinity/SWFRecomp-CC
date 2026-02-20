# Ruffle Test Results (Filtered)

**Date**: 2026-02-20 16:59 UTC

**Git SHA**: `6881c80008`

**Run Duration**: 73m 42s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **223** (46.6%) |
| Failing | 256 |
| Total expected lines | 71488 |
| Matching lines | 42295 (59.2%) |
| Mismatched lines | 29193 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 249 | 97.3% |
| Segfault | 6 | 2.3% |
| Timeout | 1 | 0.4% |

## Passing Tests

**223 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.5s |  |
| 2 | `action_to_integer` | 28 | 7.0s |  |
| 3 | `add` | 28 | 7.0s |  |
| 4 | `add2` | 354 | 7.0s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 6.8s |  |
| 6 | `add_swf5` | 28 | 6.8s |  |
| 7 | `arguments` | 127 | 6.9s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 6.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 6.8s |  |
| 10 | `array_constructor` | 30 | 7.0s |  |
| 11 | `array_enumerate` | 4 | 6.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 7.0s |  |
| 13 | `array_properties` | 36 | 6.8s |  |
| 14 | `array_prototyping` | 12 | 6.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 6.9s |  |
| 16 | `array_sort_random` | 443 | 7.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 7.0s |  |
| 18 | `array_trivial` | 209 | 7.0s |  |
| 19 | `as1_constructor_v6` | 35 | 7.2s |  |
| 20 | `as1_constructor_v7` | 35 | 7.2s |  |
| 21 | `as2_oop` | 13 | 6.9s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 6.7s |  |
| 23 | `as_set_prop_flags_version` | 31 | 6.8s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 6.8s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 6.8s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 6.8s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 6.8s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 6.8s |  |
| 29 | `as_transformed_flag` | 20 | 6.8s |  |
| 30 | `bad_swf_tag_past_eof` | 0 | 6.8s |  |
| 31 | `bitand` | 1058 | 9.5s |  |
| 32 | `bitmap_data_colortransform` | 0 | 7.0s |  |
| 33 | `bitmap_data_fillrect` | 0 | 7.0s |  |
| 34 | `bitmap_data_max_size_swf10` | 12 | 6.8s |  |
| 35 | `bitmap_data_max_size_swf9` | 10 | 6.8s |  |
| 36 | `bitmap_data_perlinnoise` | 0 | 7.5s |  |
| 37 | `bitmap_data_pixeldissolve_image` | 0 | 7.2s |  |
| 38 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.9s |  |
| 39 | `bitor` | 1058 | 9.5s |  |
| 40 | `biturshift` | 14 | 6.8s |  |
| 41 | `biturshift_swf8` | 14 | 7.0s |  |
| 42 | `bitxor` | 1058 | 9.4s |  |
| 43 | `call_method_empty_name` | 1 | 6.8s |  |
| 44 | `capabilities_resolution` | 8 | 6.9s |  |
| 45 | `catch_references_registers` | 2 | 6.8s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 46 | `color` | 57 | 7.0s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 47 | `color_transform` | 48 | 7.0s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 48 | `define_function2` | 8 | 6.9s |  |
| 49 | `define_function2_preload` | 13 | 6.9s |  |
| 50 | `define_function_case_sensitive` | 2 | 6.8s |  |
| 51 | `delete` | 3 | 7.0s |  |
| 52 | `divide_swf4` | 107 | 6.9s |  |
| 53 | `edittext_antialiastype` | 296 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_autosize_setter` | 20 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_default_format` | 221 | 6.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_default_format_empty` | 95 | 6.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_default_format_font_style` | 335 | 6.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_html_align_swf7` | 52 | 6.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_html_align_swf8` | 52 | 6.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_newline_stripping` | 64 | 11.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_width_height` | 103 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `equals` | 32 | 6.7s |  |
| 63 | `equals2_swf5` | 926 | 8.3s |  |
| 64 | `equals2_swf6` | 926 | 8.4s |  |
| 65 | `equals2_swf7` | 926 | 8.4s |  |
| 66 | `equals_swf4` | 665 | 7.1s |  |
| 67 | `equals_swf4_alt` | 32 | 6.7s |  |
| 68 | `equals_swf5` | 32 | 6.7s |  |
| 69 | `error` | 58 | 6.7s |  |
| 70 | `escape` | 14 | 6.7s |  |
| 71 | `execution_order3` | 4 | 6.7s |  |
| 72 | `focusrect_mouse_swf8` | 0 | 6.8s |  |
| 73 | `focusrect_mouse_swf9` | 0 | 9.8s |  |
| 74 | `focusrect_swf5` | 6 | 6.9s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 75 | `function_suppress_and_preload` | 28 | 6.8s |  |
| 76 | `get_variable_in_scope` | 29 | 6.8s |  |
| 77 | `getproperty` | 28 | 6.7s |  |
| 78 | `getproperty_swf4` | 28 | 8.7s |  |
| 79 | `getproperty_swf5` | 28 | 7.0s |  |
| 80 | `global_array` | 3 | 6.9s |  |
| 81 | `global_is_bare` | 7 | 6.9s |  |
| 82 | `globals_swf6` | 304 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `globals_swf7` | 304 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 84 | `globals_swf8` | 304 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 85 | `goto_execution_order` | 2 | 6.9s |  |
| 86 | `goto_execution_order2` | 2 | 6.9s |  |
| 87 | `goto_frame_number` | 3 | 6.9s |  |
| 88 | `greater_swf6` | 1175 | 8.8s |  |
| 89 | `greater_swf7` | 1175 | 8.8s |  |
| 90 | `greaterthan_swf5` | 1 | 6.8s |  |
| 91 | `greaterthan_swf8` | 1 | 6.8s |  |
| 92 | `has_own_property` | 32 | 6.9s |  |
| 93 | `infinite_recursion_function` | 4 | 6.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 94 | `infinite_recursion_function_in_setter` | 131 | 6.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 95 | `infinite_recursion_virtual_property` | 67 | 6.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 96 | `init_array_invalid` | 4 | 6.8s |  |
| 97 | `init_object_invalid` | 4 | 8.3s |  |
| 98 | `is_finite` | 49 | 6.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 99 | `is_finite_swf6` | 49 | 6.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 100 | `is_prototype_of` | 89 | 7.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 101 | `issue_1086` | 1 | 6.9s |  |
| 102 | `issue_1671` | 0 | 6.8s |  |
| 103 | `issue_1906` | 4 | 6.9s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 104 | `issue_2166` | 9 | 6.8s |  |
| 105 | `issue_3446` | 1 | 6.8s |  |
| 106 | `issue_4377` | 2 | 6.8s |  |
| 107 | `issue_710` | 4 | 6.8s |  |
| 108 | `issue_768` | 3 | 8.1s | [15](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 109 | `lessthan` | 41 | 7.0s |  |
| 110 | `lessthan2_swf5` | 1226 | 9.2s |  |
| 111 | `lessthan2_swf6` | 1226 | 9.2s |  |
| 112 | `lessthan2_swf7` | 1226 | 9.2s |  |
| 113 | `lessthan_swf4` | 902 | 7.7s |  |
| 114 | `lessthan_swf4_alt` | 41 | 6.9s |  |
| 115 | `lessthan_swf5` | 41 | 7.0s |  |
| 116 | `logical_ops_swf4` | 90 | 6.7s |  |
| 117 | `logical_ops_swf8` | 108 | 6.8s |  |
| 118 | `looping` | 6 | 6.8s |  |
| 119 | `mask_reapply` | 0 | 6.8s |  |
| 120 | `mask_with_drawing` | 0 | 6.9s |  |
| 121 | `math_min_max` | 101 | 7.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 122 | `matrix` | 171 | 7.1s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 123 | `movieclip_begin_gradient_fill` | 0 | 7.6s |  |
| 124 | `movieclip_blend_mode_property` | 35 | 8.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 125 | `movieclip_line_gradient_style` | 0 | 7.5s |  |
| 126 | `movieclip_prototype_extension` | 5 | 6.7s |  |
| 127 | `nested_textfields_in_buttons` | 0 | 6.7s |  |
| 128 | `netstream_play_flv_screen` | 0 | 19.5s |  |
| 129 | `new_method_wrap` | 4 | 6.8s |  |
| 130 | `new_object_enumerate` | 7 | 6.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 131 | `new_object_wrap` | 4 | 6.8s |  |
| 132 | `o` | 3 | 6.8s |  |
| 133 | `object_constructor` | 33 | 6.8s |  |
| 134 | `object_function` | 32 | 6.9s |  |
| 135 | `object_properties` | 31 | 6.9s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 136 | `object_prototypes` | 74 | 6.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 137 | `object_string_coerce_swf5` | 62 | 6.8s | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 138 | `parse_int` | 64 | 7.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 139 | `point` | 175 | 7.3s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 140 | `primitive_instanceof` | 37 | 6.8s |  |
| 141 | `primitive_type_globals` | 557 | 7.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 142 | `prototype_delete` | 12 | 6.8s |  |
| 143 | `prototype_enumerate` | 5 | 6.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 144 | `prototype_properties` | 17 | 6.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 145 | `rectangle` | 745 | 7.5s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 146 | `recursive_prototypes` | 0 | 6.7s |  |
| 147 | `sandbox_type_local_file` | 1 | 6.8s |  |
| 148 | `set_variable_scope` | 58 | 6.8s |  |
| 149 | `single_frame` | 1 | 6.7s |  |
| 150 | `sound_start_load` | 0 | 6.9s |  |
| 151 | `stage_object_enumerate` | 4 | 6.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 152 | `stage_object_properties_get_var` | 5 | 6.8s |  |
| 153 | `stage_property_representation` | 586 | 6.8s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 154 | `strictequals_swf6` | 902 | 8.4s |  |
| 155 | `strictly_equals` | 7 | 6.9s |  |
| 156 | `string_coercion` | 117 | 7.1s | [29](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 157 | `string_methods` | 285 | 7.6s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 158 | `string_methods_negative_args` | 240 | 7.0s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 159 | `string_methods_swfv5` | 275 | 7.4s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 160 | `string_ops_swf6` | 95 | 6.9s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 161 | `string_paths_keyevents` | 0 | 7.0s |  |
| 162 | `string_paths_timer` | 0 | 7.1s |  |
| 163 | `swf4_actions_bool` | 96 | 6.8s |  |
| 164 | `swf4_bool` | 4 | 6.9s |  |
| 165 | `swf4_function_calls` | 7 | 6.8s |  |
| 166 | `swf5_encoding` | 3 | 6.9s |  |
| 167 | `tab_ordering_properties_tab_index_edge_case` | 4 | 7.0s |  |
| 168 | `text_format` | 1146 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 169 | `text_format_display` | 21 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 170 | `text_format_font_max_length` | 2 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 171 | `text_format_rounding_swf7` | 840 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 172 | `text_format_rounding_swf8` | 840 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `textfield_background_color` | 11 | 6.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 174 | `textfield_border_color` | 11 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `textfield_maxchars` | 3 | 8.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `textfield_props_swf5` | 175 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `textfield_props_swf6` | 210 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `textfield_props_swf7` | 210 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `textfield_props_swf8` | 210 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `textfield_text` | 7 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `textfield_variable` | 81 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `this_swf7` | 41 | 7.0s | [34](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 183 | `timeline_function_def` | 7 | 7.1s |  |
| 184 | `try_catch_finally` | 118 | 7.0s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 185 | `try_finally_simple` | 16 | 6.9s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 186 | `typeof` | 22 | 6.9s |  |
| 187 | `typeof_globals` | 7 | 6.8s |  |
| 188 | `uncaught_exception` | 1 | 6.8s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 189 | `uncaught_exception_bubbled` | 1 | 7.1s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 190 | `undefined_to_string_swf6` | 4 | 6.9s |  |
| 191 | `unescape` | 43 | 7.0s |  |
| 192 | `use_hand_cursor` | 8 | 7.1s |  |
| 193 | `waitforframe` | 7 | 7.1s |  |
| 194 | `waitforframe2` | 16 | 6.8s |  |
| 195 | `watch` | 117 | 6.8s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 196 | `watch_virtual_property_proto` | 2 | 6.6s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 197 | `with_return` | 2 | 6.6s |  |
| 198 | `with_variable_scopes` | 43 | 6.6s | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 199 | `xml` | 15 | 6.6s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 200 | `xml_append_child` | 28 | 6.5s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 201 | `xml_append_child_with_parent` | 20 | 6.5s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 202 | `xml_cdata` | 11 | 6.7s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 203 | `xml_child_nodes_edge_cases` | 4 | 6.6s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 204 | `xml_clone_expandos` | 19 | 6.6s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 205 | `xml_first_last_child` | 8 | 6.7s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 206 | `xml_has_child_nodes` | 3 | 6.7s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 207 | `xml_idmap` | 21 | 6.7s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 208 | `xml_ignore_comments` | 21 | 6.7s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 209 | `xml_ignore_white` | 34 | 8.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 210 | `xml_insert_before` | 20 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_inspect_createmethods` | 15 | 6.9s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_inspect_doctype` | 7 | 6.9s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_inspect_parsexml` | 62 | 6.9s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_inspect_xmldecl` | 7 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_namespaces` | 203 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_parent_and_child` | 5 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_remove_node` | 22 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_reparenting` | 14 | 6.9s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_siblings` | 10 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_to_string` | 13 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_to_string_comment` | 1 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_unescaping` | 23 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xmlnode_proto` | 1 | 6.8s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**78 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522 | 530 | 8 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522 | 530 | 8 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522 | 530 | 8 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `swf7_case_sensitive` | 97.7% | 43 | 44 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `textfield_properties` | 97.7% | 43 | 44 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `globals_swf5` | 96.4% | 293 | 304 | 11 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_depth_methods` | 95.9% | 94 | 98 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 9 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 10 | `transform` | 92.9% | 65 | 70 | 5 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 11 | `with` | 91.8% | 45 | 49 | 4 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 13 | `movieclip_get_instance_at_depth` | 89.3% | 25 | 28 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `movieclip_name_from_timeline` | 84.6% | 11 | 13 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `local_to_global` | 83.7% | 41 | 49 | 8 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `rewind_depth` | 83.3% | 25 | 30 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `frame_size_translated_negative` | 81.0% | 17 | 21 | 4 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 18 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 19 | `stage_object_children` | 80.7% | 67 | 83 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 20 | `duplicate_movie_clip` | 80.0% | 16 | 20 | 4 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 21 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `conflicting_instance_names` | 78.3% | 18 | 23 | 5 |  |
| 23 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 24 | `frame_size_translated_positive` | 76.2% | 16 | 21 | 5 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 25 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 27 | `attach_movie` | 72.9% | 43 | 59 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 30 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 31 | `sound_props_swf5` | 70.6% | 48 | 68 | 20 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 32 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `issue_1104` | 66.7% | 2 | 3 | 1 |  |
| 37 | `issue_9885` | 66.7% | 2 | 3 | 1 |  |
| 38 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 39 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 40 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 43 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `swf6_case_insensitive` | 61.4% | 27 | 44 | 17 |  |
| 46 | `do_init_action` | 60.0% | 3 | 5 | 2 |  |
| 47 | `edittext_align` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `goto_rewind2` | 60.0% | 3 | 5 | 2 |  |
| 54 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 55 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 57 | `asnative` | 55.9% | 19 | 34 | 15 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 58 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 59 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 60 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `sound_props_swf6` | 52.9% | 36 | 68 | 32 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 62 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `edittext_html_swf6` | 50.5% | 2718 | 5377 | 2659 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `clone_sprite_types` | 50.0% | 12 | 24 | 12 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 65 | `display_object_properties` | 50.0% | 1 | 2 | 1 |  |
| 66 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `goto_advance2` | 50.0% | 2 | 4 | 2 |  |
| 68 | `goto_rewind3` | 50.0% | 2 | 4 | 2 |  |
| 69 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 70 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 71 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 72 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 73 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 74 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 75 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 76 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 77 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `unload_clip_event` | 50.0% | 2 | 4 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Segfaults

**6 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 9.1s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 2 | `native_objects_swf6` | 9.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf7` | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `placeobject_occupied_depth` | 8.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `target_path` | 9.1s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.9s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**249 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `swf7_case_sensitive` | 97.7% | 43/44 | 44 | 44 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `textfield_properties` | 97.7% | 43/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `globals_swf5` | 96.4% | 293/304 | 304 | 304 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_depth_methods` | 95.9% | 94/98 | 98 | 98 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 9 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 10 | `transform` | 92.9% | 65/70 | 70 | 70 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 11 | `with` | 91.8% | 45/49 | 49 | 49 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 13 | `movieclip_get_instance_at_depth` | 89.3% | 25/28 | 28 | 28 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `movieclip_name_from_timeline` | 84.6% | 11/13 | 13 | 13 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `rewind_depth` | 83.3% | 25/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `frame_size_translated_negative` | 81.0% | 17/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 18 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 19 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 20 | `duplicate_movie_clip` | 80.0% | 16/20 | 20 | 20 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 21 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `conflicting_instance_names` | 78.3% | 18/23 | 23 | 23 |  |
| 23 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 24 | `frame_size_translated_positive` | 76.2% | 16/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 25 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 27 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 30 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 31 | `sound_props_swf5` | 70.6% | 48/68 | 68 | 68 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 32 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `create_empty_movie_clip` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `issue_1104` | 66.7% | 2/3 | 3 | 2 |  |
| 37 | `issue_9885` | 66.7% | 2/3 | 3 | 2 |  |
| 38 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 39 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 40 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 43 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `swf6_case_insensitive` | 61.4% | 27/44 | 44 | 42 |  |
| 46 | `do_init_action` | 60.0% | 3/5 | 5 | 3 |  |
| 47 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `goto_rewind2` | 60.0% | 3/5 | 5 | 3 |  |
| 54 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 55 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 57 | `asnative` | 55.9% | 19/34 | 31 | 34 | [16](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 58 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 59 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 60 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `sound_props_swf6` | 52.9% | 36/68 | 68 | 68 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 62 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `edittext_html_swf6` | 50.5% | 2718/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `clone_sprite_types` | 50.0% | 12/24 | 24 | 24 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 65 | `display_object_properties` | 50.0% | 1/2 | 2 | 2 |  |
| 66 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `goto_advance2` | 50.0% | 2/4 | 4 | 2 |  |
| 68 | `goto_rewind3` | 50.0% | 2/4 | 4 | 2 |  |
| 69 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 70 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 71 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 72 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 73 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 74 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 75 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 76 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 77 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `unload_clip_event` | 50.0% | 2/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 79 | `enumerate` | 48.4% | 31/64 | 62 | 64 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 80 | `edittext_html_condensewhite_swf7` | 46.6% | 145/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 82 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_html_condensewhite_swf8` | 45.7% | 142/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 85 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 86 | `button_children` | 42.9% | 6/14 | 14 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 87 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 88 | `edittext_html_swf7` | 42.1% | 2262/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_html_swf8` | 41.8% | 2247/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 91 | `remove_movie_clip` | 41.4% | 12/29 | 29 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 92 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 93 | `goto_both_ways1` | 40.0% | 2/5 | 5 | 3 |  |
| 94 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 95 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 96 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 97 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 98 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 99 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 100 | `button_v5` | 33.3% | 12/36 | 36 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 101 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 105 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 106 | `string_paths_other` | 33.3% | 12/36 | 28 | 36 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 107 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 109 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 110 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 111 | `button_v6` | 27.8% | 10/36 | 36 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 112 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 113 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 114 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 116 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 117 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 118 | `goto_rewind1` | 25.0% | 1/4 | 4 | 1 |  |
| 119 | `root_global_parent` | 25.0% | 2/8 | 8 | 6 |  |
| 120 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 121 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 123 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 124 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 125 | `stage_object_properties_swf6` | 20.2% | 100/495 | 495 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 126 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 127 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 3 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 128 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 129 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 130 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 131 | `register_and_init_order` | 18.2% | 42/231 | 113 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 132 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 133 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 134 | `tell_target_invalid` | 16.7% | 1/6 | 3 | 6 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 135 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 136 | `stage_object_properties` | 16.0% | 102/637 | 637 | 241 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 137 | `printjob_props_swf5` | 15.6% | 7/45 | 35 | 45 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 138 | `printjob_props_swf7` | 15.6% | 7/45 | 35 | 45 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 139 | `path_string` | 15.2% | 49/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 140 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 141 | `goto_both_ways2` | 14.3% | 1/7 | 7 | 3 |  |
| 142 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 143 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 144 | `unload` | 13.5% | 7/52 | 49 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 145 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 146 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 147 | `goto_advance1` | 12.5% | 1/8 | 8 | 6 |  |
| 148 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 149 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 150 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 151 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 152 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 153 | `printjob_props_swf6` | 11.1% | 5/45 | 35 | 45 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 154 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 155 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 156 | `selection` | 9.3% | 42/454 | 244 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 157 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 158 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 159 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 160 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 161 | `execution_order4` | 7.7% | 1/13 | 13 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 162 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 163 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 164 | `define_local` | 7.4% | 2/27 | 23 | 27 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 165 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 166 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 167 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 168 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 169 | `removed_clip_halts_script` | 6.7% | 1/15 | 4 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 171 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 172 | `funky_function_calls` | 5.4% | 3/56 | 16 | 56 |  |
| 173 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 174 | `clip_events` | 5.3% | 1/19 | 15 | 19 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 175 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 176 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 177 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 178 | `movieclip_gettextsnapshot` | 4.5% | 5/112 | 63 | 112 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 179 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 180 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 181 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 182 | `register_class` | 3.0% | 2/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 183 | `default_names` | 2.9% | 3/102 | 102 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 184 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 185 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 187 | `global_proto_decls` | 0.2% | 9/4497 | 466 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 188 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 189 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 190 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 191 | `button_goto` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 192 | `button_order` | 0.0% | 0/2 | 0 | 2 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 193 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 194 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 195 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 196 | `closure_scope` | 0.0% | 0/8 | 8 | 7 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 197 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 198 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 199 | `define_function2_preload_order` | 0.0% | 0/6 | 6 | 4 |  |
| 200 | `device_font_spacing` | 0.0% | 0/91 | 91 | 91 |  |
| 201 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 202 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 203 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 204 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 205 | `execution_order1` | 0.0% | 0/6 | 6 | 5 |  |
| 206 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 207 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 208 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 209 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 210 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 211 | `global_proto_decls_delete` | 0.0% | 0/4158 | 157 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 212 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 213 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 214 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 215 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 216 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 217 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 218 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 220 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 222 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 223 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 224 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 225 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 226 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 227 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 228 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 229 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 230 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 231 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 233 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 234 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 235 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 236 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 237 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 238 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 239 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 240 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 241 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 242 | `target_clip_removed` | 0.0% | 0/7 | 7 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 243 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 244 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 245 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 246 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 247 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 249 | `variable_args` | 0.0% | 0/6 | 6 | 5 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/incomplete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 0 | 14 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 4 | 1 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 10 | 4 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 8 | 23 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 0 | 17 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/incomplete/issue_768.md) | 1 | 1 | 0 |
| 16 | [MATH_PLAN.md](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) | 5 | 1 | 4 |
| 17 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 18 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 1 | 57 |
| 19 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 4 | 13 |
| 20 | [object_string_coerce.md](ruffle-tests/_investigation/incomplete/object_string_coerce.md) | 2 | 1 | 1 |
| 21 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 22 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 23 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 24 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 6 | 6 |
| 25 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 26 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 27 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 2 | 7 |
| 28 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 2 | 5 |
| 29 | [string_coercion.md](ruffle-tests/_investigation/incomplete/string_coercion.md) | 1 | 1 | 0 |
| 30 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 4 | 9 |
| 31 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 32 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 23 | 47 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 192 | 124 | 68 |
