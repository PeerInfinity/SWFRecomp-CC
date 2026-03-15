# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-15 17:09 UTC

**Git SHA**: `df1f69a204`

**Run Duration**: 165m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **555** (89.7%) |
| Failing | 64 |
| Total expected lines | 91497 |
| Matching lines | 78492 (85.8%) |
| Mismatched lines | 13005 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 61 | 95.3% |
| Runtime Segfault | 2 | 3.1% |
| Timeout | 1 | 1.6% |

## Passing Tests

**555 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.4s |  |
| 2 | `action_to_integer` | 28 | 15.3s |  |
| 3 | `add` | 28 | 15.3s |  |
| 4 | `add2` | 354 | 15.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.3s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.3s |  |
| 7 | `add_swf5` | 28 | 15.3s |  |
| 8 | `arguments` | 127 | 15.3s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 15.2s |  |
| 11 | `array_constructor` | 30 | 15.2s |  |
| 12 | `array_enumerate` | 4 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 15.3s |  |
| 14 | `array_properties` | 36 | 15.3s |  |
| 15 | `array_prototyping` | 12 | 15.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.3s |  |
| 17 | `array_sort` | 161 | 16.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 15.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 15.5s |  |
| 20 | `array_trivial` | 209 | 15.4s |  |
| 21 | `as1_constructor_v6` | 35 | 15.3s |  |
| 22 | `as1_constructor_v7` | 35 | 16.4s |  |
| 23 | `as2_oop` | 13 | 15.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 15.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 15.7s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 15.7s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 15.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 15.4s |  |
| 29 | `as_broadcaster_undef` | 89 | 15.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 15.4s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 15.4s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 15.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 15.3s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 15.4s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 15.3s |  |
| 37 | `as_transformed_flag` | 20 | 15.3s |  |
| 38 | `asnative` | 34 | 15.4s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 15.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 15.4s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 15.4s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 17.4s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 16.1s |  |
| 44 | `bitand` | 1058 | 19.5s |  |
| 45 | `bitmap_data` | 1126 | 18.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_colortransform` | 0 | 16.5s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_compare` | 40 | 15.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_fillrect` | 0 | 15.3s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_hittest` | 132 | 16.3s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 50 | `bitmap_data_max_size_swf10` | 12 | 15.4s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 51 | `bitmap_data_max_size_swf9` | 10 | 15.6s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 52 | `bitmap_data_noise` | 631 | 15.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_perlinnoise` | 0 | 16.3s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_pixeldissolve_image` | 0 | 15.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_threshold` | 176 | 16.0s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 56 | `bitmapdata_applyfilter_colormatrix` | 0 | 16.0s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 57 | `bitmapdata_channels` | 19 | 15.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 58 | `bitor` | 1058 | 18.6s |  |
| 59 | `biturshift` | 14 | 16.3s |  |
| 60 | `biturshift_swf8` | 14 | 15.8s |  |
| 61 | `bitxor` | 1058 | 19.1s |  |
| 62 | `boxed_primitives` | 24 | 16.0s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 63 | `button_children` | 8 | 15.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_goto` | 4 | 15.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_key_events` | 14 | 16.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_key_events_special` | 45 | 16.8s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_keypress` | 3 | 16.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_keypress_vs_press` | 25 | 15.8s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_keypress_vs_tab` | 20 | 15.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_keypress_vs_textinput` | 4 | 15.7s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_order` | 2 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_properties_special_cases` | 22 | 16.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_v5` | 18 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_v6` | 18 | 15.8s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `call` | 63 | 16.2s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 76 | `call_method_empty_name` | 1 | 15.7s |  |
| 77 | `capabilities_resolution` | 8 | 15.8s |  |
| 78 | `catch_references_registers` | 2 | 16.0s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 79 | `click_block` | 5 | 15.8s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 80 | `clip_constructors` | 8 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 81 | `clip_event_propagation_order` | 17 | 15.4s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 82 | `clip_events` | 19 | 15.5s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 83 | `clone_sprite_edittext` | 94 | 15.6s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 84 | `clone_sprite_types` | 24 | 15.3s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 85 | `closure_scope` | 7 | 15.3s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 86 | `coerce_to_primitive_resolve` | 17 | 15.5s | [46](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 87 | `color` | 57 | 15.6s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 88 | `color_transform` | 48 | 15.4s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 89 | `conflicting_instance_names` | 23 | 15.6s |  |
| 90 | `constructor_function` | 2 | 15.2s |  |
| 91 | `context_menu` | 39 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 92 | `context_menu_item` | 41 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 93 | `create_empty_movie_clip` | 3 | 15.1s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 94 | `cross_movie_root` | 10 | 15.3s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 95 | `custom_clip_methods` | 4 | 15.3s | [12](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 96 | `default_names` | 52 | 15.3s | [14](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 97 | `define_function2` | 8 | 15.2s |  |
| 98 | `define_function2_preload` | 13 | 16.9s |  |
| 99 | `define_function2_preload_order` | 4 | 15.5s |  |
| 100 | `define_function_case_sensitive` | 2 | 15.8s |  |
| 101 | `define_local` | 27 | 15.7s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 102 | `define_local_with_paths` | 54 | 15.4s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 103 | `delete` | 3 | 15.5s |  |
| 104 | `device_font_spacing` | 91 | 15.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 105 | `display_object_properties` | 2 | 15.9s |  |
| 106 | `divide_swf4` | 107 | 15.7s |  |
| 107 | `do_init_action` | 3 | 15.8s |  |
| 108 | `do_init_action_child` | 12 | 15.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 109 | `drag_drop` | 10 | 15.8s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 110 | `drag_over_from_outside` | 1 | 15.4s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 111 | `drag_over_without_startdrag` | 1 | 15.5s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 112 | `duplicate_movie_clip` | 20 | 15.8s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 113 | `duplicate_movie_clip_drawing` | 2 | 15.3s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 114 | `edittext_align` | 60 | 15.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_align_trailing_spaces_swf7` | 576 | 15.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_align_trailing_spaces_swf8` | 576 | 15.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_antialiastype` | 296 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_autosize` | 71 | 17.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_autosize_setter` | 20 | 16.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_bullet` | 30 | 16.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_default_format` | 221 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_default_format_font_style` | 335 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_focus_selection` | 2 | 15.7s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_font_size` | 45 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_hscroll` | 27 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_html_align_swf7` | 52 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_html_align_swf8` | 52 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_html_color` | 114 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_html_condensewhite_swf7` | 311 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_html_condensewhite_swf8` | 311 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_html_entity` | 4 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_html_roundtrip` | 17 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_html_swf6` | 5377 | 16.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_html_swf7` | 5377 | 16.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_swf8` | 5377 | 17.1s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_input` | 1 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_input_newlines` | 9 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_leading` | 9 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_letter_spacing` | 15 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_margins` | 25 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_newline_stripping` | 64 | 21.1s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_newlines` | 30 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_password` | 5 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_password_copy` | 4 | 16.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_paste_empty` | 2 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_place_caret` | 2 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_programmatic_focus` | 12 | 16.0s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_restrict` | 191 | 16.1s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_restrict_paste` | 5 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_scroll` | 54 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_stylesheet` | 325 | 16.7s | [57](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_tab_focus` | 13 | 16.0s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_tab_stops` | 60 | 16.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_tag_indent` | 31 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_text_height_leading` | 20 | 16.2s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_underline` | 40 | 16.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_width_height` | 103 | 17.0s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `empty_movieclip_can_attach_movies` | 11 | 16.1s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 159 | `enumerate` | 64 | 16.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 160 | `equals` | 32 | 16.2s |  |
| 161 | `equals2_swf5` | 926 | 17.8s |  |
| 162 | `equals2_swf6` | 926 | 18.0s |  |
| 163 | `equals2_swf7` | 926 | 17.9s |  |
| 164 | `equals_swf4` | 665 | 16.7s |  |
| 165 | `equals_swf4_alt` | 32 | 16.1s |  |
| 166 | `equals_swf5` | 32 | 16.0s |  |
| 167 | `error` | 58 | 16.2s |  |
| 168 | `escape` | 14 | 16.0s |  |
| 169 | `execution_order1` | 5 | 16.0s |  |
| 170 | `execution_order2` | 7 | 16.1s |  |
| 171 | `execution_order3` | 4 | 16.0s |  |
| 172 | `execution_order4` | 12 | 16.2s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 173 | `export_assets` | 3 | 15.8s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 174 | `extends_chain` | 134 | 16.5s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 175 | `extends_native_type` | 11 | 16.3s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 176 | `external_interface` | 84 | 16.4s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 177 | `external_interface_escapexml` | 26 | 16.4s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 178 | `external_interface_jsquotestring` | 21 | 17.7s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 179 | `external_interface_toas_basic` | 354 | 16.1s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 180 | `external_interface_toxml_array` | 25 | 15.8s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 181 | `external_interface_toxml_basic` | 179 | 16.0s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 182 | `external_interface_unescapexml` | 40 | 15.9s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 183 | `focus_keyboard_press` | 60 | 16.1s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 184 | `focus_mouse` | 45 | 15.7s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 185 | `focus_mouse_focusable` | 8 | 15.9s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 186 | `focus_mouse_rollout` | 4 | 15.7s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 187 | `focus_remove` | 33 | 15.5s |  |
| 188 | `focus_root_movie` | 2 | 15.5s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 189 | `focus_visibility_change` | 45 | 15.6s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 190 | `focusrect_focuslost` | 4 | 15.6s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 191 | `focusrect_mouse_swf8` | 0 | 16.2s |  |
| 192 | `focusrect_mouse_swf9` | 0 | 16.1s |  |
| 193 | `focusrect_property_swf5` | 1237 | 16.0s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 194 | `focusrect_property_swf6` | 1237 | 16.1s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 195 | `focusrect_property_swf7` | 1237 | 16.6s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 196 | `focusrect_swf5` | 6 | 16.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 197 | `focusrect_swf6` | 42 | 16.2s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 198 | `form_loader_encoding_1` | 1 | 16.0s |  |
| 199 | `frame_size_translated_negative` | 21 | 15.9s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 200 | `frame_size_translated_positive` | 21 | 15.9s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 201 | `function_as_function` | 35 | 15.7s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 202 | `function_base_clip` | 8 | 15.7s |  |
| 203 | `function_base_clip_readded` | 11 | 15.8s |  |
| 204 | `function_base_clip_removed` | 25 | 16.2s |  |
| 205 | `function_suppress_and_preload` | 28 | 16.1s |  |
| 206 | `funky_function_calls` | 56 | 16.2s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 207 | `get_bytes_total` | 4 | 16.1s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 208 | `get_variable_in_scope` | 29 | 16.4s |  |
| 209 | `getproperty` | 28 | 16.9s |  |
| 210 | `getproperty_swf4` | 28 | 15.6s |  |
| 211 | `getproperty_swf5` | 28 | 15.5s |  |
| 212 | `gettextextent` | 56 | 15.5s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 213 | `global_array` | 3 | 15.5s |  |
| 214 | `global_is_bare` | 7 | 15.5s |  |
| 215 | `global_swf5_6_7_8_9` | 1145 | 16.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 216 | `global_swf6_7_8` | 15 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 217 | `globals_swf5` | 304 | 15.8s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 218 | `globals_swf6` | 304 | 15.8s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 219 | `globals_swf7` | 304 | 15.9s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 220 | `globals_swf8` | 304 | 15.8s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 221 | `goto_advance1` | 6 | 15.5s |  |
| 222 | `goto_advance2` | 2 | 15.5s |  |
| 223 | `goto_both_ways1` | 3 | 15.6s |  |
| 224 | `goto_both_ways2` | 3 | 15.6s |  |
| 225 | `goto_execution_order` | 2 | 15.7s |  |
| 226 | `goto_execution_order2` | 2 | 15.8s |  |
| 227 | `goto_frame` | 12 | 15.5s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 228 | `goto_frame2` | 44 | 15.8s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 229 | `goto_frame_number` | 3 | 15.4s |  |
| 230 | `goto_label` | 17 | 15.4s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 231 | `goto_methods` | 40 | 15.4s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 232 | `goto_rewind1` | 1 | 15.3s |  |
| 233 | `goto_rewind2` | 3 | 15.2s |  |
| 234 | `goto_rewind3` | 2 | 15.2s |  |
| 235 | `greater_swf6` | 1175 | 17.1s |  |
| 236 | `greater_swf7` | 1175 | 17.1s |  |
| 237 | `greaterthan_swf5` | 1 | 15.1s |  |
| 238 | `greaterthan_swf8` | 1 | 15.1s |  |
| 239 | `has_own_property` | 32 | 15.2s |  |
| 240 | `hittest_lockroot` | 15 | 15.5s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 241 | `hittest_morph` | 70 | 15.3s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 242 | `hittest_morph_input` | 1 | 15.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 243 | `hittest_winding_rule` | 12 | 15.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 244 | `infinite_recursion_function` | 4 | 15.3s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 245 | `infinite_recursion_function_in_setter` | 131 | 15.2s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 246 | `infinite_recursion_virtual_property` | 67 | 15.3s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 247 | `init_array_invalid` | 4 | 15.5s |  |
| 248 | `init_object_invalid` | 4 | 15.5s |  |
| 249 | `init_object_order` | 15 | 15.6s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 250 | `input_dead_keys_windows` | 15 | 15.6s | [29](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 251 | `instanceof_coercions` | 88 | 15.8s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 252 | `interface_implements_op` | 47 | 16.1s | [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 253 | `is_finite` | 49 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 254 | `is_finite_swf6` | 49 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 255 | `is_prototype_of` | 89 | 15.6s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 256 | `issue_1086` | 1 | 15.4s |  |
| 257 | `issue_1104` | 2 | 15.5s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 258 | `issue_1671` | 0 | 15.4s |  |
| 259 | `issue_1906` | 4 | 15.4s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 260 | `issue_2166` | 9 | 15.4s |  |
| 261 | `issue_2870` | 3 | 15.6s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 262 | `issue_3169` | 2 | 15.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 263 | `issue_3446` | 1 | 15.4s |  |
| 264 | `issue_3522` | 2 | 15.4s |  |
| 265 | `issue_4377` | 2 | 15.4s |  |
| 266 | `issue_710` | 4 | 17.1s |  |
| 267 | `issue_768` | 3 | 15.6s | [30](ruffle-tests/_investigation/complete/issue_768.md) |
| 268 | `issue_9327` | 2 | 15.6s |  |
| 269 | `issue_9885` | 2 | 15.6s |  |
| 270 | `key_isToggled` | 9 | 15.4s |  |
| 271 | `lessthan` | 41 | 15.7s |  |
| 272 | `lessthan2_swf5` | 1226 | 17.7s |  |
| 273 | `lessthan2_swf6` | 1226 | 17.8s |  |
| 274 | `lessthan2_swf7` | 1226 | 17.8s |  |
| 275 | `lessthan_swf4` | 902 | 16.8s |  |
| 276 | `lessthan_swf4_alt` | 41 | 15.6s |  |
| 277 | `lessthan_swf5` | 41 | 15.7s |  |
| 278 | `loadmovie` | 2 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 279 | `loadmovie_fail` | 2 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 280 | `loadmovie_flashvars` | 4 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 281 | `loadmovie_method` | 2 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 282 | `loadmovie_registerclass` | 30 | 15.8s | [11](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 283 | `loadmovie_replace_root` | 5 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 284 | `loadmovie_var_persistence` | 8 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 285 | `loadmovienum` | 3 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 286 | `loadmovienum_cross_version_prototype` | 9 | 17.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 287 | `loadvariables` | 2 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 288 | `loadvariables2` | 8 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 289 | `loadvariablesnum` | 2 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 290 | `local_to_global` | 49 | 15.7s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 291 | `localconnection_properties` | 8 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 292 | `lock_root` | 1 | 15.6s |  |
| 293 | `logical_ops_swf4` | 90 | 15.7s |  |
| 294 | `logical_ops_swf8` | 108 | 15.7s |  |
| 295 | `looping` | 6 | 15.5s |  |
| 296 | `mask_reapply` | 0 | 15.5s |  |
| 297 | `mask_with_drawing` | 0 | 15.6s |  |
| 298 | `math_min_max` | 101 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 299 | `math_swf6` | 530 | 16.1s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 300 | `math_swf7` | 530 | 16.0s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 301 | `math_swf8` | 530 | 16.0s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 302 | `matrix` | 171 | 15.9s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 303 | `mcl_as_broadcaster` | 12 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 304 | `mcl_events_swf_version` | 232 | 16.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mcl_getprogress` | 30 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 306 | `mcl_loadclip` | 149 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 307 | `mcl_loadclip_properties` | 6 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 308 | `mcl_loadclip_replace_root` | 1 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 309 | `mcl_mislabeled_target` | 6 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 310 | `mcl_target_gif87a` | 6 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 311 | `mcl_target_gif89a` | 6 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mcl_target_jpg` | 6 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_target_png` | 6 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_unloadclip` | 5 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mouse_events` | 8 | 15.1s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 316 | `mouse_events_visible_enabled` | 12 | 15.3s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 317 | `mouse_hover_events_while_dragging` | 1 | 15.2s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 318 | `mouse_listeners` | 67 | 15.1s |  |
| 319 | `mouse_pos` | 665 | 15.1s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 320 | `mouse_pos_with_scale_factor` | 260 | 15.2s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 321 | `mouse_wheel_enabled` | 2 | 15.1s |  |
| 322 | `movieclip_begin_gradient_fill` | 0 | 15.7s |  |
| 323 | `movieclip_blend_mode_property` | 35 | 15.2s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_create_text_field` | 90 | 16.5s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 325 | `movieclip_default_state` | 69 | 16.7s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_depth_methods` | 98 | 16.7s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 327 | `movieclip_focusenabled` | 99 | 16.4s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_get_instance_at_depth` | 28 | 16.2s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_getbounds` | 191 | 16.1s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_gettextsnapshot` | 112 | 16.3s | [24](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_hittest` | 92 | 16.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_in_removed_button` | 4 | 16.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 333 | `movieclip_init_object` | 5 | 16.3s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 334 | `movieclip_invalid_get_bounds_1` | 75 | 16.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_invalid_get_bounds_2` | 75 | 17.2s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_invalid_get_bounds_3` | 13 | 16.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_invalid_get_bounds_4` | 13 | 16.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_invalid_get_bounds_5` | 11 | 16.6s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_invalid_get_bounds_6` | 10 | 41.3s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_invalid_get_bounds_7` | 10 | 41.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_invalid_get_bounds_8` | 11 | 16.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_line_gradient_style` | 0 | 16.7s |  |
| 343 | `movieclip_lockroot` | 29 | 16.9s | [35](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_name_from_timeline` | 13 | 15.1s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_prototype_extension` | 5 | 15.1s |  |
| 346 | `movieclip_setmask` | 14 | 15.3s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 347 | `moviecliploader_flashvars` | 4 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 348 | `mutable_this` | 18 | 15.2s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 349 | `named_shapes` | 14 | 15.3s |  |
| 350 | `nan_scale` | 9 | 15.5s |  |
| 351 | `native_double_construct` | 12 | 15.2s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 352 | `native_objects_swf7` | 84 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 353 | `native_objects_swf8` | 84 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 354 | `native_subclasses` | 191 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 355 | `nested_textfields_in_buttons` | 0 | 15.3s |  |
| 356 | `new_method_wrap` | 4 | 15.8s |  |
| 357 | `new_object_enumerate` | 7 | 15.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 358 | `new_object_wrap` | 4 | 15.4s |  |
| 359 | `o` | 3 | 15.6s |  |
| 360 | `object_constructor` | 33 | 15.7s |  |
| 361 | `object_function` | 32 | 15.5s |  |
| 362 | `object_properties` | 31 | 15.8s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 363 | `object_prototypes` | 74 | 15.7s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 364 | `object_resolve` | 38 | 15.9s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 365 | `object_string_coerce_swf5` | 62 | 15.7s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 366 | `object_string_coerce_swf6` | 68 | 15.8s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 367 | `on_construct` | 25 | 15.8s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 368 | `parse_float` | 74 | 15.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 369 | `parse_int` | 64 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 370 | `path_string` | 322 | 15.8s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 371 | `place_and_lookup` | 30 | 15.7s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 372 | `placeobject_occupied_depth` | 6 | 15.5s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 373 | `point` | 175 | 16.0s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 374 | `primitive_instanceof` | 37 | 15.6s |  |
| 375 | `primitive_type_globals` | 557 | 15.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 376 | `printjob_props_swf5` | 45 | 18.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 377 | `printjob_props_swf6` | 45 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 378 | `printjob_props_swf7` | 45 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 379 | `property_invalid_base_clip` | 36 | 15.7s |  |
| 380 | `prototype_delete` | 12 | 15.5s |  |
| 381 | `prototype_enumerate` | 5 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 382 | `prototype_properties` | 17 | 15.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 383 | `rectangle` | 745 | 16.4s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 384 | `recursive_prototypes` | 0 | 15.4s |  |
| 385 | `register_and_init_order` | 231 | 16.0s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 386 | `register_class` | 66 | 15.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 387 | `register_class_return_value` | 16 | 15.5s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 388 | `register_class_swf6` | 37 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 389 | `register_class_with_sound` | 11 | 15.5s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 390 | `register_globals_across_frames` | 15 | 15.5s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 391 | `register_underflow` | 26 | 15.4s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 392 | `remove_movie_clip` | 29 | 15.6s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 393 | `removed_clip_halts_script` | 15 | 15.9s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 394 | `removed_target_clip_scope` | 35 | 15.7s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 395 | `resolve_different_root` | 2 | 16.0s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 396 | `rewind_depth` | 30 | 15.5s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 397 | `root_button_mode` | 10 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 398 | `root_global_parent` | 6 | 15.5s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 399 | `root_onload` | 1 | 16.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 400 | `sandbox_type_local_file` | 1 | 17.3s |  |
| 401 | `sandbox_type_local_network` | 1 | 17.5s |  |
| 402 | `selection` | 454 | 17.3s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 403 | `selection_handlers` | 27 | 16.6s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 404 | `set_interval` | 27 | 17.3s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 405 | `set_variable_scope` | 58 | 16.9s |  |
| 406 | `single_frame` | 1 | 16.2s |  |
| 407 | `slash_syntax` | 14 | 15.9s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 408 | `sound` | 628 | 16.3s | [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 409 | `sound_props_swf5` | 68 | 15.6s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 410 | `sound_props_swf6` | 68 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 411 | `sound_start_load` | 0 | 15.3s |  |
| 412 | `stage_display_state` | 16 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 413 | `stage_object_children` | 83 | 15.4s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 414 | `stage_object_enumerate` | 4 | 15.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 415 | `stage_object_properties` | 241 | 15.6s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 416 | `stage_object_properties_get_var` | 5 | 15.3s |  |
| 417 | `stage_object_properties_swf6` | 231 | 15.5s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 418 | `stage_property_representation` | 586 | 15.3s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 419 | `stage_scale_mode` | 39 | 15.2s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 420 | `strictequals_swf6` | 902 | 16.8s |  |
| 421 | `strictly_equals` | 7 | 15.3s |  |
| 422 | `string_coercion` | 117 | 15.5s | [55](ruffle-tests/_investigation/complete/string_coercion.md) |
| 423 | `string_methods` | 285 | 15.9s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 424 | `string_methods_negative_args` | 240 | 15.4s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 425 | `string_methods_swfv5` | 275 | 16.0s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 426 | `string_ops_swf6` | 95 | 15.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 427 | `string_paths_basic` | 4 | 15.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 428 | `string_paths_eval` | 4 | 15.4s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 429 | `string_paths_eval2` | 7 | 15.6s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 430 | `string_paths_hidden` | 54 | 15.4s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 431 | `string_paths_keyevents` | 0 | 15.3s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 432 | `string_paths_other` | 36 | 15.4s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 433 | `string_paths_timer` | 0 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 434 | `string_paths_unload` | 1 | 15.2s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 435 | `string_paths_variable_alias` | 4 | 15.2s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 436 | `string_paths_variable_scopes` | 5 | 15.3s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 437 | `stylesheet` | 283 | 16.1s |  |
| 438 | `stylesheet_transform` | 750 | 16.1s |  |
| 439 | `super_edge_cases` | 39 | 15.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 440 | `swf4_actions_bool` | 96 | 15.3s |  |
| 441 | `swf4_actions_coercion_order` | 158 | 15.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 442 | `swf4_bool` | 4 | 15.2s |  |
| 443 | `swf4_function_calls` | 7 | 15.3s |  |
| 444 | `swf5_encoding` | 3 | 15.3s |  |
| 445 | `swf5_global_funcs` | 232 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 446 | `swf5_no_closure` | 19 | 15.3s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 447 | `swf5_to_6_cross_call` | 29 | 15.5s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 448 | `swf6_case_insensitive` | 42 | 15.2s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 449 | `swf6_global_funcs` | 232 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 450 | `swf6_string_as_bool` | 15 | 15.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 451 | `swf6_to_5_cross_call` | 29 | 15.4s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 452 | `swf7_case_sensitive` | 44 | 15.4s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 453 | `swf7_global_funcs` | 232 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 454 | `tab_ordering_automatic_basic` | 92 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 455 | `tab_ordering_automatic_order_grid` | 21 | 15.2s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 456 | `tab_ordering_automatic_order_same_position` | 12 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 457 | `tab_ordering_children` | 208 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 458 | `tab_ordering_custom_basic` | 71 | 15.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 459 | `tab_ordering_custom_duplicate_index` | 22 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 460 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 461 | `tab_ordering_custom_m1` | 29 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 462 | `tab_ordering_events` | 150 | 15.8s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 463 | `tab_ordering_events_mouse` | 65 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 464 | `tab_ordering_movieclip_enabled_default` | 462 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 465 | `tab_ordering_properties_tab_index_edge_case` | 4 | 17.3s |  |
| 466 | `tab_ordering_reverse` | 51 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 467 | `tab_ordering_tabbable` | 47 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 468 | `target_clip_removed` | 5 | 15.6s | [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 469 | `target_clip_swf5` | 2 | 15.5s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 470 | `target_clip_swf6` | 2 | 15.4s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 471 | `target_path` | 14 | 15.5s |  |
| 472 | `tell_target` | 37 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 473 | `tell_target_invalid` | 6 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 474 | `tell_target_invalid_swf6` | 5 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 475 | `text_blocks_clicks` | 4 | 15.6s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 476 | `text_format` | 1146 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 477 | `text_format_display` | 21 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 478 | `text_format_font_max_length` | 2 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 479 | `text_format_get_text_extent_undefined_width` | 10 | 15.5s |  |
| 480 | `text_format_rounding_swf7` | 840 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 481 | `text_format_rounding_swf8` | 840 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 482 | `textfield_background_color` | 11 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 483 | `textfield_border_color` | 11 | 15.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 484 | `textfield_cache_as_bitmap` | 1 | 15.5s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 485 | `textfield_maxchars` | 3 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 486 | `textfield_properties` | 44 | 15.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 487 | `textfield_props_swf5` | 175 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 488 | `textfield_props_swf6` | 210 | 15.5s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 489 | `textfield_props_swf7` | 210 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 490 | `textfield_props_swf8` | 210 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 491 | `textfield_text` | 7 | 15.6s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 492 | `textfield_variable` | 81 | 15.9s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 493 | `textsnapshot_available_text` | 20 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 494 | `textsnapshot_findtext` | 44 | 16.3s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 495 | `textsnapshot_gettext` | 55 | 16.4s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 496 | `textsnapshot_props_swf5` | 56 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `textsnapshot_props_swf6` | 56 | 15.8s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `textsnapshot_text_order` | 1 | 15.7s | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 499 | `this_scoping` | 52 | 15.7s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 500 | `this_swf5` | 41 | 15.5s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 501 | `this_swf6` | 41 | 15.5s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 502 | `this_swf7` | 41 | 15.4s | [65](ruffle-tests/_investigation/complete/this_swf7.md) |
| 503 | `timeline_function_def` | 7 | 15.4s |  |
| 504 | `timer_run_actions` | 18 | 15.8s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 505 | `trace` | 8 | 15.4s |  |
| 506 | `transform` | 70 | 15.5s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 507 | `try_catch_finally` | 118 | 15.5s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 508 | `try_finally_simple` | 16 | 15.2s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 509 | `typeof` | 22 | 15.2s |  |
| 510 | `typeof_globals` | 7 | 15.1s |  |
| 511 | `uncaught_exception` | 1 | 15.1s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 512 | `uncaught_exception_bubbled` | 1 | 15.1s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 513 | `undefined_to_string_swf6` | 4 | 15.3s |  |
| 514 | `unescape` | 43 | 15.2s |  |
| 515 | `unload` | 52 | 15.4s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 516 | `unload_clip_event` | 4 | 15.2s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 517 | `unloadmovie` | 4 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 518 | `unloadmovie_method` | 3 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 519 | `unloadmovienum` | 13 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 520 | `use_hand_cursor` | 8 | 15.6s |  |
| 521 | `variable_args` | 5 | 15.8s |  |
| 522 | `waitforframe` | 7 | 15.4s |  |
| 523 | `waitforframe2` | 16 | 17.5s |  |
| 524 | `watch` | 117 | 15.8s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 525 | `watch_textfield` | 12 | 15.4s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 526 | `watch_virtual_property_proto` | 2 | 15.8s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 527 | `with` | 49 | 15.6s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 528 | `with_return` | 2 | 15.4s |  |
| 529 | `with_variable_scopes` | 43 | 15.5s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 530 | `xml` | 15 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_append_child` | 28 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_append_child_with_parent` | 20 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_attributes_read` | 4 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_cdata` | 11 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 535 | `xml_child_nodes_edge_cases` | 4 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 536 | `xml_clone_expandos` | 19 | 15.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 537 | `xml_first_last_child` | 8 | 15.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 538 | `xml_has_child_nodes` | 3 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_idmap` | 21 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 540 | `xml_ignore_comments` | 21 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 541 | `xml_ignore_white` | 34 | 17.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 542 | `xml_insert_before` | 20 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_inspect_createmethods` | 15 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_inspect_doctype` | 7 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 545 | `xml_inspect_parsexml` | 62 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 546 | `xml_inspect_xmldecl` | 7 | 16.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 547 | `xml_namespaces` | 203 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_parent_and_child` | 5 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_remove_node` | 22 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_reparenting` | 14 | 16.1s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_siblings` | 10 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_to_string` | 13 | 15.9s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_to_string_comment` | 1 | 15.8s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_unescaping` | 23 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 555 | `xmlnode_proto` | 1 | 16.0s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [13](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 7 | `tab_ordering_properties` | 93.9% | 275 | 293 | 18 | [60](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 92.0% | 311 | 338 | 27 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `clone_sprite_edittext_dynamic` | 91.9% | 79 | 86 | 7 | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 10 | `bitmap_data_copypixels` | 88.2% | 15 | 17 | 2 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 11 | `bitmap_data_draw_cliprect` | 69.2% | 9 | 13 | 4 |  |
| 12 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 13 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 14 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 15 | `issue_2030` | 50.0% | 2 | 4 | 2 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 18.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 31.8s | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 45.2s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**61 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [13](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 7 | `tab_ordering_properties` | 93.9% | 275/293 | 293 | 293 | [60](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 92.0% | 311/338 | 338 | 338 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `clone_sprite_edittext_dynamic` | 91.9% | 79/86 | 86 | 86 | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 10 | `bitmap_data_copypixels` | 88.2% | 15/17 | 17 | 17 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 11 | `bitmap_data_draw_cliprect` | 69.2% | 9/13 | 13 | 13 |  |
| 12 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 13 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 14 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 15 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 16 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `unload_nested_child` | 40.0% | 2/5 | 5 | 5 | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 18 | `issue_2084` | 37.5% | 6/16 | 8 | 16 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 19 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 20 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 21 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 22 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 23 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 25 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 26 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 27 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 28 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 29 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 30 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 31 | `bitmap_data_pixeldissolve` | 7.6% | 82/1075 | 1055 | 1075 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 32 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 33 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 34 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 35 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 36 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 37 | `global_instance_decls` | 2.4% | 18/758 | 695 | 758 | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 38 | `global_proto_decls_delete` | 2.2% | 91/4158 | 705 | 4158 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 39 | `global_proto_decls` | 2.1% | 93/4497 | 1266 | 4497 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 40 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 41 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 42 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 43 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 44 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 45 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 46 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 47 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) |
| 48 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 49 | `geturl` | 0.0% | 0/7 | 0 | 7 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 50 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 51 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 52 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 53 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 54 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 55 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 56 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 57 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 58 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 59 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 60 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 61 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) | 17 | 14 | 3 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 7 | 1 |
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
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 5 | 2 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 27 | 4 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 0 | 23 |
| 28 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 30 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 42 | 6 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 36 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) | 58 | 51 | 7 |
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
| 56 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 12 | 1 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 0 | 1 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 17 | 2 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 67 | 3 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 10 | 6 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 11 | 1 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 152 | 151 | 1 |
