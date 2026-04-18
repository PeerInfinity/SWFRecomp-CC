# Ruffle Test Results (Filtered)

**Date**: 2026-04-18 19:32 UTC

**Git SHA**: `14e85d4451`

**Run Duration**: 48m 57s

**Filtered**: 41 tests ignored out of 641 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 600 |
| Passing | **597** (99.5%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **600** (100.0%) |
| Failing | 0 |
| Total expected lines | 95093 |
| Matching lines | 94917 (99.8%) |
| Mismatched lines | 176 |

## Passing Tests

**597 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 16.3s |  |
| 2 | `action_to_integer` | 28 | 0.2s |  |
| 3 | `add` | 28 | 15.6s |  |
| 4 | `add2` | 354 | 0.3s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 0.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.2s |  |
| 7 | `add_swf5` | 28 | 0.2s |  |
| 8 | `arguments` | 127 | 0.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 0.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 0.2s |  |
| 11 | `array_constructor` | 30 | 0.2s |  |
| 12 | `array_enumerate` | 4 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 0.2s |  |
| 14 | `array_properties` | 36 | 0.2s |  |
| 15 | `array_prototyping` | 12 | 0.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 0.2s |  |
| 17 | `array_sort` | 161 | 0.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 15.6s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 0.2s |  |
| 20 | `array_trivial` | 209 | 0.2s |  |
| 21 | `as1_constructor_v6` | 35 | 0.2s |  |
| 22 | `as1_constructor_v7` | 35 | 0.2s |  |
| 23 | `as2_oop` | 13 | 16.6s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 16.1s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 0.2s |  |
| 29 | `as_broadcaster_undef` | 89 | 0.2s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 0.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 0.4s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 0.4s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 0.3s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 0.3s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 0.3s |  |
| 37 | `as_transformed_flag` | 20 | 15.9s |  |
| 38 | `asfunction` | 11 | 0.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 39 | `asnative` | 34 | 0.2s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `asnew` | 34 | 16.0s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 41 | `attach_movie` | 59 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 42 | `attach_movie_stop` | 3 | 15.8s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 43 | `bad_placeobject_clipaction` | 2 | 0.2s |  |
| 44 | `bad_swf_tag_past_eof` | 0 | 0.2s |  |
| 45 | `bitand` | 1058 | 12.4s |  |
| 46 | `bitmap_data` | 1126 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_colortransform` | 0 | 12.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 48 | `bitmap_data_compare` | 40 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_copypixels` | 17 | 12.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 50 | `bitmap_data_draw_cliprect` | 13 | 12.2s |  |
| 51 | `bitmap_data_fillrect` | 0 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 52 | `bitmap_data_hittest` | 132 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 53 | `bitmap_data_max_size_swf10` | 12 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_max_size_swf9` | 10 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_noise` | 631 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_perlinnoise` | 0 | 12.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 57 | `bitmap_data_pixeldissolve` | 1075 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 58 | `bitmap_data_pixeldissolve_image` | 0 | 12.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 59 | `bitmap_data_thorough/colorTransform` | 279 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 60 | `bitmap_data_thorough/compare` | 69 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 61 | `bitmap_data_thorough/constructor` | 313 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 62 | `bitmap_data_thorough/copyChannel` | 2715 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 63 | `bitmap_data_thorough/fillRect` | 342 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 64 | `bitmap_data_thorough/floodFill` | 867 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 65 | `bitmap_data_thorough/getColorBoundsRect` | 285 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 66 | `bitmap_data_thorough/getPixel` | 141 | 15.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 67 | `bitmap_data_thorough/getPixel32` | 141 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 68 | `bitmap_data_thorough/hitTest` | 519 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 69 | `bitmap_data_thorough/merge` | 1203 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 70 | `bitmap_data_thorough/noise` | 1518 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 71 | `bitmap_data_thorough/scroll` | 384 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 72 | `bitmap_data_thorough/setPixel` | 531 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 73 | `bitmap_data_thorough/setPixel32` | 531 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 74 | `bitmap_data_thorough/threshold` | 1308 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 75 | `bitmap_data_threshold` | 176 | 15.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 76 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.9s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [13](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 77 | `bitmapdata_channels` | 19 | 0.2s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 78 | `bitor` | 1058 | 0.2s |  |
| 79 | `biturshift` | 14 | 0.2s |  |
| 80 | `biturshift_swf8` | 14 | 0.2s |  |
| 81 | `bitxor` | 1058 | 0.2s |  |
| 82 | `boxed_primitives` | 24 | 15.8s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 83 | `button_children` | 8 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 84 | `button_goto` | 4 | 15.6s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 85 | `button_key_events` | 14 | 15.6s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 86 | `button_key_events_special` | 45 | 0.4s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 87 | `button_keypress` | 3 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 88 | `button_keypress_vs_press` | 25 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 89 | `button_keypress_vs_tab` | 20 | 0.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 90 | `button_keypress_vs_textinput` | 4 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 91 | `button_order` | 2 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 92 | `button_properties_special_cases` | 22 | 15.7s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 93 | `button_v5` | 18 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 94 | `button_v6` | 18 | 0.2s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 95 | `call` | 63 | 15.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 96 | `call_method_empty_name` | 1 | 0.2s |  |
| 97 | `capabilities_resolution` | 8 | 15.9s |  |
| 98 | `catch_references_registers` | 2 | 0.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 99 | `click_block` | 5 | 15.5s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 100 | `clip_constructors` | 8 | 15.6s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 101 | `clip_event_propagation_order` | 17 | 15.6s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 102 | `clip_events` | 19 | 15.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 103 | `clone_sprite_edittext` | 94 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 104 | `clone_sprite_edittext_dynamic` | 86 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 105 | `clone_sprite_types` | 24 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 106 | `closure_scope` | 7 | 15.6s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 107 | `coerce_to_object_monkeypatch` | 129 | 15.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 108 | `coerce_to_primitive_resolve` | 17 | 15.5s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 109 | `color` | 57 | 15.4s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 110 | `color_transform` | 48 | 15.4s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 111 | `conflicting_instance_names` | 23 | 15.2s |  |
| 112 | `constructor_function` | 2 | 0.2s |  |
| 113 | `context_menu` | 39 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 114 | `context_menu_item` | 41 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 115 | `create_empty_movie_clip` | 3 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 116 | `cross_movie_root` | 10 | 15.1s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 117 | `custom_clip_methods` | 4 | 0.2s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 118 | `default_names` | 52 | 0.2s | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 119 | `define_function2` | 8 | 0.2s |  |
| 120 | `define_function2_preload` | 13 | 0.2s |  |
| 121 | `define_function2_preload_order` | 4 | 0.2s |  |
| 122 | `define_function_case_sensitive` | 2 | 15.6s |  |
| 123 | `define_local` | 27 | 0.2s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 124 | `define_local_with_paths` | 54 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 125 | `delete` | 3 | 0.2s |  |
| 126 | `depth_replacement_audio_unloading` | 3 | 15.8s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) |
| 127 | `device_font_spacing` | 91 | 15.8s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 128 | `displacementmapfilter_mappoint_throw_error` | 13 | 15.4s | [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 129 | `display_object_properties` | 2 | 15.5s | [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 130 | `divide_swf4` | 107 | 0.2s |  |
| 131 | `do_init_action` | 3 | 15.3s |  |
| 132 | `do_init_action_child` | 12 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 133 | `drag_drop` | 10 | 0.2s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 134 | `drag_over_from_outside` | 1 | 15.5s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 135 | `drag_over_without_startdrag` | 1 | 0.2s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 136 | `duplicate_movie_clip` | 20 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 137 | `duplicate_movie_clip_drawing` | 2 | 0.2s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 138 | `edittext_align` | 60 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 139 | `edittext_align_trailing_spaces_swf7` | 576 | 15.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 140 | `edittext_align_trailing_spaces_swf8` | 576 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 141 | `edittext_antialiastype` | 296 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_autosize` | 71 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_autosize_setter` | 20 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 144 | `edittext_bullet` | 30 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 145 | `edittext_default_format` | 221 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 146 | `edittext_default_format_empty` | 100 | 0.2s | [36](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 147 | `edittext_default_format_font_style` | 335 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 148 | `edittext_drag_select` | 9 | 15.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 149 | `edittext_focus_selection` | 2 | 17.4s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 150 | `edittext_font_size` | 45 | 16.8s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 151 | `edittext_hscroll` | 27 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 152 | `edittext_html_align_swf7` | 52 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 153 | `edittext_html_align_swf8` | 52 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 154 | `edittext_html_color` | 114 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 155 | `edittext_html_condensewhite_swf7` | 311 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 156 | `edittext_html_condensewhite_swf8` | 311 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 157 | `edittext_html_entity` | 4 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 158 | `edittext_html_roundtrip` | 17 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_html_swf6` | 5377 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_html_swf7` | 5377 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_html_swf8` | 5377 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_ime_focus_lost` | 7 | 16.6s | [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `edittext_input` | 1 | 16.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 164 | `edittext_input_newlines` | 9 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 165 | `edittext_leading` | 9 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 166 | `edittext_letter_spacing` | 15 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 167 | `edittext_margins` | 25 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 168 | `edittext_newline_stripping` | 64 | 6.6s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 169 | `edittext_newlines` | 30 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 170 | `edittext_password` | 5 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 171 | `edittext_password_copy` | 4 | 15.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 172 | `edittext_paste_empty` | 2 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 173 | `edittext_place_caret` | 2 | 15.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 174 | `edittext_programmatic_focus` | 12 | 0.2s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 175 | `edittext_restrict` | 191 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 176 | `edittext_restrict_paste` | 5 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 177 | `edittext_scroll` | 54 | 15.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 178 | `edittext_stylesheet` | 325 | 15.4s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 179 | `edittext_tab_focus` | 13 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 180 | `edittext_tab_stops` | 60 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 181 | `edittext_tag_indent` | 31 | 15.4s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 182 | `edittext_text_height_leading` | 20 | 15.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 183 | `edittext_underline` | 40 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 184 | `edittext_width_height` | 103 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 185 | `empty_movieclip_can_attach_movies` | 11 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 186 | `enumerate` | 64 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 187 | `equals` | 32 | 0.2s |  |
| 188 | `equals2_swf5` | 926 | 0.2s |  |
| 189 | `equals2_swf6` | 926 | 0.2s |  |
| 190 | `equals2_swf7` | 926 | 0.2s |  |
| 191 | `equals_swf4` | 665 | 0.2s |  |
| 192 | `equals_swf4_alt` | 32 | 0.2s |  |
| 193 | `equals_swf5` | 32 | 16.6s |  |
| 194 | `error` | 58 | 15.7s |  |
| 195 | `escape` | 14 | 0.2s |  |
| 196 | `execution_order1` | 5 | 15.6s |  |
| 197 | `execution_order2` | 7 | 15.6s |  |
| 198 | `execution_order3` | 4 | 0.2s |  |
| 199 | `execution_order4` | 12 | 0.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 200 | `export_assets` | 3 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 201 | `extends_chain` | 134 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 202 | `extends_native_type` | 11 | 0.2s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 203 | `external_interface` | 84 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 204 | `external_interface_escapexml` | 26 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 205 | `external_interface_jsquotestring` | 21 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 206 | `external_interface_toas_basic` | 354 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 207 | `external_interface_toxml_array` | 25 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 208 | `external_interface_toxml_basic` | 179 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 209 | `external_interface_unescapexml` | 40 | 0.2s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 210 | `focus_keyboard_press` | 60 | 0.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 211 | `focus_mouse` | 45 | 0.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 212 | `focus_mouse_focusable` | 8 | 15.5s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 213 | `focus_mouse_rollout` | 4 | 0.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 214 | `focus_remove` | 33 | 15.5s |  |
| 215 | `focus_root_movie` | 2 | 0.2s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 216 | `focus_visibility_change` | 45 | 0.2s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 217 | `focusrect_focuslost` | 4 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 218 | `focusrect_mouse_swf8` | 0 | 0.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 219 | `focusrect_mouse_swf9` | 0 | 0.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 220 | `focusrect_property_swf5` | 1237 | 0.3s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 221 | `focusrect_property_swf6` | 1237 | 0.3s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 222 | `focusrect_property_swf7` | 1237 | 15.5s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 223 | `focusrect_swf5` | 6 | 15.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 224 | `focusrect_swf6` | 42 | 0.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 225 | `form_loader_encoding_1` | 1 | 0.2s |  |
| 226 | `frame_size_translated_negative` | 21 | 15.9s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 227 | `frame_size_translated_positive` | 21 | 16.2s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 228 | `function_as_function` | 35 | 15.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 229 | `function_base_clip` | 8 | 15.4s |  |
| 230 | `function_base_clip_readded` | 11 | 15.6s |  |
| 231 | `function_base_clip_removed` | 25 | 15.5s |  |
| 232 | `function_suppress_and_preload` | 28 | 15.4s |  |
| 233 | `funky_function_calls` | 56 | 0.2s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 234 | `get_bytes_total` | 4 | 15.5s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 235 | `get_variable_in_scope` | 29 | 0.2s |  |
| 236 | `getproperty` | 28 | 0.2s |  |
| 237 | `getproperty_swf4` | 28 | 0.2s |  |
| 238 | `getproperty_swf5` | 28 | 0.2s |  |
| 239 | `gettextextent` | 56 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 240 | `global_array` | 3 | 0.2s |  |
| 241 | `global_is_bare` | 7 | 0.2s |  |
| 242 | `global_swf5_6_7_8_9` | 1145 | 15.5s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 243 | `global_swf6_7_8` | 15 | 16.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 244 | `globals_swf6` | 304 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 245 | `globals_swf7` | 304 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 246 | `globals_swf8` | 304 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 247 | `goto_advance1` | 6 | 16.2s |  |
| 248 | `goto_advance2` | 2 | 0.2s |  |
| 249 | `goto_both_ways1` | 3 | 0.2s |  |
| 250 | `goto_both_ways2` | 3 | 16.4s |  |
| 251 | `goto_execution_order` | 2 | 16.2s |  |
| 252 | `goto_execution_order2` | 2 | 0.2s |  |
| 253 | `goto_frame` | 12 | 0.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 254 | `goto_frame2` | 44 | 16.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 255 | `goto_frame_number` | 3 | 16.2s |  |
| 256 | `goto_label` | 17 | 16.1s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 257 | `goto_methods` | 40 | 0.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 258 | `goto_rewind1` | 1 | 0.2s |  |
| 259 | `goto_rewind2` | 3 | 0.2s |  |
| 260 | `goto_rewind3` | 2 | 0.2s |  |
| 261 | `greater_swf6` | 1175 | 0.3s |  |
| 262 | `greater_swf7` | 1175 | 0.2s |  |
| 263 | `greaterthan_swf5` | 1 | 15.6s |  |
| 264 | `greaterthan_swf8` | 1 | 0.2s |  |
| 265 | `has_own_property` | 32 | 0.2s |  |
| 266 | `hittest_lockroot` | 15 | 15.6s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 267 | `hittest_morph` | 70 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 268 | `hittest_morph_input` | 1 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 269 | `hittest_winding_rule` | 12 | 15.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 270 | `infinite_recursion_function` | 4 | 0.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 271 | `infinite_recursion_function_in_setter` | 131 | 0.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 272 | `infinite_recursion_virtual_property` | 67 | 0.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 273 | `init_array_invalid` | 4 | 15.3s |  |
| 274 | `init_object_invalid` | 4 | 0.1s |  |
| 275 | `init_object_order` | 15 | 0.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 276 | `input_dead_keys_windows` | 15 | 0.3s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 277 | `instanceof_coercions` | 88 | 0.3s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 278 | `interface_implements_op` | 47 | 0.3s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 279 | `is_finite` | 49 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 280 | `is_finite_swf6` | 49 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 281 | `is_prototype_of` | 89 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 282 | `issue_1086` | 1 | 0.2s |  |
| 283 | `issue_1104` | 2 | 15.2s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 284 | `issue_1671` | 0 | 12.9s |  |
| 285 | `issue_1906` | 4 | 0.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 286 | `issue_2030` | 4 | 13.5s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 287 | `issue_2084` | 16 | 12.9s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 288 | `issue_2166` | 9 | 0.2s |  |
| 289 | `issue_2870` | 3 | 12.7s | [52](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 290 | `issue_3169` | 2 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 291 | `issue_3446` | 1 | 0.2s |  |
| 292 | `issue_3522` | 2 | 0.2s |  |
| 293 | `issue_4377` | 2 | 0.2s |  |
| 294 | `issue_710` | 4 | 0.2s |  |
| 295 | `issue_768` | 3 | 0.2s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 296 | `issue_9327` | 2 | 12.8s |  |
| 297 | `issue_9885` | 2 | 0.2s |  |
| 298 | `key_isToggled` | 9 | 0.2s |  |
| 299 | `lessthan` | 41 | 12.9s |  |
| 300 | `lessthan2_swf5` | 1226 | 0.2s |  |
| 301 | `lessthan2_swf6` | 1226 | 0.2s |  |
| 302 | `lessthan2_swf7` | 1226 | 0.2s |  |
| 303 | `lessthan_swf4` | 902 | 0.2s |  |
| 304 | `lessthan_swf4_alt` | 41 | 0.2s |  |
| 305 | `lessthan_swf5` | 41 | 15.7s |  |
| 306 | `loadmovie` | 2 | 15.4s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 307 | `loadmovie_fail` | 2 | 15.5s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 308 | `loadmovie_flashvars` | 4 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 309 | `loadmovie_method` | 2 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 310 | `loadmovie_registerclass` | 30 | 0.3s | [22](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 311 | `loadmovie_replace_root` | 5 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 312 | `loadmovie_var_persistence` | 8 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 313 | `loadmovienum` | 3 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 314 | `loadmovienum_cross_version_prototype` | 9 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 315 | `loadvariables` | 2 | 15.5s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 316 | `loadvariables2` | 8 | 15.4s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 317 | `loadvariablesnum` | 2 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 318 | `local_to_global` | 49 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 319 | `localconnection_properties` | 8 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 320 | `lock_root` | 1 | 0.2s |  |
| 321 | `logical_ops_swf4` | 90 | 0.3s |  |
| 322 | `logical_ops_swf8` | 108 | 0.2s |  |
| 323 | `looping` | 6 | 15.7s |  |
| 324 | `mask_reapply` | 0 | 15.7s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 325 | `mask_with_drawing` | 0 | 15.6s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 326 | `math_min_max` | 101 | 15.6s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 327 | `math_swf6` | 530 | 15.8s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 328 | `math_swf7` | 530 | 0.2s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 329 | `math_swf8` | 530 | 0.2s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 330 | `matrix` | 171 | 0.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 331 | `mcl_as_broadcaster` | 12 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 332 | `mcl_events_swf_version` | 232 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 333 | `mcl_getprogress` | 30 | 15.7s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 334 | `mcl_loadclip` | 149 | 16.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 335 | `mcl_loadclip_properties` | 6 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 336 | `mcl_loadclip_replace_root` | 1 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 337 | `mcl_mislabeled_target` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 338 | `mcl_target_gif87a` | 6 | 0.4s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 339 | `mcl_target_gif89a` | 6 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 340 | `mcl_target_jpg` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 341 | `mcl_target_png` | 6 | 0.2s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 342 | `mcl_unloadclip` | 5 | 15.5s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 343 | `mouse_events` | 8 | 15.6s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 344 | `mouse_events_visible_enabled` | 12 | 15.5s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 345 | `mouse_hover_events_while_dragging` | 1 | 15.3s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 346 | `mouse_listeners` | 67 | 15.3s |  |
| 347 | `mouse_pos` | 665 | 15.2s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 348 | `mouse_pos_with_scale_factor` | 260 | 15.2s | [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 349 | `mouse_wheel_enabled` | 2 | 0.2s |  |
| 350 | `movieclip_begin_gradient_fill` | 0 | 15.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 351 | `movieclip_blend_mode_property` | 35 | 15.4s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 352 | `movieclip_create_text_field` | 90 | 15.4s | [21](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 353 | `movieclip_default_state` | 69 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 354 | `movieclip_depth_methods` | 98 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 355 | `movieclip_focusenabled` | 99 | 0.2s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 356 | `movieclip_get_instance_at_depth` | 28 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 357 | `movieclip_getbounds` | 191 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 358 | `movieclip_gettextsnapshot` | 112 | 0.2s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 359 | `movieclip_hittest` | 92 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 360 | `movieclip_in_removed_button` | 4 | 15.3s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 361 | `movieclip_init_object` | 5 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 362 | `movieclip_invalid_get_bounds_1` | 75 | 17.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 363 | `movieclip_invalid_get_bounds_2` | 75 | 0.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 364 | `movieclip_invalid_get_bounds_3` | 13 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 365 | `movieclip_invalid_get_bounds_4` | 13 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 366 | `movieclip_invalid_get_bounds_5` | 11 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 367 | `movieclip_invalid_get_bounds_6` | 10 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 368 | `movieclip_invalid_get_bounds_7` | 10 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 369 | `movieclip_invalid_get_bounds_8` | 11 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 370 | `movieclip_line_gradient_style` | 0 | 16.9s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 371 | `movieclip_lockroot` | 29 | 0.3s | [57](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 372 | `movieclip_methods_with_loaded_image` | 4 | 16.9s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 373 | `movieclip_name_from_timeline` | 13 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 374 | `movieclip_prototype_extension` | 5 | 0.2s |  |
| 375 | `movieclip_setmask` | 14 | 16.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 376 | `movieclip_state_values` | 114 | 0.4s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 377 | `moviecliploader_flashvars` | 4 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 378 | `mutable_this` | 18 | 0.2s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 379 | `named_shapes` | 14 | 16.7s |  |
| 380 | `nan_scale` | 9 | 0.2s |  |
| 381 | `native_double_construct` | 12 | 16.9s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 382 | `native_objects_swf7` | 115 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 383 | `native_objects_swf8` | 115 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 384 | `native_subclasses` | 191 | 16.0s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 385 | `nested_textfields_in_buttons` | 0 | 0.2s |  |
| 386 | `netconnection_close` | 39 | 0.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 387 | `netstream_play_flv` | 21 | 0.3s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 388 | `netstream_seek_flv` | 25 | 16.0s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 389 | `new_method_wrap` | 4 | 15.7s |  |
| 390 | `new_object_enumerate` | 7 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 391 | `new_object_wrap` | 4 | 0.2s |  |
| 392 | `o` | 3 | 0.2s |  |
| 393 | `object_constructor` | 33 | 0.2s |  |
| 394 | `object_function` | 32 | 0.2s |  |
| 395 | `object_properties` | 31 | 0.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 396 | `object_prototypes` | 74 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 397 | `object_resolve` | 38 | 0.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 398 | `object_string_coerce_swf5` | 62 | 0.2s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 399 | `object_string_coerce_swf6` | 68 | 0.2s | [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 400 | `on_construct` | 25 | 17.3s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [19](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 401 | `parse_float` | 74 | 16.1s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 402 | `parse_int` | 64 | 16.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 403 | `path_string` | 322 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 404 | `place_and_lookup` | 30 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 405 | `placeobject_occupied_depth` | 6 | 16.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 406 | `point` | 175 | 0.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 407 | `primitive_instanceof` | 37 | 0.2s |  |
| 408 | `primitive_type_globals` | 557 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 409 | `printjob_props_swf5` | 45 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 410 | `printjob_props_swf6` | 45 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 411 | `printjob_props_swf7` | 45 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 412 | `property_invalid_base_clip` | 36 | 0.2s |  |
| 413 | `prototype_delete` | 12 | 0.2s |  |
| 414 | `prototype_enumerate` | 5 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 415 | `prototype_properties` | 17 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 416 | `rectangle` | 745 | 0.2s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 417 | `recursive_prototypes` | 0 | 0.2s |  |
| 418 | `register_and_init_order` | 231 | 16.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 419 | `register_class` | 66 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 420 | `register_class_return_value` | 16 | 16.1s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 421 | `register_class_swf6` | 37 | 16.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 422 | `register_class_with_sound` | 11 | 16.6s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 423 | `register_globals_across_frames` | 15 | 16.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 424 | `register_underflow` | 26 | 0.2s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 425 | `remove_movie_clip` | 29 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 426 | `removed_clip_halts_script` | 15 | 16.4s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 427 | `removed_target_clip_scope` | 35 | 0.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 428 | `resolve_different_root` | 2 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 429 | `rewind_depth` | 30 | 16.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 430 | `root_button_mode` | 10 | 16.0s | [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 431 | `root_global_parent` | 6 | 16.4s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 432 | `root_onload` | 1 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 433 | `sandbox_type_local_file` | 1 | 16.9s |  |
| 434 | `sandbox_type_local_network` | 1 | 0.2s |  |
| 435 | `selection` | 454 | 0.2s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 436 | `selection_handlers` | 27 | 0.2s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 437 | `set_interval` | 27 | 0.2s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 438 | `set_variable_scope` | 58 | 0.2s |  |
| 439 | `single_frame` | 1 | 0.2s |  |
| 440 | `slash_syntax` | 14 | 16.9s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 441 | `sound` | 628 | 0.3s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 442 | `sound_duration_position_props` | 290 | 16.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 443 | `sound_id3` | 633 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 444 | `sound_id3_prop` | 138 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 445 | `sound_load_start` | 3 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 446 | `sound_multiple_load` | 1 | 0.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 447 | `sound_props_swf5` | 68 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 448 | `sound_props_swf6` | 68 | 0.3s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 449 | `sound_start_load` | 0 | 0.1s |  |
| 450 | `stage_display_state` | 16 | 0.3s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 451 | `stage_object_children` | 83 | 15.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 452 | `stage_object_enumerate` | 4 | 0.2s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 453 | `stage_object_properties` | 241 | 15.9s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 454 | `stage_object_properties_get_var` | 5 | 0.2s |  |
| 455 | `stage_object_properties_swf6` | 231 | 16.0s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 456 | `stage_property_representation` | 586 | 0.2s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 457 | `stage_scale_mode` | 39 | 15.7s | [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 458 | `strictequals_swf6` | 902 | 0.3s |  |
| 459 | `strictly_equals` | 7 | 0.2s |  |
| 460 | `string_coercion` | 117 | 0.3s | [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 461 | `string_methods` | 285 | 16.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 462 | `string_methods_negative_args` | 240 | 16.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 463 | `string_methods_swfv5` | 275 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 464 | `string_ops_swf6` | 95 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 465 | `string_paths_basic` | 4 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 466 | `string_paths_eval` | 4 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 467 | `string_paths_eval2` | 7 | 15.9s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 468 | `string_paths_hidden` | 54 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 469 | `string_paths_keyevents` | 0 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 470 | `string_paths_other` | 36 | 0.3s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 471 | `string_paths_timer` | 0 | 0.2s | [101](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 472 | `string_paths_unload` | 1 | 0.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 473 | `string_paths_variable_alias` | 4 | 0.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 474 | `string_paths_variable_scopes` | 5 | 0.3s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 475 | `stylesheet` | 283 | 16.3s |  |
| 476 | `stylesheet_transform` | 750 | 0.3s |  |
| 477 | `super_edge_cases` | 39 | 0.3s | [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 478 | `swf4_actions_bool` | 96 | 0.3s |  |
| 479 | `swf4_actions_coercion_order` | 158 | 16.5s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 480 | `swf4_bool` | 4 | 15.7s |  |
| 481 | `swf4_function_calls` | 7 | 0.2s |  |
| 482 | `swf5_encoding` | 3 | 0.2s |  |
| 483 | `swf5_global_funcs` | 232 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 484 | `swf5_no_closure` | 19 | 0.2s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 485 | `swf5_to_6_cross_call` | 29 | 0.3s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 486 | `swf5_xml_event_handler_context` | 2 | 15.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 487 | `swf6_case_insensitive` | 42 | 0.2s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 488 | `swf6_global_funcs` | 232 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 489 | `swf6_string_as_bool` | 15 | 0.2s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 490 | `swf6_to_5_cross_call` | 29 | 0.3s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 491 | `swf7_case_sensitive` | 44 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 492 | `swf7_global_funcs` | 232 | 0.2s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 493 | `tab_ordering_automatic_basic` | 92 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 494 | `tab_ordering_automatic_order_grid` | 21 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 495 | `tab_ordering_automatic_order_same_position` | 12 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 496 | `tab_ordering_children` | 208 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 497 | `tab_ordering_custom_basic` | 71 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 498 | `tab_ordering_custom_duplicate_index` | 22 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 499 | `tab_ordering_custom_i32_vs_u32` | 12 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 500 | `tab_ordering_custom_m1` | 29 | 15.5s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 501 | `tab_ordering_events` | 150 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 502 | `tab_ordering_events_mouse` | 65 | 0.3s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 503 | `tab_ordering_movieclip_enabled_default` | 462 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 504 | `tab_ordering_properties` | 293 | 0.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 505 | `tab_ordering_reverse` | 51 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 506 | `tab_ordering_tabbable` | 47 | 0.2s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 507 | `target_clip_removed` | 5 | 15.5s | [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 508 | `target_clip_swf5` | 2 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 509 | `target_clip_swf6` | 2 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 510 | `target_path` | 14 | 0.2s |  |
| 511 | `tell_target` | 37 | 0.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 512 | `tell_target_invalid` | 6 | 15.3s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 513 | `tell_target_invalid_swf6` | 5 | 0.3s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 514 | `text_blocks_clicks` | 4 | 0.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 515 | `text_format` | 1146 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 516 | `text_format_display` | 21 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 517 | `text_format_font_max_length` | 2 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 518 | `text_format_get_text_extent_undefined_width` | 10 | 0.2s |  |
| 519 | `text_format_rounding_swf7` | 840 | 0.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 520 | `text_format_rounding_swf8` | 840 | 16.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 521 | `textfield_background_color` | 11 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 522 | `textfield_border_color` | 11 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 523 | `textfield_cache_as_bitmap` | 1 | 0.3s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 524 | `textfield_maxchars` | 3 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 525 | `textfield_properties` | 44 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 526 | `textfield_props_swf5` | 175 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 527 | `textfield_props_swf6` | 210 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 528 | `textfield_props_swf7` | 210 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 529 | `textfield_props_swf8` | 210 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 530 | `textfield_text` | 7 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 531 | `textfield_variable` | 81 | 16.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 532 | `textsnapshot_available_text` | 20 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 533 | `textsnapshot_findtext` | 44 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 534 | `textsnapshot_gettext` | 55 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 535 | `textsnapshot_props_swf5` | 56 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 536 | `textsnapshot_props_swf6` | 56 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 537 | `textsnapshot_text_order` | 1 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 538 | `this_scoping` | 52 | 16.0s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 539 | `this_swf5` | 41 | 0.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 540 | `this_swf6` | 41 | 0.3s | [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 541 | `this_swf7` | 41 | 15.4s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 542 | `timeline_function_def` | 7 | 15.5s |  |
| 543 | `timeout` | 0 | 5.2s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 544 | `timer_run_actions` | 18 | 0.2s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 545 | `trace` | 8 | 0.2s |  |
| 546 | `transform` | 70 | 0.2s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 547 | `try_catch_finally` | 118 | 0.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 548 | `try_finally_simple` | 16 | 0.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 549 | `typeof` | 22 | 0.2s |  |
| 550 | `typeof_globals` | 7 | 0.2s |  |
| 551 | `uncaught_exception` | 1 | 0.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 552 | `uncaught_exception_bubbled` | 1 | 0.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 553 | `undefined_to_string_swf6` | 4 | 0.2s |  |
| 554 | `unescape` | 43 | 0.2s |  |
| 555 | `unload` | 52 | 15.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 556 | `unload_clip_event` | 4 | 15.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 557 | `unload_nested_child` | 5 | 0.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 558 | `unloadmovie` | 4 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 559 | `unloadmovie_method` | 3 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 560 | `unloadmovienum` | 13 | 0.3s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 561 | `use_hand_cursor` | 8 | 0.2s |  |
| 562 | `variable_args` | 5 | 16.2s |  |
| 563 | `waitforframe` | 7 | 16.1s |  |
| 564 | `waitforframe2` | 16 | 0.2s |  |
| 565 | `watch` | 117 | 0.2s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 566 | `watch_textfield` | 12 | 15.6s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 567 | `watch_virtual_property_proto` | 2 | 15.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 568 | `with` | 49 | 0.2s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 569 | `with_return` | 2 | 0.2s |  |
| 570 | `with_variable_scopes` | 43 | 0.2s | [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 571 | `xml` | 15 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 572 | `xml_append_child` | 28 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 573 | `xml_append_child_with_parent` | 20 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 574 | `xml_attributes_read` | 4 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 575 | `xml_cdata` | 11 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 576 | `xml_child_nodes_edge_cases` | 4 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 577 | `xml_clone_expandos` | 19 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 578 | `xml_first_last_child` | 8 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 579 | `xml_has_child_nodes` | 3 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 580 | `xml_idmap` | 21 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 581 | `xml_ignore_comments` | 21 | 16.6s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 582 | `xml_ignore_white` | 34 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 583 | `xml_insert_before` | 20 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 584 | `xml_inspect_createmethods` | 15 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 585 | `xml_inspect_doctype` | 7 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 586 | `xml_inspect_parsexml` | 62 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 587 | `xml_inspect_xmldecl` | 7 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 588 | `xml_load` | 2 | 16.6s | [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 589 | `xml_namespaces` | 203 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 590 | `xml_parent_and_child` | 5 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 591 | `xml_remove_node` | 22 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 592 | `xml_reparenting` | 14 | 16.3s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 593 | `xml_siblings` | 10 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 594 | `xml_to_string` | 13 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 595 | `xml_to_string_comment` | 1 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 596 | `xml_unescaping` | 23 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 597 | `xmlnode_proto` | 1 | 0.2s | [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `bitmap_data_thorough/copyPixels` | 68 | 68 | 0.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 2 | `bitmap_data_thorough/paletteMap` | 68 | 68 | 0.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `bitmap_data_thorough/perlinNoise` | 40 | 445 | 0.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 16 | 16 | 0 |
| 6 | [BITMAP_DATA_THOROUGH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) | 19 | 16 | 3 |
| 7 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 0 | 0 | 0 |
| 8 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 0 | 0 | 0 |
| 9 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 0 | 0 | 0 |
| 10 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 11 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 13 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 14 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 15 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 16 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 17 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 18 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 19 | [CONSTRUCT_PARAMETER_REPLAY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) | 1 | 1 | 0 |
| 20 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 21 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 22 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 23 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 24 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 25 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 26 | [DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) | 1 | 1 | 0 |
| 27 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 28 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 29 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 30 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 31 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 32 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 33 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 13 | 13 | 0 |
| 34 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 35 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 36 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 1 | 1 | 0 |
| 37 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 2 | 2 | 0 |
| 38 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 39 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 40 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 41 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 42 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 43 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 6 | 0 |
| 44 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 45 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 26 | 26 | 0 |
| 46 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 16 | 0 |
| 47 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 8 | 8 | 0 |
| 48 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 49 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 50 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 51 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 52 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 53 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 44 | 44 | 0 |
| 54 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 4 | 4 | 0 |
| 55 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 3 | 3 | 0 |
| 56 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 0 | 0 | 0 |
| 57 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 58 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 59 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 60 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 61 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 55 | 55 | 0 |
| 62 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 63 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 14 | 14 | 0 |
| 64 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 2 | 2 | 0 |
| 65 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 1 | 1 | 0 |
| 66 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 67 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 3 | 3 | 0 |
| 68 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 69 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 70 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 71 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 72 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 73 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 74 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
| 75 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 76 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 77 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 78 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 79 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 80 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 81 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 82 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) | 2 | 2 | 0 |
| 83 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 2 | 2 | 0 |
| 84 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 85 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 86 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 87 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 12 | 12 | 0 |
| 88 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 89 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 2 | 2 | 0 |
| 90 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 91 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 92 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 93 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 17 | 17 | 0 |
| 94 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 70 | 0 |
| 95 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 96 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 97 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 98 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 3 | 0 |
| 99 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 100 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 101 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 13 | 13 | 0 |
| 102 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 103 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 0 | 0 | 0 |
| 104 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 105 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 28 | 28 | 0 |
| | *(tests not in any document)* | 144 | 144 | 0 |
