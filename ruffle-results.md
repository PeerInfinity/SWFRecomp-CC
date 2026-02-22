# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-22 21:02 UTC

**Git SHA**: `ebdc0601be`

**Run Duration**: 80m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **284** (45.9%) |
| Failing | 335 |
| Total expected lines | 91478 |
| Matching lines | 54893 (60.0%) |
| Mismatched lines | 36585 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 327 | 97.6% |
| Runtime Segfault | 5 | 1.5% |
| Runtime Error | 2 | 0.6% |
| Timeout | 1 | 0.3% |

## Passing Tests

**284 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 9.0s |  |
| 2 | `action_to_integer` | 28 | 7.5s |  |
| 3 | `add` | 28 | 7.5s |  |
| 4 | `add2` | 354 | 7.7s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 7.4s |  |
| 6 | `add_swf5` | 28 | 7.4s |  |
| 7 | `arguments` | 127 | 7.4s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 7.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 7.5s |  |
| 10 | `array_constructor` | 30 | 7.5s |  |
| 11 | `array_enumerate` | 4 | 7.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 7.5s |  |
| 13 | `array_properties` | 36 | 7.5s |  |
| 14 | `array_prototyping` | 12 | 7.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 7.5s |  |
| 16 | `array_sort` | 161 | 8.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_sort_random` | 443 | 7.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 7.6s |  |
| 19 | `array_trivial` | 209 | 7.6s |  |
| 20 | `as1_constructor_v6` | 35 | 7.5s |  |
| 21 | `as1_constructor_v7` | 35 | 8.0s |  |
| 22 | `as2_oop` | 13 | 7.7s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as_broadcaster_initialize` | 10 | 7.5s |  |
| 24 | `as_set_prop_flags_version` | 31 | 7.6s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `as_set_prop_flags_version_swf5` | 1 | 7.5s |  |
| 26 | `as_set_prop_flags_version_swf6` | 1 | 7.6s |  |
| 27 | `as_set_prop_flags_version_swf7` | 1 | 7.6s |  |
| 28 | `as_set_prop_flags_version_swf8` | 1 | 7.5s |  |
| 29 | `as_set_prop_flags_version_swf9` | 1 | 7.5s |  |
| 30 | `as_transformed_flag` | 20 | 7.5s |  |
| 31 | `bad_swf_tag_past_eof` | 0 | 7.2s |  |
| 32 | `bitand` | 1058 | 9.6s |  |
| 33 | `bitmap_data_colortransform` | 0 | 7.6s |  |
| 34 | `bitmap_data_fillrect` | 0 | 7.5s |  |
| 35 | `bitmap_data_max_size_swf10` | 12 | 7.4s |  |
| 36 | `bitmap_data_max_size_swf9` | 10 | 7.3s |  |
| 37 | `bitmap_data_perlinnoise` | 0 | 7.9s |  |
| 38 | `bitmap_data_pixeldissolve_image` | 0 | 7.7s |  |
| 39 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.4s |  |
| 40 | `bitor` | 1058 | 9.8s |  |
| 41 | `biturshift` | 14 | 7.3s |  |
| 42 | `biturshift_swf8` | 14 | 9.8s |  |
| 43 | `bitxor` | 1058 | 10.0s |  |
| 44 | `boxed_primitives` | 24 | 7.5s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 45 | `button_children` | 8 | 7.4s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 46 | `button_order` | 2 | 7.4s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 47 | `button_v5` | 18 | 7.4s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 48 | `button_v6` | 18 | 7.4s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 49 | `call_method_empty_name` | 1 | 7.4s |  |
| 50 | `capabilities_resolution` | 8 | 7.4s |  |
| 51 | `catch_references_registers` | 2 | 7.4s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 52 | `clone_sprite_types` | 24 | 7.4s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `color` | 57 | 7.6s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 54 | `color_transform` | 48 | 7.5s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 55 | `conflicting_instance_names` | 23 | 7.5s |  |
| 56 | `create_empty_movie_clip` | 3 | 7.4s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `define_function2` | 8 | 7.4s |  |
| 58 | `define_function2_preload` | 13 | 7.4s |  |
| 59 | `define_function2_preload_order` | 4 | 8.1s |  |
| 60 | `define_function_case_sensitive` | 2 | 7.6s |  |
| 61 | `delete` | 3 | 7.8s |  |
| 62 | `display_object_properties` | 2 | 7.7s |  |
| 63 | `divide_swf4` | 107 | 7.8s |  |
| 64 | `do_init_action` | 3 | 7.7s |  |
| 65 | `duplicate_movie_clip` | 20 | 7.8s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 66 | `edittext_antialiastype` | 296 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `edittext_autosize_setter` | 20 | 8.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_default_format` | 221 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_default_format_empty` | 95 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `edittext_default_format_font_style` | 335 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `edittext_html_align_swf7` | 52 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_html_align_swf8` | 52 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_html_entity` | 4 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_newline_stripping` | 64 | 12.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_password` | 5 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_width_height` | 103 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `enumerate` | 64 | 7.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 78 | `equals` | 32 | 7.5s |  |
| 79 | `equals2_swf5` | 926 | 9.3s |  |
| 80 | `equals2_swf6` | 926 | 9.2s |  |
| 81 | `equals2_swf7` | 926 | 9.2s |  |
| 82 | `equals_swf4` | 665 | 8.3s |  |
| 83 | `equals_swf4_alt` | 32 | 7.5s |  |
| 84 | `equals_swf5` | 32 | 7.6s |  |
| 85 | `error` | 58 | 7.5s |  |
| 86 | `escape` | 14 | 7.5s |  |
| 87 | `execution_order1` | 5 | 7.5s |  |
| 88 | `execution_order2` | 7 | 7.5s |  |
| 89 | `execution_order3` | 4 | 7.4s |  |
| 90 | `focusrect_mouse_swf8` | 0 | 7.7s |  |
| 91 | `focusrect_mouse_swf9` | 0 | 8.0s |  |
| 92 | `focusrect_swf5` | 6 | 7.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 93 | `function_suppress_and_preload` | 28 | 7.5s |  |
| 94 | `get_variable_in_scope` | 29 | 7.5s |  |
| 95 | `getproperty` | 28 | 7.5s |  |
| 96 | `getproperty_swf4` | 28 | 7.7s |  |
| 97 | `getproperty_swf5` | 28 | 7.6s |  |
| 98 | `global_array` | 3 | 7.5s |  |
| 99 | `global_is_bare` | 7 | 7.4s |  |
| 100 | `globals_swf5` | 304 | 7.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 101 | `globals_swf6` | 304 | 7.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 102 | `globals_swf7` | 304 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 103 | `globals_swf8` | 304 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 104 | `goto_advance1` | 6 | 7.5s |  |
| 105 | `goto_advance2` | 2 | 7.6s |  |
| 106 | `goto_both_ways1` | 3 | 7.7s |  |
| 107 | `goto_both_ways2` | 3 | 7.6s |  |
| 108 | `goto_execution_order` | 2 | 7.5s |  |
| 109 | `goto_execution_order2` | 2 | 7.5s |  |
| 110 | `goto_frame_number` | 3 | 7.6s |  |
| 111 | `goto_rewind1` | 1 | 7.7s |  |
| 112 | `goto_rewind2` | 3 | 7.5s |  |
| 113 | `goto_rewind3` | 2 | 7.6s |  |
| 114 | `greater_swf6` | 1175 | 9.9s |  |
| 115 | `greater_swf7` | 1175 | 9.8s |  |
| 116 | `greaterthan_swf5` | 1 | 7.7s |  |
| 117 | `greaterthan_swf8` | 1 | 7.8s |  |
| 118 | `has_own_property` | 32 | 7.9s |  |
| 119 | `infinite_recursion_function` | 4 | 7.7s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 120 | `infinite_recursion_function_in_setter` | 131 | 7.7s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 121 | `infinite_recursion_virtual_property` | 67 | 7.7s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 122 | `init_array_invalid` | 4 | 7.7s |  |
| 123 | `init_object_invalid` | 4 | 7.7s |  |
| 124 | `is_finite` | 49 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 125 | `is_finite_swf6` | 49 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 126 | `is_prototype_of` | 89 | 7.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 127 | `issue_1086` | 1 | 7.4s |  |
| 128 | `issue_1104` | 2 | 7.5s |  |
| 129 | `issue_1671` | 0 | 7.4s |  |
| 130 | `issue_1906` | 4 | 7.5s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 131 | `issue_2166` | 9 | 7.5s |  |
| 132 | `issue_3446` | 1 | 7.4s |  |
| 133 | `issue_3522` | 2 | 7.4s |  |
| 134 | `issue_4377` | 2 | 7.4s |  |
| 135 | `issue_710` | 4 | 7.4s |  |
| 136 | `issue_768` | 3 | 7.7s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 137 | `issue_9327` | 2 | 7.5s |  |
| 138 | `issue_9885` | 2 | 7.5s |  |
| 139 | `lessthan` | 41 | 7.5s |  |
| 140 | `lessthan2_swf5` | 1226 | 9.5s |  |
| 141 | `lessthan2_swf6` | 1226 | 9.5s |  |
| 142 | `lessthan2_swf7` | 1226 | 9.5s |  |
| 143 | `lessthan_swf4` | 902 | 8.6s |  |
| 144 | `lessthan_swf4_alt` | 41 | 7.5s |  |
| 145 | `lessthan_swf5` | 41 | 7.5s |  |
| 146 | `local_to_global` | 49 | 7.5s | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 147 | `localconnection_properties` | 8 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 148 | `logical_ops_swf4` | 90 | 7.5s |  |
| 149 | `logical_ops_swf8` | 108 | 7.6s |  |
| 150 | `looping` | 6 | 7.5s |  |
| 151 | `mask_reapply` | 0 | 7.4s |  |
| 152 | `mask_with_drawing` | 0 | 7.4s |  |
| 153 | `math_min_max` | 101 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 154 | `math_swf6` | 530 | 7.8s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 155 | `math_swf7` | 530 | 7.8s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 156 | `math_swf8` | 530 | 7.8s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 157 | `matrix` | 171 | 7.9s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 158 | `mouse_listeners` | 67 | 7.7s |  |
| 159 | `mouse_wheel_enabled` | 2 | 7.7s |  |
| 160 | `movieclip_begin_gradient_fill` | 0 | 8.1s |  |
| 161 | `movieclip_blend_mode_property` | 35 | 7.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 162 | `movieclip_default_state` | 69 | 7.7s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 163 | `movieclip_depth_methods` | 98 | 7.7s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 164 | `movieclip_get_instance_at_depth` | 28 | 7.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 165 | `movieclip_line_gradient_style` | 0 | 8.2s |  |
| 166 | `movieclip_name_from_timeline` | 13 | 7.7s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 167 | `movieclip_prototype_extension` | 5 | 7.8s |  |
| 168 | `nested_textfields_in_buttons` | 0 | 7.6s |  |
| 169 | `netstream_play_flv_screen` | 0 | 20.9s |  |
| 170 | `new_method_wrap` | 4 | 7.4s |  |
| 171 | `new_object_enumerate` | 7 | 7.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 172 | `new_object_wrap` | 4 | 7.5s |  |
| 173 | `o` | 3 | 7.5s |  |
| 174 | `object_constructor` | 33 | 7.5s |  |
| 175 | `object_function` | 32 | 7.6s |  |
| 176 | `object_properties` | 31 | 7.7s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 177 | `object_prototypes` | 74 | 7.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 178 | `object_string_coerce_swf5` | 62 | 7.7s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 179 | `object_string_coerce_swf6` | 68 | 7.6s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 180 | `parse_int` | 64 | 7.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 181 | `point` | 175 | 7.8s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 182 | `primitive_instanceof` | 37 | 7.4s |  |
| 183 | `primitive_type_globals` | 557 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 184 | `printjob_props_swf5` | 45 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 185 | `printjob_props_swf6` | 45 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 186 | `printjob_props_swf7` | 45 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 187 | `prototype_delete` | 12 | 7.4s |  |
| 188 | `prototype_enumerate` | 5 | 7.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 189 | `prototype_properties` | 17 | 7.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 190 | `rectangle` | 745 | 8.2s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 191 | `recursive_prototypes` | 0 | 7.4s |  |
| 192 | `remove_movie_clip` | 29 | 7.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 193 | `root_onload` | 1 | 7.4s |  |
| 194 | `sandbox_type_local_file` | 1 | 7.4s |  |
| 195 | `sandbox_type_local_network` | 1 | 7.4s |  |
| 196 | `set_variable_scope` | 58 | 7.5s |  |
| 197 | `single_frame` | 1 | 7.4s |  |
| 198 | `sound_props_swf5` | 68 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 199 | `sound_props_swf6` | 68 | 7.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 200 | `sound_start_load` | 0 | 7.4s |  |
| 201 | `stage_object_enumerate` | 4 | 7.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 202 | `stage_object_properties_get_var` | 5 | 7.3s |  |
| 203 | `stage_property_representation` | 586 | 7.4s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 204 | `strictequals_swf6` | 902 | 8.8s |  |
| 205 | `strictly_equals` | 7 | 7.4s |  |
| 206 | `string_coercion` | 117 | 7.7s | [29](ruffle-tests/_investigation/complete/string_coercion.md) |
| 207 | `string_methods` | 285 | 8.0s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 208 | `string_methods_negative_args` | 240 | 7.5s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 209 | `string_methods_swfv5` | 275 | 7.9s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 210 | `string_ops_swf6` | 95 | 7.4s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 211 | `string_paths_basic` | 4 | 7.4s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 212 | `string_paths_keyevents` | 0 | 7.6s |  |
| 213 | `string_paths_timer` | 0 | 7.6s |  |
| 214 | `string_paths_variable_alias` | 4 | 7.5s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 215 | `swf4_actions_bool` | 96 | 7.6s |  |
| 216 | `swf4_bool` | 4 | 7.5s |  |
| 217 | `swf4_function_calls` | 7 | 7.5s |  |
| 218 | `swf5_encoding` | 3 | 7.6s |  |
| 219 | `swf7_case_sensitive` | 44 | 7.4s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 220 | `tab_ordering_properties_tab_index_edge_case` | 4 | 7.6s |  |
| 221 | `target_clip_removed` | 5 | 7.7s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 222 | `target_path` | 14 | 7.7s |  |
| 223 | `text_format` | 1146 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 224 | `text_format_display` | 21 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 225 | `text_format_font_max_length` | 2 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 226 | `text_format_rounding_swf7` | 840 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 227 | `text_format_rounding_swf8` | 840 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 228 | `textfield_background_color` | 11 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 229 | `textfield_border_color` | 11 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 230 | `textfield_maxchars` | 3 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 231 | `textfield_properties` | 44 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 232 | `textfield_props_swf5` | 175 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 233 | `textfield_props_swf6` | 210 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 234 | `textfield_props_swf7` | 210 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 235 | `textfield_props_swf8` | 210 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 236 | `textfield_text` | 7 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 237 | `textfield_variable` | 81 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 238 | `this_swf7` | 41 | 7.5s | [34](ruffle-tests/_investigation/complete/this_swf7.md) |
| 239 | `timeline_function_def` | 7 | 7.5s |  |
| 240 | `transform` | 70 | 7.6s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 241 | `try_catch_finally` | 118 | 7.6s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 242 | `try_finally_simple` | 16 | 7.6s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 243 | `typeof` | 22 | 7.6s |  |
| 244 | `typeof_globals` | 7 | 7.5s |  |
| 245 | `uncaught_exception` | 1 | 7.5s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 246 | `uncaught_exception_bubbled` | 1 | 7.4s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 247 | `undefined_to_string_swf6` | 4 | 7.4s |  |
| 248 | `unescape` | 43 | 7.5s |  |
| 249 | `unload_clip_event` | 4 | 7.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 250 | `use_hand_cursor` | 8 | 7.5s |  |
| 251 | `variable_args` | 5 | 7.6s |  |
| 252 | `waitforframe` | 7 | 7.5s |  |
| 253 | `waitforframe2` | 16 | 7.7s |  |
| 254 | `watch` | 117 | 7.7s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 255 | `watch_virtual_property_proto` | 2 | 7.5s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 256 | `with` | 49 | 7.5s | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 257 | `with_return` | 2 | 7.5s |  |
| 258 | `with_variable_scopes` | 43 | 7.6s | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 259 | `xml` | 15 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 260 | `xml_append_child` | 28 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 261 | `xml_append_child_with_parent` | 20 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 262 | `xml_attributes_read` | 4 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 263 | `xml_cdata` | 11 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 264 | `xml_child_nodes_edge_cases` | 4 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 265 | `xml_clone_expandos` | 19 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 266 | `xml_first_last_child` | 8 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 267 | `xml_has_child_nodes` | 3 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 268 | `xml_idmap` | 21 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 269 | `xml_ignore_comments` | 21 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 270 | `xml_ignore_white` | 34 | 9.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 271 | `xml_insert_before` | 20 | 7.5s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 272 | `xml_inspect_createmethods` | 15 | 7.4s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 273 | `xml_inspect_doctype` | 7 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 274 | `xml_inspect_parsexml` | 62 | 7.4s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 275 | `xml_inspect_xmldecl` | 7 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 276 | `xml_namespaces` | 203 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 277 | `xml_parent_and_child` | 5 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 278 | `xml_remove_node` | 22 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 279 | `xml_reparenting` | 14 | 7.4s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 280 | `xml_siblings` | 10 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 281 | `xml_to_string` | 13 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 282 | `xml_to_string_comment` | 1 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 283 | `xml_unescaping` | 23 | 7.4s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 284 | `xmlnode_proto` | 1 | 7.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**68 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 3 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `stage_object_properties` | 93.8% | 226 | 241 | 15 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 5 | `stage_object_properties_swf6` | 92.6% | 214 | 231 | 17 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 6 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 7 | `movieclip_focusenabled` | 82.8% | 82 | 99 | 17 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `selection` | 81.9% | 372 | 454 | 82 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 11 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 13 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `attach_movie` | 72.9% | 43 | 59 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 17 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 18 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 19 | `unload` | 69.2% | 36 | 52 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 20 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `export_assets` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 22 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 23 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 27 | `slash_syntax` | 64.3% | 9 | 14 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 28 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 29 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `string_paths_other` | 61.1% | 22 | 36 | 14 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 31 | `edittext_align` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 40 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 41 | `execution_order4` | 58.3% | 7 | 12 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 42 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 43 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 44 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 45 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 46 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 48 | `movieclip_hittest_shapeflag` | 57.1% | 193 | 338 | 145 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 49 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 51 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 52 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 53 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 54 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 55 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 56 | `edittext_html_condensewhite_swf7` | 52.4% | 163 | 311 | 148 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 59 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 62 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 63 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 64 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 65 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 66 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 67 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 68 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 8.9s |  |
| 2 | `goto_methods` | 9.8s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 10.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 10.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 10.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_library_state_values` | exit code -6 | 9.7s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_state_values` | exit code -6 | 10.6s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 17.5s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**327 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 3 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `stage_object_properties` | 93.8% | 226/241 | 241 | 241 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 5 | `stage_object_properties_swf6` | 92.6% | 214/231 | 231 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 6 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 7 | `movieclip_focusenabled` | 82.8% | 82/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `selection` | 81.9% | 372/454 | 454 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 11 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 12 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 13 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 17 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 18 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 19 | `unload` | 69.2% | 36/52 | 52 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 20 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 22 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 23 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 27 | `slash_syntax` | 64.3% | 9/14 | 14 | 14 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 28 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 29 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `string_paths_other` | 61.1% | 22/36 | 28 | 36 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 31 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 40 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 41 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 42 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 43 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 44 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 45 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 46 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 48 | `movieclip_hittest_shapeflag` | 57.1% | 193/338 | 338 | 338 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 49 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 51 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 52 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 53 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 54 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 55 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 56 | `edittext_html_condensewhite_swf7` | 52.4% | 163/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 59 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 62 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 63 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 64 | `loadmovie` | 50.0% | 1/2 | 1 | 2 |  |
| 65 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 66 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 67 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 68 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_html_condensewhite_swf8` | 48.9% | 152/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 71 | `goto_label` | 47.1% | 8/17 | 9 | 17 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 72 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 73 | `hittest_lockroot` | 46.7% | 7/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 74 | `register_globals_across_frames` | 46.7% | 7/15 | 15 | 15 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 75 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 76 | `unloadmovienum` | 46.2% | 6/13 | 12 | 13 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 77 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 79 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 |  |
| 80 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 81 | `mcl_as_broadcaster` | 41.7% | 5/12 | 8 | 12 |  |
| 82 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 83 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 84 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 85 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 86 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 87 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 88 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 89 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 90 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 94 | `loadmovienum` | 33.3% | 1/3 | 1 | 3 |  |
| 95 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 96 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 97 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 98 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 100 | `default_names` | 30.8% | 16/52 | 44 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 101 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 102 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 103 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 104 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 105 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 106 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 107 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 108 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 109 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 110 | `loadmovie_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 111 | `loadvariables2` | 25.0% | 2/8 | 2 | 8 |  |
| 112 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 113 | `unloadmovie` | 25.0% | 1/4 | 2 | 4 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 114 | `movieclip_getbounds` | 24.7% | 53/215 | 215 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 116 | `focusrect_property_swf5` | 23.2% | 287/1237 | 1236 | 1237 |  |
| 117 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 119 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 120 | `focus_remove` | 21.2% | 7/33 | 21 | 33 |  |
| 121 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 122 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 123 | `movieclip_in_removed_button` | 20.0% | 1/5 | 5 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 124 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 125 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 126 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 127 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 128 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 129 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 130 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 131 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 132 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 133 | `tell_target_invalid` | 16.7% | 1/6 | 5 | 6 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 134 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 135 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 136 | `path_string` | 15.2% | 49/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 137 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 138 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 139 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 140 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 141 | `removed_clip_halts_script` | 13.3% | 2/15 | 11 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 142 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 143 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 144 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 145 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 146 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 147 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 148 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 149 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 150 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 151 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 152 | `tab_ordering_events` | 11.3% | 17/150 | 26 | 150 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 153 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 |  |
| 154 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 155 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 156 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 157 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 158 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 159 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 160 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 161 | `tell_target` | 8.1% | 3/37 | 34 | 37 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 162 | `call` | 7.9% | 5/63 | 28 | 63 |  |
| 163 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 164 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 165 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 166 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 167 | `define_local` | 7.4% | 2/27 | 23 | 27 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 168 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 169 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 170 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 171 | `tab_ordering_reverse` | 5.9% | 3/51 | 3 | 51 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 172 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 173 | `swf4_actions_coercion_order` | 5.7% | 9/158 | 93 | 158 |  |
| 174 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 175 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 176 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 177 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 178 | `clip_events` | 5.3% | 1/19 | 13 | 19 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 179 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 180 | `button_keypress_vs_tab` | 5.0% | 1/20 | 1 | 20 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 181 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 182 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 183 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 184 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 185 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 186 | `tab_ordering_custom_basic` | 4.2% | 3/71 | 3 | 71 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 187 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 188 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 189 | `tab_ordering_automatic_basic` | 3.3% | 3/92 | 3 | 92 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 190 | `register_class` | 3.0% | 2/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 191 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 192 | `netconnection_send_remote` | 2.0% | 1/50 | 1 | 50 |  |
| 193 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 194 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 195 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 196 | `focus_keyboard_press` | 1.7% | 1/60 | 1 | 60 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 197 | `tab_ordering_children` | 1.4% | 3/208 | 3 | 208 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 198 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 199 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 200 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 201 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 202 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 203 | `tab_ordering_movieclip_enabled_default` | 0.6% | 3/462 | 3 | 462 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 204 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 205 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 206 | `global_proto_decls` | 0.2% | 9/4497 | 539 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 207 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 208 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 209 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 211 | `button_goto` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 212 | `button_key_events` | 0.0% | 0/14 | 0 | 14 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 213 | `button_key_events_special` | 0.0% | 0/45 | 0 | 45 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 214 | `button_keypress` | 0.0% | 0/3 | 0 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 215 | `button_keypress_vs_press` | 0.0% | 0/25 | 0 | 25 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 216 | `button_keypress_vs_textinput` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 217 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 218 | `click_block` | 0.0% | 0/5 | 0 | 5 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 219 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 220 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 221 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 222 | `cross_movie_root` | 0.0% | 0/10 | 7 | 10 |  |
| 223 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 224 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 225 | `drag_drop` | 0.0% | 0/10 | 0 | 10 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 226 | `drag_over_from_outside` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 227 | `drag_over_without_startdrag` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 228 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 229 | `edittext_drag_select` | 0.0% | 0/9 | 0 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 230 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 231 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 232 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 233 | `edittext_input_newlines` | 0.0% | 0/9 | 0 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 234 | `edittext_password_copy` | 0.0% | 0/4 | 0 | 4 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 235 | `edittext_paste_empty` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 236 | `edittext_place_caret` | 0.0% | 0/2 | 0 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 237 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 238 | `edittext_restrict_paste` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 239 | `edittext_tab_focus` | 0.0% | 0/13 | 0 | 13 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 240 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 241 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 242 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 243 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 244 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 245 | `focus_mouse` | 0.0% | 0/45 | 0 | 45 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 246 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 247 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 248 | `focus_root_movie` | 0.0% | 0/3 | 3 | 2 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 249 | `focusrect_focuslost` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 250 | `focusrect_swf6` | 0.0% | 0/42 | 0 | 42 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 251 | `form_loader_encoding_1` | 0.0% | 0/1 | 0 | 1 |  |
| 252 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 253 | `form_loader_encoding_3` | 0.0% | 0/3 | 0 | 3 |  |
| 254 | `form_loader_encoding_4` | 0.0% | 0/3 | 0 | 3 |  |
| 255 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 256 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 257 | `global_proto_decls_delete` | 0.0% | 0/4158 | 203 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 258 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 259 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 260 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 261 | `input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 262 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 263 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 264 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 265 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 266 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 267 | `loadmovie_replace_root` | 0.0% | 0/5 | 0 | 5 |  |
| 268 | `loadvariables` | 0.0% | 0/2 | 0 | 2 |  |
| 269 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 270 | `loadvariablesnum` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 272 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 273 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 274 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 275 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 277 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 278 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 279 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 280 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 281 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 282 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 283 | `mouse_events` | 0.0% | 0/8 | 0 | 8 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 284 | `mouse_events_visible_enabled` | 0.0% | 0/12 | 0 | 12 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 285 | `mouse_hover_events_while_dragging` | 0.0% | 0/1 | 0 | 1 | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 286 | `mouse_pos` | 0.0% | 0/665 | 8 | 665 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 287 | `mouse_pos_with_scale_factor` | 0.0% | 0/260 | 8 | 260 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 288 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 289 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 290 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 291 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 292 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 293 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 294 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 295 | `placeobject_occupied_depth` | 0.0% | 0/6 | 4 | 6 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 296 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 297 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 298 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 299 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 301 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 302 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 304 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 305 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 306 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 307 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 308 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 309 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 310 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 311 | `tab_ordering_automatic_order_grid` | 0.0% | 0/21 | 0 | 21 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 312 | `tab_ordering_automatic_order_same_position` | 0.0% | 0/12 | 0 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 313 | `tab_ordering_custom_duplicate_index` | 0.0% | 0/22 | 0 | 22 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 314 | `tab_ordering_custom_i32_vs_u32` | 0.0% | 0/12 | 0 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 315 | `tab_ordering_custom_m1` | 0.0% | 0/29 | 0 | 29 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 316 | `tab_ordering_events_mouse` | 0.0% | 0/65 | 0 | 65 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 317 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 318 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 319 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 320 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 321 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 322 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 323 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 324 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 325 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 326 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 327 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 4 | 10 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 2 | 6 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 12 | 2 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 1 | 16 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 16 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 17 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 18 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 12 | 46 |
| 19 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 20 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 21 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 22 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 23 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 24 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 25 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 26 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 27 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 2 | 7 |
| 28 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 2 | 5 |
| 29 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 30 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 6 | 7 |
| 31 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 32 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 3 | 16 |
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 26 | 44 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 3 | 9 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 2 | 3 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 268 | 147 | 121 |
