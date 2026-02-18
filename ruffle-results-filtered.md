# Ruffle Test Results (Filtered)

**Date**: 2026-02-18 19:49 UTC

**Git SHA**: `c3381e0ef8`

**Run Duration**: 63m 12s

**Filtered**: 139 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 480 |
| Passing | **224** (46.7%) |
| Failing | 256 |
| Total expected lines | 71655 |
| Matching lines | 41742 (58.3%) |
| Mismatched lines | 29913 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 254 | 99.2% |
| Segfault | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**224 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.1s |  |
| 2 | `action_to_integer` | 28 | 5.8s |  |
| 3 | `add` | 28 | 5.8s |  |
| 4 | `add2` | 354 | 6.0s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 5.8s |  |
| 6 | `add_swf5` | 28 | 5.8s |  |
| 7 | `arguments` | 127 | 5.8s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 5.8s | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 5.8s |  |
| 10 | `array_constructor` | 30 | 5.8s |  |
| 11 | `array_enumerate` | 4 | 5.8s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 5.9s |  |
| 13 | `array_properties` | 36 | 5.8s |  |
| 14 | `array_slice` | 34 | 5.9s |  |
| 15 | `array_splice` | 207 | 6.1s |  |
| 16 | `array_trivial` | 209 | 6.0s |  |
| 17 | `as1_constructor_v6` | 35 | 5.9s |  |
| 18 | `as1_constructor_v7` | 35 | 5.9s |  |
| 19 | `as2_oop` | 13 | 6.0s | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 20 | `as_broadcaster_initialize` | 10 | 5.8s |  |
| 21 | `as_set_prop_flags_version` | 31 | 5.9s | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `as_set_prop_flags_version_swf5` | 1 | 5.9s |  |
| 23 | `as_set_prop_flags_version_swf6` | 1 | 5.9s |  |
| 24 | `as_set_prop_flags_version_swf7` | 1 | 5.9s |  |
| 25 | `as_set_prop_flags_version_swf8` | 1 | 5.9s |  |
| 26 | `as_set_prop_flags_version_swf9` | 1 | 5.9s |  |
| 27 | `as_transformed_flag` | 20 | 5.8s |  |
| 28 | `bad_swf_tag_past_eof` | 0 | 5.8s |  |
| 29 | `bitand` | 1058 | 8.6s |  |
| 30 | `bitmap_data_colortransform` | 0 | 6.1s |  |
| 31 | `bitmap_data_fillrect` | 0 | 5.9s |  |
| 32 | `bitmap_data_max_size_swf10` | 12 | 5.9s |  |
| 33 | `bitmap_data_max_size_swf9` | 10 | 5.8s |  |
| 34 | `bitmap_data_perlinnoise` | 0 | 6.4s |  |
| 35 | `bitmap_data_pixeldissolve_image` | 0 | 6.2s |  |
| 36 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.9s |  |
| 37 | `bitor` | 1058 | 8.4s |  |
| 38 | `biturshift` | 14 | 8.3s |  |
| 39 | `biturshift_swf8` | 14 | 6.0s |  |
| 40 | `bitxor` | 1058 | 8.7s |  |
| 41 | `call_method_empty_name` | 1 | 5.9s |  |
| 42 | `capabilities_resolution` | 8 | 5.9s |  |
| 43 | `catch_references_registers` | 2 | 5.9s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 44 | `conflicting_instance_names` | 23 | 6.0s |  |
| 45 | `define_function2` | 8 | 6.0s |  |
| 46 | `define_function2_preload` | 13 | 5.9s |  |
| 47 | `define_function2_preload_order` | 4 | 5.9s |  |
| 48 | `define_function_case_sensitive` | 2 | 5.9s |  |
| 49 | `delete` | 3 | 6.0s |  |
| 50 | `display_object_properties` | 2 | 5.8s |  |
| 51 | `divide_swf4` | 107 | 5.9s |  |
| 52 | `do_init_action` | 3 | 5.9s |  |
| 53 | `edittext_antialiastype` | 296 | 7.4s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_autosize_setter` | 20 | 6.0s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_default_format` | 221 | 6.1s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_default_format_empty` | 95 | 6.0s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_default_format_font_style` | 335 | 6.2s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `equals` | 32 | 6.0s |  |
| 59 | `equals2_swf5` | 926 | 7.8s |  |
| 60 | `equals2_swf6` | 926 | 7.7s |  |
| 61 | `equals2_swf7` | 926 | 7.7s |  |
| 62 | `equals_swf4` | 665 | 6.4s |  |
| 63 | `equals_swf4_alt` | 32 | 5.9s |  |
| 64 | `equals_swf5` | 32 | 5.9s |  |
| 65 | `error` | 58 | 6.0s |  |
| 66 | `escape` | 14 | 5.9s |  |
| 67 | `execution_order1` | 5 | 6.0s |  |
| 68 | `execution_order2` | 7 | 6.1s |  |
| 69 | `focusrect_mouse_swf8` | 0 | 5.8s |  |
| 70 | `focusrect_mouse_swf9` | 0 | 5.8s |  |
| 71 | `focusrect_swf5` | 6 | 5.9s |  |
| 72 | `function_suppress_and_preload` | 28 | 5.9s |  |
| 73 | `get_variable_in_scope` | 29 | 5.9s |  |
| 74 | `getproperty` | 28 | 5.9s |  |
| 75 | `getproperty_swf4` | 28 | 5.8s |  |
| 76 | `getproperty_swf5` | 28 | 5.8s |  |
| 77 | `global_array` | 3 | 5.8s |  |
| 78 | `global_is_bare` | 7 | 5.8s |  |
| 79 | `globals_swf5` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 80 | `globals_swf6` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 81 | `globals_swf7` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 82 | `globals_swf8` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `goto_advance1` | 6 | 5.8s |  |
| 84 | `goto_advance2` | 2 | 5.8s |  |
| 85 | `goto_both_ways2` | 3 | 6.0s |  |
| 86 | `goto_execution_order` | 2 | 5.9s |  |
| 87 | `goto_frame_number` | 3 | 6.0s |  |
| 88 | `goto_rewind1` | 1 | 6.2s |  |
| 89 | `goto_rewind2` | 3 | 5.9s |  |
| 90 | `greater_swf6` | 1175 | 8.0s |  |
| 91 | `greater_swf7` | 1175 | 8.0s |  |
| 92 | `greaterthan_swf5` | 1 | 5.9s |  |
| 93 | `greaterthan_swf8` | 1 | 5.9s |  |
| 94 | `has_own_property` | 32 | 5.9s |  |
| 95 | `infinite_recursion_function` | 4 | 5.9s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 96 | `infinite_recursion_function_in_setter` | 131 | 6.0s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 97 | `infinite_recursion_virtual_property` | 67 | 6.0s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 98 | `init_array_invalid` | 4 | 5.9s |  |
| 99 | `init_object_invalid` | 4 | 5.9s |  |
| 100 | `is_finite` | 49 | 6.0s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 101 | `is_finite_swf6` | 49 | 6.0s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 102 | `is_prototype_of` | 89 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 103 | `issue_1086` | 1 | 6.0s |  |
| 104 | `issue_1671` | 0 | 5.9s |  |
| 105 | `issue_2166` | 9 | 5.9s |  |
| 106 | `issue_3446` | 1 | 5.9s |  |
| 107 | `issue_4377` | 2 | 5.9s |  |
| 108 | `issue_710` | 4 | 5.9s |  |
| 109 | `issue_768` | 3 | 5.9s | [11](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 110 | `lessthan` | 41 | 5.9s |  |
| 111 | `lessthan2_swf5` | 1226 | 8.2s |  |
| 112 | `lessthan2_swf6` | 1226 | 8.2s |  |
| 113 | `lessthan2_swf7` | 1226 | 8.2s |  |
| 114 | `lessthan_swf4` | 902 | 6.6s |  |
| 115 | `lessthan_swf4_alt` | 41 | 5.9s |  |
| 116 | `lessthan_swf5` | 41 | 6.0s |  |
| 117 | `logical_ops_swf4` | 90 | 5.5s |  |
| 118 | `logical_ops_swf8` | 108 | 5.6s |  |
| 119 | `looping` | 6 | 5.5s |  |
| 120 | `mask_reapply` | 0 | 5.5s |  |
| 121 | `mask_with_drawing` | 0 | 5.6s |  |
| 122 | `math_min_max` | 101 | 5.7s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 123 | `matrix` | 171 | 5.9s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 124 | `movieclip_begin_gradient_fill` | 0 | 6.2s |  |
| 125 | `movieclip_blend_mode_property` | 35 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `movieclip_default_state` | 69 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 127 | `movieclip_get_instance_at_depth` | 28 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `movieclip_line_gradient_style` | 0 | 6.6s |  |
| 129 | `movieclip_name_from_timeline` | 13 | 6.2s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 130 | `movieclip_prototype_extension` | 5 | 6.2s |  |
| 131 | `nested_textfields_in_buttons` | 0 | 6.2s |  |
| 132 | `netstream_play_flv_screen` | 0 | 20.2s |  |
| 133 | `new_method_wrap` | 4 | 6.2s |  |
| 134 | `new_object_enumerate` | 7 | 6.2s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 135 | `new_object_wrap` | 4 | 6.2s |  |
| 136 | `o` | 3 | 6.2s |  |
| 137 | `object_constructor` | 33 | 6.2s |  |
| 138 | `object_function` | 32 | 6.3s |  |
| 139 | `object_properties` | 31 | 6.5s | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 140 | `object_string_coerce_swf5` | 62 | 6.3s | [15](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 141 | `point` | 175 | 6.6s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 142 | `primitive_instanceof` | 37 | 6.1s |  |
| 143 | `prototype_delete` | 12 | 6.2s |  |
| 144 | `prototype_enumerate` | 5 | 6.2s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 145 | `prototype_properties` | 17 | 6.4s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 146 | `rectangle` | 745 | 7.2s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 147 | `recursive_prototypes` | 0 | 6.2s |  |
| 148 | `sandbox_type_local_file` | 1 | 5.8s |  |
| 149 | `set_variable_scope` | 58 | 5.8s |  |
| 150 | `single_frame` | 1 | 5.8s |  |
| 151 | `sound_start_load` | 0 | 5.9s |  |
| 152 | `stage_object_enumerate` | 4 | 5.8s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 153 | `stage_object_properties_get_var` | 5 | 5.8s |  |
| 154 | `stage_property_representation` | 586 | 5.9s | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 155 | `strictequals_swf6` | 902 | 7.5s |  |
| 156 | `strictly_equals` | 7 | 5.9s |  |
| 157 | `string_coercion` | 117 | 6.2s | [24](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 158 | `string_methods` | 285 | 6.5s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 159 | `string_methods_negative_args` | 240 | 6.1s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 160 | `string_methods_swfv5` | 275 | 6.6s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 161 | `string_ops_swf6` | 95 | 6.1s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 162 | `string_paths_keyevents` | 0 | 6.1s |  |
| 163 | `string_paths_timer` | 0 | 6.0s |  |
| 164 | `swf4_actions_bool` | 96 | 6.0s |  |
| 165 | `swf4_bool` | 4 | 5.9s |  |
| 166 | `swf4_function_calls` | 7 | 5.8s |  |
| 167 | `swf5_encoding` | 3 | 5.6s |  |
| 168 | `swf7_case_sensitive` | 44 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 169 | `tab_ordering_properties_tab_index_edge_case` | 4 | 5.7s |  |
| 170 | `text_format` | 1146 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 171 | `text_format_display` | 21 | 5.7s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 172 | `text_format_font_max_length` | 2 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `text_format_rounding_swf7` | 840 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 174 | `text_format_rounding_swf8` | 840 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `textfield_background_color` | 11 | 5.7s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `textfield_border_color` | 11 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `textfield_maxchars` | 3 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `textfield_properties` | 44 | 5.7s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `textfield_props_swf6` | 210 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `textfield_props_swf7` | 210 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `textfield_props_swf8` | 210 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `textfield_text` | 7 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 183 | `textfield_variable` | 81 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 184 | `this_swf7` | 41 | 5.7s | [28](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 185 | `timeline_function_def` | 7 | 5.7s |  |
| 186 | `try_catch_finally` | 118 | 6.0s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 187 | `try_finally_simple` | 16 | 5.8s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 188 | `typeof` | 22 | 5.8s |  |
| 189 | `typeof_globals` | 7 | 5.8s |  |
| 190 | `uncaught_exception` | 1 | 5.8s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 191 | `uncaught_exception_bubbled` | 1 | 5.8s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 192 | `undefined_to_string_swf6` | 4 | 5.8s |  |
| 193 | `unescape` | 43 | 5.9s |  |
| 194 | `use_hand_cursor` | 8 | 5.8s |  |
| 195 | `variable_args` | 5 | 6.0s |  |
| 196 | `waitforframe` | 7 | 5.8s |  |
| 197 | `waitforframe2` | 16 | 5.9s |  |
| 198 | `with_return` | 2 | 5.8s |  |
| 199 | `with_variable_scopes` | 43 | 6.0s | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 200 | `xml` | 15 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 201 | `xml_append_child` | 28 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 202 | `xml_append_child_with_parent` | 20 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 203 | `xml_cdata` | 11 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 204 | `xml_child_nodes_edge_cases` | 4 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 205 | `xml_clone_expandos` | 19 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 206 | `xml_first_last_child` | 8 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 207 | `xml_has_child_nodes` | 3 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 208 | `xml_idmap` | 21 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 209 | `xml_ignore_comments` | 21 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 210 | `xml_ignore_white` | 34 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_insert_before` | 20 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_inspect_createmethods` | 15 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_inspect_doctype` | 7 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_inspect_parsexml` | 62 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_inspect_xmldecl` | 7 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_namespaces` | 203 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_parent_and_child` | 5 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_remove_node` | 22 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_reparenting` | 14 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_siblings` | 10 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_to_string` | 13 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_to_string_comment` | 1 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_unescaping` | 23 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xmlnode_proto` | 1 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**78 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `math_swf6` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 5 | `movieclip_depth_methods` | 95.9% | 94 | 98 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `with` | 93.9% | 46 | 49 | 3 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 10 | `stage_object_properties` | 93.4% | 225 | 241 | 16 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 11 | `stage_object_properties_swf6` | 91.8% | 212 | 231 | 19 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `object_prototypes` | 85.1% | 63 | 74 | 11 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `local_to_global` | 83.7% | 41 | 49 | 8 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 17 | `edittext_width_height` | 81.6% | 84 | 103 | 19 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `this_scoping` | 80.8% | 42 | 52 | 10 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 20 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 22 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 23 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 24 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `add_property` | 73.3% | 11 | 15 | 4 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `attach_movie` | 72.9% | 43 | 59 | 16 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 29 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 30 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 31 | `transform` | 71.4% | 50 | 70 | 20 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 32 | `register_underflow` | 69.2% | 18 | 26 | 8 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [15](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `array_prototyping` | 66.7% | 8 | 12 | 4 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 35 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 36 | `export_assets` | 66.7% | 2 | 3 | 1 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 38 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 39 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 42 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 43 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 45 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `color` | 61.4% | 35 | 57 | 22 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 47 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 48 | `edittext_align` | 60.0% | 36 | 60 | 24 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 55 | `parse_float` | 58.1% | 43 | 74 | 31 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 56 | `primitive_type_globals` | 57.6% | 321 | 557 | 236 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 57 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `asnative` | 55.9% | 19 | 34 | 15 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 59 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 60 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 61 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 65 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 66 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 68 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 69 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 70 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 71 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 72 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 73 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 74 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 75 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 76 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 77 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 78 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 8.2s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.0s | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**254 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 5 | `movieclip_depth_methods` | 95.9% | 94/98 | 98 | 98 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `with` | 93.9% | 46/49 | 49 | 49 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 10 | `stage_object_properties` | 93.4% | 225/241 | 241 | 241 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 11 | `stage_object_properties_swf6` | 91.8% | 212/231 | 231 | 231 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `object_prototypes` | 85.1% | 63/74 | 73 | 74 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 17 | `edittext_width_height` | 81.6% | 84/103 | 103 | 103 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 20 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 22 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 23 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 24 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `add_property` | 73.3% | 11/15 | 15 | 15 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 29 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 30 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 31 | `transform` | 71.4% | 50/70 | 70 | 70 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 32 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [15](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 35 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 36 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 38 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 39 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 42 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 43 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 45 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `color` | 61.4% | 35/57 | 57 | 57 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 47 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 48 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 55 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 56 | `primitive_type_globals` | 57.6% | 321/557 | 555 | 557 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 57 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `asnative` | 55.9% | 19/34 | 31 | 34 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 59 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 60 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 61 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 65 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 66 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 68 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 69 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 70 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 71 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 72 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 73 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 74 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 75 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 76 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 77 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 78 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 80 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 83 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 84 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 85 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 87 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 88 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 89 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 90 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 91 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 92 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 93 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 95 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 96 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `goto_both_ways1` | 33.3% | 1/3 | 2 | 3 |  |
| 100 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 101 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 103 | `enumerate` | 29.7% | 19/64 | 60 | 64 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 104 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 105 | `default_names` | 28.8% | 15/52 | 40 | 52 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 106 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 107 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 108 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 109 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 110 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 114 | `unload` | 21.2% | 11/52 | 48 | 52 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 115 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 116 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 118 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 119 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 120 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 121 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 122 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 123 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 125 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 126 | `watch` | 15.4% | 18/117 | 101 | 117 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 127 | `path_string` | 15.2% | 49/322 | 300 | 322 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 128 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 129 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 130 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 131 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 132 | `register_and_init_order` | 13.4% | 31/231 | 73 | 231 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 133 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 134 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 135 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 136 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 137 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 138 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 139 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 140 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 141 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 142 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 143 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 144 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 146 | `selection` | 9.3% | 42/454 | 244 | 454 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 147 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 148 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 150 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 151 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 152 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 153 | `define_local` | 7.4% | 2/27 | 23 | 27 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 154 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 155 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 156 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 157 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 158 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 159 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 160 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 161 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 162 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 163 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 164 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 165 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 166 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 167 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 168 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 169 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 170 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `register_class` | 3.0% | 2/66 | 27 | 66 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 172 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 173 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `parse_int` | 1.6% | 1/64 | 64 | 64 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 175 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 177 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 178 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 179 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 180 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 181 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 182 | `array_sort_random` | 0.2% | 1/443 | 80 | 443 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 183 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 184 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 185 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 186 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 187 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 188 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 189 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 190 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 191 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 192 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 193 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 194 | `closure_scope` | 0.0% | 0/7 | 4 | 7 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 195 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 196 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 197 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 198 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 199 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 200 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 201 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 202 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 203 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 204 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 205 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 206 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 207 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 208 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 209 | `goto_execution_order2` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 211 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 212 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 214 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 215 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 216 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 218 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 219 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 220 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 221 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 222 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 223 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 224 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 225 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `native_objects_swf8` | 0.0% | 0/144 | 144 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 228 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 229 | `place_and_lookup` | 0.0% | 0/30 | 27 | 30 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 230 | `placeobject_occupied_depth` | 0.0% | 0/6 | 2 | 6 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 231 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 232 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 233 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 234 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 236 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 237 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 238 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 239 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 240 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 241 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 242 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 243 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 244 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 245 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 246 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 247 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 248 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 249 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 250 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 251 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 253 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 254 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/incomplete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) | 4 | 1 | 3 |
| 3 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 4 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 1 | 4 |
| 5 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 6 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) | 14 | 10 | 4 |
| 7 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 8 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 7 | 24 |
| 9 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 0 | 17 |
| 10 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 11 | [issue_768.md](ruffle-tests/_investigation/incomplete/issue_768.md) | 1 | 1 | 0 |
| 12 | [MATH_PLAN.md](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) | 5 | 1 | 4 |
| 13 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 5 | 53 |
| 14 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 15 | [object_string_coerce.md](ruffle-tests/_investigation/incomplete/object_string_coerce.md) | 2 | 1 | 1 |
| 16 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 0 | 4 |
| 17 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 18 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 1 | 2 |
| 19 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 5 | 7 |
| 20 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 21 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 22 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 2 | 7 |
| 23 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 2 | 5 |
| 24 | [string_coercion.md](ruffle-tests/_investigation/incomplete/string_coercion.md) | 1 | 1 | 0 |
| 25 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 4 | 9 |
| 26 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 27 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 19 | 51 |
| 28 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 29 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 30 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 31 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 32 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 33 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 205 | 135 | 70 |
