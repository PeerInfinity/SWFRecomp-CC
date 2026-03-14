# Ruffle Test Results (Filtered)

**Date**: 2026-03-14 01:03 UTC

**Git SHA**: `0f35011d0c`

**Run Duration**: 156m 21s

**Filtered**: 51 tests ignored out of 618 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 567 |
| Passing | **533** (94.0%) |
| Failing | 34 |
| Total expected lines | 79119 |
| Matching lines | 68762 (86.9%) |
| Mismatched lines | 10357 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 34 | 100.0% |

## Passing Tests

**533 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.5s |  |
| 2 | `action_to_integer` | 28 | 14.3s |  |
| 3 | `add` | 28 | 14.2s |  |
| 4 | `add2` | 354 | 14.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.3s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.3s |  |
| 7 | `add_swf5` | 28 | 14.3s |  |
| 8 | `arguments` | 127 | 14.3s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 14.3s |  |
| 11 | `array_constructor` | 30 | 14.3s |  |
| 12 | `array_enumerate` | 4 | 14.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.3s |  |
| 14 | `array_properties` | 36 | 14.2s |  |
| 15 | `array_prototyping` | 12 | 14.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 14.3s |  |
| 17 | `array_sort_random` | 443 | 14.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 14.5s |  |
| 19 | `array_trivial` | 209 | 14.4s |  |
| 20 | `as1_constructor_v6` | 35 | 14.3s |  |
| 21 | `as1_constructor_v7` | 35 | 14.7s |  |
| 22 | `as2_oop` | 13 | 14.7s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 14.7s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 14.7s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 14.8s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 14.5s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 14.4s |  |
| 28 | `as_broadcaster_undef` | 89 | 14.6s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 14.4s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 14.4s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 14.5s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 14.5s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 14.5s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 14.4s |  |
| 36 | `as_transformed_flag` | 20 | 14.4s |  |
| 37 | `asnative` | 34 | 14.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 14.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 14.5s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 14.7s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 14.5s |  |
| 43 | `bitand` | 1058 | 17.1s |  |
| 44 | `bitmap_data_colortransform` | 0 | 14.6s |  |
| 45 | `bitmap_data_fillrect` | 0 | 14.4s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 14.3s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 14.4s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 15.3s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 14.8s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.6s |  |
| 51 | `bitor` | 1058 | 17.1s |  |
| 52 | `biturshift` | 14 | 14.3s |  |
| 53 | `biturshift_swf8` | 14 | 15.5s |  |
| 54 | `bitxor` | 1058 | 18.5s |  |
| 55 | `boxed_primitives` | 24 | 15.4s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 15.2s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_key_events` | 14 | 15.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events_special` | 45 | 16.2s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_keypress` | 3 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_press` | 25 | 15.5s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_tab` | 20 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_textinput` | 4 | 15.1s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_order` | 2 | 14.9s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_properties_special_cases` | 22 | 15.2s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_v5` | 18 | 14.9s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v6` | 18 | 14.9s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `call` | 63 | 15.2s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 69 | `call_method_empty_name` | 1 | 14.9s |  |
| 70 | `capabilities_resolution` | 8 | 15.1s |  |
| 71 | `catch_references_registers` | 2 | 15.0s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 72 | `click_block` | 5 | 15.0s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 73 | `clip_constructors` | 8 | 15.2s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 74 | `clip_events` | 19 | 15.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `clone_sprite_types` | 24 | 15.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 76 | `closure_scope` | 7 | 15.4s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 77 | `coerce_to_primitive_resolve` | 17 | 15.2s | [45](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 78 | `color` | 57 | 15.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 15.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 15.2s |  |
| 81 | `constructor_function` | 2 | 15.4s |  |
| 82 | `context_menu` | 39 | 16.3s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 15.6s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 15.1s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 85 | `cross_movie_root` | 10 | 15.4s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 86 | `custom_clip_methods` | 4 | 15.5s | [11](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 87 | `default_names` | 52 | 15.5s | [13](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 88 | `define_function2` | 8 | 15.5s |  |
| 89 | `define_function2_preload` | 13 | 15.3s |  |
| 90 | `define_function2_preload_order` | 4 | 16.9s |  |
| 91 | `define_function_case_sensitive` | 2 | 14.9s |  |
| 92 | `define_local` | 27 | 14.9s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 93 | `define_local_with_paths` | 54 | 15.0s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `delete` | 3 | 15.1s |  |
| 95 | `device_font_spacing` | 91 | 15.2s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 96 | `display_object_properties` | 2 | 14.8s |  |
| 97 | `divide_swf4` | 107 | 14.8s |  |
| 98 | `do_init_action` | 3 | 15.0s |  |
| 99 | `do_init_action_child` | 12 | 14.9s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 100 | `drag_drop` | 10 | 14.8s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 101 | `drag_over_from_outside` | 1 | 15.0s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_without_startdrag` | 1 | 15.2s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `duplicate_movie_clip` | 20 | 15.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `duplicate_movie_clip_drawing` | 2 | 15.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 105 | `edittext_align` | 60 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_align_trailing_spaces_swf7` | 576 | 15.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf8` | 576 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_antialiastype` | 296 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_autosize` | 71 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize_setter` | 20 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_default_format` | 221 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format_font_style` | 335 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_focus_selection` | 2 | 14.8s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_font_size` | 45 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_hscroll` | 27 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_align_swf7` | 52 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf8` | 52 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_color` | 114 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_condensewhite_swf7` | 311 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf8` | 311 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_entity` | 4 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_roundtrip` | 17 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_swf7` | 5377 | 16.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf8` | 5377 | 16.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_input` | 1 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input_newlines` | 9 | 16.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_leading` | 9 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_letter_spacing` | 15 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_margins` | 25 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_newline_stripping` | 64 | 19.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_newlines` | 30 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_password` | 5 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_password_copy` | 4 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_paste_empty` | 2 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_place_caret` | 2 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_programmatic_focus` | 12 | 15.0s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_restrict` | 191 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_restrict_paste` | 5 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_scroll` | 54 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_stylesheet` | 325 | 15.6s | [56](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_tab_focus` | 13 | 14.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_tab_stops` | 60 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_tag_indent` | 31 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_text_height_leading` | 20 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_underline` | 40 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_width_height` | 103 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `empty_movieclip_can_attach_movies` | 11 | 14.9s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 148 | `enumerate` | 64 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 149 | `equals` | 32 | 14.8s |  |
| 150 | `equals2_swf5` | 926 | 16.5s |  |
| 151 | `equals2_swf6` | 926 | 16.4s |  |
| 152 | `equals2_swf7` | 926 | 16.2s |  |
| 153 | `equals_swf4` | 665 | 15.3s |  |
| 154 | `equals_swf4_alt` | 32 | 14.5s |  |
| 155 | `equals_swf5` | 32 | 14.6s |  |
| 156 | `error` | 58 | 14.6s |  |
| 157 | `escape` | 14 | 14.6s |  |
| 158 | `execution_order1` | 5 | 15.0s |  |
| 159 | `execution_order2` | 7 | 15.1s |  |
| 160 | `execution_order3` | 4 | 15.2s |  |
| 161 | `execution_order4` | 12 | 15.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 162 | `export_assets` | 3 | 15.2s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 163 | `extends_chain` | 134 | 15.2s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 164 | `extends_native_type` | 11 | 14.9s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 165 | `external_interface` | 84 | 15.2s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_escapexml` | 26 | 15.2s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_jsquotestring` | 21 | 15.2s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_toas_basic` | 354 | 15.5s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_toxml_array` | 25 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_toxml_basic` | 179 | 14.9s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_unescapexml` | 40 | 14.6s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `focus_keyboard_press` | 60 | 14.6s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 173 | `focus_mouse` | 45 | 14.5s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focus_mouse_focusable` | 8 | 14.9s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focus_mouse_rollout` | 4 | 14.4s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_remove` | 33 | 14.7s |  |
| 177 | `focus_root_movie` | 2 | 14.7s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 178 | `focus_visibility_change` | 45 | 14.7s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 179 | `focusrect_focuslost` | 4 | 14.7s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 180 | `focusrect_mouse_swf8` | 0 | 14.6s |  |
| 181 | `focusrect_mouse_swf9` | 0 | 15.1s |  |
| 182 | `focusrect_property_swf5` | 1237 | 15.2s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 183 | `focusrect_property_swf6` | 1237 | 15.1s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 184 | `focusrect_property_swf7` | 1237 | 15.1s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 185 | `focusrect_swf5` | 6 | 15.0s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 186 | `focusrect_swf6` | 42 | 14.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 187 | `frame_size_translated_negative` | 21 | 14.9s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 188 | `frame_size_translated_positive` | 21 | 15.0s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 189 | `function_as_function` | 35 | 14.8s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 190 | `function_base_clip` | 8 | 14.9s |  |
| 191 | `function_base_clip_readded` | 11 | 14.9s |  |
| 192 | `function_base_clip_removed` | 25 | 15.0s |  |
| 193 | `function_suppress_and_preload` | 28 | 14.9s |  |
| 194 | `funky_function_calls` | 56 | 15.0s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 195 | `get_bytes_total` | 4 | 14.8s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 196 | `get_variable_in_scope` | 29 | 14.9s |  |
| 197 | `getproperty` | 28 | 14.9s |  |
| 198 | `getproperty_swf4` | 28 | 16.1s |  |
| 199 | `getproperty_swf5` | 28 | 14.3s |  |
| 200 | `gettextextent` | 56 | 14.3s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 201 | `global_array` | 3 | 14.2s |  |
| 202 | `global_is_bare` | 7 | 14.2s |  |
| 203 | `global_swf5_6_7_8_9` | 1145 | 14.9s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 204 | `global_swf6_7_8` | 15 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 205 | `globals_swf5` | 304 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 206 | `globals_swf6` | 304 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 207 | `globals_swf7` | 304 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 208 | `globals_swf8` | 304 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 209 | `goto_advance1` | 6 | 14.4s |  |
| 210 | `goto_advance2` | 2 | 14.4s |  |
| 211 | `goto_both_ways1` | 3 | 14.3s |  |
| 212 | `goto_both_ways2` | 3 | 14.3s |  |
| 213 | `goto_execution_order` | 2 | 14.2s |  |
| 214 | `goto_execution_order2` | 2 | 14.2s |  |
| 215 | `goto_frame` | 12 | 15.1s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 216 | `goto_frame2` | 44 | 15.1s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 217 | `goto_frame_number` | 3 | 14.7s |  |
| 218 | `goto_label` | 17 | 14.8s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 219 | `goto_methods` | 40 | 14.7s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 220 | `goto_rewind1` | 1 | 14.6s |  |
| 221 | `goto_rewind2` | 3 | 14.6s |  |
| 222 | `goto_rewind3` | 2 | 14.7s |  |
| 223 | `greater_swf6` | 1175 | 16.7s |  |
| 224 | `greater_swf7` | 1175 | 16.7s |  |
| 225 | `greaterthan_swf5` | 1 | 14.7s |  |
| 226 | `greaterthan_swf8` | 1 | 14.8s |  |
| 227 | `has_own_property` | 32 | 14.7s |  |
| 228 | `hittest_lockroot` | 15 | 14.9s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 229 | `hittest_morph` | 70 | 15.0s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [36](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 230 | `hittest_winding_rule` | 12 | 14.9s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 231 | `infinite_recursion_function` | 4 | 14.7s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 232 | `infinite_recursion_function_in_setter` | 131 | 14.7s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 233 | `infinite_recursion_virtual_property` | 67 | 14.7s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 234 | `init_array_invalid` | 4 | 14.6s |  |
| 235 | `init_object_invalid` | 4 | 16.5s |  |
| 236 | `init_object_order` | 15 | 14.8s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 237 | `instanceof_coercions` | 88 | 15.6s | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 238 | `interface_implements_op` | 47 | 16.1s | [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 239 | `is_finite` | 49 | 15.5s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 240 | `is_finite_swf6` | 49 | 15.5s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 241 | `is_prototype_of` | 89 | 15.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 242 | `issue_1086` | 1 | 15.3s |  |
| 243 | `issue_1104` | 2 | 15.4s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 244 | `issue_1671` | 0 | 15.5s |  |
| 245 | `issue_1906` | 4 | 15.3s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 246 | `issue_2166` | 9 | 14.6s |  |
| 247 | `issue_2870` | 3 | 14.9s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 248 | `issue_3169` | 2 | 14.9s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 249 | `issue_3446` | 1 | 14.7s |  |
| 250 | `issue_3522` | 2 | 14.7s |  |
| 251 | `issue_4377` | 2 | 14.5s |  |
| 252 | `issue_710` | 4 | 14.6s |  |
| 253 | `issue_768` | 3 | 14.7s | [29](ruffle-tests/_investigation/complete/issue_768.md) |
| 254 | `issue_9327` | 2 | 14.6s |  |
| 255 | `issue_9885` | 2 | 14.5s |  |
| 256 | `key_isToggled` | 9 | 14.5s |  |
| 257 | `lessthan` | 41 | 14.7s |  |
| 258 | `lessthan2_swf5` | 1226 | 16.6s |  |
| 259 | `lessthan2_swf6` | 1226 | 16.6s |  |
| 260 | `lessthan2_swf7` | 1226 | 16.9s |  |
| 261 | `lessthan_swf4` | 902 | 15.7s |  |
| 262 | `lessthan_swf4_alt` | 41 | 14.6s |  |
| 263 | `lessthan_swf5` | 41 | 14.5s |  |
| 264 | `loadmovie` | 2 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 265 | `loadmovie_fail` | 2 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 266 | `loadmovie_flashvars` | 4 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 267 | `loadmovie_method` | 2 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 268 | `loadmovie_registerclass` | 30 | 14.8s | [10](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 269 | `loadmovie_replace_root` | 5 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 270 | `loadmovie_var_persistence` | 8 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 271 | `loadmovienum` | 3 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 272 | `loadmovienum_cross_version_prototype` | 9 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 273 | `loadvariables` | 2 | 14.9s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 274 | `loadvariables2` | 8 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 275 | `loadvariablesnum` | 2 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 276 | `local_to_global` | 49 | 14.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 277 | `localconnection_properties` | 8 | 14.8s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 278 | `lock_root` | 1 | 14.7s |  |
| 279 | `logical_ops_swf4` | 90 | 14.6s |  |
| 280 | `logical_ops_swf8` | 108 | 14.7s |  |
| 281 | `looping` | 6 | 14.6s |  |
| 282 | `mask_reapply` | 0 | 15.1s |  |
| 283 | `mask_with_drawing` | 0 | 14.7s |  |
| 284 | `math_min_max` | 101 | 14.9s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 285 | `math_swf6` | 530 | 15.2s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 286 | `math_swf7` | 530 | 15.1s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 287 | `math_swf8` | 530 | 15.2s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 288 | `matrix` | 171 | 15.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 289 | `mcl_as_broadcaster` | 12 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 290 | `mcl_events_swf_version` | 232 | 15.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 291 | `mcl_getprogress` | 30 | 14.9s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mcl_loadclip` | 149 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 293 | `mcl_loadclip_properties` | 6 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 294 | `mcl_loadclip_replace_root` | 1 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 295 | `mcl_mislabeled_target` | 6 | 14.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_target_gif87a` | 6 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 297 | `mcl_target_gif89a` | 6 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_target_jpg` | 6 | 14.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 299 | `mcl_target_png` | 6 | 14.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 300 | `mcl_unloadclip` | 5 | 14.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 301 | `mouse_events` | 8 | 14.3s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 302 | `mouse_events_visible_enabled` | 12 | 14.5s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 303 | `mouse_hover_events_while_dragging` | 1 | 14.4s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 304 | `mouse_listeners` | 67 | 14.3s |  |
| 305 | `mouse_pos` | 665 | 14.3s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 306 | `mouse_pos_with_scale_factor` | 260 | 14.3s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 307 | `mouse_wheel_enabled` | 2 | 14.2s |  |
| 308 | `movieclip_begin_gradient_fill` | 0 | 14.8s |  |
| 309 | `movieclip_blend_mode_property` | 35 | 14.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 310 | `movieclip_create_text_field` | 90 | 14.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 311 | `movieclip_default_state` | 69 | 15.2s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 312 | `movieclip_depth_methods` | 98 | 15.0s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 313 | `movieclip_focusenabled` | 99 | 14.6s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_get_instance_at_depth` | 28 | 14.7s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 315 | `movieclip_getbounds` | 191 | 14.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 316 | `movieclip_gettextsnapshot` | 112 | 14.7s | [23](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 317 | `movieclip_hittest` | 92 | 14.6s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 318 | `movieclip_in_removed_button` | 4 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 319 | `movieclip_init_object` | 5 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 320 | `movieclip_invalid_get_bounds_1` | 75 | 15.2s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 321 | `movieclip_invalid_get_bounds_2` | 75 | 15.2s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 322 | `movieclip_invalid_get_bounds_3` | 13 | 15.1s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 323 | `movieclip_invalid_get_bounds_4` | 13 | 15.0s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_invalid_get_bounds_5` | 11 | 14.9s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_invalid_get_bounds_8` | 11 | 14.8s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_line_gradient_style` | 0 | 15.4s |  |
| 327 | `movieclip_lockroot` | 29 | 15.1s | [34](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_name_from_timeline` | 13 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_prototype_extension` | 5 | 14.5s |  |
| 330 | `movieclip_setmask` | 14 | 14.8s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 331 | `moviecliploader_flashvars` | 4 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 332 | `mutable_this` | 18 | 14.6s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 333 | `named_shapes` | 14 | 14.8s |  |
| 334 | `nan_scale` | 9 | 14.7s |  |
| 335 | `native_double_construct` | 12 | 14.7s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 336 | `native_objects_swf7` | 84 | 15.2s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 337 | `native_objects_swf8` | 84 | 15.1s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 338 | `nested_textfields_in_buttons` | 0 | 14.7s |  |
| 339 | `new_method_wrap` | 4 | 16.0s |  |
| 340 | `new_object_enumerate` | 7 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 341 | `new_object_wrap` | 4 | 14.4s |  |
| 342 | `o` | 3 | 14.3s |  |
| 343 | `object_constructor` | 33 | 14.4s |  |
| 344 | `object_function` | 32 | 14.4s |  |
| 345 | `object_properties` | 31 | 14.7s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 346 | `object_prototypes` | 74 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 347 | `object_resolve` | 38 | 14.6s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 348 | `object_string_coerce_swf5` | 62 | 14.6s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 349 | `object_string_coerce_swf6` | 68 | 14.6s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 350 | `on_construct` | 25 | 14.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 351 | `parse_float` | 74 | 14.4s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 352 | `parse_int` | 64 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 353 | `path_string` | 322 | 14.7s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 354 | `place_and_lookup` | 30 | 14.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 355 | `placeobject_occupied_depth` | 6 | 14.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 356 | `point` | 175 | 14.8s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 357 | `primitive_instanceof` | 37 | 14.5s |  |
| 358 | `primitive_type_globals` | 557 | 14.6s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 359 | `printjob_props_swf5` | 45 | 14.8s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 360 | `printjob_props_swf6` | 45 | 14.5s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 361 | `printjob_props_swf7` | 45 | 14.6s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 362 | `property_invalid_base_clip` | 36 | 14.6s |  |
| 363 | `prototype_delete` | 12 | 14.3s |  |
| 364 | `prototype_enumerate` | 5 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 365 | `prototype_properties` | 17 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 366 | `rectangle` | 745 | 15.2s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 367 | `recursive_prototypes` | 0 | 14.4s |  |
| 368 | `register_and_init_order` | 231 | 14.9s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 369 | `register_class` | 66 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 370 | `register_class_return_value` | 16 | 14.6s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 371 | `register_class_swf6` | 37 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 372 | `register_class_with_sound` | 11 | 14.5s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 373 | `register_globals_across_frames` | 15 | 14.4s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 374 | `register_underflow` | 26 | 14.4s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 375 | `remove_movie_clip` | 29 | 14.5s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 376 | `removed_clip_halts_script` | 15 | 14.8s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 377 | `removed_target_clip_scope` | 35 | 14.6s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 378 | `resolve_different_root` | 2 | 15.3s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 379 | `rewind_depth` | 30 | 15.0s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 380 | `root_button_mode` | 10 | 15.1s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 381 | `root_global_parent` | 6 | 15.0s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 382 | `root_onload` | 1 | 14.8s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 383 | `sandbox_type_local_file` | 1 | 14.8s |  |
| 384 | `sandbox_type_local_network` | 1 | 14.8s |  |
| 385 | `selection` | 454 | 15.0s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 386 | `selection_handlers` | 27 | 14.9s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 387 | `set_interval` | 27 | 15.0s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 388 | `set_variable_scope` | 58 | 14.9s |  |
| 389 | `single_frame` | 1 | 14.9s |  |
| 390 | `slash_syntax` | 14 | 14.9s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 391 | `sound` | 628 | 15.2s | [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 392 | `sound_props_swf5` | 68 | 16.1s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 393 | `sound_props_swf6` | 68 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 394 | `sound_start_load` | 0 | 14.6s |  |
| 395 | `stage_display_state` | 16 | 14.6s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 396 | `stage_object_children` | 83 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 397 | `stage_object_enumerate` | 4 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 398 | `stage_object_properties` | 241 | 15.0s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 399 | `stage_object_properties_get_var` | 5 | 14.6s |  |
| 400 | `stage_object_properties_swf6` | 231 | 14.8s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 401 | `stage_property_representation` | 586 | 14.5s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 402 | `stage_scale_mode` | 39 | 14.6s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 403 | `strictequals_swf6` | 902 | 16.1s |  |
| 404 | `strictly_equals` | 7 | 14.4s |  |
| 405 | `string_coercion` | 117 | 14.8s | [54](ruffle-tests/_investigation/complete/string_coercion.md) |
| 406 | `string_methods` | 285 | 15.3s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 407 | `string_methods_negative_args` | 240 | 15.1s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 408 | `string_methods_swfv5` | 275 | 15.5s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 409 | `string_ops_swf6` | 95 | 14.7s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 410 | `string_paths_basic` | 4 | 14.4s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 411 | `string_paths_eval2` | 7 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 412 | `string_paths_hidden` | 54 | 14.6s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 413 | `string_paths_other` | 36 | 14.6s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 414 | `string_paths_unload` | 1 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 415 | `string_paths_variable_alias` | 4 | 14.6s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 416 | `string_paths_variable_scopes` | 5 | 14.6s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 417 | `stylesheet` | 283 | 15.6s |  |
| 418 | `stylesheet_transform` | 750 | 15.8s |  |
| 419 | `super_edge_cases` | 39 | 15.0s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 420 | `swf4_actions_bool` | 96 | 14.7s |  |
| 421 | `swf4_actions_coercion_order` | 158 | 15.1s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 422 | `swf4_bool` | 4 | 14.6s |  |
| 423 | `swf4_function_calls` | 7 | 14.5s |  |
| 424 | `swf5_encoding` | 3 | 14.5s |  |
| 425 | `swf5_global_funcs` | 232 | 14.6s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 426 | `swf5_no_closure` | 19 | 14.6s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 427 | `swf5_to_6_cross_call` | 29 | 15.0s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 428 | `swf6_case_insensitive` | 42 | 14.7s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 429 | `swf6_global_funcs` | 232 | 14.7s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 430 | `swf6_string_as_bool` | 15 | 14.7s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 431 | `swf6_to_5_cross_call` | 29 | 14.6s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 432 | `swf7_case_sensitive` | 44 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 433 | `swf7_global_funcs` | 232 | 14.8s | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 434 | `tab_ordering_automatic_basic` | 92 | 14.8s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 435 | `tab_ordering_automatic_order_grid` | 21 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 436 | `tab_ordering_automatic_order_same_position` | 12 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 437 | `tab_ordering_children` | 208 | 14.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 438 | `tab_ordering_custom_basic` | 71 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 439 | `tab_ordering_custom_duplicate_index` | 22 | 14.8s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 440 | `tab_ordering_custom_i32_vs_u32` | 12 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 441 | `tab_ordering_custom_m1` | 29 | 14.8s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 442 | `tab_ordering_events` | 150 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 443 | `tab_ordering_events_mouse` | 65 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 444 | `tab_ordering_movieclip_enabled_default` | 462 | 15.0s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 445 | `tab_ordering_properties_tab_index_edge_case` | 4 | 18.4s |  |
| 446 | `tab_ordering_reverse` | 51 | 15.6s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 447 | `tab_ordering_tabbable` | 47 | 15.4s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 448 | `target_clip_removed` | 5 | 15.0s | [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 449 | `target_clip_swf5` | 2 | 15.5s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 450 | `target_clip_swf6` | 2 | 15.6s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 451 | `target_path` | 14 | 15.6s |  |
| 452 | `tell_target` | 37 | 16.8s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 453 | `tell_target_invalid` | 6 | 15.4s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 454 | `tell_target_invalid_swf6` | 5 | 15.4s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 455 | `text_format` | 1146 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 456 | `text_format_display` | 21 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 457 | `text_format_font_max_length` | 2 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 458 | `text_format_get_text_extent_undefined_width` | 10 | 14.9s |  |
| 459 | `text_format_rounding_swf7` | 840 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 460 | `text_format_rounding_swf8` | 840 | 15.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 461 | `textfield_background_color` | 11 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 462 | `textfield_border_color` | 11 | 15.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `textfield_cache_as_bitmap` | 1 | 15.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 464 | `textfield_maxchars` | 3 | 16.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 465 | `textfield_properties` | 44 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 466 | `textfield_props_swf5` | 175 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `textfield_props_swf6` | 210 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textfield_props_swf7` | 210 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `textfield_props_swf8` | 210 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 470 | `textfield_text` | 7 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 471 | `textfield_variable` | 81 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 472 | `textsnapshot_available_text` | 20 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 473 | `textsnapshot_findtext` | 44 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 474 | `textsnapshot_gettext` | 55 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 475 | `textsnapshot_props_swf5` | 56 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 476 | `textsnapshot_props_swf6` | 56 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 477 | `textsnapshot_text_order` | 1 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 478 | `this_scoping` | 52 | 14.5s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 479 | `this_swf5` | 41 | 14.4s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 480 | `this_swf6` | 41 | 14.3s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 481 | `this_swf7` | 41 | 14.4s | [64](ruffle-tests/_investigation/complete/this_swf7.md) |
| 482 | `timeline_function_def` | 7 | 14.5s |  |
| 483 | `timer_run_actions` | 18 | 16.6s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 484 | `trace` | 8 | 14.5s |  |
| 485 | `transform` | 70 | 14.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 486 | `try_catch_finally` | 118 | 14.8s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 487 | `try_finally_simple` | 16 | 14.7s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 488 | `typeof` | 22 | 14.9s |  |
| 489 | `typeof_globals` | 7 | 15.0s |  |
| 490 | `uncaught_exception` | 1 | 15.6s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 491 | `uncaught_exception_bubbled` | 1 | 15.3s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 492 | `undefined_to_string_swf6` | 4 | 15.4s |  |
| 493 | `unescape` | 43 | 15.4s |  |
| 494 | `unload` | 52 | 15.8s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 495 | `unload_clip_event` | 4 | 14.9s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 496 | `unloadmovie` | 4 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 497 | `unloadmovie_method` | 3 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 498 | `unloadmovienum` | 13 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 499 | `use_hand_cursor` | 8 | 14.7s |  |
| 500 | `variable_args` | 5 | 14.7s |  |
| 501 | `waitforframe` | 7 | 14.7s |  |
| 502 | `waitforframe2` | 16 | 16.1s |  |
| 503 | `watch` | 117 | 15.9s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 504 | `watch_textfield` | 12 | 15.6s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 505 | `watch_virtual_property_proto` | 2 | 16.1s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 506 | `with` | 49 | 15.9s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 507 | `with_return` | 2 | 15.9s |  |
| 508 | `with_variable_scopes` | 43 | 15.7s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 509 | `xml` | 15 | 15.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 510 | `xml_append_child` | 28 | 15.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 511 | `xml_append_child_with_parent` | 20 | 15.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_cdata` | 11 | 15.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_child_nodes_edge_cases` | 4 | 15.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_clone_expandos` | 19 | 15.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_first_last_child` | 8 | 15.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_has_child_nodes` | 3 | 15.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_idmap` | 21 | 15.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_ignore_comments` | 21 | 15.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_ignore_white` | 34 | 15.5s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_insert_before` | 20 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_inspect_createmethods` | 15 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_inspect_doctype` | 7 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_inspect_parsexml` | 62 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_inspect_xmldecl` | 7 | 15.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_namespaces` | 203 | 15.1s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_parent_and_child` | 5 | 15.1s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_remove_node` | 22 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_reparenting` | 14 | 15.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_siblings` | 10 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_to_string` | 13 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_to_string_comment` | 1 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_unescaping` | 23 | 15.1s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 533 | `xmlnode_proto` | 1 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**12 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `clone_sprite_edittext` | 95.7% | 90 | 94 | 4 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `clone_sprite_edittext_dynamic` | 90.7% | 78 | 86 | 8 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 7 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 9 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 11 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 12 | `issue_2030` | 50.0% | 2 | 4 | 2 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**34 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 2 | `clone_sprite_edittext` | 95.7% | 90/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `clone_sprite_edittext_dynamic` | 90.7% | 78/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 7 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `text_blocks_clicks` | 75.0% | 3/4 | 4 | 4 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 9 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 11 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 12 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 13 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) |
| 14 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 17 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 18 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 19 | `global_proto_decls` | 2.1% | 96/4497 | 1163 | 4497 | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 20 | `global_proto_decls_delete` | 0.4% | 18/4158 | 573 | 4158 | [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 21 | `global_instance_decls` | 0.4% | 3/758 | 596 | 758 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [24](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 22 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 23 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 24 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 25 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 26 | `geturl` | 0.0% | 0/7 | 0 | 7 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 28 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 29 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 30 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 31 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 32 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 33 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 34 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 3 | 3 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
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
| 18 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 19 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 20 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 21 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 22 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 5 | 4 | 1 |
| 23 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 24 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 29 | 26 | 3 |
| 25 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 26 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 27 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 28 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 0 | 1 |
| 29 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 30 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 31 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 44 | 40 | 4 |
| 32 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 4 | 3 | 1 |
| 33 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 34 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 35 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 36 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 37 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 38 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 56 | 47 | 9 |
| 39 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 40 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 41 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 42 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 43 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 44 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 45 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 46 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 47 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 48 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
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
| 60 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 18 | 16 | 2 |
| 61 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 69 | 65 | 4 |
| 62 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 63 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 64 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 65 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 2 | 2 | 0 |
| 66 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 67 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 68 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 69 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 70 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 71 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 26 | 25 | 1 |
| | *(tests not in any document)* | 157 | 157 | 0 |
