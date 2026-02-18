# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-18 19:49 UTC

**Git SHA**: `c3381e0ef8`

**Run Duration**: 63m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **226** (36.5%) |
| Failing | 393 |
| Total expected lines | 91478 |
| Matching lines | 50792 (55.5%) |
| Mismatched lines | 40686 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 391 | 99.5% |
| Timeout | 1 | 0.3% |
| Runtime Segfault | 1 | 0.3% |

## Passing Tests

**226 tests passing**

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
| 58 | `edittext_password` | 5 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `equals` | 32 | 6.0s |  |
| 60 | `equals2_swf5` | 926 | 7.8s |  |
| 61 | `equals2_swf6` | 926 | 7.7s |  |
| 62 | `equals2_swf7` | 926 | 7.7s |  |
| 63 | `equals_swf4` | 665 | 6.4s |  |
| 64 | `equals_swf4_alt` | 32 | 5.9s |  |
| 65 | `equals_swf5` | 32 | 5.9s |  |
| 66 | `error` | 58 | 6.0s |  |
| 67 | `escape` | 14 | 5.9s |  |
| 68 | `execution_order1` | 5 | 6.0s |  |
| 69 | `execution_order2` | 7 | 6.1s |  |
| 70 | `focusrect_mouse_swf8` | 0 | 5.8s |  |
| 71 | `focusrect_mouse_swf9` | 0 | 5.8s |  |
| 72 | `focusrect_swf5` | 6 | 5.9s |  |
| 73 | `function_suppress_and_preload` | 28 | 5.9s |  |
| 74 | `get_variable_in_scope` | 29 | 5.9s |  |
| 75 | `getproperty` | 28 | 5.9s |  |
| 76 | `getproperty_swf4` | 28 | 5.8s |  |
| 77 | `getproperty_swf5` | 28 | 5.8s |  |
| 78 | `global_array` | 3 | 5.8s |  |
| 79 | `global_is_bare` | 7 | 5.8s |  |
| 80 | `globals_swf5` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 81 | `globals_swf6` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 82 | `globals_swf7` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `globals_swf8` | 304 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 84 | `goto_advance1` | 6 | 5.8s |  |
| 85 | `goto_advance2` | 2 | 5.8s |  |
| 86 | `goto_both_ways2` | 3 | 6.0s |  |
| 87 | `goto_execution_order` | 2 | 5.9s |  |
| 88 | `goto_frame_number` | 3 | 6.0s |  |
| 89 | `goto_rewind1` | 1 | 6.2s |  |
| 90 | `goto_rewind2` | 3 | 5.9s |  |
| 91 | `greater_swf6` | 1175 | 8.0s |  |
| 92 | `greater_swf7` | 1175 | 8.0s |  |
| 93 | `greaterthan_swf5` | 1 | 5.9s |  |
| 94 | `greaterthan_swf8` | 1 | 5.9s |  |
| 95 | `has_own_property` | 32 | 5.9s |  |
| 96 | `infinite_recursion_function` | 4 | 5.9s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 97 | `infinite_recursion_function_in_setter` | 131 | 6.0s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 98 | `infinite_recursion_virtual_property` | 67 | 6.0s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 99 | `init_array_invalid` | 4 | 5.9s |  |
| 100 | `init_object_invalid` | 4 | 5.9s |  |
| 101 | `is_finite` | 49 | 6.0s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 102 | `is_finite_swf6` | 49 | 6.0s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 103 | `is_prototype_of` | 89 | 6.0s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 104 | `issue_1086` | 1 | 6.0s |  |
| 105 | `issue_1671` | 0 | 5.9s |  |
| 106 | `issue_2166` | 9 | 5.9s |  |
| 107 | `issue_3446` | 1 | 5.9s |  |
| 108 | `issue_4377` | 2 | 5.9s |  |
| 109 | `issue_710` | 4 | 5.9s |  |
| 110 | `issue_768` | 3 | 5.9s | [11](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 111 | `lessthan` | 41 | 5.9s |  |
| 112 | `lessthan2_swf5` | 1226 | 8.2s |  |
| 113 | `lessthan2_swf6` | 1226 | 8.2s |  |
| 114 | `lessthan2_swf7` | 1226 | 8.2s |  |
| 115 | `lessthan_swf4` | 902 | 6.6s |  |
| 116 | `lessthan_swf4_alt` | 41 | 5.9s |  |
| 117 | `lessthan_swf5` | 41 | 6.0s |  |
| 118 | `logical_ops_swf4` | 90 | 5.5s |  |
| 119 | `logical_ops_swf8` | 108 | 5.6s |  |
| 120 | `looping` | 6 | 5.5s |  |
| 121 | `mask_reapply` | 0 | 5.5s |  |
| 122 | `mask_with_drawing` | 0 | 5.6s |  |
| 123 | `math_min_max` | 101 | 5.7s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 124 | `matrix` | 171 | 5.9s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 125 | `mouse_wheel_enabled` | 2 | 5.5s |  |
| 126 | `movieclip_begin_gradient_fill` | 0 | 6.2s |  |
| 127 | `movieclip_blend_mode_property` | 35 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `movieclip_default_state` | 69 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 129 | `movieclip_get_instance_at_depth` | 28 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 130 | `movieclip_line_gradient_style` | 0 | 6.6s |  |
| 131 | `movieclip_name_from_timeline` | 13 | 6.2s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 132 | `movieclip_prototype_extension` | 5 | 6.2s |  |
| 133 | `nested_textfields_in_buttons` | 0 | 6.2s |  |
| 134 | `netstream_play_flv_screen` | 0 | 20.2s |  |
| 135 | `new_method_wrap` | 4 | 6.2s |  |
| 136 | `new_object_enumerate` | 7 | 6.2s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 137 | `new_object_wrap` | 4 | 6.2s |  |
| 138 | `o` | 3 | 6.2s |  |
| 139 | `object_constructor` | 33 | 6.2s |  |
| 140 | `object_function` | 32 | 6.3s |  |
| 141 | `object_properties` | 31 | 6.5s | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 142 | `object_string_coerce_swf5` | 62 | 6.3s | [15](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 143 | `point` | 175 | 6.6s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 144 | `primitive_instanceof` | 37 | 6.1s |  |
| 145 | `prototype_delete` | 12 | 6.2s |  |
| 146 | `prototype_enumerate` | 5 | 6.2s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 147 | `prototype_properties` | 17 | 6.4s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 148 | `rectangle` | 745 | 7.2s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 149 | `recursive_prototypes` | 0 | 6.2s |  |
| 150 | `sandbox_type_local_file` | 1 | 5.8s |  |
| 151 | `set_variable_scope` | 58 | 5.8s |  |
| 152 | `single_frame` | 1 | 5.8s |  |
| 153 | `sound_start_load` | 0 | 5.9s |  |
| 154 | `stage_object_enumerate` | 4 | 5.8s | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 155 | `stage_object_properties_get_var` | 5 | 5.8s |  |
| 156 | `stage_property_representation` | 586 | 5.9s | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 157 | `strictequals_swf6` | 902 | 7.5s |  |
| 158 | `strictly_equals` | 7 | 5.9s |  |
| 159 | `string_coercion` | 117 | 6.2s | [24](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 160 | `string_methods` | 285 | 6.5s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 161 | `string_methods_negative_args` | 240 | 6.1s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 162 | `string_methods_swfv5` | 275 | 6.6s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 163 | `string_ops_swf6` | 95 | 6.1s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 164 | `string_paths_keyevents` | 0 | 6.1s |  |
| 165 | `string_paths_timer` | 0 | 6.0s |  |
| 166 | `swf4_actions_bool` | 96 | 6.0s |  |
| 167 | `swf4_bool` | 4 | 5.9s |  |
| 168 | `swf4_function_calls` | 7 | 5.8s |  |
| 169 | `swf5_encoding` | 3 | 5.6s |  |
| 170 | `swf7_case_sensitive` | 44 | 5.7s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `tab_ordering_properties_tab_index_edge_case` | 4 | 5.7s |  |
| 172 | `text_format` | 1146 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `text_format_display` | 21 | 5.7s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 174 | `text_format_font_max_length` | 2 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `text_format_rounding_swf7` | 840 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `text_format_rounding_swf8` | 840 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `textfield_background_color` | 11 | 5.7s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `textfield_border_color` | 11 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `textfield_maxchars` | 3 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `textfield_properties` | 44 | 5.7s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `textfield_props_swf6` | 210 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `textfield_props_swf7` | 210 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 183 | `textfield_props_swf8` | 210 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 184 | `textfield_text` | 7 | 5.6s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 185 | `textfield_variable` | 81 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 186 | `this_swf7` | 41 | 5.7s | [28](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 187 | `timeline_function_def` | 7 | 5.7s |  |
| 188 | `try_catch_finally` | 118 | 6.0s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 189 | `try_finally_simple` | 16 | 5.8s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 190 | `typeof` | 22 | 5.8s |  |
| 191 | `typeof_globals` | 7 | 5.8s |  |
| 192 | `uncaught_exception` | 1 | 5.8s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 193 | `uncaught_exception_bubbled` | 1 | 5.8s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 194 | `undefined_to_string_swf6` | 4 | 5.8s |  |
| 195 | `unescape` | 43 | 5.9s |  |
| 196 | `use_hand_cursor` | 8 | 5.8s |  |
| 197 | `variable_args` | 5 | 6.0s |  |
| 198 | `waitforframe` | 7 | 5.8s |  |
| 199 | `waitforframe2` | 16 | 5.9s |  |
| 200 | `with_return` | 2 | 5.8s |  |
| 201 | `with_variable_scopes` | 43 | 6.0s | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 202 | `xml` | 15 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 203 | `xml_append_child` | 28 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 204 | `xml_append_child_with_parent` | 20 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 205 | `xml_cdata` | 11 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 206 | `xml_child_nodes_edge_cases` | 4 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 207 | `xml_clone_expandos` | 19 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 208 | `xml_first_last_child` | 8 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 209 | `xml_has_child_nodes` | 3 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 210 | `xml_idmap` | 21 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_ignore_comments` | 21 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_ignore_white` | 34 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_insert_before` | 20 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_inspect_createmethods` | 15 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_inspect_doctype` | 7 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_inspect_parsexml` | 62 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_inspect_xmldecl` | 7 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_namespaces` | 203 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_parent_and_child` | 5 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_remove_node` | 22 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_reparenting` | 14 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_siblings` | 10 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_to_string` | 13 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xml_to_string_comment` | 1 | 5.8s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 225 | `xml_unescaping` | 23 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 226 | `xmlnode_proto` | 1 | 5.9s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**94 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 6 | `movieclip_depth_methods` | 95.9% | 94 | 98 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 8 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `with` | 93.9% | 46 | 49 | 3 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 11 | `stage_object_properties` | 93.4% | 225 | 241 | 16 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `stage_object_properties_swf6` | 91.8% | 212 | 231 | 19 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `object_prototypes` | 85.1% | 63 | 74 | 11 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `local_to_global` | 83.7% | 41 | 49 | 8 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 18 | `edittext_width_height` | 81.6% | 84 | 103 | 19 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `this_scoping` | 80.8% | 42 | 52 | 10 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 21 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 22 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 23 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 25 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `add_property` | 73.3% | 11 | 15 | 4 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 27 | `attach_movie` | 72.9% | 43 | 59 | 16 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 30 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 31 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 32 | `transform` | 71.4% | 50 | 70 | 20 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 33 | `register_underflow` | 69.2% | 18 | 26 | 8 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 34 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [15](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 35 | `array_prototyping` | 66.7% | 8 | 12 | 4 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 36 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `export_assets` | 66.7% | 2 | 3 | 1 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 38 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 39 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 40 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 41 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 44 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 45 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 47 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `color` | 61.4% | 35 | 57 | 22 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 49 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 50 | `edittext_align` | 60.0% | 36 | 60 | 24 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 58 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 59 | `parse_float` | 58.1% | 43 | 74 | 31 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 60 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 61 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 62 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 63 | `primitive_type_globals` | 57.6% | 321 | 557 | 236 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 64 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `asnative` | 55.9% | 19 | 34 | 15 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 66 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 67 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 68 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 71 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 72 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 74 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 75 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 76 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 77 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 79 | `goto_rewind3` | 50.0% | 1 | 2 | 1 |  |
| 80 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 81 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 82 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 84 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 85 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 86 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 87 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 88 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 89 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 90 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 91 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 92 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 94 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

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

**391 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 6 | `movieclip_depth_methods` | 95.9% | 94/98 | 98 | 98 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 8 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `with` | 93.9% | 46/49 | 49 | 49 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 11 | `stage_object_properties` | 93.4% | 225/241 | 241 | 241 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `stage_object_properties_swf6` | 91.8% | 212/231 | 231 | 231 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `object_prototypes` | 85.1% | 63/74 | 73 | 74 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 18 | `edittext_width_height` | 81.6% | 84/103 | 103 | 103 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 21 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 22 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 23 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 25 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `add_property` | 73.3% | 11/15 | 15 | 15 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 27 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 30 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 31 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 32 | `transform` | 71.4% | 50/70 | 70 | 70 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 33 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 34 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [15](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 35 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 36 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 38 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 39 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 40 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 41 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 44 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 45 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 47 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `color` | 61.4% | 35/57 | 57 | 57 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 49 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 50 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 58 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 59 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 60 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 61 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 62 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 63 | `primitive_type_globals` | 57.6% | 321/557 | 555 | 557 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 64 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `asnative` | 55.9% | 19/34 | 31 | 34 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 66 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 67 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 68 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 71 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 72 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 74 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 75 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 76 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 77 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `execution_order3` | 50.0% | 2/4 | 3 | 4 |  |
| 79 | `goto_rewind3` | 50.0% | 1/2 | 1 | 2 |  |
| 80 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 81 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 82 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 84 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 85 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 86 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 87 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 88 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 89 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 90 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 91 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 92 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 94 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 95 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 96 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 97 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 100 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 101 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 102 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 104 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 105 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 106 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 107 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 108 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 109 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 110 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 111 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 113 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 114 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `goto_both_ways1` | 33.3% | 1/3 | 2 | 3 |  |
| 118 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 119 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 120 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 121 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 123 | `enumerate` | 29.7% | 19/64 | 60 | 64 | [6](ruffle-tests/_investigation/incomplete/ENUMERATION_PLAN.md) |
| 124 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 125 | `default_names` | 28.8% | 15/52 | 40 | 52 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 127 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 128 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 129 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 130 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 131 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 132 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 133 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 135 | `focusrect_property_swf5` | 21.7% | 269/1237 | 1236 | 1237 |  |
| 136 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 137 | `unload` | 21.2% | 11/52 | 48 | 52 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 138 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 139 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 140 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 141 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 142 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 143 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 144 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 145 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 146 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 147 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 148 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 149 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 150 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 151 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 152 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 153 | `watch` | 15.4% | 18/117 | 101 | 117 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 154 | `path_string` | 15.2% | 49/322 | 300 | 322 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 155 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 156 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 157 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 158 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 159 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 160 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 161 | `register_and_init_order` | 13.4% | 31/231 | 73 | 231 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 162 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 163 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 164 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 165 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 166 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 167 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 168 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 169 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 170 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 171 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 172 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 173 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 174 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 175 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 177 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 178 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 179 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 180 | `selection` | 9.3% | 42/454 | 244 | 454 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 181 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 182 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 184 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 185 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 186 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 187 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 188 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 189 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 190 | `define_local` | 7.4% | 2/27 | 23 | 27 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 191 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 192 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 193 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 194 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 195 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 196 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 197 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 198 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 199 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 200 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 201 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 202 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 203 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 204 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 205 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 206 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 207 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 208 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 209 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 210 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 211 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 212 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 213 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 214 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 215 | `register_class` | 3.0% | 2/66 | 27 | 66 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 216 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 217 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 218 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 219 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 220 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 221 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 222 | `parse_int` | 1.6% | 1/64 | 64 | 64 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 223 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 224 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 225 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 226 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 227 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 228 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 229 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 230 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 231 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 232 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 233 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 234 | `array_sort_random` | 0.2% | 1/443 | 80 | 443 | [2](ruffle-tests/_investigation/incomplete/ARRAY_METHODS_PLAN.md) |
| 235 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 236 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 237 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 238 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 240 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 242 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 243 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 244 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 245 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 246 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 249 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 250 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 251 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 252 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 253 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 254 | `closure_scope` | 0.0% | 0/7 | 4 | 7 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 255 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 256 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 257 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 258 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 259 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 260 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 263 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 264 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 265 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 266 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 267 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 268 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 269 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 270 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 271 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 272 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 273 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 274 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 275 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 276 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 277 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 278 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 279 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 280 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 281 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 282 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 283 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 284 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 285 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 286 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 287 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 288 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 289 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 290 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 291 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 292 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 293 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 294 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 295 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 296 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 297 | `goto_execution_order2` | 0.0% | 0/2 | 0 | 2 |  |
| 298 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 299 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 300 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 301 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 302 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 303 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 304 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 305 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 306 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 307 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 308 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 309 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 310 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 311 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 312 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 313 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 314 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 315 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 316 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 317 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 318 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 319 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 320 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 321 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 322 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 323 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 324 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 325 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 326 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 327 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 328 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 329 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 |  |
| 330 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 |  |
| 331 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 332 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 333 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 334 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 336 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 337 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 338 | `native_objects_swf8` | 0.0% | 0/144 | 144 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 339 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 340 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 341 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 342 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 343 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 344 | `place_and_lookup` | 0.0% | 0/30 | 27 | 30 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 345 | `placeobject_occupied_depth` | 0.0% | 0/6 | 2 | 6 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 346 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 347 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 348 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 349 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 350 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 351 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 352 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 353 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 354 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 355 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 356 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 357 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 358 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 359 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 360 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 361 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 362 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 363 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 364 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 365 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 366 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 367 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 368 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 369 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 370 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 371 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 372 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 373 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 374 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 375 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 376 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 377 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 378 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 379 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 380 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 381 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 382 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 383 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 384 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 385 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 386 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 387 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 388 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 389 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 390 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 391 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

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
| 27 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 20 | 50 |
| 28 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 29 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 30 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 31 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 32 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 33 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 315 | 136 | 179 |
