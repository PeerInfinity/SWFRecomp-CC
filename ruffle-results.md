# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-14 03:47 UTC

**Git SHA**: `6e238d4eae`

**Run Duration**: 158m 53s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 618 |
| Passing | **539** (87.2%) |
| Failing | 79 |
| Total expected lines | 91484 |
| Matching lines | 76649 (83.8%) |
| Mismatched lines | 14835 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 76 | 96.2% |
| Runtime Segfault | 2 | 2.5% |
| Timeout | 1 | 1.3% |

## Passing Tests

**539 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.2s |  |
| 2 | `action_to_integer` | 28 | 14.1s |  |
| 3 | `add` | 28 | 14.2s |  |
| 4 | `add2` | 354 | 14.3s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.4s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.4s |  |
| 7 | `add_swf5` | 28 | 14.3s |  |
| 8 | `arguments` | 127 | 14.0s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 14.1s |  |
| 11 | `array_constructor` | 30 | 14.1s |  |
| 12 | `array_enumerate` | 4 | 14.1s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.2s |  |
| 14 | `array_properties` | 36 | 14.3s |  |
| 15 | `array_prototyping` | 12 | 14.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 14.4s |  |
| 17 | `array_sort` | 161 | 15.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 14.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 15.0s |  |
| 20 | `array_trivial` | 209 | 15.0s |  |
| 21 | `as1_constructor_v6` | 35 | 14.9s |  |
| 22 | `as1_constructor_v7` | 35 | 14.9s |  |
| 23 | `as2_oop` | 13 | 15.0s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 14.9s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 15.1s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 15.1s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 14.6s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 14.7s |  |
| 29 | `as_broadcaster_undef` | 89 | 14.8s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 14.6s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 14.7s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 14.5s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 14.6s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 14.5s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 14.6s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 14.5s |  |
| 37 | `as_transformed_flag` | 20 | 14.5s |  |
| 38 | `asnative` | 34 | 14.4s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 14.7s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 14.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 14.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 15.1s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 14.9s |  |
| 44 | `bitand` | 1058 | 17.8s |  |
| 45 | `bitmap_data_colortransform` | 0 | 15.1s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_fillrect` | 0 | 15.0s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_max_size_swf10` | 12 | 14.8s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_max_size_swf9` | 10 | 14.8s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_perlinnoise` | 0 | 15.8s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 15.5s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.2s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) |
| 52 | `bitor` | 1058 | 17.9s |  |
| 53 | `biturshift` | 14 | 14.8s |  |
| 54 | `biturshift_swf8` | 14 | 16.8s |  |
| 55 | `bitxor` | 1058 | 17.9s |  |
| 56 | `boxed_primitives` | 24 | 15.1s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 14.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 15.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 15.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 15.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 15.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 15.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 15.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 14.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 14.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 14.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 15.1s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 14.8s |  |
| 71 | `capabilities_resolution` | 8 | 15.0s |  |
| 72 | `catch_references_registers` | 2 | 15.0s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 14.9s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 14.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 75 | `clip_event_propagation_order` | 17 | 17.8s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clip_events` | 19 | 15.0s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 77 | `clone_sprite_types` | 24 | 14.6s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `closure_scope` | 7 | 14.6s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 79 | `coerce_to_primitive_resolve` | 17 | 14.7s | [46](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 80 | `color` | 57 | 14.7s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `color_transform` | 48 | 14.6s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 82 | `conflicting_instance_names` | 23 | 14.6s |  |
| 83 | `constructor_function` | 2 | 14.7s |  |
| 84 | `context_menu` | 39 | 14.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `context_menu_item` | 41 | 14.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 86 | `create_empty_movie_clip` | 3 | 14.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `cross_movie_root` | 10 | 14.7s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 88 | `custom_clip_methods` | 4 | 14.6s | [12](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `default_names` | 52 | 14.6s | [14](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 90 | `define_function2` | 8 | 14.4s |  |
| 91 | `define_function2_preload` | 13 | 14.4s |  |
| 92 | `define_function2_preload_order` | 4 | 15.5s |  |
| 93 | `define_function_case_sensitive` | 2 | 15.2s |  |
| 94 | `define_local` | 27 | 15.1s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 95 | `define_local_with_paths` | 54 | 15.3s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 96 | `delete` | 3 | 15.3s |  |
| 97 | `device_font_spacing` | 91 | 15.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 98 | `display_object_properties` | 2 | 15.2s |  |
| 99 | `divide_swf4` | 107 | 15.2s |  |
| 100 | `do_init_action` | 3 | 15.0s |  |
| 101 | `do_init_action_child` | 12 | 15.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 102 | `drag_drop` | 10 | 15.0s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `drag_over_from_outside` | 1 | 15.1s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 104 | `drag_over_without_startdrag` | 1 | 15.2s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 105 | `duplicate_movie_clip` | 20 | 15.2s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `duplicate_movie_clip_drawing` | 2 | 15.0s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 107 | `edittext_align` | 60 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_align_trailing_spaces_swf7` | 576 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_align_trailing_spaces_swf8` | 576 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_antialiastype` | 296 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_autosize` | 71 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_autosize_setter` | 20 | 17.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_default_format` | 221 | 16.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_default_format_font_style` | 335 | 16.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_focus_selection` | 2 | 15.8s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_font_size` | 45 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_hscroll` | 27 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_align_swf7` | 52 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_align_swf8` | 52 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_color` | 114 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_condensewhite_swf7` | 311 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_condensewhite_swf8` | 311 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_entity` | 4 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_roundtrip` | 17 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_swf7` | 5377 | 16.8s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_html_swf8` | 5377 | 17.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_input` | 1 | 16.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_input_newlines` | 9 | 16.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_leading` | 9 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_letter_spacing` | 15 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_margins` | 25 | 15.8s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_newline_stripping` | 64 | 21.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_newlines` | 30 | 16.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_password` | 5 | 15.8s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_password_copy` | 4 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_paste_empty` | 2 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_place_caret` | 2 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_programmatic_focus` | 12 | 15.2s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_restrict` | 191 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_restrict_paste` | 5 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_scroll` | 54 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_stylesheet` | 325 | 16.1s | [57](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_tab_focus` | 13 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_tab_stops` | 60 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_tag_indent` | 31 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_text_height_leading` | 20 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `edittext_underline` | 40 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 148 | `edittext_width_height` | 103 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 149 | `empty_movieclip_can_attach_movies` | 11 | 17.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 150 | `enumerate` | 64 | 16.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 151 | `equals` | 32 | 16.1s |  |
| 152 | `equals2_swf5` | 926 | 17.9s |  |
| 153 | `equals2_swf6` | 926 | 17.8s |  |
| 154 | `equals2_swf7` | 926 | 17.8s |  |
| 155 | `equals_swf4` | 665 | 16.4s |  |
| 156 | `equals_swf4_alt` | 32 | 15.9s |  |
| 157 | `equals_swf5` | 32 | 15.8s |  |
| 158 | `error` | 58 | 15.8s |  |
| 159 | `escape` | 14 | 15.7s |  |
| 160 | `execution_order1` | 5 | 15.9s |  |
| 161 | `execution_order2` | 7 | 15.6s |  |
| 162 | `execution_order3` | 4 | 15.3s |  |
| 163 | `execution_order4` | 12 | 15.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 164 | `export_assets` | 3 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 165 | `extends_chain` | 134 | 15.9s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `extends_native_type` | 11 | 16.1s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 167 | `external_interface` | 84 | 16.6s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_escapexml` | 26 | 16.9s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_jsquotestring` | 21 | 17.5s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_toas_basic` | 354 | 15.4s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_toxml_array` | 25 | 14.8s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `external_interface_toxml_basic` | 179 | 15.0s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 173 | `external_interface_unescapexml` | 40 | 14.8s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 174 | `focus_keyboard_press` | 60 | 15.0s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focus_mouse` | 45 | 15.0s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_mouse_focusable` | 8 | 15.3s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 177 | `focus_mouse_rollout` | 4 | 14.6s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 178 | `focus_remove` | 33 | 14.5s |  |
| 179 | `focus_root_movie` | 2 | 14.8s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 180 | `focus_visibility_change` | 45 | 14.8s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 181 | `focusrect_focuslost` | 4 | 14.8s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 182 | `focusrect_mouse_swf8` | 0 | 14.8s |  |
| 183 | `focusrect_mouse_swf9` | 0 | 16.1s |  |
| 184 | `focusrect_property_swf5` | 1237 | 14.8s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 185 | `focusrect_property_swf6` | 1237 | 14.7s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 186 | `focusrect_property_swf7` | 1237 | 14.6s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 187 | `focusrect_swf5` | 6 | 14.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 188 | `focusrect_swf6` | 42 | 14.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 189 | `form_loader_encoding_1` | 1 | 14.4s |  |
| 190 | `frame_size_translated_negative` | 21 | 14.5s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 191 | `frame_size_translated_positive` | 21 | 14.5s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 192 | `function_as_function` | 35 | 14.5s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 193 | `function_base_clip` | 8 | 14.5s |  |
| 194 | `function_base_clip_readded` | 11 | 14.5s |  |
| 195 | `function_base_clip_removed` | 25 | 14.5s |  |
| 196 | `function_suppress_and_preload` | 28 | 14.5s |  |
| 197 | `funky_function_calls` | 56 | 14.6s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 198 | `get_bytes_total` | 4 | 14.4s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 199 | `get_variable_in_scope` | 29 | 14.5s |  |
| 200 | `getproperty` | 28 | 14.4s |  |
| 201 | `getproperty_swf4` | 28 | 15.1s |  |
| 202 | `getproperty_swf5` | 28 | 14.6s |  |
| 203 | `gettextextent` | 56 | 14.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 204 | `global_array` | 3 | 14.4s |  |
| 205 | `global_is_bare` | 7 | 14.5s |  |
| 206 | `global_swf5_6_7_8_9` | 1145 | 15.1s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 207 | `global_swf6_7_8` | 15 | 14.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 208 | `globals_swf5` | 304 | 14.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 209 | `globals_swf6` | 304 | 14.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 210 | `globals_swf7` | 304 | 14.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 211 | `globals_swf8` | 304 | 14.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 212 | `goto_advance1` | 6 | 14.6s |  |
| 213 | `goto_advance2` | 2 | 14.5s |  |
| 214 | `goto_both_ways1` | 3 | 14.6s |  |
| 215 | `goto_both_ways2` | 3 | 14.6s |  |
| 216 | `goto_execution_order` | 2 | 14.5s |  |
| 217 | `goto_execution_order2` | 2 | 14.6s |  |
| 218 | `goto_frame` | 12 | 16.0s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 219 | `goto_frame2` | 44 | 15.8s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 220 | `goto_frame_number` | 3 | 14.8s |  |
| 221 | `goto_label` | 17 | 14.9s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 222 | `goto_methods` | 40 | 14.9s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 223 | `goto_rewind1` | 1 | 14.7s |  |
| 224 | `goto_rewind2` | 3 | 15.4s |  |
| 225 | `goto_rewind3` | 2 | 15.0s |  |
| 226 | `greater_swf6` | 1175 | 17.2s |  |
| 227 | `greater_swf7` | 1175 | 17.0s |  |
| 228 | `greaterthan_swf5` | 1 | 15.3s |  |
| 229 | `greaterthan_swf8` | 1 | 15.1s |  |
| 230 | `has_own_property` | 32 | 15.4s |  |
| 231 | `hittest_lockroot` | 15 | 15.7s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 232 | `hittest_morph` | 70 | 15.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 233 | `hittest_winding_rule` | 12 | 15.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 234 | `infinite_recursion_function` | 4 | 15.1s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 235 | `infinite_recursion_function_in_setter` | 131 | 14.9s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 236 | `infinite_recursion_virtual_property` | 67 | 14.9s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 237 | `init_array_invalid` | 4 | 14.9s |  |
| 238 | `init_object_invalid` | 4 | 16.4s |  |
| 239 | `init_object_order` | 15 | 14.6s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 240 | `input_dead_keys_windows` | 15 | 14.7s | [29](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 241 | `instanceof_coercions` | 88 | 14.9s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 242 | `interface_implements_op` | 47 | 15.0s | [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 243 | `is_finite` | 49 | 14.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 244 | `is_finite_swf6` | 49 | 14.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 245 | `is_prototype_of` | 89 | 14.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 246 | `issue_1086` | 1 | 14.4s |  |
| 247 | `issue_1104` | 2 | 14.5s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 248 | `issue_1671` | 0 | 14.4s |  |
| 249 | `issue_1906` | 4 | 14.5s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 250 | `issue_2166` | 9 | 14.5s |  |
| 251 | `issue_2870` | 3 | 14.6s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 252 | `issue_3169` | 2 | 14.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 253 | `issue_3446` | 1 | 14.5s |  |
| 254 | `issue_3522` | 2 | 14.5s |  |
| 255 | `issue_4377` | 2 | 14.7s |  |
| 256 | `issue_710` | 4 | 14.8s |  |
| 257 | `issue_768` | 3 | 15.8s | [30](ruffle-tests/_investigation/complete/issue_768.md) |
| 258 | `issue_9327` | 2 | 14.7s |  |
| 259 | `issue_9885` | 2 | 14.9s |  |
| 260 | `key_isToggled` | 9 | 14.8s |  |
| 261 | `lessthan` | 41 | 14.8s |  |
| 262 | `lessthan2_swf5` | 1226 | 16.5s |  |
| 263 | `lessthan2_swf6` | 1226 | 16.7s |  |
| 264 | `lessthan2_swf7` | 1226 | 16.6s |  |
| 265 | `lessthan_swf4` | 902 | 15.8s |  |
| 266 | `lessthan_swf4_alt` | 41 | 15.5s |  |
| 267 | `lessthan_swf5` | 41 | 15.5s |  |
| 268 | `loadmovie` | 2 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 269 | `loadmovie_fail` | 2 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 270 | `loadmovie_flashvars` | 4 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 271 | `loadmovie_method` | 2 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 272 | `loadmovie_registerclass` | 30 | 15.0s | [11](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 273 | `loadmovie_replace_root` | 5 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 274 | `loadmovie_var_persistence` | 8 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 275 | `loadmovienum` | 3 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 276 | `loadmovienum_cross_version_prototype` | 9 | 14.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 277 | `loadvariables` | 2 | 17.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 278 | `loadvariables2` | 8 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 279 | `loadvariablesnum` | 2 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 280 | `local_to_global` | 49 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 281 | `localconnection_properties` | 8 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 282 | `lock_root` | 1 | 15.6s |  |
| 283 | `logical_ops_swf4` | 90 | 15.3s |  |
| 284 | `logical_ops_swf8` | 108 | 15.2s |  |
| 285 | `looping` | 6 | 14.8s |  |
| 286 | `mask_reapply` | 0 | 14.9s |  |
| 287 | `mask_with_drawing` | 0 | 15.0s |  |
| 288 | `math_min_max` | 101 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 289 | `math_swf6` | 530 | 15.7s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 290 | `math_swf7` | 530 | 15.5s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 291 | `math_swf8` | 530 | 15.5s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 292 | `matrix` | 171 | 15.3s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 293 | `mcl_as_broadcaster` | 12 | 14.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 294 | `mcl_events_swf_version` | 232 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 295 | `mcl_getprogress` | 30 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_loadclip` | 149 | 15.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 297 | `mcl_loadclip_properties` | 6 | 14.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_loadclip_replace_root` | 1 | 14.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 299 | `mcl_mislabeled_target` | 6 | 14.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 300 | `mcl_target_gif87a` | 6 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 301 | `mcl_target_gif89a` | 6 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 302 | `mcl_target_jpg` | 6 | 15.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 303 | `mcl_target_png` | 6 | 14.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 304 | `mcl_unloadclip` | 5 | 14.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mouse_events` | 8 | 14.8s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 306 | `mouse_events_visible_enabled` | 12 | 14.9s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 307 | `mouse_hover_events_while_dragging` | 1 | 14.7s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 308 | `mouse_listeners` | 67 | 14.9s |  |
| 309 | `mouse_pos` | 665 | 14.6s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 310 | `mouse_pos_with_scale_factor` | 260 | 14.7s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 311 | `mouse_wheel_enabled` | 2 | 14.8s |  |
| 312 | `movieclip_begin_gradient_fill` | 0 | 15.2s |  |
| 313 | `movieclip_blend_mode_property` | 35 | 14.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_create_text_field` | 90 | 14.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 315 | `movieclip_default_state` | 69 | 16.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 316 | `movieclip_depth_methods` | 98 | 15.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 317 | `movieclip_focusenabled` | 99 | 15.3s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 318 | `movieclip_get_instance_at_depth` | 28 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_getbounds` | 191 | 15.6s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_gettextsnapshot` | 112 | 15.7s | [24](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 321 | `movieclip_hittest` | 92 | 15.3s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 322 | `movieclip_in_removed_button` | 4 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 323 | `movieclip_init_object` | 5 | 15.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 324 | `movieclip_invalid_get_bounds_1` | 75 | 15.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_invalid_get_bounds_2` | 75 | 15.7s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_invalid_get_bounds_3` | 13 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_invalid_get_bounds_4` | 13 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_invalid_get_bounds_5` | 11 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_invalid_get_bounds_8` | 11 | 15.5s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_line_gradient_style` | 0 | 15.9s |  |
| 331 | `movieclip_lockroot` | 29 | 15.8s | [35](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_name_from_timeline` | 13 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 333 | `movieclip_prototype_extension` | 5 | 15.8s |  |
| 334 | `movieclip_setmask` | 14 | 15.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 335 | `moviecliploader_flashvars` | 4 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 336 | `mutable_this` | 18 | 15.7s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 337 | `named_shapes` | 14 | 15.7s |  |
| 338 | `nan_scale` | 9 | 15.9s |  |
| 339 | `native_double_construct` | 12 | 15.8s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 340 | `native_objects_swf7` | 84 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 341 | `native_objects_swf8` | 84 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 342 | `native_subclasses` | 191 | 15.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 343 | `nested_textfields_in_buttons` | 0 | 15.2s |  |
| 344 | `new_method_wrap` | 4 | 15.0s |  |
| 345 | `new_object_enumerate` | 7 | 14.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 346 | `new_object_wrap` | 4 | 14.5s |  |
| 347 | `o` | 3 | 14.5s |  |
| 348 | `object_constructor` | 33 | 14.5s |  |
| 349 | `object_function` | 32 | 14.8s |  |
| 350 | `object_properties` | 31 | 14.9s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 351 | `object_prototypes` | 74 | 14.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 352 | `object_resolve` | 38 | 14.8s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 353 | `object_string_coerce_swf5` | 62 | 14.8s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 354 | `object_string_coerce_swf6` | 68 | 14.8s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 355 | `on_construct` | 25 | 14.9s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 356 | `parse_float` | 74 | 14.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 357 | `parse_int` | 64 | 15.1s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 358 | `path_string` | 322 | 15.1s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 359 | `place_and_lookup` | 30 | 14.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 360 | `placeobject_occupied_depth` | 6 | 14.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 361 | `point` | 175 | 15.2s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 362 | `primitive_instanceof` | 37 | 14.7s |  |
| 363 | `primitive_type_globals` | 557 | 15.0s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 364 | `printjob_props_swf5` | 45 | 19.0s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 365 | `printjob_props_swf6` | 45 | 14.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 366 | `printjob_props_swf7` | 45 | 14.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 367 | `property_invalid_base_clip` | 36 | 14.8s |  |
| 368 | `prototype_delete` | 12 | 15.2s |  |
| 369 | `prototype_enumerate` | 5 | 15.0s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 370 | `prototype_properties` | 17 | 15.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 371 | `rectangle` | 745 | 15.8s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 372 | `recursive_prototypes` | 0 | 15.0s |  |
| 373 | `register_and_init_order` | 231 | 15.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 374 | `register_class` | 66 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 375 | `register_class_return_value` | 16 | 15.0s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 376 | `register_class_swf6` | 37 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 377 | `register_class_with_sound` | 11 | 14.9s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 378 | `register_globals_across_frames` | 15 | 14.8s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 379 | `register_underflow` | 26 | 14.8s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 380 | `remove_movie_clip` | 29 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 381 | `removed_clip_halts_script` | 15 | 15.0s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 382 | `removed_target_clip_scope` | 35 | 14.8s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 383 | `resolve_different_root` | 2 | 16.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 384 | `rewind_depth` | 30 | 16.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 385 | `root_button_mode` | 10 | 16.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 386 | `root_global_parent` | 6 | 16.1s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 387 | `root_onload` | 1 | 16.1s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 388 | `sandbox_type_local_file` | 1 | 16.1s |  |
| 389 | `sandbox_type_local_network` | 1 | 16.6s |  |
| 390 | `selection` | 454 | 16.6s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 391 | `selection_handlers` | 27 | 16.4s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 392 | `set_interval` | 27 | 17.2s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 393 | `set_variable_scope` | 58 | 16.9s |  |
| 394 | `single_frame` | 1 | 16.8s |  |
| 395 | `slash_syntax` | 14 | 17.0s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 396 | `sound` | 628 | 16.6s | [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 397 | `sound_props_swf5` | 68 | 16.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 398 | `sound_props_swf6` | 68 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 399 | `sound_start_load` | 0 | 15.4s |  |
| 400 | `stage_display_state` | 16 | 15.6s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 401 | `stage_object_children` | 83 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 402 | `stage_object_enumerate` | 4 | 15.1s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 403 | `stage_object_properties` | 241 | 15.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 404 | `stage_object_properties_get_var` | 5 | 15.4s |  |
| 405 | `stage_object_properties_swf6` | 231 | 15.6s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 406 | `stage_property_representation` | 586 | 15.4s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 407 | `stage_scale_mode` | 39 | 15.6s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 408 | `strictequals_swf6` | 902 | 16.9s |  |
| 409 | `strictly_equals` | 7 | 15.6s |  |
| 410 | `string_coercion` | 117 | 16.0s | [55](ruffle-tests/_investigation/complete/string_coercion.md) |
| 411 | `string_methods` | 285 | 16.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 412 | `string_methods_negative_args` | 240 | 15.4s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 413 | `string_methods_swfv5` | 275 | 16.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 414 | `string_ops_swf6` | 95 | 15.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 415 | `string_paths_basic` | 4 | 15.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 416 | `string_paths_eval2` | 7 | 15.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 417 | `string_paths_hidden` | 54 | 14.8s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 418 | `string_paths_other` | 36 | 15.0s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 419 | `string_paths_unload` | 1 | 14.8s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 420 | `string_paths_variable_alias` | 4 | 14.7s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 421 | `string_paths_variable_scopes` | 5 | 14.6s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 422 | `stylesheet` | 283 | 15.4s |  |
| 423 | `stylesheet_transform` | 750 | 15.7s |  |
| 424 | `super_edge_cases` | 39 | 14.8s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 425 | `swf4_actions_bool` | 96 | 14.8s |  |
| 426 | `swf4_actions_coercion_order` | 158 | 14.8s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 427 | `swf4_bool` | 4 | 14.6s |  |
| 428 | `swf4_function_calls` | 7 | 14.7s |  |
| 429 | `swf5_encoding` | 3 | 14.8s |  |
| 430 | `swf5_global_funcs` | 232 | 14.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 431 | `swf5_no_closure` | 19 | 14.8s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 432 | `swf5_to_6_cross_call` | 29 | 14.7s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 433 | `swf6_case_insensitive` | 42 | 14.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 434 | `swf6_global_funcs` | 232 | 14.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 435 | `swf6_string_as_bool` | 15 | 14.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 436 | `swf6_to_5_cross_call` | 29 | 14.5s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 437 | `swf7_case_sensitive` | 44 | 14.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 438 | `swf7_global_funcs` | 232 | 14.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 439 | `tab_ordering_automatic_basic` | 92 | 14.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 440 | `tab_ordering_automatic_order_grid` | 21 | 14.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 441 | `tab_ordering_automatic_order_same_position` | 12 | 14.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 442 | `tab_ordering_children` | 208 | 14.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 443 | `tab_ordering_custom_basic` | 71 | 14.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 444 | `tab_ordering_custom_duplicate_index` | 22 | 14.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 445 | `tab_ordering_custom_i32_vs_u32` | 12 | 14.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 446 | `tab_ordering_custom_m1` | 29 | 14.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 447 | `tab_ordering_events` | 150 | 14.8s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 448 | `tab_ordering_events_mouse` | 65 | 14.8s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 449 | `tab_ordering_movieclip_enabled_default` | 462 | 14.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 450 | `tab_ordering_properties_tab_index_edge_case` | 4 | 16.1s |  |
| 451 | `tab_ordering_reverse` | 51 | 14.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 452 | `tab_ordering_tabbable` | 47 | 14.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 453 | `target_clip_removed` | 5 | 14.7s | [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 454 | `target_clip_swf5` | 2 | 14.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 455 | `target_clip_swf6` | 2 | 14.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 456 | `target_path` | 14 | 14.5s |  |
| 457 | `tell_target` | 37 | 14.7s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 458 | `tell_target_invalid` | 6 | 14.8s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 459 | `tell_target_invalid_swf6` | 5 | 14.8s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 460 | `text_format` | 1146 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 461 | `text_format_display` | 21 | 14.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 462 | `text_format_font_max_length` | 2 | 14.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `text_format_get_text_extent_undefined_width` | 10 | 14.7s |  |
| 464 | `text_format_rounding_swf7` | 840 | 14.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 465 | `text_format_rounding_swf8` | 840 | 14.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 466 | `textfield_background_color` | 11 | 14.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `textfield_border_color` | 11 | 14.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textfield_cache_as_bitmap` | 1 | 14.8s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `textfield_maxchars` | 3 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 470 | `textfield_properties` | 44 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 471 | `textfield_props_swf5` | 175 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 472 | `textfield_props_swf6` | 210 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 473 | `textfield_props_swf7` | 210 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 474 | `textfield_props_swf8` | 210 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 475 | `textfield_text` | 7 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 476 | `textfield_variable` | 81 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 477 | `textsnapshot_available_text` | 20 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 478 | `textsnapshot_findtext` | 44 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 479 | `textsnapshot_gettext` | 55 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 480 | `textsnapshot_props_swf5` | 56 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 481 | `textsnapshot_props_swf6` | 56 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 482 | `textsnapshot_text_order` | 1 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 483 | `this_scoping` | 52 | 15.2s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 484 | `this_swf5` | 41 | 15.2s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 485 | `this_swf6` | 41 | 15.2s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 486 | `this_swf7` | 41 | 15.2s | [65](ruffle-tests/_investigation/complete/this_swf7.md) |
| 487 | `timeline_function_def` | 7 | 15.2s |  |
| 488 | `timer_run_actions` | 18 | 15.0s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 489 | `trace` | 8 | 14.6s |  |
| 490 | `transform` | 70 | 14.8s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 491 | `try_catch_finally` | 118 | 14.7s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 492 | `try_finally_simple` | 16 | 14.6s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 493 | `typeof` | 22 | 14.7s |  |
| 494 | `typeof_globals` | 7 | 14.6s |  |
| 495 | `uncaught_exception` | 1 | 14.5s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 496 | `uncaught_exception_bubbled` | 1 | 14.6s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 497 | `undefined_to_string_swf6` | 4 | 14.6s |  |
| 498 | `unescape` | 43 | 14.6s |  |
| 499 | `unload` | 52 | 14.8s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 500 | `unload_clip_event` | 4 | 14.7s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 501 | `unloadmovie` | 4 | 14.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 502 | `unloadmovie_method` | 3 | 14.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 503 | `unloadmovienum` | 13 | 14.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 504 | `use_hand_cursor` | 8 | 14.7s |  |
| 505 | `variable_args` | 5 | 14.8s |  |
| 506 | `waitforframe` | 7 | 14.6s |  |
| 507 | `waitforframe2` | 16 | 17.4s |  |
| 508 | `watch` | 117 | 15.2s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 509 | `watch_textfield` | 12 | 14.9s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 510 | `watch_virtual_property_proto` | 2 | 15.0s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 511 | `with` | 49 | 15.0s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 512 | `with_return` | 2 | 14.8s |  |
| 513 | `with_variable_scopes` | 43 | 15.2s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 514 | `xml` | 15 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_append_child` | 28 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_append_child_with_parent` | 20 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_attributes_read` | 4 | 14.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_cdata` | 11 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_child_nodes_edge_cases` | 4 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_clone_expandos` | 19 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_first_last_child` | 8 | 15.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_has_child_nodes` | 3 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_idmap` | 21 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_ignore_comments` | 21 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_ignore_white` | 34 | 14.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_insert_before` | 20 | 14.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_inspect_createmethods` | 15 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_inspect_doctype` | 7 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_inspect_parsexml` | 62 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_inspect_xmldecl` | 7 | 14.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_namespaces` | 203 | 14.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_parent_and_child` | 5 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_remove_node` | 22 | 14.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_reparenting` | 14 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 535 | `xml_siblings` | 10 | 14.7s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 536 | `xml_to_string` | 13 | 14.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 537 | `xml_to_string_comment` | 1 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 538 | `xml_unescaping` | 23 | 15.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 539 | `xmlnode_proto` | 1 | 15.7s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**24 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [13](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `clone_sprite_edittext` | 95.7% | 90 | 94 | 4 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `clone_sprite_edittext_dynamic` | 90.7% | 78 | 86 | 8 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `string_paths_eval` | 75.0% | 3 | 4 | 1 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 16 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 18 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 19 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 20 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 21 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 22 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 23 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 | [60](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 24 | `issue_2030` | 50.0% | 2 | 4 | 2 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 18.5s | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 34.4s | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 45.0s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**76 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [13](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `clone_sprite_edittext` | 95.7% | 90/94 | 94 | 94 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `clone_sprite_edittext_dynamic` | 90.7% | 78/86 | 86 | 86 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `string_paths_eval` | 75.0% | 3/4 | 4 | 4 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `text_blocks_clicks` | 75.0% | 3/4 | 4 | 4 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 16 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 18 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 19 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 20 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 21 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 22 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 23 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 | [60](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 24 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 25 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 26 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 27 | `issue_2084` | 37.5% | 6/16 | 8 | 16 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 28 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 29 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 31 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 32 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 33 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 34 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 35 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 36 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 37 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 38 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 39 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 40 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 41 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 42 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 | [5](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 43 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 44 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 45 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 46 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 47 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 48 | `global_proto_decls` | 2.1% | 96/4497 | 1163 | 4497 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 49 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 50 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 51 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 52 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 53 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 54 | `global_proto_decls_delete` | 0.4% | 18/4158 | 573 | 4158 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 55 | `global_instance_decls` | 0.4% | 3/758 | 596 | 758 | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 56 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 57 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 58 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 59 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 60 | `geturl` | 0.0% | 0/7 | 0 | 7 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 61 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 62 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 63 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 64 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 65 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 66 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 67 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 68 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 69 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 70 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 71 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 72 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 73 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 74 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 75 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 76 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/_investigation/incomplete/BITMAP_DATA_PLAN.md) | 17 | 8 | 9 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 6 | 2 |
| 9 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 10 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 11 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 12 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 13 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 14 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 15 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 16 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 17 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 18 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 19 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 20 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 21 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 22 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 27 | 4 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 29 | 0 | 29 |
| 28 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 30 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 40 | 8 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 36 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 48 | 10 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 42 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 44 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 45 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 46 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 47 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 48 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 49 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 50 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 51 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 52 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 53 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 54 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 55 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 56 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 0 | 1 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 16 | 3 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 65 | 5 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 11 | 1 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 151 | 151 | 0 |
