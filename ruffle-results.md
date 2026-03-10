# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-10 01:19 UTC

**Git SHA**: `e40afd5265`

**Run Duration**: 149m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 618 |
| Passing | **502** (81.2%) |
| Failing | 116 |
| Total expected lines | 91483 |
| Matching lines | 71989 (78.7%) |
| Mismatched lines | 19494 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 108 | 93.1% |
| Runtime Error | 4 | 3.4% |
| Runtime Segfault | 2 | 1.7% |
| Compile Fail | 1 | 0.9% |
| Timeout | 1 | 0.9% |

## Passing Tests

**502 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.6s |  |
| 2 | `action_to_integer` | 28 | 14.1s |  |
| 3 | `add` | 28 | 14.1s |  |
| 4 | `add2` | 354 | 14.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.1s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.0s |  |
| 7 | `add_swf5` | 28 | 14.1s |  |
| 8 | `arguments` | 127 | 14.0s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.9s |  |
| 11 | `array_constructor` | 30 | 14.0s |  |
| 12 | `array_enumerate` | 4 | 13.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.1s |  |
| 14 | `array_properties` | 36 | 13.9s |  |
| 15 | `array_prototyping` | 12 | 14.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 14.1s |  |
| 17 | `array_sort` | 161 | 15.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 14.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 14.1s |  |
| 20 | `array_trivial` | 209 | 14.2s |  |
| 21 | `as1_constructor_v6` | 35 | 14.0s |  |
| 22 | `as1_constructor_v7` | 35 | 14.3s |  |
| 23 | `as2_oop` | 13 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 14.2s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 14.1s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 14.0s |  |
| 29 | `as_broadcaster_undef` | 89 | 14.2s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 14.2s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 14.0s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 14.0s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 14.0s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 14.1s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 14.0s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 14.2s |  |
| 37 | `as_transformed_flag` | 20 | 13.9s |  |
| 38 | `asnative` | 34 | 13.9s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 14.0s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 14.6s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 15.9s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 14.2s |  |
| 44 | `bitand` | 1058 | 17.1s |  |
| 45 | `bitmap_data_colortransform` | 0 | 14.5s |  |
| 46 | `bitmap_data_fillrect` | 0 | 14.3s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 14.1s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 14.0s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 14.8s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 14.4s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.4s |  |
| 52 | `bitor` | 1058 | 17.2s |  |
| 53 | `biturshift` | 14 | 14.2s |  |
| 54 | `biturshift_swf8` | 14 | 16.2s |  |
| 55 | `bitxor` | 1058 | 16.9s |  |
| 56 | `boxed_primitives` | 24 | 14.1s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 15.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 13.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 13.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 14.2s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 14.0s |  |
| 71 | `capabilities_resolution` | 8 | 13.9s |  |
| 72 | `catch_references_registers` | 2 | 13.9s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 14.0s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 13.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 13.9s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 17 | 13.9s | [40](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `color` | 57 | 14.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `color_transform` | 48 | 13.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `conflicting_instance_names` | 23 | 13.9s |  |
| 82 | `constructor_function` | 2 | 13.7s |  |
| 83 | `context_menu` | 39 | 13.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `context_menu_item` | 41 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `create_empty_movie_clip` | 3 | 13.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `custom_clip_methods` | 4 | 14.1s | [10](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `default_names` | 52 | 13.9s | [12](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `define_function2` | 8 | 13.8s |  |
| 89 | `define_function2_preload` | 13 | 13.8s |  |
| 90 | `define_function2_preload_order` | 4 | 14.5s |  |
| 91 | `define_function_case_sensitive` | 2 | 14.1s |  |
| 92 | `define_local` | 27 | 14.6s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 93 | `define_local_with_paths` | 54 | 14.3s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `delete` | 3 | 14.5s |  |
| 95 | `device_font_spacing` | 91 | 14.1s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 96 | `display_object_properties` | 2 | 14.1s |  |
| 97 | `divide_swf4` | 107 | 14.4s |  |
| 98 | `do_init_action` | 3 | 14.1s |  |
| 99 | `do_init_action_child` | 12 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 100 | `drag_drop` | 10 | 14.3s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 101 | `drag_over_from_outside` | 1 | 14.3s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_without_startdrag` | 1 | 14.4s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `duplicate_movie_clip` | 20 | 14.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `duplicate_movie_clip_drawing` | 2 | 13.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `edittext_align` | 60 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_align_trailing_spaces_swf7` | 576 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf8` | 576 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_antialiastype` | 296 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_autosize` | 71 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize_setter` | 20 | 14.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_default_format` | 221 | 14.5s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format_font_style` | 335 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_focus_selection` | 2 | 14.0s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_font_size` | 45 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_hscroll` | 27 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_align_swf7` | 52 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf8` | 52 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_color` | 114 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_condensewhite_swf7` | 311 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf8` | 311 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_entity` | 4 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_roundtrip` | 17 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_swf7` | 5377 | 15.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf8` | 5377 | 15.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_input` | 1 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input_newlines` | 9 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_leading` | 9 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_letter_spacing` | 15 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_margins` | 25 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_newline_stripping` | 64 | 18.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_password` | 5 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_password_copy` | 4 | 13.6s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_paste_empty` | 2 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_place_caret` | 2 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_programmatic_focus` | 12 | 13.7s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_restrict` | 191 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_restrict_paste` | 5 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_stylesheet` | 325 | 14.4s | [51](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_tab_focus` | 13 | 13.7s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_tag_indent` | 31 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_text_height_leading` | 20 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_underline` | 40 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_width_height` | 103 | 13.7s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `empty_movieclip_can_attach_movies` | 11 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 145 | `enumerate` | 64 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 146 | `equals` | 32 | 14.0s |  |
| 147 | `equals2_swf5` | 926 | 15.8s |  |
| 148 | `equals2_swf6` | 926 | 15.7s |  |
| 149 | `equals2_swf7` | 926 | 16.0s |  |
| 150 | `equals_swf4` | 665 | 15.2s |  |
| 151 | `equals_swf4_alt` | 32 | 14.2s |  |
| 152 | `equals_swf5` | 32 | 14.3s |  |
| 153 | `error` | 58 | 14.1s |  |
| 154 | `escape` | 14 | 14.0s |  |
| 155 | `execution_order1` | 5 | 14.2s |  |
| 156 | `execution_order2` | 7 | 14.1s |  |
| 157 | `execution_order3` | 4 | 14.0s |  |
| 158 | `execution_order4` | 12 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 159 | `export_assets` | 3 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 160 | `extends_chain` | 134 | 14.7s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 161 | `extends_native_type` | 11 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 162 | `external_interface` | 84 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 163 | `external_interface_escapexml` | 26 | 14.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 164 | `external_interface_jsquotestring` | 21 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_toas_basic` | 354 | 16.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_toxml_array` | 25 | 14.0s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_toxml_basic` | 179 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_unescapexml` | 40 | 14.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `focus_keyboard_press` | 60 | 14.9s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 170 | `focus_mouse` | 45 | 15.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 171 | `focus_mouse_rollout` | 4 | 14.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 172 | `focus_root_movie` | 2 | 14.0s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 173 | `focusrect_focuslost` | 4 | 14.0s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focusrect_mouse_swf8` | 0 | 13.9s |  |
| 175 | `focusrect_mouse_swf9` | 0 | 15.3s |  |
| 176 | `focusrect_swf5` | 6 | 14.5s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 177 | `focusrect_swf6` | 42 | 14.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 178 | `form_loader_encoding_1` | 1 | 14.3s |  |
| 179 | `frame_size_translated_negative` | 21 | 14.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 180 | `frame_size_translated_positive` | 21 | 14.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 181 | `function_as_function` | 35 | 14.4s | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 182 | `function_base_clip` | 8 | 14.4s |  |
| 183 | `function_base_clip_readded` | 11 | 14.4s |  |
| 184 | `function_base_clip_removed` | 25 | 14.4s |  |
| 185 | `function_suppress_and_preload` | 28 | 14.3s |  |
| 186 | `funky_function_calls` | 56 | 14.5s | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 187 | `get_bytes_total` | 4 | 14.3s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 188 | `get_variable_in_scope` | 29 | 14.3s |  |
| 189 | `getproperty` | 28 | 14.2s |  |
| 190 | `getproperty_swf4` | 28 | 15.8s |  |
| 191 | `getproperty_swf5` | 28 | 14.0s |  |
| 192 | `gettextextent` | 56 | 14.2s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 193 | `global_array` | 3 | 14.1s |  |
| 194 | `global_is_bare` | 7 | 14.0s |  |
| 195 | `global_swf6_7_8` | 15 | 14.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 196 | `globals_swf5` | 304 | 15.0s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 197 | `globals_swf6` | 304 | 14.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 198 | `globals_swf7` | 304 | 15.4s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 199 | `globals_swf8` | 304 | 15.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 200 | `goto_advance1` | 6 | 14.7s |  |
| 201 | `goto_advance2` | 2 | 14.2s |  |
| 202 | `goto_both_ways1` | 3 | 14.2s |  |
| 203 | `goto_both_ways2` | 3 | 14.3s |  |
| 204 | `goto_execution_order` | 2 | 14.3s |  |
| 205 | `goto_execution_order2` | 2 | 14.3s |  |
| 206 | `goto_frame` | 12 | 16.4s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 207 | `goto_frame2` | 44 | 15.8s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 208 | `goto_frame_number` | 3 | 15.2s |  |
| 209 | `goto_label` | 17 | 15.3s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 210 | `goto_methods` | 40 | 15.7s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 211 | `goto_rewind1` | 1 | 15.8s |  |
| 212 | `goto_rewind2` | 3 | 15.8s |  |
| 213 | `goto_rewind3` | 2 | 15.6s |  |
| 214 | `greater_swf6` | 1175 | 17.8s |  |
| 215 | `greater_swf7` | 1175 | 17.5s |  |
| 216 | `greaterthan_swf5` | 1 | 15.4s |  |
| 217 | `greaterthan_swf8` | 1 | 15.5s |  |
| 218 | `has_own_property` | 32 | 15.3s |  |
| 219 | `hittest_lockroot` | 15 | 15.4s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 220 | `hittest_morph` | 70 | 15.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 221 | `hittest_winding_rule` | 12 | 15.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 222 | `infinite_recursion_function` | 4 | 15.0s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 223 | `infinite_recursion_function_in_setter` | 131 | 15.1s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 224 | `infinite_recursion_virtual_property` | 67 | 15.0s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 225 | `init_array_invalid` | 4 | 14.8s |  |
| 226 | `init_object_invalid` | 4 | 14.1s |  |
| 227 | `init_object_order` | 15 | 14.2s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 228 | `instanceof_coercions` | 88 | 14.3s | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 229 | `interface_implements_op` | 47 | 14.5s | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 230 | `is_finite` | 49 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 231 | `is_finite_swf6` | 49 | 13.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 232 | `is_prototype_of` | 89 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 233 | `issue_1086` | 1 | 14.0s |  |
| 234 | `issue_1104` | 2 | 13.9s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 235 | `issue_1671` | 0 | 13.9s |  |
| 236 | `issue_1906` | 4 | 14.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 237 | `issue_2166` | 9 | 13.9s |  |
| 238 | `issue_3169` | 2 | 14.0s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 239 | `issue_3446` | 1 | 13.8s |  |
| 240 | `issue_3522` | 2 | 13.9s |  |
| 241 | `issue_4377` | 2 | 13.8s |  |
| 242 | `issue_710` | 4 | 13.9s |  |
| 243 | `issue_768` | 3 | 14.3s | [25](ruffle-tests/_investigation/complete/issue_768.md) |
| 244 | `issue_9327` | 2 | 14.2s |  |
| 245 | `issue_9885` | 2 | 14.2s |  |
| 246 | `key_isToggled` | 9 | 14.2s |  |
| 247 | `lessthan` | 41 | 14.3s |  |
| 248 | `lessthan2_swf5` | 1226 | 16.7s |  |
| 249 | `lessthan2_swf6` | 1226 | 16.7s |  |
| 250 | `lessthan2_swf7` | 1226 | 16.4s |  |
| 251 | `lessthan_swf4` | 902 | 15.5s |  |
| 252 | `lessthan_swf4_alt` | 41 | 14.7s |  |
| 253 | `lessthan_swf5` | 41 | 14.5s |  |
| 254 | `loadmovie` | 2 | 14.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 255 | `loadmovie_fail` | 2 | 14.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 256 | `loadmovie_flashvars` | 4 | 14.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 257 | `loadmovie_method` | 2 | 14.9s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 258 | `loadmovie_replace_root` | 5 | 14.6s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 259 | `loadmovie_var_persistence` | 8 | 14.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 260 | `loadmovienum` | 3 | 14.9s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 261 | `loadvariables` | 2 | 13.9s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 262 | `loadvariables2` | 8 | 13.5s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 263 | `loadvariablesnum` | 2 | 13.5s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 264 | `local_to_global` | 49 | 13.6s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 265 | `localconnection_properties` | 8 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 266 | `lock_root` | 1 | 13.5s |  |
| 267 | `logical_ops_swf4` | 90 | 13.5s |  |
| 268 | `logical_ops_swf8` | 108 | 13.6s |  |
| 269 | `looping` | 6 | 13.6s |  |
| 270 | `mask_reapply` | 0 | 13.6s |  |
| 271 | `mask_with_drawing` | 0 | 13.6s |  |
| 272 | `math_min_max` | 101 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 273 | `math_swf6` | 530 | 14.1s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 274 | `math_swf7` | 530 | 14.0s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 275 | `math_swf8` | 530 | 14.0s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 276 | `matrix` | 171 | 13.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 277 | `mcl_as_broadcaster` | 12 | 13.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 278 | `mcl_events_swf_version` | 232 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 279 | `mcl_getprogress` | 30 | 13.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 280 | `mcl_loadclip` | 149 | 14.9s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mcl_loadclip_properties` | 6 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 282 | `mcl_loadclip_replace_root` | 1 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 283 | `mcl_mislabeled_target` | 6 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 284 | `mcl_target_gif87a` | 6 | 14.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 285 | `mcl_target_gif89a` | 6 | 14.5s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 286 | `mcl_target_jpg` | 6 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 287 | `mcl_target_png` | 6 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 288 | `mcl_unloadclip` | 5 | 14.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 289 | `mouse_events` | 8 | 14.1s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 290 | `mouse_events_visible_enabled` | 12 | 14.3s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 291 | `mouse_hover_events_while_dragging` | 1 | 14.3s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 292 | `mouse_listeners` | 67 | 14.2s |  |
| 293 | `mouse_pos` | 665 | 14.1s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 294 | `mouse_pos_with_scale_factor` | 260 | 14.2s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 295 | `mouse_wheel_enabled` | 2 | 14.1s |  |
| 296 | `movieclip_begin_gradient_fill` | 0 | 14.8s |  |
| 297 | `movieclip_blend_mode_property` | 35 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 298 | `movieclip_create_text_field` | 90 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 299 | `movieclip_default_state` | 69 | 14.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 300 | `movieclip_depth_methods` | 98 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 301 | `movieclip_focusenabled` | 99 | 14.2s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 302 | `movieclip_get_instance_at_depth` | 28 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 303 | `movieclip_getbounds` | 191 | 14.1s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 304 | `movieclip_gettextsnapshot` | 112 | 14.1s | [21](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 305 | `movieclip_hittest` | 92 | 14.1s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 306 | `movieclip_init_object` | 5 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 307 | `movieclip_line_gradient_style` | 0 | 14.4s |  |
| 308 | `movieclip_lockroot` | 29 | 14.3s | [29](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 309 | `movieclip_name_from_timeline` | 13 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 310 | `movieclip_prototype_extension` | 5 | 13.8s |  |
| 311 | `movieclip_setmask` | 14 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 312 | `moviecliploader_flashvars` | 4 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mutable_this` | 18 | 13.9s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 314 | `named_shapes` | 14 | 13.9s |  |
| 315 | `nan_scale` | 9 | 13.9s |  |
| 316 | `native_double_construct` | 12 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 317 | `native_objects_swf7` | 84 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 318 | `native_objects_swf8` | 84 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 319 | `native_subclasses` | 191 | 14.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 320 | `nested_textfields_in_buttons` | 0 | 13.9s |  |
| 321 | `new_method_wrap` | 4 | 13.9s |  |
| 322 | `new_object_enumerate` | 7 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 323 | `new_object_wrap` | 4 | 13.7s |  |
| 324 | `o` | 3 | 13.6s |  |
| 325 | `object_constructor` | 33 | 13.8s |  |
| 326 | `object_function` | 32 | 13.8s |  |
| 327 | `object_properties` | 31 | 13.9s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 328 | `object_prototypes` | 74 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 329 | `object_resolve` | 38 | 13.8s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 330 | `object_string_coerce_swf5` | 62 | 13.7s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 331 | `object_string_coerce_swf6` | 68 | 13.8s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 332 | `on_construct` | 25 | 13.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 333 | `parse_float` | 74 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 334 | `parse_int` | 64 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 335 | `path_string` | 322 | 13.9s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 336 | `place_and_lookup` | 30 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 337 | `placeobject_occupied_depth` | 6 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 338 | `point` | 175 | 14.1s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 339 | `primitive_instanceof` | 37 | 13.6s |  |
| 340 | `primitive_type_globals` | 557 | 13.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 341 | `printjob_props_swf5` | 45 | 14.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 342 | `printjob_props_swf6` | 45 | 14.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 343 | `printjob_props_swf7` | 45 | 14.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 344 | `property_invalid_base_clip` | 36 | 14.1s |  |
| 345 | `prototype_delete` | 12 | 13.9s |  |
| 346 | `prototype_enumerate` | 5 | 14.0s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 347 | `prototype_properties` | 17 | 13.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 348 | `rectangle` | 745 | 14.7s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 349 | `recursive_prototypes` | 0 | 13.8s |  |
| 350 | `register_class_return_value` | 16 | 14.0s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 351 | `register_class_with_sound` | 11 | 14.1s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 352 | `register_globals_across_frames` | 15 | 13.9s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 353 | `register_underflow` | 26 | 13.9s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 354 | `remove_movie_clip` | 29 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 355 | `removed_clip_halts_script` | 15 | 14.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 356 | `resolve_different_root` | 2 | 17.0s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 357 | `rewind_depth` | 30 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 358 | `root_global_parent` | 6 | 13.8s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 359 | `sandbox_type_local_file` | 1 | 13.8s |  |
| 360 | `sandbox_type_local_network` | 1 | 13.7s |  |
| 361 | `selection` | 454 | 14.0s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 362 | `set_interval` | 27 | 14.0s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 363 | `set_variable_scope` | 58 | 14.0s |  |
| 364 | `single_frame` | 1 | 14.3s |  |
| 365 | `slash_syntax` | 14 | 14.3s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 366 | `sound` | 628 | 14.3s | [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 367 | `sound_props_swf5` | 68 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 368 | `sound_props_swf6` | 68 | 14.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 369 | `sound_start_load` | 0 | 14.1s |  |
| 370 | `stage_display_state` | 16 | 14.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 371 | `stage_object_children` | 83 | 14.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 372 | `stage_object_enumerate` | 4 | 14.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 373 | `stage_object_properties` | 241 | 14.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 374 | `stage_object_properties_get_var` | 5 | 14.6s |  |
| 375 | `stage_object_properties_swf6` | 231 | 15.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 376 | `stage_property_representation` | 586 | 14.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 377 | `stage_scale_mode` | 39 | 14.6s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 378 | `strictequals_swf6` | 902 | 15.8s |  |
| 379 | `strictly_equals` | 7 | 14.3s |  |
| 380 | `string_coercion` | 117 | 14.7s | [49](ruffle-tests/_investigation/complete/string_coercion.md) |
| 381 | `string_methods` | 285 | 14.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 382 | `string_methods_negative_args` | 240 | 14.4s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 383 | `string_methods_swfv5` | 275 | 15.1s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 384 | `string_ops_swf6` | 95 | 14.2s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 385 | `string_paths_basic` | 4 | 14.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 386 | `string_paths_eval2` | 7 | 15.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 387 | `string_paths_hidden` | 54 | 13.9s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 388 | `string_paths_other` | 36 | 13.8s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 389 | `string_paths_unload` | 1 | 13.8s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 390 | `string_paths_variable_alias` | 4 | 13.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 391 | `string_paths_variable_scopes` | 5 | 13.8s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 392 | `stylesheet` | 283 | 14.6s |  |
| 393 | `stylesheet_transform` | 750 | 14.6s |  |
| 394 | `super_edge_cases` | 39 | 14.0s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 395 | `swf4_actions_bool` | 96 | 13.8s |  |
| 396 | `swf4_actions_coercion_order` | 158 | 14.0s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 397 | `swf4_bool` | 4 | 13.7s |  |
| 398 | `swf4_function_calls` | 7 | 13.8s |  |
| 399 | `swf5_encoding` | 3 | 13.8s |  |
| 400 | `swf5_global_funcs` | 232 | 13.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 401 | `swf5_no_closure` | 19 | 13.7s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 402 | `swf6_case_insensitive` | 42 | 13.1s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 403 | `swf6_global_funcs` | 232 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 404 | `swf6_string_as_bool` | 15 | 13.5s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 405 | `swf7_case_sensitive` | 44 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 406 | `swf7_global_funcs` | 232 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 407 | `tab_ordering_automatic_basic` | 92 | 13.5s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 408 | `tab_ordering_automatic_order_grid` | 21 | 13.5s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 409 | `tab_ordering_automatic_order_same_position` | 12 | 13.6s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 410 | `tab_ordering_children` | 208 | 13.5s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 411 | `tab_ordering_custom_basic` | 71 | 13.7s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 412 | `tab_ordering_custom_duplicate_index` | 22 | 13.5s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 413 | `tab_ordering_custom_i32_vs_u32` | 12 | 13.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 414 | `tab_ordering_custom_m1` | 29 | 13.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 415 | `tab_ordering_events` | 150 | 13.4s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 416 | `tab_ordering_events_mouse` | 65 | 13.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 417 | `tab_ordering_movieclip_enabled_default` | 462 | 13.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 418 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.4s |  |
| 419 | `tab_ordering_reverse` | 51 | 14.2s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 420 | `tab_ordering_tabbable` | 47 | 14.2s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 421 | `target_clip_removed` | 5 | 14.2s | [44](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 422 | `target_clip_swf5` | 2 | 14.0s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 423 | `target_clip_swf6` | 2 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 424 | `target_path` | 14 | 14.0s |  |
| 425 | `tell_target` | 37 | 14.1s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 426 | `tell_target_invalid` | 6 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 427 | `tell_target_invalid_swf6` | 5 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 428 | `text_format` | 1146 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 429 | `text_format_display` | 21 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 430 | `text_format_font_max_length` | 2 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 431 | `text_format_get_text_extent_undefined_width` | 10 | 14.0s |  |
| 432 | `text_format_rounding_swf7` | 840 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 433 | `text_format_rounding_swf8` | 840 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 434 | `textfield_background_color` | 11 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 435 | `textfield_border_color` | 11 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 436 | `textfield_cache_as_bitmap` | 1 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 437 | `textfield_maxchars` | 3 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 438 | `textfield_properties` | 44 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 439 | `textfield_props_swf5` | 175 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 440 | `textfield_props_swf6` | 210 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 441 | `textfield_props_swf7` | 210 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 442 | `textfield_props_swf8` | 210 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 443 | `textfield_text` | 7 | 13.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 444 | `textfield_variable` | 81 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 445 | `textsnapshot_props_swf5` | 56 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 446 | `textsnapshot_props_swf6` | 56 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 447 | `this_scoping` | 52 | 14.0s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 448 | `this_swf5` | 41 | 13.8s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 449 | `this_swf6` | 41 | 13.8s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 450 | `this_swf7` | 41 | 13.7s | [58](ruffle-tests/_investigation/complete/this_swf7.md) |
| 451 | `timeline_function_def` | 7 | 13.9s |  |
| 452 | `trace` | 8 | 14.1s |  |
| 453 | `transform` | 70 | 14.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 454 | `try_catch_finally` | 118 | 14.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 455 | `try_finally_simple` | 16 | 14.1s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 456 | `typeof` | 22 | 14.2s |  |
| 457 | `typeof_globals` | 7 | 14.1s |  |
| 458 | `uncaught_exception` | 1 | 14.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 459 | `uncaught_exception_bubbled` | 1 | 14.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 460 | `undefined_to_string_swf6` | 4 | 14.2s |  |
| 461 | `unescape` | 43 | 14.4s |  |
| 462 | `unload` | 52 | 14.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 463 | `unload_clip_event` | 4 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 464 | `unloadmovie` | 4 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 465 | `unloadmovie_method` | 3 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 466 | `unloadmovienum` | 13 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 467 | `use_hand_cursor` | 8 | 14.2s |  |
| 468 | `variable_args` | 5 | 14.3s |  |
| 469 | `waitforframe` | 7 | 14.2s |  |
| 470 | `waitforframe2` | 16 | 15.8s |  |
| 471 | `watch` | 117 | 14.1s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 472 | `watch_textfield` | 12 | 13.8s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 473 | `watch_virtual_property_proto` | 2 | 13.9s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 474 | `with` | 49 | 13.8s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 475 | `with_return` | 2 | 13.8s |  |
| 476 | `with_variable_scopes` | 43 | 13.8s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 477 | `xml` | 15 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 478 | `xml_append_child` | 28 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 479 | `xml_append_child_with_parent` | 20 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 480 | `xml_attributes_read` | 4 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 481 | `xml_cdata` | 11 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 482 | `xml_child_nodes_edge_cases` | 4 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 483 | `xml_clone_expandos` | 19 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 484 | `xml_first_last_child` | 8 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 485 | `xml_has_child_nodes` | 3 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 486 | `xml_idmap` | 21 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 487 | `xml_ignore_comments` | 21 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 488 | `xml_ignore_white` | 34 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 489 | `xml_insert_before` | 20 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 490 | `xml_inspect_createmethods` | 15 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 491 | `xml_inspect_doctype` | 7 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 492 | `xml_inspect_parsexml` | 62 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 493 | `xml_inspect_xmldecl` | 7 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 494 | `xml_namespaces` | 203 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 495 | `xml_parent_and_child` | 5 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 496 | `xml_remove_node` | 22 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 497 | `xml_reparenting` | 14 | 14.7s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 498 | `xml_siblings` | 10 | 14.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 499 | `xml_to_string` | 13 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 500 | `xml_to_string_comment` | 1 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 501 | `xml_unescaping` | 23 | 14.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 502 | `xmlnode_proto` | 1 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**34 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `removed_target_clip_scope` | 97.1% | 34 | 35 | 1 | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 5 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `global_swf5_6_7_8_9` | 93.7% | 1073 | 1145 | 72 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `swf5_to_6_cross_call` | 79.3% | 23 | 29 | 6 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 10 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 11 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `register_class` | 71.6% | 48 | 67 | 19 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 16 | `loadmovie_registerclass` | 70.0% | 21 | 30 | 9 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 17 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `loadmovienum_cross_version_prototype` | 66.7% | 6 | 9 | 3 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 19 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `cross_movie_root` | 60.0% | 6 | 10 | 4 |  |
| 21 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `movieclip_in_removed_button` | 60.0% | 3 | 5 | 2 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 23 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 24 | `textsnapshot_findtext` | 59.1% | 26 | 44 | 18 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 25 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 26 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 27 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 28 | `swf6_to_5_cross_call` | 55.2% | 16 | 29 | 13 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 29 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 30 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 31 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 32 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 33 | `issue_2030` | 50.0% | 2 | 4 | 2 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 34 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 17.6s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 31.1s |  |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_1` | exit code -6 | 14.4s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_2` | exit code -6 | 14.7s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 39.5s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 39.9s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 43.7s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**108 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `removed_target_clip_scope` | 97.1% | 34/35 | 35 | 35 | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 5 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 6 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `global_swf5_6_7_8_9` | 93.7% | 1073/1145 | 1145 | 1145 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `swf5_to_6_cross_call` | 79.3% | 23/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 10 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 11 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 14 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `register_class` | 71.6% | 48/67 | 67 | 66 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 16 | `loadmovie_registerclass` | 70.0% | 21/30 | 27 | 30 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 17 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `loadmovienum_cross_version_prototype` | 66.7% | 6/9 | 9 | 9 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 19 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `cross_movie_root` | 60.0% | 6/10 | 10 | 10 |  |
| 21 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `movieclip_in_removed_button` | 60.0% | 3/5 | 5 | 4 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 23 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 24 | `textsnapshot_findtext` | 59.1% | 26/44 | 44 | 44 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 25 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 26 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 27 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 28 | `swf6_to_5_cross_call` | 55.2% | 16/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 29 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 30 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 31 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 32 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 33 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 34 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 35 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 36 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 37 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 38 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 39 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 40 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 41 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 42 | `movieclip_state_values` | 34.2% | 39/114 | 55 | 114 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 43 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 44 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 45 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 46 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 47 | `mcl_replace_root_swf7_to_swf6` | 29.8% | 17/57 | 45 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 48 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 49 | `mcl_replace_root_swf7_to_swf5` | 24.6% | 14/57 | 45 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 50 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 51 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 52 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 53 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 54 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 55 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 56 | `register_and_init_order` | 15.6% | 36/231 | 154 | 231 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 57 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 58 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 59 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 60 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 61 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 62 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 63 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 64 | `textsnapshot_gettext` | 9.1% | 5/55 | 55 | 55 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 65 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 66 | `register_class_swf6` | 8.1% | 3/37 | 37 | 37 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 67 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 68 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 69 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 70 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 71 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 72 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 73 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 74 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 75 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 76 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 77 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 78 | `global_instance_decls` | 1.6% | 12/758 | 482 | 758 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 79 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 80 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 81 | `global_proto_decls` | 0.2% | 11/4497 | 692 | 4497 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 82 | `global_proto_decls_delete` | 0.0% | 1/4158 | 310 | 4158 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 84 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 85 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 86 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 87 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 88 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 89 | `geturl` | 0.0% | 0/7 | 0 | 7 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 90 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 91 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 92 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 93 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 94 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 95 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 96 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 97 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 98 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 99 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 100 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 101 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 102 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 103 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 104 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 105 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 106 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 107 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 108 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 12 | 2 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 11 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 12 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 13 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 14 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 15 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 16 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 17 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 6 | 1 |
| 18 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 19 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 20 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 21 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 22 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 26 | 5 |
| 23 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 6 | 11 |
| 24 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 25 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 26 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 48 | 28 | 20 |
| 27 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 2 | 3 |
| 28 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 29 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 30 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 31 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 32 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 33 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 38 | 20 |
| 34 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 35 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 36 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 37 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 38 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 39 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 40 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 41 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 42 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 43 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 44 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 45 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 3 | 1 |
| 46 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 47 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 48 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 49 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 50 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 51 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 52 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 53 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 54 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 15 | 4 |
| 55 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 58 | 12 |
| 56 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 0 | 4 |
| 57 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 58 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 59 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 60 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 61 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 62 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 7 | 9 |
| 63 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 64 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 65 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 195 | 157 | 38 |
