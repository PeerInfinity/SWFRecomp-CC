# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-03 02:23 UTC

**Git SHA**: `245c5872b9`

**Run Duration**: 127m 29s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **433** (70.0%) |
| Failing | 186 |
| Total expected lines | 91475 |
| Matching lines | 68149 (74.5%) |
| Mismatched lines | 23326 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 177 | 95.2% |
| Runtime Segfault | 5 | 2.7% |
| Runtime Error | 2 | 1.1% |
| Compile Fail | 1 | 0.5% |
| Timeout | 1 | 0.5% |

## Passing Tests

**433 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.5s |  |
| 2 | `action_to_integer` | 28 | 11.8s |  |
| 3 | `add` | 28 | 11.8s |  |
| 4 | `add2` | 354 | 11.9s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 11.7s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 11.8s |  |
| 7 | `add_swf5` | 28 | 11.7s |  |
| 8 | `arguments` | 127 | 11.8s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 11.9s |  |
| 11 | `array_constructor` | 30 | 11.8s |  |
| 12 | `array_enumerate` | 4 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.0s |  |
| 14 | `array_properties` | 36 | 12.1s |  |
| 15 | `array_prototyping` | 12 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 11.8s |  |
| 17 | `array_sort` | 161 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 12.0s |  |
| 20 | `array_trivial` | 209 | 12.3s |  |
| 21 | `as1_constructor_v6` | 35 | 11.9s |  |
| 22 | `as1_constructor_v7` | 35 | 12.6s |  |
| 23 | `as2_oop` | 13 | 12.5s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 12.3s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 12.2s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 12.2s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 11.8s |  |
| 28 | `as_set_prop_flags` | 79 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 11.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 11.9s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 12.0s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 11.9s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 11.9s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 12.0s |  |
| 35 | `as_transformed_flag` | 20 | 11.9s |  |
| 36 | `attach_movie` | 59 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `bad_placeobject_clipaction` | 2 | 12.2s |  |
| 39 | `bad_swf_tag_past_eof` | 0 | 11.8s |  |
| 40 | `bitand` | 1058 | 14.4s |  |
| 41 | `bitmap_data_colortransform` | 0 | 12.1s |  |
| 42 | `bitmap_data_fillrect` | 0 | 11.9s |  |
| 43 | `bitmap_data_max_size_swf10` | 12 | 11.8s |  |
| 44 | `bitmap_data_max_size_swf9` | 10 | 11.9s |  |
| 45 | `bitmap_data_perlinnoise` | 0 | 12.7s |  |
| 46 | `bitmap_data_pixeldissolve_image` | 0 | 12.4s |  |
| 47 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.4s |  |
| 48 | `bitor` | 1058 | 14.9s |  |
| 49 | `biturshift` | 14 | 12.1s |  |
| 50 | `biturshift_swf8` | 14 | 13.2s |  |
| 51 | `bitxor` | 1058 | 14.2s |  |
| 52 | `boxed_primitives` | 24 | 11.9s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 53 | `button_children` | 8 | 11.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_goto` | 4 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events` | 14 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_key_events_special` | 45 | 12.5s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress` | 3 | 12.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_press` | 25 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_keypress_vs_tab` | 20 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_keypress_vs_textinput` | 4 | 11.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_order` | 2 | 11.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_properties_special_cases` | 22 | 11.9s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_v5` | 18 | 11.8s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_v6` | 18 | 11.7s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `call_method_empty_name` | 1 | 11.7s |  |
| 66 | `capabilities_resolution` | 8 | 11.7s |  |
| 67 | `catch_references_registers` | 2 | 11.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 68 | `click_block` | 5 | 11.8s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 69 | `clip_constructors` | 8 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 70 | `clip_events` | 19 | 12.0s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 71 | `clone_sprite_types` | 24 | 11.6s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `closure_scope` | 7 | 11.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 73 | `color` | 57 | 11.8s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 74 | `color_transform` | 48 | 11.7s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 75 | `conflicting_instance_names` | 23 | 11.7s |  |
| 76 | `constructor_function` | 2 | 11.6s |  |
| 77 | `context_menu` | 39 | 11.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 78 | `context_menu_item` | 41 | 11.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 79 | `create_empty_movie_clip` | 3 | 11.5s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `define_function2` | 8 | 11.6s |  |
| 81 | `define_function2_preload` | 13 | 11.6s |  |
| 82 | `define_function2_preload_order` | 4 | 12.8s |  |
| 83 | `define_function_case_sensitive` | 2 | 12.4s |  |
| 84 | `delete` | 3 | 12.3s |  |
| 85 | `display_object_properties` | 2 | 12.0s |  |
| 86 | `divide_swf4` | 107 | 12.2s |  |
| 87 | `do_init_action` | 3 | 12.5s |  |
| 88 | `do_init_action_child` | 12 | 12.4s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 89 | `drag_drop` | 10 | 12.5s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 90 | `drag_over_from_outside` | 1 | 12.2s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 91 | `drag_over_without_startdrag` | 1 | 12.1s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 92 | `duplicate_movie_clip` | 20 | 12.1s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `edittext_align` | 60 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 94 | `edittext_align_trailing_spaces_swf7` | 576 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `edittext_align_trailing_spaces_swf8` | 576 | 12.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 96 | `edittext_antialiastype` | 296 | 12.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `edittext_autosize` | 71 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 98 | `edittext_autosize_setter` | 20 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 99 | `edittext_default_format` | 221 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 100 | `edittext_default_format_font_style` | 335 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `edittext_font_size` | 45 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 102 | `edittext_hscroll` | 27 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_align_swf7` | 52 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_align_swf8` | 52 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_color` | 114 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_entity` | 4 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_roundtrip` | 17 | 11.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_input` | 1 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_leading` | 9 | 13.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_letter_spacing` | 15 | 13.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_margins` | 25 | 13.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_password` | 5 | 13.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_password_copy` | 4 | 13.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_paste_empty` | 2 | 13.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_programmatic_focus` | 12 | 13.4s | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_restrict_paste` | 5 | 13.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_tag_indent` | 31 | 13.3s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_text_height_leading` | 20 | 13.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_underline` | 40 | 13.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_width_height` | 103 | 13.5s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `empty_movieclip_can_attach_movies` | 11 | 12.6s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 122 | `enumerate` | 64 | 12.2s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 123 | `equals` | 32 | 12.2s |  |
| 124 | `equals2_swf5` | 926 | 13.8s |  |
| 125 | `equals2_swf6` | 926 | 13.7s |  |
| 126 | `equals2_swf7` | 926 | 13.5s |  |
| 127 | `equals_swf4` | 665 | 12.7s |  |
| 128 | `equals_swf4_alt` | 32 | 11.9s |  |
| 129 | `equals_swf5` | 32 | 11.9s |  |
| 130 | `error` | 58 | 12.0s |  |
| 131 | `escape` | 14 | 12.0s |  |
| 132 | `execution_order1` | 5 | 12.2s |  |
| 133 | `execution_order2` | 7 | 12.1s |  |
| 134 | `execution_order3` | 4 | 12.0s |  |
| 135 | `execution_order4` | 12 | 12.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 136 | `export_assets` | 3 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 137 | `extends_chain` | 134 | 12.6s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 138 | `extends_native_type` | 11 | 12.0s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 139 | `focus_mouse` | 45 | 11.9s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 140 | `focus_root_movie` | 2 | 11.8s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 141 | `focusrect_focuslost` | 4 | 11.7s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 142 | `focusrect_mouse_swf8` | 0 | 11.8s |  |
| 143 | `focusrect_mouse_swf9` | 0 | 12.3s |  |
| 144 | `focusrect_swf5` | 6 | 12.1s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 145 | `focusrect_swf6` | 42 | 12.2s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 146 | `form_loader_encoding_1` | 1 | 12.1s |  |
| 147 | `frame_size_translated_negative` | 21 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 148 | `frame_size_translated_positive` | 21 | 12.1s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 149 | `function_suppress_and_preload` | 28 | 12.2s |  |
| 150 | `get_variable_in_scope` | 29 | 12.0s |  |
| 151 | `getproperty` | 28 | 12.0s |  |
| 152 | `getproperty_swf4` | 28 | 13.8s |  |
| 153 | `getproperty_swf5` | 28 | 11.8s |  |
| 154 | `global_array` | 3 | 11.7s |  |
| 155 | `global_is_bare` | 7 | 11.8s |  |
| 156 | `globals_swf5` | 304 | 12.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 157 | `globals_swf6` | 304 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 158 | `globals_swf7` | 304 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 159 | `globals_swf8` | 304 | 11.9s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 160 | `goto_advance1` | 6 | 11.8s |  |
| 161 | `goto_advance2` | 2 | 11.8s |  |
| 162 | `goto_both_ways1` | 3 | 11.7s |  |
| 163 | `goto_both_ways2` | 3 | 11.7s |  |
| 164 | `goto_execution_order` | 2 | 11.6s |  |
| 165 | `goto_execution_order2` | 2 | 11.8s |  |
| 166 | `goto_frame` | 12 | 12.1s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 167 | `goto_frame2` | 44 | 12.2s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 168 | `goto_frame_number` | 3 | 11.7s |  |
| 169 | `goto_label` | 17 | 11.8s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 170 | `goto_methods` | 40 | 11.7s | [11](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 171 | `goto_rewind1` | 1 | 11.7s |  |
| 172 | `goto_rewind2` | 3 | 11.7s |  |
| 173 | `goto_rewind3` | 2 | 11.7s |  |
| 174 | `greater_swf6` | 1175 | 13.7s |  |
| 175 | `greater_swf7` | 1175 | 13.7s |  |
| 176 | `greaterthan_swf5` | 1 | 11.8s |  |
| 177 | `greaterthan_swf8` | 1 | 11.7s |  |
| 178 | `has_own_property` | 32 | 11.8s |  |
| 179 | `hittest_lockroot` | 15 | 11.9s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 180 | `hittest_morph` | 70 | 11.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [21](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 181 | `hittest_winding_rule` | 12 | 11.8s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 182 | `infinite_recursion_function` | 4 | 11.7s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 183 | `infinite_recursion_function_in_setter` | 131 | 11.7s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 184 | `infinite_recursion_virtual_property` | 67 | 11.7s | [15](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 185 | `init_array_invalid` | 4 | 11.7s |  |
| 186 | `init_object_invalid` | 4 | 11.9s |  |
| 187 | `init_object_order` | 15 | 11.8s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 188 | `is_finite` | 49 | 11.7s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 189 | `is_finite_swf6` | 49 | 11.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 190 | `is_prototype_of` | 89 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 191 | `issue_1086` | 1 | 11.6s |  |
| 192 | `issue_1671` | 0 | 11.6s |  |
| 193 | `issue_1906` | 4 | 11.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 194 | `issue_2166` | 9 | 11.7s |  |
| 195 | `issue_3446` | 1 | 11.9s |  |
| 196 | `issue_3522` | 2 | 11.9s |  |
| 197 | `issue_4377` | 2 | 11.9s |  |
| 198 | `issue_710` | 4 | 11.9s |  |
| 199 | `issue_768` | 3 | 13.9s | [16](ruffle-tests/_investigation/complete/issue_768.md) |
| 200 | `issue_9327` | 2 | 11.8s |  |
| 201 | `issue_9885` | 2 | 11.8s |  |
| 202 | `key_isToggled` | 9 | 11.8s |  |
| 203 | `lessthan` | 41 | 11.7s |  |
| 204 | `lessthan2_swf5` | 1226 | 13.8s |  |
| 205 | `lessthan2_swf6` | 1226 | 13.8s |  |
| 206 | `lessthan2_swf7` | 1226 | 13.9s |  |
| 207 | `lessthan_swf4` | 902 | 13.1s |  |
| 208 | `lessthan_swf4_alt` | 41 | 11.8s |  |
| 209 | `lessthan_swf5` | 41 | 11.7s |  |
| 210 | `loadmovie` | 2 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 211 | `loadmovie_fail` | 2 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 212 | `loadmovie_flashvars` | 4 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 213 | `loadmovie_method` | 2 | 11.6s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 214 | `loadmovie_replace_root` | 5 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 215 | `loadmovienum` | 3 | 11.7s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 216 | `loadvariables` | 2 | 12.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 217 | `loadvariables2` | 8 | 12.6s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 218 | `loadvariablesnum` | 2 | 12.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 219 | `local_to_global` | 49 | 12.2s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 220 | `localconnection_properties` | 8 | 12.0s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 221 | `lock_root` | 1 | 12.1s |  |
| 222 | `logical_ops_swf4` | 90 | 12.1s |  |
| 223 | `logical_ops_swf8` | 108 | 12.1s |  |
| 224 | `looping` | 6 | 12.1s |  |
| 225 | `mask_reapply` | 0 | 12.3s |  |
| 226 | `mask_with_drawing` | 0 | 12.1s |  |
| 227 | `math_min_max` | 101 | 12.3s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 228 | `math_swf6` | 530 | 12.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 229 | `math_swf7` | 530 | 12.6s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 230 | `math_swf8` | 530 | 12.5s | [20](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 231 | `matrix` | 171 | 12.5s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 232 | `mcl_as_broadcaster` | 12 | 12.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 233 | `mcl_getprogress` | 30 | 12.5s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 234 | `mcl_loadclip` | 149 | 12.0s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 235 | `mcl_loadclip_properties` | 6 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 236 | `mcl_mislabeled_target` | 6 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 237 | `mcl_target_gif87a` | 6 | 12.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 238 | `mcl_target_gif89a` | 6 | 12.2s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 239 | `mcl_target_jpg` | 6 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 240 | `mcl_target_png` | 6 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 241 | `mcl_unloadclip` | 5 | 11.8s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 242 | `mouse_events` | 8 | 11.9s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 243 | `mouse_events_visible_enabled` | 12 | 12.0s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 244 | `mouse_hover_events_while_dragging` | 1 | 12.0s | [8](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 245 | `mouse_listeners` | 67 | 11.9s |  |
| 246 | `mouse_pos` | 665 | 12.0s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 247 | `mouse_pos_with_scale_factor` | 260 | 11.8s | [22](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 248 | `mouse_wheel_enabled` | 2 | 11.6s |  |
| 249 | `movieclip_begin_gradient_fill` | 0 | 12.2s |  |
| 250 | `movieclip_blend_mode_property` | 35 | 12.4s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 251 | `movieclip_create_text_field` | 90 | 12.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 252 | `movieclip_default_state` | 69 | 12.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 253 | `movieclip_depth_methods` | 98 | 12.2s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 254 | `movieclip_focusenabled` | 99 | 12.1s | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 255 | `movieclip_get_instance_at_depth` | 28 | 12.0s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 256 | `movieclip_hittest` | 92 | 12.1s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 257 | `movieclip_in_removed_button` | 4 | 12.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 258 | `movieclip_init_object` | 5 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 259 | `movieclip_line_gradient_style` | 0 | 14.0s |  |
| 260 | `movieclip_name_from_timeline` | 13 | 12.1s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 261 | `movieclip_prototype_extension` | 5 | 12.0s |  |
| 262 | `moviecliploader_flashvars` | 4 | 12.1s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 263 | `mutable_this` | 18 | 12.0s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 264 | `named_shapes` | 14 | 12.0s |  |
| 265 | `nan_scale` | 9 | 12.0s |  |
| 266 | `native_double_construct` | 12 | 12.1s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 267 | `native_objects_swf7` | 84 | 12.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 268 | `native_objects_swf8` | 84 | 12.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 269 | `native_subclasses` | 191 | 12.4s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 270 | `nested_textfields_in_buttons` | 0 | 12.0s |  |
| 271 | `new_method_wrap` | 4 | 11.5s |  |
| 272 | `new_object_enumerate` | 7 | 11.6s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 273 | `new_object_wrap` | 4 | 11.6s |  |
| 274 | `o` | 3 | 11.6s |  |
| 275 | `object_constructor` | 33 | 11.7s |  |
| 276 | `object_function` | 32 | 11.7s |  |
| 277 | `object_properties` | 31 | 11.8s | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 278 | `object_prototypes` | 74 | 11.8s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 279 | `object_string_coerce_swf5` | 62 | 11.7s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 280 | `object_string_coerce_swf6` | 68 | 11.7s | [26](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 281 | `on_construct` | 25 | 11.7s | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 282 | `parse_float` | 74 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 283 | `parse_int` | 64 | 11.9s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [29](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 284 | `path_string` | 322 | 11.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 285 | `place_and_lookup` | 30 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 286 | `placeobject_occupied_depth` | 6 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 287 | `point` | 175 | 12.3s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 288 | `primitive_instanceof` | 37 | 11.7s |  |
| 289 | `primitive_type_globals` | 557 | 12.2s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 290 | `printjob_props_swf5` | 45 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 291 | `printjob_props_swf6` | 45 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 292 | `printjob_props_swf7` | 45 | 11.8s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 293 | `property_invalid_base_clip` | 36 | 11.8s |  |
| 294 | `prototype_delete` | 12 | 11.7s |  |
| 295 | `prototype_enumerate` | 5 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 296 | `prototype_properties` | 17 | 11.7s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 297 | `rectangle` | 745 | 12.4s | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 298 | `recursive_prototypes` | 0 | 11.6s |  |
| 299 | `register_class_return_value` | 16 | 11.8s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 300 | `register_globals_across_frames` | 15 | 11.7s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 301 | `register_underflow` | 26 | 11.7s | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 302 | `remove_movie_clip` | 29 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 303 | `rewind_depth` | 30 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 304 | `sandbox_type_local_file` | 1 | 11.6s |  |
| 305 | `sandbox_type_local_network` | 1 | 11.6s |  |
| 306 | `set_interval` | 27 | 11.8s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 307 | `set_variable_scope` | 58 | 11.7s |  |
| 308 | `single_frame` | 1 | 11.6s |  |
| 309 | `slash_syntax` | 14 | 11.7s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 310 | `sound_props_swf5` | 68 | 13.6s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 311 | `sound_props_swf6` | 68 | 13.5s | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 312 | `sound_start_load` | 0 | 13.6s |  |
| 313 | `stage_display_state` | 16 | 13.5s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 314 | `stage_object_children` | 83 | 13.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 315 | `stage_object_enumerate` | 4 | 13.4s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 316 | `stage_object_properties` | 241 | 14.0s | [9](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 317 | `stage_object_properties_get_var` | 5 | 13.5s |  |
| 318 | `stage_object_properties_swf6` | 231 | 13.8s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 319 | `stage_property_representation` | 586 | 13.7s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 320 | `stage_scale_mode` | 39 | 13.7s | [34](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [35](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 321 | `strictequals_swf6` | 902 | 15.4s |  |
| 322 | `strictly_equals` | 7 | 13.9s |  |
| 323 | `string_coercion` | 117 | 14.2s | [36](ruffle-tests/_investigation/complete/string_coercion.md) |
| 324 | `string_methods` | 285 | 14.5s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 325 | `string_methods_negative_args` | 240 | 14.1s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 326 | `string_methods_swfv5` | 275 | 14.6s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 327 | `string_ops_swf6` | 95 | 13.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 328 | `string_paths_basic` | 4 | 13.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 329 | `string_paths_eval2` | 7 | 11.9s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 330 | `string_paths_hidden` | 54 | 11.8s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 331 | `string_paths_variable_alias` | 4 | 11.7s | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 332 | `super_edge_cases` | 39 | 12.0s | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 333 | `swf4_actions_bool` | 96 | 11.8s |  |
| 334 | `swf4_actions_coercion_order` | 158 | 11.9s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 335 | `swf4_bool` | 4 | 11.8s |  |
| 336 | `swf4_function_calls` | 7 | 11.8s |  |
| 337 | `swf5_encoding` | 3 | 11.8s |  |
| 338 | `swf5_no_closure` | 19 | 12.0s | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 339 | `swf6_case_insensitive` | 42 | 11.8s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 340 | `swf6_string_as_bool` | 15 | 11.7s | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 341 | `swf7_case_sensitive` | 44 | 11.7s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 342 | `tab_ordering_automatic_basic` | 92 | 11.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 343 | `tab_ordering_automatic_order_grid` | 21 | 11.7s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 344 | `tab_ordering_children` | 208 | 11.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 345 | `tab_ordering_custom_basic` | 71 | 11.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 346 | `tab_ordering_custom_duplicate_index` | 22 | 11.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 347 | `tab_ordering_custom_i32_vs_u32` | 12 | 11.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 348 | `tab_ordering_custom_m1` | 29 | 11.8s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 349 | `tab_ordering_events` | 150 | 12.1s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 350 | `tab_ordering_movieclip_enabled_default` | 462 | 11.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 351 | `tab_ordering_properties_tab_index_edge_case` | 4 | 11.8s |  |
| 352 | `tab_ordering_reverse` | 51 | 11.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 353 | `tab_ordering_tabbable` | 47 | 11.9s | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 354 | `target_clip_removed` | 5 | 11.9s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 355 | `target_clip_swf5` | 2 | 11.7s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 356 | `target_clip_swf6` | 2 | 11.7s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 357 | `target_path` | 14 | 11.7s |  |
| 358 | `tell_target` | 37 | 11.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 359 | `tell_target_invalid` | 6 | 11.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 360 | `tell_target_invalid_swf6` | 5 | 11.8s | [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 361 | `text_format` | 1146 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 362 | `text_format_display` | 21 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 363 | `text_format_font_max_length` | 2 | 11.8s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 364 | `text_format_rounding_swf7` | 840 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 365 | `text_format_rounding_swf8` | 840 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 366 | `textfield_background_color` | 11 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 367 | `textfield_border_color` | 11 | 11.9s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 368 | `textfield_cache_as_bitmap` | 1 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 369 | `textfield_maxchars` | 3 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 370 | `textfield_properties` | 44 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 371 | `textfield_props_swf5` | 175 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 372 | `textfield_props_swf6` | 210 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 373 | `textfield_props_swf7` | 210 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 374 | `textfield_props_swf8` | 210 | 12.4s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 375 | `textfield_text` | 7 | 12.1s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 376 | `textfield_variable` | 81 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 377 | `textsnapshot_props_swf5` | 56 | 12.2s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 378 | `textsnapshot_props_swf6` | 56 | 12.0s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 379 | `this_scoping` | 52 | 12.1s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 380 | `this_swf5` | 41 | 12.0s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 381 | `this_swf6` | 41 | 12.0s | [42](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 382 | `this_swf7` | 41 | 12.1s | [43](ruffle-tests/_investigation/complete/this_swf7.md) |
| 383 | `timeline_function_def` | 7 | 12.3s |  |
| 384 | `transform` | 70 | 11.6s | [6](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 385 | `try_catch_finally` | 118 | 11.8s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 386 | `try_finally_simple` | 16 | 11.6s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 387 | `typeof` | 22 | 11.7s |  |
| 388 | `typeof_globals` | 7 | 11.6s |  |
| 389 | `uncaught_exception` | 1 | 11.6s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 390 | `uncaught_exception_bubbled` | 1 | 11.7s | [45](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 391 | `undefined_to_string_swf6` | 4 | 11.7s |  |
| 392 | `unescape` | 43 | 11.7s |  |
| 393 | `unload` | 52 | 11.9s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 394 | `unload_clip_event` | 4 | 11.8s | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 395 | `unloadmovie` | 4 | 11.9s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 396 | `unloadmovie_method` | 3 | 12.3s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 397 | `unloadmovienum` | 13 | 12.5s | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 398 | `use_hand_cursor` | 8 | 12.2s |  |
| 399 | `variable_args` | 5 | 12.3s |  |
| 400 | `waitforframe` | 7 | 12.2s |  |
| 401 | `waitforframe2` | 16 | 12.3s |  |
| 402 | `watch` | 117 | 11.9s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 403 | `watch_textfield` | 12 | 11.6s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 404 | `watch_virtual_property_proto` | 2 | 11.7s | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 405 | `with` | 49 | 11.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 406 | `with_return` | 2 | 11.6s |  |
| 407 | `with_variable_scopes` | 43 | 11.7s | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 408 | `xml` | 15 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 409 | `xml_append_child` | 28 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 410 | `xml_append_child_with_parent` | 20 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 411 | `xml_attributes_read` | 4 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 412 | `xml_cdata` | 11 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 413 | `xml_child_nodes_edge_cases` | 4 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 414 | `xml_clone_expandos` | 19 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 415 | `xml_first_last_child` | 8 | 11.6s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 416 | `xml_has_child_nodes` | 3 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 417 | `xml_idmap` | 21 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 418 | `xml_ignore_comments` | 21 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 419 | `xml_ignore_white` | 34 | 12.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 420 | `xml_insert_before` | 20 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 421 | `xml_inspect_createmethods` | 15 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 422 | `xml_inspect_doctype` | 7 | 12.5s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 423 | `xml_inspect_parsexml` | 62 | 13.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 424 | `xml_inspect_xmldecl` | 7 | 13.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 425 | `xml_namespaces` | 203 | 12.1s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 426 | `xml_parent_and_child` | 5 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 427 | `xml_remove_node` | 22 | 12.9s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 428 | `xml_reparenting` | 14 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 429 | `xml_siblings` | 10 | 12.0s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 430 | `xml_to_string` | 13 | 12.2s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 431 | `xml_to_string_comment` | 1 | 11.7s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 432 | `xml_unescaping` | 23 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 433 | `xmlnode_proto` | 1 | 11.8s | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**53 tests** within reach

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
| 11 | `function_base_clip_removed` | 88.0% | 22 | 25 | 3 |  |
| 12 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `string_paths_other` | 83.3% | 30 | 36 | 6 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `function_base_clip_readded` | 81.8% | 9 | 11 | 2 |  |
| 15 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_restrict` | 75.9% | 145 | 191 | 46 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `focus_mouse_rollout` | 75.0% | 3 | 4 | 1 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 20 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3897 | 5377 | 1480 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `global_swf5_6_7_8_9` | 69.7% | 798 | 1145 | 347 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 24 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `removed_target_clip_scope` | 65.7% | 23 | 35 | 12 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `edittext_stylesheet` | 62.8% | 204 | 325 | 121 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `loadmovie_var_persistence` | 62.5% | 5 | 8 | 3 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `global_swf6_7_8` | 60.0% | 9 | 15 | 6 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 31 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 32 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 33 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 34 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 35 | `register_class` | 57.6% | 38 | 66 | 28 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 36 | `edittext_html_condensewhite_swf8` | 56.9% | 177 | 311 | 134 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 38 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 39 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 40 | `movieclip_lockroot` | 55.2% | 16 | 29 | 13 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `register_class_with_sound` | 54.5% | 6 | 11 | 5 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 43 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 44 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 45 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 46 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 47 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `issue_1104` | 50.0% | 1 | 2 | 1 |  |
| 51 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 52 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 53 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 13.7s | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 14.3s |  |
| 3 | `netstream_play_flv_screen` | 27.0s |  |
| 4 | `string_paths_timer` | 13.8s |  |
| 5 | `timer_run_actions` | 14.1s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 35.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.4s | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 22.5s | [44](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**177 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `function_base_clip_removed` | 88.0% | 22/25 | 25 | 25 |  |
| 12 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `string_paths_other` | 83.3% | 30/36 | 36 | 36 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 14 | `function_base_clip_readded` | 81.8% | 9/11 | 11 | 11 |  |
| 15 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `edittext_restrict` | 75.9% | 145/191 | 191 | 191 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `focus_mouse_rollout` | 75.0% | 3/4 | 3 | 4 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 20 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3897/5377 | 5377 | 5377 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `global_swf5_6_7_8_9` | 69.7% | 798/1145 | 1145 | 1145 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 24 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `removed_target_clip_scope` | 65.7% | 23/35 | 35 | 35 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `edittext_stylesheet` | 62.8% | 204/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `loadmovie_var_persistence` | 62.5% | 5/8 | 5 | 8 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `global_swf6_7_8` | 60.0% | 9/15 | 15 | 15 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 31 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 32 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 33 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 34 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 35 | `register_class` | 57.6% | 38/66 | 47 | 66 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 36 | `edittext_html_condensewhite_swf8` | 56.9% | 177/311 | 311 | 311 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 38 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 39 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 40 | `movieclip_lockroot` | 55.2% | 16/29 | 17 | 29 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `register_class_with_sound` | 54.5% | 6/11 | 11 | 11 | [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 43 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 44 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 45 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 46 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 47 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 48 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [33](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `issue_1104` | 50.0% | 1/2 | 1 | 2 |  |
| 51 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 52 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 53 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 55 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 56 | `bitmap_filters` | 46.4% | 254/548 | 548 | 548 | [25](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 57 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 58 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 60 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 61 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 62 | `issue_2870` | 40.0% | 2/5 | 5 | 3 |  |
| 63 | `loadmovienum_cross_version_prototype` | 40.0% | 6/15 | 15 | 9 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 64 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [39](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 65 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 66 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 67 | `sound` | 37.7% | 237/628 | 628 | 628 |  |
| 68 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 69 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 70 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 71 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [30](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 72 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 73 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 74 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 75 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 76 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 77 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 78 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 79 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 80 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 81 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 82 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 83 | `edittext_newline_stripping` | 29.7% | 19/64 | 60 | 64 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 84 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 85 | `default_names` | 28.8% | 15/52 | 48 | 52 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [38](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 88 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 89 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 90 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 91 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 92 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 93 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 4 | 11 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 94 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 95 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 96 | `mcl_events_swf_version` | 15.9% | 37/232 | 37 | 232 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 97 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 98 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 99 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 100 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [5](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 101 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [27](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 102 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 103 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 105 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 106 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 107 | `function_base_clip` | 12.5% | 1/8 | 1 | 8 |  |
| 108 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 109 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 110 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 112 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 113 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 114 | `define_local` | 7.4% | 2/27 | 23 | 27 | [47](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 115 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 117 | `call` | 6.3% | 4/63 | 29 | 63 |  |
| 118 | `movieclip_gettextsnapshot` | 6.2% | 7/112 | 42 | 112 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 119 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 120 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 121 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 122 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 123 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 124 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 125 | `removed_clip_halts_script` | 4.8% | 1/21 | 21 | 15 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 126 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 127 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 128 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 129 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 130 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [18](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 131 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [28](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 132 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 133 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 134 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 135 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 136 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 137 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 138 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 139 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 140 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 141 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [12](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 142 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 143 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [4](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 144 | `custom_clip_methods` | 0.0% | 0/4 | 2 | 4 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 145 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 146 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 147 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 148 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 149 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [10](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 150 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 151 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 152 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 153 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [13](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 154 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [14](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 155 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 156 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 157 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [19](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 158 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [32](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 159 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 160 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 161 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 162 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 163 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 164 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [17](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 165 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 166 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 167 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 168 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 169 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 170 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/complete/STRING_PLAN.md) [40](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 171 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 172 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [41](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [23](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 174 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 175 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 176 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 177 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [48](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
| 4 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 5 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 2 | 2 |
| 6 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 7 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 8 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 9 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 10 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 4 | 3 |
| 11 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 12 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 13 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 22 | 9 |
| 14 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 15 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 16 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 17 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 24 | 25 |
| 18 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 19 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 20 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 21 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 22 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 23 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
| 24 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 25 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 26 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 27 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 28 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 29 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 30 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 31 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 11 | 4 |
| 32 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 33 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 34 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 35 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 36 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 37 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 8 | 5 |
| 38 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 39 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 13 | 3 |
| 40 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 12 | 7 |
| 41 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 47 | 23 |
| 42 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 43 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 44 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 45 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 46 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 47 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 48 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 230 | 150 | 80 |
