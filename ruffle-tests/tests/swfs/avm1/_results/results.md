# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-04 02:19 UTC

**Git SHA**: `112f7a9df7`

**Run Duration**: 193m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 620 |
| Passing | **572** (92.3%) |
| Failing | 48 |
| Total expected lines | 91594 |
| Matching lines | 81329 (88.8%) |
| Mismatched lines | 10265 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 45 | 93.8% |
| Runtime Segfault | 2 | 4.2% |
| Timeout | 1 | 2.1% |

## Passing Tests

**572 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 19.1s |  |
| 2 | `action_to_integer` | 28 | 18.7s |  |
| 3 | `add` | 28 | 19.0s |  |
| 4 | `add2` | 354 | 19.1s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 18.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 18.6s |  |
| 7 | `add_swf5` | 28 | 18.6s |  |
| 8 | `arguments` | 127 | 18.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 18.6s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 18.9s |  |
| 11 | `array_constructor` | 30 | 18.5s |  |
| 12 | `array_enumerate` | 4 | 18.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 18.7s |  |
| 14 | `array_properties` | 36 | 18.6s |  |
| 15 | `array_prototyping` | 12 | 18.7s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 18.8s |  |
| 17 | `array_sort` | 161 | 19.3s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 18.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 19.1s |  |
| 20 | `array_trivial` | 209 | 18.9s |  |
| 21 | `as1_constructor_v6` | 35 | 18.5s |  |
| 22 | `as1_constructor_v7` | 35 | 18.7s |  |
| 23 | `as2_oop` | 13 | 18.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 18.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 18.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 18.7s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 18.3s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 18.3s |  |
| 29 | `as_broadcaster_undef` | 89 | 18.5s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 18.5s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 18.5s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 18.2s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 18.1s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 18.1s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 18.3s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 18.2s |  |
| 37 | `as_transformed_flag` | 20 | 18.3s |  |
| 38 | `asfunction` | 11 | 18.5s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 18.3s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 18.0s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `attach_movie` | 59 | 18.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 42 | `attach_movie_stop` | 3 | 18.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 43 | `bad_placeobject_clipaction` | 2 | 18.8s |  |
| 44 | `bad_swf_tag_past_eof` | 0 | 19.1s |  |
| 45 | `bitand` | 1058 | 22.6s |  |
| 46 | `bitmap_data` | 1126 | 21.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_colortransform` | 0 | 19.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 48 | `bitmap_data_compare` | 40 | 19.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_copypixels` | 17 | 19.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 50 | `bitmap_data_draw_cliprect` | 13 | 18.9s |  |
| 51 | `bitmap_data_fillrect` | 0 | 19.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_hittest` | 132 | 19.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 53 | `bitmap_data_max_size_swf10` | 12 | 19.0s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_max_size_swf9` | 10 | 18.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_noise` | 631 | 19.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_perlinnoise` | 0 | 20.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 57 | `bitmap_data_pixeldissolve` | 1075 | 20.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 58 | `bitmap_data_pixeldissolve_image` | 0 | 19.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 59 | `bitmap_data_threshold` | 176 | 19.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 60 | `bitmap_filters` | 548 | 20.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 61 | `bitmapdata_applyfilter_colormatrix` | 0 | 19.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [12](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 62 | `bitmapdata_channels` | 19 | 19.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 63 | `bitor` | 1058 | 22.8s |  |
| 64 | `biturshift` | 14 | 18.7s |  |
| 65 | `biturshift_swf8` | 14 | 18.4s |  |
| 66 | `bitxor` | 1058 | 21.1s |  |
| 67 | `boxed_primitives` | 24 | 18.7s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 68 | `button_children` | 8 | 18.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_goto` | 4 | 18.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_key_events` | 14 | 18.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_key_events_special` | 45 | 19.6s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `button_keypress` | 3 | 18.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 73 | `button_keypress_vs_press` | 25 | 18.6s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 74 | `button_keypress_vs_tab` | 20 | 18.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 75 | `button_keypress_vs_textinput` | 4 | 18.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 76 | `button_order` | 2 | 18.7s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 77 | `button_properties_special_cases` | 22 | 18.6s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 78 | `button_v5` | 18 | 18.4s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 79 | `button_v6` | 18 | 18.3s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 80 | `call` | 63 | 18.4s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 81 | `call_method_empty_name` | 1 | 18.5s |  |
| 82 | `capabilities_resolution` | 8 | 18.3s |  |
| 83 | `catch_references_registers` | 2 | 18.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 84 | `click_block` | 5 | 18.7s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 85 | `clip_constructors` | 8 | 18.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 86 | `clip_event_propagation_order` | 17 | 18.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 87 | `clip_events` | 19 | 18.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 88 | `clone_sprite_edittext` | 94 | 18.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 89 | `clone_sprite_edittext_dynamic` | 86 | 19.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 90 | `clone_sprite_types` | 24 | 18.7s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 91 | `closure_scope` | 7 | 18.6s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 92 | `coerce_to_object_monkeypatch` | 129 | 18.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 93 | `coerce_to_primitive_resolve` | 17 | 18.2s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 94 | `color` | 57 | 18.2s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 95 | `color_transform` | 48 | 18.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 96 | `conflicting_instance_names` | 23 | 18.0s |  |
| 97 | `constructor_function` | 2 | 17.9s |  |
| 98 | `context_menu` | 39 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 99 | `context_menu_item` | 41 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 100 | `create_empty_movie_clip` | 3 | 17.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 101 | `cross_movie_root` | 10 | 17.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 102 | `custom_clip_methods` | 4 | 17.9s | [21](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 103 | `default_names` | 52 | 17.9s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 104 | `define_function2` | 8 | 17.8s |  |
| 105 | `define_function2_preload` | 13 | 18.1s |  |
| 106 | `define_function2_preload_order` | 4 | 17.9s |  |
| 107 | `define_function_case_sensitive` | 2 | 18.1s |  |
| 108 | `define_local` | 27 | 18.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 109 | `define_local_with_paths` | 54 | 18.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 110 | `delete` | 3 | 18.1s |  |
| 111 | `device_font_spacing` | 91 | 18.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 112 | `displacementmapfilter_mappoint_throw_error` | 13 | 18.1s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 113 | `display_object_properties` | 2 | 17.9s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 114 | `divide_swf4` | 107 | 18.0s |  |
| 115 | `do_init_action` | 3 | 17.8s |  |
| 116 | `do_init_action_child` | 12 | 17.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 117 | `drag_drop` | 10 | 17.9s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 118 | `drag_over_from_outside` | 1 | 18.1s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 119 | `drag_over_without_startdrag` | 1 | 18.3s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 120 | `duplicate_movie_clip` | 20 | 18.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 121 | `duplicate_movie_clip_drawing` | 2 | 18.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 122 | `edittext_align` | 60 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 123 | `edittext_align_trailing_spaces_swf7` | 576 | 18.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 124 | `edittext_align_trailing_spaces_swf8` | 576 | 18.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 125 | `edittext_antialiastype` | 296 | 18.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 126 | `edittext_autosize` | 71 | 19.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 127 | `edittext_autosize_setter` | 20 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 128 | `edittext_bullet` | 30 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 129 | `edittext_default_format` | 221 | 18.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 130 | `edittext_default_format_empty` | 100 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 131 | `edittext_default_format_font_style` | 335 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 132 | `edittext_drag_select` | 9 | 18.3s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 133 | `edittext_focus_selection` | 2 | 18.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 134 | `edittext_font_size` | 45 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 135 | `edittext_hscroll` | 27 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 136 | `edittext_html_align_swf7` | 52 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 137 | `edittext_html_align_swf8` | 52 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_html_color` | 114 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_html_condensewhite_swf7` | 311 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_html_condensewhite_swf8` | 311 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_html_entity` | 4 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_html_roundtrip` | 17 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_html_swf6` | 5377 | 19.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_html_swf7` | 5377 | 19.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_html_swf8` | 5377 | 19.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_ime_focus_lost` | 7 | 18.3s | [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_input` | 1 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_input_newlines` | 9 | 18.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_leading` | 9 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_letter_spacing` | 15 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_margins` | 25 | 19.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_newline_stripping` | 64 | 23.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_newlines` | 30 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_password` | 5 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_password_copy` | 4 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_paste_empty` | 2 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_place_caret` | 2 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_programmatic_focus` | 12 | 18.2s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_restrict` | 191 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_restrict_paste` | 5 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_scroll` | 54 | 18.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_stylesheet` | 325 | 19.3s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `edittext_tab_focus` | 13 | 18.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 164 | `edittext_tab_stops` | 60 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 165 | `edittext_tag_indent` | 31 | 18.2s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 166 | `edittext_text_height_leading` | 20 | 18.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 167 | `edittext_underline` | 40 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 168 | `edittext_width_height` | 103 | 19.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 169 | `empty_movieclip_can_attach_movies` | 11 | 18.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 170 | `enumerate` | 64 | 18.5s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 171 | `equals` | 32 | 18.3s |  |
| 172 | `equals2_swf5` | 926 | 19.9s |  |
| 173 | `equals2_swf6` | 926 | 20.0s |  |
| 174 | `equals2_swf7` | 926 | 20.2s |  |
| 175 | `equals_swf4` | 665 | 18.9s |  |
| 176 | `equals_swf4_alt` | 32 | 18.1s |  |
| 177 | `equals_swf5` | 32 | 18.3s |  |
| 178 | `error` | 58 | 18.3s |  |
| 179 | `escape` | 14 | 18.4s |  |
| 180 | `execution_order1` | 5 | 18.3s |  |
| 181 | `execution_order2` | 7 | 18.2s |  |
| 182 | `execution_order3` | 4 | 18.1s |  |
| 183 | `execution_order4` | 12 | 18.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 184 | `export_assets` | 3 | 18.1s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 185 | `extends_chain` | 134 | 18.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 186 | `extends_native_type` | 11 | 18.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 187 | `external_interface` | 84 | 18.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 188 | `external_interface_escapexml` | 26 | 18.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 189 | `external_interface_jsquotestring` | 21 | 18.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 190 | `external_interface_toas_basic` | 354 | 18.4s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 191 | `external_interface_toxml_array` | 25 | 18.0s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 192 | `external_interface_toxml_basic` | 179 | 18.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 193 | `external_interface_unescapexml` | 40 | 18.0s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 194 | `focus_keyboard_press` | 60 | 18.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 195 | `focus_mouse` | 45 | 18.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 196 | `focus_mouse_focusable` | 8 | 18.5s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 197 | `focus_mouse_rollout` | 4 | 18.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 198 | `focus_remove` | 33 | 18.1s |  |
| 199 | `focus_root_movie` | 2 | 18.0s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 200 | `focus_visibility_change` | 45 | 18.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 201 | `focusrect_focuslost` | 4 | 18.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 202 | `focusrect_mouse_swf8` | 0 | 18.2s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 203 | `focusrect_mouse_swf9` | 0 | 18.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 204 | `focusrect_property_swf5` | 1237 | 18.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 205 | `focusrect_property_swf6` | 1237 | 18.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 206 | `focusrect_property_swf7` | 1237 | 18.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 207 | `focusrect_swf5` | 6 | 18.2s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 208 | `focusrect_swf6` | 42 | 18.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 209 | `form_loader_encoding_1` | 1 | 17.9s |  |
| 210 | `frame_size_translated_negative` | 21 | 18.0s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 211 | `frame_size_translated_positive` | 21 | 17.8s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 212 | `function_as_function` | 35 | 18.1s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 213 | `function_base_clip` | 8 | 18.1s |  |
| 214 | `function_base_clip_readded` | 11 | 18.1s |  |
| 215 | `function_base_clip_removed` | 25 | 18.2s |  |
| 216 | `function_suppress_and_preload` | 28 | 18.1s |  |
| 217 | `funky_function_calls` | 56 | 18.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 218 | `get_bytes_total` | 4 | 18.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 219 | `get_variable_in_scope` | 29 | 18.1s |  |
| 220 | `getproperty` | 28 | 18.0s |  |
| 221 | `getproperty_swf4` | 28 | 17.9s |  |
| 222 | `getproperty_swf5` | 28 | 17.9s |  |
| 223 | `gettextextent` | 56 | 17.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 224 | `global_array` | 3 | 17.8s |  |
| 225 | `global_is_bare` | 7 | 17.8s |  |
| 226 | `global_swf5_6_7_8_9` | 1145 | 18.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 227 | `global_swf6_7_8` | 15 | 18.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 228 | `globals_swf5` | 304 | 18.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 229 | `globals_swf6` | 304 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 230 | `globals_swf7` | 304 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 231 | `globals_swf8` | 304 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 232 | `goto_advance1` | 6 | 17.8s |  |
| 233 | `goto_advance2` | 2 | 17.9s |  |
| 234 | `goto_both_ways1` | 3 | 17.7s |  |
| 235 | `goto_both_ways2` | 3 | 17.8s |  |
| 236 | `goto_execution_order` | 2 | 17.9s |  |
| 237 | `goto_execution_order2` | 2 | 18.1s |  |
| 238 | `goto_frame` | 12 | 18.1s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 239 | `goto_frame2` | 44 | 18.3s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 240 | `goto_frame_number` | 3 | 18.0s |  |
| 241 | `goto_label` | 17 | 18.0s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 242 | `goto_methods` | 40 | 17.9s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 243 | `goto_rewind1` | 1 | 18.1s |  |
| 244 | `goto_rewind2` | 3 | 17.9s |  |
| 245 | `goto_rewind3` | 2 | 18.0s |  |
| 246 | `greater_swf6` | 1175 | 19.9s |  |
| 247 | `greater_swf7` | 1175 | 19.8s |  |
| 248 | `greaterthan_swf5` | 1 | 17.8s |  |
| 249 | `greaterthan_swf8` | 1 | 17.8s |  |
| 250 | `has_own_property` | 32 | 17.8s |  |
| 251 | `hittest_lockroot` | 15 | 18.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 252 | `hittest_morph` | 70 | 17.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 253 | `hittest_morph_input` | 1 | 17.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 254 | `hittest_winding_rule` | 12 | 18.0s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 255 | `infinite_recursion_function` | 4 | 17.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 256 | `infinite_recursion_function_in_setter` | 131 | 17.8s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 257 | `infinite_recursion_virtual_property` | 67 | 17.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 258 | `init_array_invalid` | 4 | 18.1s |  |
| 259 | `init_object_invalid` | 4 | 18.0s |  |
| 260 | `init_object_order` | 15 | 18.2s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 261 | `input_dead_keys_windows` | 15 | 18.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 262 | `instanceof_coercions` | 88 | 18.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 263 | `interface_implements_op` | 47 | 18.6s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 264 | `is_finite` | 49 | 18.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 265 | `is_finite_swf6` | 49 | 18.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 266 | `is_prototype_of` | 89 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 267 | `issue_1086` | 1 | 18.1s |  |
| 268 | `issue_1104` | 2 | 18.1s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 269 | `issue_1671` | 0 | 18.1s |  |
| 270 | `issue_1906` | 4 | 18.1s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 271 | `issue_2030` | 4 | 18.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 272 | `issue_2084` | 16 | 18.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 273 | `issue_2166` | 9 | 17.9s |  |
| 274 | `issue_2870` | 3 | 18.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 275 | `issue_3169` | 2 | 18.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 276 | `issue_3446` | 1 | 18.0s |  |
| 277 | `issue_3522` | 2 | 17.9s |  |
| 278 | `issue_4377` | 2 | 18.0s |  |
| 279 | `issue_710` | 4 | 18.7s |  |
| 280 | `issue_768` | 3 | 18.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 281 | `issue_9327` | 2 | 18.1s |  |
| 282 | `issue_9885` | 2 | 18.2s |  |
| 283 | `key_isToggled` | 9 | 18.0s |  |
| 284 | `lessthan` | 41 | 18.1s |  |
| 285 | `lessthan2_swf5` | 1226 | 20.2s |  |
| 286 | `lessthan2_swf6` | 1226 | 20.2s |  |
| 287 | `lessthan2_swf7` | 1226 | 20.1s |  |
| 288 | `lessthan_swf4` | 902 | 19.4s |  |
| 289 | `lessthan_swf4_alt` | 41 | 18.1s |  |
| 290 | `lessthan_swf5` | 41 | 18.0s |  |
| 291 | `loadmovie` | 2 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 292 | `loadmovie_fail` | 2 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 293 | `loadmovie_flashvars` | 4 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 294 | `loadmovie_method` | 2 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 295 | `loadmovie_registerclass` | 30 | 18.4s | [20](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 296 | `loadmovie_replace_root` | 5 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 297 | `loadmovie_var_persistence` | 8 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 298 | `loadmovienum` | 3 | 18.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 299 | `loadmovienum_cross_version_prototype` | 9 | 18.8s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) |
| 300 | `loadvariables` | 2 | 18.8s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 301 | `loadvariables2` | 8 | 18.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 302 | `loadvariablesnum` | 2 | 18.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 303 | `local_to_global` | 49 | 18.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 304 | `localconnection_properties` | 8 | 18.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 305 | `lock_root` | 1 | 18.6s |  |
| 306 | `logical_ops_swf4` | 90 | 18.2s |  |
| 307 | `logical_ops_swf8` | 108 | 18.2s |  |
| 308 | `looping` | 6 | 18.1s |  |
| 309 | `mask_reapply` | 0 | 18.2s | [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 310 | `mask_with_drawing` | 0 | 18.2s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 311 | `math_min_max` | 101 | 18.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 312 | `math_swf6` | 530 | 18.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 313 | `math_swf7` | 530 | 18.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 314 | `math_swf8` | 530 | 18.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 315 | `matrix` | 171 | 18.5s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 316 | `mcl_as_broadcaster` | 12 | 18.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 317 | `mcl_events_swf_version` | 232 | 18.8s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 318 | `mcl_getprogress` | 30 | 19.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 319 | `mcl_loadclip` | 149 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 320 | `mcl_loadclip_properties` | 6 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 321 | `mcl_loadclip_replace_root` | 1 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 322 | `mcl_mislabeled_target` | 6 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 323 | `mcl_target_gif87a` | 6 | 18.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 324 | `mcl_target_gif89a` | 6 | 18.7s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 325 | `mcl_target_jpg` | 6 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 326 | `mcl_target_png` | 6 | 18.1s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 327 | `mcl_unloadclip` | 5 | 18.0s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 328 | `mouse_events` | 8 | 17.9s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 329 | `mouse_events_visible_enabled` | 12 | 18.2s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 330 | `mouse_hover_events_while_dragging` | 1 | 18.2s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 331 | `mouse_listeners` | 67 | 18.1s |  |
| 332 | `mouse_pos` | 665 | 18.1s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 333 | `mouse_pos_with_scale_factor` | 260 | 18.0s | [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 334 | `mouse_wheel_enabled` | 2 | 18.0s |  |
| 335 | `movieclip_begin_gradient_fill` | 0 | 18.7s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 336 | `movieclip_blend_mode_property` | 35 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_create_text_field` | 90 | 18.3s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 338 | `movieclip_default_state` | 69 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_depth_methods` | 98 | 18.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 340 | `movieclip_focusenabled` | 99 | 18.2s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_get_instance_at_depth` | 28 | 18.0s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_getbounds` | 191 | 18.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 343 | `movieclip_gettextsnapshot` | 112 | 18.3s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_hittest` | 92 | 18.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_in_removed_button` | 4 | 18.1s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 346 | `movieclip_init_object` | 5 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 347 | `movieclip_invalid_get_bounds_1` | 75 | 18.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 348 | `movieclip_invalid_get_bounds_2` | 75 | 18.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 349 | `movieclip_invalid_get_bounds_3` | 13 | 18.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 350 | `movieclip_invalid_get_bounds_4` | 13 | 18.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 351 | `movieclip_invalid_get_bounds_5` | 11 | 18.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 352 | `movieclip_invalid_get_bounds_6` | 10 | 41.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 353 | `movieclip_invalid_get_bounds_7` | 10 | 42.0s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 354 | `movieclip_invalid_get_bounds_8` | 11 | 18.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 355 | `movieclip_line_gradient_style` | 0 | 18.4s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 356 | `movieclip_lockroot` | 29 | 19.6s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 357 | `movieclip_name_from_timeline` | 13 | 18.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 358 | `movieclip_prototype_extension` | 5 | 18.9s |  |
| 359 | `movieclip_setmask` | 14 | 19.1s | [27](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) |
| 360 | `moviecliploader_flashvars` | 4 | 18.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 361 | `mutable_this` | 18 | 18.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 362 | `named_shapes` | 14 | 18.9s |  |
| 363 | `nan_scale` | 9 | 19.0s |  |
| 364 | `native_double_construct` | 12 | 18.8s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 365 | `native_subclasses` | 191 | 19.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 366 | `nested_textfields_in_buttons` | 0 | 18.7s |  |
| 367 | `netconnection_close` | 39 | 18.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 368 | `new_method_wrap` | 4 | 18.1s |  |
| 369 | `new_object_enumerate` | 7 | 17.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 370 | `new_object_wrap` | 4 | 17.9s |  |
| 371 | `o` | 3 | 17.8s |  |
| 372 | `object_constructor` | 33 | 17.8s |  |
| 373 | `object_function` | 32 | 17.9s |  |
| 374 | `object_properties` | 31 | 18.0s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 375 | `object_prototypes` | 74 | 17.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 376 | `object_resolve` | 38 | 18.0s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 377 | `object_string_coerce_swf5` | 62 | 17.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 378 | `object_string_coerce_swf6` | 68 | 18.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 379 | `on_construct` | 25 | 18.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 380 | `parse_float` | 74 | 17.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 381 | `parse_int` | 64 | 18.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 382 | `path_string` | 322 | 18.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 383 | `place_and_lookup` | 30 | 17.9s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 384 | `placeobject_occupied_depth` | 6 | 17.9s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 385 | `point` | 175 | 18.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 386 | `primitive_instanceof` | 37 | 17.9s |  |
| 387 | `primitive_type_globals` | 557 | 18.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 388 | `printjob_props_swf5` | 45 | 17.9s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 389 | `printjob_props_swf6` | 45 | 18.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 390 | `printjob_props_swf7` | 45 | 18.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 391 | `property_invalid_base_clip` | 36 | 18.1s |  |
| 392 | `prototype_delete` | 12 | 18.0s |  |
| 393 | `prototype_enumerate` | 5 | 18.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 394 | `prototype_properties` | 17 | 18.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 395 | `rectangle` | 745 | 18.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 396 | `recursive_prototypes` | 0 | 18.2s |  |
| 397 | `register_and_init_order` | 231 | 18.9s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 398 | `register_class` | 66 | 18.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 399 | `register_class_return_value` | 16 | 18.2s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 400 | `register_class_swf6` | 37 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 401 | `register_class_with_sound` | 11 | 18.3s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 402 | `register_globals_across_frames` | 15 | 18.3s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 403 | `register_underflow` | 26 | 18.1s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 404 | `remove_movie_clip` | 29 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 405 | `removed_clip_halts_script` | 15 | 18.4s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 406 | `removed_target_clip_scope` | 35 | 18.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 407 | `resolve_different_root` | 2 | 18.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 408 | `rewind_depth` | 30 | 18.0s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 409 | `root_button_mode` | 10 | 17.8s | [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 410 | `root_global_parent` | 6 | 17.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 411 | `root_onload` | 1 | 17.9s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 412 | `sandbox_type_local_file` | 1 | 17.9s |  |
| 413 | `sandbox_type_local_network` | 1 | 17.8s |  |
| 414 | `selection` | 454 | 17.9s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 415 | `selection_handlers` | 27 | 17.7s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 416 | `set_interval` | 27 | 17.7s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 417 | `set_variable_scope` | 58 | 17.9s |  |
| 418 | `single_frame` | 1 | 17.6s |  |
| 419 | `slash_syntax` | 14 | 17.8s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 420 | `sound` | 628 | 18.0s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 421 | `sound_duration_position_props` | 290 | 18.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 422 | `sound_load_start` | 3 | 17.8s | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 423 | `sound_multiple_load` | 1 | 17.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 424 | `sound_props_swf5` | 68 | 17.8s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 425 | `sound_props_swf6` | 68 | 18.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 426 | `sound_start_load` | 0 | 18.2s |  |
| 427 | `stage_display_state` | 16 | 18.1s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 428 | `stage_object_children` | 83 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 429 | `stage_object_enumerate` | 4 | 18.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 430 | `stage_object_properties` | 241 | 18.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 431 | `stage_object_properties_get_var` | 5 | 18.2s |  |
| 432 | `stage_object_properties_swf6` | 231 | 18.5s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 433 | `stage_property_representation` | 586 | 18.2s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 434 | `stage_scale_mode` | 39 | 18.2s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 435 | `strictequals_swf6` | 902 | 19.6s |  |
| 436 | `strictly_equals` | 7 | 18.1s |  |
| 437 | `string_coercion` | 117 | 18.4s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 438 | `string_methods` | 285 | 18.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 439 | `string_methods_negative_args` | 240 | 18.7s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 440 | `string_methods_swfv5` | 275 | 19.2s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 441 | `string_ops_swf6` | 95 | 18.4s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 442 | `string_paths_basic` | 4 | 18.1s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 443 | `string_paths_eval` | 4 | 18.1s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 444 | `string_paths_eval2` | 7 | 18.2s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 445 | `string_paths_hidden` | 54 | 18.3s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 446 | `string_paths_keyevents` | 0 | 18.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 447 | `string_paths_other` | 36 | 18.0s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 448 | `string_paths_timer` | 0 | 17.8s | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 449 | `string_paths_unload` | 1 | 17.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 450 | `string_paths_variable_alias` | 4 | 17.9s | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 451 | `string_paths_variable_scopes` | 5 | 17.9s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 452 | `string_relational_compare` | 4 | 17.9s |  |
| 453 | `stylesheet` | 283 | 18.8s |  |
| 454 | `stylesheet_transform` | 750 | 18.8s |  |
| 455 | `super_edge_cases` | 39 | 18.1s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 456 | `swf4_actions_bool` | 96 | 17.9s |  |
| 457 | `swf4_actions_coercion_order` | 158 | 18.0s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 458 | `swf4_bool` | 4 | 18.0s |  |
| 459 | `swf4_function_calls` | 7 | 18.0s |  |
| 460 | `swf5_encoding` | 3 | 17.9s |  |
| 461 | `swf5_global_funcs` | 232 | 18.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 462 | `swf5_no_closure` | 19 | 18.0s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 463 | `swf5_to_6_cross_call` | 29 | 18.6s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 464 | `swf6_case_insensitive` | 42 | 18.8s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 465 | `swf6_global_funcs` | 232 | 18.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 466 | `swf6_string_as_bool` | 15 | 18.8s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 467 | `swf6_to_5_cross_call` | 29 | 18.8s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 468 | `swf7_case_sensitive` | 44 | 18.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 469 | `swf7_global_funcs` | 232 | 19.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 470 | `tab_ordering_automatic_basic` | 92 | 19.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 471 | `tab_ordering_automatic_order_grid` | 21 | 19.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 472 | `tab_ordering_automatic_order_same_position` | 12 | 18.9s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 473 | `tab_ordering_children` | 208 | 19.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 474 | `tab_ordering_custom_basic` | 71 | 19.2s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 475 | `tab_ordering_custom_duplicate_index` | 22 | 18.9s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 476 | `tab_ordering_custom_i32_vs_u32` | 12 | 19.0s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 477 | `tab_ordering_custom_m1` | 29 | 19.1s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 478 | `tab_ordering_events` | 150 | 19.7s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 479 | `tab_ordering_events_mouse` | 65 | 19.8s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 480 | `tab_ordering_movieclip_enabled_default` | 462 | 20.0s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 481 | `tab_ordering_properties` | 293 | 19.7s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 482 | `tab_ordering_reverse` | 51 | 18.6s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 483 | `tab_ordering_tabbable` | 47 | 18.5s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 484 | `target_clip_removed` | 5 | 18.5s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 485 | `target_clip_swf5` | 2 | 18.2s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 486 | `target_clip_swf6` | 2 | 18.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 487 | `target_path` | 14 | 18.6s |  |
| 488 | `tell_target` | 37 | 18.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 489 | `tell_target_invalid` | 6 | 18.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 490 | `tell_target_invalid_swf6` | 5 | 18.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 491 | `text_blocks_clicks` | 4 | 18.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 492 | `text_format` | 1146 | 18.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 493 | `text_format_display` | 21 | 18.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 494 | `text_format_font_max_length` | 2 | 18.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 495 | `text_format_get_text_extent_undefined_width` | 10 | 18.5s |  |
| 496 | `text_format_rounding_swf7` | 840 | 18.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `text_format_rounding_swf8` | 840 | 18.7s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `textfield_background_color` | 11 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 499 | `textfield_border_color` | 11 | 18.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 500 | `textfield_cache_as_bitmap` | 1 | 18.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 501 | `textfield_maxchars` | 3 | 19.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 502 | `textfield_properties` | 44 | 19.3s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 503 | `textfield_props_swf5` | 175 | 19.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 504 | `textfield_props_swf6` | 210 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 505 | `textfield_props_swf7` | 210 | 19.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 506 | `textfield_props_swf8` | 210 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 507 | `textfield_text` | 7 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 508 | `textfield_variable` | 81 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 509 | `textsnapshot_available_text` | 20 | 19.2s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 510 | `textsnapshot_findtext` | 44 | 19.4s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 511 | `textsnapshot_gettext` | 55 | 19.5s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 512 | `textsnapshot_props_swf5` | 56 | 19.0s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 513 | `textsnapshot_props_swf6` | 56 | 18.8s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 514 | `textsnapshot_text_order` | 1 | 19.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 515 | `this_scoping` | 52 | 19.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 516 | `this_swf5` | 41 | 19.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 517 | `this_swf6` | 41 | 19.0s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 518 | `this_swf7` | 41 | 19.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 519 | `timeline_function_def` | 7 | 19.2s |  |
| 520 | `timer_run_actions` | 18 | 19.1s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 521 | `trace` | 8 | 18.1s |  |
| 522 | `transform` | 70 | 18.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 523 | `try_catch_finally` | 118 | 18.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 524 | `try_finally_simple` | 16 | 18.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 525 | `typeof` | 22 | 18.1s |  |
| 526 | `typeof_globals` | 7 | 17.9s |  |
| 527 | `uncaught_exception` | 1 | 18.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 528 | `uncaught_exception_bubbled` | 1 | 17.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 529 | `undefined_to_string_swf6` | 4 | 18.0s |  |
| 530 | `unescape` | 43 | 18.1s |  |
| 531 | `unload` | 52 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 532 | `unload_clip_event` | 4 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 533 | `unload_nested_child` | 5 | 18.2s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 534 | `unloadmovie` | 4 | 18.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 535 | `unloadmovie_method` | 3 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 536 | `unloadmovienum` | 13 | 18.2s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 537 | `use_hand_cursor` | 8 | 18.2s |  |
| 538 | `variable_args` | 5 | 18.5s |  |
| 539 | `waitforframe` | 7 | 18.3s |  |
| 540 | `waitforframe2` | 16 | 18.5s |  |
| 541 | `watch` | 117 | 18.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 542 | `watch_textfield` | 12 | 18.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 543 | `watch_virtual_property_proto` | 2 | 18.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 544 | `with` | 49 | 18.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 545 | `with_return` | 2 | 18.3s |  |
| 546 | `with_variable_scopes` | 43 | 18.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 547 | `xml` | 15 | 18.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_append_child` | 28 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_append_child_with_parent` | 20 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_attributes_read` | 4 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_cdata` | 11 | 18.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_child_nodes_edge_cases` | 4 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_clone_expandos` | 19 | 18.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_first_last_child` | 8 | 19.1s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_has_child_nodes` | 3 | 19.0s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 556 | `xml_idmap` | 21 | 19.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 557 | `xml_ignore_comments` | 21 | 19.7s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 558 | `xml_ignore_white` | 34 | 19.1s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 559 | `xml_insert_before` | 20 | 18.7s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 560 | `xml_inspect_createmethods` | 15 | 18.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 561 | `xml_inspect_doctype` | 7 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 562 | `xml_inspect_parsexml` | 62 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 563 | `xml_inspect_xmldecl` | 7 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 564 | `xml_namespaces` | 203 | 18.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 565 | `xml_parent_and_child` | 5 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 566 | `xml_remove_node` | 22 | 18.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 567 | `xml_reparenting` | 14 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 568 | `xml_siblings` | 10 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 569 | `xml_to_string` | 13 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 570 | `xml_to_string_comment` | 1 | 18.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 571 | `xml_unescaping` | 23 | 18.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 572 | `xmlnode_proto` | 1 | 18.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.3% | 6289 | 6335 | 46 | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56 | 57 | 1 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56 | 57 | 1 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `movieclip_library_state_values` | 97.4% | 76 | 78 | 2 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_hittest_shapeflag` | 96.4% | 326 | 338 | 12 | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) |
| 6 | `native_objects_swf7` | 91.3% | 105 | 115 | 10 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `native_objects_swf8` | 89.6% | 103 | 115 | 12 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `native_objects_swf6` | 21.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `netstream_play_flv_screen` | 36.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `timeout` | runtime timeout (>10s) | 49.1s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |

## All Output Mismatches

**45 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.3% | 6289/6335 | 6335 | 6335 | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `mcl_replace_root_swf7_to_swf5` | 98.2% | 56/57 | 57 | 57 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 3 | `mcl_replace_root_swf7_to_swf6` | 98.2% | 56/57 | 57 | 57 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 4 | `movieclip_library_state_values` | 97.4% | 76/78 | 78 | 78 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 5 | `movieclip_hittest_shapeflag` | 96.4% | 326/338 | 338 | 338 | [42](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [98](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) |
| 6 | `native_objects_swf7` | 91.3% | 105/115 | 115 | 115 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 7 | `native_objects_swf8` | 89.6% | 103/115 | 115 | 115 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 9 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 10 | `load_vars` | 37.1% | 13/35 | 23 | 35 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 11 | `movieclip_state_values` | 34.2% | 39/114 | 63 | 114 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [50](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 12 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 13 | `form_loader_encoding_4` | 33.3% | 1/3 | 3 | 3 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 14 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 15 | `tab_ordering_properties_tab_index_edge_case` | 25.0% | 1/4 | 4 | 4 |  |
| 16 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 17 | `global_proto_decls` | 18.0% | 809/4497 | 3725 | 4497 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 18 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 19 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 20 | `localconnection` | 12.8% | 74/579 | 261 | 579 | [52](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 21 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 22 | `netstream_play_flv` | 9.5% | 2/21 | 2 | 21 | [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 23 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 24 | `global_proto_decls_delete` | 7.1% | 297/4158 | 885 | 4158 | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 25 | `sound_id3_prop` | 5.8% | 8/138 | 18 | 138 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) |
| 26 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 27 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 28 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 29 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 30 | `sound_id3` | 2.7% | 17/633 | 229 | 633 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) |
| 31 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 32 | `netconnection_send_remote` | 2.0% | 1/50 | 20 | 50 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 33 | `global_instance_decls` | 1.6% | 14/853 | 853 | 758 | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 34 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 35 | `geturl` | 0.0% | 0/7 | 0 | 7 | [96](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 36 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 37 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 38 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 | [33](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 39 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 1 | 2 | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 40 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 41 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 0 | 2 | [84](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 42 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 43 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 44 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 45 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 17 | 17 | 0 |
| 6 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 1 | 1 | 0 |
| 7 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 1 | 1 | 0 |
| 8 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 1 | 1 | 0 |
| 9 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 13 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 14 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 15 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 16 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 17 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 18 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 19 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 20 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 21 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 22 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 23 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 24 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 25 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 26 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 27 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 28 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 29 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 30 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 14 | 0 |
| 31 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 32 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 33 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/FLV_PLAYBACK_PLAN.md) | 3 | 0 | 3 |
| 34 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 35 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 36 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 37 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 38 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 39 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 6 | 1 |
| 40 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 41 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 31 | 25 | 6 |
| 42 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 43 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 4 | 19 |
| 44 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 45 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 46 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 47 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 48 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 49 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 42 | 6 |
| 50 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 5 | 3 | 2 |
| 51 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 52 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 1 | 0 | 1 |
| 53 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 54 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 55 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 56 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 57 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 58 | 53 | 5 |
| 58 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 59 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 14 | 3 |
| 60 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 2 | 1 | 1 |
| 61 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 62 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 63 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 64 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 65 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 66 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 67 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 68 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 69 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 70 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 71 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 72 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 73 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 74 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 75 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 76 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 77 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SOUND_ID3_PLAN.md) | 2 | 0 | 2 |
| 78 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 2 | 2 | 0 |
| 79 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 80 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 81 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 82 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 13 | 12 | 1 |
| 83 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 84 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 1 | 0 | 1 |
| 85 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 86 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 87 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 88 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 19 | 17 | 2 |
| 89 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 70 | 0 |
| 90 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 91 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 92 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 93 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 2 | 1 |
| 94 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 95 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 96 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 13 | 3 |
| 97 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 98 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/incomplete/VECTOR_PATH_HITTEST_PLAN.md) | 1 | 0 | 1 |
| 99 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 100 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 26 | 7 |
| | *(tests not in any document)* | 146 | 145 | 1 |
