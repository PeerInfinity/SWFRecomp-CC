# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-13 20:29 UTC

**Git SHA**: `7714e90841`

**Run Duration**: 156m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 618 |
| Passing | **537** (86.9%) |
| Failing | 81 |
| Total expected lines | 91484 |
| Matching lines | 76451 (83.6%) |
| Mismatched lines | 15033 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 78 | 96.3% |
| Runtime Segfault | 2 | 2.5% |
| Timeout | 1 | 1.2% |

## Passing Tests

**537 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 15.0s |  |
| 2 | `action_to_integer` | 28 | 15.0s |  |
| 3 | `add` | 28 | 15.2s |  |
| 4 | `add2` | 354 | 15.2s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.1s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.0s |  |
| 7 | `add_swf5` | 28 | 14.9s |  |
| 8 | `arguments` | 127 | 15.0s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 15.0s |  |
| 11 | `array_constructor` | 30 | 15.0s |  |
| 12 | `array_enumerate` | 4 | 14.9s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 15.0s |  |
| 14 | `array_properties` | 36 | 14.9s |  |
| 15 | `array_prototyping` | 12 | 15.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.5s |  |
| 17 | `array_sort` | 161 | 16.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 15.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 15.6s |  |
| 20 | `array_trivial` | 209 | 15.5s |  |
| 21 | `as1_constructor_v6` | 35 | 15.4s |  |
| 22 | `as1_constructor_v7` | 35 | 14.7s |  |
| 23 | `as2_oop` | 13 | 14.8s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 15.1s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 14.9s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 15.2s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 15.0s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 14.5s |  |
| 29 | `as_broadcaster_undef` | 89 | 14.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 14.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 14.8s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 15.3s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 15.8s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 15.7s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 14.8s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 14.9s |  |
| 37 | `as_transformed_flag` | 20 | 15.5s |  |
| 38 | `asnative` | 34 | 14.9s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 15.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 14.9s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 14.7s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 14.4s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 14.2s |  |
| 44 | `bitand` | 1058 | 16.8s |  |
| 45 | `bitmap_data_colortransform` | 0 | 14.5s |  |
| 46 | `bitmap_data_fillrect` | 0 | 14.3s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 14.2s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 14.2s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 15.1s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 14.7s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.5s |  |
| 52 | `bitor` | 1058 | 16.9s |  |
| 53 | `biturshift` | 14 | 14.2s |  |
| 54 | `biturshift_swf8` | 14 | 15.7s |  |
| 55 | `bitxor` | 1058 | 18.4s |  |
| 56 | `boxed_primitives` | 24 | 15.7s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 15.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 15.5s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 15.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 16.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 15.5s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 15.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 15.8s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 15.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 15.8s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 15.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 15.5s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 15.5s |  |
| 71 | `capabilities_resolution` | 8 | 15.4s |  |
| 72 | `catch_references_registers` | 2 | 15.4s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 15.4s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 15.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 15.7s | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 15.3s | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 15.0s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 17 | 14.9s | [45](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `color` | 57 | 15.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `color_transform` | 48 | 15.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `conflicting_instance_names` | 23 | 14.9s |  |
| 82 | `constructor_function` | 2 | 14.8s |  |
| 83 | `context_menu` | 39 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 84 | `context_menu_item` | 41 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 85 | `create_empty_movie_clip` | 3 | 14.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 86 | `cross_movie_root` | 10 | 14.6s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 87 | `custom_clip_methods` | 4 | 14.7s | [11](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 88 | `default_names` | 52 | 15.1s | [13](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 89 | `define_function2` | 8 | 15.0s |  |
| 90 | `define_function2_preload` | 13 | 15.2s |  |
| 91 | `define_function2_preload_order` | 4 | 17.3s |  |
| 92 | `define_function_case_sensitive` | 2 | 15.1s |  |
| 93 | `define_local` | 27 | 15.3s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 94 | `define_local_with_paths` | 54 | 15.0s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `delete` | 3 | 15.0s |  |
| 96 | `device_font_spacing` | 91 | 14.9s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 97 | `display_object_properties` | 2 | 14.7s |  |
| 98 | `divide_swf4` | 107 | 14.6s |  |
| 99 | `do_init_action` | 3 | 14.9s |  |
| 100 | `do_init_action_child` | 12 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 101 | `drag_drop` | 10 | 14.9s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_from_outside` | 1 | 14.8s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `drag_over_without_startdrag` | 1 | 14.8s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 104 | `duplicate_movie_clip` | 20 | 14.7s | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 105 | `duplicate_movie_clip_drawing` | 2 | 15.3s | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 106 | `edittext_align` | 60 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf7` | 576 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_align_trailing_spaces_swf8` | 576 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_antialiastype` | 296 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize` | 71 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_autosize_setter` | 20 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format` | 221 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_default_format_font_style` | 335 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_focus_selection` | 2 | 14.3s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_font_size` | 45 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_hscroll` | 27 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf7` | 52 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_align_swf8` | 52 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_color` | 114 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf7` | 311 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_condensewhite_swf8` | 311 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_entity` | 4 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_roundtrip` | 17 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf7` | 5377 | 15.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_swf8` | 5377 | 15.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input` | 1 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_input_newlines` | 9 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_leading` | 9 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_letter_spacing` | 15 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_margins` | 25 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_newline_stripping` | 64 | 19.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_newlines` | 30 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_password` | 5 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_password_copy` | 4 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_paste_empty` | 2 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_place_caret` | 2 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_programmatic_focus` | 12 | 14.9s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_restrict` | 191 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_restrict_paste` | 5 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_scroll` | 54 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_stylesheet` | 325 | 15.5s | [56](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_tab_focus` | 13 | 14.8s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_tab_stops` | 60 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_tag_indent` | 31 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_text_height_leading` | 20 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_underline` | 40 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `edittext_width_height` | 103 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 148 | `empty_movieclip_can_attach_movies` | 11 | 16.2s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 149 | `enumerate` | 64 | 14.3s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 150 | `equals` | 32 | 14.3s |  |
| 151 | `equals2_swf5` | 926 | 16.1s |  |
| 152 | `equals2_swf6` | 926 | 16.1s |  |
| 153 | `equals2_swf7` | 926 | 16.1s |  |
| 154 | `equals_swf4` | 665 | 15.4s |  |
| 155 | `equals_swf4_alt` | 32 | 14.5s |  |
| 156 | `equals_swf5` | 32 | 14.6s |  |
| 157 | `error` | 58 | 14.3s |  |
| 158 | `escape` | 14 | 14.3s |  |
| 159 | `execution_order1` | 5 | 14.5s |  |
| 160 | `execution_order2` | 7 | 14.4s |  |
| 161 | `execution_order3` | 4 | 14.7s |  |
| 162 | `execution_order4` | 12 | 14.7s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 163 | `export_assets` | 3 | 14.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 164 | `extends_chain` | 134 | 14.8s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 165 | `extends_native_type` | 11 | 14.4s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 166 | `external_interface` | 84 | 14.3s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_escapexml` | 26 | 14.2s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_jsquotestring` | 21 | 14.2s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_toas_basic` | 354 | 14.8s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_toxml_array` | 25 | 14.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `external_interface_toxml_basic` | 179 | 14.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 172 | `external_interface_unescapexml` | 40 | 14.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 173 | `focus_keyboard_press` | 60 | 14.4s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focus_mouse` | 45 | 14.4s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 175 | `focus_mouse_focusable` | 8 | 14.7s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_mouse_rollout` | 4 | 14.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 177 | `focus_remove` | 33 | 14.3s |  |
| 178 | `focus_root_movie` | 2 | 14.3s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 179 | `focus_visibility_change` | 45 | 14.3s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 180 | `focusrect_focuslost` | 4 | 14.3s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 181 | `focusrect_mouse_swf8` | 0 | 14.3s |  |
| 182 | `focusrect_mouse_swf9` | 0 | 16.2s |  |
| 183 | `focusrect_property_swf5` | 1237 | 14.7s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 184 | `focusrect_property_swf6` | 1237 | 14.8s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 185 | `focusrect_property_swf7` | 1237 | 14.6s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 186 | `focusrect_swf5` | 6 | 14.6s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 187 | `focusrect_swf6` | 42 | 14.4s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 188 | `form_loader_encoding_1` | 1 | 14.3s |  |
| 189 | `frame_size_translated_negative` | 21 | 14.3s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 190 | `frame_size_translated_positive` | 21 | 14.4s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 191 | `function_as_function` | 35 | 14.3s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 192 | `function_base_clip` | 8 | 14.4s |  |
| 193 | `function_base_clip_readded` | 11 | 14.3s |  |
| 194 | `function_base_clip_removed` | 25 | 14.3s |  |
| 195 | `function_suppress_and_preload` | 28 | 14.5s |  |
| 196 | `funky_function_calls` | 56 | 14.3s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 197 | `get_bytes_total` | 4 | 14.3s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 198 | `get_variable_in_scope` | 29 | 14.4s |  |
| 199 | `getproperty` | 28 | 14.4s |  |
| 200 | `getproperty_swf4` | 28 | 16.5s |  |
| 201 | `getproperty_swf5` | 28 | 14.8s |  |
| 202 | `gettextextent` | 56 | 14.9s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 203 | `global_array` | 3 | 14.8s |  |
| 204 | `global_is_bare` | 7 | 14.7s |  |
| 205 | `global_swf5_6_7_8_9` | 1145 | 15.4s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 206 | `global_swf6_7_8` | 15 | 15.1s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 207 | `globals_swf5` | 304 | 15.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 208 | `globals_swf6` | 304 | 15.0s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 209 | `globals_swf7` | 304 | 15.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 210 | `globals_swf8` | 304 | 15.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 211 | `goto_advance1` | 6 | 14.9s |  |
| 212 | `goto_advance2` | 2 | 14.9s |  |
| 213 | `goto_both_ways1` | 3 | 14.9s |  |
| 214 | `goto_both_ways2` | 3 | 14.8s |  |
| 215 | `goto_execution_order` | 2 | 14.8s |  |
| 216 | `goto_execution_order2` | 2 | 14.9s |  |
| 217 | `goto_frame` | 12 | 14.9s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 218 | `goto_frame2` | 44 | 15.1s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 219 | `goto_frame_number` | 3 | 14.5s |  |
| 220 | `goto_label` | 17 | 14.5s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 221 | `goto_methods` | 40 | 14.5s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 222 | `goto_rewind1` | 1 | 14.4s |  |
| 223 | `goto_rewind2` | 3 | 14.4s |  |
| 224 | `goto_rewind3` | 2 | 14.3s |  |
| 225 | `greater_swf6` | 1175 | 16.3s |  |
| 226 | `greater_swf7` | 1175 | 16.4s |  |
| 227 | `greaterthan_swf5` | 1 | 14.4s |  |
| 228 | `greaterthan_swf8` | 1 | 14.6s |  |
| 229 | `has_own_property` | 32 | 14.3s |  |
| 230 | `hittest_lockroot` | 15 | 14.5s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 231 | `hittest_morph` | 70 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [36](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 232 | `hittest_winding_rule` | 12 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 233 | `infinite_recursion_function` | 4 | 14.3s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 234 | `infinite_recursion_function_in_setter` | 131 | 14.3s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 235 | `infinite_recursion_virtual_property` | 67 | 14.7s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 236 | `init_array_invalid` | 4 | 14.3s |  |
| 237 | `init_object_invalid` | 4 | 16.5s |  |
| 238 | `init_object_order` | 15 | 15.0s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 239 | `instanceof_coercions` | 88 | 15.3s | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 240 | `interface_implements_op` | 47 | 15.4s | [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 241 | `is_finite` | 49 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 242 | `is_finite_swf6` | 49 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 243 | `is_prototype_of` | 89 | 14.9s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 244 | `issue_1086` | 1 | 14.7s |  |
| 245 | `issue_1104` | 2 | 14.9s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 246 | `issue_1671` | 0 | 14.7s |  |
| 247 | `issue_1906` | 4 | 14.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 248 | `issue_2166` | 9 | 14.8s |  |
| 249 | `issue_2870` | 3 | 14.8s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 250 | `issue_3169` | 2 | 14.7s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 251 | `issue_3446` | 1 | 14.7s |  |
| 252 | `issue_3522` | 2 | 14.7s |  |
| 253 | `issue_4377` | 2 | 14.6s |  |
| 254 | `issue_710` | 4 | 14.7s |  |
| 255 | `issue_768` | 3 | 15.3s | [29](ruffle-tests/_investigation/complete/issue_768.md) |
| 256 | `issue_9327` | 2 | 15.1s |  |
| 257 | `issue_9885` | 2 | 15.1s |  |
| 258 | `key_isToggled` | 9 | 15.2s |  |
| 259 | `lessthan` | 41 | 15.4s |  |
| 260 | `lessthan2_swf5` | 1226 | 17.5s |  |
| 261 | `lessthan2_swf6` | 1226 | 17.5s |  |
| 262 | `lessthan2_swf7` | 1226 | 17.4s |  |
| 263 | `lessthan_swf4` | 902 | 16.5s |  |
| 264 | `lessthan_swf4_alt` | 41 | 15.3s |  |
| 265 | `lessthan_swf5` | 41 | 15.3s |  |
| 266 | `loadmovie` | 2 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 267 | `loadmovie_fail` | 2 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 268 | `loadmovie_flashvars` | 4 | 15.1s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 269 | `loadmovie_method` | 2 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 270 | `loadmovie_registerclass` | 30 | 15.4s | [10](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 271 | `loadmovie_replace_root` | 5 | 15.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 272 | `loadmovie_var_persistence` | 8 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 273 | `loadmovienum` | 3 | 15.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 274 | `loadmovienum_cross_version_prototype` | 9 | 15.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 275 | `loadvariables` | 2 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 276 | `loadvariables2` | 8 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 277 | `loadvariablesnum` | 2 | 14.9s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 278 | `local_to_global` | 49 | 14.8s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 279 | `localconnection_properties` | 8 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 280 | `lock_root` | 1 | 14.5s |  |
| 281 | `logical_ops_swf4` | 90 | 14.6s |  |
| 282 | `logical_ops_swf8` | 108 | 14.6s |  |
| 283 | `looping` | 6 | 14.6s |  |
| 284 | `mask_reapply` | 0 | 14.6s |  |
| 285 | `mask_with_drawing` | 0 | 14.7s |  |
| 286 | `math_min_max` | 101 | 14.6s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 287 | `math_swf6` | 530 | 14.9s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 288 | `math_swf7` | 530 | 15.1s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 289 | `math_swf8` | 530 | 15.0s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 290 | `matrix` | 171 | 14.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 291 | `mcl_as_broadcaster` | 12 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mcl_events_swf_version` | 232 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 293 | `mcl_getprogress` | 30 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 294 | `mcl_loadclip` | 149 | 16.1s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 295 | `mcl_loadclip_properties` | 6 | 16.1s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 296 | `mcl_loadclip_replace_root` | 1 | 15.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 297 | `mcl_mislabeled_target` | 6 | 15.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 298 | `mcl_target_gif87a` | 6 | 16.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 299 | `mcl_target_gif89a` | 6 | 15.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 300 | `mcl_target_jpg` | 6 | 15.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 301 | `mcl_target_png` | 6 | 15.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 302 | `mcl_unloadclip` | 5 | 15.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 303 | `mouse_events` | 8 | 15.5s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 304 | `mouse_events_visible_enabled` | 12 | 15.6s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 305 | `mouse_hover_events_while_dragging` | 1 | 15.6s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 306 | `mouse_listeners` | 67 | 15.4s |  |
| 307 | `mouse_pos` | 665 | 15.5s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 308 | `mouse_pos_with_scale_factor` | 260 | 15.4s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 309 | `mouse_wheel_enabled` | 2 | 15.6s |  |
| 310 | `movieclip_begin_gradient_fill` | 0 | 16.1s |  |
| 311 | `movieclip_blend_mode_property` | 35 | 15.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 312 | `movieclip_create_text_field` | 90 | 15.4s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 313 | `movieclip_default_state` | 69 | 16.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_depth_methods` | 98 | 16.1s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 315 | `movieclip_focusenabled` | 99 | 16.1s | [19](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 316 | `movieclip_get_instance_at_depth` | 28 | 15.8s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 317 | `movieclip_getbounds` | 191 | 15.8s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 318 | `movieclip_gettextsnapshot` | 112 | 15.8s | [23](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_hittest` | 92 | 16.0s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_in_removed_button` | 4 | 15.8s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 321 | `movieclip_init_object` | 5 | 15.5s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 322 | `movieclip_invalid_get_bounds_1` | 75 | 16.2s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 323 | `movieclip_invalid_get_bounds_2` | 75 | 16.0s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_invalid_get_bounds_3` | 13 | 15.6s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_invalid_get_bounds_4` | 13 | 16.1s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_invalid_get_bounds_5` | 11 | 15.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_invalid_get_bounds_8` | 11 | 15.5s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_line_gradient_style` | 0 | 15.8s |  |
| 329 | `movieclip_lockroot` | 29 | 15.6s | [34](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_name_from_timeline` | 13 | 14.2s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_prototype_extension` | 5 | 14.3s |  |
| 332 | `movieclip_setmask` | 14 | 14.5s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 333 | `moviecliploader_flashvars` | 4 | 14.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 334 | `mutable_this` | 18 | 14.2s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 335 | `named_shapes` | 14 | 14.3s |  |
| 336 | `nan_scale` | 9 | 14.4s |  |
| 337 | `native_double_construct` | 12 | 14.4s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 338 | `native_objects_swf7` | 84 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 339 | `native_objects_swf8` | 84 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 340 | `native_subclasses` | 191 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 341 | `nested_textfields_in_buttons` | 0 | 14.3s |  |
| 342 | `new_method_wrap` | 4 | 16.1s |  |
| 343 | `new_object_enumerate` | 7 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 344 | `new_object_wrap` | 4 | 15.2s |  |
| 345 | `o` | 3 | 15.6s |  |
| 346 | `object_constructor` | 33 | 15.2s |  |
| 347 | `object_function` | 32 | 14.8s |  |
| 348 | `object_properties` | 31 | 15.0s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 349 | `object_prototypes` | 74 | 14.9s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 350 | `object_resolve` | 38 | 14.8s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 351 | `object_string_coerce_swf5` | 62 | 14.6s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 352 | `object_string_coerce_swf6` | 68 | 14.6s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 353 | `on_construct` | 25 | 14.7s | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 354 | `parse_float` | 74 | 14.6s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 355 | `parse_int` | 64 | 15.0s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 356 | `path_string` | 322 | 14.9s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 357 | `place_and_lookup` | 30 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 358 | `placeobject_occupied_depth` | 6 | 14.7s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 359 | `point` | 175 | 15.1s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 360 | `primitive_instanceof` | 37 | 14.8s |  |
| 361 | `primitive_type_globals` | 557 | 14.9s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 362 | `printjob_props_swf5` | 45 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 363 | `printjob_props_swf6` | 45 | 14.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 364 | `printjob_props_swf7` | 45 | 14.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 365 | `property_invalid_base_clip` | 36 | 14.5s |  |
| 366 | `prototype_delete` | 12 | 14.6s |  |
| 367 | `prototype_enumerate` | 5 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 368 | `prototype_properties` | 17 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 369 | `rectangle` | 745 | 15.2s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 370 | `recursive_prototypes` | 0 | 14.4s |  |
| 371 | `register_and_init_order` | 231 | 14.9s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 372 | `register_class` | 66 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 373 | `register_class_return_value` | 16 | 14.6s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 374 | `register_class_swf6` | 37 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 375 | `register_class_with_sound` | 11 | 14.6s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 376 | `register_globals_across_frames` | 15 | 14.3s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 377 | `register_underflow` | 26 | 14.3s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 378 | `remove_movie_clip` | 29 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 379 | `removed_clip_halts_script` | 15 | 14.9s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 380 | `removed_target_clip_scope` | 35 | 14.8s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 381 | `resolve_different_root` | 2 | 14.5s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 382 | `rewind_depth` | 30 | 14.3s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 383 | `root_button_mode` | 10 | 14.3s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 384 | `root_global_parent` | 6 | 14.2s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 385 | `root_onload` | 1 | 14.1s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 386 | `sandbox_type_local_file` | 1 | 14.1s |  |
| 387 | `sandbox_type_local_network` | 1 | 14.1s |  |
| 388 | `selection` | 454 | 14.3s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 389 | `selection_handlers` | 27 | 14.2s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 390 | `set_interval` | 27 | 14.3s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 391 | `set_variable_scope` | 58 | 14.2s |  |
| 392 | `single_frame` | 1 | 14.1s |  |
| 393 | `slash_syntax` | 14 | 14.2s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 394 | `sound` | 628 | 14.5s | [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 395 | `sound_props_swf5` | 68 | 14.9s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 396 | `sound_props_swf6` | 68 | 14.8s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 397 | `sound_start_load` | 0 | 14.7s |  |
| 398 | `stage_display_state` | 16 | 14.7s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 399 | `stage_object_children` | 83 | 14.6s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 400 | `stage_object_enumerate` | 4 | 14.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 401 | `stage_object_properties` | 241 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 402 | `stage_object_properties_get_var` | 5 | 14.4s |  |
| 403 | `stage_object_properties_swf6` | 231 | 14.9s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 404 | `stage_property_representation` | 586 | 14.5s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 405 | `stage_scale_mode` | 39 | 14.6s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 406 | `strictequals_swf6` | 902 | 16.1s |  |
| 407 | `strictly_equals` | 7 | 14.7s |  |
| 408 | `string_coercion` | 117 | 15.1s | [54](ruffle-tests/_investigation/complete/string_coercion.md) |
| 409 | `string_methods` | 285 | 15.3s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 410 | `string_methods_negative_args` | 240 | 15.4s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 411 | `string_methods_swfv5` | 275 | 16.4s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 412 | `string_ops_swf6` | 95 | 15.7s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 413 | `string_paths_basic` | 4 | 15.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 414 | `string_paths_eval2` | 7 | 15.0s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 415 | `string_paths_hidden` | 54 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 416 | `string_paths_other` | 36 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 417 | `string_paths_unload` | 1 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 418 | `string_paths_variable_alias` | 4 | 14.9s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 419 | `string_paths_variable_scopes` | 5 | 14.9s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 420 | `stylesheet` | 283 | 15.5s |  |
| 421 | `stylesheet_transform` | 750 | 15.7s |  |
| 422 | `super_edge_cases` | 39 | 15.1s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 423 | `swf4_actions_bool` | 96 | 15.1s |  |
| 424 | `swf4_actions_coercion_order` | 158 | 15.4s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 425 | `swf4_bool` | 4 | 14.9s |  |
| 426 | `swf4_function_calls` | 7 | 14.9s |  |
| 427 | `swf5_encoding` | 3 | 14.7s |  |
| 428 | `swf5_global_funcs` | 232 | 14.9s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 429 | `swf5_no_closure` | 19 | 15.0s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 430 | `swf5_to_6_cross_call` | 29 | 15.8s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 431 | `swf6_case_insensitive` | 42 | 15.2s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 432 | `swf6_global_funcs` | 232 | 15.0s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 433 | `swf6_string_as_bool` | 15 | 15.0s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 434 | `swf6_to_5_cross_call` | 29 | 15.1s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 435 | `swf7_case_sensitive` | 44 | 15.2s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 436 | `swf7_global_funcs` | 232 | 15.1s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 437 | `tab_ordering_automatic_basic` | 92 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 438 | `tab_ordering_automatic_order_grid` | 21 | 15.2s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 439 | `tab_ordering_automatic_order_same_position` | 12 | 15.3s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 440 | `tab_ordering_children` | 208 | 15.2s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 441 | `tab_ordering_custom_basic` | 71 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 442 | `tab_ordering_custom_duplicate_index` | 22 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 443 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.3s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 444 | `tab_ordering_custom_m1` | 29 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 445 | `tab_ordering_events` | 150 | 15.3s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 446 | `tab_ordering_events_mouse` | 65 | 15.4s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 447 | `tab_ordering_movieclip_enabled_default` | 462 | 15.5s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 448 | `tab_ordering_properties_tab_index_edge_case` | 4 | 16.0s |  |
| 449 | `tab_ordering_reverse` | 51 | 14.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 450 | `tab_ordering_tabbable` | 47 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 451 | `target_clip_removed` | 5 | 14.9s | [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 452 | `target_clip_swf5` | 2 | 15.0s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 453 | `target_clip_swf6` | 2 | 15.0s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 454 | `target_path` | 14 | 14.7s |  |
| 455 | `tell_target` | 37 | 14.6s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 456 | `tell_target_invalid` | 6 | 14.4s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 457 | `tell_target_invalid_swf6` | 5 | 14.4s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 458 | `text_format` | 1146 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 459 | `text_format_display` | 21 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 460 | `text_format_font_max_length` | 2 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 461 | `text_format_get_text_extent_undefined_width` | 10 | 14.6s |  |
| 462 | `text_format_rounding_swf7` | 840 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `text_format_rounding_swf8` | 840 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 464 | `textfield_background_color` | 11 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 465 | `textfield_border_color` | 11 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 466 | `textfield_cache_as_bitmap` | 1 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `textfield_maxchars` | 3 | 16.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textfield_properties` | 44 | 16.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 469 | `textfield_props_swf5` | 175 | 16.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 470 | `textfield_props_swf6` | 210 | 16.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 471 | `textfield_props_swf7` | 210 | 16.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 472 | `textfield_props_swf8` | 210 | 16.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 473 | `textfield_text` | 7 | 16.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 474 | `textfield_variable` | 81 | 16.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 475 | `textsnapshot_available_text` | 20 | 16.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 476 | `textsnapshot_findtext` | 44 | 16.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 477 | `textsnapshot_gettext` | 55 | 16.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 478 | `textsnapshot_props_swf5` | 56 | 16.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 479 | `textsnapshot_props_swf6` | 56 | 16.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 480 | `textsnapshot_text_order` | 1 | 15.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 481 | `this_scoping` | 52 | 16.0s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 482 | `this_swf5` | 41 | 15.9s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 483 | `this_swf6` | 41 | 15.8s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 484 | `this_swf7` | 41 | 15.8s | [64](ruffle-tests/_investigation/complete/this_swf7.md) |
| 485 | `timeline_function_def` | 7 | 16.0s |  |
| 486 | `timer_run_actions` | 18 | 15.3s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 487 | `trace` | 8 | 15.3s |  |
| 488 | `transform` | 70 | 15.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 489 | `try_catch_finally` | 118 | 15.2s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 490 | `try_finally_simple` | 16 | 15.1s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 491 | `typeof` | 22 | 14.8s |  |
| 492 | `typeof_globals` | 7 | 14.9s |  |
| 493 | `uncaught_exception` | 1 | 14.7s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 494 | `uncaught_exception_bubbled` | 1 | 14.9s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 495 | `undefined_to_string_swf6` | 4 | 14.9s |  |
| 496 | `unescape` | 43 | 15.1s |  |
| 497 | `unload` | 52 | 15.1s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 498 | `unload_clip_event` | 4 | 14.8s | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 499 | `unloadmovie` | 4 | 15.1s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 500 | `unloadmovie_method` | 3 | 15.2s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 501 | `unloadmovienum` | 13 | 15.0s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 502 | `use_hand_cursor` | 8 | 15.2s |  |
| 503 | `variable_args` | 5 | 15.3s |  |
| 504 | `waitforframe` | 7 | 15.2s |  |
| 505 | `waitforframe2` | 16 | 16.4s |  |
| 506 | `watch` | 117 | 14.9s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 507 | `watch_textfield` | 12 | 14.5s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 508 | `watch_virtual_property_proto` | 2 | 14.6s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 509 | `with` | 49 | 14.5s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 510 | `with_return` | 2 | 14.3s |  |
| 511 | `with_variable_scopes` | 43 | 14.5s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 512 | `xml` | 15 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_append_child` | 28 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_append_child_with_parent` | 20 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_attributes_read` | 4 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_cdata` | 11 | 14.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_child_nodes_edge_cases` | 4 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_clone_expandos` | 19 | 14.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_first_last_child` | 8 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_has_child_nodes` | 3 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_idmap` | 21 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_ignore_comments` | 21 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_ignore_white` | 34 | 15.1s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xml_insert_before` | 20 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 525 | `xml_inspect_createmethods` | 15 | 15.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 526 | `xml_inspect_doctype` | 7 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 527 | `xml_inspect_parsexml` | 62 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 528 | `xml_inspect_xmldecl` | 7 | 14.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_namespaces` | 203 | 14.4s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_parent_and_child` | 5 | 14.5s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_remove_node` | 22 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_reparenting` | 14 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_siblings` | 10 | 14.5s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_to_string` | 13 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 535 | `xml_to_string_comment` | 1 | 15.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 536 | `xml_unescaping` | 23 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 537 | `xmlnode_proto` | 1 | 14.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**22 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [12](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 13 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 16 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 18 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 19 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 20 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 21 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 22 | `issue_2030` | 50.0% | 2 | 4 | 2 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 16.8s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 31.2s | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 45.9s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**78 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [12](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 13 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 16 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 18 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 19 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 20 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 21 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 22 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 23 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 24 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 25 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) |
| 26 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 27 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 28 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 29 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 30 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 31 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 32 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 33 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 34 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 35 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 36 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 37 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 38 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 39 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 40 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 41 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 42 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 43 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 44 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 45 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 46 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 47 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 48 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 49 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 50 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 51 | `global_instance_decls` | 1.6% | 12/758 | 492 | 758 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 52 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 53 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 54 | `global_proto_decls` | 0.5% | 24/4497 | 887 | 4497 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 55 | `global_proto_decls_delete` | 0.5% | 22/4158 | 468 | 4158 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 56 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 57 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 58 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 59 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 60 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 61 | `geturl` | 0.0% | 0/7 | 0 | 7 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 62 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 63 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 64 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 65 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 66 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 67 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 68 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 69 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 70 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 71 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 72 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 73 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 74 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [38](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 76 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 77 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 78 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
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
| 18 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 19 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 20 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 21 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 22 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 23 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 24 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 27 | 4 |
| 25 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 26 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) | 29 | 0 | 29 |
| 27 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 28 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 0 | 1 |
| 29 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 30 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 31 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 40 | 8 |
| 32 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 33 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 34 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 35 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 36 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 37 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 38 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 47 | 11 |
| 39 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 40 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
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
| 60 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 16 | 3 |
| 61 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 65 | 5 |
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
