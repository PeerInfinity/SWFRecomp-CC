# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-21 03:54 UTC

**Git SHA**: `41ebbe04ab`

**Run Duration**: 77m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **261** (42.2%) |
| Failing | 358 |
| Total expected lines | 91472 |
| Matching lines | 52424 (57.3%) |
| Mismatched lines | 39048 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 351 | 98.0% |
| Runtime Segfault | 5 | 1.4% |
| Runtime Error | 1 | 0.3% |
| Timeout | 1 | 0.3% |

## Passing Tests

**261 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.3s |  |
| 2 | `action_to_integer` | 28 | 7.2s |  |
| 3 | `add` | 28 | 7.2s |  |
| 4 | `add2` | 354 | 7.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 7.2s |  |
| 6 | `add_swf5` | 28 | 7.2s |  |
| 7 | `arguments` | 127 | 7.2s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 7.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 7.2s |  |
| 10 | `array_constructor` | 30 | 7.2s |  |
| 11 | `array_enumerate` | 4 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 7.2s |  |
| 13 | `array_properties` | 36 | 7.2s |  |
| 14 | `array_prototyping` | 12 | 7.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 7.3s |  |
| 16 | `array_sort_random` | 443 | 7.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 7.4s |  |
| 18 | `array_trivial` | 209 | 7.4s |  |
| 19 | `as1_constructor_v6` | 35 | 7.3s |  |
| 20 | `as1_constructor_v7` | 35 | 9.9s |  |
| 21 | `as2_oop` | 13 | 8.1s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 7.7s |  |
| 23 | `as_set_prop_flags_version` | 31 | 7.4s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 7.4s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 7.4s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 7.4s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 7.5s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 7.3s |  |
| 29 | `as_transformed_flag` | 20 | 7.3s |  |
| 30 | `bad_swf_tag_past_eof` | 0 | 7.2s |  |
| 31 | `bitand` | 1058 | 9.8s |  |
| 32 | `bitmap_data_colortransform` | 0 | 7.4s |  |
| 33 | `bitmap_data_fillrect` | 0 | 7.3s |  |
| 34 | `bitmap_data_max_size_swf10` | 12 | 7.2s |  |
| 35 | `bitmap_data_max_size_swf9` | 10 | 7.2s |  |
| 36 | `bitmap_data_perlinnoise` | 0 | 7.8s |  |
| 37 | `bitmap_data_pixeldissolve_image` | 0 | 7.6s |  |
| 38 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.2s |  |
| 39 | `bitor` | 1058 | 9.9s |  |
| 40 | `biturshift` | 14 | 7.2s |  |
| 41 | `biturshift_swf8` | 14 | 7.6s |  |
| 42 | `bitxor` | 1058 | 10.5s |  |
| 43 | `call_method_empty_name` | 1 | 7.5s |  |
| 44 | `capabilities_resolution` | 8 | 7.5s |  |
| 45 | `catch_references_registers` | 2 | 7.6s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 46 | `clone_sprite_types` | 24 | 7.3s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `color` | 57 | 7.4s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 48 | `color_transform` | 48 | 7.3s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 49 | `conflicting_instance_names` | 23 | 7.3s |  |
| 50 | `create_empty_movie_clip` | 3 | 7.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 51 | `define_function2` | 8 | 7.1s |  |
| 52 | `define_function2_preload` | 13 | 7.1s |  |
| 53 | `define_function2_preload_order` | 4 | 7.5s |  |
| 54 | `define_function_case_sensitive` | 2 | 7.2s |  |
| 55 | `delete` | 3 | 7.3s |  |
| 56 | `display_object_properties` | 2 | 7.1s |  |
| 57 | `divide_swf4` | 107 | 7.2s |  |
| 58 | `do_init_action` | 3 | 7.2s |  |
| 59 | `duplicate_movie_clip` | 20 | 7.2s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 60 | `edittext_antialiastype` | 296 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_autosize_setter` | 20 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_default_format` | 221 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_default_format_empty` | 95 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_default_format_font_style` | 335 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_html_align_swf7` | 52 | 6.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `edittext_html_align_swf8` | 52 | 6.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `edittext_newline_stripping` | 64 | 11.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_password` | 5 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_width_height` | 103 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `enumerate` | 64 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 71 | `equals` | 32 | 7.1s |  |
| 72 | `equals2_swf5` | 926 | 8.9s |  |
| 73 | `equals2_swf6` | 926 | 9.0s |  |
| 74 | `equals2_swf7` | 926 | 9.0s |  |
| 75 | `equals_swf4` | 665 | 7.6s |  |
| 76 | `equals_swf4_alt` | 32 | 7.2s |  |
| 77 | `equals_swf5` | 32 | 7.1s |  |
| 78 | `error` | 58 | 7.3s |  |
| 79 | `escape` | 14 | 7.2s |  |
| 80 | `execution_order1` | 5 | 7.3s |  |
| 81 | `execution_order2` | 7 | 7.3s |  |
| 82 | `execution_order3` | 4 | 7.2s |  |
| 83 | `focusrect_mouse_swf8` | 0 | 7.2s |  |
| 84 | `focusrect_mouse_swf9` | 0 | 7.6s |  |
| 85 | `focusrect_swf5` | 6 | 7.5s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 86 | `function_suppress_and_preload` | 28 | 7.4s |  |
| 87 | `get_variable_in_scope` | 29 | 7.4s |  |
| 88 | `getproperty` | 28 | 7.3s |  |
| 89 | `getproperty_swf4` | 28 | 7.7s |  |
| 90 | `getproperty_swf5` | 28 | 7.5s |  |
| 91 | `global_array` | 3 | 7.5s |  |
| 92 | `global_is_bare` | 7 | 7.5s |  |
| 93 | `globals_swf5` | 304 | 7.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 94 | `globals_swf6` | 304 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 95 | `globals_swf7` | 304 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 96 | `globals_swf8` | 304 | 7.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 97 | `goto_advance1` | 6 | 7.4s |  |
| 98 | `goto_advance2` | 2 | 7.5s |  |
| 99 | `goto_both_ways1` | 3 | 7.4s |  |
| 100 | `goto_both_ways2` | 3 | 7.5s |  |
| 101 | `goto_execution_order` | 2 | 7.4s |  |
| 102 | `goto_execution_order2` | 2 | 7.5s |  |
| 103 | `goto_frame_number` | 3 | 7.6s |  |
| 104 | `goto_rewind1` | 1 | 7.7s |  |
| 105 | `goto_rewind2` | 3 | 7.4s |  |
| 106 | `greater_swf6` | 1175 | 9.7s |  |
| 107 | `greater_swf7` | 1175 | 9.9s |  |
| 108 | `greaterthan_swf5` | 1 | 7.6s |  |
| 109 | `greaterthan_swf8` | 1 | 7.6s |  |
| 110 | `has_own_property` | 32 | 7.5s |  |
| 111 | `infinite_recursion_function` | 4 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 112 | `infinite_recursion_function_in_setter` | 131 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 113 | `infinite_recursion_virtual_property` | 67 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 114 | `init_array_invalid` | 4 | 7.7s |  |
| 115 | `init_object_invalid` | 4 | 7.4s |  |
| 116 | `is_finite` | 49 | 7.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 117 | `is_finite_swf6` | 49 | 7.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 118 | `is_prototype_of` | 89 | 7.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 119 | `issue_1086` | 1 | 7.3s |  |
| 120 | `issue_1671` | 0 | 7.3s |  |
| 121 | `issue_2166` | 9 | 7.3s |  |
| 122 | `issue_3446` | 1 | 7.3s |  |
| 123 | `issue_4377` | 2 | 7.3s |  |
| 124 | `issue_710` | 4 | 7.3s |  |
| 125 | `issue_768` | 3 | 7.4s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 126 | `issue_9885` | 2 | 7.4s |  |
| 127 | `lessthan` | 41 | 7.3s |  |
| 128 | `lessthan2_swf5` | 1226 | 9.4s |  |
| 129 | `lessthan2_swf6` | 1226 | 9.4s |  |
| 130 | `lessthan2_swf7` | 1226 | 9.4s |  |
| 131 | `lessthan_swf4` | 902 | 8.0s |  |
| 132 | `lessthan_swf4_alt` | 41 | 7.3s |  |
| 133 | `lessthan_swf5` | 41 | 7.3s |  |
| 134 | `localconnection_properties` | 8 | 7.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 135 | `logical_ops_swf4` | 90 | 7.1s |  |
| 136 | `logical_ops_swf8` | 108 | 7.2s |  |
| 137 | `looping` | 6 | 7.1s |  |
| 138 | `mask_reapply` | 0 | 7.1s |  |
| 139 | `mask_with_drawing` | 0 | 7.1s |  |
| 140 | `math_min_max` | 101 | 7.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 141 | `math_swf6` | 530 | 7.6s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 142 | `math_swf7` | 530 | 7.6s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 143 | `math_swf8` | 530 | 7.5s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 144 | `matrix` | 171 | 7.5s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 145 | `mouse_listeners` | 67 | 7.1s |  |
| 146 | `mouse_wheel_enabled` | 2 | 7.2s |  |
| 147 | `movieclip_begin_gradient_fill` | 0 | 7.6s |  |
| 148 | `movieclip_blend_mode_property` | 35 | 7.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `movieclip_default_state` | 69 | 7.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `movieclip_get_instance_at_depth` | 28 | 7.2s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 151 | `movieclip_line_gradient_style` | 0 | 9.0s |  |
| 152 | `movieclip_prototype_extension` | 5 | 7.2s |  |
| 153 | `nested_textfields_in_buttons` | 0 | 7.2s |  |
| 154 | `netstream_play_flv_screen` | 0 | 20.2s |  |
| 155 | `new_method_wrap` | 4 | 7.2s |  |
| 156 | `new_object_enumerate` | 7 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 157 | `new_object_wrap` | 4 | 7.2s |  |
| 158 | `o` | 3 | 7.2s |  |
| 159 | `object_constructor` | 33 | 7.2s |  |
| 160 | `object_function` | 32 | 7.3s |  |
| 161 | `object_properties` | 31 | 7.4s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 162 | `object_prototypes` | 74 | 7.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 163 | `object_string_coerce_swf5` | 62 | 7.3s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 164 | `object_string_coerce_swf6` | 68 | 7.3s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 165 | `parse_int` | 64 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 166 | `point` | 175 | 7.7s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 167 | `primitive_instanceof` | 37 | 7.4s |  |
| 168 | `primitive_type_globals` | 557 | 7.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 169 | `printjob_props_swf5` | 45 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 170 | `printjob_props_swf6` | 45 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 171 | `printjob_props_swf7` | 45 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 172 | `prototype_delete` | 12 | 7.1s |  |
| 173 | `prototype_enumerate` | 5 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 174 | `prototype_properties` | 17 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 175 | `rectangle` | 745 | 7.9s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 176 | `recursive_prototypes` | 0 | 7.2s |  |
| 177 | `sandbox_type_local_file` | 1 | 7.1s |  |
| 178 | `set_variable_scope` | 58 | 7.2s |  |
| 179 | `single_frame` | 1 | 7.2s |  |
| 180 | `sound_props_swf5` | 68 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 181 | `sound_props_swf6` | 68 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 182 | `sound_start_load` | 0 | 7.4s |  |
| 183 | `stage_object_enumerate` | 4 | 7.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 184 | `stage_object_properties_get_var` | 5 | 7.3s |  |
| 185 | `stage_property_representation` | 586 | 7.2s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 186 | `strictequals_swf6` | 902 | 8.8s |  |
| 187 | `strictly_equals` | 7 | 7.2s |  |
| 188 | `string_coercion` | 117 | 7.5s | [29](ruffle-tests/_investigation/complete/string_coercion.md) |
| 189 | `string_methods` | 285 | 7.7s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 190 | `string_methods_negative_args` | 240 | 7.3s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 191 | `string_methods_swfv5` | 275 | 7.8s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 192 | `string_ops_swf6` | 95 | 7.3s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 193 | `string_paths_keyevents` | 0 | 7.1s |  |
| 194 | `string_paths_timer` | 0 | 7.2s |  |
| 195 | `swf4_actions_bool` | 96 | 7.1s |  |
| 196 | `swf4_bool` | 4 | 7.0s |  |
| 197 | `swf4_function_calls` | 7 | 7.1s |  |
| 198 | `swf5_encoding` | 3 | 7.0s |  |
| 199 | `swf7_case_sensitive` | 44 | 7.2s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 200 | `tab_ordering_properties_tab_index_edge_case` | 4 | 7.2s |  |
| 201 | `target_clip_removed` | 5 | 7.4s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 202 | `text_format` | 1146 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 203 | `text_format_display` | 21 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 204 | `text_format_font_max_length` | 2 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 205 | `text_format_rounding_swf7` | 840 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 206 | `text_format_rounding_swf8` | 840 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 207 | `textfield_background_color` | 11 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 208 | `textfield_border_color` | 11 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 209 | `textfield_maxchars` | 3 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 210 | `textfield_properties` | 44 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 211 | `textfield_props_swf5` | 175 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 212 | `textfield_props_swf6` | 210 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 213 | `textfield_props_swf7` | 210 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 214 | `textfield_props_swf8` | 210 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 215 | `textfield_text` | 7 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 216 | `textfield_variable` | 81 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 217 | `this_swf7` | 41 | 7.1s | [34](ruffle-tests/_investigation/complete/this_swf7.md) |
| 218 | `timeline_function_def` | 7 | 7.2s |  |
| 219 | `try_catch_finally` | 118 | 7.2s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 220 | `try_finally_simple` | 16 | 7.1s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 221 | `typeof` | 22 | 7.1s |  |
| 222 | `typeof_globals` | 7 | 7.1s |  |
| 223 | `uncaught_exception` | 1 | 7.1s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 224 | `uncaught_exception_bubbled` | 1 | 7.1s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 225 | `undefined_to_string_swf6` | 4 | 7.1s |  |
| 226 | `unescape` | 43 | 7.2s |  |
| 227 | `unload_clip_event` | 4 | 7.3s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 228 | `use_hand_cursor` | 8 | 7.3s |  |
| 229 | `variable_args` | 5 | 7.4s |  |
| 230 | `waitforframe` | 7 | 7.3s |  |
| 231 | `waitforframe2` | 16 | 7.7s |  |
| 232 | `watch` | 117 | 7.7s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 233 | `watch_virtual_property_proto` | 2 | 7.8s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 234 | `with_return` | 2 | 7.4s |  |
| 235 | `with_variable_scopes` | 43 | 7.5s | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 236 | `xml` | 15 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 237 | `xml_append_child` | 28 | 7.4s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 238 | `xml_append_child_with_parent` | 20 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 239 | `xml_attributes_read` | 4 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 240 | `xml_cdata` | 11 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 241 | `xml_child_nodes_edge_cases` | 4 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 242 | `xml_clone_expandos` | 19 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 243 | `xml_first_last_child` | 8 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 244 | `xml_has_child_nodes` | 3 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 245 | `xml_idmap` | 21 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 246 | `xml_ignore_comments` | 21 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 247 | `xml_ignore_white` | 34 | 8.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 248 | `xml_insert_before` | 20 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 249 | `xml_inspect_createmethods` | 15 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 250 | `xml_inspect_doctype` | 7 | 7.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 251 | `xml_inspect_parsexml` | 62 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 252 | `xml_inspect_xmldecl` | 7 | 7.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 253 | `xml_namespaces` | 203 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 254 | `xml_parent_and_child` | 5 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 255 | `xml_remove_node` | 22 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 256 | `xml_reparenting` | 14 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 257 | `xml_siblings` | 10 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 258 | `xml_to_string` | 13 | 7.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 259 | `xml_to_string_comment` | 1 | 7.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 260 | `xml_unescaping` | 23 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 261 | `xmlnode_proto` | 1 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**82 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `transform` | 98.6% | 69 | 70 | 1 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 3 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 4 | `movieclip_depth_methods` | 96.9% | 95 | 98 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 5 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `with` | 93.9% | 46 | 49 | 3 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 9 | `stage_object_properties` | 92.5% | 223 | 241 | 18 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 11 | `stage_object_properties_swf6` | 90.9% | 210 | 231 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_name_from_timeline` | 84.6% | 11 | 13 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `local_to_global` | 83.7% | 41 | 49 | 8 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `movieclip_focusenabled` | 82.8% | 82 | 99 | 17 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 17 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 18 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 19 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 20 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 22 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `attach_movie` | 72.9% | 43 | 59 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 26 | `remove_movie_clip` | 72.4% | 21 | 29 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 28 | `unload` | 69.2% | 36 | 52 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `button_v5` | 66.7% | 12 | 18 | 6 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 30 | `export_assets` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 31 | `goto_rewind3` | 66.7% | 2 | 3 | 1 |  |
| 32 | `issue_1104` | 66.7% | 2 | 3 | 1 |  |
| 33 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 34 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 35 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 38 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 39 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `button_children` | 62.5% | 5 | 8 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 41 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_align` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 50 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 51 | `string_paths_other` | 58.3% | 21 | 36 | 15 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 52 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 54 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 55 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 56 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 57 | `movieclip_hittest_shapeflag` | 57.1% | 193 | 338 | 145 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 59 | `button_v6` | 55.6% | 10 | 18 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 60 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 61 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 62 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 63 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 64 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 65 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 66 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 67 | `edittext_html_swf6` | 50.5% | 2718 | 5377 | 2659 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 71 | `issue_1906` | 50.0% | 2 | 4 | 2 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 72 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 73 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 74 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 75 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 76 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 77 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 78 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 79 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 80 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 81 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 9.8s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 2 | `native_objects_swf6` | 9.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf7` | 9.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 9.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `placeobject_occupied_depth` | 9.3s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_state_values` | exit code -6 | 10.3s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 17.1s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**351 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `transform` | 98.6% | 69/70 | 70 | 70 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 3 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 4 | `movieclip_depth_methods` | 96.9% | 95/98 | 98 | 98 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 5 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `with` | 93.9% | 46/49 | 49 | 49 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 9 | `stage_object_properties` | 92.5% | 223/241 | 241 | 241 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 11 | `stage_object_properties_swf6` | 90.9% | 210/231 | 231 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_name_from_timeline` | 84.6% | 11/13 | 13 | 13 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `movieclip_focusenabled` | 82.8% | 82/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 17 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 18 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 19 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 20 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 21 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 22 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 25 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 26 | `remove_movie_clip` | 72.4% | 21/29 | 29 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 27 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 28 | `unload` | 69.2% | 36/52 | 52 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 29 | `button_v5` | 66.7% | 12/18 | 18 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 30 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 31 | `goto_rewind3` | 66.7% | 2/3 | 3 | 2 |  |
| 32 | `issue_1104` | 66.7% | 2/3 | 3 | 2 |  |
| 33 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 34 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 35 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 38 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 39 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `button_children` | 62.5% | 5/8 | 8 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 41 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 50 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 51 | `string_paths_other` | 58.3% | 21/36 | 28 | 36 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 52 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 54 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 55 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 56 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 57 | `movieclip_hittest_shapeflag` | 57.1% | 193/338 | 338 | 338 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 59 | `button_v6` | 55.6% | 10/18 | 18 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 60 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 61 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 62 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 63 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 64 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 65 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 66 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 67 | `edittext_html_swf6` | 50.5% | 2718/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 71 | `issue_1906` | 50.0% | 2/4 | 4 | 4 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 72 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 73 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 74 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 75 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 76 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 77 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 78 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 79 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 80 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 81 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 83 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 84 | `selection` | 47.8% | 217/454 | 433 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 85 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 86 | `edittext_html_condensewhite_swf7` | 46.6% | 145/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 88 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_html_condensewhite_swf8` | 45.7% | 142/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 91 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 92 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 93 | `edittext_html_swf7` | 42.1% | 2262/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_swf8` | 41.8% | 2247/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `mcl_as_broadcaster` | 41.7% | 5/12 | 8 | 12 |  |
| 96 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 97 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 98 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 99 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 100 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 101 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 102 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 103 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 104 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 105 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 109 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 110 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 111 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 112 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 114 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 115 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 116 | `default_names` | 28.8% | 15/52 | 44 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 118 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 119 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 120 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 121 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 122 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 123 | `execution_order4` | 25.0% | 3/12 | 11 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 125 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 126 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 127 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 128 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 129 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 130 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 131 | `focus_remove` | 21.2% | 7/33 | 21 | 33 |  |
| 132 | `focusrect_property_swf5` | 20.9% | 259/1237 | 1236 | 1237 |  |
| 133 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 134 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 135 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 136 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 4 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 137 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 138 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 139 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 140 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 141 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 142 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 143 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 144 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 145 | `movieclip_library_state_values` | 16.7% | 13/78 | 73 | 78 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 146 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 147 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 148 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 149 | `path_string` | 15.2% | 49/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 150 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 151 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 152 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 153 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 154 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 155 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 156 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 157 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 158 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 159 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 160 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 161 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 162 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 163 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 164 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 165 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 166 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 167 | `tab_ordering_events` | 11.3% | 17/150 | 26 | 150 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 168 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 2 | 9 |  |
| 169 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 172 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 173 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 174 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 175 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 176 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 177 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 178 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 179 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 180 | `define_local` | 7.4% | 2/27 | 23 | 27 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 181 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 183 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 184 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 185 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 187 | `tab_ordering_reverse` | 5.9% | 3/51 | 3 | 51 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 188 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 189 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 190 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 191 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 192 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 193 | `clip_events` | 5.3% | 1/19 | 14 | 19 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 194 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 195 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 196 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 197 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 198 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 199 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 200 | `tab_ordering_custom_basic` | 4.2% | 3/71 | 3 | 71 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 201 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 202 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 203 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 204 | `tab_ordering_automatic_basic` | 3.3% | 3/92 | 3 | 92 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 205 | `register_class` | 3.0% | 2/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 206 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 207 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 208 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 209 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 210 | `focus_keyboard_press` | 1.7% | 1/60 | 1 | 60 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 211 | `tab_ordering_children` | 1.4% | 3/208 | 3 | 208 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 212 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 213 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 214 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 215 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 216 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 217 | `tab_ordering_movieclip_enabled_default` | 0.6% | 3/462 | 3 | 462 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 218 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 219 | `global_proto_decls` | 0.2% | 9/4497 | 539 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 220 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 221 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 222 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 223 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 224 | `button_goto` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 225 | `button_key_events` | 0.0% | 0/14 | 0 | 14 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 226 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 227 | `button_keypress` | 0.0% | 0/3 | 0 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 228 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 229 | `button_keypress_vs_tab` | 0.0% | 0/20 | 0 | 20 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 230 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 231 | `button_order` | 0.0% | 0/2 | 1 | 2 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 232 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 233 | `click_block` | 0.0% | 0/5 | 0 | 5 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 234 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 235 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 236 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 237 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 238 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 239 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 240 | `drag_drop` | 0.0% | 0/10 | 0 | 10 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 241 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 242 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 243 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 244 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 245 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 246 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 247 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 249 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 250 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 251 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 257 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 258 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 259 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 260 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 261 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 262 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 263 | `focus_root_movie` | 0.0% | 0/3 | 3 | 2 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 264 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 265 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 266 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 267 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 268 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 269 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 270 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 271 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 272 | `global_proto_decls_delete` | 0.0% | 0/4158 | 203 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 273 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 274 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 275 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 276 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 277 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 278 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 279 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 280 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 282 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 283 | `loadmovie_replace_root` | 0.0% | 0/5 | 1 | 5 |  |
| 284 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 285 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 286 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 287 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 288 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 289 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 290 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 291 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 292 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 293 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 294 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 295 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 296 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 297 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 298 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 299 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `mouse_events` | 0.0% | 0/8 | 0 | 8 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 301 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 302 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 303 | `mouse_pos` | 0.0% | 0/665 | 0 | 665 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 304 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 0 | 260 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 305 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 306 | `movieclip_in_removed_button` | 0.0% | 0/4 | 3 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 307 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 308 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 309 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 310 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 311 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 312 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 313 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 314 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 315 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 316 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 317 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 319 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 320 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 321 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 322 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 323 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 324 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 325 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 326 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 327 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 328 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 329 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 330 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 331 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 332 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 1 | 29 |  |
| 333 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 334 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 335 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 336 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 337 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 338 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 339 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 340 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 341 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 342 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 343 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 344 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 345 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 346 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 347 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 348 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 349 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 350 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 351 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 0 | 14 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 2 | 6 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 3 | 2 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 12 | 2 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 0 | 17 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 16 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 17 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 18 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 8 | 50 |
| 19 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 20 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 21 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 22 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 23 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 24 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 6 | 6 |
| 25 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 26 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 27 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 2 | 7 |
| 28 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 2 | 5 |
| 29 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 30 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 4 | 9 |
| 31 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 32 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 1 | 18 |
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 25 | 45 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 1 | 11 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 268 | 140 | 128 |
