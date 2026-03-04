# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-04 05:14 UTC

**Git SHA**: `8f807f41b7`

**Run Duration**: 129m 33s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **441** (71.2%) |
| Failing | 178 |
| Total expected lines | 91475 |
| Matching lines | 69092 (75.5%) |
| Mismatched lines | 22383 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 169 | 94.9% |
| Runtime Segfault | 5 | 2.8% |
| Runtime Error | 2 | 1.1% |
| Compile Fail | 1 | 0.6% |
| Timeout | 1 | 0.6% |

## Passing Tests

**441 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.0s |  |
| 2 | `action_to_integer` | 28 | 11.9s |  |
| 3 | `add` | 28 | 11.9s |  |
| 4 | `add2` | 354 | 12.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.2s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.3s |  |
| 7 | `add_swf5` | 28 | 12.1s |  |
| 8 | `arguments` | 127 | 12.1s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.0s |  |
| 11 | `array_constructor` | 30 | 12.1s |  |
| 12 | `array_enumerate` | 4 | 12.1s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.1s |  |
| 14 | `array_properties` | 36 | 12.0s |  |
| 15 | `array_prototyping` | 12 | 12.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 11.9s |  |
| 17 | `array_sort` | 161 | 12.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 11.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 12.1s |  |
| 20 | `array_trivial` | 209 | 12.1s |  |
| 21 | `as1_constructor_v6` | 35 | 11.9s |  |
| 22 | `as1_constructor_v7` | 35 | 13.9s |  |
| 23 | `as2_oop` | 13 | 12.2s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 12.3s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 12.2s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 12.1s |  |
| 28 | `as_set_prop_flags` | 79 | 12.2s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 12.1s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 12.1s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 12.1s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 12.1s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 12.0s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 12.0s |  |
| 35 | `as_transformed_flag` | 20 | 12.3s |  |
| 36 | `attach_movie` | 59 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `bad_swf_tag_past_eof` | 0 | 11.8s |  |
| 39 | `bitand` | 1058 | 14.3s |  |
| 40 | `bitmap_data_colortransform` | 0 | 12.2s |  |
| 41 | `bitmap_data_fillrect` | 0 | 12.0s |  |
| 42 | `bitmap_data_max_size_swf10` | 12 | 11.9s |  |
| 43 | `bitmap_data_max_size_swf9` | 10 | 11.8s |  |
| 44 | `bitmap_data_perlinnoise` | 0 | 12.7s |  |
| 45 | `bitmap_data_pixeldissolve_image` | 0 | 12.3s |  |
| 46 | `bitmapdata_applyfilter_colormatrix` | 0 | 11.9s |  |
| 47 | `bitor` | 1058 | 14.3s |  |
| 48 | `biturshift` | 14 | 11.8s |  |
| 49 | `biturshift_swf8` | 14 | 12.6s |  |
| 50 | `bitxor` | 1058 | 15.0s |  |
| 51 | `boxed_primitives` | 24 | 12.3s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 52 | `button_children` | 8 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 53 | `button_goto` | 4 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_key_events` | 14 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events_special` | 45 | 13.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_keypress` | 3 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress_vs_press` | 25 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_tab` | 20 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_keypress_vs_textinput` | 4 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_properties_special_cases` | 22 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_v5` | 18 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_v6` | 18 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `call_method_empty_name` | 1 | 12.1s |  |
| 64 | `capabilities_resolution` | 8 | 12.1s |  |
| 65 | `catch_references_registers` | 2 | 12.0s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 66 | `click_block` | 5 | 12.3s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 67 | `clip_constructors` | 8 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 68 | `clip_events` | 19 | 12.4s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 69 | `clone_sprite_types` | 24 | 12.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 70 | `closure_scope` | 7 | 12.2s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 71 | `color` | 57 | 12.3s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 72 | `color_transform` | 48 | 12.2s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 73 | `conflicting_instance_names` | 23 | 12.2s |  |
| 74 | `constructor_function` | 2 | 12.1s |  |
| 75 | `context_menu` | 39 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `context_menu_item` | 41 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 77 | `define_function2` | 8 | 12.0s |  |
| 78 | `define_function2_preload` | 13 | 12.1s |  |
| 79 | `define_function2_preload_order` | 4 | 12.1s |  |
| 80 | `define_function_case_sensitive` | 2 | 12.1s |  |
| 81 | `delete` | 3 | 12.1s |  |
| 82 | `display_object_properties` | 2 | 12.1s |  |
| 83 | `divide_swf4` | 107 | 12.2s |  |
| 84 | `do_init_action` | 3 | 12.3s |  |
| 85 | `do_init_action_child` | 12 | 12.7s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 86 | `drag_drop` | 10 | 12.4s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 87 | `drag_over_from_outside` | 1 | 12.8s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 88 | `drag_over_without_startdrag` | 1 | 12.7s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 89 | `duplicate_movie_clip` | 20 | 12.5s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 90 | `edittext_align` | 60 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 91 | `edittext_align_trailing_spaces_swf7` | 576 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 92 | `edittext_align_trailing_spaces_swf8` | 576 | 12.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 93 | `edittext_antialiastype` | 296 | 12.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_autosize` | 71 | 13.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_autosize_setter` | 20 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_default_format` | 221 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_default_format_font_style` | 335 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_font_size` | 45 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_hscroll` | 27 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_html_align_swf7` | 52 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_html_align_swf8` | 52 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_html_color` | 114 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_entity` | 4 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_roundtrip` | 17 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_swf7` | 5377 | 13.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_swf8` | 5377 | 13.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_input` | 1 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_leading` | 9 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_letter_spacing` | 15 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_margins` | 25 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_newline_stripping` | 64 | 17.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_password` | 5 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_password_copy` | 4 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_paste_empty` | 2 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_programmatic_focus` | 12 | 12.3s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_restrict` | 191 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_restrict_paste` | 5 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_tag_indent` | 31 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_text_height_leading` | 20 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_underline` | 40 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_width_height` | 103 | 12.3s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `empty_movieclip_can_attach_movies` | 11 | 13.7s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 123 | `enumerate` | 64 | 12.0s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 124 | `equals` | 32 | 12.1s |  |
| 125 | `equals2_swf5` | 926 | 13.7s |  |
| 126 | `equals2_swf6` | 926 | 13.7s |  |
| 127 | `equals2_swf7` | 926 | 13.9s |  |
| 128 | `equals_swf4` | 665 | 12.9s |  |
| 129 | `equals_swf4_alt` | 32 | 12.1s |  |
| 130 | `equals_swf5` | 32 | 12.2s |  |
| 131 | `error` | 58 | 12.2s |  |
| 132 | `escape` | 14 | 12.1s |  |
| 133 | `execution_order1` | 5 | 12.1s |  |
| 134 | `execution_order2` | 7 | 12.2s |  |
| 135 | `execution_order3` | 4 | 12.2s |  |
| 136 | `execution_order4` | 12 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 137 | `export_assets` | 3 | 11.9s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 138 | `extends_chain` | 134 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 139 | `extends_native_type` | 11 | 12.1s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 140 | `focus_mouse` | 45 | 11.5s | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 141 | `focus_root_movie` | 2 | 11.4s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 142 | `focusrect_focuslost` | 4 | 11.5s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 143 | `focusrect_mouse_swf8` | 0 | 11.3s |  |
| 144 | `focusrect_mouse_swf9` | 0 | 13.6s |  |
| 145 | `focusrect_swf5` | 6 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 146 | `focusrect_swf6` | 42 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 147 | `form_loader_encoding_1` | 1 | 12.0s |  |
| 148 | `frame_size_translated_negative` | 21 | 12.1s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 149 | `frame_size_translated_positive` | 21 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 150 | `function_base_clip` | 8 | 12.0s |  |
| 151 | `function_base_clip_removed` | 25 | 12.1s |  |
| 152 | `function_suppress_and_preload` | 28 | 12.2s |  |
| 153 | `get_variable_in_scope` | 29 | 12.1s |  |
| 154 | `getproperty` | 28 | 12.2s |  |
| 155 | `getproperty_swf4` | 28 | 14.1s |  |
| 156 | `getproperty_swf5` | 28 | 12.0s |  |
| 157 | `global_array` | 3 | 12.2s |  |
| 158 | `global_is_bare` | 7 | 11.9s |  |
| 159 | `global_swf6_7_8` | 15 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 160 | `globals_swf5` | 304 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 161 | `globals_swf6` | 304 | 12.6s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 162 | `globals_swf7` | 304 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 163 | `globals_swf8` | 304 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 164 | `goto_advance1` | 6 | 12.2s |  |
| 165 | `goto_advance2` | 2 | 12.2s |  |
| 166 | `goto_both_ways1` | 3 | 12.2s |  |
| 167 | `goto_both_ways2` | 3 | 12.2s |  |
| 168 | `goto_execution_order` | 2 | 12.0s |  |
| 169 | `goto_execution_order2` | 2 | 12.1s |  |
| 170 | `goto_frame` | 12 | 16.7s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 171 | `goto_frame2` | 44 | 13.3s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 172 | `goto_frame_number` | 3 | 12.5s |  |
| 173 | `goto_label` | 17 | 12.5s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 174 | `goto_methods` | 40 | 12.4s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 175 | `goto_rewind1` | 1 | 12.3s |  |
| 176 | `goto_rewind2` | 3 | 12.3s |  |
| 177 | `goto_rewind3` | 2 | 12.3s |  |
| 178 | `greater_swf6` | 1175 | 14.3s |  |
| 179 | `greater_swf7` | 1175 | 14.2s |  |
| 180 | `greaterthan_swf5` | 1 | 12.2s |  |
| 181 | `greaterthan_swf8` | 1 | 12.4s |  |
| 182 | `has_own_property` | 32 | 12.3s |  |
| 183 | `hittest_lockroot` | 15 | 12.6s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 184 | `hittest_morph` | 70 | 12.7s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 185 | `hittest_winding_rule` | 12 | 12.6s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 186 | `infinite_recursion_function` | 4 | 12.4s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 187 | `infinite_recursion_function_in_setter` | 131 | 12.8s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 188 | `infinite_recursion_virtual_property` | 67 | 12.8s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 189 | `init_array_invalid` | 4 | 12.7s |  |
| 190 | `init_object_invalid` | 4 | 13.3s |  |
| 191 | `init_object_order` | 15 | 12.2s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 192 | `is_finite` | 49 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 193 | `is_finite_swf6` | 49 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 194 | `is_prototype_of` | 89 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 195 | `issue_1086` | 1 | 12.1s |  |
| 196 | `issue_1104` | 2 | 12.2s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 197 | `issue_1671` | 0 | 12.2s |  |
| 198 | `issue_1906` | 4 | 11.9s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 199 | `issue_2166` | 9 | 12.0s |  |
| 200 | `issue_3446` | 1 | 12.1s |  |
| 201 | `issue_3522` | 2 | 12.0s |  |
| 202 | `issue_4377` | 2 | 12.1s |  |
| 203 | `issue_710` | 4 | 12.1s |  |
| 204 | `issue_768` | 3 | 13.9s | [18](ruffle-tests/_investigation/complete/issue_768.md) |
| 205 | `issue_9327` | 2 | 12.2s |  |
| 206 | `issue_9885` | 2 | 12.1s |  |
| 207 | `key_isToggled` | 9 | 11.9s |  |
| 208 | `lessthan` | 41 | 12.1s |  |
| 209 | `lessthan2_swf5` | 1226 | 14.4s |  |
| 210 | `lessthan2_swf6` | 1226 | 14.1s |  |
| 211 | `lessthan2_swf7` | 1226 | 14.2s |  |
| 212 | `lessthan_swf4` | 902 | 13.2s |  |
| 213 | `lessthan_swf4_alt` | 41 | 12.0s |  |
| 214 | `lessthan_swf5` | 41 | 12.2s |  |
| 215 | `loadmovie` | 2 | 12.6s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 216 | `loadmovie_fail` | 2 | 12.5s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 217 | `loadmovie_flashvars` | 4 | 12.2s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 218 | `loadmovie_method` | 2 | 12.1s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 219 | `loadmovie_replace_root` | 5 | 11.9s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 220 | `loadmovienum` | 3 | 12.0s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 221 | `loadvariables` | 2 | 12.8s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 222 | `loadvariables2` | 8 | 12.8s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 223 | `loadvariablesnum` | 2 | 12.2s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 224 | `local_to_global` | 49 | 12.6s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 225 | `localconnection_properties` | 8 | 12.7s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 226 | `lock_root` | 1 | 12.7s |  |
| 227 | `logical_ops_swf4` | 90 | 12.3s |  |
| 228 | `logical_ops_swf8` | 108 | 12.4s |  |
| 229 | `looping` | 6 | 12.4s |  |
| 230 | `mask_reapply` | 0 | 12.5s |  |
| 231 | `mask_with_drawing` | 0 | 12.9s |  |
| 232 | `math_min_max` | 101 | 12.8s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 233 | `math_swf6` | 530 | 13.0s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 234 | `math_swf7` | 530 | 13.1s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 235 | `math_swf8` | 530 | 13.0s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 236 | `matrix` | 171 | 13.1s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 237 | `mcl_as_broadcaster` | 12 | 12.7s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 238 | `mcl_getprogress` | 30 | 14.1s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 239 | `mcl_loadclip` | 149 | 12.2s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 240 | `mcl_loadclip_properties` | 6 | 12.3s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 241 | `mcl_mislabeled_target` | 6 | 12.3s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 242 | `mcl_target_gif87a` | 6 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 243 | `mcl_target_gif89a` | 6 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 244 | `mcl_target_jpg` | 6 | 12.1s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 245 | `mcl_target_png` | 6 | 12.0s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 246 | `mcl_unloadclip` | 5 | 12.1s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 247 | `mouse_events` | 8 | 12.0s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 248 | `mouse_events_visible_enabled` | 12 | 12.1s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 249 | `mouse_hover_events_while_dragging` | 1 | 12.1s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 250 | `mouse_listeners` | 67 | 12.0s |  |
| 251 | `mouse_pos` | 665 | 12.1s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 252 | `mouse_pos_with_scale_factor` | 260 | 12.0s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 253 | `mouse_wheel_enabled` | 2 | 12.1s |  |
| 254 | `movieclip_begin_gradient_fill` | 0 | 12.6s |  |
| 255 | `movieclip_blend_mode_property` | 35 | 13.4s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 256 | `movieclip_create_text_field` | 90 | 13.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 257 | `movieclip_default_state` | 69 | 13.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 258 | `movieclip_depth_methods` | 98 | 13.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 259 | `movieclip_focusenabled` | 99 | 12.9s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 260 | `movieclip_get_instance_at_depth` | 28 | 12.8s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 261 | `movieclip_hittest` | 92 | 12.8s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 262 | `movieclip_init_object` | 5 | 12.7s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 263 | `movieclip_line_gradient_style` | 0 | 12.8s |  |
| 264 | `movieclip_name_from_timeline` | 13 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 265 | `movieclip_prototype_extension` | 5 | 12.0s |  |
| 266 | `moviecliploader_flashvars` | 4 | 12.0s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 267 | `mutable_this` | 18 | 11.9s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 268 | `named_shapes` | 14 | 11.9s |  |
| 269 | `nan_scale` | 9 | 12.1s |  |
| 270 | `native_double_construct` | 12 | 12.1s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 271 | `native_objects_swf7` | 84 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 272 | `native_objects_swf8` | 84 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 273 | `native_subclasses` | 191 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 274 | `nested_textfields_in_buttons` | 0 | 11.9s |  |
| 275 | `new_method_wrap` | 4 | 12.0s |  |
| 276 | `new_object_enumerate` | 7 | 12.0s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 277 | `new_object_wrap` | 4 | 12.0s |  |
| 278 | `o` | 3 | 12.1s |  |
| 279 | `object_constructor` | 33 | 12.3s |  |
| 280 | `object_function` | 32 | 12.3s |  |
| 281 | `object_properties` | 31 | 12.5s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 282 | `object_prototypes` | 74 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 283 | `object_string_coerce_swf5` | 62 | 12.2s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 284 | `object_string_coerce_swf6` | 68 | 12.2s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 285 | `on_construct` | 25 | 12.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 286 | `parse_float` | 74 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 287 | `parse_int` | 64 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 288 | `path_string` | 322 | 12.4s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 289 | `place_and_lookup` | 30 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 290 | `placeobject_occupied_depth` | 6 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 291 | `point` | 175 | 12.4s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 292 | `primitive_instanceof` | 37 | 11.9s |  |
| 293 | `primitive_type_globals` | 557 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 294 | `printjob_props_swf5` | 45 | 12.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 295 | `printjob_props_swf6` | 45 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 296 | `printjob_props_swf7` | 45 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 297 | `property_invalid_base_clip` | 36 | 12.2s |  |
| 298 | `prototype_delete` | 12 | 12.3s |  |
| 299 | `prototype_enumerate` | 5 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 300 | `prototype_properties` | 17 | 12.4s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 301 | `rectangle` | 745 | 13.2s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 302 | `recursive_prototypes` | 0 | 12.3s |  |
| 303 | `register_class_return_value` | 16 | 12.1s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 304 | `register_class_with_sound` | 11 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 305 | `register_globals_across_frames` | 15 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 306 | `register_underflow` | 26 | 12.2s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 307 | `remove_movie_clip` | 29 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 308 | `rewind_depth` | 30 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 309 | `sandbox_type_local_file` | 1 | 11.9s |  |
| 310 | `sandbox_type_local_network` | 1 | 11.9s |  |
| 311 | `selection` | 454 | 12.1s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 312 | `set_interval` | 27 | 12.1s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 313 | `set_variable_scope` | 58 | 12.0s |  |
| 314 | `single_frame` | 1 | 11.9s |  |
| 315 | `slash_syntax` | 14 | 11.9s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 316 | `sound_props_swf5` | 68 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 317 | `sound_props_swf6` | 68 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 318 | `sound_start_load` | 0 | 12.1s |  |
| 319 | `stage_display_state` | 16 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 320 | `stage_object_children` | 83 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 321 | `stage_object_enumerate` | 4 | 12.1s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 322 | `stage_object_properties` | 241 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 323 | `stage_object_properties_get_var` | 5 | 12.1s |  |
| 324 | `stage_object_properties_swf6` | 231 | 12.3s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 325 | `stage_property_representation` | 586 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 326 | `stage_scale_mode` | 39 | 12.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 327 | `strictequals_swf6` | 902 | 13.4s |  |
| 328 | `strictly_equals` | 7 | 12.0s |  |
| 329 | `string_methods` | 285 | 12.5s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 330 | `string_methods_negative_args` | 240 | 12.2s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 331 | `string_methods_swfv5` | 275 | 12.5s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 332 | `string_ops_swf6` | 95 | 12.1s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 333 | `string_paths_basic` | 4 | 11.9s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 334 | `string_paths_eval2` | 7 | 12.2s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 335 | `string_paths_hidden` | 54 | 12.0s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 336 | `string_paths_other` | 36 | 12.1s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 337 | `string_paths_unload` | 1 | 12.2s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 338 | `string_paths_variable_alias` | 4 | 12.0s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 339 | `string_paths_variable_scopes` | 5 | 11.9s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 340 | `super_edge_cases` | 39 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 341 | `swf4_actions_bool` | 96 | 12.3s |  |
| 342 | `swf4_actions_coercion_order` | 158 | 12.3s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 343 | `swf4_bool` | 4 | 12.2s |  |
| 344 | `swf4_function_calls` | 7 | 12.1s |  |
| 345 | `swf5_encoding` | 3 | 12.3s |  |
| 346 | `swf5_no_closure` | 19 | 12.4s | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 347 | `swf6_case_insensitive` | 42 | 12.6s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 348 | `swf6_string_as_bool` | 15 | 12.1s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 349 | `swf7_case_sensitive` | 44 | 11.9s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 350 | `tab_ordering_automatic_basic` | 92 | 12.0s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 351 | `tab_ordering_automatic_order_grid` | 21 | 12.1s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 352 | `tab_ordering_children` | 208 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 353 | `tab_ordering_custom_basic` | 71 | 12.1s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 354 | `tab_ordering_custom_duplicate_index` | 22 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 355 | `tab_ordering_custom_i32_vs_u32` | 12 | 12.1s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 356 | `tab_ordering_custom_m1` | 29 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 357 | `tab_ordering_events` | 150 | 12.5s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 358 | `tab_ordering_movieclip_enabled_default` | 462 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 359 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.0s |  |
| 360 | `tab_ordering_reverse` | 51 | 11.9s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 361 | `tab_ordering_tabbable` | 47 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 362 | `target_clip_swf5` | 2 | 11.8s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 363 | `target_clip_swf6` | 2 | 12.1s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 364 | `target_path` | 14 | 12.1s |  |
| 365 | `tell_target` | 37 | 12.2s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 366 | `tell_target_invalid` | 6 | 12.2s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 367 | `tell_target_invalid_swf6` | 5 | 12.1s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 368 | `text_format` | 1146 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 369 | `text_format_display` | 21 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 370 | `text_format_font_max_length` | 2 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 371 | `text_format_rounding_swf7` | 840 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 372 | `text_format_rounding_swf8` | 840 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 373 | `textfield_background_color` | 11 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 374 | `textfield_border_color` | 11 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 375 | `textfield_cache_as_bitmap` | 1 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 376 | `textfield_maxchars` | 3 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 377 | `textfield_properties` | 44 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 378 | `textfield_props_swf5` | 175 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 379 | `textfield_props_swf6` | 210 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 380 | `textfield_props_swf7` | 210 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 381 | `textfield_props_swf8` | 210 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 382 | `textfield_text` | 7 | 11.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 383 | `textfield_variable` | 81 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 384 | `textsnapshot_props_swf5` | 56 | 11.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 385 | `textsnapshot_props_swf6` | 56 | 11.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 386 | `this_scoping` | 52 | 11.9s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 387 | `this_swf5` | 41 | 11.8s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 388 | `this_swf6` | 41 | 11.8s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 389 | `this_swf7` | 41 | 11.8s | [48](ruffle-tests/_investigation/complete/this_swf7.md) |
| 390 | `timeline_function_def` | 7 | 11.9s |  |
| 391 | `trace` | 8 | 12.5s |  |
| 392 | `transform` | 70 | 12.5s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 393 | `try_catch_finally` | 118 | 12.3s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 394 | `try_finally_simple` | 16 | 12.2s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 395 | `typeof` | 22 | 12.2s |  |
| 396 | `typeof_globals` | 7 | 12.2s |  |
| 397 | `uncaught_exception` | 1 | 12.0s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 398 | `uncaught_exception_bubbled` | 1 | 12.1s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 399 | `undefined_to_string_swf6` | 4 | 12.1s |  |
| 400 | `unescape` | 43 | 12.1s |  |
| 401 | `unload` | 52 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 402 | `unload_clip_event` | 4 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 403 | `unloadmovie` | 4 | 12.6s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 404 | `unloadmovie_method` | 3 | 12.9s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 405 | `unloadmovienum` | 13 | 13.0s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 406 | `use_hand_cursor` | 8 | 12.4s |  |
| 407 | `variable_args` | 5 | 12.8s |  |
| 408 | `waitforframe` | 7 | 12.6s |  |
| 409 | `waitforframe2` | 16 | 16.0s |  |
| 410 | `watch` | 117 | 13.4s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 411 | `watch_textfield` | 12 | 13.2s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 412 | `watch_virtual_property_proto` | 2 | 13.4s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 413 | `with` | 49 | 12.8s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 414 | `with_return` | 2 | 13.0s |  |
| 415 | `with_variable_scopes` | 43 | 13.1s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 416 | `xml` | 15 | 12.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 417 | `xml_append_child` | 28 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 418 | `xml_append_child_with_parent` | 20 | 12.4s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 419 | `xml_attributes_read` | 4 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 420 | `xml_cdata` | 11 | 12.2s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 421 | `xml_child_nodes_edge_cases` | 4 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 422 | `xml_clone_expandos` | 19 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 423 | `xml_first_last_child` | 8 | 12.3s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 424 | `xml_has_child_nodes` | 3 | 12.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 425 | `xml_idmap` | 21 | 12.5s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 426 | `xml_ignore_comments` | 21 | 12.6s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 427 | `xml_ignore_white` | 34 | 12.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 428 | `xml_insert_before` | 20 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 429 | `xml_inspect_createmethods` | 15 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 430 | `xml_inspect_doctype` | 7 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 431 | `xml_inspect_parsexml` | 62 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 432 | `xml_inspect_xmldecl` | 7 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 433 | `xml_namespaces` | 203 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 434 | `xml_parent_and_child` | 5 | 11.7s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 435 | `xml_remove_node` | 22 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 436 | `xml_reparenting` | 14 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 437 | `xml_siblings` | 10 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 438 | `xml_to_string` | 13 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 439 | `xml_to_string_comment` | 1 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 440 | `xml_unescaping` | 23 | 12.1s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 441 | `xmlnode_proto` | 1 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**49 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [8](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `string_coercion` | 99.1% | 116 | 117 | 1 | [39](ruffle-tests/_investigation/complete/string_coercion.md) |
| 3 | `sound` | 99.0% | 622 | 628 | 6 | [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 4 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `edittext_stylesheet` | 91.7% | 298 | 325 | 27 | [41](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 12 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_condensewhite_swf8` | 80.1% | 249 | 311 | 62 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `focus_mouse_rollout` | 75.0% | 3 | 4 | 1 | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 20 | `tab_ordering_automatic_order_same_position` | 75.0% | 9 | 12 | 3 | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 25 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `loadmovie_var_persistence` | 62.5% | 5 | 8 | 3 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 28 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 29 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 31 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 32 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 33 | `register_class` | 57.6% | 38 | 66 | 28 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 34 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 35 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 36 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 37 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 38 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 39 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 40 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 41 | `bitmap_filters` | 50.9% | 279 | 548 | 269 | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 42 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 43 | `bad_placeobject_clipaction` | 50.0% | 1 | 2 | 1 |  |
| 44 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 46 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 47 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 48 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 49 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 14.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 14.1s |  |
| 3 | `netstream_play_flv_screen` | 27.1s |  |
| 4 | `string_paths_timer` | 14.2s |  |
| 5 | `timer_run_actions` | 21.0s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.1s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 35.9s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 21.7s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**169 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [8](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `string_coercion` | 99.1% | 116/117 | 117 | 117 | [39](ruffle-tests/_investigation/complete/string_coercion.md) |
| 3 | `sound` | 99.0% | 622/628 | 628 | 628 | [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 4 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `edittext_stylesheet` | 91.7% | 298/325 | 325 | 325 | [41](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 12 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `edittext_html_condensewhite_swf8` | 80.1% | 249/311 | 311 | 311 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `focus_mouse_rollout` | 75.0% | 3/4 | 3 | 4 | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 20 | `tab_ordering_automatic_order_same_position` | 75.0% | 9/12 | 12 | 12 | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 25 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `loadmovie_var_persistence` | 62.5% | 5/8 | 5 | 8 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 28 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 29 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 31 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 32 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 33 | `register_class` | 57.6% | 38/66 | 47 | 66 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 34 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 35 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 36 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 37 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 38 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 39 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 40 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 41 | `bitmap_filters` | 50.9% | 279/548 | 548 | 548 | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 42 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 43 | `bad_placeobject_clipaction` | 50.0% | 1/2 | 1 | 2 |  |
| 44 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 46 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 47 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 48 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 49 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 50 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 51 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 52 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 53 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 54 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 55 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 56 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 58 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 59 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 60 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 61 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 62 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 63 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 64 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 65 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 67 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 68 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 69 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 70 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 71 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 72 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 73 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 74 | `removed_target_clip_scope` | 32.4% | 12/37 | 37 | 35 | [4](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 75 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 76 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 77 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 78 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 79 | `default_names` | 28.8% | 15/52 | 48 | 52 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `movieclip_in_removed_button` | 25.0% | 1/4 | 3 | 4 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 82 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 83 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 84 | `call` | 20.6% | 13/63 | 48 | 63 | [4](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) |
| 85 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 86 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 87 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 88 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 89 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 90 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 91 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 92 | `mcl_events_swf_version` | 15.9% | 37/232 | 37 | 232 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 93 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 94 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 95 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 96 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 97 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 98 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 99 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 100 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 101 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 102 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 103 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 104 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 105 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 106 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 107 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 108 | `define_local` | 7.4% | 2/27 | 23 | 27 | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 109 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 110 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 111 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 112 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 113 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 114 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 115 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 116 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 117 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 118 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 119 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 120 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 121 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 122 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 123 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 124 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 125 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 126 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 127 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 128 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 129 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 130 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 131 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 132 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 133 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 134 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 135 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 136 | `button_order` | 0.0% | 0/2 | 0 | 2 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 137 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 138 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 139 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 140 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 141 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 142 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 143 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 144 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 145 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 146 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 147 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 148 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 149 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 150 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 151 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 152 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 153 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 154 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 155 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 156 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 157 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 158 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 159 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 160 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 161 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 162 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 163 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 164 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 165 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 166 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 167 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 168 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 169 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 11 | 3 |
| 4 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) | 2 | 0 | 2 |
| 5 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 6 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 2 | 2 |
| 7 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 8 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 9 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 10 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 11 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 12 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 4 | 3 |
| 13 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 14 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 15 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 23 | 8 |
| 16 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 17 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 18 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 19 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 25 | 24 |
| 20 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 21 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 22 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 23 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 24 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 25 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
| 26 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 27 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 28 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 29 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 30 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 31 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 32 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 10 | 2 |
| 33 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 34 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 35 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 36 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) | 2 | 1 | 1 |
| 37 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 38 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 39 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 40 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 41 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/incomplete/STYLESHEET_PLAN.md) | 1 | 0 | 1 |
| 42 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 43 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 13 | 3 |
| 44 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 45 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 51 | 19 |
| 46 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) | 4 | 0 | 4 |
| 47 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 48 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 49 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 50 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 51 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 52 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 53 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 227 | 152 | 75 |
