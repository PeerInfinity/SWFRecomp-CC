# Ruffle Test Results (Filtered)

**Date**: 2026-02-20 03:24 UTC

**Git SHA**: `a58b421c18`

**Run Duration**: 71m 33s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **223** (46.6%) |
| Failing | 256 |
| Total expected lines | 71494 |
| Matching lines | 42663 (59.7%) |
| Mismatched lines | 28831 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 254 | 99.2% |
| Segfault | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**223 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.2s |  |
| 2 | `action_to_integer` | 28 | 6.7s |  |
| 3 | `add` | 28 | 6.6s |  |
| 4 | `add2` | 354 | 6.8s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 6.7s |  |
| 6 | `add_swf5` | 28 | 6.9s |  |
| 7 | `arguments` | 127 | 6.7s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 6.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 6.7s |  |
| 10 | `array_constructor` | 30 | 6.6s |  |
| 11 | `array_enumerate` | 4 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 6.7s |  |
| 13 | `array_properties` | 36 | 6.6s |  |
| 14 | `array_prototyping` | 12 | 6.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 6.7s |  |
| 16 | `array_sort_random` | 443 | 6.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 6.8s |  |
| 18 | `array_trivial` | 209 | 6.7s |  |
| 19 | `as1_constructor_v6` | 35 | 6.6s |  |
| 20 | `as1_constructor_v7` | 35 | 7.0s |  |
| 21 | `as2_oop` | 13 | 6.9s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_set_prop_flags_version` | 31 | 6.8s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 23 | `as_set_prop_flags_version_swf5` | 1 | 6.9s |  |
| 24 | `as_set_prop_flags_version_swf6` | 1 | 6.9s |  |
| 25 | `as_set_prop_flags_version_swf7` | 1 | 6.8s |  |
| 26 | `as_set_prop_flags_version_swf8` | 1 | 6.9s |  |
| 27 | `as_set_prop_flags_version_swf9` | 1 | 6.8s |  |
| 28 | `bad_swf_tag_past_eof` | 0 | 6.6s |  |
| 29 | `bitand` | 1058 | 9.1s |  |
| 30 | `bitmap_data_colortransform` | 0 | 6.9s |  |
| 31 | `bitmap_data_fillrect` | 0 | 6.7s |  |
| 32 | `bitmap_data_max_size_swf10` | 12 | 6.6s |  |
| 33 | `bitmap_data_max_size_swf9` | 10 | 6.6s |  |
| 34 | `bitmap_data_perlinnoise` | 0 | 7.2s |  |
| 35 | `bitmap_data_pixeldissolve_image` | 0 | 7.0s |  |
| 36 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.6s |  |
| 37 | `bitor` | 1058 | 9.2s |  |
| 38 | `biturshift` | 14 | 6.7s |  |
| 39 | `biturshift_swf8` | 14 | 6.8s |  |
| 40 | `bitxor` | 1058 | 9.1s |  |
| 41 | `call_method_empty_name` | 1 | 6.6s |  |
| 42 | `capabilities_resolution` | 8 | 6.6s |  |
| 43 | `catch_references_registers` | 2 | 6.5s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 44 | `clone_sprite_types` | 24 | 6.9s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `color` | 57 | 7.1s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 46 | `color_transform` | 48 | 7.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 47 | `define_function2` | 8 | 6.8s |  |
| 48 | `define_function2_preload` | 13 | 6.9s |  |
| 49 | `define_function2_preload_order` | 4 | 7.0s |  |
| 50 | `define_function_case_sensitive` | 2 | 6.8s |  |
| 51 | `delete` | 3 | 6.7s |  |
| 52 | `display_object_properties` | 2 | 6.6s |  |
| 53 | `divide_swf4` | 107 | 6.7s |  |
| 54 | `edittext_antialiastype` | 296 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_autosize_setter` | 20 | 8.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_default_format` | 221 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_default_format_empty` | 95 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_width_height` | 103 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `enumerate` | 64 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 60 | `equals` | 32 | 6.6s |  |
| 61 | `equals2_swf5` | 926 | 8.4s |  |
| 62 | `equals2_swf6` | 926 | 8.3s |  |
| 63 | `equals2_swf7` | 926 | 8.4s |  |
| 64 | `equals_swf4` | 665 | 7.0s |  |
| 65 | `equals_swf4_alt` | 32 | 6.6s |  |
| 66 | `equals_swf5` | 32 | 6.6s |  |
| 67 | `error` | 58 | 6.7s |  |
| 68 | `escape` | 14 | 6.6s |  |
| 69 | `execution_order1` | 5 | 6.7s |  |
| 70 | `execution_order3` | 4 | 6.6s |  |
| 71 | `focusrect_mouse_swf8` | 0 | 6.6s |  |
| 72 | `focusrect_mouse_swf9` | 0 | 7.1s |  |
| 73 | `focusrect_swf5` | 6 | 6.9s |  |
| 74 | `function_suppress_and_preload` | 28 | 6.8s |  |
| 75 | `get_variable_in_scope` | 29 | 6.8s |  |
| 76 | `getproperty` | 28 | 6.7s |  |
| 77 | `getproperty_swf4` | 28 | 7.1s |  |
| 78 | `getproperty_swf5` | 28 | 6.9s |  |
| 79 | `global_array` | 3 | 7.0s |  |
| 80 | `global_is_bare` | 7 | 7.0s |  |
| 81 | `globals_swf5` | 304 | 7.3s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 82 | `globals_swf6` | 304 | 7.4s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `globals_swf7` | 304 | 7.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 84 | `globals_swf8` | 304 | 7.4s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 85 | `goto_execution_order` | 2 | 6.9s |  |
| 86 | `goto_execution_order2` | 2 | 6.9s |  |
| 87 | `goto_frame_number` | 3 | 6.8s |  |
| 88 | `greater_swf6` | 1175 | 8.7s |  |
| 89 | `greater_swf7` | 1175 | 8.7s |  |
| 90 | `greaterthan_swf5` | 1 | 6.7s |  |
| 91 | `greaterthan_swf8` | 1 | 6.7s |  |
| 92 | `has_own_property` | 32 | 6.7s |  |
| 93 | `infinite_recursion_function` | 4 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 94 | `infinite_recursion_function_in_setter` | 131 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 95 | `infinite_recursion_virtual_property` | 67 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 96 | `init_array_invalid` | 4 | 6.7s |  |
| 97 | `init_object_invalid` | 4 | 6.8s |  |
| 98 | `is_finite` | 49 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 99 | `is_finite_swf6` | 49 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 100 | `is_prototype_of` | 89 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 101 | `issue_1086` | 1 | 6.5s |  |
| 102 | `issue_1671` | 0 | 6.6s |  |
| 103 | `issue_2166` | 9 | 6.6s |  |
| 104 | `issue_3446` | 1 | 6.5s |  |
| 105 | `issue_4377` | 2 | 6.5s |  |
| 106 | `issue_710` | 4 | 6.6s |  |
| 107 | `issue_768` | 3 | 7.0s | [12](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 108 | `lessthan` | 41 | 6.8s |  |
| 109 | `lessthan2_swf5` | 1226 | 8.8s |  |
| 110 | `lessthan2_swf6` | 1226 | 8.8s |  |
| 111 | `lessthan2_swf7` | 1226 | 8.9s |  |
| 112 | `lessthan_swf4` | 902 | 7.3s |  |
| 113 | `lessthan_swf4_alt` | 41 | 6.7s |  |
| 114 | `lessthan_swf5` | 41 | 6.7s |  |
| 115 | `logical_ops_swf4` | 90 | 6.6s |  |
| 116 | `logical_ops_swf8` | 108 | 6.7s |  |
| 117 | `looping` | 6 | 6.6s |  |
| 118 | `mask_reapply` | 0 | 6.6s |  |
| 119 | `mask_with_drawing` | 0 | 6.6s |  |
| 120 | `math_min_max` | 101 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 121 | `matrix` | 171 | 6.9s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 122 | `movieclip_begin_gradient_fill` | 0 | 7.1s |  |
| 123 | `movieclip_blend_mode_property` | 35 | 7.3s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `movieclip_get_instance_at_depth` | 28 | 6.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 125 | `movieclip_line_gradient_style` | 0 | 7.4s |  |
| 126 | `movieclip_prototype_extension` | 5 | 6.5s |  |
| 127 | `nested_textfields_in_buttons` | 0 | 6.4s |  |
| 128 | `netstream_play_flv_screen` | 0 | 19.4s |  |
| 129 | `new_method_wrap` | 4 | 6.5s |  |
| 130 | `new_object_enumerate` | 7 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 131 | `new_object_wrap` | 4 | 6.5s |  |
| 132 | `o` | 3 | 6.6s |  |
| 133 | `object_constructor` | 33 | 6.6s |  |
| 134 | `object_function` | 32 | 6.6s |  |
| 135 | `object_properties` | 31 | 6.7s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 136 | `object_prototypes` | 74 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 137 | `object_string_coerce_swf5` | 62 | 6.6s | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 138 | `parse_int` | 64 | 6.8s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 139 | `point` | 175 | 7.0s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 140 | `primitive_instanceof` | 37 | 6.6s |  |
| 141 | `primitive_type_globals` | 557 | 9.4s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 142 | `prototype_delete` | 12 | 6.7s |  |
| 143 | `prototype_enumerate` | 5 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 144 | `prototype_properties` | 17 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 145 | `rectangle` | 745 | 7.5s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 146 | `recursive_prototypes` | 0 | 6.6s |  |
| 147 | `sandbox_type_local_file` | 1 | 6.7s |  |
| 148 | `set_variable_scope` | 58 | 6.7s |  |
| 149 | `single_frame` | 1 | 6.8s |  |
| 150 | `sound_start_load` | 0 | 6.7s |  |
| 151 | `stage_object_properties_get_var` | 5 | 6.6s |  |
| 152 | `stage_property_representation` | 586 | 6.7s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 153 | `strictequals_swf6` | 902 | 8.3s |  |
| 154 | `strictly_equals` | 7 | 6.7s |  |
| 155 | `string_coercion` | 117 | 7.0s | [25](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 156 | `string_methods` | 285 | 7.4s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 157 | `string_methods_negative_args` | 240 | 6.9s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 158 | `string_methods_swfv5` | 275 | 7.3s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 159 | `string_ops_swf6` | 95 | 6.8s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 160 | `string_paths_keyevents` | 0 | 6.6s |  |
| 161 | `string_paths_timer` | 0 | 6.6s |  |
| 162 | `swf4_actions_bool` | 96 | 6.7s |  |
| 163 | `swf4_bool` | 4 | 6.6s |  |
| 164 | `swf4_function_calls` | 7 | 6.6s |  |
| 165 | `swf5_encoding` | 3 | 6.6s |  |
| 166 | `swf7_case_sensitive` | 44 | 6.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 167 | `tab_ordering_properties_tab_index_edge_case` | 4 | 6.7s |  |
| 168 | `text_format` | 1146 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 169 | `text_format_display` | 21 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 170 | `text_format_font_max_length` | 2 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 171 | `text_format_rounding_swf7` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 172 | `text_format_rounding_swf8` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `textfield_background_color` | 11 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 174 | `textfield_border_color` | 11 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `textfield_maxchars` | 3 | 7.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `textfield_properties` | 44 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `textfield_props_swf6` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `textfield_props_swf7` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `textfield_props_swf8` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `textfield_text` | 7 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `this_swf7` | 41 | 6.8s | [29](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 182 | `timeline_function_def` | 7 | 6.8s |  |
| 183 | `try_catch_finally` | 118 | 6.7s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 184 | `try_finally_simple` | 16 | 6.6s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 185 | `typeof` | 22 | 6.6s |  |
| 186 | `typeof_globals` | 7 | 6.6s |  |
| 187 | `uncaught_exception` | 1 | 6.5s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 188 | `uncaught_exception_bubbled` | 1 | 6.6s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 189 | `undefined_to_string_swf6` | 4 | 6.6s |  |
| 190 | `unescape` | 43 | 6.6s |  |
| 191 | `use_hand_cursor` | 8 | 6.6s |  |
| 192 | `variable_args` | 5 | 6.7s |  |
| 193 | `waitforframe` | 7 | 6.6s |  |
| 194 | `waitforframe2` | 16 | 6.9s |  |
| 195 | `watch` | 117 | 7.0s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 196 | `watch_virtual_property_proto` | 2 | 6.9s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 197 | `with_return` | 2 | 6.8s |  |
| 198 | `with_variable_scopes` | 43 | 6.9s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 199 | `xml` | 15 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 200 | `xml_append_child` | 28 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 201 | `xml_append_child_with_parent` | 20 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 202 | `xml_cdata` | 11 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 203 | `xml_child_nodes_edge_cases` | 4 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 204 | `xml_clone_expandos` | 19 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 205 | `xml_first_last_child` | 8 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 206 | `xml_has_child_nodes` | 3 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 207 | `xml_idmap` | 21 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 208 | `xml_ignore_comments` | 21 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 209 | `xml_ignore_white` | 34 | 7.2s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 210 | `xml_insert_before` | 20 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_inspect_createmethods` | 15 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_inspect_doctype` | 7 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_inspect_parsexml` | 62 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_inspect_xmldecl` | 7 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_namespaces` | 203 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_parent_and_child` | 5 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_remove_node` | 22 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_reparenting` | 14 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_siblings` | 10 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_to_string` | 13 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_to_string_comment` | 1 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_unescaping` | 23 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xmlnode_proto` | 1 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**84 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `textfield_variable` | 96.3% | 78 | 81 | 3 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `conflicting_instance_names` | 95.7% | 22 | 23 | 1 |  |
| 8 | `duplicate_movie_clip` | 95.0% | 19 | 20 | 1 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_depth_methods` | 94.9% | 93 | 98 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 10 | `edittext_default_format_font_style` | 94.0% | 315 | 335 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 11 | `with` | 93.9% | 46 | 49 | 3 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `movieclip_name_from_timeline` | 92.3% | 12 | 13 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 14 | `transform` | 90.0% | 63 | 70 | 7 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 15 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `local_to_global` | 83.7% | 41 | 49 | 8 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 19 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `this_scoping` | 80.8% | 42 | 52 | 10 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 21 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 22 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 23 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 25 | `do_init_action` | 75.0% | 3 | 4 | 1 |  |
| 26 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `add_property` | 73.3% | 11 | 15 | 4 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `attach_movie` | 72.9% | 43 | 59 | 16 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 31 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 32 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 33 | `as_broadcaster_initialize` | 70.0% | 7 | 10 | 3 |  |
| 34 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 35 | `register_underflow` | 69.2% | 18 | 26 | 8 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 37 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `export_assets` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 39 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 40 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 41 | `goto_advance2` | 66.7% | 2 | 3 | 1 |  |
| 42 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 43 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 44 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 45 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 48 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 49 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 52 | `edittext_align` | 60.0% | 36 | 60 | 24 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `goto_rewind2` | 60.0% | 3 | 5 | 2 |  |
| 59 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 60 | `parse_float` | 58.1% | 43 | 74 | 31 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 61 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `asnative` | 55.9% | 19 | 34 | 15 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 63 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 64 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 65 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 67 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 69 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 70 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `goto_rewind3` | 50.0% | 2 | 4 | 2 |  |
| 72 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 73 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 74 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 75 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 76 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 77 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 78 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 79 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 80 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 81 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 82 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 83 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `unload_clip_event` | 50.0% | 2 | 4 | 2 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 9.0s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.6s | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**254 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `textfield_variable` | 96.3% | 78/81 | 81 | 81 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `conflicting_instance_names` | 95.7% | 22/23 | 23 | 23 |  |
| 8 | `duplicate_movie_clip` | 95.0% | 19/20 | 20 | 20 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_depth_methods` | 94.9% | 93/98 | 98 | 98 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 10 | `edittext_default_format_font_style` | 94.0% | 315/335 | 335 | 335 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 11 | `with` | 93.9% | 46/49 | 49 | 49 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `movieclip_name_from_timeline` | 92.3% | 12/13 | 13 | 13 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 14 | `transform` | 90.0% | 63/70 | 70 | 70 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 15 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 19 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 21 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 22 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 23 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 25 | `do_init_action` | 75.0% | 3/4 | 4 | 3 |  |
| 26 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `add_property` | 73.3% | 11/15 | 15 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 31 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 32 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 33 | `as_broadcaster_initialize` | 70.0% | 7/10 | 10 | 10 |  |
| 34 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 35 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 37 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 39 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 40 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 41 | `goto_advance2` | 66.7% | 2/3 | 3 | 2 |  |
| 42 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 43 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 44 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 45 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 48 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 49 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 52 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `goto_rewind2` | 60.0% | 3/5 | 5 | 3 |  |
| 59 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 60 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 61 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `asnative` | 55.9% | 19/34 | 31 | 34 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 63 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 64 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 65 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 67 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 69 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 70 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `goto_rewind3` | 50.0% | 2/4 | 4 | 2 |  |
| 72 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 73 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 74 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 75 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 76 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 77 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 78 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 79 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 80 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 81 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 82 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 83 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `unload_clip_event` | 50.0% | 2/4 | 2 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 85 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 86 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 89 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 90 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 91 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 93 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 94 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 95 | `goto_both_ways1` | 40.0% | 2/5 | 5 | 3 |  |
| 96 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 97 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 98 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 99 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 100 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 102 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 103 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 107 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 108 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 110 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 111 | `stage_object_properties_swf6` | 30.5% | 131/429 | 429 | 231 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 112 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 113 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 114 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 115 | `default_names` | 26.2% | 16/61 | 61 | 52 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 116 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 117 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 118 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 119 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 120 | `execution_order4` | 25.0% | 3/12 | 11 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 121 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 122 | `goto_rewind1` | 25.0% | 1/4 | 4 | 1 |  |
| 123 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 124 | `unload` | 25.0% | 13/52 | 49 | 52 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 125 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 126 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 127 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 128 | `stage_object_properties` | 22.9% | 131/571 | 571 | 241 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 129 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 130 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 131 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 132 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 133 | `goto_both_ways2` | 20.0% | 1/5 | 5 | 3 |  |
| 134 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 135 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 136 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 137 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 138 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 139 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 140 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 141 | `path_string` | 15.2% | 49/322 | 300 | 322 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 142 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 143 | `goto_advance1` | 14.3% | 1/7 | 7 | 6 |  |
| 144 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 146 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 147 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 148 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 149 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 150 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 151 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 152 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 153 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 154 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 155 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 156 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 157 | `placeobject_occupied_depth` | 11.1% | 1/9 | 9 | 6 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 158 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 159 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 160 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 161 | `selection` | 9.3% | 42/454 | 244 | 454 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 162 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 163 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 164 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 165 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 167 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `define_local` | 7.4% | 2/27 | 23 | 27 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 169 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 170 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 171 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 172 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 173 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 175 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 176 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 177 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 178 | `clip_events` | 5.3% | 1/19 | 9 | 19 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 179 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 180 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 181 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 182 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 183 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 184 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 185 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `register_class` | 3.0% | 2/66 | 27 | 66 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 187 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 188 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 189 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 190 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 191 | `global_proto_decls` | 0.2% | 9/4497 | 440 | 4497 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 192 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 193 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 194 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 196 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 197 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 198 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 199 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 200 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 201 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 202 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 203 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 204 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 205 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 206 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 207 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 208 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 209 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 210 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 211 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 212 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 213 | `global_proto_decls_delete` | 0.0% | 0/4158 | 146 | 4158 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 214 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 215 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 216 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 217 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 218 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 219 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 220 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 221 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 222 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 223 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 224 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 225 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 226 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 227 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 228 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 229 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 230 | `native_objects_swf8` | 0.0% | 0/146 | 146 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 231 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 232 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 233 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 234 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 235 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 236 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 238 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 239 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 240 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 241 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 242 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 243 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 244 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 245 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 246 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 247 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 248 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 249 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 250 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 251 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 252 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/incomplete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 1 | 7 |
| 4 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 3 | 2 |
| 5 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 6 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 11 | 3 |
| 7 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 8 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 9 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 9 | 22 |
| 10 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 0 | 17 |
| 11 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 12 | [issue_768.md](ruffle-tests/_investigation/incomplete/issue_768.md) | 1 | 1 | 0 |
| 13 | [MATH_PLAN.md](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) | 5 | 1 | 4 |
| 14 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 4 | 54 |
| 15 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 16 | [object_string_coerce.md](ruffle-tests/_investigation/incomplete/object_string_coerce.md) | 2 | 1 | 1 |
| 17 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 18 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 19 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 20 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 6 | 6 |
| 21 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 22 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 23 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 1 | 8 |
| 24 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 1 | 6 |
| 25 | [string_coercion.md](ruffle-tests/_investigation/incomplete/string_coercion.md) | 1 | 1 | 0 |
| 26 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 4 | 9 |
| 27 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 28 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 18 | 52 |
| 29 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 30 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 31 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 32 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 33 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 34 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 201 | 127 | 74 |
