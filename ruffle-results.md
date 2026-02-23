# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-23 07:17 UTC

**Git SHA**: `6ad82ff6d0`

**Run Duration**: 85m 59s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **312** (50.4%) |
| Failing | 307 |
| Total expected lines | 91478 |
| Matching lines | 56585 (61.9%) |
| Mismatched lines | 34893 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 299 | 97.4% |
| Runtime Segfault | 5 | 1.6% |
| Runtime Error | 2 | 0.7% |
| Timeout | 1 | 0.3% |

## Passing Tests

**312 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 9.6s |  |
| 2 | `action_to_integer` | 28 | 8.0s |  |
| 3 | `add` | 28 | 8.1s |  |
| 4 | `add2` | 354 | 8.3s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 8.1s |  |
| 6 | `add_swf5` | 28 | 8.1s |  |
| 7 | `arguments` | 127 | 8.1s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 8.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 8.1s |  |
| 10 | `array_constructor` | 30 | 8.0s |  |
| 11 | `array_enumerate` | 4 | 8.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 8.1s |  |
| 13 | `array_properties` | 36 | 8.1s |  |
| 14 | `array_prototyping` | 12 | 8.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 8.0s |  |
| 16 | `array_sort` | 161 | 8.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_sort_random` | 443 | 8.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 8.2s |  |
| 19 | `array_trivial` | 209 | 8.2s |  |
| 20 | `as1_constructor_v6` | 35 | 8.1s |  |
| 21 | `as1_constructor_v7` | 35 | 9.0s |  |
| 22 | `as2_oop` | 13 | 8.1s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as_broadcaster_initialize` | 10 | 8.0s |  |
| 24 | `as_set_prop_flags_version` | 31 | 8.0s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `as_set_prop_flags_version_swf5` | 1 | 8.0s |  |
| 26 | `as_set_prop_flags_version_swf6` | 1 | 8.0s |  |
| 27 | `as_set_prop_flags_version_swf7` | 1 | 8.0s |  |
| 28 | `as_set_prop_flags_version_swf8` | 1 | 8.0s |  |
| 29 | `as_set_prop_flags_version_swf9` | 1 | 8.0s |  |
| 30 | `as_transformed_flag` | 20 | 8.0s |  |
| 31 | `attach_movie` | 59 | 8.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 32 | `attach_movie_stop` | 3 | 8.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `bad_swf_tag_past_eof` | 0 | 8.0s |  |
| 34 | `bitand` | 1058 | 10.5s |  |
| 35 | `bitmap_data_colortransform` | 0 | 8.2s |  |
| 36 | `bitmap_data_fillrect` | 0 | 8.0s |  |
| 37 | `bitmap_data_max_size_swf10` | 12 | 8.0s |  |
| 38 | `bitmap_data_max_size_swf9` | 10 | 7.9s |  |
| 39 | `bitmap_data_perlinnoise` | 0 | 8.5s |  |
| 40 | `bitmap_data_pixeldissolve_image` | 0 | 8.3s |  |
| 41 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.0s |  |
| 42 | `bitor` | 1058 | 10.5s |  |
| 43 | `biturshift` | 14 | 7.9s |  |
| 44 | `biturshift_swf8` | 14 | 8.4s |  |
| 45 | `bitxor` | 1058 | 10.7s |  |
| 46 | `boxed_primitives` | 24 | 8.1s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 47 | `button_children` | 8 | 8.1s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 48 | `button_goto` | 4 | 8.1s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 49 | `button_order` | 2 | 8.0s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 50 | `button_v5` | 18 | 8.0s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 51 | `button_v6` | 18 | 8.0s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 52 | `call_method_empty_name` | 1 | 8.0s |  |
| 53 | `capabilities_resolution` | 8 | 8.0s |  |
| 54 | `catch_references_registers` | 2 | 8.0s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 55 | `clone_sprite_types` | 24 | 8.1s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `closure_scope` | 7 | 8.1s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 57 | `color` | 57 | 8.3s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 58 | `color_transform` | 48 | 8.3s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 59 | `conflicting_instance_names` | 23 | 8.1s |  |
| 60 | `create_empty_movie_clip` | 3 | 8.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `define_function2` | 8 | 8.1s |  |
| 62 | `define_function2_preload` | 13 | 8.1s |  |
| 63 | `define_function2_preload_order` | 4 | 8.2s |  |
| 64 | `define_function_case_sensitive` | 2 | 8.0s |  |
| 65 | `delete` | 3 | 8.1s |  |
| 66 | `display_object_properties` | 2 | 8.0s |  |
| 67 | `divide_swf4` | 107 | 8.0s |  |
| 68 | `do_init_action` | 3 | 8.0s |  |
| 69 | `drag_drop` | 10 | 8.0s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 70 | `drag_over_from_outside` | 1 | 8.1s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 71 | `drag_over_without_startdrag` | 1 | 8.1s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 72 | `duplicate_movie_clip` | 20 | 8.0s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `edittext_antialiastype` | 296 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_autosize_setter` | 20 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_default_format` | 221 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_default_format_empty` | 95 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_default_format_font_style` | 335 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_html_align_swf7` | 52 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_html_align_swf8` | 52 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_html_entity` | 4 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_newline_stripping` | 64 | 13.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_password` | 5 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_password_copy` | 4 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_paste_empty` | 2 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_restrict_paste` | 5 | 10.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_width_height` | 103 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `empty_movieclip_can_attach_movies` | 11 | 8.2s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 88 | `enumerate` | 64 | 8.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 89 | `equals` | 32 | 8.1s |  |
| 90 | `equals2_swf5` | 926 | 9.8s |  |
| 91 | `equals2_swf6` | 926 | 9.7s |  |
| 92 | `equals2_swf7` | 926 | 9.7s |  |
| 93 | `equals_swf4` | 665 | 8.8s |  |
| 94 | `equals_swf4_alt` | 32 | 8.0s |  |
| 95 | `equals_swf5` | 32 | 8.0s |  |
| 96 | `error` | 58 | 8.0s |  |
| 97 | `escape` | 14 | 8.0s |  |
| 98 | `execution_order1` | 5 | 8.0s |  |
| 99 | `execution_order2` | 7 | 8.1s |  |
| 100 | `execution_order3` | 4 | 8.0s |  |
| 101 | `export_assets` | 3 | 7.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 102 | `extends_native_type` | 11 | 8.0s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 103 | `focusrect_mouse_swf8` | 0 | 8.0s |  |
| 104 | `focusrect_mouse_swf9` | 0 | 8.5s |  |
| 105 | `focusrect_swf5` | 6 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 106 | `focusrect_swf6` | 42 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 107 | `function_suppress_and_preload` | 28 | 8.4s |  |
| 108 | `get_variable_in_scope` | 29 | 8.3s |  |
| 109 | `getproperty` | 28 | 8.3s |  |
| 110 | `getproperty_swf4` | 28 | 9.8s |  |
| 111 | `getproperty_swf5` | 28 | 7.9s |  |
| 112 | `global_array` | 3 | 8.0s |  |
| 113 | `global_is_bare` | 7 | 7.9s |  |
| 114 | `globals_swf5` | 304 | 8.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 115 | `globals_swf6` | 304 | 8.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 116 | `globals_swf7` | 304 | 8.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 117 | `globals_swf8` | 304 | 8.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 118 | `goto_advance1` | 6 | 7.9s |  |
| 119 | `goto_advance2` | 2 | 7.9s |  |
| 120 | `goto_both_ways1` | 3 | 7.9s |  |
| 121 | `goto_both_ways2` | 3 | 7.9s |  |
| 122 | `goto_execution_order` | 2 | 7.9s |  |
| 123 | `goto_execution_order2` | 2 | 7.9s |  |
| 124 | `goto_frame_number` | 3 | 8.0s |  |
| 125 | `goto_rewind1` | 1 | 8.0s |  |
| 126 | `goto_rewind2` | 3 | 7.8s |  |
| 127 | `goto_rewind3` | 2 | 7.9s |  |
| 128 | `greater_swf6` | 1175 | 9.9s |  |
| 129 | `greater_swf7` | 1175 | 9.9s |  |
| 130 | `greaterthan_swf5` | 1 | 7.8s |  |
| 131 | `greaterthan_swf8` | 1 | 7.8s |  |
| 132 | `has_own_property` | 32 | 7.8s |  |
| 133 | `infinite_recursion_function` | 4 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 134 | `infinite_recursion_function_in_setter` | 131 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 135 | `infinite_recursion_virtual_property` | 67 | 7.8s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 136 | `init_array_invalid` | 4 | 7.8s |  |
| 137 | `init_object_invalid` | 4 | 9.7s |  |
| 138 | `is_finite` | 49 | 8.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 139 | `is_finite_swf6` | 49 | 8.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 140 | `is_prototype_of` | 89 | 8.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 141 | `issue_1086` | 1 | 8.2s |  |
| 142 | `issue_1104` | 2 | 8.2s |  |
| 143 | `issue_1671` | 0 | 8.2s |  |
| 144 | `issue_1906` | 4 | 8.3s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 145 | `issue_2166` | 9 | 8.4s |  |
| 146 | `issue_3446` | 1 | 8.3s |  |
| 147 | `issue_3522` | 2 | 8.2s |  |
| 148 | `issue_4377` | 2 | 8.2s |  |
| 149 | `issue_710` | 4 | 8.2s |  |
| 150 | `issue_768` | 3 | 8.2s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 151 | `issue_9327` | 2 | 8.0s |  |
| 152 | `issue_9885` | 2 | 8.0s |  |
| 153 | `key_isToggled` | 9 | 8.0s |  |
| 154 | `lessthan` | 41 | 8.1s |  |
| 155 | `lessthan2_swf5` | 1226 | 10.4s |  |
| 156 | `lessthan2_swf6` | 1226 | 10.5s |  |
| 157 | `lessthan2_swf7` | 1226 | 10.4s |  |
| 158 | `lessthan_swf4` | 902 | 9.6s |  |
| 159 | `lessthan_swf4_alt` | 41 | 8.2s |  |
| 160 | `lessthan_swf5` | 41 | 8.2s |  |
| 161 | `local_to_global` | 49 | 8.0s | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 162 | `localconnection_properties` | 8 | 7.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 163 | `logical_ops_swf4` | 90 | 7.9s |  |
| 164 | `logical_ops_swf8` | 108 | 7.9s |  |
| 165 | `looping` | 6 | 7.9s |  |
| 166 | `mask_reapply` | 0 | 7.9s |  |
| 167 | `mask_with_drawing` | 0 | 7.9s |  |
| 168 | `math_min_max` | 101 | 8.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 169 | `math_swf6` | 530 | 8.2s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 170 | `math_swf7` | 530 | 8.2s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 171 | `math_swf8` | 530 | 8.2s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 172 | `matrix` | 171 | 8.2s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 173 | `mouse_events` | 8 | 8.0s | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 174 | `mouse_hover_events_while_dragging` | 1 | 8.1s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 175 | `mouse_listeners` | 67 | 7.9s |  |
| 176 | `mouse_wheel_enabled` | 2 | 7.9s |  |
| 177 | `movieclip_begin_gradient_fill` | 0 | 8.4s |  |
| 178 | `movieclip_blend_mode_property` | 35 | 10.2s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 179 | `movieclip_depth_methods` | 98 | 8.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 180 | `movieclip_get_instance_at_depth` | 28 | 8.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 181 | `movieclip_line_gradient_style` | 0 | 9.8s |  |
| 182 | `movieclip_name_from_timeline` | 13 | 7.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `movieclip_prototype_extension` | 5 | 7.9s |  |
| 184 | `nested_textfields_in_buttons` | 0 | 7.9s |  |
| 185 | `netstream_play_flv_screen` | 0 | 20.7s |  |
| 186 | `new_method_wrap` | 4 | 8.2s |  |
| 187 | `new_object_enumerate` | 7 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 188 | `new_object_wrap` | 4 | 8.2s |  |
| 189 | `o` | 3 | 8.2s |  |
| 190 | `object_constructor` | 33 | 8.2s |  |
| 191 | `object_function` | 32 | 8.3s |  |
| 192 | `object_properties` | 31 | 8.3s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 193 | `object_prototypes` | 74 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 194 | `object_string_coerce_swf5` | 62 | 8.3s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 195 | `object_string_coerce_swf6` | 68 | 8.1s | [20](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 196 | `parse_int` | 64 | 8.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 197 | `placeobject_occupied_depth` | 6 | 8.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 198 | `point` | 175 | 8.5s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 199 | `primitive_instanceof` | 37 | 8.1s |  |
| 200 | `primitive_type_globals` | 557 | 9.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 201 | `printjob_props_swf5` | 45 | 7.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 202 | `printjob_props_swf6` | 45 | 8.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 203 | `printjob_props_swf7` | 45 | 8.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 204 | `prototype_delete` | 12 | 8.0s |  |
| 205 | `prototype_enumerate` | 5 | 8.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 206 | `prototype_properties` | 17 | 8.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 207 | `rectangle` | 745 | 8.9s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 208 | `recursive_prototypes` | 0 | 8.0s |  |
| 209 | `remove_movie_clip` | 29 | 8.4s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 210 | `root_onload` | 1 | 8.2s |  |
| 211 | `sandbox_type_local_file` | 1 | 8.0s |  |
| 212 | `sandbox_type_local_network` | 1 | 7.9s |  |
| 213 | `set_variable_scope` | 58 | 8.2s |  |
| 214 | `single_frame` | 1 | 8.1s |  |
| 215 | `slash_syntax` | 14 | 8.2s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 216 | `sound_props_swf5` | 68 | 8.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 217 | `sound_props_swf6` | 68 | 8.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 218 | `sound_start_load` | 0 | 8.2s |  |
| 219 | `stage_display_state` | 16 | 8.3s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 220 | `stage_object_enumerate` | 4 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 221 | `stage_object_properties` | 241 | 8.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 222 | `stage_object_properties_get_var` | 5 | 8.2s |  |
| 223 | `stage_property_representation` | 586 | 8.3s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 224 | `stage_scale_mode` | 39 | 8.4s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 225 | `strictequals_swf6` | 902 | 10.0s |  |
| 226 | `strictly_equals` | 7 | 8.3s |  |
| 227 | `string_coercion` | 117 | 8.6s | [29](ruffle-tests/_investigation/complete/string_coercion.md) |
| 228 | `string_methods` | 285 | 8.8s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 229 | `string_methods_negative_args` | 240 | 8.4s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 230 | `string_methods_swfv5` | 275 | 8.8s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 231 | `string_ops_swf6` | 95 | 8.4s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 232 | `string_paths_basic` | 4 | 8.2s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 233 | `string_paths_timer` | 0 | 8.0s |  |
| 234 | `string_paths_variable_alias` | 4 | 8.0s | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 235 | `swf4_actions_bool` | 96 | 8.1s |  |
| 236 | `swf4_bool` | 4 | 8.0s |  |
| 237 | `swf4_function_calls` | 7 | 8.1s |  |
| 238 | `swf5_encoding` | 3 | 8.0s |  |
| 239 | `swf7_case_sensitive` | 44 | 7.9s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 240 | `tab_ordering_automatic_basic` | 92 | 8.0s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 241 | `tab_ordering_automatic_order_grid` | 21 | 7.9s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 242 | `tab_ordering_children` | 208 | 8.1s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 243 | `tab_ordering_custom_basic` | 71 | 8.0s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 244 | `tab_ordering_custom_duplicate_index` | 22 | 8.0s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 245 | `tab_ordering_custom_i32_vs_u32` | 12 | 7.9s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 246 | `tab_ordering_custom_m1` | 29 | 8.0s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 247 | `tab_ordering_properties_tab_index_edge_case` | 4 | 8.3s |  |
| 248 | `tab_ordering_reverse` | 51 | 8.6s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 249 | `target_clip_removed` | 5 | 8.6s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 250 | `target_path` | 14 | 8.4s |  |
| 251 | `text_format` | 1146 | 8.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `text_format_display` | 21 | 8.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `text_format_font_max_length` | 2 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `text_format_rounding_swf7` | 840 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `text_format_rounding_swf8` | 840 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `textfield_background_color` | 11 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `textfield_border_color` | 11 | 8.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 258 | `textfield_maxchars` | 3 | 9.7s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `textfield_properties` | 44 | 8.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `textfield_props_swf5` | 175 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `textfield_props_swf6` | 210 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 262 | `textfield_props_swf7` | 210 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 263 | `textfield_props_swf8` | 210 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 264 | `textfield_text` | 7 | 7.9s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 265 | `textfield_variable` | 81 | 8.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 266 | `this_swf7` | 41 | 7.9s | [34](ruffle-tests/_investigation/complete/this_swf7.md) |
| 267 | `timeline_function_def` | 7 | 8.0s |  |
| 268 | `transform` | 70 | 8.1s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 269 | `try_catch_finally` | 118 | 8.1s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 270 | `try_finally_simple` | 16 | 8.0s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 271 | `typeof` | 22 | 8.0s |  |
| 272 | `typeof_globals` | 7 | 7.9s |  |
| 273 | `uncaught_exception` | 1 | 8.0s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 274 | `uncaught_exception_bubbled` | 1 | 8.0s | [36](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 275 | `undefined_to_string_swf6` | 4 | 8.0s |  |
| 276 | `unescape` | 43 | 8.0s |  |
| 277 | `unload_clip_event` | 4 | 8.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 278 | `use_hand_cursor` | 8 | 7.9s |  |
| 279 | `variable_args` | 5 | 8.1s |  |
| 280 | `waitforframe` | 7 | 7.9s |  |
| 281 | `waitforframe2` | 16 | 8.3s |  |
| 282 | `watch` | 117 | 8.3s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 283 | `watch_virtual_property_proto` | 2 | 8.2s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 284 | `with` | 49 | 8.2s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 285 | `with_return` | 2 | 8.1s |  |
| 286 | `with_variable_scopes` | 43 | 8.2s | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 287 | `xml` | 15 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 288 | `xml_append_child` | 28 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 289 | `xml_append_child_with_parent` | 20 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 290 | `xml_attributes_read` | 4 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 291 | `xml_cdata` | 11 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 292 | `xml_child_nodes_edge_cases` | 4 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `xml_clone_expandos` | 19 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 294 | `xml_first_last_child` | 8 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 295 | `xml_has_child_nodes` | 3 | 8.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 296 | `xml_idmap` | 21 | 8.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 297 | `xml_ignore_comments` | 21 | 8.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_ignore_white` | 34 | 9.7s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_insert_before` | 20 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 300 | `xml_inspect_createmethods` | 15 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 301 | `xml_inspect_doctype` | 7 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_inspect_parsexml` | 62 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_inspect_xmldecl` | 7 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_namespaces` | 203 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 305 | `xml_parent_and_child` | 5 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 306 | `xml_remove_node` | 22 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 307 | `xml_reparenting` | 14 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 308 | `xml_siblings` | 10 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 309 | `xml_to_string` | 13 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 310 | `xml_to_string_comment` | 1 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 311 | `xml_unescaping` | 23 | 8.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 312 | `xmlnode_proto` | 1 | 7.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**73 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `stage_object_properties_swf6` | 99.1% | 229 | 231 | 2 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `selection` | 95.6% | 434 | 454 | 20 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `movieclip_focusenabled` | 89.9% | 89 | 99 | 10 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `movieclip_default_state` | 88.4% | 61 | 69 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `button_properties_special_cases` | 86.4% | 19 | 22 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 10 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 11 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 13 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 14 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `tab_ordering_tabbable` | 76.6% | 36 | 47 | 11 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 18 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 19 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 20 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 21 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 23 | `unload` | 69.2% | 36 | 52 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `function_base_clip_removed` | 68.0% | 17 | 25 | 8 |  |
| 25 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 28 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 33 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 34 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
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
| 57 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 59 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 60 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 61 | `edittext_html_condensewhite_swf7` | 52.4% | 163 | 311 | 148 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
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
| 1 | `funky_function_calls` | 10.4s |  |
| 2 | `goto_methods` | 9.4s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 10.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 10.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 10.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_library_state_values` | exit code -6 | 10.3s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_state_values` | exit code -6 | 10.7s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 17.9s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**299 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `stage_object_properties_swf6` | 99.1% | 229/231 | 231 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `selection` | 95.6% | 434/454 | 454 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `movieclip_focusenabled` | 89.9% | 89/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `movieclip_default_state` | 88.4% | 61/69 | 69 | 69 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `button_properties_special_cases` | 86.4% | 19/22 | 22 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 10 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 11 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 13 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 14 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `tab_ordering_tabbable` | 76.6% | 36/47 | 47 | 47 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 18 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 19 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 20 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 21 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 23 | `unload` | 69.2% | 36/52 | 52 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `function_base_clip_removed` | 68.0% | 17/25 | 25 | 25 |  |
| 25 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 28 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 33 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 34 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
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
| 57 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 59 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 60 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 61 | `edittext_html_condensewhite_swf7` | 52.4% | 163/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
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
| 89 | `string_paths_variable_scopes` | 40.0% | 4/10 | 10 | 5 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 90 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 91 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 92 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 93 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 94 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
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
| 108 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 109 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 110 | `default_names` | 28.8% | 15/52 | 48 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
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
| 123 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 124 | `focusrect_property_swf5` | 23.2% | 287/1237 | 1236 | 1237 |  |
| 125 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 126 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 127 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 128 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 129 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 130 | `movieclip_in_removed_button` | 20.0% | 1/5 | 5 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 131 | `movieclip_init_object` | 20.0% | 1/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 132 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 133 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 134 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 135 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
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
| 146 | `register_and_init_order` | 14.7% | 34/231 | 85 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 147 | `path_string` | 14.6% | 47/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 148 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 149 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 151 | `tab_ordering_movieclip_enabled_default` | 13.6% | 63/462 | 432 | 462 | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 152 | `removed_clip_halts_script` | 13.3% | 2/15 | 13 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 153 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 154 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
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
| 193 | `register_class` | 4.5% | 3/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 194 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 195 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 196 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 197 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 198 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 199 | `netconnection_send_remote` | 2.0% | 1/50 | 1 | 50 |  |
| 200 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 201 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 202 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 203 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 204 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 205 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 206 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 207 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 208 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 209 | `global_proto_decls` | 0.3% | 13/4497 | 568 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 210 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 211 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 212 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 213 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 215 | `button_key_events` | 0.0% | 0/14 | 0 | 14 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 216 | `button_key_events_special` | 0.0% | 0/45 | 5 | 45 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 217 | `button_keypress_vs_press` | 0.0% | 0/25 | 7 | 25 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 218 | `click_block` | 0.0% | 0/5 | 0 | 5 | [17](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 219 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 220 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 221 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 222 | `cross_movie_root` | 0.0% | 0/10 | 7 | 10 |  |
| 223 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 224 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 225 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 226 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 227 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 228 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 229 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 230 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 231 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 232 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 233 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 234 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 235 | `focus_mouse` | 0.0% | 0/45 | 4 | 45 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 236 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 237 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 238 | `focus_root_movie` | 0.0% | 0/3 | 3 | 2 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 239 | `focusrect_focuslost` | 0.0% | 0/4 | 1 | 4 | [9](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) |
| 240 | `form_loader_encoding_1` | 0.0% | 0/1 | 0 | 1 |  |
| 241 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 242 | `form_loader_encoding_3` | 0.0% | 0/3 | 0 | 3 |  |
| 243 | `form_loader_encoding_4` | 0.0% | 0/3 | 0 | 3 |  |
| 244 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 245 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 246 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 247 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 248 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 249 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 250 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 251 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 252 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 253 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 254 | `loadmovie_replace_root` | 0.0% | 0/5 | 0 | 5 |  |
| 255 | `loadvariables` | 0.0% | 0/2 | 0 | 2 |  |
| 256 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 257 | `loadvariablesnum` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 259 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 260 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 261 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 262 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 263 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 264 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 265 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 266 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 267 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 268 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 269 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 270 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 271 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 272 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 273 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 274 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 275 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 276 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 277 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 278 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 279 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 280 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 281 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 282 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 283 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 284 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 285 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/complete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 286 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 287 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 288 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 289 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 290 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 291 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 292 | `text_blocks_clicks` | 0.0% | 0/4 | 0 | 4 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 293 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 294 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 295 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 296 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 297 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/incomplete/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 1 | 16 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 16 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 17 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 1 | 4 |
| 18 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 16 | 42 |
| 19 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 20 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 21 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 22 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 23 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 24 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 25 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 4 | 11 |
| 26 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 27 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 5 | 4 |
| 28 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 5 | 2 |
| 29 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 30 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 31 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 10 | 6 |
| 32 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 29 | 41 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 5 | 7 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 268 | 147 | 121 |
