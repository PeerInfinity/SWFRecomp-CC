# Ruffle Test Results (Filtered)

**Date**: 2026-02-28 02:14 UTC

**Git SHA**: `5e876a36fd`

**Run Duration**: 108m 39s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **336** (70.1%) |
| Failing | 143 |
| Total expected lines | 71493 |
| Matching lines | 48695 (68.1%) |
| Mismatched lines | 22798 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 131 | 91.6% |
| Segfault | 8 | 5.6% |
| Runtime Error | 2 | 1.4% |
| Compile Fail | 1 | 0.7% |
| Timeout | 1 | 0.7% |

## Passing Tests

**336 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.2s |  |
| 2 | `action_to_integer` | 28 | 10.2s |  |
| 3 | `add` | 28 | 10.4s |  |
| 4 | `add2` | 354 | 10.7s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 10.4s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 10.5s |  |
| 7 | `add_swf5` | 28 | 10.3s |  |
| 8 | `arguments` | 127 | 10.1s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 10.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 10.3s |  |
| 11 | `array_constructor` | 30 | 10.2s |  |
| 12 | `array_enumerate` | 4 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 10.2s |  |
| 14 | `array_properties` | 36 | 10.4s |  |
| 15 | `array_prototyping` | 12 | 10.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 10.4s |  |
| 17 | `array_sort_random` | 443 | 10.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 11.0s |  |
| 19 | `array_trivial` | 209 | 11.0s |  |
| 20 | `as1_constructor_v6` | 35 | 11.0s |  |
| 21 | `as1_constructor_v7` | 35 | 10.5s |  |
| 22 | `as2_oop` | 13 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 10.2s |  |
| 27 | `as_set_prop_flags` | 79 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 10.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 10.3s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 10.2s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 10.2s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 10.2s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 10.2s |  |
| 34 | `as_transformed_flag` | 20 | 10.3s |  |
| 35 | `attach_movie` | 59 | 10.3s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 10.3s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `bad_swf_tag_past_eof` | 0 | 10.0s |  |
| 38 | `bitand` | 1058 | 12.6s |  |
| 39 | `bitmap_data_colortransform` | 0 | 10.3s |  |
| 40 | `bitmap_data_fillrect` | 0 | 10.1s |  |
| 41 | `bitmap_data_max_size_swf10` | 12 | 10.1s |  |
| 42 | `bitmap_data_max_size_swf9` | 10 | 10.0s |  |
| 43 | `bitmap_data_perlinnoise` | 0 | 10.8s |  |
| 44 | `bitmap_data_pixeldissolve_image` | 0 | 10.6s |  |
| 45 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.0s |  |
| 46 | `bitor` | 1058 | 12.6s |  |
| 47 | `biturshift` | 14 | 10.0s |  |
| 48 | `biturshift_swf8` | 14 | 11.1s |  |
| 49 | `bitxor` | 1058 | 12.6s |  |
| 50 | `boxed_primitives` | 24 | 10.1s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `button_children` | 8 | 9.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `button_goto` | 4 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_order` | 2 | 9.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_properties_special_cases` | 22 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_v5` | 18 | 9.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v6` | 18 | 9.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `call_method_empty_name` | 1 | 9.9s |  |
| 58 | `capabilities_resolution` | 8 | 9.9s |  |
| 59 | `catch_references_registers` | 2 | 9.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 60 | `clip_constructors` | 8 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 61 | `clip_events` | 19 | 10.8s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 62 | `clone_sprite_types` | 24 | 10.4s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `closure_scope` | 7 | 10.5s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 64 | `color` | 57 | 10.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 65 | `color_transform` | 48 | 10.3s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 66 | `conflicting_instance_names` | 23 | 10.3s |  |
| 67 | `constructor_function` | 2 | 10.1s |  |
| 68 | `context_menu` | 39 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 69 | `context_menu_item` | 41 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `define_function2` | 8 | 10.2s |  |
| 71 | `define_function2_preload` | 13 | 10.3s |  |
| 72 | `define_function2_preload_order` | 4 | 11.6s |  |
| 73 | `define_function_case_sensitive` | 2 | 10.0s |  |
| 74 | `delete` | 3 | 10.1s |  |
| 75 | `display_object_properties` | 2 | 9.9s |  |
| 76 | `divide_swf4` | 107 | 10.1s |  |
| 77 | `do_init_action` | 3 | 10.1s |  |
| 78 | `duplicate_movie_clip` | 20 | 10.0s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 79 | `edittext_antialiastype` | 296 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_autosize_setter` | 20 | 11.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_default_format` | 221 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_default_format_empty` | 95 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_default_format_font_style` | 335 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_html_align_swf7` | 52 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_html_align_swf8` | 52 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_html_entity` | 4 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_newline_stripping` | 64 | 14.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_width_height` | 103 | 10.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `empty_movieclip_can_attach_movies` | 11 | 10.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 90 | `enumerate` | 64 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 91 | `equals` | 32 | 10.3s |  |
| 92 | `equals2_swf5` | 926 | 12.1s |  |
| 93 | `equals2_swf6` | 926 | 12.0s |  |
| 94 | `equals2_swf7` | 926 | 12.0s |  |
| 95 | `equals_swf4` | 665 | 11.0s |  |
| 96 | `equals_swf4_alt` | 32 | 10.2s |  |
| 97 | `equals_swf5` | 32 | 10.2s |  |
| 98 | `error` | 58 | 10.1s |  |
| 99 | `escape` | 14 | 10.0s |  |
| 100 | `execution_order1` | 5 | 10.1s |  |
| 101 | `execution_order2` | 7 | 10.1s |  |
| 102 | `execution_order3` | 4 | 10.1s |  |
| 103 | `execution_order4` | 12 | 10.3s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `export_assets` | 3 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 105 | `extends_chain` | 134 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 106 | `extends_native_type` | 11 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 107 | `focusrect_mouse_swf8` | 0 | 10.2s |  |
| 108 | `focusrect_mouse_swf9` | 0 | 10.3s |  |
| 109 | `focusrect_swf5` | 6 | 10.1s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 110 | `function_suppress_and_preload` | 28 | 10.0s |  |
| 111 | `get_variable_in_scope` | 29 | 9.9s |  |
| 112 | `getproperty` | 28 | 9.9s |  |
| 113 | `getproperty_swf4` | 28 | 10.3s |  |
| 114 | `getproperty_swf5` | 28 | 10.1s |  |
| 115 | `global_array` | 3 | 10.1s |  |
| 116 | `global_is_bare` | 7 | 10.0s |  |
| 117 | `globals_swf5` | 304 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 118 | `globals_swf6` | 304 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 119 | `globals_swf7` | 304 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 120 | `globals_swf8` | 304 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 121 | `goto_advance1` | 6 | 10.0s |  |
| 122 | `goto_advance2` | 2 | 10.0s |  |
| 123 | `goto_both_ways1` | 3 | 10.1s |  |
| 124 | `goto_both_ways2` | 3 | 10.1s |  |
| 125 | `goto_execution_order` | 2 | 10.0s |  |
| 126 | `goto_execution_order2` | 2 | 10.0s |  |
| 127 | `goto_frame` | 12 | 12.0s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 128 | `goto_frame2` | 44 | 11.1s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 129 | `goto_frame_number` | 3 | 10.7s |  |
| 130 | `goto_label` | 17 | 10.7s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 131 | `goto_methods` | 40 | 10.7s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 132 | `goto_rewind1` | 1 | 10.4s |  |
| 133 | `goto_rewind2` | 3 | 10.5s |  |
| 134 | `goto_rewind3` | 2 | 10.5s |  |
| 135 | `greater_swf6` | 1175 | 12.6s |  |
| 136 | `greater_swf7` | 1175 | 12.6s |  |
| 137 | `greaterthan_swf5` | 1 | 10.4s |  |
| 138 | `greaterthan_swf8` | 1 | 10.5s |  |
| 139 | `has_own_property` | 32 | 10.4s |  |
| 140 | `hittest_lockroot` | 15 | 10.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 141 | `hittest_morph` | 70 | 10.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 142 | `hittest_winding_rule` | 12 | 10.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 143 | `infinite_recursion_function` | 4 | 10.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 144 | `infinite_recursion_function_in_setter` | 131 | 10.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 145 | `infinite_recursion_virtual_property` | 67 | 10.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 146 | `init_array_invalid` | 4 | 10.5s |  |
| 147 | `init_object_invalid` | 4 | 10.2s |  |
| 148 | `init_object_order` | 15 | 10.1s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 149 | `is_finite` | 49 | 10.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 150 | `is_finite_swf6` | 49 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 151 | `is_prototype_of` | 89 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 152 | `issue_1086` | 1 | 10.1s |  |
| 153 | `issue_1671` | 0 | 9.9s |  |
| 154 | `issue_1906` | 4 | 10.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 155 | `issue_2166` | 9 | 10.0s |  |
| 156 | `issue_3446` | 1 | 10.0s |  |
| 157 | `issue_3522` | 2 | 10.2s |  |
| 158 | `issue_4377` | 2 | 10.1s |  |
| 159 | `issue_710` | 4 | 10.2s |  |
| 160 | `issue_768` | 3 | 10.3s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 161 | `issue_9327` | 2 | 10.2s |  |
| 162 | `issue_9885` | 2 | 10.3s |  |
| 163 | `lessthan` | 41 | 10.1s |  |
| 164 | `lessthan2_swf5` | 1226 | 12.3s |  |
| 165 | `lessthan2_swf6` | 1226 | 12.0s |  |
| 166 | `lessthan2_swf7` | 1226 | 12.0s |  |
| 167 | `lessthan_swf4` | 902 | 11.1s |  |
| 168 | `lessthan_swf4_alt` | 41 | 10.0s |  |
| 169 | `lessthan_swf5` | 41 | 10.0s |  |
| 170 | `local_to_global` | 49 | 10.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `localconnection_properties` | 8 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 172 | `lock_root` | 1 | 10.5s |  |
| 173 | `logical_ops_swf4` | 90 | 10.6s |  |
| 174 | `logical_ops_swf8` | 108 | 10.6s |  |
| 175 | `looping` | 6 | 10.6s |  |
| 176 | `mask_reapply` | 0 | 10.6s |  |
| 177 | `mask_with_drawing` | 0 | 10.7s |  |
| 178 | `math_min_max` | 101 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 179 | `math_swf6` | 530 | 11.1s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 180 | `math_swf7` | 530 | 11.0s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 181 | `math_swf8` | 530 | 11.1s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 182 | `matrix` | 171 | 11.1s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 183 | `movieclip_begin_gradient_fill` | 0 | 11.0s |  |
| 184 | `movieclip_blend_mode_property` | 35 | 10.5s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 185 | `movieclip_default_state` | 69 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_focusenabled` | 99 | 10.2s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 187 | `movieclip_get_instance_at_depth` | 28 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 188 | `movieclip_hittest` | 92 | 10.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 189 | `movieclip_in_removed_button` | 4 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 190 | `movieclip_line_gradient_style` | 0 | 10.6s |  |
| 191 | `movieclip_name_from_timeline` | 13 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 192 | `movieclip_prototype_extension` | 5 | 9.9s |  |
| 193 | `mutable_this` | 18 | 9.9s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 194 | `named_shapes` | 14 | 9.9s |  |
| 195 | `nan_scale` | 9 | 10.0s |  |
| 196 | `nested_textfields_in_buttons` | 0 | 9.9s |  |
| 197 | `new_method_wrap` | 4 | 10.1s |  |
| 198 | `new_object_enumerate` | 7 | 10.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 199 | `new_object_wrap` | 4 | 10.1s |  |
| 200 | `o` | 3 | 10.1s |  |
| 201 | `object_constructor` | 33 | 10.2s |  |
| 202 | `object_function` | 32 | 10.2s |  |
| 203 | `object_properties` | 31 | 10.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 204 | `object_prototypes` | 74 | 10.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 205 | `object_string_coerce_swf5` | 62 | 10.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 206 | `object_string_coerce_swf6` | 68 | 10.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 207 | `on_construct` | 25 | 10.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 208 | `parse_float` | 74 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 209 | `parse_int` | 64 | 10.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 210 | `path_string` | 322 | 10.2s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 211 | `place_and_lookup` | 30 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 212 | `placeobject_occupied_depth` | 6 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 213 | `point` | 175 | 10.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 214 | `primitive_instanceof` | 37 | 10.1s |  |
| 215 | `primitive_type_globals` | 557 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 216 | `printjob_props_swf5` | 45 | 9.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 217 | `printjob_props_swf6` | 45 | 9.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 218 | `printjob_props_swf7` | 45 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 219 | `property_invalid_base_clip` | 36 | 9.9s |  |
| 220 | `prototype_delete` | 12 | 9.8s |  |
| 221 | `prototype_enumerate` | 5 | 9.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 222 | `prototype_properties` | 17 | 9.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 223 | `rectangle` | 745 | 10.6s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 224 | `recursive_prototypes` | 0 | 9.8s |  |
| 225 | `register_class_return_value` | 16 | 9.9s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 226 | `register_globals_across_frames` | 15 | 10.0s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 227 | `register_underflow` | 26 | 10.0s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 228 | `rewind_depth` | 30 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 229 | `sandbox_type_local_file` | 1 | 9.9s |  |
| 230 | `sandbox_type_local_network` | 1 | 9.9s |  |
| 231 | `selection` | 454 | 10.1s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 232 | `set_interval` | 27 | 10.1s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 233 | `set_variable_scope` | 58 | 9.9s |  |
| 234 | `single_frame` | 1 | 10.0s |  |
| 235 | `slash_syntax` | 14 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 236 | `sound_props_swf5` | 68 | 10.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 237 | `sound_props_swf6` | 68 | 10.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 238 | `sound_start_load` | 0 | 10.3s |  |
| 239 | `stage_display_state` | 16 | 10.2s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 240 | `stage_object_children` | 83 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 241 | `stage_object_enumerate` | 4 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 242 | `stage_object_properties` | 241 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 243 | `stage_object_properties_get_var` | 5 | 10.2s |  |
| 244 | `stage_object_properties_swf6` | 231 | 10.6s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 245 | `stage_property_representation` | 586 | 10.2s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 246 | `stage_scale_mode` | 39 | 10.4s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 247 | `strictequals_swf6` | 902 | 12.0s |  |
| 248 | `strictly_equals` | 7 | 10.4s |  |
| 249 | `string_coercion` | 117 | 10.8s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 250 | `string_methods` | 285 | 10.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 251 | `string_methods_negative_args` | 240 | 10.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 252 | `string_methods_swfv5` | 275 | 10.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 253 | `string_ops_swf6` | 95 | 10.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 254 | `string_paths_basic` | 4 | 10.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 255 | `string_paths_hidden` | 54 | 9.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 256 | `string_paths_variable_alias` | 4 | 10.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 257 | `swf4_actions_bool` | 96 | 10.0s |  |
| 258 | `swf4_actions_coercion_order` | 158 | 10.1s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 259 | `swf4_bool` | 4 | 9.9s |  |
| 260 | `swf4_function_calls` | 7 | 9.9s |  |
| 261 | `swf5_encoding` | 3 | 9.9s |  |
| 262 | `swf5_no_closure` | 19 | 10.4s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 263 | `swf6_case_insensitive` | 42 | 10.3s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 264 | `swf6_string_as_bool` | 15 | 10.2s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 265 | `swf7_case_sensitive` | 44 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 266 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.0s |  |
| 267 | `target_clip_removed` | 5 | 10.2s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 268 | `target_clip_swf5` | 2 | 10.1s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 269 | `target_clip_swf6` | 2 | 10.0s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 270 | `target_path` | 14 | 9.9s |  |
| 271 | `tell_target` | 37 | 10.0s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 272 | `tell_target_invalid` | 6 | 10.2s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 273 | `tell_target_invalid_swf6` | 5 | 10.2s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 274 | `text_format` | 1146 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 275 | `text_format_display` | 21 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 276 | `text_format_font_max_length` | 2 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 277 | `text_format_rounding_swf7` | 840 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 278 | `text_format_rounding_swf8` | 840 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 279 | `textfield_background_color` | 11 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 280 | `textfield_border_color` | 11 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 281 | `textfield_maxchars` | 3 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 282 | `textfield_properties` | 44 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 283 | `textfield_props_swf5` | 175 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 284 | `textfield_props_swf6` | 210 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 285 | `textfield_props_swf7` | 210 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 286 | `textfield_props_swf8` | 210 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 287 | `textfield_text` | 7 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 288 | `textfield_variable` | 81 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 289 | `textsnapshot_props_swf6` | 56 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 290 | `this_scoping` | 52 | 10.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 291 | `this_swf5` | 41 | 10.2s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 292 | `this_swf6` | 41 | 10.2s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 293 | `this_swf7` | 41 | 10.1s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 294 | `timeline_function_def` | 7 | 10.3s |  |
| 295 | `try_catch_finally` | 118 | 10.2s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 296 | `try_finally_simple` | 16 | 10.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 297 | `typeof` | 22 | 10.3s |  |
| 298 | `typeof_globals` | 7 | 10.0s |  |
| 299 | `uncaught_exception` | 1 | 10.1s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 300 | `uncaught_exception_bubbled` | 1 | 10.6s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 301 | `undefined_to_string_swf6` | 4 | 11.3s |  |
| 302 | `unescape` | 43 | 11.4s |  |
| 303 | `unload_clip_event` | 4 | 11.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 304 | `use_hand_cursor` | 8 | 10.1s |  |
| 305 | `variable_args` | 5 | 10.1s |  |
| 306 | `waitforframe` | 7 | 10.2s |  |
| 307 | `waitforframe2` | 16 | 11.1s |  |
| 308 | `watch` | 117 | 10.2s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 309 | `watch_virtual_property_proto` | 2 | 9.9s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 310 | `with_return` | 2 | 9.8s |  |
| 311 | `with_variable_scopes` | 43 | 9.9s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 312 | `xml` | 15 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 313 | `xml_append_child` | 28 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 314 | `xml_append_child_with_parent` | 20 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 315 | `xml_cdata` | 11 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 316 | `xml_child_nodes_edge_cases` | 4 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 317 | `xml_clone_expandos` | 19 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 318 | `xml_first_last_child` | 8 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 319 | `xml_has_child_nodes` | 3 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 320 | `xml_idmap` | 21 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 321 | `xml_ignore_comments` | 21 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 322 | `xml_ignore_white` | 34 | 11.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 323 | `xml_insert_before` | 20 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 324 | `xml_inspect_createmethods` | 15 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 325 | `xml_inspect_doctype` | 7 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 326 | `xml_inspect_parsexml` | 62 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 327 | `xml_inspect_xmldecl` | 7 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 328 | `xml_namespaces` | 203 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 329 | `xml_parent_and_child` | 5 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 330 | `xml_remove_node` | 22 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 331 | `xml_reparenting` | 14 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 332 | `xml_siblings` | 10 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 333 | `xml_to_string` | 13 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 334 | `xml_to_string_comment` | 1 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 335 | `xml_unescaping` | 23 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 336 | `xmlnode_proto` | 1 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**46 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `with` | 98.0% | 48 | 49 | 1 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `transform` | 94.3% | 66 | 70 | 4 | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 6 | `movieclip_depth_methods` | 87.8% | 86 | 98 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 8 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `movieclip_hittest_shapeflag` | 82.2% | 278 | 338 | 60 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 12 | `remove_movie_clip` | 75.9% | 22 | 29 | 7 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 13 | `create_empty_movie_clip` | 75.0% | 3 | 4 | 1 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 16 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 17 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 18 | `textsnapshot_props_swf5` | 67.9% | 38 | 56 | 18 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `unload` | 61.5% | 32 | 52 | 20 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_programmatic_focus` | 58.3% | 7 | 12 | 5 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 33 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 36 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 37 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `register_and_init_order` | 55.0% | 127 | 231 | 104 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 39 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 41 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 42 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 44 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 45 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 46 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**8 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 11.9s |  |
| 2 | `movieclip_library_state_values` | 12.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `netstream_play_flv_screen` | 24.5s |  |
| 7 | `string_paths_timer` | 12.1s |  |
| 8 | `timer_run_actions` | 13.2s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 32.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 33.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 20.1s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**131 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `with` | 98.0% | 48/49 | 49 | 49 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `transform` | 94.3% | 66/70 | 70 | 70 | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 6 | `movieclip_depth_methods` | 87.8% | 86/98 | 98 | 98 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 8 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `movieclip_hittest_shapeflag` | 82.2% | 278/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 12 | `remove_movie_clip` | 75.9% | 22/29 | 29 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 13 | `create_empty_movie_clip` | 75.0% | 3/4 | 4 | 3 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 16 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 17 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 18 | `textsnapshot_props_swf5` | 67.9% | 38/56 | 56 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 21 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `unload` | 61.5% | 32/52 | 52 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 24 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_programmatic_focus` | 58.3% | 7/12 | 12 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 33 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 36 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 37 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 38 | `register_and_init_order` | 55.0% | 127/231 | 194 | 231 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 39 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 41 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 42 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 44 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 45 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 46 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 49 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 51 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 53 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 54 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 55 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 56 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 57 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 58 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 59 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 63 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 64 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 66 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 67 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 68 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 69 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 71 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 72 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 74 | `movieclip_init_object` | 20.0% | 1/5 | 4 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 75 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 76 | `register_class_swf6` | 18.9% | 7/37 | 10 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 77 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 78 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 79 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 80 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 81 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 82 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 83 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 84 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 85 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 86 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 87 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 88 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `register_class` | 10.6% | 7/66 | 52 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 90 | `register_class_with_sound` | 9.1% | 1/11 | 11 | 11 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 91 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 92 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 94 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 95 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 96 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 97 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 98 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 99 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 100 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 101 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 102 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 103 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 104 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 105 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 106 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 107 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 108 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 109 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 110 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 111 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 113 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 114 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 115 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 116 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 117 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 118 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 119 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 120 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 122 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 123 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 124 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 125 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 126 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 127 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 128 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 129 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 130 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 131 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 4 | 1 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 1 | 6 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 19 | 12 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 0 | 49 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 23 | 35 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 9 | 6 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 7 | 2 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 7 | 6 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 11 | 8 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 26 | 44 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 4 | 8 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 145 | 41 |
