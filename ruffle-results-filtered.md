# Ruffle Test Results (Filtered)

**Date**: 2026-02-20 02:09 UTC

**Git SHA**: `6a95bcac32`

**Run Duration**: 70m 12s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **224** (46.8%) |
| Failing | 255 |
| Total expected lines | 71483 |
| Matching lines | 42522 (59.5%) |
| Mismatched lines | 28961 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 247 | 96.9% |
| Runtime Error | 6 | 2.4% |
| Segfault | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**224 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 6.8s |  |
| 2 | `action_to_integer` | 28 | 6.6s |  |
| 3 | `add` | 28 | 6.5s |  |
| 4 | `add2` | 354 | 6.8s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 6.5s |  |
| 6 | `add_swf5` | 28 | 6.5s |  |
| 7 | `arguments` | 127 | 6.7s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 6.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 6.6s |  |
| 10 | `array_constructor` | 30 | 6.6s |  |
| 11 | `array_enumerate` | 4 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 6.6s |  |
| 13 | `array_properties` | 36 | 6.6s |  |
| 14 | `array_prototyping` | 12 | 6.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 6.7s |  |
| 16 | `array_sort_random` | 443 | 6.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 6.8s |  |
| 18 | `array_trivial` | 209 | 6.7s |  |
| 19 | `as1_constructor_v6` | 35 | 6.6s |  |
| 20 | `as1_constructor_v7` | 35 | 6.6s |  |
| 21 | `as2_oop` | 13 | 6.8s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 6.6s |  |
| 23 | `as_set_prop_flags_version` | 31 | 6.6s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 6.6s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 6.6s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 6.6s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 6.7s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 6.6s |  |
| 29 | `bad_swf_tag_past_eof` | 0 | 6.7s |  |
| 30 | `bitand` | 1058 | 9.2s |  |
| 31 | `bitmap_data_colortransform` | 0 | 6.8s |  |
| 32 | `bitmap_data_fillrect` | 0 | 6.9s |  |
| 33 | `bitmap_data_max_size_swf10` | 12 | 6.9s |  |
| 34 | `bitmap_data_max_size_swf9` | 10 | 6.8s |  |
| 35 | `bitmap_data_perlinnoise` | 0 | 7.3s |  |
| 36 | `bitmap_data_pixeldissolve_image` | 0 | 7.2s |  |
| 37 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.0s |  |
| 38 | `bitor` | 1058 | 9.1s |  |
| 39 | `biturshift` | 14 | 7.0s |  |
| 40 | `biturshift_swf8` | 14 | 6.8s |  |
| 41 | `bitxor` | 1058 | 9.6s |  |
| 42 | `call_method_empty_name` | 1 | 6.7s |  |
| 43 | `capabilities_resolution` | 8 | 6.7s |  |
| 44 | `catch_references_registers` | 2 | 6.7s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 45 | `clone_sprite_types` | 24 | 6.7s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `color` | 57 | 6.9s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 47 | `color_transform` | 48 | 6.9s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 48 | `define_function2` | 8 | 6.8s |  |
| 49 | `define_function2_preload` | 13 | 6.7s |  |
| 50 | `define_function2_preload_order` | 4 | 6.7s |  |
| 51 | `define_function_case_sensitive` | 2 | 6.7s |  |
| 52 | `delete` | 3 | 6.8s |  |
| 53 | `display_object_properties` | 2 | 6.7s |  |
| 54 | `divide_swf4` | 107 | 6.8s |  |
| 55 | `edittext_antialiastype` | 296 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_autosize_setter` | 20 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_default_format` | 221 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_default_format_empty` | 95 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_width_height` | 103 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `enumerate` | 64 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 61 | `equals` | 32 | 6.6s |  |
| 62 | `equals2_swf5` | 926 | 8.4s |  |
| 63 | `equals2_swf6` | 926 | 8.5s |  |
| 64 | `equals2_swf7` | 926 | 8.5s |  |
| 65 | `equals_swf4` | 665 | 7.2s |  |
| 66 | `equals_swf4_alt` | 32 | 6.7s |  |
| 67 | `equals_swf5` | 32 | 6.6s |  |
| 68 | `error` | 58 | 6.6s |  |
| 69 | `escape` | 14 | 6.5s |  |
| 70 | `execution_order1` | 5 | 6.6s |  |
| 71 | `execution_order3` | 4 | 6.5s |  |
| 72 | `focusrect_mouse_swf8` | 0 | 6.4s |  |
| 73 | `focusrect_mouse_swf9` | 0 | 6.4s |  |
| 74 | `focusrect_swf5` | 6 | 6.6s |  |
| 75 | `function_suppress_and_preload` | 28 | 6.7s |  |
| 76 | `get_variable_in_scope` | 29 | 6.5s |  |
| 77 | `getproperty` | 28 | 6.5s |  |
| 78 | `getproperty_swf4` | 28 | 6.4s |  |
| 79 | `getproperty_swf5` | 28 | 6.4s |  |
| 80 | `global_array` | 3 | 6.5s |  |
| 81 | `global_is_bare` | 7 | 6.4s |  |
| 82 | `globals_swf5` | 304 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `globals_swf6` | 304 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 84 | `globals_swf7` | 304 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 85 | `globals_swf8` | 304 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 86 | `goto_execution_order` | 2 | 6.5s |  |
| 87 | `goto_execution_order2` | 2 | 6.5s |  |
| 88 | `goto_frame_number` | 3 | 6.6s |  |
| 89 | `greater_swf6` | 1175 | 8.5s |  |
| 90 | `greater_swf7` | 1175 | 8.7s |  |
| 91 | `greaterthan_swf5` | 1 | 6.5s |  |
| 92 | `greaterthan_swf8` | 1 | 6.5s |  |
| 93 | `has_own_property` | 32 | 6.6s |  |
| 94 | `infinite_recursion_function` | 4 | 6.6s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 95 | `infinite_recursion_function_in_setter` | 131 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 96 | `infinite_recursion_virtual_property` | 67 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 97 | `init_array_invalid` | 4 | 6.7s |  |
| 98 | `init_object_invalid` | 4 | 6.7s |  |
| 99 | `is_finite` | 49 | 6.6s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 100 | `is_finite_swf6` | 49 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 101 | `is_prototype_of` | 89 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 102 | `issue_1086` | 1 | 6.5s |  |
| 103 | `issue_1671` | 0 | 6.5s |  |
| 104 | `issue_2166` | 9 | 6.6s |  |
| 105 | `issue_3446` | 1 | 6.5s |  |
| 106 | `issue_4377` | 2 | 6.5s |  |
| 107 | `issue_710` | 4 | 6.5s |  |
| 108 | `issue_768` | 3 | 6.5s | [12](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 109 | `lessthan` | 41 | 6.6s |  |
| 110 | `lessthan2_swf5` | 1226 | 8.7s |  |
| 111 | `lessthan2_swf6` | 1226 | 8.6s |  |
| 112 | `lessthan2_swf7` | 1226 | 8.7s |  |
| 113 | `lessthan_swf4` | 902 | 7.2s |  |
| 114 | `lessthan_swf4_alt` | 41 | 6.5s |  |
| 115 | `lessthan_swf5` | 41 | 6.6s |  |
| 116 | `logical_ops_swf4` | 90 | 6.4s |  |
| 117 | `logical_ops_swf8` | 108 | 6.5s |  |
| 118 | `looping` | 6 | 6.4s |  |
| 119 | `mask_reapply` | 0 | 6.4s |  |
| 120 | `mask_with_drawing` | 0 | 6.4s |  |
| 121 | `math_min_max` | 101 | 6.6s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 122 | `matrix` | 171 | 6.8s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 123 | `movieclip_begin_gradient_fill` | 0 | 7.3s |  |
| 124 | `movieclip_blend_mode_property` | 35 | 6.5s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 125 | `movieclip_get_instance_at_depth` | 28 | 6.5s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `movieclip_line_gradient_style` | 0 | 7.0s |  |
| 127 | `movieclip_prototype_extension` | 5 | 6.5s |  |
| 128 | `nested_textfields_in_buttons` | 0 | 6.6s |  |
| 129 | `netstream_play_flv_screen` | 0 | 19.4s |  |
| 130 | `new_method_wrap` | 4 | 6.5s |  |
| 131 | `new_object_enumerate` | 7 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 132 | `new_object_wrap` | 4 | 6.5s |  |
| 133 | `o` | 3 | 6.5s |  |
| 134 | `object_constructor` | 33 | 6.5s |  |
| 135 | `object_function` | 32 | 6.5s |  |
| 136 | `object_properties` | 31 | 6.7s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 137 | `object_prototypes` | 74 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 138 | `object_string_coerce_swf5` | 62 | 6.6s | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 139 | `parse_int` | 64 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 140 | `point` | 175 | 7.1s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 141 | `primitive_instanceof` | 37 | 6.5s |  |
| 142 | `primitive_type_globals` | 557 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 143 | `prototype_delete` | 12 | 6.5s |  |
| 144 | `prototype_enumerate` | 5 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 145 | `prototype_properties` | 17 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 146 | `rectangle` | 745 | 7.3s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 147 | `recursive_prototypes` | 0 | 6.5s |  |
| 148 | `sandbox_type_local_file` | 1 | 6.6s |  |
| 149 | `set_variable_scope` | 58 | 6.6s |  |
| 150 | `single_frame` | 1 | 6.5s |  |
| 151 | `sound_start_load` | 0 | 6.6s |  |
| 152 | `stage_object_properties_get_var` | 5 | 6.5s |  |
| 153 | `stage_property_representation` | 586 | 6.6s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 154 | `strictequals_swf6` | 902 | 8.1s |  |
| 155 | `strictly_equals` | 7 | 6.6s |  |
| 156 | `string_coercion` | 117 | 6.8s | [25](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 157 | `string_methods` | 285 | 7.1s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 158 | `string_methods_negative_args` | 240 | 6.6s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 159 | `string_methods_swfv5` | 275 | 7.1s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 160 | `string_ops_swf6` | 95 | 6.6s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 161 | `string_paths_keyevents` | 0 | 6.5s |  |
| 162 | `string_paths_timer` | 0 | 6.6s |  |
| 163 | `swf4_actions_bool` | 96 | 6.6s |  |
| 164 | `swf4_bool` | 4 | 6.5s |  |
| 165 | `swf4_function_calls` | 7 | 6.5s |  |
| 166 | `swf5_encoding` | 3 | 6.2s |  |
| 167 | `swf7_case_sensitive` | 44 | 6.2s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `tab_ordering_properties_tab_index_edge_case` | 4 | 6.1s |  |
| 169 | `text_format` | 1146 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 170 | `text_format_display` | 21 | 6.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 171 | `text_format_font_max_length` | 2 | 6.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 172 | `text_format_rounding_swf7` | 840 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `text_format_rounding_swf8` | 840 | 6.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 174 | `textfield_background_color` | 11 | 6.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `textfield_border_color` | 11 | 6.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `textfield_maxchars` | 3 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `textfield_properties` | 44 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `textfield_props_swf6` | 210 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `textfield_props_swf7` | 210 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `textfield_props_swf8` | 210 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `textfield_text` | 7 | 6.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `this_swf7` | 41 | 6.4s | [29](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 183 | `timeline_function_def` | 7 | 6.4s |  |
| 184 | `try_catch_finally` | 118 | 6.6s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 185 | `try_finally_simple` | 16 | 6.5s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 186 | `typeof` | 22 | 6.5s |  |
| 187 | `typeof_globals` | 7 | 6.5s |  |
| 188 | `uncaught_exception` | 1 | 6.5s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 189 | `uncaught_exception_bubbled` | 1 | 6.5s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 190 | `undefined_to_string_swf6` | 4 | 6.5s |  |
| 191 | `unescape` | 43 | 6.5s |  |
| 192 | `use_hand_cursor` | 8 | 6.5s |  |
| 193 | `variable_args` | 5 | 6.6s |  |
| 194 | `waitforframe` | 7 | 6.5s |  |
| 195 | `waitforframe2` | 16 | 6.5s |  |
| 196 | `watch` | 117 | 6.8s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 197 | `watch_virtual_property_proto` | 2 | 6.5s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 198 | `with_return` | 2 | 6.5s |  |
| 199 | `with_variable_scopes` | 43 | 6.7s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 200 | `xml` | 15 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 201 | `xml_append_child` | 28 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 202 | `xml_append_child_with_parent` | 20 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 203 | `xml_cdata` | 11 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 204 | `xml_child_nodes_edge_cases` | 4 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 205 | `xml_clone_expandos` | 19 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 206 | `xml_first_last_child` | 8 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 207 | `xml_has_child_nodes` | 3 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 208 | `xml_idmap` | 21 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 209 | `xml_ignore_comments` | 21 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 210 | `xml_ignore_white` | 34 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_insert_before` | 20 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_inspect_createmethods` | 15 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_inspect_doctype` | 7 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_inspect_parsexml` | 62 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_inspect_xmldecl` | 7 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_namespaces` | 203 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_parent_and_child` | 5 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_remove_node` | 22 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_reparenting` | 14 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_siblings` | 10 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_to_string` | 13 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_to_string_comment` | 1 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_unescaping` | 23 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xmlnode_proto` | 1 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**80 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `textfield_variable` | 96.3% | 78 | 81 | 3 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `conflicting_instance_names` | 95.7% | 22 | 23 | 1 |  |
| 8 | `edittext_default_format_font_style` | 94.0% | 315 | 335 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 9 | `with` | 93.9% | 46 | 49 | 3 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 10 | `movieclip_name_from_timeline` | 92.3% | 12 | 13 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 12 | `transform` | 90.0% | 63 | 70 | 7 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 13 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `local_to_global` | 83.7% | 41 | 49 | 8 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 17 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `this_scoping` | 80.8% | 42 | 52 | 10 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 19 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 20 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `do_init_action` | 75.0% | 3 | 4 | 1 |  |
| 24 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `add_property` | 73.3% | 11 | 15 | 4 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `attach_movie` | 72.9% | 43 | 59 | 16 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 29 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 30 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 31 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 32 | `register_underflow` | 69.2% | 18 | 26 | 8 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 37 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 38 | `goto_advance2` | 66.7% | 2 | 3 | 1 |  |
| 39 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 40 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 41 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 42 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 45 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 46 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 49 | `edittext_align` | 60.0% | 36 | 60 | 24 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `goto_rewind2` | 60.0% | 3 | 5 | 2 |  |
| 56 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `parse_float` | 58.1% | 43 | 74 | 31 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 58 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `asnative` | 55.9% | 19 | 34 | 15 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 60 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 61 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 62 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 65 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 66 | `bad_placeobject_clipaction` | 50.0% | 1 | 2 | 1 |  |
| 67 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `goto_rewind3` | 50.0% | 2 | 4 | 2 |  |
| 69 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 70 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 71 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 72 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 73 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 74 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 75 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 76 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 77 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 78 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 79 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `unload_clip_event` | 50.0% | 2 | 4 | 2 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 8.8s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |

## Runtime Errors

**6 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `clip_events` | exit code -6 | 8.8s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 2 | `default_names` | exit code -6 | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `function_base_clip_readded` | exit code -6 | 8.6s |  |
| 4 | `movieclip_depth_methods` | exit code -6 | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 5 | `movieclip_hittest_shapeflag` | exit code -6 | 9.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `placeobject_occupied_depth` | exit code -8 | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.7s | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**247 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `textfield_variable` | 96.3% | 78/81 | 81 | 81 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `conflicting_instance_names` | 95.7% | 22/23 | 23 | 23 |  |
| 8 | `edittext_default_format_font_style` | 94.0% | 315/335 | 335 | 335 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 9 | `with` | 93.9% | 46/49 | 49 | 49 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 10 | `movieclip_name_from_timeline` | 92.3% | 12/13 | 13 | 13 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 12 | `transform` | 90.0% | 63/70 | 70 | 70 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 13 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 17 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 19 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 20 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `do_init_action` | 75.0% | 3/4 | 4 | 3 |  |
| 24 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `add_property` | 73.3% | 11/15 | 15 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 29 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 30 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 31 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 32 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 37 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 38 | `goto_advance2` | 66.7% | 2/3 | 3 | 2 |  |
| 39 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 40 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 41 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 42 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 45 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 46 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 49 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `goto_rewind2` | 60.0% | 3/5 | 5 | 3 |  |
| 56 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 58 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `asnative` | 55.9% | 19/34 | 31 | 34 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 60 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 61 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 62 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 65 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 66 | `bad_placeobject_clipaction` | 50.0% | 1/2 | 1 | 2 |  |
| 67 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `goto_rewind3` | 50.0% | 2/4 | 4 | 2 |  |
| 69 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 70 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 71 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 72 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 73 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 74 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 75 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 76 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 77 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 78 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 79 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `unload_clip_event` | 50.0% | 2/4 | 2 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 81 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 82 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 85 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 86 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 87 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 89 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 90 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 91 | `goto_both_ways1` | 40.0% | 2/5 | 5 | 3 |  |
| 92 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 93 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 94 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 95 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 96 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 98 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 99 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 103 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 106 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 107 | `stage_object_properties_swf6` | 30.5% | 131/429 | 429 | 231 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 108 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 109 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 110 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 111 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 112 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 113 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 114 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 115 | `execution_order4` | 25.0% | 3/12 | 11 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 116 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 117 | `goto_rewind1` | 25.0% | 1/4 | 4 | 1 |  |
| 118 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 119 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 120 | `unload` | 25.0% | 13/52 | 49 | 52 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 121 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 123 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 124 | `stage_object_properties` | 22.9% | 131/571 | 571 | 241 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 125 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 126 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 127 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 129 | `goto_both_ways2` | 20.0% | 1/5 | 5 | 3 |  |
| 130 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 131 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 132 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 133 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 134 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 135 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 136 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 137 | `path_string` | 15.2% | 49/322 | 300 | 322 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 138 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 139 | `goto_advance1` | 14.3% | 1/7 | 7 | 6 |  |
| 140 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 141 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 142 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 143 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 144 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 145 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 146 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 147 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 148 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 149 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 150 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 151 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 152 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 153 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 154 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 155 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 156 | `selection` | 9.3% | 42/454 | 244 | 454 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 157 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 158 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 159 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 160 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 161 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 162 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 163 | `define_local` | 7.4% | 2/27 | 23 | 27 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 164 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 165 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 167 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 168 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 169 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 170 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 171 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 172 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 173 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 174 | `duplicate_movie_clip` | 5.0% | 1/20 | 18 | 20 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 175 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 176 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 177 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 178 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 179 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 180 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 181 | `register_class` | 3.0% | 2/66 | 27 | 66 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 182 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 184 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 185 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 187 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 188 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 189 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 190 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 191 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 192 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 193 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 194 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 195 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 196 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 197 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 198 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 199 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 200 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 201 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 202 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 203 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 204 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 205 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 206 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 207 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 208 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 209 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 210 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 211 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 212 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 213 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 215 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 216 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 217 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 218 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 219 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 220 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 221 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 222 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 223 | `native_objects_swf8` | 0.0% | 0/146 | 146 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 224 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 225 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 226 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 227 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 228 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 229 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 231 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 232 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 233 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 234 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 235 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 236 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 237 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 238 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 239 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 240 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 241 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 242 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 243 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 244 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 245 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 246 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 247 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

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
| | *(tests not in any document)* | 201 | 128 | 73 |
