# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-13 18:01 UTC

**Git SHA**: `e5aadd667f`

**Run Duration**: 155m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 618 |
| Passing | **531** (85.9%) |
| Failing | 87 |
| Total expected lines | 91484 |
| Matching lines | 76363 (83.5%) |
| Mismatched lines | 15121 |

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
| 1 | `access_unnamed_shape` | 1 | 15.4s |  |
| 2 | `action_to_integer` | 28 | 14.8s |  |
| 3 | `add` | 28 | 14.9s |  |
| 4 | `add2` | 354 | 15.0s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.8s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.8s |  |
| 7 | `add_swf5` | 28 | 15.1s |  |
| 8 | `arguments` | 127 | 15.1s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 14.5s |  |
| 11 | `array_constructor` | 30 | 14.5s |  |
| 12 | `array_enumerate` | 4 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.7s |  |
| 14 | `array_properties` | 36 | 14.5s |  |
| 15 | `array_prototyping` | 12 | 14.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.0s |  |
| 17 | `array_sort` | 161 | 15.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 14.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 14.8s |  |
| 20 | `array_trivial` | 209 | 14.6s |  |
| 21 | `as1_constructor_v6` | 35 | 14.6s |  |
| 22 | `as1_constructor_v7` | 35 | 14.6s |  |
| 23 | `as2_oop` | 13 | 14.6s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 14.6s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 14.6s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 14.7s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 14.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 14.3s |  |
| 29 | `as_broadcaster_undef` | 89 | 14.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 14.3s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 14.3s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 14.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 14.3s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 14.4s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 14.4s |  |
| 37 | `as_transformed_flag` | 20 | 14.4s |  |
| 38 | `asnative` | 34 | 14.4s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 14.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 14.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 14.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 16.0s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 14.2s |  |
| 44 | `bitand` | 1058 | 17.4s |  |
| 45 | `bitmap_data_colortransform` | 0 | 15.2s |  |
| 46 | `bitmap_data_fillrect` | 0 | 15.0s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 14.8s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 14.9s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 15.7s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 15.3s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.5s |  |
| 52 | `bitor` | 1058 | 16.8s |  |
| 53 | `biturshift` | 14 | 14.2s |  |
| 54 | `biturshift_swf8` | 14 | 14.7s |  |
| 55 | `bitxor` | 1058 | 17.1s |  |
| 56 | `boxed_primitives` | 24 | 14.5s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 14.7s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 14.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 14.5s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 14.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 14.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 14.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 14.6s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 14.3s |  |
| 71 | `capabilities_resolution` | 8 | 14.5s |  |
| 72 | `catch_references_registers` | 2 | 14.6s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 14.4s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 14.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 15.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 14.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 14.9s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 17 | 14.8s | [45](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `color` | 57 | 15.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `color_transform` | 48 | 15.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `conflicting_instance_names` | 23 | 14.8s |  |
| 82 | `constructor_function` | 2 | 14.8s |  |
| 83 | `context_menu` | 39 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 84 | `context_menu_item` | 41 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 85 | `create_empty_movie_clip` | 3 | 14.9s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `cross_movie_root` | 10 | 15.2s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 87 | `custom_clip_methods` | 4 | 15.4s | [11](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `default_names` | 52 | 15.6s | [13](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 89 | `define_function2` | 8 | 15.3s |  |
| 90 | `define_function2_preload` | 13 | 15.2s |  |
| 91 | `define_function2_preload_order` | 4 | 15.6s |  |
| 92 | `define_function_case_sensitive` | 2 | 15.8s |  |
| 93 | `define_local` | 27 | 15.7s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 94 | `define_local_with_paths` | 54 | 15.7s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `delete` | 3 | 15.8s |  |
| 96 | `device_font_spacing` | 91 | 16.3s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 97 | `display_object_properties` | 2 | 15.5s |  |
| 98 | `divide_swf4` | 107 | 15.2s |  |
| 99 | `do_init_action` | 3 | 15.1s |  |
| 100 | `do_init_action_child` | 12 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 101 | `drag_drop` | 10 | 15.1s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_from_outside` | 1 | 14.9s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `drag_over_without_startdrag` | 1 | 15.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 104 | `duplicate_movie_clip` | 20 | 15.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `duplicate_movie_clip_drawing` | 2 | 15.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `edittext_align` | 60 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf7` | 576 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_align_trailing_spaces_swf8` | 576 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_antialiastype` | 296 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize` | 71 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_autosize_setter` | 20 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format` | 221 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_default_format_font_style` | 335 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_focus_selection` | 2 | 14.4s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_font_size` | 45 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_hscroll` | 27 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf7` | 52 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_align_swf8` | 52 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_color` | 114 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf7` | 311 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_condensewhite_swf8` | 311 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_entity` | 4 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_roundtrip` | 17 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf7` | 5377 | 16.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_swf8` | 5377 | 16.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input` | 1 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_input_newlines` | 9 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_leading` | 9 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_letter_spacing` | 15 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_margins` | 25 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_newline_stripping` | 64 | 19.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_newlines` | 30 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_password` | 5 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_password_copy` | 4 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_paste_empty` | 2 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_place_caret` | 2 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_programmatic_focus` | 12 | 15.3s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_restrict` | 191 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_restrict_paste` | 5 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_scroll` | 54 | 15.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_stylesheet` | 325 | 15.7s | [56](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_tab_focus` | 13 | 14.8s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_tab_stops` | 60 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_tag_indent` | 31 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_text_height_leading` | 20 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_underline` | 40 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `edittext_width_height` | 103 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 148 | `empty_movieclip_can_attach_movies` | 11 | 15.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 149 | `enumerate` | 64 | 15.0s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 150 | `equals` | 32 | 15.0s |  |
| 151 | `equals2_swf5` | 926 | 17.2s |  |
| 152 | `equals2_swf6` | 926 | 16.8s |  |
| 153 | `equals2_swf7` | 926 | 16.9s |  |
| 154 | `equals_swf4` | 665 | 15.8s |  |
| 155 | `equals_swf4_alt` | 32 | 14.8s |  |
| 156 | `equals_swf5` | 32 | 14.9s |  |
| 157 | `error` | 58 | 14.6s |  |
| 158 | `escape` | 14 | 14.8s |  |
| 159 | `execution_order1` | 5 | 14.7s |  |
| 160 | `execution_order2` | 7 | 14.5s |  |
| 161 | `execution_order3` | 4 | 14.5s |  |
| 162 | `execution_order4` | 12 | 14.8s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 163 | `export_assets` | 3 | 14.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 164 | `extends_chain` | 134 | 15.1s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 165 | `extends_native_type` | 11 | 14.6s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `external_interface` | 84 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_escapexml` | 26 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_jsquotestring` | 21 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_toas_basic` | 354 | 16.9s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_toxml_array` | 25 | 15.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_toxml_basic` | 179 | 15.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `external_interface_unescapexml` | 40 | 15.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 173 | `focus_keyboard_press` | 60 | 15.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focus_mouse` | 45 | 14.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focus_mouse_rollout` | 4 | 14.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_remove` | 33 | 14.6s |  |
| 177 | `focus_root_movie` | 2 | 14.6s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 178 | `focus_visibility_change` | 45 | 14.8s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 179 | `focusrect_focuslost` | 4 | 14.8s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 180 | `focusrect_mouse_swf8` | 0 | 14.6s |  |
| 181 | `focusrect_mouse_swf9` | 0 | 14.9s |  |
| 182 | `focusrect_property_swf5` | 1237 | 15.0s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 183 | `focusrect_property_swf6` | 1237 | 15.0s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 184 | `focusrect_property_swf7` | 1237 | 15.1s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 185 | `focusrect_swf5` | 6 | 15.0s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 186 | `focusrect_swf6` | 42 | 14.8s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 187 | `form_loader_encoding_1` | 1 | 14.6s |  |
| 188 | `frame_size_translated_negative` | 21 | 14.7s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 189 | `frame_size_translated_positive` | 21 | 14.7s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 190 | `function_as_function` | 35 | 14.7s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 191 | `function_base_clip` | 8 | 14.7s |  |
| 192 | `function_base_clip_readded` | 11 | 14.8s |  |
| 193 | `function_base_clip_removed` | 25 | 14.7s |  |
| 194 | `function_suppress_and_preload` | 28 | 14.8s |  |
| 195 | `funky_function_calls` | 56 | 14.8s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 196 | `get_bytes_total` | 4 | 14.8s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 197 | `get_variable_in_scope` | 29 | 14.8s |  |
| 198 | `getproperty` | 28 | 14.7s |  |
| 199 | `getproperty_swf4` | 28 | 15.5s |  |
| 200 | `getproperty_swf5` | 28 | 15.3s |  |
| 201 | `gettextextent` | 56 | 15.3s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 202 | `global_array` | 3 | 14.9s |  |
| 203 | `global_is_bare` | 7 | 15.0s |  |
| 204 | `global_swf6_7_8` | 15 | 15.1s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 205 | `globals_swf7` | 304 | 15.0s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 206 | `globals_swf8` | 304 | 14.9s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 207 | `goto_advance1` | 6 | 14.7s |  |
| 208 | `goto_advance2` | 2 | 14.9s |  |
| 209 | `goto_both_ways1` | 3 | 15.1s |  |
| 210 | `goto_both_ways2` | 3 | 14.7s |  |
| 211 | `goto_execution_order` | 2 | 15.0s |  |
| 212 | `goto_execution_order2` | 2 | 15.1s |  |
| 213 | `goto_frame` | 12 | 16.3s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 214 | `goto_frame2` | 44 | 14.8s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 215 | `goto_frame_number` | 3 | 14.4s |  |
| 216 | `goto_label` | 17 | 14.6s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 217 | `goto_methods` | 40 | 14.4s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 218 | `goto_rewind1` | 1 | 14.3s |  |
| 219 | `goto_rewind2` | 3 | 14.5s |  |
| 220 | `goto_rewind3` | 2 | 14.4s |  |
| 221 | `greater_swf6` | 1175 | 16.4s |  |
| 222 | `greater_swf7` | 1175 | 16.4s |  |
| 223 | `greaterthan_swf5` | 1 | 14.4s |  |
| 224 | `greaterthan_swf8` | 1 | 14.3s |  |
| 225 | `has_own_property` | 32 | 14.4s |  |
| 226 | `hittest_lockroot` | 15 | 14.6s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 227 | `hittest_morph` | 70 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [36](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 228 | `hittest_winding_rule` | 12 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 229 | `infinite_recursion_function` | 4 | 14.4s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 230 | `infinite_recursion_function_in_setter` | 131 | 14.4s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 231 | `infinite_recursion_virtual_property` | 67 | 14.4s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 232 | `init_array_invalid` | 4 | 14.3s |  |
| 233 | `init_object_invalid` | 4 | 16.9s |  |
| 234 | `init_object_order` | 15 | 14.7s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 235 | `instanceof_coercions` | 88 | 14.8s | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 236 | `interface_implements_op` | 47 | 15.2s | [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 237 | `is_finite` | 49 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 238 | `is_finite_swf6` | 49 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 239 | `is_prototype_of` | 89 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 240 | `issue_1086` | 1 | 14.5s |  |
| 241 | `issue_1104` | 2 | 14.4s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 242 | `issue_1671` | 0 | 14.4s |  |
| 243 | `issue_1906` | 4 | 14.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 244 | `issue_2166` | 9 | 14.5s |  |
| 245 | `issue_2870` | 3 | 14.6s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 246 | `issue_3169` | 2 | 14.5s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 247 | `issue_3446` | 1 | 14.8s |  |
| 248 | `issue_3522` | 2 | 15.0s |  |
| 249 | `issue_4377` | 2 | 14.8s |  |
| 250 | `issue_710` | 4 | 14.9s |  |
| 251 | `issue_768` | 3 | 14.8s | [29](ruffle-tests/_investigation/complete/issue_768.md) |
| 252 | `issue_9327` | 2 | 14.7s |  |
| 253 | `issue_9885` | 2 | 14.6s |  |
| 254 | `key_isToggled` | 9 | 14.6s |  |
| 255 | `lessthan` | 41 | 14.4s |  |
| 256 | `lessthan2_swf5` | 1226 | 16.4s |  |
| 257 | `lessthan2_swf6` | 1226 | 16.5s |  |
| 258 | `lessthan2_swf7` | 1226 | 16.4s |  |
| 259 | `lessthan_swf4` | 902 | 15.4s |  |
| 260 | `lessthan_swf4_alt` | 41 | 14.3s |  |
| 261 | `lessthan_swf5` | 41 | 14.2s |  |
| 262 | `loadmovie` | 2 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 263 | `loadmovie_fail` | 2 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 264 | `loadmovie_flashvars` | 4 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 265 | `loadmovie_method` | 2 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 266 | `loadmovie_registerclass` | 30 | 14.8s | [10](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 267 | `loadmovie_replace_root` | 5 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 268 | `loadmovie_var_persistence` | 8 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 269 | `loadmovienum` | 3 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 270 | `loadmovienum_cross_version_prototype` | 9 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 271 | `loadvariables` | 2 | 15.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 272 | `loadvariables2` | 8 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 273 | `loadvariablesnum` | 2 | 14.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 274 | `local_to_global` | 49 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 275 | `localconnection_properties` | 8 | 14.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 276 | `lock_root` | 1 | 14.3s |  |
| 277 | `logical_ops_swf4` | 90 | 14.3s |  |
| 278 | `logical_ops_swf8` | 108 | 14.4s |  |
| 279 | `looping` | 6 | 14.3s |  |
| 280 | `mask_reapply` | 0 | 14.3s |  |
| 281 | `mask_with_drawing` | 0 | 14.3s |  |
| 282 | `math_min_max` | 101 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 283 | `math_swf6` | 530 | 14.9s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 284 | `math_swf7` | 530 | 14.9s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 285 | `math_swf8` | 530 | 14.8s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 286 | `matrix` | 171 | 14.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 287 | `mcl_as_broadcaster` | 12 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 288 | `mcl_events_swf_version` | 232 | 15.1s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 289 | `mcl_getprogress` | 30 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 290 | `mcl_loadclip` | 149 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 291 | `mcl_loadclip_properties` | 6 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mcl_loadclip_replace_root` | 1 | 15.1s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 293 | `mcl_mislabeled_target` | 6 | 15.0s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 294 | `mcl_target_gif87a` | 6 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 295 | `mcl_target_gif89a` | 6 | 15.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_target_jpg` | 6 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 297 | `mcl_target_png` | 6 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_unloadclip` | 5 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 299 | `mouse_events` | 8 | 14.8s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 300 | `mouse_events_visible_enabled` | 12 | 14.8s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 301 | `mouse_hover_events_while_dragging` | 1 | 14.8s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 302 | `mouse_listeners` | 67 | 14.7s |  |
| 303 | `mouse_pos` | 665 | 14.7s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 304 | `mouse_pos_with_scale_factor` | 260 | 14.7s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 305 | `mouse_wheel_enabled` | 2 | 14.7s |  |
| 306 | `movieclip_begin_gradient_fill` | 0 | 15.3s |  |
| 307 | `movieclip_blend_mode_property` | 35 | 14.8s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 308 | `movieclip_create_text_field` | 90 | 14.8s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 309 | `movieclip_default_state` | 69 | 14.9s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 310 | `movieclip_depth_methods` | 98 | 14.6s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 311 | `movieclip_focusenabled` | 99 | 14.7s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 312 | `movieclip_get_instance_at_depth` | 28 | 14.5s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 313 | `movieclip_getbounds` | 191 | 14.8s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_gettextsnapshot` | 112 | 14.4s | [23](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 315 | `movieclip_hittest` | 92 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 316 | `movieclip_in_removed_button` | 4 | 14.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 317 | `movieclip_init_object` | 5 | 14.3s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 318 | `movieclip_invalid_get_bounds_1` | 75 | 14.9s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_invalid_get_bounds_2` | 75 | 14.8s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_invalid_get_bounds_3` | 13 | 14.6s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 321 | `movieclip_invalid_get_bounds_4` | 13 | 14.5s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 322 | `movieclip_invalid_get_bounds_5` | 11 | 14.5s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 323 | `movieclip_invalid_get_bounds_8` | 11 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_line_gradient_style` | 0 | 14.7s |  |
| 325 | `movieclip_lockroot` | 29 | 14.6s | [34](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_name_from_timeline` | 13 | 14.7s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_prototype_extension` | 5 | 14.4s |  |
| 328 | `movieclip_setmask` | 14 | 14.8s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 329 | `moviecliploader_flashvars` | 4 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 330 | `mutable_this` | 18 | 14.5s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 331 | `named_shapes` | 14 | 14.5s |  |
| 332 | `nan_scale` | 9 | 14.9s |  |
| 333 | `native_double_construct` | 12 | 14.9s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 334 | `native_objects_swf7` | 84 | 15.0s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 335 | `native_objects_swf8` | 84 | 15.2s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 336 | `native_subclasses` | 191 | 15.4s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 337 | `nested_textfields_in_buttons` | 0 | 14.5s |  |
| 338 | `new_method_wrap` | 4 | 15.6s |  |
| 339 | `new_object_enumerate` | 7 | 14.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 340 | `new_object_wrap` | 4 | 14.6s |  |
| 341 | `o` | 3 | 14.6s |  |
| 342 | `object_constructor` | 33 | 14.8s |  |
| 343 | `object_function` | 32 | 14.5s |  |
| 344 | `object_properties` | 31 | 14.8s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 345 | `object_prototypes` | 74 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 346 | `object_resolve` | 38 | 14.6s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 347 | `object_string_coerce_swf5` | 62 | 14.6s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 348 | `object_string_coerce_swf6` | 68 | 14.8s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 349 | `on_construct` | 25 | 15.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 350 | `parse_float` | 74 | 15.6s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 351 | `parse_int` | 64 | 15.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 352 | `path_string` | 322 | 15.8s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 353 | `place_and_lookup` | 30 | 15.6s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 354 | `placeobject_occupied_depth` | 6 | 15.3s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 355 | `point` | 175 | 15.8s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 356 | `primitive_instanceof` | 37 | 15.5s |  |
| 357 | `primitive_type_globals` | 557 | 15.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 358 | `printjob_props_swf5` | 45 | 15.3s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 359 | `printjob_props_swf6` | 45 | 15.4s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 360 | `printjob_props_swf7` | 45 | 15.3s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 361 | `property_invalid_base_clip` | 36 | 15.4s |  |
| 362 | `prototype_delete` | 12 | 15.1s |  |
| 363 | `prototype_enumerate` | 5 | 15.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 364 | `prototype_properties` | 17 | 15.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 365 | `rectangle` | 745 | 16.0s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 366 | `recursive_prototypes` | 0 | 15.0s |  |
| 367 | `register_and_init_order` | 231 | 15.7s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 368 | `register_class` | 66 | 15.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 369 | `register_class_return_value` | 16 | 15.3s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 370 | `register_class_swf6` | 37 | 15.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 371 | `register_class_with_sound` | 11 | 15.7s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 372 | `register_globals_across_frames` | 15 | 15.3s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 373 | `register_underflow` | 26 | 15.4s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 374 | `remove_movie_clip` | 29 | 15.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 375 | `removed_clip_halts_script` | 15 | 15.9s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 376 | `removed_target_clip_scope` | 35 | 15.4s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 377 | `resolve_different_root` | 2 | 14.9s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 378 | `rewind_depth` | 30 | 14.7s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 379 | `root_button_mode` | 10 | 14.8s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 380 | `root_global_parent` | 6 | 14.8s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 381 | `root_onload` | 1 | 14.6s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 382 | `sandbox_type_local_file` | 1 | 14.5s |  |
| 383 | `sandbox_type_local_network` | 1 | 14.6s |  |
| 384 | `selection` | 454 | 14.8s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 385 | `selection_handlers` | 27 | 14.6s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 386 | `set_interval` | 27 | 14.7s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 387 | `set_variable_scope` | 58 | 14.6s |  |
| 388 | `single_frame` | 1 | 14.9s |  |
| 389 | `slash_syntax` | 14 | 14.7s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 390 | `sound` | 628 | 14.9s | [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 391 | `sound_props_swf5` | 68 | 15.4s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 392 | `sound_props_swf6` | 68 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 393 | `sound_start_load` | 0 | 14.8s |  |
| 394 | `stage_display_state` | 16 | 14.7s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 395 | `stage_object_children` | 83 | 14.8s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 396 | `stage_object_enumerate` | 4 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 397 | `stage_object_properties` | 241 | 15.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 398 | `stage_object_properties_get_var` | 5 | 14.3s |  |
| 399 | `stage_object_properties_swf6` | 231 | 14.8s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 400 | `stage_property_representation` | 586 | 14.5s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 401 | `stage_scale_mode` | 39 | 14.5s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 402 | `strictequals_swf6` | 902 | 16.0s |  |
| 403 | `strictly_equals` | 7 | 14.6s |  |
| 404 | `string_coercion` | 117 | 14.9s | [54](ruffle-tests/_investigation/complete/string_coercion.md) |
| 405 | `string_methods` | 285 | 15.0s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 406 | `string_methods_negative_args` | 240 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 407 | `string_methods_swfv5` | 275 | 15.4s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 408 | `string_ops_swf6` | 95 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 409 | `string_paths_basic` | 4 | 14.4s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 410 | `string_paths_eval2` | 7 | 15.7s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 411 | `string_paths_hidden` | 54 | 15.2s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 412 | `string_paths_other` | 36 | 15.2s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 413 | `string_paths_unload` | 1 | 15.1s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 414 | `string_paths_variable_alias` | 4 | 14.9s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 415 | `string_paths_variable_scopes` | 5 | 15.1s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 416 | `stylesheet` | 283 | 15.9s |  |
| 417 | `stylesheet_transform` | 750 | 16.0s |  |
| 418 | `super_edge_cases` | 39 | 15.4s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 419 | `swf4_actions_bool` | 96 | 15.2s |  |
| 420 | `swf4_actions_coercion_order` | 158 | 14.6s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 421 | `swf4_bool` | 4 | 14.3s |  |
| 422 | `swf4_function_calls` | 7 | 14.3s |  |
| 423 | `swf5_encoding` | 3 | 14.2s |  |
| 424 | `swf5_global_funcs` | 232 | 14.3s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 425 | `swf5_no_closure` | 19 | 14.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 426 | `swf5_to_6_cross_call` | 29 | 14.8s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 427 | `swf6_case_insensitive` | 42 | 14.6s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 428 | `swf6_global_funcs` | 232 | 14.6s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 429 | `swf6_string_as_bool` | 15 | 14.6s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 430 | `swf6_to_5_cross_call` | 29 | 14.6s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 431 | `swf7_case_sensitive` | 44 | 14.5s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 432 | `swf7_global_funcs` | 232 | 14.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 433 | `tab_ordering_automatic_basic` | 92 | 14.5s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 434 | `tab_ordering_automatic_order_grid` | 21 | 14.5s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 435 | `tab_ordering_automatic_order_same_position` | 12 | 14.6s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 436 | `tab_ordering_children` | 208 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 437 | `tab_ordering_custom_basic` | 71 | 14.6s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 438 | `tab_ordering_custom_duplicate_index` | 22 | 14.6s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 439 | `tab_ordering_custom_i32_vs_u32` | 12 | 14.6s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 440 | `tab_ordering_custom_m1` | 29 | 14.5s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 441 | `tab_ordering_events` | 150 | 14.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 442 | `tab_ordering_events_mouse` | 65 | 14.8s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 443 | `tab_ordering_movieclip_enabled_default` | 462 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 444 | `tab_ordering_properties_tab_index_edge_case` | 4 | 15.8s |  |
| 445 | `tab_ordering_reverse` | 51 | 15.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 446 | `tab_ordering_tabbable` | 47 | 14.6s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 447 | `target_clip_removed` | 5 | 14.4s | [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 448 | `target_clip_swf6` | 2 | 14.2s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 449 | `target_path` | 14 | 14.1s |  |
| 450 | `tell_target` | 37 | 14.2s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 451 | `tell_target_invalid` | 6 | 14.3s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 452 | `tell_target_invalid_swf6` | 5 | 14.4s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 453 | `text_format` | 1146 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 454 | `text_format_display` | 21 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 455 | `text_format_font_max_length` | 2 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 456 | `text_format_get_text_extent_undefined_width` | 10 | 14.3s |  |
| 457 | `text_format_rounding_swf7` | 840 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 458 | `text_format_rounding_swf8` | 840 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 459 | `textfield_background_color` | 11 | 14.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 460 | `textfield_border_color` | 11 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 461 | `textfield_cache_as_bitmap` | 1 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 462 | `textfield_maxchars` | 3 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `textfield_properties` | 44 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 464 | `textfield_props_swf6` | 210 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 465 | `textfield_props_swf7` | 210 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 466 | `textfield_props_swf8` | 210 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `textfield_text` | 7 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textfield_variable` | 81 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `textsnapshot_available_text` | 20 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 470 | `textsnapshot_findtext` | 44 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 471 | `textsnapshot_gettext` | 55 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 472 | `textsnapshot_props_swf5` | 56 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 473 | `textsnapshot_props_swf6` | 56 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 474 | `textsnapshot_text_order` | 1 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 475 | `this_scoping` | 52 | 14.3s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 476 | `this_swf5` | 41 | 14.2s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 477 | `this_swf6` | 41 | 14.2s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 478 | `this_swf7` | 41 | 14.2s | [64](ruffle-tests/_investigation/complete/this_swf7.md) |
| 479 | `timeline_function_def` | 7 | 14.4s |  |
| 480 | `timer_run_actions` | 18 | 15.1s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 481 | `trace` | 8 | 14.9s |  |
| 482 | `transform` | 70 | 14.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 483 | `try_catch_finally` | 118 | 15.0s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 484 | `try_finally_simple` | 16 | 14.9s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 485 | `typeof` | 22 | 14.8s |  |
| 486 | `typeof_globals` | 7 | 14.6s |  |
| 487 | `uncaught_exception` | 1 | 14.9s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 488 | `uncaught_exception_bubbled` | 1 | 14.9s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 489 | `undefined_to_string_swf6` | 4 | 14.9s |  |
| 490 | `unescape` | 43 | 15.0s |  |
| 491 | `unload` | 52 | 15.3s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 492 | `unload_clip_event` | 4 | 15.2s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 493 | `unloadmovie` | 4 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 494 | `unloadmovie_method` | 3 | 15.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 495 | `unloadmovienum` | 13 | 15.0s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 496 | `use_hand_cursor` | 8 | 15.2s |  |
| 497 | `variable_args` | 5 | 15.3s |  |
| 498 | `waitforframe` | 7 | 15.2s |  |
| 499 | `waitforframe2` | 16 | 14.6s |  |
| 500 | `watch` | 117 | 15.0s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 501 | `watch_textfield` | 12 | 14.9s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 502 | `watch_virtual_property_proto` | 2 | 14.9s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 503 | `with` | 49 | 14.8s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 504 | `with_return` | 2 | 15.0s |  |
| 505 | `with_variable_scopes` | 43 | 14.7s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 506 | `xml` | 15 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 507 | `xml_append_child` | 28 | 14.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 508 | `xml_append_child_with_parent` | 20 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 509 | `xml_attributes_read` | 4 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 510 | `xml_cdata` | 11 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 511 | `xml_child_nodes_edge_cases` | 4 | 15.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_clone_expandos` | 19 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_first_last_child` | 8 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_has_child_nodes` | 3 | 14.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_idmap` | 21 | 15.1s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_ignore_comments` | 21 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_ignore_white` | 34 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_insert_before` | 20 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_inspect_createmethods` | 15 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_inspect_doctype` | 7 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_inspect_parsexml` | 62 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_inspect_xmldecl` | 7 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_namespaces` | 203 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_parent_and_child` | 5 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_remove_node` | 22 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_reparenting` | 14 | 14.5s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_siblings` | 10 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_to_string` | 13 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_to_string_comment` | 1 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_unescaping` | 23 | 14.5s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xmlnode_proto` | 1 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**26 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [12](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `globals_swf6` | 99.0% | 301 | 304 | 3 | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `textfield_props_swf5` | 98.9% | 173 | 175 | 2 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 7 | `native_objects_swf6` | 97.6% | 82 | 84 | 2 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `global_swf5_6_7_8_9` | 97.4% | 1115 | 1145 | 30 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 10 | `globals_swf5` | 97.4% | 296 | 304 | 8 | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 11 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 17 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 20 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 21 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 22 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 23 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 24 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 25 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 26 | `issue_2030` | 50.0% | 2 | 4 | 2 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 17.6s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 32.0s | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 44.3s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**84 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [12](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `globals_swf6` | 99.0% | 301/304 | 304 | 304 | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `textfield_props_swf5` | 98.9% | 173/175 | 175 | 175 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 7 | `native_objects_swf6` | 97.6% | 82/84 | 84 | 84 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `global_swf5_6_7_8_9` | 97.4% | 1115/1145 | 1145 | 1145 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 10 | `globals_swf5` | 97.4% | 296/304 | 304 | 304 | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 11 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 15 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 17 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 20 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 21 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 22 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 23 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 24 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 25 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 26 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 28 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 29 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) |
| 30 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 31 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 32 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 33 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 34 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 35 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 37 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 38 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 39 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 40 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 41 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 42 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 43 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 44 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 45 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 46 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 47 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 48 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 49 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 50 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 51 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 52 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 53 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 54 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 55 | `global_instance_decls` | 1.6% | 12/758 | 482 | 758 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 56 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 57 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 58 | `global_proto_decls` | 0.2% | 11/4497 | 692 | 4497 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 59 | `global_proto_decls_delete` | 0.0% | 1/4158 | 310 | 4158 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 60 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 61 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 62 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 63 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 64 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 65 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 66 | `geturl` | 0.0% | 0/7 | 0 | 7 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 67 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 68 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 69 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 70 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 72 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 73 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 74 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 75 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 76 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 77 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 78 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 79 | `target_clip_swf5` | 0.0% | 0/2 | 0 | 2 | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 80 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 81 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 82 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 83 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 84 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 16 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 12 | 2 |
| 17 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 18 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 19 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 6 | 1 |
| 20 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 21 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 22 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 23 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 24 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 24 | 7 |
| 25 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 26 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) | 29 | 0 | 29 |
| 27 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 28 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 0 | 1 |
| 29 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 30 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 31 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 39 | 9 |
| 32 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 33 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 34 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 35 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 36 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 37 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 38 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 47 | 11 |
| 39 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 40 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 13 | 4 |
| 41 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 42 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 43 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 44 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 45 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 46 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 47 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 48 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 49 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 50 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 51 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 52 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 53 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 54 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 55 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 56 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 57 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 58 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 59 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 0 | 1 |
| 60 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 15 | 4 |
| 61 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 64 | 6 |
| 62 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 63 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 64 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 65 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 66 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 67 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 68 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 69 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 70 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 71 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 158 | 158 | 0 |
