# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-13 04:05 UTC

**Git SHA**: `1f8dfd4989`

**Run Duration**: 154m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 618 |
| Passing | **531** (85.9%) |
| Failing | 87 |
| Total expected lines | 91484 |
| Matching lines | 74197 (81.1%) |
| Mismatched lines | 17287 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 84 | 96.6% |
| Runtime Segfault | 2 | 2.3% |
| Timeout | 1 | 1.1% |

## Passing Tests

**531 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.3s |  |
| 2 | `action_to_integer` | 28 | 14.1s |  |
| 3 | `add` | 28 | 14.1s |  |
| 4 | `add2` | 354 | 14.3s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.1s | [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.1s |  |
| 7 | `add_swf5` | 28 | 14.1s |  |
| 8 | `arguments` | 127 | 14.1s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [43](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 14.1s |  |
| 11 | `array_constructor` | 30 | 14.1s |  |
| 12 | `array_enumerate` | 4 | 14.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.1s |  |
| 14 | `array_properties` | 36 | 14.1s |  |
| 15 | `array_prototyping` | 12 | 14.0s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 14.2s |  |
| 17 | `array_sort` | 161 | 14.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 14.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 14.3s |  |
| 20 | `array_trivial` | 209 | 14.3s |  |
| 21 | `as1_constructor_v6` | 35 | 14.1s |  |
| 22 | `as1_constructor_v7` | 35 | 14.9s |  |
| 23 | `as2_oop` | 13 | 14.7s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 14.8s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 14.8s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 14.7s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 14.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 14.3s |  |
| 29 | `as_broadcaster_undef` | 89 | 14.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 14.6s | [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 14.4s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 14.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 14.5s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 14.6s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 14.5s |  |
| 37 | `as_transformed_flag` | 20 | 14.5s |  |
| 38 | `asnative` | 34 | 14.4s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 14.6s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 14.6s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 14.6s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 14.7s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 14.3s |  |
| 44 | `bitand` | 1058 | 17.2s |  |
| 45 | `bitmap_data_colortransform` | 0 | 14.6s |  |
| 46 | `bitmap_data_fillrect` | 0 | 14.5s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 14.3s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 14.3s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 15.2s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 14.8s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.6s |  |
| 52 | `bitor` | 1058 | 17.1s |  |
| 53 | `biturshift` | 14 | 14.3s |  |
| 54 | `biturshift_swf8` | 14 | 14.6s |  |
| 55 | `bitxor` | 1058 | 17.0s |  |
| 56 | `boxed_primitives` | 24 | 14.4s | [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 14.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 14.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 14.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 15.2s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 14.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 14.5s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 14.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 14.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 14.5s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 14.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 14.2s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 14.4s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 14.2s |  |
| 71 | `capabilities_resolution` | 8 | 14.2s |  |
| 72 | `catch_references_registers` | 2 | 14.2s | [65](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 14.3s | [36](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 14.4s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 15.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 15.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 15.1s | [69](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 17 | 15.2s | [44](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `color` | 57 | 15.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `color_transform` | 48 | 15.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `conflicting_instance_names` | 23 | 15.2s |  |
| 82 | `constructor_function` | 2 | 15.1s |  |
| 83 | `context_menu` | 39 | 15.3s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `context_menu_item` | 41 | 15.4s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `create_empty_movie_clip` | 3 | 15.2s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `cross_movie_root` | 10 | 15.0s | [29](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 87 | `custom_clip_methods` | 4 | 15.3s | [11](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `default_names` | 52 | 14.9s | [13](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `define_function2` | 8 | 14.9s |  |
| 90 | `define_function2_preload` | 13 | 14.8s |  |
| 91 | `define_function2_preload_order` | 4 | 14.2s |  |
| 92 | `define_function_case_sensitive` | 2 | 14.1s |  |
| 93 | `define_local` | 27 | 14.1s | [69](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 94 | `define_local_with_paths` | 54 | 14.1s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `delete` | 3 | 14.1s |  |
| 96 | `device_font_spacing` | 91 | 14.3s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 97 | `display_object_properties` | 2 | 14.1s |  |
| 98 | `divide_swf4` | 107 | 14.2s |  |
| 99 | `do_init_action` | 3 | 14.2s |  |
| 100 | `do_init_action_child` | 12 | 14.2s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 101 | `drag_drop` | 10 | 14.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_from_outside` | 1 | 14.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `drag_over_without_startdrag` | 1 | 14.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 104 | `duplicate_movie_clip` | 20 | 14.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `duplicate_movie_clip_drawing` | 2 | 14.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `edittext_align` | 60 | 14.2s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf7` | 576 | 14.2s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_align_trailing_spaces_swf8` | 576 | 14.2s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_antialiastype` | 296 | 14.3s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize` | 71 | 14.2s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_autosize_setter` | 20 | 15.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format` | 221 | 15.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_default_format_font_style` | 335 | 15.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_focus_selection` | 2 | 15.0s | [49](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_font_size` | 45 | 15.0s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_hscroll` | 27 | 15.0s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf7` | 52 | 15.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_align_swf8` | 52 | 15.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_color` | 114 | 15.0s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf7` | 311 | 14.6s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_condensewhite_swf8` | 311 | 15.0s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_entity` | 4 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_roundtrip` | 17 | 14.6s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf7` | 5377 | 16.4s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_swf8` | 5377 | 16.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input` | 1 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_input_newlines` | 9 | 15.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_leading` | 9 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_letter_spacing` | 15 | 14.8s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_margins` | 25 | 15.0s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_newline_stripping` | 64 | 19.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_newlines` | 30 | 14.8s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_password` | 5 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_password_copy` | 4 | 14.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_paste_empty` | 2 | 14.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_place_caret` | 2 | 14.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_programmatic_focus` | 12 | 14.5s | [49](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_restrict` | 191 | 14.6s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_restrict_paste` | 5 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_scroll` | 54 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_stylesheet` | 325 | 15.3s | [55](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_tab_focus` | 13 | 14.7s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_tab_stops` | 60 | 14.8s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_tag_indent` | 31 | 14.8s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_text_height_leading` | 20 | 14.8s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_underline` | 40 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `edittext_width_height` | 103 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 148 | `empty_movieclip_can_attach_movies` | 11 | 14.9s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 149 | `enumerate` | 64 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 150 | `equals` | 32 | 14.7s |  |
| 151 | `equals2_swf5` | 926 | 16.1s |  |
| 152 | `equals2_swf6` | 926 | 16.6s |  |
| 153 | `equals2_swf7` | 926 | 16.8s |  |
| 154 | `equals_swf4` | 665 | 15.7s |  |
| 155 | `equals_swf4_alt` | 32 | 14.8s |  |
| 156 | `equals_swf5` | 32 | 14.6s |  |
| 157 | `error` | 58 | 14.4s |  |
| 158 | `escape` | 14 | 14.5s |  |
| 159 | `execution_order1` | 5 | 14.5s |  |
| 160 | `execution_order2` | 7 | 14.8s |  |
| 161 | `execution_order3` | 4 | 14.6s |  |
| 162 | `execution_order4` | 12 | 14.7s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 163 | `export_assets` | 3 | 14.5s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 164 | `extends_chain` | 134 | 15.0s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 165 | `extends_native_type` | 11 | 14.6s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `external_interface` | 84 | 14.7s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_escapexml` | 26 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_jsquotestring` | 21 | 14.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_toas_basic` | 354 | 17.2s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_toxml_array` | 25 | 14.8s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_toxml_basic` | 179 | 14.9s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `external_interface_unescapexml` | 40 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 173 | `focus_keyboard_press` | 60 | 15.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focus_mouse` | 45 | 14.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focus_mouse_rollout` | 4 | 14.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_remove` | 33 | 14.6s |  |
| 177 | `focus_root_movie` | 2 | 14.5s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 178 | `focusrect_focuslost` | 4 | 15.4s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 179 | `focusrect_mouse_swf8` | 0 | 15.3s |  |
| 180 | `focusrect_mouse_swf9` | 0 | 14.6s |  |
| 181 | `focusrect_swf5` | 6 | 14.7s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 182 | `focusrect_swf6` | 42 | 14.5s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 183 | `form_loader_encoding_1` | 1 | 14.5s |  |
| 184 | `frame_size_translated_negative` | 21 | 14.6s | [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 185 | `frame_size_translated_positive` | 21 | 14.6s | [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 186 | `function_as_function` | 35 | 14.6s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 187 | `function_base_clip` | 8 | 14.4s |  |
| 188 | `function_base_clip_readded` | 11 | 14.4s |  |
| 189 | `function_base_clip_removed` | 25 | 14.5s |  |
| 190 | `function_suppress_and_preload` | 28 | 14.5s |  |
| 191 | `funky_function_calls` | 56 | 14.5s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 192 | `get_bytes_total` | 4 | 14.6s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 193 | `get_variable_in_scope` | 29 | 14.4s |  |
| 194 | `getproperty` | 28 | 14.6s |  |
| 195 | `getproperty_swf4` | 28 | 14.4s |  |
| 196 | `getproperty_swf5` | 28 | 14.2s |  |
| 197 | `gettextextent` | 56 | 14.3s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 198 | `global_array` | 3 | 14.4s |  |
| 199 | `global_is_bare` | 7 | 14.2s |  |
| 200 | `global_swf5_6_7_8_9` | 1145 | 14.8s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 201 | `global_swf6_7_8` | 15 | 14.4s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 202 | `globals_swf5` | 304 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 203 | `globals_swf6` | 304 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 204 | `globals_swf7` | 304 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 205 | `globals_swf8` | 304 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 206 | `goto_advance1` | 6 | 14.1s |  |
| 207 | `goto_advance2` | 2 | 14.1s |  |
| 208 | `goto_both_ways1` | 3 | 14.1s |  |
| 209 | `goto_both_ways2` | 3 | 14.2s |  |
| 210 | `goto_execution_order` | 2 | 14.2s |  |
| 211 | `goto_execution_order2` | 2 | 14.2s |  |
| 212 | `goto_frame` | 12 | 15.2s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 213 | `goto_frame2` | 44 | 15.0s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 214 | `goto_frame_number` | 3 | 14.6s |  |
| 215 | `goto_label` | 17 | 14.8s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 216 | `goto_methods` | 40 | 14.8s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 217 | `goto_rewind1` | 1 | 14.8s |  |
| 218 | `goto_rewind2` | 3 | 14.9s |  |
| 219 | `goto_rewind3` | 2 | 14.9s |  |
| 220 | `greater_swf6` | 1175 | 17.3s |  |
| 221 | `greater_swf7` | 1175 | 16.8s |  |
| 222 | `greaterthan_swf5` | 1 | 14.6s |  |
| 223 | `greaterthan_swf8` | 1 | 14.6s |  |
| 224 | `has_own_property` | 32 | 14.6s |  |
| 225 | `hittest_lockroot` | 15 | 14.8s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 226 | `hittest_morph` | 70 | 14.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [35](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 227 | `hittest_winding_rule` | 12 | 14.8s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 228 | `infinite_recursion_function` | 4 | 14.8s | [26](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 229 | `infinite_recursion_function_in_setter` | 131 | 15.1s | [26](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 230 | `infinite_recursion_virtual_property` | 67 | 14.6s | [26](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 231 | `init_array_invalid` | 4 | 14.7s |  |
| 232 | `init_object_invalid` | 4 | 16.5s |  |
| 233 | `init_object_order` | 15 | 14.8s | [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 234 | `instanceof_coercions` | 88 | 15.0s | [66](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 235 | `interface_implements_op` | 47 | 15.2s | [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 236 | `is_finite` | 49 | 14.6s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 237 | `is_finite_swf6` | 49 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 238 | `is_prototype_of` | 89 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 239 | `issue_1086` | 1 | 15.1s |  |
| 240 | `issue_1104` | 2 | 15.3s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 241 | `issue_1671` | 0 | 14.9s |  |
| 242 | `issue_1906` | 4 | 15.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 243 | `issue_2166` | 9 | 15.7s |  |
| 244 | `issue_3169` | 2 | 15.4s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 245 | `issue_3446` | 1 | 15.3s |  |
| 246 | `issue_3522` | 2 | 15.2s |  |
| 247 | `issue_4377` | 2 | 15.0s |  |
| 248 | `issue_710` | 4 | 15.0s |  |
| 249 | `issue_768` | 3 | 15.8s | [28](ruffle-tests/_investigation/complete/issue_768.md) |
| 250 | `issue_9327` | 2 | 14.5s |  |
| 251 | `issue_9885` | 2 | 14.3s |  |
| 252 | `key_isToggled` | 9 | 14.6s |  |
| 253 | `lessthan` | 41 | 14.4s |  |
| 254 | `lessthan2_swf5` | 1226 | 16.7s |  |
| 255 | `lessthan2_swf6` | 1226 | 16.3s |  |
| 256 | `lessthan2_swf7` | 1226 | 16.2s |  |
| 257 | `lessthan_swf4` | 902 | 15.2s |  |
| 258 | `lessthan_swf4_alt` | 41 | 14.2s |  |
| 259 | `lessthan_swf5` | 41 | 14.1s |  |
| 260 | `loadmovie` | 2 | 14.4s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 261 | `loadmovie_fail` | 2 | 14.4s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 262 | `loadmovie_flashvars` | 4 | 14.5s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 263 | `loadmovie_method` | 2 | 14.2s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 264 | `loadmovie_registerclass` | 30 | 14.3s | [10](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 265 | `loadmovie_replace_root` | 5 | 14.7s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [47](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 266 | `loadmovie_var_persistence` | 8 | 15.2s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 267 | `loadmovienum` | 3 | 14.7s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 268 | `loadmovienum_cross_version_prototype` | 9 | 14.6s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 269 | `loadvariables` | 2 | 15.3s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 270 | `loadvariables2` | 8 | 14.5s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 271 | `loadvariablesnum` | 2 | 14.4s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 272 | `local_to_global` | 49 | 14.6s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 273 | `localconnection_properties` | 8 | 14.5s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 274 | `lock_root` | 1 | 14.5s |  |
| 275 | `logical_ops_swf4` | 90 | 14.5s |  |
| 276 | `logical_ops_swf8` | 108 | 14.8s |  |
| 277 | `looping` | 6 | 14.8s |  |
| 278 | `mask_reapply` | 0 | 14.6s |  |
| 279 | `mask_with_drawing` | 0 | 14.8s |  |
| 280 | `math_min_max` | 101 | 15.0s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [34](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 281 | `math_swf6` | 530 | 15.2s | [34](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 282 | `math_swf7` | 530 | 15.1s | [34](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 283 | `math_swf8` | 530 | 15.0s | [34](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 284 | `matrix` | 171 | 14.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 285 | `mcl_as_broadcaster` | 12 | 14.6s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 286 | `mcl_events_swf_version` | 232 | 15.2s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 287 | `mcl_getprogress` | 30 | 14.7s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 288 | `mcl_loadclip` | 149 | 14.4s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 289 | `mcl_loadclip_properties` | 6 | 14.4s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 290 | `mcl_loadclip_replace_root` | 1 | 14.3s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [47](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 291 | `mcl_mislabeled_target` | 6 | 14.3s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mcl_target_gif87a` | 6 | 14.6s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 293 | `mcl_target_gif89a` | 6 | 14.6s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 294 | `mcl_target_jpg` | 6 | 14.3s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 295 | `mcl_target_png` | 6 | 14.3s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_unloadclip` | 5 | 14.2s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 297 | `mouse_events` | 8 | 14.3s | [36](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 298 | `mouse_events_visible_enabled` | 12 | 14.4s | [36](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 299 | `mouse_hover_events_while_dragging` | 1 | 14.4s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 300 | `mouse_listeners` | 67 | 14.4s |  |
| 301 | `mouse_pos` | 665 | 14.3s | [36](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 302 | `mouse_pos_with_scale_factor` | 260 | 14.3s | [36](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 303 | `mouse_wheel_enabled` | 2 | 14.2s |  |
| 304 | `movieclip_begin_gradient_fill` | 0 | 14.7s |  |
| 305 | `movieclip_blend_mode_property` | 35 | 14.3s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 306 | `movieclip_create_text_field` | 90 | 14.3s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 307 | `movieclip_default_state` | 69 | 17.1s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 308 | `movieclip_depth_methods` | 98 | 15.5s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 309 | `movieclip_focusenabled` | 99 | 15.2s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 310 | `movieclip_get_instance_at_depth` | 28 | 15.0s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 311 | `movieclip_getbounds` | 191 | 15.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 312 | `movieclip_gettextsnapshot` | 112 | 15.2s | [23](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 313 | `movieclip_hittest` | 92 | 15.2s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_in_removed_button` | 4 | 15.0s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 315 | `movieclip_init_object` | 5 | 15.1s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 316 | `movieclip_invalid_get_bounds_1` | 75 | 15.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 317 | `movieclip_invalid_get_bounds_2` | 75 | 15.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 318 | `movieclip_invalid_get_bounds_3` | 13 | 15.5s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_invalid_get_bounds_4` | 13 | 15.5s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_invalid_get_bounds_5` | 11 | 15.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 321 | `movieclip_invalid_get_bounds_8` | 11 | 15.5s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 322 | `movieclip_line_gradient_style` | 0 | 14.9s |  |
| 323 | `movieclip_lockroot` | 29 | 15.4s | [33](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_name_from_timeline` | 13 | 14.3s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_prototype_extension` | 5 | 14.2s |  |
| 326 | `movieclip_setmask` | 14 | 14.5s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 327 | `moviecliploader_flashvars` | 4 | 14.4s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 328 | `mutable_this` | 18 | 14.3s | [62](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 329 | `named_shapes` | 14 | 14.3s |  |
| 330 | `nan_scale` | 9 | 14.4s |  |
| 331 | `native_double_construct` | 12 | 14.4s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 332 | `native_objects_swf7` | 84 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 333 | `native_objects_swf8` | 84 | 14.8s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 334 | `native_subclasses` | 191 | 14.8s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 335 | `nested_textfields_in_buttons` | 0 | 14.3s |  |
| 336 | `new_method_wrap` | 4 | 15.4s |  |
| 337 | `new_object_enumerate` | 7 | 14.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 338 | `new_object_wrap` | 4 | 15.2s |  |
| 339 | `o` | 3 | 14.8s |  |
| 340 | `object_constructor` | 33 | 14.9s |  |
| 341 | `object_function` | 32 | 14.9s |  |
| 342 | `object_properties` | 31 | 14.9s | [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 343 | `object_prototypes` | 74 | 15.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 344 | `object_resolve` | 38 | 15.9s | [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 345 | `object_string_coerce_swf5` | 62 | 15.2s | [40](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 346 | `object_string_coerce_swf6` | 68 | 15.4s | [40](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 347 | `on_construct` | 25 | 15.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 348 | `parse_float` | 74 | 15.1s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [43](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 349 | `parse_int` | 64 | 15.1s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [43](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 350 | `path_string` | 322 | 14.9s | [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 351 | `place_and_lookup` | 30 | 15.4s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 352 | `placeobject_occupied_depth` | 6 | 14.9s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 353 | `point` | 175 | 14.9s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 354 | `primitive_instanceof` | 37 | 14.9s |  |
| 355 | `primitive_type_globals` | 557 | 14.6s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 356 | `printjob_props_swf5` | 45 | 15.3s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 357 | `printjob_props_swf6` | 45 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 358 | `printjob_props_swf7` | 45 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 359 | `property_invalid_base_clip` | 36 | 14.8s |  |
| 360 | `prototype_delete` | 12 | 14.7s |  |
| 361 | `prototype_enumerate` | 5 | 14.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 362 | `prototype_properties` | 17 | 14.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 363 | `rectangle` | 745 | 15.6s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 364 | `recursive_prototypes` | 0 | 14.7s |  |
| 365 | `register_and_init_order` | 231 | 15.2s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 366 | `register_class` | 66 | 15.0s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 367 | `register_class_return_value` | 16 | 14.8s | [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 368 | `register_class_swf6` | 37 | 15.0s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 369 | `register_class_with_sound` | 11 | 14.8s | [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [50](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 370 | `register_globals_across_frames` | 15 | 14.8s | [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 371 | `register_underflow` | 26 | 14.7s | [46](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 372 | `remove_movie_clip` | 29 | 14.7s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 373 | `removed_clip_halts_script` | 15 | 15.2s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 374 | `removed_target_clip_scope` | 35 | 14.9s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 375 | `resolve_different_root` | 2 | 16.7s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 376 | `rewind_depth` | 30 | 15.0s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 377 | `root_button_mode` | 10 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 378 | `root_global_parent` | 6 | 14.9s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 379 | `root_onload` | 1 | 15.2s | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 380 | `sandbox_type_local_file` | 1 | 14.9s |  |
| 381 | `sandbox_type_local_network` | 1 | 15.1s |  |
| 382 | `selection` | 454 | 15.3s | [49](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 383 | `selection_handlers` | 27 | 15.2s | [49](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 384 | `set_interval` | 27 | 15.4s | [64](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 385 | `set_variable_scope` | 58 | 15.1s |  |
| 386 | `single_frame` | 1 | 15.0s |  |
| 387 | `slash_syntax` | 14 | 15.0s | [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 388 | `sound` | 628 | 15.4s | [50](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 389 | `sound_props_swf5` | 68 | 15.8s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 390 | `sound_props_swf6` | 68 | 15.6s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 391 | `sound_start_load` | 0 | 15.9s |  |
| 392 | `stage_display_state` | 16 | 15.6s | [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 393 | `stage_object_children` | 83 | 15.7s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 394 | `stage_object_enumerate` | 4 | 15.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 395 | `stage_object_properties` | 241 | 16.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 396 | `stage_object_properties_get_var` | 5 | 15.9s |  |
| 397 | `stage_object_properties_swf6` | 231 | 16.1s | [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 398 | `stage_property_representation` | 586 | 15.8s | [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 399 | `stage_scale_mode` | 39 | 15.8s | [51](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 400 | `strictequals_swf6` | 902 | 17.0s |  |
| 401 | `strictly_equals` | 7 | 15.7s |  |
| 402 | `string_coercion` | 117 | 16.1s | [53](ruffle-tests/_investigation/complete/string_coercion.md) |
| 403 | `string_methods` | 285 | 16.0s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 404 | `string_methods_negative_args` | 240 | 15.7s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 405 | `string_methods_swfv5` | 275 | 16.2s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 406 | `string_ops_swf6` | 95 | 15.4s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 407 | `string_paths_basic` | 4 | 15.5s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 408 | `string_paths_eval2` | 7 | 16.1s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 409 | `string_paths_hidden` | 54 | 14.4s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 410 | `string_paths_other` | 36 | 14.4s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 411 | `string_paths_unload` | 1 | 14.3s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 412 | `string_paths_variable_alias` | 4 | 14.4s | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 413 | `string_paths_variable_scopes` | 5 | 14.7s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 414 | `stylesheet` | 283 | 15.4s |  |
| 415 | `stylesheet_transform` | 750 | 15.3s |  |
| 416 | `super_edge_cases` | 39 | 14.9s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [42](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 417 | `swf4_actions_bool` | 96 | 14.4s |  |
| 418 | `swf4_actions_coercion_order` | 158 | 14.5s | [56](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 419 | `swf4_bool` | 4 | 14.4s |  |
| 420 | `swf4_function_calls` | 7 | 14.7s |  |
| 421 | `swf5_encoding` | 3 | 14.5s |  |
| 422 | `swf5_global_funcs` | 232 | 14.4s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 423 | `swf5_no_closure` | 19 | 14.4s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [62](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 424 | `swf5_to_6_cross_call` | 29 | 14.7s | [56](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 425 | `swf6_case_insensitive` | 42 | 14.2s | [56](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 426 | `swf6_global_funcs` | 232 | 14.3s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 427 | `swf6_string_as_bool` | 15 | 14.2s | [56](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 428 | `swf6_to_5_cross_call` | 29 | 14.3s | [56](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 429 | `swf7_case_sensitive` | 44 | 14.3s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 430 | `swf7_global_funcs` | 232 | 14.2s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 431 | `tab_ordering_automatic_basic` | 92 | 14.3s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 432 | `tab_ordering_automatic_order_grid` | 21 | 14.6s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 433 | `tab_ordering_automatic_order_same_position` | 12 | 14.5s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 434 | `tab_ordering_children` | 208 | 14.7s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 435 | `tab_ordering_custom_basic` | 71 | 14.7s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 436 | `tab_ordering_custom_duplicate_index` | 22 | 14.6s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 437 | `tab_ordering_custom_i32_vs_u32` | 12 | 14.6s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 438 | `tab_ordering_custom_m1` | 29 | 14.6s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 439 | `tab_ordering_events` | 150 | 14.9s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 440 | `tab_ordering_events_mouse` | 65 | 14.6s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 441 | `tab_ordering_movieclip_enabled_default` | 462 | 14.5s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 442 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.8s |  |
| 443 | `tab_ordering_reverse` | 51 | 14.5s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 444 | `tab_ordering_tabbable` | 47 | 14.4s | [57](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 445 | `target_clip_removed` | 5 | 14.5s | [48](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 446 | `target_clip_swf5` | 2 | 14.4s | [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 447 | `target_clip_swf6` | 2 | 14.4s | [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 448 | `target_path` | 14 | 14.2s |  |
| 449 | `tell_target` | 37 | 14.3s | [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 450 | `tell_target_invalid` | 6 | 14.3s | [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 451 | `tell_target_invalid_swf6` | 5 | 14.3s | [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 452 | `text_format` | 1146 | 14.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 453 | `text_format_display` | 21 | 14.3s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 454 | `text_format_font_max_length` | 2 | 14.3s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 455 | `text_format_get_text_extent_undefined_width` | 10 | 14.3s |  |
| 456 | `text_format_rounding_swf7` | 840 | 14.4s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 457 | `text_format_rounding_swf8` | 840 | 14.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 458 | `textfield_background_color` | 11 | 14.3s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 459 | `textfield_border_color` | 11 | 14.5s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 460 | `textfield_cache_as_bitmap` | 1 | 14.2s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 461 | `textfield_maxchars` | 3 | 15.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 462 | `textfield_properties` | 44 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `textfield_props_swf5` | 175 | 14.9s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 464 | `textfield_props_swf6` | 210 | 15.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 465 | `textfield_props_swf7` | 210 | 15.0s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 466 | `textfield_props_swf8` | 210 | 14.9s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `textfield_text` | 7 | 14.7s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textfield_variable` | 81 | 14.8s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `textsnapshot_available_text` | 20 | 14.8s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [61](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 470 | `textsnapshot_findtext` | 44 | 15.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [61](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 471 | `textsnapshot_gettext` | 55 | 15.1s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [61](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 472 | `textsnapshot_props_swf5` | 56 | 14.6s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 473 | `textsnapshot_props_swf6` | 56 | 14.6s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 474 | `textsnapshot_text_order` | 1 | 14.6s | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [61](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 475 | `this_scoping` | 52 | 14.7s | [62](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [69](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 476 | `this_swf5` | 41 | 14.7s | [62](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 477 | `this_swf6` | 41 | 14.7s | [62](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 478 | `this_swf7` | 41 | 14.8s | [63](ruffle-tests/_investigation/complete/this_swf7.md) |
| 479 | `timeline_function_def` | 7 | 14.8s |  |
| 480 | `timer_run_actions` | 18 | 14.3s | [64](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 481 | `trace` | 8 | 14.1s |  |
| 482 | `transform` | 70 | 14.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 483 | `try_catch_finally` | 118 | 14.2s | [65](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 484 | `try_finally_simple` | 16 | 13.9s | [65](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 485 | `typeof` | 22 | 14.1s |  |
| 486 | `typeof_globals` | 7 | 13.9s |  |
| 487 | `uncaught_exception` | 1 | 13.8s | [65](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 488 | `uncaught_exception_bubbled` | 1 | 14.0s | [65](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 489 | `undefined_to_string_swf6` | 4 | 14.1s |  |
| 490 | `unescape` | 43 | 14.0s |  |
| 491 | `unload` | 52 | 14.2s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 492 | `unload_clip_event` | 4 | 13.9s | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 493 | `unloadmovie` | 4 | 14.0s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 494 | `unloadmovie_method` | 3 | 14.0s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 495 | `unloadmovienum` | 13 | 14.2s | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 496 | `use_hand_cursor` | 8 | 13.9s |  |
| 497 | `variable_args` | 5 | 14.1s |  |
| 498 | `waitforframe` | 7 | 14.0s |  |
| 499 | `waitforframe2` | 16 | 16.3s |  |
| 500 | `watch` | 117 | 15.0s | [41](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 501 | `watch_textfield` | 12 | 14.7s | [41](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 502 | `watch_virtual_property_proto` | 2 | 14.7s | [41](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 503 | `with` | 49 | 14.8s | [69](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 504 | `with_return` | 2 | 14.8s |  |
| 505 | `with_variable_scopes` | 43 | 14.8s | [69](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 506 | `xml` | 15 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 507 | `xml_append_child` | 28 | 14.8s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 508 | `xml_append_child_with_parent` | 20 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 509 | `xml_attributes_read` | 4 | 14.8s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 510 | `xml_cdata` | 11 | 14.7s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 511 | `xml_child_nodes_edge_cases` | 4 | 14.7s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_clone_expandos` | 19 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_first_last_child` | 8 | 14.7s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_has_child_nodes` | 3 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_idmap` | 21 | 15.1s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_ignore_comments` | 21 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_ignore_white` | 34 | 14.7s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_insert_before` | 20 | 14.4s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_inspect_createmethods` | 15 | 14.5s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_inspect_doctype` | 7 | 14.5s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_inspect_parsexml` | 62 | 14.5s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_inspect_xmldecl` | 7 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_namespaces` | 203 | 14.7s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_parent_and_child` | 5 | 14.7s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_remove_node` | 22 | 14.7s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_reparenting` | 14 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_siblings` | 10 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_to_string` | 13 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_to_string_comment` | 1 | 14.5s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_unescaping` | 23 | 14.6s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xmlnode_proto` | 1 | 14.5s | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**23 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [12](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [47](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [47](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 13 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 16 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 | [18](ruffle-tests/_investigation/incomplete/FOCUS_FOCUSRECT_PLAN.md) |
| 17 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 18 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [66](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 19 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 20 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 21 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 22 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 | [58](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 23 | `issue_2030` | 50.0% | 2 | 4 | 2 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 17.8s | [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 31.4s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 44.6s | [64](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**84 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [12](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [47](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [47](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 13 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 16 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 | [18](ruffle-tests/_investigation/incomplete/FOCUS_FOCUSRECT_PLAN.md) |
| 17 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 18 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [66](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 19 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 20 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 21 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 22 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 | [58](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 23 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 25 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 26 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 | [18](ruffle-tests/_investigation/incomplete/FOCUS_FOCUSRECT_PLAN.md) |
| 27 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 | [27](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) |
| 28 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 29 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 30 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [31](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 31 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 32 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 33 | `issue_2870` | 33.3% | 1/3 | 2 | 3 | [29](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 34 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 35 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 36 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 | [18](ruffle-tests/_investigation/incomplete/FOCUS_FOCUSRECT_PLAN.md) |
| 37 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 38 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 39 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 | [18](ruffle-tests/_investigation/incomplete/FOCUS_FOCUSRECT_PLAN.md) |
| 40 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [41](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 41 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 42 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 43 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 44 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 45 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 46 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 47 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 48 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 49 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 50 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 51 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 52 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 53 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 54 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 55 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 56 | `global_instance_decls` | 1.6% | 12/758 | 482 | 758 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 57 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 58 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 59 | `global_proto_decls` | 0.2% | 11/4497 | 692 | 4497 | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 60 | `global_proto_decls_delete` | 0.0% | 1/4158 | 310 | 4158 | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 61 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 62 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 63 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 64 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [60](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 65 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 66 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 67 | `geturl` | 0.0% | 0/7 | 0 | 7 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 68 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 69 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 70 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 71 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [30](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 73 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 74 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 75 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 76 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 77 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [54](ruffle-tests/_investigation/complete/STRING_PLAN.md) [59](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 78 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [67](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 79 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 80 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [37](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [68](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 81 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 82 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 83 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 84 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [70](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 11 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 12 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 13 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 14 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 15 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 16 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 17 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 18 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/_investigation/incomplete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 0 | 4 |
| 19 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 6 | 1 |
| 20 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 21 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 22 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 23 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 24 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 27 | 4 |
| 25 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 26 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 27 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 0 | 1 |
| 28 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 29 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 1 | 1 |
| 30 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 40 | 8 |
| 31 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 32 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 33 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 34 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 35 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 36 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 37 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 47 | 11 |
| 38 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 39 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 40 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 41 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 42 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 43 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 44 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 45 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 46 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 47 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 48 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 49 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 50 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 51 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 52 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 53 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 54 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 55 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 56 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 57 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 58 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 0 | 1 |
| 59 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 16 | 3 |
| 60 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 65 | 5 |
| 61 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 62 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 63 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 64 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 65 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 66 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 67 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 68 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 69 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 70 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 187 | 158 | 29 |
