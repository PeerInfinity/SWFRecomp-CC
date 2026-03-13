# Ruffle Test Results (Filtered)

**Date**: 2026-03-13 18:59 UTC

**Git SHA**: `d368848b67`

**Run Duration**: 155m 46s

**Filtered**: 51 tests ignored out of 618 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 567 |
| Passing | **524** (92.4%) |
| Failing | 43 |
| Total expected lines | 79119 |
| Matching lines | 68313 (86.3%) |
| Mismatched lines | 10806 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 43 | 100.0% |

## Passing Tests

**524 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.9s |  |
| 2 | `action_to_integer` | 28 | 14.9s |  |
| 3 | `add` | 28 | 14.8s |  |
| 4 | `add2` | 354 | 15.5s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.6s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.4s |  |
| 7 | `add_swf5` | 28 | 14.8s |  |
| 8 | `arguments` | 127 | 14.7s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 14.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 14.8s |  |
| 11 | `array_constructor` | 30 | 14.8s |  |
| 12 | `array_enumerate` | 4 | 14.8s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 14.8s |  |
| 14 | `array_properties` | 36 | 14.5s |  |
| 15 | `array_prototyping` | 12 | 14.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.1s |  |
| 17 | `array_sort_random` | 443 | 14.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 14.9s |  |
| 19 | `array_trivial` | 209 | 14.8s |  |
| 20 | `as1_constructor_v6` | 35 | 14.8s |  |
| 21 | `as1_constructor_v7` | 35 | 14.5s |  |
| 22 | `as2_oop` | 13 | 14.5s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 14.7s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 14.6s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 14.6s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 14.3s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 14.2s |  |
| 28 | `as_broadcaster_undef` | 89 | 14.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 14.3s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 14.3s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 14.3s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 14.3s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 14.3s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 14.3s |  |
| 36 | `as_transformed_flag` | 20 | 14.4s |  |
| 37 | `asnative` | 34 | 14.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 14.4s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 14.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 14.3s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 15.1s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 14.7s |  |
| 43 | `bitand` | 1058 | 17.5s |  |
| 44 | `bitmap_data_colortransform` | 0 | 15.0s |  |
| 45 | `bitmap_data_fillrect` | 0 | 15.1s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 14.7s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 14.9s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 15.7s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 15.3s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 14.9s |  |
| 51 | `bitor` | 1058 | 17.3s |  |
| 52 | `biturshift` | 14 | 14.6s |  |
| 53 | `biturshift_swf8` | 14 | 14.8s |  |
| 54 | `bitxor` | 1058 | 17.5s |  |
| 55 | `boxed_primitives` | 24 | 14.7s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 58 | `button_key_events` | 14 | 14.8s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 59 | `button_key_events_special` | 45 | 15.4s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_keypress` | 3 | 14.8s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_press` | 25 | 14.7s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_tab` | 20 | 14.9s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_textinput` | 4 | 14.7s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_order` | 2 | 14.7s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_properties_special_cases` | 22 | 14.8s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_v5` | 18 | 14.6s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_v6` | 18 | 14.5s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `call` | 63 | 14.8s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 69 | `call_method_empty_name` | 1 | 14.6s |  |
| 70 | `capabilities_resolution` | 8 | 14.6s |  |
| 71 | `catch_references_registers` | 2 | 14.5s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 72 | `click_block` | 5 | 14.6s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 73 | `clip_constructors` | 8 | 14.7s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 74 | `clip_events` | 19 | 14.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `clone_sprite_types` | 24 | 14.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `closure_scope` | 7 | 14.5s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 77 | `coerce_to_primitive_resolve` | 17 | 14.6s | [45](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 78 | `color` | 57 | 14.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 14.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 14.6s |  |
| 81 | `constructor_function` | 2 | 14.3s |  |
| 82 | `context_menu` | 39 | 14.4s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 14.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 14.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `cross_movie_root` | 10 | 14.5s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 86 | `custom_clip_methods` | 4 | 14.6s | [11](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 87 | `default_names` | 52 | 14.7s | [13](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `define_function2` | 8 | 14.7s |  |
| 89 | `define_function2_preload` | 13 | 14.5s |  |
| 90 | `define_function2_preload_order` | 4 | 14.5s |  |
| 91 | `define_function_case_sensitive` | 2 | 14.3s |  |
| 92 | `define_local` | 27 | 14.4s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 93 | `define_local_with_paths` | 54 | 14.4s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 94 | `delete` | 3 | 14.4s |  |
| 95 | `device_font_spacing` | 91 | 14.4s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 96 | `display_object_properties` | 2 | 14.3s |  |
| 97 | `divide_swf4` | 107 | 14.5s |  |
| 98 | `do_init_action` | 3 | 14.4s |  |
| 99 | `do_init_action_child` | 12 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 100 | `drag_drop` | 10 | 14.4s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 101 | `drag_over_from_outside` | 1 | 14.4s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 102 | `drag_over_without_startdrag` | 1 | 14.5s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 103 | `duplicate_movie_clip` | 20 | 14.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `duplicate_movie_clip_drawing` | 2 | 14.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 105 | `edittext_align` | 60 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_align_trailing_spaces_swf7` | 576 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_align_trailing_spaces_swf8` | 576 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_antialiastype` | 296 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_autosize` | 71 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_autosize_setter` | 20 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_default_format` | 221 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_default_format_font_style` | 335 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_focus_selection` | 2 | 14.9s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_font_size` | 45 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_hscroll` | 27 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_html_align_swf7` | 52 | 15.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_html_align_swf8` | 52 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_html_color` | 114 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_html_condensewhite_swf7` | 311 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_html_condensewhite_swf8` | 311 | 15.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_html_entity` | 4 | 15.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_html_roundtrip` | 17 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_html_swf7` | 5377 | 16.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_html_swf8` | 5377 | 16.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_input` | 1 | 15.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_input_newlines` | 9 | 16.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_leading` | 9 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_letter_spacing` | 15 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_margins` | 25 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_newline_stripping` | 64 | 19.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_newlines` | 30 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `edittext_password` | 5 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 133 | `edittext_password_copy` | 4 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 134 | `edittext_paste_empty` | 2 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 135 | `edittext_place_caret` | 2 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 136 | `edittext_programmatic_focus` | 12 | 14.8s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 137 | `edittext_restrict` | 191 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 138 | `edittext_restrict_paste` | 5 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 139 | `edittext_scroll` | 54 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 140 | `edittext_stylesheet` | 325 | 15.5s | [56](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 141 | `edittext_tab_focus` | 13 | 14.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 142 | `edittext_tab_stops` | 60 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 143 | `edittext_tag_indent` | 31 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 144 | `edittext_text_height_leading` | 20 | 15.0s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 145 | `edittext_underline` | 40 | 14.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 146 | `edittext_width_height` | 103 | 14.8s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 147 | `empty_movieclip_can_attach_movies` | 11 | 16.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 148 | `enumerate` | 64 | 16.1s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 149 | `equals` | 32 | 16.1s |  |
| 150 | `equals2_swf5` | 926 | 18.2s |  |
| 151 | `equals2_swf6` | 926 | 17.9s |  |
| 152 | `equals2_swf7` | 926 | 18.2s |  |
| 153 | `equals_swf4_alt` | 32 | 16.0s |  |
| 154 | `equals_swf5` | 32 | 15.8s |  |
| 155 | `error` | 58 | 16.0s |  |
| 156 | `escape` | 14 | 16.1s |  |
| 157 | `execution_order1` | 5 | 15.9s |  |
| 158 | `execution_order2` | 7 | 16.2s |  |
| 159 | `execution_order3` | 4 | 15.7s |  |
| 160 | `execution_order4` | 12 | 16.1s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 161 | `export_assets` | 3 | 16.0s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 162 | `extends_chain` | 134 | 16.3s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 163 | `extends_native_type` | 11 | 16.2s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 164 | `external_interface` | 84 | 16.3s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 165 | `external_interface_escapexml` | 26 | 16.1s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 166 | `external_interface_jsquotestring` | 21 | 16.1s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 167 | `external_interface_toas_basic` | 354 | 15.1s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 168 | `external_interface_toxml_array` | 25 | 14.7s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 169 | `external_interface_toxml_basic` | 179 | 14.5s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 170 | `external_interface_unescapexml` | 40 | 14.4s | [17](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 171 | `focus_keyboard_press` | 60 | 14.4s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 172 | `focus_mouse` | 45 | 14.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 173 | `focus_mouse_rollout` | 4 | 14.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 174 | `focus_remove` | 33 | 14.3s |  |
| 175 | `focus_root_movie` | 2 | 14.2s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 176 | `focus_visibility_change` | 45 | 14.2s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 177 | `focusrect_focuslost` | 4 | 14.1s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 178 | `focusrect_mouse_swf8` | 0 | 14.1s |  |
| 179 | `focusrect_mouse_swf9` | 0 | 15.8s |  |
| 180 | `focusrect_property_swf5` | 1237 | 15.5s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 181 | `focusrect_property_swf6` | 1237 | 15.6s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 182 | `focusrect_property_swf7` | 1237 | 15.5s | [18](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 183 | `focusrect_swf5` | 6 | 15.5s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 184 | `focusrect_swf6` | 42 | 15.4s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 185 | `frame_size_translated_negative` | 21 | 16.3s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 186 | `frame_size_translated_positive` | 21 | 15.8s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 187 | `function_as_function` | 35 | 15.7s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 188 | `function_base_clip` | 8 | 15.5s |  |
| 189 | `function_base_clip_readded` | 11 | 15.2s |  |
| 190 | `function_base_clip_removed` | 25 | 14.9s |  |
| 191 | `function_suppress_and_preload` | 28 | 15.0s |  |
| 192 | `funky_function_calls` | 56 | 14.9s | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 193 | `get_bytes_total` | 4 | 14.8s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 194 | `get_variable_in_scope` | 29 | 14.9s |  |
| 195 | `getproperty` | 28 | 15.2s |  |
| 196 | `getproperty_swf4` | 28 | 15.8s |  |
| 197 | `getproperty_swf5` | 28 | 15.5s |  |
| 198 | `gettextextent` | 56 | 15.5s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 199 | `global_array` | 3 | 15.4s |  |
| 200 | `global_swf6_7_8` | 15 | 15.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 201 | `globals_swf5` | 304 | 15.5s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 202 | `globals_swf6` | 304 | 15.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 203 | `globals_swf7` | 304 | 15.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 204 | `globals_swf8` | 304 | 15.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 205 | `goto_advance1` | 6 | 15.2s |  |
| 206 | `goto_advance2` | 2 | 15.3s |  |
| 207 | `goto_both_ways1` | 3 | 15.4s |  |
| 208 | `goto_both_ways2` | 3 | 15.3s |  |
| 209 | `goto_execution_order` | 2 | 15.2s |  |
| 210 | `goto_execution_order2` | 2 | 15.6s |  |
| 211 | `goto_frame` | 12 | 14.6s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 212 | `goto_frame2` | 44 | 14.7s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 213 | `goto_frame_number` | 3 | 14.2s |  |
| 214 | `goto_label` | 17 | 14.4s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 215 | `goto_methods` | 40 | 14.3s | [20](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 216 | `goto_rewind1` | 1 | 14.1s |  |
| 217 | `goto_rewind2` | 3 | 14.1s |  |
| 218 | `goto_rewind3` | 2 | 14.2s |  |
| 219 | `greaterthan_swf5` | 1 | 14.1s |  |
| 220 | `greaterthan_swf8` | 1 | 14.2s |  |
| 221 | `has_own_property` | 32 | 14.2s |  |
| 222 | `hittest_lockroot` | 15 | 14.4s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 223 | `hittest_morph` | 70 | 14.3s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [36](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 224 | `hittest_winding_rule` | 12 | 14.3s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 225 | `infinite_recursion_function` | 4 | 14.2s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 226 | `infinite_recursion_function_in_setter` | 131 | 14.2s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 227 | `infinite_recursion_virtual_property` | 67 | 14.2s | [27](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 228 | `init_array_invalid` | 4 | 14.1s |  |
| 229 | `init_object_invalid` | 4 | 15.0s |  |
| 230 | `init_object_order` | 15 | 14.9s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 231 | `instanceof_coercions` | 88 | 15.1s | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 232 | `interface_implements_op` | 47 | 15.2s | [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 233 | `is_finite` | 49 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 234 | `is_finite_swf6` | 49 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 235 | `is_prototype_of` | 89 | 14.7s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 236 | `issue_1086` | 1 | 14.6s |  |
| 237 | `issue_1104` | 2 | 14.6s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 238 | `issue_1671` | 0 | 14.7s |  |
| 239 | `issue_1906` | 4 | 14.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 240 | `issue_2166` | 9 | 14.7s |  |
| 241 | `issue_2870` | 3 | 14.8s | [30](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 242 | `issue_3169` | 2 | 14.8s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 243 | `issue_3446` | 1 | 14.7s |  |
| 244 | `issue_3522` | 2 | 14.7s |  |
| 245 | `issue_4377` | 2 | 14.7s |  |
| 246 | `issue_710` | 4 | 14.7s |  |
| 247 | `issue_768` | 3 | 14.5s | [29](ruffle-tests/_investigation/complete/issue_768.md) |
| 248 | `issue_9327` | 2 | 14.6s |  |
| 249 | `issue_9885` | 2 | 14.7s |  |
| 250 | `key_isToggled` | 9 | 14.7s |  |
| 251 | `lessthan` | 41 | 14.5s |  |
| 252 | `lessthan2_swf5` | 1226 | 16.4s |  |
| 253 | `lessthan_swf4_alt` | 41 | 14.4s |  |
| 254 | `lessthan_swf5` | 41 | 14.4s |  |
| 255 | `loadmovie` | 2 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 256 | `loadmovie_fail` | 2 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 257 | `loadmovie_flashvars` | 4 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 258 | `loadmovie_method` | 2 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 259 | `loadmovie_registerclass` | 30 | 14.6s | [10](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 260 | `loadmovie_replace_root` | 5 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 261 | `loadmovie_var_persistence` | 8 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 262 | `loadmovienum` | 3 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 263 | `loadmovienum_cross_version_prototype` | 9 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) |
| 264 | `loadvariables` | 2 | 15.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 265 | `loadvariables2` | 8 | 15.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 266 | `loadvariablesnum` | 2 | 15.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 267 | `local_to_global` | 49 | 15.6s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 268 | `localconnection_properties` | 8 | 15.4s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 269 | `lock_root` | 1 | 15.5s |  |
| 270 | `logical_ops_swf4` | 90 | 15.5s |  |
| 271 | `logical_ops_swf8` | 108 | 15.5s |  |
| 272 | `looping` | 6 | 15.3s |  |
| 273 | `mask_reapply` | 0 | 15.5s |  |
| 274 | `mask_with_drawing` | 0 | 15.4s |  |
| 275 | `math_min_max` | 101 | 15.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 276 | `math_swf6` | 530 | 16.0s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 277 | `math_swf7` | 530 | 16.0s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 278 | `math_swf8` | 530 | 16.0s | [35](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 279 | `matrix` | 171 | 15.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 280 | `mcl_as_broadcaster` | 12 | 15.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mcl_events_swf_version` | 232 | 16.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 282 | `mcl_getprogress` | 30 | 15.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 283 | `mcl_loadclip` | 149 | 16.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 284 | `mcl_loadclip_properties` | 6 | 14.7s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 285 | `mcl_loadclip_replace_root` | 1 | 14.5s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [48](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 286 | `mcl_mislabeled_target` | 6 | 14.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 287 | `mcl_target_gif87a` | 6 | 14.8s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 288 | `mcl_target_gif89a` | 6 | 14.9s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 289 | `mcl_target_jpg` | 6 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 290 | `mcl_target_png` | 6 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 291 | `mcl_unloadclip` | 5 | 14.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 292 | `mouse_events` | 8 | 14.5s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 293 | `mouse_events_visible_enabled` | 12 | 14.7s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 294 | `mouse_hover_events_while_dragging` | 1 | 14.6s | [14](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 295 | `mouse_listeners` | 67 | 14.4s |  |
| 296 | `mouse_pos` | 665 | 14.7s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 297 | `mouse_pos_with_scale_factor` | 260 | 14.5s | [37](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 298 | `mouse_wheel_enabled` | 2 | 14.4s |  |
| 299 | `movieclip_begin_gradient_fill` | 0 | 15.2s |  |
| 300 | `movieclip_blend_mode_property` | 35 | 14.7s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 301 | `movieclip_create_text_field` | 90 | 14.7s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 302 | `movieclip_default_state` | 69 | 16.8s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 303 | `movieclip_depth_methods` | 98 | 15.1s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 304 | `movieclip_focusenabled` | 99 | 15.2s | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 305 | `movieclip_get_instance_at_depth` | 28 | 14.8s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 306 | `movieclip_getbounds` | 191 | 15.3s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 307 | `movieclip_gettextsnapshot` | 112 | 15.3s | [23](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 308 | `movieclip_hittest` | 92 | 15.3s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 309 | `movieclip_in_removed_button` | 4 | 14.7s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 310 | `movieclip_init_object` | 5 | 15.1s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 311 | `movieclip_invalid_get_bounds_1` | 75 | 15.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 312 | `movieclip_invalid_get_bounds_2` | 75 | 15.3s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 313 | `movieclip_invalid_get_bounds_3` | 13 | 15.1s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 314 | `movieclip_invalid_get_bounds_4` | 13 | 15.3s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 315 | `movieclip_invalid_get_bounds_5` | 11 | 15.1s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 316 | `movieclip_invalid_get_bounds_8` | 11 | 14.7s | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 317 | `movieclip_line_gradient_style` | 0 | 15.2s |  |
| 318 | `movieclip_lockroot` | 29 | 15.2s | [34](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 319 | `movieclip_name_from_timeline` | 13 | 14.2s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 320 | `movieclip_prototype_extension` | 5 | 14.2s |  |
| 321 | `movieclip_setmask` | 14 | 14.4s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 322 | `moviecliploader_flashvars` | 4 | 14.3s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 323 | `mutable_this` | 18 | 14.2s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 324 | `named_shapes` | 14 | 14.2s |  |
| 325 | `nan_scale` | 9 | 14.2s |  |
| 326 | `native_double_construct` | 12 | 14.4s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 327 | `native_objects_swf7` | 84 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 328 | `native_objects_swf8` | 84 | 14.6s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 329 | `nested_textfields_in_buttons` | 0 | 14.1s |  |
| 330 | `new_method_wrap` | 4 | 14.8s |  |
| 331 | `new_object_enumerate` | 7 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 332 | `new_object_wrap` | 4 | 14.4s |  |
| 333 | `o` | 3 | 14.4s |  |
| 334 | `object_constructor` | 33 | 14.4s |  |
| 335 | `object_function` | 32 | 14.4s |  |
| 336 | `object_properties` | 31 | 14.6s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 337 | `object_prototypes` | 74 | 14.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 338 | `object_resolve` | 38 | 14.6s | [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 339 | `object_string_coerce_swf5` | 62 | 14.6s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 340 | `object_string_coerce_swf6` | 68 | 14.5s | [41](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 341 | `on_construct` | 25 | 14.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 342 | `parse_float` | 74 | 14.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 343 | `parse_int` | 64 | 14.7s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [44](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 344 | `path_string` | 322 | 14.7s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 345 | `place_and_lookup` | 30 | 14.5s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 346 | `placeobject_occupied_depth` | 6 | 14.5s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 347 | `point` | 175 | 14.7s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 348 | `primitive_instanceof` | 37 | 14.5s |  |
| 349 | `primitive_type_globals` | 557 | 14.5s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 350 | `printjob_props_swf5` | 45 | 15.3s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 351 | `printjob_props_swf6` | 45 | 15.1s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 352 | `printjob_props_swf7` | 45 | 15.2s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 353 | `property_invalid_base_clip` | 36 | 15.3s |  |
| 354 | `prototype_delete` | 12 | 15.2s |  |
| 355 | `prototype_enumerate` | 5 | 15.4s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 356 | `prototype_properties` | 17 | 15.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 357 | `rectangle` | 745 | 15.8s | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 358 | `recursive_prototypes` | 0 | 14.5s |  |
| 359 | `register_and_init_order` | 231 | 15.2s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 360 | `register_class` | 66 | 15.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 361 | `register_class_return_value` | 16 | 14.9s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 362 | `register_class_swf6` | 37 | 15.0s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 363 | `register_class_with_sound` | 11 | 14.9s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 364 | `register_globals_across_frames` | 15 | 15.1s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 365 | `register_underflow` | 26 | 15.1s | [47](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 366 | `remove_movie_clip` | 29 | 14.9s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 367 | `removed_clip_halts_script` | 15 | 15.3s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 368 | `removed_target_clip_scope` | 35 | 15.0s | [6](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 369 | `resolve_different_root` | 2 | 15.3s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 370 | `rewind_depth` | 30 | 14.7s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 371 | `root_button_mode` | 10 | 14.7s | [5](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 372 | `root_global_parent` | 6 | 14.6s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 373 | `root_onload` | 1 | 14.4s | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 374 | `sandbox_type_local_file` | 1 | 14.4s |  |
| 375 | `sandbox_type_local_network` | 1 | 14.5s |  |
| 376 | `selection` | 454 | 14.7s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 377 | `selection_handlers` | 27 | 14.5s | [50](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 378 | `set_interval` | 27 | 14.6s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 379 | `set_variable_scope` | 58 | 14.4s |  |
| 380 | `single_frame` | 1 | 14.4s |  |
| 381 | `slash_syntax` | 14 | 14.4s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 382 | `sound` | 628 | 14.8s | [51](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 383 | `sound_props_swf5` | 68 | 14.4s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 384 | `sound_props_swf6` | 68 | 14.3s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 385 | `sound_start_load` | 0 | 14.3s |  |
| 386 | `stage_display_state` | 16 | 14.2s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 387 | `stage_object_children` | 83 | 14.2s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 388 | `stage_object_enumerate` | 4 | 14.2s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 389 | `stage_object_properties` | 241 | 14.6s | [16](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 390 | `stage_object_properties_get_var` | 5 | 14.2s |  |
| 391 | `stage_object_properties_swf6` | 231 | 14.5s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 392 | `stage_property_representation` | 586 | 14.2s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 393 | `stage_scale_mode` | 39 | 14.2s | [52](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [53](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 394 | `strictequals_swf6` | 902 | 15.7s |  |
| 395 | `strictly_equals` | 7 | 14.2s |  |
| 396 | `string_coercion` | 117 | 14.4s | [54](ruffle-tests/_investigation/complete/string_coercion.md) |
| 397 | `string_methods` | 285 | 14.7s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 398 | `string_methods_negative_args` | 240 | 14.3s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 399 | `string_methods_swfv5` | 275 | 14.8s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 400 | `string_ops_swf6` | 95 | 14.2s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 401 | `string_paths_basic` | 4 | 14.1s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 402 | `string_paths_eval2` | 7 | 14.5s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 403 | `string_paths_hidden` | 54 | 14.3s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 404 | `string_paths_other` | 36 | 14.6s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 405 | `string_paths_unload` | 1 | 14.3s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 406 | `string_paths_variable_alias` | 4 | 14.3s | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 407 | `string_paths_variable_scopes` | 5 | 14.3s | [15](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 408 | `stylesheet` | 283 | 15.1s |  |
| 409 | `stylesheet_transform` | 750 | 15.0s |  |
| 410 | `super_edge_cases` | 39 | 14.4s | [40](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [43](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 411 | `swf4_actions_bool` | 96 | 14.2s |  |
| 412 | `swf4_actions_coercion_order` | 158 | 14.3s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 413 | `swf4_bool` | 4 | 14.2s |  |
| 414 | `swf4_function_calls` | 7 | 14.3s |  |
| 415 | `swf5_encoding` | 3 | 14.4s |  |
| 416 | `swf5_global_funcs` | 232 | 14.3s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 417 | `swf5_no_closure` | 19 | 14.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 418 | `swf5_to_6_cross_call` | 29 | 15.3s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 419 | `swf6_case_insensitive` | 42 | 14.9s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 420 | `swf6_global_funcs` | 232 | 15.0s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 421 | `swf6_string_as_bool` | 15 | 15.0s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 422 | `swf6_to_5_cross_call` | 29 | 15.3s | [57](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 423 | `swf7_case_sensitive` | 44 | 15.0s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 424 | `swf7_global_funcs` | 232 | 15.0s | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 425 | `tab_ordering_automatic_basic` | 92 | 14.9s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 426 | `tab_ordering_automatic_order_grid` | 21 | 15.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 427 | `tab_ordering_automatic_order_same_position` | 12 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 428 | `tab_ordering_children` | 208 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 429 | `tab_ordering_custom_basic` | 71 | 15.0s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 430 | `tab_ordering_custom_duplicate_index` | 22 | 15.4s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 431 | `tab_ordering_custom_i32_vs_u32` | 12 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 432 | `tab_ordering_custom_m1` | 29 | 14.7s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 433 | `tab_ordering_events` | 150 | 15.1s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 434 | `tab_ordering_events_mouse` | 65 | 15.2s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 435 | `tab_ordering_movieclip_enabled_default` | 462 | 15.0s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 436 | `tab_ordering_properties_tab_index_edge_case` | 4 | 14.6s |  |
| 437 | `tab_ordering_reverse` | 51 | 14.4s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 438 | `tab_ordering_tabbable` | 47 | 14.4s | [58](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 439 | `target_clip_removed` | 5 | 14.3s | [49](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 440 | `target_clip_swf5` | 2 | 14.3s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 441 | `target_clip_swf6` | 2 | 14.2s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 442 | `target_path` | 14 | 14.2s |  |
| 443 | `tell_target` | 37 | 14.3s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 444 | `tell_target_invalid` | 6 | 14.3s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 445 | `tell_target_invalid_swf6` | 5 | 14.3s | [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 446 | `text_format` | 1146 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 447 | `text_format_display` | 21 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 448 | `text_format_font_max_length` | 2 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 449 | `text_format_get_text_extent_undefined_width` | 10 | 14.2s |  |
| 450 | `text_format_rounding_swf7` | 840 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 451 | `text_format_rounding_swf8` | 840 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 452 | `textfield_background_color` | 11 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 453 | `textfield_border_color` | 11 | 14.1s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 454 | `textfield_cache_as_bitmap` | 1 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 455 | `textfield_maxchars` | 3 | 15.9s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 456 | `textfield_properties` | 44 | 14.3s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 457 | `textfield_props_swf5` | 175 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 458 | `textfield_props_swf6` | 210 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 459 | `textfield_props_swf7` | 210 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 460 | `textfield_props_swf8` | 210 | 14.4s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 461 | `textfield_text` | 7 | 14.2s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 462 | `textfield_variable` | 81 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 463 | `textsnapshot_available_text` | 20 | 14.5s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 464 | `textsnapshot_findtext` | 44 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 465 | `textsnapshot_gettext` | 55 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 466 | `textsnapshot_props_swf5` | 56 | 14.7s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 467 | `textsnapshot_props_swf6` | 56 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 468 | `textsnapshot_text_order` | 1 | 14.6s | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [62](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 469 | `this_scoping` | 52 | 14.4s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 470 | `this_swf5` | 41 | 14.3s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 471 | `this_swf6` | 41 | 14.7s | [63](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 472 | `this_swf7` | 41 | 14.8s | [64](ruffle-tests/_investigation/complete/this_swf7.md) |
| 473 | `timeline_function_def` | 7 | 14.9s |  |
| 474 | `timer_run_actions` | 18 | 14.9s | [65](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 475 | `trace` | 8 | 14.6s |  |
| 476 | `transform` | 70 | 14.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 477 | `try_catch_finally` | 118 | 14.8s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 478 | `try_finally_simple` | 16 | 14.6s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 479 | `typeof` | 22 | 14.8s |  |
| 480 | `typeof_globals` | 7 | 14.6s |  |
| 481 | `uncaught_exception` | 1 | 14.9s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 482 | `uncaught_exception_bubbled` | 1 | 14.8s | [66](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 483 | `undefined_to_string_swf6` | 4 | 14.7s |  |
| 484 | `unescape` | 43 | 14.8s |  |
| 485 | `unload` | 52 | 15.1s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 486 | `unload_clip_event` | 4 | 15.3s | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 487 | `unloadmovie` | 4 | 17.9s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 488 | `unloadmovie_method` | 3 | 17.4s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 489 | `unloadmovienum` | 13 | 17.6s | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 490 | `use_hand_cursor` | 8 | 16.6s |  |
| 491 | `variable_args` | 5 | 16.5s |  |
| 492 | `waitforframe` | 7 | 15.7s |  |
| 493 | `waitforframe2` | 16 | 16.2s |  |
| 494 | `watch` | 117 | 15.2s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 495 | `watch_textfield` | 12 | 14.8s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 496 | `watch_virtual_property_proto` | 2 | 15.0s | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 497 | `with` | 49 | 14.9s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 498 | `with_return` | 2 | 14.8s |  |
| 499 | `with_variable_scopes` | 43 | 15.0s | [70](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 500 | `xml` | 15 | 15.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 501 | `xml_append_child` | 28 | 14.8s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 502 | `xml_append_child_with_parent` | 20 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 503 | `xml_cdata` | 11 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 504 | `xml_child_nodes_edge_cases` | 4 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 505 | `xml_clone_expandos` | 19 | 15.0s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 506 | `xml_first_last_child` | 8 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 507 | `xml_has_child_nodes` | 3 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 508 | `xml_idmap` | 21 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 509 | `xml_ignore_comments` | 21 | 14.9s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 510 | `xml_ignore_white` | 34 | 14.6s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 511 | `xml_insert_before` | 20 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 512 | `xml_inspect_createmethods` | 15 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 513 | `xml_inspect_doctype` | 7 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 514 | `xml_inspect_parsexml` | 62 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 515 | `xml_inspect_xmldecl` | 7 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 516 | `xml_namespaces` | 203 | 14.7s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 517 | `xml_parent_and_child` | 5 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 518 | `xml_remove_node` | 22 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 519 | `xml_reparenting` | 14 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 520 | `xml_siblings` | 10 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 521 | `xml_to_string` | 13 | 14.3s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 522 | `xml_to_string_comment` | 1 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 523 | `xml_unescaping` | 23 | 14.5s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 524 | `xmlnode_proto` | 1 | 14.2s | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**19 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `global_swf5_6_7_8_9` | 99.3% | 1137 | 1145 | 8 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 2 | `edittext_html_swf6` | 98.4% | 5289 | 5377 | 88 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `lessthan2_swf6` | 98.0% | 1201 | 1226 | 25 |  |
| 4 | `greater_swf6` | 97.9% | 1150 | 1175 | 25 |  |
| 5 | `lessthan2_swf7` | 96.2% | 1179 | 1226 | 47 |  |
| 6 | `greater_swf7` | 96.0% | 1128 | 1175 | 47 |  |
| 7 | `lessthan_swf4` | 95.3% | 860 | 902 | 42 |  |
| 8 | `movieclip_hittest_shapeflag` | 90.5% | 306 | 338 | 32 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_invalid_get_bounds_6` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_7` | 90.0% | 9 | 10 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `equals_swf4` | 89.9% | 598 | 665 | 67 |  |
| 12 | `edittext_bullet` | 86.7% | 26 | 30 | 4 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `global_is_bare` | 85.7% | 6 | 7 | 1 |  |
| 14 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 15 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `coerce_to_object_monkeypatch` | 57.0% | 77 | 135 | 58 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 18 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 19 | `issue_2030` | 50.0% | 2 | 4 | 2 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**43 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `global_swf5_6_7_8_9` | 99.3% | 1137/1145 | 1145 | 1145 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) |
| 2 | `edittext_html_swf6` | 98.4% | 5289/5377 | 5377 | 5377 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `lessthan2_swf6` | 98.0% | 1201/1226 | 1226 | 1226 |  |
| 4 | `greater_swf6` | 97.9% | 1150/1175 | 1175 | 1175 |  |
| 5 | `lessthan2_swf7` | 96.2% | 1179/1226 | 1226 | 1226 |  |
| 6 | `greater_swf7` | 96.0% | 1128/1175 | 1175 | 1175 |  |
| 7 | `lessthan_swf4` | 95.3% | 860/902 | 902 | 902 |  |
| 8 | `movieclip_hittest_shapeflag` | 90.5% | 306/338 | 338 | 338 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 9 | `movieclip_invalid_get_bounds_6` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 10 | `movieclip_invalid_get_bounds_7` | 90.0% | 9/10 | 10 | 10 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 11 | `equals_swf4` | 89.9% | 598/665 | 665 | 665 |  |
| 12 | `edittext_bullet` | 86.7% | 26/30 | 30 | 30 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `global_is_bare` | 85.7% | 6/7 | 7 | 7 |  |
| 14 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 15 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `coerce_to_object_monkeypatch` | 57.0% | 77/135 | 135 | 129 | [67](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 18 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 | [59](ruffle-tests/_investigation/incomplete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 19 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 20 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 | [28](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) |
| 21 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 22 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [32](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 25 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [42](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 26 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 27 | `global_instance_decls` | 1.6% | 12/758 | 492 | 758 | [22](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 28 | `global_proto_decls` | 0.3% | 15/4497 | 817 | 4497 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 29 | `global_proto_decls_delete` | 0.0% | 1/4158 | 370 | 4158 | [24](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 30 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [21](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 31 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 32 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 33 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [61](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 34 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [19](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 35 | `geturl` | 0.0% | 0/7 | 0 | 7 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [25](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 37 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 38 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [31](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 39 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 40 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [55](ruffle-tests/_investigation/complete/STRING_PLAN.md) [60](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 41 | `string_paths_timer` | 0.0% | 0/41 | 41 | 0 | [68](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 42 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [71](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 43 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [38](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [69](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |

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
| 19 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 6 | 1 |
| 20 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 21 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 22 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 5 | 4 | 1 |
| 23 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 24 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 29 | 25 | 4 |
| 25 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 12 | 5 |
| 26 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/incomplete/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 27 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 28 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/incomplete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 0 | 1 |
| 29 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 30 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 31 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 44 | 39 | 5 |
| 32 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/incomplete/LOADMOVIE_REMAINING_PLAN.md) | 4 | 3 | 1 |
| 33 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 34 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 35 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 36 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 37 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 38 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 56 | 47 | 9 |
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
| | *(tests not in any document)* | 157 | 150 | 7 |
