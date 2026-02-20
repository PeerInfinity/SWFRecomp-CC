# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-20 03:51 UTC

**Git SHA**: `d71ead76ea`

**Run Duration**: 72m 37s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **227** (36.7%) |
| Failing | 392 |
| Total expected lines | 91478 |
| Matching lines | 51897 (56.7%) |
| Mismatched lines | 39581 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 390 | 99.5% |
| Runtime Segfault | 1 | 0.3% |
| Timeout | 1 | 0.3% |

## Passing Tests

**227 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.0s |  |
| 2 | `action_to_integer` | 28 | 6.8s |  |
| 3 | `add` | 28 | 6.6s |  |
| 4 | `add2` | 354 | 6.8s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 6.6s |  |
| 6 | `add_swf5` | 28 | 6.6s |  |
| 7 | `arguments` | 127 | 6.6s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 6.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 6.7s |  |
| 10 | `array_constructor` | 30 | 6.7s |  |
| 11 | `array_enumerate` | 4 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 6.7s |  |
| 13 | `array_properties` | 36 | 6.6s |  |
| 14 | `array_prototyping` | 12 | 6.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 6.7s |  |
| 16 | `array_sort_random` | 443 | 6.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 6.8s |  |
| 18 | `array_trivial` | 209 | 6.8s |  |
| 19 | `as1_constructor_v6` | 35 | 6.6s |  |
| 20 | `as1_constructor_v7` | 35 | 8.3s |  |
| 21 | `as2_oop` | 13 | 6.9s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 6.6s |  |
| 23 | `as_set_prop_flags_version` | 31 | 6.7s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 6.7s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 6.7s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 6.6s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 6.6s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 6.6s |  |
| 29 | `bad_swf_tag_past_eof` | 0 | 7.0s |  |
| 30 | `bitand` | 1058 | 9.9s |  |
| 31 | `bitmap_data_colortransform` | 0 | 7.1s |  |
| 32 | `bitmap_data_fillrect` | 0 | 7.0s |  |
| 33 | `bitmap_data_max_size_swf10` | 12 | 6.9s |  |
| 34 | `bitmap_data_max_size_swf9` | 10 | 6.9s |  |
| 35 | `bitmap_data_perlinnoise` | 0 | 7.5s |  |
| 36 | `bitmap_data_pixeldissolve_image` | 0 | 7.5s |  |
| 37 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.1s |  |
| 38 | `bitor` | 1058 | 9.7s |  |
| 39 | `biturshift` | 14 | 6.9s |  |
| 40 | `biturshift_swf8` | 14 | 9.0s |  |
| 41 | `bitxor` | 1058 | 9.5s |  |
| 42 | `call_method_empty_name` | 1 | 6.6s |  |
| 43 | `capabilities_resolution` | 8 | 6.7s |  |
| 44 | `catch_references_registers` | 2 | 6.9s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 45 | `clone_sprite_types` | 24 | 6.7s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `color` | 57 | 7.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 47 | `color_transform` | 48 | 6.9s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 48 | `define_function2` | 8 | 6.7s |  |
| 49 | `define_function2_preload` | 13 | 6.8s |  |
| 50 | `define_function2_preload_order` | 4 | 7.5s |  |
| 51 | `define_function_case_sensitive` | 2 | 7.0s |  |
| 52 | `delete` | 3 | 6.9s |  |
| 53 | `display_object_properties` | 2 | 6.7s |  |
| 54 | `divide_swf4` | 107 | 6.7s |  |
| 55 | `edittext_antialiastype` | 296 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_autosize_setter` | 20 | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_default_format` | 221 | 7.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_default_format_empty` | 95 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_password` | 5 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_width_height` | 103 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `enumerate` | 64 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 62 | `equals` | 32 | 6.6s |  |
| 63 | `equals2_swf5` | 926 | 8.3s |  |
| 64 | `equals2_swf6` | 926 | 8.3s |  |
| 65 | `equals2_swf7` | 926 | 8.3s |  |
| 66 | `equals_swf4` | 665 | 7.0s |  |
| 67 | `equals_swf4_alt` | 32 | 6.6s |  |
| 68 | `equals_swf5` | 32 | 6.6s |  |
| 69 | `error` | 58 | 6.6s |  |
| 70 | `escape` | 14 | 6.6s |  |
| 71 | `execution_order1` | 5 | 6.6s |  |
| 72 | `execution_order3` | 4 | 6.6s |  |
| 73 | `focusrect_mouse_swf8` | 0 | 6.8s |  |
| 74 | `focusrect_mouse_swf9` | 0 | 7.1s |  |
| 75 | `focusrect_swf5` | 6 | 6.7s |  |
| 76 | `function_suppress_and_preload` | 28 | 6.7s |  |
| 77 | `get_variable_in_scope` | 29 | 6.6s |  |
| 78 | `getproperty` | 28 | 6.6s |  |
| 79 | `getproperty_swf4` | 28 | 8.8s |  |
| 80 | `getproperty_swf5` | 28 | 6.7s |  |
| 81 | `global_array` | 3 | 6.7s |  |
| 82 | `global_is_bare` | 7 | 6.6s |  |
| 83 | `globals_swf5` | 304 | 7.0s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 84 | `globals_swf6` | 304 | 7.0s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 85 | `globals_swf7` | 304 | 7.0s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 86 | `globals_swf8` | 304 | 6.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 87 | `goto_execution_order` | 2 | 6.7s |  |
| 88 | `goto_execution_order2` | 2 | 6.7s |  |
| 89 | `goto_frame_number` | 3 | 6.7s |  |
| 90 | `greater_swf6` | 1175 | 8.6s |  |
| 91 | `greater_swf7` | 1175 | 8.7s |  |
| 92 | `greaterthan_swf5` | 1 | 6.7s |  |
| 93 | `greaterthan_swf8` | 1 | 6.6s |  |
| 94 | `has_own_property` | 32 | 6.7s |  |
| 95 | `infinite_recursion_function` | 4 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 96 | `infinite_recursion_function_in_setter` | 131 | 6.6s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 97 | `infinite_recursion_virtual_property` | 67 | 6.6s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 98 | `init_array_invalid` | 4 | 6.6s |  |
| 99 | `init_object_invalid` | 4 | 7.0s |  |
| 100 | `is_finite` | 49 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 101 | `is_finite_swf6` | 49 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 102 | `is_prototype_of` | 89 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 103 | `issue_1086` | 1 | 6.6s |  |
| 104 | `issue_1671` | 0 | 6.7s |  |
| 105 | `issue_2166` | 9 | 6.6s |  |
| 106 | `issue_3446` | 1 | 6.7s |  |
| 107 | `issue_4377` | 2 | 6.6s |  |
| 108 | `issue_710` | 4 | 6.6s |  |
| 109 | `issue_768` | 3 | 7.0s | [12](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 110 | `lessthan` | 41 | 6.7s |  |
| 111 | `lessthan2_swf5` | 1226 | 8.9s |  |
| 112 | `lessthan2_swf6` | 1226 | 8.8s |  |
| 113 | `lessthan2_swf7` | 1226 | 8.8s |  |
| 114 | `lessthan_swf4` | 902 | 7.3s |  |
| 115 | `lessthan_swf4_alt` | 41 | 6.7s |  |
| 116 | `lessthan_swf5` | 41 | 6.7s |  |
| 117 | `logical_ops_swf4` | 90 | 7.0s |  |
| 118 | `logical_ops_swf8` | 108 | 7.0s |  |
| 119 | `looping` | 6 | 6.9s |  |
| 120 | `mask_reapply` | 0 | 6.9s |  |
| 121 | `mask_with_drawing` | 0 | 7.0s |  |
| 122 | `math_min_max` | 101 | 7.1s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 123 | `matrix` | 171 | 7.4s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 124 | `mouse_listeners` | 67 | 6.7s |  |
| 125 | `mouse_wheel_enabled` | 2 | 6.7s |  |
| 126 | `movieclip_begin_gradient_fill` | 0 | 7.2s |  |
| 127 | `movieclip_blend_mode_property` | 35 | 6.9s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `movieclip_get_instance_at_depth` | 28 | 6.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 129 | `movieclip_line_gradient_style` | 0 | 7.4s |  |
| 130 | `movieclip_prototype_extension` | 5 | 6.9s |  |
| 131 | `nested_textfields_in_buttons` | 0 | 6.7s |  |
| 132 | `netstream_play_flv_screen` | 0 | 20.4s |  |
| 133 | `new_method_wrap` | 4 | 6.7s |  |
| 134 | `new_object_enumerate` | 7 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 135 | `new_object_wrap` | 4 | 6.8s |  |
| 136 | `o` | 3 | 6.7s |  |
| 137 | `object_constructor` | 33 | 6.7s |  |
| 138 | `object_function` | 32 | 6.8s |  |
| 139 | `object_properties` | 31 | 6.9s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 140 | `object_prototypes` | 74 | 6.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 141 | `object_string_coerce_swf5` | 62 | 6.9s | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 142 | `parse_int` | 64 | 6.9s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 143 | `point` | 175 | 7.1s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 144 | `primitive_instanceof` | 37 | 6.7s |  |
| 145 | `primitive_type_globals` | 557 | 7.2s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 146 | `prototype_delete` | 12 | 6.9s |  |
| 147 | `prototype_enumerate` | 5 | 6.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 148 | `prototype_properties` | 17 | 7.0s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 149 | `rectangle` | 745 | 7.8s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 150 | `recursive_prototypes` | 0 | 6.9s |  |
| 151 | `sandbox_type_local_file` | 1 | 6.7s |  |
| 152 | `set_variable_scope` | 58 | 6.7s |  |
| 153 | `single_frame` | 1 | 6.6s |  |
| 154 | `sound_start_load` | 0 | 6.9s |  |
| 155 | `stage_object_properties_get_var` | 5 | 6.8s |  |
| 156 | `stage_property_representation` | 586 | 6.8s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 157 | `strictequals_swf6` | 902 | 8.3s |  |
| 158 | `strictly_equals` | 7 | 6.8s |  |
| 159 | `string_coercion` | 117 | 7.1s | [25](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 160 | `string_methods` | 285 | 7.3s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 161 | `string_methods_negative_args` | 240 | 6.9s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 162 | `string_methods_swfv5` | 275 | 7.3s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 163 | `string_ops_swf6` | 95 | 6.8s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 164 | `string_paths_keyevents` | 0 | 6.7s |  |
| 165 | `string_paths_timer` | 0 | 6.8s |  |
| 166 | `swf4_actions_bool` | 96 | 6.8s |  |
| 167 | `swf4_bool` | 4 | 6.7s |  |
| 168 | `swf4_function_calls` | 7 | 6.8s |  |
| 169 | `swf5_encoding` | 3 | 6.7s |  |
| 170 | `swf7_case_sensitive` | 44 | 6.8s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `tab_ordering_properties_tab_index_edge_case` | 4 | 6.7s |  |
| 172 | `text_format` | 1146 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `text_format_display` | 21 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 174 | `text_format_font_max_length` | 2 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `text_format_rounding_swf7` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `text_format_rounding_swf8` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `textfield_background_color` | 11 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `textfield_border_color` | 11 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `textfield_maxchars` | 3 | 11.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `textfield_properties` | 44 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `textfield_props_swf6` | 210 | 7.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `textfield_props_swf7` | 210 | 7.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 183 | `textfield_props_swf8` | 210 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 184 | `textfield_text` | 7 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 185 | `this_swf7` | 41 | 6.8s | [29](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 186 | `timeline_function_def` | 7 | 6.9s |  |
| 187 | `try_catch_finally` | 118 | 6.7s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 188 | `try_finally_simple` | 16 | 6.6s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 189 | `typeof` | 22 | 6.6s |  |
| 190 | `typeof_globals` | 7 | 6.6s |  |
| 191 | `uncaught_exception` | 1 | 6.6s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 192 | `uncaught_exception_bubbled` | 1 | 6.6s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 193 | `undefined_to_string_swf6` | 4 | 6.6s |  |
| 194 | `unescape` | 43 | 6.6s |  |
| 195 | `use_hand_cursor` | 8 | 6.6s |  |
| 196 | `variable_args` | 5 | 6.7s |  |
| 197 | `waitforframe` | 7 | 6.6s |  |
| 198 | `waitforframe2` | 16 | 7.6s |  |
| 199 | `watch` | 117 | 7.0s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 200 | `watch_virtual_property_proto` | 2 | 6.8s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 201 | `with_return` | 2 | 6.7s |  |
| 202 | `with_variable_scopes` | 43 | 6.8s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 203 | `xml` | 15 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 204 | `xml_append_child` | 28 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 205 | `xml_append_child_with_parent` | 20 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 206 | `xml_cdata` | 11 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 207 | `xml_child_nodes_edge_cases` | 4 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 208 | `xml_clone_expandos` | 19 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 209 | `xml_first_last_child` | 8 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 210 | `xml_has_child_nodes` | 3 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_idmap` | 21 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_ignore_comments` | 21 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_ignore_white` | 34 | 7.1s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_insert_before` | 20 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_inspect_createmethods` | 15 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_inspect_doctype` | 7 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_inspect_parsexml` | 62 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_inspect_xmldecl` | 7 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_namespaces` | 203 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_parent_and_child` | 5 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_remove_node` | 22 | 7.0s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_reparenting` | 14 | 7.0s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_siblings` | 10 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xml_to_string` | 13 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 225 | `xml_to_string_comment` | 1 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 226 | `xml_unescaping` | 23 | 7.0s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 227 | `xmlnode_proto` | 1 | 7.0s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**99 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `math_swf6` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf7` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `math_swf8` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 6 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 7 | `textfield_variable` | 96.3% | 78 | 81 | 3 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 9 | `conflicting_instance_names` | 95.7% | 22 | 23 | 1 |  |
| 10 | `duplicate_movie_clip` | 95.0% | 19 | 20 | 1 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_depth_methods` | 94.9% | 93 | 98 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 12 | `edittext_default_format_font_style` | 94.0% | 315 | 335 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 13 | `with` | 93.9% | 46 | 49 | 3 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 14 | `movieclip_name_from_timeline` | 92.3% | 12 | 13 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 16 | `transform` | 90.0% | 63 | 70 | 7 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 17 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `local_to_global` | 83.7% | 41 | 49 | 8 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 20 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 21 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `this_scoping` | 80.8% | 42 | 52 | 10 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 23 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 25 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 27 | `do_init_action` | 75.0% | 3 | 4 | 1 |  |
| 28 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `sound_props_swf5` | 73.5% | 50 | 68 | 18 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 30 | `add_property` | 73.3% | 11 | 15 | 4 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `attach_movie` | 72.9% | 43 | 59 | 16 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 32 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 33 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 34 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 35 | `as_transformed_flag` | 70.0% | 14 | 20 | 6 |  |
| 36 | `register_underflow` | 69.2% | 18 | 26 | 8 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 38 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 39 | `export_assets` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 40 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 41 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 42 | `goto_advance2` | 66.7% | 2 | 3 | 1 |  |
| 43 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 44 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 45 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 46 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 49 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 50 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 53 | `edittext_align` | 60.0% | 36 | 60 | 24 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `goto_rewind2` | 60.0% | 3 | 5 | 2 |  |
| 61 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 62 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `parse_float` | 58.1% | 43 | 74 | 31 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 64 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 65 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 66 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 67 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `asnative` | 55.9% | 19 | 34 | 15 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 69 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 70 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 71 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `sound_props_swf6` | 52.9% | 36 | 68 | 32 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 74 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 75 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 76 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 78 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 79 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 80 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `goto_rewind3` | 50.0% | 2 | 4 | 2 |  |
| 82 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 83 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 84 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 85 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 88 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 89 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 90 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 91 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 92 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 93 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 94 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 95 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `unload_clip_event` | 50.0% | 2 | 4 | 2 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 98 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 99 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 8.9s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.8s | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**390 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 6 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 7 | `textfield_variable` | 96.3% | 78/81 | 81 | 81 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 9 | `conflicting_instance_names` | 95.7% | 22/23 | 23 | 23 |  |
| 10 | `duplicate_movie_clip` | 95.0% | 19/20 | 20 | 20 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_depth_methods` | 94.9% | 93/98 | 98 | 98 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 12 | `edittext_default_format_font_style` | 94.0% | 315/335 | 335 | 335 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 13 | `with` | 93.9% | 46/49 | 49 | 49 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 14 | `movieclip_name_from_timeline` | 92.3% | 12/13 | 13 | 13 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 16 | `transform` | 90.0% | 63/70 | 70 | 70 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 17 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 20 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 21 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 23 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 25 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 27 | `do_init_action` | 75.0% | 3/4 | 4 | 3 |  |
| 28 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `sound_props_swf5` | 73.5% | 50/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 30 | `add_property` | 73.3% | 11/15 | 15 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 32 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 33 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 34 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 35 | `as_transformed_flag` | 70.0% | 14/20 | 20 | 20 |  |
| 36 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 38 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 39 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 40 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 41 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 42 | `goto_advance2` | 66.7% | 2/3 | 3 | 2 |  |
| 43 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 44 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 45 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 46 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 49 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 50 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 53 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `goto_rewind2` | 60.0% | 3/5 | 5 | 3 |  |
| 61 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 62 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 64 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 65 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 66 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 67 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `asnative` | 55.9% | 19/34 | 31 | 34 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 69 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 70 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 71 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `sound_props_swf6` | 52.9% | 36/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 74 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 75 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 76 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 78 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 79 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 80 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `goto_rewind3` | 50.0% | 2/4 | 4 | 2 |  |
| 82 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 83 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 84 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 85 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 87 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 89 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 90 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 91 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 92 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 93 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 94 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 95 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 96 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `unload_clip_event` | 50.0% | 2/4 | 2 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 98 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 99 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 100 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 101 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 102 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 105 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 106 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 107 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 109 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 110 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 111 | `goto_both_ways1` | 40.0% | 2/5 | 5 | 3 |  |
| 112 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 113 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 114 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 115 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 116 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 117 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 119 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 120 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 123 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 124 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 125 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 127 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 128 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 129 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 130 | `stage_object_properties_swf6` | 30.5% | 131/429 | 429 | 231 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 131 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 132 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 133 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 134 | `default_names` | 26.2% | 16/61 | 61 | 52 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 135 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 136 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 137 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 138 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 139 | `execution_order4` | 25.0% | 3/12 | 11 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 140 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 141 | `goto_rewind1` | 25.0% | 1/4 | 4 | 1 |  |
| 142 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 143 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 144 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 145 | `textsnapshot_props_swf5` | 25.0% | 14/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 146 | `unload` | 25.0% | 13/52 | 49 | 52 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 147 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 148 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 149 | `stage_object_properties` | 22.9% | 131/571 | 571 | 241 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 150 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 151 | `focusrect_property_swf5` | 21.7% | 269/1237 | 1236 | 1237 |  |
| 152 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 153 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 154 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 155 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 156 | `goto_both_ways2` | 20.0% | 1/5 | 5 | 3 |  |
| 157 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 158 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 159 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 160 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 161 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 162 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 163 | `as_broadcaster` | 17.1% | 7/41 | 25 | 41 |  |
| 164 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 165 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 166 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 167 | `printjob_props_swf7` | 15.6% | 7/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 168 | `path_string` | 15.2% | 49/322 | 300 | 322 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 169 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 170 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 171 | `goto_advance1` | 14.3% | 1/7 | 7 | 6 |  |
| 172 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 173 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 175 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 176 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 177 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 178 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 179 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 180 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 181 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 182 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 183 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 184 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 185 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 186 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 187 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 188 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 189 | `placeobject_occupied_depth` | 11.1% | 1/9 | 9 | 6 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 190 | `printjob_props_swf5` | 11.1% | 5/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 191 | `printjob_props_swf6` | 11.1% | 5/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 192 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 193 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 194 | `selection` | 9.3% | 42/454 | 244 | 454 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 195 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 196 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 197 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 198 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 199 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 200 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 201 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 202 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 203 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 204 | `define_local` | 7.4% | 2/27 | 23 | 27 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 205 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 206 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 207 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 208 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 209 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 210 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 211 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 212 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 213 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 214 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 215 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 216 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 217 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 218 | `clip_events` | 5.3% | 1/19 | 9 | 19 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 219 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 220 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 221 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 222 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 223 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 224 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 225 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 227 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 228 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 229 | `register_class` | 3.0% | 2/66 | 27 | 66 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 230 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 231 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 232 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 233 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 234 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 235 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 236 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 237 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 238 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 239 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 240 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 241 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 242 | `global_proto_decls` | 0.2% | 8/4497 | 446 | 4497 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 243 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 244 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 245 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 246 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 247 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 248 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 249 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 250 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 251 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 252 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 253 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 256 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 257 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 258 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 259 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 260 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 261 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 262 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 263 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 264 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 265 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 266 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 267 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 269 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 270 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 271 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 272 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 273 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 274 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 275 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 276 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 277 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 278 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 279 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 280 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 281 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 282 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 283 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 284 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 285 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 286 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 287 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 288 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 289 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 291 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 292 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 293 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 294 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 295 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 296 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 297 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 298 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 299 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 300 | `global_proto_decls_delete` | 0.0% | 0/4158 | 149 | 4158 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 301 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 302 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 303 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 304 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 305 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 306 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 307 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 308 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 310 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 311 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 312 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 313 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 314 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 315 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 316 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 317 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 318 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 319 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 320 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 321 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 322 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 323 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 324 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 325 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 326 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 327 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 328 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 329 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 330 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 331 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 332 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 |  |
| 333 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 |  |
| 334 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 335 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 336 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 337 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 339 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 340 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 341 | `native_objects_swf8` | 0.0% | 0/146 | 146 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 342 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 343 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 344 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 345 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 346 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 347 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 348 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 349 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 350 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 351 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 352 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 353 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 354 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 355 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 356 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 357 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 358 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 359 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 360 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 361 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 362 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 363 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 364 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 365 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 366 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 367 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 368 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 369 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 370 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 371 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 372 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 373 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 374 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 375 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 376 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 377 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 378 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 379 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 380 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 381 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 382 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 383 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 384 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 385 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 386 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 387 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 388 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 389 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 390 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

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
| 28 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 19 | 51 |
| 29 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 30 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 31 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 32 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 33 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 34 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 311 | 130 | 181 |
