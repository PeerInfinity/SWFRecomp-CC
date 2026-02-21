# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-21 01:31 UTC

**Git SHA**: `3c59fa1ad5`

**Run Duration**: 75m 51s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **246** (39.7%) |
| Failing | 373 |
| Total expected lines | 91472 |
| Matching lines | 51893 (56.7%) |
| Mismatched lines | 39579 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 366 | 98.1% |
| Runtime Segfault | 5 | 1.3% |
| Runtime Error | 1 | 0.3% |
| Timeout | 1 | 0.3% |

## Passing Tests

**246 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.5s |  |
| 2 | `action_to_integer` | 28 | 7.0s |  |
| 3 | `add` | 28 | 7.0s |  |
| 4 | `add2` | 354 | 7.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 7.1s |  |
| 6 | `add_swf5` | 28 | 7.0s |  |
| 7 | `arguments` | 127 | 7.0s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 7.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 7.1s |  |
| 10 | `array_constructor` | 30 | 7.1s |  |
| 11 | `array_enumerate` | 4 | 7.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 7.0s |  |
| 13 | `array_properties` | 36 | 7.0s |  |
| 14 | `array_prototyping` | 12 | 7.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 7.0s |  |
| 16 | `array_sort_random` | 443 | 7.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 7.3s |  |
| 18 | `array_trivial` | 209 | 7.3s |  |
| 19 | `as1_constructor_v6` | 35 | 7.2s |  |
| 20 | `as1_constructor_v7` | 35 | 8.8s |  |
| 21 | `as2_oop` | 13 | 7.2s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 7.0s |  |
| 23 | `as_set_prop_flags_version` | 31 | 7.1s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 7.1s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 7.0s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 7.0s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 7.0s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 7.0s |  |
| 29 | `as_transformed_flag` | 20 | 7.1s |  |
| 30 | `bad_swf_tag_past_eof` | 0 | 7.0s |  |
| 31 | `bitand` | 1058 | 9.5s |  |
| 32 | `bitmap_data_colortransform` | 0 | 7.2s |  |
| 33 | `bitmap_data_fillrect` | 0 | 7.1s |  |
| 34 | `bitmap_data_max_size_swf10` | 12 | 7.0s |  |
| 35 | `bitmap_data_max_size_swf9` | 10 | 7.0s |  |
| 36 | `bitmap_data_perlinnoise` | 0 | 7.6s |  |
| 37 | `bitmap_data_pixeldissolve_image` | 0 | 7.4s |  |
| 38 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.0s |  |
| 39 | `bitor` | 1058 | 9.5s |  |
| 40 | `biturshift` | 14 | 7.0s |  |
| 41 | `biturshift_swf8` | 14 | 7.3s |  |
| 42 | `bitxor` | 1058 | 9.6s |  |
| 43 | `call_method_empty_name` | 1 | 6.9s |  |
| 44 | `capabilities_resolution` | 8 | 6.9s |  |
| 45 | `catch_references_registers` | 2 | 6.9s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 46 | `clone_sprite_types` | 24 | 7.0s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `color` | 57 | 7.2s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 48 | `color_transform` | 48 | 7.2s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 49 | `create_empty_movie_clip` | 3 | 7.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 50 | `define_function2` | 8 | 7.0s |  |
| 51 | `define_function2_preload` | 13 | 7.0s |  |
| 52 | `define_function2_preload_order` | 4 | 7.4s |  |
| 53 | `define_function_case_sensitive` | 2 | 7.1s |  |
| 54 | `delete` | 3 | 7.2s |  |
| 55 | `display_object_properties` | 2 | 7.1s |  |
| 56 | `divide_swf4` | 107 | 7.2s |  |
| 57 | `duplicate_movie_clip` | 20 | 7.1s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `edittext_antialiastype` | 296 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_autosize_setter` | 20 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_default_format` | 221 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_default_format_empty` | 95 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_default_format_font_style` | 335 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_html_align_swf7` | 52 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_html_align_swf8` | 52 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_newline_stripping` | 64 | 11.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `edittext_password` | 5 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `edittext_width_height` | 103 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `equals` | 32 | 7.0s |  |
| 69 | `equals2_swf5` | 926 | 8.7s |  |
| 70 | `equals2_swf6` | 926 | 8.7s |  |
| 71 | `equals2_swf7` | 926 | 8.7s |  |
| 72 | `equals_swf4` | 665 | 7.5s |  |
| 73 | `equals_swf4_alt` | 32 | 7.0s |  |
| 74 | `equals_swf5` | 32 | 7.0s |  |
| 75 | `error` | 58 | 7.0s |  |
| 76 | `escape` | 14 | 7.0s |  |
| 77 | `execution_order1` | 5 | 7.0s |  |
| 78 | `execution_order3` | 4 | 7.1s |  |
| 79 | `focusrect_mouse_swf8` | 0 | 7.1s |  |
| 80 | `focusrect_mouse_swf9` | 0 | 8.5s |  |
| 81 | `focusrect_swf5` | 6 | 7.5s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 82 | `function_suppress_and_preload` | 28 | 7.4s |  |
| 83 | `get_variable_in_scope` | 29 | 7.3s |  |
| 84 | `getproperty` | 28 | 7.3s |  |
| 85 | `getproperty_swf4` | 28 | 7.2s |  |
| 86 | `getproperty_swf5` | 28 | 6.9s |  |
| 87 | `global_array` | 3 | 6.9s |  |
| 88 | `global_is_bare` | 7 | 6.9s |  |
| 89 | `globals_swf5` | 304 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 90 | `globals_swf6` | 304 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 91 | `globals_swf7` | 304 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 92 | `globals_swf8` | 304 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 93 | `goto_execution_order` | 2 | 6.9s |  |
| 94 | `goto_execution_order2` | 2 | 6.9s |  |
| 95 | `goto_frame_number` | 3 | 7.7s |  |
| 96 | `greater_swf6` | 1175 | 9.6s |  |
| 97 | `greater_swf7` | 1175 | 9.6s |  |
| 98 | `greaterthan_swf5` | 1 | 7.3s |  |
| 99 | `greaterthan_swf8` | 1 | 7.3s |  |
| 100 | `has_own_property` | 32 | 7.4s |  |
| 101 | `infinite_recursion_function` | 4 | 7.3s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 102 | `infinite_recursion_function_in_setter` | 131 | 7.3s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 103 | `infinite_recursion_virtual_property` | 67 | 7.3s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 104 | `init_array_invalid` | 4 | 7.2s |  |
| 105 | `init_object_invalid` | 4 | 8.8s |  |
| 106 | `is_finite` | 49 | 7.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 107 | `is_finite_swf6` | 49 | 7.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 108 | `is_prototype_of` | 89 | 7.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 109 | `issue_1086` | 1 | 7.5s |  |
| 110 | `issue_1671` | 0 | 7.3s |  |
| 111 | `issue_1906` | 4 | 7.5s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 112 | `issue_2166` | 9 | 7.5s |  |
| 113 | `issue_3446` | 1 | 7.5s |  |
| 114 | `issue_4377` | 2 | 7.3s |  |
| 115 | `issue_710` | 4 | 7.4s |  |
| 116 | `issue_768` | 3 | 7.4s | [15](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 117 | `issue_9885` | 2 | 7.1s |  |
| 118 | `lessthan` | 41 | 7.1s |  |
| 119 | `lessthan2_swf5` | 1226 | 9.3s |  |
| 120 | `lessthan2_swf6` | 1226 | 9.2s |  |
| 121 | `lessthan2_swf7` | 1226 | 9.2s |  |
| 122 | `lessthan_swf4` | 902 | 7.9s |  |
| 123 | `lessthan_swf4_alt` | 41 | 7.2s |  |
| 124 | `lessthan_swf5` | 41 | 7.3s |  |
| 125 | `localconnection_properties` | 8 | 6.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 126 | `logical_ops_swf4` | 90 | 6.5s |  |
| 127 | `logical_ops_swf8` | 108 | 6.5s |  |
| 128 | `looping` | 6 | 6.5s |  |
| 129 | `mask_reapply` | 0 | 6.4s |  |
| 130 | `mask_with_drawing` | 0 | 6.4s |  |
| 131 | `math_min_max` | 101 | 6.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 132 | `math_swf6` | 530 | 6.8s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 133 | `math_swf7` | 530 | 6.8s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 134 | `math_swf8` | 530 | 7.0s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 135 | `matrix` | 171 | 6.8s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 136 | `mouse_wheel_enabled` | 2 | 7.2s |  |
| 137 | `movieclip_begin_gradient_fill` | 0 | 7.6s |  |
| 138 | `movieclip_blend_mode_property` | 35 | 7.4s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 139 | `movieclip_get_instance_at_depth` | 28 | 7.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 140 | `movieclip_line_gradient_style` | 0 | 7.8s |  |
| 141 | `movieclip_prototype_extension` | 5 | 7.2s |  |
| 142 | `nested_textfields_in_buttons` | 0 | 7.1s |  |
| 143 | `netstream_play_flv_screen` | 0 | 20.5s |  |
| 144 | `new_method_wrap` | 4 | 7.1s |  |
| 145 | `new_object_enumerate` | 7 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 146 | `new_object_wrap` | 4 | 7.0s |  |
| 147 | `o` | 3 | 7.0s |  |
| 148 | `object_constructor` | 33 | 7.0s |  |
| 149 | `object_function` | 32 | 7.1s |  |
| 150 | `object_properties` | 31 | 7.3s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 151 | `object_string_coerce_swf5` | 62 | 7.2s | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 152 | `parse_int` | 64 | 7.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 153 | `point` | 175 | 7.8s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 154 | `primitive_instanceof` | 37 | 7.1s |  |
| 155 | `primitive_type_globals` | 557 | 7.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 156 | `printjob_props_swf5` | 45 | 6.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 157 | `printjob_props_swf6` | 45 | 6.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 158 | `printjob_props_swf7` | 45 | 6.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 159 | `prototype_delete` | 12 | 6.5s |  |
| 160 | `prototype_enumerate` | 5 | 6.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 161 | `prototype_properties` | 17 | 6.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 162 | `rectangle` | 745 | 7.3s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 163 | `recursive_prototypes` | 0 | 6.5s |  |
| 164 | `sandbox_type_local_file` | 1 | 7.0s |  |
| 165 | `set_variable_scope` | 58 | 7.0s |  |
| 166 | `single_frame` | 1 | 7.0s |  |
| 167 | `sound_props_swf5` | 68 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 168 | `sound_props_swf6` | 68 | 7.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 169 | `sound_start_load` | 0 | 7.2s |  |
| 170 | `stage_object_enumerate` | 4 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 171 | `stage_object_properties_get_var` | 5 | 7.1s |  |
| 172 | `stage_property_representation` | 586 | 7.2s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 173 | `strictequals_swf6` | 902 | 8.7s |  |
| 174 | `strictly_equals` | 7 | 7.2s |  |
| 175 | `string_coercion` | 117 | 7.4s | [29](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 176 | `string_methods` | 285 | 7.7s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 177 | `string_methods_negative_args` | 240 | 7.3s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 178 | `string_methods_swfv5` | 275 | 7.7s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 179 | `string_ops_swf6` | 95 | 7.3s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 180 | `string_paths_keyevents` | 0 | 6.7s |  |
| 181 | `string_paths_timer` | 0 | 6.7s |  |
| 182 | `swf4_actions_bool` | 96 | 6.8s |  |
| 183 | `swf4_bool` | 4 | 6.7s |  |
| 184 | `swf4_function_calls` | 7 | 6.7s |  |
| 185 | `swf5_encoding` | 3 | 6.7s |  |
| 186 | `swf7_case_sensitive` | 44 | 7.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 187 | `tab_ordering_properties_tab_index_edge_case` | 4 | 7.1s |  |
| 188 | `target_clip_removed` | 5 | 7.1s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 189 | `text_format` | 1146 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 190 | `text_format_display` | 21 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 191 | `text_format_font_max_length` | 2 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 192 | `text_format_rounding_swf7` | 840 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 193 | `text_format_rounding_swf8` | 840 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 194 | `textfield_background_color` | 11 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 195 | `textfield_border_color` | 11 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 196 | `textfield_maxchars` | 3 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 197 | `textfield_properties` | 44 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 198 | `textfield_props_swf5` | 175 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 199 | `textfield_props_swf7` | 210 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 200 | `textfield_props_swf8` | 210 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 201 | `textfield_text` | 7 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 202 | `textfield_variable` | 81 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 203 | `this_swf7` | 41 | 7.0s | [34](ruffle-tests/_investigation/complete/this_swf7.md) |
| 204 | `timeline_function_def` | 7 | 7.1s |  |
| 205 | `try_catch_finally` | 118 | 7.3s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 206 | `try_finally_simple` | 16 | 7.2s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 207 | `typeof` | 22 | 7.3s |  |
| 208 | `typeof_globals` | 7 | 7.3s |  |
| 209 | `uncaught_exception` | 1 | 7.3s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 210 | `uncaught_exception_bubbled` | 1 | 7.2s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 211 | `undefined_to_string_swf6` | 4 | 7.2s |  |
| 212 | `unescape` | 43 | 7.3s |  |
| 213 | `unload_clip_event` | 4 | 7.4s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 214 | `use_hand_cursor` | 8 | 7.1s |  |
| 215 | `variable_args` | 5 | 7.2s |  |
| 216 | `waitforframe` | 7 | 7.1s |  |
| 217 | `waitforframe2` | 16 | 8.4s |  |
| 218 | `watch` | 117 | 7.6s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 219 | `watch_virtual_property_proto` | 2 | 7.4s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 220 | `with_return` | 2 | 7.5s |  |
| 221 | `with_variable_scopes` | 43 | 7.6s | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 222 | `xml` | 15 | 7.4s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 223 | `xml_append_child` | 28 | 7.6s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 224 | `xml_append_child_with_parent` | 20 | 7.5s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 225 | `xml_cdata` | 11 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 226 | `xml_child_nodes_edge_cases` | 4 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 227 | `xml_clone_expandos` | 19 | 7.3s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 228 | `xml_first_last_child` | 8 | 7.3s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 229 | `xml_has_child_nodes` | 3 | 7.3s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 230 | `xml_idmap` | 21 | 7.4s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 231 | `xml_ignore_comments` | 21 | 7.5s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 232 | `xml_ignore_white` | 34 | 7.4s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 233 | `xml_insert_before` | 20 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 234 | `xml_inspect_createmethods` | 15 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 235 | `xml_inspect_doctype` | 7 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 236 | `xml_inspect_parsexml` | 62 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 237 | `xml_inspect_xmldecl` | 7 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 238 | `xml_namespaces` | 203 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 239 | `xml_parent_and_child` | 5 | 7.1s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 240 | `xml_remove_node` | 22 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 241 | `xml_reparenting` | 14 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 242 | `xml_siblings` | 10 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 243 | `xml_to_string` | 13 | 7.1s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 244 | `xml_to_string_comment` | 1 | 7.1s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 245 | `xml_unescaping` | 23 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 246 | `xmlnode_proto` | 1 | 7.2s | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**88 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 3 | `transform` | 98.6% | 69 | 70 | 1 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 4 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 5 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 6 | `movieclip_depth_methods` | 96.9% | 95 | 98 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `object_prototypes` | 95.9% | 71 | 74 | 3 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 8 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 9 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 11 | `with` | 93.9% | 46 | 49 | 3 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 13 | `mouse_listeners` | 88.1% | 59 | 67 | 8 |  |
| 14 | `conflicting_instance_names` | 87.0% | 20 | 23 | 3 |  |
| 15 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `movieclip_name_from_timeline` | 84.6% | 11 | 13 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `local_to_global` | 83.7% | 41 | 49 | 8 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 19 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 20 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `do_init_action` | 75.0% | 3 | 4 | 1 |  |
| 24 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `attach_movie` | 72.9% | 43 | 59 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `remove_movie_clip` | 72.4% | 21 | 29 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 30 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 31 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 32 | `unload` | 69.2% | 36 | 52 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `button_v5` | 66.7% | 12 | 18 | 6 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `goto_advance2` | 66.7% | 2 | 3 | 1 |  |
| 37 | `issue_1104` | 66.7% | 2 | 3 | 1 |  |
| 38 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 39 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 40 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 43 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 44 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `button_children` | 62.5% | 5 | 8 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 46 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_align` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `goto_rewind2` | 60.0% | 3 | 5 | 2 |  |
| 55 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 56 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 57 | `string_paths_other` | 58.3% | 21 | 36 | 15 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 58 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 59 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 60 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 61 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 62 | `focusrect_property_swf6` | 57.2% | 707 | 1237 | 530 |  |
| 63 | `asnative` | 55.9% | 19 | 34 | 15 | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 64 | `button_v6` | 55.6% | 10 | 18 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 65 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 66 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 67 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 68 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 69 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 70 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 71 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 72 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 73 | `edittext_html_swf6` | 50.5% | 2718 | 5377 | 2659 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `goto_rewind3` | 50.0% | 2 | 4 | 2 |  |
| 76 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 77 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 78 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 79 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 80 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 81 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 82 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 83 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 84 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 85 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 88 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 9.7s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 2 | `native_objects_swf6` | 9.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf7` | 9.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 9.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `placeobject_occupied_depth` | 9.3s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_state_values` | exit code -6 | 10.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 16.9s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**366 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 3 | `transform` | 98.6% | 69/70 | 70 | 70 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 4 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 5 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 6 | `movieclip_depth_methods` | 96.9% | 95/98 | 98 | 98 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `object_prototypes` | 95.9% | 71/74 | 74 | 74 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 8 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 9 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 10 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 11 | `with` | 93.9% | 46/49 | 49 | 49 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 13 | `mouse_listeners` | 88.1% | 59/67 | 67 | 67 |  |
| 14 | `conflicting_instance_names` | 87.0% | 20/23 | 23 | 23 |  |
| 15 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `movieclip_name_from_timeline` | 84.6% | 11/13 | 13 | 13 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 19 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 20 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 21 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `do_init_action` | 75.0% | 3/4 | 4 | 3 |  |
| 24 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 26 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `remove_movie_clip` | 72.4% | 21/29 | 29 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 30 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 31 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 32 | `unload` | 69.2% | 36/52 | 52 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 33 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 34 | `button_v5` | 66.7% | 12/18 | 18 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 35 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `goto_advance2` | 66.7% | 2/3 | 3 | 2 |  |
| 37 | `issue_1104` | 66.7% | 2/3 | 3 | 2 |  |
| 38 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 39 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 40 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 43 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 44 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `button_children` | 62.5% | 5/8 | 8 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 46 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `goto_rewind2` | 60.0% | 3/5 | 5 | 3 |  |
| 55 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 56 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 57 | `string_paths_other` | 58.3% | 21/36 | 28 | 36 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 58 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 59 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 60 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 61 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 62 | `focusrect_property_swf6` | 57.2% | 707/1237 | 1236 | 1237 |  |
| 63 | `asnative` | 55.9% | 19/34 | 31 | 34 | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 64 | `button_v6` | 55.6% | 10/18 | 18 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 65 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 66 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 67 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 68 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 69 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 70 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 71 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 72 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 73 | `edittext_html_swf6` | 50.5% | 2718/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `goto_rewind3` | 50.0% | 2/4 | 4 | 2 |  |
| 76 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 77 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 78 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 79 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 80 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 81 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 82 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 83 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 84 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 85 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 86 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 88 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 89 | `enumerate` | 48.4% | 31/64 | 62 | 64 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 90 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 91 | `edittext_html_condensewhite_swf7` | 46.6% | 145/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 93 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_condensewhite_swf8` | 45.7% | 142/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 96 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 97 | `edittext_html_swf7` | 42.1% | 2262/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_html_swf8` | 41.8% | 2247/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `mcl_as_broadcaster` | 41.7% | 5/12 | 8 | 12 |  |
| 100 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 101 | `this_swf6` | 41.5% | 17/41 | 41 | 41 |  |
| 102 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 103 | `goto_both_ways1` | 40.0% | 2/5 | 5 | 3 |  |
| 104 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 105 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 106 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 107 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 108 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 109 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 110 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 111 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 115 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 116 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 118 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 119 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 120 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 121 | `stage_object_properties_swf6` | 30.5% | 131/429 | 429 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 122 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 123 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 124 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 125 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 126 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 127 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 128 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 129 | `execution_order4` | 25.0% | 3/12 | 11 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 130 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 131 | `goto_rewind1` | 25.0% | 1/4 | 4 | 1 |  |
| 132 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 133 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 134 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 135 | `stage_object_properties` | 23.1% | 132/571 | 571 | 241 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 136 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 137 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 138 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 139 | `focusrect_property_swf5` | 20.9% | 259/1237 | 1236 | 1237 |  |
| 140 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 141 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 142 | `default_names` | 20.0% | 14/70 | 70 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 143 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 144 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 145 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 146 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 147 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 148 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 149 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 150 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 151 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 152 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 153 | `goto_both_ways2` | 16.7% | 1/6 | 6 | 3 |  |
| 154 | `movieclip_library_state_values` | 16.7% | 13/78 | 73 | 78 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 155 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 156 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 157 | `path_string` | 15.2% | 49/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 158 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 159 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 160 | `goto_advance1` | 14.3% | 1/7 | 7 | 6 |  |
| 161 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 162 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 163 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 164 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 165 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 166 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 167 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 168 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 169 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 170 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 171 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 172 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 173 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 174 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 175 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 176 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 177 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 178 | `selection` | 9.3% | 42/454 | 244 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 179 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 180 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 181 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 182 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 183 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 184 | `textsnapshot_props_swf6` | 8.9% | 5/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 185 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 186 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 187 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 188 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 189 | `define_local` | 7.4% | 2/27 | 23 | 27 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 190 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 191 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 192 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 193 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 194 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 195 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 196 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 197 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 198 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 199 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 200 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 201 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 202 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 203 | `clip_events` | 5.3% | 1/19 | 17 | 19 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 204 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 205 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 206 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 207 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 208 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 209 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 210 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 211 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 212 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 213 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 214 | `register_class` | 3.0% | 2/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 215 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 216 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 217 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 218 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 219 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 220 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 221 | `tab_ordering_events` | 1.3% | 2/150 | 12 | 150 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 222 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 223 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 224 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 225 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 226 | `global_proto_decls` | 0.2% | 10/4497 | 529 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 227 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 228 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 229 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 231 | `button_goto` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 232 | `button_key_events` | 0.0% | 0/14 | 0 | 14 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 233 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 234 | `button_keypress` | 0.0% | 0/3 | 0 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 235 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 236 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 237 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 238 | `button_order` | 0.0% | 0/2 | 1 | 2 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 239 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 240 | `click_block` | 0.0% | 0/5 | 0 | 5 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 241 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 242 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 243 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 244 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 245 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 246 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 247 | `drag_drop` | 0.0% | 0/10 | 0 | 10 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 248 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 249 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 250 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 251 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 258 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 262 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 263 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 264 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 265 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 266 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 267 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 268 | `focus_keyboard_press` | 0.0% | 0/60 | 0 | 60 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 269 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 270 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 271 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 272 | `focus_root_movie` | 0.0% | 0/2 | 1 | 2 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 273 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 274 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 275 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 276 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 277 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 278 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 279 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 280 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 281 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 282 | `global_proto_decls_delete` | 0.0% | 0/4158 | 199 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 283 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 284 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 285 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 286 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 287 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 288 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 289 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 290 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 292 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 293 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 294 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 295 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 296 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 297 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 298 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
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
| 310 | `mouse_events` | 0.0% | 0/8 | 0 | 8 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 311 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 312 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 313 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 314 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 315 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 316 | `movieclip_in_removed_button` | 0.0% | 0/4 | 3 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 317 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 318 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 319 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 320 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 321 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 322 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 323 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 324 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 325 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 326 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 327 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 328 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 329 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 330 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 331 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 332 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 333 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 334 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 336 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 337 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 338 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 339 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 340 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 341 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 342 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 343 | `tab_ordering_automatic_basic` | 0.0% | 0/92 | 0 | 92 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 344 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 345 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 346 | `tab_ordering_children` | 0.0% | 0/208 | 0 | 208 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 347 | `tab_ordering_custom_basic` | 0.0% | 0/71 | 0 | 71 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 348 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 349 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 350 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 351 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 352 | `tab_ordering_movieclip_enabled_default` | 0.0% | 0/462 | 0 | 462 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 353 | `tab_ordering_reverse` | 0.0% | 0/51 | 0 | 51 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 354 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 355 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 356 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 357 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 358 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 359 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 360 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 361 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 362 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 363 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 364 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 365 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 366 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [39](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 0 | 14 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 2 | 6 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 4 | 1 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 10 | 4 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 0 | 17 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/incomplete/issue_768.md) | 1 | 1 | 0 |
| 16 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 5 | 4 | 1 |
| 17 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 18 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 7 | 51 |
| 19 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 20 | [object_string_coerce.md](ruffle-tests/_investigation/incomplete/object_string_coerce.md) | 2 | 1 | 1 |
| 21 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 22 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 23 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 24 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 5 | 7 |
| 25 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 26 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 27 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 2 | 7 |
| 28 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 2 | 5 |
| 29 | [string_coercion.md](ruffle-tests/_investigation/incomplete/string_coercion.md) | 1 | 1 | 0 |
| 30 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 4 | 9 |
| 31 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 32 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 1 | 18 |
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 24 | 46 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 1 | 11 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 267 | 130 | 137 |
