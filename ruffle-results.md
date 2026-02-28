# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-28 05:09 UTC

**Git SHA**: `eb4a18cc7c`

**Run Duration**: 109m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **400** (64.6%) |
| Failing | 219 |
| Total expected lines | 91470 |
| Matching lines | 60116 (65.7%) |
| Mismatched lines | 31354 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 207 | 94.5% |
| Runtime Segfault | 8 | 3.7% |
| Runtime Error | 2 | 0.9% |
| Compile Fail | 1 | 0.5% |
| Timeout | 1 | 0.5% |

## Passing Tests

**400 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.9s |  |
| 2 | `action_to_integer` | 28 | 10.2s |  |
| 3 | `add` | 28 | 10.2s |  |
| 4 | `add2` | 354 | 10.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 10.4s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 10.3s |  |
| 7 | `add_swf5` | 28 | 10.3s |  |
| 8 | `arguments` | 127 | 10.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 10.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 10.3s |  |
| 11 | `array_constructor` | 30 | 10.3s |  |
| 12 | `array_enumerate` | 4 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 11.0s |  |
| 14 | `array_properties` | 36 | 10.9s |  |
| 15 | `array_prototyping` | 12 | 10.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 10.5s |  |
| 17 | `array_sort` | 161 | 10.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 10.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 10.4s |  |
| 20 | `array_trivial` | 209 | 10.2s |  |
| 21 | `as1_constructor_v6` | 35 | 10.1s |  |
| 22 | `as1_constructor_v7` | 35 | 11.6s |  |
| 23 | `as2_oop` | 13 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 10.4s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 10.2s |  |
| 28 | `as_set_prop_flags` | 79 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 10.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 10.2s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 10.2s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 10.2s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 10.2s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 10.2s |  |
| 35 | `as_transformed_flag` | 20 | 10.2s |  |
| 36 | `attach_movie` | 59 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 38 | `bad_swf_tag_past_eof` | 0 | 9.9s |  |
| 39 | `bitand` | 1058 | 12.4s |  |
| 40 | `bitmap_data_colortransform` | 0 | 10.2s |  |
| 41 | `bitmap_data_fillrect` | 0 | 10.1s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 9.9s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 9.9s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 10.8s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 10.4s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.0s |  |
| 47 | `bitor` | 1058 | 12.3s |  |
| 48 | `biturshift` | 14 | 9.8s |  |
| 49 | `biturshift_swf8` | 14 | 10.1s |  |
| 50 | `bitxor` | 1058 | 12.6s |  |
| 51 | `boxed_primitives` | 24 | 10.1s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_key_events` | 14 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events_special` | 45 | 10.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_keypress` | 3 | 10.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress_vs_press` | 25 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_tab` | 20 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_order` | 2 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_properties_special_cases` | 22 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v5` | 18 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_v6` | 18 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 9.9s |  |
| 64 | `capabilities_resolution` | 8 | 10.0s |  |
| 65 | `catch_references_registers` | 2 | 10.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `click_block` | 5 | 10.1s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 67 | `clip_constructors` | 8 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 68 | `clip_events` | 19 | 10.5s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 69 | `clone_sprite_types` | 24 | 10.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `closure_scope` | 7 | 10.2s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 71 | `color` | 57 | 10.3s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `color_transform` | 48 | 10.1s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `conflicting_instance_names` | 23 | 10.1s |  |
| 74 | `constructor_function` | 2 | 9.9s |  |
| 75 | `context_menu` | 39 | 10.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `context_menu_item` | 41 | 10.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 77 | `create_empty_movie_clip` | 3 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 78 | `define_function2` | 8 | 10.0s |  |
| 79 | `define_function2_preload` | 13 | 10.0s |  |
| 80 | `define_function2_preload_order` | 4 | 10.2s |  |
| 81 | `define_function_case_sensitive` | 2 | 9.9s |  |
| 82 | `delete` | 3 | 10.0s |  |
| 83 | `display_object_properties` | 2 | 9.9s |  |
| 84 | `divide_swf4` | 107 | 10.1s |  |
| 85 | `do_init_action` | 3 | 10.1s |  |
| 86 | `drag_drop` | 10 | 10.4s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 87 | `drag_over_from_outside` | 1 | 10.5s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 88 | `drag_over_without_startdrag` | 1 | 10.4s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 89 | `duplicate_movie_clip` | 20 | 10.4s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 90 | `edittext_antialiastype` | 296 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_autosize_setter` | 20 | 11.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_default_format` | 221 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_default_format_empty` | 95 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_default_format_font_style` | 335 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_align_swf7` | 52 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_align_swf8` | 52 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_entity` | 4 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_newline_stripping` | 64 | 14.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_password` | 5 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_password_copy` | 4 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_paste_empty` | 2 | 10.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_restrict_paste` | 5 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_width_height` | 103 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `empty_movieclip_can_attach_movies` | 11 | 12.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 105 | `enumerate` | 64 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 106 | `equals` | 32 | 10.1s |  |
| 107 | `equals2_swf5` | 926 | 11.8s |  |
| 108 | `equals2_swf6` | 926 | 12.0s |  |
| 109 | `equals2_swf7` | 926 | 12.0s |  |
| 110 | `equals_swf4` | 665 | 11.0s |  |
| 111 | `equals_swf4_alt` | 32 | 10.4s |  |
| 112 | `equals_swf5` | 32 | 10.3s |  |
| 113 | `error` | 58 | 10.4s |  |
| 114 | `escape` | 14 | 10.1s |  |
| 115 | `execution_order1` | 5 | 10.3s |  |
| 116 | `execution_order2` | 7 | 10.3s |  |
| 117 | `execution_order3` | 4 | 10.2s |  |
| 118 | `execution_order4` | 12 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 119 | `export_assets` | 3 | 10.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 120 | `extends_chain` | 134 | 10.5s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 121 | `extends_native_type` | 11 | 10.2s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 122 | `focus_root_movie` | 2 | 10.0s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 123 | `focusrect_focuslost` | 4 | 9.9s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 124 | `focusrect_mouse_swf8` | 0 | 9.8s |  |
| 125 | `focusrect_mouse_swf9` | 0 | 10.2s |  |
| 126 | `focusrect_swf5` | 6 | 10.1s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 127 | `focusrect_swf6` | 42 | 10.0s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 128 | `form_loader_encoding_1` | 1 | 9.9s |  |
| 129 | `function_suppress_and_preload` | 28 | 10.0s |  |
| 130 | `get_variable_in_scope` | 29 | 10.1s |  |
| 131 | `getproperty` | 28 | 9.9s |  |
| 132 | `getproperty_swf4` | 28 | 10.8s |  |
| 133 | `getproperty_swf5` | 28 | 10.4s |  |
| 134 | `global_array` | 3 | 10.4s |  |
| 135 | `global_is_bare` | 7 | 10.4s |  |
| 136 | `globals_swf5` | 304 | 10.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 137 | `globals_swf6` | 304 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 138 | `globals_swf7` | 304 | 10.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 139 | `globals_swf8` | 304 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 140 | `goto_advance1` | 6 | 10.4s |  |
| 141 | `goto_advance2` | 2 | 10.4s |  |
| 142 | `goto_both_ways1` | 3 | 10.3s |  |
| 143 | `goto_both_ways2` | 3 | 10.5s |  |
| 144 | `goto_execution_order` | 2 | 10.4s |  |
| 145 | `goto_execution_order2` | 2 | 10.5s |  |
| 146 | `goto_frame` | 12 | 12.2s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 147 | `goto_frame2` | 44 | 10.7s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 148 | `goto_frame_number` | 3 | 10.2s |  |
| 149 | `goto_label` | 17 | 10.3s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 150 | `goto_methods` | 40 | 10.2s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 151 | `goto_rewind1` | 1 | 10.1s |  |
| 152 | `goto_rewind2` | 3 | 10.1s |  |
| 153 | `goto_rewind3` | 2 | 10.1s |  |
| 154 | `greater_swf6` | 1175 | 12.1s |  |
| 155 | `greater_swf7` | 1175 | 12.1s |  |
| 156 | `greaterthan_swf5` | 1 | 10.1s |  |
| 157 | `greaterthan_swf8` | 1 | 10.1s |  |
| 158 | `has_own_property` | 32 | 10.1s |  |
| 159 | `hittest_lockroot` | 15 | 10.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 160 | `hittest_morph` | 70 | 10.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 161 | `hittest_winding_rule` | 12 | 10.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 162 | `infinite_recursion_function` | 4 | 10.1s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 163 | `infinite_recursion_function_in_setter` | 131 | 10.1s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 164 | `infinite_recursion_virtual_property` | 67 | 10.1s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 165 | `init_array_invalid` | 4 | 10.1s |  |
| 166 | `init_object_invalid` | 4 | 10.6s |  |
| 167 | `init_object_order` | 15 | 10.7s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 168 | `is_finite` | 49 | 10.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 169 | `is_finite_swf6` | 49 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 170 | `is_prototype_of` | 89 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 171 | `issue_1086` | 1 | 10.3s |  |
| 172 | `issue_1671` | 0 | 10.1s |  |
| 173 | `issue_1906` | 4 | 10.2s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 174 | `issue_2166` | 9 | 10.5s |  |
| 175 | `issue_3446` | 1 | 10.2s |  |
| 176 | `issue_3522` | 2 | 10.1s |  |
| 177 | `issue_4377` | 2 | 10.1s |  |
| 178 | `issue_710` | 4 | 10.1s |  |
| 179 | `issue_768` | 3 | 10.2s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 180 | `issue_9327` | 2 | 10.1s |  |
| 181 | `issue_9885` | 2 | 10.1s |  |
| 182 | `key_isToggled` | 9 | 10.1s |  |
| 183 | `lessthan` | 41 | 10.2s |  |
| 184 | `lessthan2_swf5` | 1226 | 12.7s |  |
| 185 | `lessthan2_swf6` | 1226 | 12.4s |  |
| 186 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 187 | `lessthan_swf4` | 902 | 11.4s |  |
| 188 | `lessthan_swf4_alt` | 41 | 10.1s |  |
| 189 | `lessthan_swf5` | 41 | 10.1s |  |
| 190 | `loadmovie` | 2 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 191 | `loadmovie_fail` | 2 | 10.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 192 | `loadmovie_flashvars` | 4 | 10.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 193 | `loadmovie_method` | 2 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 194 | `loadmovie_replace_root` | 5 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 195 | `loadmovienum` | 3 | 9.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 196 | `loadvariables` | 2 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 197 | `loadvariables2` | 8 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 198 | `loadvariablesnum` | 2 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 199 | `local_to_global` | 49 | 10.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 200 | `localconnection_properties` | 8 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 201 | `lock_root` | 1 | 10.2s |  |
| 202 | `logical_ops_swf4` | 90 | 10.2s |  |
| 203 | `logical_ops_swf8` | 108 | 10.2s |  |
| 204 | `looping` | 6 | 10.2s |  |
| 205 | `mask_reapply` | 0 | 10.2s |  |
| 206 | `mask_with_drawing` | 0 | 10.2s |  |
| 207 | `math_min_max` | 101 | 10.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 208 | `math_swf6` | 530 | 10.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 209 | `math_swf7` | 530 | 10.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 210 | `math_swf8` | 530 | 10.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 211 | `matrix` | 171 | 10.5s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 212 | `mcl_as_broadcaster` | 12 | 10.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 213 | `mcl_getprogress` | 30 | 10.5s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 214 | `mcl_loadclip` | 149 | 10.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 215 | `mcl_loadclip_properties` | 6 | 10.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 216 | `mcl_mislabeled_target` | 6 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 217 | `mcl_target_gif87a` | 6 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 218 | `mcl_target_gif89a` | 6 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 219 | `mcl_target_jpg` | 6 | 10.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 220 | `mcl_target_png` | 6 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 221 | `mcl_unloadclip` | 5 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 222 | `mouse_events` | 8 | 10.0s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 223 | `mouse_events_visible_enabled` | 12 | 10.1s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 224 | `mouse_hover_events_while_dragging` | 1 | 10.0s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 225 | `mouse_listeners` | 67 | 9.9s |  |
| 226 | `mouse_pos` | 665 | 9.9s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 227 | `mouse_pos_with_scale_factor` | 260 | 9.9s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 228 | `mouse_wheel_enabled` | 2 | 9.9s |  |
| 229 | `movieclip_begin_gradient_fill` | 0 | 10.4s |  |
| 230 | `movieclip_blend_mode_property` | 35 | 13.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 231 | `movieclip_default_state` | 69 | 11.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 232 | `movieclip_depth_methods` | 98 | 11.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 233 | `movieclip_focusenabled` | 99 | 11.0s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 234 | `movieclip_get_instance_at_depth` | 28 | 11.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 235 | `movieclip_hittest` | 92 | 10.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 236 | `movieclip_in_removed_button` | 4 | 10.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 237 | `movieclip_init_object` | 5 | 10.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 238 | `movieclip_line_gradient_style` | 0 | 10.6s |  |
| 239 | `movieclip_name_from_timeline` | 13 | 10.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 240 | `movieclip_prototype_extension` | 5 | 9.9s |  |
| 241 | `moviecliploader_flashvars` | 4 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 242 | `mutable_this` | 18 | 10.0s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 243 | `named_shapes` | 14 | 9.9s |  |
| 244 | `nan_scale` | 9 | 10.0s |  |
| 245 | `nested_textfields_in_buttons` | 0 | 9.9s |  |
| 246 | `new_method_wrap` | 4 | 10.2s |  |
| 247 | `new_object_enumerate` | 7 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 248 | `new_object_wrap` | 4 | 10.1s |  |
| 249 | `o` | 3 | 10.1s |  |
| 250 | `object_constructor` | 33 | 10.1s |  |
| 251 | `object_function` | 32 | 10.1s |  |
| 252 | `object_properties` | 31 | 10.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 253 | `object_prototypes` | 74 | 10.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 254 | `object_string_coerce_swf5` | 62 | 10.2s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 255 | `object_string_coerce_swf6` | 68 | 10.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 256 | `on_construct` | 25 | 10.2s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 257 | `parse_float` | 74 | 10.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 258 | `parse_int` | 64 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 259 | `path_string` | 322 | 10.4s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 260 | `place_and_lookup` | 30 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 261 | `placeobject_occupied_depth` | 6 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 262 | `point` | 175 | 10.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 263 | `primitive_instanceof` | 37 | 10.2s |  |
| 264 | `primitive_type_globals` | 557 | 11.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 265 | `printjob_props_swf5` | 45 | 10.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 266 | `printjob_props_swf6` | 45 | 10.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 267 | `printjob_props_swf7` | 45 | 10.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 268 | `property_invalid_base_clip` | 36 | 10.1s |  |
| 269 | `prototype_delete` | 12 | 10.0s |  |
| 270 | `prototype_enumerate` | 5 | 10.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 271 | `prototype_properties` | 17 | 10.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 272 | `rectangle` | 745 | 10.9s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 273 | `recursive_prototypes` | 0 | 10.0s |  |
| 274 | `register_class_return_value` | 16 | 10.2s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 275 | `register_globals_across_frames` | 15 | 10.1s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 276 | `register_underflow` | 26 | 10.2s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 277 | `remove_movie_clip` | 29 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 278 | `rewind_depth` | 30 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 279 | `sandbox_type_local_file` | 1 | 10.1s |  |
| 280 | `sandbox_type_local_network` | 1 | 10.2s |  |
| 281 | `selection` | 454 | 10.4s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 282 | `set_interval` | 27 | 10.4s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 283 | `set_variable_scope` | 58 | 10.3s |  |
| 284 | `single_frame` | 1 | 10.2s |  |
| 285 | `slash_syntax` | 14 | 10.2s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 286 | `sound_props_swf5` | 68 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 287 | `sound_props_swf6` | 68 | 10.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 288 | `sound_start_load` | 0 | 10.1s |  |
| 289 | `stage_display_state` | 16 | 10.1s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 290 | `stage_object_children` | 83 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 291 | `stage_object_enumerate` | 4 | 10.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 292 | `stage_object_properties` | 241 | 10.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 293 | `stage_object_properties_get_var` | 5 | 10.0s |  |
| 294 | `stage_object_properties_swf6` | 231 | 10.4s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 295 | `stage_property_representation` | 586 | 10.1s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 296 | `stage_scale_mode` | 39 | 10.1s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 297 | `strictequals_swf6` | 902 | 11.6s |  |
| 298 | `strictly_equals` | 7 | 10.1s |  |
| 299 | `string_coercion` | 117 | 10.3s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 300 | `string_methods` | 285 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 301 | `string_methods_negative_args` | 240 | 10.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 302 | `string_methods_swfv5` | 275 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 303 | `string_ops_swf6` | 95 | 10.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 304 | `string_paths_basic` | 4 | 10.0s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 305 | `string_paths_hidden` | 54 | 9.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 306 | `string_paths_variable_alias` | 4 | 10.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 307 | `swf4_actions_bool` | 96 | 10.1s |  |
| 308 | `swf4_actions_coercion_order` | 158 | 10.0s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 309 | `swf4_bool` | 4 | 9.9s |  |
| 310 | `swf4_function_calls` | 7 | 9.9s |  |
| 311 | `swf5_encoding` | 3 | 9.8s |  |
| 312 | `swf5_no_closure` | 19 | 11.1s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 313 | `swf6_case_insensitive` | 42 | 10.4s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 314 | `swf6_string_as_bool` | 15 | 10.5s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 315 | `swf7_case_sensitive` | 44 | 10.3s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 316 | `tab_ordering_automatic_basic` | 92 | 10.3s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 317 | `tab_ordering_automatic_order_grid` | 21 | 10.4s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 318 | `tab_ordering_children` | 208 | 10.5s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 319 | `tab_ordering_custom_basic` | 71 | 10.2s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 320 | `tab_ordering_custom_duplicate_index` | 22 | 10.2s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 321 | `tab_ordering_custom_i32_vs_u32` | 12 | 10.2s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 322 | `tab_ordering_custom_m1` | 29 | 10.2s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 323 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.4s |  |
| 324 | `tab_ordering_reverse` | 51 | 10.5s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 325 | `target_clip_removed` | 5 | 10.5s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 326 | `target_clip_swf5` | 2 | 10.4s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 327 | `target_clip_swf6` | 2 | 10.4s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 328 | `target_path` | 14 | 10.4s |  |
| 329 | `tell_target` | 37 | 10.5s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 330 | `tell_target_invalid` | 6 | 10.5s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 331 | `tell_target_invalid_swf6` | 5 | 10.4s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 332 | `text_format` | 1146 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 333 | `text_format_display` | 21 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 334 | `text_format_font_max_length` | 2 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 335 | `text_format_rounding_swf7` | 840 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 336 | `text_format_rounding_swf8` | 840 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 337 | `textfield_background_color` | 11 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 338 | `textfield_border_color` | 11 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 339 | `textfield_maxchars` | 3 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 340 | `textfield_properties` | 44 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 341 | `textfield_props_swf5` | 175 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 342 | `textfield_props_swf6` | 210 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 343 | `textfield_props_swf7` | 210 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 344 | `textfield_props_swf8` | 210 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 345 | `textfield_text` | 7 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 346 | `textfield_variable` | 81 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 347 | `textsnapshot_props_swf6` | 56 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 348 | `this_scoping` | 52 | 10.6s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 349 | `this_swf5` | 41 | 10.6s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 350 | `this_swf6` | 41 | 10.5s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 351 | `this_swf7` | 41 | 10.4s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 352 | `timeline_function_def` | 7 | 10.7s |  |
| 353 | `transform` | 70 | 10.2s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 354 | `try_catch_finally` | 118 | 10.2s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 355 | `try_finally_simple` | 16 | 10.1s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 356 | `typeof` | 22 | 10.1s |  |
| 357 | `typeof_globals` | 7 | 10.0s |  |
| 358 | `uncaught_exception` | 1 | 10.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 359 | `uncaught_exception_bubbled` | 1 | 10.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 360 | `undefined_to_string_swf6` | 4 | 10.0s |  |
| 361 | `unescape` | 43 | 10.0s |  |
| 362 | `unload_clip_event` | 4 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 363 | `unloadmovie` | 4 | 10.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 364 | `unloadmovie_method` | 3 | 10.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 365 | `unloadmovienum` | 13 | 10.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 366 | `use_hand_cursor` | 8 | 10.0s |  |
| 367 | `variable_args` | 5 | 10.1s |  |
| 368 | `waitforframe` | 7 | 10.1s |  |
| 369 | `waitforframe2` | 16 | 10.6s |  |
| 370 | `watch` | 117 | 10.6s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 371 | `watch_virtual_property_proto` | 2 | 10.2s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 372 | `with` | 49 | 10.3s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 373 | `with_return` | 2 | 10.2s |  |
| 374 | `with_variable_scopes` | 43 | 10.2s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 375 | `xml` | 15 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_append_child` | 28 | 10.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_append_child_with_parent` | 20 | 10.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_attributes_read` | 4 | 10.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xml_cdata` | 11 | 10.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_child_nodes_edge_cases` | 4 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_clone_expandos` | 19 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_first_last_child` | 8 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_has_child_nodes` | 3 | 10.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_idmap` | 21 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_ignore_comments` | 21 | 10.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_ignore_white` | 34 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xml_insert_before` | 20 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 388 | `xml_inspect_createmethods` | 15 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 389 | `xml_inspect_doctype` | 7 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 390 | `xml_inspect_parsexml` | 62 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 391 | `xml_inspect_xmldecl` | 7 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_namespaces` | 203 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xml_parent_and_child` | 5 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xml_remove_node` | 22 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 395 | `xml_reparenting` | 14 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 396 | `xml_siblings` | 10 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 397 | `xml_to_string` | 13 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 398 | `xml_to_string_comment` | 1 | 10.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 399 | `xml_unescaping` | 23 | 10.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xmlnode_proto` | 1 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**61 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 7 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 8 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 9 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 10 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `tab_ordering_tabbable` | 76.6% | 36 | 47 | 11 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 13 | `button_keypress_vs_textinput` | 75.0% | 3 | 4 | 1 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 14 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 15 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 16 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 18 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 19 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 20 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 22 | `textsnapshot_props_swf5` | 67.9% | 38 | 56 | 18 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 26 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `register_and_init_order` | 61.5% | 142 | 231 | 89 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 29 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 38 | `edittext_programmatic_focus` | 58.3% | 7 | 12 | 5 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 40 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 41 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 43 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 45 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 46 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 49 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 50 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 51 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 52 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 53 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 54 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 58 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 59 | `loadmovie_var_persistence` | 50.0% | 4 | 8 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 60 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 61 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**8 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 11.9s |  |
| 3 | `native_objects_swf6` | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf7` | 12.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `native_objects_swf8` | 12.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `netstream_play_flv_screen` | 25.1s |  |
| 7 | `string_paths_timer` | 12.0s |  |
| 8 | `timer_run_actions` | 11.8s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 34.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 20.5s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**207 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 7 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 8 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 9 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 10 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `tab_ordering_tabbable` | 76.6% | 36/47 | 47 | 47 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 13 | `button_keypress_vs_textinput` | 75.0% | 3/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 14 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 15 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 16 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 18 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 19 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 20 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 22 | `textsnapshot_props_swf5` | 67.9% | 38/56 | 56 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 26 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `register_and_init_order` | 61.5% | 142/231 | 194 | 231 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 29 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 38 | `edittext_programmatic_focus` | 58.3% | 7/12 | 12 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 40 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 41 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 43 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 45 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 46 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 47 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 49 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 50 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 51 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 52 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 53 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 54 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 58 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 59 | `loadmovie_var_persistence` | 50.0% | 4/8 | 5 | 8 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 60 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 61 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 64 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 65 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 66 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `register_class_with_sound` | 45.5% | 5/11 | 11 | 11 | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 68 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 69 | `focus_mouse` | 44.4% | 20/45 | 38 | 45 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 70 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 71 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 72 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 73 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 74 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 75 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 76 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 77 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 78 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 79 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 80 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 81 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 82 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 83 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 86 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 87 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 88 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 89 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 90 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 92 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 93 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 94 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 95 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 96 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 97 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 98 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 99 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 100 | `register_class` | 24.2% | 16/66 | 50 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 101 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 102 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 104 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 105 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 106 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 107 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
| 108 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 109 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 110 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 111 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 112 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 113 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 114 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 115 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 116 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 117 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 118 | `mcl_events_swf_version` | 13.8% | 32/232 | 37 | 232 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 119 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 120 | `tab_ordering_movieclip_enabled_default` | 13.6% | 63/462 | 432 | 462 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 121 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 122 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 123 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 124 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 125 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 126 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 128 | `tab_ordering_events` | 9.3% | 14/150 | 71 | 150 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 129 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 130 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 131 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 132 | `tab_ordering_events_mouse` | 7.7% | 5/65 | 48 | 65 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 133 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 134 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 135 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 136 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 137 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 138 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 139 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 140 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 141 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 142 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 143 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 144 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 145 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 146 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 147 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 148 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 149 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 150 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 151 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 152 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 153 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 154 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 155 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 156 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 157 | `focus_keyboard_press` | 0.7% | 1/138 | 138 | 60 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 158 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 159 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 160 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 161 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 162 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 163 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 164 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 165 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 166 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 167 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 168 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 169 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 170 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 171 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 172 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 173 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 174 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 175 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 177 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 178 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 179 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 180 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 181 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 182 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 183 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 184 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 185 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 186 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 187 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 188 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 189 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 190 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 191 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 192 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 193 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 194 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 195 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 196 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 197 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 198 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 199 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 200 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 201 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 202 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 203 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 204 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 205 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 206 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 207 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 12 | 2 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 1 | 3 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 3 | 4 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 19 | 12 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 23 | 26 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 27 | 31 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 10 | 5 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 7 | 2 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 7 | 6 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 10 | 6 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 11 | 8 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 30 | 40 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 9 | 3 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 149 | 81 |
