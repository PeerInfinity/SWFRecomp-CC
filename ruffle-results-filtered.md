# Ruffle Test Results (Filtered)

**Date**: 2026-03-16 01:10 UTC

**Git SHA**: `afce4866b1`

**Run Duration**: 166m 37s

**Filtered**: 45 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 574 |
| Passing | **562** (97.9%) |
| Failing | 12 |
| Total expected lines | 81443 |
| Matching lines | 71658 (88.0%) |
| Mismatched lines | 9785 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**562 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 17.2s |  |
| 2 | `action_to_integer` | 28 | 15.6s |  |
| 3 | `add` | 28 | 15.8s |  |
| 4 | `add2` | 354 | 16.0s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.9s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.6s |  |
| 7 | `add_swf5` | 28 | 15.8s |  |
| 8 | `arguments` | 127 | 15.6s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 16.6s |  |
| 11 | `array_constructor` | 30 | 17.1s |  |
| 12 | `array_enumerate` | 4 | 16.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 15.8s |  |
| 14 | `array_properties` | 36 | 16.2s |  |
| 15 | `array_prototyping` | 12 | 16.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 16.6s |  |
| 17 | `array_sort` | 161 | 17.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 16.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 16.6s |  |
| 20 | `array_trivial` | 209 | 16.1s |  |
| 21 | `as1_constructor_v6` | 35 | 16.3s |  |
| 22 | `as1_constructor_v7` | 35 | 18.5s |  |
| 23 | `as2_oop` | 13 | 16.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 17.0s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 16.9s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 16.5s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 16.2s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 16.1s |  |
| 29 | `as_broadcaster_undef` | 89 | 16.2s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 16.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 16.2s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 16.2s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 16.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 16.7s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 16.5s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 16.6s |  |
| 37 | `as_transformed_flag` | 20 | 16.5s |  |
| 38 | `asnative` | 34 | 16.6s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 16.7s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 16.1s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 16.3s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 17.6s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 15.8s |  |
| 44 | `bitand` | 1058 | 18.8s |  |
| 45 | `bitmap_data` | 1126 | 18.4s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_colortransform` | 0 | 16.0s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_compare` | 40 | 16.2s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_copypixels` | 17 | 16.5s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_draw_cliprect` | 13 | 16.1s |  |
| 50 | `bitmap_data_fillrect` | 0 | 15.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 51 | `bitmap_data_hittest` | 132 | 16.2s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 52 | `bitmap_data_max_size_swf10` | 12 | 15.7s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_max_size_swf9` | 10 | 15.6s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_noise` | 631 | 16.1s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_perlinnoise` | 0 | 16.5s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_pixeldissolve_image` | 0 | 16.1s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 57 | `bitmap_data_threshold` | 176 | 16.1s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 58 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 59 | `bitmapdata_channels` | 19 | 15.6s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 60 | `bitor` | 1058 | 18.4s |  |
| 61 | `biturshift` | 14 | 16.7s |  |
| 62 | `biturshift_swf8` | 14 | 16.1s |  |
| 63 | `bitxor` | 1058 | 19.0s |  |
| 64 | `boxed_primitives` | 24 | 16.0s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 65 | `button_children` | 8 | 16.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_goto` | 4 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_key_events` | 14 | 16.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_key_events_special` | 45 | 16.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_keypress` | 3 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_keypress_vs_press` | 25 | 15.7s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_keypress_vs_tab` | 20 | 16.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_keypress_vs_textinput` | 4 | 15.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_order` | 2 | 16.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_properties_special_cases` | 22 | 16.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `button_v5` | 18 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 76 | `button_v6` | 18 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 77 | `call` | 63 | 15.9s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 78 | `call_method_empty_name` | 1 | 15.8s |  |
| 79 | `capabilities_resolution` | 8 | 15.5s |  |
| 80 | `catch_references_registers` | 2 | 15.7s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 81 | `click_block` | 5 | 15.7s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 82 | `clip_constructors` | 8 | 15.7s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 83 | `clip_event_propagation_order` | 17 | 15.5s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 84 | `clip_events` | 19 | 15.6s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 85 | `clone_sprite_edittext` | 94 | 15.6s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 86 | `clone_sprite_edittext_dynamic` | 86 | 15.5s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 87 | `clone_sprite_types` | 24 | 15.2s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 88 | `closure_scope` | 7 | 15.3s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 89 | `coerce_to_object_monkeypatch` | 129 | 15.7s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 90 | `coerce_to_primitive_resolve` | 17 | 15.4s | [46](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 91 | `color` | 57 | 15.5s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 92 | `color_transform` | 48 | 15.4s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 93 | `conflicting_instance_names` | 23 | 15.3s |  |
| 94 | `constructor_function` | 2 | 15.2s |  |
| 95 | `context_menu` | 39 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 96 | `context_menu_item` | 41 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 97 | `create_empty_movie_clip` | 3 | 15.0s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 98 | `cross_movie_root` | 10 | 15.2s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 99 | `custom_clip_methods` | 4 | 15.3s | [12](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 100 | `default_names` | 52 | 15.2s | [14](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 101 | `define_function2` | 8 | 15.2s |  |
| 102 | `define_function2_preload` | 13 | 16.0s |  |
| 103 | `define_function2_preload_order` | 4 | 15.8s |  |
| 104 | `define_function_case_sensitive` | 2 | 15.8s |  |
| 105 | `define_local` | 27 | 15.8s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 106 | `define_local_with_paths` | 54 | 15.9s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 107 | `delete` | 3 | 15.9s |  |
| 108 | `device_font_spacing` | 91 | 15.9s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 109 | `display_object_properties` | 2 | 15.9s |  |
| 110 | `divide_swf4` | 107 | 15.8s |  |
| 111 | `do_init_action` | 3 | 15.7s |  |
| 112 | `do_init_action_child` | 12 | 15.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 113 | `drag_drop` | 10 | 15.9s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 114 | `drag_over_from_outside` | 1 | 15.9s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 115 | `drag_over_without_startdrag` | 1 | 16.1s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 116 | `duplicate_movie_clip` | 20 | 16.0s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 117 | `duplicate_movie_clip_drawing` | 2 | 15.8s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 118 | `edittext_align` | 60 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_align_trailing_spaces_swf7` | 576 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_align_trailing_spaces_swf8` | 576 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_antialiastype` | 296 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_autosize` | 71 | 17.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_autosize_setter` | 20 | 15.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_bullet` | 30 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_default_format` | 221 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_default_format_font_style` | 335 | 15.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_focus_selection` | 2 | 15.3s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_font_size` | 45 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_hscroll` | 27 | 15.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_html_align_swf7` | 52 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_html_align_swf8` | 52 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_html_color` | 114 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_html_condensewhite_swf7` | 311 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_html_condensewhite_swf8` | 311 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_entity` | 4 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_html_roundtrip` | 17 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_html_swf6` | 5377 | 17.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_html_swf7` | 5377 | 16.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_html_swf8` | 5377 | 17.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_input` | 1 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_input_newlines` | 9 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_leading` | 9 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_letter_spacing` | 15 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_margins` | 25 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_newline_stripping` | 64 | 20.1s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_newlines` | 30 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_password` | 5 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_password_copy` | 4 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_paste_empty` | 2 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_place_caret` | 2 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_programmatic_focus` | 12 | 15.3s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_restrict` | 191 | 15.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_restrict_paste` | 5 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_scroll` | 54 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_stylesheet` | 325 | 16.1s | [57](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_tab_focus` | 13 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_tab_stops` | 60 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_tag_indent` | 31 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_text_height_leading` | 20 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_underline` | 40 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_width_height` | 103 | 16.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `empty_movieclip_can_attach_movies` | 11 | 16.1s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 163 | `enumerate` | 64 | 16.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 164 | `equals` | 32 | 16.0s |  |
| 165 | `equals2_swf5` | 926 | 18.0s |  |
| 166 | `equals2_swf6` | 926 | 18.1s |  |
| 167 | `equals2_swf7` | 926 | 17.6s |  |
| 168 | `equals_swf4` | 665 | 16.9s |  |
| 169 | `equals_swf4_alt` | 32 | 16.2s |  |
| 170 | `equals_swf5` | 32 | 16.0s |  |
| 171 | `error` | 58 | 16.0s |  |
| 172 | `escape` | 14 | 16.0s |  |
| 173 | `execution_order1` | 5 | 16.2s |  |
| 174 | `execution_order2` | 7 | 16.2s |  |
| 175 | `execution_order3` | 4 | 16.1s |  |
| 176 | `execution_order4` | 12 | 16.3s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 177 | `export_assets` | 3 | 16.1s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 178 | `extends_chain` | 134 | 16.5s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 179 | `extends_native_type` | 11 | 16.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 180 | `external_interface` | 84 | 16.3s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 181 | `external_interface_escapexml` | 26 | 16.1s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 182 | `external_interface_jsquotestring` | 21 | 17.9s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 183 | `external_interface_toas_basic` | 354 | 16.4s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 184 | `external_interface_toxml_array` | 25 | 16.0s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 185 | `external_interface_toxml_basic` | 179 | 16.2s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 186 | `external_interface_unescapexml` | 40 | 16.2s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 187 | `focus_keyboard_press` | 60 | 16.5s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 188 | `focus_mouse` | 45 | 16.2s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 189 | `focus_mouse_focusable` | 8 | 16.5s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 190 | `focus_mouse_rollout` | 4 | 15.9s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 191 | `focus_remove` | 33 | 15.9s |  |
| 192 | `focus_root_movie` | 2 | 16.1s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 193 | `focus_visibility_change` | 45 | 16.4s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 194 | `focusrect_focuslost` | 4 | 15.9s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 195 | `focusrect_mouse_swf8` | 0 | 17.2s |  |
| 196 | `focusrect_mouse_swf9` | 0 | 15.3s |  |
| 197 | `focusrect_property_swf5` | 1237 | 15.5s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 198 | `focusrect_property_swf6` | 1237 | 15.5s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 199 | `focusrect_property_swf7` | 1237 | 15.5s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 200 | `focusrect_swf5` | 6 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 201 | `focusrect_swf6` | 42 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 202 | `form_loader_encoding_1` | 1 | 15.2s |  |
| 203 | `frame_size_translated_negative` | 21 | 15.2s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 204 | `frame_size_translated_positive` | 21 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 205 | `function_as_function` | 35 | 15.3s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 206 | `function_base_clip` | 8 | 15.3s |  |
| 207 | `function_base_clip_readded` | 11 | 15.3s |  |
| 208 | `function_base_clip_removed` | 25 | 15.4s |  |
| 209 | `function_suppress_and_preload` | 28 | 15.4s |  |
| 210 | `funky_function_calls` | 56 | 15.3s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 211 | `get_bytes_total` | 4 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 212 | `get_variable_in_scope` | 29 | 15.3s |  |
| 213 | `getproperty` | 28 | 16.3s |  |
| 214 | `getproperty_swf4` | 28 | 16.0s |  |
| 215 | `getproperty_swf5` | 28 | 16.1s |  |
| 216 | `gettextextent` | 56 | 16.1s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 217 | `global_array` | 3 | 16.1s |  |
| 218 | `global_is_bare` | 7 | 16.0s |  |
| 219 | `global_swf5_6_7_8_9` | 1145 | 16.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 220 | `global_swf6_7_8` | 15 | 16.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 221 | `globals_swf5` | 304 | 16.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 222 | `globals_swf6` | 304 | 16.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 223 | `globals_swf7` | 304 | 16.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 224 | `globals_swf8` | 304 | 16.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 225 | `goto_advance1` | 6 | 16.0s |  |
| 226 | `goto_advance2` | 2 | 16.1s |  |
| 227 | `goto_both_ways1` | 3 | 16.0s |  |
| 228 | `goto_both_ways2` | 3 | 16.2s |  |
| 229 | `goto_execution_order` | 2 | 16.0s |  |
| 230 | `goto_execution_order2` | 2 | 15.8s |  |
| 231 | `goto_frame` | 12 | 15.8s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 232 | `goto_frame2` | 44 | 16.0s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 233 | `goto_frame_number` | 3 | 15.5s |  |
| 234 | `goto_label` | 17 | 15.7s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 235 | `goto_methods` | 40 | 15.3s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 236 | `goto_rewind1` | 1 | 15.3s |  |
| 237 | `goto_rewind2` | 3 | 15.2s |  |
| 238 | `goto_rewind3` | 2 | 15.4s |  |
| 239 | `greater_swf6` | 1175 | 17.3s |  |
| 240 | `greater_swf7` | 1175 | 17.2s |  |
| 241 | `greaterthan_swf5` | 1 | 15.2s |  |
| 242 | `greaterthan_swf8` | 1 | 15.3s |  |
| 243 | `has_own_property` | 32 | 15.3s |  |
| 244 | `hittest_lockroot` | 15 | 15.6s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 245 | `hittest_morph` | 70 | 15.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 246 | `hittest_morph_input` | 1 | 15.3s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 247 | `hittest_winding_rule` | 12 | 15.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 248 | `infinite_recursion_function` | 4 | 15.2s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 249 | `infinite_recursion_function_in_setter` | 131 | 15.3s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 250 | `infinite_recursion_virtual_property` | 67 | 15.3s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 251 | `init_array_invalid` | 4 | 16.1s |  |
| 252 | `init_object_invalid` | 4 | 15.8s |  |
| 253 | `init_object_order` | 15 | 15.8s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 254 | `input_dead_keys_windows` | 15 | 16.0s | [29](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 255 | `instanceof_coercions` | 88 | 16.3s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 256 | `interface_implements_op` | 47 | 16.4s | [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 257 | `is_finite` | 49 | 16.0s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 258 | `is_finite_swf6` | 49 | 15.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 259 | `is_prototype_of` | 89 | 16.0s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 260 | `issue_1086` | 1 | 15.9s |  |
| 261 | `issue_1104` | 2 | 15.9s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 262 | `issue_1671` | 0 | 16.1s |  |
| 263 | `issue_1906` | 4 | 15.9s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 264 | `issue_2030` | 4 | 15.8s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 265 | `issue_2084` | 16 | 16.0s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 266 | `issue_2166` | 9 | 15.9s |  |
| 267 | `issue_2870` | 3 | 15.9s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 268 | `issue_3169` | 2 | 15.8s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 269 | `issue_3446` | 1 | 15.7s |  |
| 270 | `issue_3522` | 2 | 15.8s |  |
| 271 | `issue_4377` | 2 | 15.8s |  |
| 272 | `issue_710` | 4 | 16.0s |  |
| 273 | `issue_768` | 3 | 15.7s | [30](ruffle-tests/_investigation/complete/issue_768.md) |
| 274 | `issue_9327` | 2 | 15.8s |  |
| 275 | `issue_9885` | 2 | 15.8s |  |
| 276 | `key_isToggled` | 9 | 15.9s |  |
| 277 | `lessthan` | 41 | 16.0s |  |
| 278 | `lessthan2_swf5` | 1226 | 18.0s |  |
| 279 | `lessthan2_swf6` | 1226 | 17.9s |  |
| 280 | `lessthan2_swf7` | 1226 | 17.8s |  |
| 281 | `lessthan_swf4` | 902 | 17.1s |  |
| 282 | `lessthan_swf4_alt` | 41 | 15.8s |  |
| 283 | `lessthan_swf5` | 41 | 15.8s |  |
| 284 | `loadmovie` | 2 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 285 | `loadmovie_fail` | 2 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 286 | `loadmovie_flashvars` | 4 | 16.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 287 | `loadmovie_method` | 2 | 15.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 288 | `loadmovie_registerclass` | 30 | 16.1s | [11](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 289 | `loadmovie_replace_root` | 5 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 290 | `loadmovie_var_persistence` | 8 | 15.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 291 | `loadmovienum` | 3 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 292 | `loadmovienum_cross_version_prototype` | 9 | 15.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 293 | `loadvariables` | 2 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 294 | `loadvariables2` | 8 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 295 | `loadvariablesnum` | 2 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 296 | `local_to_global` | 49 | 15.5s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 297 | `localconnection_properties` | 8 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 298 | `lock_root` | 1 | 15.5s |  |
| 299 | `logical_ops_swf4` | 90 | 15.6s |  |
| 300 | `logical_ops_swf8` | 108 | 15.5s |  |
| 301 | `looping` | 6 | 15.5s |  |
| 302 | `mask_reapply` | 0 | 15.5s |  |
| 303 | `mask_with_drawing` | 0 | 15.5s |  |
| 304 | `math_min_max` | 101 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 305 | `math_swf6` | 530 | 16.2s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 306 | `math_swf7` | 530 | 16.1s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 307 | `math_swf8` | 530 | 16.4s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 308 | `matrix` | 171 | 16.0s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 309 | `mcl_as_broadcaster` | 12 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 310 | `mcl_events_swf_version` | 232 | 16.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 311 | `mcl_getprogress` | 30 | 16.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mcl_loadclip` | 149 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_loadclip_properties` | 6 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_loadclip_replace_root` | 1 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 315 | `mcl_mislabeled_target` | 6 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 316 | `mcl_target_gif87a` | 6 | 16.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 317 | `mcl_target_gif89a` | 6 | 16.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 318 | `mcl_target_jpg` | 6 | 15.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 319 | `mcl_target_png` | 6 | 16.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 320 | `mcl_unloadclip` | 5 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 321 | `mouse_events` | 8 | 16.0s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 322 | `mouse_events_visible_enabled` | 12 | 16.2s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 323 | `mouse_hover_events_while_dragging` | 1 | 15.9s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 324 | `mouse_listeners` | 67 | 15.7s |  |
| 325 | `mouse_pos` | 665 | 15.7s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 326 | `mouse_pos_with_scale_factor` | 260 | 15.7s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 327 | `mouse_wheel_enabled` | 2 | 15.7s |  |
| 328 | `movieclip_begin_gradient_fill` | 0 | 16.3s |  |
| 329 | `movieclip_blend_mode_property` | 35 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_create_text_field` | 90 | 16.4s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 331 | `movieclip_default_state` | 69 | 16.2s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_depth_methods` | 98 | 15.9s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 333 | `movieclip_focusenabled` | 99 | 15.6s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 334 | `movieclip_get_instance_at_depth` | 28 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_getbounds` | 191 | 16.0s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_gettextsnapshot` | 112 | 15.9s | [24](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_hittest` | 92 | 16.3s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_in_removed_button` | 4 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 339 | `movieclip_init_object` | 5 | 15.6s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 340 | `movieclip_invalid_get_bounds_1` | 75 | 16.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_invalid_get_bounds_2` | 75 | 16.1s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_invalid_get_bounds_3` | 13 | 15.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 343 | `movieclip_invalid_get_bounds_4` | 13 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_invalid_get_bounds_5` | 11 | 15.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_invalid_get_bounds_6` | 10 | 40.1s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 346 | `movieclip_invalid_get_bounds_7` | 10 | 40.7s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 347 | `movieclip_invalid_get_bounds_8` | 11 | 16.0s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 348 | `movieclip_line_gradient_style` | 0 | 16.2s |  |
| 349 | `movieclip_lockroot` | 29 | 17.3s | [35](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 350 | `movieclip_name_from_timeline` | 13 | 15.3s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 351 | `movieclip_prototype_extension` | 5 | 15.3s |  |
| 352 | `movieclip_setmask` | 14 | 15.5s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 353 | `moviecliploader_flashvars` | 4 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 354 | `mutable_this` | 18 | 15.3s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 355 | `named_shapes` | 14 | 15.2s |  |
| 356 | `nan_scale` | 9 | 15.3s |  |
| 357 | `native_double_construct` | 12 | 15.4s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 358 | `native_objects_swf7` | 84 | 15.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 359 | `native_objects_swf8` | 84 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 360 | `native_subclasses` | 191 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 361 | `nested_textfields_in_buttons` | 0 | 15.2s |  |
| 362 | `new_method_wrap` | 4 | 17.1s |  |
| 363 | `new_object_enumerate` | 7 | 15.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 364 | `new_object_wrap` | 4 | 15.4s |  |
| 365 | `o` | 3 | 15.4s |  |
| 366 | `object_constructor` | 33 | 15.4s |  |
| 367 | `object_function` | 32 | 15.4s |  |
| 368 | `object_properties` | 31 | 15.6s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 369 | `object_prototypes` | 74 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 370 | `object_resolve` | 38 | 15.6s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 371 | `object_string_coerce_swf5` | 62 | 15.5s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 372 | `object_string_coerce_swf6` | 68 | 15.5s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 373 | `on_construct` | 25 | 15.6s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 374 | `parse_float` | 74 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 375 | `parse_int` | 64 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 376 | `path_string` | 322 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 377 | `place_and_lookup` | 30 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 378 | `placeobject_occupied_depth` | 6 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 379 | `point` | 175 | 16.1s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 380 | `primitive_instanceof` | 37 | 15.7s |  |
| 381 | `primitive_type_globals` | 557 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 382 | `printjob_props_swf5` | 45 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 383 | `printjob_props_swf6` | 45 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 384 | `printjob_props_swf7` | 45 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 385 | `property_invalid_base_clip` | 36 | 15.5s |  |
| 386 | `prototype_delete` | 12 | 15.7s |  |
| 387 | `prototype_enumerate` | 5 | 15.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 388 | `prototype_properties` | 17 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 389 | `rectangle` | 745 | 16.2s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 390 | `recursive_prototypes` | 0 | 15.4s |  |
| 391 | `register_and_init_order` | 231 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 392 | `register_class` | 66 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 393 | `register_class_return_value` | 16 | 15.5s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 394 | `register_class_swf6` | 37 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 395 | `register_class_with_sound` | 11 | 15.6s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 396 | `register_globals_across_frames` | 15 | 15.5s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 397 | `register_underflow` | 26 | 15.6s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 398 | `remove_movie_clip` | 29 | 15.5s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 399 | `removed_clip_halts_script` | 15 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 400 | `removed_target_clip_scope` | 35 | 15.7s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 401 | `resolve_different_root` | 2 | 15.9s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 402 | `rewind_depth` | 30 | 15.4s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 403 | `root_button_mode` | 10 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 404 | `root_global_parent` | 6 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 405 | `root_onload` | 1 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 406 | `sandbox_type_local_file` | 1 | 15.1s |  |
| 407 | `sandbox_type_local_network` | 1 | 15.1s |  |
| 408 | `selection` | 454 | 15.3s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 409 | `selection_handlers` | 27 | 15.2s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 410 | `set_interval` | 27 | 15.3s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 411 | `set_variable_scope` | 58 | 15.2s |  |
| 412 | `single_frame` | 1 | 15.3s |  |
| 413 | `slash_syntax` | 14 | 15.3s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 414 | `sound` | 628 | 15.5s | [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 415 | `sound_props_swf5` | 68 | 16.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 416 | `sound_props_swf6` | 68 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 417 | `sound_start_load` | 0 | 15.6s |  |
| 418 | `stage_display_state` | 16 | 15.6s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 419 | `stage_object_children` | 83 | 15.5s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 420 | `stage_object_enumerate` | 4 | 15.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 421 | `stage_object_properties` | 241 | 15.8s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 422 | `stage_object_properties_get_var` | 5 | 15.5s |  |
| 423 | `stage_object_properties_swf6` | 231 | 15.9s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 424 | `stage_property_representation` | 586 | 15.5s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 425 | `stage_scale_mode` | 39 | 15.6s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 426 | `strictequals_swf6` | 902 | 17.0s |  |
| 427 | `strictly_equals` | 7 | 15.5s |  |
| 428 | `string_coercion` | 117 | 15.7s | [55](ruffle-tests/_investigation/complete/string_coercion.md) |
| 429 | `string_methods` | 285 | 15.9s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 430 | `string_methods_negative_args` | 240 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 431 | `string_methods_swfv5` | 275 | 16.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 432 | `string_ops_swf6` | 95 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 433 | `string_paths_basic` | 4 | 15.7s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 434 | `string_paths_eval` | 4 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 435 | `string_paths_eval2` | 7 | 17.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 436 | `string_paths_hidden` | 54 | 15.6s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 437 | `string_paths_keyevents` | 0 | 15.3s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 438 | `string_paths_other` | 36 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 439 | `string_paths_timer` | 0 | 15.3s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 440 | `string_paths_unload` | 1 | 15.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 441 | `string_paths_variable_alias` | 4 | 15.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 442 | `string_paths_variable_scopes` | 5 | 15.8s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 443 | `stylesheet` | 283 | 16.2s |  |
| 444 | `stylesheet_transform` | 750 | 16.1s |  |
| 445 | `super_edge_cases` | 39 | 15.5s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 446 | `swf4_actions_bool` | 96 | 15.4s |  |
| 447 | `swf4_actions_coercion_order` | 158 | 15.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 448 | `swf4_bool` | 4 | 15.4s |  |
| 449 | `swf4_function_calls` | 7 | 15.4s |  |
| 450 | `swf5_encoding` | 3 | 15.3s |  |
| 451 | `swf5_global_funcs` | 232 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 452 | `swf5_no_closure` | 19 | 15.4s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 453 | `swf5_to_6_cross_call` | 29 | 15.9s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 454 | `swf6_case_insensitive` | 42 | 15.5s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 455 | `swf6_global_funcs` | 232 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 456 | `swf6_string_as_bool` | 15 | 15.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 457 | `swf6_to_5_cross_call` | 29 | 15.6s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 458 | `swf7_case_sensitive` | 44 | 15.6s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 459 | `swf7_global_funcs` | 232 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 460 | `tab_ordering_automatic_basic` | 92 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 461 | `tab_ordering_automatic_order_grid` | 21 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 462 | `tab_ordering_automatic_order_same_position` | 12 | 15.8s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 463 | `tab_ordering_children` | 208 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 464 | `tab_ordering_custom_basic` | 71 | 15.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 465 | `tab_ordering_custom_duplicate_index` | 22 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 466 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 467 | `tab_ordering_custom_m1` | 29 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 468 | `tab_ordering_events` | 150 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 469 | `tab_ordering_events_mouse` | 65 | 16.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 470 | `tab_ordering_movieclip_enabled_default` | 462 | 16.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 471 | `tab_ordering_properties` | 293 | 16.1s | [60](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 472 | `tab_ordering_reverse` | 51 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 473 | `tab_ordering_tabbable` | 47 | 16.2s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 474 | `target_clip_removed` | 5 | 17.8s | [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 475 | `target_clip_swf5` | 2 | 16.3s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 476 | `target_clip_swf6` | 2 | 16.9s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 477 | `target_path` | 14 | 16.2s |  |
| 478 | `tell_target` | 37 | 17.2s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 479 | `tell_target_invalid` | 6 | 17.7s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 480 | `tell_target_invalid_swf6` | 5 | 17.4s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 481 | `text_blocks_clicks` | 4 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 482 | `text_format` | 1146 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 483 | `text_format_display` | 21 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 484 | `text_format_font_max_length` | 2 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 485 | `text_format_get_text_extent_undefined_width` | 10 | 16.3s |  |
| 486 | `text_format_rounding_swf7` | 840 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 487 | `text_format_rounding_swf8` | 840 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 488 | `textfield_background_color` | 11 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 489 | `textfield_border_color` | 11 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 490 | `textfield_cache_as_bitmap` | 1 | 16.0s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 491 | `textfield_maxchars` | 3 | 17.1s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 492 | `textfield_properties` | 44 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 493 | `textfield_props_swf5` | 175 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 494 | `textfield_props_swf6` | 210 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 495 | `textfield_props_swf7` | 210 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 496 | `textfield_props_swf8` | 210 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `textfield_text` | 7 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `textfield_variable` | 81 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 499 | `textsnapshot_available_text` | 20 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 500 | `textsnapshot_findtext` | 44 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 501 | `textsnapshot_gettext` | 55 | 16.1s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 502 | `textsnapshot_props_swf5` | 56 | 16.1s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 503 | `textsnapshot_props_swf6` | 56 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 504 | `textsnapshot_text_order` | 1 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 505 | `this_scoping` | 52 | 16.1s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 506 | `this_swf5` | 41 | 16.0s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 507 | `this_swf6` | 41 | 16.0s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 508 | `this_swf7` | 41 | 15.7s | [65](ruffle-tests/_investigation/complete/this_swf7.md) |
| 509 | `timeline_function_def` | 7 | 16.0s |  |
| 510 | `timer_run_actions` | 18 | 16.1s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 511 | `trace` | 8 | 15.7s |  |
| 512 | `transform` | 70 | 15.7s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 513 | `try_catch_finally` | 118 | 15.7s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 514 | `try_finally_simple` | 16 | 15.7s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 515 | `typeof` | 22 | 15.6s |  |
| 516 | `typeof_globals` | 7 | 15.6s |  |
| 517 | `uncaught_exception` | 1 | 15.6s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 518 | `uncaught_exception_bubbled` | 1 | 15.7s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 519 | `undefined_to_string_swf6` | 4 | 15.6s |  |
| 520 | `unescape` | 43 | 15.6s |  |
| 521 | `unload` | 52 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 522 | `unload_clip_event` | 4 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 523 | `unload_nested_child` | 5 | 15.7s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 524 | `unloadmovie` | 4 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 525 | `unloadmovie_method` | 3 | 15.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 526 | `unloadmovienum` | 13 | 15.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 527 | `use_hand_cursor` | 8 | 15.7s |  |
| 528 | `variable_args` | 5 | 15.8s |  |
| 529 | `waitforframe` | 7 | 15.8s |  |
| 530 | `waitforframe2` | 16 | 23.6s |  |
| 531 | `watch` | 117 | 15.6s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 532 | `watch_textfield` | 12 | 15.2s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 533 | `watch_virtual_property_proto` | 2 | 15.7s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 534 | `with` | 49 | 15.4s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 535 | `with_return` | 2 | 15.3s |  |
| 536 | `with_variable_scopes` | 43 | 15.5s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 537 | `xml` | 15 | 15.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 538 | `xml_append_child` | 28 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_append_child_with_parent` | 20 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 540 | `xml_attributes_read` | 4 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 541 | `xml_cdata` | 11 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 542 | `xml_child_nodes_edge_cases` | 4 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_clone_expandos` | 19 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_first_last_child` | 8 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 545 | `xml_has_child_nodes` | 3 | 15.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 546 | `xml_idmap` | 21 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 547 | `xml_ignore_comments` | 21 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_ignore_white` | 34 | 17.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_insert_before` | 20 | 16.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_inspect_createmethods` | 15 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_inspect_doctype` | 7 | 16.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_inspect_parsexml` | 62 | 16.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_inspect_xmldecl` | 7 | 16.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_namespaces` | 203 | 16.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_parent_and_child` | 5 | 16.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 556 | `xml_remove_node` | 22 | 16.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 557 | `xml_reparenting` | 14 | 16.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 558 | `xml_siblings` | 10 | 16.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 559 | `xml_to_string` | 13 | 16.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 560 | `xml_to_string_comment` | 1 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 561 | `xml_unescaping` | 23 | 16.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 562 | `xmlnode_proto` | 1 | 16.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_hittest_shapeflag` | 92.0% | 311 | 338 | 27 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 2 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**12 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_hittest_shapeflag` | 92.0% | 311/338 | 338 | 338 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 2 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 3 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 4 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 5 | `global_instance_decls` | 2.4% | 18/758 | 695 | 758 | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 6 | `global_proto_decls_delete` | 2.2% | 91/4158 | 705 | 4158 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 7 | `global_proto_decls` | 2.1% | 93/4497 | 1266 | 4497 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 8 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 9 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 10 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 11 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 12 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) | 15 | 15 | 0 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
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
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 5 | 1 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 30 | 27 | 3 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 28 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 30 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 43 | 42 | 1 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 3 | 3 | 0 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 36 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) | 55 | 53 | 2 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 15 | 15 | 0 |
| 42 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 3 | 0 |
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
| 56 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 12 | 12 | 0 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 17 | 17 | 0 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) | 69 | 67 | 2 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 2 | 0 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 15 | 12 | 3 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 27 | 26 | 1 |
| | *(tests not in any document)* | 151 | 151 | 0 |
