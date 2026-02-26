# Ruffle Test Results (Filtered)

**Date**: 2026-02-26 23:28 UTC

**Git SHA**: `56afab65dd`

**Run Duration**: 105m 25s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **326** (68.1%) |
| Failing | 153 |
| Total expected lines | 71493 |
| Matching lines | 48436 (67.7%) |
| Mismatched lines | 23057 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 137 | 89.5% |
| Segfault | 12 | 7.8% |
| Runtime Error | 2 | 1.3% |
| Compile Fail | 1 | 0.7% |
| Timeout | 1 | 0.7% |

## Passing Tests

**326 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.2s |  |
| 2 | `action_to_integer` | 28 | 9.9s |  |
| 3 | `add` | 28 | 10.0s |  |
| 4 | `add2` | 354 | 10.1s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 9.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 9.9s |  |
| 7 | `add_swf5` | 28 | 9.9s |  |
| 8 | `arguments` | 127 | 10.0s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 9.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 9.9s |  |
| 11 | `array_constructor` | 30 | 9.8s |  |
| 12 | `array_enumerate` | 4 | 9.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 9.8s |  |
| 14 | `array_properties` | 36 | 9.8s |  |
| 15 | `array_prototyping` | 12 | 9.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 9.8s |  |
| 17 | `array_sort_random` | 443 | 9.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 10.0s |  |
| 19 | `array_trivial` | 209 | 10.0s |  |
| 20 | `as1_constructor_v6` | 35 | 9.9s |  |
| 21 | `as1_constructor_v7` | 35 | 10.2s |  |
| 22 | `as2_oop` | 13 | 9.9s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 10.0s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 9.8s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 9.8s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 9.7s |  |
| 27 | `as_set_prop_flags` | 79 | 10.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 9.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 9.7s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 9.6s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 9.6s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 9.6s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 9.6s |  |
| 34 | `as_transformed_flag` | 20 | 9.7s |  |
| 35 | `attach_movie` | 59 | 10.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 10.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `bad_swf_tag_past_eof` | 0 | 9.8s |  |
| 38 | `bitand` | 1058 | 12.7s |  |
| 39 | `bitmap_data_colortransform` | 0 | 10.2s |  |
| 40 | `bitmap_data_fillrect` | 0 | 10.0s |  |
| 41 | `bitmap_data_max_size_swf10` | 12 | 9.9s |  |
| 42 | `bitmap_data_max_size_swf9` | 10 | 9.9s |  |
| 43 | `bitmap_data_perlinnoise` | 0 | 10.7s |  |
| 44 | `bitmap_data_pixeldissolve_image` | 0 | 10.3s |  |
| 45 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.9s |  |
| 46 | `bitor` | 1058 | 12.7s |  |
| 47 | `biturshift` | 14 | 9.9s |  |
| 48 | `biturshift_swf8` | 14 | 9.6s |  |
| 49 | `bitxor` | 1058 | 11.7s |  |
| 50 | `boxed_primitives` | 24 | 9.5s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `button_children` | 8 | 9.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `button_goto` | 4 | 9.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_order` | 2 | 9.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_properties_special_cases` | 22 | 9.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_v5` | 18 | 9.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v6` | 18 | 9.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `call_method_empty_name` | 1 | 9.4s |  |
| 58 | `capabilities_resolution` | 8 | 9.4s |  |
| 59 | `catch_references_registers` | 2 | 9.4s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 60 | `clip_events` | 19 | 9.8s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 61 | `clone_sprite_types` | 24 | 9.6s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 62 | `closure_scope` | 7 | 9.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 63 | `color` | 57 | 9.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 64 | `color_transform` | 48 | 9.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 65 | `conflicting_instance_names` | 23 | 9.6s |  |
| 66 | `constructor_function` | 2 | 9.5s |  |
| 67 | `context_menu` | 39 | 9.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 68 | `context_menu_item` | 41 | 9.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 69 | `define_function2` | 8 | 9.5s |  |
| 70 | `define_function2_preload` | 13 | 9.5s |  |
| 71 | `define_function2_preload_order` | 4 | 9.9s |  |
| 72 | `define_function_case_sensitive` | 2 | 9.7s |  |
| 73 | `delete` | 3 | 9.7s |  |
| 74 | `display_object_properties` | 2 | 9.7s |  |
| 75 | `divide_swf4` | 107 | 9.7s |  |
| 76 | `do_init_action` | 3 | 9.7s |  |
| 77 | `duplicate_movie_clip` | 20 | 9.7s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 78 | `edittext_antialiastype` | 296 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_autosize_setter` | 20 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_default_format` | 221 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_default_format_empty` | 95 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_default_format_font_style` | 335 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_html_align_swf7` | 52 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_html_align_swf8` | 52 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_html_entity` | 4 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_newline_stripping` | 64 | 15.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_width_height` | 103 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `empty_movieclip_can_attach_movies` | 11 | 10.6s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 89 | `enumerate` | 64 | 9.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 90 | `equals` | 32 | 10.0s |  |
| 91 | `equals2_swf5` | 926 | 11.7s |  |
| 92 | `equals2_swf6` | 926 | 11.6s |  |
| 93 | `equals2_swf7` | 926 | 12.0s |  |
| 94 | `equals_swf4` | 665 | 11.0s |  |
| 95 | `equals_swf4_alt` | 32 | 10.2s |  |
| 96 | `equals_swf5` | 32 | 10.2s |  |
| 97 | `error` | 58 | 10.2s |  |
| 98 | `escape` | 14 | 10.0s |  |
| 99 | `execution_order1` | 5 | 9.9s |  |
| 100 | `execution_order2` | 7 | 9.9s |  |
| 101 | `execution_order3` | 4 | 10.0s |  |
| 102 | `export_assets` | 3 | 9.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 103 | `extends_chain` | 134 | 10.1s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 104 | `extends_native_type` | 11 | 9.7s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 105 | `focusrect_mouse_swf8` | 0 | 9.8s |  |
| 106 | `focusrect_mouse_swf9` | 0 | 10.7s |  |
| 107 | `focusrect_swf5` | 6 | 10.4s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 108 | `function_suppress_and_preload` | 28 | 10.3s |  |
| 109 | `get_variable_in_scope` | 29 | 10.4s |  |
| 110 | `getproperty` | 28 | 10.4s |  |
| 111 | `getproperty_swf4` | 28 | 10.1s |  |
| 112 | `getproperty_swf5` | 28 | 9.9s |  |
| 113 | `global_array` | 3 | 10.0s |  |
| 114 | `global_is_bare` | 7 | 10.0s |  |
| 115 | `globals_swf5` | 304 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 116 | `globals_swf6` | 304 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 117 | `globals_swf7` | 304 | 10.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 118 | `globals_swf8` | 304 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 119 | `goto_advance1` | 6 | 9.9s |  |
| 120 | `goto_advance2` | 2 | 10.0s |  |
| 121 | `goto_both_ways1` | 3 | 10.0s |  |
| 122 | `goto_both_ways2` | 3 | 10.1s |  |
| 123 | `goto_execution_order` | 2 | 10.0s |  |
| 124 | `goto_execution_order2` | 2 | 10.1s |  |
| 125 | `goto_frame` | 12 | 10.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 126 | `goto_frame2` | 44 | 10.5s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 127 | `goto_frame_number` | 3 | 9.9s |  |
| 128 | `goto_label` | 17 | 10.0s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 129 | `goto_methods` | 40 | 10.1s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 130 | `goto_rewind1` | 1 | 9.9s |  |
| 131 | `goto_rewind2` | 3 | 9.9s |  |
| 132 | `goto_rewind3` | 2 | 10.1s |  |
| 133 | `greater_swf6` | 1175 | 12.0s |  |
| 134 | `greater_swf7` | 1175 | 11.8s |  |
| 135 | `greaterthan_swf5` | 1 | 9.9s |  |
| 136 | `greaterthan_swf8` | 1 | 9.9s |  |
| 137 | `has_own_property` | 32 | 10.0s |  |
| 138 | `hittest_lockroot` | 15 | 10.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 139 | `hittest_morph` | 70 | 10.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 140 | `hittest_winding_rule` | 12 | 9.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 141 | `infinite_recursion_function` | 4 | 9.8s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 142 | `infinite_recursion_function_in_setter` | 131 | 9.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 143 | `infinite_recursion_virtual_property` | 67 | 9.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 144 | `init_array_invalid` | 4 | 10.0s |  |
| 145 | `init_object_invalid` | 4 | 10.3s |  |
| 146 | `init_object_order` | 15 | 10.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 147 | `is_finite` | 49 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 148 | `is_finite_swf6` | 49 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 149 | `is_prototype_of` | 89 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 150 | `issue_1086` | 1 | 10.1s |  |
| 151 | `issue_1671` | 0 | 10.2s |  |
| 152 | `issue_1906` | 4 | 10.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 153 | `issue_2166` | 9 | 9.9s |  |
| 154 | `issue_3446` | 1 | 9.8s |  |
| 155 | `issue_3522` | 2 | 9.6s |  |
| 156 | `issue_4377` | 2 | 9.6s |  |
| 157 | `issue_710` | 4 | 9.6s |  |
| 158 | `issue_9327` | 2 | 9.7s |  |
| 159 | `issue_9885` | 2 | 9.7s |  |
| 160 | `lessthan` | 41 | 9.7s |  |
| 161 | `lessthan2_swf5` | 1226 | 11.8s |  |
| 162 | `lessthan2_swf6` | 1226 | 11.8s |  |
| 163 | `lessthan2_swf7` | 1226 | 11.7s |  |
| 164 | `lessthan_swf4` | 902 | 10.8s |  |
| 165 | `lessthan_swf4_alt` | 41 | 9.7s |  |
| 166 | `lessthan_swf5` | 41 | 9.7s |  |
| 167 | `local_to_global` | 49 | 9.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `localconnection_properties` | 8 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 169 | `lock_root` | 1 | 9.6s |  |
| 170 | `logical_ops_swf4` | 90 | 9.7s |  |
| 171 | `logical_ops_swf8` | 108 | 9.7s |  |
| 172 | `looping` | 6 | 9.6s |  |
| 173 | `mask_reapply` | 0 | 9.7s |  |
| 174 | `mask_with_drawing` | 0 | 9.7s |  |
| 175 | `math_min_max` | 101 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 176 | `math_swf6` | 530 | 10.0s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 177 | `math_swf7` | 530 | 10.0s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 178 | `math_swf8` | 530 | 10.0s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 179 | `matrix` | 171 | 10.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 180 | `movieclip_begin_gradient_fill` | 0 | 10.2s |  |
| 181 | `movieclip_blend_mode_property` | 35 | 10.3s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 182 | `movieclip_default_state` | 69 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `movieclip_depth_methods` | 98 | 10.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 184 | `movieclip_focusenabled` | 99 | 10.1s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 185 | `movieclip_get_instance_at_depth` | 28 | 9.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_hittest` | 92 | 10.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 187 | `movieclip_in_removed_button` | 4 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 188 | `movieclip_line_gradient_style` | 0 | 10.6s |  |
| 189 | `movieclip_name_from_timeline` | 13 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 190 | `movieclip_prototype_extension` | 5 | 10.0s |  |
| 191 | `mutable_this` | 18 | 10.0s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 192 | `nested_textfields_in_buttons` | 0 | 9.7s |  |
| 193 | `new_method_wrap` | 4 | 10.0s |  |
| 194 | `new_object_enumerate` | 7 | 9.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 195 | `new_object_wrap` | 4 | 9.8s |  |
| 196 | `o` | 3 | 9.7s |  |
| 197 | `object_constructor` | 33 | 9.8s |  |
| 198 | `object_function` | 32 | 9.9s |  |
| 199 | `object_properties` | 31 | 10.1s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `object_prototypes` | 74 | 9.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 201 | `object_string_coerce_swf5` | 62 | 9.9s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 202 | `object_string_coerce_swf6` | 68 | 9.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 203 | `parse_float` | 74 | 10.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 204 | `parse_int` | 64 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 205 | `placeobject_occupied_depth` | 6 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 206 | `point` | 175 | 10.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 207 | `primitive_instanceof` | 37 | 9.8s |  |
| 208 | `primitive_type_globals` | 557 | 11.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 209 | `printjob_props_swf5` | 45 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 210 | `printjob_props_swf6` | 45 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 211 | `printjob_props_swf7` | 45 | 9.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 212 | `property_invalid_base_clip` | 36 | 9.9s |  |
| 213 | `prototype_delete` | 12 | 9.8s |  |
| 214 | `prototype_enumerate` | 5 | 9.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 215 | `prototype_properties` | 17 | 9.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 216 | `rectangle` | 745 | 10.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 217 | `recursive_prototypes` | 0 | 9.8s |  |
| 218 | `register_class_return_value` | 16 | 9.8s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 219 | `register_globals_across_frames` | 15 | 9.8s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 220 | `register_underflow` | 26 | 9.7s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 221 | `remove_movie_clip` | 29 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 222 | `sandbox_type_local_file` | 1 | 9.6s |  |
| 223 | `sandbox_type_local_network` | 1 | 9.6s |  |
| 224 | `set_interval` | 27 | 9.7s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 225 | `set_variable_scope` | 58 | 9.6s |  |
| 226 | `single_frame` | 1 | 9.7s |  |
| 227 | `slash_syntax` | 14 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 228 | `sound_props_swf5` | 68 | 10.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 229 | `sound_props_swf6` | 68 | 10.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 230 | `sound_start_load` | 0 | 10.0s |  |
| 231 | `stage_display_state` | 16 | 9.9s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 232 | `stage_object_children` | 83 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 233 | `stage_object_enumerate` | 4 | 9.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 234 | `stage_object_properties` | 241 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 235 | `stage_object_properties_get_var` | 5 | 9.8s |  |
| 236 | `stage_object_properties_swf6` | 231 | 10.2s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 237 | `stage_property_representation` | 586 | 9.9s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 238 | `stage_scale_mode` | 39 | 9.9s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 239 | `strictequals_swf6` | 902 | 11.4s |  |
| 240 | `strictly_equals` | 7 | 10.0s |  |
| 241 | `string_coercion` | 117 | 10.1s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 242 | `string_methods` | 285 | 10.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 243 | `string_methods_negative_args` | 240 | 10.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 244 | `string_methods_swfv5` | 275 | 10.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 245 | `string_ops_swf6` | 95 | 10.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 246 | `string_paths_basic` | 4 | 9.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 247 | `string_paths_variable_alias` | 4 | 9.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 248 | `swf4_actions_bool` | 96 | 10.2s |  |
| 249 | `swf4_actions_coercion_order` | 158 | 10.2s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 250 | `swf4_bool` | 4 | 9.9s |  |
| 251 | `swf4_function_calls` | 7 | 9.9s |  |
| 252 | `swf5_encoding` | 3 | 9.9s |  |
| 253 | `swf5_no_closure` | 19 | 10.1s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 254 | `swf6_case_insensitive` | 42 | 9.7s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 255 | `swf6_string_as_bool` | 15 | 9.6s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 256 | `swf7_case_sensitive` | 44 | 9.5s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 257 | `tab_ordering_properties_tab_index_edge_case` | 4 | 9.8s |  |
| 258 | `target_clip_removed` | 5 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 259 | `target_clip_swf5` | 2 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 260 | `target_clip_swf6` | 2 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 261 | `target_path` | 14 | 9.8s |  |
| 262 | `tell_target` | 37 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 263 | `text_format` | 1146 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 264 | `text_format_display` | 21 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 265 | `text_format_font_max_length` | 2 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 266 | `text_format_rounding_swf7` | 840 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 267 | `text_format_rounding_swf8` | 840 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 268 | `textfield_background_color` | 11 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 269 | `textfield_border_color` | 11 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 270 | `textfield_maxchars` | 3 | 11.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 271 | `textfield_properties` | 44 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 272 | `textfield_props_swf5` | 175 | 10.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 273 | `textfield_props_swf6` | 210 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 274 | `textfield_props_swf7` | 210 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 275 | `textfield_props_swf8` | 210 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 276 | `textfield_text` | 7 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 277 | `textfield_variable` | 81 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 278 | `textsnapshot_props_swf6` | 56 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 279 | `this_swf5` | 41 | 9.7s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 280 | `this_swf6` | 41 | 9.7s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 281 | `this_swf7` | 41 | 9.7s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 282 | `timeline_function_def` | 7 | 9.8s |  |
| 283 | `transform` | 70 | 10.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 284 | `try_catch_finally` | 118 | 10.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 285 | `try_finally_simple` | 16 | 9.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 286 | `typeof` | 22 | 9.9s |  |
| 287 | `typeof_globals` | 7 | 9.8s |  |
| 288 | `uncaught_exception` | 1 | 9.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 289 | `uncaught_exception_bubbled` | 1 | 9.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 290 | `undefined_to_string_swf6` | 4 | 9.9s |  |
| 291 | `unescape` | 43 | 9.8s |  |
| 292 | `unload_clip_event` | 4 | 9.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 293 | `use_hand_cursor` | 8 | 9.8s |  |
| 294 | `variable_args` | 5 | 9.9s |  |
| 295 | `waitforframe` | 7 | 9.8s |  |
| 296 | `waitforframe2` | 16 | 10.1s |  |
| 297 | `watch` | 117 | 9.9s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 298 | `watch_virtual_property_proto` | 2 | 9.9s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 299 | `with` | 49 | 10.0s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 300 | `with_return` | 2 | 9.7s |  |
| 301 | `with_variable_scopes` | 43 | 9.8s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 302 | `xml` | 15 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_append_child` | 28 | 10.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_append_child_with_parent` | 20 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 305 | `xml_cdata` | 11 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 306 | `xml_child_nodes_edge_cases` | 4 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 307 | `xml_clone_expandos` | 19 | 10.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 308 | `xml_first_last_child` | 8 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 309 | `xml_has_child_nodes` | 3 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 310 | `xml_idmap` | 21 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 311 | `xml_ignore_comments` | 21 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 312 | `xml_ignore_white` | 34 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 313 | `xml_insert_before` | 20 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 314 | `xml_inspect_createmethods` | 15 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 315 | `xml_inspect_doctype` | 7 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 316 | `xml_inspect_parsexml` | 62 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 317 | `xml_inspect_xmldecl` | 7 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 318 | `xml_namespaces` | 203 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 319 | `xml_parent_and_child` | 5 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 320 | `xml_remove_node` | 22 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 321 | `xml_reparenting` | 14 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 322 | `xml_siblings` | 10 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 323 | `xml_to_string` | 13 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 324 | `xml_to_string_comment` | 1 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 325 | `xml_unescaping` | 23 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 326 | `xmlnode_proto` | 1 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**50 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `selection` | 95.6% | 434 | 454 | 20 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `path_string` | 86.0% | 277 | 322 | 45 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 6 | `named_shapes` | 85.7% | 12 | 14 | 2 |  |
| 7 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 8 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 10 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 11 | `tell_target_invalid_swf6` | 80.0% | 4 | 5 | 1 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `clip_constructors` | 75.0% | 6 | 8 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 14 | `create_empty_movie_clip` | 75.0% | 3 | 4 | 1 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 17 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 19 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 20 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 21 | `textsnapshot_props_swf5` | 67.9% | 38 | 56 | 18 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `issue_768` | 66.7% | 2 | 3 | 1 | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 24 | `tell_target_invalid` | 66.7% | 4 | 6 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 26 | `string_paths_hidden` | 64.8% | 35 | 54 | 19 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 27 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `execution_order4` | 58.3% | 7 | 12 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 41 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 42 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 43 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 44 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 48 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 49 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 50 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**12 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 11.8s |  |
| 2 | `movieclip_init_object` | 12.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 3 | `movieclip_library_state_values` | 12.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf7` | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `native_objects_swf8` | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `netstream_play_flv_screen` | 24.9s |  |
| 8 | `on_construct` | 11.9s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 9 | `register_and_init_order` | 12.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 10 | `register_class_with_sound` | 11.8s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 11 | `string_paths_timer` | 11.8s |  |
| 12 | `timer_run_actions` | 12.2s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 32.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 33.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 19.7s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**137 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `selection` | 95.6% | 434/454 | 454 | 454 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `path_string` | 86.0% | 277/322 | 320 | 322 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 6 | `named_shapes` | 85.7% | 12/14 | 14 | 14 |  |
| 7 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 8 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 10 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 11 | `tell_target_invalid_swf6` | 80.0% | 4/5 | 4 | 5 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `clip_constructors` | 75.0% | 6/8 | 8 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 14 | `create_empty_movie_clip` | 75.0% | 3/4 | 4 | 3 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 17 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 19 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 20 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 21 | `textsnapshot_props_swf5` | 67.9% | 38/56 | 56 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `issue_768` | 66.7% | 2/3 | 3 | 3 | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 24 | `tell_target_invalid` | 66.7% | 4/6 | 4 | 6 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 26 | `string_paths_hidden` | 64.8% | 35/54 | 54 | 54 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 27 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 37 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 41 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 42 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 43 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 44 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 48 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 49 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 50 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 53 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 55 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 57 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 58 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 59 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 60 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 61 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 62 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 66 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 69 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 72 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 74 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 75 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 76 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 77 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `this_scoping` | 20.8% | 11/53 | 53 | 52 | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 79 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 80 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 81 | `register_class_swf6` | 18.9% | 7/37 | 10 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 82 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 83 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 84 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 85 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 86 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 87 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 88 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 89 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 90 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 91 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 92 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 93 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 94 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `register_class` | 10.6% | 7/66 | 52 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 96 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 97 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 99 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 100 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 101 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 102 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 103 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 104 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 105 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 106 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 107 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 108 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 109 | `global_proto_decls` | 0.4% | 20/4497 | 665 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 110 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 111 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 112 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 113 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 114 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 116 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 119 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 120 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 121 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 122 | `global_proto_decls_delete` | 0.0% | 0/4158 | 303 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 123 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 124 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 125 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 126 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 129 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 130 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 131 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 132 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 133 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 134 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 135 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 136 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 137 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 1 | 6 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 19 | 12 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 0 | 1 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 0 | 49 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 20 | 38 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 7 | 8 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 7 | 2 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 7 | 12 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 26 | 44 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 143 | 43 |
