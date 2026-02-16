# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-16 02:19 UTC

**Git SHA**: `95429be6ac`

**Run Duration**: 51m 23s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **210** (33.9%) |
| Failing | 409 |
| Total expected lines | 91294 |
| Matching lines | 42750 (46.8%) |
| Mismatched lines | 48544 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 397 | 97.1% |
| Runtime Segfault | 10 | 2.4% |
| Timeout | 2 | 0.5% |

## Passing Tests

**210 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 4.9s |  |
| 2 | `action_to_integer` | 28 | 4.7s |  |
| 3 | `add` | 28 | 4.7s |  |
| 4 | `add2` | 354 | 5.0s | [1](ruffle-tests/_investigation/add2.md) |
| 5 | `add_swf4` | 28 | 4.2s |  |
| 6 | `add_swf5` | 28 | 4.2s |  |
| 7 | `array_concat` | 98 | 4.8s |  |
| 8 | `array_constructor` | 30 | 4.8s |  |
| 9 | `array_enumerate` | 4 | 4.7s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 10 | `array_length` | 42 | 4.3s |  |
| 11 | `array_properties` | 36 | 4.7s |  |
| 12 | `array_slice` | 34 | 4.8s |  |
| 13 | `array_splice` | 207 | 4.9s |  |
| 14 | `array_trivial` | 209 | 4.4s |  |
| 15 | `as1_constructor_v6` | 35 | 4.3s |  |
| 16 | `as1_constructor_v7` | 35 | 4.2s |  |
| 17 | `as_broadcaster_initialize` | 10 | 4.7s |  |
| 18 | `as_set_prop_flags_version` | 31 | 4.7s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 19 | `as_set_prop_flags_version_swf5` | 1 | 4.2s |  |
| 20 | `as_set_prop_flags_version_swf6` | 1 | 4.3s |  |
| 21 | `as_set_prop_flags_version_swf7` | 1 | 4.3s |  |
| 22 | `as_set_prop_flags_version_swf8` | 1 | 4.7s |  |
| 23 | `as_set_prop_flags_version_swf9` | 1 | 4.7s |  |
| 24 | `as_transformed_flag` | 20 | 4.8s |  |
| 25 | `bad_swf_tag_past_eof` | 0 | 4.7s |  |
| 26 | `bitand` | 1058 | 6.8s |  |
| 27 | `bitmap_data_colortransform` | 0 | 5.0s |  |
| 28 | `bitmap_data_fillrect` | 0 | 4.9s |  |
| 29 | `bitmap_data_max_size_swf10` | 12 | 4.8s |  |
| 30 | `bitmap_data_max_size_swf9` | 10 | 4.7s |  |
| 31 | `bitmap_data_perlinnoise` | 0 | 5.4s |  |
| 32 | `bitmap_data_pixeldissolve_image` | 0 | 5.1s |  |
| 33 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.8s |  |
| 34 | `bitor` | 1058 | 6.8s |  |
| 35 | `biturshift` | 14 | 6.8s |  |
| 36 | `biturshift_swf8` | 14 | 4.8s |  |
| 37 | `bitxor` | 1058 | 7.0s |  |
| 38 | `call_method_empty_name` | 1 | 4.9s |  |
| 39 | `capabilities_resolution` | 8 | 4.9s |  |
| 40 | `catch_references_registers` | 2 | 5.0s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 41 | `conflicting_instance_names` | 23 | 5.0s |  |
| 42 | `define_function2` | 8 | 5.0s |  |
| 43 | `define_function2_preload` | 13 | 4.8s |  |
| 44 | `define_function2_preload_order` | 4 | 4.4s |  |
| 45 | `define_function_case_sensitive` | 2 | 4.8s |  |
| 46 | `delete` | 3 | 4.4s |  |
| 47 | `display_object_properties` | 2 | 4.8s |  |
| 48 | `do_init_action` | 3 | 4.8s |  |
| 49 | `edittext_antialiastype` | 296 | 6.1s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 50 | `edittext_autosize_setter` | 20 | 4.4s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 51 | `edittext_default_format` | 221 | 5.0s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 52 | `edittext_default_format_empty` | 95 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 53 | `edittext_default_format_font_style` | 335 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 54 | `edittext_password` | 5 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 55 | `equals` | 32 | 4.8s |  |
| 56 | `equals2_swf5` | 926 | 6.1s |  |
| 57 | `equals2_swf6` | 926 | 6.2s |  |
| 58 | `equals2_swf7` | 926 | 6.1s |  |
| 59 | `equals_swf4` | 665 | 4.7s |  |
| 60 | `equals_swf4_alt` | 32 | 4.3s |  |
| 61 | `equals_swf5` | 32 | 4.3s |  |
| 62 | `error` | 58 | 4.8s |  |
| 63 | `escape` | 14 | 4.8s |  |
| 64 | `execution_order1` | 5 | 4.9s |  |
| 65 | `execution_order2` | 7 | 4.9s |  |
| 66 | `execution_order3` | 4 | 4.8s |  |
| 67 | `focusrect_mouse_swf8` | 0 | 4.8s |  |
| 68 | `focusrect_mouse_swf9` | 0 | 4.8s |  |
| 69 | `focusrect_swf5` | 6 | 4.4s |  |
| 70 | `get_variable_in_scope` | 29 | 4.9s |  |
| 71 | `getproperty` | 28 | 4.8s |  |
| 72 | `getproperty_swf4` | 28 | 4.4s |  |
| 73 | `getproperty_swf5` | 28 | 4.3s |  |
| 74 | `global_array` | 3 | 4.8s |  |
| 75 | `global_is_bare` | 7 | 4.8s |  |
| 76 | `globals_swf6` | 304 | 4.6s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 77 | `globals_swf7` | 304 | 4.6s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 78 | `globals_swf8` | 304 | 5.2s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 79 | `goto_advance1` | 6 | 4.9s |  |
| 80 | `goto_advance2` | 2 | 4.9s |  |
| 81 | `goto_both_ways1` | 3 | 4.6s |  |
| 82 | `goto_both_ways2` | 3 | 4.4s |  |
| 83 | `goto_execution_order` | 2 | 4.9s |  |
| 84 | `goto_execution_order2` | 2 | 4.9s |  |
| 85 | `goto_frame_number` | 3 | 5.0s |  |
| 86 | `goto_rewind1` | 1 | 5.0s |  |
| 87 | `goto_rewind2` | 3 | 5.0s |  |
| 88 | `goto_rewind3` | 2 | 4.4s |  |
| 89 | `greater_swf6` | 1175 | 6.5s |  |
| 90 | `greater_swf7` | 1175 | 6.6s |  |
| 91 | `greaterthan_swf5` | 1 | 4.3s |  |
| 92 | `greaterthan_swf8` | 1 | 4.8s |  |
| 93 | `has_own_property` | 32 | 4.4s |  |
| 94 | `infinite_recursion_function` | 4 | 4.8s | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 95 | `init_array_invalid` | 4 | 4.8s |  |
| 96 | `init_object_invalid` | 4 | 4.8s |  |
| 97 | `is_finite` | 49 | 4.8s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 98 | `is_finite_swf6` | 49 | 4.4s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 99 | `is_prototype_of` | 89 | 4.4s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 100 | `issue_1086` | 1 | 4.3s |  |
| 101 | `issue_1671` | 0 | 4.8s |  |
| 102 | `issue_2166` | 9 | 4.3s |  |
| 103 | `issue_3446` | 1 | 4.8s |  |
| 104 | `issue_4377` | 2 | 4.8s |  |
| 105 | `issue_710` | 4 | 4.3s |  |
| 106 | `issue_768` | 3 | 4.8s | [9](ruffle-tests/_investigation/issue_768.md) |
| 107 | `lessthan` | 41 | 4.8s |  |
| 108 | `lessthan2_swf5` | 1226 | 6.4s |  |
| 109 | `lessthan2_swf6` | 1226 | 6.5s |  |
| 110 | `lessthan2_swf7` | 1226 | 6.5s |  |
| 111 | `lessthan_swf4` | 902 | 5.0s |  |
| 112 | `lessthan_swf4_alt` | 41 | 4.3s |  |
| 113 | `lessthan_swf5` | 41 | 4.4s |  |
| 114 | `logical_ops_swf4` | 90 | 4.3s |  |
| 115 | `logical_ops_swf8` | 108 | 4.9s |  |
| 116 | `looping` | 6 | 4.8s |  |
| 117 | `mask_reapply` | 0 | 4.8s |  |
| 118 | `mask_with_drawing` | 0 | 4.8s |  |
| 119 | `math_min_max` | 101 | 4.9s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 120 | `matrix` | 171 | 5.1s | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 121 | `mouse_wheel_enabled` | 2 | 4.8s |  |
| 122 | `movieclip_begin_gradient_fill` | 0 | 5.3s |  |
| 123 | `movieclip_blend_mode_property` | 35 | 4.9s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 124 | `movieclip_default_state` | 69 | 5.1s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 125 | `movieclip_line_gradient_style` | 0 | 5.2s |  |
| 126 | `movieclip_name_from_timeline` | 13 | 4.7s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 127 | `movieclip_prototype_extension` | 5 | 4.3s |  |
| 128 | `nested_textfields_in_buttons` | 0 | 4.7s |  |
| 129 | `netstream_play_flv_screen` | 0 | 17.4s |  |
| 130 | `new_method_wrap` | 4 | 4.7s |  |
| 131 | `new_object_enumerate` | 7 | 4.7s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 132 | `new_object_wrap` | 4 | 4.7s |  |
| 133 | `o` | 3 | 4.7s |  |
| 134 | `object_constructor` | 33 | 4.7s |  |
| 135 | `object_function` | 32 | 4.8s |  |
| 136 | `object_properties` | 31 | 4.9s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 137 | `object_string_coerce_swf5` | 62 | 4.3s | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 138 | `point` | 175 | 5.1s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 139 | `prototype_delete` | 12 | 4.8s |  |
| 140 | `prototype_enumerate` | 5 | 4.3s | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 141 | `rectangle` | 745 | 5.5s | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 142 | `recursive_prototypes` | 0 | 4.3s |  |
| 143 | `sandbox_type_local_file` | 1 | 4.4s |  |
| 144 | `set_variable_scope` | 58 | 4.8s |  |
| 145 | `single_frame` | 1 | 4.8s |  |
| 146 | `sound_start_load` | 0 | 4.8s |  |
| 147 | `stage_object_properties_get_var` | 5 | 4.8s |  |
| 148 | `strictequals_swf6` | 902 | 5.9s |  |
| 149 | `strictly_equals` | 7 | 4.8s |  |
| 150 | `string_coercion` | 117 | 4.6s | [21](ruffle-tests/_investigation/string_coercion.md) |
| 151 | `string_methods` | 285 | 5.3s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 152 | `string_methods_negative_args` | 240 | 4.4s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 153 | `string_methods_swfv5` | 275 | 4.8s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 154 | `string_ops_swf6` | 95 | 4.9s | [22](ruffle-tests/_investigation/STRING_PLAN.md) |
| 155 | `string_paths_keyevents` | 0 | 4.8s |  |
| 156 | `string_paths_timer` | 0 | 4.8s |  |
| 157 | `swf4_actions_bool` | 96 | 4.3s |  |
| 158 | `swf4_bool` | 4 | 4.3s |  |
| 159 | `swf5_encoding` | 3 | 4.3s |  |
| 160 | `swf7_case_sensitive` | 44 | 4.3s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 161 | `tab_ordering_properties_tab_index_edge_case` | 4 | 4.8s |  |
| 162 | `text_format` | 1146 | 5.0s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 163 | `text_format_display` | 21 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 164 | `text_format_font_max_length` | 2 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 165 | `text_format_rounding_swf7` | 840 | 4.5s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 166 | `text_format_rounding_swf8` | 840 | 4.9s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 167 | `textfield_background_color` | 11 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 168 | `textfield_border_color` | 11 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 169 | `textfield_maxchars` | 3 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 170 | `textfield_properties` | 44 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 171 | `textfield_text` | 7 | 4.8s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 172 | `textfield_variable` | 81 | 4.5s | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 173 | `this_swf7` | 41 | 4.3s | [25](ruffle-tests/_investigation/this_swf7.md) |
| 174 | `timeline_function_def` | 7 | 4.4s |  |
| 175 | `try_finally_simple` | 16 | 5.1s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 176 | `typeof` | 22 | 5.1s |  |
| 177 | `typeof_globals` | 7 | 4.4s |  |
| 178 | `uncaught_exception` | 1 | 5.0s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 179 | `uncaught_exception_bubbled` | 1 | 5.0s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |
| 180 | `undefined_to_string_swf6` | 4 | 4.5s |  |
| 181 | `unescape` | 43 | 5.0s |  |
| 182 | `use_hand_cursor` | 8 | 4.9s |  |
| 183 | `variable_args` | 5 | 4.6s |  |
| 184 | `waitforframe` | 7 | 4.5s |  |
| 185 | `waitforframe2` | 16 | 4.6s |  |
| 186 | `with_return` | 2 | 4.9s |  |
| 187 | `with_variable_scopes` | 43 | 5.0s | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 188 | `xml` | 15 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 189 | `xml_append_child` | 28 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 190 | `xml_append_child_with_parent` | 20 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 191 | `xml_cdata` | 11 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 192 | `xml_clone_expandos` | 19 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 193 | `xml_first_last_child` | 8 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 194 | `xml_has_child_nodes` | 3 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 195 | `xml_idmap` | 21 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 196 | `xml_ignore_comments` | 21 | 4.9s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 197 | `xml_ignore_white` | 34 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 198 | `xml_insert_before` | 20 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 199 | `xml_inspect_createmethods` | 15 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 200 | `xml_inspect_doctype` | 7 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 201 | `xml_inspect_parsexml` | 62 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 202 | `xml_inspect_xmldecl` | 7 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 203 | `xml_namespaces` | 203 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 204 | `xml_parent_and_child` | 5 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 205 | `xml_remove_node` | 22 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 206 | `xml_reparenting` | 14 | 4.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 207 | `xml_siblings` | 10 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 208 | `xml_to_string_comment` | 1 | 4.5s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 209 | `xml_unescaping` | 23 | 4.6s | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 210 | `xmlnode_proto` | 1 | 5.0s | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**101 tests** within reach

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
| 19 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 20 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `movieclip_depth_methods` | 77.6% | 76 | 98 | 22 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 23 | `as2_oop` | 76.9% | 10 | 13 | 3 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 25 | `xml_child_nodes_edge_cases` | 75.0% | 3 | 4 | 1 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 26 | `array_sort` | 73.9% | 119 | 161 | 42 |  |
| 27 | `add_property` | 73.3% | 11 | 15 | 4 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `attach_movie` | 72.9% | 43 | 59 | 16 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 30 | `extends_native_type` | 72.7% | 8 | 11 | 3 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 31 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 32 | `stage_object_properties_swf6` | 71.9% | 166 | 231 | 65 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 33 | `stage_object_properties` | 71.8% | 173 | 241 | 68 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 34 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 35 | `transform` | 71.4% | 50 | 70 | 20 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 36 | `register_underflow` | 69.2% | 18 | 26 | 8 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 37 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 38 | `textfield_props_swf6` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 39 | `textfield_props_swf7` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 40 | `textfield_props_swf8` | 67.6% | 142 | 210 | 68 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 41 | `array_prototyping` | 66.7% | 8 | 12 | 4 |  |
| 42 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 43 | `export_assets` | 66.7% | 2 | 3 | 1 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 44 | `frame_size_translated_negative` | 66.7% | 14 | 21 | 7 |  |
| 45 | `frame_size_translated_positive` | 66.7% | 14 | 21 | 7 |  |
| 46 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 47 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
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
| 63 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 64 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 65 | `this_scoping` | 59.3% | 32 | 54 | 22 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 66 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 67 | `boxed_primitives` | 58.3% | 14 | 24 | 10 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 68 | `clone_sprite_types` | 58.3% | 14 | 24 | 10 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 69 | `parse_float` | 58.1% | 43 | 74 | 31 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 70 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 71 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 72 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 74 | `asnative` | 55.9% | 19 | 34 | 15 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 75 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 76 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 77 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 78 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 79 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 80 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 81 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 82 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 83 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 84 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 85 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 86 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 87 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 |  |
| 88 | `issue_1906` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 89 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 90 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 91 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 92 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 93 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 94 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 95 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 96 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 97 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 98 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 99 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 100 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 101 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |

