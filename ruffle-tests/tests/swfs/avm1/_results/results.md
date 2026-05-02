# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-02 19:29 UTC

**Git SHA**: `802674fd5c`

**Run Duration**: 53m 20s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 647 |
| Passing | **568** (87.8%) |
| Ruffle-matched | 9 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **577** (89.2%) |
| Failing | 70 |
| Total expected lines | 114967 |
| Matching lines | 104658 (91.0%) |
| Mismatched lines | 10309 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 70 | 100.0% |

## Passing Tests

**568 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 17.2s |  |
| 2 | `action_to_integer` | 28 | 0.2s |  |
| 3 | `add` | 28 | 16.8s |  |
| 4 | `add2` | 354 | 0.2s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 0.3s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.3s |  |
| 7 | `add_swf5` | 28 | 0.3s |  |
| 8 | `arguments` | 127 | 0.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 0.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 0.3s |  |
| 11 | `array_constructor` | 30 | 0.2s |  |
| 12 | `array_enumerate` | 4 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 0.2s |  |
| 14 | `array_properties` | 36 | 0.2s |  |
| 15 | `array_prototyping` | 12 | 0.3s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 0.2s |  |
| 17 | `array_sort` | 161 | 0.3s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 16.7s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 0.3s |  |
| 20 | `array_trivial` | 209 | 0.3s |  |
| 21 | `as1_constructor_v6` | 35 | 0.2s |  |
| 22 | `as1_constructor_v7` | 35 | 0.2s |  |
| 23 | `as2_oop` | 13 | 17.5s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 16.7s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 0.2s |  |
| 29 | `as_broadcaster_undef` | 89 | 0.3s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 0.3s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 0.4s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 0.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 0.3s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 0.3s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 0.3s |  |
| 37 | `as_transformed_flag` | 20 | 16.5s |  |
| 38 | `asfunction` | 11 | 0.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 0.2s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 16.7s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `attach_movie` | 59 | 17.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 42 | `attach_movie_stop` | 3 | 17.4s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 43 | `bad_placeobject_clipaction` | 2 | 0.3s |  |
| 44 | `bad_swf_tag_past_eof` | 0 | 0.3s |  |
| 45 | `bitand` | 1058 | 0.3s |  |
| 46 | `bitmap_data` | 1126 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_colortransform` | 0 | 17.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 48 | `bitmap_data_compare` | 40 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_copypixels` | 17 | 17.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 50 | `bitmap_data_draw_cliprect` | 13 | 17.0s |  |
| 51 | `bitmap_data_fillrect` | 0 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_hittest` | 132 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 53 | `bitmap_data_max_size_swf10` | 12 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_max_size_swf9` | 10 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_noise` | 631 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_perlinnoise` | 0 | 17.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 57 | `bitmap_data_pixeldissolve` | 1075 | 0.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 58 | `bitmap_data_pixeldissolve_image` | 0 | 17.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 59 | `bitmap_data_thorough/colorTransform` | 279 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 60 | `bitmap_data_thorough/compare` | 69 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 61 | `bitmap_data_thorough/constructor` | 313 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 62 | `bitmap_data_thorough/copyChannel` | 2715 | 0.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 63 | `bitmap_data_thorough/fillRect` | 342 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 64 | `bitmap_data_thorough/floodFill` | 867 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 65 | `bitmap_data_thorough/getColorBoundsRect` | 285 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 66 | `bitmap_data_thorough/getPixel` | 141 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 67 | `bitmap_data_thorough/getPixel32` | 141 | 0.7s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 68 | `bitmap_data_thorough/hitTest` | 519 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 69 | `bitmap_data_thorough/merge` | 1203 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 70 | `bitmap_data_thorough/noise` | 1518 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 71 | `bitmap_data_thorough/scroll` | 384 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 72 | `bitmap_data_thorough/setPixel` | 531 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 73 | `bitmap_data_thorough/setPixel32` | 531 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 74 | `bitmap_data_thorough/threshold` | 1308 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 75 | `bitmap_data_threshold` | 176 | 17.8s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 76 | `bitmap_filters` | 548 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 77 | `bitmapdata_applyfilter_colormatrix` | 0 | 18.1s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 78 | `bitmapdata_channels` | 19 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 79 | `bitor` | 1058 | 0.3s |  |
| 80 | `biturshift` | 14 | 0.3s |  |
| 81 | `biturshift_swf8` | 14 | 17.1s |  |
| 82 | `bitxor` | 1058 | 0.3s |  |
| 83 | `boxed_primitives` | 24 | 17.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 84 | `button_children` | 8 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 85 | `button_goto` | 4 | 16.7s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 86 | `button_key_events` | 14 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 87 | `button_key_events_special` | 45 | 0.4s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 88 | `button_keypress` | 3 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 89 | `button_keypress_vs_press` | 25 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 90 | `button_keypress_vs_tab` | 20 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 91 | `button_keypress_vs_textinput` | 4 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 92 | `button_order` | 2 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 93 | `button_properties_special_cases` | 22 | 17.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 94 | `button_v5` | 18 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 95 | `button_v6` | 18 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 96 | `call` | 63 | 16.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 97 | `call_method_empty_name` | 1 | 0.3s |  |
| 98 | `capabilities_resolution` | 8 | 17.1s |  |
| 99 | `catch_references_registers` | 2 | 0.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 100 | `click_block` | 5 | 16.9s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 101 | `clip_constructors` | 8 | 17.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 102 | `clip_event_propagation_order` | 17 | 17.1s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 103 | `clip_events` | 19 | 17.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 104 | `clone_sprite_types` | 24 | 0.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 105 | `closure_scope` | 7 | 17.0s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 106 | `coerce_to_object_monkeypatch` | 129 | 17.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 107 | `coerce_to_primitive_resolve` | 17 | 17.7s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 108 | `color` | 57 | 17.5s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 109 | `color_transform` | 48 | 0.3s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 110 | `conflicting_instance_names` | 23 | 16.9s |  |
| 111 | `constructor_function` | 2 | 0.3s |  |
| 112 | `context_menu` | 39 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 113 | `context_menu_item` | 41 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 114 | `create_empty_movie_clip` | 3 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 115 | `cross_movie_root` | 10 | 16.9s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 116 | `custom_clip_methods` | 4 | 0.3s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 117 | `default_names` | 52 | 0.3s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 118 | `define_function2` | 8 | 0.3s |  |
| 119 | `define_function2_preload` | 13 | 0.3s |  |
| 120 | `define_function2_preload_order` | 4 | 0.3s |  |
| 121 | `define_function_case_sensitive` | 2 | 16.9s |  |
| 122 | `define_local` | 27 | 17.6s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 123 | `define_local_with_paths` | 54 | 0.3s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 124 | `delete` | 3 | 17.6s |  |
| 125 | `depth_replacement_audio_unloading` | 3 | 17.5s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) |
| 126 | `device_font_spacing` | 91 | 17.3s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 127 | `displacementmapfilter_mappoint_throw_error` | 13 | 0.3s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 128 | `display_object_properties` | 2 | 17.4s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 129 | `divide_swf4` | 107 | 0.3s |  |
| 130 | `do_init_action` | 3 | 0.3s |  |
| 131 | `do_init_action_child` | 12 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 132 | `drag_drop` | 10 | 0.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 133 | `drag_over_from_outside` | 1 | 17.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 134 | `drag_over_without_startdrag` | 1 | 0.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 135 | `duplicate_movie_clip` | 20 | 0.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 136 | `duplicate_movie_clip_drawing` | 2 | 0.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 137 | `edittext_antialiastype` | 296 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 138 | `edittext_autosize_setter` | 20 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_hscroll` | 27 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_html_condensewhite_swf7` | 311 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_html_condensewhite_swf8` | 311 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_html_entity` | 4 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_html_swf6` | 5377 | 0.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_html_swf7` | 5377 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_html_swf8` | 5377 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_input` | 1 | 16.8s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_input_newlines` | 9 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_newline_stripping` | 64 | 6.6s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_password` | 5 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_password_copy` | 4 | 17.6s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_paste_empty` | 2 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_place_caret` | 2 | 17.7s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_restrict` | 191 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_restrict_paste` | 5 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_scroll` | 54 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_width_height` | 103 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `empty_movieclip_can_attach_movies` | 11 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 158 | `enumerate` | 64 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 159 | `equals` | 32 | 0.3s |  |
| 160 | `equals2_swf5` | 926 | 0.3s |  |
| 161 | `equals2_swf6` | 926 | 16.6s |  |
| 162 | `equals2_swf7` | 926 | 0.3s |  |
| 163 | `equals_swf4` | 665 | 0.3s |  |
| 164 | `equals_swf4_alt` | 32 | 16.9s |  |
| 165 | `equals_swf5` | 32 | 0.3s |  |
| 166 | `error` | 58 | 0.3s |  |
| 167 | `escape` | 14 | 0.2s |  |
| 168 | `execution_order1` | 5 | 16.6s |  |
| 169 | `execution_order2` | 7 | 16.5s |  |
| 170 | `execution_order3` | 4 | 0.3s |  |
| 171 | `execution_order4` | 12 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 172 | `export_assets` | 3 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 173 | `extends_chain` | 134 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 174 | `extends_native_type` | 11 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 175 | `external_interface` | 84 | 0.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 176 | `external_interface_escapexml` | 26 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 177 | `external_interface_jsquotestring` | 21 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 178 | `external_interface_toas_basic` | 354 | 0.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 179 | `external_interface_toxml_array` | 25 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 180 | `external_interface_toxml_basic` | 179 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 181 | `external_interface_unescapexml` | 40 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 182 | `focus_keyboard_press` | 60 | 0.2s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 183 | `focus_mouse` | 45 | 0.2s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 184 | `focus_mouse_focusable` | 8 | 14.2s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 185 | `focus_mouse_rollout` | 4 | 0.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 186 | `focus_remove` | 33 | 13.6s |  |
| 187 | `focus_root_movie` | 2 | 0.2s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 188 | `focus_visibility_change` | 45 | 0.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 189 | `focusrect_focuslost` | 4 | 13.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 190 | `focusrect_mouse_swf8` | 0 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 191 | `focusrect_mouse_swf9` | 0 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 192 | `focusrect_property_swf5` | 1237 | 0.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 193 | `focusrect_property_swf6` | 1237 | 0.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 194 | `focusrect_property_swf7` | 1237 | 13.8s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 195 | `focusrect_swf5` | 6 | 13.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 196 | `focusrect_swf6` | 42 | 0.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 197 | `form_loader_encoding_1` | 1 | 19.2s |  |
| 198 | `frame_size_translated_negative` | 21 | 16.8s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 199 | `frame_size_translated_positive` | 21 | 16.8s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 200 | `function_as_function` | 35 | 16.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 201 | `function_base_clip` | 8 | 16.6s |  |
| 202 | `function_base_clip_readded` | 11 | 16.6s |  |
| 203 | `function_base_clip_removed` | 25 | 16.6s |  |
| 204 | `function_suppress_and_preload` | 28 | 16.5s |  |
| 205 | `funky_function_calls` | 56 | 0.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 206 | `get_bytes_total` | 4 | 16.5s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 207 | `get_variable_in_scope` | 29 | 0.2s |  |
| 208 | `getproperty` | 28 | 0.2s |  |
| 209 | `getproperty_swf4` | 28 | 0.2s |  |
| 210 | `getproperty_swf5` | 28 | 0.2s |  |
| 211 | `gettextextent` | 56 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 212 | `global_array` | 3 | 0.2s |  |
| 213 | `global_is_bare` | 7 | 0.2s |  |
| 214 | `global_swf5_6_7_8_9` | 1145 | 17.7s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 215 | `global_swf6_7_8` | 15 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 216 | `globals_swf6` | 304 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 217 | `globals_swf7` | 304 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 218 | `globals_swf8` | 304 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 219 | `goto_advance1` | 6 | 17.6s |  |
| 220 | `goto_advance2` | 2 | 0.3s |  |
| 221 | `goto_both_ways1` | 3 | 0.3s |  |
| 222 | `goto_both_ways2` | 3 | 17.7s |  |
| 223 | `goto_execution_order` | 2 | 17.5s |  |
| 224 | `goto_execution_order2` | 2 | 0.3s |  |
| 225 | `goto_frame` | 12 | 0.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 226 | `goto_frame2` | 44 | 17.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 227 | `goto_frame_number` | 3 | 17.3s |  |
| 228 | `goto_label` | 17 | 17.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 229 | `goto_methods` | 40 | 0.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 230 | `goto_rewind1` | 1 | 0.3s |  |
| 231 | `goto_rewind2` | 3 | 0.3s |  |
| 232 | `goto_rewind3` | 2 | 0.3s |  |
| 233 | `greater_swf6` | 1175 | 17.1s |  |
| 234 | `greater_swf7` | 1175 | 0.3s |  |
| 235 | `greaterthan_swf5` | 1 | 0.3s |  |
| 236 | `greaterthan_swf8` | 1 | 0.3s |  |
| 237 | `has_own_property` | 32 | 0.3s |  |
| 238 | `hittest_lockroot` | 15 | 17.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 239 | `hittest_morph` | 70 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 240 | `hittest_morph_input` | 1 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 241 | `hittest_winding_rule` | 12 | 17.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 242 | `infinite_recursion_function` | 4 | 0.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 243 | `infinite_recursion_function_in_setter` | 131 | 0.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 244 | `infinite_recursion_virtual_property` | 67 | 0.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 245 | `init_array_invalid` | 4 | 17.0s |  |
| 246 | `init_object_invalid` | 4 | 0.1s |  |
| 247 | `init_object_order` | 15 | 0.3s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 248 | `input_dead_keys_windows` | 15 | 0.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 249 | `instanceof_coercions` | 88 | 0.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 250 | `interface_implements_op` | 47 | 0.3s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 251 | `is_finite` | 49 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 252 | `is_finite_swf6` | 49 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 253 | `is_prototype_of` | 89 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 254 | `issue_1086` | 1 | 0.3s |  |
| 255 | `issue_1104` | 2 | 16.9s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 256 | `issue_1671` | 0 | 16.9s |  |
| 257 | `issue_1906` | 4 | 0.3s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 258 | `issue_2030` | 4 | 16.8s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 259 | `issue_2084` | 16 | 17.1s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 260 | `issue_2166` | 9 | 0.3s |  |
| 261 | `issue_2870` | 3 | 16.8s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 262 | `issue_3169` | 2 | 0.3s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 263 | `issue_3446` | 1 | 0.3s |  |
| 264 | `issue_3522` | 2 | 0.3s |  |
| 265 | `issue_4377` | 2 | 0.3s |  |
| 266 | `issue_710` | 4 | 0.3s |  |
| 267 | `issue_768` | 3 | 0.3s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 268 | `issue_9327` | 2 | 17.0s |  |
| 269 | `issue_9885` | 2 | 0.3s |  |
| 270 | `key_isToggled` | 9 | 0.3s |  |
| 271 | `lessthan` | 41 | 17.0s |  |
| 272 | `lessthan2_swf5` | 1226 | 0.3s |  |
| 273 | `lessthan2_swf6` | 1226 | 0.3s |  |
| 274 | `lessthan2_swf7` | 1226 | 0.3s |  |
| 275 | `lessthan_swf4` | 902 | 0.3s |  |
| 276 | `lessthan_swf4_alt` | 41 | 0.3s |  |
| 277 | `lessthan_swf5` | 41 | 18.1s |  |
| 278 | `loadmovie` | 2 | 17.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 279 | `loadmovie_fail` | 2 | 17.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 280 | `loadmovie_flashvars` | 4 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 281 | `loadmovie_method` | 2 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 282 | `loadmovie_registerclass` | 30 | 0.3s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 283 | `loadmovie_replace_root` | 5 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 284 | `loadmovie_var_persistence` | 8 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 285 | `loadmovienum` | 3 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 286 | `loadmovienum_cross_version_prototype` | 9 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 287 | `loadvariables` | 2 | 17.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 288 | `loadvariables2` | 8 | 17.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 289 | `loadvariablesnum` | 2 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 290 | `loadvars_tostring` | 5 | 0.3s |  |
| 291 | `local_to_global` | 49 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 292 | `localconnection_properties` | 8 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 293 | `lock_root` | 1 | 0.3s |  |
| 294 | `logical_ops_swf4` | 90 | 0.3s |  |
| 295 | `logical_ops_swf8` | 108 | 0.3s |  |
| 296 | `looping` | 6 | 18.0s |  |
| 297 | `mask_reapply` | 0 | 17.4s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 298 | `mask_with_drawing` | 0 | 17.1s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 299 | `math_min_max` | 101 | 16.8s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 300 | `math_swf6` | 530 | 17.1s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 301 | `math_swf7` | 530 | 0.3s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 302 | `math_swf8` | 530 | 0.3s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 303 | `matrix` | 171 | 0.3s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 304 | `mcl_as_broadcaster` | 12 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 305 | `mcl_events_swf_version` | 232 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 306 | `mcl_getprogress` | 30 | 17.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 307 | `mcl_loadclip` | 149 | 17.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 308 | `mcl_loadclip_properties` | 6 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 309 | `mcl_loadclip_replace_root` | 1 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 310 | `mcl_mislabeled_target` | 6 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 311 | `mcl_target_gif87a` | 6 | 0.4s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 312 | `mcl_target_gif89a` | 6 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 313 | `mcl_target_jpg` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 314 | `mcl_target_png` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 315 | `mcl_unloadclip` | 5 | 16.8s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 316 | `mouse_events` | 8 | 18.0s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 317 | `mouse_events_visible_enabled` | 12 | 18.2s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 318 | `mouse_hover_events_while_dragging` | 1 | 17.8s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 319 | `mouse_listeners` | 67 | 17.8s |  |
| 320 | `mouse_pos` | 665 | 17.9s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 321 | `mouse_pos_with_scale_factor` | 260 | 17.8s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 322 | `mouse_wheel_enabled` | 2 | 0.3s |  |
| 323 | `movieclip_begin_gradient_fill` | 0 | 17.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 324 | `movieclip_blend_mode_property` | 35 | 17.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 325 | `movieclip_create_text_field` | 90 | 18.0s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 326 | `movieclip_default_state` | 69 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 327 | `movieclip_depth_methods` | 98 | 17.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 328 | `movieclip_focusenabled` | 99 | 0.3s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 329 | `movieclip_getbounds` | 191 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 330 | `movieclip_gettextsnapshot` | 112 | 0.3s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 331 | `movieclip_hittest` | 92 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 332 | `movieclip_in_removed_button` | 4 | 17.6s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 333 | `movieclip_init_object` | 5 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 334 | `movieclip_invalid_get_bounds_1` | 75 | 0.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 335 | `movieclip_invalid_get_bounds_2` | 75 | 17.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 336 | `movieclip_invalid_get_bounds_3` | 13 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 337 | `movieclip_invalid_get_bounds_4` | 13 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 338 | `movieclip_invalid_get_bounds_5` | 11 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 339 | `movieclip_invalid_get_bounds_6` | 10 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 340 | `movieclip_invalid_get_bounds_7` | 10 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 341 | `movieclip_invalid_get_bounds_8` | 11 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 342 | `movieclip_line_gradient_style` | 0 | 17.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 343 | `movieclip_lockroot` | 29 | 0.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 344 | `movieclip_methods_with_loaded_image` | 4 | 17.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 345 | `movieclip_name_from_timeline` | 13 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 346 | `movieclip_onconstruct` | 20 | 0.3s |  |
| 347 | `movieclip_prototype_extension` | 5 | 0.3s |  |
| 348 | `movieclip_setmask` | 14 | 16.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 349 | `movieclip_state_values` | 114 | 0.4s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 350 | `moviecliploader_flashvars` | 4 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 351 | `mutable_this` | 18 | 0.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 352 | `named_shapes` | 14 | 16.8s |  |
| 353 | `nan_scale` | 9 | 0.3s |  |
| 354 | `native_double_construct` | 12 | 17.1s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 355 | `native_objects_swf7` | 115 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 356 | `native_objects_swf8` | 115 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 357 | `native_subclasses` | 191 | 17.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 358 | `nested_textfields_in_buttons` | 0 | 0.3s |  |
| 359 | `netconnection_close` | 39 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 360 | `netstream_play_flv` | 21 | 0.3s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 361 | `netstream_play_flv_screen` | 0 | 17.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 362 | `netstream_seek_flv` | 25 | 17.3s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 363 | `new_method_wrap` | 4 | 17.0s |  |
| 364 | `new_object_enumerate` | 7 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 365 | `new_object_wrap` | 4 | 0.3s |  |
| 366 | `o` | 3 | 0.3s |  |
| 367 | `object_constructor` | 33 | 0.3s |  |
| 368 | `object_function` | 32 | 0.3s |  |
| 369 | `object_properties` | 31 | 0.3s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 370 | `object_prototypes` | 74 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 371 | `object_resolve` | 38 | 0.3s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 372 | `object_string_coerce_swf5` | 62 | 0.3s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 373 | `object_string_coerce_swf6` | 68 | 0.3s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 374 | `on_construct` | 25 | 14.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 375 | `parse_float` | 74 | 14.4s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 376 | `parse_int` | 64 | 14.0s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 377 | `path_string` | 322 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 378 | `place_and_lookup` | 30 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 379 | `placeobject_occupied_depth` | 6 | 13.8s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 380 | `point` | 175 | 0.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 381 | `primitive_instanceof` | 37 | 0.2s |  |
| 382 | `primitive_type_globals` | 557 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 383 | `printjob_props_swf5` | 45 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 384 | `printjob_props_swf6` | 45 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 385 | `printjob_props_swf7` | 45 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 386 | `property_invalid_base_clip` | 36 | 0.2s |  |
| 387 | `prototype_delete` | 12 | 0.2s |  |
| 388 | `prototype_enumerate` | 5 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 389 | `prototype_properties` | 17 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 390 | `rectangle` | 745 | 0.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 391 | `recursive_prototypes` | 0 | 0.2s |  |
| 392 | `register_and_init_order` | 231 | 13.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 393 | `register_class` | 66 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 394 | `register_class_return_value` | 16 | 13.7s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 395 | `register_class_swf6` | 37 | 20.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 396 | `register_class_with_sound` | 11 | 17.8s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 397 | `register_globals_across_frames` | 15 | 17.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 398 | `register_underflow` | 26 | 0.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 399 | `remove_movie_clip` | 29 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 400 | `removed_clip_halts_script` | 15 | 17.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 401 | `removed_target_clip_scope` | 35 | 0.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 402 | `resolve_different_root` | 2 | 0.3s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 403 | `rewind_depth` | 30 | 17.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 404 | `root_button_mode` | 10 | 17.6s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 405 | `root_global_parent` | 6 | 17.5s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 406 | `root_onload` | 1 | 0.3s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 407 | `sandbox_type_local_file` | 1 | 17.4s |  |
| 408 | `sandbox_type_local_network` | 1 | 0.3s |  |
| 409 | `selection_handlers` | 27 | 0.3s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 410 | `set_interval` | 27 | 0.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 411 | `set_variable_scope` | 58 | 0.3s |  |
| 412 | `single_frame` | 1 | 0.3s |  |
| 413 | `slash_syntax` | 14 | 17.6s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 414 | `sound` | 628 | 0.3s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 415 | `sound_duration_position_props` | 290 | 17.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 416 | `sound_id3` | 633 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 417 | `sound_id3_prop` | 138 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 418 | `sound_load_start` | 3 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 419 | `sound_multiple_load` | 1 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 420 | `sound_props_swf5` | 68 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 421 | `sound_props_swf6` | 68 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 422 | `sound_start_load` | 0 | 0.2s |  |
| 423 | `stage_display_state` | 16 | 0.3s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 424 | `stage_object_children` | 83 | 17.8s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 425 | `stage_object_enumerate` | 4 | 0.3s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 426 | `stage_object_properties` | 241 | 17.5s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 427 | `stage_object_properties_get_var` | 5 | 0.3s |  |
| 428 | `stage_object_properties_swf6` | 231 | 17.4s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 429 | `stage_property_representation` | 586 | 0.3s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 430 | `stage_scale_mode` | 39 | 17.6s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 431 | `strictequals_swf6` | 902 | 0.3s |  |
| 432 | `strictly_equals` | 7 | 0.3s |  |
| 433 | `string_coercion` | 117 | 0.3s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 434 | `string_methods` | 285 | 16.8s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 435 | `string_methods_negative_args` | 240 | 17.1s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 436 | `string_methods_swfv5` | 275 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 437 | `string_ops_swf6` | 95 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 438 | `string_paths_basic` | 4 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 439 | `string_paths_eval` | 4 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 440 | `string_paths_eval2` | 7 | 16.7s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 441 | `string_paths_hidden` | 54 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 442 | `string_paths_keyevents` | 0 | 0.3s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 443 | `string_paths_other` | 36 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 444 | `string_paths_timer` | 0 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 445 | `string_paths_unload` | 1 | 0.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 446 | `string_paths_variable_alias` | 4 | 0.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 447 | `string_paths_variable_scopes` | 5 | 0.3s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 448 | `stylesheet` | 283 | 16.9s |  |
| 449 | `stylesheet_transform` | 750 | 0.3s |  |
| 450 | `super_edge_cases` | 39 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 451 | `swf4_actions_bool` | 96 | 0.3s |  |
| 452 | `swf4_actions_coercion_order` | 158 | 17.7s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 453 | `swf4_bool` | 4 | 17.0s |  |
| 454 | `swf4_function_calls` | 7 | 0.3s |  |
| 455 | `swf5_encoding` | 3 | 0.3s |  |
| 456 | `swf5_global_funcs` | 232 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 457 | `swf5_no_closure` | 19 | 0.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 458 | `swf5_to_6_cross_call` | 29 | 0.3s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 459 | `swf5_xml_event_handler_context` | 2 | 17.1s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 460 | `swf6_case_insensitive` | 42 | 0.3s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 461 | `swf6_global_funcs` | 232 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 462 | `swf6_string_as_bool` | 15 | 0.3s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 463 | `swf6_to_5_cross_call` | 29 | 0.3s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 464 | `swf7_case_sensitive` | 44 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 465 | `swf7_global_funcs` | 232 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 466 | `tab_ordering_automatic_basic` | 92 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 467 | `tab_ordering_automatic_order_grid` | 21 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 468 | `tab_ordering_automatic_order_same_position` | 12 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 469 | `tab_ordering_children` | 208 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 470 | `tab_ordering_custom_basic` | 71 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 471 | `tab_ordering_custom_duplicate_index` | 22 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 472 | `tab_ordering_custom_i32_vs_u32` | 12 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 473 | `tab_ordering_custom_m1` | 29 | 18.4s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 474 | `tab_ordering_events` | 150 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 475 | `tab_ordering_events_mouse` | 65 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 476 | `tab_ordering_movieclip_enabled_default` | 462 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 477 | `tab_ordering_properties` | 293 | 0.3s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 478 | `tab_ordering_reverse` | 51 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 479 | `tab_ordering_tabbable` | 47 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 480 | `target_clip_removed` | 5 | 17.9s | [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 481 | `target_clip_swf5` | 2 | 0.3s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 482 | `target_clip_swf6` | 2 | 0.3s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 483 | `target_path` | 14 | 0.3s |  |
| 484 | `tell_target` | 37 | 0.3s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 485 | `tell_target_invalid` | 6 | 17.7s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 486 | `tell_target_invalid_swf6` | 5 | 0.3s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 487 | `text_blocks_clicks` | 4 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 488 | `text_format` | 1146 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 489 | `text_format_display` | 21 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 490 | `text_format_font_max_length` | 2 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 491 | `text_format_get_text_extent_undefined_width` | 10 | 0.3s |  |
| 492 | `text_format_rounding_swf7` | 840 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 493 | `text_format_rounding_swf8` | 840 | 17.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 494 | `textfield_background_color` | 11 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 495 | `textfield_border_color` | 11 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 496 | `textfield_cache_as_bitmap` | 1 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 497 | `textfield_maxchars` | 3 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 498 | `textfield_props_swf6` | 210 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 499 | `textfield_props_swf7` | 210 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 500 | `textfield_props_swf8` | 210 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 501 | `textfield_text` | 7 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 502 | `textfield_variable` | 81 | 16.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 503 | `textsnapshot_available_text` | 20 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 504 | `textsnapshot_findtext` | 44 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 505 | `textsnapshot_gettext` | 55 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 506 | `textsnapshot_props_swf5` | 56 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 507 | `textsnapshot_props_swf6` | 56 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 508 | `textsnapshot_text_order` | 1 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 509 | `this_scoping` | 52 | 16.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 510 | `this_swf5` | 41 | 0.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 511 | `this_swf6` | 41 | 0.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 512 | `this_swf7` | 41 | 17.2s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 513 | `timeline_function_def` | 7 | 17.1s |  |
| 514 | `timeout` | 0 | 5.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 515 | `timer_run_actions` | 18 | 0.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 516 | `trace` | 8 | 0.3s |  |
| 517 | `transform` | 70 | 0.3s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 518 | `try_catch_finally` | 118 | 0.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 519 | `try_finally_simple` | 16 | 0.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 520 | `typeof` | 22 | 0.3s |  |
| 521 | `typeof_globals` | 7 | 0.3s |  |
| 522 | `uncaught_exception` | 1 | 0.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 523 | `uncaught_exception_bubbled` | 1 | 0.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 524 | `undefined_to_string_swf6` | 4 | 0.3s |  |
| 525 | `unescape` | 43 | 0.3s |  |
| 526 | `unload` | 52 | 17.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 527 | `unload_clip_event` | 4 | 16.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 528 | `unload_nested_child` | 5 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 529 | `unloadmovie` | 4 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 530 | `unloadmovie_method` | 3 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 531 | `unloadmovienum` | 13 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 532 | `use_hand_cursor` | 8 | 0.3s |  |
| 533 | `variable_args` | 5 | 17.8s |  |
| 534 | `waitforframe` | 7 | 17.7s |  |
| 535 | `waitforframe2` | 16 | 0.3s |  |
| 536 | `watch` | 117 | 0.3s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 537 | `watch_textfield` | 12 | 17.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 538 | `watch_virtual_property_proto` | 2 | 17.8s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 539 | `with` | 49 | 0.3s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 540 | `with_return` | 2 | 0.3s |  |
| 541 | `with_variable_scopes` | 43 | 0.3s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 542 | `xml` | 15 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 543 | `xml_append_child` | 28 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 544 | `xml_append_child_with_parent` | 20 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 545 | `xml_attributes_read` | 4 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 546 | `xml_cdata` | 11 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 547 | `xml_child_nodes_edge_cases` | 4 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 548 | `xml_clone_expandos` | 19 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 549 | `xml_first_last_child` | 8 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 550 | `xml_has_child_nodes` | 3 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 551 | `xml_idmap` | 21 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 552 | `xml_ignore_comments` | 21 | 17.5s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 553 | `xml_ignore_white` | 34 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 554 | `xml_insert_before` | 20 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 555 | `xml_inspect_createmethods` | 15 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 556 | `xml_inspect_doctype` | 7 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 557 | `xml_inspect_parsexml` | 62 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 558 | `xml_inspect_xmldecl` | 7 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 559 | `xml_load` | 2 | 16.9s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 560 | `xml_namespaces` | 203 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 561 | `xml_parent_and_child` | 5 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 562 | `xml_remove_node` | 22 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 563 | `xml_reparenting` | 14 | 16.8s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 564 | `xml_siblings` | 10 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 565 | `xml_to_string` | 13 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 566 | `xml_to_string_comment` | 1 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 567 | `xml_unescaping` | 23 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 568 | `xmlnode_proto` | 1 | 0.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Ruffle-Matched Tests

**9 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `bitmap_data_thorough/copyPixels` | 68 | 68 | 18.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 2 | `bitmap_data_thorough/paletteMap` | 68 | 68 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `bitmap_data_thorough/perlinNoise` | 40 | 445 | 0.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `form_loader_encoding_4` | 2 | 2 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 5 | `mcl_replace_root_swf7_to_swf5` | 1 | 1 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 6 | `mcl_replace_root_swf7_to_swf6` | 1 | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 7 | `movieclip_library_state_values` | 2 | 9 | 16.9s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 8 | `tab_ordering_properties_tab_index_edge_case` | 3 | 3 | 0.3s |  |
| 9 | `textfield_props_swf5` | 2 | 103 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**33 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_stylesheet` | 99.7% | 324 | 325 | 1 | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 2 | `selection` | 99.6% | 452 | 454 | 2 | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 3 | `date` | 99.3% | 6289 | 6335 | 46 | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 4 | `native_objects_swf6` | 99.1% | 114 | 115 | 1 | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 5 | `bitmap_data_thorough/pixelDissolve` | 97.4% | 1335 | 1371 | 36 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 6 | `movieclip_hittest_shapeflag` | 97.3% | 329 | 338 | 9 | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 7 | `globals_swf5` | 96.7% | 294 | 304 | 10 | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_get_instance_at_depth` | 96.4% | 27 | 28 | 1 | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `textfield_properties` | 84.1% | 37 | 44 | 7 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 10 | `load_vars` | 82.9% | 29 | 35 | 6 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 11 | `edittext_html_roundtrip` | 76.5% | 13 | 17 | 4 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 12 | `string_relational_compare` | 75.0% | 3 | 4 | 1 | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) |
| 13 | `localconnection` | 74.8% | 433 | 579 | 146 | [56](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 14 | `edittext_autosize` | 74.6% | 53 | 71 | 18 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 15 | `clone_sprite_edittext` | 74.5% | 70 | 94 | 24 | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 16 | `edittext_tab_focus` | 69.2% | 9 | 13 | 4 | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 17 | `assetnative` | 66.7% | 54 | 81 | 27 |  |
| 18 | `assetnativeaccessor` | 66.7% | 54 | 81 | 27 |  |
| 19 | `edittext_drag_select` | 66.7% | 6 | 9 | 3 | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 20 | `edittext_newlines` | 63.3% | 19 | 30 | 11 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 21 | `clone_sprite_edittext_dynamic` | 62.8% | 54 | 86 | 32 | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 22 | `edittext_align` | 60.0% | 36 | 60 | 24 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_bullet` | 60.0% | 18 | 30 | 12 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_letter_spacing` | 60.0% | 9 | 15 | 6 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_margins` | 60.0% | 15 | 25 | 10 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_tab_stops` | 60.0% | 36 | 60 | 24 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_underline` | 60.0% | 24 | 40 | 16 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_default_format_font_style` | 57.1% | 192 | 336 | 144 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_align_trailing_spaces_swf8` | 54.7% | 315 | 576 | 261 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_default_format` | 51.4% | 114 | 222 | 108 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_programmatic_focus` | 50.0% | 6 | 12 | 6 | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_text_height_leading` | 50.0% | 10 | 20 | 10 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 33 | `string_paths_reference_launder` | 50.0% | 1 | 2 | 1 | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**70 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_stylesheet` | 99.7% | 324/325 | 325 | 325 | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 2 | `selection` | 99.6% | 452/454 | 454 | 454 | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 3 | `date` | 99.3% | 6289/6335 | 6335 | 6335 | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 4 | `native_objects_swf6` | 99.1% | 114/115 | 115 | 115 | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 5 | `bitmap_data_thorough/pixelDissolve` | 97.4% | 1335/1371 | 1371 | 1371 | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 6 | `movieclip_hittest_shapeflag` | 97.3% | 329/338 | 338 | 338 | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 7 | `globals_swf5` | 96.7% | 294/304 | 304 | 304 | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 8 | `movieclip_get_instance_at_depth` | 96.4% | 27/28 | 28 | 28 | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 9 | `textfield_properties` | 84.1% | 37/44 | 44 | 44 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 10 | `load_vars` | 82.9% | 29/35 | 30 | 35 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 11 | `edittext_html_roundtrip` | 76.5% | 13/17 | 17 | 17 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 12 | `string_relational_compare` | 75.0% | 3/4 | 4 | 4 | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) |
| 13 | `localconnection` | 74.8% | 433/579 | 555 | 579 | [56](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 14 | `edittext_autosize` | 74.6% | 53/71 | 71 | 71 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 15 | `clone_sprite_edittext` | 74.5% | 70/94 | 94 | 94 | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 16 | `edittext_tab_focus` | 69.2% | 9/13 | 13 | 13 | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 17 | `assetnative` | 66.7% | 54/81 | 81 | 81 |  |
| 18 | `assetnativeaccessor` | 66.7% | 54/81 | 81 | 81 |  |
| 19 | `edittext_drag_select` | 66.7% | 6/9 | 9 | 9 | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 20 | `edittext_newlines` | 63.3% | 19/30 | 30 | 30 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 21 | `clone_sprite_edittext_dynamic` | 62.8% | 54/86 | 86 | 86 | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 22 | `edittext_align` | 60.0% | 36/60 | 60 | 60 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_bullet` | 60.0% | 18/30 | 30 | 30 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_letter_spacing` | 60.0% | 9/15 | 15 | 15 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_margins` | 60.0% | 15/25 | 25 | 25 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_tab_stops` | 60.0% | 36/60 | 60 | 60 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_underline` | 60.0% | 24/40 | 40 | 40 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_default_format_font_style` | 57.1% | 192/336 | 336 | 335 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_align_trailing_spaces_swf8` | 54.7% | 315/576 | 576 | 576 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_default_format` | 51.4% | 114/222 | 222 | 221 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_programmatic_focus` | 50.0% | 6/12 | 12 | 12 | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_text_height_leading` | 50.0% | 10/20 | 20 | 20 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 33 | `string_paths_reference_launder` | 50.0% | 1/2 | 2 | 2 | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 34 | `edittext_align_trailing_spaces_swf7` | 48.4% | 279/576 | 576 | 576 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 35 | `file_reference_browse_cancel` | 47.6% | 10/21 | 10 | 21 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 36 | `xml_getbytes` | 47.1% | 8/17 | 16 | 17 | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 37 | `assetnative_ids` | 40.0% | 4/10 | 8 | 10 |  |
| 38 | `edittext_font_size` | 33.3% | 15/45 | 45 | 45 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_leading` | 33.3% | 3/9 | 9 | 9 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 41 | `form_loader_encoding_3` | 33.3% | 1/3 | 3 | 3 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 42 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 43 | `edittext_ime_focus_lost` | 28.6% | 2/7 | 6 | 7 | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_html_align_swf7` | 23.1% | 12/52 | 52 | 52 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_html_align_swf8` | 23.1% | 12/52 | 52 | 52 | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 46 | `global_proto_decls` | 20.6% | 926/4497 | 3774 | 4497 | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 47 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 48 | `edittext_tag_indent` | 16.1% | 5/31 | 31 | 31 | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 49 | `watch_virtual_property` | 15.0% | 9/60 | 52 | 60 | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 50 | `assetnativeaccessor_ids` | 14.3% | 3/21 | 19 | 21 |  |
| 51 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 52 | `xml_socket` | 12.5% | 1/8 | 1 | 8 | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 53 | `global_proto_decls_delete` | 9.3% | 386/4158 | 2370 | 4158 | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 54 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 55 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 56 | `edittext_default_format_empty` | 5.0% | 5/100 | 100 | 100 | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 57 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 58 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 59 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 60 | `netconnection_send_remote` | 4.0% | 2/50 | 2 | 50 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 61 | `global_instance_decls` | 2.9% | 23/796 | 796 | 758 | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 62 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 63 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 64 | `form_loader_encoding_2` | 0.0% | 0/3 | 3 | 3 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 65 | `geturl` | 0.0% | 0/7 | 0 | 7 | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 66 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 67 | `removed_base_clip_tell_target` | 0.0% | 0/2 | 2 | 2 | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 68 | `xml_socket_close_in_handler` | 0.0% | 0/6 | 0 | 6 | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 69 | `xml_socket_on_data` | 0.0% | 0/7 | 0 | 7 | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 70 | `xml_socket_segmented` | 0.0% | 0/29 | 0 | 29 | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 17 | 17 | 0 |
| 6 | [BITMAP_DATA_THOROUGH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) | 20 | 16 | 4 |
| 7 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 1 | 1 | 0 |
| 8 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 1 | 1 | 0 |
| 9 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 1 | 1 | 0 |
| 10 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 13 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 14 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 15 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 16 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 6 | 2 |
| 17 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 18 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 19 | [CONSTRUCT_PARAMETER_REPLAY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) | 2 | 2 | 0 |
| 20 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 21 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 3 | 2 |
| 22 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 23 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 24 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 25 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 26 | [DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) | 1 | 1 | 0 |
| 27 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 0 | 2 |
| 28 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 29 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 30 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 31 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 0 | 1 |
| 32 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 33 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 34 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 35 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 36 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 3 | 1 | 2 |
| 37 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 3 | 3 | 0 |
| 38 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 39 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 40 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 41 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 42 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 43 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 6 | 1 |
| 44 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 45 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 31 | 26 | 5 |
| 46 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 47 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 9 | 14 |
| 48 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 49 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 50 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 51 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 52 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 53 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 44 | 4 |
| 54 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 4 | 1 |
| 55 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 56 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 1 | 0 | 1 |
| 57 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 58 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 59 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 60 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 61 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 58 | 52 | 6 |
| 62 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 63 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 64 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 3 | 2 | 1 |
| 65 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 2 | 1 | 1 |
| 66 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 67 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 3 | 1 |
| 68 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 69 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 70 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 1 | 2 |
| 71 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 72 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 73 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 74 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 75 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 76 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 77 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 78 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 79 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 1 | 3 |
| 80 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 81 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 82 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) | 2 | 2 | 0 |
| 83 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 2 | 2 | 0 |
| 84 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 85 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 86 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 87 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 13 | 12 | 1 |
| 88 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 0 | 1 |
| 89 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 2 | 2 | 0 |
| 90 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 91 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 15 | 1 |
| 92 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 93 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 19 | 17 | 2 |
| 94 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 41 | 29 |
| 95 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 96 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 97 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 98 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 3 | 0 |
| 99 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 100 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 101 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 13 | 3 |
| 102 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 103 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 1 | 0 | 1 |
| 104 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 105 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 28 | 5 |
| | *(tests not in any document)* | 151 | 146 | 5 |
