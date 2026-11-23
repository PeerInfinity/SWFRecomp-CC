# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 07:07 UTC

**Git SHA**: `da9b49b17a`

**Run Duration**: 63m 33s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 781 |
| Passing | **747** (95.6%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **769** (98.5%) |
| Failing | 12 |
| Total expected lines | 137730 |
| Matching lines | 125291 (91.0%) |
| Mismatched lines | 12439 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**747 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 36.6s |  |
| 2 | `action_to_integer` | 28 | 1.5s |  |
| 3 | `add` | 28 | 1.5s |  |
| 4 | `add2` | 354 | 1.7s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 1.5s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.8s |  |
| 7 | `add_swf5` | 28 | 0.8s |  |
| 8 | `allow_networking_import_assets` | 4 | 19.1s |  |
| 9 | `allow_networking_import_assets2` | 4 | 1.4s |  |
| 10 | `amf0_array_matrix` | 50 | 1.6s |  |
| 11 | `amf0_serde_suite` | 144 | 1.9s |  |
| 12 | `amf0_utf8_probe` | 14 | 1.6s |  |
| 13 | `amf_array_indices` | 32 | 1.6s |  |
| 14 | `amf_array_serialization` | 10 | 1.6s |  |
| 15 | `amf_serialize_typed_objects` | 6 | 1.8s |  |
| 16 | `amf_sharedobject_strict_array_serialization` | 3 | 1.5s |  |
| 17 | `amf_strict_array_serialization` | 7 | 1.5s |  |
| 18 | `amf_swf6_case_insensitive_typed_objects` | 6 | 1.5s |  |
| 19 | `amf_swf6_serialize_typed_objects` | 6 | 1.5s |  |
| 20 | `amf_swf8_case_sensitive_typed_objects` | 6 | 1.5s |  |
| 21 | `arguments` | 127 | 1.5s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 22 | `array_call_method` | 9 | 1.5s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 23 | `array_concat` | 98 | 1.5s |  |
| 24 | `array_constructor` | 53 | 1.6s |  |
| 25 | `array_enumerate` | 4 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 26 | `array_length` | 42 | 1.5s |  |
| 27 | `array_properties` | 36 | 1.5s |  |
| 28 | `array_prototyping` | 12 | 8.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 29 | `array_reverse` | 226 | 1.5s |  |
| 30 | `array_shift` | 216 | 1.6s |  |
| 31 | `array_slice` | 34 | 1.5s |  |
| 32 | `array_sort` | 161 | 2.2s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 33 | `array_sort_random` | 443 | 1.6s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 34 | `array_splice` | 207 | 1.6s |  |
| 35 | `array_trivial` | 209 | 1.6s |  |
| 36 | `array_truncation_non_canonical_keys` | 37 | 1.5s |  |
| 37 | `array_unshift` | 146 | 1.5s |  |
| 38 | `as1_constructor_v6` | 35 | 1.5s |  |
| 39 | `as1_constructor_v7` | 35 | 0.8s |  |
| 40 | `as2_oop` | 13 | 1.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 41 | `as2_super_and_this_v6` | 97 | 1.8s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 42 | `as2_super_and_this_v8` | 85 | 1.5s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 43 | `as2_super_via_manual_prototype` | 40 | 1.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 44 | `as_broadcaster` | 312 | 2.2s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 45 | `as_set_prop_flags` | 79 | 1.6s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 46 | `as_set_prop_flags_version` | 31 | 1.5s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 47 | `as_set_prop_flags_version_swf5` | 1 | 1.5s |  |
| 48 | `as_set_prop_flags_version_swf6` | 1 | 1.5s |  |
| 49 | `as_set_prop_flags_version_swf7` | 1 | 0.9s |  |
| 50 | `as_set_prop_flags_version_swf8` | 1 | 1.4s |  |
| 51 | `as_set_prop_flags_version_swf9` | 1 | 0.9s |  |
| 52 | `as_setup_error` | 52 | 1.6s |  |
| 53 | `as_transformed_flag` | 20 | 1.7s |  |
| 54 | `asfunction` | 11 | 4.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 55 | `asnative` | 34 | 3.5s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 56 | `asnew` | 34 | 24.2s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 57 | `assetnative` | 81 | 2.8s |  |
| 58 | `assetnative_ids` | 10 | 2.3s |  |
| 59 | `assetnativeaccessor` | 81 | 2.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 60 | `assetnativeaccessor_ids` | 21 | 2.4s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 61 | `attach_movie` | 59 | 2.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 62 | `attach_movie_stop` | 3 | 2.4s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 63 | `bad_placeobject_clipaction` | 2 | 2.4s |  |
| 64 | `bad_swf_tag_past_eof` | 0 | 2.2s |  |
| 65 | `bitand` | 1058 | 5.4s |  |
| 66 | `bitmap_data` | 1126 | 5.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 67 | `bitmap_data_colortransform` | 0 | 3.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 68 | `bitmap_data_compare` | 40 | 2.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 69 | `bitmap_data_copypixels` | 17 | 26.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 70 | `bitmap_data_draw_cliprect` | 13 | 2.6s |  |
| 71 | `bitmap_data_draw_return_value` | 9 | 2.7s |  |
| 72 | `bitmap_data_draw_string_target` | 40 | 2.4s |  |
| 73 | `bitmap_data_fillrect` | 0 | 2.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 74 | `bitmap_data_hittest` | 132 | 3.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 75 | `bitmap_data_max_size_swf10` | 12 | 2.4s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 76 | `bitmap_data_max_size_swf9` | 10 | 2.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 77 | `bitmap_data_noise` | 631 | 2.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 78 | `bitmap_data_perlinnoise` | 0 | 22.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 79 | `bitmap_data_pixeldissolve` | 1075 | 3.7s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 80 | `bitmap_data_pixeldissolve_image` | 0 | 22.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 81 | `bitmap_data_thorough/colorTransform` | 279 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 82 | `bitmap_data_thorough/compare` | 69 | 3.1s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 83 | `bitmap_data_thorough/constructor` | 313 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 84 | `bitmap_data_thorough/copyChannel` | 2715 | 2.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 85 | `bitmap_data_thorough/fillRect` | 342 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 86 | `bitmap_data_thorough/floodFill` | 867 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 87 | `bitmap_data_thorough/getColorBoundsRect` | 285 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 88 | `bitmap_data_thorough/getPixel` | 141 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 89 | `bitmap_data_thorough/getPixel32` | 141 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 90 | `bitmap_data_thorough/hitTest` | 519 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 91 | `bitmap_data_thorough/merge` | 1203 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 92 | `bitmap_data_thorough/noise` | 1518 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 93 | `bitmap_data_thorough/scroll` | 384 | 2.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 94 | `bitmap_data_thorough/setPixel` | 531 | 2.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 95 | `bitmap_data_thorough/setPixel32` | 531 | 2.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 96 | `bitmap_data_thorough/threshold` | 1308 | 2.8s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 97 | `bitmap_data_threshold` | 176 | 2.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 98 | `bitmap_filters` | 548 | 4.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 99 | `bitmapdata_applyfilter_colormatrix` | 0 | 23.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 100 | `bitmapdata_channels` | 19 | 1.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 101 | `bitmapdata_copypixels_self` | 612 | 2.0s |  |
| 102 | `bitmapdata_hittest_default_threshold` | 4 | 3.8s |  |
| 103 | `bitmapdata_hittest_threshold` | 6 | 1.9s |  |
| 104 | `bitor` | 1058 | 4.4s |  |
| 105 | `biturshift` | 14 | 1.8s |  |
| 106 | `biturshift_swf8` | 14 | 1.6s |  |
| 107 | `bitxor` | 1058 | 4.4s |  |
| 108 | `boxed_primitives` | 24 | 2.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 109 | `button_children` | 8 | 2.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 110 | `button_goto` | 4 | 2.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 111 | `button_key_events` | 14 | 2.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 112 | `button_key_events_special` | 45 | 4.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 113 | `button_keypress` | 3 | 2.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 114 | `button_keypress_vs_press` | 25 | 2.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 115 | `button_keypress_vs_tab` | 20 | 2.5s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 116 | `button_keypress_vs_textinput` | 4 | 2.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 117 | `button_order` | 2 | 1.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 118 | `button_properties_special_cases` | 22 | 19.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 119 | `button_v5` | 18 | 1.8s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 120 | `button_v6` | 18 | 1.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 121 | `call` | 62 | 19.5s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 122 | `call_method_empty_name` | 1 | 1.8s |  |
| 123 | `capabilities_resolution` | 8 | 19.3s |  |
| 124 | `catch_references_registers` | 2 | 36.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 125 | `click_block` | 5 | 24.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 126 | `clip_constructors` | 8 | 2.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 127 | `clip_event_propagation_order` | 17 | 23.8s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 128 | `clip_events` | 19 | 24.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 129 | `clone_sprite_edittext` | 94 | 2.7s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 130 | `clone_sprite_edittext_dynamic` | 86 | 2.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 131 | `clone_sprite_types` | 24 | 2.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 132 | `closure_scope` | 7 | 23.9s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 133 | `coerce_to_object_monkeypatch` | 129 | 24.1s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 134 | `coerce_to_primitive_resolve` | 22 | 2.1s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 135 | `color` | 57 | 6.8s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 136 | `color_transform` | 48 | 2.1s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 137 | `conflicting_instance_names` | 23 | 23.8s |  |
| 138 | `constructor_function` | 2 | 1.9s |  |
| 139 | `context_menu` | 128 | 2.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 140 | `context_menu_item` | 96 | 2.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 141 | `context_menu_swf6` | 14 | 2.0s |  |
| 142 | `create_empty_movie_clip` | 3 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 143 | `cross_movie_root` | 10 | 23.7s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 144 | `custom_clip_methods` | 4 | 2.2s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 145 | `default_names` | 52 | 2.3s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 146 | `define_font_glyph_table_order` | 0 | 57.3s |  |
| 147 | `define_font_glyph_table_overlap` | 0 | 1.1s |  |
| 148 | `define_function2` | 8 | 1.9s |  |
| 149 | `define_function2_preload` | 13 | 4.3s |  |
| 150 | `define_function2_preload_order` | 4 | 1.7s |  |
| 151 | `define_function_case_sensitive` | 2 | 1.5s |  |
| 152 | `define_local` | 27 | 1.5s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 153 | `define_local_with_paths` | 54 | 1.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 154 | `delete` | 3 | 1.7s |  |
| 155 | `delete2` | 74 | 1.6s |  |
| 156 | `depth_replacement_audio_unloading` | 3 | 1.8s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) |
| 157 | `device_font_spacing` | 91 | 19.7s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 158 | `displacementmapfilter_mappoint_throw_error` | 13 | 1.6s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 159 | `display_object_properties` | 2 | 1.7s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 160 | `divide_swf4` | 107 | 1.5s |  |
| 161 | `do_init_action` | 3 | 1.6s |  |
| 162 | `do_init_action_child` | 12 | 1.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 163 | `drag_drop` | 10 | 1.6s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 164 | `drag_over_from_outside` | 1 | 1.6s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 165 | `drag_over_without_startdrag` | 1 | 1.7s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 166 | `duplicate_movie_clip` | 20 | 1.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 167 | `duplicate_movie_clip_drawing` | 2 | 1.5s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 168 | `edittext_align` | 60 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 169 | `edittext_align_trailing_spaces_swf7` | 576 | 19.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 170 | `edittext_align_trailing_spaces_swf8` | 576 | 0.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 171 | `edittext_antialiastype` | 296 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 172 | `edittext_asfunction_case_insensitive` | 1 | 1.5s |  |
| 173 | `edittext_autosize` | 71 | 1.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 174 | `edittext_autosize_setter` | 20 | 1.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 175 | `edittext_bullet` | 30 | 7.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 176 | `edittext_default_format` | 221 | 3.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 177 | `edittext_default_format_empty` | 100 | 2.0s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 178 | `edittext_default_format_font_style` | 335 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 179 | `edittext_drag_select` | 9 | 23.9s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 180 | `edittext_focus_selection` | 2 | 2.0s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 181 | `edittext_font_size` | 45 | 3.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 182 | `edittext_hscroll` | 27 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 183 | `edittext_html_align_swf7` | 52 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 184 | `edittext_html_align_swf8` | 52 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 185 | `edittext_html_color` | 114 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 186 | `edittext_html_condensewhite_swf7` | 311 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 187 | `edittext_html_condensewhite_swf8` | 311 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 188 | `edittext_html_duplicate_attributes` | 247 | 2.2s |  |
| 189 | `edittext_html_entity` | 4 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 190 | `edittext_html_roundtrip` | 17 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 191 | `edittext_html_swf6` | 5377 | 3.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 192 | `edittext_html_swf7` | 5377 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 193 | `edittext_html_swf8` | 5377 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 194 | `edittext_ime_focus_lost` | 7 | 23.5s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 195 | `edittext_input` | 1 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 196 | `edittext_input_newlines` | 9 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 197 | `edittext_leading` | 9 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 198 | `edittext_letter_spacing` | 15 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 199 | `edittext_margins` | 25 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 200 | `edittext_newline_stripping` | 64 | 7.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 201 | `edittext_newlines` | 30 | 9.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 202 | `edittext_password` | 5 | 2.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 203 | `edittext_password_copy` | 4 | 19.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 204 | `edittext_paste_empty` | 2 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 205 | `edittext_place_caret` | 2 | 20.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 206 | `edittext_programmatic_focus` | 12 | 1.9s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 207 | `edittext_restrict` | 191 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 208 | `edittext_restrict_paste` | 5 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 209 | `edittext_scroll` | 54 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 210 | `edittext_set_text_same` | 70 | 2.5s |  |
| 211 | `edittext_set_text_same_after_edits` | 98 | 2.2s |  |
| 212 | `edittext_stylesheet` | 325 | 3.4s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 213 | `edittext_tab_focus` | 13 | 2.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 214 | `edittext_tab_stops` | 60 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 215 | `edittext_tag_indent` | 31 | 21.0s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 216 | `edittext_text_height_leading` | 20 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 217 | `edittext_underline` | 40 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 218 | `edittext_width_height` | 103 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 219 | `empty_movieclip_can_attach_movies` | 11 | 2.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 220 | `enumerate` | 64 | 2.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 221 | `equals` | 32 | 2.1s |  |
| 222 | `equals2_swf5` | 926 | 3.7s |  |
| 223 | `equals2_swf6` | 926 | 1.1s |  |
| 224 | `equals2_swf7` | 926 | 1.1s |  |
| 225 | `equals_swf4` | 665 | 2.9s |  |
| 226 | `equals_swf4_alt` | 32 | 43.7s |  |
| 227 | `equals_swf5` | 32 | 1.2s |  |
| 228 | `error` | 58 | 2.3s |  |
| 229 | `escape` | 14 | 2.2s |  |
| 230 | `execution_order1` | 5 | 24.7s |  |
| 231 | `execution_order2` | 7 | 24.4s |  |
| 232 | `execution_order3` | 4 | 2.4s |  |
| 233 | `execution_order4` | 12 | 2.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 234 | `export_assets` | 3 | 2.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 235 | `extends_chain` | 134 | 3.0s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 236 | `extends_native_type` | 11 | 2.4s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 237 | `external_interface` | 84 | 2.5s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 238 | `external_interface_escapexml` | 26 | 2.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 239 | `external_interface_jsquotestring` | 21 | 2.3s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 240 | `external_interface_toas_basic` | 354 | 2.7s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 241 | `external_interface_toxml_array` | 25 | 2.3s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 242 | `external_interface_toxml_basic` | 179 | 2.5s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 243 | `external_interface_unescapexml` | 40 | 2.4s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 244 | `file_reference_browse_cancel` | 21 | 2.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 245 | `file_reference_download_cancel` | 7 | 2.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 246 | `file_reference_download_httperror_dns_error` | 13 | 2.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 247 | `file_reference_download_httperror_status_code` | 23 | 2.2s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 248 | `file_reference_download_success` | 34 | 2.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 249 | `file_reference_list_asbroadcaster` | 9 | 2.3s |  |
| 250 | `file_reference_list_browse_cancel` | 4 | 2.2s |  |
| 251 | `file_reference_list_browse_invalid_filters` | 36 | 7.2s |  |
| 252 | `file_reference_list_browse_select` | 7 | 1.5s |  |
| 253 | `file_reference_listeners_per_instance` | 20 | 1.6s |  |
| 254 | `file_reference_upload_httperror_dns_error` | 18 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 255 | `file_reference_upload_httperror_status_code` | 23 | 1.5s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 256 | `file_reference_upload_request` | 158 | 19.7s |  |
| 257 | `file_reference_upload_success` | 23 | 1.5s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 258 | `focus_keyboard_press` | 60 | 2.3s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 259 | `focus_mouse` | 45 | 1.7s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 260 | `focus_mouse_focusable` | 8 | 19.2s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 261 | `focus_mouse_rollout` | 4 | 1.7s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 262 | `focus_remove` | 33 | 18.7s |  |
| 263 | `focus_root_movie` | 2 | 1.6s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 264 | `focus_visibility_change` | 45 | 1.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 265 | `focusrect_focuslost` | 4 | 1.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 266 | `focusrect_mouse_swf8` | 0 | 1.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 267 | `focusrect_mouse_swf9` | 0 | 1.0s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 268 | `focusrect_property_swf5` | 1237 | 2.0s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 269 | `focusrect_property_swf6` | 1237 | 1.4s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 270 | `focusrect_property_swf7` | 1237 | 0.9s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 271 | `focusrect_swf5` | 6 | 19.3s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 272 | `focusrect_swf6` | 42 | 1.8s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 273 | `form_loader_encoding_1` | 1 | 1.5s |  |
| 274 | `form_loader_encoding_2` | 3 | 1.6s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 275 | `form_loader_encoding_3` | 3 | 1.5s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 276 | `frame_size_translated_negative` | 21 | 32.7s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 277 | `frame_size_translated_positive` | 21 | 25.1s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 278 | `function_as_function` | 35 | 2.4s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 279 | `function_base_clip` | 8 | 2.5s |  |
| 280 | `function_base_clip_readded` | 11 | 25.4s |  |
| 281 | `function_base_clip_removed` | 25 | 2.7s |  |
| 282 | `function_suppress_and_preload` | 28 | 2.5s |  |
| 283 | `funky_function_calls` | 56 | 2.5s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 284 | `get_bytes_total` | 4 | 26.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 285 | `get_variable_in_scope` | 29 | 2.4s |  |
| 286 | `getproperty` | 28 | 2.4s |  |
| 287 | `getproperty_swf4` | 28 | 1.3s |  |
| 288 | `getproperty_swf5` | 28 | 1.2s |  |
| 289 | `gettextextent` | 56 | 3.0s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 290 | `geturl` | 7 | 26.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 291 | `geturl_opcode_target_normalize` | 45 | 25.5s |  |
| 292 | `geturl_target_normalize` | 89 | 25.4s |  |
| 293 | `global_array` | 3 | 2.3s |  |
| 294 | `global_is_bare` | 7 | 2.3s |  |
| 295 | `global_swf5_6_7_8_9` | 1145 | 3.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 296 | `global_swf6_7_8` | 15 | 2.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 297 | `globals_swf6` | 304 | 5.8s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 298 | `globals_swf7` | 304 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 299 | `globals_swf8` | 304 | 2.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 300 | `goto_advance1` | 6 | 1.8s |  |
| 301 | `goto_advance2` | 2 | 1.7s |  |
| 302 | `goto_both_ways1` | 3 | 1.8s |  |
| 303 | `goto_both_ways2` | 3 | 19.4s |  |
| 304 | `goto_execution_order` | 2 | 1.6s |  |
| 305 | `goto_execution_order2` | 2 | 1.8s |  |
| 306 | `goto_frame` | 12 | 2.0s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 307 | `goto_frame2` | 44 | 20.1s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 308 | `goto_frame_number` | 3 | 19.3s |  |
| 309 | `goto_label` | 17 | 18.9s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 310 | `goto_methods` | 40 | 1.7s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 311 | `goto_rewind1` | 1 | 1.5s |  |
| 312 | `goto_rewind2` | 3 | 1.6s |  |
| 313 | `goto_rewind3` | 2 | 1.6s |  |
| 314 | `greater_swf6` | 1175 | 3.2s |  |
| 315 | `greater_swf7` | 1175 | 1.0s |  |
| 316 | `greaterthan_swf5` | 1 | 1.5s |  |
| 317 | `greaterthan_swf8` | 1 | 1.4s |  |
| 318 | `has_own_property` | 32 | 1.5s |  |
| 319 | `hitarea_lazy_getter` | 6 | 1.6s |  |
| 320 | `hitarea_remove_owner_drag` | 10 | 1.6s |  |
| 321 | `hitarea_remove_sibling` | 4 | 1.6s |  |
| 322 | `hitarea_sweep` | 33 | 26.5s |  |
| 323 | `hittest_lockroot` | 15 | 1.7s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 324 | `hittest_morph` | 70 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 325 | `hittest_morph_input` | 1 | 1.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 326 | `hittest_winding_rule` | 12 | 1.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 327 | `html_text_img_numeric_attributes` | 3 | 1.5s |  |
| 328 | `html_text_img_parsing_swf5` | 517 | 1.7s |  |
| 329 | `html_text_img_parsing_swf6` | 517 | 0.9s |  |
| 330 | `html_text_img_parsing_swf7` | 517 | 1.8s |  |
| 331 | `html_text_img_parsing_swf8` | 517 | 0.9s |  |
| 332 | `infinite_recursion_function` | 4 | 1.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 333 | `infinite_recursion_function_in_setter` | 131 | 1.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 334 | `infinite_recursion_virtual_property` | 67 | 1.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 335 | `init_array_invalid` | 4 | 18.3s |  |
| 336 | `init_object_invalid` | 4 | 0.6s |  |
| 337 | `init_object_order` | 15 | 1.6s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 338 | `input_dead_keys_windows` | 15 | 1.7s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 339 | `instanceof_coercions` | 88 | 1.8s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 340 | `interface_implements_op` | 47 | 2.0s | [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 341 | `is_finite` | 49 | 1.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 342 | `is_finite_swf6` | 49 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 343 | `is_prototype_of` | 89 | 1.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 344 | `issue_1086` | 1 | 1.4s |  |
| 345 | `issue_1104` | 2 | 1.4s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 346 | `issue_1671` | 0 | 1.4s |  |
| 347 | `issue_1906` | 4 | 1.5s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 348 | `issue_2030` | 4 | 8.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 349 | `issue_2084` | 16 | 19.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 350 | `issue_2166` | 9 | 1.5s |  |
| 351 | `issue_2870` | 3 | 1.9s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 352 | `issue_3169` | 2 | 1.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 353 | `issue_3446` | 1 | 1.5s |  |
| 354 | `issue_3522` | 2 | 1.9s |  |
| 355 | `issue_4377` | 2 | 1.5s |  |
| 356 | `issue_710` | 4 | 1.5s |  |
| 357 | `issue_768` | 3 | 1.5s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 358 | `issue_9327` | 2 | 1.6s |  |
| 359 | `issue_9885` | 2 | 1.6s |  |
| 360 | `key_isToggled` | 9 | 1.5s |  |
| 361 | `lazy_prototype_shared` | 8 | 1.6s |  |
| 362 | `lessthan` | 41 | 1.6s |  |
| 363 | `lessthan2_swf5` | 1226 | 3.3s |  |
| 364 | `lessthan2_swf6` | 1226 | 0.8s |  |
| 365 | `lessthan2_swf7` | 1226 | 0.8s |  |
| 366 | `lessthan_swf4` | 902 | 2.6s |  |
| 367 | `lessthan_swf4_alt` | 41 | 0.8s |  |
| 368 | `lessthan_swf5` | 41 | 0.8s |  |
| 369 | `load_cancel_via_removemovieclip` | 4 | 1.6s |  |
| 370 | `load_vars` | 35 | 1.6s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 371 | `loadmovie` | 2 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 372 | `loadmovie_fail` | 2 | 6.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 373 | `loadmovie_flashvars` | 4 | 2.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 374 | `loadmovie_method` | 2 | 2.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 375 | `loadmovie_registerclass` | 30 | 2.7s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 376 | `loadmovie_replace_root` | 5 | 2.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 377 | `loadmovie_var_persistence` | 8 | 2.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 378 | `loadmovienum` | 3 | 2.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 379 | `loadmovienum_cross_version_prototype` | 9 | 2.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 380 | `loadvariables` | 2 | 2.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 381 | `loadvariables2` | 8 | 26.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 382 | `loadvariables_method` | 7 | 26.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 383 | `loadvariablesnum` | 2 | 2.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 384 | `loadvars_tostring` | 5 | 2.4s |  |
| 385 | `local_to_global` | 49 | 2.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 386 | `localconnection` | 579 | 3.8s | [57](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 387 | `localconnection_properties` | 8 | 2.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 388 | `localconnection_reference_identity` | 5 | 2.4s |  |
| 389 | `localconnection_serialize_function_array_elements` | 20 | 2.4s |  |
| 390 | `localconnection_serialize_inherited_array_indices` | 12 | 2.4s |  |
| 391 | `localconnection_serialize_sparse_array_getters` | 26 | 2.5s |  |
| 392 | `localconnection_serialize_undefined_array_elements` | 24 | 2.4s |  |
| 393 | `localconnection_top_level` | 7 | 24.7s |  |
| 394 | `localconnection_xml` | 14 | 2.4s |  |
| 395 | `localconnection_xml_unavailable` | 23 | 2.5s |  |
| 396 | `lock_root` | 1 | 2.4s |  |
| 397 | `logical_ops_swf4` | 90 | 2.4s |  |
| 398 | `logical_ops_swf8` | 108 | 28.8s |  |
| 399 | `looping` | 6 | 16.7s |  |
| 400 | `looping_child_swf32` | 141 | 17.4s |  |
| 401 | `looping_child_swf5` | 141 | 2.2s |  |
| 402 | `looping_child_swf9` | 141 | 1.1s |  |
| 403 | `looping_real_1_declared_1` | 1 | 1.6s |  |
| 404 | `looping_real_1_declared_2` | 1 | 0.9s |  |
| 405 | `looping_real_2_declared_1` | 5 | 1.7s |  |
| 406 | `looping_real_2_declared_2` | 5 | 0.8s |  |
| 407 | `mask_reapply` | 0 | 19.9s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 408 | `mask_with_drawing` | 0 | 17.5s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 409 | `math_min_max` | 101 | 1.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 410 | `math_swf6` | 530 | 17.9s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 411 | `math_swf7` | 530 | 1.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 412 | `math_swf8` | 530 | 1.0s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 413 | `matrix` | 810 | 2.9s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 414 | `mcl_as_broadcaster` | 12 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 415 | `mcl_events_swf_version` | 232 | 2.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 416 | `mcl_getprogress` | 30 | 17.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 417 | `mcl_loadclip` | 149 | 17.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 418 | `mcl_loadclip_properties` | 6 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 419 | `mcl_loadclip_replace_root` | 1 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 420 | `mcl_mislabeled_target` | 6 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 421 | `mcl_target_gif87a` | 6 | 5.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 422 | `mcl_target_gif89a` | 6 | 4.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 423 | `mcl_target_jpg` | 6 | 1.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 424 | `mcl_target_png` | 6 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 425 | `mcl_unloadclip` | 5 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 426 | `mouse_events` | 8 | 20.5s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 427 | `mouse_events_visible_enabled` | 12 | 3.3s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 428 | `mouse_hover_events_while_dragging` | 1 | 1.8s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 429 | `mouse_listeners` | 67 | 1.7s |  |
| 430 | `mouse_pos` | 665 | 20.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 431 | `mouse_pos_with_scale_factor` | 260 | 20.0s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 432 | `mouse_wheel_enabled` | 2 | 1.8s |  |
| 433 | `movieclip_begin_gradient_fill` | 0 | 20.7s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 434 | `movieclip_blend_mode_property` | 35 | 2.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 435 | `movieclip_create_text_field` | 90 | 20.4s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 436 | `movieclip_default_state` | 69 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 437 | `movieclip_depth_methods` | 98 | 1.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 438 | `movieclip_focusenabled` | 99 | 1.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 439 | `movieclip_get_instance_at_depth` | 28 | 1.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 440 | `movieclip_getbounds` | 191 | 1.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 441 | `movieclip_gettextsnapshot` | 112 | 1.9s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 442 | `movieclip_hittest` | 92 | 1.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 443 | `movieclip_in_removed_button` | 4 | 20.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 444 | `movieclip_init_object` | 5 | 1.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 445 | `movieclip_invalid_get_bounds_1` | 75 | 2.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 446 | `movieclip_invalid_get_bounds_2` | 75 | 1.9s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 447 | `movieclip_invalid_get_bounds_3` | 13 | 6.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 448 | `movieclip_invalid_get_bounds_4` | 13 | 1.7s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 449 | `movieclip_invalid_get_bounds_5` | 11 | 1.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 450 | `movieclip_invalid_get_bounds_6` | 10 | 21.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 451 | `movieclip_invalid_get_bounds_7` | 10 | 21.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 452 | `movieclip_invalid_get_bounds_8` | 11 | 1.7s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 453 | `movieclip_line_gradient_style` | 0 | 19.4s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 454 | `movieclip_lockroot` | 29 | 1.8s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 455 | `movieclip_methods_with_loaded_image` | 4 | 19.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 456 | `movieclip_name_from_timeline` | 13 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 457 | `movieclip_onconstruct` | 20 | 1.6s |  |
| 458 | `movieclip_prototype_extension` | 5 | 1.4s |  |
| 459 | `movieclip_setmask` | 14 | 19.4s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 460 | `movieclip_state_values` | 114 | 2.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 461 | `moviecliploader_flashvars` | 4 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 462 | `mutable_this` | 18 | 1.5s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 463 | `named_shapes` | 14 | 19.2s |  |
| 464 | `nan_scale` | 9 | 1.6s |  |
| 465 | `native_double_construct` | 12 | 1.6s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 466 | `native_objects_swf7` | 115 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 467 | `native_objects_swf8` | 115 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 468 | `native_subclasses` | 191 | 1.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 469 | `nested_textfields_in_buttons` | 0 | 1.8s |  |
| 470 | `netconnection_close` | 39 | 1.5s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 471 | `netconnection_deserialize_strict_array_undefined` | 17 | 31.6s |  |
| 472 | `netconnection_send_remote` | 50 | 2.8s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 473 | `netconnection_serialize_arrays` | 6 | 2.4s |  |
| 474 | `netstream_play_flv` | 21 | 3.5s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 475 | `netstream_play_flv_screen` | 0 | 42.5s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 476 | `netstream_seek_flv` | 25 | 26.1s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 477 | `new_class_prototype_getter` | 6 | 2.4s |  |
| 478 | `new_method_wrap` | 4 | 25.2s |  |
| 479 | `new_object_enumerate` | 7 | 2.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 480 | `new_object_wrap` | 4 | 2.3s |  |
| 481 | `o` | 3 | 2.3s |  |
| 482 | `object_constructor` | 33 | 2.4s |  |
| 483 | `object_function` | 32 | 2.3s |  |
| 484 | `object_properties` | 31 | 2.5s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 485 | `object_prototypes` | 74 | 2.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 486 | `object_resolve` | 38 | 2.5s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 487 | `object_string_coerce_swf5` | 62 | 2.4s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 488 | `object_string_coerce_swf6` | 68 | 2.4s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 489 | `on_construct` | 25 | 2.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 490 | `parse_float` | 74 | 2.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 491 | `parse_int` | 64 | 25.4s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 492 | `path_string` | 301 | 2.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 493 | `place_and_lookup` | 30 | 2.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 494 | `placeobject_all_event_flags` | 10 | 2.9s |  |
| 495 | `placeobject_occupied_depth` | 6 | 2.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 496 | `point` | 329 | 3.4s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 497 | `primitive_instanceof` | 37 | 8.0s |  |
| 498 | `primitive_type_globals` | 557 | 1.6s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 499 | `printjob_props_swf5` | 45 | 1.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 500 | `printjob_props_swf6` | 45 | 1.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 501 | `printjob_props_swf7` | 45 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 502 | `property_invalid_base_clip` | 35 | 1.5s |  |
| 503 | `prototype_delete` | 12 | 1.5s |  |
| 504 | `prototype_enumerate` | 5 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 505 | `prototype_properties` | 17 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 506 | `rectangle` | 629 | 2.7s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 507 | `recursive_prototypes` | 0 | 1.4s |  |
| 508 | `register_and_init_order` | 231 | 2.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 509 | `register_class` | 66 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 510 | `register_class_return_value` | 16 | 1.6s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 511 | `register_class_swf6` | 37 | 1.7s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 512 | `register_class_with_sound` | 11 | 1.6s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 513 | `register_globals_across_frames` | 15 | 1.5s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 514 | `register_underflow` | 26 | 1.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 515 | `remove_different_level` | 3 | 1.5s |  |
| 516 | `remove_movie_clip` | 29 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 517 | `removed_base_clip_tell_target` | 1 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 518 | `removed_clip_function_scope` | 12 | 1.6s |  |
| 519 | `removed_clip_halts_script` | 15 | 19.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 520 | `removed_target_clip_scope` | 35 | 1.6s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 521 | `resolve_different_root` | 2 | 1.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 522 | `rewind_depth` | 30 | 18.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 523 | `root_button_mode` | 10 | 38.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 524 | `root_global_parent` | 6 | 24.5s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 525 | `root_onload` | 1 | 24.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 526 | `sandbox_type_local_file` | 1 | 24.3s |  |
| 527 | `sandbox_type_local_network` | 1 | 2.0s |  |
| 528 | `selection` | 454 | 3.0s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 529 | `selection_asbroadcaster` | 9 | 2.3s |  |
| 530 | `selection_handlers` | 27 | 2.4s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 531 | `set_interval` | 27 | 2.4s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 532 | `set_property_values/swf5` | 1743 | 1.3s |  |
| 533 | `set_property_values/swf6` | 1743 | 1.3s |  |
| 534 | `set_property_values/swf7` | 1743 | 1.3s |  |
| 535 | `set_target_2_swf5` | 13 | 2.5s |  |
| 536 | `set_target_2_swf6` | 13 | 2.3s |  |
| 537 | `set_target_2_swf7` | 13 | 1.1s |  |
| 538 | `set_variable_scope` | 58 | 2.3s |  |
| 539 | `shared_object_members_swf5` | 32 | 2.3s |  |
| 540 | `shared_object_secure` | 20 | 2.4s |  |
| 541 | `shared_object_serialize_typed_objects` | 1 | 2.4s |  |
| 542 | `shared_stack` | 16 | 24.7s |  |
| 543 | `single_frame` | 1 | 2.2s |  |
| 544 | `slash_syntax` | 14 | 2.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 545 | `sound` | 628 | 2.6s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 546 | `sound_duration_position_props` | 290 | 2.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 547 | `sound_getters` | 99 | 38.8s |  |
| 548 | `sound_gettransform_props` | 4 | 2.2s |  |
| 549 | `sound_id3` | 633 | 2.5s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 550 | `sound_id3_prop` | 138 | 2.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 551 | `sound_load_multiple_instances` | 19 | 25.2s |  |
| 552 | `sound_load_multiple_remote` | 6 | 2.3s |  |
| 553 | `sound_load_props` | 111 | 2.4s |  |
| 554 | `sound_load_start` | 6 | 2.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 555 | `sound_load_start_remote` | 1 | 2.3s |  |
| 556 | `sound_load_stops_when_dereferenced` | 0 | 24.6s |  |
| 557 | `sound_load_streaming_stop_remote` | 3 | 2.2s |  |
| 558 | `sound_mixed_attach_load` | 13 | 25.4s |  |
| 559 | `sound_multiple_load` | 1 | 2.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 560 | `sound_nested_clips` | 10 | 2.4s |  |
| 561 | `sound_owner_reference` | 12 | 2.3s |  |
| 562 | `sound_owner_tostring_fail` | 9 | 2.3s |  |
| 563 | `sound_props_swf5` | 68 | 2.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 564 | `sound_props_swf6` | 68 | 2.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 565 | `sound_setters` | 43 | 2.4s |  |
| 566 | `sound_start_load` | 0 | 2.3s |  |
| 567 | `sound_start_stop` | 44 | 24.6s |  |
| 568 | `sparse_array_truncation_non_canonical_keys` | 43 | 2.6s |  |
| 569 | `stage_display_state` | 16 | 2.2s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 570 | `stage_object_children` | 83 | 2.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 571 | `stage_object_enumerate` | 4 | 2.3s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 572 | `stage_object_properties` | 241 | 25.0s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 573 | `stage_object_properties_get_var` | 5 | 9.0s |  |
| 574 | `stage_object_properties_swf6` | 231 | 2.0s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 575 | `stage_property_representation` | 586 | 1.5s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 576 | `stage_scale_mode` | 39 | 18.9s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 577 | `strictequals_swf6` | 902 | 2.8s |  |
| 578 | `strictly_equals` | 7 | 1.5s |  |
| 579 | `string_coercion` | 117 | 1.8s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 580 | `string_methods` | 285 | 1.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 581 | `string_methods_negative_args` | 240 | 1.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 582 | `string_methods_swfv5` | 275 | 2.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 583 | `string_ops_swf6` | 95 | 1.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 584 | `string_paths_basic` | 4 | 1.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 585 | `string_paths_eval` | 4 | 1.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 586 | `string_paths_eval2` | 7 | 1.7s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 587 | `string_paths_hidden` | 54 | 1.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 588 | `string_paths_keyevents` | 0 | 1.5s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 589 | `string_paths_other` | 36 | 1.6s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 590 | `string_paths_reference_launder` | 2 | 1.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 591 | `string_paths_timer` | 0 | 1.4s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 592 | `string_paths_unload` | 1 | 1.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 593 | `string_paths_variable_alias` | 4 | 1.4s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 594 | `string_paths_variable_scopes` | 5 | 1.5s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 595 | `string_relational_compare` | 4 | 1.5s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) |
| 596 | `stylesheet` | 283 | 2.2s |  |
| 597 | `stylesheet_load` | 49 | 1.7s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 598 | `stylesheet_transform` | 750 | 2.1s |  |
| 599 | `super_edge_cases` | 39 | 7.4s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 600 | `swf4_actions_bool` | 96 | 1.5s |  |
| 601 | `swf4_actions_coercion_order` | 157 | 1.6s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 602 | `swf4_bool` | 4 | 1.4s |  |
| 603 | `swf4_function_calls` | 7 | 1.4s |  |
| 604 | `swf4_vars` | 25 | 1.5s |  |
| 605 | `swf5_encoding` | 3 | 1.4s |  |
| 606 | `swf5_global_funcs` | 232 | 1.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 607 | `swf5_no_closure` | 19 | 1.6s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 608 | `swf5_to_6_cross_call` | 29 | 1.6s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 609 | `swf5_xml_event_handler_context` | 2 | 1.6s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 610 | `swf6_case_insensitive` | 42 | 1.5s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 611 | `swf6_global_funcs` | 232 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 612 | `swf6_string_as_bool` | 15 | 1.5s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 613 | `swf6_to_5_cross_call` | 29 | 1.5s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 614 | `swf7_case_sensitive` | 44 | 0.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 615 | `swf7_global_funcs` | 232 | 0.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 616 | `tab_ordering_automatic_basic` | 92 | 1.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 617 | `tab_ordering_automatic_order_grid` | 21 | 1.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 618 | `tab_ordering_automatic_order_same_position` | 12 | 1.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 619 | `tab_ordering_children` | 208 | 1.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 620 | `tab_ordering_custom_basic` | 71 | 1.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 621 | `tab_ordering_custom_duplicate_index` | 22 | 1.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 622 | `tab_ordering_custom_i32_vs_u32` | 12 | 1.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 623 | `tab_ordering_custom_m1` | 29 | 1.5s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 624 | `tab_ordering_events` | 150 | 2.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 625 | `tab_ordering_events_mouse` | 65 | 8.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 626 | `tab_ordering_movieclip_enabled_default` | 462 | 1.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 627 | `tab_ordering_properties` | 293 | 1.7s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 628 | `tab_ordering_reverse` | 51 | 1.7s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 629 | `tab_ordering_tabbable` | 47 | 1.9s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 630 | `target_clip_removed` | 5 | 1.6s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 631 | `target_clip_swf5` | 2 | 1.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 632 | `target_clip_swf6` | 2 | 1.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 633 | `target_path` | 14 | 1.5s |  |
| 634 | `target_paths/swf4` | 818 | 2.8s |  |
| 635 | `tell_target` | 34 | 1.7s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 636 | `tell_target_invalid` | 5 | 18.6s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 637 | `tell_target_invalid_swf6` | 4 | 0.8s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 638 | `text_blocks_clicks` | 4 | 1.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 639 | `text_format` | 1146 | 1.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 640 | `text_format_display` | 21 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 641 | `text_format_font_max_length` | 2 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 642 | `text_format_get_text_extent_own` | 19 | 1.6s |  |
| 643 | `text_format_get_text_extent_undefined_width` | 10 | 1.5s |  |
| 644 | `text_format_prototype_lazy` | 35 | 1.7s |  |
| 645 | `text_format_rounding_swf7` | 840 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 646 | `text_format_rounding_swf8` | 840 | 0.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 647 | `textfield_asbroadcaster` | 14 | 1.5s |  |
| 648 | `textfield_background_color` | 11 | 5.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 649 | `textfield_border_color` | 11 | 3.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 650 | `textfield_cache_as_bitmap` | 1 | 2.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 651 | `textfield_get_text_format_args` | 269 | 2.6s |  |
| 652 | `textfield_maxchars` | 3 | 1.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 653 | `textfield_properties` | 44 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 654 | `textfield_props_swf6` | 210 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 655 | `textfield_props_swf7` | 210 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 656 | `textfield_props_swf8` | 210 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 657 | `textfield_set_text_format_args` | 232 | 2.5s |  |
| 658 | `textfield_set_text_format_text_change` | 37 | 2.3s |  |
| 659 | `textfield_text` | 7 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 660 | `textfield_variable` | 81 | 20.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 661 | `textsnapshot_available_text` | 20 | 2.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 662 | `textsnapshot_findtext` | 44 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 663 | `textsnapshot_gettext` | 55 | 2.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 664 | `textsnapshot_props_swf5` | 56 | 2.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 665 | `textsnapshot_props_swf6` | 56 | 1.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 666 | `textsnapshot_text_order` | 1 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 667 | `this_scoping` | 52 | 2.3s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 668 | `this_swf5` | 41 | 2.0s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 669 | `this_swf6` | 41 | 1.9s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 670 | `this_swf7` | 41 | 1.0s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 671 | `timeline_function_def` | 7 | 2.6s |  |
| 672 | `timeout` | 0 | 7.3s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 673 | `timer_run_actions` | 18 | 34.8s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 674 | `trace` | 8 | 1.4s |  |
| 675 | `transform` | 70 | 1.6s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 676 | `try_catch_finally` | 118 | 1.5s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 677 | `try_catch_stack` | 16 | 1.4s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) |
| 678 | `try_finally_simple` | 16 | 1.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 679 | `typeof` | 22 | 1.5s |  |
| 680 | `typeof_globals` | 7 | 1.4s |  |
| 681 | `uncaught_exception` | 1 | 1.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 682 | `uncaught_exception_bubbled` | 1 | 1.4s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 683 | `undefined_to_string_swf6` | 4 | 1.4s |  |
| 684 | `unescape` | 43 | 1.4s |  |
| 685 | `unload` | 52 | 18.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 686 | `unload_clip_event` | 4 | 18.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 687 | `unload_nested_child` | 5 | 18.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 688 | `unloadmovie` | 4 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 689 | `unloadmovie_method` | 3 | 1.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 690 | `unloadmovienum` | 13 | 1.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 691 | `use_hand_cursor` | 8 | 1.4s |  |
| 692 | `variable_args` | 5 | 1.6s |  |
| 693 | `video_prototype_lazy` | 21 | 1.7s |  |
| 694 | `video_prototype_lazy_swf6_child` | 8 | 1.6s |  |
| 695 | `video_width_height` | 19 | 4.8s |  |
| 696 | `virtual_property_recursion_double_swf6` | 11 | 1.4s |  |
| 697 | `virtual_property_recursion_double_swf7` | 523 | 1.4s |  |
| 698 | `virtual_property_recursion_scope` | 11 | 1.5s |  |
| 699 | `virtual_property_recursion_swf7` | 262 | 1.5s |  |
| 700 | `waitforframe` | 7 | 1.7s |  |
| 701 | `waitforframe2` | 16 | 1.5s |  |
| 702 | `watch` | 117 | 1.7s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 703 | `watch_infinite_recursion` | 1 | 1.5s |  |
| 704 | `watch_proto_recursion` | 1 | 1.5s |  |
| 705 | `watch_recursion_double_swf7` | 3118 | 1.6s |  |
| 706 | `watch_recursion_swf7` | 1042 | 0.9s |  |
| 707 | `watch_textfield` | 12 | 1.8s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 708 | `watch_virtual_property` | 60 | 1.5s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 709 | `watch_virtual_property_proto` | 2 | 1.5s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 710 | `with` | 46 | 1.5s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 711 | `with_return` | 2 | 1.4s |  |
| 712 | `with_variable_scopes` | 43 | 1.5s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 713 | `xml` | 15 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 714 | `xml_append_child` | 28 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 715 | `xml_append_child_with_parent` | 20 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 716 | `xml_attributes_read` | 4 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 717 | `xml_cdata` | 11 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 718 | `xml_child_nodes_edge_cases` | 4 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 719 | `xml_clone_expandos` | 19 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 720 | `xml_first_last_child` | 8 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 721 | `xml_getbytes` | 17 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 722 | `xml_has_child_nodes` | 3 | 5.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 723 | `xml_idmap` | 21 | 1.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 724 | `xml_ignore_comments` | 21 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 725 | `xml_ignore_white` | 34 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 726 | `xml_insert_before` | 20 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 727 | `xml_inspect_createmethods` | 15 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 728 | `xml_inspect_doctype` | 7 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 729 | `xml_inspect_parsexml` | 62 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 730 | `xml_inspect_xmldecl` | 7 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 731 | `xml_load` | 2 | 1.5s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 732 | `xml_namespaces` | 203 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 733 | `xml_parent_and_child` | 5 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 734 | `xml_remove_node` | 22 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 735 | `xml_reparenting` | 14 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 736 | `xml_siblings` | 10 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 737 | `xml_socket` | 8 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 738 | `xml_socket_close_in_handler` | 6 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 739 | `xml_socket_connect_null` | 12 | 19.4s |  |
| 740 | `xml_socket_on_data` | 7 | 1.5s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 741 | `xml_socket_segmented` | 29 | 0.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 742 | `xml_status_mismatched_tags` | 63 | 1.5s |  |
| 743 | `xml_stringify_utf16` | 4 | 1.6s |  |
| 744 | `xml_to_string` | 13 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 745 | `xml_to_string_comment` | 1 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 746 | `xml_unescaping` | 23 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 747 | `xmlnode_proto` | 1 | 1.6s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `asnative_instrument` | 172 | 172 | 2.5s |  |
| 2 | `asnative_sweep` | 73 | 74 | 2.5s |  |
| 3 | `attach_movie_export_not_yet_run` | 1 | 1 | 24.1s |  |
| 4 | `bitmap_data_thorough/copyPixels` | 68 | 68 | 2.7s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 5 | `bitmap_data_thorough/paletteMap` | 68 | 68 | 2.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 6 | `bitmap_data_thorough/perlinNoise` | 40 | 445 | 2.9s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 7 | `bitmapdata_custom_rectangle` | 27 | 27 | 1.9s |  |
| 8 | `edittext_onscroller` | 8 | 8 | 20.4s |  |
| 9 | `form_loader_encoding_4` | 2 | 2 | 1.5s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 10 | `goto_rewind_movieclip_replace` | 1 | 1 | 18.2s |  |
| 11 | `load_cancel_via_unloadclip` | 2 | 2 | 1.6s |  |
| 12 | `load_cancel_via_unloadmovie` | 3 | 3 | 1.5s |  |
| 13 | `mcl_replace_root_swf7_to_swf5` | 1 | 1 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 14 | `mcl_replace_root_swf7_to_swf6` | 5 | 5 | 0.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 15 | `movieclip_library_state_values` | 2 | 9 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 16 | `tab_ordering_properties_tab_index_edge_case` | 3 | 3 | 1.4s |  |
| 17 | `target_paths/swf5` | 654 | 654 | 0.8s |  |
| 18 | `target_paths/swf6` | 654 | 654 | 0.8s |  |
| 19 | `textfield_props_swf5` | 2 | 103 | 2.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 20 | `virtual_property_recursion_swf6` | 3 | 261 | 5.4s |  |
| 21 | `watch_recursion_double_swf6` | 4 | 3109 | 1.6s |  |
| 22 | `watch_recursion_swf6` | 1 | 1039 | 1.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.3% | 6289 | 6335 | 46 | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 99.1% | 114 | 115 | 1 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 3 | `bitmap_data_thorough/pixelDissolve` | 98.5% | 1351 | 1371 | 20 | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 98.2% | 332 | 338 | 6 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 5 | `globals_swf5` | 96.7% | 294 | 304 | 10 | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**12 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.3% | 6289/6335 | 6335 | 6335 | [25](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) |
| 2 | `native_objects_swf6` | 99.1% | 114/115 | 115 | 115 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 3 | `bitmap_data_thorough/pixelDissolve` | 98.5% | 1351/1371 | 1371 | 1371 | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 4 | `movieclip_hittest_shapeflag` | 98.2% | 332/338 | 338 | 338 | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [105](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) |
| 5 | `globals_swf5` | 96.7% | 294/304 | 304 | 304 | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 6 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 7 | `set_property_values/swf4` | 19.9% | 346/1743 | 1743 | 1571 |  |
| 8 | `globals_monkeypatch` | 16.0% | 49/306 | 222 | 306 |  |
| 9 | `global_proto_decls_delete` | 11.1% | 461/4158 | 2371 | 4158 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 10 | `external_interface_monkeypatch` | 2.9% | 4/139 | 65 | 139 |  |
| 11 | `global_instance_decls` | 2.2% | 17/758 | 734 | 758 | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 12 | `global_proto_decls` | 1.1% | 50/4562 | 3865 | 4562 | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 1 | 1 | 0 |
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
| 48 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 23 | 22 | 1 |
| 49 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 50 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 51 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 52 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 53 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 54 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 48 | 45 | 3 |
| 55 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 5 | 4 | 1 |
| 56 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 4 | 0 |
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
| 103 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) | 16 | 15 | 1 |
| 104 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 105 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 1 | 0 | 1 |
| 106 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 107 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 33 | 0 |
| | *(tests not in any document)* | 283 | 266 | 17 |
