# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-19 02:28 UTC

**Git SHA**: `5002fe1163`

**Run Duration**: 165m 58s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **553** (89.3%) |
| Failing | 66 |
| Total expected lines | 91497 |
| Matching lines | 78501 (85.8%) |
| Mismatched lines | 12996 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 63 | 95.5% |
| Runtime Segfault | 2 | 3.0% |
| Timeout | 1 | 1.5% |

## Passing Tests

**553 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 16.0s |  |
| 2 | `action_to_integer` | 28 | 15.7s |  |
| 3 | `add` | 28 | 15.7s |  |
| 4 | `add2` | 354 | 16.0s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 15.7s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 15.8s |  |
| 7 | `add_swf5` | 28 | 15.7s |  |
| 8 | `arguments` | 127 | 15.7s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 15.7s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 15.8s |  |
| 11 | `array_constructor` | 30 | 15.8s |  |
| 12 | `array_enumerate` | 4 | 15.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 15.8s |  |
| 14 | `array_properties` | 36 | 15.7s |  |
| 15 | `array_prototyping` | 12 | 15.7s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 15.8s |  |
| 17 | `array_sort` | 161 | 16.7s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 15.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 15.8s |  |
| 20 | `array_trivial` | 209 | 15.8s |  |
| 21 | `as1_constructor_v6` | 35 | 15.7s |  |
| 22 | `as1_constructor_v7` | 35 | 15.9s |  |
| 23 | `as2_oop` | 13 | 15.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 15.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 16.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 15.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 15.6s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 15.5s |  |
| 29 | `as_broadcaster_undef` | 89 | 15.7s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 15.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 15.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 15.6s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 15.6s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 15.6s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 15.5s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 15.6s |  |
| 37 | `as_transformed_flag` | 20 | 15.5s |  |
| 38 | `asnative` | 34 | 15.5s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 15.6s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_swf_tag_past_eof` | 0 | 15.5s |  |
| 43 | `bitand` | 1058 | 18.5s |  |
| 44 | `bitmap_data` | 1126 | 18.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 45 | `bitmap_data_colortransform` | 0 | 15.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_compare` | 40 | 15.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_copypixels` | 17 | 16.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_draw_cliprect` | 13 | 15.8s |  |
| 49 | `bitmap_data_fillrect` | 0 | 15.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 50 | `bitmap_data_hittest` | 132 | 16.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 51 | `bitmap_data_max_size_swf10` | 12 | 15.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 52 | `bitmap_data_max_size_swf9` | 10 | 15.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_noise` | 631 | 15.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_perlinnoise` | 0 | 16.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_pixeldissolve_image` | 0 | 16.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_threshold` | 176 | 16.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 57 | `bitmapdata_applyfilter_colormatrix` | 0 | 16.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 58 | `bitmapdata_channels` | 19 | 15.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 59 | `bitor` | 1058 | 18.4s |  |
| 60 | `biturshift` | 14 | 16.2s |  |
| 61 | `biturshift_swf8` | 14 | 15.8s |  |
| 62 | `bitxor` | 1058 | 18.6s |  |
| 63 | `boxed_primitives` | 24 | 15.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 64 | `button_children` | 8 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_goto` | 4 | 15.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_key_events` | 14 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_key_events_special` | 45 | 16.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_keypress` | 3 | 16.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_keypress_vs_press` | 25 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_keypress_vs_tab` | 20 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_keypress_vs_textinput` | 4 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_order` | 2 | 15.7s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_properties_special_cases` | 22 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_v5` | 18 | 15.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `button_v6` | 18 | 15.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 76 | `call` | 63 | 16.1s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 77 | `call_method_empty_name` | 1 | 15.7s |  |
| 78 | `capabilities_resolution` | 8 | 15.8s |  |
| 79 | `catch_references_registers` | 2 | 15.8s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 80 | `click_block` | 5 | 15.7s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 81 | `clip_constructors` | 8 | 16.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 82 | `clip_event_propagation_order` | 17 | 17.1s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 83 | `clone_sprite_edittext` | 94 | 15.9s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 84 | `clone_sprite_edittext_dynamic` | 86 | 15.8s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 85 | `clone_sprite_types` | 24 | 15.5s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 86 | `closure_scope` | 7 | 15.5s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 87 | `coerce_to_object_monkeypatch` | 129 | 16.3s | [68](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 88 | `coerce_to_primitive_resolve` | 17 | 15.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 89 | `color` | 57 | 15.7s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 90 | `color_transform` | 48 | 16.0s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 91 | `conflicting_instance_names` | 23 | 15.8s |  |
| 92 | `constructor_function` | 2 | 15.4s |  |
| 93 | `context_menu` | 39 | 16.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 94 | `context_menu_item` | 41 | 16.5s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 95 | `create_empty_movie_clip` | 3 | 16.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 96 | `cross_movie_root` | 10 | 16.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 97 | `custom_clip_methods` | 4 | 17.0s | [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 98 | `default_names` | 52 | 15.7s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 99 | `define_function2` | 8 | 16.1s |  |
| 100 | `define_function2_preload` | 13 | 15.9s |  |
| 101 | `define_function2_preload_order` | 4 | 15.3s |  |
| 102 | `define_function_case_sensitive` | 2 | 15.3s |  |
| 103 | `define_local` | 27 | 15.2s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 104 | `define_local_with_paths` | 54 | 15.2s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 105 | `delete` | 3 | 15.3s |  |
| 106 | `device_font_spacing` | 91 | 15.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 107 | `display_object_properties` | 2 | 15.2s |  |
| 108 | `divide_swf4` | 107 | 15.3s |  |
| 109 | `do_init_action` | 3 | 15.2s |  |
| 110 | `do_init_action_child` | 12 | 15.3s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 111 | `drag_over_from_outside` | 1 | 15.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 112 | `drag_over_without_startdrag` | 1 | 15.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 113 | `duplicate_movie_clip_drawing` | 2 | 15.2s | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 114 | `edittext_align` | 60 | 15.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_align_trailing_spaces_swf7` | 576 | 15.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_align_trailing_spaces_swf8` | 576 | 15.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_antialiastype` | 296 | 15.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_autosize` | 71 | 15.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_autosize_setter` | 20 | 15.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_bullet` | 30 | 15.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_default_format` | 221 | 15.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_default_format_font_style` | 335 | 15.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_focus_selection` | 2 | 15.0s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_font_size` | 45 | 15.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_hscroll` | 27 | 15.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_html_align_swf7` | 52 | 15.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_html_align_swf8` | 52 | 15.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_html_color` | 114 | 15.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_html_condensewhite_swf7` | 311 | 15.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_html_condensewhite_swf8` | 311 | 15.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_html_entity` | 4 | 15.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_html_roundtrip` | 17 | 15.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_html_swf6` | 5377 | 16.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_html_swf7` | 5377 | 16.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_swf8` | 5377 | 16.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_input` | 1 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_input_newlines` | 9 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_leading` | 9 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_letter_spacing` | 15 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_margins` | 25 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_newline_stripping` | 64 | 20.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_newlines` | 30 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_password` | 5 | 15.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_password_copy` | 4 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_paste_empty` | 2 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_place_caret` | 2 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_programmatic_focus` | 12 | 15.5s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_restrict` | 191 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_restrict_paste` | 5 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_scroll` | 54 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_stylesheet` | 325 | 16.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_tab_focus` | 13 | 15.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_tab_stops` | 60 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_tag_indent` | 31 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_text_height_leading` | 20 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_underline` | 40 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_width_height` | 103 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `empty_movieclip_can_attach_movies` | 11 | 15.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 159 | `enumerate` | 64 | 15.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 160 | `equals` | 32 | 15.5s |  |
| 161 | `equals2_swf5` | 926 | 17.1s |  |
| 162 | `equals2_swf6` | 926 | 17.1s |  |
| 163 | `equals2_swf7` | 926 | 17.2s |  |
| 164 | `equals_swf4` | 665 | 16.6s |  |
| 165 | `equals_swf4_alt` | 32 | 15.9s |  |
| 166 | `equals_swf5` | 32 | 15.8s |  |
| 167 | `error` | 58 | 15.6s |  |
| 168 | `escape` | 14 | 15.6s |  |
| 169 | `execution_order1` | 5 | 15.7s |  |
| 170 | `execution_order2` | 7 | 15.7s |  |
| 171 | `execution_order3` | 4 | 15.6s |  |
| 172 | `execution_order4` | 12 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 173 | `export_assets` | 3 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 174 | `extends_chain` | 134 | 16.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 175 | `extends_native_type` | 11 | 15.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 176 | `external_interface` | 84 | 15.8s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 177 | `external_interface_escapexml` | 26 | 15.7s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 178 | `external_interface_jsquotestring` | 21 | 17.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 179 | `external_interface_toas_basic` | 354 | 16.1s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 180 | `external_interface_toxml_array` | 25 | 15.7s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 181 | `external_interface_toxml_basic` | 179 | 15.9s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 182 | `external_interface_unescapexml` | 40 | 15.8s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 183 | `focus_keyboard_press` | 60 | 16.4s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 184 | `focus_mouse` | 45 | 16.2s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 185 | `focus_mouse_focusable` | 8 | 16.9s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 186 | `focus_mouse_rollout` | 4 | 16.4s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 187 | `focus_remove` | 33 | 16.3s |  |
| 188 | `focus_root_movie` | 2 | 16.1s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 189 | `focus_visibility_change` | 45 | 16.2s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 190 | `focusrect_focuslost` | 4 | 16.2s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 191 | `focusrect_mouse_swf8` | 0 | 15.1s |  |
| 192 | `focusrect_mouse_swf9` | 0 | 14.5s |  |
| 193 | `focusrect_property_swf5` | 1237 | 14.6s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 194 | `focusrect_property_swf6` | 1237 | 15.1s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 195 | `focusrect_property_swf7` | 1237 | 14.6s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 196 | `focusrect_swf5` | 6 | 14.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 197 | `focusrect_swf6` | 42 | 14.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 198 | `form_loader_encoding_1` | 1 | 14.3s |  |
| 199 | `frame_size_translated_negative` | 21 | 14.5s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 200 | `frame_size_translated_positive` | 21 | 14.8s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 201 | `function_as_function` | 35 | 14.3s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 202 | `function_base_clip` | 8 | 14.3s |  |
| 203 | `function_base_clip_readded` | 11 | 14.4s |  |
| 204 | `function_base_clip_removed` | 25 | 14.5s |  |
| 205 | `function_suppress_and_preload` | 28 | 14.5s |  |
| 206 | `funky_function_calls` | 56 | 14.4s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 207 | `get_bytes_total` | 4 | 14.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 208 | `get_variable_in_scope` | 29 | 14.4s |  |
| 209 | `getproperty` | 28 | 18.8s |  |
| 210 | `getproperty_swf4` | 28 | 15.9s |  |
| 211 | `getproperty_swf5` | 28 | 15.8s |  |
| 212 | `gettextextent` | 56 | 16.0s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 213 | `global_array` | 3 | 15.7s |  |
| 214 | `global_is_bare` | 7 | 15.9s |  |
| 215 | `global_swf5_6_7_8_9` | 1145 | 16.4s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 216 | `global_swf6_7_8` | 15 | 16.0s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 217 | `globals_swf5` | 304 | 16.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 218 | `globals_swf6` | 304 | 15.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 219 | `globals_swf7` | 304 | 15.8s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 220 | `globals_swf8` | 304 | 15.9s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 221 | `goto_advance1` | 6 | 15.6s |  |
| 222 | `goto_advance2` | 2 | 15.8s |  |
| 223 | `goto_both_ways1` | 3 | 15.8s |  |
| 224 | `goto_both_ways2` | 3 | 15.9s |  |
| 225 | `goto_execution_order` | 2 | 16.0s |  |
| 226 | `goto_execution_order2` | 2 | 15.9s |  |
| 227 | `goto_frame` | 12 | 15.8s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 228 | `goto_frame2` | 44 | 16.2s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 229 | `goto_frame_number` | 3 | 15.7s |  |
| 230 | `goto_label` | 17 | 15.9s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 231 | `goto_methods` | 40 | 15.8s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 232 | `goto_rewind1` | 1 | 15.7s |  |
| 233 | `goto_rewind2` | 3 | 15.6s |  |
| 234 | `goto_rewind3` | 2 | 15.6s |  |
| 235 | `greater_swf6` | 1175 | 17.7s |  |
| 236 | `greater_swf7` | 1175 | 17.7s |  |
| 237 | `greaterthan_swf5` | 1 | 15.6s |  |
| 238 | `greaterthan_swf8` | 1 | 15.5s |  |
| 239 | `has_own_property` | 32 | 15.7s |  |
| 240 | `hittest_lockroot` | 15 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 241 | `hittest_morph` | 70 | 15.6s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 242 | `hittest_morph_input` | 1 | 15.5s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 243 | `hittest_winding_rule` | 12 | 15.7s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 244 | `infinite_recursion_function` | 4 | 15.6s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 245 | `infinite_recursion_function_in_setter` | 131 | 15.7s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 246 | `infinite_recursion_virtual_property` | 67 | 15.6s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 247 | `init_array_invalid` | 4 | 15.7s |  |
| 248 | `init_object_invalid` | 4 | 15.3s |  |
| 249 | `init_object_order` | 15 | 15.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 250 | `input_dead_keys_windows` | 15 | 15.5s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 251 | `instanceof_coercions` | 88 | 15.7s | [68](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 252 | `interface_implements_op` | 47 | 15.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 253 | `is_finite` | 49 | 15.2s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 254 | `is_finite_swf6` | 49 | 15.3s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 255 | `is_prototype_of` | 89 | 15.5s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 256 | `issue_1086` | 1 | 15.2s |  |
| 257 | `issue_1671` | 0 | 15.2s |  |
| 258 | `issue_1906` | 4 | 15.3s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 259 | `issue_2030` | 4 | 15.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 260 | `issue_2084` | 16 | 15.7s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 261 | `issue_2166` | 9 | 15.3s |  |
| 262 | `issue_3169` | 2 | 15.6s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 263 | `issue_3446` | 1 | 15.6s |  |
| 264 | `issue_3522` | 2 | 15.4s |  |
| 265 | `issue_4377` | 2 | 15.5s |  |
| 266 | `issue_710` | 4 | 17.1s |  |
| 267 | `issue_768` | 3 | 16.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 268 | `issue_9327` | 2 | 16.9s |  |
| 269 | `issue_9885` | 2 | 16.4s |  |
| 270 | `key_isToggled` | 9 | 16.4s |  |
| 271 | `lessthan` | 41 | 16.5s |  |
| 272 | `lessthan2_swf5` | 1226 | 18.5s |  |
| 273 | `lessthan2_swf6` | 1226 | 18.3s |  |
| 274 | `lessthan2_swf7` | 1226 | 18.6s |  |
| 275 | `lessthan_swf4` | 902 | 17.3s |  |
| 276 | `lessthan_swf4_alt` | 41 | 16.1s |  |
| 277 | `lessthan_swf5` | 41 | 16.4s |  |
| 278 | `loadmovie` | 2 | 16.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 279 | `loadmovie_fail` | 2 | 16.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 280 | `loadmovie_flashvars` | 4 | 16.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 281 | `loadmovie_method` | 2 | 16.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 282 | `loadmovie_registerclass` | 30 | 16.8s | [11](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 283 | `loadmovie_replace_root` | 5 | 16.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 284 | `loadmovie_var_persistence` | 8 | 16.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 285 | `loadmovienum` | 3 | 16.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 286 | `loadmovienum_cross_version_prototype` | 9 | 16.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 287 | `loadvariables` | 2 | 16.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 288 | `loadvariables2` | 8 | 16.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 289 | `loadvariablesnum` | 2 | 17.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 290 | `local_to_global` | 49 | 17.4s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 291 | `localconnection_properties` | 8 | 16.8s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 292 | `lock_root` | 1 | 16.5s |  |
| 293 | `logical_ops_swf4` | 90 | 16.2s |  |
| 294 | `logical_ops_swf8` | 108 | 16.6s |  |
| 295 | `looping` | 6 | 16.7s |  |
| 296 | `mask_reapply` | 0 | 17.2s |  |
| 297 | `mask_with_drawing` | 0 | 16.7s |  |
| 298 | `math_min_max` | 101 | 17.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 299 | `math_swf6` | 530 | 17.5s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 300 | `math_swf7` | 530 | 17.5s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 301 | `math_swf8` | 530 | 17.4s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 302 | `matrix` | 171 | 17.6s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 303 | `mcl_as_broadcaster` | 12 | 16.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 304 | `mcl_events_swf_version` | 232 | 17.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mcl_getprogress` | 30 | 16.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 306 | `mcl_loadclip` | 149 | 16.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 307 | `mcl_loadclip_properties` | 6 | 16.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 308 | `mcl_loadclip_replace_root` | 1 | 16.4s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 309 | `mcl_mislabeled_target` | 6 | 16.3s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 310 | `mcl_target_gif87a` | 6 | 16.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 311 | `mcl_target_gif89a` | 6 | 16.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mcl_target_jpg` | 6 | 16.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_target_png` | 6 | 15.9s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_unloadclip` | 5 | 16.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mouse_events` | 8 | 16.3s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 316 | `mouse_events_visible_enabled` | 12 | 16.3s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 317 | `mouse_hover_events_while_dragging` | 1 | 16.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 318 | `mouse_listeners` | 67 | 16.2s |  |
| 319 | `mouse_pos` | 665 | 16.1s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 320 | `mouse_pos_with_scale_factor` | 260 | 16.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 321 | `mouse_wheel_enabled` | 2 | 16.2s |  |
| 322 | `movieclip_begin_gradient_fill` | 0 | 16.9s |  |
| 323 | `movieclip_blend_mode_property` | 35 | 16.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 324 | `movieclip_create_text_field` | 90 | 16.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 325 | `movieclip_default_state` | 69 | 15.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 326 | `movieclip_depth_methods` | 98 | 15.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 327 | `movieclip_focusenabled` | 99 | 15.8s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 328 | `movieclip_get_instance_at_depth` | 28 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_getbounds` | 191 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_gettextsnapshot` | 112 | 15.9s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_hittest` | 92 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_in_removed_button` | 4 | 15.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 333 | `movieclip_init_object` | 5 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 334 | `movieclip_invalid_get_bounds_1` | 75 | 16.2s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_invalid_get_bounds_2` | 75 | 16.2s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_invalid_get_bounds_3` | 13 | 15.9s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_invalid_get_bounds_4` | 13 | 15.7s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_invalid_get_bounds_5` | 11 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_invalid_get_bounds_6` | 10 | 39.5s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_invalid_get_bounds_7` | 10 | 39.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_invalid_get_bounds_8` | 11 | 15.9s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_line_gradient_style` | 0 | 16.2s |  |
| 343 | `movieclip_lockroot` | 29 | 16.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_name_from_timeline` | 13 | 15.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_prototype_extension` | 5 | 15.3s |  |
| 346 | `movieclip_setmask` | 14 | 15.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 347 | `moviecliploader_flashvars` | 4 | 15.5s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 348 | `mutable_this` | 18 | 15.6s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 349 | `named_shapes` | 14 | 15.6s |  |
| 350 | `nan_scale` | 9 | 15.7s |  |
| 351 | `native_double_construct` | 12 | 15.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 352 | `native_objects_swf7` | 84 | 16.0s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 353 | `native_objects_swf8` | 84 | 15.8s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 354 | `native_subclasses` | 191 | 15.9s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 355 | `nested_textfields_in_buttons` | 0 | 15.4s |  |
| 356 | `new_method_wrap` | 4 | 15.9s |  |
| 357 | `new_object_enumerate` | 7 | 15.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 358 | `new_object_wrap` | 4 | 15.7s |  |
| 359 | `o` | 3 | 15.7s |  |
| 360 | `object_constructor` | 33 | 15.7s |  |
| 361 | `object_function` | 32 | 15.7s |  |
| 362 | `object_properties` | 31 | 15.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 363 | `object_prototypes` | 74 | 15.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 364 | `object_resolve` | 38 | 15.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 365 | `object_string_coerce_swf5` | 62 | 15.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 366 | `object_string_coerce_swf6` | 68 | 15.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 367 | `parse_float` | 74 | 15.8s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 368 | `parse_int` | 64 | 15.9s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 369 | `path_string` | 322 | 15.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 370 | `place_and_lookup` | 30 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 371 | `placeobject_occupied_depth` | 6 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 372 | `point` | 175 | 16.3s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 373 | `primitive_instanceof` | 37 | 15.6s |  |
| 374 | `primitive_type_globals` | 557 | 15.8s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 375 | `printjob_props_swf5` | 45 | 17.7s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 376 | `printjob_props_swf6` | 45 | 15.9s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 377 | `printjob_props_swf7` | 45 | 16.0s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 378 | `property_invalid_base_clip` | 36 | 15.9s |  |
| 379 | `prototype_delete` | 12 | 15.9s |  |
| 380 | `prototype_enumerate` | 5 | 15.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 381 | `prototype_properties` | 17 | 15.8s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 382 | `rectangle` | 745 | 16.4s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 383 | `recursive_prototypes` | 0 | 16.3s |  |
| 384 | `register_and_init_order` | 231 | 16.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 385 | `register_class` | 66 | 16.1s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 386 | `register_class_return_value` | 16 | 16.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 387 | `register_class_swf6` | 37 | 16.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 388 | `register_class_with_sound` | 11 | 16.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 389 | `register_globals_across_frames` | 15 | 16.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 390 | `register_underflow` | 26 | 15.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 391 | `remove_movie_clip` | 29 | 16.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 392 | `removed_clip_halts_script` | 15 | 16.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 393 | `removed_target_clip_scope` | 35 | 16.1s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 394 | `resolve_different_root` | 2 | 15.8s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 395 | `rewind_depth` | 30 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 396 | `root_button_mode` | 10 | 15.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 397 | `root_global_parent` | 6 | 15.5s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 398 | `root_onload` | 1 | 15.4s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 399 | `sandbox_type_local_file` | 1 | 15.4s |  |
| 400 | `sandbox_type_local_network` | 1 | 15.4s |  |
| 401 | `selection` | 454 | 15.6s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 402 | `selection_handlers` | 27 | 15.5s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 403 | `set_interval` | 27 | 15.6s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 404 | `set_variable_scope` | 58 | 15.4s |  |
| 405 | `single_frame` | 1 | 15.4s |  |
| 406 | `slash_syntax` | 14 | 15.4s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 407 | `sound` | 628 | 15.8s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 408 | `sound_props_swf5` | 68 | 17.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 409 | `sound_props_swf6` | 68 | 15.9s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 410 | `sound_start_load` | 0 | 15.8s |  |
| 411 | `stage_display_state` | 16 | 15.9s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 412 | `stage_object_children` | 83 | 15.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 413 | `stage_object_enumerate` | 4 | 15.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 414 | `stage_object_properties` | 241 | 16.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 415 | `stage_object_properties_get_var` | 5 | 15.9s |  |
| 416 | `stage_object_properties_swf6` | 231 | 16.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 417 | `stage_property_representation` | 586 | 15.8s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 418 | `stage_scale_mode` | 39 | 15.7s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 419 | `strictequals_swf6` | 902 | 17.3s |  |
| 420 | `strictly_equals` | 7 | 15.7s |  |
| 421 | `string_coercion` | 117 | 16.1s | [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 422 | `string_methods` | 285 | 16.2s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 423 | `string_methods_negative_args` | 240 | 16.0s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 424 | `string_methods_swfv5` | 275 | 16.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 425 | `string_ops_swf6` | 95 | 16.6s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 426 | `string_paths_basic` | 4 | 16.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 427 | `string_paths_eval` | 4 | 16.6s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 428 | `string_paths_eval2` | 7 | 15.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 429 | `string_paths_hidden` | 54 | 15.6s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 430 | `string_paths_keyevents` | 0 | 15.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 431 | `string_paths_other` | 36 | 15.5s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 432 | `string_paths_timer` | 0 | 15.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 433 | `string_paths_unload` | 1 | 15.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 434 | `string_paths_variable_alias` | 4 | 15.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 435 | `string_paths_variable_scopes` | 5 | 15.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 436 | `stylesheet` | 283 | 16.2s |  |
| 437 | `stylesheet_transform` | 750 | 16.2s |  |
| 438 | `super_edge_cases` | 39 | 15.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 439 | `swf4_actions_bool` | 96 | 15.4s |  |
| 440 | `swf4_actions_coercion_order` | 158 | 15.4s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 441 | `swf4_bool` | 4 | 15.2s |  |
| 442 | `swf4_function_calls` | 7 | 15.3s |  |
| 443 | `swf5_encoding` | 3 | 15.2s |  |
| 444 | `swf5_global_funcs` | 232 | 15.3s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 445 | `swf5_no_closure` | 19 | 15.4s | [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 446 | `swf5_to_6_cross_call` | 29 | 15.8s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 447 | `swf6_case_insensitive` | 42 | 15.6s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 448 | `swf6_global_funcs` | 232 | 15.6s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 449 | `swf6_string_as_bool` | 15 | 15.5s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 450 | `swf6_to_5_cross_call` | 29 | 15.6s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 451 | `swf7_case_sensitive` | 44 | 15.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 452 | `swf7_global_funcs` | 232 | 15.5s | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 453 | `tab_ordering_automatic_basic` | 92 | 15.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 454 | `tab_ordering_automatic_order_grid` | 21 | 15.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 455 | `tab_ordering_automatic_order_same_position` | 12 | 15.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 456 | `tab_ordering_children` | 208 | 15.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 457 | `tab_ordering_custom_basic` | 71 | 15.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 458 | `tab_ordering_custom_duplicate_index` | 22 | 15.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 459 | `tab_ordering_custom_i32_vs_u32` | 12 | 15.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 460 | `tab_ordering_custom_m1` | 29 | 15.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 461 | `tab_ordering_events` | 150 | 15.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 462 | `tab_ordering_events_mouse` | 65 | 15.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 463 | `tab_ordering_movieclip_enabled_default` | 462 | 15.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 464 | `tab_ordering_properties` | 293 | 15.5s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 465 | `tab_ordering_reverse` | 51 | 15.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 466 | `tab_ordering_tabbable` | 47 | 15.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 467 | `target_clip_removed` | 5 | 15.6s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 468 | `target_clip_swf5` | 2 | 15.6s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 469 | `target_clip_swf6` | 2 | 15.6s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 470 | `target_path` | 14 | 15.5s |  |
| 471 | `tell_target` | 37 | 15.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 472 | `tell_target_invalid` | 6 | 15.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 473 | `tell_target_invalid_swf6` | 5 | 15.6s | [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 474 | `text_blocks_clicks` | 4 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 475 | `text_format` | 1146 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 476 | `text_format_display` | 21 | 15.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 477 | `text_format_font_max_length` | 2 | 15.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 478 | `text_format_get_text_extent_undefined_width` | 10 | 15.4s |  |
| 479 | `text_format_rounding_swf7` | 840 | 15.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 480 | `text_format_rounding_swf8` | 840 | 15.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 481 | `textfield_background_color` | 11 | 15.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 482 | `textfield_border_color` | 11 | 15.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 483 | `textfield_cache_as_bitmap` | 1 | 15.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 484 | `textfield_maxchars` | 3 | 16.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 485 | `textfield_properties` | 44 | 16.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 486 | `textfield_props_swf5` | 175 | 16.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 487 | `textfield_props_swf6` | 210 | 16.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 488 | `textfield_props_swf7` | 210 | 16.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 489 | `textfield_props_swf8` | 210 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 490 | `textfield_text` | 7 | 16.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 491 | `textfield_variable` | 81 | 16.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 492 | `textsnapshot_available_text` | 20 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 493 | `textsnapshot_findtext` | 44 | 16.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 494 | `textsnapshot_gettext` | 55 | 16.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 495 | `textsnapshot_props_swf5` | 56 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 496 | `textsnapshot_props_swf6` | 56 | 15.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `textsnapshot_text_order` | 1 | 16.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 498 | `this_scoping` | 52 | 15.6s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 499 | `this_swf5` | 41 | 15.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 500 | `this_swf6` | 41 | 15.8s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 501 | `this_swf7` | 41 | 15.8s | [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 502 | `timeline_function_def` | 7 | 15.7s |  |
| 503 | `timer_run_actions` | 18 | 16.0s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 504 | `trace` | 8 | 15.7s |  |
| 505 | `transform` | 70 | 15.7s | [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 506 | `try_catch_finally` | 118 | 15.7s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 507 | `try_finally_simple` | 16 | 15.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 508 | `typeof` | 22 | 15.6s |  |
| 509 | `typeof_globals` | 7 | 15.6s |  |
| 510 | `uncaught_exception` | 1 | 15.5s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 511 | `uncaught_exception_bubbled` | 1 | 15.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 512 | `undefined_to_string_swf6` | 4 | 15.6s |  |
| 513 | `unescape` | 43 | 15.5s |  |
| 514 | `unload_nested_child` | 5 | 15.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 515 | `unloadmovie` | 4 | 15.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 516 | `unloadmovie_method` | 3 | 15.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 517 | `unloadmovienum` | 13 | 15.7s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 518 | `use_hand_cursor` | 8 | 15.6s |  |
| 519 | `variable_args` | 5 | 15.7s |  |
| 520 | `waitforframe` | 7 | 15.5s |  |
| 521 | `waitforframe2` | 16 | 17.6s |  |
| 522 | `watch` | 117 | 15.9s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 523 | `watch_textfield` | 12 | 15.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 524 | `watch_virtual_property_proto` | 2 | 15.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 525 | `with` | 49 | 15.6s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 526 | `with_return` | 2 | 15.6s |  |
| 527 | `with_variable_scopes` | 43 | 16.0s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 528 | `xml` | 15 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 529 | `xml_append_child` | 28 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 530 | `xml_append_child_with_parent` | 20 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 531 | `xml_attributes_read` | 4 | 15.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_cdata` | 11 | 15.5s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_child_nodes_edge_cases` | 4 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_clone_expandos` | 19 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 535 | `xml_first_last_child` | 8 | 15.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 536 | `xml_has_child_nodes` | 3 | 15.5s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 537 | `xml_idmap` | 21 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 538 | `xml_ignore_comments` | 21 | 15.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_ignore_white` | 34 | 16.5s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 540 | `xml_insert_before` | 20 | 16.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 541 | `xml_inspect_createmethods` | 15 | 15.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 542 | `xml_inspect_doctype` | 7 | 15.9s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_inspect_parsexml` | 62 | 15.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_inspect_xmldecl` | 7 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 545 | `xml_namespaces` | 203 | 15.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 546 | `xml_parent_and_child` | 5 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 547 | `xml_remove_node` | 22 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_reparenting` | 14 | 15.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_siblings` | 10 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_to_string` | 13 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_to_string_comment` | 1 | 15.6s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_unescaping` | 23 | 15.7s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 553 | `xmlnode_proto` | 1 | 15.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83 | 84 | 1 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97 | 100 | 3 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 7 | `movieclip_hittest_shapeflag` | 92.3% | 312 | 338 | 26 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 8 | `duplicate_movie_clip` | 80.0% | 16 | 20 | 4 | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 10 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 18.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 32.5s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 45.8s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**63 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 98.8% | 83/84 | 84 | 84 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 5 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 6 | `edittext_default_format_empty` | 97.0% | 97/100 | 100 | 100 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 7 | `movieclip_hittest_shapeflag` | 92.3% | 312/338 | 338 | 338 | [26](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 8 | `duplicate_movie_clip` | 80.0% | 16/20 | 16 | 20 | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 10 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 11 | `unload` | 48.1% | 25/52 | 50 | 52 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 12 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 13 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 14 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 15 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 16 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 18 | `on_construct` | 32.0% | 8/25 | 12 | 25 | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 19 | `tab_ordering_properties_tab_index_edge_case` | 25.0% | 1/4 | 4 | 4 |  |
| 20 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 21 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 22 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 23 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 24 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 25 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 26 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 27 | `bitmap_data_pixeldissolve` | 7.6% | 82/1075 | 1055 | 1075 | [5](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 28 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 29 | `clip_events` | 5.3% | 1/19 | 12 | 19 | [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 30 | `netstream_play_flv` | 4.8% | 1/21 | 2 | 21 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 31 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 32 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 33 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 34 | `global_instance_decls` | 2.4% | 18/758 | 695 | 758 | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 35 | `global_proto_decls_delete` | 2.2% | 91/4158 | 705 | 4158 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 36 | `global_proto_decls` | 2.1% | 93/4497 | 1266 | 4497 | [25](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) |
| 37 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 38 | `netconnection_send_remote` | 2.0% | 1/50 | 11 | 50 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 39 | `sound_id3` | 1.7% | 11/633 | 11 | 633 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 40 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 41 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 42 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 43 | `bad_placeobject_clipaction` | 0.0% | 0/2 | 0 | 2 |  |
| 44 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 45 | `drag_drop` | 0.0% | 0/10 | 0 | 10 | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 46 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 6 | 7 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 47 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 48 | `geturl` | 0.0% | 0/7 | 0 | 7 | [69](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 49 | `issue_1104` | 0.0% | 0/2 | 0 | 2 | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 50 | `issue_2870` | 0.0% | 0/3 | 1 | 3 | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 51 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 52 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 53 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 54 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 55 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 56 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 57 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) |
| 58 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 59 | `unload_clip_event` | 0.0% | 0/4 | 2 | 4 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 60 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 61 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 62 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 63 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) | 17 | 15 | 2 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 5 | 3 |
| 9 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 10 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 11 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 12 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 13 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 14 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 15 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 3 | 1 |
| 16 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 1 | 1 |
| 17 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 18 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 19 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 20 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 21 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 22 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 5 | 2 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) | 31 | 27 | 4 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 0 | 23 |
| 28 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 30 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 1 | 1 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 42 | 6 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 36 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 58 | 48 | 10 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 42 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 44 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 45 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 46 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 47 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 48 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 14 | 1 |
| 49 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 50 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 51 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 52 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 53 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 54 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 55 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 56 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 13 | 12 | 1 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) | 19 | 17 | 2 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 67 | 3 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 65 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 12 | 4 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 9 | 3 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 152 | 150 | 2 |
