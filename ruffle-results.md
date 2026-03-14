# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-14 20:27 UTC

**Git SHA**: `81898206a3`

**Run Duration**: 163m 8s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 618 |
| Passing | **545** (88.2%) |
| Failing | 73 |
| Total expected lines | 91484 |
| Matching lines | 78257 (85.5%) |
| Mismatched lines | 13227 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 70 | 95.9% |
| Runtime Segfault | 2 | 2.7% |
| Timeout | 1 | 1.4% |

## Passing Tests

**545 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 16.0s |  |
| 2 | `action_to_integer` | 28 | 15.9s |  |
| 3 | `add` | 28 | 15.8s |  |
| 4 | `add2` | 354 | 15.9s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.8s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.7s |  |
| 7 | `add_swf5` | 28 | 15.8s |  |
| 8 | `arguments` | 127 | 15.8s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 15.8s |  |
| 11 | `array_constructor` | 30 | 15.7s |  |
| 12 | `array_enumerate` | 4 | 15.8s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 15.8s |  |
| 14 | `array_properties` | 36 | 15.7s |  |
| 15 | `array_prototyping` | 12 | 15.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.8s |  |
| 17 | `array_sort` | 161 | 16.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 15.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 15.9s |  |
| 20 | `array_trivial` | 209 | 15.9s |  |
| 21 | `as1_constructor_v6` | 35 | 15.7s |  |
| 22 | `as1_constructor_v7` | 35 | 16.6s |  |
| 23 | `as2_oop` | 13 | 16.2s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 16.2s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 15.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 15.7s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 15.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 15.5s |  |
| 29 | `as_broadcaster_undef` | 89 | 15.8s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 15.9s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 15.9s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 15.7s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 15.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 15.5s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 15.5s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 15.3s |  |
| 37 | `as_transformed_flag` | 20 | 15.5s |  |
| 38 | `asnative` | 34 | 15.8s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 15.7s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 15.6s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 15.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 16.8s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 15.7s |  |
| 44 | `bitand` | 1058 | 18.3s |  |
| 45 | `bitmap_data_colortransform` | 0 | 15.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_compare` | 40 | 15.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 47 | `bitmap_data_fillrect` | 0 | 15.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_max_size_swf10` | 12 | 16.4s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_max_size_swf9` | 10 | 16.4s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 50 | `bitmap_data_noise` | 631 | 16.0s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 51 | `bitmap_data_perlinnoise` | 0 | 16.4s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 52 | `bitmap_data_pixeldissolve_image` | 0 | 15.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 53 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 54 | `bitor` | 1058 | 18.3s |  |
| 55 | `biturshift` | 14 | 15.3s |  |
| 56 | `biturshift_swf8` | 14 | 16.5s |  |
| 57 | `bitxor` | 1058 | 17.8s |  |
| 58 | `boxed_primitives` | 24 | 15.2s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 59 | `button_children` | 8 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_goto` | 4 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_key_events` | 14 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_key_events_special` | 45 | 16.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress` | 3 | 15.5s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_press` | 25 | 15.4s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_keypress_vs_tab` | 20 | 15.5s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_keypress_vs_textinput` | 4 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_order` | 2 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_properties_special_cases` | 22 | 15.6s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_v5` | 18 | 15.3s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_v6` | 18 | 15.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `call` | 63 | 15.3s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 72 | `call_method_empty_name` | 1 | 15.1s |  |
| 73 | `capabilities_resolution` | 8 | 15.1s |  |
| 74 | `catch_references_registers` | 2 | 15.0s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 75 | `click_block` | 5 | 15.1s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 76 | `clip_constructors` | 8 | 15.0s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 77 | `clip_event_propagation_order` | 17 | 17.0s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 78 | `clip_events` | 19 | 15.7s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 79 | `clone_sprite_types` | 24 | 15.3s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 80 | `closure_scope` | 7 | 15.4s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 81 | `coerce_to_primitive_resolve` | 17 | 15.4s | [46](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 82 | `color` | 57 | 15.6s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 83 | `color_transform` | 48 | 15.4s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 84 | `conflicting_instance_names` | 23 | 15.5s |  |
| 85 | `constructor_function` | 2 | 15.3s |  |
| 86 | `context_menu` | 39 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 87 | `context_menu_item` | 41 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 88 | `create_empty_movie_clip` | 3 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `cross_movie_root` | 10 | 15.5s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 90 | `custom_clip_methods` | 4 | 15.3s | [12](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 91 | `default_names` | 52 | 15.4s | [14](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 92 | `define_function2` | 8 | 15.5s |  |
| 93 | `define_function2_preload` | 13 | 15.2s |  |
| 94 | `define_function2_preload_order` | 4 | 16.5s |  |
| 95 | `define_function_case_sensitive` | 2 | 15.0s |  |
| 96 | `define_local` | 27 | 15.0s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 97 | `define_local_with_paths` | 54 | 15.0s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 98 | `delete` | 3 | 15.2s |  |
| 99 | `device_font_spacing` | 91 | 15.1s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 100 | `display_object_properties` | 2 | 14.9s |  |
| 101 | `divide_swf4` | 107 | 15.2s |  |
| 102 | `do_init_action` | 3 | 15.2s |  |
| 103 | `do_init_action_child` | 12 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 104 | `drag_drop` | 10 | 15.0s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 105 | `drag_over_from_outside` | 1 | 15.3s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 106 | `drag_over_without_startdrag` | 1 | 15.1s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 107 | `duplicate_movie_clip` | 20 | 15.1s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 108 | `duplicate_movie_clip_drawing` | 2 | 15.0s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 109 | `edittext_align` | 60 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_align_trailing_spaces_swf7` | 576 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_align_trailing_spaces_swf8` | 576 | 14.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_antialiastype` | 296 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_autosize` | 71 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_autosize_setter` | 20 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_bullet` | 30 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_default_format` | 221 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_default_format_font_style` | 335 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_focus_selection` | 2 | 15.2s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_font_size` | 45 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_hscroll` | 27 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_align_swf7` | 52 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_align_swf8` | 52 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_color` | 114 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_condensewhite_swf7` | 311 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_condensewhite_swf8` | 311 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_html_entity` | 4 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_html_roundtrip` | 17 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_html_swf7` | 5377 | 16.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_html_swf8` | 5377 | 16.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_input` | 1 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_input_newlines` | 9 | 16.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_leading` | 9 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_letter_spacing` | 15 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_margins` | 25 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_newline_stripping` | 64 | 20.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_newlines` | 30 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_password` | 5 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_password_copy` | 4 | 15.0s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_paste_empty` | 2 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_place_caret` | 2 | 15.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_programmatic_focus` | 12 | 15.1s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_restrict` | 191 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_restrict_paste` | 5 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_scroll` | 54 | 15.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_stylesheet` | 325 | 16.1s | [57](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_tab_focus` | 13 | 15.2s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `edittext_tab_stops` | 60 | 15.4s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 148 | `edittext_tag_indent` | 31 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 149 | `edittext_text_height_leading` | 20 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 150 | `edittext_underline` | 40 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 151 | `edittext_width_height` | 103 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 152 | `empty_movieclip_can_attach_movies` | 11 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 153 | `enumerate` | 64 | 15.3s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 154 | `equals` | 32 | 15.3s |  |
| 155 | `equals2_swf5` | 926 | 16.8s |  |
| 156 | `equals2_swf6` | 926 | 16.9s |  |
| 157 | `equals2_swf7` | 926 | 16.9s |  |
| 158 | `equals_swf4` | 665 | 15.9s |  |
| 159 | `equals_swf4_alt` | 32 | 15.2s |  |
| 160 | `equals_swf5` | 32 | 15.2s |  |
| 161 | `error` | 58 | 15.2s |  |
| 162 | `escape` | 14 | 15.2s |  |
| 163 | `execution_order1` | 5 | 15.3s |  |
| 164 | `execution_order2` | 7 | 15.2s |  |
| 165 | `execution_order3` | 4 | 15.3s |  |
| 166 | `execution_order4` | 12 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 167 | `export_assets` | 3 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 168 | `extends_chain` | 134 | 15.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 169 | `extends_native_type` | 11 | 15.3s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 170 | `external_interface` | 84 | 15.5s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_escapexml` | 26 | 15.2s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `external_interface_jsquotestring` | 21 | 15.2s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 173 | `external_interface_toas_basic` | 354 | 19.6s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 174 | `external_interface_toxml_array` | 25 | 16.1s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 175 | `external_interface_toxml_basic` | 179 | 16.3s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 176 | `external_interface_unescapexml` | 40 | 16.1s | [18](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 177 | `focus_keyboard_press` | 60 | 16.5s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 178 | `focus_mouse` | 45 | 16.3s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 179 | `focus_mouse_focusable` | 8 | 17.0s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 180 | `focus_mouse_rollout` | 4 | 16.5s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 181 | `focus_remove` | 33 | 16.8s |  |
| 182 | `focus_root_movie` | 2 | 16.5s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 183 | `focus_visibility_change` | 45 | 17.0s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 184 | `focusrect_focuslost` | 4 | 17.2s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 185 | `focusrect_mouse_swf8` | 0 | 16.9s |  |
| 186 | `focusrect_mouse_swf9` | 0 | 17.1s |  |
| 187 | `focusrect_property_swf5` | 1237 | 16.1s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 188 | `focusrect_property_swf6` | 1237 | 16.1s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 189 | `focusrect_property_swf7` | 1237 | 15.8s | [19](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 190 | `focusrect_swf5` | 6 | 16.0s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 191 | `focusrect_swf6` | 42 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 192 | `form_loader_encoding_1` | 1 | 15.6s |  |
| 193 | `frame_size_translated_negative` | 21 | 15.8s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 194 | `frame_size_translated_positive` | 21 | 16.2s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 195 | `function_as_function` | 35 | 16.2s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 196 | `function_base_clip` | 8 | 16.0s |  |
| 197 | `function_base_clip_readded` | 11 | 15.9s |  |
| 198 | `function_base_clip_removed` | 25 | 15.8s |  |
| 199 | `function_suppress_and_preload` | 28 | 15.7s |  |
| 200 | `funky_function_calls` | 56 | 15.9s | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 201 | `get_bytes_total` | 4 | 15.7s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 202 | `get_variable_in_scope` | 29 | 16.0s |  |
| 203 | `getproperty` | 28 | 15.6s |  |
| 204 | `getproperty_swf4` | 28 | 16.1s |  |
| 205 | `getproperty_swf5` | 28 | 15.9s |  |
| 206 | `gettextextent` | 56 | 15.8s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 207 | `global_array` | 3 | 15.3s |  |
| 208 | `global_is_bare` | 7 | 15.4s |  |
| 209 | `global_swf5_6_7_8_9` | 1145 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 210 | `global_swf6_7_8` | 15 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 211 | `globals_swf5` | 304 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 212 | `globals_swf6` | 304 | 15.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 213 | `globals_swf7` | 304 | 15.6s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 214 | `globals_swf8` | 304 | 15.8s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 215 | `goto_advance1` | 6 | 15.3s |  |
| 216 | `goto_advance2` | 2 | 15.1s |  |
| 217 | `goto_both_ways1` | 3 | 15.0s |  |
| 218 | `goto_both_ways2` | 3 | 15.1s |  |
| 219 | `goto_execution_order` | 2 | 15.0s |  |
| 220 | `goto_execution_order2` | 2 | 15.1s |  |
| 221 | `goto_frame` | 12 | 15.3s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 222 | `goto_frame2` | 44 | 15.3s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 223 | `goto_frame_number` | 3 | 14.9s |  |
| 224 | `goto_label` | 17 | 15.0s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 225 | `goto_methods` | 40 | 14.8s | [21](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 226 | `goto_rewind1` | 1 | 14.9s |  |
| 227 | `goto_rewind2` | 3 | 14.8s |  |
| 228 | `goto_rewind3` | 2 | 14.8s |  |
| 229 | `greater_swf6` | 1175 | 16.9s |  |
| 230 | `greater_swf7` | 1175 | 16.9s |  |
| 231 | `greaterthan_swf5` | 1 | 14.8s |  |
| 232 | `greaterthan_swf8` | 1 | 14.8s |  |
| 233 | `has_own_property` | 32 | 14.8s |  |
| 234 | `hittest_lockroot` | 15 | 15.0s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 235 | `hittest_morph` | 70 | 14.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 236 | `hittest_morph_input` | 1 | 14.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 237 | `hittest_winding_rule` | 12 | 14.9s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 238 | `infinite_recursion_function` | 4 | 14.9s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 239 | `infinite_recursion_function_in_setter` | 131 | 14.7s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 240 | `infinite_recursion_virtual_property` | 67 | 14.6s | [28](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 241 | `init_array_invalid` | 4 | 14.7s |  |
| 242 | `init_object_invalid` | 4 | 16.7s |  |
| 243 | `init_object_order` | 15 | 15.5s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 244 | `input_dead_keys_windows` | 15 | 15.5s | [29](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 245 | `instanceof_coercions` | 88 | 15.6s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 246 | `interface_implements_op` | 47 | 15.9s | [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 247 | `is_finite` | 49 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 248 | `is_finite_swf6` | 49 | 15.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 249 | `is_prototype_of` | 89 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 250 | `issue_1086` | 1 | 15.2s |  |
| 251 | `issue_1104` | 2 | 15.4s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 252 | `issue_1671` | 0 | 15.2s |  |
| 253 | `issue_1906` | 4 | 15.3s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 254 | `issue_2166` | 9 | 15.2s |  |
| 255 | `issue_2870` | 3 | 15.3s | [31](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 256 | `issue_3169` | 2 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 257 | `issue_3446` | 1 | 15.3s |  |
| 258 | `issue_3522` | 2 | 15.3s |  |
| 259 | `issue_4377` | 2 | 15.1s |  |
| 260 | `issue_710` | 4 | 15.1s |  |
| 261 | `issue_768` | 3 | 15.5s | [30](ruffle-tests/_investigation/complete/issue_768.md) |
| 262 | `issue_9327` | 2 | 15.1s |  |
| 263 | `issue_9885` | 2 | 15.0s |  |
| 264 | `key_isToggled` | 9 | 14.9s |  |
| 265 | `lessthan` | 41 | 15.0s |  |
| 266 | `lessthan2_swf5` | 1226 | 16.9s |  |
| 267 | `lessthan2_swf6` | 1226 | 16.9s |  |
| 268 | `lessthan2_swf7` | 1226 | 16.9s |  |
| 269 | `lessthan_swf4` | 902 | 16.0s |  |
| 270 | `lessthan_swf4_alt` | 41 | 14.9s |  |
| 271 | `lessthan_swf5` | 41 | 14.9s |  |
| 272 | `loadmovie` | 2 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 273 | `loadmovie_fail` | 2 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 274 | `loadmovie_flashvars` | 4 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 275 | `loadmovie_method` | 2 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 276 | `loadmovie_registerclass` | 30 | 15.1s | [11](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 277 | `loadmovie_replace_root` | 5 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 278 | `loadmovie_var_persistence` | 8 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 279 | `loadmovienum` | 3 | 14.8s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 280 | `loadmovienum_cross_version_prototype` | 9 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 281 | `loadvariables` | 2 | 17.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 282 | `loadvariables2` | 8 | 16.0s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 283 | `loadvariablesnum` | 2 | 16.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 284 | `local_to_global` | 49 | 16.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 285 | `localconnection_properties` | 8 | 16.0s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 286 | `lock_root` | 1 | 15.9s |  |
| 287 | `logical_ops_swf4` | 90 | 16.0s |  |
| 288 | `logical_ops_swf8` | 108 | 16.1s |  |
| 289 | `looping` | 6 | 16.0s |  |
| 290 | `mask_reapply` | 0 | 15.8s |  |
| 291 | `mask_with_drawing` | 0 | 15.9s |  |
| 292 | `math_min_max` | 101 | 15.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 293 | `math_swf6` | 530 | 16.3s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 294 | `math_swf7` | 530 | 16.1s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 295 | `math_swf8` | 530 | 16.1s | [36](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 296 | `matrix` | 171 | 15.9s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 297 | `mcl_as_broadcaster` | 12 | 15.7s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_events_swf_version` | 232 | 16.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 299 | `mcl_getprogress` | 30 | 16.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 300 | `mcl_loadclip` | 149 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 301 | `mcl_loadclip_properties` | 6 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 302 | `mcl_loadclip_replace_root` | 1 | 15.3s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 303 | `mcl_mislabeled_target` | 6 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 304 | `mcl_target_gif87a` | 6 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mcl_target_gif89a` | 6 | 15.6s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 306 | `mcl_target_jpg` | 6 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 307 | `mcl_target_png` | 6 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 308 | `mcl_unloadclip` | 5 | 15.2s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 309 | `mouse_events` | 8 | 15.1s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 310 | `mouse_events_visible_enabled` | 12 | 15.3s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 311 | `mouse_hover_events_while_dragging` | 1 | 15.3s | [15](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 312 | `mouse_listeners` | 67 | 15.1s |  |
| 313 | `mouse_pos` | 665 | 15.0s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 314 | `mouse_pos_with_scale_factor` | 260 | 15.1s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 315 | `mouse_wheel_enabled` | 2 | 15.1s |  |
| 316 | `movieclip_begin_gradient_fill` | 0 | 15.6s |  |
| 317 | `movieclip_blend_mode_property` | 35 | 15.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 318 | `movieclip_create_text_field` | 90 | 15.2s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 319 | `movieclip_default_state` | 69 | 16.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_depth_methods` | 98 | 15.4s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 321 | `movieclip_focusenabled` | 99 | 15.3s | [20](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 322 | `movieclip_get_instance_at_depth` | 28 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 323 | `movieclip_getbounds` | 191 | 15.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_gettextsnapshot` | 112 | 15.6s | [24](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_hittest` | 92 | 15.5s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_in_removed_button` | 4 | 15.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 327 | `movieclip_init_object` | 5 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 328 | `movieclip_invalid_get_bounds_1` | 75 | 15.8s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_invalid_get_bounds_2` | 75 | 16.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_invalid_get_bounds_3` | 13 | 16.6s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_invalid_get_bounds_4` | 13 | 16.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_invalid_get_bounds_5` | 11 | 16.1s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 333 | `movieclip_invalid_get_bounds_8` | 11 | 16.4s | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 334 | `movieclip_line_gradient_style` | 0 | 16.7s |  |
| 335 | `movieclip_lockroot` | 29 | 16.1s | [35](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_name_from_timeline` | 13 | 14.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_prototype_extension` | 5 | 14.9s |  |
| 338 | `movieclip_setmask` | 14 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 339 | `moviecliploader_flashvars` | 4 | 14.9s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 340 | `mutable_this` | 18 | 14.9s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 341 | `named_shapes` | 14 | 14.8s |  |
| 342 | `nan_scale` | 9 | 14.9s |  |
| 343 | `native_double_construct` | 12 | 14.9s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 344 | `native_objects_swf7` | 84 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 345 | `native_objects_swf8` | 84 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 346 | `native_subclasses` | 191 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 347 | `nested_textfields_in_buttons` | 0 | 14.9s |  |
| 348 | `new_method_wrap` | 4 | 18.0s |  |
| 349 | `new_object_enumerate` | 7 | 16.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 350 | `new_object_wrap` | 4 | 16.2s |  |
| 351 | `o` | 3 | 16.3s |  |
| 352 | `object_constructor` | 33 | 16.1s |  |
| 353 | `object_function` | 32 | 16.5s |  |
| 354 | `object_properties` | 31 | 16.4s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 355 | `object_prototypes` | 74 | 16.5s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 356 | `object_resolve` | 38 | 17.0s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 357 | `object_string_coerce_swf5` | 62 | 17.1s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 358 | `object_string_coerce_swf6` | 68 | 17.7s | [42](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 359 | `on_construct` | 25 | 17.6s | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 360 | `parse_float` | 74 | 17.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 361 | `parse_int` | 64 | 17.7s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 362 | `path_string` | 322 | 16.8s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 363 | `place_and_lookup` | 30 | 17.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 364 | `placeobject_occupied_depth` | 6 | 16.9s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 365 | `point` | 175 | 17.4s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 366 | `primitive_instanceof` | 37 | 17.0s |  |
| 367 | `primitive_type_globals` | 557 | 16.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 368 | `printjob_props_swf5` | 45 | 15.1s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 369 | `printjob_props_swf6` | 45 | 14.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 370 | `printjob_props_swf7` | 45 | 14.9s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 371 | `property_invalid_base_clip` | 36 | 14.9s |  |
| 372 | `prototype_delete` | 12 | 14.9s |  |
| 373 | `prototype_enumerate` | 5 | 14.9s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 374 | `prototype_properties` | 17 | 14.9s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 375 | `rectangle` | 745 | 15.6s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 376 | `recursive_prototypes` | 0 | 14.8s |  |
| 377 | `register_and_init_order` | 231 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 378 | `register_class` | 66 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 379 | `register_class_return_value` | 16 | 15.0s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 380 | `register_class_swf6` | 37 | 15.1s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 381 | `register_class_with_sound` | 11 | 15.2s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 382 | `register_globals_across_frames` | 15 | 15.1s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 383 | `register_underflow` | 26 | 14.9s | [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 384 | `remove_movie_clip` | 29 | 15.0s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 385 | `removed_clip_halts_script` | 15 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 386 | `removed_target_clip_scope` | 35 | 15.1s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 387 | `resolve_different_root` | 2 | 16.4s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 388 | `rewind_depth` | 30 | 16.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 389 | `root_button_mode` | 10 | 15.9s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 390 | `root_global_parent` | 6 | 15.8s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 391 | `root_onload` | 1 | 15.6s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 392 | `sandbox_type_local_file` | 1 | 15.9s |  |
| 393 | `sandbox_type_local_network` | 1 | 15.8s |  |
| 394 | `selection` | 454 | 16.3s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 395 | `selection_handlers` | 27 | 16.2s | [51](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 396 | `set_interval` | 27 | 16.1s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 397 | `set_variable_scope` | 58 | 15.9s |  |
| 398 | `single_frame` | 1 | 15.7s |  |
| 399 | `slash_syntax` | 14 | 15.8s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 400 | `sound` | 628 | 15.9s | [52](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 401 | `sound_props_swf5` | 68 | 15.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 402 | `sound_props_swf6` | 68 | 15.5s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 403 | `sound_start_load` | 0 | 15.2s |  |
| 404 | `stage_display_state` | 16 | 15.0s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 405 | `stage_object_children` | 83 | 15.0s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 406 | `stage_object_enumerate` | 4 | 15.2s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 407 | `stage_object_properties` | 241 | 15.6s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 408 | `stage_object_properties_get_var` | 5 | 15.1s |  |
| 409 | `stage_object_properties_swf6` | 231 | 15.5s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 410 | `stage_property_representation` | 586 | 15.0s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 411 | `stage_scale_mode` | 39 | 15.6s | [53](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 412 | `strictequals_swf6` | 902 | 16.6s |  |
| 413 | `strictly_equals` | 7 | 15.0s |  |
| 414 | `string_coercion` | 117 | 15.3s | [55](ruffle-tests/_investigation/complete/string_coercion.md) |
| 415 | `string_methods` | 285 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 416 | `string_methods_negative_args` | 240 | 15.5s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 417 | `string_methods_swfv5` | 275 | 15.7s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 418 | `string_ops_swf6` | 95 | 15.0s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 419 | `string_paths_basic` | 4 | 15.0s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 420 | `string_paths_eval2` | 7 | 17.2s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 421 | `string_paths_hidden` | 54 | 15.3s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 422 | `string_paths_keyevents` | 0 | 15.1s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 423 | `string_paths_other` | 36 | 15.4s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 424 | `string_paths_timer` | 0 | 15.2s | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 425 | `string_paths_unload` | 1 | 15.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 426 | `string_paths_variable_alias` | 4 | 15.1s | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 427 | `string_paths_variable_scopes` | 5 | 15.2s | [16](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 428 | `stylesheet` | 283 | 16.0s |  |
| 429 | `stylesheet_transform` | 750 | 16.1s |  |
| 430 | `super_edge_cases` | 39 | 15.4s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 431 | `swf4_actions_bool` | 96 | 15.3s |  |
| 432 | `swf4_actions_coercion_order` | 158 | 15.3s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 433 | `swf4_bool` | 4 | 15.2s |  |
| 434 | `swf4_function_calls` | 7 | 15.2s |  |
| 435 | `swf5_encoding` | 3 | 15.5s |  |
| 436 | `swf5_global_funcs` | 232 | 15.4s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 437 | `swf5_no_closure` | 19 | 15.2s | [9](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 438 | `swf5_to_6_cross_call` | 29 | 16.5s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 439 | `swf6_case_insensitive` | 42 | 15.2s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 440 | `swf6_global_funcs` | 232 | 15.3s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 441 | `swf6_string_as_bool` | 15 | 15.2s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 442 | `swf6_to_5_cross_call` | 29 | 15.1s | [58](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 443 | `swf7_case_sensitive` | 44 | 15.1s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 444 | `swf7_global_funcs` | 232 | 15.1s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 445 | `tab_ordering_automatic_basic` | 92 | 15.9s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 446 | `tab_ordering_automatic_order_grid` | 21 | 15.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 447 | `tab_ordering_automatic_order_same_position` | 12 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 448 | `tab_ordering_children` | 208 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 449 | `tab_ordering_custom_basic` | 71 | 15.3s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 450 | `tab_ordering_custom_duplicate_index` | 22 | 15.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 451 | `tab_ordering_custom_i32_vs_u32` | 12 | 16.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 452 | `tab_ordering_custom_m1` | 29 | 16.4s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 453 | `tab_ordering_events` | 150 | 16.0s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 454 | `tab_ordering_events_mouse` | 65 | 16.6s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 455 | `tab_ordering_movieclip_enabled_default` | 462 | 16.1s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 456 | `tab_ordering_properties` | 293 | 15.8s | [60](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 457 | `tab_ordering_reverse` | 51 | 15.5s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 458 | `tab_ordering_tabbable` | 47 | 15.7s | [59](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 459 | `target_clip_removed` | 5 | 15.8s | [50](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 460 | `target_clip_swf5` | 2 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 461 | `target_clip_swf6` | 2 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 462 | `target_path` | 14 | 15.3s |  |
| 463 | `tell_target` | 37 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 464 | `tell_target_invalid` | 6 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 465 | `tell_target_invalid_swf6` | 5 | 15.6s | [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 466 | `text_format` | 1146 | 15.8s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `text_format_display` | 21 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `text_format_font_max_length` | 2 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `text_format_get_text_extent_undefined_width` | 10 | 15.4s |  |
| 470 | `text_format_rounding_swf7` | 840 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 471 | `text_format_rounding_swf8` | 840 | 15.8s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 472 | `textfield_background_color` | 11 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 473 | `textfield_border_color` | 11 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 474 | `textfield_cache_as_bitmap` | 1 | 15.6s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 475 | `textfield_maxchars` | 3 | 17.2s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 476 | `textfield_properties` | 44 | 16.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 477 | `textfield_props_swf5` | 175 | 16.1s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 478 | `textfield_props_swf6` | 210 | 15.9s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 479 | `textfield_props_swf7` | 210 | 15.6s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 480 | `textfield_props_swf8` | 210 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 481 | `textfield_text` | 7 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 482 | `textfield_variable` | 81 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 483 | `textsnapshot_available_text` | 20 | 15.5s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 484 | `textsnapshot_findtext` | 44 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 485 | `textsnapshot_gettext` | 55 | 15.8s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 486 | `textsnapshot_props_swf5` | 56 | 15.7s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 487 | `textsnapshot_props_swf6` | 56 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 488 | `textsnapshot_text_order` | 1 | 15.3s | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [63](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 489 | `this_scoping` | 52 | 15.5s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 490 | `this_swf5` | 41 | 15.4s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 491 | `this_swf6` | 41 | 15.3s | [64](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 492 | `this_swf7` | 41 | 15.2s | [65](ruffle-tests/_investigation/complete/this_swf7.md) |
| 493 | `timeline_function_def` | 7 | 15.6s |  |
| 494 | `timer_run_actions` | 18 | 15.8s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 495 | `trace` | 8 | 15.3s |  |
| 496 | `transform` | 70 | 15.4s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 497 | `try_catch_finally` | 118 | 15.4s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 498 | `try_finally_simple` | 16 | 15.3s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 499 | `typeof` | 22 | 15.4s |  |
| 500 | `typeof_globals` | 7 | 15.2s |  |
| 501 | `uncaught_exception` | 1 | 15.2s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 502 | `uncaught_exception_bubbled` | 1 | 15.2s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 503 | `undefined_to_string_swf6` | 4 | 15.3s |  |
| 504 | `unescape` | 43 | 15.4s |  |
| 505 | `unload` | 52 | 15.5s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 506 | `unload_clip_event` | 4 | 15.3s | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 507 | `unloadmovie` | 4 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 508 | `unloadmovie_method` | 3 | 15.5s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 509 | `unloadmovienum` | 13 | 15.4s | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 510 | `use_hand_cursor` | 8 | 15.3s |  |
| 511 | `variable_args` | 5 | 15.4s |  |
| 512 | `waitforframe` | 7 | 15.2s |  |
| 513 | `waitforframe2` | 16 | 16.3s |  |
| 514 | `watch` | 117 | 14.9s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 515 | `watch_textfield` | 12 | 14.6s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 516 | `watch_virtual_property_proto` | 2 | 14.8s | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 517 | `with` | 49 | 14.7s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 518 | `with_return` | 2 | 14.6s |  |
| 519 | `with_variable_scopes` | 43 | 14.7s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 520 | `xml` | 15 | 14.5s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_append_child` | 28 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_append_child_with_parent` | 20 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_attributes_read` | 4 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_cdata` | 11 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_child_nodes_edge_cases` | 4 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_clone_expandos` | 19 | 14.7s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_first_last_child` | 8 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_has_child_nodes` | 3 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_idmap` | 21 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_ignore_comments` | 21 | 14.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_ignore_white` | 34 | 15.6s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_insert_before` | 20 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_inspect_createmethods` | 15 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_inspect_doctype` | 7 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 535 | `xml_inspect_parsexml` | 62 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 536 | `xml_inspect_xmldecl` | 7 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 537 | `xml_namespaces` | 203 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 538 | `xml_parent_and_child` | 5 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_remove_node` | 22 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 540 | `xml_reparenting` | 14 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 541 | `xml_siblings` | 10 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 542 | `xml_to_string` | 13 | 15.2s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_to_string_comment` | 1 | 15.3s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_unescaping` | 23 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 545 | `xmlnode_proto` | 1 | 15.4s | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**23 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `bitmap_data` | 99.9% | 1125 | 1126 | 1 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 2 | `date` | 99.2% | 6284 | 6335 | 51 | [13](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `bitmap_data_threshold` | 96.0% | 169 | 176 | 7 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 10 | `clone_sprite_edittext` | 95.7% | 90 | 94 | 4 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `clone_sprite_edittext_dynamic` | 90.7% | 78 | 86 | 8 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `bitmap_data_copypixels` | 88.2% | 15 | 17 | 2 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 16 | `bitmapdata_channels` | 78.9% | 15 | 19 | 4 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `string_paths_eval` | 75.0% | 3 | 4 | 1 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 18 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 19 | `bitmap_data_hittest` | 72.7% | 96 | 132 | 36 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 20 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 22 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 23 | `issue_2030` | 50.0% | 2 | 4 | 2 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 18.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 31.3s | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 45.5s | [66](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**70 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `bitmap_data` | 99.9% | 1125/1126 | 1126 | 1126 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 2 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [13](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 3 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `bitmap_data_threshold` | 96.0% | 169/176 | 176 | 176 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 10 | `clone_sprite_edittext` | 95.7% | 90/94 | 94 | 94 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `clone_sprite_edittext_dynamic` | 90.7% | 78/86 | 86 | 86 | [8](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `bitmap_data_copypixels` | 88.2% | 15/17 | 17 | 17 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 16 | `bitmapdata_channels` | 78.9% | 15/19 | 19 | 19 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `string_paths_eval` | 75.0% | 3/4 | 4 | 4 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 18 | `text_blocks_clicks` | 75.0% | 3/4 | 4 | 4 | [26](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 19 | `bitmap_data_hittest` | 72.7% | 96/132 | 131 | 132 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 20 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 22 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 23 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 25 | `issue_2084` | 37.5% | 6/16 | 8 | 16 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 26 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 27 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 29 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 30 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 31 | `tab_ordering_properties_tab_index_edge_case` | 25.0% | 1/4 | 4 | 4 |  |
| 32 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 33 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [43](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 34 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 35 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 37 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 38 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 39 | `bitmap_data_pixeldissolve` | 7.6% | 82/1075 | 1055 | 1075 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 40 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 41 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 42 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 43 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 44 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 45 | `global_proto_decls` | 2.1% | 96/4497 | 1192 | 4497 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 46 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 47 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 48 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 49 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 50 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 51 | `global_instance_decls` | 0.4% | 3/758 | 695 | 758 | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 52 | `global_proto_decls_delete` | 0.3% | 14/4158 | 577 | 4158 | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 53 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 54 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 55 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 56 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 57 | `geturl` | 0.0% | 0/7 | 0 | 7 | [69](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 58 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 59 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 60 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 61 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 62 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 63 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 64 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [56](ruffle-tests/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 65 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 66 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [39](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 67 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 68 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 69 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 70 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [72](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) | 17 | 10 | 7 |
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
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 13 | 4 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 29 | 2 | 27 |
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
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 16 | 3 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 66 | 4 |
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
| | *(tests not in any document)* | 151 | 150 | 1 |
