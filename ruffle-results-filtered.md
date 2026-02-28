# Ruffle Test Results (Filtered)

**Date**: 2026-02-28 23:01 UTC

**Git SHA**: `28fd597f16`

**Run Duration**: 112m 56s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **346** (72.5%) |
| Failing | 131 |
| Total expected lines | 71224 |
| Matching lines | 49009 (68.8%) |
| Mismatched lines | 22215 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 121 | 92.4% |
| Segfault | 4 | 3.1% |
| Runtime Error | 4 | 3.1% |
| Compile Fail | 1 | 0.8% |
| Timeout | 1 | 0.8% |

## Passing Tests

**346 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 12.6s |  |
| 2 | `action_to_integer` | 28 | 10.8s |  |
| 3 | `add` | 28 | 10.8s |  |
| 4 | `add2` | 354 | 10.9s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 10.7s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 10.8s |  |
| 7 | `add_swf5` | 28 | 10.7s |  |
| 8 | `arguments` | 127 | 10.6s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 10.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 10.8s |  |
| 11 | `array_constructor` | 30 | 10.8s |  |
| 12 | `array_enumerate` | 4 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 10.8s |  |
| 14 | `array_properties` | 36 | 10.8s |  |
| 15 | `array_prototyping` | 12 | 10.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 10.8s |  |
| 17 | `array_sort_random` | 443 | 10.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 10.8s |  |
| 19 | `array_trivial` | 209 | 10.8s |  |
| 20 | `as1_constructor_v6` | 35 | 10.7s |  |
| 21 | `as1_constructor_v7` | 35 | 11.9s |  |
| 22 | `as2_oop` | 13 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 10.7s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 10.7s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 10.6s |  |
| 27 | `as_set_prop_flags` | 79 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 10.5s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 10.5s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 10.5s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 10.6s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 10.4s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 10.5s |  |
| 34 | `as_transformed_flag` | 20 | 10.4s |  |
| 35 | `attach_movie` | 59 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 37 | `bad_swf_tag_past_eof` | 0 | 10.5s |  |
| 38 | `bitand` | 1058 | 13.0s |  |
| 39 | `bitmap_data_colortransform` | 0 | 10.7s |  |
| 40 | `bitmap_data_fillrect` | 0 | 10.5s |  |
| 41 | `bitmap_data_max_size_swf10` | 12 | 10.3s |  |
| 42 | `bitmap_data_max_size_swf9` | 10 | 10.3s |  |
| 43 | `bitmap_data_perlinnoise` | 0 | 11.2s |  |
| 44 | `bitmap_data_pixeldissolve_image` | 0 | 10.8s |  |
| 45 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.4s |  |
| 46 | `bitor` | 1058 | 13.0s |  |
| 47 | `biturshift` | 14 | 10.4s |  |
| 48 | `biturshift_swf8` | 14 | 12.0s |  |
| 49 | `bitxor` | 1058 | 13.0s |  |
| 50 | `boxed_primitives` | 24 | 10.7s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `button_children` | 8 | 10.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `button_goto` | 4 | 10.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_order` | 2 | 10.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_properties_special_cases` | 22 | 10.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_v5` | 18 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v6` | 18 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `call_method_empty_name` | 1 | 10.4s |  |
| 58 | `capabilities_resolution` | 8 | 10.2s |  |
| 59 | `catch_references_registers` | 2 | 10.2s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 60 | `clip_constructors` | 8 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 61 | `clip_events` | 19 | 11.0s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 62 | `clone_sprite_types` | 24 | 10.5s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `closure_scope` | 7 | 10.5s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 64 | `color` | 57 | 10.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 65 | `color_transform` | 48 | 10.5s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 66 | `conflicting_instance_names` | 23 | 10.4s |  |
| 67 | `constructor_function` | 2 | 10.3s |  |
| 68 | `context_menu` | 39 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 69 | `context_menu_item` | 41 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `create_empty_movie_clip` | 3 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `define_function2` | 8 | 10.3s |  |
| 72 | `define_function2_preload` | 13 | 10.5s |  |
| 73 | `define_function2_preload_order` | 4 | 11.0s |  |
| 74 | `define_function_case_sensitive` | 2 | 10.7s |  |
| 75 | `delete` | 3 | 10.7s |  |
| 76 | `display_object_properties` | 2 | 10.6s |  |
| 77 | `divide_swf4` | 107 | 10.7s |  |
| 78 | `do_init_action` | 3 | 10.6s |  |
| 79 | `duplicate_movie_clip` | 20 | 10.7s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `edittext_antialiastype` | 296 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_autosize_setter` | 20 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_default_format` | 221 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_default_format_empty` | 95 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_default_format_font_style` | 335 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_html_align_swf7` | 52 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_html_align_swf8` | 52 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_html_entity` | 4 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_newline_stripping` | 64 | 15.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_width_height` | 103 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `empty_movieclip_can_attach_movies` | 11 | 11.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 91 | `enumerate` | 64 | 11.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 92 | `equals` | 32 | 11.2s |  |
| 93 | `equals2_swf5` | 926 | 13.1s |  |
| 94 | `equals2_swf6` | 926 | 13.1s |  |
| 95 | `equals2_swf7` | 926 | 13.0s |  |
| 96 | `equals_swf4` | 665 | 12.1s |  |
| 97 | `equals_swf4_alt` | 32 | 11.3s |  |
| 98 | `equals_swf5` | 32 | 11.1s |  |
| 99 | `error` | 58 | 10.9s |  |
| 100 | `escape` | 14 | 11.2s |  |
| 101 | `execution_order1` | 5 | 11.4s |  |
| 102 | `execution_order2` | 7 | 11.2s |  |
| 103 | `execution_order3` | 4 | 11.1s |  |
| 104 | `execution_order4` | 12 | 11.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `export_assets` | 3 | 11.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 106 | `extends_chain` | 134 | 11.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 107 | `extends_native_type` | 11 | 11.1s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 108 | `focusrect_mouse_swf8` | 0 | 10.5s |  |
| 109 | `focusrect_mouse_swf9` | 0 | 11.8s |  |
| 110 | `focusrect_swf5` | 6 | 10.8s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 111 | `function_suppress_and_preload` | 28 | 10.7s |  |
| 112 | `get_variable_in_scope` | 29 | 10.6s |  |
| 113 | `getproperty` | 28 | 10.6s |  |
| 114 | `getproperty_swf4` | 28 | 10.4s |  |
| 115 | `getproperty_swf5` | 28 | 10.2s |  |
| 116 | `global_array` | 3 | 10.2s |  |
| 117 | `global_is_bare` | 7 | 10.2s |  |
| 118 | `globals_swf5` | 304 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 119 | `globals_swf6` | 304 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 120 | `globals_swf7` | 304 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 121 | `globals_swf8` | 304 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 122 | `goto_advance1` | 6 | 10.5s |  |
| 123 | `goto_advance2` | 2 | 11.2s |  |
| 124 | `goto_both_ways1` | 3 | 10.7s |  |
| 125 | `goto_both_ways2` | 3 | 10.9s |  |
| 126 | `goto_execution_order` | 2 | 11.0s |  |
| 127 | `goto_execution_order2` | 2 | 11.2s |  |
| 128 | `goto_frame` | 12 | 11.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 129 | `goto_frame2` | 44 | 10.8s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 130 | `goto_frame_number` | 3 | 10.4s |  |
| 131 | `goto_label` | 17 | 10.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 132 | `goto_methods` | 40 | 10.4s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 133 | `goto_rewind1` | 1 | 10.4s |  |
| 134 | `goto_rewind2` | 3 | 10.5s |  |
| 135 | `goto_rewind3` | 2 | 10.3s |  |
| 136 | `greater_swf6` | 1175 | 12.4s |  |
| 137 | `greater_swf7` | 1175 | 12.4s |  |
| 138 | `greaterthan_swf5` | 1 | 10.4s |  |
| 139 | `greaterthan_swf8` | 1 | 10.4s |  |
| 140 | `has_own_property` | 32 | 10.5s |  |
| 141 | `hittest_lockroot` | 15 | 10.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 142 | `hittest_morph` | 70 | 10.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 143 | `hittest_winding_rule` | 12 | 10.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 144 | `infinite_recursion_function` | 4 | 10.4s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 145 | `infinite_recursion_function_in_setter` | 131 | 10.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 146 | `infinite_recursion_virtual_property` | 67 | 10.4s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 147 | `init_array_invalid` | 4 | 10.4s |  |
| 148 | `init_object_invalid` | 4 | 11.4s |  |
| 149 | `init_object_order` | 15 | 10.5s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 150 | `is_finite` | 49 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 151 | `is_finite_swf6` | 49 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 152 | `is_prototype_of` | 89 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 153 | `issue_1086` | 1 | 10.2s |  |
| 154 | `issue_1671` | 0 | 10.6s |  |
| 155 | `issue_1906` | 4 | 10.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 156 | `issue_2166` | 9 | 10.4s |  |
| 157 | `issue_3446` | 1 | 10.3s |  |
| 158 | `issue_3522` | 2 | 10.3s |  |
| 159 | `issue_4377` | 2 | 10.3s |  |
| 160 | `issue_710` | 4 | 10.3s |  |
| 161 | `issue_768` | 3 | 11.6s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 162 | `issue_9327` | 2 | 10.4s |  |
| 163 | `issue_9885` | 2 | 10.4s |  |
| 164 | `lessthan` | 41 | 10.5s |  |
| 165 | `lessthan2_swf5` | 1226 | 12.5s |  |
| 166 | `lessthan2_swf6` | 1226 | 12.4s |  |
| 167 | `lessthan2_swf7` | 1226 | 12.4s |  |
| 168 | `lessthan_swf4` | 902 | 11.4s |  |
| 169 | `lessthan_swf4_alt` | 41 | 10.2s |  |
| 170 | `lessthan_swf5` | 41 | 10.2s |  |
| 171 | `local_to_global` | 49 | 10.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 172 | `localconnection_properties` | 8 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 173 | `lock_root` | 1 | 10.4s |  |
| 174 | `logical_ops_swf4` | 90 | 10.4s |  |
| 175 | `logical_ops_swf8` | 108 | 10.5s |  |
| 176 | `looping` | 6 | 10.4s |  |
| 177 | `mask_reapply` | 0 | 10.3s |  |
| 178 | `mask_with_drawing` | 0 | 10.4s |  |
| 179 | `math_min_max` | 101 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 180 | `math_swf6` | 530 | 10.8s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 181 | `math_swf7` | 530 | 10.7s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 182 | `math_swf8` | 530 | 10.8s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 183 | `matrix` | 171 | 10.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 184 | `movieclip_begin_gradient_fill` | 0 | 10.6s |  |
| 185 | `movieclip_blend_mode_property` | 35 | 13.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_default_state` | 69 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 187 | `movieclip_depth_methods` | 98 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 188 | `movieclip_focusenabled` | 99 | 11.9s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 189 | `movieclip_get_instance_at_depth` | 28 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 190 | `movieclip_hittest` | 92 | 11.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 191 | `movieclip_in_removed_button` | 4 | 11.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 192 | `movieclip_init_object` | 5 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 193 | `movieclip_line_gradient_style` | 0 | 11.2s |  |
| 194 | `movieclip_name_from_timeline` | 13 | 10.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 195 | `movieclip_prototype_extension` | 5 | 10.3s |  |
| 196 | `mutable_this` | 18 | 10.3s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 197 | `named_shapes` | 14 | 10.2s |  |
| 198 | `nan_scale` | 9 | 10.3s |  |
| 199 | `native_double_construct` | 12 | 10.3s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 200 | `native_objects_swf7` | 84 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 201 | `native_objects_swf8` | 84 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 202 | `nested_textfields_in_buttons` | 0 | 10.2s |  |
| 203 | `new_method_wrap` | 4 | 10.7s |  |
| 204 | `new_object_enumerate` | 7 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 205 | `new_object_wrap` | 4 | 10.8s |  |
| 206 | `o` | 3 | 10.6s |  |
| 207 | `object_constructor` | 33 | 10.7s |  |
| 208 | `object_function` | 32 | 10.6s |  |
| 209 | `object_properties` | 31 | 11.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 210 | `object_prototypes` | 74 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 211 | `object_string_coerce_swf5` | 62 | 10.9s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 212 | `object_string_coerce_swf6` | 68 | 10.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 213 | `on_construct` | 25 | 10.7s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 214 | `parse_float` | 74 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 215 | `parse_int` | 64 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 216 | `path_string` | 322 | 11.1s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 217 | `place_and_lookup` | 30 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 218 | `placeobject_occupied_depth` | 6 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 219 | `point` | 175 | 11.2s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 220 | `primitive_instanceof` | 37 | 11.0s |  |
| 221 | `primitive_type_globals` | 557 | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 222 | `printjob_props_swf5` | 45 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 223 | `printjob_props_swf6` | 45 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 224 | `printjob_props_swf7` | 45 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 225 | `property_invalid_base_clip` | 36 | 10.7s |  |
| 226 | `prototype_delete` | 12 | 10.7s |  |
| 227 | `prototype_enumerate` | 5 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 228 | `prototype_properties` | 17 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 229 | `rectangle` | 745 | 11.4s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 230 | `recursive_prototypes` | 0 | 10.6s |  |
| 231 | `register_class_return_value` | 16 | 10.7s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 232 | `register_globals_across_frames` | 15 | 10.6s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 233 | `register_underflow` | 26 | 10.6s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 234 | `remove_movie_clip` | 29 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 235 | `rewind_depth` | 30 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 236 | `sandbox_type_local_file` | 1 | 10.7s |  |
| 237 | `sandbox_type_local_network` | 1 | 10.7s |  |
| 238 | `selection` | 454 | 10.9s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 239 | `set_interval` | 27 | 10.9s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 240 | `set_variable_scope` | 58 | 10.8s |  |
| 241 | `single_frame` | 1 | 10.7s |  |
| 242 | `slash_syntax` | 14 | 10.7s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 243 | `sound_props_swf5` | 68 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 244 | `sound_props_swf6` | 68 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 245 | `sound_start_load` | 0 | 10.4s |  |
| 246 | `stage_display_state` | 16 | 10.3s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 247 | `stage_object_children` | 83 | 10.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 248 | `stage_object_enumerate` | 4 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 249 | `stage_object_properties` | 241 | 10.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 250 | `stage_object_properties_get_var` | 5 | 10.2s |  |
| 251 | `stage_object_properties_swf6` | 231 | 10.5s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 252 | `stage_property_representation` | 586 | 10.2s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 253 | `stage_scale_mode` | 39 | 10.2s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 254 | `strictequals_swf6` | 902 | 11.8s |  |
| 255 | `strictly_equals` | 7 | 10.2s |  |
| 256 | `string_coercion` | 117 | 10.5s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 257 | `string_methods` | 285 | 10.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 258 | `string_methods_negative_args` | 240 | 10.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 259 | `string_methods_swfv5` | 275 | 10.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 260 | `string_ops_swf6` | 95 | 10.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 261 | `string_paths_basic` | 4 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 262 | `string_paths_hidden` | 54 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 263 | `string_paths_variable_alias` | 4 | 10.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 264 | `super_edge_cases` | 39 | 10.7s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 265 | `swf4_actions_bool` | 96 | 10.6s |  |
| 266 | `swf4_actions_coercion_order` | 158 | 10.7s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 267 | `swf4_bool` | 4 | 10.5s |  |
| 268 | `swf4_function_calls` | 7 | 10.5s |  |
| 269 | `swf5_encoding` | 3 | 10.5s |  |
| 270 | `swf5_no_closure` | 19 | 11.1s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 271 | `swf6_case_insensitive` | 42 | 10.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 272 | `swf6_string_as_bool` | 15 | 10.7s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 273 | `swf7_case_sensitive` | 44 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 274 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.4s |  |
| 275 | `target_clip_removed` | 5 | 10.5s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 276 | `target_clip_swf5` | 2 | 10.5s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 277 | `target_clip_swf6` | 2 | 10.4s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 278 | `target_path` | 14 | 10.3s |  |
| 279 | `tell_target` | 37 | 10.4s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 280 | `tell_target_invalid` | 6 | 10.6s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 281 | `tell_target_invalid_swf6` | 5 | 10.5s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 282 | `text_format` | 1146 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 283 | `text_format_display` | 21 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 284 | `text_format_font_max_length` | 2 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 285 | `text_format_rounding_swf7` | 840 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 286 | `text_format_rounding_swf8` | 840 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 287 | `textfield_background_color` | 11 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 288 | `textfield_border_color` | 11 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 289 | `textfield_maxchars` | 3 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 290 | `textfield_properties` | 44 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 291 | `textfield_props_swf5` | 175 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 292 | `textfield_props_swf6` | 210 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 293 | `textfield_props_swf7` | 210 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 294 | `textfield_props_swf8` | 210 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 295 | `textfield_text` | 7 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 296 | `textfield_variable` | 81 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 297 | `textsnapshot_props_swf6` | 56 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 298 | `this_scoping` | 52 | 10.4s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 299 | `this_swf5` | 41 | 10.5s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 300 | `this_swf6` | 41 | 10.3s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 301 | `this_swf7` | 41 | 10.4s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 302 | `timeline_function_def` | 7 | 10.3s |  |
| 303 | `transform` | 70 | 10.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 304 | `try_catch_finally` | 118 | 10.4s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 305 | `try_finally_simple` | 16 | 10.3s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 306 | `typeof` | 22 | 10.4s |  |
| 307 | `typeof_globals` | 7 | 10.3s |  |
| 308 | `uncaught_exception` | 1 | 10.3s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 309 | `uncaught_exception_bubbled` | 1 | 10.3s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 310 | `undefined_to_string_swf6` | 4 | 10.3s |  |
| 311 | `unescape` | 43 | 10.3s |  |
| 312 | `unload_clip_event` | 4 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 313 | `use_hand_cursor` | 8 | 10.3s |  |
| 314 | `variable_args` | 5 | 10.5s |  |
| 315 | `waitforframe` | 7 | 10.4s |  |
| 316 | `waitforframe2` | 16 | 10.7s |  |
| 317 | `watch` | 117 | 10.7s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 318 | `watch_virtual_property_proto` | 2 | 10.8s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 319 | `with` | 49 | 11.0s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 320 | `with_return` | 2 | 10.8s |  |
| 321 | `with_variable_scopes` | 43 | 10.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 322 | `xml` | 15 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 323 | `xml_append_child` | 28 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 324 | `xml_append_child_with_parent` | 20 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 325 | `xml_cdata` | 11 | 11.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 326 | `xml_child_nodes_edge_cases` | 4 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 327 | `xml_clone_expandos` | 19 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 328 | `xml_first_last_child` | 8 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 329 | `xml_has_child_nodes` | 3 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 330 | `xml_idmap` | 21 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 331 | `xml_ignore_comments` | 21 | 11.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 332 | `xml_ignore_white` | 34 | 11.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 333 | `xml_insert_before` | 20 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 334 | `xml_inspect_createmethods` | 15 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 335 | `xml_inspect_doctype` | 7 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 336 | `xml_inspect_parsexml` | 62 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 337 | `xml_inspect_xmldecl` | 7 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 338 | `xml_namespaces` | 203 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 339 | `xml_parent_and_child` | 5 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 340 | `xml_remove_node` | 22 | 11.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 341 | `xml_reparenting` | 14 | 11.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 342 | `xml_siblings` | 10 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 343 | `xml_to_string` | 13 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 344 | `xml_to_string_comment` | 1 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 345 | `xml_unescaping` | 23 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 346 | `xmlnode_proto` | 1 | 11.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**41 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `function_base_clip_removed` | 88.0% | 22 | 25 | 3 |  |
| 6 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 7 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 8 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 12 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 13 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 14 | `textsnapshot_props_swf5` | 67.9% | 38 | 56 | 18 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 17 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 19 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `edittext_programmatic_focus` | 58.3% | 7 | 12 | 5 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 32 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 33 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 39 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 40 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 41 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 12.4s |  |
| 2 | `netstream_play_flv_screen` | 25.2s |  |
| 3 | `string_paths_timer` | 12.6s |  |
| 4 | `timer_run_actions` | 14.0s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_3` | exit code -6 | 12.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_4` | exit code -6 | 12.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 36.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 20.3s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**121 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 4 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `function_base_clip_removed` | 88.0% | 22/25 | 25 | 25 |  |
| 6 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 7 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 8 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 12 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 13 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 14 | `textsnapshot_props_swf5` | 67.9% | 38/56 | 56 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 17 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 19 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `edittext_programmatic_focus` | 58.3% | 7/12 | 12 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 32 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 33 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 39 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 40 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 41 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 44 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `register_class_with_sound` | 45.5% | 5/11 | 11 | 11 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 46 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 47 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 48 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 49 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 50 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 51 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 52 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 53 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 54 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 59 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 60 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 62 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 63 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 64 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 65 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 67 | `register_class` | 24.2% | 16/66 | 50 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 68 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 70 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 71 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 73 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 74 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 75 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 77 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 78 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 79 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 80 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 82 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 84 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 85 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 87 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 89 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 90 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 91 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 92 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 93 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 94 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 95 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 96 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 97 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 98 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 99 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 100 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 101 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 103 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 104 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 105 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 106 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 107 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 108 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 109 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 110 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 112 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 113 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 114 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 115 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 116 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 117 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 118 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 119 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 120 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 7 | 7 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 1 | 6 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 21 | 10 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 0 | 49 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 27 | 31 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 10 | 5 |
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
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 145 | 41 |
