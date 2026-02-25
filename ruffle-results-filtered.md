# Ruffle Test Results (Filtered)

**Date**: 2026-02-25 03:39 UTC

**Git SHA**: `cf619be6dc`

**Run Duration**: 94m 35s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **304** (63.5%) |
| Failing | 175 |
| Total expected lines | 71493 |
| Matching lines | 47391 (66.3%) |
| Mismatched lines | 24102 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 167 | 95.4% |
| Segfault | 4 | 2.3% |
| Runtime Error | 2 | 1.1% |
| Compile Fail | 1 | 0.6% |
| Timeout | 1 | 0.6% |

## Passing Tests

**304 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 9.3s |  |
| 2 | `action_to_integer` | 28 | 8.9s |  |
| 3 | `add` | 28 | 9.0s |  |
| 4 | `add2` | 354 | 9.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 9.0s |  |
| 6 | `add_swf5` | 28 | 9.0s |  |
| 7 | `arguments` | 127 | 9.0s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 9.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 9.0s |  |
| 10 | `array_constructor` | 30 | 9.0s |  |
| 11 | `array_enumerate` | 4 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 9.0s |  |
| 13 | `array_properties` | 36 | 9.0s |  |
| 14 | `array_prototyping` | 12 | 8.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 9.0s |  |
| 16 | `array_sort_random` | 443 | 9.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 9.1s |  |
| 18 | `array_trivial` | 209 | 9.1s |  |
| 19 | `as1_constructor_v6` | 35 | 8.9s |  |
| 20 | `as1_constructor_v7` | 35 | 8.9s |  |
| 21 | `as2_oop` | 13 | 8.9s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as_broadcaster_initialize` | 10 | 8.6s |  |
| 23 | `as_set_prop_flags_version` | 31 | 8.7s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 24 | `as_set_prop_flags_version_swf5` | 1 | 8.7s |  |
| 25 | `as_set_prop_flags_version_swf6` | 1 | 8.7s |  |
| 26 | `as_set_prop_flags_version_swf7` | 1 | 8.6s |  |
| 27 | `as_set_prop_flags_version_swf8` | 1 | 8.6s |  |
| 28 | `as_set_prop_flags_version_swf9` | 1 | 8.6s |  |
| 29 | `as_transformed_flag` | 20 | 8.7s |  |
| 30 | `attach_movie` | 59 | 8.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 31 | `attach_movie_stop` | 3 | 8.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 32 | `bad_swf_tag_past_eof` | 0 | 8.8s |  |
| 33 | `bitand` | 1058 | 11.6s |  |
| 34 | `bitmap_data_colortransform` | 0 | 9.0s |  |
| 35 | `bitmap_data_fillrect` | 0 | 9.1s |  |
| 36 | `bitmap_data_max_size_swf10` | 12 | 9.3s |  |
| 37 | `bitmap_data_max_size_swf9` | 10 | 9.2s |  |
| 38 | `bitmap_data_perlinnoise` | 0 | 9.8s |  |
| 39 | `bitmap_data_pixeldissolve_image` | 0 | 9.5s |  |
| 40 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.1s |  |
| 41 | `bitor` | 1058 | 12.1s |  |
| 42 | `biturshift` | 14 | 9.2s |  |
| 43 | `biturshift_swf8` | 14 | 10.4s |  |
| 44 | `bitxor` | 1058 | 11.2s |  |
| 45 | `boxed_primitives` | 24 | 8.7s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 46 | `button_children` | 8 | 8.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 47 | `button_goto` | 4 | 8.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 48 | `button_order` | 2 | 8.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 49 | `button_properties_special_cases` | 22 | 8.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 50 | `button_v5` | 18 | 8.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `button_v6` | 18 | 8.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `call_method_empty_name` | 1 | 8.6s |  |
| 53 | `capabilities_resolution` | 8 | 8.7s |  |
| 54 | `catch_references_registers` | 2 | 8.6s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 55 | `clip_events` | 19 | 8.9s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 56 | `clone_sprite_types` | 24 | 8.6s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `closure_scope` | 7 | 8.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 58 | `color` | 57 | 8.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 59 | `color_transform` | 48 | 8.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 60 | `conflicting_instance_names` | 23 | 8.7s |  |
| 61 | `create_empty_movie_clip` | 3 | 8.6s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 62 | `define_function2` | 8 | 8.6s |  |
| 63 | `define_function2_preload` | 13 | 8.6s |  |
| 64 | `define_function_case_sensitive` | 2 | 8.7s |  |
| 65 | `delete` | 3 | 8.8s |  |
| 66 | `display_object_properties` | 2 | 8.6s |  |
| 67 | `divide_swf4` | 107 | 8.7s |  |
| 68 | `do_init_action` | 3 | 8.7s |  |
| 69 | `duplicate_movie_clip` | 20 | 8.8s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `edittext_antialiastype` | 296 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `edittext_autosize_setter` | 20 | 9.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `edittext_default_format` | 221 | 9.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `edittext_default_format_empty` | 95 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `edittext_default_format_font_style` | 335 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_html_align_swf7` | 52 | 9.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_html_align_swf8` | 52 | 9.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_html_entity` | 4 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_newline_stripping` | 64 | 13.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_width_height` | 103 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `empty_movieclip_can_attach_movies` | 11 | 9.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 81 | `enumerate` | 64 | 8.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 82 | `equals` | 32 | 8.7s |  |
| 83 | `equals2_swf5` | 926 | 10.4s |  |
| 84 | `equals2_swf6` | 926 | 10.5s |  |
| 85 | `equals2_swf7` | 926 | 10.5s |  |
| 86 | `equals_swf4` | 665 | 9.5s |  |
| 87 | `equals_swf4_alt` | 32 | 8.7s |  |
| 88 | `equals_swf5` | 32 | 8.8s |  |
| 89 | `error` | 58 | 8.7s |  |
| 90 | `escape` | 14 | 8.8s |  |
| 91 | `execution_order1` | 5 | 8.8s |  |
| 92 | `execution_order3` | 4 | 8.6s |  |
| 93 | `export_assets` | 3 | 8.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 94 | `extends_native_type` | 11 | 8.7s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 95 | `focusrect_mouse_swf8` | 0 | 9.1s |  |
| 96 | `focusrect_mouse_swf9` | 0 | 9.3s |  |
| 97 | `focusrect_swf5` | 6 | 9.0s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 98 | `function_suppress_and_preload` | 28 | 9.0s |  |
| 99 | `get_variable_in_scope` | 29 | 9.0s |  |
| 100 | `getproperty` | 28 | 8.9s |  |
| 101 | `getproperty_swf4` | 28 | 8.9s |  |
| 102 | `getproperty_swf5` | 28 | 8.7s |  |
| 103 | `global_array` | 3 | 8.7s |  |
| 104 | `global_is_bare` | 7 | 8.7s |  |
| 105 | `globals_swf5` | 304 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 106 | `globals_swf6` | 304 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 107 | `globals_swf7` | 304 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 108 | `globals_swf8` | 304 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 109 | `goto_advance1` | 6 | 8.7s |  |
| 110 | `goto_advance2` | 2 | 8.7s |  |
| 111 | `goto_both_ways1` | 3 | 8.7s |  |
| 112 | `goto_both_ways2` | 3 | 8.7s |  |
| 113 | `goto_execution_order` | 2 | 8.7s |  |
| 114 | `goto_execution_order2` | 2 | 8.7s |  |
| 115 | `goto_frame` | 12 | 9.4s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 116 | `goto_frame_number` | 3 | 8.9s |  |
| 117 | `goto_label` | 17 | 9.0s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 118 | `goto_methods` | 40 | 8.9s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 119 | `goto_rewind1` | 1 | 8.9s |  |
| 120 | `goto_rewind2` | 3 | 8.9s |  |
| 121 | `goto_rewind3` | 2 | 8.9s |  |
| 122 | `greater_swf6` | 1175 | 10.9s |  |
| 123 | `greater_swf7` | 1175 | 10.8s |  |
| 124 | `greaterthan_swf5` | 1 | 8.8s |  |
| 125 | `greaterthan_swf8` | 1 | 8.9s |  |
| 126 | `has_own_property` | 32 | 8.9s |  |
| 127 | `hittest_lockroot` | 15 | 9.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 128 | `hittest_winding_rule` | 12 | 9.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 129 | `infinite_recursion_function` | 4 | 8.8s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 130 | `infinite_recursion_function_in_setter` | 131 | 8.8s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 131 | `infinite_recursion_virtual_property` | 67 | 8.8s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 132 | `init_array_invalid` | 4 | 8.8s |  |
| 133 | `init_object_invalid` | 4 | 10.2s |  |
| 134 | `is_finite` | 49 | 8.8s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 135 | `is_finite_swf6` | 49 | 8.8s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 136 | `is_prototype_of` | 89 | 8.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 137 | `issue_1086` | 1 | 8.7s |  |
| 138 | `issue_1671` | 0 | 8.8s |  |
| 139 | `issue_1906` | 4 | 8.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 140 | `issue_2166` | 9 | 8.7s |  |
| 141 | `issue_3446` | 1 | 8.7s |  |
| 142 | `issue_3522` | 2 | 8.7s |  |
| 143 | `issue_4377` | 2 | 8.7s |  |
| 144 | `issue_710` | 4 | 8.8s |  |
| 145 | `issue_768` | 3 | 9.0s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 146 | `issue_9327` | 2 | 8.9s |  |
| 147 | `issue_9885` | 2 | 8.8s |  |
| 148 | `lessthan` | 41 | 9.0s |  |
| 149 | `lessthan2_swf5` | 1226 | 11.1s |  |
| 150 | `lessthan2_swf6` | 1226 | 10.9s |  |
| 151 | `lessthan2_swf7` | 1226 | 11.0s |  |
| 152 | `lessthan_swf4` | 902 | 10.1s |  |
| 153 | `lessthan_swf4_alt` | 41 | 9.0s |  |
| 154 | `lessthan_swf5` | 41 | 9.0s |  |
| 155 | `local_to_global` | 49 | 8.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 156 | `localconnection_properties` | 8 | 8.9s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 157 | `lock_root` | 1 | 9.1s |  |
| 158 | `logical_ops_swf4` | 90 | 9.1s |  |
| 159 | `logical_ops_swf8` | 108 | 9.1s |  |
| 160 | `looping` | 6 | 9.0s |  |
| 161 | `mask_reapply` | 0 | 9.0s |  |
| 162 | `mask_with_drawing` | 0 | 8.9s |  |
| 163 | `math_min_max` | 101 | 9.2s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 164 | `math_swf6` | 530 | 9.3s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 165 | `math_swf7` | 530 | 9.3s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 166 | `math_swf8` | 530 | 9.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 167 | `matrix` | 171 | 9.2s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 168 | `movieclip_begin_gradient_fill` | 0 | 9.4s |  |
| 169 | `movieclip_blend_mode_property` | 35 | 11.3s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `movieclip_depth_methods` | 98 | 9.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 171 | `movieclip_focusenabled` | 99 | 8.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 172 | `movieclip_get_instance_at_depth` | 28 | 8.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 173 | `movieclip_hittest` | 92 | 8.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `movieclip_line_gradient_style` | 0 | 9.4s |  |
| 175 | `movieclip_name_from_timeline` | 13 | 8.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `movieclip_prototype_extension` | 5 | 8.8s |  |
| 177 | `mutable_this` | 18 | 8.6s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 178 | `nested_textfields_in_buttons` | 0 | 8.6s |  |
| 179 | `netstream_play_flv_screen` | 0 | 21.5s |  |
| 180 | `new_method_wrap` | 4 | 8.8s |  |
| 181 | `new_object_enumerate` | 7 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 182 | `new_object_wrap` | 4 | 8.9s |  |
| 183 | `o` | 3 | 8.9s |  |
| 184 | `object_constructor` | 33 | 8.8s |  |
| 185 | `object_function` | 32 | 8.8s |  |
| 186 | `object_properties` | 31 | 8.8s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 187 | `object_prototypes` | 74 | 8.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 188 | `object_string_coerce_swf5` | 62 | 8.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 189 | `object_string_coerce_swf6` | 68 | 8.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 190 | `parse_int` | 64 | 9.3s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 191 | `placeobject_occupied_depth` | 6 | 9.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 192 | `point` | 175 | 9.2s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 193 | `primitive_instanceof` | 37 | 8.7s |  |
| 194 | `primitive_type_globals` | 557 | 10.7s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 195 | `printjob_props_swf5` | 45 | 9.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 196 | `printjob_props_swf6` | 45 | 9.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 197 | `printjob_props_swf7` | 45 | 9.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 198 | `prototype_delete` | 12 | 9.0s |  |
| 199 | `prototype_enumerate` | 5 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `prototype_properties` | 17 | 9.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 201 | `rectangle` | 745 | 9.8s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 202 | `recursive_prototypes` | 0 | 9.0s |  |
| 203 | `register_globals_across_frames` | 15 | 9.0s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 204 | `register_underflow` | 26 | 9.0s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 205 | `remove_movie_clip` | 29 | 9.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 206 | `sandbox_type_local_file` | 1 | 8.7s |  |
| 207 | `sandbox_type_local_network` | 1 | 8.7s |  |
| 208 | `set_variable_scope` | 58 | 8.7s |  |
| 209 | `single_frame` | 1 | 8.6s |  |
| 210 | `slash_syntax` | 14 | 8.7s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 211 | `sound_props_swf5` | 68 | 8.6s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 212 | `sound_props_swf6` | 68 | 8.6s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 213 | `sound_start_load` | 0 | 8.6s |  |
| 214 | `stage_display_state` | 16 | 8.5s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 215 | `stage_object_enumerate` | 4 | 8.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 216 | `stage_object_properties` | 241 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 217 | `stage_object_properties_get_var` | 5 | 8.5s |  |
| 218 | `stage_object_properties_swf6` | 231 | 8.8s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 219 | `stage_property_representation` | 586 | 8.5s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 220 | `stage_scale_mode` | 39 | 8.5s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 221 | `strictequals_swf6` | 902 | 9.9s |  |
| 222 | `strictly_equals` | 7 | 8.5s |  |
| 223 | `string_coercion` | 117 | 8.8s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 224 | `string_methods` | 285 | 9.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 225 | `string_methods_negative_args` | 240 | 8.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 226 | `string_methods_swfv5` | 275 | 9.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 227 | `string_ops_swf6` | 95 | 8.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 228 | `string_paths_basic` | 4 | 8.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 229 | `string_paths_timer` | 0 | 8.7s |  |
| 230 | `string_paths_variable_alias` | 4 | 8.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 231 | `swf4_actions_bool` | 96 | 8.7s |  |
| 232 | `swf4_actions_coercion_order` | 158 | 8.8s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 233 | `swf4_bool` | 4 | 8.6s |  |
| 234 | `swf4_function_calls` | 7 | 8.7s |  |
| 235 | `swf5_encoding` | 3 | 8.6s |  |
| 236 | `swf6_case_insensitive` | 42 | 8.9s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 237 | `swf6_string_as_bool` | 15 | 8.9s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 238 | `swf7_case_sensitive` | 44 | 8.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 239 | `tab_ordering_properties_tab_index_edge_case` | 4 | 8.8s |  |
| 240 | `target_clip_removed` | 5 | 8.8s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 241 | `target_path` | 14 | 8.7s |  |
| 242 | `text_format` | 1146 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 243 | `text_format_display` | 21 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 244 | `text_format_font_max_length` | 2 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 245 | `text_format_rounding_swf7` | 840 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 246 | `text_format_rounding_swf8` | 840 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 247 | `textfield_background_color` | 11 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `textfield_border_color` | 11 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 249 | `textfield_maxchars` | 3 | 9.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 250 | `textfield_properties` | 44 | 8.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 251 | `textfield_props_swf5` | 175 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `textfield_props_swf6` | 210 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `textfield_props_swf7` | 210 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `textfield_props_swf8` | 210 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `textfield_text` | 7 | 8.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `textfield_variable` | 81 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `this_swf5` | 41 | 8.6s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 258 | `this_swf6` | 41 | 8.6s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 259 | `this_swf7` | 41 | 8.6s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 260 | `timeline_function_def` | 7 | 8.7s |  |
| 261 | `transform` | 70 | 8.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 262 | `try_catch_finally` | 118 | 8.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 263 | `try_finally_simple` | 16 | 8.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 264 | `typeof` | 22 | 8.7s |  |
| 265 | `typeof_globals` | 7 | 8.7s |  |
| 266 | `uncaught_exception` | 1 | 8.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 267 | `uncaught_exception_bubbled` | 1 | 8.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 268 | `undefined_to_string_swf6` | 4 | 8.7s |  |
| 269 | `unescape` | 43 | 8.8s |  |
| 270 | `unload_clip_event` | 4 | 8.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 271 | `use_hand_cursor` | 8 | 8.7s |  |
| 272 | `variable_args` | 5 | 8.8s |  |
| 273 | `waitforframe` | 7 | 8.7s |  |
| 274 | `waitforframe2` | 16 | 8.8s |  |
| 275 | `watch` | 117 | 8.9s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 276 | `watch_virtual_property_proto` | 2 | 8.7s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 277 | `with` | 49 | 8.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 278 | `with_return` | 2 | 8.6s |  |
| 279 | `with_variable_scopes` | 43 | 8.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 280 | `xml` | 15 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 281 | `xml_append_child` | 28 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 282 | `xml_append_child_with_parent` | 20 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 283 | `xml_cdata` | 11 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 284 | `xml_child_nodes_edge_cases` | 4 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 285 | `xml_clone_expandos` | 19 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 286 | `xml_first_last_child` | 8 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 287 | `xml_has_child_nodes` | 3 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 288 | `xml_idmap` | 21 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 289 | `xml_ignore_comments` | 21 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 290 | `xml_ignore_white` | 34 | 9.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 291 | `xml_insert_before` | 20 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 292 | `xml_inspect_createmethods` | 15 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `xml_inspect_doctype` | 7 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 294 | `xml_inspect_parsexml` | 62 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 295 | `xml_inspect_xmldecl` | 7 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 296 | `xml_namespaces` | 203 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 297 | `xml_parent_and_child` | 5 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_remove_node` | 22 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_reparenting` | 14 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 300 | `xml_siblings` | 10 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 301 | `xml_to_string` | 13 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_to_string_comment` | 1 | 8.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_unescaping` | 23 | 8.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xmlnode_proto` | 1 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**53 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `hittest_morph` | 95.7% | 67 | 70 | 3 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 3 | `movieclip_default_state` | 95.7% | 66 | 69 | 3 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `selection` | 95.6% | 434 | 454 | 20 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `property_invalid_base_clip` | 94.4% | 34 | 36 | 2 |  |
| 8 | `movieclip_library_state_values` | 89.7% | 70 | 78 | 8 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 10 | `swf5_no_closure` | 84.2% | 16 | 19 | 3 | [5](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 11 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 13 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 14 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `add_property` | 73.3% | 11 | 15 | 4 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 19 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 20 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 21 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 22 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 27 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `execution_order4` | 58.3% | 7 | 12 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 36 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `parse_float` | 58.1% | 43 | 74 | 31 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 38 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `execution_order2` | 57.1% | 4 | 7 | 3 |  |
| 40 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 42 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 43 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 44 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `define_function2_preload_order` | 50.0% | 2 | 4 | 2 |  |
| 47 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 50 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 51 | `movieclip_in_removed_button` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 53 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 11.2s |  |
| 2 | `native_objects_swf6` | 11.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf7` | 11.2s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 11.2s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 31.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 32.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 18.6s | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**167 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `hittest_morph` | 95.7% | 67/70 | 70 | 70 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 3 | `movieclip_default_state` | 95.7% | 66/69 | 69 | 69 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `selection` | 95.6% | 434/454 | 454 | 454 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `property_invalid_base_clip` | 94.4% | 34/36 | 36 | 36 |  |
| 8 | `movieclip_library_state_values` | 89.7% | 70/78 | 74 | 78 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 10 | `swf5_no_closure` | 84.2% | 16/19 | 19 | 19 | [5](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 11 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 12 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 13 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 14 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 16 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `add_property` | 73.3% | 11/15 | 15 | 15 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 18 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 19 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 20 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 21 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 22 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 27 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 36 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 38 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `execution_order2` | 57.1% | 4/7 | 7 | 7 |  |
| 40 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 42 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 43 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 44 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `define_function2_preload_order` | 50.0% | 2/4 | 4 | 4 |  |
| 47 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 50 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 51 | `movieclip_in_removed_button` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 53 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 56 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 58 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 59 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 60 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 61 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 62 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 63 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 64 | `on_construct` | 36.0% | 9/25 | 12 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 65 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 69 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 71 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 73 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 74 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 75 | `goto_frame2` | 29.5% | 13/44 | 19 | 44 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 76 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 77 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 78 | `string_paths_eval2` | 28.6% | 2/7 | 2 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 79 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 80 | `tell_target` | 26.3% | 10/38 | 38 | 37 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 81 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 82 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 83 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 84 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 85 | `textsnapshot_props_swf5` | 25.0% | 14/56 | 38 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `this_scoping` | 20.8% | 11/53 | 53 | 52 | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 88 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 89 | `movieclip_init_object` | 20.0% | 1/5 | 2 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 90 | `tell_target_invalid` | 20.0% | 2/10 | 10 | 6 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 91 | `tell_target_invalid_swf6` | 20.0% | 2/10 | 10 | 5 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 92 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 93 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 94 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 95 | `super_edge_cases` | 17.9% | 7/39 | 33 | 39 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 96 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 97 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 98 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 99 | `register_class_swf6` | 16.2% | 6/37 | 8 | 37 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 100 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 6 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 101 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 6 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 102 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 103 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 104 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 105 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 106 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 108 | `register_and_init_order` | 11.7% | 27/231 | 61 | 231 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 109 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `path_string` | 10.9% | 38/350 | 350 | 322 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 111 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 112 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 113 | `register_class` | 7.6% | 5/66 | 44 | 66 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 114 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 115 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 117 | `coerce_to_object_monkeypatch` | 7.0% | 9/129 | 80 | 129 |  |
| 118 | `removed_clip_halts_script` | 6.7% | 1/15 | 15 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 119 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 120 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 121 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 122 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 123 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 124 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 125 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 126 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 127 | `movieclip_invalid_get_bounds_2` | 4.0% | 3/75 | 3 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `movieclip_invalid_get_bounds_1` | 2.7% | 2/75 | 3 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 129 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 130 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 131 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 132 | `global_proto_decls` | 0.4% | 16/4497 | 572 | 4497 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 133 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 134 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 135 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 136 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 137 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 138 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 139 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 140 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 141 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 142 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 143 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 144 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 145 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 146 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 147 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 148 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 149 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 150 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 151 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 152 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 153 | `movieclip_methods_with_loaded_image` | 0.0% | 0/8 | 8 | 4 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 154 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 155 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 156 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 157 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 158 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 159 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 160 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 161 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 162 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 163 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 164 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 165 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 166 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 167 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 6 | 8 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) | 4 | 0 | 4 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 3 | 1 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 15 | 16 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 4 | 13 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) | 49 | 0 | 49 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) | 1 | 0 | 1 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 19 | 39 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 6 | 11 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 2 | 6 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 7 | 5 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 6 | 9 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 6 | 3 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 6 | 1 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 25 | 45 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 3 | 2 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 141 | 45 |
