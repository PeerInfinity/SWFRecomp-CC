# Ruffle Test Results (Filtered)

**Date**: 2026-02-25 20:15 UTC

**Git SHA**: `a9f8745287`

**Run Duration**: 97m 53s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **309** (64.5%) |
| Failing | 170 |
| Total expected lines | 71493 |
| Matching lines | 47750 (66.8%) |
| Mismatched lines | 23743 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 162 | 95.3% |
| Segfault | 4 | 2.4% |
| Runtime Error | 2 | 1.2% |
| Compile Fail | 1 | 0.6% |
| Timeout | 1 | 0.6% |

## Passing Tests

**309 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.6s |  |
| 2 | `action_to_integer` | 28 | 9.1s |  |
| 3 | `add` | 28 | 9.2s |  |
| 4 | `add2` | 354 | 9.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_swf4` | 28 | 9.2s |  |
| 6 | `add_swf5` | 28 | 9.3s |  |
| 7 | `arguments` | 127 | 9.2s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 9.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 9.2s |  |
| 10 | `array_constructor` | 30 | 9.2s |  |
| 11 | `array_enumerate` | 4 | 9.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 9.2s |  |
| 13 | `array_properties` | 36 | 9.2s |  |
| 14 | `array_prototyping` | 12 | 9.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 9.3s |  |
| 16 | `array_sort_random` | 443 | 9.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 9.4s |  |
| 18 | `array_trivial` | 209 | 9.4s |  |
| 19 | `as1_constructor_v6` | 35 | 9.2s |  |
| 20 | `as1_constructor_v7` | 35 | 9.0s |  |
| 21 | `as2_oop` | 13 | 8.9s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as2_super_and_this_v6` | 97 | 9.0s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v8` | 85 | 9.1s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_via_manual_prototype` | 40 | 9.0s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as_broadcaster_initialize` | 10 | 8.8s |  |
| 26 | `as_set_prop_flags_version` | 31 | 8.7s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 27 | `as_set_prop_flags_version_swf5` | 1 | 8.8s |  |
| 28 | `as_set_prop_flags_version_swf6` | 1 | 8.8s |  |
| 29 | `as_set_prop_flags_version_swf7` | 1 | 8.7s |  |
| 30 | `as_set_prop_flags_version_swf8` | 1 | 8.8s |  |
| 31 | `as_set_prop_flags_version_swf9` | 1 | 8.8s |  |
| 32 | `as_transformed_flag` | 20 | 8.8s |  |
| 33 | `attach_movie` | 59 | 8.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 34 | `attach_movie_stop` | 3 | 8.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 35 | `bad_swf_tag_past_eof` | 0 | 8.9s |  |
| 36 | `bitand` | 1058 | 11.7s |  |
| 37 | `bitmap_data_colortransform` | 0 | 9.3s |  |
| 38 | `bitmap_data_fillrect` | 0 | 9.3s |  |
| 39 | `bitmap_data_max_size_swf10` | 12 | 9.1s |  |
| 40 | `bitmap_data_max_size_swf9` | 10 | 9.2s |  |
| 41 | `bitmap_data_perlinnoise` | 0 | 10.0s |  |
| 42 | `bitmap_data_pixeldissolve_image` | 0 | 9.6s |  |
| 43 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.0s |  |
| 44 | `bitor` | 1058 | 11.6s |  |
| 45 | `biturshift` | 14 | 8.9s |  |
| 46 | `biturshift_swf8` | 14 | 9.3s |  |
| 47 | `bitxor` | 1058 | 12.0s |  |
| 48 | `boxed_primitives` | 24 | 9.3s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 49 | `button_children` | 8 | 9.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 50 | `button_goto` | 4 | 9.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `button_order` | 2 | 8.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `button_properties_special_cases` | 22 | 9.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_v5` | 18 | 8.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_v6` | 18 | 8.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `call_method_empty_name` | 1 | 8.8s |  |
| 56 | `capabilities_resolution` | 8 | 8.9s |  |
| 57 | `catch_references_registers` | 2 | 8.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 58 | `clip_events` | 19 | 9.2s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 59 | `clone_sprite_types` | 24 | 8.9s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 60 | `closure_scope` | 7 | 9.0s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 61 | `color` | 57 | 9.1s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 62 | `color_transform` | 48 | 9.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 63 | `conflicting_instance_names` | 23 | 8.9s |  |
| 64 | `create_empty_movie_clip` | 3 | 8.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 65 | `define_function2` | 8 | 8.9s |  |
| 66 | `define_function2_preload` | 13 | 8.9s |  |
| 67 | `define_function2_preload_order` | 4 | 9.8s |  |
| 68 | `define_function_case_sensitive` | 2 | 9.5s |  |
| 69 | `delete` | 3 | 9.6s |  |
| 70 | `display_object_properties` | 2 | 9.5s |  |
| 71 | `divide_swf4` | 107 | 9.6s |  |
| 72 | `do_init_action` | 3 | 9.6s |  |
| 73 | `duplicate_movie_clip` | 20 | 9.7s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 74 | `edittext_antialiastype` | 296 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `edittext_autosize_setter` | 20 | 14.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 76 | `edittext_default_format` | 221 | 9.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_default_format_empty` | 95 | 9.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_default_format_font_style` | 335 | 9.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_html_align_swf7` | 52 | 9.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_html_align_swf8` | 52 | 9.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_html_entity` | 4 | 9.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_newline_stripping` | 64 | 13.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_width_height` | 103 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `empty_movieclip_can_attach_movies` | 11 | 10.4s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 85 | `enumerate` | 64 | 9.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 86 | `equals` | 32 | 9.3s |  |
| 87 | `equals2_swf5` | 926 | 10.8s |  |
| 88 | `equals2_swf6` | 926 | 10.7s |  |
| 89 | `equals2_swf7` | 926 | 10.7s |  |
| 90 | `equals_swf4` | 665 | 9.8s |  |
| 91 | `equals_swf4_alt` | 32 | 9.0s |  |
| 92 | `equals_swf5` | 32 | 9.0s |  |
| 93 | `error` | 58 | 9.0s |  |
| 94 | `escape` | 14 | 9.0s |  |
| 95 | `execution_order1` | 5 | 9.0s |  |
| 96 | `execution_order2` | 7 | 9.1s |  |
| 97 | `export_assets` | 3 | 8.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 98 | `extends_chain` | 134 | 9.4s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 99 | `extends_native_type` | 11 | 9.0s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 100 | `focusrect_mouse_swf8` | 0 | 9.3s |  |
| 101 | `focusrect_mouse_swf9` | 0 | 9.6s |  |
| 102 | `focusrect_swf5` | 6 | 9.6s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 103 | `function_suppress_and_preload` | 28 | 9.3s |  |
| 104 | `get_variable_in_scope` | 29 | 9.1s |  |
| 105 | `getproperty` | 28 | 9.2s |  |
| 106 | `getproperty_swf4` | 28 | 10.9s |  |
| 107 | `getproperty_swf5` | 28 | 9.0s |  |
| 108 | `global_array` | 3 | 9.2s |  |
| 109 | `global_is_bare` | 7 | 9.0s |  |
| 110 | `globals_swf5` | 304 | 9.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 111 | `globals_swf6` | 304 | 9.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 112 | `globals_swf7` | 304 | 9.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 113 | `globals_swf8` | 304 | 9.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 114 | `goto_advance1` | 6 | 9.0s |  |
| 115 | `goto_advance2` | 2 | 8.9s |  |
| 116 | `goto_both_ways1` | 3 | 9.0s |  |
| 117 | `goto_both_ways2` | 3 | 9.0s |  |
| 118 | `goto_execution_order` | 2 | 8.9s |  |
| 119 | `goto_frame` | 12 | 11.1s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 120 | `goto_frame_number` | 3 | 9.0s |  |
| 121 | `goto_label` | 17 | 9.1s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 122 | `goto_methods` | 40 | 9.0s | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 123 | `goto_rewind1` | 1 | 8.9s |  |
| 124 | `goto_rewind2` | 3 | 8.9s |  |
| 125 | `goto_rewind3` | 2 | 8.9s |  |
| 126 | `greater_swf6` | 1175 | 10.9s |  |
| 127 | `greater_swf7` | 1175 | 10.8s |  |
| 128 | `greaterthan_swf5` | 1 | 8.9s |  |
| 129 | `greaterthan_swf8` | 1 | 8.9s |  |
| 130 | `has_own_property` | 32 | 8.9s |  |
| 131 | `hittest_lockroot` | 15 | 9.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 132 | `hittest_winding_rule` | 12 | 9.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 133 | `infinite_recursion_function` | 4 | 8.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 134 | `infinite_recursion_function_in_setter` | 131 | 8.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 135 | `infinite_recursion_virtual_property` | 67 | 8.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 136 | `init_array_invalid` | 4 | 8.9s |  |
| 137 | `init_object_invalid` | 4 | 9.6s |  |
| 138 | `is_finite` | 49 | 9.2s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 139 | `is_finite_swf6` | 49 | 9.2s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 140 | `is_prototype_of` | 89 | 9.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 141 | `issue_1086` | 1 | 9.1s |  |
| 142 | `issue_1671` | 0 | 9.0s |  |
| 143 | `issue_1906` | 4 | 9.1s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 144 | `issue_2166` | 9 | 9.1s |  |
| 145 | `issue_3446` | 1 | 9.0s |  |
| 146 | `issue_3522` | 2 | 9.1s |  |
| 147 | `issue_4377` | 2 | 9.1s |  |
| 148 | `issue_710` | 4 | 9.1s |  |
| 149 | `issue_768` | 3 | 9.5s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 150 | `issue_9327` | 2 | 9.3s |  |
| 151 | `issue_9885` | 2 | 9.2s |  |
| 152 | `lessthan` | 41 | 9.3s |  |
| 153 | `lessthan2_swf5` | 1226 | 11.3s |  |
| 154 | `lessthan2_swf6` | 1226 | 11.3s |  |
| 155 | `lessthan2_swf7` | 1226 | 11.4s |  |
| 156 | `lessthan_swf4` | 902 | 10.4s |  |
| 157 | `lessthan_swf4_alt` | 41 | 9.2s |  |
| 158 | `lessthan_swf5` | 41 | 9.2s |  |
| 159 | `local_to_global` | 49 | 9.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 160 | `localconnection_properties` | 8 | 9.2s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 161 | `lock_root` | 1 | 9.2s |  |
| 162 | `logical_ops_swf4` | 90 | 9.2s |  |
| 163 | `logical_ops_swf8` | 108 | 9.2s |  |
| 164 | `looping` | 6 | 9.2s |  |
| 165 | `mask_reapply` | 0 | 9.2s |  |
| 166 | `mask_with_drawing` | 0 | 9.2s |  |
| 167 | `math_min_max` | 101 | 9.3s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 168 | `math_swf6` | 530 | 9.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 169 | `math_swf7` | 530 | 9.5s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 170 | `math_swf8` | 530 | 9.5s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 171 | `matrix` | 171 | 9.5s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 172 | `movieclip_begin_gradient_fill` | 0 | 9.5s |  |
| 173 | `movieclip_blend_mode_property` | 35 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 174 | `movieclip_depth_methods` | 98 | 9.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 175 | `movieclip_focusenabled` | 99 | 9.6s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `movieclip_get_instance_at_depth` | 28 | 9.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 177 | `movieclip_hittest` | 92 | 9.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 178 | `movieclip_line_gradient_style` | 0 | 10.3s |  |
| 179 | `movieclip_name_from_timeline` | 13 | 9.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 180 | `movieclip_prototype_extension` | 5 | 9.1s |  |
| 181 | `mutable_this` | 18 | 9.2s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 182 | `nested_textfields_in_buttons` | 0 | 9.2s |  |
| 183 | `netstream_play_flv_screen` | 0 | 22.3s |  |
| 184 | `new_method_wrap` | 4 | 8.9s |  |
| 185 | `new_object_enumerate` | 7 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 186 | `new_object_wrap` | 4 | 8.9s |  |
| 187 | `o` | 3 | 8.9s |  |
| 188 | `object_constructor` | 33 | 8.9s |  |
| 189 | `object_function` | 32 | 8.9s |  |
| 190 | `object_properties` | 31 | 9.1s | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 191 | `object_prototypes` | 74 | 9.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 192 | `object_string_coerce_swf5` | 62 | 8.9s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 193 | `object_string_coerce_swf6` | 68 | 9.0s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 194 | `parse_int` | 64 | 9.2s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 195 | `placeobject_occupied_depth` | 6 | 9.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 196 | `point` | 175 | 9.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 197 | `primitive_instanceof` | 37 | 9.0s |  |
| 198 | `primitive_type_globals` | 557 | 9.3s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 199 | `printjob_props_swf5` | 45 | 9.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 200 | `printjob_props_swf6` | 45 | 9.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 201 | `printjob_props_swf7` | 45 | 9.1s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 202 | `prototype_delete` | 12 | 9.0s |  |
| 203 | `prototype_enumerate` | 5 | 8.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 204 | `prototype_properties` | 17 | 9.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 205 | `rectangle` | 745 | 9.7s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 206 | `recursive_prototypes` | 0 | 9.0s |  |
| 207 | `register_globals_across_frames` | 15 | 9.0s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 208 | `register_underflow` | 26 | 9.0s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 209 | `remove_movie_clip` | 29 | 9.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 210 | `sandbox_type_local_file` | 1 | 9.0s |  |
| 211 | `sandbox_type_local_network` | 1 | 9.0s |  |
| 212 | `set_variable_scope` | 58 | 9.0s |  |
| 213 | `single_frame` | 1 | 8.9s |  |
| 214 | `slash_syntax` | 14 | 9.1s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 215 | `sound_props_swf5` | 68 | 9.8s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 216 | `sound_props_swf6` | 68 | 9.7s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 217 | `sound_start_load` | 0 | 9.6s |  |
| 218 | `stage_display_state` | 16 | 9.6s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 219 | `stage_object_enumerate` | 4 | 9.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 220 | `stage_object_properties` | 241 | 10.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 221 | `stage_object_properties_get_var` | 5 | 9.7s |  |
| 222 | `stage_object_properties_swf6` | 231 | 10.0s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 223 | `stage_property_representation` | 586 | 9.7s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 224 | `stage_scale_mode` | 39 | 9.6s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 225 | `strictequals_swf6` | 902 | 11.4s |  |
| 226 | `strictly_equals` | 7 | 9.6s |  |
| 227 | `string_coercion` | 117 | 9.8s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 228 | `string_methods` | 285 | 10.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 229 | `string_methods_negative_args` | 240 | 9.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 230 | `string_methods_swfv5` | 275 | 10.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 231 | `string_ops_swf6` | 95 | 9.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 232 | `string_paths_basic` | 4 | 9.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 233 | `string_paths_timer` | 0 | 8.9s |  |
| 234 | `string_paths_variable_alias` | 4 | 8.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 235 | `swf4_actions_bool` | 96 | 8.9s |  |
| 236 | `swf4_actions_coercion_order` | 158 | 9.0s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 237 | `swf4_bool` | 4 | 8.9s |  |
| 238 | `swf4_function_calls` | 7 | 8.9s |  |
| 239 | `swf5_encoding` | 3 | 8.8s |  |
| 240 | `swf5_no_closure` | 19 | 9.7s | [5](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 241 | `swf6_case_insensitive` | 42 | 9.0s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 242 | `swf6_string_as_bool` | 15 | 9.1s | [38](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 243 | `swf7_case_sensitive` | 44 | 8.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 244 | `tab_ordering_properties_tab_index_edge_case` | 4 | 8.8s |  |
| 245 | `target_clip_removed` | 5 | 8.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 246 | `target_path` | 14 | 8.9s |  |
| 247 | `text_format` | 1146 | 9.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 248 | `text_format_display` | 21 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 249 | `text_format_font_max_length` | 2 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 250 | `text_format_rounding_swf7` | 840 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 251 | `text_format_rounding_swf8` | 840 | 8.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `textfield_background_color` | 11 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 253 | `textfield_border_color` | 11 | 8.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 254 | `textfield_maxchars` | 3 | 11.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `textfield_properties` | 44 | 9.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `textfield_props_swf5` | 175 | 9.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `textfield_props_swf6` | 210 | 9.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 258 | `textfield_props_swf7` | 210 | 9.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `textfield_props_swf8` | 210 | 9.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `textfield_text` | 7 | 9.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `textfield_variable` | 81 | 9.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 262 | `this_swf5` | 41 | 9.2s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 263 | `this_swf6` | 41 | 9.2s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 264 | `this_swf7` | 41 | 9.2s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 265 | `timeline_function_def` | 7 | 9.4s |  |
| 266 | `transform` | 70 | 8.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 267 | `try_catch_finally` | 118 | 8.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 268 | `try_finally_simple` | 16 | 8.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 269 | `typeof` | 22 | 8.8s |  |
| 270 | `typeof_globals` | 7 | 8.8s |  |
| 271 | `uncaught_exception` | 1 | 8.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 272 | `uncaught_exception_bubbled` | 1 | 8.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 273 | `undefined_to_string_swf6` | 4 | 8.8s |  |
| 274 | `unescape` | 43 | 8.8s |  |
| 275 | `unload_clip_event` | 4 | 8.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 276 | `use_hand_cursor` | 8 | 8.8s |  |
| 277 | `variable_args` | 5 | 8.9s |  |
| 278 | `waitforframe` | 7 | 8.8s |  |
| 279 | `waitforframe2` | 16 | 9.3s |  |
| 280 | `watch` | 117 | 9.1s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 281 | `watch_virtual_property_proto` | 2 | 8.9s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 282 | `with` | 49 | 8.9s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 283 | `with_return` | 2 | 8.8s |  |
| 284 | `with_variable_scopes` | 43 | 8.9s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 285 | `xml` | 15 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 286 | `xml_append_child` | 28 | 8.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 287 | `xml_append_child_with_parent` | 20 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 288 | `xml_cdata` | 11 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 289 | `xml_child_nodes_edge_cases` | 4 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 290 | `xml_clone_expandos` | 19 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 291 | `xml_first_last_child` | 8 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 292 | `xml_has_child_nodes` | 3 | 8.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `xml_idmap` | 21 | 8.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 294 | `xml_ignore_comments` | 21 | 8.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 295 | `xml_ignore_white` | 34 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 296 | `xml_insert_before` | 20 | 9.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 297 | `xml_inspect_createmethods` | 15 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_inspect_doctype` | 7 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_inspect_parsexml` | 62 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 300 | `xml_inspect_xmldecl` | 7 | 9.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 301 | `xml_namespaces` | 203 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_parent_and_child` | 5 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_remove_node` | 22 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_reparenting` | 14 | 9.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 305 | `xml_siblings` | 10 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 306 | `xml_to_string` | 13 | 9.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 307 | `xml_to_string_comment` | 1 | 9.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 308 | `xml_unescaping` | 23 | 9.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 309 | `xmlnode_proto` | 1 | 9.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**52 tests** within reach

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
| 10 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
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
| 39 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 41 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 42 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 43 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 44 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `execution_order3` | 50.0% | 2 | 4 | 2 |  |
| 48 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 49 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 50 | `movieclip_in_removed_button` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 52 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 11.4s |  |
| 2 | `native_objects_swf6` | 11.5s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `native_objects_swf7` | 11.7s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 11.7s | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 33.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 33.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 19.3s | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**162 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
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
| 39 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 41 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 42 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 43 | `movieclip_lockroot` | 55.2% | 16/29 | 16 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 44 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `execution_order3` | 50.0% | 2/4 | 4 | 4 |  |
| 48 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 49 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 50 | `movieclip_in_removed_button` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 52 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 55 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 57 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 58 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 59 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 60 | `register_class_return_value` | 37.5% | 6/16 | 16 | 16 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 61 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 62 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `on_construct` | 36.0% | 9/25 | 12 | 25 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 64 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 68 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 69 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 70 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 72 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 73 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 74 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 75 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 76 | `string_paths_eval2` | 28.6% | 2/7 | 2 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 77 | `goto_frame2` | 27.3% | 12/44 | 17 | 44 | [11](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 78 | `tell_target` | 26.3% | 10/38 | 38 | 37 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 79 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 80 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 81 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 82 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 83 | `textsnapshot_props_swf5` | 25.0% | 14/56 | 38 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `this_scoping` | 20.8% | 11/53 | 53 | 52 | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 86 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 87 | `movieclip_init_object` | 20.0% | 1/5 | 2 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 88 | `tell_target_invalid` | 20.0% | 2/10 | 10 | 6 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 89 | `tell_target_invalid_swf6` | 20.0% | 2/10 | 10 | 5 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 90 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 91 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 92 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 93 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 94 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 95 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 96 | `register_class_swf6` | 16.2% | 6/37 | 8 | 37 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 97 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 6 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 98 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 6 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 99 | `register_and_init_order` | 14.7% | 34/231 | 85 | 231 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 100 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 101 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 102 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 103 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 104 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 106 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `path_string` | 10.9% | 38/350 | 350 | 322 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 108 | `register_class_with_sound` | 9.1% | 1/11 | 3 | 11 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 109 | `coerce_to_object_monkeypatch` | 7.8% | 10/129 | 80 | 129 |  |
| 110 | `register_class` | 7.6% | 5/66 | 44 | 66 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 111 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 112 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 114 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [44](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 116 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 117 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 118 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 119 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 120 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 121 | `movieclip_invalid_get_bounds_2` | 4.0% | 3/75 | 3 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 122 | `movieclip_invalid_get_bounds_1` | 2.7% | 2/75 | 3 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 123 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 125 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 126 | `global_proto_decls` | 0.4% | 16/4497 | 572 | 4497 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 127 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 128 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 129 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 130 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 131 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 132 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 133 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 134 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 135 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 136 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 137 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 138 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 139 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 140 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 141 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 142 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [13](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 143 | `goto_execution_order2` | 0.0% | 0/2 | 2 | 2 |  |
| 144 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 145 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 146 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 147 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 148 | `movieclip_methods_with_loaded_image` | 0.0% | 0/8 | 8 | 4 | [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 149 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [30](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 150 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 151 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 152 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 153 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 154 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 155 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 156 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 157 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 158 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 159 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 160 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 161 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 162 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 6 | 8 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/blocked/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
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
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
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
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 141 | 45 |
