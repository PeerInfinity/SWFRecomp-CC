# Ruffle Test Results (Filtered)

**Date**: 2026-02-24 04:41 UTC

**Git SHA**: `04f4d9cbe0`

**Run Duration**: 89m 56s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **296** (61.8%) |
| Failing | 183 |
| Total expected lines | 71494 |
| Matching lines | 46249 (64.7%) |
| Mismatched lines | 25245 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 177 | 96.7% |
| Segfault | 5 | 2.7% |
| Timeout | 1 | 0.5% |

## Passing Tests

**296 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 8.5s |  |
| 2 | `action_to_integer` | 28 | 8.3s |  |
| 3 | `add` | 28 | 8.3s |  |
| 4 | `add2` | 354 | 8.6s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 8.3s |  |
| 6 | `add_swf5` | 28 | 8.3s |  |
| 7 | `arguments` | 127 | 8.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [26](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 8.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 8.3s |  |
| 10 | `array_constructor` | 30 | 8.4s |  |
| 11 | `array_enumerate` | 4 | 8.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 8.4s |  |
| 13 | `array_properties` | 36 | 8.3s |  |
| 14 | `array_prototyping` | 12 | 8.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 8.4s |  |
| 16 | `array_sort_random` | 443 | 8.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 8.8s |  |
| 18 | `array_trivial` | 209 | 8.5s |  |
| 19 | `as1_constructor_v6` | 35 | 8.3s |  |
| 20 | `as1_constructor_v7` | 35 | 9.4s |  |
| 21 | `as2_oop` | 13 | 8.3s | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 8.0s |  |
| 23 | `as_set_prop_flags_version` | 31 | 8.1s | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 8.1s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 8.1s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 8.1s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 8.1s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 8.1s |  |
| 29 | `as_transformed_flag` | 20 | 8.1s |  |
| 30 | `attach_movie` | 59 | 8.2s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 31 | `attach_movie_stop` | 3 | 8.1s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 32 | `bad_swf_tag_past_eof` | 0 | 8.2s |  |
| 33 | `bitand` | 1058 | 10.8s |  |
| 34 | `bitmap_data_colortransform` | 0 | 8.5s |  |
| 35 | `bitmap_data_fillrect` | 0 | 8.4s |  |
| 36 | `bitmap_data_max_size_swf10` | 12 | 8.3s |  |
| 37 | `bitmap_data_max_size_swf9` | 10 | 8.2s |  |
| 38 | `bitmap_data_perlinnoise` | 0 | 8.9s |  |
| 39 | `bitmap_data_pixeldissolve_image` | 0 | 8.7s |  |
| 40 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.3s |  |
| 41 | `bitor` | 1058 | 10.8s |  |
| 42 | `biturshift` | 14 | 8.2s |  |
| 43 | `biturshift_swf8` | 14 | 9.6s |  |
| 44 | `bitxor` | 1058 | 10.7s |  |
| 45 | `boxed_primitives` | 24 | 8.3s | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 46 | `button_children` | 8 | 8.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 47 | `button_goto` | 4 | 8.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 48 | `button_order` | 2 | 8.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 49 | `button_properties_special_cases` | 22 | 8.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 50 | `button_v5` | 18 | 8.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `button_v6` | 18 | 8.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `call_method_empty_name` | 1 | 8.2s |  |
| 53 | `capabilities_resolution` | 8 | 8.2s |  |
| 54 | `catch_references_registers` | 2 | 8.0s | [39](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 55 | `clip_events` | 19 | 8.6s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 56 | `clone_sprite_types` | 24 | 8.2s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `closure_scope` | 7 | 8.3s | [41](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 58 | `color` | 57 | 8.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 59 | `color_transform` | 48 | 8.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 60 | `conflicting_instance_names` | 23 | 8.3s |  |
| 61 | `create_empty_movie_clip` | 3 | 8.2s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 62 | `define_function2` | 8 | 8.2s |  |
| 63 | `define_function2_preload` | 13 | 8.2s |  |
| 64 | `define_function2_preload_order` | 4 | 8.9s |  |
| 65 | `define_function_case_sensitive` | 2 | 8.7s |  |
| 66 | `delete` | 3 | 8.7s |  |
| 67 | `display_object_properties` | 2 | 8.7s |  |
| 68 | `divide_swf4` | 107 | 8.9s |  |
| 69 | `do_init_action` | 3 | 8.8s |  |
| 70 | `duplicate_movie_clip` | 20 | 8.7s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 71 | `edittext_antialiastype` | 296 | 8.8s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_autosize_setter` | 20 | 8.7s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_default_format` | 221 | 8.4s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_default_format_empty` | 95 | 8.2s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_default_format_font_style` | 335 | 8.3s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_html_align_swf7` | 52 | 8.3s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_html_align_swf8` | 52 | 8.3s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_html_entity` | 4 | 8.3s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_newline_stripping` | 64 | 13.5s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_width_height` | 103 | 8.5s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `empty_movieclip_can_attach_movies` | 11 | 8.6s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 82 | `enumerate` | 64 | 8.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 83 | `equals` | 32 | 8.2s |  |
| 84 | `equals2_swf5` | 926 | 9.9s |  |
| 85 | `equals2_swf6` | 926 | 9.9s |  |
| 86 | `equals2_swf7` | 926 | 9.9s |  |
| 87 | `equals_swf4` | 665 | 9.0s |  |
| 88 | `equals_swf4_alt` | 32 | 8.2s |  |
| 89 | `equals_swf5` | 32 | 8.2s |  |
| 90 | `error` | 58 | 8.2s |  |
| 91 | `escape` | 14 | 8.2s |  |
| 92 | `execution_order1` | 5 | 8.3s |  |
| 93 | `execution_order2` | 7 | 8.3s |  |
| 94 | `execution_order3` | 4 | 8.2s |  |
| 95 | `export_assets` | 3 | 8.2s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 96 | `extends_native_type` | 11 | 8.2s | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 97 | `focusrect_mouse_swf8` | 0 | 8.4s |  |
| 98 | `focusrect_mouse_swf9` | 0 | 8.7s |  |
| 99 | `focusrect_swf5` | 6 | 8.4s | [34](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 100 | `function_suppress_and_preload` | 28 | 8.4s |  |
| 101 | `get_variable_in_scope` | 29 | 8.3s |  |
| 102 | `getproperty` | 28 | 8.2s |  |
| 103 | `getproperty_swf4` | 28 | 8.7s |  |
| 104 | `getproperty_swf5` | 28 | 8.3s |  |
| 105 | `global_array` | 3 | 8.3s |  |
| 106 | `global_is_bare` | 7 | 8.2s |  |
| 107 | `globals_swf5` | 304 | 8.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 108 | `globals_swf6` | 304 | 8.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 109 | `globals_swf7` | 304 | 8.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 110 | `globals_swf8` | 304 | 8.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 111 | `goto_advance1` | 6 | 8.3s |  |
| 112 | `goto_advance2` | 2 | 8.3s |  |
| 113 | `goto_both_ways1` | 3 | 8.3s |  |
| 114 | `goto_both_ways2` | 3 | 8.3s |  |
| 115 | `goto_execution_order` | 2 | 8.3s |  |
| 116 | `goto_execution_order2` | 2 | 8.3s |  |
| 117 | `goto_frame_number` | 3 | 8.1s |  |
| 118 | `goto_rewind1` | 1 | 8.4s |  |
| 119 | `goto_rewind2` | 3 | 8.2s |  |
| 120 | `goto_rewind3` | 2 | 8.3s |  |
| 121 | `greater_swf6` | 1175 | 10.4s |  |
| 122 | `greater_swf7` | 1175 | 10.4s |  |
| 123 | `greaterthan_swf5` | 1 | 8.3s |  |
| 124 | `greaterthan_swf8` | 1 | 8.3s |  |
| 125 | `has_own_property` | 32 | 8.3s |  |
| 126 | `hittest_lockroot` | 15 | 8.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 127 | `hittest_winding_rule` | 12 | 8.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 128 | `infinite_recursion_function` | 4 | 8.4s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 129 | `infinite_recursion_function_in_setter` | 131 | 8.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 130 | `infinite_recursion_virtual_property` | 67 | 8.4s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 131 | `init_array_invalid` | 4 | 8.4s |  |
| 132 | `init_object_invalid` | 4 | 9.8s |  |
| 133 | `is_finite` | 49 | 8.4s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 134 | `is_finite_swf6` | 49 | 8.4s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 135 | `is_prototype_of` | 89 | 8.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 136 | `issue_1086` | 1 | 8.3s |  |
| 137 | `issue_1671` | 0 | 8.3s |  |
| 138 | `issue_1906` | 4 | 8.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 139 | `issue_2166` | 9 | 8.3s |  |
| 140 | `issue_3446` | 1 | 8.4s |  |
| 141 | `issue_3522` | 2 | 8.4s |  |
| 142 | `issue_4377` | 2 | 8.3s |  |
| 143 | `issue_710` | 4 | 8.4s |  |
| 144 | `issue_768` | 3 | 10.3s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 145 | `issue_9327` | 2 | 8.6s |  |
| 146 | `issue_9885` | 2 | 8.5s |  |
| 147 | `lessthan` | 41 | 8.4s |  |
| 148 | `lessthan2_swf5` | 1226 | 10.6s |  |
| 149 | `lessthan2_swf6` | 1226 | 10.6s |  |
| 150 | `lessthan2_swf7` | 1226 | 10.7s |  |
| 151 | `lessthan_swf4` | 902 | 9.7s |  |
| 152 | `lessthan_swf4_alt` | 41 | 8.5s |  |
| 153 | `lessthan_swf5` | 41 | 8.5s |  |
| 154 | `local_to_global` | 49 | 8.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 155 | `localconnection_properties` | 8 | 8.4s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 156 | `lock_root` | 1 | 8.4s |  |
| 157 | `logical_ops_swf4` | 90 | 8.4s |  |
| 158 | `logical_ops_swf8` | 108 | 8.4s |  |
| 159 | `looping` | 6 | 8.3s |  |
| 160 | `mask_reapply` | 0 | 8.3s |  |
| 161 | `mask_with_drawing` | 0 | 8.2s |  |
| 162 | `math_min_max` | 101 | 8.4s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [18](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 163 | `math_swf6` | 530 | 8.7s | [18](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 164 | `math_swf7` | 530 | 8.6s | [18](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 165 | `math_swf8` | 530 | 8.7s | [18](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 166 | `matrix` | 171 | 8.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 167 | `movieclip_begin_gradient_fill` | 0 | 8.7s |  |
| 168 | `movieclip_blend_mode_property` | 35 | 8.7s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 169 | `movieclip_default_state` | 69 | 8.5s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `movieclip_depth_methods` | 98 | 8.6s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 171 | `movieclip_focusenabled` | 99 | 8.3s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 172 | `movieclip_get_instance_at_depth` | 28 | 8.5s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 173 | `movieclip_hittest` | 92 | 8.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `movieclip_line_gradient_style` | 0 | 9.0s |  |
| 175 | `movieclip_name_from_timeline` | 13 | 8.4s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `movieclip_prototype_extension` | 5 | 8.3s |  |
| 177 | `nested_textfields_in_buttons` | 0 | 8.3s |  |
| 178 | `netstream_play_flv_screen` | 0 | 21.5s |  |
| 179 | `new_method_wrap` | 4 | 8.9s |  |
| 180 | `new_object_enumerate` | 7 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 181 | `new_object_wrap` | 4 | 8.8s |  |
| 182 | `o` | 3 | 8.9s |  |
| 183 | `object_constructor` | 33 | 9.0s |  |
| 184 | `object_function` | 32 | 8.8s |  |
| 185 | `object_properties` | 31 | 9.0s | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 186 | `object_prototypes` | 74 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 187 | `object_string_coerce_swf5` | 62 | 8.9s | [23](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 188 | `object_string_coerce_swf6` | 68 | 8.9s | [23](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 189 | `parse_int` | 64 | 9.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 190 | `placeobject_occupied_depth` | 6 | 8.9s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 191 | `point` | 175 | 9.2s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 192 | `primitive_instanceof` | 37 | 8.8s |  |
| 193 | `primitive_type_globals` | 557 | 8.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 194 | `printjob_props_swf5` | 45 | 8.6s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 195 | `printjob_props_swf6` | 45 | 8.6s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 196 | `printjob_props_swf7` | 45 | 8.8s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 197 | `prototype_delete` | 12 | 8.6s |  |
| 198 | `prototype_enumerate` | 5 | 8.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 199 | `prototype_properties` | 17 | 8.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `rectangle` | 745 | 9.4s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 201 | `recursive_prototypes` | 0 | 8.5s |  |
| 202 | `remove_movie_clip` | 29 | 8.8s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 203 | `root_onload` | 1 | 8.3s |  |
| 204 | `sandbox_type_local_file` | 1 | 8.4s |  |
| 205 | `sandbox_type_local_network` | 1 | 8.3s |  |
| 206 | `set_variable_scope` | 58 | 8.4s |  |
| 207 | `single_frame` | 1 | 8.3s |  |
| 208 | `slash_syntax` | 14 | 8.4s | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 209 | `sound_props_swf5` | 68 | 8.4s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 210 | `sound_props_swf6` | 68 | 8.4s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 211 | `sound_start_load` | 0 | 8.3s |  |
| 212 | `stage_display_state` | 16 | 8.3s | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 213 | `stage_object_enumerate` | 4 | 8.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 214 | `stage_object_properties` | 241 | 8.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 215 | `stage_object_properties_get_var` | 5 | 8.2s |  |
| 216 | `stage_property_representation` | 586 | 8.3s | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 217 | `stage_scale_mode` | 39 | 8.3s | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 218 | `strictequals_swf6` | 902 | 9.8s |  |
| 219 | `strictly_equals` | 7 | 8.3s |  |
| 220 | `string_coercion` | 117 | 8.6s | [32](ruffle-tests/_investigation/complete/string_coercion.md) |
| 221 | `string_methods` | 285 | 8.8s | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 222 | `string_methods_negative_args` | 240 | 8.4s | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 223 | `string_methods_swfv5` | 275 | 8.8s | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 224 | `string_ops_swf6` | 95 | 8.3s | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 225 | `string_paths_basic` | 4 | 8.3s | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 226 | `string_paths_timer` | 0 | 8.3s |  |
| 227 | `string_paths_variable_alias` | 4 | 8.4s | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 228 | `swf4_actions_bool` | 96 | 8.4s |  |
| 229 | `swf4_bool` | 4 | 8.4s |  |
| 230 | `swf4_function_calls` | 7 | 8.4s |  |
| 231 | `swf5_encoding` | 3 | 8.4s |  |
| 232 | `swf7_case_sensitive` | 44 | 8.3s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 233 | `tab_ordering_properties_tab_index_edge_case` | 4 | 8.5s |  |
| 234 | `target_clip_removed` | 5 | 8.6s | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 235 | `target_path` | 14 | 8.4s |  |
| 236 | `text_format` | 1146 | 8.7s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 237 | `text_format_display` | 21 | 8.5s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 238 | `text_format_font_max_length` | 2 | 8.3s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 239 | `text_format_rounding_swf7` | 840 | 8.6s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 240 | `text_format_rounding_swf8` | 840 | 8.7s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 241 | `textfield_background_color` | 11 | 8.6s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 242 | `textfield_border_color` | 11 | 9.1s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 243 | `textfield_maxchars` | 3 | 8.5s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 244 | `textfield_properties` | 44 | 8.4s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 245 | `textfield_props_swf5` | 175 | 8.5s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 246 | `textfield_props_swf6` | 210 | 8.4s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 247 | `textfield_props_swf7` | 210 | 8.4s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `textfield_props_swf8` | 210 | 8.5s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 249 | `textfield_text` | 7 | 8.2s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 250 | `textfield_variable` | 81 | 8.4s | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 251 | `this_swf7` | 41 | 8.3s | [37](ruffle-tests/_investigation/complete/this_swf7.md) |
| 252 | `timeline_function_def` | 7 | 8.4s |  |
| 253 | `transform` | 70 | 8.3s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 254 | `try_catch_finally` | 118 | 8.3s | [39](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 255 | `try_finally_simple` | 16 | 8.2s | [39](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 256 | `typeof` | 22 | 8.2s |  |
| 257 | `typeof_globals` | 7 | 8.2s |  |
| 258 | `uncaught_exception` | 1 | 8.2s | [39](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 259 | `uncaught_exception_bubbled` | 1 | 8.2s | [39](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 260 | `undefined_to_string_swf6` | 4 | 8.1s |  |
| 261 | `unescape` | 43 | 8.2s |  |
| 262 | `unload_clip_event` | 4 | 8.1s | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 263 | `use_hand_cursor` | 8 | 8.0s |  |
| 264 | `variable_args` | 5 | 8.1s |  |
| 265 | `waitforframe` | 7 | 8.1s |  |
| 266 | `waitforframe2` | 16 | 10.0s |  |
| 267 | `watch` | 117 | 8.7s | [24](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 268 | `watch_virtual_property_proto` | 2 | 8.5s | [24](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 269 | `with` | 49 | 8.5s | [41](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 270 | `with_return` | 2 | 8.5s |  |
| 271 | `with_variable_scopes` | 43 | 8.5s | [41](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 272 | `xml` | 15 | 8.5s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 273 | `xml_append_child` | 28 | 8.5s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 274 | `xml_append_child_with_parent` | 20 | 8.4s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 275 | `xml_cdata` | 11 | 8.4s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 276 | `xml_child_nodes_edge_cases` | 4 | 8.4s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 277 | `xml_clone_expandos` | 19 | 8.5s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 278 | `xml_first_last_child` | 8 | 8.5s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 279 | `xml_has_child_nodes` | 3 | 8.5s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 280 | `xml_idmap` | 21 | 8.5s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 281 | `xml_ignore_comments` | 21 | 8.5s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 282 | `xml_ignore_white` | 34 | 9.7s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 283 | `xml_insert_before` | 20 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 284 | `xml_inspect_createmethods` | 15 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 285 | `xml_inspect_doctype` | 7 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 286 | `xml_inspect_parsexml` | 62 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 287 | `xml_inspect_xmldecl` | 7 | 8.2s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 288 | `xml_namespaces` | 203 | 8.2s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 289 | `xml_parent_and_child` | 5 | 8.2s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 290 | `xml_remove_node` | 22 | 8.2s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 291 | `xml_reparenting` | 14 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 292 | `xml_siblings` | 10 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `xml_to_string` | 13 | 8.4s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 294 | `xml_to_string_comment` | 1 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 295 | `xml_unescaping` | 23 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 296 | `xmlnode_proto` | 1 | 8.3s | [42](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**52 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stage_object_properties_swf6` | 99.1% | 229 | 231 | 2 | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `hittest_morph` | 95.7% | 67 | 70 | 3 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 4 | `selection` | 95.6% | 434 | 454 | 20 | [29](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `movieclip_library_state_values` | 87.2% | 68 | 78 | 10 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 11 | `this_scoping` | 80.8% | 42 | 52 | 10 | [41](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `add_property` | 73.3% | 11 | 15 | 4 | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `register_underflow` | 69.2% | 18 | 26 | 8 | [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 18 | `unload` | 69.2% | 36 | 52 | 16 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 19 | `function_base_clip_removed` | 68.0% | 17 | 25 | 8 |  |
| 20 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 22 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 26 | `swf6_case_insensitive` | 63.6% | 28 | 44 | 16 |  |
| 27 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36 | 60 | 24 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `this_swf5` | 58.5% | 24 | 41 | 17 |  |
| 36 | `execution_order4` | 58.3% | 7 | 12 | 5 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `parse_float` | 58.1% | 43 | 74 | 31 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 39 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 42 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 43 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 44 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [29](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 49 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 50 | `movieclip_in_removed_button` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 52 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 10.4s |  |
| 2 | `goto_methods` | 9.8s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 3 | `native_objects_swf6` | 10.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 10.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 10.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 18.2s | [38](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**177 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stage_object_properties_swf6` | 99.1% | 229/231 | 231 | 231 | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `hittest_morph` | 95.7% | 67/70 | 70 | 70 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 4 | `selection` | 95.6% | 434/454 | 454 | 454 | [29](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `movieclip_library_state_values` | 87.2% | 68/78 | 74 | 78 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [31](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 11 | `this_scoping` | 80.8% | 42/52 | 52 | 52 | [41](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `add_property` | 73.3% | 11/15 | 15 | 15 | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 18 | `unload` | 69.2% | 36/52 | 52 | 52 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 19 | `function_base_clip_removed` | 68.0% | 17/25 | 25 | 25 |  |
| 20 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 22 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 26 | `swf6_case_insensitive` | 63.6% | 28/44 | 44 | 42 |  |
| 27 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `this_swf5` | 58.5% | 24/41 | 41 | 41 |  |
| 36 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 39 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 42 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 43 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 44 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [29](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 49 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 50 | `movieclip_in_removed_button` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 52 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [29](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 55 | `goto_label` | 47.1% | 8/17 | 9 | 17 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 56 | `register_globals_across_frames` | 46.7% | 7/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 57 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 59 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 60 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 61 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 62 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 63 | `property_invalid_base_clip` | 38.9% | 14/36 | 35 | 36 |  |
| 64 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 65 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 66 | `on_construct` | 36.0% | 9/25 | 12 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 67 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 71 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 72 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 73 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 75 | `swf5_no_closure` | 31.6% | 6/19 | 15 | 19 | [5](ruffle-tests/_investigation/incomplete/CLOSURE_CAPTURE_PLAN.md) |
| 76 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 77 | `default_names` | 28.8% | 15/52 | 48 | 52 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 78 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 79 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 80 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 81 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 82 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 83 | `goto_frame` | 25.0% | 3/12 | 10 | 12 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 84 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 85 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 86 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `textsnapshot_props_swf5` | 21.4% | 12/56 | 38 | 56 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 89 | `movieclip_init_object` | 20.0% | 1/5 | 2 | 5 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 90 | `tell_target_invalid_swf6` | 20.0% | 1/5 | 5 | 5 | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 91 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 92 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [38](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 93 | `goto_frame2` | 18.2% | 8/44 | 20 | 44 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 94 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 95 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 96 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 97 | `tell_target_invalid` | 16.7% | 1/6 | 5 | 6 | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 98 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [24](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 99 | `register_class_swf6` | 16.2% | 6/37 | 8 | 37 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 100 | `instanceof_coercions` | 14.8% | 13/88 | 70 | 88 |  |
| 101 | `register_and_init_order` | 14.7% | 34/231 | 85 | 231 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 102 | `path_string` | 14.6% | 47/322 | 300 | 322 | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 103 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 105 | `removed_clip_halts_script` | 13.3% | 2/15 | 13 | 15 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 106 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [24](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 107 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 108 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 110 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 112 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 113 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 114 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 116 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 117 | `tell_target` | 8.1% | 3/37 | 34 | 37 | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 118 | `call` | 7.9% | 5/63 | 28 | 63 |  |
| 119 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 120 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 121 | `define_local` | 7.4% | 2/27 | 23 | 27 | [41](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 122 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 123 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 124 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 125 | `swf4_actions_coercion_order` | 5.7% | 9/158 | 93 | 158 |  |
| 126 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [38](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 127 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 129 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 130 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 131 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 132 | `register_class` | 4.5% | 3/66 | 27 | 66 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 133 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 134 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 135 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 136 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 137 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 138 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 139 | `global_proto_decls` | 0.3% | 13/4497 | 569 | 4497 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 140 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 141 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 142 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 143 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 144 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 145 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 146 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 147 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 148 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 150 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 151 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 152 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 153 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 154 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 155 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 156 | `global_swf6_7_8` | 0.0% | 0/15 | 0 | 15 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 157 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 158 | `interface_implements_op` | 0.0% | 0/47 | 0 | 47 | [25](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 159 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 160 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 161 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 162 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 163 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [27](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 164 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 165 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 166 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 167 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 168 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 169 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 170 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 171 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/complete/STRING_PLAN.md) [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 172 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 173 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 174 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [35](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 175 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 176 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [36](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [21](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 6 | 8 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/incomplete/CLOSURE_CAPTURE_PLAN.md) | 4 | 0 | 4 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 4 | 13 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) | 49 | 0 | 49 |
| 18 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 19 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) | 1 | 0 | 1 |
| 20 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 21 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 20 | 38 |
| 22 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 23 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 24 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 25 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 26 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 27 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 28 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 4 | 11 |
| 29 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 30 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 5 | 4 |
| 31 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 5 | 2 |
| 32 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 33 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 34 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 35 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 36 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 25 | 45 |
| 37 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 38 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 39 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 40 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 41 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 42 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 192 | 144 | 48 |
