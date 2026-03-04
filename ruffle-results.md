# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-04 18:32 UTC

**Git SHA**: `dd1d31e455`

**Run Duration**: 130m 35s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **445** (71.9%) |
| Failing | 174 |
| Total expected lines | 91475 |
| Matching lines | 69099 (75.5%) |
| Mismatched lines | 22376 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 165 | 94.8% |
| Runtime Segfault | 5 | 2.9% |
| Runtime Error | 2 | 1.1% |
| Compile Fail | 1 | 0.6% |
| Timeout | 1 | 0.6% |

## Passing Tests

**445 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 19.5s |  |
| 2 | `action_to_integer` | 28 | 12.3s |  |
| 3 | `add` | 28 | 12.2s |  |
| 4 | `add2` | 354 | 12.4s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.2s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.1s |  |
| 7 | `add_swf5` | 28 | 12.1s |  |
| 8 | `arguments` | 127 | 12.1s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.2s |  |
| 11 | `array_constructor` | 30 | 12.2s |  |
| 12 | `array_enumerate` | 4 | 12.0s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.1s |  |
| 14 | `array_properties` | 36 | 12.1s |  |
| 15 | `array_prototyping` | 12 | 12.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.1s |  |
| 17 | `array_sort` | 161 | 12.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 12.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 12.3s |  |
| 20 | `array_trivial` | 209 | 12.2s |  |
| 21 | `as1_constructor_v6` | 35 | 12.1s |  |
| 22 | `as1_constructor_v7` | 35 | 12.7s |  |
| 23 | `as2_oop` | 13 | 12.5s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 12.2s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 12.3s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 12.2s |  |
| 28 | `as_set_prop_flags` | 79 | 12.6s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 29 | `as_set_prop_flags_version` | 31 | 12.7s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version_swf5` | 1 | 12.5s |  |
| 31 | `as_set_prop_flags_version_swf6` | 1 | 12.4s |  |
| 32 | `as_set_prop_flags_version_swf7` | 1 | 12.4s |  |
| 33 | `as_set_prop_flags_version_swf8` | 1 | 12.7s |  |
| 34 | `as_set_prop_flags_version_swf9` | 1 | 12.6s |  |
| 35 | `as_transformed_flag` | 20 | 12.6s |  |
| 36 | `attach_movie` | 59 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 37 | `attach_movie_stop` | 3 | 12.5s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `bad_placeobject_clipaction` | 2 | 12.2s |  |
| 39 | `bad_swf_tag_past_eof` | 0 | 11.8s |  |
| 40 | `bitand` | 1058 | 14.4s |  |
| 41 | `bitmap_data_colortransform` | 0 | 12.1s |  |
| 42 | `bitmap_data_fillrect` | 0 | 12.0s |  |
| 43 | `bitmap_data_max_size_swf10` | 12 | 11.9s |  |
| 44 | `bitmap_data_max_size_swf9` | 10 | 11.8s |  |
| 45 | `bitmap_data_perlinnoise` | 0 | 12.6s |  |
| 46 | `bitmap_data_pixeldissolve_image` | 0 | 12.3s |  |
| 47 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.0s |  |
| 48 | `bitor` | 1058 | 14.3s |  |
| 49 | `biturshift` | 14 | 11.8s |  |
| 50 | `biturshift_swf8` | 14 | 12.4s |  |
| 51 | `bitxor` | 1058 | 14.7s |  |
| 52 | `boxed_primitives` | 24 | 12.2s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 53 | `button_children` | 8 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 54 | `button_goto` | 4 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 55 | `button_key_events` | 14 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 56 | `button_key_events_special` | 45 | 13.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_keypress` | 3 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_keypress_vs_press` | 25 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_keypress_vs_tab` | 20 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_keypress_vs_textinput` | 4 | 12.2s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_order` | 2 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_properties_special_cases` | 22 | 12.3s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_v5` | 18 | 12.0s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_v6` | 18 | 12.1s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `call_method_empty_name` | 1 | 12.1s |  |
| 66 | `capabilities_resolution` | 8 | 12.1s |  |
| 67 | `catch_references_registers` | 2 | 12.1s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 68 | `click_block` | 5 | 12.2s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 69 | `clip_constructors` | 8 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 70 | `clip_events` | 19 | 13.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 71 | `clone_sprite_types` | 24 | 13.1s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `closure_scope` | 7 | 13.2s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 73 | `color` | 57 | 13.1s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 74 | `color_transform` | 48 | 12.5s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 75 | `conflicting_instance_names` | 23 | 12.3s |  |
| 76 | `constructor_function` | 2 | 12.3s |  |
| 77 | `context_menu` | 39 | 12.4s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 78 | `context_menu_item` | 41 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 79 | `create_empty_movie_clip` | 3 | 12.4s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `define_function2` | 8 | 12.4s |  |
| 81 | `define_function2_preload` | 13 | 12.4s |  |
| 82 | `define_function2_preload_order` | 4 | 13.6s |  |
| 83 | `define_function_case_sensitive` | 2 | 12.2s |  |
| 84 | `delete` | 3 | 12.2s |  |
| 85 | `display_object_properties` | 2 | 12.1s |  |
| 86 | `divide_swf4` | 107 | 12.2s |  |
| 87 | `do_init_action` | 3 | 12.2s |  |
| 88 | `do_init_action_child` | 12 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 89 | `drag_drop` | 10 | 12.2s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 90 | `drag_over_from_outside` | 1 | 12.6s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 91 | `drag_over_without_startdrag` | 1 | 12.2s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 92 | `duplicate_movie_clip` | 20 | 12.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `edittext_align` | 60 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 94 | `edittext_align_trailing_spaces_swf7` | 576 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 95 | `edittext_align_trailing_spaces_swf8` | 576 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 96 | `edittext_antialiastype` | 296 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_autosize` | 71 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_autosize_setter` | 20 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_default_format` | 221 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_default_format_font_style` | 335 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_font_size` | 45 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_hscroll` | 27 | 11.9s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_html_align_swf7` | 52 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_align_swf8` | 52 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_color` | 114 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_entity` | 4 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_roundtrip` | 17 | 11.9s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_swf7` | 5377 | 12.9s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_swf8` | 5377 | 12.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_input` | 1 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_leading` | 9 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_letter_spacing` | 15 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_margins` | 25 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_newline_stripping` | 64 | 16.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_password` | 5 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_password_copy` | 4 | 11.9s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_paste_empty` | 2 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_programmatic_focus` | 12 | 11.9s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_restrict` | 191 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_restrict_paste` | 5 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_tag_indent` | 31 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_text_height_leading` | 20 | 12.1s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_underline` | 40 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_width_height` | 103 | 12.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `empty_movieclip_can_attach_movies` | 11 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 126 | `enumerate` | 64 | 12.2s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 127 | `equals` | 32 | 12.2s |  |
| 128 | `equals2_swf5` | 926 | 14.0s |  |
| 129 | `equals2_swf6` | 926 | 14.0s |  |
| 130 | `equals2_swf7` | 926 | 13.8s |  |
| 131 | `equals_swf4` | 665 | 12.9s |  |
| 132 | `equals_swf4_alt` | 32 | 12.1s |  |
| 133 | `equals_swf5` | 32 | 12.1s |  |
| 134 | `error` | 58 | 12.0s |  |
| 135 | `escape` | 14 | 12.1s |  |
| 136 | `execution_order1` | 5 | 12.2s |  |
| 137 | `execution_order2` | 7 | 12.2s |  |
| 138 | `execution_order3` | 4 | 12.1s |  |
| 139 | `execution_order4` | 12 | 12.4s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 140 | `export_assets` | 3 | 12.0s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 141 | `extends_chain` | 134 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 142 | `extends_native_type` | 11 | 12.1s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 143 | `focus_mouse` | 45 | 12.1s | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 144 | `focus_root_movie` | 2 | 12.1s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 145 | `focusrect_focuslost` | 4 | 12.0s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 146 | `focusrect_mouse_swf8` | 0 | 12.0s |  |
| 147 | `focusrect_mouse_swf9` | 0 | 15.1s |  |
| 148 | `focusrect_swf5` | 6 | 13.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 149 | `focusrect_swf6` | 42 | 13.1s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 150 | `form_loader_encoding_1` | 1 | 13.2s |  |
| 151 | `frame_size_translated_negative` | 21 | 12.9s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 152 | `frame_size_translated_positive` | 21 | 13.0s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) |
| 153 | `function_base_clip` | 8 | 13.0s |  |
| 154 | `function_base_clip_removed` | 25 | 12.4s |  |
| 155 | `function_suppress_and_preload` | 28 | 12.5s |  |
| 156 | `get_variable_in_scope` | 29 | 12.4s |  |
| 157 | `getproperty` | 28 | 12.2s |  |
| 158 | `getproperty_swf4` | 28 | 13.4s |  |
| 159 | `getproperty_swf5` | 28 | 12.1s |  |
| 160 | `global_array` | 3 | 12.1s |  |
| 161 | `global_is_bare` | 7 | 12.0s |  |
| 162 | `global_swf6_7_8` | 15 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 163 | `globals_swf5` | 304 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 164 | `globals_swf6` | 304 | 12.2s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 165 | `globals_swf7` | 304 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 166 | `globals_swf8` | 304 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 167 | `goto_advance1` | 6 | 12.0s |  |
| 168 | `goto_advance2` | 2 | 12.0s |  |
| 169 | `goto_both_ways1` | 3 | 12.0s |  |
| 170 | `goto_both_ways2` | 3 | 12.2s |  |
| 171 | `goto_execution_order` | 2 | 12.1s |  |
| 172 | `goto_execution_order2` | 2 | 12.0s |  |
| 173 | `goto_frame` | 12 | 12.7s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 174 | `goto_frame2` | 44 | 12.4s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 175 | `goto_frame_number` | 3 | 12.1s |  |
| 176 | `goto_label` | 17 | 12.2s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 177 | `goto_methods` | 40 | 12.0s | [13](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 178 | `goto_rewind1` | 1 | 12.0s |  |
| 179 | `goto_rewind2` | 3 | 12.0s |  |
| 180 | `goto_rewind3` | 2 | 11.9s |  |
| 181 | `greater_swf6` | 1175 | 13.8s |  |
| 182 | `greater_swf7` | 1175 | 13.9s |  |
| 183 | `greaterthan_swf5` | 1 | 11.9s |  |
| 184 | `greaterthan_swf8` | 1 | 12.0s |  |
| 185 | `has_own_property` | 32 | 12.0s |  |
| 186 | `hittest_lockroot` | 15 | 12.1s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 187 | `hittest_morph` | 70 | 12.2s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 188 | `hittest_winding_rule` | 12 | 12.1s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 189 | `infinite_recursion_function` | 4 | 11.9s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 190 | `infinite_recursion_function_in_setter` | 131 | 11.9s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 191 | `infinite_recursion_virtual_property` | 67 | 11.9s | [17](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 192 | `init_array_invalid` | 4 | 11.9s |  |
| 193 | `init_object_invalid` | 4 | 11.9s |  |
| 194 | `init_object_order` | 15 | 11.9s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 195 | `is_finite` | 49 | 11.8s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 196 | `is_finite_swf6` | 49 | 11.8s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 197 | `is_prototype_of` | 89 | 11.8s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 198 | `issue_1086` | 1 | 11.7s |  |
| 199 | `issue_1104` | 2 | 11.8s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 200 | `issue_1671` | 0 | 11.7s |  |
| 201 | `issue_1906` | 4 | 11.8s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 202 | `issue_2166` | 9 | 11.5s |  |
| 203 | `issue_3446` | 1 | 11.7s |  |
| 204 | `issue_3522` | 2 | 11.6s |  |
| 205 | `issue_4377` | 2 | 11.7s |  |
| 206 | `issue_710` | 4 | 11.9s |  |
| 207 | `issue_768` | 3 | 14.4s | [18](ruffle-tests/_investigation/complete/issue_768.md) |
| 208 | `issue_9327` | 2 | 12.9s |  |
| 209 | `issue_9885` | 2 | 12.6s |  |
| 210 | `key_isToggled` | 9 | 12.9s |  |
| 211 | `lessthan` | 41 | 12.8s |  |
| 212 | `lessthan2_swf5` | 1226 | 14.8s |  |
| 213 | `lessthan2_swf6` | 1226 | 14.8s |  |
| 214 | `lessthan2_swf7` | 1226 | 14.8s |  |
| 215 | `lessthan_swf4` | 902 | 13.9s |  |
| 216 | `lessthan_swf4_alt` | 41 | 12.6s |  |
| 217 | `lessthan_swf5` | 41 | 12.5s |  |
| 218 | `loadmovie` | 2 | 12.5s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 219 | `loadmovie_fail` | 2 | 12.7s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 220 | `loadmovie_flashvars` | 4 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 221 | `loadmovie_method` | 2 | 12.5s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 222 | `loadmovie_replace_root` | 5 | 12.6s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 223 | `loadmovienum` | 3 | 12.6s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 224 | `loadvariables` | 2 | 11.9s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 225 | `loadvariables2` | 8 | 12.1s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 226 | `loadvariablesnum` | 2 | 12.0s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 227 | `local_to_global` | 49 | 12.1s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 228 | `localconnection_properties` | 8 | 12.0s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 229 | `lock_root` | 1 | 12.0s |  |
| 230 | `logical_ops_swf4` | 90 | 11.9s |  |
| 231 | `logical_ops_swf8` | 108 | 12.1s |  |
| 232 | `looping` | 6 | 12.0s |  |
| 233 | `mask_reapply` | 0 | 11.9s |  |
| 234 | `mask_with_drawing` | 0 | 12.1s |  |
| 235 | `math_min_max` | 101 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 236 | `math_swf6` | 530 | 12.3s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 237 | `math_swf7` | 530 | 12.2s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 238 | `math_swf8` | 530 | 12.2s | [22](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 239 | `matrix` | 171 | 12.2s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 240 | `mcl_as_broadcaster` | 12 | 11.8s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 241 | `mcl_getprogress` | 30 | 12.7s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 242 | `mcl_loadclip` | 149 | 12.5s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 243 | `mcl_loadclip_properties` | 6 | 12.5s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 244 | `mcl_mislabeled_target` | 6 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 245 | `mcl_target_gif87a` | 6 | 12.8s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 246 | `mcl_target_gif89a` | 6 | 12.8s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 247 | `mcl_target_jpg` | 6 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 248 | `mcl_target_png` | 6 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 249 | `mcl_unloadclip` | 5 | 12.4s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 250 | `mouse_events` | 8 | 12.5s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 251 | `mouse_events_visible_enabled` | 12 | 12.7s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 252 | `mouse_hover_events_while_dragging` | 1 | 12.8s | [9](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 253 | `mouse_listeners` | 67 | 12.5s |  |
| 254 | `mouse_pos` | 665 | 12.6s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 255 | `mouse_pos_with_scale_factor` | 260 | 12.8s | [24](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 256 | `mouse_wheel_enabled` | 2 | 12.3s |  |
| 257 | `movieclip_begin_gradient_fill` | 0 | 12.9s |  |
| 258 | `movieclip_blend_mode_property` | 35 | 14.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 259 | `movieclip_create_text_field` | 90 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 260 | `movieclip_default_state` | 69 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 261 | `movieclip_depth_methods` | 98 | 12.2s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 262 | `movieclip_focusenabled` | 99 | 12.1s | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 263 | `movieclip_get_instance_at_depth` | 28 | 12.0s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 264 | `movieclip_hittest` | 92 | 12.6s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 265 | `movieclip_in_removed_button` | 4 | 12.4s | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 266 | `movieclip_init_object` | 5 | 12.8s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 267 | `movieclip_line_gradient_style` | 0 | 12.9s |  |
| 268 | `movieclip_name_from_timeline` | 13 | 12.1s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 269 | `movieclip_prototype_extension` | 5 | 12.1s |  |
| 270 | `moviecliploader_flashvars` | 4 | 12.1s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 271 | `mutable_this` | 18 | 12.2s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 272 | `named_shapes` | 14 | 12.2s |  |
| 273 | `nan_scale` | 9 | 12.4s |  |
| 274 | `native_double_construct` | 12 | 12.4s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 275 | `native_objects_swf7` | 84 | 12.8s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 276 | `native_objects_swf8` | 84 | 12.8s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 277 | `native_subclasses` | 191 | 12.7s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 278 | `nested_textfields_in_buttons` | 0 | 12.3s |  |
| 279 | `new_method_wrap` | 4 | 12.2s |  |
| 280 | `new_object_enumerate` | 7 | 12.2s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 281 | `new_object_wrap` | 4 | 12.2s |  |
| 282 | `o` | 3 | 12.2s |  |
| 283 | `object_constructor` | 33 | 12.3s |  |
| 284 | `object_function` | 32 | 12.3s |  |
| 285 | `object_properties` | 31 | 12.3s | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 286 | `object_prototypes` | 74 | 12.3s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 287 | `object_string_coerce_swf5` | 62 | 12.3s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 288 | `object_string_coerce_swf6` | 68 | 12.4s | [28](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 289 | `on_construct` | 25 | 12.2s | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 290 | `parse_float` | 74 | 12.3s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 291 | `parse_int` | 64 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 292 | `path_string` | 322 | 12.5s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 293 | `place_and_lookup` | 30 | 12.3s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 294 | `placeobject_occupied_depth` | 6 | 12.3s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 295 | `point` | 175 | 12.6s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 296 | `primitive_instanceof` | 37 | 12.2s |  |
| 297 | `primitive_type_globals` | 557 | 20.1s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 298 | `printjob_props_swf5` | 45 | 12.6s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 299 | `printjob_props_swf6` | 45 | 12.8s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 300 | `printjob_props_swf7` | 45 | 13.0s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 301 | `property_invalid_base_clip` | 36 | 13.2s |  |
| 302 | `prototype_delete` | 12 | 12.6s |  |
| 303 | `prototype_enumerate` | 5 | 12.6s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 304 | `prototype_properties` | 17 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 305 | `rectangle` | 745 | 13.1s | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 306 | `recursive_prototypes` | 0 | 12.3s |  |
| 307 | `register_class_return_value` | 16 | 12.6s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 308 | `register_class_with_sound` | 11 | 12.5s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [36](ruffle-tests/_investigation/blocked/SOUND_CLASS_PLAN.md) |
| 309 | `register_globals_across_frames` | 15 | 12.4s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 310 | `register_underflow` | 26 | 12.3s | [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 311 | `remove_movie_clip` | 29 | 12.4s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 312 | `rewind_depth` | 30 | 12.4s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 313 | `sandbox_type_local_file` | 1 | 12.2s |  |
| 314 | `sandbox_type_local_network` | 1 | 12.1s |  |
| 315 | `selection` | 454 | 12.4s | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 316 | `set_interval` | 27 | 12.2s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 317 | `set_variable_scope` | 58 | 12.1s |  |
| 318 | `single_frame` | 1 | 12.1s |  |
| 319 | `slash_syntax` | 14 | 12.1s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 320 | `sound_props_swf5` | 68 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 321 | `sound_props_swf6` | 68 | 12.2s | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 322 | `sound_start_load` | 0 | 12.2s |  |
| 323 | `stage_display_state` | 16 | 12.2s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 324 | `stage_object_children` | 83 | 12.3s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 325 | `stage_object_enumerate` | 4 | 12.2s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 326 | `stage_object_properties` | 241 | 12.5s | [11](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 327 | `stage_object_properties_get_var` | 5 | 12.1s |  |
| 328 | `stage_object_properties_swf6` | 231 | 12.4s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 329 | `stage_property_representation` | 586 | 12.2s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 330 | `stage_scale_mode` | 39 | 12.3s | [37](ruffle-tests/_investigation/blocked/STAGE_FRAME_PROPS_PLAN.md) [38](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 331 | `strictequals_swf6` | 902 | 13.7s |  |
| 332 | `strictly_equals` | 7 | 12.2s |  |
| 333 | `string_methods` | 285 | 12.9s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 334 | `string_methods_negative_args` | 240 | 12.4s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 335 | `string_methods_swfv5` | 275 | 12.8s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 336 | `string_ops_swf6` | 95 | 12.3s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 337 | `string_paths_basic` | 4 | 12.3s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 338 | `string_paths_eval2` | 7 | 12.8s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 339 | `string_paths_hidden` | 54 | 12.8s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 340 | `string_paths_other` | 36 | 13.1s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 341 | `string_paths_unload` | 1 | 12.9s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 342 | `string_paths_variable_alias` | 4 | 12.7s | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 343 | `string_paths_variable_scopes` | 5 | 12.7s | [10](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 344 | `super_edge_cases` | 39 | 12.9s | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 345 | `swf4_actions_bool` | 96 | 12.9s |  |
| 346 | `swf4_actions_coercion_order` | 158 | 12.8s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 347 | `swf4_bool` | 4 | 12.7s |  |
| 348 | `swf4_function_calls` | 7 | 12.7s |  |
| 349 | `swf5_encoding` | 3 | 12.8s |  |
| 350 | `swf5_no_closure` | 19 | 12.5s | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 351 | `swf6_case_insensitive` | 42 | 11.9s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 352 | `swf6_string_as_bool` | 15 | 11.9s | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 353 | `swf7_case_sensitive` | 44 | 11.9s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 354 | `tab_ordering_automatic_basic` | 92 | 12.0s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 355 | `tab_ordering_automatic_order_grid` | 21 | 11.9s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 356 | `tab_ordering_children` | 208 | 12.1s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 357 | `tab_ordering_custom_basic` | 71 | 12.1s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 358 | `tab_ordering_custom_duplicate_index` | 22 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 359 | `tab_ordering_custom_i32_vs_u32` | 12 | 12.1s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 360 | `tab_ordering_custom_m1` | 29 | 12.0s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 361 | `tab_ordering_events` | 150 | 12.4s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 362 | `tab_ordering_movieclip_enabled_default` | 462 | 12.2s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 363 | `tab_ordering_properties_tab_index_edge_case` | 4 | 12.4s |  |
| 364 | `tab_ordering_reverse` | 51 | 12.3s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 365 | `tab_ordering_tabbable` | 47 | 12.5s | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 366 | `target_clip_swf5` | 2 | 12.1s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 367 | `target_clip_swf6` | 2 | 12.1s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 368 | `target_path` | 14 | 12.2s |  |
| 369 | `tell_target` | 37 | 12.2s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 370 | `tell_target_invalid` | 6 | 12.3s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 371 | `tell_target_invalid_swf6` | 5 | 12.3s | [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 372 | `text_format` | 1146 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 373 | `text_format_display` | 21 | 12.2s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 374 | `text_format_font_max_length` | 2 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 375 | `text_format_rounding_swf7` | 840 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 376 | `text_format_rounding_swf8` | 840 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 377 | `textfield_background_color` | 11 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 378 | `textfield_border_color` | 11 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 379 | `textfield_cache_as_bitmap` | 1 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 380 | `textfield_maxchars` | 3 | 14.7s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 381 | `textfield_properties` | 44 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 382 | `textfield_props_swf5` | 175 | 12.7s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 383 | `textfield_props_swf6` | 210 | 12.8s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 384 | `textfield_props_swf7` | 210 | 12.7s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 385 | `textfield_props_swf8` | 210 | 12.7s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 386 | `textfield_text` | 7 | 12.5s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 387 | `textfield_variable` | 81 | 12.7s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 388 | `textsnapshot_props_swf5` | 56 | 12.4s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 389 | `textsnapshot_props_swf6` | 56 | 12.6s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 390 | `this_scoping` | 52 | 12.9s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 391 | `this_swf5` | 41 | 12.8s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 392 | `this_swf6` | 41 | 12.6s | [47](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 393 | `this_swf7` | 41 | 12.7s | [48](ruffle-tests/_investigation/complete/this_swf7.md) |
| 394 | `timeline_function_def` | 7 | 12.6s |  |
| 395 | `trace` | 8 | 12.8s |  |
| 396 | `transform` | 70 | 13.0s | [7](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 397 | `try_catch_finally` | 118 | 12.8s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 398 | `try_finally_simple` | 16 | 12.6s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 399 | `typeof` | 22 | 12.8s |  |
| 400 | `typeof_globals` | 7 | 12.8s |  |
| 401 | `uncaught_exception` | 1 | 12.8s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 402 | `uncaught_exception_bubbled` | 1 | 12.7s | [50](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 403 | `undefined_to_string_swf6` | 4 | 12.7s |  |
| 404 | `unescape` | 43 | 12.7s |  |
| 405 | `unload` | 52 | 12.9s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 406 | `unload_clip_event` | 4 | 12.8s | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 407 | `unloadmovie` | 4 | 12.8s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 408 | `unloadmovie_method` | 3 | 12.9s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 409 | `unloadmovienum` | 13 | 12.8s | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 410 | `use_hand_cursor` | 8 | 12.7s |  |
| 411 | `variable_args` | 5 | 12.9s |  |
| 412 | `waitforframe` | 7 | 12.7s |  |
| 413 | `waitforframe2` | 16 | 12.9s |  |
| 414 | `watch` | 117 | 12.6s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 415 | `watch_textfield` | 12 | 12.2s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 416 | `watch_virtual_property_proto` | 2 | 12.3s | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 417 | `with` | 49 | 12.3s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 418 | `with_return` | 2 | 12.2s |  |
| 419 | `with_variable_scopes` | 43 | 12.4s | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 420 | `xml` | 15 | 12.3s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 421 | `xml_append_child` | 28 | 12.1s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 422 | `xml_append_child_with_parent` | 20 | 12.2s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 423 | `xml_attributes_read` | 4 | 12.1s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 424 | `xml_cdata` | 11 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 425 | `xml_child_nodes_edge_cases` | 4 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 426 | `xml_clone_expandos` | 19 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 427 | `xml_first_last_child` | 8 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 428 | `xml_has_child_nodes` | 3 | 12.2s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 429 | `xml_idmap` | 21 | 12.2s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 430 | `xml_ignore_comments` | 21 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 431 | `xml_ignore_white` | 34 | 12.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 432 | `xml_insert_before` | 20 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 433 | `xml_inspect_createmethods` | 15 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 434 | `xml_inspect_doctype` | 7 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 435 | `xml_inspect_parsexml` | 62 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 436 | `xml_inspect_xmldecl` | 7 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 437 | `xml_namespaces` | 203 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 438 | `xml_parent_and_child` | 5 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 439 | `xml_remove_node` | 22 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 440 | `xml_reparenting` | 14 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 441 | `xml_siblings` | 10 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 442 | `xml_to_string` | 13 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 443 | `xml_to_string_comment` | 1 | 11.8s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 444 | `xml_unescaping` | 23 | 12.0s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 445 | `xmlnode_proto` | 1 | 11.9s | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**47 tests** within reach

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
| 23 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 26 | `loadmovie_var_persistence` | 62.5% | 5 | 8 | 3 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 27 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 28 | `clone_sprite_edittext_dynamic` | 59.3% | 51 | 86 | 35 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 30 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 31 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 32 | `register_class` | 57.6% | 38 | 66 | 28 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 33 | `asnative` | 55.9% | 19 | 34 | 15 |  |
| 34 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 35 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 36 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 37 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 38 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 39 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 40 | `bitmap_filters` | 50.9% | 279 | 548 | 269 | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 41 | `device_font_spacing` | 50.5% | 46 | 91 | 45 |  |
| 42 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 44 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 45 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 46 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 47 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_ime_focus_lost` | 14.0s | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `funky_function_calls` | 14.6s |  |
| 3 | `netstream_play_flv_screen` | 27.8s |  |
| 4 | `string_paths_timer` | 14.7s |  |
| 5 | `timer_run_actions` | 22.1s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.1s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 36.4s | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 22.6s | [49](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**165 tests** with output mismatch, sorted by match rate (best first)

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
| 23 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 26 | `loadmovie_var_persistence` | 62.5% | 5/8 | 5 | 8 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 27 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 28 | `clone_sprite_edittext_dynamic` | 59.3% | 51/86 | 86 | 86 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 30 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 31 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 32 | `register_class` | 57.6% | 38/66 | 47 | 66 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 33 | `asnative` | 55.9% | 19/34 | 31 | 34 |  |
| 34 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 35 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 36 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 37 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 38 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 39 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 40 | `bitmap_filters` | 50.9% | 279/548 | 548 | 548 | [27](ruffle-tests/_investigation/blocked/NATIVE_INTROSPECTION_PLAN.md) |
| 41 | `device_font_spacing` | 50.5% | 46/91 | 91 | 91 |  |
| 42 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [35](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 44 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 45 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 46 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 47 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 48 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 49 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 50 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 51 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 52 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 53 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 54 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 55 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 56 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [43](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 57 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 58 | `define_local_with_paths` | 38.9% | 21/54 | 34 | 54 |  |
| 59 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 60 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 61 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 62 | `object_resolve` | 36.8% | 14/38 | 30 | 38 | [32](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 63 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `swf5_to_6_cross_call` | 34.5% | 10/29 | 11 | 29 | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 65 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 66 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 67 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 68 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 |  |
| 69 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 70 | `swf6_global_funcs` | 32.8% | 76/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 71 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 72 | `removed_target_clip_scope` | 32.4% | 12/37 | 37 | 35 | [4](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 73 | `swf5_global_funcs` | 31.5% | 73/232 | 232 | 232 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 74 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 75 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 76 | `asnew` | 29.4% | 10/34 | 18 | 34 |  |
| 77 | `default_names` | 28.8% | 15/52 | 48 | 52 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `clone_sprite_edittext` | 26.6% | 25/94 | 94 | 94 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [42](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 80 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 81 | `call` | 20.6% | 13/63 | 48 | 63 | [4](ruffle-tests/_investigation/incomplete/CALL_SEMANTICS_PLAN.md) |
| 82 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 83 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 84 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 85 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 86 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 88 | `as_broadcaster` | 17.1% | 7/41 | 26 | 41 |  |
| 89 | `mcl_events_swf_version` | 15.9% | 37/232 | 37 | 232 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 90 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 91 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 92 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [6](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 94 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [29](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 95 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 96 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 97 | `instanceof_coercions` | 13.6% | 12/88 | 70 | 88 |  |
| 98 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 99 | `localconnection` | 12.8% | 74/579 | 261 | 579 |  |
| 100 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 101 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 102 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 103 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 104 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 105 | `define_local` | 7.4% | 2/27 | 23 | 27 | [52](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 106 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 107 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 108 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 109 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 110 | `coerce_to_object_monkeypatch` | 5.4% | 7/129 | 116 | 129 |  |
| 111 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 112 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 113 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 114 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 115 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 116 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 117 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 118 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 119 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 120 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [20](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 121 | `interface_implements_op` | 2.1% | 1/47 | 43 | 47 | [30](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 122 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 123 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 124 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 125 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 126 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 127 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 128 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 129 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 130 | `global_proto_decls` | 0.2% | 11/4497 | 676 | 4497 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 131 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [14](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 132 | `asfunction` | 0.0% | 0/11 | 0 | 11 |  |
| 133 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [5](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 134 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 135 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 136 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 137 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 138 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 139 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [12](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 140 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 141 | `get_bytes_total` | 0.0% | 0/4 | 4 | 4 |  |
| 142 | `geturl` | 0.0% | 0/7 | 0 | 7 |  |
| 143 | `global_proto_decls_delete` | 0.0% | 0/4158 | 305 | 4158 | [15](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 144 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [16](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 145 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 146 | `issue_3169` | 0.0% | 0/2 | 1 | 2 |  |
| 147 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [21](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 148 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [26](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [34](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 149 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 150 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 151 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 152 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 153 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 154 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [3](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [19](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 155 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 156 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 157 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 |  |
| 158 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [40](ruffle-tests/_investigation/complete/STRING_PLAN.md) [44](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 159 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 160 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [45](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [46](ruffle-tests/_investigation/incomplete/TEXTSNAPSHOT_PLAN.md) |
| 161 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [25](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 162 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 163 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 164 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 165 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [53](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
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
| 25 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
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
| | *(tests not in any document)* | 227 | 153 | 74 |
