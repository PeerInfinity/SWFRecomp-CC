# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-06 03:19 UTC

**Git SHA**: `4eb4f907d6`

**Run Duration**: 139m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **466** (75.3%) |
| Failing | 153 |
| Total expected lines | 91475 |
| Matching lines | 70132 (76.7%) |
| Mismatched lines | 21343 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 144 | 94.1% |
| Runtime Segfault | 5 | 3.3% |
| Runtime Error | 2 | 1.3% |
| Timeout | 1 | 0.7% |
| Compile Fail | 1 | 0.7% |

## Passing Tests

**466 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 14.5s |  |
| 2 | `action_to_integer` | 28 | 13.3s |  |
| 3 | `add` | 28 | 13.3s |  |
| 4 | `add_property` | 15 | 13.4s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `add_swf4` | 28 | 13.3s |  |
| 6 | `add_swf5` | 28 | 13.4s |  |
| 7 | `arguments` | 127 | 13.2s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 13.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 13.5s |  |
| 10 | `array_constructor` | 30 | 13.4s |  |
| 11 | `array_enumerate` | 4 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 13.3s |  |
| 13 | `array_properties` | 36 | 13.3s |  |
| 14 | `array_prototyping` | 12 | 13.3s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 13.3s |  |
| 16 | `array_sort` | 161 | 14.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 17 | `array_sort_random` | 443 | 13.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_splice` | 207 | 13.4s |  |
| 19 | `array_trivial` | 209 | 13.5s |  |
| 20 | `as1_constructor_v6` | 35 | 13.3s |  |
| 21 | `as1_constructor_v7` | 35 | 13.3s |  |
| 22 | `as2_oop` | 13 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 23 | `as2_super_and_this_v6` | 97 | 13.6s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v8` | 85 | 13.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_via_manual_prototype` | 40 | 13.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as_broadcaster` | 41 | 13.3s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 27 | `as_broadcaster_initialize` | 10 | 13.3s |  |
| 28 | `as_broadcaster_undef` | 89 | 13.3s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 13.3s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 13.2s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 13.2s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 13.2s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 13.2s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 13.2s |  |
| 36 | `as_transformed_flag` | 20 | 13.3s |  |
| 37 | `asnative` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 13.3s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 13.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 13.6s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 13.3s |  |
| 43 | `bitand` | 1058 | 16.2s |  |
| 44 | `bitmap_data_colortransform` | 0 | 13.7s |  |
| 45 | `bitmap_data_fillrect` | 0 | 13.7s |  |
| 46 | `bitmap_data_max_size_swf10` | 12 | 13.4s |  |
| 47 | `bitmap_data_max_size_swf9` | 10 | 13.3s |  |
| 48 | `bitmap_data_perlinnoise` | 0 | 14.2s |  |
| 49 | `bitmap_data_pixeldissolve_image` | 0 | 13.8s |  |
| 50 | `bitmapdata_applyfilter_colormatrix` | 0 | 13.5s |  |
| 51 | `bitor` | 1058 | 16.1s |  |
| 52 | `biturshift` | 14 | 13.0s |  |
| 53 | `biturshift_swf8` | 14 | 12.8s |  |
| 54 | `bitxor` | 1058 | 15.4s |  |
| 55 | `boxed_primitives` | 24 | 13.5s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `button_children` | 8 | 13.6s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 57 | `button_goto` | 4 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_key_events` | 14 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events_special` | 45 | 14.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_keypress` | 3 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress_vs_press` | 25 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_tab` | 20 | 13.4s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_textinput` | 4 | 13.3s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_order` | 2 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_properties_special_cases` | 22 | 13.5s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_v5` | 18 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v6` | 18 | 13.2s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `call` | 63 | 13.4s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 69 | `call_method_empty_name` | 1 | 13.1s |  |
| 70 | `capabilities_resolution` | 8 | 12.9s |  |
| 71 | `catch_references_registers` | 2 | 12.8s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 72 | `click_block` | 5 | 12.9s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 73 | `clip_constructors` | 8 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 74 | `clip_events` | 19 | 13.2s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 75 | `clone_sprite_types` | 24 | 12.7s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 76 | `closure_scope` | 7 | 12.9s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 77 | `color` | 57 | 13.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 78 | `color_transform` | 48 | 12.9s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `conflicting_instance_names` | 23 | 12.9s |  |
| 80 | `constructor_function` | 2 | 12.8s |  |
| 81 | `context_menu` | 39 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 82 | `context_menu_item` | 41 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `create_empty_movie_clip` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 84 | `define_function2` | 8 | 12.7s |  |
| 85 | `define_function2_preload` | 13 | 12.8s |  |
| 86 | `define_function2_preload_order` | 4 | 12.8s |  |
| 87 | `define_function_case_sensitive` | 2 | 12.8s |  |
| 88 | `delete` | 3 | 12.9s |  |
| 89 | `display_object_properties` | 2 | 12.7s |  |
| 90 | `divide_swf4` | 107 | 12.8s |  |
| 91 | `do_init_action` | 3 | 12.8s |  |
| 92 | `do_init_action_child` | 12 | 13.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 93 | `drag_drop` | 10 | 12.8s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 94 | `drag_over_from_outside` | 1 | 12.8s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 95 | `drag_over_without_startdrag` | 1 | 12.9s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 96 | `edittext_align` | 60 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 97 | `edittext_align_trailing_spaces_swf7` | 576 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 98 | `edittext_align_trailing_spaces_swf8` | 576 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 99 | `edittext_antialiastype` | 296 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_autosize` | 71 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_autosize_setter` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_default_format` | 221 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_default_format_font_style` | 335 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_font_size` | 45 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_hscroll` | 27 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_align_swf7` | 52 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_align_swf8` | 52 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_color` | 114 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_entity` | 4 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_html_roundtrip` | 17 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_html_swf7` | 5377 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_html_swf8` | 5377 | 13.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_input` | 1 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_leading` | 9 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_letter_spacing` | 15 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_margins` | 25 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_newline_stripping` | 64 | 17.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_password` | 5 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_password_copy` | 4 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_paste_empty` | 2 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_programmatic_focus` | 12 | 12.8s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_restrict` | 191 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `edittext_restrict_paste` | 5 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 124 | `edittext_stylesheet` | 325 | 13.5s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 125 | `edittext_tag_indent` | 31 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 126 | `edittext_text_height_leading` | 20 | 13.2s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 127 | `edittext_underline` | 40 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 128 | `edittext_width_height` | 103 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 129 | `empty_movieclip_can_attach_movies` | 11 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 130 | `enumerate` | 64 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 131 | `equals` | 32 | 13.1s |  |
| 132 | `equals2_swf5` | 926 | 14.8s |  |
| 133 | `equals2_swf6` | 926 | 14.6s |  |
| 134 | `equals2_swf7` | 926 | 14.5s |  |
| 135 | `equals_swf4` | 665 | 13.6s |  |
| 136 | `equals_swf4_alt` | 32 | 12.9s |  |
| 137 | `equals_swf5` | 32 | 12.8s |  |
| 138 | `error` | 58 | 12.9s |  |
| 139 | `escape` | 14 | 12.8s |  |
| 140 | `execution_order1` | 5 | 12.9s |  |
| 141 | `execution_order2` | 7 | 12.8s |  |
| 142 | `execution_order3` | 4 | 12.8s |  |
| 143 | `execution_order4` | 12 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 144 | `export_assets` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 145 | `extends_chain` | 134 | 13.1s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 146 | `extends_native_type` | 11 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 147 | `external_interface_escapexml` | 26 | 12.9s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 148 | `external_interface_jsquotestring` | 21 | 12.8s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 149 | `external_interface_unescapexml` | 40 | 12.9s | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 150 | `focus_mouse` | 45 | 13.6s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 151 | `focus_mouse_rollout` | 4 | 13.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 152 | `focus_root_movie` | 2 | 12.8s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 153 | `focusrect_focuslost` | 4 | 13.3s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 154 | `focusrect_mouse_swf8` | 0 | 13.7s |  |
| 155 | `focusrect_mouse_swf9` | 0 | 13.8s |  |
| 156 | `focusrect_swf5` | 6 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 157 | `focusrect_swf6` | 42 | 13.3s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 158 | `form_loader_encoding_1` | 1 | 13.2s |  |
| 159 | `frame_size_translated_negative` | 21 | 13.3s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 160 | `frame_size_translated_positive` | 21 | 13.0s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 161 | `function_as_function` | 35 | 12.9s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 162 | `function_base_clip` | 8 | 12.9s |  |
| 163 | `function_base_clip_removed` | 25 | 12.9s |  |
| 164 | `function_suppress_and_preload` | 28 | 12.9s |  |
| 165 | `get_bytes_total` | 4 | 12.9s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 166 | `get_variable_in_scope` | 29 | 13.0s |  |
| 167 | `getproperty` | 28 | 12.9s |  |
| 168 | `getproperty_swf4` | 28 | 13.0s |  |
| 169 | `getproperty_swf5` | 28 | 12.8s |  |
| 170 | `gettextextent` | 56 | 13.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 171 | `global_array` | 3 | 12.8s |  |
| 172 | `global_is_bare` | 7 | 12.9s |  |
| 173 | `global_swf6_7_8` | 15 | 13.4s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 174 | `globals_swf5` | 304 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 175 | `globals_swf6` | 304 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 176 | `globals_swf7` | 304 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 177 | `globals_swf8` | 304 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 178 | `goto_advance1` | 6 | 13.3s |  |
| 179 | `goto_advance2` | 2 | 13.6s |  |
| 180 | `goto_both_ways1` | 3 | 13.1s |  |
| 181 | `goto_both_ways2` | 3 | 12.7s |  |
| 182 | `goto_execution_order` | 2 | 12.6s |  |
| 183 | `goto_execution_order2` | 2 | 12.7s |  |
| 184 | `goto_frame` | 12 | 12.8s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 185 | `goto_frame2` | 44 | 13.2s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 186 | `goto_frame_number` | 3 | 12.9s |  |
| 187 | `goto_label` | 17 | 12.8s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 188 | `goto_methods` | 40 | 12.8s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 189 | `goto_rewind1` | 1 | 12.7s |  |
| 190 | `goto_rewind2` | 3 | 12.7s |  |
| 191 | `goto_rewind3` | 2 | 12.7s |  |
| 192 | `greater_swf6` | 1175 | 14.6s |  |
| 193 | `greater_swf7` | 1175 | 14.5s |  |
| 194 | `greaterthan_swf5` | 1 | 12.6s |  |
| 195 | `greaterthan_swf8` | 1 | 12.6s |  |
| 196 | `has_own_property` | 32 | 12.7s |  |
| 197 | `hittest_lockroot` | 15 | 12.8s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 198 | `hittest_morph` | 70 | 12.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 199 | `hittest_winding_rule` | 12 | 12.8s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 200 | `infinite_recursion_function` | 4 | 12.6s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 201 | `infinite_recursion_function_in_setter` | 131 | 12.7s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 202 | `infinite_recursion_virtual_property` | 67 | 12.6s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 203 | `init_array_invalid` | 4 | 12.6s |  |
| 204 | `init_object_invalid` | 4 | 12.6s |  |
| 205 | `init_object_order` | 15 | 12.8s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 206 | `is_finite` | 49 | 12.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 207 | `is_finite_swf6` | 49 | 12.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 208 | `is_prototype_of` | 89 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 209 | `issue_1086` | 1 | 12.6s |  |
| 210 | `issue_1104` | 2 | 12.6s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 211 | `issue_1671` | 0 | 12.6s |  |
| 212 | `issue_1906` | 4 | 12.7s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 213 | `issue_2166` | 9 | 12.6s |  |
| 214 | `issue_3169` | 2 | 12.7s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 215 | `issue_3446` | 1 | 12.6s |  |
| 216 | `issue_3522` | 2 | 12.6s |  |
| 217 | `issue_4377` | 2 | 12.6s |  |
| 218 | `issue_710` | 4 | 12.6s |  |
| 219 | `issue_768` | 3 | 12.6s | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 220 | `issue_9327` | 2 | 12.7s |  |
| 221 | `issue_9885` | 2 | 12.7s |  |
| 222 | `key_isToggled` | 9 | 12.7s |  |
| 223 | `lessthan` | 41 | 12.7s |  |
| 224 | `lessthan2_swf5` | 1226 | 14.7s |  |
| 225 | `lessthan2_swf6` | 1226 | 14.7s |  |
| 226 | `lessthan2_swf7` | 1226 | 14.7s |  |
| 227 | `lessthan_swf4` | 902 | 13.8s |  |
| 228 | `lessthan_swf4_alt` | 41 | 12.7s |  |
| 229 | `lessthan_swf5` | 41 | 12.7s |  |
| 230 | `loadmovie` | 2 | 12.7s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 231 | `loadmovie_fail` | 2 | 12.7s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 232 | `loadmovie_flashvars` | 4 | 12.7s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 233 | `loadmovie_method` | 2 | 14.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 234 | `loadmovie_replace_root` | 5 | 14.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 235 | `loadmovienum` | 3 | 14.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 236 | `loadvariables` | 2 | 13.8s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 237 | `loadvariables2` | 8 | 13.6s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 238 | `loadvariablesnum` | 2 | 13.6s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 239 | `local_to_global` | 49 | 14.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 240 | `localconnection_properties` | 8 | 13.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 241 | `lock_root` | 1 | 13.7s |  |
| 242 | `logical_ops_swf4` | 90 | 13.6s |  |
| 243 | `logical_ops_swf8` | 108 | 13.7s |  |
| 244 | `looping` | 6 | 13.8s |  |
| 245 | `mask_reapply` | 0 | 13.6s |  |
| 246 | `mask_with_drawing` | 0 | 13.5s |  |
| 247 | `math_min_max` | 101 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 248 | `math_swf6` | 530 | 14.1s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 249 | `math_swf7` | 530 | 13.9s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 250 | `math_swf8` | 530 | 13.4s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 251 | `matrix` | 171 | 13.5s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 252 | `mcl_as_broadcaster` | 12 | 13.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 253 | `mcl_loadclip_properties` | 6 | 13.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 254 | `mcl_mislabeled_target` | 6 | 13.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 255 | `mcl_target_gif87a` | 6 | 14.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 256 | `mcl_target_gif89a` | 6 | 14.5s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 257 | `mcl_target_jpg` | 6 | 13.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 258 | `mcl_target_png` | 6 | 14.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 259 | `mcl_unloadclip` | 5 | 14.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 260 | `mouse_events` | 8 | 13.6s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 261 | `mouse_events_visible_enabled` | 12 | 14.0s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 262 | `mouse_hover_events_while_dragging` | 1 | 14.2s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 263 | `mouse_listeners` | 67 | 13.7s |  |
| 264 | `mouse_pos` | 665 | 14.2s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 265 | `mouse_pos_with_scale_factor` | 260 | 14.0s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 266 | `mouse_wheel_enabled` | 2 | 13.8s |  |
| 267 | `movieclip_begin_gradient_fill` | 0 | 14.3s |  |
| 268 | `movieclip_blend_mode_property` | 35 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 269 | `movieclip_create_text_field` | 90 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 270 | `movieclip_default_state` | 69 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 271 | `movieclip_depth_methods` | 98 | 13.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 272 | `movieclip_focusenabled` | 99 | 13.7s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 273 | `movieclip_get_instance_at_depth` | 28 | 13.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 274 | `movieclip_hittest` | 92 | 13.7s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 275 | `movieclip_in_removed_button` | 4 | 13.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 276 | `movieclip_init_object` | 5 | 13.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 277 | `movieclip_line_gradient_style` | 0 | 13.9s |  |
| 278 | `movieclip_name_from_timeline` | 13 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 279 | `movieclip_prototype_extension` | 5 | 13.5s |  |
| 280 | `moviecliploader_flashvars` | 4 | 13.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `mutable_this` | 18 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 282 | `named_shapes` | 14 | 13.6s |  |
| 283 | `nan_scale` | 9 | 13.4s |  |
| 284 | `native_double_construct` | 12 | 13.2s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 285 | `native_objects_swf7` | 84 | 14.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 286 | `native_objects_swf8` | 84 | 14.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 287 | `native_subclasses` | 191 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 288 | `nested_textfields_in_buttons` | 0 | 13.3s |  |
| 289 | `new_method_wrap` | 4 | 13.3s |  |
| 290 | `new_object_enumerate` | 7 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 291 | `new_object_wrap` | 4 | 13.5s |  |
| 292 | `o` | 3 | 13.6s |  |
| 293 | `object_constructor` | 33 | 13.7s |  |
| 294 | `object_function` | 32 | 13.6s |  |
| 295 | `object_properties` | 31 | 13.8s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 296 | `object_prototypes` | 74 | 13.6s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 297 | `object_resolve` | 38 | 13.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 298 | `object_string_coerce_swf5` | 62 | 13.5s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 299 | `object_string_coerce_swf6` | 68 | 13.5s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 300 | `on_construct` | 25 | 13.5s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 301 | `parse_float` | 74 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 302 | `parse_int` | 64 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 303 | `place_and_lookup` | 30 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 304 | `placeobject_occupied_depth` | 6 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 305 | `point` | 175 | 13.9s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 306 | `primitive_instanceof` | 37 | 13.7s |  |
| 307 | `primitive_type_globals` | 557 | 13.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 308 | `printjob_props_swf5` | 45 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 309 | `printjob_props_swf6` | 45 | 13.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 310 | `printjob_props_swf7` | 45 | 13.5s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 311 | `property_invalid_base_clip` | 36 | 13.4s |  |
| 312 | `prototype_delete` | 12 | 13.2s |  |
| 313 | `prototype_enumerate` | 5 | 13.3s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 314 | `prototype_properties` | 17 | 13.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 315 | `rectangle` | 745 | 14.1s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 316 | `recursive_prototypes` | 0 | 13.3s |  |
| 317 | `register_class_return_value` | 16 | 13.5s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 318 | `register_class_with_sound` | 11 | 13.4s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 319 | `register_globals_across_frames` | 15 | 14.4s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 320 | `register_underflow` | 26 | 13.1s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 321 | `remove_movie_clip` | 29 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 322 | `rewind_depth` | 30 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 323 | `sandbox_type_local_file` | 1 | 13.0s |  |
| 324 | `sandbox_type_local_network` | 1 | 12.9s |  |
| 325 | `selection` | 454 | 13.3s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 326 | `set_interval` | 27 | 13.3s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 327 | `set_variable_scope` | 58 | 13.0s |  |
| 328 | `single_frame` | 1 | 12.7s |  |
| 329 | `slash_syntax` | 14 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 330 | `sound` | 628 | 13.3s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 331 | `sound_props_swf5` | 68 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 332 | `sound_props_swf6` | 68 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 333 | `sound_start_load` | 0 | 14.1s |  |
| 334 | `stage_display_state` | 16 | 13.6s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 335 | `stage_object_children` | 83 | 13.5s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 336 | `stage_object_enumerate` | 4 | 13.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 337 | `stage_object_properties` | 241 | 13.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 338 | `stage_object_properties_get_var` | 5 | 13.2s |  |
| 339 | `stage_object_properties_swf6` | 231 | 13.4s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 340 | `stage_property_representation` | 586 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 341 | `stage_scale_mode` | 39 | 13.2s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 342 | `strictequals_swf6` | 902 | 14.7s |  |
| 343 | `strictly_equals` | 7 | 13.3s |  |
| 344 | `string_methods` | 285 | 13.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 345 | `string_methods_negative_args` | 240 | 13.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 346 | `string_methods_swfv5` | 275 | 14.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 347 | `string_ops_swf6` | 95 | 14.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 348 | `string_paths_basic` | 4 | 14.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 349 | `string_paths_eval2` | 7 | 14.6s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `string_paths_hidden` | 54 | 14.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 351 | `string_paths_other` | 36 | 13.5s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 352 | `string_paths_unload` | 1 | 13.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 353 | `string_paths_variable_alias` | 4 | 13.1s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 354 | `string_paths_variable_scopes` | 5 | 13.0s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 355 | `stylesheet` | 283 | 13.8s |  |
| 356 | `stylesheet_transform` | 750 | 13.6s |  |
| 357 | `super_edge_cases` | 39 | 13.0s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 358 | `swf4_actions_bool` | 96 | 13.0s |  |
| 359 | `swf4_actions_coercion_order` | 158 | 13.0s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 360 | `swf4_bool` | 4 | 12.8s |  |
| 361 | `swf4_function_calls` | 7 | 13.3s |  |
| 362 | `swf5_encoding` | 3 | 12.7s |  |
| 363 | `swf5_global_funcs` | 232 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 364 | `swf5_no_closure` | 19 | 12.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 365 | `swf6_case_insensitive` | 42 | 12.7s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 366 | `swf6_global_funcs` | 232 | 12.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 367 | `swf6_string_as_bool` | 15 | 12.6s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 368 | `swf7_case_sensitive` | 44 | 12.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 369 | `swf7_global_funcs` | 232 | 12.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 370 | `tab_ordering_automatic_basic` | 92 | 12.8s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 371 | `tab_ordering_automatic_order_grid` | 21 | 12.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 372 | `tab_ordering_automatic_order_same_position` | 12 | 12.8s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 373 | `tab_ordering_children` | 208 | 12.9s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 374 | `tab_ordering_custom_basic` | 71 | 12.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 375 | `tab_ordering_custom_duplicate_index` | 22 | 12.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 376 | `tab_ordering_custom_i32_vs_u32` | 12 | 12.8s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 377 | `tab_ordering_custom_m1` | 29 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 378 | `tab_ordering_events` | 150 | 13.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 379 | `tab_ordering_movieclip_enabled_default` | 462 | 13.3s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 380 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.3s |  |
| 381 | `tab_ordering_reverse` | 51 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 382 | `tab_ordering_tabbable` | 47 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 383 | `target_clip_swf5` | 2 | 13.1s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 384 | `target_clip_swf6` | 2 | 13.1s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 385 | `target_path` | 14 | 12.8s |  |
| 386 | `tell_target` | 37 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 387 | `tell_target_invalid` | 6 | 13.0s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 388 | `tell_target_invalid_swf6` | 5 | 13.1s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 389 | `text_format` | 1146 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 390 | `text_format_display` | 21 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 391 | `text_format_font_max_length` | 2 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 392 | `text_format_rounding_swf7` | 840 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 393 | `text_format_rounding_swf8` | 840 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 394 | `textfield_background_color` | 11 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 395 | `textfield_border_color` | 11 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 396 | `textfield_cache_as_bitmap` | 1 | 12.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 397 | `textfield_maxchars` | 3 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 398 | `textfield_properties` | 44 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 399 | `textfield_props_swf5` | 175 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 400 | `textfield_props_swf6` | 210 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 401 | `textfield_props_swf7` | 210 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 402 | `textfield_props_swf8` | 210 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 403 | `textfield_text` | 7 | 12.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 404 | `textfield_variable` | 81 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 405 | `textsnapshot_available_text` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 406 | `textsnapshot_findtext` | 44 | 13.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 407 | `textsnapshot_gettext` | 55 | 13.3s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 408 | `textsnapshot_props_swf5` | 56 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 409 | `textsnapshot_props_swf6` | 56 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 410 | `textsnapshot_text_order` | 1 | 12.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 411 | `this_scoping` | 52 | 12.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 412 | `this_swf5` | 41 | 12.9s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 413 | `this_swf6` | 41 | 12.7s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 414 | `this_swf7` | 41 | 12.7s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 415 | `timeline_function_def` | 7 | 13.1s |  |
| 416 | `trace` | 8 | 13.5s |  |
| 417 | `transform` | 70 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 418 | `try_catch_finally` | 118 | 13.3s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 419 | `try_finally_simple` | 16 | 13.1s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 420 | `typeof` | 22 | 13.2s |  |
| 421 | `typeof_globals` | 7 | 13.2s |  |
| 422 | `uncaught_exception` | 1 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 423 | `uncaught_exception_bubbled` | 1 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 424 | `undefined_to_string_swf6` | 4 | 13.2s |  |
| 425 | `unescape` | 43 | 13.2s |  |
| 426 | `unload` | 52 | 13.3s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 427 | `unload_clip_event` | 4 | 13.2s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 428 | `unloadmovie` | 4 | 13.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 429 | `unloadmovie_method` | 3 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 430 | `unloadmovienum` | 13 | 13.5s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 431 | `use_hand_cursor` | 8 | 13.2s |  |
| 432 | `variable_args` | 5 | 13.4s |  |
| 433 | `waitforframe` | 7 | 13.3s |  |
| 434 | `waitforframe2` | 16 | 13.3s |  |
| 435 | `watch` | 117 | 13.5s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 436 | `watch_textfield` | 12 | 13.2s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 437 | `watch_virtual_property_proto` | 2 | 13.2s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 438 | `with` | 49 | 13.2s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 439 | `with_return` | 2 | 13.1s |  |
| 440 | `with_variable_scopes` | 43 | 13.3s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 441 | `xml` | 15 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 442 | `xml_append_child` | 28 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 443 | `xml_append_child_with_parent` | 20 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 444 | `xml_attributes_read` | 4 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 445 | `xml_cdata` | 11 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 446 | `xml_child_nodes_edge_cases` | 4 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 447 | `xml_clone_expandos` | 19 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 448 | `xml_first_last_child` | 8 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 449 | `xml_has_child_nodes` | 3 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 450 | `xml_idmap` | 21 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 451 | `xml_ignore_comments` | 21 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 452 | `xml_ignore_white` | 34 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 453 | `xml_insert_before` | 20 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 454 | `xml_inspect_createmethods` | 15 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 455 | `xml_inspect_doctype` | 7 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 456 | `xml_inspect_parsexml` | 62 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 457 | `xml_inspect_xmldecl` | 7 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 458 | `xml_namespaces` | 203 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 459 | `xml_parent_and_child` | 5 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 460 | `xml_remove_node` | 22 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 461 | `xml_reparenting` | 14 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 462 | `xml_siblings` | 10 | 13.1s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 463 | `xml_to_string` | 13 | 13.2s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 464 | `xml_to_string_comment` | 1 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 465 | `xml_unescaping` | 23 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 466 | `xmlnode_proto` | 1 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**43 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `edittext_html_condensewhite_swf7` | 99.0% | 308 | 311 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189 | 191 | 2 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `instanceof_coercions` | 97.7% | 86 | 88 | 2 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `funky_function_calls` | 96.4% | 54 | 56 | 2 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52 | 54 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `define_local_with_paths` | 94.4% | 51 | 54 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 11 | `edittext_html_condensewhite_swf8` | 92.6% | 288 | 311 | 23 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 13 | `string_coercion` | 90.7% | 107 | 118 | 11 | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 14 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 15 | `path_string` | 86.7% | 280 | 323 | 43 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 18 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `edittext_newlines` | 76.7% | 23 | 30 | 7 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `duplicate_movie_clip` | 66.7% | 14 | 21 | 7 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 25 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `loadmovie_var_persistence` | 62.5% | 5 | 8 | 3 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 28 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 30 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 31 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 32 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 33 | `register_class` | 57.6% | 38 | 66 | 28 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 34 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 35 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 36 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 37 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 38 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 39 | `device_font_spacing` | 51.6% | 47 | 91 | 44 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 40 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 42 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 43 | `issue_2030` | 50.0% | 2 | 4 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 16.5s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `edittext_ime_focus_lost` | 15.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `netstream_play_flv_screen` | 29.2s |  |
| 4 | `string_paths_timer` | 15.8s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 5 | `timer_run_actions` | 15.5s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 37.6s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 38.1s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 23.7s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**144 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [10](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `edittext_html_condensewhite_swf7` | 99.0% | 308/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `movieclip_getbounds` | 99.0% | 189/191 | 191 | 191 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 4 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 5 | `instanceof_coercions` | 97.7% | 86/88 | 88 | 88 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 6 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 7 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 8 | `funky_function_calls` | 96.4% | 54/56 | 56 | 56 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 9 | `edittext_scroll` | 96.3% | 52/54 | 54 | 54 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 10 | `define_local_with_paths` | 94.4% | 51/54 | 54 | 54 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 11 | `edittext_html_condensewhite_swf8` | 92.6% | 288/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 13 | `string_coercion` | 90.7% | 107/118 | 118 | 117 | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 14 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 15 | `path_string` | 86.7% | 280/323 | 323 | 322 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 16 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 17 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 18 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 19 | `edittext_newlines` | 76.7% | 23/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 21 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 22 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `duplicate_movie_clip` | 66.7% | 14/21 | 21 | 20 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 24 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 25 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 26 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 27 | `loadmovie_var_persistence` | 62.5% | 5/8 | 5 | 8 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 28 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 29 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 30 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 31 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 32 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 33 | `register_class` | 57.6% | 38/66 | 47 | 66 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 34 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 35 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 36 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 37 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 38 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 39 | `device_font_spacing` | 51.6% | 47/91 | 91 | 91 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 40 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 41 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 42 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 43 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 44 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 45 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 46 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 47 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 48 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 49 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 50 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 51 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 52 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 53 | `swf5_to_6_cross_call` | 37.9% | 11/29 | 11 | 29 | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 54 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 55 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 56 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 57 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 58 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 59 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 60 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 61 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 62 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 63 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 64 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 65 | `default_names` | 28.8% | 15/52 | 48 | 52 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 66 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 67 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 68 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 69 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 70 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 71 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 72 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 73 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 74 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 75 | `mcl_events_swf_version` | 15.9% | 37/232 | 37 | 232 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 76 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 77 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 78 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 80 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 81 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 82 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 83 | `external_interface` | 13.1% | 11/84 | 23 | 84 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 84 | `coerce_to_object_monkeypatch` | 13.0% | 17/131 | 131 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 85 | `mcl_getprogress` | 12.9% | 4/31 | 31 | 30 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 86 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 87 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 88 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 89 | `add2` | 8.7% | 31/358 | 358 | 354 | [1](ruffle-tests/_investigation/complete/add2.md) |
| 90 | `mcl_loadclip` | 8.0% | 12/150 | 150 | 149 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 91 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 92 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 93 | `define_local` | 7.4% | 2/27 | 23 | 27 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 94 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 95 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 96 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 97 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 98 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 99 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 100 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 101 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 102 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 103 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 104 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 105 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 107 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 108 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 109 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 110 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 111 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 112 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 113 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 114 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 115 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 116 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 117 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 118 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 119 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 120 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 121 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 122 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 123 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 124 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 125 | `interface_implements_op` | 0.0% | 0/47 | 46 | 47 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 126 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 127 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 128 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 129 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 130 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 131 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 132 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 133 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 134 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 135 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 136 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 137 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 138 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 139 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 140 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 141 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 142 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 143 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 144 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 0 | 1 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BUTTON_PLAN.md](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) | 14 | 13 | 1 |
| 6 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) | 2 | 1 | 1 |
| 7 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) | 8 | 3 | 5 |
| 8 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 3 | 1 |
| 9 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 10 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 11 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 12 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 13 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 14 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 3 | 4 |
| 15 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 5 | 2 |
| 16 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 17 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 1 | 2 |
| 18 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 19 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 26 | 5 |
| 20 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 21 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 22 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 23 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 23 | 26 |
| 24 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 25 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 26 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 27 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 28 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 29 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 29 | 29 |
| 30 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 10 | 6 |
| 31 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 32 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 33 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 34 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 7 | 1 |
| 35 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 36 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 11 | 1 |
| 37 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) | 15 | 12 | 3 |
| 38 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) | 4 | 1 | 3 |
| 39 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 4 | 2 | 2 |
| 40 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 41 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 42 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 43 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 0 | 1 |
| 44 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 45 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 46 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 47 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 14 | 2 |
| 48 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 13 | 6 |
| 49 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 56 | 14 |
| 50 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 51 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 52 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 53 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 54 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 55 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 56 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 3 | 13 |
| 57 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 58 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 59 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 195 | 155 | 40 |
