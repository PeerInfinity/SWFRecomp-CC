# Ruffle Test Results (Filtered)

**Date**: 2026-03-01 04:39 UTC

**Git SHA**: `fa0f23599a`

**Run Duration**: 113m 39s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **352** (73.8%) |
| Failing | 125 |
| Total expected lines | 70886 |
| Matching lines | 49266 (69.5%) |
| Mismatched lines | 21620 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 114 | 91.2% |
| Segfault | 4 | 3.2% |
| Runtime Error | 4 | 3.2% |
| Compile Fail | 2 | 1.6% |
| Timeout | 1 | 0.8% |

## Passing Tests

**352 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.4s |  |
| 2 | `action_to_integer` | 28 | 10.4s |  |
| 3 | `add` | 28 | 10.4s |  |
| 4 | `add2` | 354 | 10.6s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 10.4s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 10.4s |  |
| 7 | `add_swf5` | 28 | 10.4s |  |
| 8 | `arguments` | 127 | 10.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 10.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 10.3s |  |
| 11 | `array_constructor` | 30 | 10.3s |  |
| 12 | `array_enumerate` | 4 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 10.3s |  |
| 14 | `array_properties` | 36 | 10.3s |  |
| 15 | `array_prototyping` | 12 | 10.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 10.4s |  |
| 17 | `array_sort_random` | 443 | 10.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 10.5s |  |
| 19 | `array_trivial` | 209 | 10.6s |  |
| 20 | `as1_constructor_v6` | 35 | 10.4s |  |
| 21 | `as1_constructor_v7` | 35 | 10.6s |  |
| 22 | `as2_oop` | 13 | 10.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 10.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 10.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 10.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 10.4s |  |
| 27 | `as_set_prop_flags` | 79 | 10.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 10.4s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 10.4s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 10.4s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 10.4s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 10.4s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 10.4s |  |
| 34 | `as_transformed_flag` | 20 | 10.4s |  |
| 35 | `attach_movie` | 59 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `bad_placeobject_clipaction` | 2 | 11.7s |  |
| 38 | `bad_swf_tag_past_eof` | 0 | 10.3s |  |
| 39 | `bitand` | 1058 | 12.9s |  |
| 40 | `bitmap_data_colortransform` | 0 | 10.8s |  |
| 41 | `bitmap_data_fillrect` | 0 | 10.7s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 10.8s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 10.5s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 11.5s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 11.1s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.4s |  |
| 47 | `bitor` | 1058 | 13.0s |  |
| 48 | `biturshift` | 14 | 10.5s |  |
| 49 | `biturshift_swf8` | 14 | 11.0s |  |
| 50 | `bitxor` | 1058 | 13.3s |  |
| 51 | `boxed_primitives` | 24 | 10.8s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 10.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 10.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_order` | 2 | 10.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_properties_special_cases` | 22 | 10.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v5` | 18 | 10.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_v6` | 18 | 10.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `call_method_empty_name` | 1 | 10.6s |  |
| 59 | `capabilities_resolution` | 8 | 10.6s |  |
| 60 | `catch_references_registers` | 2 | 10.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 61 | `clip_constructors` | 8 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 62 | `clip_events` | 19 | 11.4s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 63 | `clone_sprite_types` | 24 | 11.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `closure_scope` | 7 | 11.1s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 65 | `color` | 57 | 11.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 66 | `color_transform` | 48 | 11.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 67 | `conflicting_instance_names` | 23 | 11.0s |  |
| 68 | `constructor_function` | 2 | 10.9s |  |
| 69 | `context_menu` | 39 | 10.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `context_menu_item` | 41 | 10.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `create_empty_movie_clip` | 3 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `define_function2` | 8 | 11.0s |  |
| 73 | `define_function2_preload` | 13 | 10.9s |  |
| 74 | `define_function2_preload_order` | 4 | 10.7s |  |
| 75 | `define_function_case_sensitive` | 2 | 10.5s |  |
| 76 | `delete` | 3 | 10.6s |  |
| 77 | `display_object_properties` | 2 | 10.5s |  |
| 78 | `divide_swf4` | 107 | 10.6s |  |
| 79 | `do_init_action` | 3 | 10.5s |  |
| 80 | `duplicate_movie_clip` | 20 | 10.5s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `edittext_antialiastype` | 296 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_autosize_setter` | 20 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_default_format` | 221 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_default_format_empty` | 95 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_default_format_font_style` | 335 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_font_size` | 45 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_html_align_swf7` | 52 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_html_align_swf8` | 52 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_html_entity` | 4 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `edittext_newline_stripping` | 64 | 15.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_programmatic_focus` | 12 | 11.0s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_width_height` | 103 | 11.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `empty_movieclip_can_attach_movies` | 11 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 94 | `enumerate` | 64 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 95 | `equals` | 32 | 10.3s |  |
| 96 | `equals2_swf5` | 926 | 11.9s |  |
| 97 | `equals2_swf6` | 926 | 11.9s |  |
| 98 | `equals2_swf7` | 926 | 11.9s |  |
| 99 | `equals_swf4` | 665 | 11.0s |  |
| 100 | `equals_swf4_alt` | 32 | 10.3s |  |
| 101 | `equals_swf5` | 32 | 10.2s |  |
| 102 | `error` | 58 | 10.2s |  |
| 103 | `escape` | 14 | 10.2s |  |
| 104 | `execution_order1` | 5 | 10.3s |  |
| 105 | `execution_order2` | 7 | 10.3s |  |
| 106 | `execution_order3` | 4 | 10.2s |  |
| 107 | `execution_order4` | 12 | 10.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 108 | `export_assets` | 3 | 10.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 109 | `extends_chain` | 134 | 10.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 110 | `extends_native_type` | 11 | 10.2s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 111 | `focusrect_mouse_swf8` | 0 | 10.5s |  |
| 112 | `focusrect_mouse_swf9` | 0 | 11.2s |  |
| 113 | `focusrect_swf5` | 6 | 11.2s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 114 | `function_suppress_and_preload` | 28 | 11.4s |  |
| 115 | `get_variable_in_scope` | 29 | 10.9s |  |
| 116 | `getproperty` | 28 | 11.0s |  |
| 117 | `getproperty_swf4` | 28 | 12.6s |  |
| 118 | `getproperty_swf5` | 28 | 10.7s |  |
| 119 | `global_array` | 3 | 10.7s |  |
| 120 | `global_is_bare` | 7 | 10.7s |  |
| 121 | `globals_swf5` | 304 | 10.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 122 | `globals_swf6` | 304 | 10.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 123 | `globals_swf7` | 304 | 10.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 124 | `globals_swf8` | 304 | 10.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 125 | `goto_advance1` | 6 | 10.7s |  |
| 126 | `goto_advance2` | 2 | 10.7s |  |
| 127 | `goto_both_ways1` | 3 | 10.7s |  |
| 128 | `goto_both_ways2` | 3 | 10.8s |  |
| 129 | `goto_execution_order` | 2 | 10.7s |  |
| 130 | `goto_execution_order2` | 2 | 10.7s |  |
| 131 | `goto_frame` | 12 | 12.2s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 132 | `goto_frame2` | 44 | 10.9s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 133 | `goto_frame_number` | 3 | 10.5s |  |
| 134 | `goto_label` | 17 | 10.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 135 | `goto_methods` | 40 | 10.4s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 136 | `goto_rewind1` | 1 | 10.4s |  |
| 137 | `goto_rewind2` | 3 | 10.4s |  |
| 138 | `goto_rewind3` | 2 | 10.4s |  |
| 139 | `greater_swf6` | 1175 | 12.3s |  |
| 140 | `greater_swf7` | 1175 | 12.3s |  |
| 141 | `greaterthan_swf5` | 1 | 10.4s |  |
| 142 | `greaterthan_swf8` | 1 | 10.4s |  |
| 143 | `has_own_property` | 32 | 10.5s |  |
| 144 | `hittest_lockroot` | 15 | 10.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 145 | `hittest_morph` | 70 | 10.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 146 | `hittest_winding_rule` | 12 | 10.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 147 | `infinite_recursion_function` | 4 | 10.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 148 | `infinite_recursion_function_in_setter` | 131 | 10.4s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 149 | `infinite_recursion_virtual_property` | 67 | 10.4s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 150 | `init_array_invalid` | 4 | 10.4s |  |
| 151 | `init_object_invalid` | 4 | 12.5s |  |
| 152 | `init_object_order` | 15 | 10.7s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 153 | `is_finite` | 49 | 10.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 154 | `is_finite_swf6` | 49 | 10.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 155 | `is_prototype_of` | 89 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 156 | `issue_1086` | 1 | 10.6s |  |
| 157 | `issue_1671` | 0 | 10.5s |  |
| 158 | `issue_1906` | 4 | 10.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 159 | `issue_2166` | 9 | 10.6s |  |
| 160 | `issue_3446` | 1 | 10.6s |  |
| 161 | `issue_3522` | 2 | 10.6s |  |
| 162 | `issue_4377` | 2 | 10.5s |  |
| 163 | `issue_710` | 4 | 10.6s |  |
| 164 | `issue_768` | 3 | 10.5s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 165 | `issue_9327` | 2 | 10.5s |  |
| 166 | `issue_9885` | 2 | 10.4s |  |
| 167 | `lessthan` | 41 | 10.4s |  |
| 168 | `lessthan2_swf5` | 1226 | 12.5s |  |
| 169 | `lessthan2_swf6` | 1226 | 12.4s |  |
| 170 | `lessthan2_swf7` | 1226 | 12.4s |  |
| 171 | `lessthan_swf4` | 902 | 11.6s |  |
| 172 | `lessthan_swf4_alt` | 41 | 10.4s |  |
| 173 | `lessthan_swf5` | 41 | 10.4s |  |
| 174 | `local_to_global` | 49 | 11.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 175 | `localconnection_properties` | 8 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 176 | `lock_root` | 1 | 11.1s |  |
| 177 | `logical_ops_swf4` | 90 | 11.0s |  |
| 178 | `logical_ops_swf8` | 108 | 11.1s |  |
| 179 | `looping` | 6 | 11.2s |  |
| 180 | `mask_reapply` | 0 | 11.2s |  |
| 181 | `mask_with_drawing` | 0 | 11.7s |  |
| 182 | `math_min_max` | 101 | 11.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 183 | `math_swf6` | 530 | 12.0s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 184 | `math_swf7` | 530 | 11.9s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 185 | `math_swf8` | 530 | 11.8s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 186 | `matrix` | 171 | 11.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 187 | `movieclip_begin_gradient_fill` | 0 | 11.7s |  |
| 188 | `movieclip_blend_mode_property` | 35 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 189 | `movieclip_create_text_field` | 90 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 190 | `movieclip_default_state` | 69 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 191 | `movieclip_depth_methods` | 98 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 192 | `movieclip_focusenabled` | 99 | 10.6s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 193 | `movieclip_get_instance_at_depth` | 28 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 194 | `movieclip_hittest` | 92 | 10.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 195 | `movieclip_in_removed_button` | 4 | 10.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 196 | `movieclip_init_object` | 5 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 197 | `movieclip_line_gradient_style` | 0 | 13.0s |  |
| 198 | `movieclip_name_from_timeline` | 13 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 199 | `movieclip_prototype_extension` | 5 | 10.5s |  |
| 200 | `mutable_this` | 18 | 10.8s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 201 | `named_shapes` | 14 | 10.8s |  |
| 202 | `nan_scale` | 9 | 10.9s |  |
| 203 | `native_double_construct` | 12 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 204 | `native_objects_swf7` | 84 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 205 | `native_objects_swf8` | 84 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 206 | `nested_textfields_in_buttons` | 0 | 11.1s |  |
| 207 | `new_method_wrap` | 4 | 10.5s |  |
| 208 | `new_object_enumerate` | 7 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 209 | `new_object_wrap` | 4 | 10.4s |  |
| 210 | `o` | 3 | 10.4s |  |
| 211 | `object_constructor` | 33 | 10.4s |  |
| 212 | `object_function` | 32 | 10.4s |  |
| 213 | `object_properties` | 31 | 10.6s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 214 | `object_prototypes` | 74 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 215 | `object_string_coerce_swf5` | 62 | 10.4s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 216 | `object_string_coerce_swf6` | 68 | 10.4s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 217 | `on_construct` | 25 | 10.4s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 218 | `parse_float` | 74 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 219 | `parse_int` | 64 | 10.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 220 | `path_string` | 322 | 10.6s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 221 | `place_and_lookup` | 30 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 222 | `placeobject_occupied_depth` | 6 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 223 | `point` | 175 | 10.8s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 224 | `primitive_instanceof` | 37 | 10.5s |  |
| 225 | `primitive_type_globals` | 557 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 226 | `printjob_props_swf5` | 45 | 10.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 227 | `printjob_props_swf6` | 45 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 228 | `printjob_props_swf7` | 45 | 10.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 229 | `property_invalid_base_clip` | 36 | 10.7s |  |
| 230 | `prototype_delete` | 12 | 10.6s |  |
| 231 | `prototype_enumerate` | 5 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 232 | `prototype_properties` | 17 | 10.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 233 | `rectangle` | 745 | 11.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 234 | `recursive_prototypes` | 0 | 10.7s |  |
| 235 | `register_class_return_value` | 16 | 10.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 236 | `register_globals_across_frames` | 15 | 10.4s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 237 | `register_underflow` | 26 | 10.5s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 238 | `remove_movie_clip` | 29 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 239 | `rewind_depth` | 30 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 240 | `sandbox_type_local_file` | 1 | 10.6s |  |
| 241 | `sandbox_type_local_network` | 1 | 10.7s |  |
| 242 | `set_interval` | 27 | 10.6s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 243 | `set_variable_scope` | 58 | 10.4s |  |
| 244 | `single_frame` | 1 | 10.3s |  |
| 245 | `slash_syntax` | 14 | 10.4s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 246 | `sound_props_swf5` | 68 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 247 | `sound_props_swf6` | 68 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 248 | `sound_start_load` | 0 | 10.6s |  |
| 249 | `stage_display_state` | 16 | 10.6s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 250 | `stage_object_children` | 83 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 251 | `stage_object_enumerate` | 4 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 252 | `stage_object_properties` | 241 | 11.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 253 | `stage_object_properties_get_var` | 5 | 10.5s |  |
| 254 | `stage_object_properties_swf6` | 231 | 10.8s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 255 | `stage_property_representation` | 586 | 10.5s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 256 | `stage_scale_mode` | 39 | 10.6s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 257 | `strictequals_swf6` | 902 | 12.1s |  |
| 258 | `strictly_equals` | 7 | 10.5s |  |
| 259 | `string_coercion` | 117 | 10.7s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 260 | `string_methods` | 285 | 11.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 261 | `string_methods_negative_args` | 240 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 262 | `string_methods_swfv5` | 275 | 11.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 263 | `string_ops_swf6` | 95 | 10.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 264 | `string_paths_basic` | 4 | 10.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 265 | `string_paths_hidden` | 54 | 10.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 266 | `string_paths_variable_alias` | 4 | 10.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 267 | `super_edge_cases` | 39 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 268 | `swf4_actions_bool` | 96 | 10.9s |  |
| 269 | `swf4_actions_coercion_order` | 158 | 10.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 270 | `swf4_bool` | 4 | 10.8s |  |
| 271 | `swf4_function_calls` | 7 | 10.8s |  |
| 272 | `swf5_encoding` | 3 | 10.7s |  |
| 273 | `swf5_no_closure` | 19 | 11.3s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 274 | `swf6_case_insensitive` | 42 | 10.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 275 | `swf6_string_as_bool` | 15 | 10.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 276 | `swf7_case_sensitive` | 44 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 277 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.4s |  |
| 278 | `target_clip_removed` | 5 | 10.5s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 279 | `target_clip_swf5` | 2 | 10.4s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 280 | `target_clip_swf6` | 2 | 10.5s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 281 | `target_path` | 14 | 10.5s |  |
| 282 | `tell_target` | 37 | 10.5s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 283 | `tell_target_invalid` | 6 | 10.5s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 284 | `tell_target_invalid_swf6` | 5 | 10.5s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 285 | `text_format` | 1146 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 286 | `text_format_display` | 21 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 287 | `text_format_font_max_length` | 2 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 288 | `text_format_rounding_swf7` | 840 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 289 | `text_format_rounding_swf8` | 840 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 290 | `textfield_background_color` | 11 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 291 | `textfield_border_color` | 11 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 292 | `textfield_cache_as_bitmap` | 1 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 293 | `textfield_maxchars` | 3 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 294 | `textfield_properties` | 44 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 295 | `textfield_props_swf5` | 175 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 296 | `textfield_props_swf6` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 297 | `textfield_props_swf7` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 298 | `textfield_props_swf8` | 210 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 299 | `textfield_text` | 7 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 300 | `textfield_variable` | 81 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 301 | `textsnapshot_props_swf5` | 56 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 302 | `textsnapshot_props_swf6` | 56 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 303 | `this_scoping` | 52 | 10.5s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 304 | `this_swf5` | 41 | 10.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 305 | `this_swf6` | 41 | 10.5s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 306 | `this_swf7` | 41 | 10.5s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 307 | `timeline_function_def` | 7 | 10.6s |  |
| 308 | `transform` | 70 | 10.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 309 | `try_catch_finally` | 118 | 10.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 310 | `try_finally_simple` | 16 | 10.6s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 311 | `typeof` | 22 | 10.6s |  |
| 312 | `typeof_globals` | 7 | 10.5s |  |
| 313 | `uncaught_exception` | 1 | 10.5s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 314 | `uncaught_exception_bubbled` | 1 | 10.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 315 | `undefined_to_string_swf6` | 4 | 10.6s |  |
| 316 | `unescape` | 43 | 10.6s |  |
| 317 | `unload_clip_event` | 4 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 318 | `use_hand_cursor` | 8 | 10.5s |  |
| 319 | `variable_args` | 5 | 10.6s |  |
| 320 | `waitforframe` | 7 | 10.5s |  |
| 321 | `waitforframe2` | 16 | 12.2s |  |
| 322 | `watch` | 117 | 11.0s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 323 | `watch_textfield` | 12 | 10.6s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 324 | `watch_virtual_property_proto` | 2 | 10.7s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 325 | `with` | 49 | 10.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 326 | `with_return` | 2 | 10.6s |  |
| 327 | `with_variable_scopes` | 43 | 10.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 328 | `xml` | 15 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 329 | `xml_append_child` | 28 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 330 | `xml_append_child_with_parent` | 20 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 331 | `xml_cdata` | 11 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 332 | `xml_child_nodes_edge_cases` | 4 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 333 | `xml_clone_expandos` | 19 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 334 | `xml_first_last_child` | 8 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 335 | `xml_has_child_nodes` | 3 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 336 | `xml_idmap` | 21 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 337 | `xml_ignore_comments` | 21 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 338 | `xml_ignore_white` | 34 | 11.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 339 | `xml_insert_before` | 20 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 340 | `xml_inspect_createmethods` | 15 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 341 | `xml_inspect_doctype` | 7 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 342 | `xml_inspect_parsexml` | 62 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 343 | `xml_inspect_xmldecl` | 7 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 344 | `xml_namespaces` | 203 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 345 | `xml_parent_and_child` | 5 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 346 | `xml_remove_node` | 22 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 347 | `xml_reparenting` | 14 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 348 | `xml_siblings` | 10 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 349 | `xml_to_string` | 13 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 350 | `xml_to_string_comment` | 1 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 351 | `xml_unescaping` | 23 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 352 | `xmlnode_proto` | 1 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**46 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `selection` | 99.6% | 452 | 454 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `function_base_clip_removed` | 88.0% | 22 | 25 | 3 |  |
| 7 | `edittext_align` | 86.7% | 52 | 60 | 8 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 10 | `edittext_text_height_leading` | 80.0% | 16 | 20 | 4 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 11 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 13 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 14 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 16 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 17 | `edittext_align_trailing_spaces_swf7` | 68.8% | 396 | 576 | 180 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_autosize` | 67.6% | 48 | 71 | 23 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `edittext_html_color` | 66.7% | 76 | 114 | 38 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 22 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `edittext_stylesheet` | 62.8% | 204 | 325 | 121 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 33 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_align_trailing_spaces_swf8` | 56.2% | 324 | 576 | 252 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 36 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 37 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 38 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `register_class_with_sound` | 54.5% | 6 | 11 | 5 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 40 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 44 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 45 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 46 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 13.0s |  |
| 2 | `netstream_play_flv_screen` | 26.4s |  |
| 3 | `string_paths_timer` | 12.8s |  |
| 4 | `timer_run_actions` | 13.9s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_3` | exit code -6 | 10.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_4` | exit code -6 | 11.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 33.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 33.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 20.4s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**114 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `selection` | 99.6% | 452/454 | 454 | 454 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `function_base_clip_removed` | 88.0% | 22/25 | 25 | 25 |  |
| 7 | `edittext_align` | 86.7% | 52/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 10 | `edittext_text_height_leading` | 80.0% | 16/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 11 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 13 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 14 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 16 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 17 | `edittext_align_trailing_spaces_swf7` | 68.8% | 396/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_autosize` | 67.6% | 48/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `edittext_html_color` | 66.7% | 76/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 22 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `edittext_stylesheet` | 62.8% | 204/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 33 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_align_trailing_spaces_swf8` | 56.2% | 324/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 36 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 37 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 38 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `register_class_with_sound` | 54.5% | 6/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 40 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 44 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 45 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 46 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 49 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 50 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 51 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 52 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 53 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 54 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 55 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 57 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 59 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 60 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 61 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 62 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 63 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 64 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 65 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 68 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 69 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 70 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 71 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 72 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 73 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 74 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 75 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 76 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 77 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 79 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 82 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 83 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 84 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 86 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 88 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 90 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 91 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 92 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 93 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 94 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 95 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 96 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 97 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 98 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 99 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 100 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 101 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 102 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 103 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 104 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 105 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 107 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 108 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 109 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 110 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 111 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 112 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 113 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

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
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 28 | 30 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 10 | 5 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 7 | 2 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 7 | 6 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 11 | 8 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 31 | 39 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 146 | 40 |
