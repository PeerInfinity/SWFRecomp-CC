# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-25 23:21 UTC

**Git SHA**: `7a73471ab5`

**Run Duration**: 100m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **362** (58.5%) |
| Failing | 257 |
| Total expected lines | 91468 |
| Matching lines | 58569 (64.0%) |
| Mismatched lines | 32899 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 239 | 93.0% |
| Runtime Segfault | 14 | 5.4% |
| Runtime Error | 2 | 0.8% |
| Compile Fail | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**362 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 9.8s |  |
| 2 | `action_to_integer` | 28 | 9.6s |  |
| 3 | `add` | 28 | 9.8s |  |
| 4 | `add2` | 354 | 10.0s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 9.6s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 9.5s |  |
| 7 | `add_swf5` | 28 | 9.5s |  |
| 8 | `arguments` | 127 | 9.6s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 9.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 9.7s |  |
| 11 | `array_constructor` | 30 | 9.5s |  |
| 12 | `array_enumerate` | 4 | 9.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 9.6s |  |
| 14 | `array_properties` | 36 | 9.6s |  |
| 15 | `array_prototyping` | 12 | 9.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 9.6s |  |
| 17 | `array_sort` | 161 | 10.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 9.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 9.8s |  |
| 20 | `array_trivial` | 209 | 9.9s |  |
| 21 | `as1_constructor_v6` | 35 | 9.6s |  |
| 22 | `as1_constructor_v7` | 35 | 9.6s |  |
| 23 | `as2_oop` | 13 | 9.6s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 9.5s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 9.6s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 9.5s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 9.3s |  |
| 28 | `as_set_prop_flags` | 79 | 9.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 9.2s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 9.2s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 9.2s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 9.2s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 9.2s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 9.2s |  |
| 35 | `as_transformed_flag` | 20 | 9.2s |  |
| 36 | `attach_movie` | 59 | 9.3s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 9.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 38 | `bad_swf_tag_past_eof` | 0 | 9.5s |  |
| 39 | `bitand` | 1058 | 12.4s |  |
| 40 | `bitmap_data_colortransform` | 0 | 9.9s |  |
| 41 | `bitmap_data_fillrect` | 0 | 9.6s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 9.4s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 9.4s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 10.3s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 9.9s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.4s |  |
| 47 | `bitor` | 1058 | 12.4s |  |
| 48 | `biturshift` | 14 | 9.5s |  |
| 49 | `biturshift_swf8` | 14 | 9.5s |  |
| 50 | `bitxor` | 1058 | 11.7s |  |
| 51 | `boxed_primitives` | 24 | 9.2s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 9.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 9.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_order` | 2 | 9.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_properties_special_cases` | 22 | 9.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_v5` | 18 | 9.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_v6` | 18 | 9.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `call_method_empty_name` | 1 | 9.5s |  |
| 59 | `capabilities_resolution` | 8 | 9.2s |  |
| 60 | `catch_references_registers` | 2 | 9.1s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 61 | `clip_events` | 19 | 9.5s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 62 | `clone_sprite_types` | 24 | 9.2s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 63 | `closure_scope` | 7 | 9.3s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 64 | `color` | 57 | 9.5s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 65 | `color_transform` | 48 | 9.3s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 66 | `conflicting_instance_names` | 23 | 9.3s |  |
| 67 | `create_empty_movie_clip` | 3 | 9.2s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 68 | `define_function2` | 8 | 9.2s |  |
| 69 | `define_function2_preload` | 13 | 9.1s |  |
| 70 | `define_function2_preload_order` | 4 | 9.5s |  |
| 71 | `define_function_case_sensitive` | 2 | 9.3s |  |
| 72 | `delete` | 3 | 9.2s |  |
| 73 | `display_object_properties` | 2 | 9.0s |  |
| 74 | `divide_swf4` | 107 | 9.1s |  |
| 75 | `do_init_action` | 3 | 9.1s |  |
| 76 | `drag_drop` | 10 | 9.2s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 77 | `drag_over_from_outside` | 1 | 9.2s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 78 | `drag_over_without_startdrag` | 1 | 9.3s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 79 | `duplicate_movie_clip` | 20 | 9.2s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 80 | `edittext_antialiastype` | 296 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 81 | `edittext_autosize_setter` | 20 | 9.2s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 82 | `edittext_default_format` | 221 | 9.2s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_default_format_empty` | 95 | 9.1s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_default_format_font_style` | 335 | 9.1s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_html_align_swf7` | 52 | 9.2s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `edittext_html_align_swf8` | 52 | 9.2s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 87 | `edittext_html_entity` | 4 | 9.2s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_newline_stripping` | 64 | 14.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_password` | 5 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `edittext_password_copy` | 4 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_paste_empty` | 2 | 10.1s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_restrict_paste` | 5 | 9.8s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_width_height` | 103 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `empty_movieclip_can_attach_movies` | 11 | 9.3s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 95 | `enumerate` | 64 | 9.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 96 | `equals` | 32 | 9.2s |  |
| 97 | `equals2_swf5` | 926 | 10.9s |  |
| 98 | `equals2_swf6` | 926 | 10.8s |  |
| 99 | `equals2_swf7` | 926 | 10.8s |  |
| 100 | `equals_swf4` | 665 | 9.8s |  |
| 101 | `equals_swf4_alt` | 32 | 9.1s |  |
| 102 | `equals_swf5` | 32 | 9.1s |  |
| 103 | `error` | 58 | 9.0s |  |
| 104 | `escape` | 14 | 9.0s |  |
| 105 | `execution_order1` | 5 | 9.1s |  |
| 106 | `execution_order2` | 7 | 9.1s |  |
| 107 | `execution_order3` | 4 | 9.1s |  |
| 108 | `export_assets` | 3 | 9.0s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 109 | `extends_chain` | 134 | 9.5s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 110 | `extends_native_type` | 11 | 9.1s | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 111 | `focus_root_movie` | 2 | 9.1s | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 112 | `focusrect_focuslost` | 4 | 9.3s | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 113 | `focusrect_mouse_swf8` | 0 | 9.3s |  |
| 114 | `focusrect_mouse_swf9` | 0 | 9.8s |  |
| 115 | `focusrect_swf5` | 6 | 9.9s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 116 | `focusrect_swf6` | 42 | 9.8s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 117 | `form_loader_encoding_1` | 1 | 9.8s |  |
| 118 | `function_suppress_and_preload` | 28 | 9.7s |  |
| 119 | `get_variable_in_scope` | 29 | 9.8s |  |
| 120 | `getproperty` | 28 | 9.6s |  |
| 121 | `getproperty_swf4` | 28 | 11.1s |  |
| 122 | `getproperty_swf5` | 28 | 9.3s |  |
| 123 | `global_array` | 3 | 9.2s |  |
| 124 | `global_is_bare` | 7 | 9.2s |  |
| 125 | `globals_swf5` | 304 | 9.5s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 126 | `globals_swf6` | 304 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 127 | `globals_swf7` | 304 | 9.7s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 128 | `globals_swf8` | 304 | 9.4s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 129 | `goto_advance1` | 6 | 9.1s |  |
| 130 | `goto_advance2` | 2 | 9.2s |  |
| 131 | `goto_both_ways1` | 3 | 9.2s |  |
| 132 | `goto_both_ways2` | 3 | 9.4s |  |
| 133 | `goto_execution_order` | 2 | 9.2s |  |
| 134 | `goto_execution_order2` | 2 | 9.2s |  |
| 135 | `goto_frame` | 12 | 11.6s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 136 | `goto_frame_number` | 3 | 9.5s |  |
| 137 | `goto_label` | 17 | 9.7s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 138 | `goto_methods` | 40 | 9.5s | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 139 | `goto_rewind1` | 1 | 9.4s |  |
| 140 | `goto_rewind2` | 3 | 9.4s |  |
| 141 | `goto_rewind3` | 2 | 9.5s |  |
| 142 | `greater_swf6` | 1175 | 11.6s |  |
| 143 | `greater_swf7` | 1175 | 11.6s |  |
| 144 | `greaterthan_swf5` | 1 | 9.4s |  |
| 145 | `greaterthan_swf8` | 1 | 9.4s |  |
| 146 | `has_own_property` | 32 | 9.4s |  |
| 147 | `hittest_lockroot` | 15 | 9.6s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 148 | `hittest_winding_rule` | 12 | 9.7s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 149 | `infinite_recursion_function` | 4 | 9.4s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 150 | `infinite_recursion_function_in_setter` | 131 | 9.4s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 151 | `infinite_recursion_virtual_property` | 67 | 9.4s | [14](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 152 | `init_array_invalid` | 4 | 9.3s |  |
| 153 | `init_object_invalid` | 4 | 9.4s |  |
| 154 | `is_finite` | 49 | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 155 | `is_finite_swf6` | 49 | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 156 | `is_prototype_of` | 89 | 9.3s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 157 | `issue_1086` | 1 | 9.1s |  |
| 158 | `issue_1671` | 0 | 9.0s |  |
| 159 | `issue_1906` | 4 | 9.1s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 160 | `issue_2166` | 9 | 9.0s |  |
| 161 | `issue_3446` | 1 | 9.0s |  |
| 162 | `issue_3522` | 2 | 9.1s |  |
| 163 | `issue_4377` | 2 | 9.0s |  |
| 164 | `issue_710` | 4 | 9.0s |  |
| 165 | `issue_768` | 3 | 9.5s | [15](ruffle-tests/_investigation/complete/issue_768.md) |
| 166 | `issue_9327` | 2 | 9.4s |  |
| 167 | `issue_9885` | 2 | 9.3s |  |
| 168 | `key_isToggled` | 9 | 9.3s |  |
| 169 | `lessthan` | 41 | 9.3s |  |
| 170 | `lessthan2_swf5` | 1226 | 11.2s |  |
| 171 | `lessthan2_swf6` | 1226 | 11.2s |  |
| 172 | `lessthan2_swf7` | 1226 | 11.2s |  |
| 173 | `lessthan_swf4` | 902 | 10.7s |  |
| 174 | `lessthan_swf4_alt` | 41 | 9.2s |  |
| 175 | `lessthan_swf5` | 41 | 9.2s |  |
| 176 | `loadmovie` | 2 | 9.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 177 | `loadmovie_fail` | 2 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 178 | `loadmovie_method` | 2 | 9.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 179 | `loadmovie_replace_root` | 5 | 9.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 180 | `loadmovienum` | 3 | 9.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 181 | `loadvariables` | 2 | 9.2s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 182 | `loadvariables2` | 8 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 183 | `loadvariablesnum` | 2 | 9.2s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 184 | `local_to_global` | 49 | 9.2s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 185 | `localconnection_properties` | 8 | 9.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 186 | `lock_root` | 1 | 9.2s |  |
| 187 | `logical_ops_swf4` | 90 | 9.1s |  |
| 188 | `logical_ops_swf8` | 108 | 9.1s |  |
| 189 | `looping` | 6 | 9.1s |  |
| 190 | `mask_reapply` | 0 | 9.2s |  |
| 191 | `mask_with_drawing` | 0 | 9.3s |  |
| 192 | `math_min_max` | 101 | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 193 | `math_swf6` | 530 | 9.5s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 194 | `math_swf7` | 530 | 9.5s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 195 | `math_swf8` | 530 | 9.5s | [19](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 196 | `matrix` | 171 | 9.5s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 197 | `mcl_as_broadcaster` | 12 | 9.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 198 | `mcl_getprogress` | 30 | 9.9s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 199 | `mcl_loadclip` | 149 | 9.6s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 200 | `mcl_loadclip_properties` | 6 | 9.5s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 201 | `mcl_mislabeled_target` | 6 | 9.4s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 202 | `mcl_target_gif87a` | 6 | 10.0s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 203 | `mcl_target_gif89a` | 6 | 9.9s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 204 | `mcl_target_jpg` | 6 | 9.4s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 205 | `mcl_target_png` | 6 | 9.4s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 206 | `mcl_unloadclip` | 5 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 207 | `mouse_events` | 8 | 9.4s | [21](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 208 | `mouse_hover_events_while_dragging` | 1 | 9.5s | [7](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) |
| 209 | `mouse_listeners` | 67 | 9.5s |  |
| 210 | `mouse_wheel_enabled` | 2 | 9.4s |  |
| 211 | `movieclip_begin_gradient_fill` | 0 | 10.0s |  |
| 212 | `movieclip_blend_mode_property` | 35 | 9.5s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 213 | `movieclip_default_state` | 69 | 9.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 214 | `movieclip_depth_methods` | 98 | 9.5s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 215 | `movieclip_focusenabled` | 99 | 9.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 216 | `movieclip_get_instance_at_depth` | 28 | 9.3s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 217 | `movieclip_hittest` | 92 | 9.3s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 218 | `movieclip_line_gradient_style` | 0 | 12.8s |  |
| 219 | `movieclip_name_from_timeline` | 13 | 10.3s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 220 | `movieclip_prototype_extension` | 5 | 10.0s |  |
| 221 | `moviecliploader_flashvars` | 4 | 10.1s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 222 | `mutable_this` | 18 | 10.7s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 223 | `nested_textfields_in_buttons` | 0 | 10.0s |  |
| 224 | `new_method_wrap` | 4 | 9.1s |  |
| 225 | `new_object_enumerate` | 7 | 9.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 226 | `new_object_wrap` | 4 | 9.0s |  |
| 227 | `o` | 3 | 9.1s |  |
| 228 | `object_constructor` | 33 | 9.1s |  |
| 229 | `object_function` | 32 | 9.1s |  |
| 230 | `object_properties` | 31 | 9.2s | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 231 | `object_prototypes` | 74 | 9.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 232 | `object_string_coerce_swf5` | 62 | 9.2s | [25](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 233 | `object_string_coerce_swf6` | 68 | 9.2s | [25](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 234 | `parse_int` | 64 | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 235 | `placeobject_occupied_depth` | 6 | 9.1s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 236 | `point` | 175 | 9.4s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 237 | `primitive_instanceof` | 37 | 9.2s |  |
| 238 | `primitive_type_globals` | 557 | 10.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 239 | `printjob_props_swf5` | 45 | 9.2s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 240 | `printjob_props_swf6` | 45 | 9.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 241 | `printjob_props_swf7` | 45 | 9.1s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 242 | `prototype_delete` | 12 | 9.1s |  |
| 243 | `prototype_enumerate` | 5 | 9.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 244 | `prototype_properties` | 17 | 9.1s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 245 | `rectangle` | 745 | 9.8s | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 246 | `recursive_prototypes` | 0 | 9.1s |  |
| 247 | `register_class_return_value` | 16 | 9.1s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 248 | `register_globals_across_frames` | 15 | 9.1s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 249 | `register_underflow` | 26 | 9.1s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 250 | `remove_movie_clip` | 29 | 9.2s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 251 | `sandbox_type_local_file` | 1 | 9.1s |  |
| 252 | `sandbox_type_local_network` | 1 | 9.7s |  |
| 253 | `set_interval` | 27 | 9.4s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 254 | `set_variable_scope` | 58 | 9.2s |  |
| 255 | `single_frame` | 1 | 9.5s |  |
| 256 | `slash_syntax` | 14 | 9.8s | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 257 | `sound_props_swf5` | 68 | 9.3s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 258 | `sound_props_swf6` | 68 | 9.4s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 259 | `sound_start_load` | 0 | 9.3s |  |
| 260 | `stage_display_state` | 16 | 9.1s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 261 | `stage_object_enumerate` | 4 | 9.2s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 262 | `stage_object_properties` | 241 | 9.6s | [8](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 263 | `stage_object_properties_get_var` | 5 | 9.2s |  |
| 264 | `stage_object_properties_swf6` | 231 | 9.6s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 265 | `stage_property_representation` | 586 | 9.3s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 266 | `stage_scale_mode` | 39 | 9.3s | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 267 | `strictequals_swf6` | 902 | 10.8s |  |
| 268 | `strictly_equals` | 7 | 9.2s |  |
| 269 | `string_coercion` | 117 | 9.4s | [35](ruffle-tests/_investigation/complete/string_coercion.md) |
| 270 | `string_methods` | 285 | 9.8s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 271 | `string_methods_negative_args` | 240 | 9.5s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 272 | `string_methods_swfv5` | 275 | 9.8s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 273 | `string_ops_swf6` | 95 | 9.4s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 274 | `string_paths_basic` | 4 | 9.3s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 275 | `string_paths_variable_alias` | 4 | 9.1s | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 276 | `swf4_actions_bool` | 96 | 9.3s |  |
| 277 | `swf4_actions_coercion_order` | 158 | 9.4s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 278 | `swf4_bool` | 4 | 9.1s |  |
| 279 | `swf4_function_calls` | 7 | 9.1s |  |
| 280 | `swf5_encoding` | 3 | 9.0s |  |
| 281 | `swf5_no_closure` | 19 | 11.1s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 282 | `swf6_case_insensitive` | 42 | 9.0s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 283 | `swf6_string_as_bool` | 15 | 9.0s | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 284 | `swf7_case_sensitive` | 44 | 9.2s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 285 | `tab_ordering_automatic_basic` | 92 | 9.2s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 286 | `tab_ordering_automatic_order_grid` | 21 | 9.3s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 287 | `tab_ordering_children` | 208 | 9.2s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 288 | `tab_ordering_custom_basic` | 71 | 9.2s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 289 | `tab_ordering_custom_duplicate_index` | 22 | 9.3s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 290 | `tab_ordering_custom_i32_vs_u32` | 12 | 9.1s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 291 | `tab_ordering_custom_m1` | 29 | 9.1s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 292 | `tab_ordering_properties_tab_index_edge_case` | 4 | 9.4s |  |
| 293 | `tab_ordering_reverse` | 51 | 9.5s | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 294 | `target_clip_removed` | 5 | 9.5s | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 295 | `target_path` | 14 | 9.3s |  |
| 296 | `text_format` | 1146 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 297 | `text_format_display` | 21 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 298 | `text_format_font_max_length` | 2 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 299 | `text_format_rounding_swf7` | 840 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 300 | `text_format_rounding_swf8` | 840 | 9.4s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 301 | `textfield_background_color` | 11 | 9.2s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 302 | `textfield_border_color` | 11 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 303 | `textfield_maxchars` | 3 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 304 | `textfield_properties` | 44 | 9.5s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 305 | `textfield_props_swf5` | 175 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 306 | `textfield_props_swf6` | 210 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 307 | `textfield_props_swf7` | 210 | 9.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 308 | `textfield_props_swf8` | 210 | 9.7s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 309 | `textfield_text` | 7 | 9.3s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 310 | `textfield_variable` | 81 | 9.6s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 311 | `this_swf5` | 41 | 9.4s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 312 | `this_swf6` | 41 | 9.5s | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 313 | `this_swf7` | 41 | 9.6s | [42](ruffle-tests/_investigation/complete/this_swf7.md) |
| 314 | `timeline_function_def` | 7 | 9.7s |  |
| 315 | `transform` | 70 | 9.3s | [5](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 316 | `try_catch_finally` | 118 | 9.4s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 317 | `try_finally_simple` | 16 | 9.1s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 318 | `typeof` | 22 | 9.1s |  |
| 319 | `typeof_globals` | 7 | 9.1s |  |
| 320 | `uncaught_exception` | 1 | 9.1s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 321 | `uncaught_exception_bubbled` | 1 | 9.2s | [44](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 322 | `undefined_to_string_swf6` | 4 | 9.4s |  |
| 323 | `unescape` | 43 | 9.6s |  |
| 324 | `unload_clip_event` | 4 | 9.3s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 325 | `unloadmovie` | 4 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 326 | `unloadmovie_method` | 3 | 9.2s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 327 | `unloadmovienum` | 13 | 9.3s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 328 | `use_hand_cursor` | 8 | 9.2s |  |
| 329 | `variable_args` | 5 | 9.3s |  |
| 330 | `waitforframe` | 7 | 9.1s |  |
| 331 | `waitforframe2` | 16 | 10.3s |  |
| 332 | `watch` | 117 | 9.9s | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 333 | `watch_virtual_property_proto` | 2 | 9.7s | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 334 | `with` | 49 | 9.8s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 335 | `with_return` | 2 | 9.6s |  |
| 336 | `with_variable_scopes` | 43 | 9.7s | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 337 | `xml` | 15 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 338 | `xml_append_child` | 28 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 339 | `xml_append_child_with_parent` | 20 | 9.8s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 340 | `xml_attributes_read` | 4 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 341 | `xml_cdata` | 11 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 342 | `xml_child_nodes_edge_cases` | 4 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 343 | `xml_clone_expandos` | 19 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 344 | `xml_first_last_child` | 8 | 9.5s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 345 | `xml_has_child_nodes` | 3 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 346 | `xml_idmap` | 21 | 9.7s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 347 | `xml_ignore_comments` | 21 | 9.6s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 348 | `xml_ignore_white` | 34 | 9.8s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 349 | `xml_insert_before` | 20 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 350 | `xml_inspect_createmethods` | 15 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 351 | `xml_inspect_doctype` | 7 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 352 | `xml_inspect_parsexml` | 62 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 353 | `xml_inspect_xmldecl` | 7 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 354 | `xml_namespaces` | 203 | 9.4s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 355 | `xml_parent_and_child` | 5 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 356 | `xml_remove_node` | 22 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 357 | `xml_reparenting` | 14 | 9.3s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 358 | `xml_siblings` | 10 | 9.1s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 359 | `xml_to_string` | 13 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xml_to_string_comment` | 1 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 361 | `xml_unescaping` | 23 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 362 | `xmlnode_proto` | 1 | 9.2s | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**67 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `hittest_morph` | 95.7% | 67 | 70 | 3 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [20](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 4 | `selection` | 95.6% | 434 | 454 | 20 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `property_invalid_base_clip` | 94.4% | 34 | 36 | 2 |  |
| 8 | `string_paths_other` | 86.1% | 31 | 36 | 5 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 10 | `stage_object_children` | 81.9% | 68 | 83 | 15 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 11 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 12 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 13 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `tab_ordering_tabbable` | 76.6% | 36 | 47 | 11 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 16 | `clip_constructors` | 75.0% | 6 | 8 | 2 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 17 | `loadmovie_flashvars` | 75.0% | 3 | 4 | 1 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 18 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 19 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 21 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 22 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 24 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `unload` | 69.2% | 36 | 52 | 16 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 26 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 32 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_align` | 60.0% | 36 | 60 | 24 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 42 | `execution_order4` | 58.3% | 7 | 12 | 5 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 43 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 44 | `parse_float` | 58.1% | 43 | 74 | 31 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 45 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 46 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 48 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 50 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 51 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 52 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 55 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 56 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 57 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 58 | `button_keypress_vs_tab` | 50.0% | 10 | 20 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 63 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 64 | `loadmovie_var_persistence` | 50.0% | 4 | 8 | 4 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 65 | `movieclip_in_removed_button` | 50.0% | 2 | 4 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 67 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**14 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 11.1s | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 11.6s |  |
| 3 | `movieclip_init_object` | 11.4s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 4 | `movieclip_library_state_values` | 11.5s | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 12.6s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `native_objects_swf7` | 12.8s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `native_objects_swf8` | 12.7s | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `netstream_play_flv_screen` | 27.1s |  |
| 9 | `on_construct` | 11.2s | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 10 | `register_and_init_order` | 11.6s | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 11 | `register_class_with_sound` | 11.2s | [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 12 | `resolve_different_root` | 12.3s |  |
| 13 | `string_paths_timer` | 11.2s |  |
| 14 | `timer_run_actions` | 11.5s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 32.3s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 32.4s | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 19.5s | [43](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**239 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [6](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `hittest_morph` | 95.7% | 67/70 | 70 | 70 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [20](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) |
| 4 | `selection` | 95.6% | 434/454 | 454 | 454 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `property_invalid_base_clip` | 94.4% | 34/36 | 36 | 36 |  |
| 8 | `string_paths_other` | 86.1% | 31/36 | 36 | 36 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 10 | `stage_object_children` | 81.9% | 68/83 | 83 | 83 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 11 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 12 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 13 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `tab_ordering_tabbable` | 76.6% | 36/47 | 47 | 47 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 16 | `clip_constructors` | 75.0% | 6/8 | 8 | 8 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 17 | `loadmovie_flashvars` | 75.0% | 3/4 | 4 | 4 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 18 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 19 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 21 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 22 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 23 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 24 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `unload` | 69.2% | 36/52 | 52 | 52 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 26 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 32 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 42 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 43 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 44 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [28](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 45 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 46 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 48 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 50 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 51 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 52 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 53 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 55 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 56 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 57 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 58 | `button_keypress_vs_tab` | 50.0% | 10/20 | 20 | 20 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 63 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 64 | `loadmovie_var_persistence` | 50.0% | 4/8 | 5 | 8 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 65 | `movieclip_in_removed_button` | 50.0% | 2/4 | 4 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 67 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 68 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 70 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 71 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 72 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 73 | `mouse_pos` | 43.8% | 291/665 | 656 | 665 | [21](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 74 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 75 | `mouse_pos_with_scale_factor` | 42.7% | 111/260 | 251 | 260 | [21](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 76 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 77 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 78 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 79 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 80 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 81 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 82 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 83 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 87 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 88 | `init_object_order` | 33.3% | 5/15 | 6 | 15 | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 89 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 90 | `place_and_lookup` | 33.3% | 10/30 | 30 | 30 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 91 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 92 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 94 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 95 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 96 | `swf6_to_5_cross_call` | 31.0% | 9/29 | 11 | 29 | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 97 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 98 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 99 | `goto_frame2` | 29.5% | 13/44 | 19 | 44 | [10](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 100 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 101 | `default_names` | 28.8% | 15/52 | 48 | 52 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 102 | `swf5_to_6_cross_call` | 27.6% | 8/29 | 11 | 29 | [37](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 103 | `tell_target` | 26.3% | 10/38 | 38 | 37 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 104 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 105 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 106 | `button_keypress_vs_textinput` | 25.0% | 1/4 | 2 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 107 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 108 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 109 | `mouse_events_visible_enabled` | 25.0% | 3/12 | 10 | 12 | [21](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 110 | `text_blocks_clicks` | 25.0% | 1/4 | 2 | 4 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 111 | `textsnapshot_props_swf5` | 25.0% | 14/56 | 38 | 56 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `button_keypress_vs_press` | 24.0% | 6/25 | 24 | 25 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 113 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `focus_mouse` | 22.2% | 10/45 | 30 | 45 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 115 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 116 | `this_scoping` | 20.8% | 11/53 | 53 | 52 | [41](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 117 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 118 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 119 | `tell_target_invalid` | 20.0% | 2/10 | 10 | 6 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 120 | `tell_target_invalid_swf6` | 20.0% | 2/10 | 10 | 5 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 121 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 122 | `register_class_swf6` | 18.9% | 7/37 | 10 | 37 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 123 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
| 124 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 125 | `tab_ordering_events` | 18.0% | 27/150 | 118 | 150 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 126 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 127 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 128 | `root_global_parent` | 16.7% | 1/6 | 6 | 6 |  |
| 129 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 130 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 131 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 6 | 13 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 132 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 6 | 13 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 133 | `button_key_events` | 14.3% | 2/14 | 9 | 14 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 134 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 135 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 136 | `mcl_events_swf_version` | 13.8% | 32/232 | 37 | 232 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) |
| 137 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 138 | `tab_ordering_movieclip_enabled_default` | 13.6% | 63/462 | 432 | 462 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 139 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [26](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 140 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 141 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 142 | `textsnapshot_props_swf6` | 12.5% | 7/56 | 38 | 56 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 143 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 144 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 145 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 146 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 147 | `path_string` | 10.9% | 38/350 | 350 | 322 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 148 | `register_class` | 10.6% | 7/66 | 52 | 66 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [30](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 149 | `focus_keyboard_press` | 10.1% | 15/148 | 148 | 60 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 150 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 151 | `coerce_to_object_monkeypatch` | 7.8% | 10/129 | 80 | 129 |  |
| 152 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 153 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 154 | `tab_ordering_events_mouse` | 7.7% | 5/65 | 47 | 65 | [38](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 155 | `define_local` | 7.4% | 2/27 | 23 | 27 | [46](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 156 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 157 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 158 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 159 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 160 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 161 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 162 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 163 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 164 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 165 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 166 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 167 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 168 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 169 | `movieclip_invalid_get_bounds_2` | 4.0% | 3/75 | 3 | 75 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 170 | `movieclip_invalid_get_bounds_1` | 2.7% | 2/75 | 3 | 75 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 171 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [17](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 172 | `button_key_events_special` | 2.2% | 1/45 | 38 | 45 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 173 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [27](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 174 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 175 | `netconnection_send_remote` | 2.0% | 1/50 | 1 | 50 |  |
| 176 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 177 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 178 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 179 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 180 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 181 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 182 | `global_proto_decls` | 0.4% | 16/4497 | 572 | 4497 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 183 | `localconnection` | 0.3% | 2/579 | 4 | 579 |  |
| 184 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 185 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [11](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 186 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 187 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 188 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [24](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 189 | `button_keypress` | 0.0% | 0/3 | 2 | 3 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 190 | `click_block` | 0.0% | 0/5 | 0 | 5 | [21](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) |
| 191 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 192 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 193 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 194 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 195 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 196 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [32](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 197 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 198 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 199 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 200 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 201 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 202 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 203 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 204 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 205 | `focus_mouse_rollout` | 0.0% | 0/4 | 0 | 4 | [9](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 206 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 207 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 208 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 209 | `global_proto_decls_delete` | 0.0% | 0/4158 | 216 | 4158 | [12](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 210 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [13](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 211 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 212 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 213 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) |
| 214 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) [31](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) |
| 215 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 216 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 217 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 218 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 219 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 220 | `object_resolve` | 0.0% | 0/38 | 23 | 38 | [29](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 221 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 222 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [16](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) |
| 223 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 224 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 225 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 226 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 227 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 228 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 229 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [36](ruffle-tests/_investigation/complete/STRING_PLAN.md) [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 230 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 231 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 232 | `target_clip_swf6` | 0.0% | 0/2 | 0 | 2 | [39](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 233 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 1 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 234 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [40](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 235 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [22](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 236 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 237 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 238 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 239 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [47](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 6 | 8 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 5 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 6 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 7 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/incomplete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 8 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 9 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 6 | 2 | 4 |
| 10 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 3 | 1 |
| 11 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 12 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 16 | 15 |
| 13 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 4 | 13 |
| 14 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 15 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 16 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_PLAN.md) | 49 | 22 | 27 |
| 17 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 18 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/incomplete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 19 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 20 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/incomplete/MORPH_INTERPOLATION_PLAN.md) | 1 | 0 | 1 |
| 21 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/incomplete/MOUSE_EVENTS_PLAN.md) | 5 | 1 | 4 |
| 22 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 20 | 38 |
| 23 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 24 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 25 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 26 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 27 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
| 28 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 29 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 9 | 3 |
| 30 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 7 | 8 |
| 31 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/incomplete/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 32 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 33 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 6 | 3 |
| 34 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 6 | 1 |
| 35 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 36 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 6 | 7 |
| 37 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/incomplete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 38 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 10 | 6 |
| 39 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 4 | 15 |
| 40 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 29 | 41 |
| 41 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 42 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 43 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 44 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 45 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 9 | 3 |
| 46 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 47 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 145 | 85 |
