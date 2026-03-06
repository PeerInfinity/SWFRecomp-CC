# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-06 02:28 UTC

**Git SHA**: `b7965a8fc0`

**Run Duration**: 139m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **461** (74.5%) |
| Failing | 158 |
| Total expected lines | 91475 |
| Matching lines | 70157 (76.7%) |
| Mismatched lines | 21318 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 149 | 94.3% |
| Runtime Segfault | 5 | 3.2% |
| Runtime Error | 2 | 1.3% |
| Timeout | 1 | 0.6% |
| Compile Fail | 1 | 0.6% |

## Passing Tests

**461 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 13.0s |  |
| 2 | `action_to_integer` | 28 | 12.6s |  |
| 3 | `add` | 28 | 12.6s |  |
| 4 | `add2` | 354 | 12.7s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 12.5s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 12.4s |  |
| 7 | `add_swf5` | 28 | 12.6s |  |
| 8 | `arguments` | 127 | 12.8s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 12.7s |  |
| 11 | `array_constructor` | 30 | 12.6s |  |
| 12 | `array_enumerate` | 4 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 12.7s |  |
| 14 | `array_properties` | 36 | 12.6s |  |
| 15 | `array_prototyping` | 12 | 12.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 12.7s |  |
| 17 | `array_sort` | 161 | 13.4s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 12.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 12.8s |  |
| 20 | `array_trivial` | 209 | 12.7s |  |
| 21 | `as1_constructor_v6` | 35 | 12.6s |  |
| 22 | `as1_constructor_v7` | 35 | 12.6s |  |
| 23 | `as2_oop` | 13 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 12.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 12.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 12.6s |  |
| 29 | `as_broadcaster_undef` | 89 | 12.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 12.7s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 12.6s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 12.6s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 12.6s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 12.6s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 12.7s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 12.7s |  |
| 37 | `as_transformed_flag` | 20 | 12.6s |  |
| 38 | `asnative` | 34 | 12.5s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 12.6s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 12.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 12.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 12.6s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 12.5s |  |
| 44 | `bitand` | 1058 | 15.0s |  |
| 45 | `bitmap_data_colortransform` | 0 | 12.8s |  |
| 46 | `bitmap_data_fillrect` | 0 | 12.8s |  |
| 47 | `bitmap_data_max_size_swf10` | 12 | 12.6s |  |
| 48 | `bitmap_data_max_size_swf9` | 10 | 12.6s |  |
| 49 | `bitmap_data_perlinnoise` | 0 | 13.3s |  |
| 50 | `bitmap_data_pixeldissolve_image` | 0 | 12.9s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 12.8s |  |
| 52 | `bitor` | 1058 | 15.0s |  |
| 53 | `biturshift` | 14 | 13.5s |  |
| 54 | `biturshift_swf8` | 14 | 12.9s |  |
| 55 | `bitxor` | 1058 | 15.4s |  |
| 56 | `boxed_primitives` | 24 | 13.0s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 57 | `button_children` | 8 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 58 | `button_goto` | 4 | 12.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 59 | `button_key_events` | 14 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 60 | `button_key_events_special` | 45 | 13.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 61 | `button_keypress` | 3 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 62 | `button_keypress_vs_press` | 25 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 63 | `button_keypress_vs_tab` | 20 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_textinput` | 4 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 65 | `button_order` | 2 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 66 | `button_properties_special_cases` | 22 | 13.0s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 67 | `button_v5` | 18 | 12.8s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 68 | `button_v6` | 18 | 12.7s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 69 | `call` | 63 | 13.0s | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) |
| 70 | `call_method_empty_name` | 1 | 12.8s |  |
| 71 | `capabilities_resolution` | 8 | 12.8s |  |
| 72 | `catch_references_registers` | 2 | 12.7s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 73 | `click_block` | 5 | 12.8s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 74 | `clip_constructors` | 8 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 75 | `clip_events` | 19 | 13.0s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 76 | `clone_sprite_types` | 24 | 12.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 77 | `closure_scope` | 7 | 12.9s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 78 | `color` | 57 | 13.1s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 79 | `color_transform` | 48 | 13.0s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 80 | `conflicting_instance_names` | 23 | 12.9s |  |
| 81 | `constructor_function` | 2 | 12.7s |  |
| 82 | `context_menu` | 39 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 83 | `context_menu_item` | 41 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 84 | `create_empty_movie_clip` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 85 | `define_function2` | 8 | 12.7s |  |
| 86 | `define_function2_preload` | 13 | 12.6s |  |
| 87 | `define_function2_preload_order` | 4 | 12.8s |  |
| 88 | `define_function_case_sensitive` | 2 | 12.8s |  |
| 89 | `delete` | 3 | 12.8s |  |
| 90 | `device_font_spacing` | 91 | 13.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 91 | `display_object_properties` | 2 | 12.7s |  |
| 92 | `divide_swf4` | 107 | 12.7s |  |
| 93 | `do_init_action` | 3 | 12.7s |  |
| 94 | `do_init_action_child` | 12 | 12.8s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 95 | `drag_drop` | 10 | 12.8s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 96 | `drag_over_from_outside` | 1 | 12.8s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 97 | `drag_over_without_startdrag` | 1 | 12.8s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 98 | `duplicate_movie_clip` | 20 | 12.8s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 99 | `edittext_antialiastype` | 296 | 15.1s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 100 | `edittext_autosize_setter` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 101 | `edittext_default_format` | 221 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 102 | `edittext_default_format_font_style` | 335 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 103 | `edittext_hscroll` | 27 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 104 | `edittext_html_align_swf7` | 52 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 105 | `edittext_html_align_swf8` | 52 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 106 | `edittext_html_color` | 114 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 107 | `edittext_html_entity` | 4 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 108 | `edittext_html_roundtrip` | 17 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 109 | `edittext_html_swf7` | 5377 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 110 | `edittext_html_swf8` | 5377 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 111 | `edittext_input` | 1 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 112 | `edittext_newline_stripping` | 64 | 17.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 113 | `edittext_password` | 5 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 114 | `edittext_password_copy` | 4 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 115 | `edittext_paste_empty` | 2 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 116 | `edittext_programmatic_focus` | 12 | 12.8s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 117 | `edittext_restrict` | 191 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 118 | `edittext_restrict_paste` | 5 | 13.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 119 | `edittext_stylesheet` | 325 | 13.4s | [45](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 120 | `edittext_tag_indent` | 31 | 12.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 121 | `edittext_text_height_leading` | 20 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 122 | `edittext_width_height` | 103 | 12.9s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 123 | `empty_movieclip_can_attach_movies` | 11 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 124 | `enumerate` | 64 | 12.9s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 125 | `equals` | 32 | 12.8s |  |
| 126 | `equals2_swf5` | 926 | 14.6s |  |
| 127 | `equals2_swf6` | 926 | 14.5s |  |
| 128 | `equals2_swf7` | 926 | 14.6s |  |
| 129 | `equals_swf4` | 665 | 13.6s |  |
| 130 | `equals_swf4_alt` | 32 | 12.9s |  |
| 131 | `equals_swf5` | 32 | 12.9s |  |
| 132 | `error` | 58 | 12.9s |  |
| 133 | `escape` | 14 | 12.7s |  |
| 134 | `execution_order1` | 5 | 13.0s |  |
| 135 | `execution_order2` | 7 | 12.9s |  |
| 136 | `execution_order3` | 4 | 12.8s |  |
| 137 | `execution_order4` | 12 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 138 | `export_assets` | 3 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 139 | `extends_chain` | 134 | 13.3s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 140 | `extends_native_type` | 11 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 141 | `focus_mouse` | 45 | 14.8s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 142 | `focus_mouse_rollout` | 4 | 15.2s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 143 | `focus_root_movie` | 2 | 15.7s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 144 | `focusrect_focuslost` | 4 | 14.5s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 145 | `focusrect_mouse_swf8` | 0 | 15.4s |  |
| 146 | `focusrect_mouse_swf9` | 0 | 14.3s |  |
| 147 | `focusrect_swf5` | 6 | 15.2s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 148 | `focusrect_swf6` | 42 | 14.6s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 149 | `form_loader_encoding_1` | 1 | 14.2s |  |
| 150 | `frame_size_translated_negative` | 21 | 14.5s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 151 | `frame_size_translated_positive` | 21 | 15.0s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 152 | `function_as_function` | 35 | 14.9s | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 153 | `function_base_clip` | 8 | 15.5s |  |
| 154 | `function_base_clip_removed` | 25 | 15.2s |  |
| 155 | `function_suppress_and_preload` | 28 | 14.2s |  |
| 156 | `get_bytes_total` | 4 | 13.7s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 157 | `get_variable_in_scope` | 29 | 15.7s |  |
| 158 | `getproperty` | 28 | 14.5s |  |
| 159 | `getproperty_swf4` | 28 | 15.5s |  |
| 160 | `getproperty_swf5` | 28 | 13.9s |  |
| 161 | `gettextextent` | 56 | 15.0s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 162 | `global_array` | 3 | 15.4s |  |
| 163 | `global_is_bare` | 7 | 15.4s |  |
| 164 | `global_swf6_7_8` | 15 | 14.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 165 | `globals_swf5` | 304 | 16.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 166 | `globals_swf6` | 304 | 14.2s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 167 | `globals_swf7` | 304 | 15.4s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 168 | `globals_swf8` | 304 | 14.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 169 | `goto_advance1` | 6 | 14.9s |  |
| 170 | `goto_advance2` | 2 | 14.9s |  |
| 171 | `goto_both_ways1` | 3 | 14.4s |  |
| 172 | `goto_both_ways2` | 3 | 12.9s |  |
| 173 | `goto_execution_order` | 2 | 12.9s |  |
| 174 | `goto_execution_order2` | 2 | 12.9s |  |
| 175 | `goto_frame` | 12 | 13.0s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 176 | `goto_frame2` | 44 | 13.3s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 177 | `goto_frame_number` | 3 | 12.8s |  |
| 178 | `goto_label` | 17 | 13.0s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 179 | `goto_methods` | 40 | 13.0s | [16](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 180 | `goto_rewind1` | 1 | 12.9s |  |
| 181 | `goto_rewind2` | 3 | 12.9s |  |
| 182 | `goto_rewind3` | 2 | 12.8s |  |
| 183 | `greater_swf6` | 1175 | 14.7s |  |
| 184 | `greater_swf7` | 1175 | 14.7s |  |
| 185 | `greaterthan_swf5` | 1 | 12.7s |  |
| 186 | `greaterthan_swf8` | 1 | 12.7s |  |
| 187 | `has_own_property` | 32 | 12.8s |  |
| 188 | `hittest_lockroot` | 15 | 13.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 189 | `hittest_morph` | 70 | 12.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [27](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 190 | `hittest_winding_rule` | 12 | 12.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 191 | `infinite_recursion_function` | 4 | 12.7s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 192 | `infinite_recursion_function_in_setter` | 131 | 12.8s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 193 | `infinite_recursion_virtual_property` | 67 | 12.9s | [21](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 194 | `init_array_invalid` | 4 | 12.8s |  |
| 195 | `init_object_invalid` | 4 | 12.8s |  |
| 196 | `init_object_order` | 15 | 12.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 197 | `is_finite` | 49 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 198 | `is_finite_swf6` | 49 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 199 | `is_prototype_of` | 89 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 200 | `issue_1086` | 1 | 12.8s |  |
| 201 | `issue_1104` | 2 | 12.9s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 202 | `issue_1671` | 0 | 12.8s |  |
| 203 | `issue_1906` | 4 | 12.8s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 204 | `issue_2166` | 9 | 12.7s |  |
| 205 | `issue_3169` | 2 | 12.8s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 206 | `issue_3446` | 1 | 12.7s |  |
| 207 | `issue_3522` | 2 | 12.9s |  |
| 208 | `issue_4377` | 2 | 12.8s |  |
| 209 | `issue_710` | 4 | 12.8s |  |
| 210 | `issue_768` | 3 | 12.9s | [22](ruffle-tests/_investigation/complete/issue_768.md) |
| 211 | `issue_9327` | 2 | 12.9s |  |
| 212 | `issue_9885` | 2 | 12.8s |  |
| 213 | `key_isToggled` | 9 | 12.7s |  |
| 214 | `lessthan` | 41 | 12.7s |  |
| 215 | `lessthan2_swf5` | 1226 | 14.8s |  |
| 216 | `lessthan2_swf6` | 1226 | 14.8s |  |
| 217 | `lessthan2_swf7` | 1226 | 14.8s |  |
| 218 | `lessthan_swf4` | 902 | 13.9s |  |
| 219 | `lessthan_swf4_alt` | 41 | 12.8s |  |
| 220 | `lessthan_swf5` | 41 | 12.8s |  |
| 221 | `loadmovie` | 2 | 12.8s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 222 | `loadmovie_fail` | 2 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 223 | `loadmovie_flashvars` | 4 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 224 | `loadmovie_method` | 2 | 13.2s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 225 | `loadmovie_replace_root` | 5 | 12.8s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 226 | `loadmovienum` | 3 | 13.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 227 | `loadvariables` | 2 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 228 | `loadvariables2` | 8 | 13.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 229 | `loadvariablesnum` | 2 | 12.8s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 230 | `local_to_global` | 49 | 12.9s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 231 | `localconnection_properties` | 8 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 232 | `lock_root` | 1 | 12.8s |  |
| 233 | `logical_ops_swf4` | 90 | 12.8s |  |
| 234 | `logical_ops_swf8` | 108 | 13.0s |  |
| 235 | `looping` | 6 | 12.9s |  |
| 236 | `mask_reapply` | 0 | 12.9s |  |
| 237 | `mask_with_drawing` | 0 | 12.8s |  |
| 238 | `math_min_max` | 101 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 239 | `math_swf6` | 530 | 13.3s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 240 | `math_swf7` | 530 | 13.3s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 241 | `math_swf8` | 530 | 13.1s | [26](ruffle-tests/_investigation/complete/MATH_PLAN.md) |
| 242 | `matrix` | 171 | 13.2s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 243 | `mcl_as_broadcaster` | 12 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 244 | `mcl_getprogress` | 30 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 245 | `mcl_loadclip` | 149 | 13.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 246 | `mcl_loadclip_properties` | 6 | 13.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 247 | `mcl_mislabeled_target` | 6 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 248 | `mcl_target_gif87a` | 6 | 13.3s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 249 | `mcl_target_gif89a` | 6 | 13.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 250 | `mcl_target_jpg` | 6 | 13.0s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 251 | `mcl_target_png` | 6 | 13.1s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 252 | `mcl_unloadclip` | 5 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 253 | `mouse_events` | 8 | 12.9s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 254 | `mouse_events_visible_enabled` | 12 | 13.1s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 255 | `mouse_hover_events_while_dragging` | 1 | 13.0s | [11](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) |
| 256 | `mouse_listeners` | 67 | 12.9s |  |
| 257 | `mouse_pos` | 665 | 12.9s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 258 | `mouse_pos_with_scale_factor` | 260 | 12.9s | [28](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 259 | `mouse_wheel_enabled` | 2 | 12.8s |  |
| 260 | `movieclip_begin_gradient_fill` | 0 | 13.4s |  |
| 261 | `movieclip_blend_mode_property` | 35 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 262 | `movieclip_create_text_field` | 90 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 263 | `movieclip_default_state` | 69 | 13.1s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 264 | `movieclip_depth_methods` | 98 | 13.0s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 265 | `movieclip_focusenabled` | 99 | 12.9s | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 266 | `movieclip_get_instance_at_depth` | 28 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 267 | `movieclip_hittest` | 92 | 13.0s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 268 | `movieclip_in_removed_button` | 4 | 12.9s | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) |
| 269 | `movieclip_init_object` | 5 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 270 | `movieclip_line_gradient_style` | 0 | 13.2s |  |
| 271 | `movieclip_name_from_timeline` | 13 | 12.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 272 | `movieclip_prototype_extension` | 5 | 12.7s |  |
| 273 | `moviecliploader_flashvars` | 4 | 12.9s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 274 | `mutable_this` | 18 | 12.8s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 275 | `named_shapes` | 14 | 13.0s |  |
| 276 | `nan_scale` | 9 | 12.9s |  |
| 277 | `native_double_construct` | 12 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 278 | `native_objects_swf7` | 84 | 13.3s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 279 | `native_objects_swf8` | 84 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 280 | `native_subclasses` | 191 | 13.2s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 281 | `nested_textfields_in_buttons` | 0 | 12.8s |  |
| 282 | `new_method_wrap` | 4 | 12.7s |  |
| 283 | `new_object_enumerate` | 7 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 284 | `new_object_wrap` | 4 | 12.7s |  |
| 285 | `o` | 3 | 12.7s |  |
| 286 | `object_constructor` | 33 | 12.7s |  |
| 287 | `object_function` | 32 | 12.7s |  |
| 288 | `object_properties` | 31 | 12.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 289 | `object_prototypes` | 74 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 290 | `object_resolve` | 38 | 12.9s | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 291 | `object_string_coerce_swf5` | 62 | 12.7s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 292 | `object_string_coerce_swf6` | 68 | 12.8s | [32](ruffle-tests/_investigation/complete/object_string_coerce.md) |
| 293 | `on_construct` | 25 | 12.9s | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 294 | `parse_float` | 74 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 295 | `parse_int` | 64 | 13.0s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [35](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 296 | `path_string` | 322 | 12.9s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 297 | `place_and_lookup` | 30 | 12.7s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 298 | `placeobject_occupied_depth` | 6 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 299 | `point` | 175 | 13.1s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 300 | `primitive_instanceof` | 37 | 12.7s |  |
| 301 | `primitive_type_globals` | 557 | 13.1s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 302 | `printjob_props_swf5` | 45 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 303 | `printjob_props_swf6` | 45 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 304 | `printjob_props_swf7` | 45 | 12.8s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 305 | `property_invalid_base_clip` | 36 | 12.8s |  |
| 306 | `prototype_delete` | 12 | 12.8s |  |
| 307 | `prototype_enumerate` | 5 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 308 | `prototype_properties` | 17 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 309 | `rectangle` | 745 | 13.5s | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 310 | `recursive_prototypes` | 0 | 12.7s |  |
| 311 | `register_class_return_value` | 16 | 12.9s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 312 | `register_class_with_sound` | 11 | 12.9s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 313 | `register_globals_across_frames` | 15 | 12.9s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 314 | `register_underflow` | 26 | 12.8s | [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 315 | `remove_movie_clip` | 29 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 316 | `rewind_depth` | 30 | 12.9s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 317 | `sandbox_type_local_file` | 1 | 12.9s |  |
| 318 | `sandbox_type_local_network` | 1 | 12.8s |  |
| 319 | `selection` | 454 | 12.9s | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 320 | `set_interval` | 27 | 12.9s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |
| 321 | `set_variable_scope` | 58 | 12.9s |  |
| 322 | `single_frame` | 1 | 12.7s |  |
| 323 | `slash_syntax` | 14 | 12.7s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 324 | `sound` | 628 | 13.0s | [40](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 325 | `sound_props_swf5` | 68 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 326 | `sound_props_swf6` | 68 | 12.9s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 327 | `sound_start_load` | 0 | 12.8s |  |
| 328 | `stage_display_state` | 16 | 12.8s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 329 | `stage_object_children` | 83 | 12.8s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 330 | `stage_object_enumerate` | 4 | 12.8s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 331 | `stage_object_properties` | 241 | 13.1s | [13](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 332 | `stage_object_properties_get_var` | 5 | 12.7s |  |
| 333 | `stage_object_properties_swf6` | 231 | 13.1s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 334 | `stage_property_representation` | 586 | 12.8s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 335 | `stage_scale_mode` | 39 | 12.8s | [41](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [42](ruffle-tests/_investigation/complete/STAGE_PLAN.md) |
| 336 | `strictequals_swf6` | 902 | 14.2s |  |
| 337 | `strictly_equals` | 7 | 12.8s |  |
| 338 | `string_coercion` | 117 | 13.0s | [43](ruffle-tests/_investigation/complete/string_coercion.md) |
| 339 | `string_methods` | 285 | 13.3s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 340 | `string_methods_negative_args` | 240 | 12.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 341 | `string_methods_swfv5` | 275 | 13.2s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 342 | `string_ops_swf6` | 95 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) |
| 343 | `string_paths_basic` | 4 | 12.7s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 344 | `string_paths_eval2` | 7 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 345 | `string_paths_hidden` | 54 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 346 | `string_paths_other` | 36 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 347 | `string_paths_unload` | 1 | 12.9s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 348 | `string_paths_variable_alias` | 4 | 12.8s | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 349 | `string_paths_variable_scopes` | 5 | 12.8s | [12](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 350 | `stylesheet` | 283 | 13.5s |  |
| 351 | `stylesheet_transform` | 750 | 13.4s |  |
| 352 | `super_edge_cases` | 39 | 12.9s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 353 | `swf4_actions_bool` | 96 | 12.8s |  |
| 354 | `swf4_actions_coercion_order` | 158 | 12.9s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 355 | `swf4_bool` | 4 | 12.7s |  |
| 356 | `swf4_function_calls` | 7 | 13.6s |  |
| 357 | `swf5_encoding` | 3 | 13.4s |  |
| 358 | `swf5_global_funcs` | 232 | 13.7s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 359 | `swf5_no_closure` | 19 | 13.6s | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 360 | `swf6_case_insensitive` | 42 | 13.4s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 361 | `swf6_global_funcs` | 232 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 362 | `swf6_string_as_bool` | 15 | 13.4s | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 363 | `swf7_case_sensitive` | 44 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 364 | `swf7_global_funcs` | 232 | 13.6s | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 365 | `tab_ordering_automatic_basic` | 92 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 366 | `tab_ordering_automatic_order_grid` | 21 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 367 | `tab_ordering_automatic_order_same_position` | 12 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 368 | `tab_ordering_children` | 208 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 369 | `tab_ordering_custom_basic` | 71 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 370 | `tab_ordering_custom_duplicate_index` | 22 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 371 | `tab_ordering_custom_i32_vs_u32` | 12 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 372 | `tab_ordering_custom_m1` | 29 | 13.7s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 373 | `tab_ordering_events` | 150 | 13.9s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 374 | `tab_ordering_movieclip_enabled_default` | 462 | 13.8s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 375 | `tab_ordering_properties_tab_index_edge_case` | 4 | 13.4s |  |
| 376 | `tab_ordering_reverse` | 51 | 13.4s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 377 | `tab_ordering_tabbable` | 47 | 13.5s | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 378 | `target_clip_swf5` | 2 | 13.4s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 379 | `target_clip_swf6` | 2 | 13.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 380 | `target_path` | 14 | 13.5s |  |
| 381 | `tell_target` | 37 | 13.6s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 382 | `tell_target_invalid` | 6 | 13.5s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 383 | `tell_target_invalid_swf6` | 5 | 13.6s | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 384 | `text_format` | 1146 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 385 | `text_format_display` | 21 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 386 | `text_format_font_max_length` | 2 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 387 | `text_format_rounding_swf7` | 840 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 388 | `text_format_rounding_swf8` | 840 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 389 | `textfield_background_color` | 11 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 390 | `textfield_border_color` | 11 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 391 | `textfield_cache_as_bitmap` | 1 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 392 | `textfield_maxchars` | 3 | 13.5s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 393 | `textfield_properties` | 44 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 394 | `textfield_props_swf5` | 175 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 395 | `textfield_props_swf6` | 210 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 396 | `textfield_props_swf7` | 210 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 397 | `textfield_props_swf8` | 210 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 398 | `textfield_text` | 7 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 399 | `textfield_variable` | 81 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 400 | `textsnapshot_available_text` | 20 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 401 | `textsnapshot_findtext` | 44 | 13.8s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 402 | `textsnapshot_gettext` | 55 | 13.7s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 403 | `textsnapshot_props_swf5` | 56 | 13.6s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 404 | `textsnapshot_props_swf6` | 56 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 405 | `textsnapshot_text_order` | 1 | 13.4s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) [50](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 406 | `this_scoping` | 52 | 13.6s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 407 | `this_swf5` | 41 | 13.5s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 408 | `this_swf6` | 41 | 13.4s | [51](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) |
| 409 | `this_swf7` | 41 | 13.7s | [52](ruffle-tests/_investigation/complete/this_swf7.md) |
| 410 | `timeline_function_def` | 7 | 13.7s |  |
| 411 | `trace` | 8 | 13.5s |  |
| 412 | `transform` | 70 | 13.4s | [9](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 413 | `try_catch_finally` | 118 | 13.4s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 414 | `try_finally_simple` | 16 | 13.2s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 415 | `typeof` | 22 | 13.4s |  |
| 416 | `typeof_globals` | 7 | 13.3s |  |
| 417 | `uncaught_exception` | 1 | 13.3s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 418 | `uncaught_exception_bubbled` | 1 | 13.4s | [54](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 419 | `undefined_to_string_swf6` | 4 | 13.3s |  |
| 420 | `unescape` | 43 | 13.5s |  |
| 421 | `unload` | 52 | 13.6s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 422 | `unload_clip_event` | 4 | 13.4s | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 423 | `unloadmovie` | 4 | 13.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 424 | `unloadmovie_method` | 3 | 13.4s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 425 | `unloadmovienum` | 13 | 13.6s | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 426 | `use_hand_cursor` | 8 | 13.4s |  |
| 427 | `variable_args` | 5 | 13.6s |  |
| 428 | `waitforframe` | 7 | 13.4s |  |
| 429 | `waitforframe2` | 16 | 13.3s |  |
| 430 | `watch` | 117 | 13.7s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 431 | `watch_textfield` | 12 | 13.4s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 432 | `watch_virtual_property_proto` | 2 | 13.6s | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 433 | `with` | 49 | 13.5s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 434 | `with_return` | 2 | 13.5s |  |
| 435 | `with_variable_scopes` | 43 | 13.6s | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 436 | `xml` | 15 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 437 | `xml_append_child` | 28 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 438 | `xml_append_child_with_parent` | 20 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 439 | `xml_attributes_read` | 4 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 440 | `xml_cdata` | 11 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 441 | `xml_child_nodes_edge_cases` | 4 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 442 | `xml_clone_expandos` | 19 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 443 | `xml_first_last_child` | 8 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 444 | `xml_has_child_nodes` | 3 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 445 | `xml_idmap` | 21 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 446 | `xml_ignore_comments` | 21 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 447 | `xml_ignore_white` | 34 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 448 | `xml_insert_before` | 20 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 449 | `xml_inspect_createmethods` | 15 | 13.6s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 450 | `xml_inspect_doctype` | 7 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 451 | `xml_inspect_parsexml` | 62 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 452 | `xml_inspect_xmldecl` | 7 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 453 | `xml_namespaces` | 203 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 454 | `xml_parent_and_child` | 5 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 455 | `xml_remove_node` | 22 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 456 | `xml_reparenting` | 14 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 457 | `xml_siblings` | 10 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 458 | `xml_to_string` | 13 | 13.3s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 459 | `xml_to_string_comment` | 1 | 13.4s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 460 | `xml_unescaping` | 23 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 461 | `xmlnode_proto` | 1 | 13.5s | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**48 tests** within reach

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
| 11 | `edittext_letter_spacing` | 93.3% | 14 | 15 | 1 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 92.6% | 288 | 311 | 23 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `function_base_clip_readded` | 90.9% | 10 | 11 | 1 |  |
| 14 | `global_swf5_6_7_8_9` | 90.0% | 1031 | 1145 | 114 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 15 | `edittext_underline` | 90.0% | 36 | 40 | 4 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `edittext_font_size` | 88.9% | 40 | 45 | 5 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `edittext_align` | 86.7% | 52 | 60 | 8 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `movieclip_hittest_shapeflag` | 84.6% | 286 | 338 | 52 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `edittext_margins` | 80.0% | 20 | 25 | 5 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `target_clip_removed` | 80.0% | 4 | 5 | 1 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 21 | `edittext_autosize` | 78.9% | 56 | 71 | 15 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `edittext_tab_focus` | 76.9% | 10 | 13 | 3 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `edittext_tab_stops` | 75.0% | 45 | 60 | 15 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `text_blocks_clicks` | 75.0% | 3 | 4 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 25 | `edittext_html_swf6` | 72.5% | 3900 | 5377 | 1477 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 26 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 27 | `edittext_leading` | 66.7% | 6 | 9 | 3 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 28 | `edittext_newlines` | 66.7% | 20 | 30 | 10 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 29 | `movieclip_lockroot` | 65.5% | 19 | 29 | 10 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `register_and_init_order` | 63.2% | 146 | 231 | 85 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 31 | `edittext_align_trailing_spaces_swf7` | 62.5% | 360 | 576 | 216 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 32 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360 | 576 | 216 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 33 | `loadmovie_var_persistence` | 62.5% | 5 | 8 | 3 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 34 | `clone_sprite_edittext_dynamic` | 60.5% | 52 | 86 | 34 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 35 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 36 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 37 | `focusrect_property_swf7` | 58.0% | 718 | 1237 | 519 |  |
| 38 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 39 | `register_class` | 57.6% | 38 | 66 | 28 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 40 | `selection_handlers` | 55.6% | 15 | 27 | 12 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 41 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 42 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 43 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 44 | `tab_ordering_properties` | 51.7% | 156 | 302 | 146 |  |
| 45 | `duplicate_movie_clip_drawing` | 50.0% | 1 | 2 | 1 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `edittext_focus_selection` | 50.0% | 1 | 2 | 1 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 47 | `edittext_place_caret` | 50.0% | 1 | 2 | 1 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 48 | `issue_2030` | 50.0% | 2 | 4 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

**5 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 15.8s | [31](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `edittext_ime_focus_lost` | 15.0s | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 3 | `netstream_play_flv_screen` | 28.4s |  |
| 4 | `string_paths_timer` | 14.8s | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 5 | `timer_run_actions` | 15.4s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## Runtime Errors

**2 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `movieclip_invalid_get_bounds_6` | exit code -6 | 36.5s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 2 | `movieclip_invalid_get_bounds_7` | exit code -6 | 36.4s | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 24.7s | [53](ruffle-tests/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**149 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `edittext_letter_spacing` | 93.3% | 14/15 | 15 | 15 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 12 | `edittext_html_condensewhite_swf8` | 92.6% | 288/311 | 311 | 311 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 13 | `function_base_clip_readded` | 90.9% | 10/11 | 11 | 11 |  |
| 14 | `global_swf5_6_7_8_9` | 90.0% | 1031/1145 | 1145 | 1145 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 15 | `edittext_underline` | 90.0% | 36/40 | 40 | 40 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 16 | `edittext_font_size` | 88.9% | 40/45 | 45 | 45 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 17 | `edittext_align` | 86.7% | 52/60 | 60 | 60 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 18 | `movieclip_hittest_shapeflag` | 84.6% | 286/338 | 338 | 338 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 19 | `edittext_margins` | 80.0% | 20/25 | 25 | 25 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 20 | `target_clip_removed` | 80.0% | 4/5 | 5 | 5 | [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 21 | `edittext_autosize` | 78.9% | 56/71 | 71 | 71 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 22 | `edittext_tab_focus` | 76.9% | 10/13 | 13 | 13 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 23 | `edittext_tab_stops` | 75.0% | 45/60 | 60 | 60 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 24 | `text_blocks_clicks` | 75.0% | 3/4 | 3 | 4 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 25 | `edittext_html_swf6` | 72.5% | 3900/5377 | 5377 | 5377 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 26 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 27 | `edittext_leading` | 66.7% | 6/9 | 9 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 28 | `edittext_newlines` | 66.7% | 20/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 29 | `movieclip_lockroot` | 65.5% | 19/29 | 29 | 29 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 30 | `register_and_init_order` | 63.2% | 146/231 | 194 | 231 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 31 | `edittext_align_trailing_spaces_swf7` | 62.5% | 360/576 | 576 | 576 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 32 | `edittext_align_trailing_spaces_swf8` | 62.5% | 360/576 | 576 | 576 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 33 | `loadmovie_var_persistence` | 62.5% | 5/8 | 5 | 8 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 34 | `clone_sprite_edittext_dynamic` | 60.5% | 52/86 | 86 | 86 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 35 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 36 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 37 | `focusrect_property_swf7` | 58.0% | 718/1237 | 1237 | 1237 |  |
| 38 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 39 | `register_class` | 57.6% | 38/66 | 47 | 66 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 40 | `selection_handlers` | 55.6% | 15/27 | 23 | 27 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) |
| 41 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 42 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 43 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 44 | `tab_ordering_properties` | 51.7% | 156/302 | 302 | 293 |  |
| 45 | `duplicate_movie_clip_drawing` | 50.0% | 1/2 | 2 | 2 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 46 | `edittext_focus_selection` | 50.0% | 1/2 | 2 | 2 | [39](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 47 | `edittext_place_caret` | 50.0% | 1/2 | 2 | 2 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 48 | `issue_2030` | 50.0% | 2/4 | 4 | 4 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 |  |
| 50 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 51 | `loadmovienum_cross_version_prototype` | 46.2% | 6/13 | 13 | 9 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 52 | `focusrect_property_swf6` | 45.3% | 560/1237 | 1237 | 1237 |  |
| 53 | `edittext_input_newlines` | 44.4% | 4/9 | 8 | 9 | [49](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) |
| 54 | `loading_avm2` | 42.9% | 3/7 | 3 | 7 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 55 | `coerce_to_primitive_resolve` | 41.2% | 7/17 | 13 | 17 | [36](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `input_dead_keys_windows` | 40.0% | 6/15 | 15 | 15 |  |
| 57 | `tab_ordering_events_mouse` | 40.0% | 26/65 | 59 | 65 | [47](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) |
| 58 | `swf5_to_6_cross_call` | 37.9% | 11/29 | 11 | 29 | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 59 | `string_paths_eval` | 37.5% | 3/8 | 8 | 4 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 60 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 61 | `movieclip_invalid_get_bounds_8` | 36.4% | 4/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 62 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 |  |
| 63 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 |  |
| 64 | `issue_2870` | 33.3% | 1/3 | 2 | 3 |  |
| 65 | `root_global_parent` | 33.3% | 2/6 | 6 | 6 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 66 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 67 | `cross_movie_root` | 30.0% | 3/10 | 10 | 10 |  |
| 68 | `loadmovie_registerclass` | 30.0% | 9/30 | 24 | 30 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 69 | `removed_target_clip_scope` | 29.7% | 11/37 | 37 | 35 | [6](ruffle-tests/_investigation/blocked/CALL_SEMANTICS_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 70 | `default_names` | 28.8% | 15/52 | 48 | 52 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 71 | `clone_sprite_edittext` | 27.7% | 26/94 | 94 | 94 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 72 | `swf6_to_5_cross_call` | 24.1% | 7/29 | 11 | 29 | [46](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) |
| 73 | `focusrect_property_swf5` | 21.1% | 261/1237 | 1237 | 1237 |  |
| 74 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 75 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 76 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 77 | `focus_remove` | 18.2% | 6/33 | 24 | 33 |  |
| 78 | `movieclip_invalid_get_bounds_5` | 18.2% | 2/11 | 5 | 11 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 79 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 80 | `mcl_events_swf_version` | 15.9% | 37/232 | 37 | 232 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 81 | `focus_visibility_change` | 15.6% | 7/45 | 36 | 45 |  |
| 82 | `movieclip_invalid_get_bounds_3` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 83 | `movieclip_invalid_get_bounds_4` | 15.4% | 2/13 | 8 | 13 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 84 | `focus_keyboard_press` | 15.0% | 15/100 | 100 | 60 | [8](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 85 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [33](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 86 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 87 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 88 | `external_interface` | 13.1% | 11/84 | 23 | 84 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 89 | `coerce_to_object_monkeypatch` | 13.0% | 17/131 | 131 | 129 | [55](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 90 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 91 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 92 | `bitmap_data_pixeldissolve` | 8.9% | 96/1075 | 1055 | 1075 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 93 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 94 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 95 | `define_local` | 7.4% | 2/27 | 23 | 27 | [58](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 96 | `movieclip_invalid_get_bounds_2` | 6.7% | 5/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 97 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 98 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 99 | `movieclip_gettextsnapshot` | 5.4% | 6/112 | 42 | 112 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 100 | `movieclip_invalid_get_bounds_1` | 5.3% | 4/75 | 5 | 75 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 101 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 |  |
| 102 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 103 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 104 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 105 | `removed_clip_halts_script` | 4.3% | 1/23 | 23 | 15 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 106 | `register_class_swf6` | 2.7% | 1/37 | 9 | 37 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [37](ruffle-tests/_investigation/blocked/REGISTERCLASS_PLAN.md) |
| 107 | `movieclip_state_values` | 2.6% | 3/114 | 7 | 114 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [24](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 108 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 109 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 |  |
| 110 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 111 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 112 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 113 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 114 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 115 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 116 | `global_proto_decls` | 0.2% | 11/4497 | 685 | 4497 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 117 | `global_instance_decls` | 0.1% | 1/758 | 327 | 758 | [18](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 118 | `global_proto_decls_delete` | 0.0% | 1/4158 | 309 | 4158 | [19](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 119 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [17](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) |
| 120 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [7](ruffle-tests/_investigation/blocked/CLONE_DUPLICATE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 121 | `custom_clip_methods` | 0.0% | 0/4 | 3 | 4 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 122 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 123 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 124 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 125 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 | [14](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) |
| 126 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 | [15](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) |
| 127 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 |  |
| 128 | `geturl` | 0.0% | 0/7 | 0 | 7 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 129 | `hittest_morph_input` | 0.0% | 0/1 | 0 | 1 | [20](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 130 | `interface_implements_op` | 0.0% | 0/47 | 46 | 47 | [34](ruffle-tests/_investigation/blocked/OOP_SUPER_EXTENDS_PLAN.md) |
| 131 | `issue_2084` | 0.0% | 0/16 | 0 | 16 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 132 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [25](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 133 | `mcl_loadclip_replace_root` | 0.0% | 0/1 | 0 | 1 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [30](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [38](ruffle-tests/_investigation/blocked/ROOT_REPLACEMENT_PLAN.md) |
| 134 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 135 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) |
| 136 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 137 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 138 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 139 | `root_button_mode` | 0.0% | 0/10 | 0 | 10 | [5](ruffle-tests/_investigation/blocked/BUTTON_PLAN.md) [23](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) |
| 140 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 141 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 142 | `string_paths_keyevents` | 0.0% | 0/1 | 1 | 0 | [56](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 143 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [44](ruffle-tests/_investigation/complete/STRING_PLAN.md) [48](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) |
| 144 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 145 | `unload_nested_child` | 0.0% | 0/5 | 0 | 5 | [29](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) [57](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 146 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 147 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 148 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |
| 149 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [59](ruffle-tests/_investigation/complete/XML_PLAN.md) |

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
| 14 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/incomplete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 0 | 7 |
| 15 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/blocked/FOCUS_SYSTEM_PLAN.md) | 7 | 5 | 2 |
| 16 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 17 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/blocked/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 1 | 2 |
| 18 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 19 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 26 | 5 |
| 20 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 5 | 12 |
| 21 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 22 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 23 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_PLAN.md) | 49 | 25 | 24 |
| 24 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 0 | 5 |
| 25 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 26 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 27 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 28 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 29 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/blocked/MOVIECLIP_PLAN.md) | 58 | 30 | 28 |
| 30 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 12 | 4 |
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
| 43 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 44 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 13 | 11 | 2 |
| 45 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 46 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/blocked/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 3 | 2 |
| 47 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/blocked/TAB_ORDERING_PLAN.md) | 16 | 14 | 2 |
| 48 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 14 | 5 |
| 49 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/blocked/TEXTFIELD_PLAN.md) | 70 | 47 | 23 |
| 50 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 51 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 52 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 53 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 3 | 1 | 2 |
| 54 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 55 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 0 | 2 |
| 56 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 4 | 12 |
| 57 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 12 | 10 | 2 |
| 58 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 4 | 1 |
| 59 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 195 | 155 | 40 |
