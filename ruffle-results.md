# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-11 06:19 UTC

**Git SHA**: `e946183199`

**Run Duration**: 151m 60s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 618 |
| Passing | **505** (81.7%) |
| Failing | 113 |
| Total expected lines | 91484 |
| Matching lines | 72279 (79.0%) |
| Mismatched lines | 19205 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 110 | 97.3% |
| Runtime Segfault | 2 | 1.8% |
| Timeout | 1 | 0.9% |

## Passing Tests

**505 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 17.1s |  |
| 2 | `action_to_integer` | 28 | 14.1s |  |
| 3 | `add` | 28 | 14.1s |  |
| 4 | `add2` | 354 | 14.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 14.2s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 14.2s |  |
| 7 | `add_swf5` | 28 | 14.1s |  |
| 8 | `arguments` | 127 | 14.1s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 14.1s |  |
| 11 | `array_constructor` | 30 | 14.1s |  |
| 12 | `array_enumerate` | 4 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.1s |  |
| 14 | `array_properties` | 36 | 14.2s |  |
| 15 | `array_prototyping` | 12 | 14.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 14.2s |  |
| 17 | `array_sort` | 161 | 14.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 14.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 14.3s |  |
| 20 | `array_trivial` | 209 | 14.2s |  |
| 21 | `as1_constructor_v6` | 35 | 14.1s |  |
| 22 | `as1_constructor_v7` | 35 | 14.8s |  |
| 23 | `as2_oop` | 13 | 14.4s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 14.2s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 14.5s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 14.3s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 14.0s |  |
| 29 | `as_broadcaster_undef` | 89 | 14.1s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 14.5s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 14.2s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 14.1s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 14.0s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 14.2s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 14.2s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 14.0s |  |
| 37 | `as_transformed_flag` | 20 | 14.0s |  |
| 38 | `asnative` | 34 | 14.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 14.2s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 17.4s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 14.2s |  |
| 44 | `bitand` | 1058 | 17.1s |  |
| 45 | `bitmap_data_colortransform` | 0 | 14.6s |  |
| 46 | `bitmap_data_fillrect` | 0 | 14.7s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 14.7s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 14.4s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 15.2s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 15.1s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.0s |  |
| 52 | `bitor` | 1058 | 17.7s |  |
| 53 | `biturshift` | 14 | 14.5s |  |
| 54 | `biturshift_swf8` | 14 | 19.1s |  |
| 55 | `bitxor` | 1058 | 16.6s |  |
| 56 | `boxed_primitives` | 24 | 14.1s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 14.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 14.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 13.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 14.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 14.2s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 14.0s |  |
| 71 | `capabilities_resolution` | 8 | 14.0s |  |
| 72 | `catch_references_registers` | 2 | 14.0s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 14.2s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 14.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 14.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 14.2s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `coerce_to_primitive_resolve` | 17 | 14.4s | [40](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 79 | `color` | 57 | 15.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `color_transform` | 48 | 14.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 81 | `conflicting_instance_names` | 23 | 14.3s |  |
| 82 | `constructor_function` | 2 | 14.3s |  |
| 83 | `context_menu` | 39 | 14.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `context_menu_item` | 41 | 14.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `create_empty_movie_clip` | 3 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `custom_clip_methods` | 4 | 14.3s | [10](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `default_names` | 52 | 14.2s | [12](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `define_function2` | 8 | 14.0s |  |
| 89 | `define_function2_preload` | 13 | 14.2s |  |
| 90 | `define_function2_preload_order` | 4 | 16.2s |  |
| 91 | `define_function_case_sensitive` | 2 | 14.2s |  |
| 92 | `define_local` | 27 | 14.2s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 93 | `define_local_with_paths` | 54 | 14.2s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `delete` | 3 | 14.3s |  |
| 95 | `device_font_spacing` | 91 | 14.4s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 96 | `display_object_properties` | 2 | 14.2s |  |
| 97 | `divide_swf4` | 107 | 14.3s |  |
| 98 | `do_init_action` | 3 | 14.2s |  |
| 99 | `do_init_action_child` | 12 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 100 | `drag_drop` | 10 | 14.4s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 101 | `drag_over_from_outside` | 1 | 14.4s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_without_startdrag` | 1 | 14.4s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `duplicate_movie_clip` | 20 | 14.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `duplicate_movie_clip_drawing` | 2 | 14.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `edittext_align` | 60 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_align_trailing_spaces_swf7` | 576 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf8` | 576 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_antialiastype` | 296 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_autosize` | 71 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize_setter` | 20 | 16.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_default_format` | 221 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format_font_style` | 335 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_focus_selection` | 2 | 14.2s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_font_size` | 45 | 14.5s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_hscroll` | 27 | 14.3s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_align_swf7` | 52 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf8` | 52 | 14.5s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_color` | 114 | 14.5s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_condensewhite_swf7` | 311 | 14.6s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf8` | 311 | 14.6s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_entity` | 4 | 14.6s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_roundtrip` | 17 | 14.6s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_swf7` | 5377 | 15.8s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf8` | 5377 | 15.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_input` | 1 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input_newlines` | 9 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_leading` | 9 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_letter_spacing` | 15 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_margins` | 25 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_newline_stripping` | 64 | 18.6s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_newlines` | 30 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_password` | 5 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_password_copy` | 4 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_paste_empty` | 2 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_place_caret` | 2 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_programmatic_focus` | 12 | 14.0s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_restrict` | 191 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_restrict_paste` | 5 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_scroll` | 54 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_stylesheet` | 325 | 14.7s | [51](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_tab_focus` | 13 | 14.0s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_tag_indent` | 31 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_text_height_leading` | 20 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_underline` | 40 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_width_height` | 103 | 14.0s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `empty_movieclip_can_attach_movies` | 11 | 16.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 147 | `enumerate` | 64 | 14.2s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 148 | `equals` | 32 | 14.2s |  |
| 149 | `equals2_swf5` | 926 | 15.7s |  |
| 150 | `equals2_swf6` | 926 | 15.6s |  |
| 151 | `equals2_swf7` | 926 | 15.6s |  |
| 152 | `equals_swf4` | 665 | 14.6s |  |
| 153 | `equals_swf4_alt` | 32 | 14.0s |  |
| 154 | `equals_swf5` | 32 | 13.9s |  |
| 155 | `error` | 58 | 13.9s |  |
| 156 | `escape` | 14 | 13.9s |  |
| 157 | `execution_order1` | 5 | 14.0s |  |
| 158 | `execution_order2` | 7 | 14.1s |  |
| 159 | `execution_order3` | 4 | 14.0s |  |
| 160 | `execution_order4` | 12 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 161 | `export_assets` | 3 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 162 | `extends_chain` | 134 | 14.4s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 163 | `extends_native_type` | 11 | 14.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 164 | `external_interface` | 84 | 14.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_escapexml` | 26 | 14.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_jsquotestring` | 21 | 14.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_toas_basic` | 354 | 15.8s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_toxml_array` | 25 | 14.0s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_toxml_basic` | 179 | 14.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_unescapexml` | 40 | 14.0s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `focus_keyboard_press` | 60 | 14.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 172 | `focus_mouse` | 45 | 14.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 173 | `focus_mouse_rollout` | 4 | 14.7s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focus_remove` | 33 | 14.8s |  |
| 175 | `focus_root_movie` | 2 | 14.4s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focusrect_focuslost` | 4 | 14.7s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 177 | `focusrect_mouse_swf8` | 0 | 14.4s |  |
| 178 | `focusrect_mouse_swf9` | 0 | 15.3s |  |
| 179 | `focusrect_swf5` | 6 | 14.8s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 180 | `focusrect_swf6` | 42 | 14.7s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 181 | `form_loader_encoding_1` | 1 | 15.0s |  |
| 182 | `frame_size_translated_negative` | 21 | 14.9s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 183 | `frame_size_translated_positive` | 21 | 15.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 184 | `function_as_function` | 35 | 14.5s | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 185 | `function_base_clip` | 8 | 14.5s |  |
| 186 | `function_base_clip_readded` | 11 | 14.5s |  |
| 187 | `function_base_clip_removed` | 25 | 14.4s |  |
| 188 | `function_suppress_and_preload` | 28 | 14.4s |  |
| 189 | `funky_function_calls` | 56 | 14.3s | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 190 | `get_bytes_total` | 4 | 14.3s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 191 | `get_variable_in_scope` | 29 | 14.3s |  |
| 192 | `getproperty` | 28 | 14.7s |  |
| 193 | `getproperty_swf4` | 28 | 14.9s |  |
| 194 | `getproperty_swf5` | 28 | 14.5s |  |
| 195 | `gettextextent` | 56 | 14.4s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 196 | `global_array` | 3 | 14.4s |  |
| 197 | `global_is_bare` | 7 | 14.7s |  |
| 198 | `global_swf5_6_7_8_9` | 1145 | 15.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 199 | `global_swf6_7_8` | 15 | 15.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 200 | `globals_swf5` | 304 | 14.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 201 | `globals_swf6` | 304 | 14.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 202 | `globals_swf7` | 304 | 14.9s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 203 | `globals_swf8` | 304 | 14.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 204 | `goto_advance1` | 6 | 14.3s |  |
| 205 | `goto_advance2` | 2 | 14.7s |  |
| 206 | `goto_both_ways1` | 3 | 14.6s |  |
| 207 | `goto_both_ways2` | 3 | 14.7s |  |
| 208 | `goto_execution_order` | 2 | 14.6s |  |
| 209 | `goto_execution_order2` | 2 | 14.5s |  |
| 210 | `goto_frame` | 12 | 16.0s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 211 | `goto_frame2` | 44 | 15.1s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 212 | `goto_frame_number` | 3 | 14.7s |  |
| 213 | `goto_label` | 17 | 14.7s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 214 | `goto_methods` | 40 | 14.8s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 215 | `goto_rewind1` | 1 | 14.2s |  |
| 216 | `goto_rewind2` | 3 | 14.0s |  |
| 217 | `goto_rewind3` | 2 | 14.1s |  |
| 218 | `greater_swf6` | 1175 | 16.4s |  |
| 219 | `greater_swf7` | 1175 | 16.5s |  |
| 220 | `greaterthan_swf5` | 1 | 14.0s |  |
| 221 | `greaterthan_swf8` | 1 | 14.0s |  |
| 222 | `has_own_property` | 32 | 14.1s |  |
| 223 | `hittest_lockroot` | 15 | 14.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 224 | `hittest_morph` | 70 | 14.0s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 225 | `hittest_winding_rule` | 12 | 14.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 226 | `infinite_recursion_function` | 4 | 14.0s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 227 | `infinite_recursion_function_in_setter` | 131 | 14.0s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 228 | `infinite_recursion_virtual_property` | 67 | 13.9s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 229 | `init_array_invalid` | 4 | 13.8s |  |
| 230 | `init_object_invalid` | 4 | 15.2s |  |
| 231 | `init_object_order` | 15 | 14.9s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 232 | `instanceof_coercions` | 88 | 14.8s | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 233 | `interface_implements_op` | 47 | 15.3s | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 234 | `is_finite` | 49 | 14.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 235 | `is_finite_swf6` | 49 | 14.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 236 | `is_prototype_of` | 89 | 14.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 237 | `issue_1086` | 1 | 14.8s |  |
| 238 | `issue_1104` | 2 | 14.4s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 239 | `issue_1671` | 0 | 14.8s |  |
| 240 | `issue_1906` | 4 | 14.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 241 | `issue_2166` | 9 | 14.8s |  |
| 242 | `issue_3169` | 2 | 14.9s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 243 | `issue_3446` | 1 | 14.6s |  |
| 244 | `issue_3522` | 2 | 14.8s |  |
| 245 | `issue_4377` | 2 | 14.7s |  |
| 246 | `issue_710` | 4 | 14.6s |  |
| 247 | `issue_768` | 3 | 14.3s | [25](ruffle-tests/_investigation/complete/issue_768.md) |
| 248 | `issue_9327` | 2 | 14.2s |  |
| 249 | `issue_9885` | 2 | 14.2s |  |
| 250 | `key_isToggled` | 9 | 14.2s |  |
| 251 | `lessthan` | 41 | 14.2s |  |
| 252 | `lessthan2_swf5` | 1226 | 16.3s |  |
| 253 | `lessthan2_swf6` | 1226 | 16.3s |  |
| 254 | `lessthan2_swf7` | 1226 | 16.3s |  |
| 255 | `lessthan_swf4` | 902 | 15.5s |  |
| 256 | `lessthan_swf4_alt` | 41 | 14.2s |  |
| 257 | `lessthan_swf5` | 41 | 14.2s |  |
| 258 | `loadmovie` | 2 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 259 | `loadmovie_fail` | 2 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 260 | `loadmovie_flashvars` | 4 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 261 | `loadmovie_method` | 2 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 262 | `loadmovie_replace_root` | 5 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 263 | `loadmovie_var_persistence` | 8 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 264 | `loadmovienum` | 3 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 265 | `loadmovienum_cross_version_prototype` | 9 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 266 | `loadvariables` | 2 | 15.5s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 267 | `loadvariables2` | 8 | 14.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 268 | `loadvariablesnum` | 2 | 14.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 269 | `local_to_global` | 49 | 14.1s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 270 | `localconnection_properties` | 8 | 14.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 271 | `lock_root` | 1 | 14.1s |  |
| 272 | `logical_ops_swf4` | 90 | 14.1s |  |
| 273 | `logical_ops_swf8` | 108 | 14.3s |  |
| 274 | `looping` | 6 | 14.1s |  |
| 275 | `mask_reapply` | 0 | 14.1s |  |
| 276 | `mask_with_drawing` | 0 | 14.2s |  |
| 277 | `math_min_max` | 101 | 14.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 278 | `math_swf6` | 530 | 14.5s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 279 | `math_swf7` | 530 | 14.6s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 280 | `math_swf8` | 530 | 14.6s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 281 | `matrix` | 171 | 14.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 282 | `mcl_as_broadcaster` | 12 | 14.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mcl_events_swf_version` | 232 | 14.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 284 | `mcl_getprogress` | 30 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 285 | `mcl_loadclip_properties` | 6 | 15.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 286 | `mcl_loadclip_replace_root` | 1 | 14.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 287 | `mouse_events` | 8 | 15.0s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 288 | `mouse_events_visible_enabled` | 12 | 15.1s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 289 | `mouse_hover_events_while_dragging` | 1 | 14.7s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 290 | `mouse_listeners` | 67 | 14.3s |  |
| 291 | `mouse_pos` | 665 | 14.7s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 292 | `mouse_pos_with_scale_factor` | 260 | 14.8s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 293 | `mouse_wheel_enabled` | 2 | 14.4s |  |
| 294 | `movieclip_begin_gradient_fill` | 0 | 14.9s |  |
| 295 | `movieclip_blend_mode_property` | 35 | 14.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 296 | `movieclip_create_text_field` | 90 | 14.6s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 297 | `movieclip_default_state` | 69 | 18.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 298 | `movieclip_depth_methods` | 98 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 299 | `movieclip_focusenabled` | 99 | 14.1s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 300 | `movieclip_get_instance_at_depth` | 28 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 301 | `movieclip_getbounds` | 191 | 14.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 302 | `movieclip_gettextsnapshot` | 112 | 14.3s | [21](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 303 | `movieclip_hittest` | 92 | 14.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 304 | `movieclip_in_removed_button` | 4 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 305 | `movieclip_init_object` | 5 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 306 | `movieclip_line_gradient_style` | 0 | 14.6s |  |
| 307 | `movieclip_lockroot` | 29 | 14.4s | [29](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 308 | `movieclip_name_from_timeline` | 13 | 14.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 309 | `movieclip_prototype_extension` | 5 | 14.9s |  |
| 310 | `movieclip_setmask` | 14 | 14.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 311 | `moviecliploader_flashvars` | 4 | 14.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mutable_this` | 18 | 14.8s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 313 | `named_shapes` | 14 | 14.7s |  |
| 314 | `nan_scale` | 9 | 14.7s |  |
| 315 | `native_double_construct` | 12 | 14.6s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 316 | `native_objects_swf7` | 84 | 14.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 317 | `native_objects_swf8` | 84 | 15.0s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 318 | `native_subclasses` | 191 | 14.8s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 319 | `nested_textfields_in_buttons` | 0 | 14.4s |  |
| 320 | `new_method_wrap` | 4 | 14.6s |  |
| 321 | `new_object_enumerate` | 7 | 14.2s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 322 | `new_object_wrap` | 4 | 14.2s |  |
| 323 | `o` | 3 | 14.1s |  |
| 324 | `object_constructor` | 33 | 14.2s |  |
| 325 | `object_function` | 32 | 14.2s |  |
| 326 | `object_properties` | 31 | 14.4s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 327 | `object_prototypes` | 74 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 328 | `object_resolve` | 38 | 14.3s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 329 | `object_string_coerce_swf5` | 62 | 14.3s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 330 | `object_string_coerce_swf6` | 68 | 14.3s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 331 | `on_construct` | 25 | 14.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 332 | `parse_float` | 74 | 14.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 333 | `parse_int` | 64 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 334 | `path_string` | 322 | 14.4s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 335 | `place_and_lookup` | 30 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 336 | `placeobject_occupied_depth` | 6 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 337 | `point` | 175 | 14.5s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 338 | `primitive_instanceof` | 37 | 14.1s |  |
| 339 | `primitive_type_globals` | 557 | 14.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 340 | `printjob_props_swf5` | 45 | 14.7s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 341 | `printjob_props_swf6` | 45 | 14.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 342 | `printjob_props_swf7` | 45 | 14.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 343 | `property_invalid_base_clip` | 36 | 14.7s |  |
| 344 | `prototype_delete` | 12 | 14.6s |  |
| 345 | `prototype_enumerate` | 5 | 14.5s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 346 | `prototype_properties` | 17 | 14.5s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 347 | `rectangle` | 745 | 15.4s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 348 | `recursive_prototypes` | 0 | 14.4s |  |
| 349 | `register_class` | 66 | 14.5s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 350 | `register_class_return_value` | 16 | 14.3s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 351 | `register_class_swf6` | 37 | 14.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 352 | `register_class_with_sound` | 11 | 14.5s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 353 | `register_globals_across_frames` | 15 | 14.3s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 354 | `register_underflow` | 26 | 14.2s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 355 | `remove_movie_clip` | 29 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 356 | `removed_clip_halts_script` | 15 | 14.6s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 357 | `removed_target_clip_scope` | 35 | 14.4s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 358 | `resolve_different_root` | 2 | 14.9s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 359 | `rewind_depth` | 30 | 14.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 360 | `root_global_parent` | 6 | 14.3s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 361 | `root_onload` | 1 | 14.2s | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 362 | `sandbox_type_local_file` | 1 | 14.2s |  |
| 363 | `sandbox_type_local_network` | 1 | 14.1s |  |
| 364 | `selection` | 454 | 14.4s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 365 | `set_interval` | 27 | 14.4s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 366 | `set_variable_scope` | 58 | 14.2s |  |
| 367 | `single_frame` | 1 | 14.2s |  |
| 368 | `slash_syntax` | 14 | 14.3s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 369 | `sound` | 628 | 14.8s | [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 370 | `sound_props_swf5` | 68 | 15.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 371 | `sound_props_swf6` | 68 | 14.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 372 | `sound_start_load` | 0 | 14.7s |  |
| 373 | `stage_display_state` | 16 | 14.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 374 | `stage_object_children` | 83 | 14.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 375 | `stage_object_enumerate` | 4 | 14.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 376 | `stage_object_properties` | 241 | 15.2s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 377 | `stage_object_properties_get_var` | 5 | 14.7s |  |
| 378 | `stage_object_properties_swf6` | 231 | 15.3s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 379 | `stage_property_representation` | 586 | 15.0s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 380 | `stage_scale_mode` | 39 | 15.0s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 381 | `strictequals_swf6` | 902 | 16.5s |  |
| 382 | `strictly_equals` | 7 | 15.0s |  |
| 383 | `string_coercion` | 117 | 15.2s | [49](ruffle-tests/_investigation/complete/string_coercion.md) |
| 384 | `string_methods` | 285 | 15.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 385 | `string_methods_negative_args` | 240 | 15.1s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 386 | `string_methods_swfv5` | 275 | 15.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 387 | `string_ops_swf6` | 95 | 15.0s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 388 | `string_paths_basic` | 4 | 14.7s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 389 | `string_paths_eval2` | 7 | 14.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 390 | `string_paths_hidden` | 54 | 14.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 391 | `string_paths_other` | 36 | 14.6s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 392 | `string_paths_unload` | 1 | 14.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 393 | `string_paths_variable_alias` | 4 | 14.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 394 | `string_paths_variable_scopes` | 5 | 14.6s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 395 | `stylesheet` | 283 | 15.2s |  |
| 396 | `stylesheet_transform` | 750 | 15.1s |  |
| 397 | `super_edge_cases` | 39 | 14.5s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 398 | `swf4_actions_bool` | 96 | 14.3s |  |
| 399 | `swf4_actions_coercion_order` | 158 | 14.4s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 400 | `swf4_bool` | 4 | 14.3s |  |
| 401 | `swf4_function_calls` | 7 | 14.4s |  |
| 402 | `swf5_encoding` | 3 | 14.3s |  |
| 403 | `swf5_global_funcs` | 232 | 14.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 404 | `swf5_no_closure` | 19 | 14.5s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 405 | `swf6_case_insensitive` | 42 | 14.8s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 406 | `swf6_global_funcs` | 232 | 14.9s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 407 | `swf6_string_as_bool` | 15 | 15.0s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 408 | `swf7_case_sensitive` | 44 | 15.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 409 | `swf7_global_funcs` | 232 | 15.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 410 | `tab_ordering_automatic_basic` | 92 | 15.1s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 411 | `tab_ordering_automatic_order_grid` | 21 | 14.9s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 412 | `tab_ordering_automatic_order_same_position` | 12 | 15.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 413 | `tab_ordering_children` | 208 | 15.4s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 414 | `tab_ordering_custom_basic` | 71 | 15.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 415 | `tab_ordering_custom_duplicate_index` | 22 | 15.1s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 416 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.4s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 417 | `tab_ordering_custom_m1` | 29 | 15.1s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 418 | `tab_ordering_events` | 150 | 15.8s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 419 | `tab_ordering_events_mouse` | 65 | 15.5s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 420 | `tab_ordering_movieclip_enabled_default` | 462 | 15.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 421 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.6s |  |
| 422 | `tab_ordering_reverse` | 51 | 14.3s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 423 | `tab_ordering_tabbable` | 47 | 14.4s | [53](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 424 | `target_clip_removed` | 5 | 14.3s | [44](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 425 | `target_clip_swf5` | 2 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 426 | `target_clip_swf6` | 2 | 14.1s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 427 | `target_path` | 14 | 14.2s |  |
| 428 | `tell_target` | 37 | 14.3s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 429 | `tell_target_invalid` | 6 | 14.4s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 430 | `tell_target_invalid_swf6` | 5 | 14.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 431 | `text_format` | 1146 | 14.5s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 432 | `text_format_display` | 21 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 433 | `text_format_font_max_length` | 2 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 434 | `text_format_get_text_extent_undefined_width` | 10 | 14.1s |  |
| 435 | `text_format_rounding_swf7` | 840 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 436 | `text_format_rounding_swf8` | 840 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 437 | `textfield_background_color` | 11 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 438 | `textfield_border_color` | 11 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 439 | `textfield_cache_as_bitmap` | 1 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 440 | `textfield_maxchars` | 3 | 14.4s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 441 | `textfield_properties` | 44 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 442 | `textfield_props_swf5` | 175 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 443 | `textfield_props_swf6` | 210 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 444 | `textfield_props_swf7` | 210 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 445 | `textfield_props_swf8` | 210 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 446 | `textfield_text` | 7 | 13.9s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 447 | `textfield_variable` | 81 | 14.2s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 448 | `textsnapshot_props_swf5` | 56 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 449 | `textsnapshot_props_swf6` | 56 | 14.1s | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 450 | `this_scoping` | 52 | 14.1s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 451 | `this_swf5` | 41 | 14.0s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 452 | `this_swf6` | 41 | 13.9s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 453 | `this_swf7` | 41 | 14.0s | [58](ruffle-tests/_investigation/complete/this_swf7.md) |
| 454 | `timeline_function_def` | 7 | 14.1s |  |
| 455 | `trace` | 8 | 14.2s |  |
| 456 | `transform` | 70 | 14.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 457 | `try_catch_finally` | 118 | 14.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 458 | `try_finally_simple` | 16 | 14.1s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 459 | `typeof` | 22 | 14.2s |  |
| 460 | `typeof_globals` | 7 | 14.1s |  |
| 461 | `uncaught_exception` | 1 | 14.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 462 | `uncaught_exception_bubbled` | 1 | 14.1s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 463 | `undefined_to_string_swf6` | 4 | 14.2s |  |
| 464 | `unescape` | 43 | 14.3s |  |
| 465 | `unload` | 52 | 14.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 466 | `unload_clip_event` | 4 | 14.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 467 | `unloadmovie` | 4 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 468 | `unloadmovie_method` | 3 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 469 | `unloadmovienum` | 13 | 14.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 470 | `use_hand_cursor` | 8 | 14.1s |  |
| 471 | `variable_args` | 5 | 14.3s |  |
| 472 | `waitforframe` | 7 | 14.2s |  |
| 473 | `waitforframe2` | 16 | 15.1s |  |
| 474 | `watch` | 117 | 14.9s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 475 | `watch_textfield` | 12 | 14.6s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 476 | `watch_virtual_property_proto` | 2 | 14.5s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 477 | `with` | 49 | 14.4s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 478 | `with_return` | 2 | 14.3s |  |
| 479 | `with_variable_scopes` | 43 | 14.3s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 480 | `xml` | 15 | 14.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 481 | `xml_append_child` | 28 | 14.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 482 | `xml_append_child_with_parent` | 20 | 14.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 483 | `xml_attributes_read` | 4 | 14.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 484 | `xml_cdata` | 11 | 14.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 485 | `xml_child_nodes_edge_cases` | 4 | 14.6s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 486 | `xml_clone_expandos` | 19 | 14.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 487 | `xml_first_last_child` | 8 | 14.6s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 488 | `xml_has_child_nodes` | 3 | 14.7s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 489 | `xml_idmap` | 21 | 14.7s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 490 | `xml_ignore_comments` | 21 | 14.6s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 491 | `xml_ignore_white` | 34 | 14.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 492 | `xml_insert_before` | 20 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 493 | `xml_inspect_createmethods` | 15 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 494 | `xml_inspect_doctype` | 7 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 495 | `xml_inspect_parsexml` | 62 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 496 | `xml_inspect_xmldecl` | 7 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 497 | `xml_namespaces` | 203 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 498 | `xml_parent_and_child` | 5 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 499 | `xml_remove_node` | 22 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 500 | `xml_reparenting` | 14 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 501 | `xml_siblings` | 10 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 502 | `xml_to_string` | 13 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 503 | `xml_to_string_comment` | 1 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 504 | `xml_unescaping` | 23 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 505 | `xmlnode_proto` | 1 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**37 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `movieclip_invalid_get_bounds_2` | 92.0% | 69 | 75 | 6 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `loadmovie_registerclass` | 80.0% | 24 | 30 | 6 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `movieclip_invalid_get_bounds_6` | 80.0% | 8 | 10 | 2 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `movieclip_invalid_get_bounds_7` | 80.0% | 8 | 10 | 2 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `swf5_to_6_cross_call` | 79.3% | 23 | 29 | 6 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 14 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 15 | `movieclip_invalid_get_bounds_3` | 76.9% | 10 | 13 | 3 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `movieclip_invalid_get_bounds_4` | 76.9% | 10 | 13 | 3 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 19 | `movieclip_invalid_get_bounds_5` | 72.7% | 8 | 11 | 3 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `movieclip_invalid_get_bounds_8` | 63.6% | 7 | 11 | 4 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `movieclip_invalid_get_bounds_1` | 61.3% | 46 | 75 | 29 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `cross_movie_root` | 60.0% | 6 | 10 | 4 |  |
| 26 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 27 | `textsnapshot_findtext` | 59.1% | 26 | 44 | 18 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 28 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 29 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 30 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 31 | `swf6_to_5_cross_call` | 55.2% | 16 | 29 | 13 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 32 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 33 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 34 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 35 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 36 | `issue_2030` | 50.0% | 2 | 4 | 2 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 37 | `textsnapshot_available_text` | 50.0% | 10 | 20 | 10 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 18.1s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 32.0s |  |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 44.0s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**110 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 7 | `movieclip_invalid_get_bounds_2` | 92.0% | 69/75 | 75 | 75 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `loadmovie_registerclass` | 80.0% | 24/30 | 27 | 30 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 11 | `movieclip_invalid_get_bounds_6` | 80.0% | 8/10 | 10 | 10 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 12 | `movieclip_invalid_get_bounds_7` | 80.0% | 8/10 | 10 | 10 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `swf5_to_6_cross_call` | 79.3% | 23/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 14 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 15 | `movieclip_invalid_get_bounds_3` | 76.9% | 10/13 | 13 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 16 | `movieclip_invalid_get_bounds_4` | 76.9% | 10/13 | 13 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 19 | `movieclip_invalid_get_bounds_5` | 72.7% | 8/11 | 11 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `movieclip_invalid_get_bounds_8` | 63.6% | 7/11 | 11 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `movieclip_invalid_get_bounds_1` | 61.3% | 46/75 | 75 | 75 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `cross_movie_root` | 60.0% | 6/10 | 10 | 10 |  |
| 26 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 27 | `textsnapshot_findtext` | 59.1% | 26/44 | 44 | 44 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 28 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 29 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 30 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 31 | `swf6_to_5_cross_call` | 55.2% | 16/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 32 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 33 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 34 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 35 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 36 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 37 | `textsnapshot_available_text` | 50.0% | 10/20 | 20 | 20 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 38 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 39 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 40 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 41 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 42 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 43 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 44 | `movieclip_state_values` | 34.2% | 39/114 | 55 | 114 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 45 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 46 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 47 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 48 | `mcl_unloadclip` | 33.3% | 2/6 | 6 | 5 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 49 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 50 | `mcl_loadclip` | 32.3% | 61/189 | 189 | 149 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 51 | `mcl_mislabeled_target` | 28.6% | 2/7 | 7 | 6 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 52 | `mcl_target_gif87a` | 28.6% | 2/7 | 7 | 6 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 53 | `mcl_target_gif89a` | 28.6% | 2/7 | 7 | 6 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 54 | `mcl_target_jpg` | 28.6% | 2/7 | 7 | 6 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 55 | `mcl_target_png` | 28.6% | 2/7 | 7 | 6 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 56 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 57 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 58 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 59 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 60 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 61 | `register_and_init_order` | 15.6% | 36/231 | 154 | 231 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 62 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 63 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 64 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 65 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 66 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 67 | `root_button_mode` | 10.0% | 1/10 | 4 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 68 | `textsnapshot_gettext` | 9.1% | 5/55 | 55 | 55 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 69 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 70 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 71 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 72 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 73 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 74 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 75 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 76 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 77 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 78 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 79 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 80 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 81 | `global_instance_decls` | 1.6% | 12/758 | 482 | 758 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 82 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 83 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 84 | `global_proto_decls` | 0.2% | 11/4497 | 692 | 4497 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 85 | `global_proto_decls_delete` | 0.0% | 1/4158 | 310 | 4158 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 86 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [19](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 87 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 88 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 89 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 90 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 91 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 92 | `geturl` | 0.0% | 0/7 | 0 | 7 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 93 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 94 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 95 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 96 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 97 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 98 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 99 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 100 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 101 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 102 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 103 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [62](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 104 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 105 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [55](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 106 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 107 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 108 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 109 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 110 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 11 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 12 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 13 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 14 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 15 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 16 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 17 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 6 | 1 |
| 18 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 19 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 20 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 21 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 22 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 27 | 4 |
| 23 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 6 | 11 |
| 24 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 25 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 26 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 48 | 25 | 23 |
| 27 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 28 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 29 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 30 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 31 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 32 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 33 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 40 | 18 |
| 34 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 7 | 9 |
| 35 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 36 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 37 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 38 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 39 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 40 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 41 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 42 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 14 | 1 |
| 43 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 44 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 45 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 3 | 1 |
| 46 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 47 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 48 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 49 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 50 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 51 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 52 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 53 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 54 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 16 | 3 |
| 55 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 60 | 10 |
| 56 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 0 | 4 |
| 57 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 58 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 59 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 60 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 61 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 62 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 8 | 8 |
| 63 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 64 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 65 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 195 | 158 | 37 |
