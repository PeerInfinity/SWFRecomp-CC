# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-23 00:43 UTC

**Git SHA**: `2a0809e5f3`

**Run Duration**: 83m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **307** (49.6%) |
| Failing | 312 |
| Total expected lines | 91478 |
| Matching lines | 56289 (61.5%) |
| Mismatched lines | 35189 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 304 | 97.4% |
| Runtime Segfault | 5 | 1.6% |
| Runtime Error | 2 | 0.6% |
| Timeout | 1 | 0.3% |

## Passing Tests

**307 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 9.5s |  |
| 2 | `action_to_integer` | 28 | 8.0s |  |
| 3 | `add` | 28 | 8.0s |  |
| 4 | `add2` | 354 | 8.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 8.1s |  |
| 6 | `add_swf5` | 28 | 8.0s |  |
| 7 | `arguments` | 127 | 8.2s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 7.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 7.9s |  |
| 10 | `array_constructor` | 30 | 7.9s |  |
| 11 | `array_enumerate` | 4 | 7.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 8.0s |  |
| 13 | `array_properties` | 36 | 7.9s |  |
| 14 | `array_prototyping` | 12 | 7.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 8.1s |  |
| 16 | `array_sort` | 161 | 8.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_sort_random` | 443 | 7.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 8.1s |  |
| 19 | `array_trivial` | 209 | 8.0s |  |
| 20 | `as1_constructor_v6` | 35 | 7.9s |  |
| 21 | `as1_constructor_v7` | 35 | 8.0s |  |
| 22 | `as2_oop` | 13 | 8.2s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as_broadcaster_initialize` | 10 | 7.9s |  |
| 24 | `as_set_prop_flags_version` | 31 | 8.0s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `as_set_prop_flags_version_swf5` | 1 | 8.0s |  |
| 26 | `as_set_prop_flags_version_swf6` | 1 | 8.0s |  |
| 27 | `as_set_prop_flags_version_swf7` | 1 | 8.0s |  |
| 28 | `as_set_prop_flags_version_swf8` | 1 | 7.9s |  |
| 29 | `as_set_prop_flags_version_swf9` | 1 | 7.9s |  |
| 30 | `as_transformed_flag` | 20 | 8.0s |  |
| 31 | `bad_swf_tag_past_eof` | 0 | 8.0s |  |
| 32 | `bitand` | 1058 | 10.8s |  |
| 33 | `bitmap_data_colortransform` | 0 | 8.3s |  |
| 34 | `bitmap_data_fillrect` | 0 | 8.2s |  |
| 35 | `bitmap_data_max_size_swf10` | 12 | 8.0s |  |
| 36 | `bitmap_data_max_size_swf9` | 10 | 7.9s |  |
| 37 | `bitmap_data_perlinnoise` | 0 | 8.5s |  |
| 38 | `bitmap_data_pixeldissolve_image` | 0 | 8.4s |  |
| 39 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.1s |  |
| 40 | `bitor` | 1058 | 10.8s |  |
| 41 | `biturshift` | 14 | 8.2s |  |
| 42 | `biturshift_swf8` | 14 | 7.8s |  |
| 43 | `bitxor` | 1058 | 10.8s |  |
| 44 | `boxed_primitives` | 24 | 8.0s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 45 | `button_children` | 8 | 7.9s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 46 | `button_goto` | 4 | 8.0s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 47 | `button_order` | 2 | 8.0s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 48 | `button_v5` | 18 | 8.0s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 49 | `button_v6` | 18 | 8.1s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 50 | `call_method_empty_name` | 1 | 8.2s |  |
| 51 | `capabilities_resolution` | 8 | 8.4s |  |
| 52 | `catch_references_registers` | 2 | 8.4s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 53 | `clone_sprite_types` | 24 | 8.0s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 54 | `closure_scope` | 7 | 8.1s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 55 | `color` | 57 | 8.4s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 56 | `color_transform` | 48 | 8.4s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 57 | `conflicting_instance_names` | 23 | 8.1s |  |
| 58 | `create_empty_movie_clip` | 3 | 8.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 59 | `define_function2` | 8 | 7.9s |  |
| 60 | `define_function2_preload` | 13 | 7.9s |  |
| 61 | `define_function2_preload_order` | 4 | 7.8s |  |
| 62 | `define_function_case_sensitive` | 2 | 7.9s |  |
| 63 | `delete` | 3 | 8.0s |  |
| 64 | `display_object_properties` | 2 | 7.9s |  |
| 65 | `divide_swf4` | 107 | 8.1s |  |
| 66 | `do_init_action` | 3 | 8.1s |  |
| 67 | `drag_drop` | 10 | 8.3s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 68 | `drag_over_from_outside` | 1 | 8.3s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 69 | `drag_over_without_startdrag` | 1 | 8.3s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 70 | `duplicate_movie_clip` | 20 | 8.1s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 71 | `edittext_antialiastype` | 296 | 8.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_autosize_setter` | 20 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_default_format` | 221 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_default_format_empty` | 95 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_default_format_font_style` | 335 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_html_align_swf7` | 52 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_html_align_swf8` | 52 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_html_entity` | 4 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_newline_stripping` | 64 | 12.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_password` | 5 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_password_copy` | 4 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_paste_empty` | 2 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_restrict_paste` | 5 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_width_height` | 103 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `enumerate` | 64 | 8.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 86 | `equals` | 32 | 7.8s |  |
| 87 | `equals2_swf5` | 926 | 9.6s |  |
| 88 | `equals2_swf6` | 926 | 9.3s |  |
| 89 | `equals2_swf7` | 926 | 9.3s |  |
| 90 | `equals_swf4` | 665 | 8.3s |  |
| 91 | `equals_swf4_alt` | 32 | 7.6s |  |
| 92 | `equals_swf5` | 32 | 7.6s |  |
| 93 | `error` | 58 | 7.6s |  |
| 94 | `escape` | 14 | 7.6s |  |
| 95 | `execution_order1` | 5 | 7.6s |  |
| 96 | `execution_order2` | 7 | 7.7s |  |
| 97 | `execution_order3` | 4 | 7.6s |  |
| 98 | `extends_native_type` | 11 | 7.6s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 99 | `focusrect_mouse_swf8` | 0 | 7.7s |  |
| 100 | `focusrect_mouse_swf9` | 0 | 7.7s |  |
| 101 | `focusrect_swf5` | 6 | 7.8s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 102 | `focusrect_swf6` | 42 | 7.7s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 103 | `function_suppress_and_preload` | 28 | 7.7s |  |
| 104 | `get_variable_in_scope` | 29 | 7.7s |  |
| 105 | `getproperty` | 28 | 7.7s |  |
| 106 | `getproperty_swf4` | 28 | 7.6s |  |
| 107 | `getproperty_swf5` | 28 | 7.6s |  |
| 108 | `global_array` | 3 | 7.6s |  |
| 109 | `global_is_bare` | 7 | 7.6s |  |
| 110 | `globals_swf5` | 304 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 111 | `globals_swf6` | 304 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 112 | `globals_swf7` | 304 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 113 | `globals_swf8` | 304 | 7.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 114 | `goto_advance1` | 6 | 7.6s |  |
| 115 | `goto_advance2` | 2 | 7.7s |  |
| 116 | `goto_both_ways1` | 3 | 8.0s |  |
| 117 | `goto_both_ways2` | 3 | 8.0s |  |
| 118 | `goto_execution_order` | 2 | 7.9s |  |
| 119 | `goto_execution_order2` | 2 | 8.1s |  |
| 120 | `goto_frame_number` | 3 | 8.0s |  |
| 121 | `goto_rewind1` | 1 | 8.0s |  |
| 122 | `goto_rewind2` | 3 | 8.0s |  |
| 123 | `goto_rewind3` | 2 | 7.9s |  |
| 124 | `greater_swf6` | 1175 | 10.2s |  |
| 125 | `greater_swf7` | 1175 | 10.1s |  |
| 126 | `greaterthan_swf5` | 1 | 7.8s |  |
| 127 | `greaterthan_swf8` | 1 | 7.9s |  |
| 128 | `has_own_property` | 32 | 7.9s |  |
| 129 | `infinite_recursion_function` | 4 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 130 | `infinite_recursion_function_in_setter` | 131 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 131 | `infinite_recursion_virtual_property` | 67 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 132 | `init_array_invalid` | 4 | 7.9s |  |
| 133 | `init_object_invalid` | 4 | 7.8s |  |
| 134 | `is_finite` | 49 | 7.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 135 | `is_finite_swf6` | 49 | 7.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 136 | `is_prototype_of` | 89 | 7.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 137 | `issue_1086` | 1 | 7.8s |  |
| 138 | `issue_1104` | 2 | 7.9s |  |
| 139 | `issue_1671` | 0 | 7.8s |  |
| 140 | `issue_1906` | 4 | 7.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 141 | `issue_2166` | 9 | 7.8s |  |
| 142 | `issue_3446` | 1 | 7.9s |  |
| 143 | `issue_3522` | 2 | 7.9s |  |
| 144 | `issue_4377` | 2 | 7.9s |  |
| 145 | `issue_710` | 4 | 7.8s |  |
| 146 | `issue_768` | 3 | 7.9s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 147 | `issue_9327` | 2 | 7.9s |  |
| 148 | `issue_9885` | 2 | 7.9s |  |
| 149 | `key_isToggled` | 9 | 7.9s |  |
| 150 | `lessthan` | 41 | 8.0s |  |
| 151 | `lessthan2_swf5` | 1226 | 10.2s |  |
| 152 | `lessthan2_swf6` | 1226 | 10.1s |  |
| 153 | `lessthan2_swf7` | 1226 | 10.3s |  |
| 154 | `lessthan_swf4` | 902 | 9.2s |  |
| 155 | `lessthan_swf4_alt` | 41 | 7.9s |  |
| 156 | `lessthan_swf5` | 41 | 7.9s |  |
| 157 | `local_to_global` | 49 | 7.8s | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 158 | `localconnection_properties` | 8 | 7.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 159 | `logical_ops_swf4` | 90 | 7.7s |  |
| 160 | `logical_ops_swf8` | 108 | 7.6s |  |
| 161 | `looping` | 6 | 7.6s |  |
| 162 | `mask_reapply` | 0 | 7.7s |  |
| 163 | `mask_with_drawing` | 0 | 7.6s |  |
| 164 | `math_min_max` | 101 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 165 | `math_swf6` | 530 | 7.9s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 166 | `math_swf7` | 530 | 8.0s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 167 | `math_swf8` | 530 | 7.9s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 168 | `matrix` | 171 | 8.0s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 169 | `mouse_events` | 8 | 7.7s | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 170 | `mouse_hover_events_while_dragging` | 1 | 7.8s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 171 | `mouse_listeners` | 67 | 7.7s |  |
| 172 | `mouse_wheel_enabled` | 2 | 7.7s |  |
| 173 | `movieclip_begin_gradient_fill` | 0 | 8.2s |  |
| 174 | `movieclip_blend_mode_property` | 35 | 7.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 175 | `movieclip_default_state` | 69 | 8.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `movieclip_depth_methods` | 98 | 8.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 177 | `movieclip_get_instance_at_depth` | 28 | 7.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 178 | `movieclip_line_gradient_style` | 0 | 8.3s |  |
| 179 | `movieclip_name_from_timeline` | 13 | 7.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 180 | `movieclip_prototype_extension` | 5 | 7.8s |  |
| 181 | `nested_textfields_in_buttons` | 0 | 7.7s |  |
| 182 | `netstream_play_flv_screen` | 0 | 20.6s |  |
| 183 | `new_method_wrap` | 4 | 7.7s |  |
| 184 | `new_object_enumerate` | 7 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 185 | `new_object_wrap` | 4 | 7.8s |  |
| 186 | `o` | 3 | 7.8s |  |
| 187 | `object_constructor` | 33 | 7.8s |  |
| 188 | `object_function` | 32 | 7.8s |  |
| 189 | `object_properties` | 31 | 7.9s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 190 | `object_prototypes` | 74 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 191 | `object_string_coerce_swf5` | 62 | 7.8s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 192 | `object_string_coerce_swf6` | 68 | 7.8s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 193 | `parse_int` | 64 | 8.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 194 | `point` | 175 | 8.1s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 195 | `primitive_instanceof` | 37 | 7.8s |  |
| 196 | `primitive_type_globals` | 557 | 7.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 197 | `printjob_props_swf5` | 45 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 198 | `printjob_props_swf6` | 45 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 199 | `printjob_props_swf7` | 45 | 7.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 200 | `prototype_delete` | 12 | 7.8s |  |
| 201 | `prototype_enumerate` | 5 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 202 | `prototype_properties` | 17 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 203 | `rectangle` | 745 | 8.6s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 204 | `recursive_prototypes` | 0 | 7.8s |  |
| 205 | `remove_movie_clip` | 29 | 7.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 206 | `root_onload` | 1 | 7.8s |  |
| 207 | `sandbox_type_local_file` | 1 | 7.8s |  |
| 208 | `sandbox_type_local_network` | 1 | 7.8s |  |
| 209 | `set_variable_scope` | 58 | 7.8s |  |
| 210 | `single_frame` | 1 | 7.7s |  |
| 211 | `slash_syntax` | 14 | 7.8s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 212 | `sound_props_swf5` | 68 | 8.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 213 | `sound_props_swf6` | 68 | 8.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 214 | `sound_start_load` | 0 | 7.9s |  |
| 215 | `stage_display_state` | 16 | 7.8s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 216 | `stage_object_enumerate` | 4 | 7.8s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 217 | `stage_object_properties_get_var` | 5 | 7.8s |  |
| 218 | `stage_property_representation` | 586 | 7.8s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 219 | `stage_scale_mode` | 39 | 7.8s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 220 | `strictequals_swf6` | 902 | 9.4s |  |
| 221 | `strictly_equals` | 7 | 7.8s |  |
| 222 | `string_coercion` | 117 | 8.1s | [29](ruffle-tests/_investigation/complete/string_coercion.md) |
| 223 | `string_methods` | 285 | 8.4s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 224 | `string_methods_negative_args` | 240 | 7.9s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 225 | `string_methods_swfv5` | 275 | 8.4s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 226 | `string_ops_swf6` | 95 | 7.9s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 227 | `string_paths_basic` | 4 | 7.8s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 228 | `string_paths_timer` | 0 | 8.0s |  |
| 229 | `string_paths_variable_alias` | 4 | 7.9s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 230 | `swf4_actions_bool` | 96 | 7.8s |  |
| 231 | `swf4_bool` | 4 | 7.7s |  |
| 232 | `swf4_function_calls` | 7 | 9.2s |  |
| 233 | `swf5_encoding` | 3 | 7.5s |  |
| 234 | `swf7_case_sensitive` | 44 | 7.6s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 235 | `tab_ordering_automatic_basic` | 92 | 7.7s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 236 | `tab_ordering_automatic_order_grid` | 21 | 7.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 237 | `tab_ordering_children` | 208 | 7.7s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 238 | `tab_ordering_custom_basic` | 71 | 7.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 239 | `tab_ordering_custom_duplicate_index` | 22 | 7.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 240 | `tab_ordering_custom_i32_vs_u32` | 12 | 7.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 241 | `tab_ordering_custom_m1` | 29 | 7.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 242 | `tab_ordering_properties_tab_index_edge_case` | 4 | 7.5s |  |
| 243 | `tab_ordering_reverse` | 51 | 7.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 244 | `target_clip_removed` | 5 | 7.7s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 245 | `target_path` | 14 | 7.5s |  |
| 246 | `text_format` | 1146 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 247 | `text_format_display` | 21 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `text_format_font_max_length` | 2 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 249 | `text_format_rounding_swf7` | 840 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 250 | `text_format_rounding_swf8` | 840 | 7.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 251 | `textfield_background_color` | 11 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `textfield_border_color` | 11 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `textfield_maxchars` | 3 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `textfield_properties` | 44 | 7.6s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `textfield_props_swf5` | 175 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `textfield_props_swf6` | 210 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `textfield_props_swf7` | 210 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 258 | `textfield_props_swf8` | 210 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `textfield_text` | 7 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `textfield_variable` | 81 | 7.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `this_swf7` | 41 | 7.6s | [34](ruffle-tests/_investigation/complete/this_swf7.md) |
| 262 | `timeline_function_def` | 7 | 7.7s |  |
| 263 | `transform` | 70 | 8.0s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 264 | `try_catch_finally` | 118 | 8.1s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 265 | `try_finally_simple` | 16 | 7.9s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 266 | `typeof` | 22 | 8.0s |  |
| 267 | `typeof_globals` | 7 | 7.9s |  |
| 268 | `uncaught_exception` | 1 | 7.9s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 269 | `uncaught_exception_bubbled` | 1 | 7.9s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 270 | `undefined_to_string_swf6` | 4 | 8.0s |  |
| 271 | `unescape` | 43 | 8.0s |  |
| 272 | `unload_clip_event` | 4 | 8.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 273 | `use_hand_cursor` | 8 | 8.0s |  |
| 274 | `variable_args` | 5 | 8.1s |  |
| 275 | `waitforframe` | 7 | 7.9s |  |
| 276 | `waitforframe2` | 16 | 8.0s |  |
| 277 | `watch` | 117 | 8.2s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 278 | `watch_virtual_property_proto` | 2 | 8.0s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 279 | `with` | 49 | 7.9s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 280 | `with_return` | 2 | 7.9s |  |
| 281 | `with_variable_scopes` | 43 | 8.0s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 282 | `xml` | 15 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 283 | `xml_append_child` | 28 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 284 | `xml_append_child_with_parent` | 20 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 285 | `xml_attributes_read` | 4 | 7.8s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 286 | `xml_cdata` | 11 | 7.8s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 287 | `xml_child_nodes_edge_cases` | 4 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 288 | `xml_clone_expandos` | 19 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 289 | `xml_first_last_child` | 8 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 290 | `xml_has_child_nodes` | 3 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 291 | `xml_idmap` | 21 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 292 | `xml_ignore_comments` | 21 | 8.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `xml_ignore_white` | 34 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 294 | `xml_insert_before` | 20 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 295 | `xml_inspect_createmethods` | 15 | 7.8s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 296 | `xml_inspect_doctype` | 7 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 297 | `xml_inspect_parsexml` | 62 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_inspect_xmldecl` | 7 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_namespaces` | 203 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 300 | `xml_parent_and_child` | 5 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 301 | `xml_remove_node` | 22 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_reparenting` | 14 | 8.3s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_siblings` | 10 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_to_string` | 13 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 305 | `xml_to_string_comment` | 1 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 306 | `xml_unescaping` | 23 | 8.4s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 307 | `xmlnode_proto` | 1 | 8.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**73 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `selection` | 95.6% | 434 | 454 | 20 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `stage_object_properties` | 93.8% | 226 | 241 | 15 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 6 | `stage_object_properties_swf6` | 92.6% | 214 | 231 | 17 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 7 | `movieclip_focusenabled` | 85.9% | 85 | 99 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 10 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 11 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 12 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `tab_ordering_tabbable` | 76.6% | 36 | 47 | 11 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 15 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 16 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 17 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `attach_movie` | 72.9% | 43 | 59 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 20 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 22 | `unload` | 69.2% | 36 | 52 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 23 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `export_assets` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 26 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 27 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 28 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 31 | `button_properties_special_cases` | 63.6% | 14 | 22 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 32 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 33 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `string_paths_other` | 61.1% | 22 | 36 | 14 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 35 | `edittext_align` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 44 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 45 | `execution_order4` | 58.3% | 7 | 12 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 48 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 49 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 50 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 52 | `movieclip_hittest_shapeflag` | 57.1% | 193 | 338 | 145 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 55 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 56 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 57 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 58 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 59 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 60 | `edittext_html_condensewhite_swf7` | 52.4% | 163 | 311 | 148 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 62 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 63 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 67 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 68 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 69 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 70 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 71 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 72 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 73 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 9.7s |  |
| 2 | `goto_methods` | 10.0s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 10.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 10.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 10.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_library_state_values` | exit code -6 | 9.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_state_values` | exit code -6 | 10.3s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 19.1s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**304 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `selection` | 95.6% | 434/454 | 454 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `stage_object_properties` | 93.8% | 226/241 | 241 | 241 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 6 | `stage_object_properties_swf6` | 92.6% | 214/231 | 231 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 7 | `movieclip_focusenabled` | 85.9% | 85/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 10 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 11 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 12 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `tab_ordering_tabbable` | 76.6% | 36/47 | 47 | 47 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 15 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 16 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 17 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 19 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 20 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 22 | `unload` | 69.2% | 36/52 | 52 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 23 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 26 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 27 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 28 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 31 | `button_properties_special_cases` | 63.6% | 14/22 | 21 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 32 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 33 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `string_paths_other` | 61.1% | 22/36 | 28 | 36 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 35 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 44 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 45 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 48 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 49 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 50 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 52 | `movieclip_hittest_shapeflag` | 57.1% | 193/338 | 338 | 338 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 55 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 56 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 57 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 58 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 59 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 60 | `edittext_html_condensewhite_swf7` | 52.4% | 163/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 62 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 63 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 67 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 68 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 69 | `loadmovie` | 50.0% | 1/2 | 1 | 2 |  |
| 70 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 71 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 72 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 73 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_html_condensewhite_swf8` | 48.9% | 152/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 76 | `goto_label` | 47.1% | 8/17 | 9 | 17 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 77 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 78 | `hittest_lockroot` | 46.7% | 7/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 79 | `register_globals_across_frames` | 46.7% | 7/15 | 15 | 15 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 80 | `unloadmovienum` | 46.2% | 6/13 | 12 | 13 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 81 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 83 | `mouse_pos` | 43.8% | 291/665 | 656 | 665 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 84 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 |  |
| 85 | `mouse_pos_with_scale_factor` | 42.7% | 111/260 | 251 | 260 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 86 | `mcl_as_broadcaster` | 41.7% | 5/12 | 8 | 12 |  |
| 87 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 88 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 89 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 90 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 91 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 92 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 93 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 94 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 95 | `button_keypress` | 33.3% | 1/3 | 2 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 96 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 100 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 101 | `loadmovienum` | 33.3% | 1/3 | 1 | 3 |  |
| 102 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 103 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 104 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 105 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 107 | `swf5_no_closure` | 31.6% | 6/19 | 15 | 19 |  |
| 108 | `default_names` | 30.8% | 16/52 | 44 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 109 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 110 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 111 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 112 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 113 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 114 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 115 | `button_keypress_vs_textinput` | 25.0% | 1/4 | 2 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 116 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 117 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 118 | `loadmovie_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 119 | `loadvariables2` | 25.0% | 2/8 | 2 | 8 |  |
| 120 | `mouse_events_visible_enabled` | 25.0% | 3/12 | 10 | 12 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 121 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 122 | `unloadmovie` | 25.0% | 1/4 | 2 | 4 | [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 123 | `movieclip_getbounds` | 24.7% | 53/215 | 215 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 125 | `focusrect_property_swf5` | 23.2% | 287/1237 | 1236 | 1237 |  |
| 126 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 128 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 129 | `focus_remove` | 21.2% | 7/33 | 21 | 33 |  |
| 130 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 131 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 132 | `movieclip_in_removed_button` | 20.0% | 1/5 | 5 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 133 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 134 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 135 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 136 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 137 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 138 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 139 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 140 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 141 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 142 | `tell_target_invalid` | 16.7% | 1/6 | 5 | 6 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 143 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 144 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 145 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 146 | `path_string` | 14.6% | 47/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 147 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 148 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 150 | `tab_ordering_movieclip_enabled_default` | 13.6% | 63/462 | 432 | 462 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 151 | `removed_clip_halts_script` | 13.3% | 2/15 | 11 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 152 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 153 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 154 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 155 | `tab_ordering_events` | 12.7% | 19/150 | 83 | 150 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 156 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 157 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 158 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 159 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 160 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 161 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 162 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 |  |
| 163 | `button_keypress_vs_tab` | 10.0% | 2/20 | 14 | 20 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 164 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 165 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 166 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 167 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 169 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 170 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 171 | `tell_target` | 8.1% | 3/37 | 34 | 37 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 172 | `call` | 7.9% | 5/63 | 28 | 63 |  |
| 173 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 174 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 175 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 177 | `define_local` | 7.4% | 2/27 | 23 | 27 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 178 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 180 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 181 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 182 | `swf4_actions_coercion_order` | 5.7% | 9/158 | 93 | 158 |  |
| 183 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 184 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 185 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 187 | `clip_events` | 5.3% | 1/19 | 13 | 19 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 188 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 189 | `focus_keyboard_press` | 5.0% | 3/60 | 14 | 60 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 190 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 191 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 192 | `tab_ordering_events_mouse` | 4.6% | 3/65 | 36 | 65 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 193 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 194 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 195 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 196 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 197 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 198 | `register_class` | 3.0% | 2/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 199 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 200 | `netconnection_send_remote` | 2.0% | 1/50 | 1 | 50 |  |
| 201 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 202 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 203 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 204 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 205 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 206 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 207 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 208 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 209 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 210 | `global_proto_decls` | 0.3% | 13/4497 | 568 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 211 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 212 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 213 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 214 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 215 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 216 | `button_key_events` | 0.0% | 0/14 | 0 | 14 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 217 | `button_key_events_special` | 0.0% | 0/45 | 5 | 45 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 218 | `button_keypress_vs_press` | 0.0% | 0/25 | 7 | 25 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 219 | `click_block` | 0.0% | 0/5 | 0 | 5 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 220 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 221 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 222 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 223 | `cross_movie_root` | 0.0% | 0/10 | 7 | 10 |  |
| 224 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 225 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 226 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 227 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 228 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 229 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 230 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 231 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 232 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 233 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 234 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 235 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 236 | `focus_mouse` | 0.0% | 0/45 | 4 | 45 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 237 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 238 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 239 | `focus_root_movie` | 0.0% | 0/3 | 3 | 2 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 240 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 241 | `form_loader_encoding_1` | 0.0% | 0/1 | 0 | 1 |  |
| 242 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 243 | `form_loader_encoding_3` | 0.0% | 0/3 | 0 | 3 |  |
| 244 | `form_loader_encoding_4` | 0.0% | 0/3 | 0 | 3 |  |
| 245 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 246 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 247 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 248 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 249 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 250 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 251 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 252 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 253 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 254 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 255 | `loadmovie_replace_root` | 0.0% | 0/5 | 0 | 5 |  |
| 256 | `loadvariables` | 0.0% | 0/2 | 0 | 2 |  |
| 257 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 258 | `loadvariablesnum` | 0.0% | 0/2 | 0 | 2 |  |
| 259 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 261 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 262 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 263 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 265 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 266 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 267 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 268 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 269 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 270 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 272 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 273 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 274 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 275 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 276 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 277 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 278 | `placeobject_occupied_depth` | 0.0% | 0/6 | 4 | 6 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 279 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 280 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 281 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 282 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 283 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 284 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 285 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 286 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 287 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 288 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 289 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 290 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 291 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 292 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 294 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 295 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 296 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 297 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 298 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 299 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 300 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 301 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 5 | 9 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 2 | 6 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 12 | 2 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 1 | 16 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 16 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 17 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 1 | 4 |
| 18 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 12 | 46 |
| 19 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 20 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 21 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 22 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 23 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 24 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 25 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 26 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 27 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 4 | 5 |
| 28 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 4 | 3 |
| 29 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 30 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 31 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 10 | 6 |
| 32 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 29 | 41 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 3 | 9 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 268 | 147 | 121 |
