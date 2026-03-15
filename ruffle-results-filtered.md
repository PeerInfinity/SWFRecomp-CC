# Ruffle Test Results (Filtered)

**Date**: 2026-03-15 01:28 UTC

**Git SHA**: `d08f9a3898`

**Run Duration**: 164m 5s

**Filtered**: 54 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 565 |
| Passing | **540** (95.6%) |
| Failing | 25 |
| Total expected lines | 79012 |
| Matching lines | 69080 (87.4%) |
| Mismatched lines | 9932 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 25 | 100.0% |

## Passing Tests

**540 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 17.3s |  |
| 2 | `action_to_integer` | 28 | 15.7s |  |
| 3 | `add` | 28 | 15.9s |  |
| 4 | `add2` | 354 | 16.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.7s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.9s |  |
| 7 | `add_swf5` | 28 | 15.9s |  |
| 8 | `arguments` | 127 | 16.1s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 15.7s |  |
| 11 | `array_constructor` | 30 | 16.3s |  |
| 12 | `array_enumerate` | 4 | 16.1s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 15.9s |  |
| 14 | `array_properties` | 36 | 16.3s |  |
| 15 | `array_prototyping` | 12 | 15.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.8s |  |
| 17 | `array_sort_random` | 443 | 16.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 16.1s |  |
| 19 | `array_trivial` | 209 | 16.3s |  |
| 20 | `as1_constructor_v6` | 35 | 16.4s |  |
| 21 | `as1_constructor_v7` | 35 | 16.7s |  |
| 22 | `as2_oop` | 13 | 16.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 16.7s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 16.5s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 16.7s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 16.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 16.4s |  |
| 28 | `as_broadcaster_undef` | 89 | 16.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 16.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 16.6s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 16.4s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 16.3s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 16.6s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 16.4s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 16.6s |  |
| 36 | `as_transformed_flag` | 20 | 16.4s |  |
| 37 | `asnative` | 34 | 16.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 16.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 16.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 16.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 17.4s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 15.6s |  |
| 43 | `bitand` | 1058 | 18.2s |  |
| 44 | `bitmap_data_colortransform` | 0 | 15.7s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 45 | `bitmap_data_fillrect` | 0 | 15.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_max_size_swf10` | 12 | 15.7s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_max_size_swf9` | 10 | 15.7s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_perlinnoise` | 0 | 16.5s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 16.0s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 51 | `bitor` | 1058 | 18.1s |  |
| 52 | `biturshift` | 14 | 15.6s |  |
| 53 | `biturshift_swf8` | 14 | 15.2s |  |
| 54 | `bitxor` | 1058 | 17.9s |  |
| 55 | `boxed_primitives` | 24 | 15.3s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_key_events` | 14 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events_special` | 45 | 16.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_keypress` | 3 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_press` | 25 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_tab` | 20 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_textinput` | 4 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_order` | 2 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_properties_special_cases` | 22 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_v5` | 18 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v6` | 18 | 15.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `call` | 63 | 15.4s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 69 | `call_method_empty_name` | 1 | 15.1s |  |
| 70 | `capabilities_resolution` | 8 | 15.1s |  |
| 71 | `catch_references_registers` | 2 | 15.1s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 72 | `click_block` | 5 | 15.2s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 73 | `clip_constructors` | 8 | 15.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 74 | `clip_event_propagation_order` | 17 | 15.3s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `clip_events` | 19 | 15.5s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 15.1s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 15.1s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 17 | 15.5s | [46](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `color` | 57 | 15.5s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `color_transform` | 48 | 15.8s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `conflicting_instance_names` | 23 | 15.8s |  |
| 82 | `constructor_function` | 2 | 16.2s |  |
| 83 | `context_menu` | 39 | 16.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `context_menu_item` | 41 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `create_empty_movie_clip` | 3 | 15.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `cross_movie_root` | 10 | 16.3s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 87 | `custom_clip_methods` | 4 | 15.8s | [12](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `default_names` | 52 | 15.5s | [14](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `define_function2` | 8 | 15.3s |  |
| 90 | `define_function2_preload` | 13 | 16.4s |  |
| 91 | `define_function2_preload_order` | 4 | 15.1s |  |
| 92 | `define_function_case_sensitive` | 2 | 15.2s |  |
| 93 | `define_local` | 27 | 15.1s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 94 | `define_local_with_paths` | 54 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `delete` | 3 | 15.2s |  |
| 96 | `device_font_spacing` | 91 | 15.3s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 97 | `display_object_properties` | 2 | 15.3s |  |
| 98 | `divide_swf4` | 107 | 15.4s |  |
| 99 | `do_init_action` | 3 | 15.2s |  |
| 100 | `do_init_action_child` | 12 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 101 | `drag_drop` | 10 | 15.2s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_from_outside` | 1 | 15.2s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `drag_over_without_startdrag` | 1 | 15.3s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 104 | `duplicate_movie_clip` | 20 | 15.3s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `duplicate_movie_clip_drawing` | 2 | 15.2s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `edittext_align` | 60 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf7` | 576 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_align_trailing_spaces_swf8` | 576 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_antialiastype` | 296 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize` | 71 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_autosize_setter` | 20 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_bullet` | 30 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_default_format` | 221 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_default_format_font_style` | 335 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_focus_selection` | 2 | 15.3s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_font_size` | 45 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_hscroll` | 27 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_align_swf7` | 52 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_align_swf8` | 52 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_color` | 114 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_condensewhite_swf7` | 311 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_condensewhite_swf8` | 311 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_entity` | 4 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_roundtrip` | 17 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_swf6` | 5377 | 16.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_html_swf7` | 5377 | 16.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_html_swf8` | 5377 | 16.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_input` | 1 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_input_newlines` | 9 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_leading` | 9 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_letter_spacing` | 15 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_margins` | 25 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_newline_stripping` | 64 | 19.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_newlines` | 30 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_password` | 5 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_password_copy` | 4 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_paste_empty` | 2 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_place_caret` | 2 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_programmatic_focus` | 12 | 15.1s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_restrict` | 191 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_restrict_paste` | 5 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_scroll` | 54 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_stylesheet` | 325 | 15.8s | [57](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_tab_focus` | 13 | 15.0s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_tab_stops` | 60 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_tag_indent` | 31 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `edittext_text_height_leading` | 20 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 148 | `edittext_underline` | 40 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 149 | `edittext_width_height` | 103 | 17.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 150 | `empty_movieclip_can_attach_movies` | 11 | 15.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 151 | `enumerate` | 64 | 15.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 152 | `equals` | 32 | 15.5s |  |
| 153 | `equals2_swf5` | 926 | 17.3s |  |
| 154 | `equals2_swf6` | 926 | 17.4s |  |
| 155 | `equals2_swf7` | 926 | 17.2s |  |
| 156 | `equals_swf4` | 665 | 16.3s |  |
| 157 | `equals_swf4_alt` | 32 | 15.5s |  |
| 158 | `equals_swf5` | 32 | 15.6s |  |
| 159 | `error` | 58 | 15.5s |  |
| 160 | `escape` | 14 | 15.9s |  |
| 161 | `execution_order1` | 5 | 15.7s |  |
| 162 | `execution_order2` | 7 | 16.1s |  |
| 163 | `execution_order3` | 4 | 15.5s |  |
| 164 | `execution_order4` | 12 | 15.8s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 165 | `export_assets` | 3 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 166 | `extends_chain` | 134 | 15.9s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 167 | `extends_native_type` | 11 | 15.8s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 168 | `external_interface` | 84 | 15.9s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_escapexml` | 26 | 15.8s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_jsquotestring` | 21 | 16.3s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_toas_basic` | 354 | 16.0s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `external_interface_toxml_array` | 25 | 15.6s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 173 | `external_interface_toxml_basic` | 179 | 15.8s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 174 | `external_interface_unescapexml` | 40 | 15.7s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 175 | `focus_keyboard_press` | 60 | 15.7s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_mouse` | 45 | 15.6s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 177 | `focus_mouse_focusable` | 8 | 16.0s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 178 | `focus_mouse_rollout` | 4 | 15.8s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 179 | `focus_remove` | 33 | 15.6s |  |
| 180 | `focus_root_movie` | 2 | 15.6s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 181 | `focus_visibility_change` | 45 | 15.5s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 182 | `focusrect_focuslost` | 4 | 15.7s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 183 | `focusrect_mouse_swf8` | 0 | 15.7s |  |
| 184 | `focusrect_mouse_swf9` | 0 | 15.5s |  |
| 185 | `focusrect_property_swf5` | 1237 | 15.8s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 186 | `focusrect_property_swf6` | 1237 | 15.7s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 187 | `focusrect_property_swf7` | 1237 | 15.7s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 188 | `focusrect_swf5` | 6 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 189 | `focusrect_swf6` | 42 | 15.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 190 | `frame_size_translated_negative` | 21 | 15.5s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 191 | `frame_size_translated_positive` | 21 | 15.4s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 192 | `function_as_function` | 35 | 15.4s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 193 | `function_base_clip` | 8 | 15.5s |  |
| 194 | `function_base_clip_readded` | 11 | 15.5s |  |
| 195 | `function_base_clip_removed` | 25 | 15.5s |  |
| 196 | `function_suppress_and_preload` | 28 | 15.6s |  |
| 197 | `funky_function_calls` | 56 | 15.5s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 198 | `get_bytes_total` | 4 | 15.4s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 199 | `get_variable_in_scope` | 29 | 15.5s |  |
| 200 | `getproperty` | 28 | 16.8s |  |
| 201 | `getproperty_swf4` | 28 | 15.1s |  |
| 202 | `getproperty_swf5` | 28 | 15.2s |  |
| 203 | `gettextextent` | 56 | 15.1s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 204 | `global_array` | 3 | 15.5s |  |
| 205 | `global_is_bare` | 7 | 15.2s |  |
| 206 | `global_swf5_6_7_8_9` | 1145 | 16.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 207 | `global_swf6_7_8` | 15 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 208 | `globals_swf5` | 304 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 209 | `globals_swf6` | 304 | 15.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 210 | `globals_swf7` | 304 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 211 | `globals_swf8` | 304 | 15.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 212 | `goto_advance1` | 6 | 15.1s |  |
| 213 | `goto_advance2` | 2 | 15.3s |  |
| 214 | `goto_both_ways1` | 3 | 15.3s |  |
| 215 | `goto_both_ways2` | 3 | 15.3s |  |
| 216 | `goto_execution_order` | 2 | 15.1s |  |
| 217 | `goto_execution_order2` | 2 | 16.3s |  |
| 218 | `goto_frame` | 12 | 15.2s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 219 | `goto_frame2` | 44 | 15.6s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 220 | `goto_frame_number` | 3 | 15.1s |  |
| 221 | `goto_label` | 17 | 15.2s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 222 | `goto_methods` | 40 | 15.1s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 223 | `goto_rewind1` | 1 | 15.1s |  |
| 224 | `goto_rewind2` | 3 | 15.1s |  |
| 225 | `goto_rewind3` | 2 | 15.1s |  |
| 226 | `greater_swf6` | 1175 | 17.0s |  |
| 227 | `greater_swf7` | 1175 | 17.0s |  |
| 228 | `greaterthan_swf5` | 1 | 15.1s |  |
| 229 | `greaterthan_swf8` | 1 | 15.1s |  |
| 230 | `has_own_property` | 32 | 15.0s |  |
| 231 | `hittest_lockroot` | 15 | 15.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 232 | `hittest_morph` | 70 | 15.1s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 233 | `hittest_morph_input` | 1 | 15.0s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 234 | `hittest_winding_rule` | 12 | 15.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 235 | `infinite_recursion_function` | 4 | 15.0s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 236 | `infinite_recursion_function_in_setter` | 131 | 15.0s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 237 | `infinite_recursion_virtual_property` | 67 | 15.0s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 238 | `init_array_invalid` | 4 | 15.7s |  |
| 239 | `init_object_invalid` | 4 | 15.3s |  |
| 240 | `init_object_order` | 15 | 15.7s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 241 | `input_dead_keys_windows` | 15 | 15.6s | [29](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 242 | `instanceof_coercions` | 88 | 15.8s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 243 | `interface_implements_op` | 47 | 16.0s | [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 244 | `is_finite` | 49 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 245 | `is_finite_swf6` | 49 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 246 | `is_prototype_of` | 89 | 16.0s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 247 | `issue_1086` | 1 | 16.1s |  |
| 248 | `issue_1104` | 2 | 15.7s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 249 | `issue_1671` | 0 | 15.9s |  |
| 250 | `issue_1906` | 4 | 15.8s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 251 | `issue_2166` | 9 | 15.6s |  |
| 252 | `issue_2870` | 3 | 15.6s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 253 | `issue_3169` | 2 | 15.8s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 254 | `issue_3446` | 1 | 15.4s |  |
| 255 | `issue_3522` | 2 | 15.7s |  |
| 256 | `issue_4377` | 2 | 16.0s |  |
| 257 | `issue_710` | 4 | 16.4s |  |
| 258 | `issue_768` | 3 | 16.2s | [30](ruffle-tests/_investigation/complete/issue_768.md) |
| 259 | `issue_9327` | 2 | 16.4s |  |
| 260 | `issue_9885` | 2 | 16.5s |  |
| 261 | `key_isToggled` | 9 | 16.4s |  |
| 262 | `lessthan` | 41 | 16.1s |  |
| 263 | `lessthan2_swf5` | 1226 | 18.3s |  |
| 264 | `lessthan2_swf6` | 1226 | 18.4s |  |
| 265 | `lessthan2_swf7` | 1226 | 18.4s |  |
| 266 | `lessthan_swf4` | 902 | 17.7s |  |
| 267 | `lessthan_swf4_alt` | 41 | 16.2s |  |
| 268 | `lessthan_swf5` | 41 | 16.2s |  |
| 269 | `loadmovie` | 2 | 16.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 270 | `loadmovie_fail` | 2 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 271 | `loadmovie_flashvars` | 4 | 16.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 272 | `loadmovie_method` | 2 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 273 | `loadmovie_registerclass` | 30 | 16.3s | [11](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 274 | `loadmovie_replace_root` | 5 | 16.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 275 | `loadmovie_var_persistence` | 8 | 16.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 276 | `loadmovienum` | 3 | 16.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 277 | `loadmovienum_cross_version_prototype` | 9 | 16.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 278 | `loadvariables` | 2 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 279 | `loadvariables2` | 8 | 15.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 280 | `loadvariablesnum` | 2 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 281 | `local_to_global` | 49 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 282 | `localconnection_properties` | 8 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 283 | `lock_root` | 1 | 15.2s |  |
| 284 | `logical_ops_swf4` | 90 | 15.3s |  |
| 285 | `logical_ops_swf8` | 108 | 15.2s |  |
| 286 | `looping` | 6 | 15.1s |  |
| 287 | `mask_reapply` | 0 | 15.1s |  |
| 288 | `mask_with_drawing` | 0 | 15.1s |  |
| 289 | `math_min_max` | 101 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 290 | `math_swf6` | 530 | 15.5s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 291 | `math_swf7` | 530 | 15.5s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 292 | `math_swf8` | 530 | 15.5s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 293 | `matrix` | 171 | 15.4s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 294 | `mcl_as_broadcaster` | 12 | 15.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 295 | `mcl_events_swf_version` | 232 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_getprogress` | 30 | 15.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 297 | `mcl_loadclip` | 149 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_loadclip_properties` | 6 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 299 | `mcl_loadclip_replace_root` | 1 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 300 | `mcl_mislabeled_target` | 6 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 301 | `mcl_target_gif87a` | 6 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 302 | `mcl_target_gif89a` | 6 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 303 | `mcl_target_jpg` | 6 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 304 | `mcl_target_png` | 6 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mcl_unloadclip` | 5 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 306 | `mouse_events` | 8 | 15.5s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 307 | `mouse_events_visible_enabled` | 12 | 15.6s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 308 | `mouse_hover_events_while_dragging` | 1 | 15.4s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 309 | `mouse_listeners` | 67 | 15.3s |  |
| 310 | `mouse_pos` | 665 | 15.3s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 311 | `mouse_pos_with_scale_factor` | 260 | 15.4s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 312 | `mouse_wheel_enabled` | 2 | 15.2s |  |
| 313 | `movieclip_begin_gradient_fill` | 0 | 15.9s |  |
| 314 | `movieclip_blend_mode_property` | 35 | 15.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 315 | `movieclip_create_text_field` | 90 | 16.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 316 | `movieclip_default_state` | 69 | 16.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 317 | `movieclip_depth_methods` | 98 | 16.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 318 | `movieclip_focusenabled` | 99 | 16.0s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_get_instance_at_depth` | 28 | 15.8s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_getbounds` | 191 | 16.0s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 321 | `movieclip_gettextsnapshot` | 112 | 15.9s | [24](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 322 | `movieclip_hittest` | 92 | 16.0s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 323 | `movieclip_in_removed_button` | 4 | 16.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 324 | `movieclip_init_object` | 5 | 15.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 325 | `movieclip_invalid_get_bounds_1` | 75 | 16.3s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_invalid_get_bounds_2` | 75 | 16.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_invalid_get_bounds_3` | 13 | 15.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_invalid_get_bounds_4` | 13 | 16.5s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_invalid_get_bounds_5` | 11 | 17.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_invalid_get_bounds_8` | 11 | 17.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_line_gradient_style` | 0 | 17.1s |  |
| 332 | `movieclip_lockroot` | 29 | 22.1s | [35](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 333 | `movieclip_name_from_timeline` | 13 | 16.0s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 334 | `movieclip_prototype_extension` | 5 | 16.1s |  |
| 335 | `movieclip_setmask` | 14 | 16.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 336 | `moviecliploader_flashvars` | 4 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 337 | `mutable_this` | 18 | 16.1s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 338 | `named_shapes` | 14 | 16.1s |  |
| 339 | `nan_scale` | 9 | 16.2s |  |
| 340 | `native_double_construct` | 12 | 16.3s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 341 | `native_objects_swf7` | 84 | 16.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 342 | `native_objects_swf8` | 84 | 16.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 343 | `nested_textfields_in_buttons` | 0 | 16.1s |  |
| 344 | `new_method_wrap` | 4 | 17.4s |  |
| 345 | `new_object_enumerate` | 7 | 15.6s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 346 | `new_object_wrap` | 4 | 15.7s |  |
| 347 | `o` | 3 | 15.6s |  |
| 348 | `object_constructor` | 33 | 15.5s |  |
| 349 | `object_function` | 32 | 15.7s |  |
| 350 | `object_properties` | 31 | 15.8s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 351 | `object_prototypes` | 74 | 15.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 352 | `object_resolve` | 38 | 15.8s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 353 | `object_string_coerce_swf5` | 62 | 15.8s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 354 | `object_string_coerce_swf6` | 68 | 15.8s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 355 | `on_construct` | 25 | 15.9s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 356 | `parse_float` | 74 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 357 | `parse_int` | 64 | 16.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 358 | `path_string` | 322 | 16.0s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 359 | `place_and_lookup` | 30 | 15.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 360 | `placeobject_occupied_depth` | 6 | 15.8s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 361 | `point` | 175 | 16.0s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 362 | `primitive_instanceof` | 37 | 15.6s |  |
| 363 | `primitive_type_globals` | 557 | 15.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 364 | `printjob_props_swf5` | 45 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 365 | `printjob_props_swf6` | 45 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 366 | `printjob_props_swf7` | 45 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 367 | `property_invalid_base_clip` | 36 | 15.2s |  |
| 368 | `prototype_delete` | 12 | 15.2s |  |
| 369 | `prototype_enumerate` | 5 | 15.1s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 370 | `prototype_properties` | 17 | 15.1s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 371 | `rectangle` | 745 | 15.9s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 372 | `recursive_prototypes` | 0 | 15.0s |  |
| 373 | `register_and_init_order` | 231 | 15.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 374 | `register_class` | 66 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 375 | `register_class_return_value` | 16 | 15.2s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 376 | `register_class_swf6` | 37 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 377 | `register_class_with_sound` | 11 | 15.2s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 378 | `register_globals_across_frames` | 15 | 15.0s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 379 | `register_underflow` | 26 | 15.1s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 380 | `remove_movie_clip` | 29 | 15.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 381 | `removed_clip_halts_script` | 15 | 15.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 382 | `removed_target_clip_scope` | 35 | 15.2s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 383 | `resolve_different_root` | 2 | 16.9s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 384 | `rewind_depth` | 30 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 385 | `root_button_mode` | 10 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 386 | `root_global_parent` | 6 | 15.3s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 387 | `root_onload` | 1 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 388 | `sandbox_type_local_file` | 1 | 15.1s |  |
| 389 | `sandbox_type_local_network` | 1 | 15.1s |  |
| 390 | `selection` | 454 | 15.3s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 391 | `selection_handlers` | 27 | 15.2s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 392 | `set_interval` | 27 | 15.3s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 393 | `set_variable_scope` | 58 | 15.2s |  |
| 394 | `single_frame` | 1 | 15.2s |  |
| 395 | `slash_syntax` | 14 | 15.4s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 396 | `sound` | 628 | 15.5s | [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 397 | `sound_props_swf5` | 68 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 398 | `sound_props_swf6` | 68 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 399 | `sound_start_load` | 0 | 15.4s |  |
| 400 | `stage_display_state` | 16 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 401 | `stage_object_children` | 83 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 402 | `stage_object_enumerate` | 4 | 15.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 403 | `stage_object_properties` | 241 | 15.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 404 | `stage_object_properties_get_var` | 5 | 15.3s |  |
| 405 | `stage_object_properties_swf6` | 231 | 15.7s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 406 | `stage_property_representation` | 586 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 407 | `stage_scale_mode` | 39 | 15.5s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 408 | `strictequals_swf6` | 902 | 16.8s |  |
| 409 | `strictly_equals` | 7 | 15.3s |  |
| 410 | `string_coercion` | 117 | 15.6s | [55](ruffle-tests/_investigation/complete/string_coercion.md) |
| 411 | `string_methods` | 285 | 15.9s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 412 | `string_methods_negative_args` | 240 | 15.6s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 413 | `string_methods_swfv5` | 275 | 16.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 414 | `string_ops_swf6` | 95 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 415 | `string_paths_basic` | 4 | 15.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 416 | `string_paths_eval2` | 7 | 15.2s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 417 | `string_paths_hidden` | 54 | 14.7s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 418 | `string_paths_keyevents` | 0 | 14.7s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 419 | `string_paths_other` | 36 | 14.7s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 420 | `string_paths_timer` | 0 | 14.5s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 421 | `string_paths_unload` | 1 | 14.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 422 | `string_paths_variable_alias` | 4 | 14.4s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 423 | `string_paths_variable_scopes` | 5 | 14.6s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 424 | `stylesheet` | 283 | 15.4s |  |
| 425 | `stylesheet_transform` | 750 | 15.3s |  |
| 426 | `super_edge_cases` | 39 | 14.8s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 427 | `swf4_actions_bool` | 96 | 14.4s |  |
| 428 | `swf4_actions_coercion_order` | 158 | 14.7s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 429 | `swf4_bool` | 4 | 14.6s |  |
| 430 | `swf4_function_calls` | 7 | 14.7s |  |
| 431 | `swf5_encoding` | 3 | 14.7s |  |
| 432 | `swf5_global_funcs` | 232 | 14.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 433 | `swf5_no_closure` | 19 | 14.6s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 434 | `swf5_to_6_cross_call` | 29 | 15.5s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 435 | `swf6_case_insensitive` | 42 | 15.6s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 436 | `swf6_global_funcs` | 232 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 437 | `swf6_string_as_bool` | 15 | 15.3s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 438 | `swf6_to_5_cross_call` | 29 | 15.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 439 | `swf7_case_sensitive` | 44 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 440 | `swf7_global_funcs` | 232 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 441 | `tab_ordering_automatic_basic` | 92 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 442 | `tab_ordering_automatic_order_grid` | 21 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 443 | `tab_ordering_automatic_order_same_position` | 12 | 15.2s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 444 | `tab_ordering_children` | 208 | 15.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 445 | `tab_ordering_custom_basic` | 71 | 15.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 446 | `tab_ordering_custom_duplicate_index` | 22 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 447 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 448 | `tab_ordering_custom_m1` | 29 | 15.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 449 | `tab_ordering_events` | 150 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 450 | `tab_ordering_events_mouse` | 65 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 451 | `tab_ordering_movieclip_enabled_default` | 462 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 452 | `tab_ordering_properties` | 293 | 15.5s | [60](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 453 | `tab_ordering_reverse` | 51 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 454 | `tab_ordering_tabbable` | 47 | 15.8s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 455 | `target_clip_removed` | 5 | 15.9s | [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 456 | `target_clip_swf5` | 2 | 16.3s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 457 | `target_clip_swf6` | 2 | 16.0s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 458 | `target_path` | 14 | 15.7s |  |
| 459 | `tell_target` | 37 | 16.4s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 460 | `tell_target_invalid` | 6 | 16.3s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 461 | `tell_target_invalid_swf6` | 5 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 462 | `text_format` | 1146 | 16.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `text_format_display` | 21 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 464 | `text_format_font_max_length` | 2 | 15.8s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 465 | `text_format_get_text_extent_undefined_width` | 10 | 15.8s |  |
| 466 | `text_format_rounding_swf7` | 840 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `text_format_rounding_swf8` | 840 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textfield_background_color` | 11 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `textfield_border_color` | 11 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 470 | `textfield_cache_as_bitmap` | 1 | 15.1s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 471 | `textfield_maxchars` | 3 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 472 | `textfield_properties` | 44 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 473 | `textfield_props_swf5` | 175 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 474 | `textfield_props_swf6` | 210 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 475 | `textfield_props_swf7` | 210 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 476 | `textfield_props_swf8` | 210 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 477 | `textfield_text` | 7 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 478 | `textfield_variable` | 81 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 479 | `textsnapshot_available_text` | 20 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 480 | `textsnapshot_findtext` | 44 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 481 | `textsnapshot_gettext` | 55 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 482 | `textsnapshot_props_swf5` | 56 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 483 | `textsnapshot_props_swf6` | 56 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 484 | `textsnapshot_text_order` | 1 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 485 | `this_scoping` | 52 | 15.3s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 486 | `this_swf5` | 41 | 15.2s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 487 | `this_swf6` | 41 | 15.3s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 488 | `this_swf7` | 41 | 15.2s | [65](ruffle-tests/_investigation/complete/this_swf7.md) |
| 489 | `timeline_function_def` | 7 | 15.3s |  |
| 490 | `timer_run_actions` | 18 | 15.7s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 491 | `trace` | 8 | 15.2s |  |
| 492 | `transform` | 70 | 15.2s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 493 | `try_catch_finally` | 118 | 15.3s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 494 | `try_finally_simple` | 16 | 15.1s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 495 | `typeof` | 22 | 15.1s |  |
| 496 | `typeof_globals` | 7 | 15.0s |  |
| 497 | `uncaught_exception` | 1 | 15.0s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 498 | `uncaught_exception_bubbled` | 1 | 15.0s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 499 | `undefined_to_string_swf6` | 4 | 15.0s |  |
| 500 | `unescape` | 43 | 15.1s |  |
| 501 | `unload` | 52 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 502 | `unload_clip_event` | 4 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 503 | `unloadmovie` | 4 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 504 | `unloadmovie_method` | 3 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 505 | `unloadmovienum` | 13 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 506 | `use_hand_cursor` | 8 | 15.5s |  |
| 507 | `variable_args` | 5 | 15.4s |  |
| 508 | `waitforframe` | 7 | 15.4s |  |
| 509 | `waitforframe2` | 16 | 15.7s |  |
| 510 | `watch` | 117 | 15.7s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 511 | `watch_textfield` | 12 | 15.4s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 512 | `watch_virtual_property_proto` | 2 | 15.6s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 513 | `with` | 49 | 15.5s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 514 | `with_return` | 2 | 15.4s |  |
| 515 | `with_variable_scopes` | 43 | 15.5s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 516 | `xml` | 15 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_append_child` | 28 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_append_child_with_parent` | 20 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_cdata` | 11 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_child_nodes_edge_cases` | 4 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_clone_expandos` | 19 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_first_last_child` | 8 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_has_child_nodes` | 3 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_idmap` | 21 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_ignore_comments` | 21 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_ignore_white` | 34 | 16.7s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_insert_before` | 20 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_inspect_createmethods` | 15 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_inspect_doctype` | 7 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_inspect_parsexml` | 62 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_inspect_xmldecl` | 7 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_namespaces` | 203 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_parent_and_child` | 5 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_remove_node` | 22 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 535 | `xml_reparenting` | 14 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 536 | `xml_siblings` | 10 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 537 | `xml_to_string` | 13 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 538 | `xml_to_string_comment` | 1 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_unescaping` | 23 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 540 | `xmlnode_proto` | 1 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `clone_sprite_edittext` | 95.7% | 90 | 94 | 4 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_hittest_shapeflag` | 92.0% | 311 | 338 | 27 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `clone_sprite_edittext_dynamic` | 90.7% | 78 | 86 | 8 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `string_paths_eval` | 75.0% | 3 | 4 | 1 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 7 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 8 | `bitmap_data_draw_cliprect` | 69.2% | 9 | 13 | 4 |  |
| 9 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 11 | `issue_2030` | 50.0% | 2 | 4 | 2 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**25 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `clone_sprite_edittext` | 95.7% | 90/94 | 94 | 94 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_hittest_shapeflag` | 92.0% | 311/338 | 338 | 338 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `clone_sprite_edittext_dynamic` | 90.7% | 78/86 | 86 | 86 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `string_paths_eval` | 75.0% | 3/4 | 4 | 4 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 7 | `text_blocks_clicks` | 75.0% | 3/4 | 4 | 4 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 8 | `bitmap_data_draw_cliprect` | 69.2% | 9/13 | 13 | 13 |  |
| 9 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 11 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 12 | `issue_2084` | 37.5% | 6/16 | 8 | 16 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 13 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 14 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 15 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 16 | `global_instance_decls` | 2.4% | 18/758 | 695 | 758 | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 17 | `global_proto_decls_delete` | 2.2% | 91/4158 | 705 | 4158 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 18 | `global_proto_decls` | 2.1% | 93/4497 | 1266 | 4497 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 19 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 20 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 21 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `geturl` | 0.0% | 0/7 | 0 | 7 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 25 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 3 | 3 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) | 8 | 8 | 0 |
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
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 13 | 4 |
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
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 17 | 16 | 1 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 69 | 67 | 2 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 2 | 0 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 10 | 6 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 11 | 1 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 26 | 25 | 1 |
| | *(tests not in any document)* | 150 | 149 | 1 |
