# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-27 01:40 UTC

**Git SHA**: `fc96eb5ca4`

**Run Duration**: 105m 51s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **384** (62.0%) |
| Failing | 235 |
| Total expected lines | 91470 |
| Matching lines | 59808 (65.4%) |
| Mismatched lines | 31662 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 218 | 92.8% |
| Runtime Segfault | 13 | 5.5% |
| Runtime Error | 2 | 0.9% |
| Compile Fail | 1 | 0.4% |
| Timeout | 1 | 0.4% |

## Passing Tests

**384 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 10.2s |  |
| 2 | `action_to_integer` | 28 | 9.9s |  |
| 3 | `add` | 28 | 9.9s |  |
| 4 | `add2` | 354 | 10.0s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 9.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 9.9s |  |
| 7 | `add_swf5` | 28 | 9.8s |  |
| 8 | `arguments` | 127 | 9.9s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 9.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 9.9s |  |
| 11 | `array_constructor` | 30 | 9.8s |  |
| 12 | `array_enumerate` | 4 | 9.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 9.8s |  |
| 14 | `array_properties` | 36 | 9.8s |  |
| 15 | `array_prototyping` | 12 | 9.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 9.9s |  |
| 17 | `array_sort` | 161 | 10.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 9.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 10.0s |  |
| 20 | `array_trivial` | 209 | 10.0s |  |
| 21 | `as1_constructor_v6` | 35 | 9.9s |  |
| 22 | `as1_constructor_v7` | 35 | 10.0s |  |
| 23 | `as2_oop` | 13 | 10.1s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 10.1s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 10.0s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 10.0s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 9.8s |  |
| 28 | `as_set_prop_flags` | 79 | 9.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 9.7s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 9.7s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 9.6s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 9.6s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 9.7s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 9.7s |  |
| 35 | `as_transformed_flag` | 20 | 9.7s |  |
| 36 | `attach_movie` | 59 | 9.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 9.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 38 | `bad_swf_tag_past_eof` | 0 | 9.7s |  |
| 39 | `bitand` | 1058 | 12.2s |  |
| 40 | `bitmap_data_colortransform` | 0 | 9.9s |  |
| 41 | `bitmap_data_fillrect` | 0 | 9.8s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 9.7s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 9.7s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 10.3s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 9.8s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.3s |  |
| 47 | `bitor` | 1058 | 11.8s |  |
| 48 | `biturshift` | 14 | 9.5s |  |
| 49 | `biturshift_swf8` | 14 | 10.1s |  |
| 50 | `bitxor` | 1058 | 12.5s |  |
| 51 | `boxed_primitives` | 24 | 10.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_key_events` | 14 | 10.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events_special` | 45 | 10.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_keypress` | 3 | 10.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress_vs_press` | 25 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_tab` | 20 | 10.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_order` | 2 | 9.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_properties_special_cases` | 22 | 10.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v5` | 18 | 9.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_v6` | 18 | 9.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 9.8s |  |
| 64 | `capabilities_resolution` | 8 | 9.8s |  |
| 65 | `catch_references_registers` | 2 | 9.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `click_block` | 5 | 10.1s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 67 | `clip_events` | 19 | 10.2s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 68 | `clone_sprite_types` | 24 | 9.9s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 69 | `closure_scope` | 7 | 10.0s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 70 | `color` | 57 | 10.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 71 | `color_transform` | 48 | 10.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `conflicting_instance_names` | 23 | 9.9s |  |
| 73 | `constructor_function` | 2 | 9.9s |  |
| 74 | `context_menu` | 39 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 75 | `context_menu_item` | 41 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `define_function2` | 8 | 10.0s |  |
| 77 | `define_function2_preload` | 13 | 10.1s |  |
| 78 | `define_function2_preload_order` | 4 | 10.0s |  |
| 79 | `define_function_case_sensitive` | 2 | 9.8s |  |
| 80 | `delete` | 3 | 9.8s |  |
| 81 | `display_object_properties` | 2 | 9.7s |  |
| 82 | `divide_swf4` | 107 | 9.7s |  |
| 83 | `do_init_action` | 3 | 9.7s |  |
| 84 | `drag_drop` | 10 | 9.7s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 85 | `drag_over_from_outside` | 1 | 9.8s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 86 | `drag_over_without_startdrag` | 1 | 9.8s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 87 | `duplicate_movie_clip` | 20 | 9.7s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 88 | `edittext_autosize_setter` | 20 | 10.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_default_format` | 221 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `edittext_default_format_empty` | 95 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 91 | `edittext_default_format_font_style` | 335 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_html_align_swf7` | 52 | 10.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_html_align_swf8` | 52 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_html_entity` | 4 | 10.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_newline_stripping` | 64 | 14.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_password_copy` | 4 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_paste_empty` | 2 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_restrict_paste` | 5 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_width_height` | 103 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `empty_movieclip_can_attach_movies` | 11 | 10.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 101 | `enumerate` | 64 | 10.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 102 | `equals` | 32 | 9.9s |  |
| 103 | `equals2_swf5` | 926 | 11.7s |  |
| 104 | `equals2_swf6` | 926 | 11.6s |  |
| 105 | `equals2_swf7` | 926 | 11.7s |  |
| 106 | `equals_swf4` | 665 | 10.7s |  |
| 107 | `equals_swf4_alt` | 32 | 10.0s |  |
| 108 | `equals_swf5` | 32 | 10.0s |  |
| 109 | `error` | 58 | 10.0s |  |
| 110 | `escape` | 14 | 9.9s |  |
| 111 | `execution_order1` | 5 | 9.9s |  |
| 112 | `execution_order2` | 7 | 10.1s |  |
| 113 | `execution_order3` | 4 | 10.0s |  |
| 114 | `export_assets` | 3 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 115 | `extends_chain` | 134 | 10.4s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 116 | `extends_native_type` | 11 | 9.9s | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 117 | `focus_root_movie` | 2 | 9.8s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 118 | `focusrect_focuslost` | 4 | 9.8s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 119 | `focusrect_mouse_swf8` | 0 | 9.7s |  |
| 120 | `focusrect_mouse_swf9` | 0 | 10.2s |  |
| 121 | `focusrect_swf5` | 6 | 10.0s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 122 | `focusrect_swf6` | 42 | 10.0s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 123 | `form_loader_encoding_1` | 1 | 10.1s |  |
| 124 | `function_suppress_and_preload` | 28 | 10.1s |  |
| 125 | `get_variable_in_scope` | 29 | 10.1s |  |
| 126 | `getproperty` | 28 | 10.1s |  |
| 127 | `getproperty_swf4` | 28 | 10.1s |  |
| 128 | `getproperty_swf5` | 28 | 9.8s |  |
| 129 | `global_array` | 3 | 9.9s |  |
| 130 | `global_is_bare` | 7 | 9.7s |  |
| 131 | `globals_swf5` | 304 | 10.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 132 | `globals_swf6` | 304 | 10.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 133 | `globals_swf7` | 304 | 10.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 134 | `globals_swf8` | 304 | 10.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 135 | `goto_advance1` | 6 | 9.7s |  |
| 136 | `goto_advance2` | 2 | 9.7s |  |
| 137 | `goto_both_ways1` | 3 | 9.8s |  |
| 138 | `goto_both_ways2` | 3 | 9.9s |  |
| 139 | `goto_execution_order` | 2 | 9.8s |  |
| 140 | `goto_execution_order2` | 2 | 9.7s |  |
| 141 | `goto_frame` | 12 | 10.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 142 | `goto_frame2` | 44 | 10.3s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 143 | `goto_frame_number` | 3 | 10.1s |  |
| 144 | `goto_label` | 17 | 9.9s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 145 | `goto_methods` | 40 | 9.8s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 146 | `goto_rewind1` | 1 | 9.8s |  |
| 147 | `goto_rewind2` | 3 | 9.9s |  |
| 148 | `goto_rewind3` | 2 | 9.8s |  |
| 149 | `greater_swf6` | 1175 | 12.0s |  |
| 150 | `greater_swf7` | 1175 | 11.8s |  |
| 151 | `greaterthan_swf5` | 1 | 9.7s |  |
| 152 | `greaterthan_swf8` | 1 | 9.7s |  |
| 153 | `has_own_property` | 32 | 9.7s |  |
| 154 | `hittest_lockroot` | 15 | 10.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 155 | `hittest_morph` | 70 | 9.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 156 | `hittest_winding_rule` | 12 | 9.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 157 | `infinite_recursion_function` | 4 | 9.7s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 158 | `infinite_recursion_function_in_setter` | 131 | 9.7s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 159 | `infinite_recursion_virtual_property` | 67 | 9.7s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 160 | `init_array_invalid` | 4 | 9.7s |  |
| 161 | `init_object_invalid` | 4 | 11.3s |  |
| 162 | `init_object_order` | 15 | 9.8s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 163 | `is_finite` | 49 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 164 | `is_finite_swf6` | 49 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 165 | `is_prototype_of` | 89 | 10.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 166 | `issue_1086` | 1 | 9.7s |  |
| 167 | `issue_1671` | 0 | 9.7s |  |
| 168 | `issue_1906` | 4 | 9.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 169 | `issue_2166` | 9 | 9.8s |  |
| 170 | `issue_3446` | 1 | 10.3s |  |
| 171 | `issue_3522` | 2 | 9.8s |  |
| 172 | `issue_4377` | 2 | 10.3s |  |
| 173 | `issue_710` | 4 | 10.0s |  |
| 174 | `issue_9327` | 2 | 10.1s |  |
| 175 | `issue_9885` | 2 | 9.9s |  |
| 176 | `key_isToggled` | 9 | 10.0s |  |
| 177 | `lessthan` | 41 | 9.9s |  |
| 178 | `lessthan2_swf5` | 1226 | 12.0s |  |
| 179 | `lessthan2_swf6` | 1226 | 12.0s |  |
| 180 | `lessthan2_swf7` | 1226 | 12.0s |  |
| 181 | `lessthan_swf4` | 902 | 11.2s |  |
| 182 | `lessthan_swf4_alt` | 41 | 9.8s |  |
| 183 | `lessthan_swf5` | 41 | 9.9s |  |
| 184 | `loadmovie` | 2 | 9.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 185 | `loadmovie_fail` | 2 | 9.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 186 | `loadmovie_flashvars` | 4 | 9.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 187 | `loadmovie_method` | 2 | 9.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 188 | `loadmovie_replace_root` | 5 | 9.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 189 | `loadmovienum` | 3 | 10.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 190 | `loadvariables` | 2 | 9.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 191 | `loadvariables2` | 8 | 9.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 192 | `loadvariablesnum` | 2 | 9.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 193 | `local_to_global` | 49 | 9.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 194 | `localconnection_properties` | 8 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 195 | `lock_root` | 1 | 9.8s |  |
| 196 | `logical_ops_swf4` | 90 | 9.8s |  |
| 197 | `logical_ops_swf8` | 108 | 9.9s |  |
| 198 | `looping` | 6 | 9.9s |  |
| 199 | `mask_reapply` | 0 | 9.8s |  |
| 200 | `mask_with_drawing` | 0 | 9.8s |  |
| 201 | `math_min_max` | 101 | 9.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 202 | `math_swf6` | 530 | 10.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 203 | `math_swf7` | 530 | 10.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 204 | `math_swf8` | 530 | 10.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 205 | `matrix` | 171 | 10.2s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 206 | `mcl_as_broadcaster` | 12 | 9.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 207 | `mcl_getprogress` | 30 | 9.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 208 | `mcl_loadclip` | 149 | 9.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 209 | `mcl_loadclip_properties` | 6 | 9.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 210 | `mcl_mislabeled_target` | 6 | 9.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 211 | `mcl_target_gif87a` | 6 | 10.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 212 | `mcl_target_gif89a` | 6 | 10.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 213 | `mcl_target_jpg` | 6 | 9.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 214 | `mcl_target_png` | 6 | 9.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 215 | `mcl_unloadclip` | 5 | 9.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 216 | `mouse_events` | 8 | 9.7s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 217 | `mouse_events_visible_enabled` | 12 | 9.8s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 218 | `mouse_hover_events_while_dragging` | 1 | 9.7s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 219 | `mouse_listeners` | 67 | 9.6s |  |
| 220 | `mouse_pos` | 665 | 9.7s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 221 | `mouse_pos_with_scale_factor` | 260 | 9.7s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 222 | `mouse_wheel_enabled` | 2 | 9.6s |  |
| 223 | `movieclip_begin_gradient_fill` | 0 | 10.2s |  |
| 224 | `movieclip_blend_mode_property` | 35 | 11.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 225 | `movieclip_default_state` | 69 | 10.0s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 226 | `movieclip_depth_methods` | 98 | 9.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 227 | `movieclip_focusenabled` | 99 | 9.8s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 228 | `movieclip_get_instance_at_depth` | 28 | 9.7s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 229 | `movieclip_hittest` | 92 | 9.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 230 | `movieclip_in_removed_button` | 4 | 9.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 231 | `movieclip_line_gradient_style` | 0 | 12.2s |  |
| 232 | `movieclip_name_from_timeline` | 13 | 10.2s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 233 | `movieclip_prototype_extension` | 5 | 10.1s |  |
| 234 | `moviecliploader_flashvars` | 4 | 10.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 235 | `mutable_this` | 18 | 10.1s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 236 | `named_shapes` | 14 | 10.2s |  |
| 237 | `nested_textfields_in_buttons` | 0 | 10.1s |  |
| 238 | `new_method_wrap` | 4 | 10.2s |  |
| 239 | `new_object_enumerate` | 7 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 240 | `new_object_wrap` | 4 | 10.0s |  |
| 241 | `o` | 3 | 9.8s |  |
| 242 | `object_constructor` | 33 | 9.8s |  |
| 243 | `object_function` | 32 | 9.8s |  |
| 244 | `object_properties` | 31 | 10.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 245 | `object_prototypes` | 74 | 9.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 246 | `object_string_coerce_swf5` | 62 | 9.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 247 | `object_string_coerce_swf6` | 68 | 9.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 248 | `parse_float` | 74 | 9.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 249 | `parse_int` | 64 | 10.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 250 | `path_string` | 322 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 251 | `placeobject_occupied_depth` | 6 | 9.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 252 | `point` | 175 | 10.1s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 253 | `primitive_instanceof` | 37 | 9.8s |  |
| 254 | `primitive_type_globals` | 557 | 10.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 255 | `printjob_props_swf5` | 45 | 9.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 256 | `printjob_props_swf6` | 45 | 9.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 257 | `printjob_props_swf7` | 45 | 9.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 258 | `property_invalid_base_clip` | 36 | 9.8s |  |
| 259 | `prototype_delete` | 12 | 9.7s |  |
| 260 | `prototype_enumerate` | 5 | 9.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 261 | `prototype_properties` | 17 | 9.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 262 | `rectangle` | 745 | 10.4s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 263 | `recursive_prototypes` | 0 | 9.6s |  |
| 264 | `register_class_return_value` | 16 | 9.8s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 265 | `register_globals_across_frames` | 15 | 9.7s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 266 | `register_underflow` | 26 | 9.7s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 267 | `remove_movie_clip` | 29 | 9.8s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 268 | `sandbox_type_local_file` | 1 | 9.9s |  |
| 269 | `sandbox_type_local_network` | 1 | 9.9s |  |
| 270 | `set_interval` | 27 | 10.0s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 271 | `set_variable_scope` | 58 | 9.8s |  |
| 272 | `single_frame` | 1 | 9.8s |  |
| 273 | `slash_syntax` | 14 | 9.9s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 274 | `sound_props_swf5` | 68 | 9.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 275 | `sound_props_swf6` | 68 | 10.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 276 | `sound_start_load` | 0 | 9.9s |  |
| 277 | `stage_display_state` | 16 | 10.4s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 278 | `stage_object_children` | 83 | 10.3s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 279 | `stage_object_enumerate` | 4 | 9.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 280 | `stage_object_properties` | 241 | 10.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 281 | `stage_object_properties_get_var` | 5 | 9.8s |  |
| 282 | `stage_object_properties_swf6` | 231 | 10.2s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 283 | `stage_property_representation` | 586 | 9.9s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 284 | `stage_scale_mode` | 39 | 9.9s | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 285 | `strictequals_swf6` | 902 | 11.4s |  |
| 286 | `strictly_equals` | 7 | 9.8s |  |
| 287 | `string_coercion` | 117 | 10.0s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 288 | `string_methods` | 285 | 10.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 289 | `string_methods_negative_args` | 240 | 9.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 290 | `string_methods_swfv5` | 275 | 10.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 291 | `string_ops_swf6` | 95 | 9.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 292 | `string_paths_basic` | 4 | 9.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 293 | `string_paths_hidden` | 54 | 9.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 294 | `string_paths_variable_alias` | 4 | 9.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 295 | `swf4_actions_bool` | 96 | 9.8s |  |
| 296 | `swf4_actions_coercion_order` | 158 | 9.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 297 | `swf4_bool` | 4 | 9.8s |  |
| 298 | `swf4_function_calls` | 7 | 9.7s |  |
| 299 | `swf5_encoding` | 3 | 9.7s |  |
| 300 | `swf5_no_closure` | 19 | 9.9s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 301 | `swf6_case_insensitive` | 42 | 9.4s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 302 | `swf6_string_as_bool` | 15 | 9.3s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 303 | `swf7_case_sensitive` | 44 | 9.4s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 304 | `tab_ordering_automatic_basic` | 92 | 9.4s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 305 | `tab_ordering_automatic_order_grid` | 21 | 9.4s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 306 | `tab_ordering_custom_basic` | 71 | 9.3s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 307 | `tab_ordering_custom_duplicate_index` | 22 | 9.6s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 308 | `tab_ordering_custom_i32_vs_u32` | 12 | 9.8s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 309 | `tab_ordering_custom_m1` | 29 | 9.7s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 310 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.0s |  |
| 311 | `tab_ordering_reverse` | 51 | 10.1s | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 312 | `target_clip_removed` | 5 | 10.1s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 313 | `target_clip_swf5` | 2 | 10.0s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 314 | `target_clip_swf6` | 2 | 10.0s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 315 | `target_path` | 14 | 10.0s |  |
| 316 | `tell_target` | 37 | 10.0s | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 317 | `text_format` | 1146 | 10.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 318 | `text_format_display` | 21 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 319 | `text_format_font_max_length` | 2 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 320 | `text_format_rounding_swf7` | 840 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 321 | `text_format_rounding_swf8` | 840 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 322 | `textfield_background_color` | 11 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 323 | `textfield_border_color` | 11 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 324 | `textfield_maxchars` | 3 | 11.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 325 | `textfield_properties` | 44 | 10.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 326 | `textfield_props_swf5` | 175 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 327 | `textfield_props_swf6` | 210 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 328 | `textfield_props_swf7` | 210 | 10.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 329 | `textfield_props_swf8` | 210 | 9.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 330 | `textfield_text` | 7 | 9.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 331 | `textfield_variable` | 81 | 10.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 332 | `textsnapshot_props_swf6` | 56 | 9.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 333 | `this_swf5` | 41 | 9.7s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 334 | `this_swf6` | 41 | 9.7s | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) |
| 335 | `this_swf7` | 41 | 9.7s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 336 | `timeline_function_def` | 7 | 9.8s |  |
| 337 | `transform` | 70 | 10.1s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 338 | `try_catch_finally` | 118 | 10.1s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 339 | `try_finally_simple` | 16 | 9.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 340 | `typeof` | 22 | 10.0s |  |
| 341 | `typeof_globals` | 7 | 10.0s |  |
| 342 | `uncaught_exception` | 1 | 10.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 343 | `uncaught_exception_bubbled` | 1 | 10.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 344 | `undefined_to_string_swf6` | 4 | 9.9s |  |
| 345 | `unescape` | 43 | 10.1s |  |
| 346 | `unload_clip_event` | 4 | 10.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 347 | `unloadmovie` | 4 | 10.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 348 | `unloadmovie_method` | 3 | 10.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 349 | `unloadmovienum` | 13 | 10.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 350 | `use_hand_cursor` | 8 | 10.1s |  |
| 351 | `variable_args` | 5 | 10.2s |  |
| 352 | `waitforframe` | 7 | 10.0s |  |
| 353 | `waitforframe2` | 16 | 11.9s |  |
| 354 | `watch` | 117 | 10.0s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 355 | `watch_virtual_property_proto` | 2 | 9.8s | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 356 | `with` | 49 | 9.8s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 357 | `with_return` | 2 | 9.8s |  |
| 358 | `with_variable_scopes` | 43 | 9.9s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 359 | `xml` | 15 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 360 | `xml_append_child` | 28 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 361 | `xml_append_child_with_parent` | 20 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 362 | `xml_attributes_read` | 4 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 363 | `xml_cdata` | 11 | 9.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 364 | `xml_child_nodes_edge_cases` | 4 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 365 | `xml_clone_expandos` | 19 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 366 | `xml_first_last_child` | 8 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 367 | `xml_has_child_nodes` | 3 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 368 | `xml_idmap` | 21 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 369 | `xml_ignore_comments` | 21 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 370 | `xml_ignore_white` | 34 | 10.3s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 371 | `xml_insert_before` | 20 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 372 | `xml_inspect_createmethods` | 15 | 10.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 373 | `xml_inspect_doctype` | 7 | 10.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 374 | `xml_inspect_parsexml` | 62 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 375 | `xml_inspect_xmldecl` | 7 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 376 | `xml_namespaces` | 203 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 377 | `xml_parent_and_child` | 5 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 378 | `xml_remove_node` | 22 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 379 | `xml_reparenting` | 14 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 380 | `xml_siblings` | 10 | 9.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 381 | `xml_to_string` | 13 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 382 | `xml_to_string_comment` | 1 | 9.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 383 | `xml_unescaping` | 23 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 384 | `xmlnode_proto` | 1 | 10.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**69 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `selection` | 95.6% | 434 | 454 | 20 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `edittext_antialiastype` | 92.6% | 274 | 296 | 22 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `tab_ordering_children` | 87.0% | 181 | 208 | 27 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 8 | `super_edge_cases` | 84.6% | 33 | 39 | 6 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 9 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20 | 25 | 5 |  |
| 12 | `tell_target_invalid_swf6` | 80.0% | 4 | 5 | 1 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 78.7% | 266 | 338 | 72 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `button_keypress_vs_textinput` | 75.0% | 3 | 4 | 1 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 16 | `clip_constructors` | 75.0% | 6 | 8 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 17 | `create_empty_movie_clip` | 75.0% | 3 | 4 | 1 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 19 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 20 | `edittext_scroll` | 74.1% | 40 | 54 | 14 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 22 | `rewind_depth` | 73.3% | 22 | 30 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `tab_ordering_tabbable` | 70.2% | 33 | 47 | 14 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 25 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 26 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `unload` | 69.2% | 36 | 52 | 16 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `textsnapshot_props_swf5` | 67.9% | 38 | 56 | 18 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_hscroll` | 66.7% | 18 | 27 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `issue_768` | 66.7% | 2 | 3 | 1 | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 32 | `tell_target_invalid` | 66.7% | 4 | 6 | 2 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 33 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 34 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_autosize` | 62.0% | 44 | 71 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_align` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_newlines` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_password` | 60.0% | 3 | 5 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `place_and_lookup` | 60.0% | 18 | 30 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 47 | `execution_order4` | 58.3% | 7 | 12 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 48 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 49 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 50 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 52 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 54 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 55 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 56 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 59 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 60 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 61 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 62 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 66 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 67 | `loadmovie_var_persistence` | 50.0% | 4 | 8 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 68 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 69 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**13 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 12.2s |  |
| 3 | `movieclip_init_object` | 11.9s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 4 | `movieclip_library_state_values` | 12.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 5 | `native_objects_swf6` | 12.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `native_objects_swf7` | 12.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `native_objects_swf8` | 12.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `netstream_play_flv_screen` | 25.3s |  |
| 9 | `on_construct` | 11.8s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 10 | `register_and_init_order` | 12.1s | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 11 | `register_class_with_sound` | 11.8s | [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 12 | `string_paths_timer` | 11.8s |  |
| 13 | `timer_run_actions` | 14.7s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 32.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 32.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 19.7s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**218 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `selection` | 95.6% | 434/454 | 454 | 454 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 4 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 5 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 6 | `edittext_antialiastype` | 92.6% | 274/296 | 296 | 296 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `tab_ordering_children` | 87.0% | 181/208 | 190 | 208 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 8 | `super_edge_cases` | 84.6% | 33/39 | 37 | 39 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 9 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 10 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 11 | `function_base_clip_removed` | 80.0% | 20/25 | 25 | 25 |  |
| 12 | `tell_target_invalid_swf6` | 80.0% | 4/5 | 4 | 5 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 78.7% | 266/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 15 | `button_keypress_vs_textinput` | 75.0% | 3/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 16 | `clip_constructors` | 75.0% | 6/8 | 8 | 8 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 17 | `create_empty_movie_clip` | 75.0% | 3/4 | 4 | 3 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 19 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 20 | `edittext_scroll` | 74.1% | 40/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 22 | `rewind_depth` | 73.3% | 22/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 24 | `tab_ordering_tabbable` | 70.2% | 33/47 | 47 | 47 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 25 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 26 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `unload` | 69.2% | 36/52 | 52 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 28 | `textsnapshot_props_swf5` | 67.9% | 38/56 | 56 | 56 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_hscroll` | 66.7% | 18/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `issue_768` | 66.7% | 2/3 | 3 | 3 | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 32 | `tell_target_invalid` | 66.7% | 4/6 | 4 | 6 | [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 33 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 34 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_autosize` | 62.0% | 44/71 | 71 | 71 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_newlines` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_password` | 60.0% | 3/5 | 5 | 5 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `place_and_lookup` | 60.0% | 18/30 | 30 | 30 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 45 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 47 | `execution_order4` | 58.3% | 7/12 | 11 | 12 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 48 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 49 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 50 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 52 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 54 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 55 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 56 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 59 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 60 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 61 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 62 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 66 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 67 | `loadmovie_var_persistence` | 50.0% | 4/8 | 5 | 8 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 68 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 69 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 70 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 71 | `selection_handlers` | 48.1% | 13/27 | 19 | 27 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 72 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 73 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 74 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 75 | `focus_mouse` | 44.4% | 20/45 | 38 | 45 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 76 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 77 | `native_double_construct` | 41.7% | 5/12 | 11 | 12 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 80 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 81 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 82 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 83 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 84 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 85 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 86 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 87 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 88 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 89 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 90 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 91 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 92 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 93 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 94 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 95 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 97 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 98 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 99 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 100 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 101 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 102 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 103 | `clone_sprite_edittext` | 25.5% | 24/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `sound` | 25.5% | 160/628 | 628 | 628 |  |
| 105 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 106 | `issue_2870` | 25.0% | 2/8 | 8 | 3 |  |
| 107 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 108 | `edittext_tag_indent` | 22.6% | 7/31 | 31 | 31 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 110 | `this_scoping` | 20.8% | 11/53 | 53 | 52 | [42](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 111 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 112 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 113 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 114 | `register_class_swf6` | 18.9% | 7/37 | 10 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 115 | `focus_remove` | 18.2% | 6/33 | 21 | 33 |  |
| 116 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 118 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 119 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 120 | `focus_visibility_change` | 15.6% | 7/45 | 33 | 45 |  |
| 121 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 122 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 123 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 124 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 125 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `mcl_events_swf_version` | 13.8% | 32/232 | 37 | 232 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 127 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 128 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 129 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 130 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 131 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 132 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 133 | `tab_ordering_movieclip_enabled_default` | 11.9% | 55/462 | 420 | 462 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 134 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 135 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 136 | `register_class` | 10.6% | 7/66 | 52 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 137 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 138 | `tab_ordering_events` | 8.7% | 13/150 | 74 | 150 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 139 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 140 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 141 | `tab_ordering_events_mouse` | 7.7% | 5/65 | 48 | 65 | [39](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) |
| 142 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 143 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 144 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 146 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 147 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 148 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 149 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 150 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 151 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 152 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 153 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 154 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 155 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 156 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 157 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 158 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 159 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 160 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 161 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 162 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 163 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 164 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 165 | `focus_keyboard_press` | 0.7% | 1/138 | 138 | 60 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 166 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 167 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 168 | `global_proto_decls` | 0.4% | 20/4497 | 665 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 169 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 170 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 171 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 172 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 173 | `bitmap_filters` | 0.0% | 0/548 | 0 | 548 | [25](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 174 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 175 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 177 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 178 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [33](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 179 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 180 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 181 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 183 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 184 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 185 | `file_reference_browse_cancel` | 0.0% | 0/21 | 0 | 21 |  |
| 186 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 187 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 188 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 189 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 190 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 191 | `global_proto_decls_delete` | 0.0% | 0/4158 | 303 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 192 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 193 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 194 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 195 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 196 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 197 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 198 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 199 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 200 | `netstream_play_flv` | 0.0% | 0/21 | 2 | 21 |  |
| 201 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 202 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 203 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 204 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 205 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 206 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 207 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 208 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 209 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 210 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 211 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 212 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 213 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 214 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 215 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 216 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 217 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 218 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 12 | 2 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
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
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 0 | 1 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 23 | 26 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 20 | 38 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 10 | 7 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 2 | 2 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 6 | 2 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 7 | 8 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 7 | 2 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 7 | 6 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PLAN.md) | 16 | 9 | 7 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 9 | 10 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 28 | 42 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/incomplete/THIS_BINDING_PLAN.md) | 5 | 4 | 1 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 9 | 3 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 3 | 2 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 148 | 82 |
