# Ruffle Test Results (Filtered)

**Date**: 2026-03-14 15:20 UTC

**Git SHA**: `598e52348e`

**Run Duration**: 162m 29s

**Filtered**: 53 tests ignored out of 618 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 565 |
| Passing | **535** (94.7%) |
| Failing | 30 |
| Total expected lines | 79003 |
| Matching lines | 68745 (87.0%) |
| Mismatched lines | 10258 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 30 | 100.0% |

## Passing Tests

**535 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.3s |  |
| 2 | `action_to_integer` | 28 | 15.1s |  |
| 3 | `add` | 28 | 15.1s |  |
| 4 | `add2` | 354 | 15.3s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.1s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.0s |  |
| 7 | `add_swf5` | 28 | 15.2s |  |
| 8 | `arguments` | 127 | 15.0s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 15.1s |  |
| 11 | `array_constructor` | 30 | 15.2s |  |
| 12 | `array_enumerate` | 4 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 15.2s |  |
| 14 | `array_properties` | 36 | 15.0s |  |
| 15 | `array_prototyping` | 12 | 15.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.0s |  |
| 17 | `array_sort_random` | 443 | 15.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 15.2s |  |
| 19 | `array_trivial` | 209 | 15.2s |  |
| 20 | `as1_constructor_v6` | 35 | 15.1s |  |
| 21 | `as1_constructor_v7` | 35 | 15.9s |  |
| 22 | `as2_oop` | 13 | 15.7s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 15.8s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 15.8s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 16.0s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 15.8s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 15.4s |  |
| 28 | `as_broadcaster_undef` | 89 | 15.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 15.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 15.4s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 15.4s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 15.4s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 15.4s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 15.5s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 15.4s |  |
| 36 | `as_transformed_flag` | 20 | 15.6s |  |
| 37 | `asnative` | 34 | 15.4s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 15.4s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 16.0s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 15.4s |  |
| 43 | `bitand` | 1058 | 18.4s |  |
| 44 | `bitmap_data_colortransform` | 0 | 15.6s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 45 | `bitmap_data_fillrect` | 0 | 15.6s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_max_size_swf10` | 12 | 15.7s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_max_size_swf9` | 10 | 15.3s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_perlinnoise` | 0 | 16.4s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 15.8s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.4s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 51 | `bitor` | 1058 | 18.2s |  |
| 52 | `biturshift` | 14 | 15.4s |  |
| 53 | `biturshift_swf8` | 14 | 17.3s |  |
| 54 | `bitxor` | 1058 | 17.9s |  |
| 55 | `boxed_primitives` | 24 | 15.2s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 15.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 15.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_key_events` | 14 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events_special` | 45 | 16.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_keypress` | 3 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_press` | 25 | 15.7s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_tab` | 20 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_textinput` | 4 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_order` | 2 | 15.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_properties_special_cases` | 22 | 15.5s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_v5` | 18 | 15.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v6` | 18 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `call` | 63 | 15.5s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 69 | `call_method_empty_name` | 1 | 15.5s |  |
| 70 | `capabilities_resolution` | 8 | 15.8s |  |
| 71 | `catch_references_registers` | 2 | 15.7s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 72 | `click_block` | 5 | 15.6s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 73 | `clip_constructors` | 8 | 15.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 74 | `clip_event_propagation_order` | 17 | 15.4s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `clip_events` | 19 | 15.4s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 15.1s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 15.2s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 17 | 15.2s | [46](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `color` | 57 | 15.3s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `color_transform` | 48 | 15.2s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `conflicting_instance_names` | 23 | 15.2s |  |
| 82 | `constructor_function` | 2 | 15.1s |  |
| 83 | `context_menu` | 39 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `context_menu_item` | 41 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `create_empty_movie_clip` | 3 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `cross_movie_root` | 10 | 15.1s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 87 | `custom_clip_methods` | 4 | 15.2s | [12](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `default_names` | 52 | 15.1s | [14](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `define_function2` | 8 | 15.2s |  |
| 90 | `define_function2_preload` | 13 | 15.1s |  |
| 91 | `define_function2_preload_order` | 4 | 16.9s |  |
| 92 | `define_function_case_sensitive` | 2 | 15.2s |  |
| 93 | `define_local` | 27 | 15.3s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 94 | `define_local_with_paths` | 54 | 15.2s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `delete` | 3 | 15.3s |  |
| 96 | `device_font_spacing` | 91 | 15.4s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 97 | `display_object_properties` | 2 | 15.2s |  |
| 98 | `divide_swf4` | 107 | 15.3s |  |
| 99 | `do_init_action` | 3 | 15.2s |  |
| 100 | `do_init_action_child` | 12 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 101 | `drag_drop` | 10 | 15.3s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_from_outside` | 1 | 15.3s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `drag_over_without_startdrag` | 1 | 15.3s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 104 | `duplicate_movie_clip` | 20 | 15.3s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `duplicate_movie_clip_drawing` | 2 | 15.3s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `edittext_align` | 60 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf7` | 576 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_align_trailing_spaces_swf8` | 576 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_antialiastype` | 296 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize` | 71 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_autosize_setter` | 20 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format` | 221 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_default_format_font_style` | 335 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_focus_selection` | 2 | 15.1s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_font_size` | 45 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_hscroll` | 27 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf7` | 52 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_align_swf8` | 52 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_color` | 114 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf7` | 311 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_condensewhite_swf8` | 311 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_entity` | 4 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_roundtrip` | 17 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf7` | 5377 | 16.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_swf8` | 5377 | 16.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input` | 1 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_input_newlines` | 9 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_leading` | 9 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_letter_spacing` | 15 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_margins` | 25 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_newline_stripping` | 64 | 19.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_newlines` | 30 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_password` | 5 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_password_copy` | 4 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_paste_empty` | 2 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_place_caret` | 2 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_programmatic_focus` | 12 | 14.9s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_restrict` | 191 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_restrict_paste` | 5 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_scroll` | 54 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_stylesheet` | 325 | 15.7s | [57](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_tab_focus` | 13 | 15.0s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_tab_stops` | 60 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_tag_indent` | 31 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_text_height_leading` | 20 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_underline` | 40 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `edittext_width_height` | 103 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 148 | `empty_movieclip_can_attach_movies` | 11 | 16.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 149 | `enumerate` | 64 | 16.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 150 | `equals` | 32 | 16.4s |  |
| 151 | `equals2_swf5` | 926 | 17.9s |  |
| 152 | `equals2_swf6` | 926 | 18.1s |  |
| 153 | `equals2_swf7` | 926 | 18.2s |  |
| 154 | `equals_swf4` | 665 | 17.1s |  |
| 155 | `equals_swf4_alt` | 32 | 15.7s |  |
| 156 | `equals_swf5` | 32 | 15.9s |  |
| 157 | `error` | 58 | 16.0s |  |
| 158 | `escape` | 14 | 16.2s |  |
| 159 | `execution_order1` | 5 | 16.2s |  |
| 160 | `execution_order2` | 7 | 16.2s |  |
| 161 | `execution_order3` | 4 | 16.2s |  |
| 162 | `execution_order4` | 12 | 16.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 163 | `export_assets` | 3 | 16.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 164 | `extends_chain` | 134 | 16.5s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 165 | `extends_native_type` | 11 | 16.3s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `external_interface` | 84 | 16.4s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_escapexml` | 26 | 16.1s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_jsquotestring` | 21 | 16.2s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_toas_basic` | 354 | 16.1s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_toxml_array` | 25 | 15.2s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_toxml_basic` | 179 | 15.3s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `external_interface_unescapexml` | 40 | 15.3s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 173 | `focus_keyboard_press` | 60 | 15.4s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focus_mouse` | 45 | 15.3s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focus_mouse_focusable` | 8 | 15.7s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_mouse_rollout` | 4 | 15.2s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 177 | `focus_remove` | 33 | 15.2s |  |
| 178 | `focus_root_movie` | 2 | 15.3s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 179 | `focus_visibility_change` | 45 | 15.3s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 180 | `focusrect_focuslost` | 4 | 15.2s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 181 | `focusrect_mouse_swf8` | 0 | 15.2s |  |
| 182 | `focusrect_mouse_swf9` | 0 | 16.2s |  |
| 183 | `focusrect_property_swf5` | 1237 | 15.4s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 184 | `focusrect_property_swf6` | 1237 | 15.4s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 185 | `focusrect_property_swf7` | 1237 | 15.4s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 186 | `focusrect_swf5` | 6 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 187 | `focusrect_swf6` | 42 | 15.2s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 188 | `frame_size_translated_negative` | 21 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 189 | `frame_size_translated_positive` | 21 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 190 | `function_as_function` | 35 | 15.2s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 191 | `function_base_clip` | 8 | 15.1s |  |
| 192 | `function_base_clip_readded` | 11 | 15.3s |  |
| 193 | `function_base_clip_removed` | 25 | 15.2s |  |
| 194 | `function_suppress_and_preload` | 28 | 15.2s |  |
| 195 | `funky_function_calls` | 56 | 15.2s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 196 | `get_bytes_total` | 4 | 15.2s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 197 | `get_variable_in_scope` | 29 | 15.1s |  |
| 198 | `getproperty` | 28 | 15.2s |  |
| 199 | `getproperty_swf4` | 28 | 15.8s |  |
| 200 | `getproperty_swf5` | 28 | 15.4s |  |
| 201 | `gettextextent` | 56 | 15.4s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 202 | `global_array` | 3 | 15.8s |  |
| 203 | `global_is_bare` | 7 | 15.6s |  |
| 204 | `global_swf5_6_7_8_9` | 1145 | 16.0s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 205 | `global_swf6_7_8` | 15 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 206 | `globals_swf5` | 304 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 207 | `globals_swf6` | 304 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 208 | `globals_swf7` | 304 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 209 | `globals_swf8` | 304 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 210 | `goto_advance1` | 6 | 15.0s |  |
| 211 | `goto_advance2` | 2 | 14.9s |  |
| 212 | `goto_both_ways1` | 3 | 15.0s |  |
| 213 | `goto_both_ways2` | 3 | 15.0s |  |
| 214 | `goto_execution_order` | 2 | 14.9s |  |
| 215 | `goto_execution_order2` | 2 | 15.0s |  |
| 216 | `goto_frame` | 12 | 15.6s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 217 | `goto_frame2` | 44 | 15.6s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 218 | `goto_frame_number` | 3 | 15.1s |  |
| 219 | `goto_label` | 17 | 15.3s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 220 | `goto_methods` | 40 | 15.3s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 221 | `goto_rewind1` | 1 | 15.1s |  |
| 222 | `goto_rewind2` | 3 | 15.2s |  |
| 223 | `goto_rewind3` | 2 | 15.1s |  |
| 224 | `greater_swf6` | 1175 | 17.2s |  |
| 225 | `greater_swf7` | 1175 | 17.2s |  |
| 226 | `greaterthan_swf5` | 1 | 15.5s |  |
| 227 | `greaterthan_swf8` | 1 | 15.4s |  |
| 228 | `has_own_property` | 32 | 15.3s |  |
| 229 | `hittest_lockroot` | 15 | 15.5s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 230 | `hittest_morph` | 70 | 15.2s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 231 | `hittest_winding_rule` | 12 | 15.3s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 232 | `infinite_recursion_function` | 4 | 15.1s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 233 | `infinite_recursion_function_in_setter` | 131 | 15.0s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 234 | `infinite_recursion_virtual_property` | 67 | 14.9s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 235 | `init_array_invalid` | 4 | 15.1s |  |
| 236 | `init_object_invalid` | 4 | 15.3s |  |
| 237 | `init_object_order` | 15 | 15.5s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 238 | `input_dead_keys_windows` | 15 | 15.4s | [29](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 239 | `instanceof_coercions` | 88 | 15.6s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 240 | `interface_implements_op` | 47 | 15.6s | [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 241 | `is_finite` | 49 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 242 | `is_finite_swf6` | 49 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 243 | `is_prototype_of` | 89 | 15.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 244 | `issue_1086` | 1 | 15.5s |  |
| 245 | `issue_1104` | 2 | 15.6s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 246 | `issue_1671` | 0 | 15.3s |  |
| 247 | `issue_1906` | 4 | 16.3s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 248 | `issue_2166` | 9 | 15.4s |  |
| 249 | `issue_2870` | 3 | 15.6s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 250 | `issue_3169` | 2 | 15.7s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 251 | `issue_3446` | 1 | 15.3s |  |
| 252 | `issue_3522` | 2 | 15.2s |  |
| 253 | `issue_4377` | 2 | 15.3s |  |
| 254 | `issue_710` | 4 | 15.4s |  |
| 255 | `issue_768` | 3 | 15.3s | [30](ruffle-tests/_investigation/complete/issue_768.md) |
| 256 | `issue_9327` | 2 | 15.1s |  |
| 257 | `issue_9885` | 2 | 15.1s |  |
| 258 | `key_isToggled` | 9 | 15.1s |  |
| 259 | `lessthan` | 41 | 15.0s |  |
| 260 | `lessthan2_swf5` | 1226 | 16.9s |  |
| 261 | `lessthan2_swf6` | 1226 | 17.0s |  |
| 262 | `lessthan2_swf7` | 1226 | 17.0s |  |
| 263 | `lessthan_swf4` | 902 | 16.1s |  |
| 264 | `lessthan_swf4_alt` | 41 | 14.9s |  |
| 265 | `lessthan_swf5` | 41 | 15.0s |  |
| 266 | `loadmovie` | 2 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 267 | `loadmovie_fail` | 2 | 15.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 268 | `loadmovie_flashvars` | 4 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 269 | `loadmovie_method` | 2 | 15.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 270 | `loadmovie_registerclass` | 30 | 15.4s | [11](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 271 | `loadmovie_replace_root` | 5 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 272 | `loadmovie_var_persistence` | 8 | 15.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 273 | `loadmovienum` | 3 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 274 | `loadmovienum_cross_version_prototype` | 9 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 275 | `loadvariables` | 2 | 16.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 276 | `loadvariables2` | 8 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 277 | `loadvariablesnum` | 2 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 278 | `local_to_global` | 49 | 15.1s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 279 | `localconnection_properties` | 8 | 15.1s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 280 | `lock_root` | 1 | 15.0s |  |
| 281 | `logical_ops_swf4` | 90 | 15.0s |  |
| 282 | `logical_ops_swf8` | 108 | 15.1s |  |
| 283 | `looping` | 6 | 15.0s |  |
| 284 | `mask_reapply` | 0 | 15.0s |  |
| 285 | `mask_with_drawing` | 0 | 15.0s |  |
| 286 | `math_min_max` | 101 | 15.1s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 287 | `math_swf6` | 530 | 15.6s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 288 | `math_swf7` | 530 | 15.6s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 289 | `math_swf8` | 530 | 15.7s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 290 | `matrix` | 171 | 16.0s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 291 | `mcl_as_broadcaster` | 12 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mcl_events_swf_version` | 232 | 16.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 293 | `mcl_getprogress` | 30 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 294 | `mcl_loadclip` | 149 | 17.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 295 | `mcl_loadclip_properties` | 6 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_loadclip_replace_root` | 1 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 297 | `mcl_mislabeled_target` | 6 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_target_gif87a` | 6 | 16.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 299 | `mcl_target_gif89a` | 6 | 16.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 300 | `mcl_target_jpg` | 6 | 15.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 301 | `mcl_target_png` | 6 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 302 | `mcl_unloadclip` | 5 | 15.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 303 | `mouse_events` | 8 | 15.9s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 304 | `mouse_events_visible_enabled` | 12 | 16.2s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 305 | `mouse_hover_events_while_dragging` | 1 | 16.0s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 306 | `mouse_listeners` | 67 | 15.8s |  |
| 307 | `mouse_pos` | 665 | 15.8s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 308 | `mouse_pos_with_scale_factor` | 260 | 16.0s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 309 | `mouse_wheel_enabled` | 2 | 16.0s |  |
| 310 | `movieclip_begin_gradient_fill` | 0 | 16.6s |  |
| 311 | `movieclip_blend_mode_property` | 35 | 16.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 312 | `movieclip_create_text_field` | 90 | 16.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 313 | `movieclip_default_state` | 69 | 17.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_depth_methods` | 98 | 15.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 315 | `movieclip_focusenabled` | 99 | 15.6s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 316 | `movieclip_get_instance_at_depth` | 28 | 15.8s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 317 | `movieclip_getbounds` | 191 | 15.9s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 318 | `movieclip_gettextsnapshot` | 112 | 16.0s | [24](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_hittest` | 92 | 16.1s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_in_removed_button` | 4 | 15.7s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 321 | `movieclip_init_object` | 5 | 15.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 322 | `movieclip_invalid_get_bounds_1` | 75 | 16.4s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 323 | `movieclip_invalid_get_bounds_2` | 75 | 16.6s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_invalid_get_bounds_3` | 13 | 15.9s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_invalid_get_bounds_4` | 13 | 15.9s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_invalid_get_bounds_5` | 11 | 15.8s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_invalid_get_bounds_8` | 11 | 15.9s | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_line_gradient_style` | 0 | 16.2s |  |
| 329 | `movieclip_lockroot` | 29 | 15.9s | [35](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_name_from_timeline` | 13 | 14.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_prototype_extension` | 5 | 14.8s |  |
| 332 | `movieclip_setmask` | 14 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 333 | `moviecliploader_flashvars` | 4 | 15.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 334 | `mutable_this` | 18 | 14.8s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 335 | `named_shapes` | 14 | 14.8s |  |
| 336 | `nan_scale` | 9 | 14.9s |  |
| 337 | `native_double_construct` | 12 | 14.9s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 338 | `native_objects_swf7` | 84 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 339 | `native_objects_swf8` | 84 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 340 | `nested_textfields_in_buttons` | 0 | 14.9s |  |
| 341 | `new_method_wrap` | 4 | 16.4s |  |
| 342 | `new_object_enumerate` | 7 | 16.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 343 | `new_object_wrap` | 4 | 16.1s |  |
| 344 | `o` | 3 | 16.2s |  |
| 345 | `object_constructor` | 33 | 16.4s |  |
| 346 | `object_function` | 32 | 16.3s |  |
| 347 | `object_properties` | 31 | 16.6s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 348 | `object_prototypes` | 74 | 16.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 349 | `object_resolve` | 38 | 16.5s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 350 | `object_string_coerce_swf5` | 62 | 16.4s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 351 | `object_string_coerce_swf6` | 68 | 16.2s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 352 | `on_construct` | 25 | 16.5s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 353 | `parse_float` | 74 | 16.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 354 | `parse_int` | 64 | 16.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 355 | `path_string` | 322 | 16.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 356 | `place_and_lookup` | 30 | 16.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 357 | `placeobject_occupied_depth` | 6 | 16.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 358 | `point` | 175 | 16.7s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 359 | `primitive_instanceof` | 37 | 16.3s |  |
| 360 | `primitive_type_globals` | 557 | 16.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 361 | `printjob_props_swf5` | 45 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 362 | `printjob_props_swf6` | 45 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 363 | `printjob_props_swf7` | 45 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 364 | `property_invalid_base_clip` | 36 | 16.0s |  |
| 365 | `prototype_delete` | 12 | 15.5s |  |
| 366 | `prototype_enumerate` | 5 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 367 | `prototype_properties` | 17 | 15.8s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 368 | `rectangle` | 745 | 16.0s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 369 | `recursive_prototypes` | 0 | 15.6s |  |
| 370 | `register_and_init_order` | 231 | 15.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 371 | `register_class` | 66 | 16.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 372 | `register_class_return_value` | 16 | 15.3s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 373 | `register_class_swf6` | 37 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 374 | `register_class_with_sound` | 11 | 15.3s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 375 | `register_globals_across_frames` | 15 | 15.7s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 376 | `register_underflow` | 26 | 15.5s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 377 | `remove_movie_clip` | 29 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 378 | `removed_clip_halts_script` | 15 | 16.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 379 | `removed_target_clip_scope` | 35 | 15.4s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 380 | `resolve_different_root` | 2 | 15.4s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 381 | `rewind_depth` | 30 | 15.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 382 | `root_button_mode` | 10 | 15.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 383 | `root_global_parent` | 6 | 15.1s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 384 | `root_onload` | 1 | 15.1s | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 385 | `sandbox_type_local_file` | 1 | 15.0s |  |
| 386 | `sandbox_type_local_network` | 1 | 15.0s |  |
| 387 | `selection` | 454 | 15.2s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 388 | `selection_handlers` | 27 | 15.1s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 389 | `set_interval` | 27 | 15.2s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 390 | `set_variable_scope` | 58 | 15.0s |  |
| 391 | `single_frame` | 1 | 15.0s |  |
| 392 | `slash_syntax` | 14 | 15.0s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 393 | `sound` | 628 | 15.3s | [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 394 | `sound_props_swf5` | 68 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 395 | `sound_props_swf6` | 68 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 396 | `sound_start_load` | 0 | 15.1s |  |
| 397 | `stage_display_state` | 16 | 15.0s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 398 | `stage_object_children` | 83 | 15.0s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 399 | `stage_object_enumerate` | 4 | 14.9s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 400 | `stage_object_properties` | 241 | 15.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 401 | `stage_object_properties_get_var` | 5 | 15.0s |  |
| 402 | `stage_object_properties_swf6` | 231 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 403 | `stage_property_representation` | 586 | 15.0s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 404 | `stage_scale_mode` | 39 | 15.1s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 405 | `strictequals_swf6` | 902 | 16.5s |  |
| 406 | `strictly_equals` | 7 | 15.1s |  |
| 407 | `string_coercion` | 117 | 15.3s | [55](ruffle-tests/_investigation/complete/string_coercion.md) |
| 408 | `string_methods` | 285 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 409 | `string_methods_negative_args` | 240 | 15.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 410 | `string_methods_swfv5` | 275 | 15.7s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 411 | `string_ops_swf6` | 95 | 15.0s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 412 | `string_paths_basic` | 4 | 15.0s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 413 | `string_paths_eval2` | 7 | 17.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 414 | `string_paths_hidden` | 54 | 15.8s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 415 | `string_paths_other` | 36 | 15.8s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 416 | `string_paths_unload` | 1 | 15.6s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 417 | `string_paths_variable_alias` | 4 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 418 | `string_paths_variable_scopes` | 5 | 15.5s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 419 | `stylesheet` | 283 | 16.3s |  |
| 420 | `stylesheet_transform` | 750 | 16.3s |  |
| 421 | `super_edge_cases` | 39 | 15.9s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 422 | `swf4_actions_bool` | 96 | 15.7s |  |
| 423 | `swf4_actions_coercion_order` | 158 | 15.7s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 424 | `swf4_bool` | 4 | 15.5s |  |
| 425 | `swf4_function_calls` | 7 | 15.6s |  |
| 426 | `swf5_encoding` | 3 | 15.6s |  |
| 427 | `swf5_global_funcs` | 232 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 428 | `swf5_no_closure` | 19 | 15.7s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 429 | `swf5_to_6_cross_call` | 29 | 16.2s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 430 | `swf6_case_insensitive` | 42 | 15.6s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 431 | `swf6_global_funcs` | 232 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 432 | `swf6_string_as_bool` | 15 | 15.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 433 | `swf6_to_5_cross_call` | 29 | 15.6s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 434 | `swf7_case_sensitive` | 44 | 15.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 435 | `swf7_global_funcs` | 232 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 436 | `tab_ordering_automatic_basic` | 92 | 16.0s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 437 | `tab_ordering_automatic_order_grid` | 21 | 15.8s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 438 | `tab_ordering_automatic_order_same_position` | 12 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 439 | `tab_ordering_children` | 208 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 440 | `tab_ordering_custom_basic` | 71 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 441 | `tab_ordering_custom_duplicate_index` | 22 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 442 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 443 | `tab_ordering_custom_m1` | 29 | 15.8s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 444 | `tab_ordering_events` | 150 | 16.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 445 | `tab_ordering_events_mouse` | 65 | 16.0s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 446 | `tab_ordering_movieclip_enabled_default` | 462 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 447 | `tab_ordering_properties_tab_index_edge_case` | 4 | 16.6s |  |
| 448 | `tab_ordering_reverse` | 51 | 15.1s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 449 | `tab_ordering_tabbable` | 47 | 15.1s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 450 | `target_clip_removed` | 5 | 15.1s | [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 451 | `target_clip_swf5` | 2 | 15.1s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 452 | `target_clip_swf6` | 2 | 15.2s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 453 | `target_path` | 14 | 15.0s |  |
| 454 | `tell_target` | 37 | 15.0s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 455 | `tell_target_invalid` | 6 | 15.1s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 456 | `tell_target_invalid_swf6` | 5 | 15.0s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 457 | `text_format` | 1146 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 458 | `text_format_display` | 21 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 459 | `text_format_font_max_length` | 2 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 460 | `text_format_get_text_extent_undefined_width` | 10 | 15.1s |  |
| 461 | `text_format_rounding_swf7` | 840 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 462 | `text_format_rounding_swf8` | 840 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `textfield_background_color` | 11 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 464 | `textfield_border_color` | 11 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 465 | `textfield_cache_as_bitmap` | 1 | 15.1s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 466 | `textfield_maxchars` | 3 | 16.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `textfield_properties` | 44 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textfield_props_swf5` | 175 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `textfield_props_swf6` | 210 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 470 | `textfield_props_swf7` | 210 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 471 | `textfield_props_swf8` | 210 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 472 | `textfield_text` | 7 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 473 | `textfield_variable` | 81 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 474 | `textsnapshot_available_text` | 20 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 475 | `textsnapshot_findtext` | 44 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 476 | `textsnapshot_gettext` | 55 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 477 | `textsnapshot_props_swf5` | 56 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 478 | `textsnapshot_props_swf6` | 56 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 479 | `textsnapshot_text_order` | 1 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 480 | `this_scoping` | 52 | 15.2s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 481 | `this_swf5` | 41 | 15.4s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 482 | `this_swf6` | 41 | 15.3s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 483 | `this_swf7` | 41 | 15.2s | [65](ruffle-tests/_investigation/complete/this_swf7.md) |
| 484 | `timeline_function_def` | 7 | 15.3s |  |
| 485 | `timer_run_actions` | 18 | 17.4s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 486 | `trace` | 8 | 15.5s |  |
| 487 | `transform` | 70 | 15.6s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 488 | `try_catch_finally` | 118 | 15.7s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 489 | `try_finally_simple` | 16 | 15.5s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 490 | `typeof` | 22 | 15.6s |  |
| 491 | `typeof_globals` | 7 | 15.7s |  |
| 492 | `uncaught_exception` | 1 | 15.5s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 493 | `uncaught_exception_bubbled` | 1 | 15.6s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 494 | `undefined_to_string_swf6` | 4 | 15.6s |  |
| 495 | `unescape` | 43 | 15.5s |  |
| 496 | `unload` | 52 | 15.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 497 | `unload_clip_event` | 4 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 498 | `unloadmovie` | 4 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 499 | `unloadmovie_method` | 3 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 500 | `unloadmovienum` | 13 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 501 | `use_hand_cursor` | 8 | 15.5s |  |
| 502 | `variable_args` | 5 | 15.5s |  |
| 503 | `waitforframe` | 7 | 15.5s |  |
| 504 | `waitforframe2` | 16 | 16.9s |  |
| 505 | `watch` | 117 | 16.0s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 506 | `watch_textfield` | 12 | 15.6s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 507 | `watch_virtual_property_proto` | 2 | 16.0s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 508 | `with` | 49 | 15.8s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 509 | `with_return` | 2 | 15.6s |  |
| 510 | `with_variable_scopes` | 43 | 15.8s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 511 | `xml` | 15 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_append_child` | 28 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_append_child_with_parent` | 20 | 16.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_cdata` | 11 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_child_nodes_edge_cases` | 4 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_clone_expandos` | 19 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_first_last_child` | 8 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_has_child_nodes` | 3 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_idmap` | 21 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_ignore_comments` | 21 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_ignore_white` | 34 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_insert_before` | 20 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_inspect_createmethods` | 15 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_inspect_doctype` | 7 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_inspect_parsexml` | 62 | 15.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_inspect_xmldecl` | 7 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_namespaces` | 203 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_parent_and_child` | 5 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_remove_node` | 22 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_reparenting` | 14 | 15.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_siblings` | 10 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_to_string` | 13 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_to_string_comment` | 1 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_unescaping` | 23 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 535 | `xmlnode_proto` | 1 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `clone_sprite_edittext` | 95.7% | 90 | 94 | 4 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `clone_sprite_edittext_dynamic` | 90.7% | 78 | 86 | 8 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `string_paths_eval` | 75.0% | 3 | 4 | 1 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 9 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 10 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 12 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 | [60](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 13 | `issue_2030` | 50.0% | 2 | 4 | 2 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**30 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `clone_sprite_edittext` | 95.7% | 90/94 | 94 | 94 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `clone_sprite_edittext_dynamic` | 90.7% | 78/86 | 86 | 86 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `string_paths_eval` | 75.0% | 3/4 | 4 | 4 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 9 | `text_blocks_clicks` | 75.0% | 3/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 10 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 12 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 | [60](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 13 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 14 | `issue_2084` | 37.5% | 6/16 | 8 | 16 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 15 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 16 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 17 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 18 | `global_proto_decls` | 2.0% | 90/4497 | 1191 | 4497 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 19 | `global_instance_decls` | 0.4% | 3/758 | 694 | 758 | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 20 | `global_proto_decls_delete` | 0.3% | 14/4158 | 577 | 4158 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 21 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 22 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `geturl` | 0.0% | 0/7 | 0 | 7 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 25 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 26 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 27 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 28 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [69](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 29 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 30 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 3 | 3 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) | 8 | 8 | 0 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 6 | 2 |
| 9 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 10 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 11 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 12 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 13 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 14 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 15 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 16 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 17 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 18 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 19 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 20 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 21 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 22 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 5 | 4 | 1 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 29 | 26 | 3 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 28 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 30 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 43 | 40 | 3 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 3 | 3 | 0 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 36 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 55 | 48 | 7 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 42 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 44 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 45 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 46 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 47 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 48 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 49 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
| 50 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 51 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 52 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 53 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 54 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 55 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 56 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 12 | 11 | 1 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 0 | 1 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 17 | 16 | 1 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 69 | 65 | 4 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 2 | 0 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 11 | 1 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 26 | 25 | 1 |
| | *(tests not in any document)* | 150 | 150 | 0 |
