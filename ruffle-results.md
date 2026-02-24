# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-24 00:26 UTC

**Git SHA**: `a3b4b418e4`

**Run Duration**: 89m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **319** (51.5%) |
| Failing | 300 |
| Total expected lines | 91478 |
| Matching lines | 56832 (62.1%) |
| Mismatched lines | 34646 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 292 | 97.3% |
| Runtime Segfault | 5 | 1.7% |
| Runtime Error | 2 | 0.7% |
| Timeout | 1 | 0.3% |

## Passing Tests

**319 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.5s |  |
| 2 | `action_to_integer` | 28 | 8.3s |  |
| 3 | `add` | 28 | 8.3s |  |
| 4 | `add2` | 354 | 8.6s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 8.3s |  |
| 6 | `add_swf5` | 28 | 8.3s |  |
| 7 | `arguments` | 127 | 8.3s | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 8.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 8.3s |  |
| 10 | `array_constructor` | 30 | 8.4s |  |
| 11 | `array_enumerate` | 4 | 8.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 8.3s |  |
| 13 | `array_properties` | 36 | 8.3s |  |
| 14 | `array_prototyping` | 12 | 8.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 8.4s |  |
| 16 | `array_sort` | 161 | 9.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_sort_random` | 443 | 8.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 8.5s |  |
| 19 | `array_trivial` | 209 | 8.4s |  |
| 20 | `as1_constructor_v6` | 35 | 8.4s |  |
| 21 | `as1_constructor_v7` | 35 | 8.4s |  |
| 22 | `as2_oop` | 13 | 8.5s | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as_broadcaster_initialize` | 10 | 8.5s |  |
| 24 | `as_set_prop_flags_version` | 31 | 8.2s | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 25 | `as_set_prop_flags_version_swf5` | 1 | 8.2s |  |
| 26 | `as_set_prop_flags_version_swf6` | 1 | 8.3s |  |
| 27 | `as_set_prop_flags_version_swf7` | 1 | 8.2s |  |
| 28 | `as_set_prop_flags_version_swf8` | 1 | 8.2s |  |
| 29 | `as_set_prop_flags_version_swf9` | 1 | 8.3s |  |
| 30 | `as_transformed_flag` | 20 | 8.3s |  |
| 31 | `attach_movie` | 59 | 8.3s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 32 | `attach_movie_stop` | 3 | 8.2s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `bad_swf_tag_past_eof` | 0 | 8.7s |  |
| 34 | `bitand` | 1058 | 11.8s |  |
| 35 | `bitmap_data_colortransform` | 0 | 9.0s |  |
| 36 | `bitmap_data_fillrect` | 0 | 8.7s |  |
| 37 | `bitmap_data_max_size_swf10` | 12 | 8.6s |  |
| 38 | `bitmap_data_max_size_swf9` | 10 | 8.6s |  |
| 39 | `bitmap_data_perlinnoise` | 0 | 9.1s |  |
| 40 | `bitmap_data_pixeldissolve_image` | 0 | 9.1s |  |
| 41 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.8s |  |
| 42 | `bitor` | 1058 | 11.5s |  |
| 43 | `biturshift` | 14 | 8.6s |  |
| 44 | `biturshift_swf8` | 14 | 10.0s |  |
| 45 | `bitxor` | 1058 | 11.6s |  |
| 46 | `boxed_primitives` | 24 | 8.8s | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 47 | `button_children` | 8 | 8.7s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 48 | `button_goto` | 4 | 8.8s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 49 | `button_order` | 2 | 8.5s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 50 | `button_v5` | 18 | 8.8s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 51 | `button_v6` | 18 | 8.6s | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 52 | `call_method_empty_name` | 1 | 8.5s |  |
| 53 | `capabilities_resolution` | 8 | 8.4s |  |
| 54 | `catch_references_registers` | 2 | 8.5s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 55 | `clip_events` | 19 | 8.8s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 56 | `clone_sprite_types` | 24 | 8.3s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `closure_scope` | 7 | 8.5s | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 58 | `color` | 57 | 8.5s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 59 | `color_transform` | 48 | 8.4s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 60 | `conflicting_instance_names` | 23 | 8.4s |  |
| 61 | `create_empty_movie_clip` | 3 | 8.4s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 62 | `define_function2` | 8 | 8.3s |  |
| 63 | `define_function2_preload` | 13 | 8.4s |  |
| 64 | `define_function2_preload_order` | 4 | 10.5s |  |
| 65 | `define_function_case_sensitive` | 2 | 8.3s |  |
| 66 | `delete` | 3 | 8.4s |  |
| 67 | `display_object_properties` | 2 | 8.2s |  |
| 68 | `divide_swf4` | 107 | 8.3s |  |
| 69 | `do_init_action` | 3 | 8.3s |  |
| 70 | `drag_drop` | 10 | 8.3s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 71 | `drag_over_from_outside` | 1 | 8.5s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 72 | `drag_over_without_startdrag` | 1 | 8.5s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 73 | `duplicate_movie_clip` | 20 | 8.4s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 74 | `edittext_antialiastype` | 296 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_autosize_setter` | 20 | 8.7s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_default_format` | 221 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_default_format_empty` | 95 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_default_format_font_style` | 335 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_html_align_swf7` | 52 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_html_align_swf8` | 52 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_html_entity` | 4 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_newline_stripping` | 64 | 12.9s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_password` | 5 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_password_copy` | 4 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_paste_empty` | 2 | 8.1s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_restrict_paste` | 5 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_width_height` | 103 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `empty_movieclip_can_attach_movies` | 11 | 9.2s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 89 | `enumerate` | 64 | 8.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 90 | `equals` | 32 | 8.4s |  |
| 91 | `equals2_swf5` | 926 | 10.2s |  |
| 92 | `equals2_swf6` | 926 | 10.2s |  |
| 93 | `equals2_swf7` | 926 | 10.2s |  |
| 94 | `equals_swf4` | 665 | 9.2s |  |
| 95 | `equals_swf4_alt` | 32 | 8.3s |  |
| 96 | `equals_swf5` | 32 | 8.4s |  |
| 97 | `error` | 58 | 8.3s |  |
| 98 | `escape` | 14 | 8.3s |  |
| 99 | `execution_order1` | 5 | 8.5s |  |
| 100 | `execution_order2` | 7 | 8.4s |  |
| 101 | `execution_order3` | 4 | 8.4s |  |
| 102 | `export_assets` | 3 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 103 | `extends_native_type` | 11 | 8.6s | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 104 | `focus_root_movie` | 2 | 8.7s |  |
| 105 | `focusrect_focuslost` | 4 | 8.5s |  |
| 106 | `focusrect_mouse_swf8` | 0 | 8.6s |  |
| 107 | `focusrect_mouse_swf9` | 0 | 8.7s |  |
| 108 | `focusrect_swf5` | 6 | 8.4s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 109 | `focusrect_swf6` | 42 | 8.3s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 110 | `function_suppress_and_preload` | 28 | 8.3s |  |
| 111 | `get_variable_in_scope` | 29 | 8.3s |  |
| 112 | `getproperty` | 28 | 8.2s |  |
| 113 | `getproperty_swf4` | 28 | 8.3s |  |
| 114 | `getproperty_swf5` | 28 | 8.1s |  |
| 115 | `global_array` | 3 | 8.1s |  |
| 116 | `global_is_bare` | 7 | 8.0s |  |
| 117 | `globals_swf5` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 118 | `globals_swf6` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 119 | `globals_swf7` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 120 | `globals_swf8` | 304 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 121 | `goto_advance1` | 6 | 8.0s |  |
| 122 | `goto_advance2` | 2 | 8.0s |  |
| 123 | `goto_both_ways1` | 3 | 8.0s |  |
| 124 | `goto_both_ways2` | 3 | 8.0s |  |
| 125 | `goto_execution_order` | 2 | 8.0s |  |
| 126 | `goto_execution_order2` | 2 | 8.0s |  |
| 127 | `goto_frame_number` | 3 | 8.4s |  |
| 128 | `goto_rewind1` | 1 | 8.6s |  |
| 129 | `goto_rewind2` | 3 | 8.3s |  |
| 130 | `goto_rewind3` | 2 | 8.3s |  |
| 131 | `greater_swf6` | 1175 | 10.2s |  |
| 132 | `greater_swf7` | 1175 | 10.2s |  |
| 133 | `greaterthan_swf5` | 1 | 8.2s |  |
| 134 | `greaterthan_swf8` | 1 | 8.2s |  |
| 135 | `has_own_property` | 32 | 8.2s |  |
| 136 | `hittest_lockroot` | 15 | 8.4s |  |
| 137 | `hittest_winding_rule` | 12 | 8.2s |  |
| 138 | `infinite_recursion_function` | 4 | 8.2s | [12](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 139 | `infinite_recursion_function_in_setter` | 131 | 8.2s | [12](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 140 | `infinite_recursion_virtual_property` | 67 | 8.2s | [12](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 141 | `init_array_invalid` | 4 | 8.2s |  |
| 142 | `init_object_invalid` | 4 | 10.2s |  |
| 143 | `is_finite` | 49 | 8.8s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 144 | `is_finite_swf6` | 49 | 8.8s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 145 | `is_prototype_of` | 89 | 9.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 146 | `issue_1086` | 1 | 8.7s |  |
| 147 | `issue_1671` | 0 | 8.8s |  |
| 148 | `issue_1906` | 4 | 8.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 149 | `issue_2166` | 9 | 10.0s |  |
| 150 | `issue_3446` | 1 | 8.7s |  |
| 151 | `issue_3522` | 2 | 8.6s |  |
| 152 | `issue_4377` | 2 | 8.6s |  |
| 153 | `issue_710` | 4 | 8.6s |  |
| 154 | `issue_768` | 3 | 9.7s | [13](ruffle-tests/_investigation/complete/issue_768.md) |
| 155 | `issue_9327` | 2 | 8.2s |  |
| 156 | `issue_9885` | 2 | 8.3s |  |
| 157 | `key_isToggled` | 9 | 8.2s |  |
| 158 | `lessthan` | 41 | 8.3s |  |
| 159 | `lessthan2_swf5` | 1226 | 10.4s |  |
| 160 | `lessthan2_swf6` | 1226 | 10.4s |  |
| 161 | `lessthan2_swf7` | 1226 | 10.3s |  |
| 162 | `lessthan_swf4` | 902 | 9.4s |  |
| 163 | `lessthan_swf4_alt` | 41 | 8.2s |  |
| 164 | `lessthan_swf5` | 41 | 8.2s |  |
| 165 | `local_to_global` | 49 | 8.6s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 166 | `localconnection_properties` | 8 | 8.5s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 167 | `logical_ops_swf4` | 90 | 8.6s |  |
| 168 | `logical_ops_swf8` | 108 | 8.5s |  |
| 169 | `looping` | 6 | 8.6s |  |
| 170 | `mask_reapply` | 0 | 8.5s |  |
| 171 | `mask_with_drawing` | 0 | 8.5s |  |
| 172 | `math_min_max` | 101 | 8.7s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 173 | `math_swf6` | 530 | 9.1s | [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 174 | `math_swf7` | 530 | 8.8s | [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 175 | `math_swf8` | 530 | 8.7s | [14](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 176 | `matrix` | 171 | 8.8s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 177 | `mouse_events` | 8 | 8.6s | [15](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 178 | `mouse_hover_events_while_dragging` | 1 | 8.6s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 179 | `mouse_listeners` | 67 | 8.6s |  |
| 180 | `mouse_wheel_enabled` | 2 | 8.6s |  |
| 181 | `movieclip_begin_gradient_fill` | 0 | 9.0s |  |
| 182 | `movieclip_blend_mode_property` | 35 | 9.1s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `movieclip_default_state` | 69 | 8.7s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 184 | `movieclip_depth_methods` | 98 | 8.7s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 185 | `movieclip_focusenabled` | 99 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_get_instance_at_depth` | 28 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 187 | `movieclip_hittest` | 92 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 188 | `movieclip_line_gradient_style` | 0 | 9.2s |  |
| 189 | `movieclip_name_from_timeline` | 13 | 8.4s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 190 | `movieclip_prototype_extension` | 5 | 8.4s |  |
| 191 | `nested_textfields_in_buttons` | 0 | 8.4s |  |
| 192 | `netstream_play_flv_screen` | 0 | 21.1s |  |
| 193 | `new_method_wrap` | 4 | 8.4s |  |
| 194 | `new_object_enumerate` | 7 | 8.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 195 | `new_object_wrap` | 4 | 8.4s |  |
| 196 | `o` | 3 | 8.4s |  |
| 197 | `object_constructor` | 33 | 8.5s |  |
| 198 | `object_function` | 32 | 8.4s |  |
| 199 | `object_properties` | 31 | 8.6s | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `object_prototypes` | 74 | 8.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 201 | `object_string_coerce_swf5` | 62 | 8.4s | [18](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 202 | `object_string_coerce_swf6` | 68 | 8.5s | [18](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 203 | `parse_int` | 64 | 8.6s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 204 | `placeobject_occupied_depth` | 6 | 8.5s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 205 | `point` | 175 | 8.8s | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 206 | `primitive_instanceof` | 37 | 8.5s |  |
| 207 | `primitive_type_globals` | 557 | 8.8s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 208 | `printjob_props_swf5` | 45 | 8.4s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 209 | `printjob_props_swf6` | 45 | 8.3s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 210 | `printjob_props_swf7` | 45 | 8.2s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 211 | `prototype_delete` | 12 | 8.2s |  |
| 212 | `prototype_enumerate` | 5 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 213 | `prototype_properties` | 17 | 8.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 214 | `rectangle` | 745 | 9.0s | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 215 | `recursive_prototypes` | 0 | 8.2s |  |
| 216 | `remove_movie_clip` | 29 | 8.3s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 217 | `root_onload` | 1 | 8.1s |  |
| 218 | `sandbox_type_local_file` | 1 | 8.2s |  |
| 219 | `sandbox_type_local_network` | 1 | 8.2s |  |
| 220 | `set_variable_scope` | 58 | 8.2s |  |
| 221 | `single_frame` | 1 | 8.1s |  |
| 222 | `slash_syntax` | 14 | 8.2s | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 223 | `sound_props_swf5` | 68 | 8.3s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 224 | `sound_props_swf6` | 68 | 8.3s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 225 | `sound_start_load` | 0 | 8.3s |  |
| 226 | `stage_display_state` | 16 | 8.3s | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 227 | `stage_object_enumerate` | 4 | 8.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 228 | `stage_object_properties` | 241 | 8.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 229 | `stage_object_properties_get_var` | 5 | 8.2s |  |
| 230 | `stage_property_representation` | 586 | 8.2s | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 231 | `stage_scale_mode` | 39 | 8.2s | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 232 | `strictequals_swf6` | 902 | 9.7s |  |
| 233 | `strictly_equals` | 7 | 8.2s |  |
| 234 | `string_coercion` | 117 | 8.5s | [27](ruffle-tests/_investigation/complete/string_coercion.md) |
| 235 | `string_methods` | 285 | 8.8s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 236 | `string_methods_negative_args` | 240 | 8.5s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 237 | `string_methods_swfv5` | 275 | 8.8s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 238 | `string_ops_swf6` | 95 | 8.3s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 239 | `string_paths_basic` | 4 | 8.2s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 240 | `string_paths_timer` | 0 | 8.5s |  |
| 241 | `string_paths_variable_alias` | 4 | 8.4s | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 242 | `swf4_actions_bool` | 96 | 8.8s |  |
| 243 | `swf4_bool` | 4 | 8.7s |  |
| 244 | `swf4_function_calls` | 7 | 8.6s |  |
| 245 | `swf5_encoding` | 3 | 8.6s |  |
| 246 | `swf7_case_sensitive` | 44 | 8.6s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 247 | `tab_ordering_automatic_basic` | 92 | 8.5s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 248 | `tab_ordering_automatic_order_grid` | 21 | 8.5s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 249 | `tab_ordering_children` | 208 | 8.6s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 250 | `tab_ordering_custom_basic` | 71 | 8.5s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 251 | `tab_ordering_custom_duplicate_index` | 22 | 8.6s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 252 | `tab_ordering_custom_i32_vs_u32` | 12 | 8.5s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 253 | `tab_ordering_custom_m1` | 29 | 8.4s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 254 | `tab_ordering_properties_tab_index_edge_case` | 4 | 8.4s |  |
| 255 | `tab_ordering_reverse` | 51 | 8.5s | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 256 | `target_clip_removed` | 5 | 8.4s | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 257 | `target_path` | 14 | 8.2s |  |
| 258 | `text_format` | 1146 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `text_format_display` | 21 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `text_format_font_max_length` | 2 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `text_format_rounding_swf7` | 840 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 262 | `text_format_rounding_swf8` | 840 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 263 | `textfield_background_color` | 11 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 264 | `textfield_border_color` | 11 | 8.2s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 265 | `textfield_maxchars` | 3 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 266 | `textfield_properties` | 44 | 8.4s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 267 | `textfield_props_swf5` | 175 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 268 | `textfield_props_swf6` | 210 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 269 | `textfield_props_swf7` | 210 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 270 | `textfield_props_swf8` | 210 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 271 | `textfield_text` | 7 | 8.3s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 272 | `textfield_variable` | 81 | 8.5s | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 273 | `this_swf7` | 41 | 8.3s | [32](ruffle-tests/_investigation/complete/this_swf7.md) |
| 274 | `timeline_function_def` | 7 | 8.4s |  |
| 275 | `transform` | 70 | 8.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 276 | `try_catch_finally` | 118 | 8.8s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 277 | `try_finally_simple` | 16 | 8.6s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 278 | `typeof` | 22 | 8.6s |  |
| 279 | `typeof_globals` | 7 | 8.6s |  |
| 280 | `uncaught_exception` | 1 | 8.6s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 281 | `uncaught_exception_bubbled` | 1 | 8.6s | [34](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 282 | `undefined_to_string_swf6` | 4 | 8.6s |  |
| 283 | `unescape` | 43 | 8.6s |  |
| 284 | `unload_clip_event` | 4 | 8.6s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 285 | `use_hand_cursor` | 8 | 8.6s |  |
| 286 | `variable_args` | 5 | 8.7s |  |
| 287 | `waitforframe` | 7 | 8.6s |  |
| 288 | `waitforframe2` | 16 | 9.1s |  |
| 289 | `watch` | 117 | 9.1s | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 290 | `watch_virtual_property_proto` | 2 | 8.8s | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 291 | `with` | 49 | 8.9s | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 292 | `with_return` | 2 | 8.8s |  |
| 293 | `with_variable_scopes` | 43 | 8.9s | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 294 | `xml` | 15 | 8.9s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 295 | `xml_append_child` | 28 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 296 | `xml_append_child_with_parent` | 20 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 297 | `xml_attributes_read` | 4 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_cdata` | 11 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_child_nodes_edge_cases` | 4 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 300 | `xml_clone_expandos` | 19 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 301 | `xml_first_last_child` | 8 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_has_child_nodes` | 3 | 8.7s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_idmap` | 21 | 8.9s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_ignore_comments` | 21 | 8.8s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 305 | `xml_ignore_white` | 34 | 8.3s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 306 | `xml_insert_before` | 20 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 307 | `xml_inspect_createmethods` | 15 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 308 | `xml_inspect_doctype` | 7 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 309 | `xml_inspect_parsexml` | 62 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 310 | `xml_inspect_xmldecl` | 7 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 311 | `xml_namespaces` | 203 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 312 | `xml_parent_and_child` | 5 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 313 | `xml_remove_node` | 22 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 314 | `xml_reparenting` | 14 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 315 | `xml_siblings` | 10 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 316 | `xml_to_string` | 13 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 317 | `xml_to_string_comment` | 1 | 8.0s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 318 | `xml_unescaping` | 23 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 319 | `xmlnode_proto` | 1 | 8.1s | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**72 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `stage_object_properties_swf6` | 99.1% | 229 | 231 | 2 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `hittest_morph` | 95.7% | 67 | 70 | 3 |  |
| 5 | `selection` | 95.6% | 434 | 454 | 20 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 6 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `button_properties_special_cases` | 86.4% | 19 | 22 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 9 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 10 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 11 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 12 | `this_scoping` | 80.8% | 42 | 52 | 10 | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `tab_ordering_tabbable` | 76.6% | 36 | 47 | 11 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 17 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 18 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `add_property` | 73.3% | 11 | 15 | 4 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 20 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 21 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `register_underflow` | 69.2% | 18 | 26 | 8 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 23 | `unload` | 69.2% | 36 | 52 | 16 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `function_base_clip_removed` | 68.0% | 17 | 25 | 8 |  |
| 25 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 28 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 32 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 33 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_align` | 60.0% | 36 | 60 | 24 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 43 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 44 | `execution_order4` | 58.3% | 7 | 12 | 5 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `parse_float` | 58.1% | 43 | 74 | 31 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 47 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 48 | `focusrect_property_swf6` | 58.0% | 717 | 1237 | 520 |  |
| 49 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 51 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 53 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 54 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 55 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 58 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 59 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 60 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 61 | `button_keypress_vs_tab` | 50.0% | 10 | 20 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 62 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 66 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 67 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 68 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 69 | `loadmovie_fail` | 50.0% | 1 | 2 | 1 |  |
| 70 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 71 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 72 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 10.3s |  |
| 2 | `goto_methods` | 10.5s | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 10.9s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 11.0s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 11.0s | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_library_state_values` | exit code -6 | 10.8s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_state_values` | exit code -6 | 11.4s | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 18.3s | [33](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**292 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `stage_object_properties_swf6` | 99.1% | 229/231 | 231 | 231 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `hittest_morph` | 95.7% | 67/70 | 70 | 70 |  |
| 5 | `selection` | 95.6% | 434/454 | 454 | 454 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 6 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `button_properties_special_cases` | 86.4% | 19/22 | 22 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 9 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 10 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 11 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 12 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 15 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `tab_ordering_tabbable` | 76.6% | 36/47 | 47 | 47 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 17 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 18 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `add_property` | 73.3% | 11/15 | 15 | 15 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 20 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 21 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 23 | `unload` | 69.2% | 36/52 | 52 | 52 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `function_base_clip_removed` | 68.0% | 17/25 | 25 | 25 |  |
| 25 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 28 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 32 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 33 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 43 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 44 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 46 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [21](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 47 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1236 | 1237 |  |
| 48 | `focusrect_property_swf6` | 58.0% | 717/1237 | 1236 | 1237 |  |
| 49 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 51 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 53 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 54 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 55 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 56 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 58 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 59 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 60 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 61 | `button_keypress_vs_tab` | 50.0% | 10/20 | 20 | 20 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 62 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 66 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 67 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 68 | `loadmovie` | 50.0% | 1/2 | 1 | 2 |  |
| 69 | `loadmovie_fail` | 50.0% | 1/2 | 1 | 2 |  |
| 70 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 71 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 72 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 75 | `goto_label` | 47.1% | 8/17 | 9 | 17 | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 76 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 77 | `register_globals_across_frames` | 46.7% | 7/15 | 15 | 15 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 78 | `unloadmovienum` | 46.2% | 6/13 | 12 | 13 | [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 79 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 81 | `mouse_pos` | 43.8% | 291/665 | 656 | 665 | [15](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 82 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 |  |
| 83 | `mouse_pos_with_scale_factor` | 42.7% | 111/260 | 251 | 260 | [15](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 84 | `mcl_as_broadcaster` | 41.7% | 5/12 | 8 | 12 |  |
| 85 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 86 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 87 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 88 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 89 | `property_invalid_base_clip` | 38.9% | 14/36 | 35 | 36 |  |
| 90 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 91 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 92 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 93 | `on_construct` | 36.0% | 9/25 | 12 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 94 | `button_keypress` | 33.3% | 1/3 | 2 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 95 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 99 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 100 | `loadmovienum` | 33.3% | 1/3 | 1 | 3 |  |
| 101 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 102 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 103 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 104 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 106 | `swf5_no_closure` | 31.6% | 6/19 | 15 | 19 |  |
| 107 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 108 | `default_names` | 28.8% | 15/52 | 48 | 52 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 109 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 110 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 111 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 112 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 113 | `button_keypress_vs_textinput` | 25.0% | 1/4 | 2 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 114 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 115 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 116 | `loadmovie_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 117 | `loadvariables2` | 25.0% | 2/8 | 2 | 8 |  |
| 118 | `mouse_events_visible_enabled` | 25.0% | 3/12 | 10 | 12 | [15](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 119 | `movieclip_in_removed_button` | 25.0% | 1/4 | 4 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 120 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 121 | `text_blocks_clicks` | 25.0% | 1/4 | 2 | 4 |  |
| 122 | `unloadmovie` | 25.0% | 1/4 | 2 | 4 | [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 123 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 124 | `button_keypress_vs_press` | 24.0% | 6/25 | 24 | 25 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 125 | `focusrect_property_swf5` | 23.2% | 287/1237 | 1236 | 1237 |  |
| 126 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 128 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 129 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 130 | `movieclip_init_object` | 20.0% | 1/5 | 2 | 5 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 131 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 132 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 133 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [33](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 134 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
| 135 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [9](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 136 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 137 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 138 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 139 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 140 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 141 | `tell_target_invalid` | 16.7% | 1/6 | 5 | 6 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 142 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 143 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 144 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 145 | `register_and_init_order` | 14.7% | 34/231 | 85 | 231 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 146 | `path_string` | 14.6% | 47/322 | 300 | 322 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 147 | `button_key_events` | 14.3% | 2/14 | 9 | 14 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 148 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 149 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 151 | `tab_ordering_movieclip_enabled_default` | 13.6% | 63/462 | 432 | 462 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 152 | `removed_clip_halts_script` | 13.3% | 2/15 | 13 | 15 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 153 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [19](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 154 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 155 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 156 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 157 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 158 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 159 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 160 | `tab_ordering_events` | 12.0% | 18/150 | 118 | 150 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 161 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 162 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 |  |
| 163 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 164 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 165 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 166 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 167 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 168 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 169 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 170 | `tell_target` | 8.1% | 3/37 | 34 | 37 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 171 | `call` | 7.9% | 5/63 | 28 | 63 |  |
| 172 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 173 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 175 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 176 | `tab_ordering_events_mouse` | 7.7% | 5/65 | 47 | 65 | [29](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 177 | `define_local` | 7.4% | 2/27 | 23 | 27 | [36](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 178 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 180 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 181 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 182 | `swf4_actions_coercion_order` | 5.7% | 9/158 | 93 | 158 |  |
| 183 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 184 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [33](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 185 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 187 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 188 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 189 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 190 | `register_class` | 4.5% | 3/66 | 27 | 66 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 191 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 192 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 193 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 194 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 195 | `button_key_events_special` | 2.2% | 1/45 | 38 | 45 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 196 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 197 | `focus_keyboard_press` | 2.0% | 3/148 | 148 | 60 |  |
| 198 | `netconnection_send_remote` | 2.0% | 1/50 | 1 | 50 |  |
| 199 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 200 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 201 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 202 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 203 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 204 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 205 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 206 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 207 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 208 | `global_proto_decls` | 0.3% | 13/4497 | 568 | 4497 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 209 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 210 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [10](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 211 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 212 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [17](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 214 | `click_block` | 0.0% | 0/5 | 0 | 5 | [15](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 215 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 216 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 217 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 218 | `cross_movie_root` | 0.0% | 0/10 | 7 | 10 |  |
| 219 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 220 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 221 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 222 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [24](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 223 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 224 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 225 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 226 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 227 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 228 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 229 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 230 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 231 | `focus_mouse` | 0.0% | 0/45 | 30 | 45 |  |
| 232 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 233 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 |  |
| 234 | `form_loader_encoding_1` | 0.0% | 0/1 | 0 | 1 |  |
| 235 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 236 | `form_loader_encoding_3` | 0.0% | 0/3 | 0 | 3 |  |
| 237 | `form_loader_encoding_4` | 0.0% | 0/3 | 0 | 3 |  |
| 238 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 239 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 240 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 241 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 242 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [11](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 243 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 |  |
| 244 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [20](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 245 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 246 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 247 | `loadmovie_registerclass` | 0.0% | 0/30 | 0 | 30 |  |
| 248 | `loadmovie_replace_root` | 0.0% | 0/5 | 0 | 5 |  |
| 249 | `loadvariables` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 |  |
| 251 | `loadvariablesnum` | 0.0% | 0/2 | 0 | 2 |  |
| 252 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 253 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 254 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 255 | `mcl_loadclip_properties` | 0.0% | 0/6 | 0 | 6 |  |
| 256 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 |  |
| 257 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 258 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 259 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 260 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 261 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 262 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 263 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 264 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 265 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 266 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 267 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 268 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [22](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 269 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [23](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 270 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 271 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 273 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 274 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 275 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 276 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 277 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 278 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 279 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [28](ruffle-tests/_investigation/complete/STRING_PLAN.md) [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 280 | `swf5_to_6_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 281 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 282 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 283 | `swf6_to_5_cross_call` | 0.0% | 0/29 | 0 | 29 |  |
| 284 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 285 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [30](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 286 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 287 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [31](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 288 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [16](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 289 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 290 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 291 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 292 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [37](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) | 14 | 5 | 9 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 9 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 10 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 11 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 12 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 13 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 14 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 15 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 1 | 4 |
| 16 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 20 | 38 |
| 17 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 18 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 19 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 20 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 21 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 22 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 23 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 4 | 11 |
| 24 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 25 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 5 | 4 |
| 26 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 5 | 2 |
| 27 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 28 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 29 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 10 | 6 |
| 30 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 31 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 29 | 41 |
| 32 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 33 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 34 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 35 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 36 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 37 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 279 | 150 | 129 |
