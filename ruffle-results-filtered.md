# Ruffle Test Results (Filtered)

**Date**: 2026-02-18 16:25 UTC

**Git SHA**: `10a57582eb`

**Run Duration**: 62m 57s

**Filtered**: 139 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 480 |
| Passing | **227** (47.3%) |
| Failing | 253 |
| Total expected lines | 71655 |
| Matching lines | 41072 (57.3%) |
| Mismatched lines | 30583 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 251 | 99.2% |
| Segfault | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**227 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 6.2s |  |
| 2 | `action_to_integer` | 28 | 5.7s |  |
| 3 | `add` | 28 | 5.7s |  |
| 4 | `add2` | 354 | 5.9s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 5.8s |  |
| 6 | `add_swf5` | 28 | 5.7s |  |
| 7 | `arguments` | 127 | 5.7s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [17](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 5.7s | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 5.8s |  |
| 10 | `array_constructor` | 30 | 5.8s |  |
| 11 | `array_enumerate` | 4 | 5.8s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 5.7s |  |
| 13 | `array_properties` | 36 | 5.7s |  |
| 14 | `array_slice` | 34 | 5.8s |  |
| 15 | `array_splice` | 207 | 5.9s |  |
| 16 | `array_trivial` | 209 | 5.8s |  |
| 17 | `as1_constructor_v6` | 35 | 5.7s |  |
| 18 | `as1_constructor_v7` | 35 | 5.7s |  |
| 19 | `as2_oop` | 13 | 5.9s | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 20 | `as_broadcaster_initialize` | 10 | 5.7s |  |
| 21 | `as_set_prop_flags_version` | 31 | 5.8s | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `as_set_prop_flags_version_swf5` | 1 | 5.7s |  |
| 23 | `as_set_prop_flags_version_swf6` | 1 | 5.7s |  |
| 24 | `as_set_prop_flags_version_swf7` | 1 | 5.7s |  |
| 25 | `as_set_prop_flags_version_swf8` | 1 | 5.7s |  |
| 26 | `as_set_prop_flags_version_swf9` | 1 | 5.7s |  |
| 27 | `as_transformed_flag` | 20 | 5.7s |  |
| 28 | `bad_swf_tag_past_eof` | 0 | 5.7s |  |
| 29 | `bitand` | 1058 | 8.3s |  |
| 30 | `bitmap_data_colortransform` | 0 | 6.0s |  |
| 31 | `bitmap_data_fillrect` | 0 | 5.8s |  |
| 32 | `bitmap_data_max_size_swf10` | 12 | 5.7s |  |
| 33 | `bitmap_data_max_size_swf9` | 10 | 5.7s |  |
| 34 | `bitmap_data_perlinnoise` | 0 | 6.2s |  |
| 35 | `bitmap_data_pixeldissolve_image` | 0 | 6.1s |  |
| 36 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.7s |  |
| 37 | `bitor` | 1058 | 8.3s |  |
| 38 | `biturshift` | 14 | 6.1s |  |
| 39 | `biturshift_swf8` | 14 | 5.9s |  |
| 40 | `bitxor` | 1058 | 8.9s |  |
| 41 | `call_method_empty_name` | 1 | 6.0s |  |
| 42 | `capabilities_resolution` | 8 | 5.9s |  |
| 43 | `catch_references_registers` | 2 | 5.9s | [28](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 44 | `conflicting_instance_names` | 23 | 6.1s |  |
| 45 | `define_function2` | 8 | 6.0s |  |
| 46 | `define_function2_preload` | 13 | 5.9s |  |
| 47 | `define_function2_preload_order` | 4 | 6.0s |  |
| 48 | `define_function_case_sensitive` | 2 | 6.0s |  |
| 49 | `delete` | 3 | 6.0s |  |
| 50 | `display_object_properties` | 2 | 5.9s |  |
| 51 | `divide_swf4` | 107 | 6.2s |  |
| 52 | `do_init_action` | 3 | 6.0s |  |
| 53 | `edittext_antialiastype` | 296 | 6.4s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_autosize_setter` | 20 | 6.0s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_default_format` | 221 | 6.1s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_default_format_empty` | 95 | 6.0s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_default_format_font_style` | 335 | 6.0s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_width_height` | 103 | 5.9s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `equals` | 32 | 5.8s |  |
| 60 | `equals2_swf5` | 926 | 7.6s |  |
| 61 | `equals2_swf6` | 926 | 7.7s |  |
| 62 | `equals2_swf7` | 926 | 7.8s |  |
| 63 | `equals_swf4` | 665 | 6.3s |  |
| 64 | `equals_swf4_alt` | 32 | 5.8s |  |
| 65 | `equals_swf5` | 32 | 5.8s |  |
| 66 | `error` | 58 | 5.9s |  |
| 67 | `escape` | 14 | 5.8s |  |
| 68 | `execution_order1` | 5 | 5.9s |  |
| 69 | `execution_order2` | 7 | 5.8s |  |
| 70 | `execution_order3` | 4 | 5.8s |  |
| 71 | `focusrect_mouse_swf8` | 0 | 6.0s |  |
| 72 | `focusrect_mouse_swf9` | 0 | 6.0s |  |
| 73 | `focusrect_swf5` | 6 | 6.1s |  |
| 74 | `function_suppress_and_preload` | 28 | 6.0s |  |
| 75 | `get_variable_in_scope` | 29 | 6.0s |  |
| 76 | `getproperty` | 28 | 6.0s |  |
| 77 | `getproperty_swf4` | 28 | 6.1s |  |
| 78 | `getproperty_swf5` | 28 | 6.0s |  |
| 79 | `global_array` | 3 | 5.9s |  |
| 80 | `global_is_bare` | 7 | 6.1s |  |
| 81 | `globals_swf5` | 304 | 6.3s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 82 | `globals_swf6` | 304 | 6.2s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `globals_swf7` | 304 | 6.2s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 84 | `globals_swf8` | 304 | 6.2s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 85 | `goto_advance1` | 6 | 6.0s |  |
| 86 | `goto_advance2` | 2 | 6.0s |  |
| 87 | `goto_both_ways1` | 3 | 8.4s |  |
| 88 | `goto_both_ways2` | 3 | 5.7s |  |
| 89 | `goto_execution_order` | 2 | 5.6s |  |
| 90 | `goto_execution_order2` | 2 | 5.7s |  |
| 91 | `goto_frame_number` | 3 | 5.7s |  |
| 92 | `goto_rewind1` | 1 | 5.7s |  |
| 93 | `goto_rewind2` | 3 | 5.8s |  |
| 94 | `goto_rewind3` | 2 | 5.7s |  |
| 95 | `greater_swf6` | 1175 | 7.6s |  |
| 96 | `greater_swf7` | 1175 | 7.6s |  |
| 97 | `greaterthan_swf5` | 1 | 5.7s |  |
| 98 | `greaterthan_swf8` | 1 | 5.7s |  |
| 99 | `has_own_property` | 32 | 5.7s |  |
| 100 | `infinite_recursion_function` | 4 | 5.6s | [9](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 101 | `infinite_recursion_function_in_setter` | 131 | 5.6s | [9](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 102 | `infinite_recursion_virtual_property` | 67 | 5.6s | [9](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 103 | `init_array_invalid` | 4 | 5.6s |  |
| 104 | `init_object_invalid` | 4 | 5.6s |  |
| 105 | `is_finite` | 49 | 5.7s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 106 | `is_finite_swf6` | 49 | 5.7s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 107 | `is_prototype_of` | 89 | 5.8s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 108 | `issue_1086` | 1 | 5.6s |  |
| 109 | `issue_1671` | 0 | 5.6s |  |
| 110 | `issue_2166` | 9 | 5.7s |  |
| 111 | `issue_3446` | 1 | 5.6s |  |
| 112 | `issue_4377` | 2 | 5.7s |  |
| 113 | `issue_710` | 4 | 5.7s |  |
| 114 | `issue_768` | 3 | 5.7s | [10](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 115 | `lessthan` | 41 | 5.7s |  |
| 116 | `lessthan2_swf5` | 1226 | 7.7s |  |
| 117 | `lessthan2_swf6` | 1226 | 7.7s |  |
| 118 | `lessthan2_swf7` | 1226 | 7.7s |  |
| 119 | `lessthan_swf4` | 902 | 6.3s |  |
| 120 | `lessthan_swf4_alt` | 41 | 5.7s |  |
| 121 | `lessthan_swf5` | 41 | 5.7s |  |
| 122 | `logical_ops_swf4` | 90 | 6.2s |  |
| 123 | `logical_ops_swf8` | 108 | 6.2s |  |
| 124 | `looping` | 6 | 6.2s |  |
| 125 | `mask_reapply` | 0 | 6.1s |  |
| 126 | `mask_with_drawing` | 0 | 6.1s |  |
| 127 | `math_min_max` | 101 | 6.3s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 128 | `matrix` | 171 | 6.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 129 | `movieclip_begin_gradient_fill` | 0 | 6.2s |  |
| 130 | `movieclip_blend_mode_property` | 35 | 5.8s | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 131 | `movieclip_default_state` | 69 | 5.9s | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 132 | `movieclip_get_instance_at_depth` | 28 | 5.8s | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 133 | `movieclip_line_gradient_style` | 0 | 6.1s |  |
| 134 | `movieclip_name_from_timeline` | 13 | 5.7s | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 135 | `movieclip_prototype_extension` | 5 | 5.7s |  |
| 136 | `nested_textfields_in_buttons` | 0 | 5.7s |  |
| 137 | `netstream_play_flv_screen` | 0 | 18.6s |  |
| 138 | `new_method_wrap` | 4 | 5.7s |  |
| 139 | `new_object_enumerate` | 7 | 5.7s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 140 | `new_object_wrap` | 4 | 5.6s |  |
| 141 | `o` | 3 | 5.7s |  |
| 142 | `object_constructor` | 33 | 5.8s |  |
| 143 | `object_function` | 32 | 5.7s |  |
| 144 | `object_properties` | 31 | 5.8s | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 145 | `object_string_coerce_swf5` | 62 | 5.8s | [14](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 146 | `point` | 175 | 6.1s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 147 | `primitive_instanceof` | 37 | 5.7s |  |
| 148 | `prototype_delete` | 12 | 5.7s |  |
| 149 | `prototype_enumerate` | 5 | 5.7s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 150 | `prototype_properties` | 17 | 5.7s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 151 | `rectangle` | 745 | 6.5s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 152 | `recursive_prototypes` | 0 | 5.7s |  |
| 153 | `sandbox_type_local_file` | 1 | 6.1s |  |
| 154 | `set_variable_scope` | 58 | 6.0s |  |
| 155 | `single_frame` | 1 | 6.0s |  |
| 156 | `sound_start_load` | 0 | 6.1s |  |
| 157 | `stage_object_properties_get_var` | 5 | 5.9s |  |
| 158 | `strictequals_swf6` | 902 | 7.5s |  |
| 159 | `strictly_equals` | 7 | 5.9s |  |
| 160 | `string_coercion` | 117 | 6.4s | [22](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 161 | `string_methods` | 285 | 6.6s | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 162 | `string_methods_negative_args` | 240 | 6.1s | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 163 | `string_methods_swfv5` | 275 | 6.6s | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 164 | `string_ops_swf6` | 95 | 6.0s | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 165 | `string_paths_keyevents` | 0 | 5.9s |  |
| 166 | `string_paths_timer` | 0 | 6.0s |  |
| 167 | `swf4_actions_bool` | 96 | 6.2s |  |
| 168 | `swf4_bool` | 4 | 6.0s |  |
| 169 | `swf4_function_calls` | 7 | 6.3s |  |
| 170 | `swf5_encoding` | 3 | 5.8s |  |
| 171 | `swf7_case_sensitive` | 44 | 6.0s | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 172 | `tab_ordering_properties_tab_index_edge_case` | 4 | 5.8s |  |
| 173 | `text_format` | 1146 | 6.1s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 174 | `text_format_display` | 21 | 5.8s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `text_format_font_max_length` | 2 | 5.8s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `text_format_rounding_swf7` | 840 | 6.0s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `text_format_rounding_swf8` | 840 | 6.0s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `textfield_background_color` | 11 | 5.8s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `textfield_border_color` | 11 | 5.9s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `textfield_maxchars` | 3 | 5.9s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `textfield_properties` | 44 | 6.0s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `textfield_props_swf6` | 210 | 6.1s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 183 | `textfield_props_swf7` | 210 | 6.1s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 184 | `textfield_props_swf8` | 210 | 6.1s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 185 | `textfield_text` | 7 | 6.0s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 186 | `textfield_variable` | 81 | 6.1s | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 187 | `this_swf7` | 41 | 5.9s | [26](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 188 | `timeline_function_def` | 7 | 6.0s |  |
| 189 | `try_catch_finally` | 118 | 5.7s | [28](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 190 | `try_finally_simple` | 16 | 5.6s | [28](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 191 | `typeof` | 22 | 5.6s |  |
| 192 | `typeof_globals` | 7 | 5.6s |  |
| 193 | `uncaught_exception` | 1 | 5.6s | [28](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 194 | `uncaught_exception_bubbled` | 1 | 5.6s | [28](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 195 | `undefined_to_string_swf6` | 4 | 5.6s |  |
| 196 | `unescape` | 43 | 5.6s |  |
| 197 | `use_hand_cursor` | 8 | 5.6s |  |
| 198 | `variable_args` | 5 | 5.7s |  |
| 199 | `waitforframe` | 7 | 5.6s |  |
| 200 | `waitforframe2` | 16 | 5.7s |  |
| 201 | `with_return` | 2 | 5.6s |  |
| 202 | `with_variable_scopes` | 43 | 5.7s | [30](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 203 | `xml` | 15 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 204 | `xml_append_child` | 28 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 205 | `xml_append_child_with_parent` | 20 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 206 | `xml_cdata` | 11 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 207 | `xml_child_nodes_edge_cases` | 4 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 208 | `xml_clone_expandos` | 19 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 209 | `xml_first_last_child` | 8 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 210 | `xml_has_child_nodes` | 3 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_idmap` | 21 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_ignore_comments` | 21 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_ignore_white` | 34 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_insert_before` | 20 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_inspect_createmethods` | 15 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_inspect_doctype` | 7 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_inspect_parsexml` | 62 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_inspect_xmldecl` | 7 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_namespaces` | 203 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_parent_and_child` | 5 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_remove_node` | 22 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_reparenting` | 14 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_siblings` | 10 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xml_to_string` | 13 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 225 | `xml_to_string_comment` | 1 | 5.6s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 226 | `xml_unescaping` | 23 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 227 | `xmlnode_proto` | 1 | 5.7s | [31](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**75 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `math_swf6` | 98.5% | 522 | 530 | 8 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522 | 530 | 8 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522 | 530 | 8 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 5 | `movieclip_depth_methods` | 98.0% | 96 | 98 | 2 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `with` | 93.9% | 46 | 49 | 3 | [30](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 8 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `object_prototypes` | 85.1% | 63 | 74 | 11 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 11 | `local_to_global` | 83.7% | 41 | 49 | 8 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 12 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `this_scoping` | 80.8% | 42 | 52 | 10 | [30](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 16 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 17 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 19 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `add_property` | 73.3% | 11 | 15 | 4 | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `attach_movie` | 72.9% | 43 | 59 | 16 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 22 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 23 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 25 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 | [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 26 | `stage_object_properties` | 71.8% | 173 | 241 | 68 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 27 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 28 | `transform` | 71.4% | 50 | 70 | 20 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 29 | `register_underflow` | 69.2% | 18 | 26 | 8 | [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 30 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [14](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 31 | `array_prototyping` | 66.7% | 8 | 12 | 4 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 32 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 33 | `export_assets` | 66.7% | 2 | 3 | 1 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 34 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 35 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 36 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 37 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 38 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 41 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 42 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 44 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `color` | 61.4% | 35 | 57 | 22 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 46 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 47 | `edittext_align` | 60.0% | 36 | 60 | 24 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 54 | `parse_float` | 58.1% | 43 | 74 | 31 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 55 | `primitive_type_globals` | 57.6% | 321 | 557 | 236 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 56 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `asnative` | 55.9% | 19 | 34 | 15 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 58 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 59 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 60 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 65 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 67 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 68 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 69 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 70 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 71 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 72 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 73 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 74 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 75 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 8.0s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.2s | [27](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**251 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 5 | `movieclip_depth_methods` | 98.0% | 96/98 | 98 | 98 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `with` | 93.9% | 46/49 | 49 | 49 | [30](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 8 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `object_prototypes` | 85.1% | 63/74 | 73 | 74 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 11 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 12 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [30](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 16 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 17 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 19 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `add_property` | 73.3% | 11/15 | 15 | 15 | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 22 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 23 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 25 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 | [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 26 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 27 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 28 | `transform` | 71.4% | 50/70 | 70 | 70 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 29 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 30 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [14](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 31 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 32 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 33 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 34 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 35 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 36 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 37 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 38 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 41 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 42 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 44 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `color` | 61.4% | 35/57 | 57 | 57 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 46 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 47 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 54 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 55 | `primitive_type_globals` | 57.6% | 321/557 | 555 | 557 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 56 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `asnative` | 55.9% | 19/34 | 31 | 34 | [11](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 58 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 59 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 60 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 65 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 67 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 68 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 69 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 70 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 71 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 72 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 73 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 74 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 75 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 77 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 80 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 81 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 82 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 84 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 85 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 86 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 87 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 88 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 89 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 90 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 92 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 93 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 97 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 99 | `enumerate` | 29.7% | 19/64 | 60 | 64 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 100 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 101 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 102 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 103 | `default_names` | 25.0% | 13/52 | 40 | 52 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 105 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 106 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 107 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 111 | `unload` | 21.2% | 11/52 | 48 | 52 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 112 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 113 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 114 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 115 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 116 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 117 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [27](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 118 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 119 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 120 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 121 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 122 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [15](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 123 | `watch` | 15.4% | 18/117 | 101 | 117 | [15](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 124 | `path_string` | 14.9% | 48/322 | 300 | 322 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 125 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 126 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 127 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 129 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 130 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 131 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 132 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [15](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 133 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 134 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 135 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 136 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 137 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 138 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 139 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 140 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 141 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 142 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 143 | `selection` | 9.3% | 42/454 | 244 | 454 | [20](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 144 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 146 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 147 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 148 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `define_local` | 7.4% | 2/27 | 23 | 27 | [30](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 151 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 152 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 153 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 154 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 155 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 156 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 157 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [27](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 158 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 159 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 160 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 161 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 162 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 163 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 164 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 165 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 166 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [20](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 167 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `register_class` | 3.0% | 2/66 | 27 | 66 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 169 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `parse_int` | 1.6% | 1/64 | 64 | 64 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 172 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 173 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 175 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 | [21](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 177 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 178 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 179 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 180 | `array_sort_random` | 0.2% | 1/443 | 80 | 443 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 181 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 182 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 183 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 184 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 185 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 186 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 187 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 188 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 189 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 190 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 191 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 192 | `closure_scope` | 0.0% | 0/7 | 4 | 7 | [30](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 193 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 194 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 195 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 196 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 197 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [20](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 198 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 199 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 200 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 201 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 202 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 203 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 204 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 205 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 206 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 207 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 208 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [16](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 209 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 211 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 212 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 213 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 215 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 216 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 217 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 218 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 219 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 220 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 221 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 222 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 223 | `native_objects_swf8` | 0.0% | 0/144 | 144 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 224 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [18](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 225 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 226 | `place_and_lookup` | 0.0% | 0/30 | 27 | 30 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 227 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 228 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [19](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 229 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 230 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 231 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 233 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 234 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 235 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 236 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 237 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 238 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 239 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 240 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 241 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 242 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 243 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 244 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 245 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 246 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [24](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 247 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [25](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 249 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 250 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [12](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 251 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [15](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/incomplete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) | 4 | 1 | 3 |
| 3 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 4 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 1 | 4 |
| 5 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 6 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) | 14 | 9 | 5 |
| 7 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 8 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 7 | 24 |
| 9 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 10 | [issue_768.md](ruffle-tests/_investigation/incomplete/issue_768.md) | 1 | 1 | 0 |
| 11 | [MATH_PLAN.md](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) | 5 | 1 | 4 |
| 12 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 5 | 53 |
| 13 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 14 | [object_string_coerce.md](ruffle-tests/_investigation/incomplete/object_string_coerce.md) | 2 | 1 | 1 |
| 15 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 0 | 4 |
| 16 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 17 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 1 | 2 |
| 18 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 5 | 7 |
| 19 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 20 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 21 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 0 | 7 |
| 22 | [string_coercion.md](ruffle-tests/_investigation/incomplete/string_coercion.md) | 1 | 1 | 0 |
| 23 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 4 | 9 |
| 24 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 25 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 20 | 50 |
| 26 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 27 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 28 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 29 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 30 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 31 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 211 | 139 | 72 |
