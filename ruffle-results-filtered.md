# Ruffle Test Results (Filtered)

**Date**: 2026-02-26 00:26 UTC

**Git SHA**: `5990fc78c7`

**Run Duration**: 102m 13s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **316** (66.0%) |
| Failing | 163 |
| Total expected lines | 71491 |
| Matching lines | 47842 (66.9%) |
| Mismatched lines | 23649 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 146 | 89.6% |
| Segfault | 13 | 8.0% |
| Runtime Error | 2 | 1.2% |
| Compile Fail | 1 | 0.6% |
| Timeout | 1 | 0.6% |

## Passing Tests

**316 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 9.7s |  |
| 2 | `action_to_integer` | 28 | 9.6s |  |
| 3 | `add` | 28 | 9.7s |  |
| 4 | `add2` | 354 | 9.8s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 9.6s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 9.4s |  |
| 7 | `add_swf5` | 28 | 9.6s |  |
| 8 | `arguments` | 127 | 9.6s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 9.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 9.5s |  |
| 11 | `array_enumerate` | 4 | 9.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 9.6s |  |
| 13 | `array_properties` | 36 | 9.6s |  |
| 14 | `array_prototyping` | 12 | 9.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 9.6s |  |
| 16 | `array_sort_random` | 443 | 9.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_splice` | 207 | 9.5s |  |
| 18 | `array_trivial` | 209 | 9.6s |  |
| 19 | `as1_constructor_v6` | 35 | 9.4s |  |
| 20 | `as1_constructor_v7` | 35 | 9.1s |  |
| 21 | `as2_oop` | 13 | 9.2s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 22 | `as2_super_and_this_v6` | 97 | 9.2s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v8` | 85 | 9.3s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_via_manual_prototype` | 40 | 9.3s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as_broadcaster_initialize` | 10 | 9.0s |  |
| 26 | `as_set_prop_flags` | 79 | 9.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 27 | `as_set_prop_flags_version` | 31 | 8.9s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 28 | `as_set_prop_flags_version_swf5` | 1 | 9.0s |  |
| 29 | `as_set_prop_flags_version_swf6` | 1 | 9.0s |  |
| 30 | `as_set_prop_flags_version_swf7` | 1 | 9.1s |  |
| 31 | `as_set_prop_flags_version_swf8` | 1 | 9.1s |  |
| 32 | `as_set_prop_flags_version_swf9` | 1 | 9.1s |  |
| 33 | `as_transformed_flag` | 20 | 9.1s |  |
| 34 | `attach_movie` | 59 | 9.1s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 35 | `attach_movie_stop` | 3 | 9.1s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `bad_swf_tag_past_eof` | 0 | 9.4s |  |
| 37 | `bitand` | 1058 | 12.1s |  |
| 38 | `bitmap_data_colortransform` | 0 | 9.8s |  |
| 39 | `bitmap_data_fillrect` | 0 | 9.6s |  |
| 40 | `bitmap_data_max_size_swf10` | 12 | 9.4s |  |
| 41 | `bitmap_data_max_size_swf9` | 10 | 9.4s |  |
| 42 | `bitmap_data_perlinnoise` | 0 | 10.2s |  |
| 43 | `bitmap_data_pixeldissolve_image` | 0 | 10.0s |  |
| 44 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.4s |  |
| 45 | `bitor` | 1058 | 12.0s |  |
| 46 | `biturshift` | 14 | 9.4s |  |
| 47 | `biturshift_swf8` | 14 | 10.0s |  |
| 48 | `bitxor` | 1058 | 12.7s |  |
| 49 | `boxed_primitives` | 24 | 9.9s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 50 | `button_children` | 8 | 9.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 51 | `button_goto` | 4 | 9.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 52 | `button_order` | 2 | 9.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_properties_special_cases` | 22 | 9.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_v5` | 18 | 9.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_v6` | 18 | 9.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `call_method_empty_name` | 1 | 9.4s |  |
| 57 | `capabilities_resolution` | 8 | 9.4s |  |
| 58 | `catch_references_registers` | 2 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 59 | `clip_events` | 19 | 10.1s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 60 | `clone_sprite_types` | 24 | 9.7s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 61 | `closure_scope` | 7 | 9.7s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 62 | `color` | 57 | 9.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 63 | `color_transform` | 48 | 9.8s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 64 | `conflicting_instance_names` | 23 | 9.8s |  |
| 65 | `constructor_function` | 2 | 9.6s |  |
| 66 | `create_empty_movie_clip` | 3 | 9.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 67 | `define_function2` | 8 | 9.6s |  |
| 68 | `define_function2_preload` | 13 | 9.5s |  |
| 69 | `define_function2_preload_order` | 4 | 10.0s |  |
| 70 | `define_function_case_sensitive` | 2 | 9.6s |  |
| 71 | `delete` | 3 | 10.2s |  |
| 72 | `display_object_properties` | 2 | 10.0s |  |
| 73 | `divide_swf4` | 107 | 10.2s |  |
| 74 | `do_init_action` | 3 | 10.4s |  |
| 75 | `duplicate_movie_clip` | 20 | 10.5s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 76 | `edittext_antialiastype` | 296 | 9.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_autosize_setter` | 20 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `edittext_default_format` | 221 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 79 | `edittext_default_format_empty` | 95 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 80 | `edittext_default_format_font_style` | 335 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_html_align_swf7` | 52 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_html_align_swf8` | 52 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_html_entity` | 4 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_newline_stripping` | 64 | 14.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_width_height` | 103 | 9.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `empty_movieclip_can_attach_movies` | 11 | 9.9s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 87 | `enumerate` | 64 | 9.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 88 | `equals` | 32 | 9.3s |  |
| 89 | `equals2_swf5` | 926 | 11.1s |  |
| 90 | `equals2_swf6` | 926 | 11.0s |  |
| 91 | `equals2_swf7` | 926 | 10.9s |  |
| 92 | `equals_swf4` | 665 | 10.0s |  |
| 93 | `equals_swf4_alt` | 32 | 9.3s |  |
| 94 | `equals_swf5` | 32 | 9.3s |  |
| 95 | `error` | 58 | 9.3s |  |
| 96 | `escape` | 14 | 9.2s |  |
| 97 | `execution_order1` | 5 | 9.3s |  |
| 98 | `execution_order2` | 7 | 9.4s |  |
| 99 | `execution_order3` | 4 | 9.3s |  |
| 100 | `export_assets` | 3 | 9.2s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 101 | `extends_chain` | 134 | 9.6s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 102 | `extends_native_type` | 11 | 9.4s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 103 | `focusrect_mouse_swf8` | 0 | 9.4s |  |
| 104 | `focusrect_mouse_swf9` | 0 | 10.6s |  |
| 105 | `focusrect_swf5` | 6 | 9.4s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 106 | `function_suppress_and_preload` | 28 | 9.3s |  |
| 107 | `get_variable_in_scope` | 29 | 9.3s |  |
| 108 | `getproperty` | 28 | 9.3s |  |
| 109 | `getproperty_swf4` | 28 | 9.9s |  |
| 110 | `getproperty_swf5` | 28 | 9.7s |  |
| 111 | `global_array` | 3 | 9.8s |  |
| 112 | `global_is_bare` | 7 | 9.7s |  |
| 113 | `globals_swf5` | 304 | 9.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 114 | `globals_swf6` | 304 | 9.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 115 | `globals_swf7` | 304 | 9.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 116 | `globals_swf8` | 304 | 9.9s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 117 | `goto_advance1` | 6 | 9.6s |  |
| 118 | `goto_advance2` | 2 | 9.6s |  |
| 119 | `goto_both_ways1` | 3 | 9.7s |  |
| 120 | `goto_both_ways2` | 3 | 9.8s |  |
| 121 | `goto_execution_order` | 2 | 9.6s |  |
| 122 | `goto_execution_order2` | 2 | 9.6s |  |
| 123 | `goto_frame` | 12 | 10.2s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 124 | `goto_frame_number` | 3 | 9.8s |  |
| 125 | `goto_label` | 17 | 9.8s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 126 | `goto_methods` | 40 | 9.7s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 127 | `goto_rewind1` | 1 | 9.6s |  |
| 128 | `goto_rewind2` | 3 | 9.6s |  |
| 129 | `goto_rewind3` | 2 | 9.4s |  |
| 130 | `greater_swf6` | 1175 | 11.5s |  |
| 131 | `greater_swf7` | 1175 | 11.4s |  |
| 132 | `greaterthan_swf5` | 1 | 9.3s |  |
| 133 | `greaterthan_swf8` | 1 | 9.3s |  |
| 134 | `has_own_property` | 32 | 9.4s |  |
| 135 | `hittest_lockroot` | 15 | 9.6s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 136 | `hittest_winding_rule` | 12 | 9.6s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 137 | `infinite_recursion_function` | 4 | 9.4s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 138 | `infinite_recursion_function_in_setter` | 131 | 9.4s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 139 | `infinite_recursion_virtual_property` | 67 | 9.4s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 140 | `init_array_invalid` | 4 | 9.4s |  |
| 141 | `init_object_invalid` | 4 | 10.9s |  |
| 142 | `init_object_order` | 15 | 9.3s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 143 | `is_finite` | 49 | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 144 | `is_finite_swf6` | 49 | 9.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 145 | `is_prototype_of` | 89 | 9.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 146 | `issue_1086` | 1 | 9.2s |  |
| 147 | `issue_1671` | 0 | 9.2s |  |
| 148 | `issue_1906` | 4 | 9.2s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 149 | `issue_2166` | 9 | 9.3s |  |
| 150 | `issue_3446` | 1 | 9.2s |  |
| 151 | `issue_3522` | 2 | 9.2s |  |
| 152 | `issue_4377` | 2 | 9.2s |  |
| 153 | `issue_710` | 4 | 9.2s |  |
| 154 | `issue_768` | 3 | 9.7s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 155 | `issue_9327` | 2 | 9.5s |  |
| 156 | `issue_9885` | 2 | 9.5s |  |
| 157 | `lessthan` | 41 | 9.5s |  |
| 158 | `lessthan2_swf5` | 1226 | 11.6s |  |
| 159 | `lessthan2_swf6` | 1226 | 11.6s |  |
| 160 | `lessthan2_swf7` | 1226 | 11.7s |  |
| 161 | `lessthan_swf4` | 902 | 11.0s |  |
| 162 | `lessthan_swf4_alt` | 41 | 9.4s |  |
| 163 | `lessthan_swf5` | 41 | 9.4s |  |
| 164 | `local_to_global` | 49 | 9.4s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 165 | `localconnection_properties` | 8 | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 166 | `lock_root` | 1 | 9.3s |  |
| 167 | `logical_ops_swf4` | 90 | 9.2s |  |
| 168 | `logical_ops_swf8` | 108 | 9.3s |  |
| 169 | `looping` | 6 | 9.3s |  |
| 170 | `mask_reapply` | 0 | 9.3s |  |
| 171 | `mask_with_drawing` | 0 | 9.3s |  |
| 172 | `math_min_max` | 101 | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 173 | `math_swf6` | 530 | 9.6s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 174 | `math_swf7` | 530 | 9.6s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 175 | `math_swf8` | 530 | 9.6s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 176 | `matrix` | 171 | 9.6s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 177 | `movieclip_begin_gradient_fill` | 0 | 10.2s |  |
| 178 | `movieclip_blend_mode_property` | 35 | 9.8s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 179 | `movieclip_default_state` | 69 | 9.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 180 | `movieclip_depth_methods` | 98 | 9.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 181 | `movieclip_focusenabled` | 99 | 9.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 182 | `movieclip_get_instance_at_depth` | 28 | 9.3s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 183 | `movieclip_hittest` | 92 | 9.6s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 184 | `movieclip_line_gradient_style` | 0 | 12.1s |  |
| 185 | `movieclip_name_from_timeline` | 13 | 9.9s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 186 | `movieclip_prototype_extension` | 5 | 9.5s |  |
| 187 | `mutable_this` | 18 | 9.7s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 188 | `nested_textfields_in_buttons` | 0 | 9.4s |  |
| 189 | `new_method_wrap` | 4 | 9.3s |  |
| 190 | `new_object_enumerate` | 7 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 191 | `new_object_wrap` | 4 | 9.3s |  |
| 192 | `o` | 3 | 9.3s |  |
| 193 | `object_constructor` | 33 | 9.3s |  |
| 194 | `object_function` | 32 | 9.3s |  |
| 195 | `object_properties` | 31 | 9.4s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 196 | `object_prototypes` | 74 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 197 | `object_string_coerce_swf5` | 62 | 9.3s | [25](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 198 | `object_string_coerce_swf6` | 68 | 9.3s | [25](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 199 | `parse_int` | 64 | 9.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 200 | `placeobject_occupied_depth` | 6 | 9.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 201 | `point` | 175 | 9.7s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 202 | `primitive_instanceof` | 37 | 9.3s |  |
| 203 | `primitive_type_globals` | 557 | 9.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 204 | `printjob_props_swf5` | 45 | 9.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 205 | `printjob_props_swf6` | 45 | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 206 | `printjob_props_swf7` | 45 | 9.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 207 | `property_invalid_base_clip` | 36 | 9.5s |  |
| 208 | `prototype_delete` | 12 | 9.5s |  |
| 209 | `prototype_enumerate` | 5 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 210 | `prototype_properties` | 17 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 211 | `rectangle` | 745 | 10.2s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 212 | `recursive_prototypes` | 0 | 9.4s |  |
| 213 | `register_class_return_value` | 16 | 9.5s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 214 | `register_globals_across_frames` | 15 | 9.5s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 215 | `register_underflow` | 26 | 9.4s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 216 | `remove_movie_clip` | 29 | 9.5s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 217 | `sandbox_type_local_file` | 1 | 9.4s |  |
| 218 | `sandbox_type_local_network` | 1 | 9.4s |  |
| 219 | `set_interval` | 27 | 9.6s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 220 | `set_variable_scope` | 58 | 9.5s |  |
| 221 | `single_frame` | 1 | 9.4s |  |
| 222 | `slash_syntax` | 14 | 9.5s | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 223 | `sound_props_swf5` | 68 | 10.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 224 | `sound_props_swf6` | 68 | 10.5s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 225 | `sound_start_load` | 0 | 10.2s |  |
| 226 | `stage_display_state` | 16 | 10.3s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 227 | `stage_object_enumerate` | 4 | 10.0s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 228 | `stage_object_properties` | 241 | 10.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 229 | `stage_object_properties_get_var` | 5 | 9.6s |  |
| 230 | `stage_object_properties_swf6` | 231 | 9.9s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 231 | `stage_property_representation` | 586 | 9.4s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 232 | `stage_scale_mode` | 39 | 9.5s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 233 | `strictequals_swf6` | 902 | 10.9s |  |
| 234 | `strictly_equals` | 7 | 9.4s |  |
| 235 | `string_coercion` | 117 | 9.7s | [35](ruffle-tests/_investigation/complete/string_coercion.md) |
| 236 | `string_methods` | 285 | 10.2s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 237 | `string_methods_negative_args` | 240 | 9.6s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 238 | `string_methods_swfv5` | 275 | 10.1s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 239 | `string_ops_swf6` | 95 | 10.0s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 240 | `string_paths_basic` | 4 | 9.6s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 241 | `string_paths_variable_alias` | 4 | 9.3s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 242 | `swf4_actions_bool` | 96 | 9.4s |  |
| 243 | `swf4_actions_coercion_order` | 158 | 9.4s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 244 | `swf4_bool` | 4 | 9.3s |  |
| 245 | `swf4_function_calls` | 7 | 9.3s |  |
| 246 | `swf5_encoding` | 3 | 9.4s |  |
| 247 | `swf5_no_closure` | 19 | 9.5s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 248 | `swf6_case_insensitive` | 42 | 9.5s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 249 | `swf6_string_as_bool` | 15 | 9.3s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 250 | `swf7_case_sensitive` | 44 | 9.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 251 | `tab_ordering_properties_tab_index_edge_case` | 4 | 9.3s |  |
| 252 | `target_clip_removed` | 5 | 9.4s | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 253 | `target_path` | 14 | 9.3s |  |
| 254 | `text_format` | 1146 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 255 | `text_format_display` | 21 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 256 | `text_format_font_max_length` | 2 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 257 | `text_format_rounding_swf7` | 840 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 258 | `text_format_rounding_swf8` | 840 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 259 | `textfield_background_color` | 11 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 260 | `textfield_border_color` | 11 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 261 | `textfield_maxchars` | 3 | 12.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 262 | `textfield_properties` | 44 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 263 | `textfield_props_swf5` | 175 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 264 | `textfield_props_swf6` | 210 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 265 | `textfield_props_swf7` | 210 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 266 | `textfield_props_swf8` | 210 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 267 | `textfield_text` | 7 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 268 | `textfield_variable` | 81 | 9.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 269 | `this_swf5` | 41 | 9.5s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 270 | `this_swf6` | 41 | 9.5s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 271 | `this_swf7` | 41 | 9.6s | [42](ruffle-tests/_investigation/complete/this_swf7.md) |
| 272 | `timeline_function_def` | 7 | 9.6s |  |
| 273 | `transform` | 70 | 9.9s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 274 | `try_catch_finally` | 118 | 9.8s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 275 | `try_finally_simple` | 16 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 276 | `typeof` | 22 | 9.5s |  |
| 277 | `typeof_globals` | 7 | 9.5s |  |
| 278 | `uncaught_exception` | 1 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 279 | `uncaught_exception_bubbled` | 1 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 280 | `undefined_to_string_swf6` | 4 | 9.4s |  |
| 281 | `unescape` | 43 | 9.4s |  |
| 282 | `unload_clip_event` | 4 | 9.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 283 | `use_hand_cursor` | 8 | 9.5s |  |
| 284 | `variable_args` | 5 | 9.7s |  |
| 285 | `waitforframe` | 7 | 9.5s |  |
| 286 | `waitforframe2` | 16 | 10.3s |  |
| 287 | `watch` | 117 | 9.8s | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 288 | `watch_virtual_property_proto` | 2 | 9.5s | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 289 | `with` | 49 | 9.5s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 290 | `with_return` | 2 | 9.4s |  |
| 291 | `with_variable_scopes` | 43 | 9.6s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 292 | `xml` | 15 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 293 | `xml_append_child` | 28 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 294 | `xml_append_child_with_parent` | 20 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 295 | `xml_cdata` | 11 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 296 | `xml_child_nodes_edge_cases` | 4 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 297 | `xml_clone_expandos` | 19 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 298 | `xml_first_last_child` | 8 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 299 | `xml_has_child_nodes` | 3 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 300 | `xml_idmap` | 21 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 301 | `xml_ignore_comments` | 21 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 302 | `xml_ignore_white` | 34 | 10.0s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 303 | `xml_insert_before` | 20 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 304 | `xml_inspect_createmethods` | 15 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 305 | `xml_inspect_doctype` | 7 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 306 | `xml_inspect_parsexml` | 62 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 307 | `xml_inspect_xmldecl` | 7 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 308 | `xml_namespaces` | 203 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 309 | `xml_parent_and_child` | 5 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 310 | `xml_remove_node` | 22 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 311 | `xml_reparenting` | 14 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 312 | `xml_siblings` | 10 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 313 | `xml_to_string` | 13 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 314 | `xml_to_string_comment` | 1 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 315 | `xml_unescaping` | 23 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 316 | `xmlnode_proto` | 1 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**49 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `array_constructor` | 96.7% | 29 | 30 | 1 |  |
| 3 | `hittest_morph` | 95.7% | 67 | 70 | 3 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [20](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 4 | `selection` | 95.6% | 434 | 454 | 20 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 8 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `clip_constructors` | 75.0% | 6 | 8 | 2 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 16 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 18 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 19 | `unload` | 69.2% | 36 | 52 | 16 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 20 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 22 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 25 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_align` | 60.0% | 36 | 60 | 24 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `execution_order4` | 58.3% | 7 | 12 | 5 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 34 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 36 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 39 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 40 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 41 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 42 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 46 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 47 | `movieclip_in_removed_button` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 48 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 49 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**13 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `funky_function_calls` | 11.4s |  |
| 2 | `movieclip_init_object` | 11.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 3 | `movieclip_library_state_values` | 11.9s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 11.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf7` | 12.0s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `native_objects_swf8` | 11.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `netstream_play_flv_screen` | 24.5s |  |
| 8 | `on_construct` | 11.4s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 9 | `register_and_init_order` | 11.9s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 10 | `register_class_with_sound` | 11.6s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 11 | `resolve_different_root` | 11.6s |  |
| 12 | `string_paths_timer` | 10.7s |  |
| 13 | `timer_run_actions` | 13.9s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 32.5s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 32.4s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 19.4s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**146 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `array_constructor` | 96.7% | 29/30 | 30 | 30 |  |
| 3 | `hittest_morph` | 95.7% | 67/70 | 70 | 70 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [20](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 4 | `selection` | 95.6% | 434/454 | 454 | 454 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 8 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 9 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 12 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `clip_constructors` | 75.0% | 6/8 | 8 | 8 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 14 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 16 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 18 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 19 | `unload` | 69.2% | 36/52 | 52 | 52 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 20 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 22 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 25 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 34 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 35 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 36 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 39 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 40 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 41 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 42 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 46 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 47 | `movieclip_in_removed_button` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 48 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 49 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 52 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 54 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 55 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 56 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 57 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 58 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 59 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 60 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 64 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 65 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 67 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 68 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 69 | `goto_frame2` | 29.5% | 13/44 | 19 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 70 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 71 | `default_names` | 28.8% | 15/52 | 48 | 52 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 72 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 74 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 75 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 76 | `textsnapshot_props_swf5` | 25.0% | 14/56 | 38 | 56 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 77 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 78 | `this_scoping` | 20.8% | 11/53 | 53 | 52 | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 79 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 80 | `tell_target_invalid` | 20.0% | 2/10 | 10 | 6 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 81 | `tell_target_invalid_swf6` | 20.0% | 2/10 | 10 | 5 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 82 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 83 | `register_class_swf6` | 18.9% | 7/37 | 10 | 37 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 84 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 85 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 86 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 87 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 88 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 6 | 13 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 89 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 6 | 13 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 90 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 91 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 92 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 93 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 94 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 96 | `path_string` | 11.5% | 40/349 | 349 | 322 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 97 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `register_class` | 10.6% | 7/66 | 52 | 66 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 99 | `tell_target` | 10.3% | 4/39 | 39 | 37 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 100 | `define_local` | 7.4% | 2/27 | 23 | 27 | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 101 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 103 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 105 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 106 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 107 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 108 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 109 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 110 | `movieclip_invalid_get_bounds_2` | 4.0% | 3/75 | 3 | 75 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 111 | `movieclip_invalid_get_bounds_1` | 2.7% | 2/75 | 3 | 75 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 112 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 113 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 114 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 115 | `global_proto_decls` | 0.4% | 16/4497 | 572 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 116 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 117 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 118 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 119 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 120 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 121 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 122 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 123 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 125 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 126 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 127 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 128 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 129 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 130 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 131 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 132 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 133 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 134 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 135 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 136 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 137 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 138 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 139 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 140 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 141 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 142 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 143 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 144 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 145 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 146 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 3 | 1 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 6 | 8 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 0 | 4 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 6 | 0 | 6 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 3 | 1 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 16 | 15 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 4 | 13 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 16 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) | 49 | 0 | 49 |
| 17 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 18 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) | 4 | 0 | 4 |
| 19 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 20 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) | 1 | 0 | 1 |
| 21 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 0 | 5 |
| 22 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 20 | 38 |
| 23 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) | 16 | 0 | 16 |
| 24 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 25 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 26 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 27 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
| 28 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 29 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 30 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 7 | 8 |
| 31 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) | 4 | 0 | 4 |
| 32 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 33 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 6 | 3 |
| 34 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 6 | 1 |
| 35 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 36 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 37 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 38 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 1 | 15 |
| 39 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 40 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 25 | 45 |
| 41 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 42 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 43 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 44 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 45 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 6 | 6 |
| 46 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 47 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 25 | 8 |
| | *(tests not in any document)* | 186 | 142 | 44 |
