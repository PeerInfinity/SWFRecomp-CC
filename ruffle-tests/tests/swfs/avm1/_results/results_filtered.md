# Ruffle Test Results (Filtered)

**Date**: 2026-04-02 01:29 UTC

**Git SHA**: `33b4d52d15`

**Run Duration**: 183m 7s

**Filtered**: 51 tests ignored out of 620 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 569 |
| Passing | **556** (97.7%) |
| Failing | 13 |
| Total expected lines | 80848 |
| Matching lines | 70683 (87.4%) |
| Mismatched lines | 10165 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**556 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 17.4s |  |
| 2 | `action_to_integer` | 28 | 17.5s |  |
| 3 | `add` | 28 | 17.4s |  |
| 4 | `add2` | 354 | 17.7s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 17.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 17.4s |  |
| 7 | `add_swf5` | 28 | 17.4s |  |
| 8 | `arguments` | 127 | 17.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 17.4s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 17.4s |  |
| 11 | `array_constructor` | 30 | 17.4s |  |
| 12 | `array_enumerate` | 4 | 17.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 17.3s |  |
| 14 | `array_properties` | 36 | 17.4s |  |
| 15 | `array_prototyping` | 12 | 17.4s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 17.4s |  |
| 17 | `array_sort` | 161 | 18.1s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 17.4s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 17.5s |  |
| 20 | `array_trivial` | 209 | 17.5s |  |
| 21 | `as1_constructor_v6` | 35 | 17.4s |  |
| 22 | `as1_constructor_v7` | 35 | 16.2s |  |
| 23 | `as2_oop` | 13 | 16.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 16.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 16.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 16.1s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 15.9s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_undef` | 89 | 16.1s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 29 | `as_set_prop_flags` | 79 | 16.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 30 | `as_set_prop_flags_version` | 31 | 15.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version_swf5` | 1 | 16.0s |  |
| 32 | `as_set_prop_flags_version_swf6` | 1 | 16.0s |  |
| 33 | `as_set_prop_flags_version_swf7` | 1 | 16.0s |  |
| 34 | `as_set_prop_flags_version_swf8` | 1 | 15.8s |  |
| 35 | `as_set_prop_flags_version_swf9` | 1 | 15.8s |  |
| 36 | `as_transformed_flag` | 20 | 15.9s |  |
| 37 | `asnative` | 34 | 16.0s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 38 | `asnew` | 34 | 16.1s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `attach_movie` | 59 | 16.0s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 40 | `attach_movie_stop` | 3 | 16.0s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 41 | `bad_placeobject_clipaction` | 2 | 19.4s |  |
| 42 | `bad_swf_tag_past_eof` | 0 | 17.7s |  |
| 43 | `bitand` | 1058 | 22.2s |  |
| 44 | `bitmap_data_colortransform` | 0 | 18.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 45 | `bitmap_data_draw_cliprect` | 13 | 17.8s |  |
| 46 | `bitmap_data_fillrect` | 0 | 18.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 47 | `bitmap_data_hittest` | 132 | 18.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 48 | `bitmap_data_max_size_swf10` | 12 | 18.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_max_size_swf9` | 10 | 18.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 50 | `bitmap_data_perlinnoise` | 0 | 19.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 51 | `bitmap_data_pixeldissolve_image` | 0 | 18.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmapdata_applyfilter_colormatrix` | 0 | 17.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 53 | `bitmapdata_channels` | 19 | 17.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitor` | 1058 | 20.5s |  |
| 55 | `biturshift` | 14 | 16.9s |  |
| 56 | `biturshift_swf8` | 14 | 17.0s |  |
| 57 | `bitxor` | 1058 | 19.9s |  |
| 58 | `boxed_primitives` | 24 | 17.4s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 59 | `button_children` | 8 | 17.3s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 60 | `button_goto` | 4 | 17.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 61 | `button_key_events` | 14 | 17.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 62 | `button_key_events_special` | 45 | 17.8s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 63 | `button_keypress` | 3 | 17.3s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 64 | `button_keypress_vs_press` | 25 | 17.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 65 | `button_keypress_vs_tab` | 20 | 17.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_keypress_vs_textinput` | 4 | 17.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_order` | 2 | 17.3s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_properties_special_cases` | 22 | 17.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_v5` | 18 | 17.0s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_v6` | 18 | 17.1s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `call` | 63 | 17.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 72 | `call_method_empty_name` | 1 | 16.9s |  |
| 73 | `capabilities_resolution` | 8 | 17.1s |  |
| 74 | `catch_references_registers` | 2 | 17.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 75 | `click_block` | 5 | 17.1s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 76 | `clip_constructors` | 8 | 18.0s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 77 | `clip_event_propagation_order` | 17 | 17.8s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 78 | `clip_events` | 19 | 18.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 79 | `clone_sprite_edittext` | 94 | 18.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 80 | `clone_sprite_edittext_dynamic` | 86 | 18.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 81 | `clone_sprite_types` | 24 | 17.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 82 | `closure_scope` | 7 | 18.0s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 83 | `coerce_to_object_monkeypatch` | 129 | 18.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 84 | `coerce_to_primitive_resolve` | 17 | 18.1s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 85 | `color` | 57 | 18.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 86 | `color_transform` | 48 | 18.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 87 | `conflicting_instance_names` | 23 | 17.9s |  |
| 88 | `constructor_function` | 2 | 17.7s |  |
| 89 | `context_menu` | 39 | 17.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 90 | `context_menu_item` | 41 | 17.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 91 | `create_empty_movie_clip` | 3 | 17.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 92 | `cross_movie_root` | 10 | 17.7s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 93 | `custom_clip_methods` | 4 | 17.9s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 94 | `default_names` | 52 | 17.7s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 95 | `define_function2` | 8 | 17.5s |  |
| 96 | `define_function2_preload` | 13 | 18.1s |  |
| 97 | `define_function2_preload_order` | 4 | 17.4s |  |
| 98 | `define_function_case_sensitive` | 2 | 17.3s |  |
| 99 | `define_local` | 27 | 17.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 100 | `define_local_with_paths` | 54 | 17.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 101 | `delete` | 3 | 17.5s |  |
| 102 | `device_font_spacing` | 91 | 17.7s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 103 | `display_object_properties` | 2 | 17.4s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 104 | `divide_swf4` | 107 | 17.6s |  |
| 105 | `do_init_action` | 3 | 17.5s |  |
| 106 | `do_init_action_child` | 12 | 17.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 107 | `drag_drop` | 10 | 17.4s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 108 | `drag_over_from_outside` | 1 | 17.5s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 109 | `drag_over_without_startdrag` | 1 | 17.6s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 110 | `duplicate_movie_clip` | 20 | 17.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 111 | `duplicate_movie_clip_drawing` | 2 | 17.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 112 | `edittext_align` | 60 | 17.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 113 | `edittext_align_trailing_spaces_swf7` | 576 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 114 | `edittext_align_trailing_spaces_swf8` | 576 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 115 | `edittext_antialiastype` | 296 | 17.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 116 | `edittext_autosize` | 71 | 17.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 117 | `edittext_autosize_setter` | 20 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 118 | `edittext_bullet` | 30 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_default_format` | 221 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_default_format_font_style` | 335 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_drag_select` | 9 | 17.3s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_focus_selection` | 2 | 17.2s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_font_size` | 45 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_hscroll` | 27 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_html_align_swf7` | 52 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_html_align_swf8` | 52 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_html_color` | 114 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_html_condensewhite_swf7` | 311 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_html_condensewhite_swf8` | 311 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_html_entity` | 4 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_html_roundtrip` | 17 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_html_swf6` | 5377 | 18.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_html_swf7` | 5377 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_html_swf8` | 5377 | 18.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_input` | 1 | 17.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_input_newlines` | 9 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_leading` | 9 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_letter_spacing` | 15 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_margins` | 25 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_newline_stripping` | 64 | 22.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_newlines` | 30 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_password` | 5 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_password_copy` | 4 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_paste_empty` | 2 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_place_caret` | 2 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_programmatic_focus` | 12 | 17.1s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_restrict` | 191 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_restrict_paste` | 5 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_scroll` | 54 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_stylesheet` | 325 | 18.0s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_tab_focus` | 13 | 17.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_tab_stops` | 60 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_tag_indent` | 31 | 17.2s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_text_height_leading` | 20 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_underline` | 40 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_width_height` | 103 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `empty_movieclip_can_attach_movies` | 11 | 17.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 158 | `enumerate` | 64 | 17.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 159 | `equals` | 32 | 17.0s |  |
| 160 | `equals2_swf5` | 926 | 18.8s |  |
| 161 | `equals2_swf6` | 926 | 18.4s |  |
| 162 | `equals2_swf7` | 926 | 18.5s |  |
| 163 | `equals_swf4` | 665 | 17.8s |  |
| 164 | `equals_swf4_alt` | 32 | 17.0s |  |
| 165 | `equals_swf5` | 32 | 17.2s |  |
| 166 | `error` | 58 | 17.0s |  |
| 167 | `escape` | 14 | 17.0s |  |
| 168 | `execution_order1` | 5 | 17.2s |  |
| 169 | `execution_order2` | 7 | 17.1s |  |
| 170 | `execution_order3` | 4 | 17.2s |  |
| 171 | `execution_order4` | 12 | 17.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 172 | `export_assets` | 3 | 17.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 173 | `extends_chain` | 134 | 17.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 174 | `extends_native_type` | 11 | 17.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 175 | `external_interface` | 84 | 17.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 176 | `external_interface_escapexml` | 26 | 17.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 177 | `external_interface_jsquotestring` | 21 | 17.6s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 178 | `external_interface_toas_basic` | 354 | 17.7s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 179 | `external_interface_toxml_array` | 25 | 17.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 180 | `external_interface_toxml_basic` | 179 | 17.4s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 181 | `external_interface_unescapexml` | 40 | 17.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 182 | `focus_keyboard_press` | 60 | 17.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 183 | `focus_mouse` | 45 | 17.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 184 | `focus_mouse_focusable` | 8 | 17.9s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 185 | `focus_mouse_rollout` | 4 | 17.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 186 | `focus_remove` | 33 | 17.4s |  |
| 187 | `focus_root_movie` | 2 | 17.2s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 188 | `focus_visibility_change` | 45 | 17.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 189 | `focusrect_focuslost` | 4 | 17.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 190 | `focusrect_mouse_swf8` | 0 | 17.7s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 191 | `focusrect_mouse_swf9` | 0 | 18.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 192 | `focusrect_property_swf5` | 1237 | 18.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 193 | `focusrect_property_swf6` | 1237 | 18.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 194 | `focusrect_property_swf7` | 1237 | 18.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 195 | `focusrect_swf5` | 6 | 18.6s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 196 | `focusrect_swf6` | 42 | 17.6s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 197 | `form_loader_encoding_1` | 1 | 17.3s |  |
| 198 | `frame_size_translated_negative` | 21 | 17.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 199 | `frame_size_translated_positive` | 21 | 17.6s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 200 | `function_as_function` | 35 | 17.4s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 201 | `function_base_clip` | 8 | 17.3s |  |
| 202 | `function_base_clip_readded` | 11 | 17.2s |  |
| 203 | `function_base_clip_removed` | 25 | 17.4s |  |
| 204 | `function_suppress_and_preload` | 28 | 17.3s |  |
| 205 | `funky_function_calls` | 56 | 17.3s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 206 | `get_bytes_total` | 4 | 17.1s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 207 | `get_variable_in_scope` | 29 | 17.3s |  |
| 208 | `getproperty` | 28 | 17.7s |  |
| 209 | `getproperty_swf4` | 28 | 17.1s |  |
| 210 | `getproperty_swf5` | 28 | 17.4s |  |
| 211 | `gettextextent` | 56 | 17.5s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 212 | `global_array` | 3 | 18.0s |  |
| 213 | `global_is_bare` | 7 | 18.0s |  |
| 214 | `global_swf5_6_7_8_9` | 1145 | 18.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 215 | `global_swf6_7_8` | 15 | 18.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 216 | `globals_swf5` | 304 | 18.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 217 | `globals_swf6` | 304 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 218 | `globals_swf7` | 304 | 18.3s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 219 | `globals_swf8` | 304 | 18.3s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 220 | `goto_advance1` | 6 | 17.4s |  |
| 221 | `goto_advance2` | 2 | 17.4s |  |
| 222 | `goto_both_ways1` | 3 | 17.3s |  |
| 223 | `goto_both_ways2` | 3 | 17.3s |  |
| 224 | `goto_execution_order` | 2 | 17.1s |  |
| 225 | `goto_execution_order2` | 2 | 18.1s |  |
| 226 | `goto_frame` | 12 | 17.3s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 227 | `goto_frame2` | 44 | 17.6s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 228 | `goto_frame_number` | 3 | 17.2s |  |
| 229 | `goto_label` | 17 | 17.4s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 230 | `goto_methods` | 40 | 17.2s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 231 | `goto_rewind1` | 1 | 17.1s |  |
| 232 | `goto_rewind2` | 3 | 17.1s |  |
| 233 | `goto_rewind3` | 2 | 17.1s |  |
| 234 | `greater_swf6` | 1175 | 19.2s |  |
| 235 | `greater_swf7` | 1175 | 19.0s |  |
| 236 | `greaterthan_swf5` | 1 | 17.1s |  |
| 237 | `greaterthan_swf8` | 1 | 17.0s |  |
| 238 | `has_own_property` | 32 | 17.1s |  |
| 239 | `hittest_lockroot` | 15 | 17.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 240 | `hittest_morph` | 70 | 17.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 241 | `hittest_morph_input` | 1 | 17.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 242 | `hittest_winding_rule` | 12 | 17.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 243 | `infinite_recursion_function` | 4 | 17.1s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 244 | `infinite_recursion_function_in_setter` | 131 | 17.0s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 245 | `infinite_recursion_virtual_property` | 67 | 17.1s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 246 | `init_array_invalid` | 4 | 18.6s |  |
| 247 | `init_object_invalid` | 4 | 17.9s |  |
| 248 | `init_object_order` | 15 | 17.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 249 | `input_dead_keys_windows` | 15 | 18.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 250 | `instanceof_coercions` | 88 | 18.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 251 | `interface_implements_op` | 47 | 18.4s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 252 | `is_finite` | 49 | 17.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 253 | `is_finite_swf6` | 49 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 254 | `is_prototype_of` | 89 | 17.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 255 | `issue_1086` | 1 | 17.5s |  |
| 256 | `issue_1104` | 2 | 17.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 257 | `issue_1671` | 0 | 17.3s |  |
| 258 | `issue_1906` | 4 | 17.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 259 | `issue_2030` | 4 | 17.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 260 | `issue_2084` | 16 | 17.7s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 261 | `issue_2166` | 9 | 17.5s |  |
| 262 | `issue_2870` | 3 | 17.7s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 263 | `issue_3169` | 2 | 17.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 264 | `issue_3446` | 1 | 17.6s |  |
| 265 | `issue_3522` | 2 | 17.4s |  |
| 266 | `issue_4377` | 2 | 17.6s |  |
| 267 | `issue_710` | 4 | 18.4s |  |
| 268 | `issue_768` | 3 | 17.6s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 269 | `issue_9327` | 2 | 17.6s |  |
| 270 | `issue_9885` | 2 | 17.6s |  |
| 271 | `key_isToggled` | 9 | 17.6s |  |
| 272 | `lessthan` | 41 | 17.6s |  |
| 273 | `lessthan2_swf5` | 1226 | 19.8s |  |
| 274 | `lessthan2_swf6` | 1226 | 19.8s |  |
| 275 | `lessthan2_swf7` | 1226 | 19.9s |  |
| 276 | `lessthan_swf4` | 902 | 18.8s |  |
| 277 | `lessthan_swf4_alt` | 41 | 17.6s |  |
| 278 | `lessthan_swf5` | 41 | 17.6s |  |
| 279 | `loadmovie` | 2 | 17.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 280 | `loadmovie_fail` | 2 | 17.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 281 | `loadmovie_flashvars` | 4 | 17.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 282 | `loadmovie_method` | 2 | 17.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 283 | `loadmovie_registerclass` | 30 | 17.9s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 284 | `loadmovie_replace_root` | 5 | 17.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 285 | `loadmovie_var_persistence` | 8 | 17.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 286 | `loadmovienum` | 3 | 17.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 287 | `loadmovienum_cross_version_prototype` | 9 | 17.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 288 | `loadvariables` | 2 | 17.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 289 | `loadvariables2` | 8 | 17.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 290 | `loadvariablesnum` | 2 | 17.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 291 | `local_to_global` | 49 | 17.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 292 | `localconnection_properties` | 8 | 17.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 293 | `lock_root` | 1 | 17.5s |  |
| 294 | `logical_ops_swf4` | 90 | 17.3s |  |
| 295 | `logical_ops_swf8` | 108 | 17.3s |  |
| 296 | `looping` | 6 | 17.3s |  |
| 297 | `mask_reapply` | 0 | 17.3s | [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 298 | `mask_with_drawing` | 0 | 17.3s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 299 | `math_min_max` | 101 | 17.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 300 | `math_swf6` | 530 | 17.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 301 | `math_swf7` | 530 | 17.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 302 | `math_swf8` | 530 | 17.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 303 | `matrix` | 171 | 17.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 304 | `mcl_as_broadcaster` | 12 | 17.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mcl_events_swf_version` | 232 | 18.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 306 | `mcl_getprogress` | 30 | 18.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 307 | `mcl_loadclip` | 149 | 18.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 308 | `mcl_loadclip_properties` | 6 | 19.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 309 | `mcl_loadclip_replace_root` | 1 | 18.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 310 | `mcl_mislabeled_target` | 6 | 19.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 311 | `mcl_target_gif87a` | 6 | 19.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mcl_target_gif89a` | 6 | 19.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_target_jpg` | 6 | 18.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_target_png` | 6 | 19.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mcl_unloadclip` | 5 | 18.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 316 | `mouse_events` | 8 | 18.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 317 | `mouse_events_visible_enabled` | 12 | 18.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 318 | `mouse_hover_events_while_dragging` | 1 | 18.1s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 319 | `mouse_listeners` | 67 | 17.7s |  |
| 320 | `mouse_pos` | 665 | 18.1s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 321 | `mouse_pos_with_scale_factor` | 260 | 18.3s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 322 | `mouse_wheel_enabled` | 2 | 18.6s |  |
| 323 | `movieclip_begin_gradient_fill` | 0 | 19.8s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) |
| 324 | `movieclip_blend_mode_property` | 35 | 19.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_create_text_field` | 90 | 16.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 326 | `movieclip_default_state` | 69 | 16.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_depth_methods` | 98 | 16.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 328 | `movieclip_focusenabled` | 99 | 16.6s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_get_instance_at_depth` | 28 | 16.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_getbounds` | 191 | 16.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_gettextsnapshot` | 112 | 16.6s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_hittest` | 92 | 16.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 333 | `movieclip_in_removed_button` | 4 | 16.5s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 334 | `movieclip_init_object` | 5 | 16.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 335 | `movieclip_invalid_get_bounds_1` | 75 | 17.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_invalid_get_bounds_2` | 75 | 17.0s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_invalid_get_bounds_3` | 13 | 16.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_invalid_get_bounds_4` | 13 | 16.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_invalid_get_bounds_5` | 11 | 16.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_invalid_get_bounds_6` | 10 | 39.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_invalid_get_bounds_7` | 10 | 39.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_invalid_get_bounds_8` | 11 | 16.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 343 | `movieclip_line_gradient_style` | 0 | 16.9s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) |
| 344 | `movieclip_lockroot` | 29 | 17.8s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_name_from_timeline` | 13 | 17.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 346 | `movieclip_prototype_extension` | 5 | 17.2s |  |
| 347 | `movieclip_setmask` | 14 | 17.3s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 348 | `moviecliploader_flashvars` | 4 | 17.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 349 | `mutable_this` | 18 | 17.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 350 | `named_shapes` | 14 | 17.2s |  |
| 351 | `nan_scale` | 9 | 17.2s |  |
| 352 | `native_double_construct` | 12 | 17.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 353 | `native_objects_swf7` | 84 | 17.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 354 | `native_objects_swf8` | 84 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 355 | `nested_textfields_in_buttons` | 0 | 17.1s |  |
| 356 | `new_method_wrap` | 4 | 17.8s |  |
| 357 | `new_object_enumerate` | 7 | 16.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 358 | `new_object_wrap` | 4 | 16.7s |  |
| 359 | `o` | 3 | 17.2s |  |
| 360 | `object_constructor` | 33 | 17.1s |  |
| 361 | `object_function` | 32 | 17.0s |  |
| 362 | `object_properties` | 31 | 17.2s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 363 | `object_prototypes` | 74 | 17.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 364 | `object_resolve` | 38 | 17.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 365 | `object_string_coerce_swf5` | 62 | 17.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 366 | `object_string_coerce_swf6` | 68 | 17.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 367 | `on_construct` | 25 | 17.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 368 | `parse_float` | 74 | 17.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 369 | `parse_int` | 64 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 370 | `path_string` | 322 | 17.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 371 | `place_and_lookup` | 30 | 17.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 372 | `placeobject_occupied_depth` | 6 | 17.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 373 | `point` | 175 | 17.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 374 | `primitive_instanceof` | 37 | 17.0s |  |
| 375 | `primitive_type_globals` | 557 | 17.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 376 | `printjob_props_swf5` | 45 | 17.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 377 | `printjob_props_swf6` | 45 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 378 | `printjob_props_swf7` | 45 | 16.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 379 | `property_invalid_base_clip` | 36 | 17.0s |  |
| 380 | `prototype_delete` | 12 | 16.9s |  |
| 381 | `prototype_enumerate` | 5 | 16.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 382 | `prototype_properties` | 17 | 17.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 383 | `rectangle` | 745 | 17.7s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 384 | `recursive_prototypes` | 0 | 16.8s |  |
| 385 | `register_and_init_order` | 231 | 17.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 386 | `register_class` | 66 | 17.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 387 | `register_class_return_value` | 16 | 17.0s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 388 | `register_class_swf6` | 37 | 17.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 389 | `register_class_with_sound` | 11 | 17.0s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 390 | `register_globals_across_frames` | 15 | 16.8s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 391 | `register_underflow` | 26 | 16.9s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 392 | `remove_movie_clip` | 29 | 16.9s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 393 | `removed_clip_halts_script` | 15 | 17.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 394 | `removed_target_clip_scope` | 35 | 17.1s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 395 | `resolve_different_root` | 2 | 17.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 396 | `rewind_depth` | 30 | 17.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 397 | `root_button_mode` | 10 | 17.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 398 | `root_global_parent` | 6 | 17.5s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 399 | `root_onload` | 1 | 17.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 400 | `sandbox_type_local_file` | 1 | 17.4s |  |
| 401 | `sandbox_type_local_network` | 1 | 17.3s |  |
| 402 | `selection` | 454 | 17.8s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 403 | `selection_handlers` | 27 | 17.3s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 404 | `set_interval` | 27 | 17.4s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 405 | `set_variable_scope` | 58 | 17.3s |  |
| 406 | `single_frame` | 1 | 17.3s |  |
| 407 | `slash_syntax` | 14 | 17.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 408 | `sound` | 628 | 17.6s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 409 | `sound_props_swf5` | 68 | 17.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 410 | `sound_props_swf6` | 68 | 17.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 411 | `sound_start_load` | 0 | 16.8s |  |
| 412 | `stage_display_state` | 16 | 16.8s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 413 | `stage_object_children` | 83 | 16.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 414 | `stage_object_enumerate` | 4 | 16.6s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 415 | `stage_object_properties` | 241 | 17.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 416 | `stage_object_properties_get_var` | 5 | 16.6s |  |
| 417 | `stage_object_properties_swf6` | 231 | 17.1s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 418 | `stage_property_representation` | 586 | 16.8s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 419 | `stage_scale_mode` | 39 | 16.8s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 420 | `strictequals_swf6` | 902 | 18.1s |  |
| 421 | `strictly_equals` | 7 | 17.0s |  |
| 422 | `string_coercion` | 117 | 17.3s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 423 | `string_methods` | 285 | 17.5s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 424 | `string_methods_negative_args` | 240 | 17.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 425 | `string_methods_swfv5` | 275 | 17.8s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 426 | `string_ops_swf6` | 95 | 17.5s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 427 | `string_paths_basic` | 4 | 17.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 428 | `string_paths_eval` | 4 | 16.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 429 | `string_paths_eval2` | 7 | 18.8s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 430 | `string_paths_hidden` | 54 | 17.5s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 431 | `string_paths_keyevents` | 0 | 17.7s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 432 | `string_paths_other` | 36 | 16.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 433 | `string_paths_timer` | 0 | 16.7s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 434 | `string_paths_unload` | 1 | 16.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 435 | `string_paths_variable_alias` | 4 | 16.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 436 | `string_paths_variable_scopes` | 5 | 16.4s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 437 | `stylesheet` | 283 | 17.3s |  |
| 438 | `stylesheet_transform` | 750 | 17.4s |  |
| 439 | `super_edge_cases` | 39 | 16.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 440 | `swf4_actions_bool` | 96 | 16.7s |  |
| 441 | `swf4_actions_coercion_order` | 158 | 16.8s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 442 | `swf4_bool` | 4 | 16.7s |  |
| 443 | `swf4_function_calls` | 7 | 16.7s |  |
| 444 | `swf5_encoding` | 3 | 16.8s |  |
| 445 | `swf5_global_funcs` | 232 | 16.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 446 | `swf5_no_closure` | 19 | 16.7s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 447 | `swf5_to_6_cross_call` | 29 | 18.1s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 448 | `swf6_case_insensitive` | 42 | 17.6s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 449 | `swf6_global_funcs` | 232 | 18.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 450 | `swf6_string_as_bool` | 15 | 17.8s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 451 | `swf6_to_5_cross_call` | 29 | 18.0s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 452 | `swf7_case_sensitive` | 44 | 17.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 453 | `swf7_global_funcs` | 232 | 17.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 454 | `tab_ordering_automatic_basic` | 92 | 18.0s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 455 | `tab_ordering_automatic_order_grid` | 21 | 17.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 456 | `tab_ordering_automatic_order_same_position` | 12 | 17.9s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 457 | `tab_ordering_children` | 208 | 18.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 458 | `tab_ordering_custom_basic` | 71 | 18.2s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 459 | `tab_ordering_custom_duplicate_index` | 22 | 18.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 460 | `tab_ordering_custom_i32_vs_u32` | 12 | 18.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 461 | `tab_ordering_custom_m1` | 29 | 17.9s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 462 | `tab_ordering_events` | 150 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 463 | `tab_ordering_events_mouse` | 65 | 18.0s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 464 | `tab_ordering_movieclip_enabled_default` | 462 | 18.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 465 | `tab_ordering_properties` | 293 | 18.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 466 | `tab_ordering_reverse` | 51 | 17.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 467 | `tab_ordering_tabbable` | 47 | 17.3s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 468 | `target_clip_removed` | 5 | 17.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 469 | `target_clip_swf5` | 2 | 17.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 470 | `target_clip_swf6` | 2 | 17.2s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 471 | `target_path` | 14 | 17.1s |  |
| 472 | `tell_target` | 37 | 17.2s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 473 | `tell_target_invalid` | 6 | 17.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 474 | `tell_target_invalid_swf6` | 5 | 17.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 475 | `text_blocks_clicks` | 4 | 17.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 476 | `text_format` | 1146 | 17.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 477 | `text_format_display` | 21 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 478 | `text_format_font_max_length` | 2 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 479 | `text_format_get_text_extent_undefined_width` | 10 | 17.2s |  |
| 480 | `text_format_rounding_swf7` | 840 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 481 | `text_format_rounding_swf8` | 840 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 482 | `textfield_background_color` | 11 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 483 | `textfield_border_color` | 11 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 484 | `textfield_cache_as_bitmap` | 1 | 17.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 485 | `textfield_maxchars` | 3 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 486 | `textfield_properties` | 44 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 487 | `textfield_props_swf5` | 175 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 488 | `textfield_props_swf6` | 210 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 489 | `textfield_props_swf7` | 210 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 490 | `textfield_props_swf8` | 210 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 491 | `textfield_text` | 7 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 492 | `textfield_variable` | 81 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 493 | `textsnapshot_available_text` | 20 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 494 | `textsnapshot_findtext` | 44 | 17.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 495 | `textsnapshot_gettext` | 55 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 496 | `textsnapshot_props_swf5` | 56 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `textsnapshot_props_swf6` | 56 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `textsnapshot_text_order` | 1 | 17.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 499 | `this_scoping` | 52 | 17.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 500 | `this_swf5` | 41 | 17.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 501 | `this_swf6` | 41 | 17.4s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 502 | `this_swf7` | 41 | 17.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 503 | `timeline_function_def` | 7 | 17.7s |  |
| 504 | `timer_run_actions` | 18 | 17.5s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 505 | `trace` | 8 | 17.2s |  |
| 506 | `transform` | 70 | 17.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 507 | `try_catch_finally` | 118 | 17.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 508 | `try_finally_simple` | 16 | 17.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 509 | `typeof` | 22 | 17.3s |  |
| 510 | `typeof_globals` | 7 | 17.2s |  |
| 511 | `uncaught_exception` | 1 | 17.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 512 | `uncaught_exception_bubbled` | 1 | 17.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 513 | `undefined_to_string_swf6` | 4 | 17.2s |  |
| 514 | `unescape` | 43 | 17.3s |  |
| 515 | `unload` | 52 | 17.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 516 | `unload_clip_event` | 4 | 17.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 517 | `unload_nested_child` | 5 | 17.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 518 | `unloadmovie` | 4 | 17.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 519 | `unloadmovie_method` | 3 | 17.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 520 | `unloadmovienum` | 13 | 17.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 521 | `use_hand_cursor` | 8 | 17.6s |  |
| 522 | `variable_args` | 5 | 17.4s |  |
| 523 | `waitforframe` | 7 | 17.3s |  |
| 524 | `waitforframe2` | 16 | 18.5s |  |
| 525 | `watch` | 117 | 17.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 526 | `watch_textfield` | 12 | 17.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 527 | `watch_virtual_property_proto` | 2 | 18.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 528 | `with` | 49 | 17.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 529 | `with_return` | 2 | 17.8s |  |
| 530 | `with_variable_scopes` | 43 | 17.9s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 531 | `xml` | 15 | 18.0s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 532 | `xml_append_child` | 28 | 17.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 533 | `xml_append_child_with_parent` | 20 | 17.7s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 534 | `xml_attributes_read` | 4 | 17.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 535 | `xml_cdata` | 11 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 536 | `xml_child_nodes_edge_cases` | 4 | 17.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 537 | `xml_clone_expandos` | 19 | 17.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 538 | `xml_first_last_child` | 8 | 17.7s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_has_child_nodes` | 3 | 17.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 540 | `xml_idmap` | 21 | 17.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 541 | `xml_ignore_comments` | 21 | 18.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 542 | `xml_ignore_white` | 34 | 18.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_insert_before` | 20 | 17.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_inspect_createmethods` | 15 | 17.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 545 | `xml_inspect_doctype` | 7 | 17.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 546 | `xml_inspect_parsexml` | 62 | 17.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 547 | `xml_inspect_xmldecl` | 7 | 17.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_namespaces` | 203 | 17.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_parent_and_child` | 5 | 17.7s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_remove_node` | 22 | 17.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_reparenting` | 14 | 17.7s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_siblings` | 10 | 17.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_to_string` | 13 | 17.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_to_string_comment` | 1 | 17.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_unescaping` | 23 | 18.0s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 556 | `xmlnode_proto` | 1 | 17.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `native_subclasses` | 99.0% | 189 | 191 | 2 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `movieclip_hittest_shapeflag` | 96.2% | 325 | 338 | 13 | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) |
| 3 | `as_broadcaster_initialize` | 90.0% | 9 | 10 | 1 |  |
| 4 | `bitmap_data_compare` | 77.5% | 31 | 40 | 9 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 5 | `displacementmapfilter_mappoint_throw_error` | 53.8% | 7 | 13 | 6 | [25](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DISPLACEMENTMAPFILTER_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `native_subclasses` | 99.0% | 189/191 | 191 | 191 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `movieclip_hittest_shapeflag` | 96.2% | 325/338 | 338 | 338 | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) |
| 3 | `as_broadcaster_initialize` | 90.0% | 9/10 | 10 | 10 |  |
| 4 | `bitmap_data_compare` | 77.5% | 31/40 | 31 | 40 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 5 | `displacementmapfilter_mappoint_throw_error` | 53.8% | 7/13 | 13 | 13 | [25](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DISPLACEMENTMAPFILTER_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 6 | `global_proto_decls` | 18.6% | 836/4497 | 3617 | 4497 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 7 | `bitmap_data_copypixels` | 11.8% | 2/17 | 12 | 17 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 8 | `bitmap_data` | 7.4% | 83/1126 | 318 | 1126 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 9 | `global_proto_decls_delete` | 7.1% | 296/4158 | 853 | 4158 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 10 | `bitmap_data_threshold` | 4.5% | 8/176 | 38 | 176 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 11 | `global_instance_decls` | 1.6% | 14/853 | 853 | 758 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 12 | `bitmap_data_noise` | 0.2% | 1/631 | 37 | 631 | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 13 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 15 | 10 | 5 |
| 6 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTER_CLONE_PLAN.md) | 0 | 0 | 0 |
| 7 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 0 | 0 | 0 |
| 8 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTERS_PLAN.md) | 0 | 0 | 0 |
| 9 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 5 | 1 |
| 13 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 14 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 15 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 16 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 17 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 18 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 19 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 20 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 21 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 22 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 23 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 24 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 25 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 0 | 1 |
| 26 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 27 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 28 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 29 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 30 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 31 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 32 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 33 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) | 0 | 0 | 0 |
| 34 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 35 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 36 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 37 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 38 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 2 | 1 |
| 39 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 5 | 1 |
| 40 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 41 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) | 30 | 26 | 4 |
| 42 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 43 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 44 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 45 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 46 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 47 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 48 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 49 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 42 | 42 | 0 |
| 50 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 3 | 3 | 0 |
| 51 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 52 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 53 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 54 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 55 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 56 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 57 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 54 | 53 | 1 |
| 58 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 59 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 15 | 14 | 1 |
| 60 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/NETCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 61 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 62 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 3 | 0 |
| 63 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 64 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 65 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) | 2 | 1 | 1 |
| 66 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 67 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 68 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 69 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
| 70 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 71 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 72 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 73 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 74 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 75 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 76 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/SOUND_DURATION_POSITION_PLAN.md) | 0 | 0 | 0 |
| 77 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) | 0 | 0 | 0 |
| 78 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/SOUND_LOADING_PLAN.md) | 0 | 0 | 0 |
| 79 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 80 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 81 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 82 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 12 | 12 | 0 |
| 83 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 84 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 0 | 0 | 0 |
| 85 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 86 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 87 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 88 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) | 17 | 17 | 0 |
| 89 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 68 | 68 | 0 |
| 90 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 91 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 92 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 93 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 2 | 2 | 0 |
| 94 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 95 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 96 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 13 | 12 | 1 |
| 97 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 98 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) | 1 | 0 | 1 |
| 99 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 100 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 26 | 26 | 0 |
| | *(tests not in any document)* | 144 | 143 | 1 |
