# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-18 04:26 UTC

**Git SHA**: `cfad7dbeaa`

**Run Duration**: 60m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **221** (35.7%) |
| Failing | 398 |
| Total expected lines | 91478 |
| Matching lines | 48521 (53.0%) |
| Mismatched lines | 42957 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 396 | 99.5% |
| Timeout | 1 | 0.3% |
| Runtime Segfault | 1 | 0.3% |

## Passing Tests

**221 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.5s |  |
| 2 | `action_to_integer` | 28 | 5.6s |  |
| 3 | `add` | 28 | 5.6s |  |
| 4 | `add2` | 354 | 5.8s | [1](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 5.5s |  |
| 6 | `add_swf5` | 28 | 5.5s |  |
| 7 | `array_call_method` | 9 | 5.6s |  |
| 8 | `array_concat` | 98 | 5.6s |  |
| 9 | `array_constructor` | 30 | 5.5s |  |
| 10 | `array_enumerate` | 4 | 5.5s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 11 | `array_length` | 42 | 5.5s |  |
| 12 | `array_properties` | 36 | 5.5s |  |
| 13 | `array_slice` | 34 | 5.6s |  |
| 14 | `array_splice` | 207 | 5.7s |  |
| 15 | `array_trivial` | 209 | 5.6s |  |
| 16 | `as1_constructor_v6` | 35 | 5.5s |  |
| 17 | `as1_constructor_v7` | 35 | 5.5s |  |
| 18 | `as2_oop` | 13 | 5.7s | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 19 | `as_broadcaster_initialize` | 10 | 5.5s |  |
| 20 | `as_set_prop_flags_version` | 31 | 5.5s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `as_set_prop_flags_version_swf5` | 1 | 5.5s |  |
| 22 | `as_set_prop_flags_version_swf6` | 1 | 5.5s |  |
| 23 | `as_set_prop_flags_version_swf7` | 1 | 5.6s |  |
| 24 | `as_set_prop_flags_version_swf8` | 1 | 5.5s |  |
| 25 | `as_set_prop_flags_version_swf9` | 1 | 5.5s |  |
| 26 | `as_transformed_flag` | 20 | 5.6s |  |
| 27 | `bad_swf_tag_past_eof` | 0 | 5.5s |  |
| 28 | `bitand` | 1058 | 8.3s |  |
| 29 | `bitmap_data_colortransform` | 0 | 5.9s |  |
| 30 | `bitmap_data_fillrect` | 0 | 5.7s |  |
| 31 | `bitmap_data_max_size_swf10` | 12 | 5.5s |  |
| 32 | `bitmap_data_max_size_swf9` | 10 | 5.6s |  |
| 33 | `bitmap_data_perlinnoise` | 0 | 6.1s |  |
| 34 | `bitmap_data_pixeldissolve_image` | 0 | 6.0s |  |
| 35 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.5s |  |
| 36 | `bitor` | 1058 | 8.2s |  |
| 37 | `biturshift` | 14 | 6.5s |  |
| 38 | `biturshift_swf8` | 14 | 5.5s |  |
| 39 | `bitxor` | 1058 | 8.0s |  |
| 40 | `call_method_empty_name` | 1 | 5.5s |  |
| 41 | `capabilities_resolution` | 8 | 5.5s |  |
| 42 | `catch_references_registers` | 2 | 5.5s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 43 | `conflicting_instance_names` | 23 | 5.6s |  |
| 44 | `define_function2` | 8 | 5.4s |  |
| 45 | `define_function2_preload` | 13 | 5.5s |  |
| 46 | `define_function2_preload_order` | 4 | 5.5s |  |
| 47 | `define_function_case_sensitive` | 2 | 5.5s |  |
| 48 | `delete` | 3 | 5.5s |  |
| 49 | `display_object_properties` | 2 | 5.5s |  |
| 50 | `divide_swf4` | 107 | 5.5s |  |
| 51 | `do_init_action` | 3 | 5.5s |  |
| 52 | `edittext_antialiastype` | 296 | 7.2s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_autosize_setter` | 20 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `edittext_default_format` | 221 | 5.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `edittext_default_format_empty` | 95 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 56 | `edittext_default_format_font_style` | 335 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `edittext_password` | 5 | 5.6s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `equals` | 32 | 5.6s |  |
| 59 | `equals2_swf5` | 926 | 7.4s |  |
| 60 | `equals2_swf6` | 926 | 7.5s |  |
| 61 | `equals2_swf7` | 926 | 7.4s |  |
| 62 | `equals_swf4` | 665 | 6.1s |  |
| 63 | `equals_swf4_alt` | 32 | 5.7s |  |
| 64 | `equals_swf5` | 32 | 5.7s |  |
| 65 | `error` | 58 | 5.7s |  |
| 66 | `escape` | 14 | 5.7s |  |
| 67 | `execution_order1` | 5 | 5.8s |  |
| 68 | `execution_order2` | 7 | 5.7s |  |
| 69 | `execution_order3` | 4 | 5.7s |  |
| 70 | `focusrect_mouse_swf8` | 0 | 5.5s |  |
| 71 | `focusrect_mouse_swf9` | 0 | 5.5s |  |
| 72 | `focusrect_swf5` | 6 | 5.7s |  |
| 73 | `get_variable_in_scope` | 29 | 5.5s |  |
| 74 | `getproperty` | 28 | 5.5s |  |
| 75 | `getproperty_swf4` | 28 | 5.5s |  |
| 76 | `getproperty_swf5` | 28 | 5.5s |  |
| 77 | `global_array` | 3 | 5.5s |  |
| 78 | `global_is_bare` | 7 | 5.5s |  |
| 79 | `globals_swf6` | 304 | 5.7s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 80 | `globals_swf7` | 304 | 5.7s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 81 | `globals_swf8` | 304 | 5.7s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 82 | `goto_advance1` | 6 | 5.5s |  |
| 83 | `goto_advance2` | 2 | 5.5s |  |
| 84 | `goto_both_ways1` | 3 | 5.8s |  |
| 85 | `goto_both_ways2` | 3 | 5.6s |  |
| 86 | `goto_execution_order` | 2 | 5.6s |  |
| 87 | `goto_execution_order2` | 2 | 5.6s |  |
| 88 | `goto_frame_number` | 3 | 5.7s |  |
| 89 | `goto_rewind1` | 1 | 5.8s |  |
| 90 | `goto_rewind2` | 3 | 5.6s |  |
| 91 | `goto_rewind3` | 2 | 5.7s |  |
| 92 | `greater_swf6` | 1175 | 7.7s |  |
| 93 | `greater_swf7` | 1175 | 7.7s |  |
| 94 | `greaterthan_swf5` | 1 | 5.6s |  |
| 95 | `greaterthan_swf8` | 1 | 5.6s |  |
| 96 | `has_own_property` | 32 | 5.6s |  |
| 97 | `infinite_recursion_function` | 4 | 5.6s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 98 | `infinite_recursion_function_in_setter` | 131 | 5.6s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 99 | `infinite_recursion_virtual_property` | 67 | 5.6s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 100 | `init_array_invalid` | 4 | 5.5s |  |
| 101 | `init_object_invalid` | 4 | 5.6s |  |
| 102 | `is_finite` | 49 | 5.7s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 103 | `is_finite_swf6` | 49 | 5.7s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 104 | `is_prototype_of` | 89 | 5.7s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 105 | `issue_1086` | 1 | 5.6s |  |
| 106 | `issue_1671` | 0 | 5.6s |  |
| 107 | `issue_2166` | 9 | 5.5s |  |
| 108 | `issue_3446` | 1 | 5.5s |  |
| 109 | `issue_4377` | 2 | 5.5s |  |
| 110 | `issue_710` | 4 | 5.6s |  |
| 111 | `issue_768` | 3 | 5.5s | [9](ruffle-tests/_investigation/issue_768.md) |
| 112 | `lessthan` | 41 | 5.6s |  |
| 113 | `lessthan2_swf5` | 1226 | 7.7s |  |
| 114 | `lessthan2_swf6` | 1226 | 7.7s |  |
| 115 | `lessthan2_swf7` | 1226 | 7.7s |  |
| 116 | `lessthan_swf4` | 902 | 6.2s |  |
| 117 | `lessthan_swf4_alt` | 41 | 5.6s |  |
| 118 | `lessthan_swf5` | 41 | 5.6s |  |
| 119 | `logical_ops_swf4` | 90 | 5.8s |  |
| 120 | `logical_ops_swf8` | 108 | 5.8s |  |
| 121 | `looping` | 6 | 5.7s |  |
| 122 | `mask_reapply` | 0 | 5.7s |  |
| 123 | `mask_with_drawing` | 0 | 5.6s |  |
| 124 | `math_min_max` | 101 | 5.7s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 125 | `matrix` | 171 | 5.9s | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 126 | `mouse_wheel_enabled` | 2 | 5.6s |  |
| 127 | `movieclip_begin_gradient_fill` | 0 | 6.1s |  |
| 128 | `movieclip_blend_mode_property` | 35 | 5.7s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 129 | `movieclip_default_state` | 69 | 5.8s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 130 | `movieclip_line_gradient_style` | 0 | 6.2s |  |
| 131 | `movieclip_name_from_timeline` | 13 | 5.8s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 132 | `movieclip_prototype_extension` | 5 | 5.8s |  |
| 133 | `nested_textfields_in_buttons` | 0 | 5.5s |  |
| 134 | `netstream_play_flv_screen` | 0 | 18.6s |  |
| 135 | `new_method_wrap` | 4 | 5.6s |  |
| 136 | `new_object_enumerate` | 7 | 5.6s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 137 | `new_object_wrap` | 4 | 5.5s |  |
| 138 | `o` | 3 | 5.6s |  |
| 139 | `object_constructor` | 33 | 5.6s |  |
| 140 | `object_function` | 32 | 5.6s |  |
| 141 | `object_properties` | 31 | 5.7s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 142 | `object_string_coerce_swf5` | 62 | 5.6s | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 143 | `point` | 175 | 6.0s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 144 | `primitive_instanceof` | 37 | 5.6s |  |
| 145 | `prototype_delete` | 12 | 5.6s |  |
| 146 | `prototype_enumerate` | 5 | 5.6s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 147 | `prototype_properties` | 17 | 5.7s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 148 | `rectangle` | 745 | 6.6s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 149 | `recursive_prototypes` | 0 | 5.5s |  |
| 150 | `sandbox_type_local_file` | 1 | 5.5s |  |
| 151 | `set_variable_scope` | 58 | 5.6s |  |
| 152 | `single_frame` | 1 | 5.5s |  |
| 153 | `sound_start_load` | 0 | 5.5s |  |
| 154 | `stage_object_properties_get_var` | 5 | 5.5s |  |
| 155 | `strictequals_swf6` | 902 | 7.0s |  |
| 156 | `strictly_equals` | 7 | 5.5s |  |
| 157 | `string_coercion` | 117 | 5.8s | [21](ruffle-tests/_investigation/string_coercion.md) |
| 158 | `string_methods` | 285 | 6.0s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 159 | `string_methods_negative_args` | 240 | 5.6s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 160 | `string_methods_swfv5` | 275 | 6.1s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 161 | `string_ops_swf6` | 95 | 5.6s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 162 | `string_paths_keyevents` | 0 | 5.5s |  |
| 163 | `string_paths_timer` | 0 | 5.5s |  |
| 164 | `swf4_actions_bool` | 96 | 5.5s |  |
| 165 | `swf4_bool` | 4 | 5.5s |  |
| 166 | `swf4_function_calls` | 7 | 6.0s |  |
| 167 | `swf5_encoding` | 3 | 5.7s |  |
| 168 | `swf7_case_sensitive` | 44 | 5.8s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 169 | `tab_ordering_properties_tab_index_edge_case` | 4 | 5.8s |  |
| 170 | `text_format` | 1146 | 5.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 171 | `text_format_display` | 21 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 172 | `text_format_font_max_length` | 2 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 173 | `text_format_rounding_swf7` | 840 | 5.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 174 | `text_format_rounding_swf8` | 840 | 5.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 175 | `textfield_background_color` | 11 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 176 | `textfield_border_color` | 11 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 177 | `textfield_maxchars` | 3 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 178 | `textfield_properties` | 44 | 5.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 179 | `textfield_text` | 7 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 180 | `textfield_variable` | 81 | 5.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 181 | `this_swf7` | 41 | 5.7s | [25](ruffle-tests/_investigation/this_swf7.md) |
| 182 | `timeline_function_def` | 7 | 5.8s |  |
| 183 | `try_catch_finally` | 118 | 5.7s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 184 | `try_finally_simple` | 16 | 5.5s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 185 | `typeof` | 22 | 5.6s |  |
| 186 | `typeof_globals` | 7 | 5.6s |  |
| 187 | `uncaught_exception` | 1 | 5.5s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 188 | `uncaught_exception_bubbled` | 1 | 5.5s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 189 | `undefined_to_string_swf6` | 4 | 5.5s |  |
| 190 | `unescape` | 43 | 5.6s |  |
| 191 | `use_hand_cursor` | 8 | 5.5s |  |
| 192 | `variable_args` | 5 | 5.6s |  |
| 193 | `waitforframe` | 7 | 5.5s |  |
| 194 | `waitforframe2` | 16 | 5.6s |  |
| 195 | `with_return` | 2 | 5.5s |  |
| 196 | `with_variable_scopes` | 43 | 5.6s | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 197 | `xml` | 15 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 198 | `xml_append_child` | 28 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 199 | `xml_append_child_with_parent` | 20 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 200 | `xml_cdata` | 11 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 201 | `xml_child_nodes_edge_cases` | 4 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 202 | `xml_clone_expandos` | 19 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 203 | `xml_first_last_child` | 8 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 204 | `xml_has_child_nodes` | 3 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 205 | `xml_idmap` | 21 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 206 | `xml_ignore_comments` | 21 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 207 | `xml_ignore_white` | 34 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 208 | `xml_insert_before` | 20 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 209 | `xml_inspect_createmethods` | 15 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 210 | `xml_inspect_doctype` | 7 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 211 | `xml_inspect_parsexml` | 62 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 212 | `xml_inspect_xmldecl` | 7 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 213 | `xml_namespaces` | 203 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 214 | `xml_parent_and_child` | 5 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 215 | `xml_remove_node` | 22 | 5.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 216 | `xml_reparenting` | 14 | 5.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 217 | `xml_siblings` | 10 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 218 | `xml_to_string` | 13 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 219 | `xml_to_string_comment` | 1 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 220 | `xml_unescaping` | 23 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 221 | `xmlnode_proto` | 1 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**97 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `math_swf6` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `globals_swf5` | 95.4% | 290 | 304 | 14 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_width_height` | 94.2% | 97 | 103 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 7 | `with` | 93.9% | 46 | 49 | 3 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 8 | `array_sort` | 87.1% | 142 | 163 | 21 |  |
| 9 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 10 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 11 | `object_prototypes` | 85.1% | 63 | 74 | 11 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 12 | `local_to_global` | 83.7% | 41 | 49 | 8 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 13 | `arguments` | 83.5% | 106 | 127 | 21 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 14 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 15 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 16 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 17 | `date` | 79.7% | 5049 | 6335 | 1286 | [4](ruffle-tests/_investigation/DATE_PLAN.md) |
| 18 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 19 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 20 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 21 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 22 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 23 | `add_property` | 73.3% | 11 | 15 | 4 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `attach_movie` | 72.9% | 43 | 59 | 16 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 26 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 28 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 29 | `stage_object_properties` | 71.8% | 173 | 241 | 68 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 30 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 31 | `transform` | 71.4% | 50 | 70 | 20 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 32 | `register_underflow` | 69.2% | 18 | 26 | 8 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 34 | `textfield_props_swf6` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 35 | `textfield_props_swf7` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 36 | `textfield_props_swf8` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 37 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 38 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 39 | `export_assets` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 40 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 41 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 42 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 43 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 44 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 45 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 46 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 47 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 48 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 49 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 50 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 51 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 52 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `color` | 61.4% | 35 | 57 | 22 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 54 | `edittext_align` | 60.0% | 36 | 60 | 24 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 56 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 59 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 60 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 61 | `this_scoping` | 59.3% | 32 | 54 | 22 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 62 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 63 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 64 | `parse_float` | 58.1% | 43 | 74 | 31 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 65 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 66 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 67 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 68 | `primitive_type_globals` | 57.6% | 321 | 557 | 236 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 69 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 70 | `asnative` | 55.9% | 19 | 34 | 15 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 71 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 72 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 73 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 74 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 75 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 76 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 77 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 78 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 79 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 80 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 81 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 82 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 83 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 84 | `issue_1906` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 85 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 86 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 87 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 88 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 89 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 90 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 91 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 92 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 93 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 94 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 95 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 96 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 97 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 7.8s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 15.7s | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |

## All Output Mismatches

**396 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `globals_swf5` | 95.4% | 290/304 | 304 | 304 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 7 | `with` | 93.9% | 46/49 | 49 | 49 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 8 | `array_sort` | 87.1% | 142/163 | 163 | 161 |  |
| 9 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 10 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 11 | `object_prototypes` | 85.1% | 63/74 | 73 | 74 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 12 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 13 | `arguments` | 83.5% | 106/127 | 127 | 127 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 14 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 15 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 16 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 17 | `date` | 79.7% | 5049/6335 | 6335 | 6335 | [4](ruffle-tests/_investigation/DATE_PLAN.md) |
| 18 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 19 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 20 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 21 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 22 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 23 | `add_property` | 73.3% | 11/15 | 15 | 15 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 26 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 28 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 29 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 30 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 31 | `transform` | 71.4% | 50/70 | 70 | 70 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 32 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 34 | `textfield_props_swf6` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 35 | `textfield_props_swf7` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 36 | `textfield_props_swf8` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 37 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 38 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 39 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 40 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 41 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 42 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 43 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 44 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 45 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 46 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 47 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 48 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 49 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 50 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 51 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 52 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `color` | 61.4% | 35/57 | 57 | 57 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 54 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 56 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 59 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 60 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 61 | `this_scoping` | 59.3% | 32/54 | 54 | 52 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 62 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 63 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 64 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 65 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 66 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 67 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 68 | `primitive_type_globals` | 57.6% | 321/557 | 555 | 557 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 69 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 70 | `asnative` | 55.9% | 19/34 | 31 | 34 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 71 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 72 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 73 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 74 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 75 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 76 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 77 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 78 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 79 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 80 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 81 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 82 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 83 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 84 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 85 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 86 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 87 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 88 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 89 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 90 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 91 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 92 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 93 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 94 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 95 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 96 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 97 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 98 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 99 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 100 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 101 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 102 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 103 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 104 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 105 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 106 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 107 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 108 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 109 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 110 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 111 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 112 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 113 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 114 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 115 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 116 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 117 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 118 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 120 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 121 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 122 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 123 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 124 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 125 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 126 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 127 | `enumerate` | 29.7% | 19/64 | 60 | 64 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 128 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 129 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 130 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 131 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 132 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 133 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 134 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 135 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 136 | `textfield_props_swf5` | 23.4% | 41/175 | 140 | 175 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 137 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 138 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 139 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 140 | `default_names` | 21.2% | 11/52 | 40 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 141 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 142 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 143 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 144 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 145 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 146 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 147 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 148 | `focusrect_property_swf5` | 19.2% | 238/1237 | 1236 | 1237 |  |
| 149 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 150 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 151 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 152 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 153 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 154 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 155 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 156 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 157 | `unload` | 15.4% | 8/52 | 48 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 158 | `watch` | 15.4% | 18/117 | 101 | 117 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 159 | `path_string` | 14.9% | 48/322 | 300 | 322 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 160 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 161 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 162 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 163 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 164 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 165 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 166 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 167 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 168 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 169 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 170 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 171 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 172 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 173 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 174 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 175 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 176 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 177 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 178 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 179 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 180 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 181 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 182 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 183 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 184 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 185 | `selection` | 9.3% | 42/454 | 244 | 454 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 186 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 187 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 188 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 189 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 190 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 191 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 192 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 193 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 194 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 195 | `define_local` | 7.4% | 2/27 | 23 | 27 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 196 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 197 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 198 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 199 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 200 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 201 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 202 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 203 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 204 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 205 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 206 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 207 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 208 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 209 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 210 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 211 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 212 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 213 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 214 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 215 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 217 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 218 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 219 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 220 | `register_class` | 3.0% | 2/66 | 27 | 66 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 221 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 222 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 223 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 224 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 225 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 226 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 227 | `parse_int` | 1.6% | 1/64 | 64 | 64 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 228 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 229 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 230 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 231 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 232 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 233 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 234 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 235 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 236 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 237 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 238 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 239 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 240 | `array_sort_random` | 0.2% | 1/443 | 80 | 443 |  |
| 241 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 242 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 243 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 244 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 246 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 248 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 249 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 250 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 251 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 252 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 253 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 255 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 256 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 257 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 258 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 259 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 260 | `closure_scope` | 0.0% | 0/7 | 4 | 7 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 261 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 262 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 263 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 264 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 265 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 266 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 267 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 269 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 270 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 271 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 272 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 273 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 274 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 275 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 276 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 277 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 278 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 279 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 280 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 281 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
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
| 300 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 301 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 302 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 303 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 304 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 305 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 306 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 307 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 308 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 309 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 310 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 311 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 312 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 313 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 314 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 315 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 316 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 317 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 318 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 319 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 320 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 321 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 322 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 323 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 324 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 325 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 326 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 327 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 328 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 329 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 330 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 331 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 332 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 333 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 |  |
| 335 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 |  |
| 336 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 337 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 338 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 339 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 341 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 342 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 343 | `native_objects_swf8` | 0.0% | 0/144 | 144 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 344 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 345 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 346 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 347 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 348 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 349 | `place_and_lookup` | 0.0% | 0/30 | 21 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 350 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 351 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 352 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 353 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 354 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 355 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 356 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 357 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 358 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 359 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 360 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 361 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 362 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 363 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 364 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 365 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 366 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 367 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 368 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 369 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 370 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 371 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 372 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 373 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 374 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 375 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 376 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 377 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 378 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 379 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 380 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 381 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 382 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 383 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 384 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 385 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 386 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 387 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 388 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 389 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 390 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 391 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 392 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 393 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 394 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 395 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 396 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/add2.md) | 1 | 1 | 0 |
| 2 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 3 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) | 5 | 1 | 4 |
| 4 | [DATE_PLAN.md](ruffle-tests/_investigation/DATE_PLAN.md) | 1 | 0 | 1 |
| 5 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/ENUMERATION_PLAN.md) | 14 | 8 | 6 |
| 6 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 3 | 4 |
| 7 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/GLOBALS_PLAN.md) | 31 | 6 | 25 |
| 8 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 9 | [issue_768.md](ruffle-tests/_investigation/issue_768.md) | 1 | 1 | 0 |
| 10 | [MATH_PLAN.md](ruffle-tests/_investigation/MATH_PLAN.md) | 5 | 1 | 4 |
| 11 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) | 58 | 4 | 54 |
| 12 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) | 17 | 4 | 13 |
| 13 | [object_string_coerce.md](ruffle-tests/_investigation/object_string_coerce.md) | 2 | 1 | 1 |
| 14 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) | 4 | 0 | 4 |
| 15 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 16 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) | 3 | 0 | 3 |
| 17 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) | 12 | 5 | 7 |
| 18 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 19 | [SELECTION_PLAN.md](ruffle-tests/_investigation/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 20 | [STAGE_PLAN.md](ruffle-tests/_investigation/STAGE_PLAN.md) | 7 | 0 | 7 |
| 21 | [string_coercion.md](ruffle-tests/_investigation/string_coercion.md) | 1 | 1 | 0 |
| 22 | [STRING_PLAN.md](ruffle-tests/_investigation/STRING_PLAN.md) | 13 | 4 | 9 |
| 23 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 24 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) | 70 | 17 | 53 |
| 25 | [this_swf7.md](ruffle-tests/_investigation/this_swf7.md) | 1 | 1 | 0 |
| 26 | [TIMER_PLAN.md](ruffle-tests/_investigation/TIMER_PLAN.md) | 3 | 0 | 3 |
| 27 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 28 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 29 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 30 | [XML_PLAN.md](ruffle-tests/_investigation/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 326 | 140 | 186 |
