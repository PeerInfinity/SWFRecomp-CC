# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-02 22:04 UTC

**Git SHA**: `8dfb5c276a`

**Run Duration**: 125m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **426** (68.8%) |
| Failing | 193 |
| Total expected lines | 91137 |
| Matching lines | 67811 (74.4%) |
| Mismatched lines | 23326 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 181 | 93.8% |
| Runtime Segfault | 5 | 2.6% |
| Runtime Error | 4 | 2.1% |
| Compile Fail | 2 | 1.0% |
| Timeout | 1 | 0.5% |

## Passing Tests

**426 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 11.8s |  |
| 2 | `action_to_integer` | 28 | 11.6s |  |
| 3 | `add` | 28 | 11.7s |  |
| 4 | `add2` | 354 | 11.8s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.0s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.3s |  |
| 7 | `add_swf5` | 28 | 12.0s |  |
| 8 | `arguments` | 127 | 12.1s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 11.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 11.5s |  |
| 11 | `array_constructor` | 30 | 11.6s |  |
| 12 | `array_enumerate` | 4 | 11.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 11.7s |  |
| 14 | `array_properties` | 36 | 11.7s |  |
| 15 | `array_prototyping` | 12 | 11.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 11.7s |  |
| 17 | `array_sort` | 161 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 11.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 12.3s |  |
| 20 | `array_trivial` | 209 | 12.2s |  |
| 21 | `as1_constructor_v6` | 35 | 12.0s |  |
| 22 | `as1_constructor_v7` | 35 | 12.2s |  |
| 23 | `as2_oop` | 13 | 12.0s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 12.2s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 11.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 11.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 12.0s |  |
| 28 | `as_set_prop_flags` | 79 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 11.7s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 11.7s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 11.7s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 11.7s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 11.7s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 11.7s |  |
| 35 | `as_transformed_flag` | 20 | 11.7s |  |
| 36 | `attach_movie` | 59 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `bad_placeobject_clipaction` | 2 | 11.9s |  |
| 39 | `bad_swf_tag_past_eof` | 0 | 11.5s |  |
| 40 | `bitand` | 1058 | 14.2s |  |
| 41 | `bitmap_data_colortransform` | 0 | 11.9s |  |
| 42 | `bitmap_data_fillrect` | 0 | 11.8s |  |
| 43 | `bitmap_data_max_size_swf10` | 12 | 11.5s |  |
| 44 | `bitmap_data_max_size_swf9` | 10 | 11.6s |  |
| 45 | `bitmap_data_perlinnoise` | 0 | 12.4s |  |
| 46 | `bitmap_data_pixeldissolve_image` | 0 | 12.1s |  |
| 47 | `bitmapdata_applyfilter_colormatrix` | 0 | 11.7s |  |
| 48 | `bitor` | 1058 | 14.1s |  |
| 49 | `biturshift` | 14 | 11.7s |  |
| 50 | `biturshift_swf8` | 14 | 13.0s |  |
| 51 | `bitxor` | 1058 | 14.3s |  |
| 52 | `boxed_primitives` | 24 | 11.8s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 53 | `button_children` | 8 | 11.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_goto` | 4 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events` | 14 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_key_events_special` | 45 | 12.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress` | 3 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_press` | 25 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_keypress_vs_tab` | 20 | 11.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_order` | 2 | 11.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_properties_special_cases` | 22 | 11.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_v5` | 18 | 11.6s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_v6` | 18 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `call_method_empty_name` | 1 | 11.6s |  |
| 65 | `capabilities_resolution` | 8 | 11.7s |  |
| 66 | `catch_references_registers` | 2 | 11.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 67 | `click_block` | 5 | 11.7s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 68 | `clip_constructors` | 8 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 69 | `clip_events` | 19 | 12.0s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 70 | `clone_sprite_types` | 24 | 11.6s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `closure_scope` | 7 | 11.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 72 | `color` | 57 | 12.0s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `color_transform` | 48 | 11.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 74 | `conflicting_instance_names` | 23 | 11.8s |  |
| 75 | `constructor_function` | 2 | 11.7s |  |
| 76 | `context_menu` | 39 | 11.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 77 | `context_menu_item` | 41 | 11.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 78 | `create_empty_movie_clip` | 3 | 11.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `define_function2` | 8 | 11.5s |  |
| 80 | `define_function2_preload` | 13 | 11.5s |  |
| 81 | `define_function2_preload_order` | 4 | 13.3s |  |
| 82 | `define_function_case_sensitive` | 2 | 12.1s |  |
| 83 | `delete` | 3 | 12.1s |  |
| 84 | `display_object_properties` | 2 | 12.5s |  |
| 85 | `divide_swf4` | 107 | 12.9s |  |
| 86 | `do_init_action` | 3 | 12.7s |  |
| 87 | `drag_drop` | 10 | 12.2s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 88 | `drag_over_from_outside` | 1 | 12.3s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 89 | `drag_over_without_startdrag` | 1 | 12.3s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 90 | `duplicate_movie_clip` | 20 | 12.0s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 91 | `edittext_align` | 60 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `edittext_align_trailing_spaces_swf7` | 576 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `edittext_align_trailing_spaces_swf8` | 576 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_antialiastype` | 296 | 12.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_autosize` | 71 | 13.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_autosize_setter` | 20 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_default_format` | 221 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_default_format_font_style` | 335 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_font_size` | 45 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_hscroll` | 27 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_align_swf7` | 52 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_html_align_swf8` | 52 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_color` | 114 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_entity` | 4 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_roundtrip` | 17 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_leading` | 9 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_letter_spacing` | 15 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_margins` | 25 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_password` | 5 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_password_copy` | 4 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_paste_empty` | 2 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_programmatic_focus` | 12 | 12.5s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_restrict_paste` | 5 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_tag_indent` | 31 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_text_height_leading` | 20 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_underline` | 40 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_width_height` | 103 | 12.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `empty_movieclip_can_attach_movies` | 11 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 119 | `enumerate` | 64 | 11.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 120 | `equals` | 32 | 11.8s |  |
| 121 | `equals2_swf5` | 926 | 13.5s |  |
| 122 | `equals2_swf6` | 926 | 13.5s |  |
| 123 | `equals2_swf7` | 926 | 13.4s |  |
| 124 | `equals_swf4` | 665 | 12.5s |  |
| 125 | `equals_swf4_alt` | 32 | 11.8s |  |
| 126 | `equals_swf5` | 32 | 11.8s |  |
| 127 | `error` | 58 | 11.7s |  |
| 128 | `escape` | 14 | 11.7s |  |
| 129 | `execution_order1` | 5 | 11.7s |  |
| 130 | `execution_order2` | 7 | 11.8s |  |
| 131 | `execution_order3` | 4 | 11.7s |  |
| 132 | `execution_order4` | 12 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 133 | `export_assets` | 3 | 11.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 134 | `extends_chain` | 134 | 12.1s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 135 | `extends_native_type` | 11 | 11.7s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 136 | `focus_root_movie` | 2 | 11.5s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 137 | `focusrect_focuslost` | 4 | 11.5s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 138 | `focusrect_mouse_swf8` | 0 | 11.5s |  |
| 139 | `focusrect_mouse_swf9` | 0 | 11.8s |  |
| 140 | `focusrect_swf5` | 6 | 11.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 141 | `focusrect_swf6` | 42 | 11.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 142 | `form_loader_encoding_1` | 1 | 11.7s |  |
| 143 | `function_suppress_and_preload` | 28 | 11.8s |  |
| 144 | `get_variable_in_scope` | 29 | 11.7s |  |
| 145 | `getproperty` | 28 | 11.6s |  |
| 146 | `getproperty_swf4` | 28 | 12.0s |  |
| 147 | `getproperty_swf5` | 28 | 12.0s |  |
| 148 | `global_array` | 3 | 12.0s |  |
| 149 | `global_is_bare` | 7 | 11.9s |  |
| 150 | `globals_swf5` | 304 | 12.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 151 | `globals_swf6` | 304 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 152 | `globals_swf7` | 304 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 153 | `globals_swf8` | 304 | 12.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 154 | `goto_advance1` | 6 | 12.0s |  |
| 155 | `goto_advance2` | 2 | 12.0s |  |
| 156 | `goto_both_ways1` | 3 | 12.0s |  |
| 157 | `goto_both_ways2` | 3 | 12.1s |  |
| 158 | `goto_execution_order` | 2 | 12.1s |  |
| 159 | `goto_execution_order2` | 2 | 12.1s |  |
| 160 | `goto_frame` | 12 | 13.9s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 161 | `goto_frame2` | 44 | 12.6s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 162 | `goto_frame_number` | 3 | 12.5s |  |
| 163 | `goto_label` | 17 | 12.4s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 164 | `goto_methods` | 40 | 12.1s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 165 | `goto_rewind1` | 1 | 12.1s |  |
| 166 | `goto_rewind2` | 3 | 12.5s |  |
| 167 | `goto_rewind3` | 2 | 12.2s |  |
| 168 | `greater_swf6` | 1175 | 14.5s |  |
| 169 | `greater_swf7` | 1175 | 14.3s |  |
| 170 | `greaterthan_swf5` | 1 | 12.2s |  |
| 171 | `greaterthan_swf8` | 1 | 12.2s |  |
| 172 | `has_own_property` | 32 | 11.9s |  |
| 173 | `hittest_lockroot` | 15 | 12.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 174 | `hittest_morph` | 70 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 175 | `hittest_winding_rule` | 12 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 176 | `infinite_recursion_function` | 4 | 11.9s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 177 | `infinite_recursion_function_in_setter` | 131 | 12.0s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 178 | `infinite_recursion_virtual_property` | 67 | 12.1s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 179 | `init_array_invalid` | 4 | 12.2s |  |
| 180 | `init_object_invalid` | 4 | 11.8s |  |
| 181 | `init_object_order` | 15 | 11.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 182 | `is_finite` | 49 | 11.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 183 | `is_finite_swf6` | 49 | 11.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 184 | `is_prototype_of` | 89 | 11.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 185 | `issue_1086` | 1 | 11.6s |  |
| 186 | `issue_1671` | 0 | 11.8s |  |
| 187 | `issue_1906` | 4 | 11.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 188 | `issue_2166` | 9 | 11.7s |  |
| 189 | `issue_3446` | 1 | 12.1s |  |
| 190 | `issue_3522` | 2 | 12.5s |  |
| 191 | `issue_4377` | 2 | 12.6s |  |
| 192 | `issue_710` | 4 | 12.3s |  |
| 193 | `issue_768` | 3 | 11.8s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 194 | `issue_9327` | 2 | 11.8s |  |
| 195 | `issue_9885` | 2 | 11.8s |  |
| 196 | `key_isToggled` | 9 | 11.7s |  |
| 197 | `lessthan` | 41 | 11.8s |  |
| 198 | `lessthan2_swf5` | 1226 | 13.9s |  |
| 199 | `lessthan2_swf6` | 1226 | 13.8s |  |
| 200 | `lessthan2_swf7` | 1226 | 13.8s |  |
| 201 | `lessthan_swf4` | 902 | 12.8s |  |
| 202 | `lessthan_swf4_alt` | 41 | 11.6s |  |
| 203 | `lessthan_swf5` | 41 | 11.7s |  |
| 204 | `loadmovie` | 2 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 205 | `loadmovie_fail` | 2 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 206 | `loadmovie_flashvars` | 4 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 207 | `loadmovie_method` | 2 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 208 | `loadmovie_replace_root` | 5 | 11.6s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 209 | `loadmovienum` | 3 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 210 | `loadvariables` | 2 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 211 | `loadvariables2` | 8 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 212 | `loadvariablesnum` | 2 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 213 | `local_to_global` | 49 | 11.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 214 | `localconnection_properties` | 8 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 215 | `lock_root` | 1 | 11.8s |  |
| 216 | `logical_ops_swf4` | 90 | 11.8s |  |
| 217 | `logical_ops_swf8` | 108 | 11.8s |  |
| 218 | `looping` | 6 | 11.8s |  |
| 219 | `mask_reapply` | 0 | 11.8s |  |
| 220 | `mask_with_drawing` | 0 | 11.8s |  |
| 221 | `math_min_max` | 101 | 11.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 222 | `math_swf6` | 530 | 12.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 223 | `math_swf7` | 530 | 12.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 224 | `math_swf8` | 530 | 12.2s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 225 | `matrix` | 171 | 12.1s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 226 | `mcl_as_broadcaster` | 12 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 227 | `mcl_getprogress` | 30 | 13.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 228 | `mcl_loadclip` | 149 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 229 | `mcl_loadclip_properties` | 6 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 230 | `mcl_mislabeled_target` | 6 | 12.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 231 | `mcl_target_gif87a` | 6 | 12.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 232 | `mcl_target_gif89a` | 6 | 12.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 233 | `mcl_target_jpg` | 6 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 234 | `mcl_target_png` | 6 | 12.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 235 | `mcl_unloadclip` | 5 | 12.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 236 | `mouse_events` | 8 | 11.8s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 237 | `mouse_events_visible_enabled` | 12 | 12.0s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 238 | `mouse_hover_events_while_dragging` | 1 | 12.1s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 239 | `mouse_listeners` | 67 | 11.8s |  |
| 240 | `mouse_pos` | 665 | 11.8s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 241 | `mouse_pos_with_scale_factor` | 260 | 11.8s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 242 | `mouse_wheel_enabled` | 2 | 11.7s |  |
| 243 | `movieclip_begin_gradient_fill` | 0 | 12.4s |  |
| 244 | `movieclip_blend_mode_property` | 35 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 245 | `movieclip_create_text_field` | 90 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 246 | `movieclip_default_state` | 69 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 247 | `movieclip_depth_methods` | 98 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 248 | `movieclip_focusenabled` | 99 | 11.7s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 249 | `movieclip_get_instance_at_depth` | 28 | 11.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 250 | `movieclip_hittest` | 92 | 11.7s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 251 | `movieclip_in_removed_button` | 4 | 11.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 252 | `movieclip_init_object` | 5 | 11.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 253 | `movieclip_line_gradient_style` | 0 | 13.5s |  |
| 254 | `movieclip_name_from_timeline` | 13 | 11.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 255 | `movieclip_prototype_extension` | 5 | 11.7s |  |
| 256 | `moviecliploader_flashvars` | 4 | 11.6s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 257 | `mutable_this` | 18 | 11.6s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 258 | `named_shapes` | 14 | 11.6s |  |
| 259 | `nan_scale` | 9 | 11.7s |  |
| 260 | `native_double_construct` | 12 | 11.7s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 261 | `native_objects_swf7` | 84 | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 262 | `native_objects_swf8` | 84 | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 263 | `native_subclasses` | 191 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 264 | `nested_textfields_in_buttons` | 0 | 11.6s |  |
| 265 | `new_method_wrap` | 4 | 11.7s |  |
| 266 | `new_object_enumerate` | 7 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 267 | `new_object_wrap` | 4 | 11.7s |  |
| 268 | `o` | 3 | 11.9s |  |
| 269 | `object_constructor` | 33 | 11.7s |  |
| 270 | `object_function` | 32 | 11.8s |  |
| 271 | `object_properties` | 31 | 11.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 272 | `object_prototypes` | 74 | 11.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 273 | `object_string_coerce_swf5` | 62 | 11.7s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 274 | `object_string_coerce_swf6` | 68 | 11.8s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 275 | `on_construct` | 25 | 11.8s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 276 | `parse_float` | 74 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 277 | `parse_int` | 64 | 12.1s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 278 | `path_string` | 322 | 11.9s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 279 | `place_and_lookup` | 30 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 280 | `placeobject_occupied_depth` | 6 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 281 | `point` | 175 | 12.0s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 282 | `primitive_instanceof` | 37 | 11.7s |  |
| 283 | `primitive_type_globals` | 557 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 284 | `printjob_props_swf5` | 45 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 285 | `printjob_props_swf6` | 45 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 286 | `printjob_props_swf7` | 45 | 11.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 287 | `property_invalid_base_clip` | 36 | 12.1s |  |
| 288 | `prototype_delete` | 12 | 11.7s |  |
| 289 | `prototype_enumerate` | 5 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 290 | `prototype_properties` | 17 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 291 | `rectangle` | 745 | 12.5s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 292 | `recursive_prototypes` | 0 | 11.7s |  |
| 293 | `register_class_return_value` | 16 | 11.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 294 | `register_globals_across_frames` | 15 | 11.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 295 | `register_underflow` | 26 | 11.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 296 | `remove_movie_clip` | 29 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 297 | `rewind_depth` | 30 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 298 | `sandbox_type_local_file` | 1 | 11.6s |  |
| 299 | `sandbox_type_local_network` | 1 | 11.4s |  |
| 300 | `set_interval` | 27 | 11.7s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 301 | `set_variable_scope` | 58 | 11.8s |  |
| 302 | `single_frame` | 1 | 11.7s |  |
| 303 | `slash_syntax` | 14 | 12.0s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 304 | `sound_props_swf5` | 68 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 305 | `sound_props_swf6` | 68 | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 306 | `sound_start_load` | 0 | 12.1s |  |
| 307 | `stage_display_state` | 16 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 308 | `stage_object_children` | 83 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 309 | `stage_object_enumerate` | 4 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 310 | `stage_object_properties` | 241 | 12.3s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 311 | `stage_object_properties_get_var` | 5 | 12.1s |  |
| 312 | `stage_object_properties_swf6` | 231 | 12.5s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 313 | `stage_property_representation` | 586 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 314 | `stage_scale_mode` | 39 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 315 | `strictequals_swf6` | 902 | 13.7s |  |
| 316 | `strictly_equals` | 7 | 12.0s |  |
| 317 | `string_coercion` | 117 | 12.3s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 318 | `string_methods` | 285 | 12.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 319 | `string_methods_negative_args` | 240 | 12.2s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 320 | `string_methods_swfv5` | 275 | 12.4s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 321 | `string_ops_swf6` | 95 | 11.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 322 | `string_paths_basic` | 4 | 11.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 323 | `string_paths_hidden` | 54 | 11.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 324 | `string_paths_variable_alias` | 4 | 11.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 325 | `super_edge_cases` | 39 | 11.9s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 326 | `swf4_actions_bool` | 96 | 11.7s |  |
| 327 | `swf4_actions_coercion_order` | 158 | 11.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 328 | `swf4_bool` | 4 | 11.6s |  |
| 329 | `swf4_function_calls` | 7 | 11.6s |  |
| 330 | `swf5_encoding` | 3 | 11.7s |  |
| 331 | `swf5_no_closure` | 19 | 11.8s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 332 | `swf6_case_insensitive` | 42 | 11.6s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 333 | `swf6_string_as_bool` | 15 | 11.6s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 334 | `swf7_case_sensitive` | 44 | 11.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 335 | `tab_ordering_automatic_basic` | 92 | 11.7s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 336 | `tab_ordering_automatic_order_grid` | 21 | 11.7s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 337 | `tab_ordering_children` | 208 | 11.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 338 | `tab_ordering_custom_basic` | 71 | 11.6s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 339 | `tab_ordering_custom_duplicate_index` | 22 | 11.7s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 340 | `tab_ordering_custom_i32_vs_u32` | 12 | 11.6s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 341 | `tab_ordering_custom_m1` | 29 | 11.6s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 342 | `tab_ordering_events` | 150 | 11.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 343 | `tab_ordering_movieclip_enabled_default` | 462 | 11.7s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 344 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.2s |  |
| 345 | `tab_ordering_reverse` | 51 | 12.2s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 346 | `tab_ordering_tabbable` | 47 | 12.3s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 347 | `target_clip_removed` | 5 | 12.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 348 | `target_clip_swf5` | 2 | 12.3s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 349 | `target_clip_swf6` | 2 | 12.1s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `target_path` | 14 | 12.2s |  |
| 351 | `tell_target` | 37 | 12.2s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 352 | `tell_target_invalid` | 6 | 12.3s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 353 | `tell_target_invalid_swf6` | 5 | 12.3s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 354 | `text_format` | 1146 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 355 | `text_format_display` | 21 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 356 | `text_format_font_max_length` | 2 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 357 | `text_format_rounding_swf7` | 840 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 358 | `text_format_rounding_swf8` | 840 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 359 | `textfield_background_color` | 11 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 360 | `textfield_border_color` | 11 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 361 | `textfield_cache_as_bitmap` | 1 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 362 | `textfield_maxchars` | 3 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 363 | `textfield_properties` | 44 | 11.6s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 364 | `textfield_props_swf5` | 175 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 365 | `textfield_props_swf6` | 210 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 366 | `textfield_props_swf7` | 210 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 367 | `textfield_props_swf8` | 210 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 368 | `textfield_text` | 7 | 11.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 369 | `textfield_variable` | 81 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 370 | `textsnapshot_props_swf5` | 56 | 11.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 371 | `textsnapshot_props_swf6` | 56 | 11.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 372 | `this_scoping` | 52 | 11.5s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 373 | `this_swf5` | 41 | 11.4s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 374 | `this_swf6` | 41 | 11.4s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 375 | `this_swf7` | 41 | 11.4s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 376 | `timeline_function_def` | 7 | 11.6s |  |
| 377 | `transform` | 70 | 11.9s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 378 | `try_catch_finally` | 118 | 11.9s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 379 | `try_finally_simple` | 16 | 11.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 380 | `typeof` | 22 | 11.9s |  |
| 381 | `typeof_globals` | 7 | 11.7s |  |
| 382 | `uncaught_exception` | 1 | 11.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 383 | `uncaught_exception_bubbled` | 1 | 11.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 384 | `undefined_to_string_swf6` | 4 | 11.7s |  |
| 385 | `unescape` | 43 | 11.7s |  |
| 386 | `unload` | 52 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 387 | `unload_clip_event` | 4 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 388 | `unloadmovie` | 4 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 389 | `unloadmovie_method` | 3 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 390 | `unloadmovienum` | 13 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 391 | `use_hand_cursor` | 8 | 11.7s |  |
| 392 | `variable_args` | 5 | 11.8s |  |
| 393 | `waitforframe` | 7 | 11.7s |  |
| 394 | `waitforframe2` | 16 | 11.7s |  |
| 395 | `watch` | 117 | 11.8s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 396 | `watch_textfield` | 12 | 11.5s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 397 | `watch_virtual_property_proto` | 2 | 11.5s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 398 | `with` | 49 | 11.5s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 399 | `with_return` | 2 | 11.4s |  |
| 400 | `with_variable_scopes` | 43 | 11.5s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 401 | `xml` | 15 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 402 | `xml_append_child` | 28 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 403 | `xml_append_child_with_parent` | 20 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 404 | `xml_attributes_read` | 4 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 405 | `xml_cdata` | 11 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 406 | `xml_child_nodes_edge_cases` | 4 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 407 | `xml_clone_expandos` | 19 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 408 | `xml_first_last_child` | 8 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 409 | `xml_has_child_nodes` | 3 | 11.4s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 410 | `xml_idmap` | 21 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 411 | `xml_ignore_comments` | 21 | 11.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 412 | `xml_ignore_white` | 34 | 13.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 413 | `xml_insert_before` | 20 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 414 | `xml_inspect_createmethods` | 15 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 415 | `xml_inspect_doctype` | 7 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 416 | `xml_inspect_parsexml` | 62 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 417 | `xml_inspect_xmldecl` | 7 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 418 | `xml_namespaces` | 203 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 419 | `xml_parent_and_child` | 5 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 420 | `xml_remove_node` | 22 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 421 | `xml_reparenting` | 14 | 11.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 422 | `xml_siblings` | 10 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 423 | `xml_to_string` | 13 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 424 | `xml_to_string_comment` | 1 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 425 | `xml_unescaping` | 23 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 426 | `xmlnode_proto` | 1 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**56 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_html_swf7` | 99.9% | 5374 | 5377 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `edittext_html_swf8` | 99.9% | 5374 | 5377 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 3 | `selection` | 99.6% | 452 | 454 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 4 | `date` | 99.2% | 6284 | 6335 | 51 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 5 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 11 | `frame_size_translated_negative` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 12 | `frame_size_translated_positive` | 95.2% | 20 | 21 | 1 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 13 | `function_base_clip_removed` | 88.0% | 22 | 25 | 3 |  |
| 14 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 16 | `edittext_restrict` | 77.0% | 147 | 191 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `button_keypress_vs_textinput` | 75.0% | 3 | 4 | 1 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 20 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 22 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 23 | `global_swf6_7_8` | 73.3% | 11 | 15 | 4 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 24 | `edittext_html_swf6` | 72.5% | 3897 | 5377 | 1480 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `string_paths_eval2` | 71.4% | 5 | 7 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 26 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 27 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 29 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 30 | `edittext_stylesheet` | 62.8% | 204 | 325 | 121 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 33 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 34 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 35 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 36 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `edittext_html_condensewhite_swf8` | 56.9% | 177 | 311 | 134 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 39 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 40 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 41 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 42 | `register_class_with_sound` | 54.5% | 6 | 11 | 5 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 43 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 44 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 45 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 46 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 47 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 48 | `do_init_action_child` | 50.0% | 6 | 12 | 6 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 49 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 53 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 54 | `loadmovie_var_persistence` | 50.0% | 4 | 8 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 55 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 56 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 14.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 13.8s |  |
| 3 | `netstream_play_flv_screen` | 26.3s |  |
| 4 | `string_paths_timer` | 13.7s |  |
| 5 | `timer_run_actions` | 14.1s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_3` | exit code -6 | 12.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_4` | exit code -6 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 34.0s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 34.3s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 21.4s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**181 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_html_swf7` | 99.9% | 5374/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `edittext_html_swf8` | 99.9% | 5374/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 3 | `selection` | 99.6% | 452/454 | 454 | 454 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 4 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [7](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 5 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 6 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 11 | `frame_size_translated_negative` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 12 | `frame_size_translated_positive` | 95.2% | 20/21 | 20 | 21 | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 13 | `function_base_clip_removed` | 88.0% | 22/25 | 25 | 25 |  |
| 14 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 16 | `edittext_restrict` | 77.0% | 147/191 | 191 | 191 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `button_keypress_vs_textinput` | 75.0% | 3/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 20 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 22 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 23 | `global_swf6_7_8` | 73.3% | 11/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 24 | `edittext_html_swf6` | 72.5% | 3897/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `string_paths_eval2` | 71.4% | 5/7 | 7 | 7 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 26 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 27 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 29 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 30 | `edittext_stylesheet` | 62.8% | 204/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 33 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 34 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 35 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 36 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 37 | `edittext_html_condensewhite_swf8` | 56.9% | 177/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 39 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 40 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 41 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 42 | `register_class_with_sound` | 54.5% | 6/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 43 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 44 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 45 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 46 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 47 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 48 | `do_init_action_child` | 50.0% | 6/12 | 6 | 12 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 49 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 53 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 54 | `loadmovie_var_persistence` | 50.0% | 4/8 | 5 | 8 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 55 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 56 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 58 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 59 | `bitmap_filters` | 46.4% | 254/548 | 548 | 548 | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 60 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 61 | `focus_mouse` | 44.4% | 20/45 | 38 | 45 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 62 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 63 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 64 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 65 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 66 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 67 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 68 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 69 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 70 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 71 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 72 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 73 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 74 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 75 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 76 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 77 | `input_dead_keys_windows` | 33.3% | 5/15 | 14 | 15 |  |
| 78 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 79 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 80 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 81 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 82 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 84 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 85 | `edittext_newline_stripping` | 29.7% | 19/64 | 60 | 64 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 86 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 87 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 90 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 91 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 92 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 93 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 94 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 95 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 96 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 97 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 98 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 99 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 100 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 101 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 102 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 103 | `mcl_events_swf_version` | 13.8% | 32/232 | 37 | 232 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 104 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 105 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 106 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 107 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 108 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 109 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 110 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `loadmovienum_cross_version_prototype` | 11.1% | 1/9 | 1 | 9 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 112 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 113 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 114 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 115 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 116 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 118 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 119 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 120 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 121 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 122 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 123 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 124 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 125 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 126 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 127 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 128 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 129 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 130 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 131 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 132 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 133 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 134 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 135 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 136 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 137 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 138 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 139 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 140 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 141 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 142 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 143 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 144 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 145 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 146 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 147 | `edittext_input` | 0.0% | 0/1 | 0 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_input_newlines` | 0.0% | 0/9 | 4 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 149 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 150 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 151 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 152 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 153 | `focus_mouse_rollout` | 0.0% | 0/4 | 1 | 4 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 154 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 155 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 156 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 157 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 158 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 159 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 160 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 161 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 162 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 163 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 164 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 165 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 166 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 167 | `resolve_different_root` | 0.0% | 0/2 | 2 | 2 |  |
| 168 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 169 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 170 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 171 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 172 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 173 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 174 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 175 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 176 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 177 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 178 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 179 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 180 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 181 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 46 | 24 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 150 | 80 |
