# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-07 03:31 UTC

**Git SHA**: `326c2cb15b`

**Run Duration**: 142m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **493** (79.6%) |
| Failing | 126 |
| Total expected lines | 91482 |
| Matching lines | 71667 (78.3%) |
| Mismatched lines | 19815 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 118 | 93.7% |
| Runtime Error | 4 | 3.2% |
| Runtime Segfault | 2 | 1.6% |
| Compile Fail | 1 | 0.8% |
| Timeout | 1 | 0.8% |

## Passing Tests

**493 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 13.7s |  |
| 2 | `action_to_integer` | 28 | 13.2s |  |
| 3 | `add` | 28 | 13.5s |  |
| 4 | `add2` | 354 | 13.4s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.2s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 13.2s |  |
| 7 | `add_swf5` | 28 | 13.2s |  |
| 8 | `arguments` | 127 | 13.1s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 13.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.4s |  |
| 11 | `array_constructor` | 30 | 13.4s |  |
| 12 | `array_enumerate` | 4 | 13.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 13.3s |  |
| 14 | `array_properties` | 36 | 13.2s |  |
| 15 | `array_prototyping` | 12 | 13.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.3s |  |
| 17 | `array_sort` | 161 | 13.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 13.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 13.3s |  |
| 20 | `array_trivial` | 209 | 13.4s |  |
| 21 | `as1_constructor_v6` | 35 | 13.4s |  |
| 22 | `as1_constructor_v7` | 35 | 15.3s |  |
| 23 | `as2_oop` | 13 | 14.4s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 13.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 13.6s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 13.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 13.7s |  |
| 29 | `as_broadcaster_undef` | 89 | 13.6s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 13.6s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 13.5s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 13.4s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 13.3s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 13.6s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 13.6s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 13.7s |  |
| 37 | `as_transformed_flag` | 20 | 13.7s |  |
| 38 | `asnative` | 34 | 13.7s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 13.8s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 15.3s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 14.0s |  |
| 44 | `bitand` | 1058 | 16.7s |  |
| 45 | `bitmap_data_colortransform` | 0 | 14.3s |  |
| 46 | `bitmap_data_fillrect` | 0 | 13.5s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 13.4s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 13.4s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 14.1s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 13.7s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.7s |  |
| 52 | `bitor` | 1058 | 16.1s |  |
| 53 | `biturshift` | 14 | 13.4s |  |
| 54 | `biturshift_swf8` | 14 | 15.5s |  |
| 55 | `bitxor` | 1058 | 15.9s |  |
| 56 | `boxed_primitives` | 24 | 13.3s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 13.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 13.5s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 13.3s |  |
| 71 | `capabilities_resolution` | 8 | 13.3s |  |
| 72 | `catch_references_registers` | 2 | 13.4s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 13.4s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 13.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 13.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 13.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 13.5s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `color` | 57 | 13.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 13.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 13.4s |  |
| 81 | `constructor_function` | 2 | 13.4s |  |
| 82 | `context_menu` | 39 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 13.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `custom_clip_methods` | 4 | 13.5s | [10](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `default_names` | 52 | 13.8s | [12](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `define_function2` | 8 | 13.5s |  |
| 88 | `define_function2_preload` | 13 | 13.4s |  |
| 89 | `define_function2_preload_order` | 4 | 14.6s |  |
| 90 | `define_function_case_sensitive` | 2 | 13.1s |  |
| 91 | `define_local` | 27 | 13.1s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 92 | `delete` | 3 | 13.1s |  |
| 93 | `device_font_spacing` | 91 | 13.2s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `display_object_properties` | 2 | 13.0s |  |
| 95 | `divide_swf4` | 107 | 13.1s |  |
| 96 | `do_init_action` | 3 | 13.1s |  |
| 97 | `do_init_action_child` | 12 | 13.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 98 | `drag_drop` | 10 | 13.1s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 99 | `drag_over_from_outside` | 1 | 13.1s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 100 | `drag_over_without_startdrag` | 1 | 13.2s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 101 | `duplicate_movie_clip` | 20 | 13.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 102 | `duplicate_movie_clip_drawing` | 2 | 13.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 103 | `edittext_align` | 60 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_align_trailing_spaces_swf7` | 576 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_align_trailing_spaces_swf8` | 576 | 13.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_antialiastype` | 296 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_autosize` | 71 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_autosize_setter` | 20 | 15.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_default_format` | 221 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_default_format_font_style` | 335 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_focus_selection` | 2 | 13.2s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_font_size` | 45 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_hscroll` | 27 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_html_align_swf7` | 52 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_align_swf8` | 52 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_color` | 114 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_condensewhite_swf7` | 311 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_condensewhite_swf8` | 311 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_entity` | 4 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_roundtrip` | 17 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_swf7` | 5377 | 14.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_swf8` | 5377 | 14.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_input` | 1 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_input_newlines` | 9 | 15.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_leading` | 9 | 14.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_letter_spacing` | 15 | 14.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_margins` | 25 | 14.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_newline_stripping` | 64 | 19.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_password` | 5 | 14.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_password_copy` | 4 | 14.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_paste_empty` | 2 | 14.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_place_caret` | 2 | 13.9s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_programmatic_focus` | 12 | 13.9s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_restrict` | 191 | 14.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_restrict_paste` | 5 | 13.9s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_stylesheet` | 325 | 14.9s | [51](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_tab_focus` | 13 | 14.1s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_tag_indent` | 31 | 14.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_text_height_leading` | 20 | 14.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_underline` | 40 | 14.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_width_height` | 103 | 14.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 142 | `empty_movieclip_can_attach_movies` | 11 | 14.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 143 | `enumerate` | 64 | 13.4s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 144 | `equals` | 32 | 13.6s |  |
| 145 | `equals2_swf5` | 926 | 15.2s |  |
| 146 | `equals2_swf6` | 926 | 15.2s |  |
| 147 | `equals2_swf7` | 926 | 15.3s |  |
| 148 | `equals_swf4` | 665 | 14.3s |  |
| 149 | `equals_swf4_alt` | 32 | 13.5s |  |
| 150 | `equals_swf5` | 32 | 13.7s |  |
| 151 | `error` | 58 | 14.0s |  |
| 152 | `escape` | 14 | 13.9s |  |
| 153 | `execution_order1` | 5 | 13.7s |  |
| 154 | `execution_order2` | 7 | 13.8s |  |
| 155 | `execution_order3` | 4 | 13.5s |  |
| 156 | `execution_order4` | 12 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 157 | `export_assets` | 3 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 158 | `extends_chain` | 134 | 14.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 159 | `extends_native_type` | 11 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 160 | `external_interface` | 84 | 14.7s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 161 | `external_interface_escapexml` | 26 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 162 | `external_interface_jsquotestring` | 21 | 14.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 163 | `external_interface_toas_basic` | 354 | 15.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 164 | `external_interface_toxml_array` | 25 | 13.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_toxml_basic` | 179 | 13.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_unescapexml` | 40 | 13.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `focus_mouse` | 45 | 13.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 168 | `focus_mouse_rollout` | 4 | 13.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 169 | `focus_root_movie` | 2 | 13.1s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 170 | `focusrect_focuslost` | 4 | 13.0s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 171 | `focusrect_mouse_swf8` | 0 | 13.0s |  |
| 172 | `focusrect_mouse_swf9` | 0 | 14.0s |  |
| 173 | `focusrect_swf5` | 6 | 14.1s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 174 | `focusrect_swf6` | 42 | 13.9s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 175 | `form_loader_encoding_1` | 1 | 13.9s |  |
| 176 | `frame_size_translated_negative` | 21 | 13.9s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 177 | `frame_size_translated_positive` | 21 | 13.9s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 178 | `function_as_function` | 35 | 13.8s | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 179 | `function_base_clip` | 8 | 13.8s |  |
| 180 | `function_base_clip_readded` | 11 | 13.9s |  |
| 181 | `function_base_clip_removed` | 25 | 14.0s |  |
| 182 | `function_suppress_and_preload` | 28 | 13.9s |  |
| 183 | `funky_function_calls` | 56 | 13.9s | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 184 | `get_bytes_total` | 4 | 13.8s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 185 | `get_variable_in_scope` | 29 | 13.9s |  |
| 186 | `getproperty` | 28 | 13.9s |  |
| 187 | `getproperty_swf4` | 28 | 17.7s |  |
| 188 | `getproperty_swf5` | 28 | 13.2s |  |
| 189 | `gettextextent` | 56 | 13.2s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 190 | `global_array` | 3 | 13.2s |  |
| 191 | `global_is_bare` | 7 | 13.2s |  |
| 192 | `global_swf6_7_8` | 15 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 193 | `globals_swf5` | 304 | 13.5s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 194 | `globals_swf6` | 304 | 13.4s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 195 | `globals_swf7` | 304 | 13.4s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 196 | `globals_swf8` | 304 | 13.5s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 197 | `goto_advance1` | 6 | 13.2s |  |
| 198 | `goto_advance2` | 2 | 13.3s |  |
| 199 | `goto_both_ways1` | 3 | 13.3s |  |
| 200 | `goto_both_ways2` | 3 | 13.3s |  |
| 201 | `goto_execution_order` | 2 | 13.2s |  |
| 202 | `goto_execution_order2` | 2 | 13.3s |  |
| 203 | `goto_frame` | 12 | 14.9s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 204 | `goto_frame2` | 44 | 13.8s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 205 | `goto_frame_number` | 3 | 13.3s |  |
| 206 | `goto_label` | 17 | 13.4s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 207 | `goto_methods` | 40 | 13.2s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 208 | `goto_rewind1` | 1 | 13.2s |  |
| 209 | `goto_rewind2` | 3 | 13.2s |  |
| 210 | `goto_rewind3` | 2 | 13.2s |  |
| 211 | `greater_swf6` | 1175 | 15.2s |  |
| 212 | `greater_swf7` | 1175 | 15.2s |  |
| 213 | `greaterthan_swf5` | 1 | 13.2s |  |
| 214 | `greaterthan_swf8` | 1 | 13.2s |  |
| 215 | `has_own_property` | 32 | 13.2s |  |
| 216 | `hittest_lockroot` | 15 | 13.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 217 | `hittest_morph` | 70 | 13.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 218 | `hittest_winding_rule` | 12 | 13.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 219 | `infinite_recursion_function` | 4 | 13.1s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 220 | `infinite_recursion_function_in_setter` | 131 | 13.2s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 221 | `infinite_recursion_virtual_property` | 67 | 13.2s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 222 | `init_array_invalid` | 4 | 13.2s |  |
| 223 | `init_object_invalid` | 4 | 14.1s |  |
| 224 | `init_object_order` | 15 | 13.7s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 225 | `instanceof_coercions` | 88 | 13.9s | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 226 | `is_finite` | 49 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 227 | `is_finite_swf6` | 49 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 228 | `is_prototype_of` | 89 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 229 | `issue_1086` | 1 | 13.5s |  |
| 230 | `issue_1104` | 2 | 13.5s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 231 | `issue_1671` | 0 | 13.4s |  |
| 232 | `issue_1906` | 4 | 13.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 233 | `issue_2166` | 9 | 13.9s |  |
| 234 | `issue_3169` | 2 | 13.5s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 235 | `issue_3446` | 1 | 13.4s |  |
| 236 | `issue_3522` | 2 | 13.3s |  |
| 237 | `issue_4377` | 2 | 13.5s |  |
| 238 | `issue_710` | 4 | 13.7s |  |
| 239 | `issue_768` | 3 | 13.5s | [25](ruffle-tests/_investigation/complete/issue_768.md) |
| 240 | `issue_9327` | 2 | 13.5s |  |
| 241 | `issue_9885` | 2 | 13.4s |  |
| 242 | `key_isToggled` | 9 | 13.4s |  |
| 243 | `lessthan` | 41 | 13.6s |  |
| 244 | `lessthan2_swf5` | 1226 | 15.6s |  |
| 245 | `lessthan2_swf6` | 1226 | 15.4s |  |
| 246 | `lessthan2_swf7` | 1226 | 15.4s |  |
| 247 | `lessthan_swf4` | 902 | 14.5s |  |
| 248 | `lessthan_swf4_alt` | 41 | 13.3s |  |
| 249 | `lessthan_swf5` | 41 | 13.6s |  |
| 250 | `loadmovie` | 2 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 251 | `loadmovie_fail` | 2 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 252 | `loadmovie_flashvars` | 4 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 253 | `loadmovie_method` | 2 | 13.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 254 | `loadmovie_replace_root` | 5 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 255 | `loadmovie_var_persistence` | 8 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 256 | `loadmovienum` | 3 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 257 | `loadvariables` | 2 | 13.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 258 | `loadvariables2` | 8 | 13.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 259 | `loadvariablesnum` | 2 | 13.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 260 | `local_to_global` | 49 | 13.4s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 261 | `localconnection_properties` | 8 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 262 | `lock_root` | 1 | 13.2s |  |
| 263 | `logical_ops_swf4` | 90 | 13.1s |  |
| 264 | `logical_ops_swf8` | 108 | 13.2s |  |
| 265 | `looping` | 6 | 13.1s |  |
| 266 | `mask_reapply` | 0 | 13.5s |  |
| 267 | `mask_with_drawing` | 0 | 13.2s |  |
| 268 | `math_min_max` | 101 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 269 | `math_swf6` | 530 | 13.5s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 270 | `math_swf7` | 530 | 13.5s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 271 | `math_swf8` | 530 | 13.5s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 272 | `matrix` | 171 | 13.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 273 | `mcl_as_broadcaster` | 12 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 274 | `mcl_events_swf_version` | 232 | 13.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 275 | `mcl_getprogress` | 30 | 13.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 276 | `mcl_loadclip` | 149 | 13.6s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 277 | `mcl_loadclip_properties` | 6 | 13.5s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 278 | `mcl_mislabeled_target` | 6 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 279 | `mcl_target_gif87a` | 6 | 13.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 280 | `mcl_target_gif89a` | 6 | 13.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mcl_target_jpg` | 6 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 282 | `mcl_target_png` | 6 | 14.0s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mcl_unloadclip` | 5 | 13.5s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 284 | `mouse_events` | 8 | 13.6s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 285 | `mouse_events_visible_enabled` | 12 | 13.9s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 286 | `mouse_hover_events_while_dragging` | 1 | 13.8s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 287 | `mouse_listeners` | 67 | 13.5s |  |
| 288 | `mouse_pos` | 665 | 13.4s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 289 | `mouse_pos_with_scale_factor` | 260 | 13.5s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 290 | `mouse_wheel_enabled` | 2 | 13.4s |  |
| 291 | `movieclip_begin_gradient_fill` | 0 | 13.9s |  |
| 292 | `movieclip_blend_mode_property` | 35 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 293 | `movieclip_create_text_field` | 90 | 13.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 294 | `movieclip_default_state` | 69 | 13.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 295 | `movieclip_depth_methods` | 98 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 296 | `movieclip_focusenabled` | 99 | 13.2s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 297 | `movieclip_get_instance_at_depth` | 28 | 13.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 298 | `movieclip_hittest` | 92 | 13.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 299 | `movieclip_in_removed_button` | 4 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 300 | `movieclip_init_object` | 5 | 13.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 301 | `movieclip_line_gradient_style` | 0 | 14.0s |  |
| 302 | `movieclip_name_from_timeline` | 13 | 13.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 303 | `movieclip_prototype_extension` | 5 | 13.2s |  |
| 304 | `moviecliploader_flashvars` | 4 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mutable_this` | 18 | 13.2s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 306 | `named_shapes` | 14 | 13.2s |  |
| 307 | `nan_scale` | 9 | 13.6s |  |
| 308 | `native_double_construct` | 12 | 13.5s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 309 | `native_objects_swf7` | 84 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 310 | `native_objects_swf8` | 84 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 311 | `native_subclasses` | 191 | 13.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 312 | `nested_textfields_in_buttons` | 0 | 13.2s |  |
| 313 | `new_method_wrap` | 4 | 13.9s |  |
| 314 | `new_object_enumerate` | 7 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 315 | `new_object_wrap` | 4 | 13.6s |  |
| 316 | `o` | 3 | 13.6s |  |
| 317 | `object_constructor` | 33 | 13.6s |  |
| 318 | `object_function` | 32 | 13.6s |  |
| 319 | `object_properties` | 31 | 13.7s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 320 | `object_prototypes` | 74 | 13.6s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 321 | `object_resolve` | 38 | 13.8s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 322 | `object_string_coerce_swf5` | 62 | 13.6s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 323 | `object_string_coerce_swf6` | 68 | 13.6s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 324 | `on_construct` | 25 | 13.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 325 | `parse_float` | 74 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 326 | `parse_int` | 64 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 327 | `path_string` | 322 | 13.8s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 328 | `place_and_lookup` | 30 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 329 | `placeobject_occupied_depth` | 6 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 330 | `point` | 175 | 14.2s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 331 | `primitive_instanceof` | 37 | 13.6s |  |
| 332 | `primitive_type_globals` | 557 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 333 | `printjob_props_swf5` | 45 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 334 | `printjob_props_swf6` | 45 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 335 | `printjob_props_swf7` | 45 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 336 | `property_invalid_base_clip` | 36 | 13.3s |  |
| 337 | `prototype_delete` | 12 | 13.3s |  |
| 338 | `prototype_enumerate` | 5 | 13.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 339 | `prototype_properties` | 17 | 13.2s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 340 | `rectangle` | 745 | 13.9s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 341 | `recursive_prototypes` | 0 | 13.2s |  |
| 342 | `register_class_return_value` | 16 | 13.2s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 343 | `register_class_with_sound` | 11 | 13.6s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 344 | `register_globals_across_frames` | 15 | 13.3s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 345 | `register_underflow` | 26 | 13.4s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 346 | `remove_movie_clip` | 29 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 347 | `rewind_depth` | 30 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 348 | `root_global_parent` | 6 | 13.6s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 349 | `sandbox_type_local_file` | 1 | 13.6s |  |
| 350 | `sandbox_type_local_network` | 1 | 13.5s |  |
| 351 | `selection` | 454 | 13.7s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 352 | `set_interval` | 27 | 13.7s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 353 | `set_variable_scope` | 58 | 13.4s |  |
| 354 | `single_frame` | 1 | 13.5s |  |
| 355 | `slash_syntax` | 14 | 13.5s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 356 | `sound` | 628 | 13.6s | [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 357 | `sound_props_swf5` | 68 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 358 | `sound_props_swf6` | 68 | 14.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 359 | `sound_start_load` | 0 | 13.9s |  |
| 360 | `stage_display_state` | 16 | 13.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 361 | `stage_object_children` | 83 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 362 | `stage_object_enumerate` | 4 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 363 | `stage_object_properties` | 241 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 364 | `stage_object_properties_get_var` | 5 | 13.4s |  |
| 365 | `stage_object_properties_swf6` | 231 | 13.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 366 | `stage_property_representation` | 586 | 13.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 367 | `stage_scale_mode` | 39 | 13.5s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 368 | `strictequals_swf6` | 902 | 15.1s |  |
| 369 | `strictly_equals` | 7 | 13.6s |  |
| 370 | `string_coercion` | 117 | 13.7s | [49](ruffle-tests/_investigation/complete/string_coercion.md) |
| 371 | `string_methods` | 285 | 14.0s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 372 | `string_methods_negative_args` | 240 | 13.9s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 373 | `string_methods_swfv5` | 275 | 14.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 374 | `string_ops_swf6` | 95 | 14.1s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 375 | `string_paths_basic` | 4 | 13.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 376 | `string_paths_eval2` | 7 | 13.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 377 | `string_paths_hidden` | 54 | 13.6s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 378 | `string_paths_other` | 36 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 379 | `string_paths_unload` | 1 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 380 | `string_paths_variable_alias` | 4 | 13.2s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 381 | `string_paths_variable_scopes` | 5 | 13.2s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 382 | `stylesheet` | 283 | 14.0s |  |
| 383 | `stylesheet_transform` | 750 | 14.4s |  |
| 384 | `super_edge_cases` | 39 | 13.4s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 385 | `swf4_actions_bool` | 96 | 13.2s |  |
| 386 | `swf4_actions_coercion_order` | 158 | 13.2s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 387 | `swf4_bool` | 4 | 13.1s |  |
| 388 | `swf4_function_calls` | 7 | 13.1s |  |
| 389 | `swf5_encoding` | 3 | 13.0s |  |
| 390 | `swf5_global_funcs` | 232 | 13.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 391 | `swf5_no_closure` | 19 | 13.6s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 392 | `swf6_case_insensitive` | 42 | 13.4s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 393 | `swf6_global_funcs` | 232 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 394 | `swf6_string_as_bool` | 15 | 13.6s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 395 | `swf7_case_sensitive` | 44 | 13.6s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 396 | `swf7_global_funcs` | 232 | 13.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 397 | `tab_ordering_automatic_basic` | 92 | 13.8s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 398 | `tab_ordering_automatic_order_grid` | 21 | 13.8s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 399 | `tab_ordering_automatic_order_same_position` | 12 | 13.8s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 400 | `tab_ordering_children` | 208 | 13.7s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 401 | `tab_ordering_custom_basic` | 71 | 13.7s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 402 | `tab_ordering_custom_duplicate_index` | 22 | 13.6s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 403 | `tab_ordering_custom_i32_vs_u32` | 12 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 404 | `tab_ordering_custom_m1` | 29 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 405 | `tab_ordering_events` | 150 | 13.7s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 406 | `tab_ordering_movieclip_enabled_default` | 462 | 13.5s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 407 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.2s |  |
| 408 | `tab_ordering_reverse` | 51 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 409 | `tab_ordering_tabbable` | 47 | 13.4s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 410 | `target_clip_swf5` | 2 | 13.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 411 | `target_clip_swf6` | 2 | 13.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 412 | `target_path` | 14 | 13.2s |  |
| 413 | `tell_target` | 37 | 13.3s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 414 | `tell_target_invalid` | 6 | 13.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 415 | `tell_target_invalid_swf6` | 5 | 13.3s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 416 | `text_format` | 1146 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 417 | `text_format_display` | 21 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 418 | `text_format_font_max_length` | 2 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 419 | `text_format_rounding_swf7` | 840 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 420 | `text_format_rounding_swf8` | 840 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 421 | `textfield_background_color` | 11 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 422 | `textfield_border_color` | 11 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 423 | `textfield_cache_as_bitmap` | 1 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 424 | `textfield_maxchars` | 3 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 425 | `textfield_properties` | 44 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 426 | `textfield_props_swf5` | 175 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 427 | `textfield_props_swf6` | 210 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 428 | `textfield_props_swf7` | 210 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 429 | `textfield_props_swf8` | 210 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 430 | `textfield_text` | 7 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 431 | `textfield_variable` | 81 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 432 | `textsnapshot_available_text` | 20 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 433 | `textsnapshot_findtext` | 44 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 434 | `textsnapshot_gettext` | 55 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 435 | `textsnapshot_props_swf5` | 56 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 436 | `textsnapshot_props_swf6` | 56 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 437 | `textsnapshot_text_order` | 1 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 438 | `this_scoping` | 52 | 13.4s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 439 | `this_swf5` | 41 | 13.3s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 440 | `this_swf6` | 41 | 13.3s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 441 | `this_swf7` | 41 | 13.3s | [58](ruffle-tests/_investigation/complete/this_swf7.md) |
| 442 | `timeline_function_def` | 7 | 13.5s |  |
| 443 | `trace` | 8 | 13.2s |  |
| 444 | `transform` | 70 | 13.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 445 | `try_catch_finally` | 118 | 13.4s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 446 | `try_finally_simple` | 16 | 13.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 447 | `typeof` | 22 | 13.3s |  |
| 448 | `typeof_globals` | 7 | 13.2s |  |
| 449 | `uncaught_exception` | 1 | 13.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 450 | `uncaught_exception_bubbled` | 1 | 13.1s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 451 | `undefined_to_string_swf6` | 4 | 13.1s |  |
| 452 | `unescape` | 43 | 13.2s |  |
| 453 | `unload` | 52 | 13.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 454 | `unload_clip_event` | 4 | 13.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 455 | `unloadmovie` | 4 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 456 | `unloadmovie_method` | 3 | 13.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 457 | `unloadmovienum` | 13 | 13.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 458 | `use_hand_cursor` | 8 | 13.3s |  |
| 459 | `variable_args` | 5 | 13.6s |  |
| 460 | `waitforframe` | 7 | 13.3s |  |
| 461 | `waitforframe2` | 16 | 14.0s |  |
| 462 | `watch` | 117 | 13.7s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 463 | `watch_textfield` | 12 | 13.4s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 464 | `watch_virtual_property_proto` | 2 | 13.6s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 465 | `with` | 49 | 13.5s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 466 | `with_return` | 2 | 13.4s |  |
| 467 | `with_variable_scopes` | 43 | 13.5s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 468 | `xml` | 15 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 469 | `xml_append_child` | 28 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 470 | `xml_append_child_with_parent` | 20 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 471 | `xml_attributes_read` | 4 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 472 | `xml_cdata` | 11 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 473 | `xml_child_nodes_edge_cases` | 4 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 474 | `xml_clone_expandos` | 19 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 475 | `xml_first_last_child` | 8 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 476 | `xml_has_child_nodes` | 3 | 13.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 477 | `xml_idmap` | 21 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 478 | `xml_ignore_comments` | 21 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 479 | `xml_ignore_white` | 34 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 480 | `xml_insert_before` | 20 | 13.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 481 | `xml_inspect_createmethods` | 15 | 13.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 482 | `xml_inspect_doctype` | 7 | 13.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 483 | `xml_inspect_parsexml` | 62 | 13.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 484 | `xml_inspect_xmldecl` | 7 | 13.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 485 | `xml_namespaces` | 203 | 13.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 486 | `xml_parent_and_child` | 5 | 13.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 487 | `xml_remove_node` | 22 | 13.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 488 | `xml_reparenting` | 14 | 13.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 489 | `xml_siblings` | 10 | 13.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 490 | `xml_to_string` | 13 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 491 | `xml_to_string_comment` | 1 | 13.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 492 | `xml_unescaping` | 23 | 13.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 493 | `xmlnode_proto` | 1 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**33 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `interface_implements_op` | 97.9% | 46 | 47 | 1 | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 9 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 10 | `movieclip_setmask` | 85.7% | 12 | 14 | 2 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `swf5_to_6_cross_call` | 79.3% | 23 | 29 | 6 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 14 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 15 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 18 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `register_class` | 66.7% | 44 | 66 | 22 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/incomplete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 25 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 26 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 27 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 28 | `swf6_to_5_cross_call` | 55.2% | 16 | 29 | 13 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 29 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 30 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 31 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 32 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 33 | `issue_2030` | 50.0% | 2 | 4 | 2 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 16.4s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 29.1s |  |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_1` | exit code -6 | 13.9s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_2` | exit code -6 | 14.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.7s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 37.1s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 23.6s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**118 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `interface_implements_op` | 97.9% | 46/47 | 47 | 47 | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 7 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 8 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 9 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 10 | `movieclip_setmask` | 85.7% | 12/14 | 14 | 14 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `swf5_to_6_cross_call` | 79.3% | 23/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 14 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 15 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 18 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 20 | `register_class` | 66.7% | 44/66 | 65 | 66 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/incomplete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 22 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 25 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 26 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 27 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 28 | `swf6_to_5_cross_call` | 55.2% | 16/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 29 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 30 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 31 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 32 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 33 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 34 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 35 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 36 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 37 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 38 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 39 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [40](ruffle-tests/_investigation/incomplete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 40 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 41 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 42 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 43 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 44 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 46 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 47 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 48 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 50 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 51 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 52 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 53 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 54 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 55 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 56 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 57 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 58 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 59 | `register_and_init_order` | 15.6% | 36/231 | 154 | 231 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 60 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 61 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 62 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 64 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 65 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 66 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 67 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 68 | `register_class_swf6` | 10.8% | 4/37 | 35 | 37 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 69 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 70 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 71 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 72 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 73 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 74 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [21](ruffle-tests/_investigation/incomplete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 75 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 76 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 77 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 78 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 79 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) |
| 80 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 82 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 83 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 84 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 85 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 86 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 87 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 88 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 89 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 90 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 91 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 92 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 93 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 95 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 96 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 97 | `geturl` | 0.0% | 0/7 | 0 | 7 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 98 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 99 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 100 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 101 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 102 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 103 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 105 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 106 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 107 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 108 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 109 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 110 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 111 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 112 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 113 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 114 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 115 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 116 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 117 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 118 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 3 | 1 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 11 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 12 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 13 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 14 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 15 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 16 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 17 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 5 | 2 |
| 18 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 19 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 20 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 21 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/incomplete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 0 | 1 |
| 22 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 26 | 5 |
| 23 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 24 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 25 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 26 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 27 | 22 |
| 27 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 2 | 3 |
| 28 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 29 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/incomplete/LOCKROOT_PLAN.md) | 1 | 0 | 1 |
| 30 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 31 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 32 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 33 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 33 | 25 |
| 34 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 13 | 3 |
| 35 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 36 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 37 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 38 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 39 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 40 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/incomplete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 0 | 1 |
| 41 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 42 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 43 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 44 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) | 2 | 0 | 2 |
| 45 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 3 | 1 |
| 46 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 47 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 48 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 49 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 50 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 51 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 52 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 53 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 15 | 1 |
| 54 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 55 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 62 | 8 |
| 56 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 57 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 58 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 59 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 60 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 61 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 62 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 5 | 11 |
| 63 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 64 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 65 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 195 | 156 | 39 |
