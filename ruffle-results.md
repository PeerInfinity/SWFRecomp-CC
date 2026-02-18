# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-18 23:28 UTC

**Git SHA**: `668f34f122`

**Run Duration**: 64m 15s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **234** (37.8%) |
| Failing | 385 |
| Total expected lines | 91478 |
| Matching lines | 51309 (56.1%) |
| Mismatched lines | 40169 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 383 | 99.5% |
| Timeout | 1 | 0.3% |
| Runtime Segfault | 1 | 0.3% |

## Passing Tests

**234 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 6.0s |  |
| 2 | `action_to_integer` | 28 | 5.9s |  |
| 3 | `add` | 28 | 6.0s |  |
| 4 | `add2` | 354 | 6.2s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 6.0s |  |
| 6 | `add_swf5` | 28 | 6.0s |  |
| 7 | `arguments` | 127 | 6.0s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 6.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 6.0s |  |
| 10 | `array_constructor` | 30 | 6.0s |  |
| 11 | `array_enumerate` | 4 | 5.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 6.0s |  |
| 13 | `array_properties` | 36 | 6.0s |  |
| 14 | `array_prototyping` | 12 | 6.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 6.1s |  |
| 16 | `array_sort_random` | 443 | 6.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 6.2s |  |
| 18 | `array_trivial` | 209 | 6.2s |  |
| 19 | `as1_constructor_v6` | 35 | 6.1s |  |
| 20 | `as1_constructor_v7` | 35 | 6.0s |  |
| 21 | `as2_oop` | 13 | 6.2s | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 6.0s |  |
| 23 | `as_set_prop_flags_version` | 31 | 6.0s | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 6.0s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 6.0s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 6.0s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 6.0s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 6.0s |  |
| 29 | `as_transformed_flag` | 20 | 6.0s |  |
| 30 | `bad_swf_tag_past_eof` | 0 | 6.0s |  |
| 31 | `bitand` | 1058 | 8.8s |  |
| 32 | `bitmap_data_colortransform` | 0 | 6.3s |  |
| 33 | `bitmap_data_fillrect` | 0 | 6.2s |  |
| 34 | `bitmap_data_max_size_swf10` | 12 | 6.0s |  |
| 35 | `bitmap_data_max_size_swf9` | 10 | 6.0s |  |
| 36 | `bitmap_data_perlinnoise` | 0 | 6.5s |  |
| 37 | `bitmap_data_pixeldissolve_image` | 0 | 6.6s |  |
| 38 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.0s |  |
| 39 | `bitor` | 1058 | 8.5s |  |
| 40 | `biturshift` | 14 | 7.8s |  |
| 41 | `biturshift_swf8` | 14 | 6.2s |  |
| 42 | `bitxor` | 1058 | 8.9s |  |
| 43 | `call_method_empty_name` | 1 | 6.2s |  |
| 44 | `capabilities_resolution` | 8 | 6.2s |  |
| 45 | `catch_references_registers` | 2 | 6.2s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 46 | `conflicting_instance_names` | 23 | 6.3s |  |
| 47 | `define_function2` | 8 | 6.2s |  |
| 48 | `define_function2_preload` | 13 | 6.2s |  |
| 49 | `define_function2_preload_order` | 4 | 6.2s |  |
| 50 | `define_function_case_sensitive` | 2 | 6.2s |  |
| 51 | `delete` | 3 | 6.3s |  |
| 52 | `display_object_properties` | 2 | 6.2s |  |
| 53 | `divide_swf4` | 107 | 6.2s |  |
| 54 | `do_init_action` | 3 | 6.2s |  |
| 55 | `edittext_antialiastype` | 296 | 6.2s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_autosize_setter` | 20 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_default_format` | 221 | 6.1s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_default_format_empty` | 95 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_default_format_font_style` | 335 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_password` | 5 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_width_height` | 103 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `enumerate` | 64 | 5.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 63 | `equals` | 32 | 5.8s |  |
| 64 | `equals2_swf5` | 926 | 7.5s |  |
| 65 | `equals2_swf6` | 926 | 7.6s |  |
| 66 | `equals2_swf7` | 926 | 7.5s |  |
| 67 | `equals_swf4` | 665 | 6.2s |  |
| 68 | `equals_swf4_alt` | 32 | 5.8s |  |
| 69 | `equals_swf5` | 32 | 5.8s |  |
| 70 | `error` | 58 | 5.9s |  |
| 71 | `escape` | 14 | 5.9s |  |
| 72 | `execution_order1` | 5 | 5.9s |  |
| 73 | `execution_order2` | 7 | 5.9s |  |
| 74 | `execution_order3` | 4 | 5.9s |  |
| 75 | `focusrect_mouse_swf8` | 0 | 6.0s |  |
| 76 | `focusrect_mouse_swf9` | 0 | 6.0s |  |
| 77 | `focusrect_swf5` | 6 | 6.1s |  |
| 78 | `function_suppress_and_preload` | 28 | 6.0s |  |
| 79 | `get_variable_in_scope` | 29 | 5.9s |  |
| 80 | `getproperty` | 28 | 5.9s |  |
| 81 | `getproperty_swf4` | 28 | 5.9s |  |
| 82 | `getproperty_swf5` | 28 | 5.9s |  |
| 83 | `global_array` | 3 | 5.9s |  |
| 84 | `global_is_bare` | 7 | 5.9s |  |
| 85 | `globals_swf5` | 304 | 6.2s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 86 | `globals_swf6` | 304 | 6.2s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 87 | `globals_swf7` | 304 | 6.2s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 88 | `globals_swf8` | 304 | 6.2s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 89 | `goto_advance1` | 6 | 6.0s |  |
| 90 | `goto_advance2` | 2 | 5.9s |  |
| 91 | `goto_both_ways1` | 3 | 6.1s |  |
| 92 | `goto_both_ways2` | 3 | 6.0s |  |
| 93 | `goto_execution_order` | 2 | 5.9s |  |
| 94 | `goto_execution_order2` | 2 | 6.0s |  |
| 95 | `goto_frame_number` | 3 | 6.0s |  |
| 96 | `goto_rewind1` | 1 | 6.0s |  |
| 97 | `goto_rewind2` | 3 | 6.0s |  |
| 98 | `goto_rewind3` | 2 | 5.9s |  |
| 99 | `greater_swf6` | 1175 | 7.9s |  |
| 100 | `greater_swf7` | 1175 | 7.9s |  |
| 101 | `greaterthan_swf5` | 1 | 5.9s |  |
| 102 | `greaterthan_swf8` | 1 | 5.9s |  |
| 103 | `has_own_property` | 32 | 6.0s |  |
| 104 | `infinite_recursion_function` | 4 | 5.9s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 105 | `infinite_recursion_function_in_setter` | 131 | 6.0s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 106 | `infinite_recursion_virtual_property` | 67 | 5.9s | [10](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 107 | `init_array_invalid` | 4 | 5.9s |  |
| 108 | `init_object_invalid` | 4 | 5.9s |  |
| 109 | `is_finite` | 49 | 5.9s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 110 | `is_finite_swf6` | 49 | 6.0s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 111 | `is_prototype_of` | 89 | 6.0s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 112 | `issue_1086` | 1 | 5.9s |  |
| 113 | `issue_1671` | 0 | 5.9s |  |
| 114 | `issue_2166` | 9 | 5.9s |  |
| 115 | `issue_3446` | 1 | 5.9s |  |
| 116 | `issue_4377` | 2 | 5.9s |  |
| 117 | `issue_710` | 4 | 5.9s |  |
| 118 | `issue_768` | 3 | 5.9s | [11](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 119 | `lessthan` | 41 | 5.9s |  |
| 120 | `lessthan2_swf5` | 1226 | 8.1s |  |
| 121 | `lessthan2_swf6` | 1226 | 8.0s |  |
| 122 | `lessthan2_swf7` | 1226 | 8.0s |  |
| 123 | `lessthan_swf4` | 902 | 6.6s |  |
| 124 | `lessthan_swf4_alt` | 41 | 5.9s |  |
| 125 | `lessthan_swf5` | 41 | 6.0s |  |
| 126 | `logical_ops_swf4` | 90 | 6.0s |  |
| 127 | `logical_ops_swf8` | 108 | 6.1s |  |
| 128 | `looping` | 6 | 6.0s |  |
| 129 | `mask_reapply` | 0 | 6.1s |  |
| 130 | `mask_with_drawing` | 0 | 6.1s |  |
| 131 | `math_min_max` | 101 | 6.2s | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 132 | `matrix` | 171 | 6.5s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 133 | `mouse_wheel_enabled` | 2 | 6.1s |  |
| 134 | `movieclip_begin_gradient_fill` | 0 | 6.5s |  |
| 135 | `movieclip_blend_mode_property` | 35 | 6.0s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 136 | `movieclip_default_state` | 69 | 6.3s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 137 | `movieclip_get_instance_at_depth` | 28 | 6.2s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 138 | `movieclip_line_gradient_style` | 0 | 6.3s |  |
| 139 | `movieclip_name_from_timeline` | 13 | 5.9s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 140 | `movieclip_prototype_extension` | 5 | 5.9s |  |
| 141 | `nested_textfields_in_buttons` | 0 | 5.9s |  |
| 142 | `netstream_play_flv_screen` | 0 | 18.8s |  |
| 143 | `new_method_wrap` | 4 | 5.9s |  |
| 144 | `new_object_enumerate` | 7 | 5.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 145 | `new_object_wrap` | 4 | 5.8s |  |
| 146 | `o` | 3 | 5.8s |  |
| 147 | `object_constructor` | 33 | 5.9s |  |
| 148 | `object_function` | 32 | 5.9s |  |
| 149 | `object_properties` | 31 | 6.1s | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 150 | `object_string_coerce_swf5` | 62 | 6.0s | [15](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 151 | `point` | 175 | 6.3s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 152 | `primitive_instanceof` | 37 | 6.0s |  |
| 153 | `prototype_delete` | 12 | 5.9s |  |
| 154 | `prototype_enumerate` | 5 | 5.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 155 | `prototype_properties` | 17 | 5.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 156 | `rectangle` | 745 | 6.7s | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 157 | `recursive_prototypes` | 0 | 5.9s |  |
| 158 | `sandbox_type_local_file` | 1 | 5.8s |  |
| 159 | `set_variable_scope` | 58 | 5.8s |  |
| 160 | `single_frame` | 1 | 5.8s |  |
| 161 | `sound_start_load` | 0 | 5.8s |  |
| 162 | `stage_object_enumerate` | 4 | 5.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 163 | `stage_object_properties_get_var` | 5 | 5.8s |  |
| 164 | `stage_property_representation` | 586 | 5.8s | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 165 | `strictequals_swf6` | 902 | 7.2s |  |
| 166 | `strictly_equals` | 7 | 5.8s |  |
| 167 | `string_coercion` | 117 | 6.1s | [24](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 168 | `string_methods` | 285 | 6.3s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 169 | `string_methods_negative_args` | 240 | 6.0s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 170 | `string_methods_swfv5` | 275 | 6.3s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 171 | `string_ops_swf6` | 95 | 5.9s | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 172 | `string_paths_keyevents` | 0 | 5.8s |  |
| 173 | `string_paths_timer` | 0 | 5.8s |  |
| 174 | `swf4_actions_bool` | 96 | 5.8s |  |
| 175 | `swf4_bool` | 4 | 5.8s |  |
| 176 | `swf4_function_calls` | 7 | 6.2s |  |
| 177 | `swf5_encoding` | 3 | 6.0s |  |
| 178 | `swf7_case_sensitive` | 44 | 6.0s | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 179 | `tab_ordering_properties_tab_index_edge_case` | 4 | 6.0s |  |
| 180 | `text_format` | 1146 | 6.2s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `text_format_display` | 21 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `text_format_font_max_length` | 2 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 183 | `text_format_rounding_swf7` | 840 | 6.1s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 184 | `text_format_rounding_swf8` | 840 | 6.0s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 185 | `textfield_background_color` | 11 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 186 | `textfield_border_color` | 11 | 5.8s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 187 | `textfield_maxchars` | 3 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 188 | `textfield_properties` | 44 | 6.0s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 189 | `textfield_props_swf6` | 210 | 6.1s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 190 | `textfield_props_swf7` | 210 | 6.2s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 191 | `textfield_props_swf8` | 210 | 6.1s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 192 | `textfield_text` | 7 | 5.9s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 193 | `textfield_variable` | 81 | 6.1s | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 194 | `this_swf7` | 41 | 5.9s | [28](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 195 | `timeline_function_def` | 7 | 6.0s |  |
| 196 | `try_catch_finally` | 118 | 6.0s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 197 | `try_finally_simple` | 16 | 6.0s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 198 | `typeof` | 22 | 6.1s |  |
| 199 | `typeof_globals` | 7 | 6.0s |  |
| 200 | `uncaught_exception` | 1 | 5.9s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 201 | `uncaught_exception_bubbled` | 1 | 6.0s | [30](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 202 | `undefined_to_string_swf6` | 4 | 6.0s |  |
| 203 | `unescape` | 43 | 6.0s |  |
| 204 | `use_hand_cursor` | 8 | 5.9s |  |
| 205 | `variable_args` | 5 | 6.0s |  |
| 206 | `waitforframe` | 7 | 6.0s |  |
| 207 | `waitforframe2` | 16 | 6.0s |  |
| 208 | `with_return` | 2 | 6.0s |  |
| 209 | `with_variable_scopes` | 43 | 6.2s | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 210 | `xml` | 15 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 211 | `xml_append_child` | 28 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 212 | `xml_append_child_with_parent` | 20 | 6.3s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 213 | `xml_cdata` | 11 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 214 | `xml_child_nodes_edge_cases` | 4 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 215 | `xml_clone_expandos` | 19 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 216 | `xml_first_last_child` | 8 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 217 | `xml_has_child_nodes` | 3 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 218 | `xml_idmap` | 21 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_ignore_comments` | 21 | 6.3s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_ignore_white` | 34 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_insert_before` | 20 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_inspect_createmethods` | 15 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_inspect_doctype` | 7 | 6.3s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xml_inspect_parsexml` | 62 | 6.3s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 225 | `xml_inspect_xmldecl` | 7 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 226 | `xml_namespaces` | 203 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 227 | `xml_parent_and_child` | 5 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 228 | `xml_remove_node` | 22 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 229 | `xml_reparenting` | 14 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 230 | `xml_siblings` | 10 | 6.0s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 231 | `xml_to_string` | 13 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 232 | `xml_to_string_comment` | 1 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 233 | `xml_unescaping` | 23 | 6.2s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 234 | `xmlnode_proto` | 1 | 6.1s | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**90 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522 | 530 | 8 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 6 | `movieclip_depth_methods` | 95.9% | 94 | 98 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 8 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `with` | 93.9% | 46 | 49 | 3 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 11 | `stage_object_properties` | 93.4% | 225 | 241 | 16 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `stage_object_properties_swf6` | 91.8% | 212 | 231 | 19 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `object_prototypes` | 85.1% | 63 | 74 | 11 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `local_to_global` | 83.7% | 41 | 49 | 8 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 18 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `this_scoping` | 80.8% | 42 | 52 | 10 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 20 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 22 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
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
| 34 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 37 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
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
| 53 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 56 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `parse_float` | 58.1% | 43 | 74 | 31 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 58 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 59 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 60 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 61 | `primitive_type_globals` | 57.6% | 321 | 557 | 236 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 62 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `asnative` | 55.9% | 19 | 34 | 15 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 64 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 65 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 66 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 68 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 69 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 70 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 74 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 75 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 77 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 78 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 79 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 80 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 81 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 82 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 83 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 84 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 85 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 86 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 87 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 88 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 90 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

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
| 1 | `timeout` | runtime timeout (>10s) | 16.2s | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**383 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 3 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 6 | `movieclip_depth_methods` | 95.9% | 94/98 | 98 | 98 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 8 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `with` | 93.9% | 46/49 | 49 | 49 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 11 | `stage_object_properties` | 93.4% | 225/241 | 241 | 241 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `stage_object_properties_swf6` | 91.8% | 212/231 | 231 | 231 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 13 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `object_prototypes` | 85.1% | 63/74 | 73 | 74 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 18 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 20 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 22 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
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
| 34 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 37 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
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
| 53 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 56 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 58 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 59 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 60 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 61 | `primitive_type_globals` | 57.6% | 321/557 | 555 | 557 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 62 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `asnative` | 55.9% | 19/34 | 31 | 34 | [12](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 64 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 65 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 66 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 68 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 69 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 70 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 72 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 74 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 75 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 77 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 78 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 79 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 80 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 81 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 82 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 83 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 84 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 85 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 86 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 87 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 88 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 90 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 91 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 92 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 93 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 96 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 97 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 98 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 100 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 101 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 102 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 103 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 104 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 105 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 106 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 107 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 109 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 110 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 114 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 115 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 116 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 118 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 119 | `default_names` | 28.8% | 15/52 | 40 | 52 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 120 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 121 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 122 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 123 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 124 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 125 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 126 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 129 | `focusrect_property_swf5` | 21.7% | 269/1237 | 1236 | 1237 |  |
| 130 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 131 | `unload` | 21.2% | 11/52 | 48 | 52 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 132 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 133 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 134 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 135 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 136 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 137 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 138 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 139 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 140 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 141 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 142 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 143 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 144 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 146 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 147 | `watch` | 15.4% | 18/117 | 101 | 117 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 148 | `path_string` | 15.2% | 49/322 | 300 | 322 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 149 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 150 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 151 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 152 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 153 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 154 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 155 | `register_and_init_order` | 13.4% | 31/231 | 73 | 231 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 156 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 157 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 158 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 159 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 160 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 161 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 162 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 163 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 164 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 165 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [22](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 166 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 167 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 168 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 169 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 170 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 171 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 172 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 173 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `selection` | 9.3% | 42/454 | 244 | 454 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 175 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 177 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 178 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 179 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 180 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 181 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 182 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 184 | `define_local` | 7.4% | 2/27 | 23 | 27 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 185 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 186 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 187 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 188 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 189 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 190 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 191 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 192 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 193 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 194 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 195 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [29](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 196 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 197 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 198 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 199 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 200 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 201 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 202 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 203 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 204 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 205 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 206 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 207 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 208 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 209 | `register_class` | 3.0% | 2/66 | 27 | 66 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 210 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 211 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 212 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 213 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 214 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 215 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 216 | `parse_int` | 1.6% | 1/64 | 64 | 64 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 217 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 218 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 219 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 220 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 221 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 222 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 223 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 224 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 225 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 226 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 227 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 228 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 229 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [7](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 230 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 231 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 232 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 233 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 234 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 235 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 236 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 237 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 238 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 239 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 240 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 242 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 243 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 244 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 245 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 246 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 247 | `closure_scope` | 0.0% | 0/7 | 4 | 7 | [32](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 248 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 249 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 250 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 251 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 252 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 253 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 254 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 255 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 256 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 258 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 262 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 263 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 264 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [21](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 265 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 266 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 267 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 268 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 269 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 270 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 271 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 272 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 273 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 274 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 275 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 276 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 277 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 278 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 280 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 281 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 282 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 283 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 284 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 285 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 286 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 287 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 288 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 289 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 290 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 291 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 292 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [17](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 293 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 294 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 295 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 296 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 297 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 298 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 299 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 300 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 301 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 302 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 303 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 304 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 305 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 307 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 308 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 309 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 310 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 312 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 313 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 314 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 315 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 316 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 317 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 319 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 320 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 321 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 |  |
| 322 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 |  |
| 323 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 324 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 325 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 326 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 328 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 329 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 330 | `native_objects_swf8` | 0.0% | 0/144 | 144 | 84 | [8](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 331 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 332 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 333 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 334 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [19](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 335 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 336 | `place_and_lookup` | 0.0% | 0/30 | 27 | 30 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 337 | `placeobject_occupied_depth` | 0.0% | 0/6 | 2 | 6 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 338 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [20](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 339 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 340 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 341 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 342 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 343 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 344 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 345 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 346 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 347 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 348 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 349 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 350 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 351 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 352 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 353 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 354 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 355 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 356 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 357 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 358 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 359 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 360 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 361 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 362 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 363 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 364 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 365 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 366 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 367 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 368 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 369 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 370 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 371 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 372 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 373 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [26](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 374 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 375 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 376 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [27](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 377 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 378 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [13](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 379 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [16](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 380 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 381 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 382 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 383 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [33](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/incomplete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 4 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 1 | 4 |
| 5 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 6 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 11 | 3 |
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
| 27 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 21 | 49 |
| 28 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 29 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 30 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 31 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 32 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 33 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 315 | 140 | 175 |
