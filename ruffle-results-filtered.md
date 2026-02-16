# Ruffle Test Results (Filtered)

**Date**: 2026-02-16 23:32 UTC

**Git SHA**: `480bce068a`

**Run Duration**: 57m 52s

**Filtered**: 138 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 481 |
| Passing | **211** (43.9%) |
| Failing | 270 |
| Total expected lines | 77534 |
| Matching lines | 45422 (58.6%) |
| Mismatched lines | 32112 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 266 | 98.5% |
| Timeout | 2 | 0.7% |
| Segfault | 1 | 0.4% |
| Compile Fail | 1 | 0.4% |

## Passing Tests

**211 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 5.5s |  |
| 2 | `action_to_integer` | 28 | 5.2s |  |
| 3 | `add` | 28 | 5.2s |  |
| 4 | `add2` | 354 | 5.5s | [1](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 5.2s |  |
| 6 | `add_swf5` | 28 | 5.2s |  |
| 7 | `array_concat` | 98 | 5.3s |  |
| 8 | `array_constructor` | 30 | 5.3s |  |
| 9 | `array_enumerate` | 4 | 5.2s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 10 | `array_length` | 42 | 5.3s |  |
| 11 | `array_properties` | 36 | 5.2s |  |
| 12 | `array_slice` | 34 | 5.3s |  |
| 13 | `array_splice` | 207 | 5.4s |  |
| 14 | `array_trivial` | 209 | 5.4s |  |
| 15 | `as1_constructor_v6` | 35 | 5.2s |  |
| 16 | `as1_constructor_v7` | 35 | 5.2s |  |
| 17 | `as_broadcaster_initialize` | 10 | 5.2s |  |
| 18 | `as_set_prop_flags_version` | 31 | 5.2s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 19 | `as_set_prop_flags_version_swf5` | 1 | 5.3s |  |
| 20 | `as_set_prop_flags_version_swf6` | 1 | 5.2s |  |
| 21 | `as_set_prop_flags_version_swf7` | 1 | 5.2s |  |
| 22 | `as_set_prop_flags_version_swf8` | 1 | 5.2s |  |
| 23 | `as_set_prop_flags_version_swf9` | 1 | 5.2s |  |
| 24 | `as_transformed_flag` | 20 | 5.2s |  |
| 25 | `bad_swf_tag_past_eof` | 0 | 5.2s |  |
| 26 | `bitand` | 1058 | 7.6s |  |
| 27 | `bitmap_data_colortransform` | 0 | 5.4s |  |
| 28 | `bitmap_data_fillrect` | 0 | 5.4s |  |
| 29 | `bitmap_data_max_size_swf10` | 12 | 5.2s |  |
| 30 | `bitmap_data_max_size_swf9` | 10 | 5.2s |  |
| 31 | `bitmap_data_perlinnoise` | 0 | 5.8s |  |
| 32 | `bitmap_data_pixeldissolve_image` | 0 | 5.6s |  |
| 33 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.2s |  |
| 34 | `bitor` | 1058 | 7.7s |  |
| 35 | `biturshift` | 14 | 5.5s |  |
| 36 | `biturshift_swf8` | 14 | 5.4s |  |
| 37 | `bitxor` | 1058 | 8.1s |  |
| 38 | `call_method_empty_name` | 1 | 5.4s |  |
| 39 | `capabilities_resolution` | 8 | 5.3s |  |
| 40 | `catch_references_registers` | 2 | 5.5s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 41 | `conflicting_instance_names` | 23 | 5.4s |  |
| 42 | `define_function2` | 8 | 5.3s |  |
| 43 | `define_function2_preload` | 13 | 5.4s |  |
| 44 | `define_function2_preload_order` | 4 | 5.3s |  |
| 45 | `define_function_case_sensitive` | 2 | 5.3s |  |
| 46 | `delete` | 3 | 5.5s |  |
| 47 | `display_object_properties` | 2 | 5.4s |  |
| 48 | `do_init_action` | 3 | 5.5s |  |
| 49 | `edittext_antialiastype` | 296 | 5.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 50 | `edittext_autosize_setter` | 20 | 5.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 51 | `edittext_default_format` | 221 | 5.5s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 52 | `edittext_default_format_empty` | 95 | 5.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_default_format_font_style` | 335 | 5.4s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `equals` | 32 | 5.3s |  |
| 55 | `equals2_swf5` | 926 | 7.2s |  |
| 56 | `equals2_swf6` | 926 | 7.2s |  |
| 57 | `equals2_swf7` | 926 | 7.2s |  |
| 58 | `equals_swf4` | 665 | 5.8s |  |
| 59 | `equals_swf4_alt` | 32 | 5.3s |  |
| 60 | `equals_swf5` | 32 | 5.3s |  |
| 61 | `error` | 58 | 5.3s |  |
| 62 | `escape` | 14 | 5.3s |  |
| 63 | `execution_order1` | 5 | 5.4s |  |
| 64 | `execution_order2` | 7 | 5.4s |  |
| 65 | `execution_order3` | 4 | 5.3s |  |
| 66 | `focusrect_mouse_swf8` | 0 | 5.3s |  |
| 67 | `focusrect_mouse_swf9` | 0 | 5.3s |  |
| 68 | `focusrect_swf5` | 6 | 5.5s |  |
| 69 | `get_variable_in_scope` | 29 | 5.4s |  |
| 70 | `getproperty` | 28 | 5.3s |  |
| 71 | `getproperty_swf4` | 28 | 5.3s |  |
| 72 | `getproperty_swf5` | 28 | 5.3s |  |
| 73 | `global_array` | 3 | 5.3s |  |
| 74 | `global_is_bare` | 7 | 5.3s |  |
| 75 | `globals_swf6` | 304 | 5.5s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 76 | `globals_swf7` | 304 | 5.5s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 77 | `globals_swf8` | 304 | 5.5s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 78 | `goto_advance1` | 6 | 5.3s |  |
| 79 | `goto_advance2` | 2 | 5.3s |  |
| 80 | `goto_both_ways1` | 3 | 5.6s |  |
| 81 | `goto_both_ways2` | 3 | 5.5s |  |
| 82 | `goto_execution_order` | 2 | 5.5s |  |
| 83 | `goto_execution_order2` | 2 | 5.6s |  |
| 84 | `goto_frame_number` | 3 | 5.6s |  |
| 85 | `goto_rewind1` | 1 | 5.7s |  |
| 86 | `goto_rewind2` | 3 | 5.5s |  |
| 87 | `goto_rewind3` | 2 | 5.5s |  |
| 88 | `greater_swf6` | 1175 | 7.6s |  |
| 89 | `greater_swf7` | 1175 | 7.6s |  |
| 90 | `greaterthan_swf5` | 1 | 5.5s |  |
| 91 | `greaterthan_swf8` | 1 | 5.4s |  |
| 92 | `has_own_property` | 32 | 5.5s |  |
| 93 | `infinite_recursion_function` | 4 | 5.5s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 94 | `infinite_recursion_function_in_setter` | 131 | 5.5s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 95 | `infinite_recursion_virtual_property` | 67 | 5.6s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 96 | `init_array_invalid` | 4 | 5.5s |  |
| 97 | `init_object_invalid` | 4 | 5.5s |  |
| 98 | `is_finite` | 49 | 5.5s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 99 | `is_finite_swf6` | 49 | 5.5s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 100 | `is_prototype_of` | 89 | 5.6s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 101 | `issue_1086` | 1 | 5.5s |  |
| 102 | `issue_1671` | 0 | 5.5s |  |
| 103 | `issue_2166` | 9 | 5.5s |  |
| 104 | `issue_3446` | 1 | 5.5s |  |
| 105 | `issue_4377` | 2 | 5.5s |  |
| 106 | `issue_710` | 4 | 5.5s |  |
| 107 | `issue_768` | 3 | 5.5s | [9](ruffle-tests/_investigation/issue_768.md) |
| 108 | `lessthan` | 41 | 5.5s |  |
| 109 | `lessthan2_swf5` | 1226 | 8.0s |  |
| 110 | `lessthan2_swf6` | 1226 | 8.1s |  |
| 111 | `lessthan2_swf7` | 1226 | 8.2s |  |
| 112 | `lessthan_swf4` | 902 | 6.5s |  |
| 113 | `lessthan_swf4_alt` | 41 | 5.7s |  |
| 114 | `lessthan_swf5` | 41 | 5.7s |  |
| 115 | `logical_ops_swf4` | 90 | 5.2s |  |
| 116 | `logical_ops_swf8` | 108 | 5.3s |  |
| 117 | `looping` | 6 | 5.2s |  |
| 118 | `mask_reapply` | 0 | 5.2s |  |
| 119 | `mask_with_drawing` | 0 | 5.2s |  |
| 120 | `math_min_max` | 101 | 5.4s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 121 | `matrix` | 171 | 5.6s | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 122 | `movieclip_begin_gradient_fill` | 0 | 5.7s |  |
| 123 | `movieclip_blend_mode_property` | 35 | 5.3s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 124 | `movieclip_default_state` | 69 | 5.4s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 125 | `movieclip_line_gradient_style` | 0 | 5.8s |  |
| 126 | `movieclip_name_from_timeline` | 13 | 5.4s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 127 | `movieclip_prototype_extension` | 5 | 5.4s |  |
| 128 | `nested_textfields_in_buttons` | 0 | 5.4s |  |
| 129 | `netstream_play_flv_screen` | 0 | 18.4s |  |
| 130 | `new_method_wrap` | 4 | 5.4s |  |
| 131 | `new_object_enumerate` | 7 | 5.4s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 132 | `new_object_wrap` | 4 | 5.4s |  |
| 133 | `o` | 3 | 5.4s |  |
| 134 | `object_constructor` | 33 | 5.4s |  |
| 135 | `object_function` | 32 | 5.5s |  |
| 136 | `object_properties` | 31 | 5.6s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 137 | `object_string_coerce_swf5` | 62 | 5.5s | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 138 | `point` | 175 | 5.8s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 139 | `primitive_instanceof` | 37 | 5.4s |  |
| 140 | `prototype_delete` | 12 | 5.4s |  |
| 141 | `prototype_enumerate` | 5 | 5.4s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 142 | `rectangle` | 745 | 6.2s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 143 | `recursive_prototypes` | 0 | 5.4s |  |
| 144 | `sandbox_type_local_file` | 1 | 5.3s |  |
| 145 | `set_variable_scope` | 58 | 5.4s |  |
| 146 | `single_frame` | 1 | 5.3s |  |
| 147 | `sound_start_load` | 0 | 5.4s |  |
| 148 | `stage_object_properties_get_var` | 5 | 5.3s |  |
| 149 | `strictequals_swf6` | 902 | 6.9s |  |
| 150 | `strictly_equals` | 7 | 5.3s |  |
| 151 | `string_coercion` | 117 | 5.6s | [21](ruffle-tests/_investigation/string_coercion.md) |
| 152 | `string_methods` | 285 | 5.9s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 153 | `string_methods_negative_args` | 240 | 5.5s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 154 | `string_methods_swfv5` | 275 | 5.9s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 155 | `string_ops_swf6` | 95 | 5.4s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 156 | `string_paths_keyevents` | 0 | 5.4s |  |
| 157 | `string_paths_timer` | 0 | 5.3s |  |
| 158 | `swf4_actions_bool` | 96 | 5.3s |  |
| 159 | `swf4_bool` | 4 | 5.3s |  |
| 160 | `swf5_encoding` | 3 | 5.3s |  |
| 161 | `swf7_case_sensitive` | 44 | 5.3s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 162 | `tab_ordering_properties_tab_index_edge_case` | 4 | 5.3s |  |
| 163 | `text_format` | 1146 | 5.5s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 164 | `text_format_display` | 21 | 5.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 165 | `text_format_font_max_length` | 2 | 5.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 166 | `text_format_rounding_swf7` | 840 | 5.4s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 167 | `text_format_rounding_swf8` | 840 | 5.4s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 168 | `textfield_background_color` | 11 | 5.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 169 | `textfield_border_color` | 11 | 5.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 170 | `textfield_maxchars` | 3 | 5.4s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 171 | `textfield_properties` | 44 | 5.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 172 | `textfield_text` | 7 | 5.4s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 173 | `textfield_variable` | 81 | 5.5s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 174 | `this_swf7` | 41 | 5.3s | [25](ruffle-tests/_investigation/this_swf7.md) |
| 175 | `timeline_function_def` | 7 | 5.4s |  |
| 176 | `try_finally_simple` | 16 | 5.3s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 177 | `typeof` | 22 | 5.4s |  |
| 178 | `typeof_globals` | 7 | 5.3s |  |
| 179 | `uncaught_exception` | 1 | 5.3s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 180 | `uncaught_exception_bubbled` | 1 | 5.3s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 181 | `undefined_to_string_swf6` | 4 | 5.3s |  |
| 182 | `unescape` | 43 | 5.3s |  |
| 183 | `use_hand_cursor` | 8 | 5.3s |  |
| 184 | `variable_args` | 5 | 5.4s |  |
| 185 | `waitforframe` | 7 | 5.3s |  |
| 186 | `waitforframe2` | 16 | 5.3s |  |
| 187 | `with_return` | 2 | 5.3s |  |
| 188 | `with_variable_scopes` | 43 | 5.4s | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 189 | `xml` | 15 | 5.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 190 | `xml_append_child` | 28 | 5.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 191 | `xml_append_child_with_parent` | 20 | 5.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 192 | `xml_cdata` | 11 | 5.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 193 | `xml_clone_expandos` | 19 | 5.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 194 | `xml_first_last_child` | 8 | 5.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 195 | `xml_has_child_nodes` | 3 | 5.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 196 | `xml_idmap` | 21 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 197 | `xml_ignore_comments` | 21 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 198 | `xml_ignore_white` | 34 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 199 | `xml_insert_before` | 20 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 200 | `xml_inspect_createmethods` | 15 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 201 | `xml_inspect_doctype` | 7 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 202 | `xml_inspect_parsexml` | 62 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 203 | `xml_inspect_xmldecl` | 7 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 204 | `xml_namespaces` | 203 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 205 | `xml_parent_and_child` | 5 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 206 | `xml_remove_node` | 22 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 207 | `xml_reparenting` | 14 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 208 | `xml_siblings` | 10 | 5.4s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 209 | `xml_to_string_comment` | 1 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 210 | `xml_unescaping` | 23 | 5.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 211 | `xmlnode_proto` | 1 | 5.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**87 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `math_swf6` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `globals_swf5` | 95.4% | 290 | 304 | 14 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `edittext_width_height` | 94.2% | 97 | 103 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 6 | `with` | 93.9% | 46 | 49 | 3 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 7 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 8 | `prototype_properties` | 88.2% | 15 | 17 | 2 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 9 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 10 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 11 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 12 | `object_prototypes` | 85.1% | 63 | 74 | 11 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 13 | `xml_to_string` | 84.6% | 11 | 13 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 14 | `local_to_global` | 83.7% | 41 | 49 | 8 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 15 | `arguments` | 83.5% | 106 | 127 | 21 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 17 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 18 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 19 | `date` | 79.7% | 5049 | 6335 | 1286 | [4](ruffle-tests/_investigation/DATE_PLAN.md) |
| 20 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 23 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 24 | `as2_oop` | 76.9% | 10 | 13 | 3 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 26 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 27 | `array_sort` | 73.9% | 119 | 161 | 42 |  |
| 28 | `add_property` | 73.3% | 11 | 15 | 4 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `attach_movie` | 72.9% | 43 | 59 | 16 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 30 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 31 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 32 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 33 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 34 | `stage_object_properties` | 71.8% | 173 | 241 | 68 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 35 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 36 | `transform` | 71.4% | 50 | 70 | 20 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 37 | `register_underflow` | 69.2% | 18 | 26 | 8 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 38 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 39 | `textfield_props_swf6` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 40 | `textfield_props_swf7` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 41 | `textfield_props_swf8` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 42 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 43 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 44 | `export_assets` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 45 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 46 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 47 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 48 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 49 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 50 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 52 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 53 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 54 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 56 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `color` | 61.4% | 35 | 57 | 22 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 58 | `edittext_align` | 60.0% | 36 | 60 | 24 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 59 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 60 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 61 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 62 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 63 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 64 | `this_scoping` | 59.3% | 32 | 54 | 22 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 65 | `boxed_primitives` | 58.3% | 14 | 24 | 10 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 66 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 67 | `parse_float` | 58.1% | 43 | 74 | 31 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 68 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 69 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 70 | `asnative` | 55.9% | 19 | 34 | 15 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 71 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 72 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 73 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 74 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 75 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 76 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 77 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 78 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 79 | `issue_1906` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 80 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 81 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 82 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 83 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 84 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 85 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 86 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 7.5s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 15.5s | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 15.6s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |

## All Output Mismatches

**266 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `globals_swf5` | 95.4% | 290/304 | 304 | 304 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 6 | `with` | 93.9% | 46/49 | 49 | 49 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 7 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 8 | `prototype_properties` | 88.2% | 15/17 | 17 | 17 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 9 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 10 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 11 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 12 | `object_prototypes` | 85.1% | 63/74 | 73 | 74 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 13 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 14 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 15 | `arguments` | 83.5% | 106/127 | 127 | 127 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 17 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 18 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 19 | `date` | 79.7% | 5049/6335 | 6335 | 6335 | [4](ruffle-tests/_investigation/DATE_PLAN.md) |
| 20 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 23 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 24 | `as2_oop` | 76.9% | 10/13 | 13 | 13 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 26 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 27 | `array_sort` | 73.9% | 119/161 | 161 | 161 |  |
| 28 | `add_property` | 73.3% | 11/15 | 15 | 15 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 30 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 31 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 32 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 33 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 34 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 35 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 36 | `transform` | 71.4% | 50/70 | 70 | 70 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 37 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 38 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 39 | `textfield_props_swf6` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 40 | `textfield_props_swf7` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 41 | `textfield_props_swf8` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 42 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 43 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 44 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 45 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 46 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 47 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 48 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 49 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 50 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 51 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 52 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 53 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 54 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 56 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 57 | `color` | 61.4% | 35/57 | 57 | 57 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 58 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 59 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 60 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 61 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 62 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 63 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 64 | `this_scoping` | 59.3% | 32/54 | 54 | 52 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 65 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 66 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 67 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 68 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 69 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 70 | `asnative` | 55.9% | 19/34 | 31 | 34 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 71 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 72 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 73 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 74 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 75 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 76 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 77 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 78 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 79 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 80 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 81 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 82 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 83 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 84 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 85 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 86 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 87 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 88 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 89 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 90 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 91 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 92 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 93 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 94 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 95 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 96 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 97 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 98 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 99 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 100 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 101 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 102 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 103 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 104 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 105 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 106 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 107 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 109 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 110 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 111 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 112 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 113 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 114 | `enumerate` | 29.7% | 19/64 | 60 | 64 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 115 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 116 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 117 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 118 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 119 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 120 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 121 | `textfield_props_swf5` | 23.4% | 41/175 | 140 | 175 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 122 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 123 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 124 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 125 | `default_names` | 21.2% | 11/52 | 40 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 126 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 127 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 128 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 129 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 130 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 131 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 132 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 133 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 134 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 135 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 136 | `unload` | 15.4% | 8/52 | 48 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 137 | `watch` | 15.4% | 18/117 | 101 | 117 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 138 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 139 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 140 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 141 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 142 | `path_string` | 14.0% | 45/322 | 299 | 322 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 143 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 144 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 145 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 146 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 147 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 148 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 149 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 150 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 151 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 152 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 153 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 154 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 155 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 156 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 157 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 158 | `selection` | 9.3% | 42/454 | 244 | 454 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 159 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 160 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 161 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 162 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 163 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 164 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 165 | `define_local` | 7.4% | 2/27 | 23 | 27 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 166 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 167 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 168 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 169 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 170 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 171 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 172 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 173 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 174 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 175 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 176 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 177 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 178 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 179 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 180 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 181 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 182 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 183 | `register_class` | 3.0% | 2/66 | 27 | 66 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 184 | `clone_sprite_edittext_dynamic` | 2.3% | 2/86 | 86 | 86 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 185 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 186 | `parse_int` | 1.6% | 1/64 | 64 | 64 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 187 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 188 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 189 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 190 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 191 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 192 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 193 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 194 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 195 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 196 | `global_instance_decls` | 0.1% | 1/758 | 322 | 758 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 197 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 198 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 199 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 201 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 202 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 203 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 204 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 205 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 206 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 207 | `closure_scope` | 0.0% | 0/7 | 4 | 7 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 208 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 209 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 210 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 211 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 212 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 213 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 214 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 215 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 216 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 217 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 218 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 219 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 220 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 221 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 222 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 223 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 224 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 225 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 226 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 227 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 228 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 229 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 230 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 231 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 232 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 233 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 234 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 235 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 236 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 237 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 238 | `native_objects_swf8` | 0.0% | 0/144 | 144 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 239 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 240 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 241 | `place_and_lookup` | 0.0% | 0/30 | 21 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 242 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 243 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 244 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 245 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 246 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 247 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 248 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 249 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 250 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 251 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 252 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 253 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 254 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 255 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 256 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 257 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 258 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 259 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 260 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 261 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 262 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 263 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 264 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 265 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 266 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/add2.md) | 1 | 1 | 0 |
| 2 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 3 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) | 5 | 1 | 4 |
| 4 | [DATE_PLAN.md](ruffle-tests/_investigation/DATE_PLAN.md) | 1 | 0 | 1 |
| 5 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/ENUMERATION_PLAN.md) | 14 | 7 | 7 |
| 6 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 3 | 4 |
| 7 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/GLOBALS_PLAN.md) | 31 | 6 | 25 |
| 8 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 9 | [issue_768.md](ruffle-tests/_investigation/issue_768.md) | 1 | 1 | 0 |
| 10 | [MATH_PLAN.md](ruffle-tests/_investigation/MATH_PLAN.md) | 5 | 1 | 4 |
| 11 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) | 58 | 4 | 54 |
| 12 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) | 17 | 3 | 14 |
| 13 | [object_string_coerce.md](ruffle-tests/_investigation/object_string_coerce.md) | 2 | 1 | 1 |
| 14 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) | 4 | 0 | 4 |
| 15 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 0 | 8 |
| 16 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) | 3 | 0 | 3 |
| 17 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) | 12 | 4 | 8 |
| 18 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 19 | [SELECTION_PLAN.md](ruffle-tests/_investigation/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 20 | [STAGE_PLAN.md](ruffle-tests/_investigation/STAGE_PLAN.md) | 7 | 0 | 7 |
| 21 | [string_coercion.md](ruffle-tests/_investigation/string_coercion.md) | 1 | 1 | 0 |
| 22 | [STRING_PLAN.md](ruffle-tests/_investigation/STRING_PLAN.md) | 13 | 4 | 9 |
| 23 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 24 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) | 70 | 16 | 54 |
| 25 | [this_swf7.md](ruffle-tests/_investigation/this_swf7.md) | 1 | 1 | 0 |
| 26 | [TIMER_PLAN.md](ruffle-tests/_investigation/TIMER_PLAN.md) | 3 | 0 | 3 |
| 27 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) | 5 | 4 | 1 |
| 28 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 29 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 30 | [XML_PLAN.md](ruffle-tests/_investigation/XML_PLAN.md) | 33 | 23 | 10 |
| | *(tests not in any document)* | 215 | 136 | 79 |
