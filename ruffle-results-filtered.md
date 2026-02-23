# Ruffle Test Results (Filtered)

**Date**: 2026-02-23 03:18 UTC

**Git SHA**: `28de609adb`

**Run Duration**: 82m 44s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **285** (59.5%) |
| Failing | 194 |
| Total expected lines | 71494 |
| Matching lines | 45749 (64.0%) |
| Mismatched lines | 25745 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 186 | 95.9% |
| Segfault | 5 | 2.6% |
| Runtime Error | 2 | 1.0% |
| Timeout | 1 | 0.5% |

## Passing Tests

**285 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.0s |  |
| 2 | `action_to_integer` | 28 | 7.6s |  |
| 3 | `add` | 28 | 7.6s |  |
| 4 | `add2` | 354 | 7.9s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 7.6s |  |
| 6 | `add_swf5` | 28 | 7.6s |  |
| 7 | `arguments` | 127 | 7.6s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 7.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 7.7s |  |
| 10 | `array_constructor` | 30 | 7.7s |  |
| 11 | `array_enumerate` | 4 | 7.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 7.7s |  |
| 13 | `array_properties` | 36 | 7.7s |  |
| 14 | `array_prototyping` | 12 | 7.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 7.7s |  |
| 16 | `array_sort_random` | 443 | 7.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 8.1s |  |
| 18 | `array_trivial` | 209 | 8.0s |  |
| 19 | `as1_constructor_v6` | 35 | 7.8s |  |
| 20 | `as1_constructor_v7` | 35 | 7.7s |  |
| 21 | `as2_oop` | 13 | 7.9s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 7.8s |  |
| 23 | `as_set_prop_flags_version` | 31 | 7.8s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 7.7s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 7.7s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 7.7s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 7.8s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 7.8s |  |
| 29 | `as_transformed_flag` | 20 | 7.9s |  |
| 30 | `bad_swf_tag_past_eof` | 0 | 7.8s |  |
| 31 | `bitand` | 1058 | 10.6s |  |
| 32 | `bitmap_data_colortransform` | 0 | 8.1s |  |
| 33 | `bitmap_data_fillrect` | 0 | 7.9s |  |
| 34 | `bitmap_data_max_size_swf10` | 12 | 7.9s |  |
| 35 | `bitmap_data_max_size_swf9` | 10 | 7.8s |  |
| 36 | `bitmap_data_perlinnoise` | 0 | 8.4s |  |
| 37 | `bitmap_data_pixeldissolve_image` | 0 | 8.2s |  |
| 38 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.9s |  |
| 39 | `bitor` | 1058 | 10.6s |  |
| 40 | `biturshift` | 14 | 8.8s |  |
| 41 | `biturshift_swf8` | 14 | 7.7s |  |
| 42 | `bitxor` | 1058 | 10.3s |  |
| 43 | `boxed_primitives` | 24 | 7.8s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 44 | `button_children` | 8 | 7.7s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 45 | `button_goto` | 4 | 7.8s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 46 | `button_order` | 2 | 7.7s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 47 | `button_v5` | 18 | 7.6s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 48 | `button_v6` | 18 | 7.7s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 49 | `call_method_empty_name` | 1 | 7.7s |  |
| 50 | `capabilities_resolution` | 8 | 7.6s |  |
| 51 | `catch_references_registers` | 2 | 7.6s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 52 | `clone_sprite_types` | 24 | 7.7s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `closure_scope` | 7 | 7.8s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 54 | `color` | 57 | 7.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 55 | `color_transform` | 48 | 7.8s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 56 | `conflicting_instance_names` | 23 | 7.8s |  |
| 57 | `create_empty_movie_clip` | 3 | 7.6s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `define_function2` | 8 | 7.6s |  |
| 59 | `define_function2_preload` | 13 | 7.7s |  |
| 60 | `define_function2_preload_order` | 4 | 7.7s |  |
| 61 | `define_function_case_sensitive` | 2 | 7.7s |  |
| 62 | `delete` | 3 | 7.8s |  |
| 63 | `display_object_properties` | 2 | 7.6s |  |
| 64 | `divide_swf4` | 107 | 7.7s |  |
| 65 | `do_init_action` | 3 | 7.7s |  |
| 66 | `duplicate_movie_clip` | 20 | 7.7s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 67 | `edittext_antialiastype` | 296 | 10.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_autosize_setter` | 20 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_default_format` | 221 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `edittext_default_format_empty` | 95 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `edittext_default_format_font_style` | 335 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_html_align_swf7` | 52 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_html_align_swf8` | 52 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_html_entity` | 4 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_newline_stripping` | 64 | 13.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_width_height` | 103 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `enumerate` | 64 | 8.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 78 | `equals` | 32 | 8.1s |  |
| 79 | `equals2_swf5` | 926 | 10.0s |  |
| 80 | `equals2_swf6` | 926 | 10.0s |  |
| 81 | `equals2_swf7` | 926 | 10.5s |  |
| 82 | `equals_swf4` | 665 | 9.3s |  |
| 83 | `equals_swf4_alt` | 32 | 8.3s |  |
| 84 | `equals_swf5` | 32 | 8.5s |  |
| 85 | `error` | 58 | 8.0s |  |
| 86 | `escape` | 14 | 8.0s |  |
| 87 | `execution_order1` | 5 | 8.0s |  |
| 88 | `execution_order2` | 7 | 8.1s |  |
| 89 | `execution_order3` | 4 | 7.9s |  |
| 90 | `extends_native_type` | 11 | 8.0s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 91 | `focusrect_mouse_swf8` | 0 | 7.7s |  |
| 92 | `focusrect_mouse_swf9` | 0 | 7.8s |  |
| 93 | `focusrect_swf5` | 6 | 8.0s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 94 | `function_suppress_and_preload` | 28 | 8.0s |  |
| 95 | `get_variable_in_scope` | 29 | 7.9s |  |
| 96 | `getproperty` | 28 | 7.9s |  |
| 97 | `getproperty_swf4` | 28 | 7.9s |  |
| 98 | `getproperty_swf5` | 28 | 7.8s |  |
| 99 | `global_array` | 3 | 7.8s |  |
| 100 | `global_is_bare` | 7 | 7.8s |  |
| 101 | `globals_swf5` | 304 | 8.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 102 | `globals_swf6` | 304 | 8.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 103 | `globals_swf7` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 104 | `globals_swf8` | 304 | 8.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 105 | `goto_advance1` | 6 | 7.9s |  |
| 106 | `goto_advance2` | 2 | 7.8s |  |
| 107 | `goto_both_ways1` | 3 | 9.9s |  |
| 108 | `goto_both_ways2` | 3 | 8.0s |  |
| 109 | `goto_execution_order` | 2 | 7.8s |  |
| 110 | `goto_execution_order2` | 2 | 7.9s |  |
| 111 | `goto_frame_number` | 3 | 8.0s |  |
| 112 | `goto_rewind1` | 1 | 8.0s |  |
| 113 | `goto_rewind2` | 3 | 7.9s |  |
| 114 | `goto_rewind3` | 2 | 7.8s |  |
| 115 | `greater_swf6` | 1175 | 9.7s |  |
| 116 | `greater_swf7` | 1175 | 9.8s |  |
| 117 | `greaterthan_swf5` | 1 | 7.7s |  |
| 118 | `greaterthan_swf8` | 1 | 7.7s |  |
| 119 | `has_own_property` | 32 | 7.8s |  |
| 120 | `infinite_recursion_function` | 4 | 7.7s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 121 | `infinite_recursion_function_in_setter` | 131 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 122 | `infinite_recursion_virtual_property` | 67 | 7.7s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 123 | `init_array_invalid` | 4 | 7.7s |  |
| 124 | `init_object_invalid` | 4 | 7.8s |  |
| 125 | `is_finite` | 49 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 126 | `is_finite_swf6` | 49 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 127 | `is_prototype_of` | 89 | 7.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 128 | `issue_1086` | 1 | 7.9s |  |
| 129 | `issue_1104` | 2 | 7.8s |  |
| 130 | `issue_1671` | 0 | 7.8s |  |
| 131 | `issue_1906` | 4 | 7.8s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 132 | `issue_2166` | 9 | 7.8s |  |
| 133 | `issue_3446` | 1 | 7.7s |  |
| 134 | `issue_3522` | 2 | 7.8s |  |
| 135 | `issue_4377` | 2 | 7.7s |  |
| 136 | `issue_710` | 4 | 7.8s |  |
| 137 | `issue_768` | 3 | 7.8s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 138 | `issue_9327` | 2 | 7.9s |  |
| 139 | `issue_9885` | 2 | 7.9s |  |
| 140 | `lessthan` | 41 | 7.9s |  |
| 141 | `lessthan2_swf5` | 1226 | 10.0s |  |
| 142 | `lessthan2_swf6` | 1226 | 10.0s |  |
| 143 | `lessthan2_swf7` | 1226 | 10.0s |  |
| 144 | `lessthan_swf4` | 902 | 9.0s |  |
| 145 | `lessthan_swf4_alt` | 41 | 7.8s |  |
| 146 | `lessthan_swf5` | 41 | 7.8s |  |
| 147 | `local_to_global` | 49 | 7.7s | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 148 | `localconnection_properties` | 8 | 7.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 149 | `logical_ops_swf4` | 90 | 7.7s |  |
| 150 | `logical_ops_swf8` | 108 | 7.7s |  |
| 151 | `looping` | 6 | 7.7s |  |
| 152 | `mask_reapply` | 0 | 7.7s |  |
| 153 | `mask_with_drawing` | 0 | 7.6s |  |
| 154 | `math_min_max` | 101 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 155 | `math_swf6` | 530 | 8.0s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 156 | `math_swf7` | 530 | 8.0s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 157 | `math_swf8` | 530 | 7.9s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 158 | `matrix` | 171 | 8.0s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 159 | `movieclip_begin_gradient_fill` | 0 | 8.1s |  |
| 160 | `movieclip_blend_mode_property` | 35 | 7.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 161 | `movieclip_default_state` | 69 | 7.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 162 | `movieclip_depth_methods` | 98 | 7.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 163 | `movieclip_get_instance_at_depth` | 28 | 7.7s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 164 | `movieclip_line_gradient_style` | 0 | 8.2s |  |
| 165 | `movieclip_name_from_timeline` | 13 | 7.6s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 166 | `movieclip_prototype_extension` | 5 | 7.6s |  |
| 167 | `nested_textfields_in_buttons` | 0 | 7.7s |  |
| 168 | `netstream_play_flv_screen` | 0 | 20.8s |  |
| 169 | `new_method_wrap` | 4 | 7.6s |  |
| 170 | `new_object_enumerate` | 7 | 7.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 171 | `new_object_wrap` | 4 | 7.5s |  |
| 172 | `o` | 3 | 7.5s |  |
| 173 | `object_constructor` | 33 | 7.6s |  |
| 174 | `object_function` | 32 | 7.6s |  |
| 175 | `object_properties` | 31 | 7.7s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 176 | `object_prototypes` | 74 | 7.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 177 | `object_string_coerce_swf5` | 62 | 7.6s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 178 | `object_string_coerce_swf6` | 68 | 7.6s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 179 | `parse_int` | 64 | 7.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 180 | `point` | 175 | 8.0s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 181 | `primitive_instanceof` | 37 | 7.6s |  |
| 182 | `primitive_type_globals` | 557 | 7.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 183 | `printjob_props_swf5` | 45 | 7.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 184 | `printjob_props_swf6` | 45 | 7.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 185 | `printjob_props_swf7` | 45 | 7.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 186 | `prototype_delete` | 12 | 7.6s |  |
| 187 | `prototype_enumerate` | 5 | 7.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 188 | `prototype_properties` | 17 | 7.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 189 | `rectangle` | 745 | 8.3s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 190 | `recursive_prototypes` | 0 | 7.5s |  |
| 191 | `remove_movie_clip` | 29 | 7.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 192 | `root_onload` | 1 | 7.7s |  |
| 193 | `sandbox_type_local_file` | 1 | 7.7s |  |
| 194 | `sandbox_type_local_network` | 1 | 7.8s |  |
| 195 | `set_variable_scope` | 58 | 7.7s |  |
| 196 | `single_frame` | 1 | 7.7s |  |
| 197 | `slash_syntax` | 14 | 7.7s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 198 | `sound_props_swf5` | 68 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 199 | `sound_props_swf6` | 68 | 7.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 200 | `sound_start_load` | 0 | 7.8s |  |
| 201 | `stage_display_state` | 16 | 7.8s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 202 | `stage_object_enumerate` | 4 | 7.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 203 | `stage_object_properties` | 241 | 8.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 204 | `stage_object_properties_get_var` | 5 | 7.7s |  |
| 205 | `stage_property_representation` | 586 | 7.7s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 206 | `stage_scale_mode` | 39 | 7.8s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 207 | `strictequals_swf6` | 902 | 9.3s |  |
| 208 | `strictly_equals` | 7 | 7.7s |  |
| 209 | `string_coercion` | 117 | 8.1s | [29](ruffle-tests/_investigation/complete/string_coercion.md) |
| 210 | `string_methods` | 285 | 8.3s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 211 | `string_methods_negative_args` | 240 | 7.8s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 212 | `string_methods_swfv5` | 275 | 8.2s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 213 | `string_ops_swf6` | 95 | 7.8s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 214 | `string_paths_basic` | 4 | 7.7s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 215 | `string_paths_timer` | 0 | 7.7s |  |
| 216 | `string_paths_variable_alias` | 4 | 7.8s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 217 | `swf4_actions_bool` | 96 | 7.8s |  |
| 218 | `swf4_bool` | 4 | 7.7s |  |
| 219 | `swf4_function_calls` | 7 | 8.0s |  |
| 220 | `swf5_encoding` | 3 | 7.6s |  |
| 221 | `swf7_case_sensitive` | 44 | 7.6s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 222 | `tab_ordering_properties_tab_index_edge_case` | 4 | 7.5s |  |
| 223 | `target_clip_removed` | 5 | 7.7s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 224 | `target_path` | 14 | 7.5s |  |
| 225 | `text_format` | 1146 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 226 | `text_format_display` | 21 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 227 | `text_format_font_max_length` | 2 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 228 | `text_format_rounding_swf7` | 840 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 229 | `text_format_rounding_swf8` | 840 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 230 | `textfield_background_color` | 11 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 231 | `textfield_border_color` | 11 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 232 | `textfield_maxchars` | 3 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 233 | `textfield_properties` | 44 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 234 | `textfield_props_swf5` | 175 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 235 | `textfield_props_swf6` | 210 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 236 | `textfield_props_swf7` | 210 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 237 | `textfield_props_swf8` | 210 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 238 | `textfield_text` | 7 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 239 | `textfield_variable` | 81 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 240 | `this_swf7` | 41 | 7.6s | [34](ruffle-tests/_investigation/complete/this_swf7.md) |
| 241 | `timeline_function_def` | 7 | 7.7s |  |
| 242 | `transform` | 70 | 7.8s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 243 | `try_catch_finally` | 118 | 7.8s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 244 | `try_finally_simple` | 16 | 7.6s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 245 | `typeof` | 22 | 7.6s |  |
| 246 | `typeof_globals` | 7 | 7.6s |  |
| 247 | `uncaught_exception` | 1 | 7.6s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 248 | `uncaught_exception_bubbled` | 1 | 7.8s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 249 | `undefined_to_string_swf6` | 4 | 7.7s |  |
| 250 | `unescape` | 43 | 7.7s |  |
| 251 | `unload_clip_event` | 4 | 7.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 252 | `use_hand_cursor` | 8 | 7.7s |  |
| 253 | `variable_args` | 5 | 7.8s |  |
| 254 | `waitforframe` | 7 | 7.6s |  |
| 255 | `waitforframe2` | 16 | 7.7s |  |
| 256 | `watch` | 117 | 7.9s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 257 | `watch_virtual_property_proto` | 2 | 7.7s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 258 | `with` | 49 | 7.7s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 259 | `with_return` | 2 | 7.6s |  |
| 260 | `with_variable_scopes` | 43 | 7.8s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 261 | `xml` | 15 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 262 | `xml_append_child` | 28 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 263 | `xml_append_child_with_parent` | 20 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 264 | `xml_cdata` | 11 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 265 | `xml_child_nodes_edge_cases` | 4 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 266 | `xml_clone_expandos` | 19 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 267 | `xml_first_last_child` | 8 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 268 | `xml_has_child_nodes` | 3 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 269 | `xml_idmap` | 21 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 270 | `xml_ignore_comments` | 21 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 271 | `xml_ignore_white` | 34 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 272 | `xml_insert_before` | 20 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 273 | `xml_inspect_createmethods` | 15 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 274 | `xml_inspect_doctype` | 7 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 275 | `xml_inspect_parsexml` | 62 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 276 | `xml_inspect_xmldecl` | 7 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 277 | `xml_namespaces` | 203 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 278 | `xml_parent_and_child` | 5 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 279 | `xml_remove_node` | 22 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 280 | `xml_reparenting` | 14 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 281 | `xml_siblings` | 10 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 282 | `xml_to_string` | 13 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 283 | `xml_to_string_comment` | 1 | 7.6s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 284 | `xml_unescaping` | 23 | 7.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 285 | `xmlnode_proto` | 1 | 7.8s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**53 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stage_object_properties_swf6` | 99.1% | 229 | 231 | 2 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 2 | `selection` | 95.6% | 434 | 454 | 20 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `movieclip_focusenabled` | 85.9% | 85 | 99 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 7 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 8 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 9 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 10 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 12 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `attach_movie` | 72.9% | 43 | 59 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 15 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 16 | `unload` | 69.2% | 36 | 52 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 17 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `export_assets` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 19 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 20 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 24 | `button_properties_special_cases` | 63.6% | 14 | 22 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 25 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 26 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `string_paths_other` | 61.1% | 22 | 36 | 14 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 36 | `execution_order4` | 58.3% | 7 | 12 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 39 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `movieclip_hittest_shapeflag` | 57.1% | 193 | 338 | 145 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 41 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 43 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 44 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 45 | `edittext_html_condensewhite_swf7` | 52.4% | 163 | 311 | 148 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 50 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 51 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 52 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 53 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 10.0s |  |
| 2 | `goto_methods` | 10.1s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 10.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 10.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 10.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_library_state_values` | exit code -6 | 9.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_state_values` | exit code -6 | 10.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 17.7s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**186 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stage_object_properties_swf6` | 99.1% | 229/231 | 231 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 2 | `selection` | 95.6% | 434/454 | 454 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `movieclip_focusenabled` | 85.9% | 85/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 7 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 8 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 9 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 10 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 12 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 14 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 15 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 16 | `unload` | 69.2% | 36/52 | 52 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 17 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 19 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 20 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 24 | `button_properties_special_cases` | 63.6% | 14/22 | 21 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 25 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 26 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `string_paths_other` | 61.1% | 22/36 | 28 | 36 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 36 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 39 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `movieclip_hittest_shapeflag` | 57.1% | 193/338 | 338 | 338 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 41 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 43 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 44 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 45 | `edittext_html_condensewhite_swf7` | 52.4% | 163/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 50 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 51 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 52 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 53 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_html_condensewhite_swf8` | 48.9% | 152/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 56 | `goto_label` | 47.1% | 8/17 | 9 | 17 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 57 | `hittest_lockroot` | 46.7% | 7/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 58 | `register_globals_across_frames` | 46.7% | 7/15 | 15 | 15 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 59 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 61 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 62 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 63 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 64 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 65 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 66 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 67 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 68 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 72 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 74 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 76 | `swf5_no_closure` | 31.6% | 6/19 | 15 | 19 |  |
| 77 | `default_names` | 30.8% | 16/52 | 44 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 78 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 79 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 80 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 81 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 82 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 83 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 84 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 85 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 86 | `movieclip_getbounds` | 24.7% | 53/215 | 215 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 87 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 88 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 90 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 92 | `movieclip_in_removed_button` | 20.0% | 1/5 | 5 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 93 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 94 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 95 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 96 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 97 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 98 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 99 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 100 | `tell_target_invalid` | 16.7% | 1/6 | 5 | 6 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 101 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 102 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 103 | `path_string` | 14.6% | 47/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 104 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 105 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 106 | `removed_clip_halts_script` | 13.3% | 2/15 | 11 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 107 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 108 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 109 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 110 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 112 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 114 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 116 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 118 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 119 | `tell_target` | 8.1% | 3/37 | 34 | 37 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 120 | `call` | 7.9% | 5/63 | 28 | 63 |  |
| 121 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 122 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 123 | `define_local` | 7.4% | 2/27 | 23 | 27 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 124 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 125 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 126 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 127 | `swf4_actions_coercion_order` | 5.7% | 9/158 | 93 | 158 |  |
| 128 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 129 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 130 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 131 | `clip_events` | 5.3% | 1/19 | 13 | 19 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 132 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 133 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 134 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 135 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 136 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 137 | `register_class` | 3.0% | 2/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 138 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 139 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 140 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 141 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 142 | `global_proto_decls` | 0.3% | 13/4497 | 568 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 143 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 144 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 145 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 146 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 147 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 148 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 149 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 151 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 152 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 153 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 154 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 155 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 156 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 157 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 158 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 159 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 160 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 161 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 162 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 163 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 164 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 165 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 166 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 167 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 169 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 170 | `placeobject_occupied_depth` | 0.0% | 0/6 | 4 | 6 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 172 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 173 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 174 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 175 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 176 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 177 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 178 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 179 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 180 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 181 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 182 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 183 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 184 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 185 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 186 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 5 | 9 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 2 | 6 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
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
| 19 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 20 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 21 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 22 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 23 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 24 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 25 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 26 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 27 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 5 | 4 |
| 28 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 5 | 2 |
| 29 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 30 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 31 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 32 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 25 | 45 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 3 | 9 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 193 | 144 | 49 |
