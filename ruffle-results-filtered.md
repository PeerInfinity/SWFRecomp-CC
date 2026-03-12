# Ruffle Test Results (Filtered)

**Date**: 2026-03-12 01:15 UTC

**Git SHA**: `fe35db71ea`

**Run Duration**: 153m 45s

**Filtered**: 49 tests ignored out of 618 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 569 |
| Passing | **514** (90.3%) |
| Failing | 55 |
| Total expected lines | 79233 |
| Matching lines | 64913 (81.9%) |
| Mismatched lines | 14320 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 55 | 100.0% |

## Passing Tests

**514 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.4s |  |
| 2 | `action_to_integer` | 28 | 14.6s |  |
| 3 | `add` | 28 | 14.5s |  |
| 4 | `add2` | 354 | 14.6s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.5s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.3s |  |
| 7 | `add_swf5` | 28 | 14.5s |  |
| 8 | `arguments` | 127 | 14.4s | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [40](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 14.3s |  |
| 11 | `array_constructor` | 30 | 14.2s |  |
| 12 | `array_enumerate` | 4 | 14.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.3s |  |
| 14 | `array_properties` | 36 | 14.3s |  |
| 15 | `array_prototyping` | 12 | 14.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 14.4s |  |
| 17 | `array_sort_random` | 443 | 14.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 14.5s |  |
| 19 | `array_trivial` | 209 | 14.4s |  |
| 20 | `as1_constructor_v6` | 35 | 14.6s |  |
| 21 | `as1_constructor_v7` | 35 | 14.5s |  |
| 22 | `as2_oop` | 13 | 14.4s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 14.5s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 14.4s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 14.4s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 14.2s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 14.1s |  |
| 28 | `as_broadcaster_undef` | 89 | 14.2s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 14.2s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 14.2s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 14.2s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 14.2s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 14.2s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 14.1s |  |
| 36 | `as_transformed_flag` | 20 | 14.2s |  |
| 37 | `asnative` | 34 | 14.2s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 14.2s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 14.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 14.1s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 14.9s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 14.6s |  |
| 43 | `bitand` | 1058 | 17.5s |  |
| 44 | `bitmap_data_colortransform` | 0 | 14.9s |  |
| 45 | `bitmap_data_fillrect` | 0 | 14.8s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 14.6s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 14.6s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 15.6s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 15.1s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.9s |  |
| 51 | `bitor` | 1058 | 17.4s |  |
| 52 | `biturshift` | 14 | 14.4s |  |
| 53 | `biturshift_swf8` | 14 | 16.7s |  |
| 54 | `bitxor` | 1058 | 17.9s |  |
| 55 | `boxed_primitives` | 24 | 15.1s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 15.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 15.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_key_events` | 14 | 15.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events_special` | 45 | 16.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_keypress` | 3 | 15.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_press` | 25 | 15.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_tab` | 20 | 15.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_textinput` | 4 | 15.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_order` | 2 | 15.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_properties_special_cases` | 22 | 15.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_v5` | 18 | 15.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v6` | 18 | 15.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `call` | 63 | 15.6s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 69 | `call_method_empty_name` | 1 | 15.2s |  |
| 70 | `capabilities_resolution` | 8 | 15.2s |  |
| 71 | `catch_references_registers` | 2 | 15.0s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 72 | `click_block` | 5 | 14.9s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 73 | `clip_constructors` | 8 | 15.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 74 | `clip_events` | 19 | 15.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `clone_sprite_types` | 24 | 14.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `closure_scope` | 7 | 15.1s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 77 | `coerce_to_primitive_resolve` | 17 | 15.3s | [41](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 78 | `color` | 57 | 15.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 15.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 15.3s |  |
| 81 | `constructor_function` | 2 | 15.0s |  |
| 82 | `context_menu` | 39 | 15.1s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 15.1s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 15.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `custom_clip_methods` | 4 | 15.4s | [11](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `default_names` | 52 | 15.4s | [13](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `define_function2` | 8 | 15.2s |  |
| 88 | `define_function2_preload` | 13 | 15.0s |  |
| 89 | `define_function2_preload_order` | 4 | 14.5s |  |
| 90 | `define_function_case_sensitive` | 2 | 14.1s |  |
| 91 | `define_local` | 27 | 14.2s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 92 | `define_local_with_paths` | 54 | 14.1s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 93 | `delete` | 3 | 14.2s |  |
| 94 | `device_font_spacing` | 91 | 14.2s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `display_object_properties` | 2 | 14.1s |  |
| 96 | `divide_swf4` | 107 | 14.3s |  |
| 97 | `do_init_action` | 3 | 14.2s |  |
| 98 | `do_init_action_child` | 12 | 14.2s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 99 | `drag_drop` | 10 | 14.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 100 | `drag_over_from_outside` | 1 | 14.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 101 | `drag_over_without_startdrag` | 1 | 14.3s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `duplicate_movie_clip` | 20 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 103 | `duplicate_movie_clip_drawing` | 2 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `edittext_align` | 60 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_align_trailing_spaces_swf7` | 576 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_align_trailing_spaces_swf8` | 576 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_antialiastype` | 296 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_autosize` | 71 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_autosize_setter` | 20 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_default_format` | 221 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_default_format_font_style` | 335 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_focus_selection` | 2 | 14.1s | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_font_size` | 45 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_hscroll` | 27 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_align_swf7` | 52 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_align_swf8` | 52 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_color` | 114 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_condensewhite_swf7` | 311 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_condensewhite_swf8` | 311 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_entity` | 4 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_roundtrip` | 17 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_swf7` | 5377 | 15.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_swf8` | 5377 | 15.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_input` | 1 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_input_newlines` | 9 | 16.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_leading` | 9 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_letter_spacing` | 15 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_margins` | 25 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_newline_stripping` | 64 | 19.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_newlines` | 30 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_password` | 5 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_password_copy` | 4 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_paste_empty` | 2 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_place_caret` | 2 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_programmatic_focus` | 12 | 14.4s | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_restrict` | 191 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_restrict_paste` | 5 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_scroll` | 54 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_stylesheet` | 325 | 15.1s | [52](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_tab_focus` | 13 | 14.3s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_tag_indent` | 31 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_text_height_leading` | 20 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_underline` | 40 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_width_height` | 103 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `empty_movieclip_can_attach_movies` | 11 | 14.7s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 146 | `enumerate` | 64 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 147 | `equals` | 32 | 14.4s |  |
| 148 | `equals2_swf5` | 926 | 16.2s |  |
| 149 | `equals2_swf6` | 926 | 16.1s |  |
| 150 | `equals2_swf7` | 926 | 16.1s |  |
| 151 | `equals_swf4` | 665 | 15.2s |  |
| 152 | `equals_swf4_alt` | 32 | 14.7s |  |
| 153 | `equals_swf5` | 32 | 14.6s |  |
| 154 | `error` | 58 | 14.6s |  |
| 155 | `escape` | 14 | 14.4s |  |
| 156 | `execution_order1` | 5 | 14.5s |  |
| 157 | `execution_order2` | 7 | 14.4s |  |
| 158 | `execution_order3` | 4 | 14.5s |  |
| 159 | `execution_order4` | 12 | 14.7s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 160 | `export_assets` | 3 | 14.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 161 | `extends_chain` | 134 | 14.8s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 162 | `extends_native_type` | 11 | 14.4s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 163 | `external_interface` | 84 | 14.5s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 164 | `external_interface_escapexml` | 26 | 14.3s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_jsquotestring` | 21 | 14.5s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_toas_basic` | 354 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_toxml_array` | 25 | 14.1s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_toxml_basic` | 179 | 14.2s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_unescapexml` | 40 | 14.1s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `focus_keyboard_press` | 60 | 14.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 171 | `focus_mouse` | 45 | 14.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 172 | `focus_mouse_rollout` | 4 | 14.0s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 173 | `focus_remove` | 33 | 14.1s |  |
| 174 | `focus_root_movie` | 2 | 13.9s | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focusrect_focuslost` | 4 | 14.0s | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focusrect_mouse_swf8` | 0 | 14.0s |  |
| 177 | `focusrect_mouse_swf9` | 0 | 15.3s |  |
| 178 | `focusrect_swf5` | 6 | 14.4s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 179 | `focusrect_swf6` | 42 | 14.3s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 180 | `frame_size_translated_negative` | 21 | 14.3s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 181 | `frame_size_translated_positive` | 21 | 14.3s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 182 | `function_as_function` | 35 | 14.2s | [20](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 183 | `function_base_clip` | 8 | 14.2s |  |
| 184 | `function_base_clip_removed` | 25 | 14.4s |  |
| 185 | `function_suppress_and_preload` | 28 | 14.3s |  |
| 186 | `funky_function_calls` | 56 | 14.2s | [20](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 187 | `get_bytes_total` | 4 | 14.2s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 188 | `get_variable_in_scope` | 29 | 14.1s |  |
| 189 | `getproperty` | 28 | 14.2s |  |
| 190 | `getproperty_swf4` | 28 | 14.9s |  |
| 191 | `getproperty_swf5` | 28 | 14.4s |  |
| 192 | `gettextextent` | 56 | 14.5s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 193 | `global_array` | 3 | 14.4s |  |
| 194 | `global_is_bare` | 7 | 14.2s |  |
| 195 | `global_swf5_6_7_8_9` | 1145 | 14.9s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 196 | `global_swf6_7_8` | 15 | 14.6s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 197 | `globals_swf5` | 304 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 198 | `globals_swf6` | 304 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 199 | `globals_swf7` | 304 | 14.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 200 | `globals_swf8` | 304 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 201 | `goto_advance1` | 6 | 14.1s |  |
| 202 | `goto_advance2` | 2 | 14.2s |  |
| 203 | `goto_both_ways1` | 3 | 14.3s |  |
| 204 | `goto_both_ways2` | 3 | 14.2s |  |
| 205 | `goto_execution_order` | 2 | 14.2s |  |
| 206 | `goto_execution_order2` | 2 | 14.3s |  |
| 207 | `goto_frame` | 12 | 14.6s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 208 | `goto_frame2` | 44 | 14.9s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 209 | `goto_frame_number` | 3 | 14.3s |  |
| 210 | `goto_label` | 17 | 14.6s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 211 | `goto_methods` | 40 | 14.4s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 212 | `goto_rewind1` | 1 | 14.3s |  |
| 213 | `goto_rewind2` | 3 | 14.3s |  |
| 214 | `goto_rewind3` | 2 | 14.4s |  |
| 215 | `greater_swf6` | 1175 | 16.5s |  |
| 216 | `greater_swf7` | 1175 | 16.5s |  |
| 217 | `greaterthan_swf5` | 1 | 14.3s |  |
| 218 | `greaterthan_swf8` | 1 | 14.3s |  |
| 219 | `has_own_property` | 32 | 14.3s |  |
| 220 | `hittest_lockroot` | 15 | 14.6s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 221 | `hittest_morph` | 70 | 14.4s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 222 | `hittest_winding_rule` | 12 | 14.5s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 223 | `infinite_recursion_function` | 4 | 14.2s | [25](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 224 | `infinite_recursion_function_in_setter` | 131 | 14.2s | [25](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 225 | `infinite_recursion_virtual_property` | 67 | 14.2s | [25](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 226 | `init_array_invalid` | 4 | 14.2s |  |
| 227 | `init_object_invalid` | 4 | 15.1s |  |
| 228 | `init_object_order` | 15 | 14.9s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 229 | `instanceof_coercions` | 88 | 15.2s | [62](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 230 | `interface_implements_op` | 47 | 15.4s | [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 231 | `is_finite` | 49 | 14.8s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 232 | `is_finite_swf6` | 49 | 14.8s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 233 | `is_prototype_of` | 89 | 15.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 234 | `issue_1086` | 1 | 14.8s |  |
| 235 | `issue_1104` | 2 | 14.9s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 236 | `issue_1671` | 0 | 14.9s |  |
| 237 | `issue_1906` | 4 | 14.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 238 | `issue_2166` | 9 | 14.4s |  |
| 239 | `issue_3169` | 2 | 14.6s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 240 | `issue_3446` | 1 | 14.2s |  |
| 241 | `issue_3522` | 2 | 14.4s |  |
| 242 | `issue_4377` | 2 | 14.4s |  |
| 243 | `issue_710` | 4 | 14.4s |  |
| 244 | `issue_768` | 3 | 16.4s | [26](ruffle-tests/_investigation/complete/issue_768.md) |
| 245 | `issue_9327` | 2 | 14.8s |  |
| 246 | `issue_9885` | 2 | 14.7s |  |
| 247 | `key_isToggled` | 9 | 14.7s |  |
| 248 | `lessthan` | 41 | 14.7s |  |
| 249 | `lessthan2_swf5` | 1226 | 16.9s |  |
| 250 | `lessthan2_swf6` | 1226 | 16.9s |  |
| 251 | `lessthan2_swf7` | 1226 | 16.9s |  |
| 252 | `lessthan_swf4` | 902 | 15.9s |  |
| 253 | `lessthan_swf4_alt` | 41 | 14.8s |  |
| 254 | `lessthan_swf5` | 41 | 14.7s |  |
| 255 | `loadmovie` | 2 | 14.8s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 256 | `loadmovie_fail` | 2 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 257 | `loadmovie_flashvars` | 4 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 258 | `loadmovie_method` | 2 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 259 | `loadmovie_registerclass` | 30 | 14.8s | [10](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 260 | `loadmovie_replace_root` | 5 | 14.8s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 261 | `loadmovie_var_persistence` | 8 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 262 | `loadmovienum` | 3 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 263 | `loadmovienum_cross_version_prototype` | 9 | 14.9s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 264 | `loadvariables` | 2 | 14.8s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 265 | `loadvariables2` | 8 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 266 | `loadvariablesnum` | 2 | 14.5s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 267 | `local_to_global` | 49 | 14.6s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 268 | `localconnection_properties` | 8 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 269 | `lock_root` | 1 | 14.6s |  |
| 270 | `logical_ops_swf4` | 90 | 14.5s |  |
| 271 | `logical_ops_swf8` | 108 | 14.6s |  |
| 272 | `looping` | 6 | 14.5s |  |
| 273 | `mask_reapply` | 0 | 14.8s |  |
| 274 | `mask_with_drawing` | 0 | 14.6s |  |
| 275 | `math_min_max` | 101 | 14.7s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 276 | `math_swf6` | 530 | 14.9s | [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 277 | `math_swf7` | 530 | 15.0s | [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 278 | `math_swf8` | 530 | 15.0s | [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 279 | `matrix` | 171 | 14.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 280 | `mcl_as_broadcaster` | 12 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mcl_events_swf_version` | 232 | 15.2s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 282 | `mcl_getprogress` | 30 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mcl_loadclip` | 149 | 16.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 284 | `mcl_loadclip_properties` | 6 | 14.5s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 285 | `mcl_loadclip_replace_root` | 1 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 286 | `mcl_mislabeled_target` | 6 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 287 | `mcl_target_gif87a` | 6 | 15.4s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 288 | `mcl_target_gif89a` | 6 | 15.9s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 289 | `mcl_target_jpg` | 6 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 290 | `mcl_target_png` | 6 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 291 | `mcl_unloadclip` | 5 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mouse_events` | 8 | 14.5s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 293 | `mouse_events_visible_enabled` | 12 | 14.7s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 294 | `mouse_hover_events_while_dragging` | 1 | 14.8s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 295 | `mouse_listeners` | 67 | 14.4s |  |
| 296 | `mouse_pos` | 665 | 14.4s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 297 | `mouse_pos_with_scale_factor` | 260 | 14.4s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 298 | `mouse_wheel_enabled` | 2 | 14.8s |  |
| 299 | `movieclip_begin_gradient_fill` | 0 | 15.0s |  |
| 300 | `movieclip_blend_mode_property` | 35 | 14.5s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 301 | `movieclip_create_text_field` | 90 | 14.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 302 | `movieclip_default_state` | 69 | 16.1s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 303 | `movieclip_depth_methods` | 98 | 15.7s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 304 | `movieclip_focusenabled` | 99 | 15.6s | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 305 | `movieclip_get_instance_at_depth` | 28 | 15.8s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 306 | `movieclip_getbounds` | 191 | 15.7s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 307 | `movieclip_gettextsnapshot` | 112 | 15.5s | [22](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 308 | `movieclip_hittest` | 92 | 15.5s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 309 | `movieclip_init_object` | 5 | 15.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 310 | `movieclip_invalid_get_bounds_1` | 75 | 16.6s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 311 | `movieclip_invalid_get_bounds_2` | 75 | 16.2s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 312 | `movieclip_invalid_get_bounds_3` | 13 | 15.8s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 313 | `movieclip_invalid_get_bounds_4` | 13 | 15.8s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_invalid_get_bounds_5` | 11 | 15.6s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 315 | `movieclip_invalid_get_bounds_8` | 11 | 15.9s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 316 | `movieclip_line_gradient_style` | 0 | 15.9s |  |
| 317 | `movieclip_lockroot` | 29 | 15.9s | [30](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 318 | `movieclip_name_from_timeline` | 13 | 14.3s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_prototype_extension` | 5 | 14.3s |  |
| 320 | `movieclip_setmask` | 14 | 14.5s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 321 | `moviecliploader_flashvars` | 4 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 322 | `mutable_this` | 18 | 14.3s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 323 | `named_shapes` | 14 | 14.0s |  |
| 324 | `nan_scale` | 9 | 14.1s |  |
| 325 | `native_double_construct` | 12 | 14.1s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 326 | `native_objects_swf7` | 84 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 327 | `native_objects_swf8` | 84 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 328 | `nested_textfields_in_buttons` | 0 | 14.0s |  |
| 329 | `new_method_wrap` | 4 | 15.0s |  |
| 330 | `new_object_enumerate` | 7 | 14.9s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 331 | `new_object_wrap` | 4 | 14.4s |  |
| 332 | `o` | 3 | 14.3s |  |
| 333 | `object_constructor` | 33 | 14.3s |  |
| 334 | `object_function` | 32 | 14.3s |  |
| 335 | `object_properties` | 31 | 14.8s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 336 | `object_prototypes` | 74 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 337 | `object_resolve` | 38 | 14.7s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 338 | `object_string_coerce_swf5` | 62 | 14.5s | [37](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 339 | `object_string_coerce_swf6` | 68 | 14.8s | [37](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 340 | `on_construct` | 25 | 14.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 341 | `parse_float` | 74 | 14.7s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 342 | `parse_int` | 64 | 15.0s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 343 | `path_string` | 322 | 14.9s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 344 | `place_and_lookup` | 30 | 14.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 345 | `placeobject_occupied_depth` | 6 | 14.6s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 346 | `point` | 175 | 14.7s | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 347 | `primitive_instanceof` | 37 | 14.2s |  |
| 348 | `primitive_type_globals` | 557 | 14.2s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 349 | `printjob_props_swf5` | 45 | 14.7s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 350 | `printjob_props_swf6` | 45 | 14.2s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 351 | `printjob_props_swf7` | 45 | 14.2s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 352 | `property_invalid_base_clip` | 36 | 14.2s |  |
| 353 | `prototype_delete` | 12 | 14.3s |  |
| 354 | `prototype_enumerate` | 5 | 14.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 355 | `prototype_properties` | 17 | 14.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 356 | `rectangle` | 745 | 14.9s | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 357 | `recursive_prototypes` | 0 | 14.1s |  |
| 358 | `register_and_init_order` | 231 | 14.6s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 359 | `register_class` | 66 | 14.4s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 360 | `register_class_return_value` | 16 | 14.2s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 361 | `register_class_swf6` | 37 | 14.5s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 362 | `register_class_with_sound` | 11 | 14.3s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [47](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 363 | `register_globals_across_frames` | 15 | 14.1s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 364 | `register_underflow` | 26 | 14.1s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 365 | `remove_movie_clip` | 29 | 14.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 366 | `removed_clip_halts_script` | 15 | 14.6s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 367 | `removed_target_clip_scope` | 35 | 14.4s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 368 | `resolve_different_root` | 2 | 14.9s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 369 | `rewind_depth` | 30 | 14.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 370 | `root_global_parent` | 6 | 14.3s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 371 | `root_onload` | 1 | 14.2s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 372 | `sandbox_type_local_file` | 1 | 14.2s |  |
| 373 | `sandbox_type_local_network` | 1 | 14.1s |  |
| 374 | `selection` | 454 | 14.3s | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 375 | `set_interval` | 27 | 14.4s | [60](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 376 | `set_variable_scope` | 58 | 14.2s |  |
| 377 | `single_frame` | 1 | 14.2s |  |
| 378 | `slash_syntax` | 14 | 14.2s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 379 | `sound` | 628 | 14.6s | [47](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 380 | `sound_props_swf5` | 68 | 14.7s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 381 | `sound_props_swf6` | 68 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 382 | `sound_start_load` | 0 | 15.0s |  |
| 383 | `stage_display_state` | 16 | 14.6s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 384 | `stage_object_children` | 83 | 14.6s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 385 | `stage_object_enumerate` | 4 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 386 | `stage_object_properties` | 241 | 15.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 387 | `stage_object_properties_get_var` | 5 | 14.6s |  |
| 388 | `stage_object_properties_swf6` | 231 | 14.8s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 389 | `stage_property_representation` | 586 | 14.5s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 390 | `stage_scale_mode` | 39 | 14.4s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 391 | `strictequals_swf6` | 902 | 15.9s |  |
| 392 | `strictly_equals` | 7 | 14.6s |  |
| 393 | `string_coercion` | 117 | 14.9s | [50](ruffle-tests/_investigation/complete/string_coercion.md) |
| 394 | `string_methods` | 285 | 15.0s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 395 | `string_methods_negative_args` | 240 | 14.6s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 396 | `string_methods_swfv5` | 275 | 15.1s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 397 | `string_ops_swf6` | 95 | 14.3s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 398 | `string_paths_basic` | 4 | 14.2s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 399 | `string_paths_eval2` | 7 | 15.9s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 400 | `string_paths_hidden` | 54 | 15.8s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 401 | `string_paths_other` | 36 | 15.8s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 402 | `string_paths_unload` | 1 | 15.8s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 403 | `string_paths_variable_alias` | 4 | 15.4s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 404 | `string_paths_variable_scopes` | 5 | 15.1s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 405 | `stylesheet` | 283 | 15.8s |  |
| 406 | `stylesheet_transform` | 750 | 15.9s |  |
| 407 | `super_edge_cases` | 39 | 15.0s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 408 | `swf4_actions_bool` | 96 | 14.8s |  |
| 409 | `swf4_actions_coercion_order` | 158 | 14.8s | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 410 | `swf4_bool` | 4 | 14.7s |  |
| 411 | `swf4_function_calls` | 7 | 14.9s |  |
| 412 | `swf5_encoding` | 3 | 15.0s |  |
| 413 | `swf5_global_funcs` | 232 | 15.6s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 414 | `swf5_no_closure` | 19 | 15.5s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 415 | `swf6_case_insensitive` | 42 | 14.6s | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 416 | `swf6_global_funcs` | 232 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 417 | `swf6_string_as_bool` | 15 | 14.5s | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 418 | `swf7_case_sensitive` | 44 | 14.6s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 419 | `swf7_global_funcs` | 232 | 14.6s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 420 | `tab_ordering_automatic_basic` | 92 | 14.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 421 | `tab_ordering_automatic_order_grid` | 21 | 14.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 422 | `tab_ordering_automatic_order_same_position` | 12 | 14.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 423 | `tab_ordering_children` | 208 | 14.7s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 424 | `tab_ordering_custom_basic` | 71 | 14.5s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 425 | `tab_ordering_custom_duplicate_index` | 22 | 14.7s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 426 | `tab_ordering_custom_i32_vs_u32` | 12 | 14.5s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 427 | `tab_ordering_custom_m1` | 29 | 14.5s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 428 | `tab_ordering_events` | 150 | 14.9s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 429 | `tab_ordering_events_mouse` | 65 | 14.8s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 430 | `tab_ordering_movieclip_enabled_default` | 462 | 14.8s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 431 | `tab_ordering_properties_tab_index_edge_case` | 4 | 16.1s |  |
| 432 | `tab_ordering_reverse` | 51 | 14.7s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 433 | `tab_ordering_tabbable` | 47 | 14.8s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 434 | `target_clip_removed` | 5 | 14.5s | [45](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 435 | `target_clip_swf5` | 2 | 14.5s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 436 | `target_clip_swf6` | 2 | 14.5s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 437 | `target_path` | 14 | 14.4s |  |
| 438 | `tell_target` | 37 | 14.6s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 439 | `tell_target_invalid` | 6 | 14.5s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 440 | `tell_target_invalid_swf6` | 5 | 14.6s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 441 | `text_format` | 1146 | 14.8s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 442 | `text_format_display` | 21 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 443 | `text_format_font_max_length` | 2 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 444 | `text_format_get_text_extent_undefined_width` | 10 | 14.4s |  |
| 445 | `text_format_rounding_swf7` | 840 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 446 | `text_format_rounding_swf8` | 840 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 447 | `textfield_background_color` | 11 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 448 | `textfield_border_color` | 11 | 14.1s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 449 | `textfield_cache_as_bitmap` | 1 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 450 | `textfield_maxchars` | 3 | 15.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 451 | `textfield_properties` | 44 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 452 | `textfield_props_swf5` | 175 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 453 | `textfield_props_swf6` | 210 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 454 | `textfield_props_swf7` | 210 | 14.8s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 455 | `textfield_props_swf8` | 210 | 15.0s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 456 | `textfield_text` | 7 | 14.8s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 457 | `textfield_variable` | 81 | 14.9s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 458 | `textsnapshot_props_swf5` | 56 | 15.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 459 | `textsnapshot_props_swf6` | 56 | 15.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 460 | `this_scoping` | 52 | 14.8s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 461 | `this_swf5` | 41 | 14.6s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 462 | `this_swf6` | 41 | 14.7s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 463 | `this_swf7` | 41 | 14.7s | [59](ruffle-tests/_investigation/complete/this_swf7.md) |
| 464 | `timeline_function_def` | 7 | 14.7s |  |
| 465 | `trace` | 8 | 14.3s |  |
| 466 | `transform` | 70 | 14.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 467 | `try_catch_finally` | 118 | 14.4s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 468 | `try_finally_simple` | 16 | 14.2s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 469 | `typeof` | 22 | 14.2s |  |
| 470 | `typeof_globals` | 7 | 14.3s |  |
| 471 | `uncaught_exception` | 1 | 14.4s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 472 | `uncaught_exception_bubbled` | 1 | 14.4s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 473 | `undefined_to_string_swf6` | 4 | 14.8s |  |
| 474 | `unescape` | 43 | 14.6s |  |
| 475 | `unload` | 52 | 15.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 476 | `unload_clip_event` | 4 | 14.7s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 477 | `unloadmovie` | 4 | 15.8s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 478 | `unloadmovie_method` | 3 | 14.8s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 479 | `unloadmovienum` | 13 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 480 | `use_hand_cursor` | 8 | 14.7s |  |
| 481 | `variable_args` | 5 | 15.1s |  |
| 482 | `waitforframe` | 7 | 15.4s |  |
| 483 | `waitforframe2` | 16 | 14.6s |  |
| 484 | `watch` | 117 | 14.5s | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 485 | `watch_textfield` | 12 | 14.2s | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 486 | `watch_virtual_property_proto` | 2 | 14.3s | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 487 | `with` | 49 | 14.3s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 488 | `with_return` | 2 | 14.2s |  |
| 489 | `with_variable_scopes` | 43 | 14.4s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 490 | `xml` | 15 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 491 | `xml_append_child` | 28 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 492 | `xml_append_child_with_parent` | 20 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 493 | `xml_cdata` | 11 | 14.3s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 494 | `xml_child_nodes_edge_cases` | 4 | 14.3s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 495 | `xml_clone_expandos` | 19 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 496 | `xml_first_last_child` | 8 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 497 | `xml_has_child_nodes` | 3 | 14.6s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 498 | `xml_idmap` | 21 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 499 | `xml_ignore_comments` | 21 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 500 | `xml_ignore_white` | 34 | 15.9s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 501 | `xml_insert_before` | 20 | 14.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 502 | `xml_inspect_createmethods` | 15 | 14.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 503 | `xml_inspect_doctype` | 7 | 14.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 504 | `xml_inspect_parsexml` | 62 | 14.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 505 | `xml_inspect_xmldecl` | 7 | 14.0s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 506 | `xml_namespaces` | 203 | 13.9s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 507 | `xml_parent_and_child` | 5 | 14.0s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 508 | `xml_remove_node` | 22 | 14.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 509 | `xml_reparenting` | 14 | 14.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 510 | `xml_siblings` | 10 | 14.0s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 511 | `xml_to_string` | 13 | 14.0s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_to_string_comment` | 1 | 14.0s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_unescaping` | 23 | 14.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 514 | `xmlnode_proto` | 1 | 14.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**23 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 2 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 3 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 4 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `swf5_to_6_cross_call` | 79.3% | 23 | 29 | 6 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 9 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 10 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 12 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `cross_movie_root` | 60.0% | 6 | 10 | 4 |  |
| 16 | `movieclip_in_removed_button` | 60.0% | 3 | 5 | 2 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 17 | `textsnapshot_findtext` | 59.1% | 26 | 44 | 18 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 18 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 19 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [62](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 20 | `swf6_to_5_cross_call` | 55.2% | 16 | 29 | 13 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 21 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 22 | `issue_2030` | 50.0% | 2 | 4 | 2 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**55 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 2 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 3 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 4 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `swf5_to_6_cross_call` | 79.3% | 23/29 | 29 | 29 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 9 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 10 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 12 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `cross_movie_root` | 60.0% | 6/10 | 10 | 10 |  |
| 16 | `movieclip_in_removed_button` | 60.0% | 3/5 | 5 | 4 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 17 | `textsnapshot_findtext` | 59.1% | 26/44 | 44 | 44 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 18 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 19 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [62](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 20 | `swf6_to_5_cross_call` | 55.2% | 16/29 | 29 | 29 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 21 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 22 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 24 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 25 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 26 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 27 | `movieclip_state_values` | 34.2% | 39/114 | 55 | 114 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 29 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 30 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 32 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [60](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 33 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 34 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 35 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `root_button_mode` | 10.0% | 1/10 | 4 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 37 | `textsnapshot_gettext` | 9.1% | 5/55 | 55 | 55 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 38 | `global_instance_decls` | 1.6% | 12/758 | 482 | 758 | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 39 | `global_proto_decls` | 0.2% | 11/4497 | 692 | 4497 | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 40 | `global_proto_decls_delete` | 0.0% | 1/4158 | 310 | 4158 | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 41 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [20](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 42 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 43 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 44 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 45 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 46 | `geturl` | 0.0% | 0/7 | 0 | 7 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 47 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 48 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 51 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 52 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 53 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 54 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 55 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 3 | 3 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 12 | 2 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 11 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 12 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 13 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 14 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 15 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 16 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 17 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 18 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 6 | 1 |
| 19 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 20 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 21 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 5 | 4 | 1 |
| 22 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 23 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 29 | 26 | 3 |
| 24 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 25 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 26 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 27 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 46 | 39 | 7 |
| 28 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 4 | 3 | 1 |
| 29 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 30 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 31 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 32 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 33 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 34 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 56 | 47 | 9 |
| 35 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 36 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 37 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 38 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 39 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 40 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 41 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 42 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 43 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 44 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 45 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 46 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 3 | 1 |
| 47 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 48 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 49 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 50 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 51 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 52 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 53 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 54 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 55 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 18 | 16 | 2 |
| 56 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 69 | 60 | 9 |
| 57 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 0 | 4 |
| 58 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 59 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 60 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 1 | 1 |
| 61 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 62 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 63 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 64 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 65 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 66 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 26 | 25 | 1 |
| | *(tests not in any document)* | 165 | 156 | 9 |
