# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-19 22:50 UTC

**Git SHA**: `1ce1d3956e`

**Run Duration**: 69m 48s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **242** (39.1%) |
| Failing | 377 |
| Total expected lines | 91478 |
| Matching lines | 52097 (57.0%) |
| Mismatched lines | 39381 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 374 | 99.2% |
| Runtime Segfault | 2 | 0.5% |
| Timeout | 1 | 0.3% |

## Passing Tests

**242 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.1s |  |
| 2 | `action_to_integer` | 28 | 6.6s |  |
| 3 | `add` | 28 | 6.6s |  |
| 4 | `add2` | 354 | 6.8s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 6.5s |  |
| 6 | `add_swf5` | 28 | 6.5s |  |
| 7 | `arguments` | 127 | 6.6s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 6.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 6.6s |  |
| 10 | `array_constructor` | 30 | 6.6s |  |
| 11 | `array_enumerate` | 4 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 6.6s |  |
| 13 | `array_properties` | 36 | 6.5s |  |
| 14 | `array_prototyping` | 12 | 6.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 6.6s |  |
| 16 | `array_sort_random` | 443 | 6.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 6.8s |  |
| 18 | `array_trivial` | 209 | 6.7s |  |
| 19 | `as1_constructor_v6` | 35 | 6.5s |  |
| 20 | `as1_constructor_v7` | 35 | 6.6s |  |
| 21 | `as2_oop` | 13 | 6.7s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 6.5s |  |
| 23 | `as_set_prop_flags_version` | 31 | 6.6s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 6.6s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 6.6s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 6.6s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 6.7s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 6.6s |  |
| 29 | `as_transformed_flag` | 20 | 6.6s |  |
| 30 | `bad_swf_tag_past_eof` | 0 | 6.5s |  |
| 31 | `bitand` | 1058 | 9.2s |  |
| 32 | `bitmap_data_colortransform` | 0 | 6.8s |  |
| 33 | `bitmap_data_fillrect` | 0 | 6.7s |  |
| 34 | `bitmap_data_max_size_swf10` | 12 | 6.5s |  |
| 35 | `bitmap_data_max_size_swf9` | 10 | 6.5s |  |
| 36 | `bitmap_data_perlinnoise` | 0 | 7.1s |  |
| 37 | `bitmap_data_pixeldissolve_image` | 0 | 6.9s |  |
| 38 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.6s |  |
| 39 | `bitor` | 1058 | 9.2s |  |
| 40 | `biturshift` | 14 | 8.0s |  |
| 41 | `biturshift_swf8` | 14 | 6.5s |  |
| 42 | `bitxor` | 1058 | 8.9s |  |
| 43 | `call_method_empty_name` | 1 | 6.5s |  |
| 44 | `capabilities_resolution` | 8 | 6.4s |  |
| 45 | `catch_references_registers` | 2 | 6.4s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 46 | `clone_sprite_types` | 24 | 6.6s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `color` | 57 | 6.8s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 48 | `color_transform` | 48 | 6.6s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 49 | `conflicting_instance_names` | 23 | 6.6s |  |
| 50 | `define_function2` | 8 | 6.6s |  |
| 51 | `define_function2_preload` | 13 | 6.7s |  |
| 52 | `define_function2_preload_order` | 4 | 6.7s |  |
| 53 | `define_function_case_sensitive` | 2 | 6.7s |  |
| 54 | `delete` | 3 | 6.6s |  |
| 55 | `display_object_properties` | 2 | 6.8s |  |
| 56 | `divide_swf4` | 107 | 6.7s |  |
| 57 | `do_init_action` | 3 | 6.7s |  |
| 58 | `duplicate_movie_clip` | 20 | 6.6s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 59 | `edittext_antialiastype` | 296 | 7.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_autosize_setter` | 20 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_default_format` | 221 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_default_format_empty` | 95 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_default_format_font_style` | 335 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_password` | 5 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_width_height` | 103 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `enumerate` | 64 | 6.4s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 67 | `equals` | 32 | 6.4s |  |
| 68 | `equals2_swf5` | 926 | 8.1s |  |
| 69 | `equals2_swf6` | 926 | 8.1s |  |
| 70 | `equals2_swf7` | 926 | 8.2s |  |
| 71 | `equals_swf4` | 665 | 6.8s |  |
| 72 | `equals_swf4_alt` | 32 | 6.4s |  |
| 73 | `equals_swf5` | 32 | 6.5s |  |
| 74 | `error` | 58 | 6.5s |  |
| 75 | `escape` | 14 | 6.4s |  |
| 76 | `execution_order1` | 5 | 6.5s |  |
| 77 | `execution_order2` | 7 | 6.5s |  |
| 78 | `execution_order3` | 4 | 6.5s |  |
| 79 | `focusrect_mouse_swf8` | 0 | 6.4s |  |
| 80 | `focusrect_mouse_swf9` | 0 | 6.5s |  |
| 81 | `focusrect_swf5` | 6 | 6.6s |  |
| 82 | `function_suppress_and_preload` | 28 | 6.5s |  |
| 83 | `get_variable_in_scope` | 29 | 6.5s |  |
| 84 | `getproperty` | 28 | 6.4s |  |
| 85 | `getproperty_swf4` | 28 | 6.4s |  |
| 86 | `getproperty_swf5` | 28 | 6.5s |  |
| 87 | `global_array` | 3 | 6.5s |  |
| 88 | `global_is_bare` | 7 | 6.5s |  |
| 89 | `globals_swf5` | 304 | 6.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 90 | `globals_swf6` | 304 | 6.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 91 | `globals_swf7` | 304 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 92 | `globals_swf8` | 304 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 93 | `goto_advance1` | 6 | 6.5s |  |
| 94 | `goto_advance2` | 2 | 6.5s |  |
| 95 | `goto_both_ways1` | 3 | 7.5s |  |
| 96 | `goto_both_ways2` | 3 | 6.6s |  |
| 97 | `goto_execution_order` | 2 | 6.4s |  |
| 98 | `goto_execution_order2` | 2 | 6.5s |  |
| 99 | `goto_frame_number` | 3 | 6.5s |  |
| 100 | `goto_rewind1` | 1 | 6.7s |  |
| 101 | `goto_rewind2` | 3 | 6.5s |  |
| 102 | `goto_rewind3` | 2 | 6.5s |  |
| 103 | `greater_swf6` | 1175 | 8.4s |  |
| 104 | `greater_swf7` | 1175 | 8.4s |  |
| 105 | `greaterthan_swf5` | 1 | 6.5s |  |
| 106 | `greaterthan_swf8` | 1 | 6.4s |  |
| 107 | `has_own_property` | 32 | 6.5s |  |
| 108 | `infinite_recursion_function` | 4 | 6.4s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 109 | `infinite_recursion_function_in_setter` | 131 | 6.4s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 110 | `infinite_recursion_virtual_property` | 67 | 6.4s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 111 | `init_array_invalid` | 4 | 6.4s |  |
| 112 | `init_object_invalid` | 4 | 6.4s |  |
| 113 | `is_finite` | 49 | 6.5s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 114 | `is_finite_swf6` | 49 | 6.5s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 115 | `is_prototype_of` | 89 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 116 | `issue_1086` | 1 | 6.4s |  |
| 117 | `issue_1671` | 0 | 6.4s |  |
| 118 | `issue_2166` | 9 | 6.5s |  |
| 119 | `issue_3446` | 1 | 6.5s |  |
| 120 | `issue_4377` | 2 | 6.4s |  |
| 121 | `issue_710` | 4 | 6.4s |  |
| 122 | `issue_768` | 3 | 6.4s | [12](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 123 | `lessthan` | 41 | 6.5s |  |
| 124 | `lessthan2_swf5` | 1226 | 8.5s |  |
| 125 | `lessthan2_swf6` | 1226 | 8.5s |  |
| 126 | `lessthan2_swf7` | 1226 | 8.5s |  |
| 127 | `lessthan_swf4` | 902 | 7.1s |  |
| 128 | `lessthan_swf4_alt` | 41 | 6.5s |  |
| 129 | `lessthan_swf5` | 41 | 6.5s |  |
| 130 | `logical_ops_swf4` | 90 | 6.6s |  |
| 131 | `logical_ops_swf8` | 108 | 6.7s |  |
| 132 | `looping` | 6 | 6.5s |  |
| 133 | `mask_reapply` | 0 | 6.5s |  |
| 134 | `mask_with_drawing` | 0 | 6.6s |  |
| 135 | `math_min_max` | 101 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 136 | `matrix` | 171 | 6.8s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 137 | `mouse_wheel_enabled` | 2 | 6.5s |  |
| 138 | `movieclip_begin_gradient_fill` | 0 | 7.0s |  |
| 139 | `movieclip_blend_mode_property` | 35 | 6.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 140 | `movieclip_get_instance_at_depth` | 28 | 6.5s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 141 | `movieclip_line_gradient_style` | 0 | 7.0s |  |
| 142 | `movieclip_name_from_timeline` | 13 | 6.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 143 | `movieclip_prototype_extension` | 5 | 6.5s |  |
| 144 | `nested_textfields_in_buttons` | 0 | 6.5s |  |
| 145 | `netstream_play_flv_screen` | 0 | 19.6s |  |
| 146 | `new_method_wrap` | 4 | 6.7s |  |
| 147 | `new_object_enumerate` | 7 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 148 | `new_object_wrap` | 4 | 6.5s |  |
| 149 | `o` | 3 | 6.5s |  |
| 150 | `object_constructor` | 33 | 6.6s |  |
| 151 | `object_function` | 32 | 6.7s |  |
| 152 | `object_properties` | 31 | 7.0s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 153 | `object_prototypes` | 74 | 6.9s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 154 | `object_string_coerce_swf5` | 62 | 6.8s | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 155 | `parse_int` | 64 | 6.8s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 156 | `point` | 175 | 6.8s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 157 | `primitive_instanceof` | 37 | 6.5s |  |
| 158 | `primitive_type_globals` | 557 | 6.6s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 159 | `prototype_delete` | 12 | 6.5s |  |
| 160 | `prototype_enumerate` | 5 | 6.5s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 161 | `prototype_properties` | 17 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 162 | `rectangle` | 745 | 7.4s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 163 | `recursive_prototypes` | 0 | 6.7s |  |
| 164 | `sandbox_type_local_file` | 1 | 6.4s |  |
| 165 | `set_variable_scope` | 58 | 6.4s |  |
| 166 | `single_frame` | 1 | 6.4s |  |
| 167 | `sound_start_load` | 0 | 6.4s |  |
| 168 | `stage_object_enumerate` | 4 | 6.4s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 169 | `stage_object_properties_get_var` | 5 | 6.4s |  |
| 170 | `stage_property_representation` | 586 | 6.5s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 171 | `strictequals_swf6` | 902 | 8.0s |  |
| 172 | `strictly_equals` | 7 | 6.5s |  |
| 173 | `string_coercion` | 117 | 6.7s | [25](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 174 | `string_methods` | 285 | 7.0s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 175 | `string_methods_negative_args` | 240 | 6.5s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 176 | `string_methods_swfv5` | 275 | 6.9s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 177 | `string_ops_swf6` | 95 | 6.5s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 178 | `string_paths_keyevents` | 0 | 6.4s |  |
| 179 | `string_paths_timer` | 0 | 6.5s |  |
| 180 | `swf4_actions_bool` | 96 | 6.4s |  |
| 181 | `swf4_bool` | 4 | 6.4s |  |
| 182 | `swf4_function_calls` | 7 | 8.3s |  |
| 183 | `swf5_encoding` | 3 | 6.3s |  |
| 184 | `swf7_case_sensitive` | 44 | 6.3s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 185 | `tab_ordering_properties_tab_index_edge_case` | 4 | 6.3s |  |
| 186 | `text_format` | 1146 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 187 | `text_format_display` | 21 | 6.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 188 | `text_format_font_max_length` | 2 | 6.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 189 | `text_format_rounding_swf7` | 840 | 6.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 190 | `text_format_rounding_swf8` | 840 | 6.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 191 | `textfield_background_color` | 11 | 6.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 192 | `textfield_border_color` | 11 | 6.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 193 | `textfield_maxchars` | 3 | 6.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 194 | `textfield_properties` | 44 | 6.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 195 | `textfield_props_swf6` | 210 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 196 | `textfield_props_swf7` | 210 | 6.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 197 | `textfield_props_swf8` | 210 | 6.5s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 198 | `textfield_text` | 7 | 6.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 199 | `this_swf7` | 41 | 6.5s | [29](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 200 | `timeline_function_def` | 7 | 6.6s |  |
| 201 | `transform` | 70 | 7.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 202 | `try_catch_finally` | 118 | 7.0s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 203 | `try_finally_simple` | 16 | 6.9s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 204 | `typeof` | 22 | 6.9s |  |
| 205 | `typeof_globals` | 7 | 6.8s |  |
| 206 | `uncaught_exception` | 1 | 6.8s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 207 | `uncaught_exception_bubbled` | 1 | 6.9s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 208 | `undefined_to_string_swf6` | 4 | 6.9s |  |
| 209 | `unescape` | 43 | 6.9s |  |
| 210 | `use_hand_cursor` | 8 | 6.6s |  |
| 211 | `variable_args` | 5 | 6.7s |  |
| 212 | `waitforframe` | 7 | 6.4s |  |
| 213 | `waitforframe2` | 16 | 6.5s |  |
| 214 | `watch` | 117 | 6.7s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 215 | `watch_virtual_property_proto` | 2 | 6.6s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 216 | `with_return` | 2 | 6.7s |  |
| 217 | `with_variable_scopes` | 43 | 6.9s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 218 | `xml` | 15 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 219 | `xml_append_child` | 28 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 220 | `xml_append_child_with_parent` | 20 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 221 | `xml_cdata` | 11 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 222 | `xml_child_nodes_edge_cases` | 4 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_clone_expandos` | 19 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xml_first_last_child` | 8 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 225 | `xml_has_child_nodes` | 3 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 226 | `xml_idmap` | 21 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 227 | `xml_ignore_comments` | 21 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 228 | `xml_ignore_white` | 34 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 229 | `xml_insert_before` | 20 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 230 | `xml_inspect_createmethods` | 15 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 231 | `xml_inspect_doctype` | 7 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 232 | `xml_inspect_parsexml` | 62 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 233 | `xml_inspect_xmldecl` | 7 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 234 | `xml_namespaces` | 203 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 235 | `xml_parent_and_child` | 5 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 236 | `xml_remove_node` | 22 | 7.0s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 237 | `xml_reparenting` | 14 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 238 | `xml_siblings` | 10 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 239 | `xml_to_string` | 13 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 240 | `xml_to_string_comment` | 1 | 6.5s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 241 | `xml_unescaping` | 23 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 242 | `xmlnode_proto` | 1 | 6.6s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**88 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `math_swf6` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf7` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `math_swf8` | 98.5% | 522 | 530 | 8 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 6 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 7 | `textfield_variable` | 96.3% | 78 | 81 | 3 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_depth_methods` | 95.9% | 94 | 98 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 9 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 10 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 11 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 12 | `with` | 93.9% | 46 | 49 | 3 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 13 | `stage_object_properties` | 93.4% | 225 | 241 | 16 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 14 | `stage_object_properties_swf6` | 91.8% | 212 | 231 | 19 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 15 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 16 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `edittext_html_align_swf8` | 86.5% | 45 | 52 | 7 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `local_to_global` | 83.7% | 41 | 49 | 8 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 19 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 20 | `edittext_html_align_swf7` | 80.8% | 42 | 52 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `this_scoping` | 80.8% | 42 | 52 | 10 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 22 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 24 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 26 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `add_property` | 73.3% | 11 | 15 | 4 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `attach_movie` | 72.9% | 43 | 59 | 16 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `remove_movie_clip` | 72.4% | 21 | 29 | 8 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 31 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 32 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 33 | `register_underflow` | 69.2% | 18 | 26 | 8 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 34 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 35 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 36 | `export_assets` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 38 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 39 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 40 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 43 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 44 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 47 | `edittext_align` | 60.0% | 36 | 60 | 24 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 55 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `parse_float` | 58.1% | 43 | 74 | 31 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 57 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 58 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 60 | `edittext_html_condensewhite_swf7` | 55.9% | 174 | 311 | 137 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `asnative` | 55.9% | 19 | 34 | 15 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 62 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 63 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 64 | `edittext_html_condensewhite_swf8` | 55.0% | 171 | 311 | 140 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 66 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 67 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 68 | `edittext_html_swf6` | 52.8% | 2838 | 5377 | 2539 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 70 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 71 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 72 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 73 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 75 | `issue_1906` | 50.0% | 2 | 4 | 2 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 76 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 77 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 78 | `issue_9885` | 50.0% | 1 | 2 | 1 |  |
| 79 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 80 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 81 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 82 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 83 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 84 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 85 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 88 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `clip_events` | 8.7s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 2 | `goto_methods` | 8.7s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 17.0s | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**374 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `math_swf6` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 4 | `math_swf7` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 5 | `math_swf8` | 98.5% | 522/530 | 529 | 530 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 6 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 7 | `textfield_variable` | 96.3% | 78/81 | 81 | 81 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_depth_methods` | 95.9% | 94/98 | 98 | 98 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 9 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 10 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 11 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 12 | `with` | 93.9% | 46/49 | 49 | 49 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 13 | `stage_object_properties` | 93.4% | 225/241 | 241 | 241 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 14 | `stage_object_properties_swf6` | 91.8% | 212/231 | 231 | 231 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 15 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 16 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `edittext_html_align_swf8` | 86.5% | 45/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 19 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 20 | `edittext_html_align_swf7` | 80.8% | 42/52 | 52 | 52 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 22 | `target_clip_removed` | 80.0% | 4/5 | 4 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 24 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 26 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `add_property` | 73.3% | 11/15 | 15 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `remove_movie_clip` | 72.4% | 21/29 | 29 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 31 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 32 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 33 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 34 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 35 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 36 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 38 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 39 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 40 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 43 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 44 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 47 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 55 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 57 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 58 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 59 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 60 | `edittext_html_condensewhite_swf7` | 55.9% | 174/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `asnative` | 55.9% | 19/34 | 31 | 34 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 62 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 63 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 64 | `edittext_html_condensewhite_swf8` | 55.0% | 171/311 | 311 | 311 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 66 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 67 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 68 | `edittext_html_swf6` | 52.8% | 2838/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 70 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 71 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 72 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 73 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 75 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 76 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 77 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 78 | `issue_9885` | 50.0% | 1/2 | 1 | 2 |  |
| 79 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 80 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 81 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 82 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 83 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 84 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 85 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 88 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 89 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 90 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 91 | `edittext_html_swf7` | 45.9% | 2466/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 94 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 95 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 96 | `edittext_html_swf8` | 43.1% | 2316/5377 | 5377 | 5377 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 98 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 99 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 14 | 17 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 100 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 101 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 102 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 103 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 104 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 105 | `edittext_newline_stripping` | 35.9% | 23/64 | 62 | 64 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 107 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 108 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 112 | `issue_2870` | 33.3% | 1/3 | 1 | 3 |  |
| 113 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 114 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 115 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 117 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 118 | `asnew` | 29.4% | 10/34 | 19 | 34 |  |
| 119 | `default_names` | 28.8% | 15/52 | 40 | 52 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 120 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 121 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 122 | `unload` | 26.9% | 14/52 | 48 | 52 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 123 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 124 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 125 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 126 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 127 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 128 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 129 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 130 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 131 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 132 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 134 | `focusrect_property_swf5` | 21.7% | 269/1237 | 1236 | 1237 |  |
| 135 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 136 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 137 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 138 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 139 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 140 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 141 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 142 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 143 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 144 | `super_edge_cases` | 17.9% | 7/39 | 34 | 39 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 145 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 146 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 147 | `execution_order4` | 16.7% | 2/12 | 12 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 148 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 149 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 150 | `path_string` | 15.2% | 49/322 | 300 | 322 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 151 | `instanceof_coercions` | 14.8% | 13/88 | 71 | 88 |  |
| 152 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 153 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 154 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 155 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 156 | `register_and_init_order` | 13.4% | 31/231 | 73 | 231 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 157 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 158 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 159 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 160 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 161 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 162 | `button_children` | 12.5% | 1/8 | 2 | 8 |  |
| 163 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 164 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 165 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 166 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 167 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 168 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 169 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 170 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 171 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 172 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 175 | `selection` | 9.3% | 42/454 | 244 | 454 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 176 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 177 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 178 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 179 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 180 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 181 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 182 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 184 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 185 | `define_local` | 7.4% | 2/27 | 23 | 27 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 186 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 187 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 188 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 81 | 129 |  |
| 189 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 190 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 191 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 192 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 193 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 194 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 195 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 196 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 197 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 198 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 199 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 200 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 201 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 202 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 203 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 204 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 205 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 206 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 207 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 208 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 209 | `register_class` | 3.0% | 2/66 | 27 | 66 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 210 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 211 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 212 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 213 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 214 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 215 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 216 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 |  |
| 217 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 218 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 219 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 220 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 221 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 222 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 223 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 224 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 225 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 226 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 227 | `button_goto` | 0.0% | 0/4 | 0 | 4 |  |
| 228 | `button_key_events` | 0.0% | 0/14 | 0 | 14 |  |
| 229 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 |  |
| 230 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 231 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 |  |
| 232 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 |  |
| 233 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 |  |
| 234 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 235 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 |  |
| 236 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 237 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 238 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 239 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 240 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 241 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 242 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 243 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 244 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 245 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 246 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 |  |
| 247 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 |  |
| 248 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 249 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 250 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 251 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 258 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 262 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 263 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 264 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 265 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 266 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 |  |
| 267 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 |  |
| 268 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 269 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 270 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 |  |
| 271 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 |  |
| 272 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 |  |
| 273 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 274 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 275 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 276 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 277 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 278 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 279 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 280 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 281 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 282 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 283 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 284 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 285 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 286 | `issue_1104` | 0.0% | 0/2 | 0 | 2 |  |
| 287 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 288 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 289 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 290 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 291 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 292 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 293 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 294 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 295 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 296 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 297 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 299 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 300 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 301 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 302 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 304 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 305 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 306 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 307 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 308 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 309 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `mouse_events` | 0.0% | 0/8 | 0 | 8 |  |
| 311 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 |  |
| 312 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 |  |
| 314 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 |  |
| 315 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 316 | `movieclip_in_removed_button` | 0.0% | 0/4 | 0 | 4 |  |
| 317 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 318 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 320 | `native_objects_swf6` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 321 | `native_objects_swf7` | 0.0% | 0/139 | 139 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 322 | `native_objects_swf8` | 0.0% | 0/146 | 146 | 84 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 323 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 324 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 325 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 326 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 327 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 328 | `place_and_lookup` | 0.0% | 0/30 | 27 | 30 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 329 | `placeobject_occupied_depth` | 0.0% | 0/6 | 2 | 6 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 330 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 331 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 332 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 333 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 334 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 335 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 336 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 337 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 338 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 339 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 340 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 342 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 343 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 344 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 345 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 346 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 347 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 348 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 349 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 |  |
| 350 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 |  |
| 351 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 |  |
| 352 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 |  |
| 353 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 |  |
| 354 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 |  |
| 355 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 |  |
| 356 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 |  |
| 357 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 |  |
| 358 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 |  |
| 359 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 |  |
| 360 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 361 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 362 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 363 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 364 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 365 | `tell_target_invalid_swf6` | 0.0% | 0/5 | 2 | 5 | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 366 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 367 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 368 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 369 | `unload_clip_event` | 0.0% | 0/4 | 0 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 370 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 371 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 372 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 373 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 374 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/incomplete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 2 | 6 |
| 4 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 4 | 1 |
| 5 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 6 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 12 | 2 |
| 7 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 8 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 9 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 9 | 22 |
| 10 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 0 | 17 |
| 11 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 12 | [issue_768.md](ruffle-tests/_investigation/incomplete/issue_768.md) | 1 | 1 | 0 |
| 13 | [MATH_PLAN.md](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) | 5 | 1 | 4 |
| 14 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 6 | 52 |
| 15 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 16 | [object_string_coerce.md](ruffle-tests/_investigation/incomplete/object_string_coerce.md) | 2 | 1 | 1 |
| 17 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 18 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 19 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 20 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 6 | 6 |
| 21 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 22 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 23 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 2 | 7 |
| 24 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 2 | 5 |
| 25 | [string_coercion.md](ruffle-tests/_investigation/incomplete/string_coercion.md) | 1 | 1 | 0 |
| 26 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 4 | 9 |
| 27 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 28 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 20 | 50 |
| 29 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 30 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 31 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 32 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 33 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 34 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 311 | 140 | 171 |
