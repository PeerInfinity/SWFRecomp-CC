# Ruffle Test Results (Filtered)

**Date**: 2026-02-15 23:34 UTC

**Git SHA**: `6c9b9420a8`

**Run Duration**: 50m 9s

**Filtered**: 137 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 482 |
| Passing | **201** (41.7%) |
| Failing | 281 |
| Total expected lines | 77810 |
| Matching lines | 43974 (56.5%) |
| Mismatched lines | 33836 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 274 | 97.5% |
| Segfault | 5 | 1.8% |
| Timeout | 2 | 0.7% |

## Passing Tests

**201 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 6.3s |  |
| 2 | `action_to_integer` | 28 | 4.6s |  |
| 3 | `add` | 28 | 4.5s |  |
| 4 | `add2` | 354 | 4.8s | [1](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.0s |  |
| 6 | `add_swf5` | 28 | 4.1s |  |
| 7 | `array_concat` | 98 | 4.6s |  |
| 8 | `array_constructor` | 30 | 4.6s |  |
| 9 | `array_enumerate` | 4 | 4.5s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 10 | `array_properties` | 36 | 4.5s |  |
| 11 | `array_slice` | 34 | 4.6s |  |
| 12 | `array_splice` | 207 | 4.7s |  |
| 13 | `array_trivial` | 209 | 4.3s |  |
| 14 | `as1_constructor_v6` | 35 | 4.1s |  |
| 15 | `as1_constructor_v7` | 35 | 4.1s |  |
| 16 | `as_broadcaster_initialize` | 10 | 4.5s |  |
| 17 | `as_set_prop_flags_version_swf5` | 1 | 4.1s |  |
| 18 | `as_set_prop_flags_version_swf6` | 1 | 4.1s |  |
| 19 | `as_set_prop_flags_version_swf7` | 1 | 4.1s |  |
| 20 | `as_set_prop_flags_version_swf8` | 1 | 4.6s |  |
| 21 | `as_set_prop_flags_version_swf9` | 1 | 4.6s |  |
| 22 | `as_transformed_flag` | 20 | 4.6s |  |
| 23 | `bad_swf_tag_past_eof` | 0 | 4.5s |  |
| 24 | `bitand` | 1058 | 6.5s |  |
| 25 | `bitmap_data_colortransform` | 0 | 4.8s |  |
| 26 | `bitmap_data_fillrect` | 0 | 4.7s |  |
| 27 | `bitmap_data_max_size_swf10` | 12 | 4.5s |  |
| 28 | `bitmap_data_max_size_swf9` | 10 | 4.5s |  |
| 29 | `bitmap_data_perlinnoise` | 0 | 5.1s |  |
| 30 | `bitmap_data_pixeldissolve_image` | 0 | 4.9s |  |
| 31 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.6s |  |
| 32 | `bitor` | 1058 | 6.4s |  |
| 33 | `biturshift` | 14 | 5.2s |  |
| 34 | `biturshift_swf8` | 14 | 4.8s |  |
| 35 | `bitxor` | 1058 | 6.9s |  |
| 36 | `call_method_empty_name` | 1 | 4.8s |  |
| 37 | `capabilities_resolution` | 8 | 4.7s |  |
| 38 | `catch_references_registers` | 2 | 4.8s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 39 | `define_function2` | 8 | 4.7s |  |
| 40 | `define_function2_preload` | 13 | 4.7s |  |
| 41 | `define_function_case_sensitive` | 2 | 4.7s |  |
| 42 | `delete` | 3 | 4.4s |  |
| 43 | `display_object_properties` | 2 | 4.7s |  |
| 44 | `do_init_action` | 3 | 4.9s |  |
| 45 | `edittext_antialiastype` | 296 | 5.4s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 46 | `edittext_autosize_setter` | 20 | 4.3s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 47 | `edittext_default_format` | 221 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 48 | `edittext_default_format_empty` | 95 | 4.7s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 49 | `edittext_default_format_font_style` | 335 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 50 | `equals` | 32 | 4.8s |  |
| 51 | `equals2_swf5` | 926 | 6.1s |  |
| 52 | `equals2_swf6` | 926 | 6.2s |  |
| 53 | `equals2_swf7` | 926 | 6.1s |  |
| 54 | `equals_swf4` | 665 | 4.8s |  |
| 55 | `equals_swf4_alt` | 32 | 4.3s |  |
| 56 | `equals_swf5` | 32 | 4.3s |  |
| 57 | `error` | 58 | 4.8s |  |
| 58 | `escape` | 14 | 4.8s |  |
| 59 | `execution_order3` | 4 | 4.8s |  |
| 60 | `focusrect_mouse_swf8` | 0 | 4.7s |  |
| 61 | `focusrect_mouse_swf9` | 0 | 4.7s |  |
| 62 | `focusrect_swf5` | 6 | 4.5s |  |
| 63 | `getproperty` | 28 | 4.7s |  |
| 64 | `getproperty_swf4` | 28 | 4.2s |  |
| 65 | `getproperty_swf5` | 28 | 4.2s |  |
| 66 | `global_array` | 3 | 4.7s |  |
| 67 | `global_is_bare` | 7 | 4.6s |  |
| 68 | `globals_swf6` | 304 | 4.5s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 69 | `globals_swf7` | 304 | 4.5s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 70 | `globals_swf8` | 304 | 4.9s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 71 | `goto_advance1` | 6 | 4.7s |  |
| 72 | `goto_advance2` | 2 | 4.7s |  |
| 73 | `goto_both_ways1` | 3 | 4.4s |  |
| 74 | `goto_both_ways2` | 3 | 4.2s |  |
| 75 | `goto_execution_order` | 2 | 4.7s |  |
| 76 | `goto_execution_order2` | 2 | 4.7s |  |
| 77 | `goto_frame_number` | 3 | 4.8s |  |
| 78 | `goto_rewind1` | 1 | 4.9s |  |
| 79 | `goto_rewind2` | 3 | 4.8s |  |
| 80 | `goto_rewind3` | 2 | 4.3s |  |
| 81 | `greater_swf6` | 1175 | 6.2s |  |
| 82 | `greater_swf7` | 1175 | 6.2s |  |
| 83 | `greaterthan_swf5` | 1 | 4.2s |  |
| 84 | `greaterthan_swf8` | 1 | 4.7s |  |
| 85 | `has_own_property` | 32 | 4.3s |  |
| 86 | `infinite_recursion_function` | 4 | 4.7s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 87 | `infinite_recursion_function_in_setter` | 131 | 4.7s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 88 | `infinite_recursion_virtual_property` | 67 | 4.7s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 89 | `init_array_invalid` | 4 | 4.7s |  |
| 90 | `init_object_invalid` | 4 | 4.7s |  |
| 91 | `is_finite` | 49 | 4.8s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 92 | `is_finite_swf6` | 49 | 4.3s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 93 | `issue_1086` | 1 | 4.2s |  |
| 94 | `issue_1671` | 0 | 4.7s |  |
| 95 | `issue_2166` | 9 | 4.3s |  |
| 96 | `issue_3446` | 1 | 4.7s |  |
| 97 | `issue_4377` | 2 | 4.7s |  |
| 98 | `issue_710` | 4 | 4.2s |  |
| 99 | `issue_768` | 3 | 4.7s | [9](ruffle-tests/_investigation/issue_768.md) |
| 100 | `lessthan` | 41 | 4.7s |  |
| 101 | `lessthan2_swf5` | 1226 | 6.3s |  |
| 102 | `lessthan2_swf6` | 1226 | 6.3s |  |
| 103 | `lessthan2_swf7` | 1226 | 6.4s |  |
| 104 | `lessthan_swf4` | 902 | 4.9s |  |
| 105 | `lessthan_swf4_alt` | 41 | 4.2s |  |
| 106 | `lessthan_swf5` | 41 | 4.2s |  |
| 107 | `logical_ops_swf4` | 90 | 4.3s |  |
| 108 | `logical_ops_swf8` | 108 | 4.7s |  |
| 109 | `looping` | 6 | 4.7s |  |
| 110 | `mask_reapply` | 0 | 4.7s |  |
| 111 | `mask_with_drawing` | 0 | 4.7s |  |
| 112 | `math_min_max` | 101 | 4.8s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 113 | `matrix` | 171 | 5.0s | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 114 | `movieclip_begin_gradient_fill` | 0 | 5.1s |  |
| 115 | `movieclip_blend_mode_property` | 35 | 4.8s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 116 | `movieclip_default_state` | 69 | 4.9s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 117 | `movieclip_line_gradient_style` | 0 | 4.9s |  |
| 118 | `movieclip_name_from_timeline` | 13 | 4.5s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 119 | `movieclip_prototype_extension` | 5 | 4.1s |  |
| 120 | `nested_textfields_in_buttons` | 0 | 4.7s |  |
| 121 | `netstream_play_flv_screen` | 0 | 17.5s |  |
| 122 | `new_method_wrap` | 4 | 4.7s |  |
| 123 | `new_object_enumerate` | 7 | 4.8s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 124 | `new_object_wrap` | 4 | 4.7s |  |
| 125 | `o` | 3 | 4.7s |  |
| 126 | `object_constructor` | 33 | 4.7s |  |
| 127 | `object_function` | 32 | 4.7s |  |
| 128 | `object_string_coerce_swf5` | 62 | 4.3s | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 129 | `point` | 175 | 5.0s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 130 | `primitive_instanceof` | 37 | 4.6s |  |
| 131 | `prototype_delete` | 12 | 4.7s |  |
| 132 | `prototype_enumerate` | 5 | 4.2s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 133 | `rectangle` | 745 | 5.4s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 134 | `recursive_prototypes` | 0 | 4.2s |  |
| 135 | `sandbox_type_local_file` | 1 | 4.3s |  |
| 136 | `set_variable_scope` | 58 | 4.8s |  |
| 137 | `single_frame` | 1 | 4.8s |  |
| 138 | `sound_start_load` | 0 | 4.8s |  |
| 139 | `stage_object_enumerate` | 4 | 4.8s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 140 | `stage_object_properties_get_var` | 5 | 4.8s |  |
| 141 | `strictequals_swf6` | 902 | 6.0s |  |
| 142 | `strictly_equals` | 7 | 4.8s |  |
| 143 | `string_coercion` | 117 | 4.6s | [21](ruffle-tests/_investigation/string_coercion.md) |
| 144 | `string_methods` | 285 | 5.3s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 145 | `string_methods_negative_args` | 240 | 4.5s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 146 | `string_methods_swfv5` | 275 | 4.8s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 147 | `string_ops_swf6` | 95 | 4.9s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 148 | `string_paths_keyevents` | 0 | 4.8s |  |
| 149 | `string_paths_timer` | 0 | 4.8s |  |
| 150 | `swf4_actions_bool` | 96 | 4.3s |  |
| 151 | `swf4_bool` | 4 | 4.3s |  |
| 152 | `swf5_encoding` | 3 | 4.2s |  |
| 153 | `swf7_case_sensitive` | 44 | 4.3s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 154 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.9s |  |
| 155 | `text_format` | 1146 | 5.1s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 156 | `text_format_display` | 21 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 157 | `text_format_font_max_length` | 2 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 158 | `text_format_rounding_swf7` | 840 | 4.5s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 159 | `text_format_rounding_swf8` | 840 | 5.0s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 160 | `textfield_background_color` | 11 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 161 | `textfield_border_color` | 11 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 162 | `textfield_maxchars` | 3 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 163 | `textfield_properties` | 44 | 5.0s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 164 | `textfield_text` | 7 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 165 | `this_swf7` | 41 | 4.2s | [25](ruffle-tests/_investigation/this_swf7.md) |
| 166 | `timeline_function_def` | 7 | 4.3s |  |
| 167 | `try_finally_simple` | 16 | 4.8s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 168 | `typeof` | 22 | 4.8s |  |
| 169 | `typeof_globals` | 7 | 4.2s |  |
| 170 | `uncaught_exception` | 1 | 4.7s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 171 | `uncaught_exception_bubbled` | 1 | 4.7s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 172 | `undefined_to_string_swf6` | 4 | 4.3s |  |
| 173 | `unescape` | 43 | 4.8s |  |
| 174 | `use_hand_cursor` | 8 | 4.8s |  |
| 175 | `waitforframe` | 7 | 4.2s |  |
| 176 | `waitforframe2` | 16 | 4.3s |  |
| 177 | `with_return` | 2 | 4.6s |  |
| 178 | `with_variable_scopes` | 43 | 4.7s | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 179 | `xml` | 15 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 180 | `xml_append_child` | 28 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 181 | `xml_append_child_with_parent` | 20 | 4.2s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 182 | `xml_cdata` | 11 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 183 | `xml_clone_expandos` | 19 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 184 | `xml_first_last_child` | 8 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 185 | `xml_has_child_nodes` | 3 | 4.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 186 | `xml_idmap` | 21 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 187 | `xml_ignore_comments` | 21 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 188 | `xml_ignore_white` | 34 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 189 | `xml_insert_before` | 20 | 4.2s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 190 | `xml_inspect_createmethods` | 15 | 4.2s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 191 | `xml_inspect_doctype` | 7 | 4.2s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 192 | `xml_inspect_parsexml` | 62 | 4.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 193 | `xml_inspect_xmldecl` | 7 | 4.2s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 194 | `xml_namespaces` | 203 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 195 | `xml_parent_and_child` | 5 | 4.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 196 | `xml_remove_node` | 22 | 4.2s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 197 | `xml_reparenting` | 14 | 4.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 198 | `xml_siblings` | 10 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 199 | `xml_to_string_comment` | 1 | 4.2s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 200 | `xml_unescaping` | 23 | 4.3s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 201 | `xmlnode_proto` | 1 | 4.7s | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**95 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `math_swf6` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522 | 530 | 8 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `conflicting_instance_names` | 95.7% | 22 | 23 | 1 |  |
| 5 | `globals_swf5` | 95.4% | 290 | 304 | 14 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_width_height` | 94.2% | 97 | 103 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 7 | `get_variable_in_scope` | 93.1% | 27 | 29 | 2 |  |
| 8 | `array_length` | 92.9% | 39 | 42 | 3 |  |
| 9 | `divide_swf4` | 88.8% | 95 | 107 | 12 |  |
| 10 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 11 | `textfield_variable` | 86.4% | 70 | 81 | 11 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 12 | `function_suppress_and_preload` | 85.7% | 24 | 28 | 4 |  |
| 13 | `swf4_function_calls` | 85.7% | 6 | 7 | 1 |  |
| 14 | `xml_to_string` | 84.6% | 11 | 13 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 15 | `object_prototypes` | 83.8% | 62 | 74 | 12 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `arguments` | 83.5% | 106 | 127 | 21 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 17 | `prototype_properties` | 82.4% | 14 | 17 | 3 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `local_to_global` | 81.6% | 40 | 49 | 9 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 19 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 20 | `stage_object_children` | 80.7% | 67 | 83 | 16 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 21 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 22 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 23 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 24 | `as2_oop` | 76.9% | 10 | 13 | 3 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `with` | 75.5% | 37 | 49 | 12 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 26 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 28 | `array_sort` | 73.9% | 119 | 161 | 42 |  |
| 29 | `attach_movie` | 72.9% | 43 | 59 | 16 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 30 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 31 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 32 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 33 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 34 | `transform` | 71.4% | 50 | 70 | 20 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 35 | `register_underflow` | 69.2% | 18 | 26 | 8 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 36 | `as_set_prop_flags` | 68.4% | 54 | 79 | 25 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 37 | `stage_object_properties` | 68.0% | 164 | 241 | 77 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 38 | `stage_object_properties_swf6` | 68.0% | 157 | 231 | 74 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 39 | `as_set_prop_flags_version` | 67.7% | 21 | 31 | 10 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 40 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 41 | `textfield_props_swf6` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 42 | `textfield_props_swf7` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 43 | `textfield_props_swf8` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 44 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 45 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 46 | `export_assets` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 47 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 48 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 49 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 50 | `is_prototype_of` | 66.3% | 59 | 89 | 30 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `remove_movie_clip` | 65.5% | 19 | 29 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 52 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18 | 28 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 55 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 56 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 57 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `string_paths_hidden` | 63.0% | 34 | 54 | 20 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 59 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 60 | `color` | 61.4% | 35 | 57 | 22 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 61 | `edittext_align` | 60.0% | 36 | 60 | 24 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 62 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 63 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 64 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 65 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 66 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 67 | `execution_order1` | 60.0% | 3 | 5 | 2 |  |
| 68 | `boxed_primitives` | 58.3% | 14 | 24 | 10 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 69 | `parse_float` | 58.1% | 43 | 74 | 31 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 70 | `primitive_type_globals` | 57.5% | 320 | 557 | 237 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 71 | `execution_order2` | 57.1% | 4 | 7 | 3 |  |
| 72 | `date` | 57.1% | 3617 | 6335 | 2718 | [4](ruffle-tests/_investigation/DATE_PLAN.md) |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 74 | `asnative` | 55.9% | 19 | 34 | 15 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 75 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 76 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 77 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 78 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 79 | `clone_sprite_types` | 54.2% | 13 | 24 | 11 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 80 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 81 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 82 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 83 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 84 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 85 | `issue_1906` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 86 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 87 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 88 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 89 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 90 | `root_global_parent` | 50.0% | 3 | 6 | 3 |  |
| 91 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 92 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 93 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 94 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 95 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `function_base_clip_removed` | 6.9s |  |
| 2 | `goto_methods` | 6.9s |  |
| 3 | `init_object_order` | 6.8s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 4 | `register_and_init_order` | 6.9s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 5 | `register_class` | 7.0s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 15.4s | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 15.1s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |

## All Output Mismatches

**274 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 2 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 3 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 4 | `conflicting_instance_names` | 95.7% | 22/23 | 23 | 23 |  |
| 5 | `globals_swf5` | 95.4% | 290/304 | 304 | 304 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `edittext_width_height` | 94.2% | 97/103 | 103 | 103 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 7 | `get_variable_in_scope` | 93.1% | 27/29 | 29 | 29 |  |
| 8 | `array_length` | 92.9% | 39/42 | 42 | 42 |  |
| 9 | `divide_swf4` | 88.8% | 95/107 | 107 | 107 |  |
| 10 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 11 | `textfield_variable` | 86.4% | 70/81 | 81 | 81 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 12 | `function_suppress_and_preload` | 85.7% | 24/28 | 28 | 28 |  |
| 13 | `swf4_function_calls` | 85.7% | 6/7 | 7 | 7 |  |
| 14 | `xml_to_string` | 84.6% | 11/13 | 13 | 13 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 15 | `object_prototypes` | 83.8% | 62/74 | 73 | 74 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `arguments` | 83.5% | 106/127 | 127 | 127 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 17 | `prototype_properties` | 82.4% | 14/17 | 17 | 17 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `local_to_global` | 81.6% | 40/49 | 49 | 49 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 19 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 20 | `stage_object_children` | 80.7% | 67/83 | 83 | 83 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 21 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 22 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 23 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 24 | `as2_oop` | 76.9% | 10/13 | 13 | 13 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `with` | 75.5% | 37/49 | 48 | 49 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 26 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 27 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 28 | `array_sort` | 73.9% | 119/161 | 161 | 161 |  |
| 29 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 30 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 31 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 32 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 33 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 34 | `transform` | 71.4% | 50/70 | 70 | 70 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 35 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 36 | `as_set_prop_flags` | 68.4% | 54/79 | 76 | 79 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 37 | `stage_object_properties` | 68.0% | 164/241 | 241 | 241 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 38 | `stage_object_properties_swf6` | 68.0% | 157/231 | 231 | 231 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 39 | `as_set_prop_flags_version` | 67.7% | 21/31 | 29 | 31 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 40 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 41 | `textfield_props_swf6` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 42 | `textfield_props_swf7` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 43 | `textfield_props_swf8` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 44 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 45 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 46 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 47 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 48 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 49 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 50 | `is_prototype_of` | 66.3% | 59/89 | 89 | 89 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `remove_movie_clip` | 65.5% | 19/29 | 29 | 29 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 52 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `movieclip_get_instance_at_depth` | 64.3% | 18/28 | 28 | 28 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 55 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 56 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 57 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 58 | `string_paths_hidden` | 63.0% | 34/54 | 54 | 54 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 59 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 60 | `color` | 61.4% | 35/57 | 57 | 57 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 61 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 62 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 63 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 64 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 65 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 66 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 67 | `execution_order1` | 60.0% | 3/5 | 5 | 5 |  |
| 68 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 69 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 70 | `primitive_type_globals` | 57.5% | 320/557 | 555 | 557 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 71 | `execution_order2` | 57.1% | 4/7 | 7 | 7 |  |
| 72 | `date` | 57.1% | 3617/6335 | 6335 | 6335 | [4](ruffle-tests/_investigation/DATE_PLAN.md) |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 74 | `asnative` | 55.9% | 19/34 | 31 | 34 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 75 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 76 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 77 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 78 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 79 | `clone_sprite_types` | 54.2% | 13/24 | 24 | 24 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 80 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 81 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 82 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 83 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 84 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 85 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 86 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 87 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 89 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 90 | `root_global_parent` | 50.0% | 3/6 | 6 | 6 |  |
| 91 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 92 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 93 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 94 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 95 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 96 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 97 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 98 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 99 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 100 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 101 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 102 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 103 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 104 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 105 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 106 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 107 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 108 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 109 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 110 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 111 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 112 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 113 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 114 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 116 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 117 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 118 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 119 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 120 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 121 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 122 | `enumerate` | 26.6% | 17/64 | 58 | 64 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 123 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 124 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 125 | `execution_order4` | 25.0% | 3/12 | 12 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 126 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 127 | `textfield_props_swf5` | 23.4% | 41/175 | 140 | 175 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 128 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 129 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 130 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 131 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 132 | `add_property` | 20.0% | 3/15 | 15 | 15 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 133 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 134 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 135 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 136 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 137 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 138 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 139 | `unload` | 15.4% | 8/52 | 48 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 140 | `watch` | 15.4% | 18/117 | 101 | 117 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 141 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 142 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 143 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 144 | `path_string` | 14.0% | 45/322 | 299 | 322 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 145 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 146 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 147 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 148 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 149 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 150 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 151 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 152 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 153 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 154 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 155 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 156 | `define_local` | 11.1% | 3/27 | 24 | 27 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 157 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 158 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 159 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 160 | `default_names` | 9.6% | 5/52 | 40 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 161 | `selection` | 9.3% | 42/454 | 244 | 454 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 162 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 163 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 164 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 165 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `super_edge_cases` | 8.1% | 8/99 | 99 | 39 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 167 | `instanceof_coercions` | 8.0% | 7/88 | 70 | 88 |  |
| 168 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 169 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 170 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 171 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 172 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 173 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 174 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 175 | `as2_super_and_this_v6` | 6.2% | 6/97 | 17 | 97 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 176 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 177 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 178 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 179 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 180 | `swf5_no_closure` | 5.3% | 1/19 | 11 | 19 |  |
| 181 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 182 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 183 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 184 | `this_scoping` | 3.8% | 2/52 | 37 | 52 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 185 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 186 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 187 | `as2_super_and_this_v8` | 2.4% | 2/85 | 9 | 85 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 188 | `clone_sprite_edittext` | 2.1% | 2/94 | 94 | 94 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 189 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 190 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 191 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 192 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 193 | `stage_property_representation` | 0.7% | 4/586 | 586 | 586 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 194 | `swf5_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 195 | `swf6_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 196 | `swf7_global_funcs` | 0.4% | 1/232 | 232 | 232 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 197 | `global_instance_decls` | 0.1% | 1/758 | 269 | 758 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 198 | `global_proto_decls` | 0.0% | 1/4497 | 203 | 4497 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 199 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
| 200 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 201 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 202 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 204 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 205 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 206 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 207 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 208 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 209 | `clone_sprite_edittext_dynamic` | 0.0% | 0/86 | 86 | 86 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 210 | `closure_scope` | 0.0% | 0/7 | 2 | 7 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 211 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 212 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 213 | `define_function2_preload_order` | 0.0% | 0/4 | 4 | 4 |  |
| 214 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 215 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 216 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 217 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 218 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 219 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 220 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 221 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 222 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 223 | `global_proto_decls_delete` | 0.0% | 0/4158 | 115 | 4158 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 224 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 225 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 226 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 227 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 228 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 229 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 230 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 231 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 232 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 234 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 235 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 236 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 237 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 238 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 239 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 240 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 241 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 242 | `native_objects_swf8` | 0.0% | 0/196 | 196 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 243 | `object_properties` | 0.0% | 0/31 | 0 | 31 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 244 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 245 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 246 | `parse_int` | 0.0% | 0/64 | 64 | 64 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 247 | `place_and_lookup` | 0.0% | 0/30 | 0 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 248 | `placeobject_occupied_depth` | 0.0% | 0/6 | 2 | 6 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 249 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 250 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 251 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 252 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 254 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 255 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 256 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 257 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 258 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 259 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 260 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 261 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 262 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 263 | `target_clip_removed` | 0.0% | 0/5 | 4 | 5 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 264 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 265 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 266 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 267 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 268 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 269 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 270 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 271 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 272 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 273 | `variable_args` | 0.0% | 0/5 | 5 | 5 |  |
| 274 | `watch_virtual_property_proto` | 0.0% | 0/2 | 0 | 2 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |

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
| 17 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) | 12 | 1 | 11 |
| 18 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 19 | [SELECTION_PLAN.md](ruffle-tests/_investigation/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 20 | [STAGE_PLAN.md](ruffle-tests/_investigation/STAGE_PLAN.md) | 7 | 1 | 6 |
| 21 | [string_coercion.md](ruffle-tests/_investigation/string_coercion.md) | 1 | 1 | 0 |
| 22 | [STRING_PLAN.md](ruffle-tests/_investigation/STRING_PLAN.md) | 13 | 4 | 9 |
| 23 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 24 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) | 70 | 15 | 55 |
| 25 | [this_swf7.md](ruffle-tests/_investigation/this_swf7.md) | 1 | 1 | 0 |
| 26 | [TIMER_PLAN.md](ruffle-tests/_investigation/TIMER_PLAN.md) | 3 | 0 | 3 |
| 27 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) | 5 | 4 | 1 |
| 28 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 29 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 30 | [XML_PLAN.md](ruffle-tests/_investigation/XML_PLAN.md) | 33 | 23 | 10 |
| | *(tests not in any document)* | 215 | 129 | 86 |
