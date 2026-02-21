# Ruffle Test Results (Filtered)

**Date**: 2026-02-21 01:40 UTC

**Git SHA**: `a0ff5dc23a`

**Run Duration**: 76m 14s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **244** (50.9%) |
| Failing | 235 |
| Total expected lines | 71488 |
| Matching lines | 42686 (59.7%) |
| Mismatched lines | 28802 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 228 | 97.0% |
| Segfault | 5 | 2.1% |
| Runtime Error | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**244 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.2s |  |
| 2 | `action_to_integer` | 28 | 7.0s |  |
| 3 | `add` | 28 | 7.1s |  |
| 4 | `add2` | 354 | 7.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 7.0s |  |
| 6 | `add_swf5` | 28 | 7.0s |  |
| 7 | `arguments` | 127 | 7.1s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 7.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 7.1s |  |
| 10 | `array_constructor` | 30 | 7.0s |  |
| 11 | `array_enumerate` | 4 | 7.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 7.0s |  |
| 13 | `array_properties` | 36 | 7.0s |  |
| 14 | `array_prototyping` | 12 | 6.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 7.0s |  |
| 16 | `array_sort_random` | 443 | 7.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 7.1s |  |
| 18 | `array_trivial` | 209 | 7.1s |  |
| 19 | `as1_constructor_v6` | 35 | 7.0s |  |
| 20 | `as1_constructor_v7` | 35 | 7.5s |  |
| 21 | `as2_oop` | 13 | 7.4s | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 7.3s |  |
| 23 | `as_set_prop_flags_version` | 31 | 7.2s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 7.2s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 7.2s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 7.2s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 7.2s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 7.2s |  |
| 29 | `as_transformed_flag` | 20 | 7.1s |  |
| 30 | `bad_swf_tag_past_eof` | 0 | 7.4s |  |
| 31 | `bitand` | 1058 | 10.4s |  |
| 32 | `bitmap_data_colortransform` | 0 | 7.7s |  |
| 33 | `bitmap_data_fillrect` | 0 | 7.7s |  |
| 34 | `bitmap_data_max_size_swf10` | 12 | 7.5s |  |
| 35 | `bitmap_data_max_size_swf9` | 10 | 7.6s |  |
| 36 | `bitmap_data_perlinnoise` | 0 | 8.2s |  |
| 37 | `bitmap_data_pixeldissolve_image` | 0 | 7.8s |  |
| 38 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.5s |  |
| 39 | `bitor` | 1058 | 10.3s |  |
| 40 | `biturshift` | 14 | 7.3s |  |
| 41 | `biturshift_swf8` | 14 | 7.6s |  |
| 42 | `bitxor` | 1058 | 10.1s |  |
| 43 | `call_method_empty_name` | 1 | 7.2s |  |
| 44 | `capabilities_resolution` | 8 | 7.2s |  |
| 45 | `catch_references_registers` | 2 | 7.2s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 46 | `clone_sprite_types` | 24 | 7.1s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `color` | 57 | 7.3s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 48 | `color_transform` | 48 | 7.2s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 49 | `create_empty_movie_clip` | 3 | 7.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 50 | `define_function2` | 8 | 7.0s |  |
| 51 | `define_function2_preload` | 13 | 7.1s |  |
| 52 | `define_function2_preload_order` | 4 | 7.4s |  |
| 53 | `define_function_case_sensitive` | 2 | 7.0s |  |
| 54 | `delete` | 3 | 7.2s |  |
| 55 | `display_object_properties` | 2 | 7.0s |  |
| 56 | `divide_swf4` | 107 | 7.1s |  |
| 57 | `duplicate_movie_clip` | 20 | 7.1s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 58 | `edittext_antialiastype` | 296 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_autosize_setter` | 20 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_default_format` | 221 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_default_format_empty` | 95 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_default_format_font_style` | 335 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_html_align_swf7` | 52 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_html_align_swf8` | 52 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_newline_stripping` | 64 | 11.8s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `edittext_width_height` | 103 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `equals` | 32 | 7.1s |  |
| 68 | `equals2_swf5` | 926 | 9.0s |  |
| 69 | `equals2_swf6` | 926 | 8.9s |  |
| 70 | `equals2_swf7` | 926 | 8.9s |  |
| 71 | `equals_swf4` | 665 | 7.6s |  |
| 72 | `equals_swf4_alt` | 32 | 7.2s |  |
| 73 | `equals_swf5` | 32 | 7.1s |  |
| 74 | `error` | 58 | 7.2s |  |
| 75 | `escape` | 14 | 7.1s |  |
| 76 | `execution_order1` | 5 | 7.1s |  |
| 77 | `execution_order3` | 4 | 7.1s |  |
| 78 | `focusrect_mouse_swf8` | 0 | 7.4s |  |
| 79 | `focusrect_mouse_swf9` | 0 | 7.3s |  |
| 80 | `focusrect_swf5` | 6 | 7.3s | [31](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 81 | `function_suppress_and_preload` | 28 | 7.1s |  |
| 82 | `get_variable_in_scope` | 29 | 7.0s |  |
| 83 | `getproperty` | 28 | 7.1s |  |
| 84 | `getproperty_swf4` | 28 | 7.2s |  |
| 85 | `getproperty_swf5` | 28 | 7.0s |  |
| 86 | `global_array` | 3 | 7.0s |  |
| 87 | `global_is_bare` | 7 | 7.0s |  |
| 88 | `globals_swf5` | 304 | 7.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 89 | `globals_swf6` | 304 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 90 | `globals_swf7` | 304 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 91 | `globals_swf8` | 304 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 92 | `goto_execution_order` | 2 | 7.0s |  |
| 93 | `goto_execution_order2` | 2 | 7.0s |  |
| 94 | `goto_frame_number` | 3 | 7.0s |  |
| 95 | `greater_swf6` | 1175 | 8.8s |  |
| 96 | `greater_swf7` | 1175 | 8.8s |  |
| 97 | `greaterthan_swf5` | 1 | 6.9s |  |
| 98 | `greaterthan_swf8` | 1 | 6.9s |  |
| 99 | `has_own_property` | 32 | 6.9s |  |
| 100 | `infinite_recursion_function` | 4 | 6.9s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 101 | `infinite_recursion_function_in_setter` | 131 | 6.9s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 102 | `infinite_recursion_virtual_property` | 67 | 6.9s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 103 | `init_array_invalid` | 4 | 6.9s |  |
| 104 | `init_object_invalid` | 4 | 7.0s |  |
| 105 | `is_finite` | 49 | 6.9s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 106 | `is_finite_swf6` | 49 | 6.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 107 | `is_prototype_of` | 89 | 6.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 108 | `issue_1086` | 1 | 6.8s |  |
| 109 | `issue_1671` | 0 | 6.8s |  |
| 110 | `issue_1906` | 4 | 6.9s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 111 | `issue_2166` | 9 | 6.8s |  |
| 112 | `issue_3446` | 1 | 6.8s |  |
| 113 | `issue_4377` | 2 | 6.8s |  |
| 114 | `issue_710` | 4 | 6.8s |  |
| 115 | `issue_768` | 3 | 8.8s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 116 | `issue_9885` | 2 | 7.0s |  |
| 117 | `lessthan` | 41 | 6.9s |  |
| 118 | `lessthan2_swf5` | 1226 | 9.0s |  |
| 119 | `lessthan2_swf6` | 1226 | 9.0s |  |
| 120 | `lessthan2_swf7` | 1226 | 9.1s |  |
| 121 | `lessthan_swf4` | 902 | 7.6s |  |
| 122 | `lessthan_swf4_alt` | 41 | 7.0s |  |
| 123 | `lessthan_swf5` | 41 | 7.0s |  |
| 124 | `localconnection_properties` | 8 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 125 | `logical_ops_swf4` | 90 | 7.2s |  |
| 126 | `logical_ops_swf8` | 108 | 7.2s |  |
| 127 | `looping` | 6 | 7.2s |  |
| 128 | `mask_reapply` | 0 | 7.2s |  |
| 129 | `mask_with_drawing` | 0 | 7.1s |  |
| 130 | `math_min_max` | 101 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 131 | `math_swf6` | 530 | 7.5s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 132 | `math_swf7` | 530 | 7.5s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 133 | `math_swf8` | 530 | 7.5s | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 134 | `matrix` | 171 | 7.5s | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 135 | `movieclip_begin_gradient_fill` | 0 | 7.5s |  |
| 136 | `movieclip_blend_mode_property` | 35 | 8.5s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 137 | `movieclip_get_instance_at_depth` | 28 | 7.1s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 138 | `movieclip_line_gradient_style` | 0 | 9.1s |  |
| 139 | `movieclip_prototype_extension` | 5 | 7.2s |  |
| 140 | `nested_textfields_in_buttons` | 0 | 7.2s |  |
| 141 | `netstream_play_flv_screen` | 0 | 20.2s |  |
| 142 | `new_method_wrap` | 4 | 7.2s |  |
| 143 | `new_object_enumerate` | 7 | 7.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 144 | `new_object_wrap` | 4 | 7.1s |  |
| 145 | `o` | 3 | 7.1s |  |
| 146 | `object_constructor` | 33 | 7.2s |  |
| 147 | `object_function` | 32 | 7.2s |  |
| 148 | `object_properties` | 31 | 7.3s | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 149 | `object_string_coerce_swf5` | 62 | 7.2s | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 150 | `parse_int` | 64 | 7.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 151 | `point` | 175 | 7.7s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 152 | `primitive_instanceof` | 37 | 7.2s |  |
| 153 | `primitive_type_globals` | 557 | 8.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 154 | `printjob_props_swf5` | 45 | 7.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 155 | `printjob_props_swf6` | 45 | 7.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 156 | `printjob_props_swf7` | 45 | 7.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 157 | `prototype_delete` | 12 | 7.0s |  |
| 158 | `prototype_enumerate` | 5 | 7.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 159 | `prototype_properties` | 17 | 7.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 160 | `rectangle` | 745 | 7.8s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 161 | `recursive_prototypes` | 0 | 7.0s |  |
| 162 | `sandbox_type_local_file` | 1 | 7.2s |  |
| 163 | `set_variable_scope` | 58 | 7.1s |  |
| 164 | `single_frame` | 1 | 7.1s |  |
| 165 | `sound_props_swf5` | 68 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 166 | `sound_props_swf6` | 68 | 7.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 167 | `sound_start_load` | 0 | 7.1s |  |
| 168 | `stage_object_enumerate` | 4 | 7.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 169 | `stage_object_properties_get_var` | 5 | 7.0s |  |
| 170 | `stage_property_representation` | 586 | 7.1s | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 171 | `strictequals_swf6` | 902 | 8.5s |  |
| 172 | `strictly_equals` | 7 | 7.1s |  |
| 173 | `string_coercion` | 117 | 7.3s | [29](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 174 | `string_methods` | 285 | 7.6s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 175 | `string_methods_negative_args` | 240 | 7.2s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 176 | `string_methods_swfv5` | 275 | 7.6s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 177 | `string_ops_swf6` | 95 | 7.1s | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 178 | `string_paths_keyevents` | 0 | 7.2s |  |
| 179 | `string_paths_timer` | 0 | 7.2s |  |
| 180 | `swf4_actions_bool` | 96 | 7.2s |  |
| 181 | `swf4_bool` | 4 | 7.2s |  |
| 182 | `swf4_function_calls` | 7 | 7.2s |  |
| 183 | `swf5_encoding` | 3 | 7.2s |  |
| 184 | `swf7_case_sensitive` | 44 | 7.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 185 | `tab_ordering_properties_tab_index_edge_case` | 4 | 7.0s |  |
| 186 | `target_clip_removed` | 5 | 7.3s | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 187 | `text_format` | 1146 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 188 | `text_format_display` | 21 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 189 | `text_format_font_max_length` | 2 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 190 | `text_format_rounding_swf7` | 840 | 7.2s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 191 | `text_format_rounding_swf8` | 840 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 192 | `textfield_background_color` | 11 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 193 | `textfield_border_color` | 11 | 7.1s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 194 | `textfield_maxchars` | 3 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 195 | `textfield_properties` | 44 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 196 | `textfield_props_swf5` | 175 | 7.5s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 197 | `textfield_props_swf7` | 210 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 198 | `textfield_props_swf8` | 210 | 7.4s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 199 | `textfield_text` | 7 | 7.0s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 200 | `textfield_variable` | 81 | 7.3s | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 201 | `this_swf7` | 41 | 7.1s | [34](ruffle-tests/_investigation/complete/this_swf7.md) |
| 202 | `timeline_function_def` | 7 | 7.2s |  |
| 203 | `try_catch_finally` | 118 | 7.1s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 204 | `try_finally_simple` | 16 | 7.0s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 205 | `typeof` | 22 | 7.0s |  |
| 206 | `typeof_globals` | 7 | 7.1s |  |
| 207 | `uncaught_exception` | 1 | 7.0s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 208 | `uncaught_exception_bubbled` | 1 | 7.0s | [36](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 209 | `undefined_to_string_swf6` | 4 | 7.0s |  |
| 210 | `unescape` | 43 | 7.0s |  |
| 211 | `unload_clip_event` | 4 | 7.0s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 212 | `use_hand_cursor` | 8 | 7.0s |  |
| 213 | `variable_args` | 5 | 7.1s |  |
| 214 | `waitforframe` | 7 | 7.0s |  |
| 215 | `waitforframe2` | 16 | 9.0s |  |
| 216 | `watch` | 117 | 7.3s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 217 | `watch_virtual_property_proto` | 2 | 7.1s | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 218 | `with_return` | 2 | 7.0s |  |
| 219 | `with_variable_scopes` | 43 | 7.1s | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 220 | `xml` | 15 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 221 | `xml_append_child` | 28 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 222 | `xml_append_child_with_parent` | 20 | 7.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 223 | `xml_cdata` | 11 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 224 | `xml_child_nodes_edge_cases` | 4 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 225 | `xml_clone_expandos` | 19 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 226 | `xml_first_last_child` | 8 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 227 | `xml_has_child_nodes` | 3 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 228 | `xml_idmap` | 21 | 7.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 229 | `xml_ignore_comments` | 21 | 7.1s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 230 | `xml_ignore_white` | 34 | 7.2s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 231 | `xml_insert_before` | 20 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 232 | `xml_inspect_createmethods` | 15 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 233 | `xml_inspect_doctype` | 7 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 234 | `xml_inspect_parsexml` | 62 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 235 | `xml_inspect_xmldecl` | 7 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 236 | `xml_namespaces` | 203 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 237 | `xml_parent_and_child` | 5 | 6.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 238 | `xml_remove_node` | 22 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 239 | `xml_reparenting` | 14 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 240 | `xml_siblings` | 10 | 6.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 241 | `xml_to_string` | 13 | 6.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 242 | `xml_to_string_comment` | 1 | 6.9s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 243 | `xml_unescaping` | 23 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 244 | `xmlnode_proto` | 1 | 7.0s | [39](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**71 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `textfield_props_swf6` | 99.0% | 208 | 210 | 2 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `transform` | 98.6% | 69 | 70 | 1 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 3 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_depth_methods` | 96.9% | 95 | 98 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 5 | `object_prototypes` | 95.9% | 71 | 74 | 3 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23 | 24 | 1 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `with` | 93.9% | 46 | 49 | 3 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 10 | `extends_native_type` | 90.9% | 10 | 11 | 1 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 11 | `conflicting_instance_names` | 87.0% | 20 | 23 | 3 |  |
| 12 | `rewind_depth` | 86.7% | 26 | 30 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_name_from_timeline` | 84.6% | 11 | 13 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `local_to_global` | 83.7% | 41 | 49 | 8 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 16 | `this_scoping` | 80.8% | 42 | 52 | 10 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 17 | `target_path` | 78.6% | 11 | 14 | 3 |  |
| 18 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 19 | `movieclip_hittest` | 77.2% | 71 | 92 | 21 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 20 | `do_init_action` | 75.0% | 3 | 4 | 1 |  |
| 21 | `edittext_html_entity` | 75.0% | 3 | 4 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `add_property` | 73.3% | 11 | 15 | 4 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 23 | `attach_movie` | 72.9% | 43 | 59 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 25 | `remove_movie_clip` | 72.4% | 21 | 29 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 26 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 27 | `execution_order2` | 71.4% | 5 | 7 | 2 |  |
| 28 | `register_underflow` | 69.2% | 18 | 26 | 8 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 29 | `unload` | 69.2% | 36 | 52 | 16 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 31 | `button_v5` | 66.7% | 12 | 18 | 6 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 32 | `export_assets` | 66.7% | 2 | 3 | 1 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `goto_advance2` | 66.7% | 2 | 3 | 1 |  |
| 34 | `issue_1104` | 66.7% | 2 | 3 | 1 |  |
| 35 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 36 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 37 | `edittext_scroll` | 64.8% | 35 | 54 | 19 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 40 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 41 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `button_children` | 62.5% | 5 | 8 | 3 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 43 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_align` | 60.0% | 36 | 60 | 24 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `goto_rewind2` | 60.0% | 3 | 5 | 2 |  |
| 51 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 52 | `string_paths_other` | 58.3% | 21 | 36 | 15 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 53 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 54 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 55 | `asnative` | 55.9% | 19 | 34 | 15 | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 56 | `button_v6` | 55.6% | 10 | 18 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 57 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 58 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 59 | `movieclip_hittest_shapeflag` | 53.3% | 180 | 338 | 158 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 60 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `edittext_html_swf6` | 50.5% | 2718 | 5377 | 2659 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `goto_rewind3` | 50.0% | 2 | 4 | 2 |  |
| 64 | `hittest_winding_rule` | 50.0% | 6 | 12 | 6 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 65 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 66 | `issue_2870` | 50.0% | 2 | 4 | 2 |  |
| 67 | `issue_3522` | 50.0% | 1 | 2 | 1 |  |
| 68 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 69 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 70 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 71 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `goto_methods` | 9.2s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 2 | `native_objects_swf6` | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf7` | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `placeobject_occupied_depth` | 9.3s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_state_values` | exit code -6 | 9.8s | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 17.2s | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**228 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `textfield_props_swf6` | 99.0% | 208/210 | 210 | 210 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `transform` | 98.6% | 69/70 | 70 | 70 | [5](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 3 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_depth_methods` | 96.9% | 95/98 | 98 | 98 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 5 | `object_prototypes` | 95.9% | 71/74 | 74 | 74 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `boxed_primitives` | 95.8% | 23/24 | 24 | 24 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `with` | 93.9% | 46/49 | 49 | 49 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 10 | `extends_native_type` | 90.9% | 10/11 | 11 | 11 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 11 | `conflicting_instance_names` | 87.0% | 20/23 | 23 | 23 |  |
| 12 | `rewind_depth` | 86.7% | 26/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_name_from_timeline` | 84.6% | 11/13 | 13 | 13 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `local_to_global` | 83.7% | 41/49 | 49 | 49 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 16 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 17 | `target_path` | 78.6% | 11/14 | 14 | 14 |  |
| 18 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 19 | `movieclip_hittest` | 77.2% | 71/92 | 92 | 92 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 20 | `do_init_action` | 75.0% | 3/4 | 4 | 3 |  |
| 21 | `edittext_html_entity` | 75.0% | 3/4 | 4 | 4 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `add_property` | 73.3% | 11/15 | 15 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 23 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 25 | `remove_movie_clip` | 72.4% | 21/29 | 29 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 26 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 27 | `execution_order2` | 71.4% | 5/7 | 7 | 7 |  |
| 28 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 29 | `unload` | 69.2% | 36/52 | 52 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 30 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [20](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 31 | `button_v5` | 66.7% | 12/18 | 18 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 32 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `goto_advance2` | 66.7% | 2/3 | 3 | 2 |  |
| 34 | `issue_1104` | 66.7% | 2/3 | 3 | 2 |  |
| 35 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 36 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 37 | `edittext_scroll` | 64.8% | 35/54 | 54 | 54 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 40 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 41 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `button_children` | 62.5% | 5/8 | 8 | 8 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 43 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `goto_rewind2` | 60.0% | 3/5 | 5 | 3 |  |
| 51 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 52 | `string_paths_other` | 58.3% | 21/36 | 28 | 36 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 53 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 54 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 55 | `asnative` | 55.9% | 19/34 | 31 | 34 | [16](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 56 | `button_v6` | 55.6% | 10/18 | 18 | 18 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 57 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 58 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 59 | `movieclip_hittest_shapeflag` | 53.3% | 180/338 | 338 | 338 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 60 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `edittext_html_swf6` | 50.5% | 2718/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `goto_rewind3` | 50.0% | 2/4 | 4 | 2 |  |
| 64 | `hittest_winding_rule` | 50.0% | 6/12 | 12 | 12 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 65 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 66 | `issue_2870` | 50.0% | 2/4 | 4 | 3 |  |
| 67 | `issue_3522` | 50.0% | 1/2 | 2 | 2 |  |
| 68 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 69 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 70 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 71 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `enumerate` | 48.4% | 31/64 | 62 | 64 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 73 | `edittext_html_condensewhite_swf7` | 46.6% | 145/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 75 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_html_condensewhite_swf8` | 45.7% | 142/311 | 311 | 311 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 78 | `swf5_no_closure` | 42.1% | 8/19 | 15 | 19 |  |
| 79 | `edittext_html_swf7` | 42.1% | 2262/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_html_swf8` | 41.8% | 2247/5377 | 5377 | 5377 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 82 | `this_swf6` | 41.5% | 17/41 | 41 | 41 |  |
| 83 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 84 | `goto_both_ways1` | 40.0% | 2/5 | 5 | 3 |  |
| 85 | `hittest_lockroot` | 40.0% | 6/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 86 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 87 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 88 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 89 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 90 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 91 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 95 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 96 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 98 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 99 | `stage_object_properties_swf6` | 30.5% | 131/429 | 429 | 231 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 100 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 101 | `closure_scope` | 28.6% | 2/7 | 7 | 7 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 102 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 103 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 104 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 105 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 106 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 107 | `execution_order4` | 25.0% | 3/12 | 11 | 12 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 108 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 109 | `goto_rewind1` | 25.0% | 1/4 | 4 | 1 |  |
| 110 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 111 | `stage_object_properties` | 23.1% | 132/571 | 571 | 241 | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 112 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `hittest_morph` | 21.4% | 15/70 | 70 | 70 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 114 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `movieclip_getbounds` | 20.9% | 45/215 | 215 | 191 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 116 | `default_names` | 20.0% | 14/70 | 70 | 52 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 118 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 119 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 120 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 121 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 122 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 123 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 124 | `goto_both_ways2` | 16.7% | 1/6 | 6 | 3 |  |
| 125 | `movieclip_library_state_values` | 16.7% | 13/78 | 73 | 78 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 127 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 128 | `path_string` | 15.2% | 49/322 | 300 | 322 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 129 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 130 | `goto_advance1` | 14.3% | 1/7 | 7 | 6 |  |
| 131 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 132 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 133 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [21](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 134 | `register_and_init_order` | 13.0% | 30/231 | 59 | 231 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 135 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 136 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [27](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 137 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 138 | `goto_label` | 11.8% | 2/17 | 11 | 17 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 139 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 140 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 141 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 142 | `selection` | 9.3% | 42/454 | 244 | 454 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 143 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 144 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 146 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 147 | `textsnapshot_props_swf6` | 8.9% | 5/56 | 38 | 56 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 148 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `define_local` | 7.4% | 2/27 | 23 | 27 | [38](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 151 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 152 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 153 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 154 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 155 | `removed_clip_halts_script` | 6.7% | 1/15 | 2 | 15 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 156 | `call` | 6.3% | 4/63 | 40 | 63 |  |
| 157 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [35](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 158 | `funky_function_calls` | 5.4% | 3/56 | 8 | 56 |  |
| 159 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 160 | `clip_events` | 5.3% | 1/19 | 17 | 19 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 161 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 162 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 163 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 164 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 165 | `function_base_clip_removed` | 4.0% | 1/25 | 6 | 25 |  |
| 166 | `selection_handlers` | 3.7% | 1/27 | 9 | 27 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 167 | `movieclip_gettextsnapshot` | 3.6% | 4/112 | 42 | 112 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `register_class` | 3.0% | 2/66 | 27 | 66 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 169 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 172 | `global_proto_decls` | 0.2% | 10/4497 | 529 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 173 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 174 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 175 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 176 | `button_goto` | 0.0% | 0/4 | 0 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 177 | `button_order` | 0.0% | 0/2 | 1 | 2 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 178 | `button_properties_special_cases` | 0.0% | 0/22 | 0 | 22 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 179 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 180 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 181 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 182 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 184 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 185 | `edittext_programmatic_focus` | 0.0% | 0/12 | 12 | 12 | [26](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 186 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 187 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 188 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 189 | `function_base_clip_readded` | 0.0% | 0/11 | 0 | 11 |  |
| 190 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 191 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 192 | `global_proto_decls_delete` | 0.0% | 0/4158 | 199 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 193 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 194 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 195 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 196 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [22](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 197 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 198 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 199 | `issue_9327` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 201 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 202 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 203 | `movieclip_in_removed_button` | 0.0% | 0/4 | 3 | 4 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 204 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 205 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 206 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [24](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 207 | `on_construct` | 0.0% | 0/25 | 0 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 208 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [25](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 209 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 210 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 211 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 212 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 | [3](ruffle-tests/_investigation/incomplete/BUTTON_PLAN.md) |
| 213 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 214 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 215 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 216 | `slash_syntax` | 0.0% | 0/14 | 0 | 14 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 217 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 218 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 219 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 220 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [30](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 221 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 222 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 223 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 224 | `tell_target` | 0.0% | 0/37 | 0 | 37 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 225 | `tell_target_invalid` | 0.0% | 0/6 | 2 | 6 | [32](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 226 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 227 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [33](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 228 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [18](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

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
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
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
| 33 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 23 | 47 |
| 34 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 35 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 36 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 37 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 1 | 11 |
| 38 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 39 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 192 | 129 | 63 |
