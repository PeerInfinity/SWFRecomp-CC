# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-07 02:59 UTC

**Git SHA**: `1e2c989065`

**Run Duration**: 143m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **487** (78.7%) |
| Failing | 132 |
| Total expected lines | 91482 |
| Matching lines | 71609 (78.3%) |
| Mismatched lines | 19873 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 124 | 93.9% |
| Runtime Error | 4 | 3.0% |
| Runtime Segfault | 2 | 1.5% |
| Compile Fail | 1 | 0.8% |
| Timeout | 1 | 0.8% |

## Passing Tests

**487 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 13.2s |  |
| 2 | `action_to_integer` | 28 | 13.1s |  |
| 3 | `add` | 28 | 13.1s |  |
| 4 | `add2` | 354 | 13.3s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.1s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 13.1s |  |
| 7 | `add_swf5` | 28 | 13.1s |  |
| 8 | `arguments` | 127 | 13.1s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 13.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.1s |  |
| 11 | `array_constructor` | 30 | 13.1s |  |
| 12 | `array_enumerate` | 4 | 13.0s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 13.1s |  |
| 14 | `array_properties` | 36 | 13.1s |  |
| 15 | `array_prototyping` | 12 | 13.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.0s |  |
| 17 | `array_sort` | 161 | 13.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 13.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 13.2s |  |
| 20 | `array_trivial` | 209 | 13.2s |  |
| 21 | `as1_constructor_v6` | 35 | 13.1s |  |
| 22 | `as1_constructor_v7` | 35 | 13.8s |  |
| 23 | `as2_oop` | 13 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 14.7s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 13.9s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 13.7s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 14.1s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 13.8s |  |
| 29 | `as_broadcaster_undef` | 89 | 14.0s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 14.5s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 14.3s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 14.4s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 14.3s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 14.3s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 14.2s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 14.2s |  |
| 37 | `as_transformed_flag` | 20 | 14.2s |  |
| 38 | `asnative` | 34 | 14.1s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 14.1s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 13.8s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 13.4s |  |
| 44 | `bitand` | 1058 | 16.1s |  |
| 45 | `bitmap_data_colortransform` | 0 | 13.7s |  |
| 46 | `bitmap_data_fillrect` | 0 | 13.6s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 13.4s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 13.4s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 14.2s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 13.9s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.6s |  |
| 52 | `bitor` | 1058 | 16.1s |  |
| 53 | `biturshift` | 14 | 13.4s |  |
| 54 | `biturshift_swf8` | 14 | 14.5s |  |
| 55 | `bitxor` | 1058 | 15.8s |  |
| 56 | `boxed_primitives` | 24 | 13.3s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 14.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 13.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 13.1s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 13.3s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 13.1s |  |
| 71 | `capabilities_resolution` | 8 | 13.2s |  |
| 72 | `catch_references_registers` | 2 | 13.2s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 13.3s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 13.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `closure_scope` | 7 | 13.3s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 77 | `color` | 57 | 13.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 78 | `color_transform` | 48 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `conflicting_instance_names` | 23 | 13.4s |  |
| 80 | `constructor_function` | 2 | 13.2s |  |
| 81 | `context_menu` | 39 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 82 | `context_menu_item` | 41 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `create_empty_movie_clip` | 3 | 13.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 84 | `custom_clip_methods` | 4 | 13.5s | [10](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `default_names` | 52 | 13.4s | [12](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 86 | `define_function2` | 8 | 13.3s |  |
| 87 | `define_function2_preload` | 13 | 13.6s |  |
| 88 | `define_function2_preload_order` | 4 | 14.2s |  |
| 89 | `define_function_case_sensitive` | 2 | 13.1s |  |
| 90 | `define_local` | 27 | 13.1s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 91 | `delete` | 3 | 13.2s |  |
| 92 | `device_font_spacing` | 91 | 13.2s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 93 | `display_object_properties` | 2 | 13.0s |  |
| 94 | `divide_swf4` | 107 | 13.1s |  |
| 95 | `do_init_action` | 3 | 13.1s |  |
| 96 | `do_init_action_child` | 12 | 13.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 97 | `drag_drop` | 10 | 13.1s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 98 | `drag_over_from_outside` | 1 | 13.1s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 99 | `drag_over_without_startdrag` | 1 | 13.2s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 100 | `duplicate_movie_clip` | 20 | 13.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 101 | `duplicate_movie_clip_drawing` | 2 | 13.1s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 102 | `edittext_align` | 60 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 103 | `edittext_align_trailing_spaces_swf7` | 576 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `edittext_align_trailing_spaces_swf8` | 576 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 105 | `edittext_antialiastype` | 296 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `edittext_autosize` | 71 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 107 | `edittext_autosize_setter` | 20 | 14.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 108 | `edittext_default_format` | 221 | 14.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 109 | `edittext_default_format_font_style` | 335 | 14.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 110 | `edittext_focus_selection` | 2 | 14.3s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 111 | `edittext_font_size` | 45 | 14.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 112 | `edittext_hscroll` | 27 | 14.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_html_align_swf7` | 52 | 14.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_html_align_swf8` | 52 | 14.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_color` | 114 | 14.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_condensewhite_swf7` | 311 | 14.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_condensewhite_swf8` | 311 | 14.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_entity` | 4 | 14.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_roundtrip` | 17 | 14.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_swf7` | 5377 | 14.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_swf8` | 5377 | 14.9s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_input` | 1 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_input_newlines` | 9 | 15.9s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_leading` | 9 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_letter_spacing` | 15 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_margins` | 25 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_newline_stripping` | 64 | 18.0s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_password` | 5 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_password_copy` | 4 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_paste_empty` | 2 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_place_caret` | 2 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_programmatic_focus` | 12 | 13.2s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_restrict` | 191 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_restrict_paste` | 5 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_stylesheet` | 325 | 13.9s | [51](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_tab_focus` | 13 | 13.2s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_tag_indent` | 31 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_text_height_leading` | 20 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_underline` | 40 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_width_height` | 103 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 141 | `empty_movieclip_can_attach_movies` | 11 | 15.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 142 | `enumerate` | 64 | 14.5s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 143 | `equals` | 32 | 14.2s |  |
| 144 | `equals2_swf5` | 926 | 16.2s |  |
| 145 | `equals2_swf6` | 926 | 16.3s |  |
| 146 | `equals2_swf7` | 926 | 16.3s |  |
| 147 | `equals_swf4` | 665 | 15.0s |  |
| 148 | `equals_swf4_alt` | 32 | 14.3s |  |
| 149 | `equals_swf5` | 32 | 14.3s |  |
| 150 | `error` | 58 | 14.2s |  |
| 151 | `escape` | 14 | 14.0s |  |
| 152 | `execution_order1` | 5 | 14.3s |  |
| 153 | `execution_order2` | 7 | 14.3s |  |
| 154 | `execution_order3` | 4 | 14.0s |  |
| 155 | `execution_order4` | 12 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 156 | `export_assets` | 3 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 157 | `extends_chain` | 134 | 14.5s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 158 | `extends_native_type` | 11 | 14.3s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 159 | `external_interface` | 84 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 160 | `external_interface_escapexml` | 26 | 14.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 161 | `external_interface_jsquotestring` | 21 | 14.1s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 162 | `external_interface_toas_basic` | 354 | 14.9s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 163 | `external_interface_toxml_array` | 25 | 14.3s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 164 | `external_interface_toxml_basic` | 179 | 14.4s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_unescapexml` | 40 | 14.2s | [16](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `focus_mouse` | 45 | 14.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 167 | `focus_mouse_rollout` | 4 | 14.5s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 168 | `focus_root_movie` | 2 | 14.4s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 169 | `focusrect_focuslost` | 4 | 14.2s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 170 | `focusrect_mouse_swf8` | 0 | 14.2s |  |
| 171 | `focusrect_mouse_swf9` | 0 | 15.0s |  |
| 172 | `focusrect_swf5` | 6 | 13.5s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 173 | `focusrect_swf6` | 42 | 13.2s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 174 | `form_loader_encoding_1` | 1 | 13.2s |  |
| 175 | `frame_size_translated_negative` | 21 | 13.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 176 | `frame_size_translated_positive` | 21 | 13.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 177 | `function_as_function` | 35 | 13.3s | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 178 | `function_base_clip` | 8 | 13.4s |  |
| 179 | `function_base_clip_readded` | 11 | 13.5s |  |
| 180 | `function_base_clip_removed` | 25 | 13.6s |  |
| 181 | `function_suppress_and_preload` | 28 | 13.3s |  |
| 182 | `funky_function_calls` | 56 | 13.4s | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 183 | `get_bytes_total` | 4 | 13.4s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 184 | `get_variable_in_scope` | 29 | 13.4s |  |
| 185 | `getproperty` | 28 | 13.3s |  |
| 186 | `getproperty_swf4` | 28 | 13.7s |  |
| 187 | `getproperty_swf5` | 28 | 13.4s |  |
| 188 | `gettextextent` | 56 | 13.5s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 189 | `global_array` | 3 | 13.3s |  |
| 190 | `global_is_bare` | 7 | 13.4s |  |
| 191 | `global_swf6_7_8` | 15 | 14.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 192 | `globals_swf5` | 304 | 14.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 193 | `globals_swf6` | 304 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 194 | `globals_swf7` | 304 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 195 | `globals_swf8` | 304 | 13.6s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 196 | `goto_advance1` | 6 | 13.6s |  |
| 197 | `goto_advance2` | 2 | 13.7s |  |
| 198 | `goto_both_ways1` | 3 | 13.6s |  |
| 199 | `goto_both_ways2` | 3 | 13.8s |  |
| 200 | `goto_execution_order` | 2 | 13.3s |  |
| 201 | `goto_execution_order2` | 2 | 13.4s |  |
| 202 | `goto_frame` | 12 | 14.7s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 203 | `goto_frame2` | 44 | 13.7s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 204 | `goto_frame_number` | 3 | 13.2s |  |
| 205 | `goto_label` | 17 | 13.4s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 206 | `goto_methods` | 40 | 13.3s | [18](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 207 | `goto_rewind1` | 1 | 13.2s |  |
| 208 | `goto_rewind2` | 3 | 13.2s |  |
| 209 | `goto_rewind3` | 2 | 13.1s |  |
| 210 | `greater_swf6` | 1175 | 15.1s |  |
| 211 | `greater_swf7` | 1175 | 15.0s |  |
| 212 | `greaterthan_swf5` | 1 | 13.3s |  |
| 213 | `greaterthan_swf8` | 1 | 13.3s |  |
| 214 | `has_own_property` | 32 | 13.2s |  |
| 215 | `hittest_lockroot` | 15 | 13.6s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 216 | `hittest_morph` | 70 | 13.3s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 217 | `hittest_winding_rule` | 12 | 13.5s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 218 | `infinite_recursion_function` | 4 | 13.2s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 219 | `infinite_recursion_function_in_setter` | 131 | 13.2s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 220 | `infinite_recursion_virtual_property` | 67 | 13.1s | [24](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 221 | `init_array_invalid` | 4 | 13.4s |  |
| 222 | `init_object_invalid` | 4 | 14.7s |  |
| 223 | `init_object_order` | 15 | 13.6s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 224 | `instanceof_coercions` | 88 | 13.7s | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 225 | `is_finite` | 49 | 13.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 226 | `is_finite_swf6` | 49 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 227 | `is_prototype_of` | 89 | 13.7s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 228 | `issue_1086` | 1 | 13.4s |  |
| 229 | `issue_1104` | 2 | 13.4s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 230 | `issue_1671` | 0 | 13.4s |  |
| 231 | `issue_1906` | 4 | 13.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 232 | `issue_2166` | 9 | 13.7s |  |
| 233 | `issue_3169` | 2 | 13.4s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 234 | `issue_3446` | 1 | 13.3s |  |
| 235 | `issue_3522` | 2 | 13.4s |  |
| 236 | `issue_4377` | 2 | 13.4s |  |
| 237 | `issue_710` | 4 | 13.7s |  |
| 238 | `issue_768` | 3 | 14.1s | [25](ruffle-tests/_investigation/complete/issue_768.md) |
| 239 | `issue_9327` | 2 | 14.0s |  |
| 240 | `issue_9885` | 2 | 13.9s |  |
| 241 | `key_isToggled` | 9 | 13.9s |  |
| 242 | `lessthan` | 41 | 13.7s |  |
| 243 | `lessthan2_swf5` | 1226 | 15.9s |  |
| 244 | `lessthan2_swf6` | 1226 | 16.0s |  |
| 245 | `lessthan2_swf7` | 1226 | 16.0s |  |
| 246 | `lessthan_swf4` | 902 | 15.0s |  |
| 247 | `lessthan_swf4_alt` | 41 | 13.6s |  |
| 248 | `lessthan_swf5` | 41 | 13.9s |  |
| 249 | `loadmovie` | 2 | 13.9s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 250 | `loadmovie_fail` | 2 | 13.9s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 251 | `loadmovie_flashvars` | 4 | 14.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 252 | `loadmovie_method` | 2 | 14.0s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 253 | `loadmovie_replace_root` | 5 | 14.1s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 254 | `loadmovie_var_persistence` | 8 | 13.9s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 255 | `loadmovienum` | 3 | 14.0s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 256 | `loadvariables` | 2 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 257 | `loadvariables2` | 8 | 13.6s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 258 | `loadvariablesnum` | 2 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 259 | `local_to_global` | 49 | 13.5s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 260 | `localconnection_properties` | 8 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 261 | `lock_root` | 1 | 13.5s |  |
| 262 | `logical_ops_swf4` | 90 | 13.4s |  |
| 263 | `logical_ops_swf8` | 108 | 13.5s |  |
| 264 | `looping` | 6 | 13.4s |  |
| 265 | `mask_reapply` | 0 | 13.4s |  |
| 266 | `mask_with_drawing` | 0 | 13.4s |  |
| 267 | `math_min_max` | 101 | 13.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 268 | `math_swf6` | 530 | 13.8s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 269 | `math_swf7` | 530 | 13.8s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 270 | `math_swf8` | 530 | 13.7s | [30](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 271 | `matrix` | 171 | 13.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 272 | `mcl_as_broadcaster` | 12 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 273 | `mcl_events_swf_version` | 232 | 14.0s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 274 | `mcl_getprogress` | 30 | 13.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 275 | `mcl_loadclip` | 149 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 276 | `mcl_loadclip_properties` | 6 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 277 | `mcl_mislabeled_target` | 6 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 278 | `mcl_target_gif87a` | 6 | 13.8s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 279 | `mcl_target_gif89a` | 6 | 13.7s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 280 | `mcl_target_jpg` | 6 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mcl_target_png` | 6 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 282 | `mcl_unloadclip` | 5 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mouse_events` | 8 | 13.4s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 284 | `mouse_events_visible_enabled` | 12 | 13.4s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 285 | `mouse_hover_events_while_dragging` | 1 | 13.3s | [13](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 286 | `mouse_listeners` | 67 | 13.2s |  |
| 287 | `mouse_pos` | 665 | 13.5s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 288 | `mouse_pos_with_scale_factor` | 260 | 13.3s | [32](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 289 | `mouse_wheel_enabled` | 2 | 13.2s |  |
| 290 | `movieclip_begin_gradient_fill` | 0 | 13.8s |  |
| 291 | `movieclip_blend_mode_property` | 35 | 14.7s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 292 | `movieclip_create_text_field` | 90 | 13.9s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 293 | `movieclip_default_state` | 69 | 14.1s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 294 | `movieclip_depth_methods` | 98 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 295 | `movieclip_focusenabled` | 99 | 13.8s | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 296 | `movieclip_get_instance_at_depth` | 28 | 13.8s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 297 | `movieclip_hittest` | 92 | 14.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 298 | `movieclip_in_removed_button` | 4 | 13.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 299 | `movieclip_init_object` | 5 | 14.0s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 300 | `movieclip_line_gradient_style` | 0 | 13.9s |  |
| 301 | `movieclip_name_from_timeline` | 13 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 302 | `movieclip_prototype_extension` | 5 | 13.2s |  |
| 303 | `moviecliploader_flashvars` | 4 | 13.2s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 304 | `mutable_this` | 18 | 13.2s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 305 | `nan_scale` | 9 | 13.2s |  |
| 306 | `native_double_construct` | 12 | 13.2s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 307 | `native_subclasses` | 191 | 13.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 308 | `nested_textfields_in_buttons` | 0 | 13.3s |  |
| 309 | `new_method_wrap` | 4 | 13.3s |  |
| 310 | `new_object_enumerate` | 7 | 13.2s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 311 | `new_object_wrap` | 4 | 13.3s |  |
| 312 | `o` | 3 | 13.1s |  |
| 313 | `object_constructor` | 33 | 13.3s |  |
| 314 | `object_function` | 32 | 13.4s |  |
| 315 | `object_properties` | 31 | 13.4s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 316 | `object_prototypes` | 74 | 13.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 317 | `object_resolve` | 38 | 13.4s | [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 318 | `object_string_coerce_swf5` | 62 | 13.3s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 319 | `object_string_coerce_swf6` | 68 | 13.3s | [36](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 320 | `on_construct` | 25 | 13.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 321 | `parse_float` | 74 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 322 | `parse_int` | 64 | 13.6s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [39](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 323 | `path_string` | 322 | 13.3s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 324 | `placeobject_occupied_depth` | 6 | 13.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 325 | `point` | 175 | 13.7s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 326 | `primitive_instanceof` | 37 | 13.3s |  |
| 327 | `primitive_type_globals` | 557 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 328 | `printjob_props_swf5` | 45 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 329 | `printjob_props_swf6` | 45 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 330 | `printjob_props_swf7` | 45 | 13.1s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 331 | `property_invalid_base_clip` | 36 | 13.1s |  |
| 332 | `prototype_delete` | 12 | 13.1s |  |
| 333 | `prototype_enumerate` | 5 | 13.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 334 | `prototype_properties` | 17 | 13.1s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 335 | `rectangle` | 745 | 13.8s | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 336 | `recursive_prototypes` | 0 | 13.1s |  |
| 337 | `register_class_return_value` | 16 | 13.2s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 338 | `register_class_with_sound` | 11 | 13.2s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 339 | `register_globals_across_frames` | 15 | 13.1s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 340 | `register_underflow` | 26 | 13.1s | [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 341 | `remove_movie_clip` | 29 | 13.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 342 | `rewind_depth` | 30 | 14.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 343 | `root_global_parent` | 6 | 14.2s | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 344 | `sandbox_type_local_file` | 1 | 13.9s |  |
| 345 | `sandbox_type_local_network` | 1 | 14.1s |  |
| 346 | `selection` | 454 | 14.0s | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 347 | `set_interval` | 27 | 14.2s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 348 | `set_variable_scope` | 58 | 14.0s |  |
| 349 | `single_frame` | 1 | 13.9s |  |
| 350 | `slash_syntax` | 14 | 13.9s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 351 | `sound` | 628 | 14.2s | [46](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 352 | `sound_props_swf5` | 68 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 353 | `sound_props_swf6` | 68 | 13.5s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 354 | `sound_start_load` | 0 | 13.4s |  |
| 355 | `stage_display_state` | 16 | 13.4s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 356 | `stage_object_children` | 83 | 13.5s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 357 | `stage_object_enumerate` | 4 | 13.3s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 358 | `stage_object_properties` | 241 | 13.8s | [15](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 359 | `stage_object_properties_get_var` | 5 | 13.4s |  |
| 360 | `stage_object_properties_swf6` | 231 | 13.8s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 361 | `stage_property_representation` | 586 | 13.5s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 362 | `stage_scale_mode` | 39 | 13.5s | [47](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [48](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 363 | `strictequals_swf6` | 902 | 14.9s |  |
| 364 | `strictly_equals` | 7 | 13.5s |  |
| 365 | `string_coercion` | 117 | 13.7s | [49](ruffle-tests/_investigation/complete/string_coercion.md) |
| 366 | `string_methods` | 285 | 13.9s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 367 | `string_methods_negative_args` | 240 | 13.5s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 368 | `string_methods_swfv5` | 275 | 14.0s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 369 | `string_ops_swf6` | 95 | 13.4s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 370 | `string_paths_basic` | 4 | 13.4s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 371 | `string_paths_eval2` | 7 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 372 | `string_paths_other` | 36 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 373 | `string_paths_unload` | 1 | 13.3s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 374 | `string_paths_variable_alias` | 4 | 13.2s | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 375 | `string_paths_variable_scopes` | 5 | 13.3s | [14](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 376 | `stylesheet` | 283 | 14.1s |  |
| 377 | `stylesheet_transform` | 750 | 13.9s |  |
| 378 | `super_edge_cases` | 39 | 13.4s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 379 | `swf4_actions_bool` | 96 | 13.3s |  |
| 380 | `swf4_actions_coercion_order` | 158 | 13.4s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 381 | `swf4_bool` | 4 | 13.3s |  |
| 382 | `swf4_function_calls` | 7 | 13.3s |  |
| 383 | `swf5_encoding` | 3 | 13.4s |  |
| 384 | `swf5_global_funcs` | 232 | 13.4s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 385 | `swf5_no_closure` | 19 | 13.7s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 386 | `swf6_case_insensitive` | 42 | 13.3s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 387 | `swf6_global_funcs` | 232 | 13.3s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 388 | `swf6_string_as_bool` | 15 | 13.3s | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 389 | `swf7_case_sensitive` | 44 | 13.2s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 390 | `swf7_global_funcs` | 232 | 13.2s | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 391 | `tab_ordering_automatic_basic` | 92 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 392 | `tab_ordering_automatic_order_grid` | 21 | 13.2s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 393 | `tab_ordering_automatic_order_same_position` | 12 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 394 | `tab_ordering_children` | 208 | 13.4s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 395 | `tab_ordering_custom_basic` | 71 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 396 | `tab_ordering_custom_duplicate_index` | 22 | 13.2s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 397 | `tab_ordering_custom_i32_vs_u32` | 12 | 13.2s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 398 | `tab_ordering_custom_m1` | 29 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 399 | `tab_ordering_events` | 150 | 13.6s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 400 | `tab_ordering_movieclip_enabled_default` | 462 | 13.6s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 401 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.2s |  |
| 402 | `tab_ordering_reverse` | 51 | 13.2s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 403 | `tab_ordering_tabbable` | 47 | 13.3s | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 404 | `target_clip_swf5` | 2 | 13.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 405 | `target_clip_swf6` | 2 | 13.1s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 406 | `target_path` | 14 | 13.1s |  |
| 407 | `tell_target` | 37 | 13.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 408 | `tell_target_invalid` | 6 | 13.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 409 | `tell_target_invalid_swf6` | 5 | 13.2s | [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 410 | `text_format` | 1146 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 411 | `text_format_display` | 21 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 412 | `text_format_font_max_length` | 2 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 413 | `text_format_rounding_swf7` | 840 | 13.3s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 414 | `text_format_rounding_swf8` | 840 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 415 | `textfield_background_color` | 11 | 13.1s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 416 | `textfield_border_color` | 11 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 417 | `textfield_cache_as_bitmap` | 1 | 13.2s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 418 | `textfield_maxchars` | 3 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 419 | `textfield_properties` | 44 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 420 | `textfield_props_swf5` | 175 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 421 | `textfield_props_swf6` | 210 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 422 | `textfield_props_swf7` | 210 | 13.6s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 423 | `textfield_props_swf8` | 210 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 424 | `textfield_text` | 7 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 425 | `textfield_variable` | 81 | 13.7s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 426 | `textsnapshot_available_text` | 20 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 427 | `textsnapshot_findtext` | 44 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 428 | `textsnapshot_gettext` | 55 | 13.8s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 429 | `textsnapshot_props_swf5` | 56 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 430 | `textsnapshot_props_swf6` | 56 | 13.5s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 431 | `textsnapshot_text_order` | 1 | 13.4s | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) [56](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 432 | `this_scoping` | 52 | 13.5s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 433 | `this_swf5` | 41 | 13.6s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 434 | `this_swf6` | 41 | 13.5s | [57](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 435 | `this_swf7` | 41 | 13.6s | [58](ruffle-tests/_investigation/complete/this_swf7.md) |
| 436 | `timeline_function_def` | 7 | 13.6s |  |
| 437 | `trace` | 8 | 13.2s |  |
| 438 | `transform` | 70 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 439 | `try_catch_finally` | 118 | 13.4s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 440 | `try_finally_simple` | 16 | 13.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 441 | `typeof` | 22 | 13.2s |  |
| 442 | `typeof_globals` | 7 | 13.2s |  |
| 443 | `uncaught_exception` | 1 | 13.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 444 | `uncaught_exception_bubbled` | 1 | 13.3s | [60](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 445 | `undefined_to_string_swf6` | 4 | 13.2s |  |
| 446 | `unescape` | 43 | 13.3s |  |
| 447 | `unload` | 52 | 13.4s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 448 | `unload_clip_event` | 4 | 13.3s | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 449 | `unloadmovie` | 4 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 450 | `unloadmovie_method` | 3 | 13.4s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 451 | `unloadmovienum` | 13 | 13.3s | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 452 | `use_hand_cursor` | 8 | 13.1s |  |
| 453 | `variable_args` | 5 | 13.4s |  |
| 454 | `waitforframe` | 7 | 13.2s |  |
| 455 | `waitforframe2` | 16 | 14.8s |  |
| 456 | `watch` | 117 | 14.2s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 457 | `watch_textfield` | 12 | 13.8s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 458 | `watch_virtual_property_proto` | 2 | 13.9s | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 459 | `with` | 49 | 14.0s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 460 | `with_return` | 2 | 13.9s |  |
| 461 | `with_variable_scopes` | 43 | 14.2s | [64](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 462 | `xml` | 15 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 463 | `xml_append_child` | 28 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 464 | `xml_append_child_with_parent` | 20 | 14.0s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 465 | `xml_attributes_read` | 4 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 466 | `xml_cdata` | 11 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 467 | `xml_child_nodes_edge_cases` | 4 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 468 | `xml_clone_expandos` | 19 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 469 | `xml_first_last_child` | 8 | 13.9s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 470 | `xml_has_child_nodes` | 3 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 471 | `xml_idmap` | 21 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 472 | `xml_ignore_comments` | 21 | 14.1s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 473 | `xml_ignore_white` | 34 | 13.8s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 474 | `xml_insert_before` | 20 | 13.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 475 | `xml_inspect_createmethods` | 15 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 476 | `xml_inspect_doctype` | 7 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 477 | `xml_inspect_parsexml` | 62 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 478 | `xml_inspect_xmldecl` | 7 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 479 | `xml_namespaces` | 203 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 480 | `xml_parent_and_child` | 5 | 13.6s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 481 | `xml_remove_node` | 22 | 13.7s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 482 | `xml_reparenting` | 14 | 13.6s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 483 | `xml_siblings` | 10 | 13.5s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 484 | `xml_to_string` | 13 | 13.3s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 485 | `xml_to_string_comment` | 1 | 13.2s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 486 | `xml_unescaping` | 23 | 13.4s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 487 | `xmlnode_proto` | 1 | 13.6s | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**38 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf7` | 98.8% | 83 | 84 | 1 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 98.8% | 83 | 84 | 1 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `interface_implements_op` | 97.9% | 46 | 47 | 1 | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 6 | `native_objects_swf6` | 97.6% | 82 | 84 | 2 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `movieclip_setmask` | 85.7% | 12 | 14 | 2 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `swf5_to_6_cross_call` | 79.3% | 23 | 29 | 6 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 16 | `selection_handlers` | 77.8% | 21 | 27 | 6 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 20 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `named_shapes` | 71.4% | 10 | 14 | 4 |  |
| 22 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `register_class` | 66.7% | 44 | 66 | 22 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `string_paths_hidden` | 66.7% | 36 | 54 | 18 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 25 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/incomplete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `clone_sprite_types` | 62.5% | 15 | 24 | 9 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 27 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 30 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 31 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 32 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 33 | `swf6_to_5_cross_call` | 55.2% | 16 | 29 | 13 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 34 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 35 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 36 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 37 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 38 | `issue_2030` | 50.0% | 2 | 4 | 2 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 16.6s | [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 28.9s |  |

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_1` | exit code -6 | 14.5s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_2` | exit code -6 | 14.9s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `movieclip_invalid_get_bounds_6` | exit code -6 | 38.2s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `movieclip_invalid_get_bounds_7` | exit code -6 | 38.0s | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 23.4s | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**124 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [11](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 3 | `native_objects_swf7` | 98.8% | 83/84 | 84 | 84 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `native_objects_swf8` | 98.8% | 83/84 | 84 | 84 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `interface_implements_op` | 97.9% | 46/47 | 47 | 47 | [38](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 6 | `native_objects_swf6` | 97.6% | 82/84 | 84 | 84 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 8 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 10 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `movieclip_setmask` | 85.7% | 12/14 | 14 | 14 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 13 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 14 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 15 | `swf5_to_6_cross_call` | 79.3% | 23/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 16 | `selection_handlers` | 77.8% | 21/27 | 23 | 27 | [45](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 17 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 18 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 20 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `named_shapes` | 71.4% | 10/14 | 14 | 14 |  |
| 22 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `register_class` | 66.7% | 44/66 | 65 | 66 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 24 | `string_paths_hidden` | 66.7% | 36/54 | 54 | 54 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 25 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/incomplete/LOCKROOT_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `clone_sprite_types` | 62.5% | 15/24 | 24 | 24 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 27 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 28 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 30 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 31 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 32 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [61](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 33 | `swf6_to_5_cross_call` | 55.2% | 16/29 | 29 | 29 | [52](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 34 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 35 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 36 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 37 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 38 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 39 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 40 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 41 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 42 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 43 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 44 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [40](ruffle-tests/_investigation/incomplete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [41](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 45 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 46 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [53](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 47 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 48 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 49 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 50 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 51 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 52 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 53 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 54 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 55 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 56 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 57 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 58 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 59 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 60 | `place_and_lookup` | 20.0% | 6/30 | 15 | 30 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 61 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 62 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 63 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 64 | `timer_run_actions` | 16.7% | 3/18 | 17 | 18 | [59](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 65 | `register_and_init_order` | 15.6% | 36/231 | 154 | 231 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 66 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 67 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 68 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 70 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [37](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 71 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 72 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 73 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 74 | `register_class_swf6` | 10.8% | 4/37 | 35 | 37 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [42](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 76 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 77 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 78 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 79 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 80 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [21](ruffle-tests/_investigation/incomplete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 82 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 83 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 84 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 85 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [44](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) |
| 86 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [27](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 88 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 89 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 90 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 91 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 92 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 93 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 94 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 95 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [20](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 96 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [22](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 97 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [19](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 98 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 99 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 100 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [55](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 101 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [17](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 102 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 103 | `geturl` | 0.0% | 0/7 | 0 | 7 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 104 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 105 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 106 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [28](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 107 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [34](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [43](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 108 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 109 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 110 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 111 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 112 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 113 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [26](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 114 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 115 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 116 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 117 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [50](ruffle-tests/_investigation/complete/STRING_PLAN.md) [54](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 118 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [62](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 119 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 120 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [33](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [63](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 121 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 122 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 123 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 124 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [65](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 4 | 4 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 3 | 1 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 11 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 12 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 13 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 14 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 15 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 16 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 17 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 5 | 2 |
| 18 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 19 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 20 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 21 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/incomplete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 0 | 1 |
| 22 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 24 | 7 |
| 23 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 24 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 25 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 26 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 27 | 22 |
| 27 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 2 | 3 |
| 28 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 29 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/incomplete/LOCKROOT_PLAN.md) | 1 | 0 | 1 |
| 30 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 31 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 32 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 33 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 31 | 27 |
| 34 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 13 | 3 |
| 35 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 13 | 4 |
| 36 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 37 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 38 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 39 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 40 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/incomplete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 0 | 1 |
| 41 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 42 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 43 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 44 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/incomplete/SCRIPT_HALTING_PLAN.md) | 2 | 0 | 2 |
| 45 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 3 | 1 |
| 46 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 47 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 48 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 49 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 50 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 10 | 3 |
| 51 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 52 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 53 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 15 | 1 |
| 54 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 13 | 6 |
| 55 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 62 | 8 |
| 56 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 57 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 58 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 59 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 60 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 61 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 62 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/incomplete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 5 | 11 |
| 63 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 64 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 65 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 195 | 155 | 40 |
