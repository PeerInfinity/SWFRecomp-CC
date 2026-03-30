# Ruffle Test Results (Filtered)

**Date**: 2026-03-30 20:10 UTC

**Git SHA**: `56ec186a4b`

**Run Duration**: 177m 49s

**Filtered**: 51 tests ignored out of 620 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 569 |
| Passing | **563** (98.9%) |
| Failing | 6 |
| Total expected lines | 80848 |
| Matching lines | 71618 (88.6%) |
| Mismatched lines | 9230 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**563 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 17.7s |  |
| 2 | `action_to_integer` | 28 | 16.7s |  |
| 3 | `add` | 28 | 16.8s |  |
| 4 | `add2` | 354 | 17.0s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 17.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 17.4s |  |
| 7 | `add_swf5` | 28 | 17.5s |  |
| 8 | `arguments` | 127 | 16.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 16.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 16.9s |  |
| 11 | `array_constructor` | 30 | 16.8s |  |
| 12 | `array_enumerate` | 4 | 16.3s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 16.2s |  |
| 14 | `array_properties` | 36 | 16.3s |  |
| 15 | `array_prototyping` | 12 | 16.5s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 17.2s |  |
| 17 | `array_sort` | 161 | 17.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 17.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 17.6s |  |
| 20 | `array_trivial` | 209 | 16.4s |  |
| 21 | `as1_constructor_v6` | 35 | 16.3s |  |
| 22 | `as1_constructor_v7` | 35 | 16.4s |  |
| 23 | `as2_oop` | 13 | 16.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 16.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 16.6s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 16.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 16.4s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 16.3s |  |
| 29 | `as_broadcaster_undef` | 89 | 16.6s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 16.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 16.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 16.6s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 16.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 16.5s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 16.4s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 16.3s |  |
| 37 | `as_transformed_flag` | 20 | 16.4s |  |
| 38 | `asnative` | 34 | 16.4s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 16.5s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 16.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 16.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 17.7s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 16.8s |  |
| 44 | `bitand` | 1058 | 19.6s |  |
| 45 | `bitmap_data` | 1126 | 19.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_colortransform` | 0 | 17.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 47 | `bitmap_data_compare` | 40 | 17.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_copypixels` | 17 | 17.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 49 | `bitmap_data_draw_cliprect` | 13 | 17.0s |  |
| 50 | `bitmap_data_fillrect` | 0 | 17.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 51 | `bitmap_data_hittest` | 132 | 17.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 52 | `bitmap_data_max_size_swf10` | 12 | 16.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_max_size_swf9` | 10 | 16.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_noise` | 631 | 17.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_perlinnoise` | 0 | 17.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 56 | `bitmap_data_pixeldissolve_image` | 0 | 17.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 57 | `bitmap_data_threshold` | 176 | 17.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 58 | `bitmapdata_applyfilter_colormatrix` | 0 | 16.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) |
| 59 | `bitmapdata_channels` | 19 | 16.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 60 | `bitor` | 1058 | 19.7s |  |
| 61 | `biturshift` | 14 | 17.3s |  |
| 62 | `biturshift_swf8` | 14 | 17.2s |  |
| 63 | `bitxor` | 1058 | 20.1s |  |
| 64 | `boxed_primitives` | 24 | 17.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 65 | `button_children` | 8 | 16.9s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_goto` | 4 | 17.3s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_key_events` | 14 | 17.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_key_events_special` | 45 | 17.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_keypress` | 3 | 17.1s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_keypress_vs_press` | 25 | 17.1s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_keypress_vs_tab` | 20 | 17.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_keypress_vs_textinput` | 4 | 17.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_order` | 2 | 17.1s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_properties_special_cases` | 22 | 17.2s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `button_v5` | 18 | 17.1s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 76 | `button_v6` | 18 | 17.5s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 77 | `call` | 63 | 17.5s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 78 | `call_method_empty_name` | 1 | 17.5s |  |
| 79 | `capabilities_resolution` | 8 | 17.6s |  |
| 80 | `catch_references_registers` | 2 | 17.6s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 81 | `click_block` | 5 | 17.6s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 82 | `clip_constructors` | 8 | 17.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 83 | `clip_event_propagation_order` | 17 | 18.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 84 | `clip_events` | 19 | 17.8s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 85 | `clone_sprite_edittext` | 94 | 17.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 86 | `clone_sprite_edittext_dynamic` | 86 | 17.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 87 | `clone_sprite_types` | 24 | 17.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 88 | `closure_scope` | 7 | 17.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 89 | `coerce_to_object_monkeypatch` | 129 | 17.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 90 | `coerce_to_primitive_resolve` | 17 | 17.2s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 91 | `color` | 57 | 17.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 92 | `color_transform` | 48 | 17.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 93 | `conflicting_instance_names` | 23 | 17.3s |  |
| 94 | `constructor_function` | 2 | 17.0s |  |
| 95 | `context_menu` | 39 | 17.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 96 | `context_menu_item` | 41 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 97 | `create_empty_movie_clip` | 3 | 17.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 98 | `cross_movie_root` | 10 | 17.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 99 | `custom_clip_methods` | 4 | 17.7s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 100 | `default_names` | 52 | 17.2s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 101 | `define_function2` | 8 | 17.1s |  |
| 102 | `define_function2_preload` | 13 | 17.4s |  |
| 103 | `define_function2_preload_order` | 4 | 17.1s |  |
| 104 | `define_function_case_sensitive` | 2 | 17.1s |  |
| 105 | `define_local` | 27 | 17.4s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 106 | `define_local_with_paths` | 54 | 16.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 107 | `delete` | 3 | 17.1s |  |
| 108 | `device_font_spacing` | 91 | 17.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 109 | `display_object_properties` | 2 | 17.3s | [70](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 110 | `divide_swf4` | 107 | 17.1s |  |
| 111 | `do_init_action` | 3 | 16.6s |  |
| 112 | `do_init_action_child` | 12 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 113 | `drag_drop` | 10 | 16.6s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 114 | `drag_over_from_outside` | 1 | 16.4s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 115 | `drag_over_without_startdrag` | 1 | 16.6s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 116 | `duplicate_movie_clip` | 20 | 16.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 117 | `duplicate_movie_clip_drawing` | 2 | 16.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 118 | `edittext_align` | 60 | 16.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 119 | `edittext_align_trailing_spaces_swf7` | 576 | 16.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 120 | `edittext_align_trailing_spaces_swf8` | 576 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 121 | `edittext_antialiastype` | 296 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 122 | `edittext_autosize` | 71 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_autosize_setter` | 20 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_bullet` | 30 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_default_format` | 221 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_default_format_font_style` | 335 | 17.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_drag_select` | 9 | 17.2s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_focus_selection` | 2 | 17.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_font_size` | 45 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_hscroll` | 27 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_html_align_swf7` | 52 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_html_align_swf8` | 52 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_html_color` | 114 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_html_condensewhite_swf7` | 311 | 17.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_html_condensewhite_swf8` | 311 | 17.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_html_entity` | 4 | 17.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_html_roundtrip` | 17 | 17.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_html_swf6` | 5377 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_html_swf7` | 5377 | 19.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_html_swf8` | 5377 | 19.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_input` | 1 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_input_newlines` | 9 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_leading` | 9 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_letter_spacing` | 15 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_margins` | 25 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_newline_stripping` | 64 | 21.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_newlines` | 30 | 16.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_password` | 5 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_password_copy` | 4 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_paste_empty` | 2 | 16.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_place_caret` | 2 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_programmatic_focus` | 12 | 16.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_restrict` | 191 | 16.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_restrict_paste` | 5 | 16.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_scroll` | 54 | 16.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_stylesheet` | 325 | 17.1s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_tab_focus` | 13 | 16.3s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_tab_stops` | 60 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_tag_indent` | 31 | 16.5s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_text_height_leading` | 20 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_underline` | 40 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_width_height` | 103 | 17.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `empty_movieclip_can_attach_movies` | 11 | 17.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 164 | `enumerate` | 64 | 17.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 165 | `equals` | 32 | 17.4s |  |
| 166 | `equals2_swf5` | 926 | 19.4s |  |
| 167 | `equals2_swf6` | 926 | 19.4s |  |
| 168 | `equals2_swf7` | 926 | 19.0s |  |
| 169 | `equals_swf4` | 665 | 17.9s |  |
| 170 | `equals_swf4_alt` | 32 | 16.6s |  |
| 171 | `equals_swf5` | 32 | 16.7s |  |
| 172 | `error` | 58 | 16.6s |  |
| 173 | `escape` | 14 | 16.8s |  |
| 174 | `execution_order1` | 5 | 17.9s |  |
| 175 | `execution_order2` | 7 | 18.8s |  |
| 176 | `execution_order3` | 4 | 18.1s |  |
| 177 | `execution_order4` | 12 | 16.9s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 178 | `export_assets` | 3 | 16.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 179 | `extends_chain` | 134 | 17.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 180 | `extends_native_type` | 11 | 17.3s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 181 | `external_interface` | 84 | 17.0s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 182 | `external_interface_escapexml` | 26 | 17.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 183 | `external_interface_jsquotestring` | 21 | 17.9s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 184 | `external_interface_toas_basic` | 354 | 17.4s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 185 | `external_interface_toxml_array` | 25 | 16.9s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 186 | `external_interface_toxml_basic` | 179 | 17.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 187 | `external_interface_unescapexml` | 40 | 17.2s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 188 | `focus_keyboard_press` | 60 | 17.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 189 | `focus_mouse` | 45 | 17.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 190 | `focus_mouse_focusable` | 8 | 17.5s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 191 | `focus_mouse_rollout` | 4 | 17.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 192 | `focus_remove` | 33 | 17.1s |  |
| 193 | `focus_root_movie` | 2 | 17.0s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 194 | `focus_visibility_change` | 45 | 17.0s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 195 | `focusrect_focuslost` | 4 | 17.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 196 | `focusrect_mouse_swf8` | 0 | 17.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 197 | `focusrect_mouse_swf9` | 0 | 17.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 198 | `focusrect_property_swf5` | 1237 | 17.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 199 | `focusrect_property_swf6` | 1237 | 17.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 200 | `focusrect_property_swf7` | 1237 | 17.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 201 | `focusrect_swf5` | 6 | 17.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 202 | `focusrect_swf6` | 42 | 17.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 203 | `form_loader_encoding_1` | 1 | 17.1s |  |
| 204 | `frame_size_translated_negative` | 21 | 17.2s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 205 | `frame_size_translated_positive` | 21 | 17.2s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 206 | `function_as_function` | 35 | 17.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 207 | `function_base_clip` | 8 | 17.1s |  |
| 208 | `function_base_clip_readded` | 11 | 17.1s |  |
| 209 | `function_base_clip_removed` | 25 | 17.2s |  |
| 210 | `function_suppress_and_preload` | 28 | 17.2s |  |
| 211 | `funky_function_calls` | 56 | 17.1s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 212 | `get_bytes_total` | 4 | 16.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 213 | `get_variable_in_scope` | 29 | 17.2s |  |
| 214 | `getproperty` | 28 | 16.9s |  |
| 215 | `getproperty_swf4` | 28 | 16.9s |  |
| 216 | `getproperty_swf5` | 28 | 16.8s |  |
| 217 | `gettextextent` | 56 | 16.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 218 | `global_array` | 3 | 17.2s |  |
| 219 | `global_is_bare` | 7 | 17.3s |  |
| 220 | `global_swf5_6_7_8_9` | 1145 | 17.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 221 | `global_swf6_7_8` | 15 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 222 | `globals_swf5` | 304 | 17.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 223 | `globals_swf6` | 304 | 16.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 224 | `globals_swf7` | 304 | 17.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 225 | `globals_swf8` | 304 | 17.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 226 | `goto_advance1` | 6 | 17.1s |  |
| 227 | `goto_advance2` | 2 | 16.9s |  |
| 228 | `goto_both_ways1` | 3 | 16.8s |  |
| 229 | `goto_both_ways2` | 3 | 17.1s |  |
| 230 | `goto_execution_order` | 2 | 17.3s |  |
| 231 | `goto_execution_order2` | 2 | 17.4s |  |
| 232 | `goto_frame` | 12 | 17.4s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 233 | `goto_frame2` | 44 | 17.7s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 234 | `goto_frame_number` | 3 | 17.1s |  |
| 235 | `goto_label` | 17 | 17.2s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 236 | `goto_methods` | 40 | 17.4s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 237 | `goto_rewind1` | 1 | 17.0s |  |
| 238 | `goto_rewind2` | 3 | 16.9s |  |
| 239 | `goto_rewind3` | 2 | 17.1s |  |
| 240 | `greater_swf6` | 1175 | 18.9s |  |
| 241 | `greater_swf7` | 1175 | 18.9s |  |
| 242 | `greaterthan_swf5` | 1 | 16.8s |  |
| 243 | `greaterthan_swf8` | 1 | 16.9s |  |
| 244 | `has_own_property` | 32 | 17.0s |  |
| 245 | `hittest_lockroot` | 15 | 17.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 246 | `hittest_morph` | 70 | 17.0s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 247 | `hittest_morph_input` | 1 | 17.0s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 248 | `hittest_winding_rule` | 12 | 17.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 249 | `infinite_recursion_function` | 4 | 16.8s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 250 | `infinite_recursion_function_in_setter` | 131 | 16.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 251 | `infinite_recursion_virtual_property` | 67 | 17.3s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 252 | `init_array_invalid` | 4 | 17.7s |  |
| 253 | `init_object_invalid` | 4 | 16.6s |  |
| 254 | `init_object_order` | 15 | 16.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 255 | `input_dead_keys_windows` | 15 | 16.6s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 256 | `instanceof_coercions` | 88 | 16.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 257 | `interface_implements_op` | 47 | 17.0s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 258 | `is_finite` | 49 | 16.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 259 | `is_finite_swf6` | 49 | 16.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 260 | `is_prototype_of` | 89 | 16.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 261 | `issue_1086` | 1 | 16.2s |  |
| 262 | `issue_1104` | 2 | 16.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 263 | `issue_1671` | 0 | 16.4s |  |
| 264 | `issue_1906` | 4 | 16.5s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 265 | `issue_2030` | 4 | 16.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 266 | `issue_2084` | 16 | 16.7s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 267 | `issue_2166` | 9 | 16.3s |  |
| 268 | `issue_2870` | 3 | 16.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 269 | `issue_3169` | 2 | 16.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 270 | `issue_3446` | 1 | 16.2s |  |
| 271 | `issue_3522` | 2 | 16.4s |  |
| 272 | `issue_4377` | 2 | 16.3s |  |
| 273 | `issue_710` | 4 | 16.6s |  |
| 274 | `issue_768` | 3 | 16.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 275 | `issue_9327` | 2 | 16.5s |  |
| 276 | `issue_9885` | 2 | 16.3s |  |
| 277 | `key_isToggled` | 9 | 16.3s |  |
| 278 | `lessthan` | 41 | 16.4s |  |
| 279 | `lessthan2_swf5` | 1226 | 18.4s |  |
| 280 | `lessthan2_swf6` | 1226 | 18.4s |  |
| 281 | `lessthan2_swf7` | 1226 | 18.4s |  |
| 282 | `lessthan_swf4` | 902 | 17.6s |  |
| 283 | `lessthan_swf4_alt` | 41 | 16.5s |  |
| 284 | `lessthan_swf5` | 41 | 16.5s |  |
| 285 | `loadmovie` | 2 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 286 | `loadmovie_fail` | 2 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 287 | `loadmovie_flashvars` | 4 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 288 | `loadmovie_method` | 2 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 289 | `loadmovie_registerclass` | 30 | 16.6s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 290 | `loadmovie_replace_root` | 5 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 291 | `loadmovie_var_persistence` | 8 | 17.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 292 | `loadmovienum` | 3 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 293 | `loadmovienum_cross_version_prototype` | 9 | 17.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 294 | `loadvariables` | 2 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 295 | `loadvariables2` | 8 | 16.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 296 | `loadvariablesnum` | 2 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 297 | `local_to_global` | 49 | 16.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 298 | `localconnection_properties` | 8 | 16.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 299 | `lock_root` | 1 | 16.3s |  |
| 300 | `logical_ops_swf4` | 90 | 16.6s |  |
| 301 | `logical_ops_swf8` | 108 | 16.4s |  |
| 302 | `looping` | 6 | 16.4s |  |
| 303 | `mask_reapply` | 0 | 16.5s | [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 304 | `mask_with_drawing` | 0 | 16.4s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 305 | `math_min_max` | 101 | 16.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 306 | `math_swf6` | 530 | 16.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 307 | `math_swf7` | 530 | 16.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 308 | `math_swf8` | 530 | 16.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 309 | `matrix` | 171 | 16.8s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 310 | `mcl_as_broadcaster` | 12 | 16.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 311 | `mcl_events_swf_version` | 232 | 17.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mcl_getprogress` | 30 | 16.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_loadclip` | 149 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_loadclip_properties` | 6 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mcl_loadclip_replace_root` | 1 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 316 | `mcl_mislabeled_target` | 6 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 317 | `mcl_target_gif87a` | 6 | 16.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 318 | `mcl_target_gif89a` | 6 | 16.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 319 | `mcl_target_jpg` | 6 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 320 | `mcl_target_png` | 6 | 16.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 321 | `mcl_unloadclip` | 5 | 16.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 322 | `mouse_events` | 8 | 16.5s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 323 | `mouse_events_visible_enabled` | 12 | 16.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 324 | `mouse_hover_events_while_dragging` | 1 | 16.6s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 325 | `mouse_listeners` | 67 | 16.6s |  |
| 326 | `mouse_pos` | 665 | 16.5s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 327 | `mouse_pos_with_scale_factor` | 260 | 16.4s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 328 | `mouse_wheel_enabled` | 2 | 16.4s |  |
| 329 | `movieclip_begin_gradient_fill` | 0 | 17.0s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) |
| 330 | `movieclip_blend_mode_property` | 35 | 16.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_create_text_field` | 90 | 18.3s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 332 | `movieclip_default_state` | 69 | 17.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 333 | `movieclip_depth_methods` | 98 | 17.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 334 | `movieclip_focusenabled` | 99 | 17.2s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_get_instance_at_depth` | 28 | 17.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_getbounds` | 191 | 17.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_gettextsnapshot` | 112 | 17.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_hittest` | 92 | 17.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_in_removed_button` | 4 | 17.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 340 | `movieclip_init_object` | 5 | 17.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 341 | `movieclip_invalid_get_bounds_1` | 75 | 18.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_invalid_get_bounds_2` | 75 | 17.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 343 | `movieclip_invalid_get_bounds_3` | 13 | 17.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_invalid_get_bounds_4` | 13 | 17.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_invalid_get_bounds_5` | 11 | 17.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 346 | `movieclip_invalid_get_bounds_6` | 10 | 42.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 347 | `movieclip_invalid_get_bounds_7` | 10 | 42.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 348 | `movieclip_invalid_get_bounds_8` | 11 | 17.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 349 | `movieclip_line_gradient_style` | 0 | 17.9s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) |
| 350 | `movieclip_lockroot` | 29 | 17.8s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 351 | `movieclip_name_from_timeline` | 13 | 16.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 352 | `movieclip_prototype_extension` | 5 | 16.7s |  |
| 353 | `movieclip_setmask` | 14 | 17.0s | [27](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DRAWING_API_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 354 | `moviecliploader_flashvars` | 4 | 16.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 355 | `mutable_this` | 18 | 16.7s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 356 | `named_shapes` | 14 | 16.9s |  |
| 357 | `nan_scale` | 9 | 17.0s |  |
| 358 | `native_double_construct` | 12 | 16.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 359 | `native_objects_swf7` | 84 | 17.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 360 | `native_objects_swf8` | 84 | 17.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 361 | `native_subclasses` | 191 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 362 | `nested_textfields_in_buttons` | 0 | 16.9s |  |
| 363 | `new_method_wrap` | 4 | 16.2s |  |
| 364 | `new_object_enumerate` | 7 | 16.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 365 | `new_object_wrap` | 4 | 16.1s |  |
| 366 | `o` | 3 | 16.1s |  |
| 367 | `object_constructor` | 33 | 16.2s |  |
| 368 | `object_function` | 32 | 16.2s |  |
| 369 | `object_properties` | 31 | 16.4s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 370 | `object_prototypes` | 74 | 16.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 371 | `object_resolve` | 38 | 16.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 372 | `object_string_coerce_swf5` | 62 | 16.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 373 | `object_string_coerce_swf6` | 68 | 16.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 374 | `on_construct` | 25 | 16.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 375 | `parse_float` | 74 | 16.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 376 | `parse_int` | 64 | 16.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 377 | `path_string` | 322 | 16.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 378 | `place_and_lookup` | 30 | 16.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 379 | `placeobject_occupied_depth` | 6 | 16.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 380 | `point` | 175 | 16.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 381 | `primitive_instanceof` | 37 | 16.1s |  |
| 382 | `primitive_type_globals` | 557 | 16.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 383 | `printjob_props_swf5` | 45 | 16.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 384 | `printjob_props_swf6` | 45 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 385 | `printjob_props_swf7` | 45 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 386 | `property_invalid_base_clip` | 36 | 17.3s |  |
| 387 | `prototype_delete` | 12 | 17.0s |  |
| 388 | `prototype_enumerate` | 5 | 17.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 389 | `prototype_properties` | 17 | 17.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 390 | `rectangle` | 745 | 18.1s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 391 | `recursive_prototypes` | 0 | 17.1s |  |
| 392 | `register_and_init_order` | 231 | 17.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 393 | `register_class` | 66 | 17.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 394 | `register_class_return_value` | 16 | 17.2s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 395 | `register_class_swf6` | 37 | 17.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 396 | `register_class_with_sound` | 11 | 17.2s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 397 | `register_globals_across_frames` | 15 | 17.2s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 398 | `register_underflow` | 26 | 17.1s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 399 | `remove_movie_clip` | 29 | 17.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 400 | `removed_clip_halts_script` | 15 | 17.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 401 | `removed_target_clip_scope` | 35 | 17.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 402 | `resolve_different_root` | 2 | 17.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 403 | `rewind_depth` | 30 | 17.6s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 404 | `root_button_mode` | 10 | 16.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 405 | `root_global_parent` | 6 | 16.4s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 406 | `root_onload` | 1 | 16.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 407 | `sandbox_type_local_file` | 1 | 16.3s |  |
| 408 | `sandbox_type_local_network` | 1 | 16.4s |  |
| 409 | `selection` | 454 | 16.7s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 410 | `selection_handlers` | 27 | 16.8s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 411 | `set_interval` | 27 | 17.0s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 412 | `set_variable_scope` | 58 | 17.7s |  |
| 413 | `single_frame` | 1 | 17.5s |  |
| 414 | `slash_syntax` | 14 | 17.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 415 | `sound` | 628 | 17.0s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 416 | `sound_props_swf5` | 68 | 16.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 417 | `sound_props_swf6` | 68 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 418 | `sound_start_load` | 0 | 16.8s |  |
| 419 | `stage_display_state` | 16 | 16.7s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 420 | `stage_object_children` | 83 | 16.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 421 | `stage_object_enumerate` | 4 | 16.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 422 | `stage_object_properties` | 241 | 17.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 423 | `stage_object_properties_get_var` | 5 | 16.7s |  |
| 424 | `stage_object_properties_swf6` | 231 | 17.1s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 425 | `stage_property_representation` | 586 | 16.8s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 426 | `stage_scale_mode` | 39 | 16.8s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 427 | `strictequals_swf6` | 902 | 18.2s |  |
| 428 | `strictly_equals` | 7 | 16.7s |  |
| 429 | `string_coercion` | 117 | 17.0s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 430 | `string_methods` | 285 | 17.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 431 | `string_methods_negative_args` | 240 | 16.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 432 | `string_methods_swfv5` | 275 | 17.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 433 | `string_ops_swf6` | 95 | 16.8s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 434 | `string_paths_basic` | 4 | 16.8s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 435 | `string_paths_eval` | 4 | 16.8s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 436 | `string_paths_eval2` | 7 | 16.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 437 | `string_paths_hidden` | 54 | 17.5s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 438 | `string_paths_keyevents` | 0 | 16.8s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 439 | `string_paths_other` | 36 | 17.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 440 | `string_paths_timer` | 0 | 16.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 441 | `string_paths_unload` | 1 | 17.0s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 442 | `string_paths_variable_alias` | 4 | 17.1s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 443 | `string_paths_variable_scopes` | 5 | 17.0s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 444 | `stylesheet` | 283 | 17.8s |  |
| 445 | `stylesheet_transform` | 750 | 18.1s |  |
| 446 | `super_edge_cases` | 39 | 17.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 447 | `swf4_actions_bool` | 96 | 17.7s |  |
| 448 | `swf4_actions_coercion_order` | 158 | 17.7s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 449 | `swf4_bool` | 4 | 17.8s |  |
| 450 | `swf4_function_calls` | 7 | 17.4s |  |
| 451 | `swf5_encoding` | 3 | 17.4s |  |
| 452 | `swf5_global_funcs` | 232 | 17.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 453 | `swf5_no_closure` | 19 | 17.5s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 454 | `swf5_to_6_cross_call` | 29 | 17.1s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 455 | `swf6_case_insensitive` | 42 | 16.3s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 456 | `swf6_global_funcs` | 232 | 16.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 457 | `swf6_string_as_bool` | 15 | 16.2s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 458 | `swf6_to_5_cross_call` | 29 | 16.3s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 459 | `swf7_case_sensitive` | 44 | 16.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 460 | `swf7_global_funcs` | 232 | 16.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 461 | `tab_ordering_automatic_basic` | 92 | 16.3s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 462 | `tab_ordering_automatic_order_grid` | 21 | 16.3s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 463 | `tab_ordering_automatic_order_same_position` | 12 | 16.3s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 464 | `tab_ordering_children` | 208 | 16.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 465 | `tab_ordering_custom_basic` | 71 | 16.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 466 | `tab_ordering_custom_duplicate_index` | 22 | 16.4s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 467 | `tab_ordering_custom_i32_vs_u32` | 12 | 16.4s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 468 | `tab_ordering_custom_m1` | 29 | 16.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 469 | `tab_ordering_events` | 150 | 16.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 470 | `tab_ordering_events_mouse` | 65 | 16.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 471 | `tab_ordering_movieclip_enabled_default` | 462 | 16.4s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 472 | `tab_ordering_properties` | 293 | 16.4s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 473 | `tab_ordering_reverse` | 51 | 16.9s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 474 | `tab_ordering_tabbable` | 47 | 17.0s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 475 | `target_clip_removed` | 5 | 16.6s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 476 | `target_clip_swf5` | 2 | 16.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 477 | `target_clip_swf6` | 2 | 16.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 478 | `target_path` | 14 | 16.3s |  |
| 479 | `tell_target` | 37 | 16.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 480 | `tell_target_invalid` | 6 | 16.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 481 | `tell_target_invalid_swf6` | 5 | 16.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 482 | `text_blocks_clicks` | 4 | 16.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 483 | `text_format` | 1146 | 17.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 484 | `text_format_display` | 21 | 17.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 485 | `text_format_font_max_length` | 2 | 17.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 486 | `text_format_get_text_extent_undefined_width` | 10 | 16.5s |  |
| 487 | `text_format_rounding_swf7` | 840 | 16.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 488 | `text_format_rounding_swf8` | 840 | 16.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 489 | `textfield_background_color` | 11 | 16.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 490 | `textfield_border_color` | 11 | 16.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 491 | `textfield_cache_as_bitmap` | 1 | 16.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 492 | `textfield_maxchars` | 3 | 17.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 493 | `textfield_properties` | 44 | 17.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 494 | `textfield_props_swf5` | 175 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 495 | `textfield_props_swf6` | 210 | 17.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 496 | `textfield_props_swf7` | 210 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `textfield_props_swf8` | 210 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `textfield_text` | 7 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 499 | `textfield_variable` | 81 | 17.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 500 | `textsnapshot_available_text` | 20 | 16.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 501 | `textsnapshot_findtext` | 44 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 502 | `textsnapshot_gettext` | 55 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 503 | `textsnapshot_props_swf5` | 56 | 16.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 504 | `textsnapshot_props_swf6` | 56 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 505 | `textsnapshot_text_order` | 1 | 16.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 506 | `this_scoping` | 52 | 16.8s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 507 | `this_swf5` | 41 | 16.7s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 508 | `this_swf6` | 41 | 16.6s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 509 | `this_swf7` | 41 | 16.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 510 | `timeline_function_def` | 7 | 16.9s |  |
| 511 | `timer_run_actions` | 18 | 16.4s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 512 | `trace` | 8 | 15.9s |  |
| 513 | `transform` | 70 | 16.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 514 | `try_catch_finally` | 118 | 16.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 515 | `try_finally_simple` | 16 | 15.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 516 | `typeof` | 22 | 16.0s |  |
| 517 | `typeof_globals` | 7 | 16.0s |  |
| 518 | `uncaught_exception` | 1 | 15.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 519 | `uncaught_exception_bubbled` | 1 | 16.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 520 | `undefined_to_string_swf6` | 4 | 16.1s |  |
| 521 | `unescape` | 43 | 16.0s |  |
| 522 | `unload` | 52 | 16.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 523 | `unload_clip_event` | 4 | 16.0s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 524 | `unload_nested_child` | 5 | 16.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 525 | `unloadmovie` | 4 | 16.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 526 | `unloadmovie_method` | 3 | 16.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 527 | `unloadmovienum` | 13 | 16.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 528 | `use_hand_cursor` | 8 | 16.0s |  |
| 529 | `variable_args` | 5 | 16.0s |  |
| 530 | `waitforframe` | 7 | 16.0s |  |
| 531 | `waitforframe2` | 16 | 18.3s |  |
| 532 | `watch` | 117 | 17.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 533 | `watch_textfield` | 12 | 17.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 534 | `watch_virtual_property_proto` | 2 | 17.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 535 | `with` | 49 | 17.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 536 | `with_return` | 2 | 17.6s |  |
| 537 | `with_variable_scopes` | 43 | 16.9s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 538 | `xml` | 15 | 17.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 539 | `xml_append_child` | 28 | 16.9s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 540 | `xml_append_child_with_parent` | 20 | 17.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 541 | `xml_attributes_read` | 4 | 17.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 542 | `xml_cdata` | 11 | 17.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_child_nodes_edge_cases` | 4 | 17.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_clone_expandos` | 19 | 17.0s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 545 | `xml_first_last_child` | 8 | 16.7s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 546 | `xml_has_child_nodes` | 3 | 17.5s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 547 | `xml_idmap` | 21 | 17.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_ignore_comments` | 21 | 17.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_ignore_white` | 34 | 17.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_insert_before` | 20 | 16.7s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_inspect_createmethods` | 15 | 16.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_inspect_doctype` | 7 | 16.7s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_inspect_parsexml` | 62 | 17.0s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_inspect_xmldecl` | 7 | 16.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_namespaces` | 203 | 16.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 556 | `xml_parent_and_child` | 5 | 17.0s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 557 | `xml_remove_node` | 22 | 16.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 558 | `xml_reparenting` | 14 | 16.7s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 559 | `xml_siblings` | 10 | 16.7s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 560 | `xml_to_string` | 13 | 16.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 561 | `xml_to_string_comment` | 1 | 16.5s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 562 | `xml_unescaping` | 23 | 16.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 563 | `xmlnode_proto` | 1 | 16.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_hittest_shapeflag` | 92.3% | 312 | 338 | 26 | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 2 | `displacementmapfilter_mappoint_throw_error` | 53.8% | 7 | 13 | 6 | [25](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DISPLACEMENTMAPFILTER_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_hittest_shapeflag` | 92.3% | 312/338 | 338 | 338 | [42](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 2 | `displacementmapfilter_mappoint_throw_error` | 53.8% | 7/13 | 13 | 13 | [25](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/DISPLACEMENTMAPFILTER_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 3 | `global_proto_decls` | 2.6% | 116/4497 | 1288 | 4497 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 4 | `global_instance_decls` | 2.2% | 17/758 | 704 | 758 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 5 | `global_proto_decls_delete` | 2.2% | 93/4158 | 727 | 4158 | [41](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) |
| 6 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/blocked/PIXEL_TEXT_LAYOUT_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 15 | 15 | 0 |
| 6 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTER_CLONE_PLAN.md) | 0 | 0 | 0 |
| 7 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 0 | 0 | 0 |
| 8 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAP_FILTERS_PLAN.md) | 0 | 0 | 0 |
| 9 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
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
| 41 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/GLOBALS_PLAN.md) | 30 | 27 | 3 |
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
| 59 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 15 | 15 | 0 |
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
| 70 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 71 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 72 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
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
| 98 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 99 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 26 | 26 | 0 |
| | *(tests not in any document)* | 144 | 144 | 0 |