## Segfaults

**10 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `date` | 8.2s | [4](ruffle-tests/_investigation/DATE_PLAN.md) |
| 2 | `function_as_function` | 6.9s |  |
| 3 | `function_base_clip_removed` | 6.8s |  |
| 4 | `get_bytes_total` | 6.7s |  |
| 5 | `goto_methods` | 7.2s |  |
| 6 | `init_object_order` | 6.9s | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `primitive_instanceof` | 6.8s |  |
| 8 | `primitive_type_globals` | 7.0s | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 9 | `register_and_init_order` | 7.2s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 10 | `register_class` | 6.8s | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 15.4s | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 2 | `try_catch_finally` | runtime timeout (>10s) | 15.2s | [27](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) |

## All Output Mismatches

**397 tests** with output mismatch, sorted by match rate (best first)

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
| 19 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 20 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `movieclip_depth_methods` | 77.6% | 76/98 | 98 | 98 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 23 | `as2_oop` | 76.9% | 10/13 | 13 | 13 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 25 | `xml_child_nodes_edge_cases` | 75.0% | 3/4 | 4 | 4 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 26 | `array_sort` | 73.9% | 119/161 | 161 | 161 |  |
| 27 | `add_property` | 73.3% | 11/15 | 15 | 15 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 30 | `extends_native_type` | 72.7% | 8/11 | 11 | 11 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 31 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 32 | `stage_object_properties_swf6` | 71.9% | 166/231 | 231 | 231 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 33 | `stage_object_properties` | 71.8% | 173/241 | 241 | 241 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 34 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 35 | `transform` | 71.4% | 50/70 | 70 | 70 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 36 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 37 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [13](ruffle-tests/_investigation/object_string_coerce.md) |
| 38 | `textfield_props_swf6` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 39 | `textfield_props_swf7` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 40 | `textfield_props_swf8` | 67.6% | 142/210 | 210 | 210 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 41 | `array_prototyping` | 66.7% | 8/12 | 12 | 12 |  |
| 42 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 43 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 44 | `frame_size_translated_negative` | 66.7% | 14/21 | 20 | 21 |  |
| 45 | `frame_size_translated_positive` | 66.7% | 14/21 | 20 | 21 |  |
| 46 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 47 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
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
| 63 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 64 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 65 | `this_scoping` | 59.3% | 32/54 | 54 | 52 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 66 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 67 | `boxed_primitives` | 58.3% | 14/24 | 24 | 24 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 68 | `clone_sprite_types` | 58.3% | 14/24 | 24 | 24 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 69 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/PARSING_FUNCTIONS_PLAN.md) |
| 70 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 71 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 72 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 73 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 74 | `asnative` | 55.9% | 19/34 | 31 | 34 | [10](ruffle-tests/_investigation/MATH_PLAN.md) |
| 75 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 76 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 77 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 78 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 79 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 80 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 81 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 82 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 83 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 84 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 85 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 86 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 87 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 |  |
| 88 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 89 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 90 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 91 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 92 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 93 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 94 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 95 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 96 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 97 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 98 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 99 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 100 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 101 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 102 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 103 | `this_swf5` | 46.3% | 19/41 | 41 | 41 |  |
| 104 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 105 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 106 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 107 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 108 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 109 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 110 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 111 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 112 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 113 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 114 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 |  |
| 115 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 116 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 117 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 118 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 119 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 120 | `array_call_method` | 33.3% | 3/9 | 6 | 9 |  |
| 121 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 122 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 124 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 125 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 126 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 127 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 128 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 129 | `rewind_depth` | 30.0% | 9/30 | 30 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 130 | `enumerate` | 29.7% | 19/64 | 60 | 64 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) |
| 131 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 132 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 133 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 134 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 135 | `goto_frame` | 25.0% | 3/12 | 10 | 12 |  |
| 136 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 137 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 138 | `stage_object_enumerate` | 25.0% | 1/4 | 1 | 4 | [5](ruffle-tests/_investigation/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 139 | `textfield_props_swf5` | 23.4% | 41/175 | 140 | 175 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 140 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 141 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 142 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 |  |
| 143 | `default_names` | 21.2% | 11/52 | 40 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 144 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 145 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 146 | `duplicate_movie_clip` | 20.0% | 4/20 | 13 | 20 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 147 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 148 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 149 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 150 | `focusrect_property_swf5` | 19.2% | 238/1237 | 1236 | 1237 |  |
| 151 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 152 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 |  |
| 153 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 154 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 155 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 156 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 157 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 158 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 159 | `unload` | 15.4% | 8/52 | 48 | 52 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 160 | `watch` | 15.4% | 18/117 | 101 | 117 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 161 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 162 | `color_transform` | 14.6% | 7/48 | 37 | 48 | [3](ruffle-tests/_investigation/COLOR_OBJECT_PLAN.md) |
| 163 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 164 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 165 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 166 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 167 | `path_string` | 14.0% | 45/322 | 299 | 322 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 168 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 169 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 170 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 171 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 172 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 173 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 174 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 175 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 176 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [20](ruffle-tests/_investigation/STAGE_PLAN.md) |
| 177 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 178 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 179 | `external_interface_toxml_array` | 12.0% | 3/25 | 25 | 25 |  |
| 180 | `goto_label` | 11.8% | 2/17 | 11 | 17 |  |
| 181 | `watch_virtual_property` | 11.7% | 7/60 | 40 | 60 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 182 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 183 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 184 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 185 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 187 | `selection` | 9.3% | 42/454 | 244 | 454 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 188 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 189 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 190 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 191 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 192 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 193 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 194 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 195 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 196 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 197 | `define_local` | 7.4% | 2/27 | 23 | 27 | [29](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) |
| 198 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 199 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 200 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 201 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 202 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 203 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 204 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 205 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 206 | `bitmap_data` | 5.8% | 68/1174 | 1174 | 1126 |  |
| 207 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 208 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [26](ruffle-tests/_investigation/TIMER_PLAN.md) |
| 209 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 210 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 211 | `clip_events` | 5.3% | 1/19 | 5 | 19 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 212 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 213 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 214 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 215 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 216 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 217 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 218 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 219 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [19](ruffle-tests/_investigation/SELECTION_PLAN.md) |
| 220 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
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
| 240 | `global_proto_decls` | 0.1% | 6/4497 | 334 | 4497 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 241 | `global_instance_decls` | 0.1% | 1/758 | 280 | 758 | [6](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 242 | `array_sort_random` | 0.0% | 0/443 | 2 | 443 |  |
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
| 298 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 299 | `global_proto_decls_delete` | 0.0% | 0/4158 | 117 | 4158 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 300 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 301 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) |
| 302 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `infinite_recursion_function_in_setter` | 0.0% | 0/131 | 1 | 131 | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 304 | `infinite_recursion_virtual_property` | 0.0% | 0/67 | 2 | 67 | [8](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 305 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 306 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [15](ruffle-tests/_investigation/OOP_SUPER_EXTENDS_PLAN.md) |
| 307 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 309 | `issue_2870` | 0.0% | 0/3 | 0 | 3 |  |
| 310 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 311 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 312 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 313 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 314 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 315 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 316 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 317 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 318 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 319 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 320 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 321 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 322 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 323 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 324 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 325 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 326 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 327 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 328 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 329 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 330 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 331 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 332 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 333 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 334 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 |  |
| 336 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 |  |
| 337 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 338 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 339 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 340 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 342 | `native_objects_swf6` | 0.0% | 0/186 | 186 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 343 | `native_objects_swf7` | 0.0% | 0/186 | 186 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 344 | `native_objects_swf8` | 0.0% | 0/196 | 196 | 84 | [7](ruffle-tests/_investigation/GLOBALS_PLAN.md) [12](ruffle-tests/_investigation/NATIVE_INTROSPECTION_PLAN.md) |
| 345 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 346 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 347 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 348 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [17](ruffle-tests/_investigation/PROTOTYPE_OBJECT_PLAN.md) |
| 349 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [2](ruffle-tests/_investigation/CLONE_DUPLICATE_PLAN.md) [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 350 | `place_and_lookup` | 0.0% | 0/30 | 21 | 30 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 351 | `placeobject_occupied_depth` | 0.0% | 0/6 | 5 | 6 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) |
| 352 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [18](ruffle-tests/_investigation/REGISTERCLASS_PLAN.md) |
| 353 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 354 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 355 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 357 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 358 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 359 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 360 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 361 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 362 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 363 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 364 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 365 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 366 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/STRING_PLAN.md) [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 367 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 368 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 369 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 370 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 371 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 372 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 373 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 374 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 375 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 376 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 377 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 378 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 379 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 380 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 381 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 382 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 383 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 384 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 385 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 386 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 387 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [23](ruffle-tests/_investigation/TELLTARGET_PLAN.md) |
| 388 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 |  |
| 389 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 390 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [24](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) |
| 391 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 392 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [11](ruffle-tests/_investigation/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/UNLOAD_PLAN.md) |
| 393 | `watch_virtual_property_proto` | 0.0% | 0/2 | 1 | 2 | [14](ruffle-tests/_investigation/OBJECT_WATCH_PLAN.md) |
| 394 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 395 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 396 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [30](ruffle-tests/_investigation/XML_PLAN.md) |
| 397 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [30](ruffle-tests/_investigation/XML_PLAN.md) |

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
| 8 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 1 | 2 |
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
| 24 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/TEXTFIELD_PLAN.md) | 70 | 17 | 53 |
| 25 | [this_swf7.md](ruffle-tests/_investigation/this_swf7.md) | 1 | 1 | 0 |
| 26 | [TIMER_PLAN.md](ruffle-tests/_investigation/TIMER_PLAN.md) | 3 | 0 | 3 |
| 27 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/TRY_CATCH_FINALLY_PLAN.md) | 5 | 4 | 1 |
| 28 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 29 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 30 | [XML_PLAN.md](ruffle-tests/_investigation/XML_PLAN.md) | 33 | 23 | 10 |
| | *(tests not in any document)* | 326 | 136 | 190 |
