# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 20:37 UTC

**Git SHA**: `92ee912f3f`

**Run Duration**: 74m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 730 |
| Passing | **689** (94.4%) |
| Ruffle-matched | 18 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **707** (96.8%) |
| Failing | 23 |
| Total expected lines | 131487 |
| Matching lines | 119983 (91.3%) |
| Mismatched lines | 11504 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 23 | 100.0% |

## Passing Tests

**689 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 28.3s |  |
| 2 | `action_to_integer` | 28 | 1.5s |  |
| 3 | `add` | 28 | 1.4s |  |
| 4 | `add2` | 354 | 1.6s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 1.4s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.5s |  |
| 7 | `add_swf5` | 28 | 0.4s |  |
| 8 | `amf0_serde_suite` | 144 | 22.1s |  |
| 9 | `amf_array_serialization` | 10 | 1.4s |  |
| 10 | `amf_serialize_typed_objects` | 6 | 1.7s |  |
| 11 | `amf_sharedobject_strict_array_serialization` | 3 | 1.4s |  |
| 12 | `amf_strict_array_serialization` | 7 | 1.4s |  |
| 13 | `amf_swf6_case_insensitive_typed_objects` | 6 | 1.4s |  |
| 14 | `amf_swf6_serialize_typed_objects` | 6 | 1.4s |  |
| 15 | `amf_swf8_case_sensitive_typed_objects` | 6 | 1.4s |  |
| 16 | `arguments` | 127 | 1.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 17 | `array_call_method` | 9 | 1.4s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_concat` | 98 | 1.4s |  |
| 19 | `array_constructor` | 30 | 1.4s |  |
| 20 | `array_enumerate` | 4 | 1.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 21 | `array_length` | 42 | 1.4s |  |
| 22 | `array_properties` | 36 | 0.4s |  |
| 23 | `array_prototyping` | 12 | 1.4s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 24 | `array_reverse` | 226 | 1.4s |  |
| 25 | `array_shift` | 216 | 1.4s |  |
| 26 | `array_slice` | 34 | 27.1s |  |
| 27 | `array_sort` | 161 | 2.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 28 | `array_sort_random` | 443 | 1.5s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 29 | `array_splice` | 207 | 1.5s |  |
| 30 | `array_trivial` | 209 | 1.5s |  |
| 31 | `array_unshift` | 146 | 1.4s |  |
| 32 | `as1_constructor_v6` | 35 | 1.3s |  |
| 33 | `as1_constructor_v7` | 35 | 0.4s |  |
| 34 | `as2_oop` | 13 | 1.6s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 35 | `as2_super_and_this_v6` | 97 | 1.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 36 | `as2_super_and_this_v8` | 85 | 1.4s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 37 | `as2_super_via_manual_prototype` | 40 | 1.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 38 | `as_broadcaster` | 41 | 1.4s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 39 | `as_broadcaster_initialize` | 10 | 1.2s |  |
| 40 | `as_broadcaster_undef` | 89 | 1.4s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 41 | `as_set_prop_flags` | 79 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 42 | `as_set_prop_flags_version` | 31 | 1.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 43 | `as_set_prop_flags_version_swf5` | 1 | 1.3s |  |
| 44 | `as_set_prop_flags_version_swf6` | 1 | 1.3s |  |
| 45 | `as_set_prop_flags_version_swf7` | 1 | 0.5s |  |
| 46 | `as_set_prop_flags_version_swf8` | 1 | 1.2s |  |
| 47 | `as_set_prop_flags_version_swf9` | 1 | 0.5s |  |
| 48 | `as_transformed_flag` | 20 | 20.7s |  |
| 49 | `asfunction` | 11 | 1.6s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 50 | `asnative` | 34 | 1.3s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 51 | `asnew` | 34 | 26.6s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 52 | `assetnative` | 81 | 20.4s |  |
| 53 | `assetnative_ids` | 10 | 1.4s |  |
| 54 | `assetnativeaccessor` | 81 | 1.5s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 55 | `assetnativeaccessor_ids` | 21 | 1.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 56 | `attach_movie` | 59 | 1.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 57 | `attach_movie_stop` | 3 | 20.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 58 | `bad_placeobject_clipaction` | 2 | 1.4s |  |
| 59 | `bad_swf_tag_past_eof` | 0 | 1.2s |  |
| 60 | `bitand` | 1058 | 4.1s |  |
| 61 | `bitmap_data` | 1126 | 3.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 62 | `bitmap_data_colortransform` | 0 | 1.7s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 63 | `bitmap_data_compare` | 40 | 1.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 64 | `bitmap_data_copypixels` | 17 | 21.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 65 | `bitmap_data_draw_cliprect` | 13 | 20.4s |  |
| 66 | `bitmap_data_fillrect` | 0 | 1.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 67 | `bitmap_data_hittest` | 132 | 1.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 68 | `bitmap_data_max_size_swf10` | 12 | 1.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 69 | `bitmap_data_max_size_swf9` | 10 | 1.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 70 | `bitmap_data_noise` | 631 | 1.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 71 | `bitmap_data_perlinnoise` | 0 | 21.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 72 | `bitmap_data_pixeldissolve` | 1075 | 2.7s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 73 | `bitmap_data_pixeldissolve_image` | 0 | 20.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 74 | `bitmap_data_thorough/colorTransform` | 279 | 1.9s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 75 | `bitmap_data_thorough/compare` | 69 | 31.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 76 | `bitmap_data_thorough/constructor` | 313 | 1.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 77 | `bitmap_data_thorough/copyChannel` | 2715 | 1.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 78 | `bitmap_data_thorough/fillRect` | 342 | 1.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 79 | `bitmap_data_thorough/floodFill` | 867 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 80 | `bitmap_data_thorough/getColorBoundsRect` | 285 | 1.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 81 | `bitmap_data_thorough/getPixel` | 141 | 1.1s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 82 | `bitmap_data_thorough/getPixel32` | 141 | 1.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 83 | `bitmap_data_thorough/hitTest` | 519 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 84 | `bitmap_data_thorough/merge` | 1203 | 1.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 85 | `bitmap_data_thorough/noise` | 1518 | 1.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 86 | `bitmap_data_thorough/scroll` | 384 | 1.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 87 | `bitmap_data_thorough/setPixel` | 531 | 1.1s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 88 | `bitmap_data_thorough/setPixel32` | 531 | 1.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 89 | `bitmap_data_thorough/threshold` | 1308 | 1.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 90 | `bitmap_data_threshold` | 176 | 1.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 91 | `bitmap_filters` | 548 | 2.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 92 | `bitmapdata_applyfilter_colormatrix` | 0 | 15.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 93 | `bitmapdata_channels` | 19 | 0.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 94 | `bitmapdata_hittest_threshold` | 6 | 0.9s |  |
| 95 | `bitor` | 1058 | 2.9s |  |
| 96 | `biturshift` | 14 | 28.1s |  |
| 97 | `biturshift_swf8` | 14 | 0.9s |  |
| 98 | `bitxor` | 1058 | 4.6s |  |
| 99 | `boxed_primitives` | 24 | 22.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 100 | `button_children` | 8 | 1.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 101 | `button_goto` | 4 | 21.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 102 | `button_key_events` | 14 | 1.7s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 103 | `button_key_events_special` | 45 | 3.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 104 | `button_keypress` | 3 | 1.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 105 | `button_keypress_vs_press` | 25 | 1.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 106 | `button_keypress_vs_tab` | 20 | 1.7s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 107 | `button_keypress_vs_textinput` | 4 | 1.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 108 | `button_order` | 2 | 1.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 109 | `button_properties_special_cases` | 22 | 21.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 110 | `button_v5` | 18 | 1.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 111 | `button_v6` | 18 | 0.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 112 | `call` | 62 | 21.5s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 113 | `call_method_empty_name` | 1 | 1.1s |  |
| 114 | `capabilities_resolution` | 8 | 21.4s |  |
| 115 | `catch_references_registers` | 2 | 1.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 116 | `click_block` | 5 | 22.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 117 | `clip_constructors` | 8 | 1.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 118 | `clip_event_propagation_order` | 17 | 22.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 119 | `clip_events` | 19 | 24.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 120 | `clone_sprite_edittext` | 94 | 1.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 121 | `clone_sprite_edittext_dynamic` | 86 | 25.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 122 | `clone_sprite_types` | 24 | 1.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 123 | `closure_scope` | 7 | 18.8s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 124 | `coerce_to_object_monkeypatch` | 129 | 18.6s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 125 | `coerce_to_primitive_resolve` | 22 | 1.2s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 126 | `color` | 57 | 1.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 127 | `color_transform` | 48 | 1.1s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 128 | `conflicting_instance_names` | 23 | 18.6s |  |
| 129 | `constructor_function` | 2 | 1.1s |  |
| 130 | `context_menu` | 39 | 1.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 131 | `context_menu_item` | 41 | 1.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 132 | `create_empty_movie_clip` | 3 | 1.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 133 | `cross_movie_root` | 10 | 19.0s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 134 | `custom_clip_methods` | 4 | 1.3s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 135 | `default_names` | 52 | 1.4s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 136 | `define_font_glyph_table_order` | 0 | 25.4s |  |
| 137 | `define_font_glyph_table_overlap` | 0 | 0.7s |  |
| 138 | `define_function2` | 8 | 1.1s |  |
| 139 | `define_function2_preload` | 13 | 1.3s |  |
| 140 | `define_function2_preload_order` | 4 | 1.2s |  |
| 141 | `define_function_case_sensitive` | 2 | 18.4s |  |
| 142 | `define_local` | 27 | 1.0s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 143 | `define_local_with_paths` | 54 | 1.2s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 144 | `delete` | 3 | 1.2s |  |
| 145 | `delete2` | 74 | 23.4s |  |
| 146 | `depth_replacement_audio_unloading` | 3 | 16.8s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) |
| 147 | `device_font_spacing` | 91 | 17.7s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 148 | `displacementmapfilter_mappoint_throw_error` | 13 | 1.2s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 149 | `display_object_properties` | 2 | 1.1s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 150 | `divide_swf4` | 107 | 1.1s |  |
| 151 | `do_init_action` | 3 | 17.1s |  |
| 152 | `do_init_action_child` | 12 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 153 | `drag_drop` | 10 | 1.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 154 | `drag_over_from_outside` | 1 | 17.0s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 155 | `drag_over_without_startdrag` | 1 | 1.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 156 | `duplicate_movie_clip` | 20 | 1.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 157 | `duplicate_movie_clip_drawing` | 2 | 1.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 158 | `edittext_align` | 60 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 159 | `edittext_align_trailing_spaces_swf7` | 576 | 17.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 160 | `edittext_align_trailing_spaces_swf8` | 576 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 161 | `edittext_antialiastype` | 296 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 162 | `edittext_autosize` | 71 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 163 | `edittext_autosize_setter` | 20 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 164 | `edittext_bullet` | 30 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 165 | `edittext_default_format` | 221 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 166 | `edittext_default_format_empty` | 100 | 1.1s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 167 | `edittext_default_format_font_style` | 335 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 168 | `edittext_drag_select` | 9 | 16.8s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 169 | `edittext_focus_selection` | 2 | 1.1s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 170 | `edittext_font_size` | 45 | 30.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 171 | `edittext_hscroll` | 27 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 172 | `edittext_html_align_swf7` | 52 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 173 | `edittext_html_align_swf8` | 52 | 0.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 174 | `edittext_html_color` | 114 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 175 | `edittext_html_condensewhite_swf7` | 311 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 176 | `edittext_html_condensewhite_swf8` | 311 | 0.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 177 | `edittext_html_entity` | 4 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 178 | `edittext_html_roundtrip` | 17 | 1.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 179 | `edittext_html_swf6` | 5377 | 3.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 180 | `edittext_html_swf7` | 5377 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 181 | `edittext_html_swf8` | 5377 | 0.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 182 | `edittext_ime_focus_lost` | 7 | 21.2s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 183 | `edittext_input` | 1 | 21.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 184 | `edittext_input_newlines` | 9 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 185 | `edittext_leading` | 9 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 186 | `edittext_letter_spacing` | 15 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 187 | `edittext_margins` | 25 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 188 | `edittext_newline_stripping` | 64 | 6.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 189 | `edittext_newlines` | 30 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 190 | `edittext_password` | 5 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 191 | `edittext_password_copy` | 4 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 192 | `edittext_paste_empty` | 2 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 193 | `edittext_place_caret` | 2 | 21.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 194 | `edittext_programmatic_focus` | 12 | 1.4s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 195 | `edittext_restrict` | 191 | 30.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 196 | `edittext_restrict_paste` | 5 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 197 | `edittext_scroll` | 54 | 24.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 198 | `edittext_stylesheet` | 325 | 2.5s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 199 | `edittext_tab_focus` | 13 | 23.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 200 | `edittext_tab_stops` | 60 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 201 | `edittext_tag_indent` | 31 | 23.7s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 202 | `edittext_text_height_leading` | 20 | 1.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 203 | `edittext_underline` | 40 | 1.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 204 | `edittext_width_height` | 103 | 1.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 205 | `empty_movieclip_can_attach_movies` | 11 | 1.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 206 | `enumerate` | 64 | 1.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 207 | `equals` | 32 | 1.5s |  |
| 208 | `equals2_swf5` | 926 | 3.5s |  |
| 209 | `equals2_swf6` | 926 | 0.5s |  |
| 210 | `equals2_swf7` | 926 | 0.5s |  |
| 211 | `equals_swf4` | 665 | 2.5s |  |
| 212 | `equals_swf4_alt` | 32 | 0.4s |  |
| 213 | `equals_swf5` | 32 | 0.4s |  |
| 214 | `error` | 58 | 1.5s |  |
| 215 | `escape` | 14 | 1.4s |  |
| 216 | `execution_order1` | 5 | 23.9s |  |
| 217 | `execution_order2` | 7 | 24.1s |  |
| 218 | `execution_order3` | 4 | 1.5s |  |
| 219 | `execution_order4` | 12 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 220 | `export_assets` | 3 | 27.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 221 | `extends_chain` | 134 | 2.0s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 222 | `extends_native_type` | 11 | 1.4s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 223 | `external_interface` | 84 | 1.6s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 224 | `external_interface_escapexml` | 26 | 1.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 225 | `external_interface_jsquotestring` | 21 | 1.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 226 | `external_interface_toas_basic` | 354 | 1.7s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 227 | `external_interface_toxml_array` | 25 | 1.3s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 228 | `external_interface_toxml_basic` | 179 | 1.5s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 229 | `external_interface_unescapexml` | 40 | 1.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 230 | `file_reference_browse_cancel` | 21 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 231 | `file_reference_download_cancel` | 7 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 232 | `file_reference_download_httperror_dns_error` | 13 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 233 | `file_reference_download_httperror_status_code` | 23 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 234 | `file_reference_download_success` | 34 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 235 | `file_reference_list_asbroadcaster` | 9 | 1.3s |  |
| 236 | `file_reference_list_browse_cancel` | 4 | 1.3s |  |
| 237 | `file_reference_list_browse_invalid_filters` | 36 | 1.5s |  |
| 238 | `file_reference_list_browse_select` | 7 | 1.3s |  |
| 239 | `file_reference_upload_httperror_dns_error` | 18 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 240 | `file_reference_upload_httperror_status_code` | 23 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 241 | `file_reference_upload_success` | 23 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 242 | `focus_keyboard_press` | 60 | 1.8s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 243 | `focus_mouse` | 45 | 1.6s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 244 | `focus_mouse_focusable` | 8 | 21.0s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 245 | `focus_mouse_rollout` | 4 | 29.9s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 246 | `focus_remove` | 33 | 21.0s |  |
| 247 | `focus_root_movie` | 2 | 1.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 248 | `focus_visibility_change` | 45 | 1.3s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 249 | `focusrect_focuslost` | 4 | 1.4s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 250 | `focusrect_mouse_swf8` | 0 | 1.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 251 | `focusrect_mouse_swf9` | 0 | 0.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 252 | `focusrect_property_swf5` | 1237 | 1.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 253 | `focusrect_property_swf6` | 1237 | 1.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 254 | `focusrect_property_swf7` | 1237 | 0.6s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 255 | `focusrect_swf5` | 6 | 22.9s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 256 | `focusrect_swf6` | 42 | 1.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 257 | `form_loader_encoding_1` | 1 | 1.4s |  |
| 258 | `form_loader_encoding_2` | 3 | 20.8s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 259 | `form_loader_encoding_3` | 3 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 260 | `frame_size_translated_negative` | 21 | 20.5s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 261 | `frame_size_translated_positive` | 21 | 20.4s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 262 | `function_as_function` | 35 | 1.3s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 263 | `function_base_clip` | 8 | 20.4s |  |
| 264 | `function_base_clip_readded` | 11 | 20.6s |  |
| 265 | `function_base_clip_removed` | 25 | 1.5s |  |
| 266 | `function_suppress_and_preload` | 28 | 20.6s |  |
| 267 | `funky_function_calls` | 56 | 1.4s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 268 | `get_bytes_total` | 4 | 27.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 269 | `get_variable_in_scope` | 29 | 22.4s |  |
| 270 | `getproperty` | 28 | 1.4s |  |
| 271 | `getproperty_swf4` | 28 | 0.5s |  |
| 272 | `getproperty_swf5` | 28 | 0.5s |  |
| 273 | `gettextextent` | 56 | 1.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 274 | `geturl_opcode_target_normalize` | 45 | 21.8s |  |
| 275 | `geturl_target_normalize` | 89 | 21.6s |  |
| 276 | `global_array` | 3 | 1.3s |  |
| 277 | `global_is_bare` | 7 | 1.3s |  |
| 278 | `global_swf5_6_7_8_9` | 1145 | 22.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 279 | `global_swf6_7_8` | 15 | 1.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 280 | `globals_swf6` | 304 | 1.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 281 | `globals_swf7` | 304 | 0.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 282 | `globals_swf8` | 304 | 0.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 283 | `goto_advance1` | 6 | 21.7s |  |
| 284 | `goto_advance2` | 2 | 1.5s |  |
| 285 | `goto_both_ways1` | 3 | 1.5s |  |
| 286 | `goto_both_ways2` | 3 | 26.8s |  |
| 287 | `goto_execution_order` | 2 | 20.3s |  |
| 288 | `goto_execution_order2` | 2 | 1.4s |  |
| 289 | `goto_frame` | 12 | 1.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 290 | `goto_frame2` | 44 | 21.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 291 | `goto_frame_number` | 3 | 20.5s |  |
| 292 | `goto_label` | 17 | 20.6s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 293 | `goto_methods` | 40 | 20.4s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 294 | `goto_rewind1` | 1 | 20.4s |  |
| 295 | `goto_rewind2` | 3 | 1.3s |  |
| 296 | `goto_rewind3` | 2 | 1.4s |  |
| 297 | `greater_swf6` | 1175 | 3.4s |  |
| 298 | `greater_swf7` | 1175 | 0.4s |  |
| 299 | `greaterthan_swf5` | 1 | 1.3s |  |
| 300 | `greaterthan_swf8` | 1 | 1.2s |  |
| 301 | `has_own_property` | 32 | 1.3s |  |
| 302 | `hittest_lockroot` | 15 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 303 | `hittest_morph` | 70 | 1.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 304 | `hittest_morph_input` | 1 | 1.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 305 | `hittest_winding_rule` | 12 | 20.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 306 | `infinite_recursion_function` | 4 | 27.9s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 307 | `infinite_recursion_function_in_setter` | 131 | 1.6s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 308 | `infinite_recursion_virtual_property` | 67 | 1.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 309 | `init_array_invalid` | 4 | 22.8s |  |
| 310 | `init_object_invalid` | 4 | 0.3s |  |
| 311 | `init_object_order` | 15 | 1.6s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 312 | `input_dead_keys_windows` | 15 | 1.8s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 313 | `instanceof_coercions` | 88 | 2.0s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 314 | `interface_implements_op` | 47 | 2.2s | [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 315 | `is_finite` | 49 | 1.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 316 | `is_finite_swf6` | 49 | 0.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 317 | `is_prototype_of` | 89 | 1.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 318 | `issue_1086` | 1 | 1.4s |  |
| 319 | `issue_1104` | 2 | 22.6s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 320 | `issue_1671` | 0 | 22.2s |  |
| 321 | `issue_1906` | 4 | 1.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 322 | `issue_2030` | 4 | 1.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 323 | `issue_2084` | 16 | 22.2s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 324 | `issue_2166` | 9 | 1.3s |  |
| 325 | `issue_2870` | 3 | 21.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 326 | `issue_3169` | 2 | 1.5s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 327 | `issue_3446` | 1 | 1.3s |  |
| 328 | `issue_3522` | 2 | 1.6s |  |
| 329 | `issue_4377` | 2 | 1.3s |  |
| 330 | `issue_710` | 4 | 25.8s |  |
| 331 | `issue_768` | 3 | 1.2s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 332 | `issue_9327` | 2 | 20.5s |  |
| 333 | `issue_9885` | 2 | 20.6s |  |
| 334 | `key_isToggled` | 9 | 1.3s |  |
| 335 | `lessthan` | 41 | 1.3s |  |
| 336 | `lessthan2_swf5` | 1226 | 3.5s |  |
| 337 | `lessthan2_swf6` | 1226 | 0.4s |  |
| 338 | `lessthan2_swf7` | 1226 | 0.4s |  |
| 339 | `lessthan_swf4` | 902 | 2.5s |  |
| 340 | `lessthan_swf4_alt` | 41 | 0.4s |  |
| 341 | `lessthan_swf5` | 41 | 0.4s |  |
| 342 | `load_cancel_via_removemovieclip` | 4 | 1.4s |  |
| 343 | `loadmovie` | 2 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 344 | `loadmovie_fail` | 2 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 345 | `loadmovie_flashvars` | 4 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 346 | `loadmovie_method` | 2 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 347 | `loadmovie_registerclass` | 30 | 1.6s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 348 | `loadmovie_replace_root` | 5 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 349 | `loadmovie_var_persistence` | 8 | 1.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 350 | `loadmovienum` | 3 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 351 | `loadmovienum_cross_version_prototype` | 9 | 26.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 352 | `loadvariables` | 2 | 20.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 353 | `loadvariables2` | 8 | 20.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 354 | `loadvariablesnum` | 2 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 355 | `loadvars_tostring` | 5 | 20.7s |  |
| 356 | `local_to_global` | 49 | 1.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 357 | `localconnection` | 579 | 2.7s | [57](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 358 | `localconnection_properties` | 8 | 1.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 359 | `localconnection_top_level` | 7 | 21.2s |  |
| 360 | `lock_root` | 1 | 1.4s |  |
| 361 | `logical_ops_swf4` | 90 | 1.3s |  |
| 362 | `logical_ops_swf8` | 108 | 1.3s |  |
| 363 | `looping` | 6 | 21.0s |  |
| 364 | `looping_child_swf32` | 141 | 22.8s |  |
| 365 | `looping_child_swf5` | 141 | 1.8s |  |
| 366 | `looping_child_swf9` | 141 | 0.6s |  |
| 367 | `looping_real_1_declared_1` | 1 | 1.3s |  |
| 368 | `looping_real_1_declared_2` | 1 | 0.4s |  |
| 369 | `looping_real_2_declared_1` | 5 | 1.3s |  |
| 370 | `looping_real_2_declared_2` | 5 | 0.4s |  |
| 371 | `mask_reapply` | 0 | 20.9s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 372 | `mask_with_drawing` | 0 | 20.9s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 373 | `math_min_max` | 101 | 1.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 374 | `math_swf6` | 530 | 27.5s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 375 | `math_swf7` | 530 | 1.1s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 376 | `math_swf8` | 530 | 1.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 377 | `matrix` | 171 | 20.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 378 | `mcl_as_broadcaster` | 12 | 1.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 379 | `mcl_events_swf_version` | 232 | 2.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 380 | `mcl_getprogress` | 30 | 20.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 381 | `mcl_loadclip` | 149 | 20.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 382 | `mcl_loadclip_properties` | 6 | 1.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 383 | `mcl_loadclip_replace_root` | 1 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 384 | `mcl_mislabeled_target` | 6 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 385 | `mcl_target_gif87a` | 6 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 386 | `mcl_target_gif89a` | 6 | 0.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 387 | `mcl_target_jpg` | 6 | 0.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 388 | `mcl_target_png` | 6 | 1.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 389 | `mcl_unloadclip` | 5 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 390 | `mouse_events` | 8 | 20.6s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 391 | `mouse_events_visible_enabled` | 12 | 1.7s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 392 | `mouse_hover_events_while_dragging` | 1 | 1.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 393 | `mouse_listeners` | 67 | 1.3s |  |
| 394 | `mouse_pos` | 665 | 20.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 395 | `mouse_pos_with_scale_factor` | 260 | 20.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 396 | `mouse_wheel_enabled` | 2 | 28.5s |  |
| 397 | `movieclip_begin_gradient_fill` | 0 | 21.5s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 398 | `movieclip_blend_mode_property` | 35 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 399 | `movieclip_create_text_field` | 90 | 20.9s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 400 | `movieclip_default_state` | 69 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 401 | `movieclip_depth_methods` | 98 | 21.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 402 | `movieclip_focusenabled` | 99 | 1.4s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 403 | `movieclip_get_instance_at_depth` | 28 | 1.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 404 | `movieclip_getbounds` | 191 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 405 | `movieclip_gettextsnapshot` | 112 | 1.6s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 406 | `movieclip_hittest` | 92 | 1.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 407 | `movieclip_in_removed_button` | 4 | 21.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 408 | `movieclip_init_object` | 5 | 1.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 409 | `movieclip_invalid_get_bounds_1` | 75 | 2.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 410 | `movieclip_invalid_get_bounds_2` | 75 | 1.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 411 | `movieclip_invalid_get_bounds_3` | 13 | 1.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 412 | `movieclip_invalid_get_bounds_4` | 13 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 413 | `movieclip_invalid_get_bounds_5` | 11 | 1.7s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 414 | `movieclip_invalid_get_bounds_6` | 10 | 27.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 415 | `movieclip_invalid_get_bounds_7` | 10 | 27.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 416 | `movieclip_invalid_get_bounds_8` | 11 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 417 | `movieclip_line_gradient_style` | 0 | 1.9s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 418 | `movieclip_lockroot` | 29 | 26.0s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 419 | `movieclip_methods_with_loaded_image` | 4 | 20.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 420 | `movieclip_name_from_timeline` | 13 | 1.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 421 | `movieclip_onconstruct` | 20 | 1.4s |  |
| 422 | `movieclip_prototype_extension` | 5 | 1.2s |  |
| 423 | `movieclip_setmask` | 14 | 20.9s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 424 | `movieclip_state_values` | 114 | 2.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 425 | `moviecliploader_flashvars` | 4 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 426 | `mutable_this` | 18 | 1.3s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 427 | `named_shapes` | 14 | 20.3s |  |
| 428 | `nan_scale` | 9 | 1.3s |  |
| 429 | `native_double_construct` | 12 | 20.3s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 430 | `native_objects_swf7` | 115 | 0.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 431 | `native_objects_swf8` | 115 | 0.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 432 | `native_subclasses` | 191 | 1.7s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 433 | `nested_textfields_in_buttons` | 0 | 1.4s |  |
| 434 | `netconnection_close` | 39 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 435 | `netconnection_send_remote` | 50 | 21.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 436 | `netconnection_serialize_arrays` | 6 | 1.3s |  |
| 437 | `netstream_play_flv` | 21 | 1.7s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 438 | `netstream_play_flv_screen` | 0 | 36.2s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 439 | `netstream_seek_flv` | 25 | 20.6s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 440 | `new_method_wrap` | 4 | 20.2s |  |
| 441 | `new_object_enumerate` | 7 | 25.7s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 442 | `new_object_wrap` | 4 | 19.4s |  |
| 443 | `o` | 3 | 1.0s |  |
| 444 | `object_constructor` | 33 | 1.1s |  |
| 445 | `object_function` | 32 | 1.1s |  |
| 446 | `object_properties` | 31 | 1.3s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 447 | `object_prototypes` | 74 | 1.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 448 | `object_resolve` | 38 | 20.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 449 | `object_string_coerce_swf5` | 62 | 1.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 450 | `object_string_coerce_swf6` | 68 | 1.1s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 451 | `on_construct` | 25 | 1.2s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 452 | `parse_float` | 74 | 1.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 453 | `parse_int` | 64 | 20.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 454 | `path_string` | 301 | 1.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 455 | `place_and_lookup` | 30 | 1.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 456 | `placeobject_all_event_flags` | 10 | 20.1s |  |
| 457 | `placeobject_occupied_depth` | 6 | 20.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 458 | `point` | 175 | 1.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 459 | `primitive_instanceof` | 37 | 1.1s |  |
| 460 | `primitive_type_globals` | 557 | 1.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 461 | `printjob_props_swf5` | 45 | 1.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 462 | `printjob_props_swf6` | 45 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 463 | `printjob_props_swf7` | 45 | 0.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 464 | `property_invalid_base_clip` | 35 | 1.2s |  |
| 465 | `prototype_delete` | 12 | 26.8s |  |
| 466 | `prototype_enumerate` | 5 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 467 | `prototype_properties` | 17 | 1.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 468 | `rectangle` | 745 | 2.2s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 469 | `recursive_prototypes` | 0 | 1.3s |  |
| 470 | `register_and_init_order` | 231 | 22.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 471 | `register_class` | 66 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 472 | `register_class_return_value` | 16 | 21.8s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 473 | `register_class_swf6` | 37 | 1.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 474 | `register_class_with_sound` | 11 | 1.6s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 475 | `register_globals_across_frames` | 15 | 1.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 476 | `register_underflow` | 26 | 1.3s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 477 | `remove_different_level` | 3 | 1.4s |  |
| 478 | `remove_movie_clip` | 29 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 479 | `removed_base_clip_tell_target` | 1 | 21.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 480 | `removed_clip_halts_script` | 15 | 22.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 481 | `removed_target_clip_scope` | 35 | 1.6s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 482 | `resolve_different_root` | 2 | 1.5s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 483 | `rewind_depth` | 30 | 21.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 484 | `root_button_mode` | 10 | 21.8s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 485 | `root_global_parent` | 6 | 21.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 486 | `root_onload` | 1 | 1.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 487 | `sandbox_type_local_file` | 1 | 21.4s |  |
| 488 | `sandbox_type_local_network` | 1 | 1.0s |  |
| 489 | `selection` | 454 | 20.2s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 490 | `selection_asbroadcaster` | 9 | 1.1s |  |
| 491 | `selection_handlers` | 27 | 1.2s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 492 | `set_interval` | 27 | 1.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 493 | `set_target_2_swf5` | 13 | 1.2s |  |
| 494 | `set_target_2_swf6` | 13 | 1.1s |  |
| 495 | `set_target_2_swf7` | 13 | 0.3s |  |
| 496 | `set_variable_scope` | 58 | 1.1s |  |
| 497 | `shared_object_serialize_typed_objects` | 1 | 1.2s |  |
| 498 | `shared_stack` | 16 | 20.0s |  |
| 499 | `single_frame` | 1 | 1.0s |  |
| 500 | `slash_syntax` | 14 | 1.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 501 | `sound` | 628 | 1.4s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 502 | `sound_duration_position_props` | 290 | 1.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 503 | `sound_getters` | 99 | 1.1s |  |
| 504 | `sound_gettransform_props` | 4 | 1.0s |  |
| 505 | `sound_id3` | 633 | 1.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 506 | `sound_id3_prop` | 138 | 1.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 507 | `sound_load_multiple_instances` | 19 | 20.5s |  |
| 508 | `sound_load_multiple_remote` | 6 | 25.4s |  |
| 509 | `sound_load_props` | 111 | 1.5s |  |
| 510 | `sound_load_start` | 6 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 511 | `sound_load_start_remote` | 1 | 2.7s |  |
| 512 | `sound_load_stops_when_dereferenced` | 0 | 20.5s |  |
| 513 | `sound_load_streaming_stop_remote` | 3 | 1.3s |  |
| 514 | `sound_mixed_attach_load` | 13 | 21.5s |  |
| 515 | `sound_multiple_load` | 1 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 516 | `sound_nested_clips` | 10 | 1.4s |  |
| 517 | `sound_owner_reference` | 12 | 1.3s |  |
| 518 | `sound_owner_tostring_fail` | 9 | 1.3s |  |
| 519 | `sound_props_swf5` | 68 | 1.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 520 | `sound_props_swf6` | 68 | 1.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 521 | `sound_setters` | 43 | 1.4s |  |
| 522 | `sound_start_load` | 0 | 1.3s |  |
| 523 | `sound_start_stop` | 44 | 20.6s |  |
| 524 | `stage_display_state` | 16 | 1.3s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 525 | `stage_object_children` | 83 | 1.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 526 | `stage_object_enumerate` | 4 | 1.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 527 | `stage_object_properties` | 241 | 20.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 528 | `stage_object_properties_get_var` | 5 | 1.2s |  |
| 529 | `stage_object_properties_swf6` | 231 | 20.9s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 530 | `stage_property_representation` | 586 | 1.3s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 531 | `stage_scale_mode` | 39 | 20.6s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 532 | `strictequals_swf6` | 902 | 27.4s |  |
| 533 | `strictly_equals` | 7 | 1.5s |  |
| 534 | `string_coercion` | 117 | 2.5s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 535 | `string_methods` | 285 | 1.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 536 | `string_methods_negative_args` | 240 | 20.7s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 537 | `string_methods_swfv5` | 275 | 2.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 538 | `string_ops_swf6` | 95 | 1.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 539 | `string_paths_basic` | 4 | 1.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 540 | `string_paths_eval` | 4 | 1.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 541 | `string_paths_eval2` | 7 | 20.8s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 542 | `string_paths_hidden` | 54 | 1.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 543 | `string_paths_keyevents` | 0 | 1.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 544 | `string_paths_other` | 36 | 1.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 545 | `string_paths_reference_launder` | 2 | 1.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 546 | `string_paths_timer` | 0 | 1.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 547 | `string_paths_unload` | 1 | 1.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 548 | `string_paths_variable_alias` | 4 | 1.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 549 | `string_paths_variable_scopes` | 5 | 1.4s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 550 | `string_relational_compare` | 4 | 1.4s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) |
| 551 | `stylesheet` | 283 | 2.2s |  |
| 552 | `stylesheet_transform` | 750 | 2.2s |  |
| 553 | `super_edge_cases` | 39 | 1.5s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 554 | `swf4_actions_bool` | 96 | 1.4s |  |
| 555 | `swf4_actions_coercion_order` | 157 | 16.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 556 | `swf4_bool` | 4 | 0.8s |  |
| 557 | `swf4_function_calls` | 7 | 0.8s |  |
| 558 | `swf5_encoding` | 3 | 0.9s |  |
| 559 | `swf5_global_funcs` | 232 | 0.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 560 | `swf5_no_closure` | 19 | 0.8s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 561 | `swf5_to_6_cross_call` | 29 | 1.0s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 562 | `swf5_xml_event_handler_context` | 2 | 12.8s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 563 | `swf6_case_insensitive` | 42 | 0.8s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 564 | `swf6_global_funcs` | 232 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 565 | `swf6_string_as_bool` | 15 | 0.8s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 566 | `swf6_to_5_cross_call` | 29 | 0.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 567 | `swf7_case_sensitive` | 44 | 0.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 568 | `swf7_global_funcs` | 232 | 1.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 569 | `tab_ordering_automatic_basic` | 92 | 1.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 570 | `tab_ordering_automatic_order_grid` | 21 | 0.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 571 | `tab_ordering_automatic_order_same_position` | 12 | 0.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 572 | `tab_ordering_children` | 208 | 1.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 573 | `tab_ordering_custom_basic` | 71 | 1.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 574 | `tab_ordering_custom_duplicate_index` | 22 | 0.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 575 | `tab_ordering_custom_i32_vs_u32` | 12 | 1.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 576 | `tab_ordering_custom_m1` | 29 | 0.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 577 | `tab_ordering_events` | 150 | 2.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 578 | `tab_ordering_events_mouse` | 65 | 27.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 579 | `tab_ordering_movieclip_enabled_default` | 462 | 1.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 580 | `tab_ordering_properties` | 293 | 1.8s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 581 | `tab_ordering_reverse` | 51 | 1.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 582 | `tab_ordering_tabbable` | 47 | 1.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 583 | `target_clip_removed` | 5 | 21.5s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 584 | `target_clip_swf5` | 2 | 1.4s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 585 | `target_clip_swf6` | 2 | 1.0s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 586 | `target_path` | 14 | 1.5s |  |
| 587 | `target_paths/swf4` | 818 | 22.6s |  |
| 588 | `tell_target` | 34 | 1.7s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 589 | `tell_target_invalid` | 5 | 21.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 590 | `tell_target_invalid_swf6` | 4 | 0.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 591 | `text_blocks_clicks` | 4 | 1.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 592 | `text_format` | 1146 | 1.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 593 | `text_format_display` | 21 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 594 | `text_format_font_max_length` | 2 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 595 | `text_format_get_text_extent_undefined_width` | 10 | 1.4s |  |
| 596 | `text_format_rounding_swf7` | 840 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 597 | `text_format_rounding_swf8` | 840 | 0.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 598 | `textfield_asbroadcaster` | 14 | 1.4s |  |
| 599 | `textfield_background_color` | 11 | 31.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 600 | `textfield_border_color` | 11 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 601 | `textfield_cache_as_bitmap` | 1 | 1.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 602 | `textfield_maxchars` | 3 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 603 | `textfield_properties` | 44 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 604 | `textfield_props_swf6` | 210 | 0.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 605 | `textfield_props_swf7` | 210 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 606 | `textfield_props_swf8` | 210 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 607 | `textfield_text` | 7 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 608 | `textfield_variable` | 81 | 21.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 609 | `textsnapshot_available_text` | 20 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 610 | `textsnapshot_findtext` | 44 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 611 | `textsnapshot_gettext` | 55 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 612 | `textsnapshot_props_swf5` | 56 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 613 | `textsnapshot_props_swf6` | 56 | 0.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 614 | `textsnapshot_text_order` | 1 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 615 | `this_scoping` | 52 | 21.3s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 616 | `this_swf5` | 41 | 1.0s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 617 | `this_swf6` | 41 | 0.7s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 618 | `this_swf7` | 41 | 0.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 619 | `timeline_function_def` | 7 | 21.4s |  |
| 620 | `timeout` | 0 | 6.0s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 621 | `timer_run_actions` | 18 | 1.2s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 622 | `trace` | 8 | 26.4s |  |
| 623 | `transform` | 70 | 1.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 624 | `try_catch_finally` | 118 | 1.6s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 625 | `try_catch_stack` | 16 | 1.7s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) |
| 626 | `try_finally_simple` | 16 | 1.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 627 | `typeof` | 22 | 1.4s |  |
| 628 | `typeof_globals` | 7 | 1.2s |  |
| 629 | `uncaught_exception` | 1 | 1.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 630 | `uncaught_exception_bubbled` | 1 | 1.2s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 631 | `undefined_to_string_swf6` | 4 | 1.2s |  |
| 632 | `unescape` | 43 | 1.2s |  |
| 633 | `unload` | 52 | 20.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 634 | `unload_clip_event` | 4 | 20.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 635 | `unload_nested_child` | 5 | 20.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 636 | `unloadmovie` | 4 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 637 | `unloadmovie_method` | 3 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 638 | `unloadmovienum` | 13 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 639 | `use_hand_cursor` | 8 | 1.2s |  |
| 640 | `variable_args` | 5 | 1.5s |  |
| 641 | `virtual_property_recursion_double_swf6` | 11 | 1.3s |  |
| 642 | `virtual_property_recursion_double_swf7` | 523 | 1.3s |  |
| 643 | `virtual_property_recursion_scope` | 11 | 1.4s |  |
| 644 | `virtual_property_recursion_swf7` | 262 | 1.3s |  |
| 645 | `waitforframe` | 7 | 25.6s |  |
| 646 | `waitforframe2` | 16 | 1.3s |  |
| 647 | `watch` | 117 | 1.7s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 648 | `watch_infinite_recursion` | 1 | 1.4s |  |
| 649 | `watch_proto_recursion` | 1 | 1.3s |  |
| 650 | `watch_recursion_double_swf7` | 3118 | 1.4s |  |
| 651 | `watch_recursion_swf7` | 1042 | 0.6s |  |
| 652 | `watch_textfield` | 12 | 1.5s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 653 | `watch_virtual_property` | 60 | 1.4s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 654 | `watch_virtual_property_proto` | 2 | 20.4s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 655 | `with` | 46 | 1.4s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 656 | `with_return` | 2 | 1.2s |  |
| 657 | `with_variable_scopes` | 43 | 1.4s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 658 | `xml` | 15 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 659 | `xml_append_child` | 28 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 660 | `xml_append_child_with_parent` | 20 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 661 | `xml_attributes_read` | 4 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 662 | `xml_cdata` | 11 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 663 | `xml_child_nodes_edge_cases` | 4 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 664 | `xml_clone_expandos` | 19 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 665 | `xml_first_last_child` | 8 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 666 | `xml_has_child_nodes` | 3 | 24.0s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 667 | `xml_idmap` | 21 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 668 | `xml_ignore_comments` | 21 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 669 | `xml_ignore_white` | 34 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 670 | `xml_insert_before` | 20 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 671 | `xml_inspect_createmethods` | 15 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 672 | `xml_inspect_doctype` | 7 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 673 | `xml_inspect_parsexml` | 62 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 674 | `xml_inspect_xmldecl` | 7 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 675 | `xml_load` | 2 | 1.0s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 676 | `xml_namespaces` | 203 | 1.0s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 677 | `xml_parent_and_child` | 5 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 678 | `xml_remove_node` | 22 | 1.0s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 679 | `xml_reparenting` | 14 | 18.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 680 | `xml_siblings` | 10 | 1.0s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 681 | `xml_socket` | 8 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 682 | `xml_socket_close_in_handler` | 6 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 683 | `xml_socket_connect_null` | 12 | 18.9s |  |
| 684 | `xml_socket_on_data` | 7 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 685 | `xml_socket_segmented` | 29 | 0.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 686 | `xml_to_string` | 13 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 687 | `xml_to_string_comment` | 1 | 1.0s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 688 | `xml_unescaping` | 23 | 1.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 689 | `xmlnode_proto` | 1 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Ruffle-Matched Tests

**18 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `attach_movie_export_not_yet_run` | 1 | 1 | 20.3s |  |
| 2 | `bitmap_data_thorough/copyPixels` | 68 | 68 | 1.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 3 | `bitmap_data_thorough/paletteMap` | 68 | 68 | 1.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `bitmap_data_thorough/perlinNoise` | 40 | 445 | 1.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 5 | `form_loader_encoding_4` | 2 | 2 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 6 | `load_cancel_via_unloadclip` | 2 | 2 | 1.4s |  |
| 7 | `load_cancel_via_unloadmovie` | 3 | 3 | 1.2s |  |
| 8 | `mcl_replace_root_swf7_to_swf5` | 1 | 1 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 9 | `mcl_replace_root_swf7_to_swf6` | 5 | 6 | 0.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 10 | `movieclip_library_state_values` | 2 | 9 | 1.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 11 | `swf4_vars` | 3 | 4 | 0.9s |  |
| 12 | `tab_ordering_properties_tab_index_edge_case` | 3 | 3 | 1.4s |  |
| 13 | `target_paths/swf5` | 654 | 654 | 0.5s |  |
| 14 | `target_paths/swf6` | 654 | 654 | 0.5s |  |
| 15 | `textfield_props_swf5` | 2 | 103 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 16 | `virtual_property_recursion_swf6` | 3 | 261 | 1.3s |  |
| 17 | `watch_recursion_double_swf6` | 4 | 3109 | 1.4s |  |
| 18 | `watch_recursion_swf6` | 1 | 1039 | 1.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**12 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.3% | 6289 | 6335 | 46 | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 99.1% | 114 | 115 | 1 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 3 | `movieclip_hittest_shapeflag` | 98.2% | 332 | 338 | 6 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 4 | `bitmap_data_thorough/pixelDissolve` | 97.4% | 1335 | 1371 | 36 | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 5 | `globals_swf5` | 96.7% | 294 | 304 | 10 | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `set_property_values/swf5` | 92.9% | 1620 | 1743 | 123 |  |
| 7 | `set_property_values/swf6` | 92.9% | 1620 | 1743 | 123 |  |
| 8 | `set_property_values/swf7` | 92.9% | 1620 | 1743 | 123 |  |
| 9 | `load_vars` | 82.9% | 29 | 35 | 6 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 10 | `hitarea_remove_sibling` | 75.0% | 3 | 4 | 1 |  |
| 11 | `geturl` | 57.1% | 4 | 7 | 3 | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 12 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**23 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.3% | 6289/6335 | 6335 | 6335 | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 99.1% | 114/115 | 115 | 115 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 3 | `movieclip_hittest_shapeflag` | 98.2% | 332/338 | 338 | 338 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 4 | `bitmap_data_thorough/pixelDissolve` | 97.4% | 1335/1371 | 1371 | 1371 | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 5 | `globals_swf5` | 96.7% | 294/304 | 304 | 304 | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `set_property_values/swf5` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 7 | `set_property_values/swf6` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 8 | `set_property_values/swf7` | 92.9% | 1620/1743 | 1743 | 1743 |  |
| 9 | `load_vars` | 82.9% | 29/35 | 30 | 35 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 10 | `hitarea_remove_sibling` | 75.0% | 3/4 | 4 | 4 |  |
| 11 | `geturl` | 57.1% | 4/7 | 4 | 7 | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 12 | `xml_getbytes` | 52.9% | 9/17 | 17 | 17 | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 13 | `globals_monkeypatch` | 38.0% | 38/100 | 96 | 100 |  |
| 14 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 15 | `hitarea_remove_owner_drag` | 30.0% | 3/10 | 10 | 10 |  |
| 16 | `set_property_values/swf4` | 20.0% | 349/1743 | 1743 | 1571 |  |
| 17 | `global_proto_decls` | 17.9% | 803/4497 | 3863 | 4497 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 18 | `global_proto_decls_delete` | 11.1% | 461/4158 | 2371 | 4158 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 19 | `global_instance_decls` | 3.3% | 26/786 | 786 | 758 | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 20 | `hitarea_sweep` | 3.0% | 1/33 | 20 | 33 |  |
| 21 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 22 | `hitarea_lazy_getter` | 0.0% | 0/6 | 3 | 6 |  |
| 23 | `loadvariables_method` | 0.0% | 0/7 | 0 | 7 | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [ASSETNATIVEACCESSOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) | 2 | 2 | 0 |
| 6 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 17 | 17 | 0 |
| 7 | [BITMAP_DATA_THOROUGH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) | 20 | 16 | 4 |
| 8 | [BITMAP_FILTER_CLONE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) | 1 | 1 | 0 |
| 9 | [BITMAP_FILTERS_MCFILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) | 1 | 1 | 0 |
| 10 | [BITMAP_FILTERS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) | 1 | 1 | 0 |
| 11 | [BITMAPDATA_APPLYFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_APPLYFILTER_PLAN.md) | 0 | 0 | 0 |
| 12 | [BITMAPDATA_PERLINNOISE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PERLINNOISE_PLAN.md) | 0 | 0 | 0 |
| 13 | [BITMAPDATA_PIXELDISSOLVE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_PIXELDISSOLVE_PLAN.md) | 0 | 0 | 0 |
| 14 | [BITMAPDATA_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) | 6 | 6 | 0 |
| 15 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 14 | 14 | 0 |
| 16 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 2 | 2 | 0 |
| 17 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 8 | 8 | 0 |
| 18 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 4 | 4 | 0 |
| 19 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 20 | [CONSTRUCT_PARAMETER_REPLAY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) | 2 | 2 | 0 |
| 21 | [COPYPIXELS_ALPHA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COPYPIXELS_ALPHA_PLAN.md) | 0 | 0 | 0 |
| 22 | [CREATETEXTFIELD_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 23 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 1 | 1 | 0 |
| 24 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 1 | 1 | 0 |
| 25 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 26 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 27 | [DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) | 1 | 1 | 0 |
| 28 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 29 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 30 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 31 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 32 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 33 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 34 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 13 | 1 |
| 35 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 36 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 37 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 3 | 3 | 0 |
| 38 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 3 | 3 | 0 |
| 39 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 40 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 41 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 42 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 43 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 44 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 6 | 1 |
| 45 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 46 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 31 | 26 | 5 |
| 47 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 17 | 16 | 1 |
| 48 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 20 | 3 |
| 49 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 50 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 51 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 52 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 53 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 54 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 44 | 4 |
| 55 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 4 | 1 |
| 56 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 3 | 1 |
| 57 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 1 | 1 | 0 |
| 58 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 59 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 60 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 61 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 62 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 58 | 56 | 2 |
| 63 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 16 | 14 | 2 |
| 64 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 15 | 2 |
| 65 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 3 | 2 | 1 |
| 66 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 2 | 2 | 0 |
| 67 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 68 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 4 | 0 |
| 69 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 70 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 71 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 72 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 73 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 74 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 75 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 4 | 2 | 2 |
| 76 | [RUNTIME_CXFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 77 | [RUNTIME_SETMASK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) | 3 | 3 | 0 |
| 78 | [RUNTIME_TRANSFORM_GPU_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) | 2 | 2 | 0 |
| 79 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 2 | 2 | 0 |
| 80 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 4 | 4 | 0 |
| 81 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 2 | 2 | 0 |
| 82 | [SOUND_DURATION_POSITION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) | 1 | 1 | 0 |
| 83 | [SOUND_ID3_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) | 2 | 2 | 0 |
| 84 | [SOUND_LOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) | 2 | 2 | 0 |
| 85 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 9 | 0 |
| 86 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 7 | 7 | 0 |
| 87 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 1 | 1 | 0 |
| 88 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 13 | 13 | 0 |
| 89 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 1 | 1 | 0 |
| 90 | [SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) | 2 | 2 | 0 |
| 91 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 5 | 5 | 0 |
| 92 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 16 | 16 | 0 |
| 93 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 1 | 1 | 0 |
| 94 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) | 19 | 19 | 0 |
| 95 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 70 | 69 | 1 |
| 96 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 4 | 4 | 0 |
| 97 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 5 | 5 | 0 |
| 98 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 1 | 1 | 0 |
| 99 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 3 | 3 | 0 |
| 100 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 101 | [TRY_CATCH_STACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) | 1 | 1 | 0 |
| 102 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) | 2 | 2 | 0 |
| 103 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 14 | 2 |
| 104 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 105 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 1 | 0 | 1 |
| 106 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 107 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 32 | 1 |
| | *(tests not in any document)* | 231 | 212 | 19 |
