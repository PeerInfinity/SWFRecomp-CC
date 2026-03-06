# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-06 17:44 UTC

**Git SHA**: `378a0f9dd0`

**Run Duration**: 140m 45s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **480** (77.5%) |
| Failing | 139 |
| Total expected lines | 91137 |
| Matching lines | 70941 (77.8%) |
| Mismatched lines | 20196 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 129 | 92.8% |
| Runtime Segfault | 5 | 3.6% |
| Compile Fail | 2 | 1.4% |
| Runtime Error | 2 | 1.4% |
| Timeout | 1 | 0.7% |

## Passing Tests

**480 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.3s |  |
| 2 | `action_to_integer` | 28 | 13.1s |  |
| 3 | `add` | 28 | 13.3s |  |
| 4 | `add2` | 354 | 13.9s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 13.6s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 13.9s |  |
| 7 | `add_swf5` | 28 | 13.8s |  |
| 8 | `arguments` | 127 | 13.9s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 13.8s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 13.6s |  |
| 11 | `array_constructor` | 30 | 13.6s |  |
| 12 | `array_enumerate` | 4 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 13.5s |  |
| 14 | `array_properties` | 36 | 13.3s |  |
| 15 | `array_prototyping` | 12 | 13.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 13.5s |  |
| 17 | `array_sort` | 161 | 14.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 13.5s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 13.4s |  |
| 20 | `array_trivial` | 209 | 13.2s |  |
| 21 | `as1_constructor_v6` | 35 | 13.4s |  |
| 22 | `as1_constructor_v7` | 35 | 13.5s |  |
| 23 | `as2_oop` | 13 | 13.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 13.4s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 13.4s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 13.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 13.4s |  |
| 29 | `as_broadcaster_undef` | 89 | 13.4s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 13.1s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 13.1s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 13.1s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 13.3s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 13.2s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 13.1s |  |
| 37 | `as_transformed_flag` | 20 | 13.3s |  |
| 38 | `asnative` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 13.2s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 13.2s |  |
| 44 | `bitand` | 1058 | 15.7s |  |
| 45 | `bitmap_data_colortransform` | 0 | 13.5s |  |
| 46 | `bitmap_data_fillrect` | 0 | 13.4s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 13.1s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 13.3s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 14.1s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 13.5s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.4s |  |
| 52 | `bitor` | 1058 | 16.1s |  |
| 53 | `biturshift` | 14 | 14.2s |  |
| 54 | `biturshift_swf8` | 14 | 13.6s |  |
| 55 | `bitxor` | 1058 | 16.1s |  |
| 56 | `boxed_primitives` | 24 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 13.6s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 13.4s |  |
| 71 | `capabilities_resolution` | 8 | 13.3s |  |
| 72 | `catch_references_registers` | 2 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 13.3s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 13.6s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 13.3s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 13.5s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `color` | 57 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 13.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 13.4s |  |
| 81 | `constructor_function` | 2 | 13.3s |  |
| 82 | `context_menu` | 39 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `define_function2` | 8 | 13.3s |  |
| 86 | `define_function2_preload` | 13 | 13.2s |  |
| 87 | `define_function2_preload_order` | 4 | 13.6s |  |
| 88 | `define_function_case_sensitive` | 2 | 13.3s |  |
| 89 | `delete` | 3 | 13.3s |  |
| 90 | `device_font_spacing` | 91 | 13.4s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 91 | `display_object_properties` | 2 | 13.2s |  |
| 92 | `divide_swf4` | 107 | 13.5s |  |
| 93 | `do_init_action` | 3 | 13.4s |  |
| 94 | `do_init_action_child` | 12 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 95 | `drag_drop` | 10 | 13.4s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 96 | `drag_over_from_outside` | 1 | 13.3s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 97 | `drag_over_without_startdrag` | 1 | 13.3s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 98 | `duplicate_movie_clip` | 20 | 13.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 99 | `edittext_align` | 60 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_align_trailing_spaces_swf7` | 576 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_align_trailing_spaces_swf8` | 576 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_antialiastype` | 296 | 14.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_autosize` | 71 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_autosize_setter` | 20 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_default_format` | 221 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_default_format_font_style` | 335 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_font_size` | 45 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_hscroll` | 27 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_align_swf7` | 52 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_html_align_swf8` | 52 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_color` | 114 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_entity` | 4 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_html_roundtrip` | 17 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_html_swf7` | 5377 | 14.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_html_swf8` | 5377 | 14.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_input` | 1 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_leading` | 9 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_letter_spacing` | 15 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_margins` | 25 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_newline_stripping` | 64 | 18.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_password` | 5 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_password_copy` | 4 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_paste_empty` | 2 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_programmatic_focus` | 12 | 13.0s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_restrict` | 191 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_restrict_paste` | 5 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_stylesheet` | 325 | 13.5s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_tag_indent` | 31 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `edittext_text_height_leading` | 20 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 130 | `edittext_underline` | 40 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 131 | `edittext_width_height` | 103 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 132 | `empty_movieclip_can_attach_movies` | 11 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 133 | `enumerate` | 64 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 134 | `equals` | 32 | 13.1s |  |
| 135 | `equals2_swf5` | 926 | 14.9s |  |
| 136 | `equals2_swf6` | 926 | 15.1s |  |
| 137 | `equals2_swf7` | 926 | 15.3s |  |
| 138 | `equals_swf4` | 665 | 14.6s |  |
| 139 | `equals_swf4_alt` | 32 | 13.7s |  |
| 140 | `equals_swf5` | 32 | 13.7s |  |
| 141 | `error` | 58 | 13.7s |  |
| 142 | `escape` | 14 | 13.7s |  |
| 143 | `execution_order1` | 5 | 13.7s |  |
| 144 | `execution_order2` | 7 | 13.7s |  |
| 145 | `execution_order3` | 4 | 13.7s |  |
| 146 | `execution_order4` | 12 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 147 | `export_assets` | 3 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 148 | `extends_chain` | 134 | 14.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 149 | `extends_native_type` | 11 | 13.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 150 | `external_interface` | 84 | 14.0s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 151 | `external_interface_escapexml` | 26 | 13.5s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 152 | `external_interface_jsquotestring` | 21 | 13.3s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 153 | `external_interface_toas_basic` | 354 | 13.9s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 154 | `external_interface_toxml_array` | 25 | 13.8s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 155 | `external_interface_toxml_basic` | 179 | 13.8s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 156 | `external_interface_unescapexml` | 40 | 13.6s | [14](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 157 | `focus_mouse` | 45 | 13.6s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 158 | `focus_mouse_rollout` | 4 | 13.3s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 159 | `focus_root_movie` | 2 | 13.3s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 160 | `focusrect_focuslost` | 4 | 13.6s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 161 | `focusrect_mouse_swf8` | 0 | 13.3s |  |
| 162 | `focusrect_mouse_swf9` | 0 | 13.5s |  |
| 163 | `focusrect_swf5` | 6 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 164 | `focusrect_swf6` | 42 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 165 | `form_loader_encoding_1` | 1 | 13.5s |  |
| 166 | `frame_size_translated_negative` | 21 | 13.4s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 167 | `frame_size_translated_positive` | 21 | 13.5s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 168 | `function_as_function` | 35 | 13.4s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 169 | `function_base_clip` | 8 | 13.5s |  |
| 170 | `function_base_clip_readded` | 11 | 13.5s |  |
| 171 | `function_base_clip_removed` | 25 | 13.5s |  |
| 172 | `function_suppress_and_preload` | 28 | 13.5s |  |
| 173 | `funky_function_calls` | 56 | 13.5s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 174 | `get_bytes_total` | 4 | 13.3s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 175 | `get_variable_in_scope` | 29 | 13.4s |  |
| 176 | `getproperty` | 28 | 13.4s |  |
| 177 | `getproperty_swf4` | 28 | 13.3s |  |
| 178 | `getproperty_swf5` | 28 | 13.4s |  |
| 179 | `gettextextent` | 56 | 13.4s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 180 | `global_array` | 3 | 13.4s |  |
| 181 | `global_is_bare` | 7 | 13.4s |  |
| 182 | `global_swf6_7_8` | 15 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 183 | `globals_swf5` | 304 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 184 | `globals_swf6` | 304 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 185 | `globals_swf7` | 304 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 186 | `globals_swf8` | 304 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 187 | `goto_advance1` | 6 | 13.3s |  |
| 188 | `goto_advance2` | 2 | 13.4s |  |
| 189 | `goto_both_ways1` | 3 | 13.5s |  |
| 190 | `goto_both_ways2` | 3 | 13.2s |  |
| 191 | `goto_execution_order` | 2 | 13.2s |  |
| 192 | `goto_execution_order2` | 2 | 13.1s |  |
| 193 | `goto_frame` | 12 | 13.2s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 194 | `goto_frame2` | 44 | 13.4s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 195 | `goto_frame_number` | 3 | 13.0s |  |
| 196 | `goto_label` | 17 | 13.7s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 197 | `goto_methods` | 40 | 13.2s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 198 | `goto_rewind1` | 1 | 13.3s |  |
| 199 | `goto_rewind2` | 3 | 13.2s |  |
| 200 | `goto_rewind3` | 2 | 13.2s |  |
| 201 | `greater_swf6` | 1175 | 15.1s |  |
| 202 | `greater_swf7` | 1175 | 15.1s |  |
| 203 | `greaterthan_swf5` | 1 | 13.3s |  |
| 204 | `greaterthan_swf8` | 1 | 13.1s |  |
| 205 | `has_own_property` | 32 | 13.3s |  |
| 206 | `hittest_lockroot` | 15 | 13.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 207 | `hittest_morph` | 70 | 13.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 208 | `hittest_winding_rule` | 12 | 13.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 209 | `infinite_recursion_function` | 4 | 13.2s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 210 | `infinite_recursion_function_in_setter` | 131 | 13.2s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 211 | `infinite_recursion_virtual_property` | 67 | 13.1s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 212 | `init_array_invalid` | 4 | 13.0s |  |
| 213 | `init_object_invalid` | 4 | 13.1s |  |
| 214 | `init_object_order` | 15 | 13.2s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 215 | `instanceof_coercions` | 88 | 13.9s | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 216 | `interface_implements_op` | 47 | 14.2s | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 217 | `is_finite` | 49 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 218 | `is_finite_swf6` | 49 | 13.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 219 | `is_prototype_of` | 89 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 220 | `issue_1086` | 1 | 13.6s |  |
| 221 | `issue_1104` | 2 | 13.7s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 222 | `issue_1671` | 0 | 13.7s |  |
| 223 | `issue_1906` | 4 | 13.6s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 224 | `issue_2166` | 9 | 13.6s |  |
| 225 | `issue_3169` | 2 | 13.6s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 226 | `issue_3446` | 1 | 13.5s |  |
| 227 | `issue_3522` | 2 | 13.2s |  |
| 228 | `issue_4377` | 2 | 13.0s |  |
| 229 | `issue_710` | 4 | 13.0s |  |
| 230 | `issue_768` | 3 | 13.1s | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 231 | `issue_9327` | 2 | 13.2s |  |
| 232 | `issue_9885` | 2 | 13.1s |  |
| 233 | `key_isToggled` | 9 | 13.1s |  |
| 234 | `lessthan` | 41 | 13.2s |  |
| 235 | `lessthan2_swf5` | 1226 | 15.2s |  |
| 236 | `lessthan2_swf6` | 1226 | 15.2s |  |
| 237 | `lessthan2_swf7` | 1226 | 15.2s |  |
| 238 | `lessthan_swf4` | 902 | 14.3s |  |
| 239 | `lessthan_swf4_alt` | 41 | 13.1s |  |
| 240 | `lessthan_swf5` | 41 | 13.2s |  |
| 241 | `loadmovie` | 2 | 13.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 242 | `loadmovie_fail` | 2 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 243 | `loadmovie_flashvars` | 4 | 13.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 244 | `loadmovie_method` | 2 | 13.5s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 245 | `loadmovie_replace_root` | 5 | 13.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 246 | `loadmovienum` | 3 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 247 | `loadvariables` | 2 | 13.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 248 | `loadvariables2` | 8 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 249 | `loadvariablesnum` | 2 | 13.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 250 | `local_to_global` | 49 | 13.6s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 251 | `localconnection_properties` | 8 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 252 | `lock_root` | 1 | 13.4s |  |
| 253 | `logical_ops_swf4` | 90 | 14.1s |  |
| 254 | `logical_ops_swf8` | 108 | 14.0s |  |
| 255 | `looping` | 6 | 14.1s |  |
| 256 | `mask_reapply` | 0 | 14.1s |  |
| 257 | `mask_with_drawing` | 0 | 13.5s |  |
| 258 | `math_min_max` | 101 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 259 | `math_swf6` | 530 | 13.9s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 260 | `math_swf7` | 530 | 14.2s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 261 | `math_swf8` | 530 | 14.1s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 262 | `matrix` | 171 | 13.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 263 | `mcl_as_broadcaster` | 12 | 13.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 264 | `mcl_getprogress` | 30 | 13.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 265 | `mcl_loadclip` | 149 | 13.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 266 | `mcl_loadclip_properties` | 6 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 267 | `mcl_mislabeled_target` | 6 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 268 | `mcl_target_gif87a` | 6 | 13.7s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 269 | `mcl_target_gif89a` | 6 | 13.6s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 270 | `mcl_target_jpg` | 6 | 13.7s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 271 | `mcl_target_png` | 6 | 14.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 272 | `mcl_unloadclip` | 5 | 14.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 273 | `mouse_events` | 8 | 14.2s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 274 | `mouse_events_visible_enabled` | 12 | 14.0s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 275 | `mouse_hover_events_while_dragging` | 1 | 13.9s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 276 | `mouse_listeners` | 67 | 13.6s |  |
| 277 | `mouse_pos` | 665 | 13.4s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 278 | `mouse_pos_with_scale_factor` | 260 | 13.6s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 279 | `mouse_wheel_enabled` | 2 | 13.4s |  |
| 280 | `movieclip_begin_gradient_fill` | 0 | 13.9s |  |
| 281 | `movieclip_blend_mode_property` | 35 | 13.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 282 | `movieclip_create_text_field` | 90 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 283 | `movieclip_depth_methods` | 98 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 284 | `movieclip_focusenabled` | 99 | 13.2s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 285 | `movieclip_get_instance_at_depth` | 28 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 286 | `movieclip_hittest` | 92 | 13.3s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 287 | `movieclip_in_removed_button` | 4 | 13.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 288 | `movieclip_init_object` | 5 | 14.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 289 | `movieclip_line_gradient_style` | 0 | 13.3s |  |
| 290 | `movieclip_name_from_timeline` | 13 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 291 | `movieclip_prototype_extension` | 5 | 13.0s |  |
| 292 | `moviecliploader_flashvars` | 4 | 13.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 293 | `mutable_this` | 18 | 13.5s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 294 | `named_shapes` | 14 | 13.3s |  |
| 295 | `nan_scale` | 9 | 13.2s |  |
| 296 | `native_double_construct` | 12 | 13.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 297 | `native_objects_swf7` | 84 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 298 | `native_objects_swf8` | 84 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 299 | `nested_textfields_in_buttons` | 0 | 13.4s |  |
| 300 | `new_method_wrap` | 4 | 13.0s |  |
| 301 | `new_object_enumerate` | 7 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 302 | `new_object_wrap` | 4 | 13.0s |  |
| 303 | `o` | 3 | 13.0s |  |
| 304 | `object_constructor` | 33 | 13.0s |  |
| 305 | `object_function` | 32 | 13.0s |  |
| 306 | `object_properties` | 31 | 13.1s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 307 | `object_prototypes` | 74 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 308 | `object_resolve` | 38 | 13.1s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 309 | `object_string_coerce_swf5` | 62 | 13.1s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 310 | `object_string_coerce_swf6` | 68 | 13.1s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 311 | `on_construct` | 25 | 13.4s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 312 | `parse_float` | 74 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 313 | `parse_int` | 64 | 14.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 314 | `path_string` | 322 | 13.8s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 315 | `place_and_lookup` | 30 | 13.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 316 | `placeobject_occupied_depth` | 6 | 14.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 317 | `point` | 175 | 14.5s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 318 | `primitive_instanceof` | 37 | 13.3s |  |
| 319 | `primitive_type_globals` | 557 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 320 | `printjob_props_swf5` | 45 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 321 | `printjob_props_swf6` | 45 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 322 | `printjob_props_swf7` | 45 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 323 | `property_invalid_base_clip` | 36 | 13.3s |  |
| 324 | `prototype_delete` | 12 | 13.1s |  |
| 325 | `prototype_enumerate` | 5 | 13.0s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 326 | `prototype_properties` | 17 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 327 | `rectangle` | 745 | 14.0s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 328 | `recursive_prototypes` | 0 | 13.1s |  |
| 329 | `register_class_return_value` | 16 | 13.2s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 330 | `register_class_with_sound` | 11 | 13.3s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 331 | `register_globals_across_frames` | 15 | 14.2s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 332 | `register_underflow` | 26 | 13.3s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 333 | `remove_movie_clip` | 29 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 334 | `rewind_depth` | 30 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 335 | `root_global_parent` | 6 | 13.9s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 336 | `sandbox_type_local_file` | 1 | 14.0s |  |
| 337 | `sandbox_type_local_network` | 1 | 13.9s |  |
| 338 | `selection` | 454 | 13.9s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 339 | `set_interval` | 27 | 13.8s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 340 | `set_variable_scope` | 58 | 13.5s |  |
| 341 | `single_frame` | 1 | 13.6s |  |
| 342 | `slash_syntax` | 14 | 13.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 343 | `sound` | 628 | 13.9s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 344 | `sound_props_swf5` | 68 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 345 | `sound_props_swf6` | 68 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 346 | `sound_start_load` | 0 | 13.4s |  |
| 347 | `stage_display_state` | 16 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 348 | `stage_object_children` | 83 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 349 | `stage_object_enumerate` | 4 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 350 | `stage_object_properties` | 241 | 13.5s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 351 | `stage_object_properties_get_var` | 5 | 13.2s |  |
| 352 | `stage_object_properties_swf6` | 231 | 13.4s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 353 | `stage_property_representation` | 586 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 354 | `stage_scale_mode` | 39 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 355 | `strictequals_swf6` | 902 | 14.8s |  |
| 356 | `strictly_equals` | 7 | 13.2s |  |
| 357 | `string_coercion` | 117 | 13.5s | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 358 | `string_methods` | 285 | 13.7s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 359 | `string_methods_negative_args` | 240 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 360 | `string_methods_swfv5` | 275 | 13.7s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 361 | `string_ops_swf6` | 95 | 13.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 362 | `string_paths_basic` | 4 | 13.4s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 363 | `string_paths_eval2` | 7 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 364 | `string_paths_hidden` | 54 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 365 | `string_paths_other` | 36 | 13.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 366 | `string_paths_unload` | 1 | 13.2s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 367 | `string_paths_variable_alias` | 4 | 13.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 368 | `string_paths_variable_scopes` | 5 | 13.1s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 369 | `stylesheet` | 283 | 13.8s |  |
| 370 | `stylesheet_transform` | 750 | 13.7s |  |
| 371 | `super_edge_cases` | 39 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 372 | `swf4_actions_bool` | 96 | 13.2s |  |
| 373 | `swf4_actions_coercion_order` | 158 | 13.4s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 374 | `swf4_bool` | 4 | 13.2s |  |
| 375 | `swf4_function_calls` | 7 | 13.3s |  |
| 376 | `swf5_encoding` | 3 | 13.1s |  |
| 377 | `swf5_global_funcs` | 232 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 378 | `swf5_no_closure` | 19 | 13.1s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 379 | `swf6_case_insensitive` | 42 | 13.1s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 380 | `swf6_global_funcs` | 232 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 381 | `swf6_string_as_bool` | 15 | 13.0s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 382 | `swf7_case_sensitive` | 44 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 383 | `swf7_global_funcs` | 232 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 384 | `tab_ordering_automatic_basic` | 92 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 385 | `tab_ordering_automatic_order_grid` | 21 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 386 | `tab_ordering_automatic_order_same_position` | 12 | 13.3s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 387 | `tab_ordering_children` | 208 | 13.3s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 388 | `tab_ordering_custom_basic` | 71 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 389 | `tab_ordering_custom_duplicate_index` | 22 | 13.4s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 390 | `tab_ordering_custom_i32_vs_u32` | 12 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 391 | `tab_ordering_custom_m1` | 29 | 13.1s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 392 | `tab_ordering_events` | 150 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 393 | `tab_ordering_movieclip_enabled_default` | 462 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 394 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.2s |  |
| 395 | `tab_ordering_reverse` | 51 | 13.3s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 396 | `tab_ordering_tabbable` | 47 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 397 | `target_clip_swf5` | 2 | 13.1s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 398 | `target_clip_swf6` | 2 | 13.2s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 399 | `target_path` | 14 | 13.2s |  |
| 400 | `tell_target` | 37 | 13.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 401 | `tell_target_invalid` | 6 | 13.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 402 | `tell_target_invalid_swf6` | 5 | 13.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 403 | `text_format` | 1146 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 404 | `text_format_display` | 21 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 405 | `text_format_font_max_length` | 2 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 406 | `text_format_rounding_swf7` | 840 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 407 | `text_format_rounding_swf8` | 840 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 408 | `textfield_background_color` | 11 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 409 | `textfield_border_color` | 11 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 410 | `textfield_cache_as_bitmap` | 1 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 411 | `textfield_maxchars` | 3 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 412 | `textfield_properties` | 44 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 413 | `textfield_props_swf5` | 175 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 414 | `textfield_props_swf6` | 210 | 13.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 415 | `textfield_props_swf7` | 210 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 416 | `textfield_props_swf8` | 210 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 417 | `textfield_text` | 7 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 418 | `textfield_variable` | 81 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 419 | `textsnapshot_available_text` | 20 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 420 | `textsnapshot_findtext` | 44 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 421 | `textsnapshot_gettext` | 55 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 422 | `textsnapshot_props_swf5` | 56 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 423 | `textsnapshot_props_swf6` | 56 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 424 | `textsnapshot_text_order` | 1 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 425 | `this_scoping` | 52 | 14.0s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 426 | `this_swf5` | 41 | 13.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 427 | `this_swf6` | 41 | 14.1s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 428 | `this_swf7` | 41 | 13.8s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 429 | `timeline_function_def` | 7 | 13.7s |  |
| 430 | `trace` | 8 | 13.3s |  |
| 431 | `transform` | 70 | 13.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 432 | `try_catch_finally` | 118 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 433 | `try_finally_simple` | 16 | 13.0s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 434 | `typeof` | 22 | 12.9s |  |
| 435 | `typeof_globals` | 7 | 13.0s |  |
| 436 | `uncaught_exception` | 1 | 13.0s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 437 | `uncaught_exception_bubbled` | 1 | 13.0s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 438 | `undefined_to_string_swf6` | 4 | 13.0s |  |
| 439 | `unescape` | 43 | 13.0s |  |
| 440 | `unload` | 52 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 441 | `unload_clip_event` | 4 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 442 | `unloadmovie` | 4 | 13.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 443 | `unloadmovie_method` | 3 | 13.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 444 | `unloadmovienum` | 13 | 13.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 445 | `use_hand_cursor` | 8 | 13.0s |  |
| 446 | `variable_args` | 5 | 13.0s |  |
| 447 | `waitforframe` | 7 | 12.9s |  |
| 448 | `waitforframe2` | 16 | 13.0s |  |
| 449 | `watch` | 117 | 13.3s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 450 | `watch_textfield` | 12 | 12.9s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 451 | `watch_virtual_property_proto` | 2 | 13.0s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 452 | `with` | 49 | 13.1s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 453 | `with_return` | 2 | 13.0s |  |
| 454 | `with_variable_scopes` | 43 | 13.1s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 455 | `xml` | 15 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 456 | `xml_append_child` | 28 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 457 | `xml_append_child_with_parent` | 20 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 458 | `xml_attributes_read` | 4 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 459 | `xml_cdata` | 11 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 460 | `xml_child_nodes_edge_cases` | 4 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 461 | `xml_clone_expandos` | 19 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 462 | `xml_first_last_child` | 8 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 463 | `xml_has_child_nodes` | 3 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 464 | `xml_idmap` | 21 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 465 | `xml_ignore_comments` | 21 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 466 | `xml_ignore_white` | 34 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 467 | `xml_insert_before` | 20 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 468 | `xml_inspect_createmethods` | 15 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 469 | `xml_inspect_doctype` | 7 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 470 | `xml_inspect_parsexml` | 62 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 471 | `xml_inspect_xmldecl` | 7 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 472 | `xml_namespaces` | 203 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 473 | `xml_parent_and_child` | 5 | 12.9s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 474 | `xml_remove_node` | 22 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 475 | `xml_reparenting` | 14 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 476 | `xml_siblings` | 10 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 477 | `xml_to_string` | 13 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 478 | `xml_to_string_comment` | 1 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 479 | `xml_unescaping` | 23 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 480 | `xmlnode_proto` | 1 | 13.0s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**36 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `movieclip_library_state_values` | 98.7% | 77 | 78 | 1 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 10 | `edittext_html_condensewhite_swf8` | 92.6% | 288 | 311 | 23 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 17 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `loadmovie_var_persistence` | 62.5% | 5 | 8 | 3 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 22 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 25 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 26 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 27 | `register_class` | 57.6% | 38 | 66 | 28 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 28 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 29 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 30 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 31 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 32 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 33 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 35 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 36 | `issue_2030` | 50.0% | 2 | 4 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 16.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `edittext_ime_focus_lost` | 15.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `netstream_play_flv_screen` | 28.6s |  |
| 4 | `string_paths_timer` | 15.1s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 5 | `timer_run_actions` | 15.1s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 37.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 23.3s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**129 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `movieclip_library_state_values` | 98.7% | 77/78 | 78 | 78 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 6 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 9 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 10 | `edittext_html_condensewhite_swf8` | 92.6% | 288/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 11 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 12 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 13 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 14 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 15 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 17 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 20 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 21 | `loadmovie_var_persistence` | 62.5% | 5/8 | 5 | 8 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 22 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 23 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 25 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 26 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 27 | `register_class` | 57.6% | 38/66 | 47 | 66 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 28 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 29 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 30 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 31 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 32 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 33 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 34 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 35 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 36 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 37 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 38 | `coerce_to_object_monkeypatch` | 47.4% | 64/135 | 135 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 39 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 40 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 41 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 42 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 43 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 44 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 45 | `loadmovienum_cross_version_prototype` | 40.0% | 6/15 | 15 | 9 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 46 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 47 | `swf5_to_6_cross_call` | 37.9% | 11/29 | 11 | 29 | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 48 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 49 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 50 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 51 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 52 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 53 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 54 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 55 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 56 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 57 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 58 | `default_names` | 28.8% | 15/52 | 48 | 52 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 59 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 60 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 61 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 62 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 63 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 64 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 65 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 66 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 67 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 68 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 69 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 70 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 71 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 72 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 73 | `mcl_events_swf_version` | 14.2% | 33/232 | 37 | 232 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 74 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 75 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 76 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 77 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 78 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 79 | `define_local` | 7.4% | 2/27 | 23 | 27 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 80 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 81 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 82 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 83 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 84 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 86 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 87 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 88 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 89 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 90 | `native_subclasses` | 4.1% | 9/221 | 221 | 191 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 91 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 92 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 93 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 94 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 95 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 96 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 97 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 98 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 99 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 100 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 101 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 102 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 103 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 104 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 105 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 107 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 108 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 109 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 110 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 111 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 112 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 113 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 114 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 115 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 116 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 117 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 118 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 119 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 120 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 121 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 122 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 123 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 124 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 125 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 126 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 127 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 128 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 129 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 10 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 11 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 12 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 13 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 14 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 15 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 5 | 2 |
| 16 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 17 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 18 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 19 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 25 | 6 |
| 20 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 21 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 22 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 23 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 25 | 24 |
| 24 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 25 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 26 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 27 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 28 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 29 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
| 30 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
| 31 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 32 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 33 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 34 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 35 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 36 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 37 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 38 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 39 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 40 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 41 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 42 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 43 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 44 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 45 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 46 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 47 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 14 | 2 |
| 48 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 49 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 56 | 14 |
| 50 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 51 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 52 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 53 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 54 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 55 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 1 | 1 |
| 56 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 5 | 11 |
| 57 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 58 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 59 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 195 | 156 | 39 |
