# Ruffle Test Results (Filtered)

**Date**: 2026-03-11 18:34 UTC

**Git SHA**: `6825ef2be0`

**Run Duration**: 153m 16s

**Filtered**: 49 tests ignored out of 618 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 569 |
| Passing | **509** (89.5%) |
| Failing | 60 |
| Total expected lines | 79233 |
| Matching lines | 64670 (81.6%) |
| Mismatched lines | 14563 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 60 | 100.0% |

## Passing Tests

**509 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 16.4s |  |
| 2 | `action_to_integer` | 28 | 15.3s |  |
| 3 | `add` | 28 | 15.0s |  |
| 4 | `add2` | 354 | 15.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.0s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.9s |  |
| 7 | `add_swf5` | 28 | 15.0s |  |
| 8 | `arguments` | 127 | 14.9s | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [40](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 15.2s |  |
| 11 | `array_constructor` | 30 | 14.9s |  |
| 12 | `array_enumerate` | 4 | 15.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.8s |  |
| 14 | `array_properties` | 36 | 14.5s |  |
| 15 | `array_prototyping` | 12 | 15.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.3s |  |
| 17 | `array_sort_random` | 443 | 14.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 14.6s |  |
| 19 | `array_trivial` | 209 | 14.7s |  |
| 20 | `as1_constructor_v6` | 35 | 14.5s |  |
| 21 | `as1_constructor_v7` | 35 | 15.4s |  |
| 22 | `as2_oop` | 13 | 15.8s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 16.4s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 15.8s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 15.3s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 15.0s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 14.8s |  |
| 28 | `as_broadcaster_undef` | 89 | 15.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 15.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 15.2s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 15.6s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 15.4s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 15.4s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 15.3s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 15.2s |  |
| 36 | `as_transformed_flag` | 20 | 15.6s |  |
| 37 | `asnative` | 34 | 14.9s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 15.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 14.7s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 14.8s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 14.3s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 13.9s |  |
| 43 | `bitand` | 1058 | 16.6s |  |
| 44 | `bitmap_data_colortransform` | 0 | 14.2s |  |
| 45 | `bitmap_data_fillrect` | 0 | 14.1s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 13.9s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 13.9s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 14.9s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 14.5s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.2s |  |
| 51 | `bitor` | 1058 | 16.6s |  |
| 52 | `biturshift` | 14 | 14.0s |  |
| 53 | `biturshift_swf8` | 14 | 14.7s |  |
| 54 | `bitxor` | 1058 | 16.9s |  |
| 55 | `boxed_primitives` | 24 | 14.2s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_key_events` | 14 | 14.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events_special` | 45 | 15.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_keypress` | 3 | 14.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_press` | 25 | 14.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_tab` | 20 | 14.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_textinput` | 4 | 14.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_order` | 2 | 14.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_properties_special_cases` | 22 | 14.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_v5` | 18 | 14.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v6` | 18 | 14.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `call` | 63 | 14.7s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 69 | `call_method_empty_name` | 1 | 14.2s |  |
| 70 | `capabilities_resolution` | 8 | 14.0s |  |
| 71 | `catch_references_registers` | 2 | 14.1s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 72 | `click_block` | 5 | 14.4s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 73 | `clip_constructors` | 8 | 14.3s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 74 | `clip_events` | 19 | 14.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `clone_sprite_types` | 24 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `closure_scope` | 7 | 14.3s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 77 | `coerce_to_primitive_resolve` | 17 | 14.3s | [41](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 78 | `color` | 57 | 14.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 14.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 14.4s |  |
| 81 | `constructor_function` | 2 | 14.1s |  |
| 82 | `context_menu` | 39 | 14.2s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 14.3s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 14.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `custom_clip_methods` | 4 | 14.3s | [11](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `default_names` | 52 | 14.3s | [13](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `define_function2` | 8 | 14.1s |  |
| 88 | `define_function2_preload` | 13 | 14.2s |  |
| 89 | `define_function2_preload_order` | 4 | 14.8s |  |
| 90 | `define_function_case_sensitive` | 2 | 14.7s |  |
| 91 | `define_local` | 27 | 14.5s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 92 | `define_local_with_paths` | 54 | 14.4s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 93 | `delete` | 3 | 14.5s |  |
| 94 | `device_font_spacing` | 91 | 14.4s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `display_object_properties` | 2 | 14.2s |  |
| 96 | `divide_swf4` | 107 | 14.2s |  |
| 97 | `do_init_action` | 3 | 14.3s |  |
| 98 | `do_init_action_child` | 12 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 99 | `drag_drop` | 10 | 14.3s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 100 | `drag_over_from_outside` | 1 | 14.3s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 101 | `drag_over_without_startdrag` | 1 | 14.3s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `duplicate_movie_clip` | 20 | 14.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 103 | `duplicate_movie_clip_drawing` | 2 | 14.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `edittext_align` | 60 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_align_trailing_spaces_swf7` | 576 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_align_trailing_spaces_swf8` | 576 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_antialiastype` | 296 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_autosize` | 71 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_autosize_setter` | 20 | 15.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_default_format` | 221 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_default_format_font_style` | 335 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_focus_selection` | 2 | 14.3s | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_font_size` | 45 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_hscroll` | 27 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_align_swf7` | 52 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_align_swf8` | 52 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_color` | 114 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_condensewhite_swf7` | 311 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_condensewhite_swf8` | 311 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_entity` | 4 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_roundtrip` | 17 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_swf7` | 5377 | 16.1s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_swf8` | 5377 | 16.0s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_input` | 1 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_input_newlines` | 9 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_leading` | 9 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_letter_spacing` | 15 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_margins` | 25 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_newline_stripping` | 64 | 18.9s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_newlines` | 30 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_password` | 5 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_password_copy` | 4 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_paste_empty` | 2 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_place_caret` | 2 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_programmatic_focus` | 12 | 14.3s | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_restrict` | 191 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_restrict_paste` | 5 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_scroll` | 54 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_stylesheet` | 325 | 14.9s | [52](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_tab_focus` | 13 | 14.2s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_tag_indent` | 31 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_text_height_leading` | 20 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_underline` | 40 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_width_height` | 103 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `empty_movieclip_can_attach_movies` | 11 | 14.8s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 146 | `enumerate` | 64 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 147 | `equals` | 32 | 14.4s |  |
| 148 | `equals2_swf5` | 926 | 16.4s |  |
| 149 | `equals2_swf6` | 926 | 16.4s |  |
| 150 | `equals2_swf7` | 926 | 16.5s |  |
| 151 | `equals_swf4` | 665 | 15.9s |  |
| 152 | `equals_swf4_alt` | 32 | 14.5s |  |
| 153 | `equals_swf5` | 32 | 14.6s |  |
| 154 | `error` | 58 | 14.4s |  |
| 155 | `escape` | 14 | 14.5s |  |
| 156 | `execution_order1` | 5 | 14.5s |  |
| 157 | `execution_order2` | 7 | 14.8s |  |
| 158 | `execution_order3` | 4 | 14.7s |  |
| 159 | `execution_order4` | 12 | 14.8s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 160 | `export_assets` | 3 | 14.7s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 161 | `extends_chain` | 134 | 15.1s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 162 | `extends_native_type` | 11 | 14.6s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 163 | `external_interface` | 84 | 15.1s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 164 | `external_interface_escapexml` | 26 | 14.5s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_jsquotestring` | 21 | 14.7s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_toas_basic` | 354 | 14.9s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_toxml_array` | 25 | 14.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_toxml_basic` | 179 | 14.7s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_unescapexml` | 40 | 14.7s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `focus_keyboard_press` | 60 | 14.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 171 | `focus_mouse` | 45 | 14.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 172 | `focus_mouse_rollout` | 4 | 14.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 173 | `focus_remove` | 33 | 14.1s |  |
| 174 | `focus_root_movie` | 2 | 14.0s | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focusrect_focuslost` | 4 | 14.2s | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focusrect_mouse_swf8` | 0 | 14.3s |  |
| 177 | `focusrect_mouse_swf9` | 0 | 14.9s |  |
| 178 | `focusrect_swf5` | 6 | 14.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 179 | `focusrect_swf6` | 42 | 14.7s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 180 | `frame_size_translated_negative` | 21 | 14.6s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 181 | `frame_size_translated_positive` | 21 | 14.8s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 182 | `function_as_function` | 35 | 14.9s | [20](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 183 | `function_base_clip` | 8 | 14.5s |  |
| 184 | `function_base_clip_readded` | 11 | 15.2s |  |
| 185 | `function_base_clip_removed` | 25 | 15.4s |  |
| 186 | `function_suppress_and_preload` | 28 | 15.2s |  |
| 187 | `funky_function_calls` | 56 | 15.2s | [20](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 188 | `get_bytes_total` | 4 | 15.0s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 189 | `get_variable_in_scope` | 29 | 14.9s |  |
| 190 | `getproperty` | 28 | 14.8s |  |
| 191 | `getproperty_swf4` | 28 | 14.3s |  |
| 192 | `getproperty_swf5` | 28 | 14.1s |  |
| 193 | `gettextextent` | 56 | 14.2s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 194 | `global_array` | 3 | 14.1s |  |
| 195 | `global_is_bare` | 7 | 14.0s |  |
| 196 | `global_swf5_6_7_8_9` | 1145 | 14.7s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 197 | `global_swf6_7_8` | 15 | 14.3s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 198 | `globals_swf5` | 304 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 199 | `globals_swf6` | 304 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 200 | `globals_swf7` | 304 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 201 | `globals_swf8` | 304 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 202 | `goto_advance1` | 6 | 14.1s |  |
| 203 | `goto_advance2` | 2 | 14.1s |  |
| 204 | `goto_both_ways1` | 3 | 14.0s |  |
| 205 | `goto_both_ways2` | 3 | 14.2s |  |
| 206 | `goto_execution_order` | 2 | 14.1s |  |
| 207 | `goto_execution_order2` | 2 | 14.1s |  |
| 208 | `goto_frame` | 12 | 17.1s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 209 | `goto_frame2` | 44 | 15.4s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 210 | `goto_frame_number` | 3 | 15.2s |  |
| 211 | `goto_label` | 17 | 15.1s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 212 | `goto_methods` | 40 | 15.0s | [19](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 213 | `goto_rewind1` | 1 | 15.0s |  |
| 214 | `goto_rewind2` | 3 | 15.0s |  |
| 215 | `goto_rewind3` | 2 | 15.1s |  |
| 216 | `greater_swf6` | 1175 | 17.2s |  |
| 217 | `greater_swf7` | 1175 | 17.0s |  |
| 218 | `greaterthan_swf5` | 1 | 14.8s |  |
| 219 | `greaterthan_swf8` | 1 | 14.9s |  |
| 220 | `has_own_property` | 32 | 14.8s |  |
| 221 | `hittest_lockroot` | 15 | 14.9s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 222 | `hittest_morph` | 70 | 14.8s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 223 | `hittest_winding_rule` | 12 | 15.2s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 224 | `infinite_recursion_function` | 4 | 14.9s | [25](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 225 | `infinite_recursion_function_in_setter` | 131 | 14.9s | [25](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 226 | `infinite_recursion_virtual_property` | 67 | 14.7s | [25](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 227 | `init_array_invalid` | 4 | 14.7s |  |
| 228 | `init_object_invalid` | 4 | 15.1s |  |
| 229 | `init_object_order` | 15 | 14.6s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 230 | `instanceof_coercions` | 88 | 14.8s | [62](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 231 | `interface_implements_op` | 47 | 15.0s | [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 232 | `is_finite` | 49 | 14.4s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 233 | `is_finite_swf6` | 49 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 234 | `is_prototype_of` | 89 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 235 | `issue_1086` | 1 | 14.3s |  |
| 236 | `issue_1104` | 2 | 14.5s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 237 | `issue_1671` | 0 | 14.3s |  |
| 238 | `issue_1906` | 4 | 14.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 239 | `issue_2166` | 9 | 14.2s |  |
| 240 | `issue_3169` | 2 | 14.5s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 241 | `issue_3446` | 1 | 14.3s |  |
| 242 | `issue_3522` | 2 | 14.3s |  |
| 243 | `issue_4377` | 2 | 14.2s |  |
| 244 | `issue_710` | 4 | 14.4s |  |
| 245 | `issue_768` | 3 | 14.3s | [26](ruffle-tests/_investigation/complete/issue_768.md) |
| 246 | `issue_9327` | 2 | 14.2s |  |
| 247 | `issue_9885` | 2 | 14.2s |  |
| 248 | `key_isToggled` | 9 | 14.3s |  |
| 249 | `lessthan` | 41 | 14.2s |  |
| 250 | `lessthan2_swf5` | 1226 | 16.4s |  |
| 251 | `lessthan2_swf6` | 1226 | 16.3s |  |
| 252 | `lessthan2_swf7` | 1226 | 16.2s |  |
| 253 | `lessthan_swf4` | 902 | 15.3s |  |
| 254 | `lessthan_swf4_alt` | 41 | 14.1s |  |
| 255 | `lessthan_swf5` | 41 | 14.2s |  |
| 256 | `loadmovie` | 2 | 14.2s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 257 | `loadmovie_fail` | 2 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 258 | `loadmovie_flashvars` | 4 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 259 | `loadmovie_method` | 2 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 260 | `loadmovie_registerclass` | 30 | 14.5s | [10](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 261 | `loadmovie_replace_root` | 5 | 14.4s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 262 | `loadmovie_var_persistence` | 8 | 14.5s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 263 | `loadmovienum` | 3 | 14.5s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 264 | `loadmovienum_cross_version_prototype` | 9 | 14.5s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 265 | `loadvariables` | 2 | 15.2s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 266 | `loadvariables2` | 8 | 15.1s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 267 | `loadvariablesnum` | 2 | 15.1s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 268 | `local_to_global` | 49 | 15.3s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 269 | `localconnection_properties` | 8 | 15.2s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 270 | `lock_root` | 1 | 15.0s |  |
| 271 | `logical_ops_swf4` | 90 | 15.0s |  |
| 272 | `logical_ops_swf8` | 108 | 15.0s |  |
| 273 | `looping` | 6 | 15.1s |  |
| 274 | `mask_reapply` | 0 | 15.0s |  |
| 275 | `mask_with_drawing` | 0 | 14.8s |  |
| 276 | `math_min_max` | 101 | 14.9s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 277 | `math_swf6` | 530 | 15.3s | [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 278 | `math_swf7` | 530 | 15.2s | [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 279 | `math_swf8` | 530 | 15.2s | [31](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 280 | `matrix` | 171 | 15.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 281 | `mcl_as_broadcaster` | 12 | 15.0s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 282 | `mcl_events_swf_version` | 232 | 15.4s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mcl_getprogress` | 30 | 14.9s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 284 | `mcl_loadclip` | 149 | 14.5s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 285 | `mcl_loadclip_properties` | 6 | 14.4s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 286 | `mcl_loadclip_replace_root` | 1 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 287 | `mcl_mislabeled_target` | 6 | 14.2s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 288 | `mcl_target_gif87a` | 6 | 14.8s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 289 | `mcl_target_gif89a` | 6 | 14.7s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 290 | `mcl_target_jpg` | 6 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 291 | `mcl_target_png` | 6 | 14.2s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mcl_unloadclip` | 5 | 14.1s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 293 | `mouse_events` | 8 | 14.1s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 294 | `mouse_events_visible_enabled` | 12 | 14.3s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 295 | `mouse_hover_events_while_dragging` | 1 | 14.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 296 | `mouse_listeners` | 67 | 14.1s |  |
| 297 | `mouse_pos` | 665 | 14.1s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 298 | `mouse_pos_with_scale_factor` | 260 | 14.2s | [33](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 299 | `mouse_wheel_enabled` | 2 | 14.3s |  |
| 300 | `movieclip_begin_gradient_fill` | 0 | 14.7s |  |
| 301 | `movieclip_blend_mode_property` | 35 | 14.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 302 | `movieclip_create_text_field` | 90 | 14.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 303 | `movieclip_default_state` | 69 | 14.6s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 304 | `movieclip_depth_methods` | 98 | 14.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 305 | `movieclip_focusenabled` | 99 | 14.2s | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 306 | `movieclip_get_instance_at_depth` | 28 | 14.3s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 307 | `movieclip_getbounds` | 191 | 14.4s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 308 | `movieclip_gettextsnapshot` | 112 | 14.3s | [22](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 309 | `movieclip_hittest` | 92 | 14.2s | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 310 | `movieclip_in_removed_button` | 4 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 311 | `movieclip_init_object` | 5 | 14.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 312 | `movieclip_line_gradient_style` | 0 | 14.7s |  |
| 313 | `movieclip_lockroot` | 29 | 14.8s | [30](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_name_from_timeline` | 13 | 14.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 315 | `movieclip_prototype_extension` | 5 | 14.3s |  |
| 316 | `movieclip_setmask` | 14 | 14.5s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 317 | `moviecliploader_flashvars` | 4 | 14.4s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 318 | `mutable_this` | 18 | 14.2s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 319 | `named_shapes` | 14 | 14.5s |  |
| 320 | `nan_scale` | 9 | 14.5s |  |
| 321 | `native_double_construct` | 12 | 14.4s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 322 | `native_objects_swf7` | 84 | 14.8s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 323 | `native_objects_swf8` | 84 | 14.9s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 324 | `nested_textfields_in_buttons` | 0 | 14.3s |  |
| 325 | `new_method_wrap` | 4 | 14.5s |  |
| 326 | `new_object_enumerate` | 7 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 327 | `new_object_wrap` | 4 | 14.2s |  |
| 328 | `o` | 3 | 14.2s |  |
| 329 | `object_constructor` | 33 | 14.3s |  |
| 330 | `object_function` | 32 | 14.3s |  |
| 331 | `object_properties` | 31 | 14.4s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 332 | `object_prototypes` | 74 | 14.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 333 | `object_resolve` | 38 | 14.4s | [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 334 | `object_string_coerce_swf5` | 62 | 14.2s | [37](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 335 | `object_string_coerce_swf6` | 68 | 14.4s | [37](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 336 | `on_construct` | 25 | 14.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 337 | `parse_float` | 74 | 14.3s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 338 | `parse_int` | 64 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 339 | `path_string` | 322 | 14.5s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 340 | `place_and_lookup` | 30 | 14.2s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 341 | `placeobject_occupied_depth` | 6 | 14.3s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 342 | `point` | 175 | 14.7s | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 343 | `primitive_instanceof` | 37 | 14.3s |  |
| 344 | `primitive_type_globals` | 557 | 14.3s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 345 | `printjob_props_swf5` | 45 | 14.5s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 346 | `printjob_props_swf6` | 45 | 14.0s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 347 | `printjob_props_swf7` | 45 | 14.0s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 348 | `property_invalid_base_clip` | 36 | 14.1s |  |
| 349 | `prototype_delete` | 12 | 14.1s |  |
| 350 | `prototype_enumerate` | 5 | 14.0s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 351 | `prototype_properties` | 17 | 13.9s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [42](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 352 | `rectangle` | 745 | 14.8s | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 353 | `recursive_prototypes` | 0 | 14.0s |  |
| 354 | `register_class` | 66 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 355 | `register_class_return_value` | 16 | 14.1s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 356 | `register_class_swf6` | 37 | 14.3s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 357 | `register_class_with_sound` | 11 | 14.2s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [47](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 358 | `register_globals_across_frames` | 15 | 14.1s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 359 | `register_underflow` | 26 | 14.1s | [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 360 | `remove_movie_clip` | 29 | 14.1s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 361 | `removed_clip_halts_script` | 15 | 14.5s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [45](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 362 | `removed_target_clip_scope` | 35 | 14.2s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 363 | `resolve_different_root` | 2 | 14.6s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 364 | `rewind_depth` | 30 | 14.4s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 365 | `root_global_parent` | 6 | 14.3s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 366 | `root_onload` | 1 | 14.2s | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 367 | `sandbox_type_local_file` | 1 | 14.2s |  |
| 368 | `sandbox_type_local_network` | 1 | 14.2s |  |
| 369 | `selection` | 454 | 14.4s | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 370 | `set_interval` | 27 | 14.3s | [60](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 371 | `set_variable_scope` | 58 | 14.2s |  |
| 372 | `single_frame` | 1 | 14.1s |  |
| 373 | `slash_syntax` | 14 | 14.2s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 374 | `sound` | 628 | 14.5s | [47](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 375 | `sound_props_swf5` | 68 | 15.9s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 376 | `sound_props_swf6` | 68 | 14.6s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 377 | `sound_start_load` | 0 | 14.8s |  |
| 378 | `stage_display_state` | 16 | 14.8s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 379 | `stage_object_children` | 83 | 15.0s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 380 | `stage_object_enumerate` | 4 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 381 | `stage_object_properties` | 241 | 14.9s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 382 | `stage_object_properties_get_var` | 5 | 14.6s |  |
| 383 | `stage_object_properties_swf6` | 231 | 14.8s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 384 | `stage_property_representation` | 586 | 14.9s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 385 | `stage_scale_mode` | 39 | 14.9s | [48](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [49](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 386 | `strictequals_swf6` | 902 | 16.5s |  |
| 387 | `strictly_equals` | 7 | 14.7s |  |
| 388 | `string_coercion` | 117 | 15.3s | [50](ruffle-tests/_investigation/complete/string_coercion.md) |
| 389 | `string_methods` | 285 | 15.5s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 390 | `string_methods_negative_args` | 240 | 14.9s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 391 | `string_methods_swfv5` | 275 | 15.4s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 392 | `string_ops_swf6` | 95 | 15.1s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 393 | `string_paths_basic` | 4 | 14.7s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 394 | `string_paths_eval2` | 7 | 15.8s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 395 | `string_paths_hidden` | 54 | 14.7s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 396 | `string_paths_other` | 36 | 14.7s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 397 | `string_paths_unload` | 1 | 14.5s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 398 | `string_paths_variable_alias` | 4 | 14.6s | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 399 | `string_paths_variable_scopes` | 5 | 14.4s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 400 | `stylesheet` | 283 | 15.2s |  |
| 401 | `stylesheet_transform` | 750 | 15.1s |  |
| 402 | `super_edge_cases` | 39 | 14.8s | [36](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [39](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 403 | `swf4_actions_bool` | 96 | 14.7s |  |
| 404 | `swf4_actions_coercion_order` | 158 | 14.5s | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 405 | `swf4_bool` | 4 | 14.4s |  |
| 406 | `swf4_function_calls` | 7 | 14.3s |  |
| 407 | `swf5_encoding` | 3 | 14.6s |  |
| 408 | `swf5_global_funcs` | 232 | 14.8s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 409 | `swf5_no_closure` | 19 | 14.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 410 | `swf6_case_insensitive` | 42 | 15.4s | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 411 | `swf6_global_funcs` | 232 | 15.2s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 412 | `swf6_string_as_bool` | 15 | 15.1s | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 413 | `swf7_case_sensitive` | 44 | 15.0s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 414 | `swf7_global_funcs` | 232 | 15.1s | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 415 | `tab_ordering_automatic_basic` | 92 | 15.1s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 416 | `tab_ordering_automatic_order_grid` | 21 | 15.2s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 417 | `tab_ordering_automatic_order_same_position` | 12 | 15.4s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 418 | `tab_ordering_children` | 208 | 15.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 419 | `tab_ordering_custom_basic` | 71 | 15.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 420 | `tab_ordering_custom_duplicate_index` | 22 | 15.5s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 421 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.0s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 422 | `tab_ordering_custom_m1` | 29 | 15.1s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 423 | `tab_ordering_events` | 150 | 15.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 424 | `tab_ordering_events_mouse` | 65 | 15.8s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 425 | `tab_ordering_movieclip_enabled_default` | 462 | 15.6s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 426 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.3s |  |
| 427 | `tab_ordering_reverse` | 51 | 14.2s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 428 | `tab_ordering_tabbable` | 47 | 14.3s | [54](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 429 | `target_clip_removed` | 5 | 14.2s | [45](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 430 | `target_clip_swf5` | 2 | 14.2s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 431 | `target_clip_swf6` | 2 | 14.2s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 432 | `target_path` | 14 | 14.1s |  |
| 433 | `tell_target` | 37 | 14.2s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 434 | `tell_target_invalid` | 6 | 14.2s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 435 | `tell_target_invalid_swf6` | 5 | 14.1s | [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 436 | `text_format` | 1146 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 437 | `text_format_display` | 21 | 14.1s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 438 | `text_format_font_max_length` | 2 | 14.0s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 439 | `text_format_get_text_extent_undefined_width` | 10 | 14.1s |  |
| 440 | `text_format_rounding_swf7` | 840 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 441 | `text_format_rounding_swf8` | 840 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 442 | `textfield_background_color` | 11 | 14.1s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 443 | `textfield_border_color` | 11 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 444 | `textfield_cache_as_bitmap` | 1 | 14.2s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 445 | `textfield_maxchars` | 3 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 446 | `textfield_properties` | 44 | 14.3s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 447 | `textfield_props_swf5` | 175 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 448 | `textfield_props_swf6` | 210 | 14.6s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 449 | `textfield_props_swf7` | 210 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 450 | `textfield_props_swf8` | 210 | 14.4s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 451 | `textfield_text` | 7 | 14.1s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 452 | `textfield_variable` | 81 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 453 | `textsnapshot_props_swf5` | 56 | 14.5s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 454 | `textsnapshot_props_swf6` | 56 | 14.7s | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 455 | `this_scoping` | 52 | 14.5s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 456 | `this_swf5` | 41 | 14.7s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 457 | `this_swf6` | 41 | 14.4s | [58](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 458 | `this_swf7` | 41 | 14.4s | [59](ruffle-tests/_investigation/complete/this_swf7.md) |
| 459 | `timeline_function_def` | 7 | 14.6s |  |
| 460 | `trace` | 8 | 14.4s |  |
| 461 | `transform` | 70 | 14.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 462 | `try_catch_finally` | 118 | 14.5s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 463 | `try_finally_simple` | 16 | 14.3s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 464 | `typeof` | 22 | 14.4s |  |
| 465 | `typeof_globals` | 7 | 14.4s |  |
| 466 | `uncaught_exception` | 1 | 14.5s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 467 | `uncaught_exception_bubbled` | 1 | 14.5s | [61](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 468 | `undefined_to_string_swf6` | 4 | 14.3s |  |
| 469 | `unescape` | 43 | 14.5s |  |
| 470 | `unload` | 52 | 14.6s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 471 | `unload_clip_event` | 4 | 14.7s | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 472 | `unloadmovie` | 4 | 14.4s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 473 | `unloadmovie_method` | 3 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 474 | `unloadmovienum` | 13 | 14.6s | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 475 | `use_hand_cursor` | 8 | 14.7s |  |
| 476 | `variable_args` | 5 | 14.7s |  |
| 477 | `waitforframe` | 7 | 14.6s |  |
| 478 | `waitforframe2` | 16 | 15.5s |  |
| 479 | `watch` | 117 | 14.9s | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 480 | `watch_textfield` | 12 | 15.1s | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 481 | `watch_virtual_property_proto` | 2 | 14.6s | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 482 | `with` | 49 | 15.1s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 483 | `with_return` | 2 | 15.1s |  |
| 484 | `with_variable_scopes` | 43 | 14.9s | [65](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 485 | `xml` | 15 | 15.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 486 | `xml_append_child` | 28 | 15.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 487 | `xml_append_child_with_parent` | 20 | 15.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 488 | `xml_cdata` | 11 | 15.2s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 489 | `xml_child_nodes_edge_cases` | 4 | 15.3s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 490 | `xml_clone_expandos` | 19 | 15.1s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 491 | `xml_first_last_child` | 8 | 14.9s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 492 | `xml_has_child_nodes` | 3 | 15.0s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 493 | `xml_idmap` | 21 | 15.5s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 494 | `xml_ignore_comments` | 21 | 15.7s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 495 | `xml_ignore_white` | 34 | 16.6s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 496 | `xml_insert_before` | 20 | 14.8s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 497 | `xml_inspect_createmethods` | 15 | 14.7s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 498 | `xml_inspect_doctype` | 7 | 14.5s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 499 | `xml_inspect_parsexml` | 62 | 14.4s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 500 | `xml_inspect_xmldecl` | 7 | 14.4s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 501 | `xml_namespaces` | 203 | 14.6s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 502 | `xml_parent_and_child` | 5 | 14.3s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 503 | `xml_remove_node` | 22 | 14.4s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 504 | `xml_reparenting` | 14 | 14.4s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 505 | `xml_siblings` | 10 | 14.6s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 506 | `xml_to_string` | 13 | 14.3s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 507 | `xml_to_string_comment` | 1 | 14.3s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 508 | `xml_unescaping` | 23 | 14.5s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 509 | `xmlnode_proto` | 1 | 14.4s | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**27 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 2 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_2` | 92.0% | 69 | 75 | 6 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_invalid_get_bounds_6` | 80.0% | 8 | 10 | 2 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `movieclip_invalid_get_bounds_7` | 80.0% | 8 | 10 | 2 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `swf5_to_6_cross_call` | 79.3% | 23 | 29 | 6 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 9 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_3` | 76.9% | 10 | 13 | 3 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_invalid_get_bounds_4` | 76.9% | 10 | 13 | 3 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 14 | `movieclip_invalid_get_bounds_5` | 72.7% | 8 | 11 | 3 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `movieclip_invalid_get_bounds_8` | 63.6% | 7 | 11 | 4 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `movieclip_invalid_get_bounds_1` | 61.3% | 46 | 75 | 29 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `cross_movie_root` | 60.0% | 6 | 10 | 4 |  |
| 21 | `textsnapshot_findtext` | 59.1% | 26 | 44 | 18 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 22 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 23 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [62](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 24 | `swf6_to_5_cross_call` | 55.2% | 16 | 29 | 13 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 25 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 26 | `issue_2030` | 50.0% | 2 | 4 | 2 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**60 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 2 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [35](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [44](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_2` | 92.0% | 69/75 | 75 | 75 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_invalid_get_bounds_6` | 80.0% | 8/10 | 10 | 10 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `movieclip_invalid_get_bounds_7` | 80.0% | 8/10 | 10 | 10 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `swf5_to_6_cross_call` | 79.3% | 23/29 | 29 | 29 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 9 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [46](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_3` | 76.9% | 10/13 | 13 | 13 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_invalid_get_bounds_4` | 76.9% | 10/13 | 13 | 13 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 14 | `movieclip_invalid_get_bounds_5` | 72.7% | 8/11 | 11 | 11 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `movieclip_invalid_get_bounds_8` | 63.6% | 7/11 | 11 | 11 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 18 | `movieclip_invalid_get_bounds_1` | 61.3% | 46/75 | 75 | 75 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `cross_movie_root` | 60.0% | 6/10 | 10 | 10 |  |
| 21 | `textsnapshot_findtext` | 59.1% | 26/44 | 44 | 44 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 22 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 23 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [62](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 24 | `swf6_to_5_cross_call` | 55.2% | 16/29 | 29 | 29 | [53](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 25 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 26 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 28 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 29 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 30 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 31 | `movieclip_state_values` | 34.2% | 39/114 | 55 | 114 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 32 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 33 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 34 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 35 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 36 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [60](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 37 | `register_and_init_order` | 15.6% | 36/231 | 154 | 231 | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [43](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 38 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 39 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [38](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 40 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 41 | `root_button_mode` | 10.0% | 1/10 | 4 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 42 | `textsnapshot_gettext` | 9.1% | 5/55 | 55 | 55 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 43 | `global_instance_decls` | 1.6% | 12/758 | 482 | 758 | [21](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 44 | `global_proto_decls` | 0.2% | 11/4497 | 692 | 4497 | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 45 | `global_proto_decls_delete` | 0.0% | 1/4158 | 310 | 4158 | [23](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 46 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [20](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 47 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 48 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 50 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [18](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 51 | `geturl` | 0.0% | 0/7 | 0 | 7 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 52 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [24](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 53 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 54 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [27](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 55 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 56 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [51](ruffle-tests/_investigation/complete/STRING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 57 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [63](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 58 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [66](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 59 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [56](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [57](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 60 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [34](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [64](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 3 | 3 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
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
| 24 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 6 | 11 |
| 25 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 26 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 27 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 46 | 33 | 13 |
| 28 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 4 | 3 | 1 |
| 29 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 30 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 31 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 32 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 33 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 34 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 56 | 40 | 16 |
| 35 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 36 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 37 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 38 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 39 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 40 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 41 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 42 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 43 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 14 | 1 |
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
| | *(tests not in any document)* | 165 | 157 | 8 |
