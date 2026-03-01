# Ruffle Test Results (Filtered)

**Date**: 2026-03-01 20:37 UTC

**Git SHA**: `3a734264f8`

**Run Duration**: 116m 18s

**Filtered**: 142 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 477 |
| Passing | **360** (75.5%) |
| Failing | 117 |
| Total expected lines | 71224 |
| Matching lines | 49791 (69.9%) |
| Mismatched lines | 21433 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 107 | 91.5% |
| Segfault | 4 | 3.4% |
| Runtime Error | 4 | 3.4% |
| Compile Fail | 1 | 0.9% |
| Timeout | 1 | 0.9% |

## Passing Tests

**360 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 12.6s |  |
| 2 | `action_to_integer` | 28 | 10.9s |  |
| 3 | `add` | 28 | 10.9s |  |
| 4 | `add2` | 354 | 11.1s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 10.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 10.9s |  |
| 7 | `add_swf5` | 28 | 10.9s |  |
| 8 | `arguments` | 127 | 10.8s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 10.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 10.9s |  |
| 11 | `array_constructor` | 30 | 10.8s |  |
| 12 | `array_enumerate` | 4 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 10.9s |  |
| 14 | `array_properties` | 36 | 10.8s |  |
| 15 | `array_prototyping` | 12 | 10.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 10.9s |  |
| 17 | `array_sort_random` | 443 | 11.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 11.1s |  |
| 19 | `array_trivial` | 209 | 11.0s |  |
| 20 | `as1_constructor_v6` | 35 | 10.8s |  |
| 21 | `as1_constructor_v7` | 35 | 11.0s |  |
| 22 | `as2_oop` | 13 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster_initialize` | 10 | 10.6s |  |
| 27 | `as_set_prop_flags` | 79 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version` | 31 | 10.6s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version_swf5` | 1 | 10.6s |  |
| 30 | `as_set_prop_flags_version_swf6` | 1 | 10.6s |  |
| 31 | `as_set_prop_flags_version_swf7` | 1 | 10.6s |  |
| 32 | `as_set_prop_flags_version_swf8` | 1 | 10.8s |  |
| 33 | `as_set_prop_flags_version_swf9` | 1 | 10.7s |  |
| 34 | `as_transformed_flag` | 20 | 10.9s |  |
| 35 | `attach_movie` | 59 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 36 | `attach_movie_stop` | 3 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `bad_placeobject_clipaction` | 2 | 11.2s |  |
| 38 | `bad_swf_tag_past_eof` | 0 | 10.8s |  |
| 39 | `bitand` | 1058 | 13.5s |  |
| 40 | `bitmap_data_colortransform` | 0 | 11.3s |  |
| 41 | `bitmap_data_fillrect` | 0 | 11.0s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 11.2s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 11.1s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 11.8s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 11.4s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.9s |  |
| 47 | `bitor` | 1058 | 13.8s |  |
| 48 | `biturshift` | 14 | 11.0s |  |
| 49 | `biturshift_swf8` | 14 | 11.4s |  |
| 50 | `bitxor` | 1058 | 13.9s |  |
| 51 | `boxed_primitives` | 24 | 11.3s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 11.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 11.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_order` | 2 | 11.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_properties_special_cases` | 22 | 11.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v5` | 18 | 11.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_v6` | 18 | 11.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `call_method_empty_name` | 1 | 11.2s |  |
| 59 | `capabilities_resolution` | 8 | 11.2s |  |
| 60 | `catch_references_registers` | 2 | 11.2s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 61 | `clip_constructors` | 8 | 11.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 62 | `clip_events` | 19 | 11.5s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 63 | `clone_sprite_types` | 24 | 11.2s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `closure_scope` | 7 | 11.2s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 65 | `color` | 57 | 11.5s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 66 | `color_transform` | 48 | 11.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 67 | `conflicting_instance_names` | 23 | 11.4s |  |
| 68 | `constructor_function` | 2 | 11.2s |  |
| 69 | `context_menu` | 39 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 70 | `context_menu_item` | 41 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `create_empty_movie_clip` | 3 | 11.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `define_function2` | 8 | 11.1s |  |
| 73 | `define_function2_preload` | 13 | 11.3s |  |
| 74 | `define_function2_preload_order` | 4 | 11.0s |  |
| 75 | `define_function_case_sensitive` | 2 | 10.7s |  |
| 76 | `delete` | 3 | 10.9s |  |
| 77 | `display_object_properties` | 2 | 10.8s |  |
| 78 | `divide_swf4` | 107 | 10.8s |  |
| 79 | `do_init_action` | 3 | 10.8s |  |
| 80 | `duplicate_movie_clip` | 20 | 10.7s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `edittext_align` | 60 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_antialiastype` | 296 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_autosize` | 71 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_autosize_setter` | 20 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_default_format` | 221 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_default_format_empty` | 95 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_default_format_font_style` | 335 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_font_size` | 45 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_html_align_swf7` | 52 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `edittext_html_align_swf8` | 52 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_html_entity` | 4 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_leading` | 9 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_margins` | 25 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_newline_stripping` | 64 | 15.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_programmatic_focus` | 12 | 10.7s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_tag_indent` | 31 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_text_height_leading` | 20 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_underline` | 40 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_width_height` | 103 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `empty_movieclip_can_attach_movies` | 11 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 101 | `enumerate` | 64 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 102 | `equals` | 32 | 11.6s |  |
| 103 | `equals2_swf5` | 926 | 13.4s |  |
| 104 | `equals2_swf6` | 926 | 13.5s |  |
| 105 | `equals2_swf7` | 926 | 13.7s |  |
| 106 | `equals_swf4` | 665 | 12.5s |  |
| 107 | `equals_swf4_alt` | 32 | 11.7s |  |
| 108 | `equals_swf5` | 32 | 11.6s |  |
| 109 | `error` | 58 | 11.5s |  |
| 110 | `escape` | 14 | 11.2s |  |
| 111 | `execution_order1` | 5 | 11.6s |  |
| 112 | `execution_order2` | 7 | 11.6s |  |
| 113 | `execution_order3` | 4 | 11.4s |  |
| 114 | `execution_order4` | 12 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 115 | `export_assets` | 3 | 11.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 116 | `extends_chain` | 134 | 11.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 117 | `extends_native_type` | 11 | 11.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 118 | `focusrect_mouse_swf8` | 0 | 10.8s |  |
| 119 | `focusrect_mouse_swf9` | 0 | 11.9s |  |
| 120 | `focusrect_swf5` | 6 | 11.0s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 121 | `function_suppress_and_preload` | 28 | 10.9s |  |
| 122 | `get_variable_in_scope` | 29 | 11.3s |  |
| 123 | `getproperty` | 28 | 11.7s |  |
| 124 | `getproperty_swf4` | 28 | 12.6s |  |
| 125 | `getproperty_swf5` | 28 | 11.1s |  |
| 126 | `global_array` | 3 | 11.1s |  |
| 127 | `global_is_bare` | 7 | 10.9s |  |
| 128 | `globals_swf5` | 304 | 11.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 129 | `globals_swf6` | 304 | 11.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 130 | `globals_swf7` | 304 | 11.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 131 | `globals_swf8` | 304 | 11.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 132 | `goto_advance1` | 6 | 10.9s |  |
| 133 | `goto_advance2` | 2 | 10.8s |  |
| 134 | `goto_both_ways1` | 3 | 10.8s |  |
| 135 | `goto_both_ways2` | 3 | 11.0s |  |
| 136 | `goto_execution_order` | 2 | 10.7s |  |
| 137 | `goto_execution_order2` | 2 | 10.8s |  |
| 138 | `goto_frame` | 12 | 12.3s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 139 | `goto_frame2` | 44 | 11.2s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 140 | `goto_frame_number` | 3 | 10.7s |  |
| 141 | `goto_label` | 17 | 10.8s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 142 | `goto_methods` | 40 | 10.8s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 143 | `goto_rewind1` | 1 | 10.7s |  |
| 144 | `goto_rewind2` | 3 | 10.7s |  |
| 145 | `goto_rewind3` | 2 | 10.7s |  |
| 146 | `greater_swf6` | 1175 | 12.6s |  |
| 147 | `greater_swf7` | 1175 | 12.6s |  |
| 148 | `greaterthan_swf5` | 1 | 10.6s |  |
| 149 | `greaterthan_swf8` | 1 | 10.6s |  |
| 150 | `has_own_property` | 32 | 10.7s |  |
| 151 | `hittest_lockroot` | 15 | 10.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 152 | `hittest_morph` | 70 | 10.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 153 | `hittest_winding_rule` | 12 | 10.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 154 | `infinite_recursion_function` | 4 | 10.6s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 155 | `infinite_recursion_function_in_setter` | 131 | 10.6s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 156 | `infinite_recursion_virtual_property` | 67 | 10.6s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 157 | `init_array_invalid` | 4 | 10.6s |  |
| 158 | `init_object_invalid` | 4 | 11.0s |  |
| 159 | `init_object_order` | 15 | 10.8s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 160 | `is_finite` | 49 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 161 | `is_finite_swf6` | 49 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 162 | `is_prototype_of` | 89 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 163 | `issue_1086` | 1 | 10.6s |  |
| 164 | `issue_1671` | 0 | 10.6s |  |
| 165 | `issue_1906` | 4 | 10.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 166 | `issue_2166` | 9 | 10.7s |  |
| 167 | `issue_3446` | 1 | 10.7s |  |
| 168 | `issue_3522` | 2 | 10.7s |  |
| 169 | `issue_4377` | 2 | 10.7s |  |
| 170 | `issue_710` | 4 | 10.7s |  |
| 171 | `issue_768` | 3 | 12.3s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 172 | `issue_9327` | 2 | 10.8s |  |
| 173 | `issue_9885` | 2 | 10.9s |  |
| 174 | `lessthan` | 41 | 10.9s |  |
| 175 | `lessthan2_swf5` | 1226 | 12.9s |  |
| 176 | `lessthan2_swf6` | 1226 | 13.1s |  |
| 177 | `lessthan2_swf7` | 1226 | 12.9s |  |
| 178 | `lessthan_swf4` | 902 | 12.0s |  |
| 179 | `lessthan_swf4_alt` | 41 | 10.8s |  |
| 180 | `lessthan_swf5` | 41 | 10.8s |  |
| 181 | `local_to_global` | 49 | 11.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 182 | `localconnection_properties` | 8 | 10.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 183 | `lock_root` | 1 | 11.1s |  |
| 184 | `logical_ops_swf4` | 90 | 11.2s |  |
| 185 | `logical_ops_swf8` | 108 | 11.0s |  |
| 186 | `looping` | 6 | 11.0s |  |
| 187 | `mask_reapply` | 0 | 11.1s |  |
| 188 | `mask_with_drawing` | 0 | 11.2s |  |
| 189 | `math_min_max` | 101 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 190 | `math_swf6` | 530 | 11.5s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 191 | `math_swf7` | 530 | 11.3s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 192 | `math_swf8` | 530 | 11.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 193 | `matrix` | 171 | 11.3s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 194 | `movieclip_begin_gradient_fill` | 0 | 11.3s |  |
| 195 | `movieclip_blend_mode_property` | 35 | 12.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 196 | `movieclip_create_text_field` | 90 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 197 | `movieclip_default_state` | 69 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 198 | `movieclip_depth_methods` | 98 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 199 | `movieclip_focusenabled` | 99 | 10.7s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 200 | `movieclip_get_instance_at_depth` | 28 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 201 | `movieclip_hittest` | 92 | 10.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 202 | `movieclip_in_removed_button` | 4 | 10.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 203 | `movieclip_init_object` | 5 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 204 | `movieclip_line_gradient_style` | 0 | 11.6s |  |
| 205 | `movieclip_name_from_timeline` | 13 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 206 | `movieclip_prototype_extension` | 5 | 10.8s |  |
| 207 | `mutable_this` | 18 | 10.9s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 208 | `named_shapes` | 14 | 10.8s |  |
| 209 | `nan_scale` | 9 | 10.9s |  |
| 210 | `native_double_construct` | 12 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 211 | `native_objects_swf7` | 84 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 212 | `native_objects_swf8` | 84 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 213 | `nested_textfields_in_buttons` | 0 | 10.8s |  |
| 214 | `new_method_wrap` | 4 | 10.8s |  |
| 215 | `new_object_enumerate` | 7 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 216 | `new_object_wrap` | 4 | 10.8s |  |
| 217 | `o` | 3 | 10.7s |  |
| 218 | `object_constructor` | 33 | 11.0s |  |
| 219 | `object_function` | 32 | 10.9s |  |
| 220 | `object_properties` | 31 | 11.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 221 | `object_prototypes` | 74 | 11.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 222 | `object_string_coerce_swf5` | 62 | 11.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 223 | `object_string_coerce_swf6` | 68 | 10.9s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 224 | `on_construct` | 25 | 11.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 225 | `parse_float` | 74 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 226 | `parse_int` | 64 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 227 | `path_string` | 322 | 11.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 228 | `place_and_lookup` | 30 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 229 | `placeobject_occupied_depth` | 6 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 230 | `point` | 175 | 11.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 231 | `primitive_instanceof` | 37 | 10.8s |  |
| 232 | `primitive_type_globals` | 557 | 11.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 233 | `printjob_props_swf5` | 45 | 10.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 234 | `printjob_props_swf6` | 45 | 10.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 235 | `printjob_props_swf7` | 45 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 236 | `property_invalid_base_clip` | 36 | 10.9s |  |
| 237 | `prototype_delete` | 12 | 10.7s |  |
| 238 | `prototype_enumerate` | 5 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 239 | `prototype_properties` | 17 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 240 | `rectangle` | 745 | 11.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 241 | `recursive_prototypes` | 0 | 10.7s |  |
| 242 | `register_class_return_value` | 16 | 10.7s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 243 | `register_globals_across_frames` | 15 | 10.7s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 244 | `register_underflow` | 26 | 10.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 245 | `remove_movie_clip` | 29 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 246 | `rewind_depth` | 30 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 247 | `sandbox_type_local_file` | 1 | 10.9s |  |
| 248 | `sandbox_type_local_network` | 1 | 10.8s |  |
| 249 | `set_interval` | 27 | 11.3s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 250 | `set_variable_scope` | 58 | 10.9s |  |
| 251 | `single_frame` | 1 | 10.8s |  |
| 252 | `slash_syntax` | 14 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 253 | `sound_props_swf5` | 68 | 10.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 254 | `sound_props_swf6` | 68 | 10.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 255 | `sound_start_load` | 0 | 10.8s |  |
| 256 | `stage_display_state` | 16 | 10.8s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 257 | `stage_object_children` | 83 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 258 | `stage_object_enumerate` | 4 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 259 | `stage_object_properties` | 241 | 11.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 260 | `stage_object_properties_get_var` | 5 | 10.7s |  |
| 261 | `stage_object_properties_swf6` | 231 | 11.0s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 262 | `stage_property_representation` | 586 | 10.7s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 263 | `stage_scale_mode` | 39 | 10.8s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 264 | `strictequals_swf6` | 902 | 12.2s |  |
| 265 | `strictly_equals` | 7 | 10.7s |  |
| 266 | `string_coercion` | 117 | 11.1s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 267 | `string_methods` | 285 | 11.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 268 | `string_methods_negative_args` | 240 | 10.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 269 | `string_methods_swfv5` | 275 | 11.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 270 | `string_ops_swf6` | 95 | 10.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 271 | `string_paths_basic` | 4 | 10.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 272 | `string_paths_hidden` | 54 | 10.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 273 | `string_paths_variable_alias` | 4 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 274 | `super_edge_cases` | 39 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 275 | `swf4_actions_bool` | 96 | 10.7s |  |
| 276 | `swf4_actions_coercion_order` | 158 | 10.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 277 | `swf4_bool` | 4 | 10.8s |  |
| 278 | `swf4_function_calls` | 7 | 10.8s |  |
| 279 | `swf5_encoding` | 3 | 10.7s |  |
| 280 | `swf5_no_closure` | 19 | 11.1s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 281 | `swf6_case_insensitive` | 42 | 11.0s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 282 | `swf6_string_as_bool` | 15 | 10.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 283 | `swf7_case_sensitive` | 44 | 11.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 284 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.7s |  |
| 285 | `target_clip_removed` | 5 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 286 | `target_clip_swf5` | 2 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 287 | `target_clip_swf6` | 2 | 10.7s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 288 | `target_path` | 14 | 10.7s |  |
| 289 | `tell_target` | 37 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 290 | `tell_target_invalid` | 6 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 291 | `tell_target_invalid_swf6` | 5 | 10.9s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 292 | `text_format` | 1146 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 293 | `text_format_display` | 21 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 294 | `text_format_font_max_length` | 2 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 295 | `text_format_rounding_swf7` | 840 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 296 | `text_format_rounding_swf8` | 840 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 297 | `textfield_background_color` | 11 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 298 | `textfield_border_color` | 11 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 299 | `textfield_cache_as_bitmap` | 1 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 300 | `textfield_maxchars` | 3 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 301 | `textfield_properties` | 44 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 302 | `textfield_props_swf5` | 175 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 303 | `textfield_props_swf6` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 304 | `textfield_props_swf7` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 305 | `textfield_props_swf8` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 306 | `textfield_text` | 7 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 307 | `textfield_variable` | 81 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 308 | `textsnapshot_props_swf5` | 56 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 309 | `textsnapshot_props_swf6` | 56 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 310 | `this_scoping` | 52 | 10.8s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 311 | `this_swf5` | 41 | 10.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 312 | `this_swf6` | 41 | 10.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 313 | `this_swf7` | 41 | 10.7s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 314 | `timeline_function_def` | 7 | 10.8s |  |
| 315 | `transform` | 70 | 10.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 316 | `try_catch_finally` | 118 | 11.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 317 | `try_finally_simple` | 16 | 10.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 318 | `typeof` | 22 | 10.7s |  |
| 319 | `typeof_globals` | 7 | 10.8s |  |
| 320 | `uncaught_exception` | 1 | 10.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 321 | `uncaught_exception_bubbled` | 1 | 10.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 322 | `undefined_to_string_swf6` | 4 | 10.7s |  |
| 323 | `unescape` | 43 | 10.8s |  |
| 324 | `unload` | 52 | 11.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 325 | `unload_clip_event` | 4 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 326 | `use_hand_cursor` | 8 | 10.8s |  |
| 327 | `variable_args` | 5 | 11.0s |  |
| 328 | `waitforframe` | 7 | 10.8s |  |
| 329 | `waitforframe2` | 16 | 12.2s |  |
| 330 | `watch` | 117 | 12.2s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 331 | `watch_textfield` | 12 | 11.7s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 332 | `watch_virtual_property_proto` | 2 | 11.9s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 333 | `with` | 49 | 11.6s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 334 | `with_return` | 2 | 11.6s |  |
| 335 | `with_variable_scopes` | 43 | 11.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 336 | `xml` | 15 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 337 | `xml_append_child` | 28 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 338 | `xml_append_child_with_parent` | 20 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 339 | `xml_cdata` | 11 | 11.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 340 | `xml_child_nodes_edge_cases` | 4 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 341 | `xml_clone_expandos` | 19 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 342 | `xml_first_last_child` | 8 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 343 | `xml_has_child_nodes` | 3 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 344 | `xml_idmap` | 21 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 345 | `xml_ignore_comments` | 21 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 346 | `xml_ignore_white` | 34 | 11.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 347 | `xml_insert_before` | 20 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 348 | `xml_inspect_createmethods` | 15 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 349 | `xml_inspect_doctype` | 7 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 350 | `xml_inspect_parsexml` | 62 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 351 | `xml_inspect_xmldecl` | 7 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 352 | `xml_namespaces` | 203 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 353 | `xml_parent_and_child` | 5 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 354 | `xml_remove_node` | 22 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 355 | `xml_reparenting` | 14 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 356 | `xml_siblings` | 10 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 357 | `xml_to_string` | 13 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 358 | `xml_to_string_comment` | 1 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 359 | `xml_unescaping` | 23 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xmlnode_proto` | 1 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**41 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `selection` | 99.6% | 452 | 454 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `edittext_letter_spacing` | 93.3% | 14 | 15 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `function_base_clip_removed` | 88.0% | 22 | 25 | 3 |  |
| 9 | `edittext_hscroll` | 85.2% | 23 | 27 | 4 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 12 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 13 | `edittext_align_trailing_spaces_swf7` | 81.2% | 468 | 576 | 108 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 16 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 17 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 18 | `edittext_html_color` | 66.7% | 76 | 114 | 38 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 20 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 22 | `edittext_stylesheet` | 62.8% | 204 | 325 | 121 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360 | 576 | 216 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `clone_sprite_edittext_dynamic` | 61.6% | 53 | 86 | 33 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 29 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 31 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 32 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 33 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `register_class_with_sound` | 54.5% | 6 | 11 | 5 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 35 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 38 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 39 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 40 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 41 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**4 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 13.3s |  |
| 2 | `netstream_play_flv_screen` | 26.0s |  |
| 3 | `string_paths_timer` | 12.8s |  |
| 4 | `timer_run_actions` | 13.5s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_3` | exit code -6 | 11.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_4` | exit code -6 | 11.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 34.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 34.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 20.6s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**107 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `selection` | 99.6% | 452/454 | 454 | 454 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `edittext_letter_spacing` | 93.3% | 14/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `function_base_clip_removed` | 88.0% | 22/25 | 25 | 25 |  |
| 9 | `edittext_hscroll` | 85.2% | 23/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 12 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 13 | `edittext_align_trailing_spaces_swf7` | 81.2% | 468/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 16 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 17 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 18 | `edittext_html_color` | 66.7% | 76/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 20 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 22 | `edittext_stylesheet` | 62.8% | 204/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `clone_sprite_edittext_dynamic` | 61.6% | 53/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 29 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 31 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 32 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 33 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `register_class_with_sound` | 54.5% | 6/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 35 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 38 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 39 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 40 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 41 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 44 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 45 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 46 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 47 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 48 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 49 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 50 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 52 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 53 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 54 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 55 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 56 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 57 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 58 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 59 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 60 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 61 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 62 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 64 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 65 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 67 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 68 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 69 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 70 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 72 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 73 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 74 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 75 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 77 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 79 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 81 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 82 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 83 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 84 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 86 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 87 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 88 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 90 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 91 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 92 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 93 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 94 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 95 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 96 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 97 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 98 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 99 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 100 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 101 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 102 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 103 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 104 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 105 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 106 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

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
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
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
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 38 | 32 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 7 | 5 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 146 | 40 |
