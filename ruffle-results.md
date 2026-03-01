# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-01 20:37 UTC

**Git SHA**: `3a734264f8`

**Run Duration**: 116m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **422** (68.2%) |
| Failing | 197 |
| Total expected lines | 91470 |
| Matching lines | 62275 (68.1%) |
| Mismatched lines | 29195 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 186 | 94.4% |
| Runtime Segfault | 5 | 2.5% |
| Runtime Error | 4 | 2.0% |
| Compile Fail | 1 | 0.5% |
| Timeout | 1 | 0.5% |

## Passing Tests

**422 tests passing**

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
| 17 | `array_sort` | 161 | 11.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 11.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 11.1s |  |
| 20 | `array_trivial` | 209 | 11.0s |  |
| 21 | `as1_constructor_v6` | 35 | 10.8s |  |
| 22 | `as1_constructor_v7` | 35 | 11.0s |  |
| 23 | `as2_oop` | 13 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 10.6s |  |
| 28 | `as_set_prop_flags` | 79 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 10.6s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 10.6s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 10.6s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 10.6s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 10.8s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 10.7s |  |
| 35 | `as_transformed_flag` | 20 | 10.9s |  |
| 36 | `attach_movie` | 59 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 10.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `bad_placeobject_clipaction` | 2 | 11.2s |  |
| 39 | `bad_swf_tag_past_eof` | 0 | 10.8s |  |
| 40 | `bitand` | 1058 | 13.5s |  |
| 41 | `bitmap_data_colortransform` | 0 | 11.3s |  |
| 42 | `bitmap_data_fillrect` | 0 | 11.0s |  |
| 43 | `bitmap_data_max_size_swf10` | 12 | 11.2s |  |
| 44 | `bitmap_data_max_size_swf9` | 10 | 11.1s |  |
| 45 | `bitmap_data_perlinnoise` | 0 | 11.8s |  |
| 46 | `bitmap_data_pixeldissolve_image` | 0 | 11.4s |  |
| 47 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.9s |  |
| 48 | `bitor` | 1058 | 13.8s |  |
| 49 | `biturshift` | 14 | 11.0s |  |
| 50 | `biturshift_swf8` | 14 | 11.4s |  |
| 51 | `bitxor` | 1058 | 13.9s |  |
| 52 | `boxed_primitives` | 24 | 11.3s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 53 | `button_children` | 8 | 11.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_goto` | 4 | 11.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events` | 14 | 11.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_key_events_special` | 45 | 12.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress` | 3 | 11.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_press` | 25 | 11.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_keypress_vs_tab` | 20 | 11.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_order` | 2 | 11.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_properties_special_cases` | 22 | 11.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_v5` | 18 | 11.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_v6` | 18 | 11.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `call_method_empty_name` | 1 | 11.2s |  |
| 65 | `capabilities_resolution` | 8 | 11.2s |  |
| 66 | `catch_references_registers` | 2 | 11.2s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 67 | `click_block` | 5 | 11.3s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 68 | `clip_constructors` | 8 | 11.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 69 | `clip_events` | 19 | 11.5s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 70 | `clone_sprite_types` | 24 | 11.2s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `closure_scope` | 7 | 11.2s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 72 | `color` | 57 | 11.5s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `color_transform` | 48 | 11.4s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 74 | `conflicting_instance_names` | 23 | 11.4s |  |
| 75 | `constructor_function` | 2 | 11.2s |  |
| 76 | `context_menu` | 39 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 77 | `context_menu_item` | 41 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 78 | `create_empty_movie_clip` | 3 | 11.3s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `define_function2` | 8 | 11.1s |  |
| 80 | `define_function2_preload` | 13 | 11.3s |  |
| 81 | `define_function2_preload_order` | 4 | 11.0s |  |
| 82 | `define_function_case_sensitive` | 2 | 10.7s |  |
| 83 | `delete` | 3 | 10.9s |  |
| 84 | `display_object_properties` | 2 | 10.8s |  |
| 85 | `divide_swf4` | 107 | 10.8s |  |
| 86 | `do_init_action` | 3 | 10.8s |  |
| 87 | `drag_drop` | 10 | 10.8s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 88 | `drag_over_from_outside` | 1 | 10.8s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 89 | `drag_over_without_startdrag` | 1 | 10.8s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 90 | `duplicate_movie_clip` | 20 | 10.7s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 91 | `edittext_align` | 60 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_antialiastype` | 296 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_autosize` | 71 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_autosize_setter` | 20 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_default_format` | 221 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_default_format_empty` | 95 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_default_format_font_style` | 335 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_font_size` | 45 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_html_align_swf7` | 52 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_align_swf8` | 52 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_entity` | 4 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_leading` | 9 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_margins` | 25 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_newline_stripping` | 64 | 15.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_password` | 5 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_password_copy` | 4 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_paste_empty` | 2 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_programmatic_focus` | 12 | 10.7s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_restrict_paste` | 5 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_tag_indent` | 31 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_text_height_leading` | 20 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_underline` | 40 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_width_height` | 103 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `empty_movieclip_can_attach_movies` | 11 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 115 | `enumerate` | 64 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 116 | `equals` | 32 | 11.6s |  |
| 117 | `equals2_swf5` | 926 | 13.4s |  |
| 118 | `equals2_swf6` | 926 | 13.5s |  |
| 119 | `equals2_swf7` | 926 | 13.7s |  |
| 120 | `equals_swf4` | 665 | 12.5s |  |
| 121 | `equals_swf4_alt` | 32 | 11.7s |  |
| 122 | `equals_swf5` | 32 | 11.6s |  |
| 123 | `error` | 58 | 11.5s |  |
| 124 | `escape` | 14 | 11.2s |  |
| 125 | `execution_order1` | 5 | 11.6s |  |
| 126 | `execution_order2` | 7 | 11.6s |  |
| 127 | `execution_order3` | 4 | 11.4s |  |
| 128 | `execution_order4` | 12 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 129 | `export_assets` | 3 | 11.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 130 | `extends_chain` | 134 | 11.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 131 | `extends_native_type` | 11 | 11.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 132 | `focus_root_movie` | 2 | 10.8s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 133 | `focusrect_focuslost` | 4 | 10.9s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 134 | `focusrect_mouse_swf8` | 0 | 10.8s |  |
| 135 | `focusrect_mouse_swf9` | 0 | 11.9s |  |
| 136 | `focusrect_swf5` | 6 | 11.0s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 137 | `focusrect_swf6` | 42 | 10.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 138 | `form_loader_encoding_1` | 1 | 10.8s |  |
| 139 | `function_suppress_and_preload` | 28 | 10.9s |  |
| 140 | `get_variable_in_scope` | 29 | 11.3s |  |
| 141 | `getproperty` | 28 | 11.7s |  |
| 142 | `getproperty_swf4` | 28 | 12.6s |  |
| 143 | `getproperty_swf5` | 28 | 11.1s |  |
| 144 | `global_array` | 3 | 11.1s |  |
| 145 | `global_is_bare` | 7 | 10.9s |  |
| 146 | `globals_swf5` | 304 | 11.5s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 147 | `globals_swf6` | 304 | 11.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 148 | `globals_swf7` | 304 | 11.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 149 | `globals_swf8` | 304 | 11.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 150 | `goto_advance1` | 6 | 10.9s |  |
| 151 | `goto_advance2` | 2 | 10.8s |  |
| 152 | `goto_both_ways1` | 3 | 10.8s |  |
| 153 | `goto_both_ways2` | 3 | 11.0s |  |
| 154 | `goto_execution_order` | 2 | 10.7s |  |
| 155 | `goto_execution_order2` | 2 | 10.8s |  |
| 156 | `goto_frame` | 12 | 12.3s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 157 | `goto_frame2` | 44 | 11.2s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 158 | `goto_frame_number` | 3 | 10.7s |  |
| 159 | `goto_label` | 17 | 10.8s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 160 | `goto_methods` | 40 | 10.8s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 161 | `goto_rewind1` | 1 | 10.7s |  |
| 162 | `goto_rewind2` | 3 | 10.7s |  |
| 163 | `goto_rewind3` | 2 | 10.7s |  |
| 164 | `greater_swf6` | 1175 | 12.6s |  |
| 165 | `greater_swf7` | 1175 | 12.6s |  |
| 166 | `greaterthan_swf5` | 1 | 10.6s |  |
| 167 | `greaterthan_swf8` | 1 | 10.6s |  |
| 168 | `has_own_property` | 32 | 10.7s |  |
| 169 | `hittest_lockroot` | 15 | 10.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 170 | `hittest_morph` | 70 | 10.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 171 | `hittest_winding_rule` | 12 | 10.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 172 | `infinite_recursion_function` | 4 | 10.6s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 173 | `infinite_recursion_function_in_setter` | 131 | 10.6s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 174 | `infinite_recursion_virtual_property` | 67 | 10.6s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 175 | `init_array_invalid` | 4 | 10.6s |  |
| 176 | `init_object_invalid` | 4 | 11.0s |  |
| 177 | `init_object_order` | 15 | 10.8s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 178 | `is_finite` | 49 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 179 | `is_finite_swf6` | 49 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 180 | `is_prototype_of` | 89 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 181 | `issue_1086` | 1 | 10.6s |  |
| 182 | `issue_1671` | 0 | 10.6s |  |
| 183 | `issue_1906` | 4 | 10.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 184 | `issue_2166` | 9 | 10.7s |  |
| 185 | `issue_3446` | 1 | 10.7s |  |
| 186 | `issue_3522` | 2 | 10.7s |  |
| 187 | `issue_4377` | 2 | 10.7s |  |
| 188 | `issue_710` | 4 | 10.7s |  |
| 189 | `issue_768` | 3 | 12.3s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 190 | `issue_9327` | 2 | 10.8s |  |
| 191 | `issue_9885` | 2 | 10.9s |  |
| 192 | `key_isToggled` | 9 | 10.8s |  |
| 193 | `lessthan` | 41 | 10.9s |  |
| 194 | `lessthan2_swf5` | 1226 | 12.9s |  |
| 195 | `lessthan2_swf6` | 1226 | 13.1s |  |
| 196 | `lessthan2_swf7` | 1226 | 12.9s |  |
| 197 | `lessthan_swf4` | 902 | 12.0s |  |
| 198 | `lessthan_swf4_alt` | 41 | 10.8s |  |
| 199 | `lessthan_swf5` | 41 | 10.8s |  |
| 200 | `loadmovie` | 2 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 201 | `loadmovie_fail` | 2 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 202 | `loadmovie_flashvars` | 4 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 203 | `loadmovie_method` | 2 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 204 | `loadmovie_replace_root` | 5 | 10.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 205 | `loadmovienum` | 3 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 206 | `loadvariables` | 2 | 10.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 207 | `loadvariables2` | 8 | 11.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 208 | `loadvariablesnum` | 2 | 10.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 209 | `local_to_global` | 49 | 11.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 210 | `localconnection_properties` | 8 | 10.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 211 | `lock_root` | 1 | 11.1s |  |
| 212 | `logical_ops_swf4` | 90 | 11.2s |  |
| 213 | `logical_ops_swf8` | 108 | 11.0s |  |
| 214 | `looping` | 6 | 11.0s |  |
| 215 | `mask_reapply` | 0 | 11.1s |  |
| 216 | `mask_with_drawing` | 0 | 11.2s |  |
| 217 | `math_min_max` | 101 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 218 | `math_swf6` | 530 | 11.5s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 219 | `math_swf7` | 530 | 11.3s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 220 | `math_swf8` | 530 | 11.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 221 | `matrix` | 171 | 11.3s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 222 | `mcl_as_broadcaster` | 12 | 11.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 223 | `mcl_getprogress` | 30 | 11.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 224 | `mcl_loadclip` | 149 | 10.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 225 | `mcl_loadclip_properties` | 6 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 226 | `mcl_mislabeled_target` | 6 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 227 | `mcl_target_gif87a` | 6 | 11.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 228 | `mcl_target_gif89a` | 6 | 11.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 229 | `mcl_target_jpg` | 6 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 230 | `mcl_target_png` | 6 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 231 | `mcl_unloadclip` | 5 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 232 | `mouse_events` | 8 | 10.8s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 233 | `mouse_events_visible_enabled` | 12 | 11.0s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 234 | `mouse_hover_events_while_dragging` | 1 | 10.9s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 235 | `mouse_listeners` | 67 | 10.7s |  |
| 236 | `mouse_pos` | 665 | 10.7s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 237 | `mouse_pos_with_scale_factor` | 260 | 10.7s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 238 | `mouse_wheel_enabled` | 2 | 10.7s |  |
| 239 | `movieclip_begin_gradient_fill` | 0 | 11.3s |  |
| 240 | `movieclip_blend_mode_property` | 35 | 12.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 241 | `movieclip_create_text_field` | 90 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 242 | `movieclip_default_state` | 69 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 243 | `movieclip_depth_methods` | 98 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 244 | `movieclip_focusenabled` | 99 | 10.7s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 245 | `movieclip_get_instance_at_depth` | 28 | 10.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 246 | `movieclip_hittest` | 92 | 10.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 247 | `movieclip_in_removed_button` | 4 | 10.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 248 | `movieclip_init_object` | 5 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 249 | `movieclip_line_gradient_style` | 0 | 11.6s |  |
| 250 | `movieclip_name_from_timeline` | 13 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 251 | `movieclip_prototype_extension` | 5 | 10.8s |  |
| 252 | `moviecliploader_flashvars` | 4 | 11.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 253 | `mutable_this` | 18 | 10.9s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 254 | `named_shapes` | 14 | 10.8s |  |
| 255 | `nan_scale` | 9 | 10.9s |  |
| 256 | `native_double_construct` | 12 | 10.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 257 | `native_objects_swf7` | 84 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 258 | `native_objects_swf8` | 84 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 259 | `native_subclasses` | 191 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 260 | `nested_textfields_in_buttons` | 0 | 10.8s |  |
| 261 | `new_method_wrap` | 4 | 10.8s |  |
| 262 | `new_object_enumerate` | 7 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 263 | `new_object_wrap` | 4 | 10.8s |  |
| 264 | `o` | 3 | 10.7s |  |
| 265 | `object_constructor` | 33 | 11.0s |  |
| 266 | `object_function` | 32 | 10.9s |  |
| 267 | `object_properties` | 31 | 11.2s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 268 | `object_prototypes` | 74 | 11.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 269 | `object_string_coerce_swf5` | 62 | 11.1s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 270 | `object_string_coerce_swf6` | 68 | 10.9s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 271 | `on_construct` | 25 | 11.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 272 | `parse_float` | 74 | 11.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 273 | `parse_int` | 64 | 11.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 274 | `path_string` | 322 | 11.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 275 | `place_and_lookup` | 30 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 276 | `placeobject_occupied_depth` | 6 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 277 | `point` | 175 | 11.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 278 | `primitive_instanceof` | 37 | 10.8s |  |
| 279 | `primitive_type_globals` | 557 | 11.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 280 | `printjob_props_swf5` | 45 | 10.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 281 | `printjob_props_swf6` | 45 | 10.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 282 | `printjob_props_swf7` | 45 | 10.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 283 | `property_invalid_base_clip` | 36 | 10.9s |  |
| 284 | `prototype_delete` | 12 | 10.7s |  |
| 285 | `prototype_enumerate` | 5 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 286 | `prototype_properties` | 17 | 10.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 287 | `rectangle` | 745 | 11.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 288 | `recursive_prototypes` | 0 | 10.7s |  |
| 289 | `register_class_return_value` | 16 | 10.7s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 290 | `register_globals_across_frames` | 15 | 10.7s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 291 | `register_underflow` | 26 | 10.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 292 | `remove_movie_clip` | 29 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 293 | `rewind_depth` | 30 | 10.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 294 | `sandbox_type_local_file` | 1 | 10.9s |  |
| 295 | `sandbox_type_local_network` | 1 | 10.8s |  |
| 296 | `set_interval` | 27 | 11.3s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 297 | `set_variable_scope` | 58 | 10.9s |  |
| 298 | `single_frame` | 1 | 10.8s |  |
| 299 | `slash_syntax` | 14 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 300 | `sound_props_swf5` | 68 | 10.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 301 | `sound_props_swf6` | 68 | 10.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 302 | `sound_start_load` | 0 | 10.8s |  |
| 303 | `stage_display_state` | 16 | 10.8s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 304 | `stage_object_children` | 83 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 305 | `stage_object_enumerate` | 4 | 10.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 306 | `stage_object_properties` | 241 | 11.1s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 307 | `stage_object_properties_get_var` | 5 | 10.7s |  |
| 308 | `stage_object_properties_swf6` | 231 | 11.0s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 309 | `stage_property_representation` | 586 | 10.7s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 310 | `stage_scale_mode` | 39 | 10.8s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 311 | `strictequals_swf6` | 902 | 12.2s |  |
| 312 | `strictly_equals` | 7 | 10.7s |  |
| 313 | `string_coercion` | 117 | 11.1s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 314 | `string_methods` | 285 | 11.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 315 | `string_methods_negative_args` | 240 | 10.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 316 | `string_methods_swfv5` | 275 | 11.3s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 317 | `string_ops_swf6` | 95 | 10.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 318 | `string_paths_basic` | 4 | 10.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 319 | `string_paths_hidden` | 54 | 10.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 320 | `string_paths_variable_alias` | 4 | 10.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 321 | `super_edge_cases` | 39 | 10.8s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 322 | `swf4_actions_bool` | 96 | 10.7s |  |
| 323 | `swf4_actions_coercion_order` | 158 | 10.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 324 | `swf4_bool` | 4 | 10.8s |  |
| 325 | `swf4_function_calls` | 7 | 10.8s |  |
| 326 | `swf5_encoding` | 3 | 10.7s |  |
| 327 | `swf5_no_closure` | 19 | 11.1s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 328 | `swf6_case_insensitive` | 42 | 11.0s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 329 | `swf6_string_as_bool` | 15 | 10.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 330 | `swf7_case_sensitive` | 44 | 11.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 331 | `tab_ordering_automatic_basic` | 92 | 10.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 332 | `tab_ordering_automatic_order_grid` | 21 | 10.7s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 333 | `tab_ordering_children` | 208 | 10.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 334 | `tab_ordering_custom_basic` | 71 | 10.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 335 | `tab_ordering_custom_duplicate_index` | 22 | 11.0s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 336 | `tab_ordering_custom_i32_vs_u32` | 12 | 10.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 337 | `tab_ordering_custom_m1` | 29 | 10.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 338 | `tab_ordering_events` | 150 | 11.3s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 339 | `tab_ordering_movieclip_enabled_default` | 462 | 11.0s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 340 | `tab_ordering_properties_tab_index_edge_case` | 4 | 10.7s |  |
| 341 | `tab_ordering_reverse` | 51 | 10.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 342 | `tab_ordering_tabbable` | 47 | 10.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 343 | `target_clip_removed` | 5 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 344 | `target_clip_swf5` | 2 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 345 | `target_clip_swf6` | 2 | 10.7s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 346 | `target_path` | 14 | 10.7s |  |
| 347 | `tell_target` | 37 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 348 | `tell_target_invalid` | 6 | 10.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 349 | `tell_target_invalid_swf6` | 5 | 10.9s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `text_format` | 1146 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 351 | `text_format_display` | 21 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 352 | `text_format_font_max_length` | 2 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 353 | `text_format_rounding_swf7` | 840 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 354 | `text_format_rounding_swf8` | 840 | 10.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 355 | `textfield_background_color` | 11 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 356 | `textfield_border_color` | 11 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 357 | `textfield_cache_as_bitmap` | 1 | 10.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 358 | `textfield_maxchars` | 3 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 359 | `textfield_properties` | 44 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 360 | `textfield_props_swf5` | 175 | 11.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 361 | `textfield_props_swf6` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 362 | `textfield_props_swf7` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 363 | `textfield_props_swf8` | 210 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 364 | `textfield_text` | 7 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 365 | `textfield_variable` | 81 | 10.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 366 | `textsnapshot_props_swf5` | 56 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 367 | `textsnapshot_props_swf6` | 56 | 10.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 368 | `this_scoping` | 52 | 10.8s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 369 | `this_swf5` | 41 | 10.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 370 | `this_swf6` | 41 | 10.7s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 371 | `this_swf7` | 41 | 10.7s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 372 | `timeline_function_def` | 7 | 10.8s |  |
| 373 | `transform` | 70 | 10.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 374 | `try_catch_finally` | 118 | 11.0s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 375 | `try_finally_simple` | 16 | 10.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 376 | `typeof` | 22 | 10.7s |  |
| 377 | `typeof_globals` | 7 | 10.8s |  |
| 378 | `uncaught_exception` | 1 | 10.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 379 | `uncaught_exception_bubbled` | 1 | 10.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 380 | `undefined_to_string_swf6` | 4 | 10.7s |  |
| 381 | `unescape` | 43 | 10.8s |  |
| 382 | `unload` | 52 | 11.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 383 | `unload_clip_event` | 4 | 10.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 384 | `unloadmovie` | 4 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 385 | `unloadmovie_method` | 3 | 10.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 386 | `unloadmovienum` | 13 | 10.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 387 | `use_hand_cursor` | 8 | 10.8s |  |
| 388 | `variable_args` | 5 | 11.0s |  |
| 389 | `waitforframe` | 7 | 10.8s |  |
| 390 | `waitforframe2` | 16 | 12.2s |  |
| 391 | `watch` | 117 | 12.2s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 392 | `watch_textfield` | 12 | 11.7s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 393 | `watch_virtual_property_proto` | 2 | 11.9s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 394 | `with` | 49 | 11.6s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 395 | `with_return` | 2 | 11.6s |  |
| 396 | `with_variable_scopes` | 43 | 11.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 397 | `xml` | 15 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 398 | `xml_append_child` | 28 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 399 | `xml_append_child_with_parent` | 20 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 400 | `xml_attributes_read` | 4 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 401 | `xml_cdata` | 11 | 11.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 402 | `xml_child_nodes_edge_cases` | 4 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xml_clone_expandos` | 19 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 404 | `xml_first_last_child` | 8 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 405 | `xml_has_child_nodes` | 3 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 406 | `xml_idmap` | 21 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 407 | `xml_ignore_comments` | 21 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 408 | `xml_ignore_white` | 34 | 11.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 409 | `xml_insert_before` | 20 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 410 | `xml_inspect_createmethods` | 15 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 411 | `xml_inspect_doctype` | 7 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 412 | `xml_inspect_parsexml` | 62 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 413 | `xml_inspect_xmldecl` | 7 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 414 | `xml_namespaces` | 203 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 415 | `xml_parent_and_child` | 5 | 10.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 416 | `xml_remove_node` | 22 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 417 | `xml_reparenting` | 14 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 418 | `xml_siblings` | 10 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 419 | `xml_to_string` | 13 | 10.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 420 | `xml_to_string_comment` | 1 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 421 | `xml_unescaping` | 23 | 10.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 422 | `xmlnode_proto` | 1 | 10.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**60 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `selection` | 99.6% | 452 | 454 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 2 | `date` | 99.2% | 6284 | 6335 | 51 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `edittext_letter_spacing` | 93.3% | 14 | 15 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `function_base_clip_removed` | 88.0% | 22 | 25 | 3 |  |
| 11 | `edittext_hscroll` | 85.2% | 23 | 27 | 4 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 15 | `edittext_align_trailing_spaces_swf7` | 81.2% | 468 | 576 | 108 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `button_keypress_vs_textinput` | 75.0% | 3 | 4 | 1 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 20 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 22 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 23 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 24 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 25 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 26 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_html_color` | 66.7% | 76 | 114 | 38 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 29 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 31 | `edittext_stylesheet` | 62.8% | 204 | 325 | 121 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360 | 576 | 216 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `clone_sprite_edittext_dynamic` | 61.6% | 53 | 86 | 33 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_html_swf8` | 59.6% | 3204 | 5377 | 2173 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 37 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 38 | `edittext_html_swf6` | 57.9% | 3114 | 5377 | 2263 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 40 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `edittext_html_swf7` | 56.6% | 3042 | 5377 | 2335 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 43 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 44 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 45 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `register_class_with_sound` | 54.5% | 6 | 11 | 5 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 47 | `edittext_html_condensewhite_swf7` | 53.4% | 166 | 311 | 145 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 49 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 50 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 51 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 52 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 53 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 57 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 58 | `loadmovie_var_persistence` | 50.0% | 4 | 8 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 59 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 60 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 12.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 13.3s |  |
| 3 | `netstream_play_flv_screen` | 26.0s |  |
| 4 | `string_paths_timer` | 12.8s |  |
| 5 | `timer_run_actions` | 13.5s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

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

**186 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `selection` | 99.6% | 452/454 | 454 | 454 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 2 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 8 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 9 | `edittext_letter_spacing` | 93.3% | 14/15 | 15 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `function_base_clip_removed` | 88.0% | 22/25 | 25 | 25 |  |
| 11 | `edittext_hscroll` | 85.2% | 23/27 | 27 | 27 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 15 | `edittext_align_trailing_spaces_swf7` | 81.2% | 468/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `button_keypress_vs_textinput` | 75.0% | 3/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 20 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 22 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 23 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 24 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 25 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 26 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_html_color` | 66.7% | 76/114 | 114 | 114 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 29 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 31 | `edittext_stylesheet` | 62.8% | 204/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360/576 | 576 | 576 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `clone_sprite_edittext_dynamic` | 61.6% | 53/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_html_swf8` | 59.6% | 3204/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 37 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 38 | `edittext_html_swf6` | 57.9% | 3114/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 40 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `edittext_html_swf7` | 56.6% | 3042/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 43 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 44 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 45 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `register_class_with_sound` | 54.5% | 6/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 47 | `edittext_html_condensewhite_swf7` | 53.4% | 166/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 49 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 50 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 51 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 52 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 53 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 57 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 58 | `loadmovie_var_persistence` | 50.0% | 4/8 | 5 | 8 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 59 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 60 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_html_condensewhite_swf8` | 49.8% | 155/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 63 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 64 | `bitmap_filters` | 46.4% | 254/548 | 548 | 548 | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 65 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 66 | `focus_mouse` | 44.4% | 20/45 | 38 | 45 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 67 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 68 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 69 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 70 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 71 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 72 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 73 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 74 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 75 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 76 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 77 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 78 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 80 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 81 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 82 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 83 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 84 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 85 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 86 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 87 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 88 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 89 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 90 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 91 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 92 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 94 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 95 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 96 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 97 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 98 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 99 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 100 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 101 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 102 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 103 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 104 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 105 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 106 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 107 | `mcl_events_swf_version` | 13.8% | 32/232 | 37 | 232 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 108 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 109 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 110 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 111 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 112 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 113 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 114 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 116 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 117 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 118 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 119 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 120 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 122 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 123 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 124 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 125 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 126 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 127 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 128 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 129 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 130 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 131 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 132 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 133 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 134 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 135 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 136 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 137 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 138 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 139 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 140 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 141 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 142 | `device_font_spacing` | 1.1% | 1/91 | 91 | 91 |  |
| 143 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 144 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 145 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 146 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 147 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 148 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 149 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 150 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 151 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 152 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 154 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 155 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 156 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 157 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 158 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 159 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 160 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 161 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 162 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 163 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 164 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 165 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 166 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 167 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 168 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 169 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 170 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 171 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 172 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 173 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 174 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 175 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 176 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 177 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 178 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 179 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 180 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 181 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 182 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 183 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 184 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 185 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 186 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
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
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 11 | 8 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 42 | 28 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 150 | 80 |
