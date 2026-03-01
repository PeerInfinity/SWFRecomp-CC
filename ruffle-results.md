# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-01 01:21 UTC

**Git SHA**: `8fb2a2d847`

**Run Duration**: 112m 36s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **408** (65.9%) |
| Failing | 211 |
| Total expected lines | 91470 |
| Matching lines | 61253 (67.0%) |
| Mismatched lines | 30217 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 200 | 94.8% |
| Runtime Segfault | 5 | 2.4% |
| Runtime Error | 4 | 1.9% |
| Compile Fail | 1 | 0.5% |
| Timeout | 1 | 0.5% |

## Passing Tests

**408 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.9s |  |
| 2 | `action_to_integer` | 28 | 10.5s |  |
| 3 | `add` | 28 | 10.4s |  |
| 4 | `add2` | 354 | 10.6s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 10.4s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 10.5s |  |
| 7 | `add_swf5` | 28 | 10.5s |  |
| 8 | `arguments` | 127 | 10.4s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 10.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 10.4s |  |
| 11 | `array_constructor` | 30 | 10.4s |  |
| 12 | `array_enumerate` | 4 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 10.4s |  |
| 14 | `array_properties` | 36 | 10.3s |  |
| 15 | `array_prototyping` | 12 | 10.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 10.4s |  |
| 17 | `array_sort` | 161 | 11.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 10.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 10.6s |  |
| 20 | `array_trivial` | 209 | 10.7s |  |
| 21 | `as1_constructor_v6` | 35 | 10.5s |  |
| 22 | `as1_constructor_v7` | 35 | 12.0s |  |
| 23 | `as2_oop` | 13 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 10.7s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 10.4s |  |
| 28 | `as_set_prop_flags` | 79 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 10.3s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 10.4s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 10.3s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 10.3s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 10.3s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 10.3s |  |
| 35 | `as_transformed_flag` | 20 | 10.3s |  |
| 36 | `attach_movie` | 59 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `bad_swf_tag_past_eof` | 0 | 10.4s |  |
| 39 | `bitand` | 1058 | 12.9s |  |
| 40 | `bitmap_data_colortransform` | 0 | 10.6s |  |
| 41 | `bitmap_data_fillrect` | 0 | 10.5s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 10.3s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 10.3s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 11.2s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 10.8s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.4s |  |
| 47 | `bitor` | 1058 | 13.0s |  |
| 48 | `biturshift` | 14 | 10.3s |  |
| 49 | `biturshift_swf8` | 14 | 10.6s |  |
| 50 | `bitxor` | 1058 | 13.1s |  |
| 51 | `boxed_primitives` | 24 | 10.6s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 10.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 10.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_key_events` | 14 | 10.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events_special` | 45 | 11.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_keypress` | 3 | 10.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress_vs_press` | 25 | 10.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_tab` | 20 | 10.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_order` | 2 | 10.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_properties_special_cases` | 22 | 10.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v5` | 18 | 10.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_v6` | 18 | 10.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 10.3s |  |
| 64 | `capabilities_resolution` | 8 | 10.3s |  |
| 65 | `catch_references_registers` | 2 | 10.3s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `click_block` | 5 | 10.4s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 67 | `clip_constructors` | 8 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 68 | `clip_events` | 19 | 10.9s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 69 | `clone_sprite_types` | 24 | 10.4s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 70 | `closure_scope` | 7 | 10.5s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 71 | `color` | 57 | 10.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `color_transform` | 48 | 10.5s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `conflicting_instance_names` | 23 | 10.5s |  |
| 74 | `constructor_function` | 2 | 10.4s |  |
| 75 | `context_menu` | 39 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `context_menu_item` | 41 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 77 | `create_empty_movie_clip` | 3 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `define_function2` | 8 | 10.4s |  |
| 79 | `define_function2_preload` | 13 | 10.4s |  |
| 80 | `define_function2_preload_order` | 4 | 11.2s |  |
| 81 | `define_function_case_sensitive` | 2 | 11.2s |  |
| 82 | `delete` | 3 | 11.2s |  |
| 83 | `display_object_properties` | 2 | 10.8s |  |
| 84 | `divide_swf4` | 107 | 10.8s |  |
| 85 | `do_init_action` | 3 | 10.6s |  |
| 86 | `drag_drop` | 10 | 10.8s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 87 | `drag_over_from_outside` | 1 | 10.7s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 88 | `drag_over_without_startdrag` | 1 | 10.8s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 89 | `duplicate_movie_clip` | 20 | 10.8s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 90 | `edittext_antialiastype` | 296 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_autosize_setter` | 20 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_default_format` | 221 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_default_format_empty` | 95 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_default_format_font_style` | 335 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_html_align_swf7` | 52 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_html_align_swf8` | 52 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_html_entity` | 4 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_newline_stripping` | 64 | 15.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_password` | 5 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_password_copy` | 4 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_paste_empty` | 2 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_restrict_paste` | 5 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_width_height` | 103 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `empty_movieclip_can_attach_movies` | 11 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 105 | `enumerate` | 64 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 106 | `equals` | 32 | 10.7s |  |
| 107 | `equals2_swf5` | 926 | 12.4s |  |
| 108 | `equals2_swf6` | 926 | 12.3s |  |
| 109 | `equals2_swf7` | 926 | 12.4s |  |
| 110 | `equals_swf4` | 665 | 11.4s |  |
| 111 | `equals_swf4_alt` | 32 | 10.5s |  |
| 112 | `equals_swf5` | 32 | 10.7s |  |
| 113 | `error` | 58 | 10.6s |  |
| 114 | `escape` | 14 | 10.5s |  |
| 115 | `execution_order1` | 5 | 10.6s |  |
| 116 | `execution_order2` | 7 | 10.8s |  |
| 117 | `execution_order3` | 4 | 10.5s |  |
| 118 | `execution_order4` | 12 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 119 | `export_assets` | 3 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 120 | `extends_chain` | 134 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 121 | `extends_native_type` | 11 | 10.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 122 | `focus_root_movie` | 2 | 10.3s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 123 | `focusrect_focuslost` | 4 | 10.3s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 124 | `focusrect_mouse_swf8` | 0 | 10.2s |  |
| 125 | `focusrect_mouse_swf9` | 0 | 10.6s |  |
| 126 | `focusrect_swf5` | 6 | 10.6s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 127 | `focusrect_swf6` | 42 | 10.5s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 128 | `form_loader_encoding_1` | 1 | 10.4s |  |
| 129 | `function_suppress_and_preload` | 28 | 10.5s |  |
| 130 | `get_variable_in_scope` | 29 | 10.4s |  |
| 131 | `getproperty` | 28 | 10.3s |  |
| 132 | `getproperty_swf4` | 28 | 10.7s |  |
| 133 | `getproperty_swf5` | 28 | 10.4s |  |
| 134 | `global_array` | 3 | 10.6s |  |
| 135 | `global_is_bare` | 7 | 10.7s |  |
| 136 | `globals_swf5` | 304 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 137 | `globals_swf6` | 304 | 10.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 138 | `globals_swf7` | 304 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 139 | `globals_swf8` | 304 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 140 | `goto_advance1` | 6 | 10.3s |  |
| 141 | `goto_advance2` | 2 | 10.4s |  |
| 142 | `goto_both_ways1` | 3 | 10.5s |  |
| 143 | `goto_both_ways2` | 3 | 10.5s |  |
| 144 | `goto_execution_order` | 2 | 10.5s |  |
| 145 | `goto_execution_order2` | 2 | 10.4s |  |
| 146 | `goto_frame` | 12 | 11.3s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 147 | `goto_frame2` | 44 | 11.0s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 148 | `goto_frame_number` | 3 | 10.6s |  |
| 149 | `goto_label` | 17 | 10.7s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 150 | `goto_methods` | 40 | 10.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 151 | `goto_rewind1` | 1 | 10.7s |  |
| 152 | `goto_rewind2` | 3 | 10.6s |  |
| 153 | `goto_rewind3` | 2 | 10.6s |  |
| 154 | `greater_swf6` | 1175 | 12.8s |  |
| 155 | `greater_swf7` | 1175 | 12.6s |  |
| 156 | `greaterthan_swf5` | 1 | 10.4s |  |
| 157 | `greaterthan_swf8` | 1 | 10.5s |  |
| 158 | `has_own_property` | 32 | 10.4s |  |
| 159 | `hittest_lockroot` | 15 | 10.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 160 | `hittest_morph` | 70 | 10.5s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 161 | `hittest_winding_rule` | 12 | 10.6s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 162 | `infinite_recursion_function` | 4 | 10.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 163 | `infinite_recursion_function_in_setter` | 131 | 10.5s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 164 | `infinite_recursion_virtual_property` | 67 | 10.4s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 165 | `init_array_invalid` | 4 | 10.4s |  |
| 166 | `init_object_invalid` | 4 | 12.9s |  |
| 167 | `init_object_order` | 15 | 11.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 168 | `is_finite` | 49 | 11.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 169 | `is_finite_swf6` | 49 | 10.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 170 | `is_prototype_of` | 89 | 11.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 171 | `issue_1086` | 1 | 10.8s |  |
| 172 | `issue_1671` | 0 | 10.8s |  |
| 173 | `issue_1906` | 4 | 10.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 174 | `issue_2166` | 9 | 10.8s |  |
| 175 | `issue_3446` | 1 | 10.9s |  |
| 176 | `issue_3522` | 2 | 10.8s |  |
| 177 | `issue_4377` | 2 | 10.9s |  |
| 178 | `issue_710` | 4 | 10.9s |  |
| 179 | `issue_768` | 3 | 11.3s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 180 | `issue_9327` | 2 | 10.4s |  |
| 181 | `issue_9885` | 2 | 10.3s |  |
| 182 | `key_isToggled` | 9 | 10.3s |  |
| 183 | `lessthan` | 41 | 10.3s |  |
| 184 | `lessthan2_swf5` | 1226 | 12.3s |  |
| 185 | `lessthan2_swf6` | 1226 | 12.3s |  |
| 186 | `lessthan2_swf7` | 1226 | 12.3s |  |
| 187 | `lessthan_swf4` | 902 | 11.5s |  |
| 188 | `lessthan_swf4_alt` | 41 | 10.3s |  |
| 189 | `lessthan_swf5` | 41 | 10.3s |  |
| 190 | `loadmovie` | 2 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 191 | `loadmovie_fail` | 2 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 192 | `loadmovie_flashvars` | 4 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 193 | `loadmovie_method` | 2 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 194 | `loadmovie_replace_root` | 5 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 195 | `loadmovienum` | 3 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 196 | `loadvariables` | 2 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 197 | `loadvariables2` | 8 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 198 | `loadvariablesnum` | 2 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 199 | `local_to_global` | 49 | 10.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 200 | `localconnection_properties` | 8 | 10.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 201 | `lock_root` | 1 | 10.3s |  |
| 202 | `logical_ops_swf4` | 90 | 10.3s |  |
| 203 | `logical_ops_swf8` | 108 | 10.3s |  |
| 204 | `looping` | 6 | 10.3s |  |
| 205 | `mask_reapply` | 0 | 10.3s |  |
| 206 | `mask_with_drawing` | 0 | 10.3s |  |
| 207 | `math_min_max` | 101 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 208 | `math_swf6` | 530 | 10.7s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 209 | `math_swf7` | 530 | 10.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 210 | `math_swf8` | 530 | 10.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 211 | `matrix` | 171 | 10.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 212 | `mcl_as_broadcaster` | 12 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 213 | `mcl_getprogress` | 30 | 10.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 214 | `mcl_loadclip` | 149 | 10.5s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 215 | `mcl_loadclip_properties` | 6 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 216 | `mcl_mislabeled_target` | 6 | 10.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 217 | `mcl_target_gif87a` | 6 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 218 | `mcl_target_gif89a` | 6 | 10.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 219 | `mcl_target_jpg` | 6 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 220 | `mcl_target_png` | 6 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 221 | `mcl_unloadclip` | 5 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 222 | `mouse_events` | 8 | 10.3s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 223 | `mouse_events_visible_enabled` | 12 | 10.5s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 224 | `mouse_hover_events_while_dragging` | 1 | 10.4s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 225 | `mouse_listeners` | 67 | 10.3s |  |
| 226 | `mouse_pos` | 665 | 10.3s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 227 | `mouse_pos_with_scale_factor` | 260 | 10.3s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 228 | `mouse_wheel_enabled` | 2 | 10.3s |  |
| 229 | `movieclip_begin_gradient_fill` | 0 | 10.8s |  |
| 230 | `movieclip_blend_mode_property` | 35 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 231 | `movieclip_default_state` | 69 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 232 | `movieclip_depth_methods` | 98 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 233 | `movieclip_focusenabled` | 99 | 10.4s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 234 | `movieclip_get_instance_at_depth` | 28 | 10.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 235 | `movieclip_hittest` | 92 | 10.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 236 | `movieclip_in_removed_button` | 4 | 10.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 237 | `movieclip_init_object` | 5 | 10.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 238 | `movieclip_line_gradient_style` | 0 | 11.4s |  |
| 239 | `movieclip_name_from_timeline` | 13 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 240 | `movieclip_prototype_extension` | 5 | 10.5s |  |
| 241 | `moviecliploader_flashvars` | 4 | 10.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 242 | `mutable_this` | 18 | 10.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 243 | `named_shapes` | 14 | 10.7s |  |
| 244 | `nan_scale` | 9 | 10.7s |  |
| 245 | `native_double_construct` | 12 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 246 | `native_objects_swf7` | 84 | 11.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 247 | `native_objects_swf8` | 84 | 11.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 248 | `native_subclasses` | 191 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 249 | `nested_textfields_in_buttons` | 0 | 10.7s |  |
| 250 | `new_method_wrap` | 4 | 10.3s |  |
| 251 | `new_object_enumerate` | 7 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 252 | `new_object_wrap` | 4 | 10.3s |  |
| 253 | `o` | 3 | 10.4s |  |
| 254 | `object_constructor` | 33 | 10.4s |  |
| 255 | `object_function` | 32 | 10.3s |  |
| 256 | `object_properties` | 31 | 10.5s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 257 | `object_prototypes` | 74 | 10.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 258 | `object_string_coerce_swf5` | 62 | 10.4s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 259 | `object_string_coerce_swf6` | 68 | 10.3s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 260 | `on_construct` | 25 | 10.6s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 261 | `parse_float` | 74 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 262 | `parse_int` | 64 | 10.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 263 | `path_string` | 322 | 10.5s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 264 | `place_and_lookup` | 30 | 10.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 265 | `placeobject_occupied_depth` | 6 | 10.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 266 | `point` | 175 | 10.6s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 267 | `primitive_instanceof` | 37 | 10.3s |  |
| 268 | `primitive_type_globals` | 557 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 269 | `printjob_props_swf5` | 45 | 10.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 270 | `printjob_props_swf6` | 45 | 10.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 271 | `printjob_props_swf7` | 45 | 10.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 272 | `property_invalid_base_clip` | 36 | 10.4s |  |
| 273 | `prototype_delete` | 12 | 10.3s |  |
| 274 | `prototype_enumerate` | 5 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 275 | `prototype_properties` | 17 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 276 | `rectangle` | 745 | 11.2s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 277 | `recursive_prototypes` | 0 | 10.4s |  |
| 278 | `register_class_return_value` | 16 | 10.5s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 279 | `register_globals_across_frames` | 15 | 10.3s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 280 | `register_underflow` | 26 | 10.3s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 281 | `remove_movie_clip` | 29 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 282 | `rewind_depth` | 30 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 283 | `sandbox_type_local_file` | 1 | 10.4s |  |
| 284 | `sandbox_type_local_network` | 1 | 10.3s |  |
| 285 | `selection` | 454 | 10.6s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 286 | `set_interval` | 27 | 10.6s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 287 | `set_variable_scope` | 58 | 10.6s |  |
| 288 | `single_frame` | 1 | 10.5s |  |
| 289 | `slash_syntax` | 14 | 10.4s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 290 | `sound_props_swf5` | 68 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 291 | `sound_props_swf6` | 68 | 10.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 292 | `sound_start_load` | 0 | 10.4s |  |
| 293 | `stage_display_state` | 16 | 10.3s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 294 | `stage_object_children` | 83 | 10.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 295 | `stage_object_enumerate` | 4 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 296 | `stage_object_properties` | 241 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 297 | `stage_object_properties_get_var` | 5 | 10.3s |  |
| 298 | `stage_object_properties_swf6` | 231 | 10.6s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 299 | `stage_property_representation` | 586 | 10.3s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 300 | `stage_scale_mode` | 39 | 10.3s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 301 | `strictequals_swf6` | 902 | 11.8s |  |
| 302 | `strictly_equals` | 7 | 10.3s |  |
| 303 | `string_coercion` | 117 | 10.6s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 304 | `string_methods` | 285 | 10.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 305 | `string_methods_negative_args` | 240 | 10.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 306 | `string_methods_swfv5` | 275 | 10.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 307 | `string_ops_swf6` | 95 | 10.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 308 | `string_paths_basic` | 4 | 10.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 309 | `string_paths_hidden` | 54 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 310 | `string_paths_variable_alias` | 4 | 10.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 311 | `super_edge_cases` | 39 | 10.7s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 312 | `swf4_actions_bool` | 96 | 10.5s |  |
| 313 | `swf4_actions_coercion_order` | 158 | 10.6s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 314 | `swf4_bool` | 4 | 10.5s |  |
| 315 | `swf4_function_calls` | 7 | 10.5s |  |
| 316 | `swf5_encoding` | 3 | 10.4s |  |
| 317 | `swf5_no_closure` | 19 | 11.6s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 318 | `swf6_case_insensitive` | 42 | 10.4s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 319 | `swf6_string_as_bool` | 15 | 10.4s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 320 | `swf7_case_sensitive` | 44 | 10.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 321 | `tab_ordering_automatic_basic` | 92 | 10.4s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 322 | `tab_ordering_automatic_order_grid` | 21 | 10.4s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 323 | `tab_ordering_children` | 208 | 10.5s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 324 | `tab_ordering_custom_basic` | 71 | 10.4s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 325 | `tab_ordering_custom_duplicate_index` | 22 | 10.4s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 326 | `tab_ordering_custom_i32_vs_u32` | 12 | 10.4s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 327 | `tab_ordering_custom_m1` | 29 | 10.4s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 328 | `tab_ordering_events` | 150 | 10.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 329 | `tab_ordering_movieclip_enabled_default` | 462 | 10.6s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 330 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.9s |  |
| 331 | `tab_ordering_reverse` | 51 | 11.0s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 332 | `tab_ordering_tabbable` | 47 | 11.0s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 333 | `target_clip_removed` | 5 | 10.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 334 | `target_clip_swf5` | 2 | 10.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 335 | `target_clip_swf6` | 2 | 10.8s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 336 | `target_path` | 14 | 10.8s |  |
| 337 | `tell_target` | 37 | 10.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 338 | `tell_target_invalid` | 6 | 10.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 339 | `tell_target_invalid_swf6` | 5 | 11.0s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 340 | `text_format` | 1146 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 341 | `text_format_display` | 21 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 342 | `text_format_font_max_length` | 2 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 343 | `text_format_rounding_swf7` | 840 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 344 | `text_format_rounding_swf8` | 840 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 345 | `textfield_background_color` | 11 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 346 | `textfield_border_color` | 11 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 347 | `textfield_maxchars` | 3 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 348 | `textfield_properties` | 44 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 349 | `textfield_props_swf5` | 175 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 350 | `textfield_props_swf6` | 210 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 351 | `textfield_props_swf7` | 210 | 11.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 352 | `textfield_props_swf8` | 210 | 11.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 353 | `textfield_text` | 7 | 11.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 354 | `textfield_variable` | 81 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 355 | `textsnapshot_props_swf6` | 56 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 356 | `this_scoping` | 52 | 11.8s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 357 | `this_swf5` | 41 | 11.2s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 358 | `this_swf6` | 41 | 11.5s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 359 | `this_swf7` | 41 | 11.7s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 360 | `timeline_function_def` | 7 | 11.7s |  |
| 361 | `transform` | 70 | 11.1s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 362 | `try_catch_finally` | 118 | 11.1s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 363 | `try_finally_simple` | 16 | 11.1s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 364 | `typeof` | 22 | 11.2s |  |
| 365 | `typeof_globals` | 7 | 11.2s |  |
| 366 | `uncaught_exception` | 1 | 11.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 367 | `uncaught_exception_bubbled` | 1 | 11.1s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 368 | `undefined_to_string_swf6` | 4 | 11.0s |  |
| 369 | `unescape` | 43 | 11.1s |  |
| 370 | `unload_clip_event` | 4 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 371 | `unloadmovie` | 4 | 11.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 372 | `unloadmovie_method` | 3 | 11.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 373 | `unloadmovienum` | 13 | 11.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 374 | `use_hand_cursor` | 8 | 11.0s |  |
| 375 | `variable_args` | 5 | 11.3s |  |
| 376 | `waitforframe` | 7 | 11.2s |  |
| 377 | `waitforframe2` | 16 | 11.1s |  |
| 378 | `watch` | 117 | 11.0s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 379 | `watch_virtual_property_proto` | 2 | 10.8s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 380 | `with` | 49 | 10.8s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 381 | `with_return` | 2 | 10.7s |  |
| 382 | `with_variable_scopes` | 43 | 10.8s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 383 | `xml` | 15 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xml_append_child` | 28 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 385 | `xml_append_child_with_parent` | 20 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 386 | `xml_attributes_read` | 4 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 387 | `xml_cdata` | 11 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 388 | `xml_child_nodes_edge_cases` | 4 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 389 | `xml_clone_expandos` | 19 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 390 | `xml_first_last_child` | 8 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 391 | `xml_has_child_nodes` | 3 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 392 | `xml_idmap` | 21 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 393 | `xml_ignore_comments` | 21 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 394 | `xml_ignore_white` | 34 | 11.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 395 | `xml_insert_before` | 20 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 396 | `xml_inspect_createmethods` | 15 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 397 | `xml_inspect_doctype` | 7 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 398 | `xml_inspect_parsexml` | 62 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 399 | `xml_inspect_xmldecl` | 7 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xml_namespaces` | 203 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 401 | `xml_parent_and_child` | 5 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 402 | `xml_remove_node` | 22 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xml_reparenting` | 14 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 404 | `xml_siblings` | 10 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 405 | `xml_to_string` | 13 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 406 | `xml_to_string_comment` | 1 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 407 | `xml_unescaping` | 23 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 408 | `xmlnode_proto` | 1 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**62 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `function_base_clip_removed` | 88.0% | 22 | 25 | 3 |  |
| 8 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 10 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `button_keypress_vs_textinput` | 75.0% | 3 | 4 | 1 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 13 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 14 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 15 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 17 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 18 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 19 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 21 | `textsnapshot_props_swf5` | 67.9% | 38 | 56 | 18 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 38 | `edittext_programmatic_focus` | 58.3% | 7 | 12 | 5 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 40 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 42 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 43 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 45 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 46 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 47 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 50 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 51 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 52 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 53 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 54 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 59 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 60 | `loadmovie_var_persistence` | 50.0% | 4 | 8 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 61 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 62 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 12.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 12.6s |  |
| 3 | `netstream_play_flv_screen` | 26.3s |  |
| 4 | `string_paths_timer` | 12.5s |  |
| 5 | `timer_run_actions` | 13.4s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_3` | exit code -6 | 10.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_4` | exit code -6 | 10.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 32.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 33.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 21.6s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**200 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 7 | `function_base_clip_removed` | 88.0% | 22/25 | 25 | 25 |  |
| 8 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 9 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 10 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `button_keypress_vs_textinput` | 75.0% | 3/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 13 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 14 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 15 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 17 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 18 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 19 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 21 | `textsnapshot_props_swf5` | 67.9% | 38/56 | 56 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 25 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 38 | `edittext_programmatic_focus` | 58.3% | 7/12 | 12 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 40 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 42 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 43 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 45 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 46 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 47 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 50 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 51 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 52 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 53 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 54 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 59 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 60 | `loadmovie_var_persistence` | 50.0% | 4/8 | 5 | 8 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 61 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 62 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 65 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 66 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `register_class_with_sound` | 45.5% | 5/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 68 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 69 | `focus_mouse` | 44.4% | 20/45 | 38 | 45 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 70 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 71 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 72 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 73 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 74 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 75 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 76 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 77 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 78 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 79 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 80 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 81 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 82 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 83 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 85 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 87 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 88 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 89 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 90 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 91 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 93 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 94 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 95 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 96 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 97 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 98 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 99 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 100 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 101 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 103 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 104 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 105 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 106 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
| 107 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 108 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 109 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 110 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 111 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 112 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 113 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 114 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 115 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 116 | `mcl_events_swf_version` | 13.8% | 32/232 | 37 | 232 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 117 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 118 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 119 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 120 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 121 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 122 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 123 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 124 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 125 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 126 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 127 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 128 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 129 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 130 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 131 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 132 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 133 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 134 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 135 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 136 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 137 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 138 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 139 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 140 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 141 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 142 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 143 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 144 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 145 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 146 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 147 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 148 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 149 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 150 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 151 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 152 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 153 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 154 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 155 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 156 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 157 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 158 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 159 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 160 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 161 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 162 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 163 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 164 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 165 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 166 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 167 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 168 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 169 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 170 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 171 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 172 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 173 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 174 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 175 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 176 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 177 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 178 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 179 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 180 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 183 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 184 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 185 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 186 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 187 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 188 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 189 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 190 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 191 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 192 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 193 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 194 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 195 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 196 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 197 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 198 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 199 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 200 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 22 | 9 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 23 | 26 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 27 | 31 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 10 | 5 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 7 | 2 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 7 | 6 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 13 | 3 |
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
