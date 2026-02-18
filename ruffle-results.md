# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-18 16:07 UTC

**Git SHA**: `45a5281eef`

**Run Duration**: 61m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **226** (36.5%) |
| Failing | 393 |
| Total expected lines | 91478 |
| Matching lines | 48826 (53.4%) |
| Mismatched lines | 42652 |

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
| 3 | `add` | 28 | 5.7s |  |
| 4 | `add2` | 354 | 6.0s | [1](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 5.7s |  |
| 6 | `add_swf5` | 28 | 5.8s |  |
| 7 | `array_call_method` | 9 | 5.7s | [2](ruffle-tests/_investigation/ARRAY_METHODS_PLAN.md) |
| 8 | `array_concat` | 98 | 5.8s |  |
| 9 | `array_constructor` | 30 | 5.8s |  |
| 10 | `array_enumerate` | 4 | 5.7s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 11 | `array_length` | 42 | 5.8s |  |
| 12 | `array_properties` | 36 | 5.7s |  |
| 13 | `array_slice` | 34 | 5.7s |  |
| 14 | `array_splice` | 207 | 5.9s |  |
| 15 | `array_trivial` | 209 | 5.8s |  |
| 16 | `as1_constructor_v6` | 35 | 5.7s |  |
| 17 | `as1_constructor_v7` | 35 | 5.8s |  |
| 18 | `as2_oop` | 13 | 5.9s | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 19 | `as_broadcaster_initialize` | 10 | 5.7s |  |
| 20 | `as_set_prop_flags_version` | 31 | 5.8s | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `as_set_prop_flags_version_swf5` | 1 | 5.7s |  |
| 22 | `as_set_prop_flags_version_swf6` | 1 | 5.7s |  |
| 23 | `as_set_prop_flags_version_swf7` | 1 | 5.8s |  |
| 24 | `as_set_prop_flags_version_swf8` | 1 | 5.8s |  |
| 25 | `as_set_prop_flags_version_swf9` | 1 | 5.8s |  |
| 26 | `as_transformed_flag` | 20 | 5.8s |  |
| 27 | `bad_swf_tag_past_eof` | 0 | 5.6s |  |
| 28 | `bitand` | 1058 | 8.4s |  |
| 29 | `bitmap_data_colortransform` | 0 | 5.9s |  |
| 30 | `bitmap_data_fillrect` | 0 | 5.8s |  |
| 31 | `bitmap_data_max_size_swf10` | 12 | 5.7s |  |
| 32 | `bitmap_data_max_size_swf9` | 10 | 5.7s |  |
| 33 | `bitmap_data_perlinnoise` | 0 | 6.3s |  |
| 34 | `bitmap_data_pixeldissolve_image` | 0 | 6.1s |  |
| 35 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.7s |  |
| 36 | `bitor` | 1058 | 8.3s |  |
| 37 | `biturshift` | 14 | 5.9s |  |
| 38 | `biturshift_swf8` | 14 | 5.7s |  |
| 39 | `bitxor` | 1058 | 8.3s |  |
| 40 | `call_method_empty_name` | 1 | 5.6s |  |
| 41 | `capabilities_resolution` | 8 | 5.7s |  |
| 42 | `catch_references_registers` | 2 | 5.7s | [28](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 43 | `conflicting_instance_names` | 23 | 5.8s |  |
| 44 | `define_function2` | 8 | 5.9s |  |
| 45 | `define_function2_preload` | 13 | 5.9s |  |
| 46 | `define_function2_preload_order` | 4 | 5.9s |  |
| 47 | `define_function_case_sensitive` | 2 | 5.8s |  |
| 48 | `delete` | 3 | 5.8s |  |
| 49 | `display_object_properties` | 2 | 5.7s |  |
| 50 | `divide_swf4` | 107 | 5.8s |  |
| 51 | `do_init_action` | 3 | 5.8s |  |
| 52 | `edittext_antialiastype` | 296 | 6.4s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_autosize_setter` | 20 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `edittext_default_format` | 221 | 6.0s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `edittext_default_format_empty` | 95 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 56 | `edittext_default_format_font_style` | 335 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `edittext_password` | 5 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `equals` | 32 | 5.8s |  |
| 59 | `equals2_swf5` | 926 | 7.6s |  |
| 60 | `equals2_swf6` | 926 | 7.6s |  |
| 61 | `equals2_swf7` | 926 | 7.6s |  |
| 62 | `equals_swf4` | 665 | 6.3s |  |
| 63 | `equals_swf4_alt` | 32 | 5.8s |  |
| 64 | `equals_swf5` | 32 | 5.8s |  |
| 65 | `error` | 58 | 5.8s |  |
| 66 | `escape` | 14 | 5.7s |  |
| 67 | `execution_order1` | 5 | 5.8s |  |
| 68 | `execution_order2` | 7 | 5.8s |  |
| 69 | `execution_order3` | 4 | 5.8s |  |
| 70 | `focusrect_mouse_swf8` | 0 | 5.6s |  |
| 71 | `focusrect_mouse_swf9` | 0 | 5.6s |  |
| 72 | `focusrect_swf5` | 6 | 5.8s |  |
| 73 | `get_variable_in_scope` | 29 | 5.7s |  |
| 74 | `getproperty` | 28 | 5.7s |  |
| 75 | `getproperty_swf4` | 28 | 5.7s |  |
| 76 | `getproperty_swf5` | 28 | 5.8s |  |
| 77 | `global_array` | 3 | 5.7s |  |
| 78 | `global_is_bare` | 7 | 5.6s |  |
| 79 | `globals_swf5` | 304 | 5.9s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 80 | `globals_swf6` | 304 | 5.8s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 81 | `globals_swf7` | 304 | 5.8s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 82 | `globals_swf8` | 304 | 5.9s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `goto_advance1` | 6 | 5.6s |  |
| 84 | `goto_advance2` | 2 | 5.7s |  |
| 85 | `goto_both_ways1` | 3 | 5.9s |  |
| 86 | `goto_both_ways2` | 3 | 5.8s |  |
| 87 | `goto_execution_order` | 2 | 5.8s |  |
| 88 | `goto_execution_order2` | 2 | 5.8s |  |
| 89 | `goto_frame_number` | 3 | 5.8s |  |
| 90 | `goto_rewind1` | 1 | 6.0s |  |
| 91 | `goto_rewind2` | 3 | 5.8s |  |
| 92 | `goto_rewind3` | 2 | 5.8s |  |
| 93 | `greater_swf6` | 1175 | 7.9s |  |
| 94 | `greater_swf7` | 1175 | 7.9s |  |
| 95 | `greaterthan_swf5` | 1 | 5.8s |  |
| 96 | `greaterthan_swf8` | 1 | 5.8s |  |
| 97 | `has_own_property` | 32 | 5.9s |  |
| 98 | `infinite_recursion_function` | 4 | 5.7s | [9](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 99 | `infinite_recursion_function_in_setter` | 131 | 5.7s | [9](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 100 | `infinite_recursion_virtual_property` | 67 | 5.7s | [9](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 101 | `init_array_invalid` | 4 | 5.7s |  |
| 102 | `init_object_invalid` | 4 | 5.7s |  |
| 103 | `is_finite` | 49 | 5.8s | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 104 | `is_finite_swf6` | 49 | 5.8s | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 105 | `is_prototype_of` | 89 | 5.9s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 106 | `issue_1086` | 1 | 5.8s |  |
| 107 | `issue_1671` | 0 | 5.9s |  |
| 108 | `issue_2166` | 9 | 5.8s |  |
| 109 | `issue_3446` | 1 | 5.7s |  |
| 110 | `issue_4377` | 2 | 5.7s |  |
| 111 | `issue_710` | 4 | 5.9s |  |
| 112 | `issue_768` | 3 | 5.9s | [10](ruffle-tests/_investigation/issue_768.md) |
| 113 | `lessthan` | 41 | 5.9s |  |
| 114 | `lessthan2_swf5` | 1226 | 8.2s |  |
| 115 | `lessthan2_swf6` | 1226 | 8.0s |  |
| 116 | `lessthan2_swf7` | 1226 | 8.1s |  |
| 117 | `lessthan_swf4` | 902 | 6.3s |  |
| 118 | `lessthan_swf4_alt` | 41 | 5.7s |  |
| 119 | `lessthan_swf5` | 41 | 5.8s |  |
| 120 | `logical_ops_swf4` | 90 | 5.7s |  |
| 121 | `logical_ops_swf8` | 108 | 5.8s |  |
| 122 | `looping` | 6 | 5.8s |  |
| 123 | `mask_reapply` | 0 | 5.7s |  |
| 124 | `mask_with_drawing` | 0 | 5.7s |  |
| 125 | `math_min_max` | 101 | 5.9s | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 126 | `matrix` | 171 | 6.1s | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 127 | `mouse_wheel_enabled` | 2 | 5.8s |  |
| 128 | `movieclip_begin_gradient_fill` | 0 | 6.2s |  |
| 129 | `movieclip_blend_mode_property` | 35 | 5.9s | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 130 | `movieclip_default_state` | 69 | 6.0s | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 131 | `movieclip_get_instance_at_depth` | 28 | 5.8s | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 132 | `movieclip_line_gradient_style` | 0 | 6.2s |  |
| 133 | `movieclip_name_from_timeline` | 13 | 5.8s | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 134 | `movieclip_prototype_extension` | 5 | 5.8s |  |
| 135 | `nested_textfields_in_buttons` | 0 | 5.8s |  |
| 136 | `netstream_play_flv_screen` | 0 | 19.1s |  |
| 137 | `new_method_wrap` | 4 | 5.8s |  |
| 138 | `new_object_enumerate` | 7 | 5.8s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 139 | `new_object_wrap` | 4 | 5.8s |  |
| 140 | `o` | 3 | 5.8s |  |
| 141 | `object_constructor` | 33 | 5.8s |  |
| 142 | `object_function` | 32 | 5.8s |  |
| 143 | `object_properties` | 31 | 5.9s | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 144 | `object_string_coerce_swf5` | 62 | 5.8s | [14](ruffle-tests/_investigation/object_string_coerce.md) |
| 145 | `point` | 175 | 6.2s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 146 | `primitive_instanceof` | 37 | 5.9s |  |
| 147 | `prototype_delete` | 12 | 5.8s |  |
| 148 | `prototype_enumerate` | 5 | 5.8s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 149 | `prototype_properties` | 17 | 5.8s | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 150 | `rectangle` | 745 | 6.7s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 151 | `recursive_prototypes` | 0 | 5.8s |  |
| 152 | `sandbox_type_local_file` | 1 | 5.6s |  |
| 153 | `set_variable_scope` | 58 | 5.7s |  |
| 154 | `single_frame` | 1 | 5.6s |  |
| 155 | `sound_start_load` | 0 | 5.6s |  |
| 156 | `stage_object_properties_get_var` | 5 | 5.5s |  |
| 157 | `strictequals_swf6` | 902 | 7.0s |  |
| 158 | `strictly_equals` | 7 | 5.6s |  |
| 159 | `string_coercion` | 117 | 5.8s | [22](ruffle-tests/_investigation/string_coercion.md) |
| 160 | `string_methods` | 285 | 6.1s | [23](ruffle-tests/_investigation/STRING_PLAN.md) |
| 161 | `string_methods_negative_args` | 240 | 5.7s | [23](ruffle-tests/_investigation/STRING_PLAN.md) |
| 162 | `string_methods_swfv5` | 275 | 6.1s | [23](ruffle-tests/_investigation/STRING_PLAN.md) |
| 163 | `string_ops_swf6` | 95 | 5.7s | [23](ruffle-tests/_investigation/STRING_PLAN.md) |
| 164 | `string_paths_keyevents` | 0 | 5.7s |  |
| 165 | `string_paths_timer` | 0 | 5.7s |  |
| 166 | `swf4_actions_bool` | 96 | 5.8s |  |
| 167 | `swf4_bool` | 4 | 5.7s |  |
| 168 | `swf4_function_calls` | 7 | 5.8s |  |
| 169 | `swf5_encoding` | 3 | 5.6s |  |
| 170 | `swf7_case_sensitive` | 44 | 5.7s | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 171 | `tab_ordering_properties_tab_index_edge_case` | 4 | 5.8s |  |
| 172 | `text_format` | 1146 | 5.9s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 173 | `text_format_display` | 21 | 5.6s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 174 | `text_format_font_max_length` | 2 | 5.6s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 175 | `text_format_rounding_swf7` | 840 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 176 | `text_format_rounding_swf8` | 840 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 177 | `textfield_background_color` | 11 | 5.6s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 178 | `textfield_border_color` | 11 | 5.7s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 179 | `textfield_maxchars` | 3 | 5.7s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 180 | `textfield_properties` | 44 | 5.7s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 181 | `textfield_props_swf6` | 210 | 5.9s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 182 | `textfield_props_swf7` | 210 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 183 | `textfield_props_swf8` | 210 | 5.8s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 184 | `textfield_text` | 7 | 5.7s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 185 | `textfield_variable` | 81 | 5.9s | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 186 | `this_swf7` | 41 | 5.7s | [26](ruffle-tests/_investigation/this_swf7.md) |
| 187 | `timeline_function_def` | 7 | 5.8s |  |
| 188 | `try_catch_finally` | 118 | 5.7s | [28](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 189 | `try_finally_simple` | 16 | 5.6s | [28](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 190 | `typeof` | 22 | 5.8s |  |
| 191 | `typeof_globals` | 7 | 5.8s |  |
| 192 | `uncaught_exception` | 1 | 5.7s | [28](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 193 | `uncaught_exception_bubbled` | 1 | 5.8s | [28](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 194 | `undefined_to_string_swf6` | 4 | 5.6s |  |
| 195 | `unescape` | 43 | 5.6s |  |
| 196 | `use_hand_cursor` | 8 | 5.7s |  |
| 197 | `variable_args` | 5 | 5.9s |  |
| 198 | `waitforframe` | 7 | 5.6s |  |
| 199 | `waitforframe2` | 16 | 5.6s |  |
| 200 | `with_return` | 2 | 5.7s |  |
| 201 | `with_variable_scopes` | 43 | 5.8s | [30](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 202 | `xml` | 15 | 5.7s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 203 | `xml_append_child` | 28 | 5.7s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 204 | `xml_append_child_with_parent` | 20 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 205 | `xml_cdata` | 11 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 206 | `xml_child_nodes_edge_cases` | 4 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 207 | `xml_clone_expandos` | 19 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 208 | `xml_first_last_child` | 8 | 5.5s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 209 | `xml_has_child_nodes` | 3 | 5.7s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 210 | `xml_idmap` | 21 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 211 | `xml_ignore_comments` | 21 | 5.7s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 212 | `xml_ignore_white` | 34 | 5.7s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 213 | `xml_insert_before` | 20 | 5.7s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 214 | `xml_inspect_createmethods` | 15 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 215 | `xml_inspect_doctype` | 7 | 5.5s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 216 | `xml_inspect_parsexml` | 62 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 217 | `xml_inspect_xmldecl` | 7 | 5.5s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 218 | `xml_namespaces` | 203 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 219 | `xml_parent_and_child` | 5 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 220 | `xml_remove_node` | 22 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 221 | `xml_reparenting` | 14 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 222 | `xml_siblings` | 10 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 223 | `xml_to_string` | 13 | 5.6s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 224 | `xml_to_string_comment` | 1 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 225 | `xml_unescaping` | 23 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 226 | `xmlnode_proto` | 1 | 5.8s | [31](ruffle-tests/_investigation/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**94 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `math_swf6` | 98.5% | 522 | 530 | 8 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522 | 530 | 8 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522 | 530 | 8 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/ARRAY_METHODS_PLAN.md) |
| 5 | `movieclip_depth_methods` | 98.0% | 96 | 98 | 2 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `edittext_width_height` | 94.2% | 97 | 103 | 6 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 8 | `with` | 93.9% | 46 | 49 | 3 | [30](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 9 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 10 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 11 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 12 | `object_prototypes` | 85.1% | 63 | 74 | 11 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 13 | `local_to_global` | 83.7% | 41 | 49 | 8 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 14 | `arguments` | 83.5% | 106 | 127 | 21 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [17](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 15 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 16 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 17 | `this_scoping` | 80.8% | 42 | 52 | 10 | [30](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 18 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 19 | `date` | 79.7% | 5049 | 6335 | 1286 | [5](ruffle-tests/_investigation/DATE_PLAN.md) |
| 20 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 23 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 24 | `add_property` | 73.3% | 11 | 15 | 4 | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `attach_movie` | 72.9% | 43 | 59 | 16 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 26 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 27 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 28 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 29 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 | [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 30 | `stage_object_properties` | 71.8% | 173 | 241 | 68 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 31 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 32 | `transform` | 71.4% | 50 | 70 | 20 | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 33 | `register_underflow` | 69.2% | 18 | 26 | 8 | [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 34 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [14](ruffle-tests/_investigation/object_string_coerce.md) |
| 35 | `array_prototyping` | 66.7% | 8 | 12 | 4 | [2](ruffle-tests/_investigation/ARRAY_METHODS_PLAN.md) |
| 36 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 37 | `export_assets` | 66.7% | 2 | 3 | 1 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 38 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 39 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 40 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 41 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 42 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 43 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 44 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 45 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 46 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 47 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 48 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 49 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 50 | `color` | 61.4% | 35 | 57 | 22 | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 51 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 52 | `edittext_align` | 60.0% | 36 | 60 | 24 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 56 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 59 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 60 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 61 | `parse_float` | 58.1% | 43 | 74 | 31 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 62 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 63 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 64 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 65 | `primitive_type_globals` | 57.6% | 321 | 557 | 236 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 66 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 67 | `asnative` | 55.9% | 19 | 34 | 15 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 68 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 69 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 70 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 71 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 72 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 73 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 74 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 75 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 76 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 77 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 78 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 79 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 80 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 81 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 82 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 83 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 84 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 85 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 86 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 87 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 88 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 89 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 90 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 91 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 92 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 93 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 94 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [31](ruffle-tests/_investigation/XML_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 8.1s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.1s | [27](ruffle-tests/_investigation/TIMER_PLAN.md) |

## All Output Mismatches

**391 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/ARRAY_METHODS_PLAN.md) |
| 5 | `movieclip_depth_methods` | 98.0% | 96/98 | 98 | 98 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 8 | `with` | 93.9% | 46/49 | 49 | 49 | [30](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 9 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 10 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 11 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 12 | `object_prototypes` | 85.1% | 63/74 | 73 | 74 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 13 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 14 | `arguments` | 83.5% | 106/127 | 127 | 127 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [17](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 15 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 16 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 17 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [30](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 18 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 19 | `date` | 79.7% | 5049/6335 | 6335 | 6335 | [5](ruffle-tests/_investigation/DATE_PLAN.md) |
| 20 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 23 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 24 | `add_property` | 73.3% | 11/15 | 15 | 15 | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 26 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 27 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 28 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 29 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 | [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 30 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 31 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 32 | `transform` | 71.4% | 50/70 | 70 | 70 | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 33 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 34 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [14](ruffle-tests/_investigation/object_string_coerce.md) |
| 35 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 | [2](ruffle-tests/_investigation/ARRAY_METHODS_PLAN.md) |
| 36 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 37 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 38 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 39 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 40 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 41 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 42 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 43 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 44 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 45 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 46 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 47 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 48 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 49 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 50 | `color` | 61.4% | 35/57 | 57 | 57 | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 51 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 52 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 56 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 59 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 60 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 61 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 62 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 63 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 64 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 65 | `primitive_type_globals` | 57.6% | 321/557 | 555 | 557 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 66 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 67 | `asnative` | 55.9% | 19/34 | 31 | 34 | [11](ruffle-tests/_investigation/MATH_PLAN.md) |
| 68 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 69 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 70 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 71 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 72 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 73 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 74 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 75 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 76 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 77 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 78 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 79 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 80 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 81 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 82 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 84 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 85 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 86 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 87 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 88 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 89 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 90 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 91 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 92 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 93 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 94 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 95 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 96 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 97 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 98 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 99 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 100 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 101 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 102 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 103 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 104 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 105 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 106 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 107 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 108 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 109 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 110 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 111 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 112 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 113 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 114 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 116 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 117 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 118 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 119 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 120 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 121 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 122 | `enumerate` | 29.7% | 19/64 | 60 | 64 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 123 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 124 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 125 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 126 | `default_names` | 25.0% | 13/52 | 40 | 52 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 127 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 128 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 129 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 130 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 131 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [6](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 132 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 133 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 134 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 135 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 136 | `unload` | 21.2% | 11/52 | 48 | 52 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 137 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 138 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 139 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 140 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 141 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 142 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 143 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 144 | `focusrect_property_swf5` | 19.3% | 239/1237 | 1236 | 1237 |  |
| 145 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [27](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 146 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 147 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 148 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 149 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 150 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 151 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 152 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [15](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 153 | `watch` | 15.4% | 18/117 | 101 | 117 | [15](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 154 | `path_string` | 14.9% | 48/322 | 300 | 322 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 155 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 156 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [4](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 157 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 158 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 159 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 160 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 161 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 162 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 163 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 164 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [15](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 165 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 166 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 167 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 168 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 169 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 170 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 171 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 172 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 173 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 174 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 175 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 176 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 177 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 178 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 179 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 180 | `selection` | 9.3% | 42/454 | 244 | 454 | [20](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 181 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 182 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 183 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 184 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 185 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 186 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 187 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 188 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 189 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 190 | `define_local` | 7.4% | 2/27 | 23 | 27 | [30](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 191 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 192 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 193 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 194 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 195 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 196 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 197 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 198 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 199 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 200 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 201 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [27](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 202 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 203 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 204 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 205 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 206 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 207 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 208 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 209 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 210 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 211 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 212 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 213 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [20](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 214 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 215 | `register_class` | 3.0% | 2/66 | 27 | 66 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 216 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 217 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 218 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 219 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 220 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 221 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 222 | `parse_int` | 1.6% | 1/64 | 64 | 64 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 223 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 224 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 225 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 226 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 227 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 228 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 229 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 230 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 | [21](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 231 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 232 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 233 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 234 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 235 | `array_sort_random` | 0.2% | 1/443 | 80 | 443 | [2](ruffle-tests/_investigation/ARRAY_METHODS_PLAN.md) |
| 236 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 237 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 238 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 239 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 240 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 241 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 242 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 243 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 244 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 245 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 246 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 247 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 248 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 249 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 250 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 251 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 252 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 253 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 254 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 255 | `closure_scope` | 0.0% | 0/7 | 4 | 7 | [30](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 256 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 257 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 258 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 259 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 260 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 261 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 263 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 264 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 265 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [20](ruffle-tests/_investigation/SELECTION_PLAN.md) [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 266 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 267 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 268 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 269 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 270 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 271 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 272 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [20](ruffle-tests/_investigation/SELECTION_PLAN.md) [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 273 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 274 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 275 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 276 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 277 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 278 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 279 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 280 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 281 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 282 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 283 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 284 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 285 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 286 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 287 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 288 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 289 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 290 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 291 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 292 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 293 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 294 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 295 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 296 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 297 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 298 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 299 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 300 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [16](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
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
| 331 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 332 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 333 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 334 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 336 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 337 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 338 | `native_objects_swf8` | 0.0% | 0/144 | 144 | 84 | [8](ruffle-tests/_investigation/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 339 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 340 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 341 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 342 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [18](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 343 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 344 | `place_and_lookup` | 0.0% | 0/30 | 27 | 30 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 345 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 346 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [19](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 347 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 348 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 349 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 350 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 351 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 352 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 353 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 354 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 355 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 356 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 357 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 358 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 359 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 360 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/STRING_PLAN.md) [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 361 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 362 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
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
| 377 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 378 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 379 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 380 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 381 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [24](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 382 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 383 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 384 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [25](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 385 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 386 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [12](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [29](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 387 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [15](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 388 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 389 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 390 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [31](ruffle-tests/_investigation/XML_PLAN.md) |
| 391 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [31](ruffle-tests/_investigation/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/ARRAY_METHODS_PLAN.md) | 4 | 1 | 3 |
| 3 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 4 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) | 5 | 1 | 4 |
| 5 | [DATE_PLAN.md](ruffle-tests/_investigation/DATE_PLAN.md) | 1 | 0 | 1 |
| 6 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/ENUMERATION_PLAN.md) | 14 | 9 | 5 |
| 7 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 3 | 4 |
| 8 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/GLOBALS_PLAN.md) | 31 | 7 | 24 |
| 9 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 10 | [issue_768.md](ruffle-tests/_investigation/issue_768.md) | 1 | 1 | 0 |
| 11 | [MATH_PLAN.md](ruffle-tests/_investigation/MATH_PLAN.md) | 5 | 1 | 4 |
| 12 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) | 58 | 5 | 53 |
| 13 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 14 | [object_string_coerce.md](ruffle-tests/_investigation/object_string_coerce.md) | 2 | 1 | 1 |
| 15 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) | 4 | 0 | 4 |
| 16 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 17 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) | 3 | 0 | 3 |
| 18 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) | 12 | 5 | 7 |
| 19 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 20 | [SELECTION_PLAN.md](ruffle-tests/_investigation/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 21 | [STAGE_PLAN.md](ruffle-tests/_investigation/STAGE_PLAN.md) | 7 | 0 | 7 |
| 22 | [string_coercion.md](ruffle-tests/_investigation/string_coercion.md) | 1 | 1 | 0 |
| 23 | [STRING_PLAN.md](ruffle-tests/_investigation/STRING_PLAN.md) | 13 | 4 | 9 |
| 24 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 25 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) | 70 | 20 | 50 |
| 26 | [this_swf7.md](ruffle-tests/_investigation/this_swf7.md) | 1 | 1 | 0 |
| 27 | [TIMER_PLAN.md](ruffle-tests/_investigation/TIMER_PLAN.md) | 3 | 0 | 3 |
| 28 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 29 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 30 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 31 | [XML_PLAN.md](ruffle-tests/_investigation/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 322 | 139 | 183 |
