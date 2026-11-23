# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 19:23 UTC

**Git SHA**: `1396f1e10b`

**Run Duration**: 77m 2s

**Filtered**: 15 tests ignored out of 781 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 766 |
| Passing | **745** (97.3%) |
| Ruffle-matched | 17 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **762** (99.5%) |
| Failing | 4 |
| Total expected lines | 119566 |
| Matching lines | 116171 (97.2%) |
| Mismatched lines | 3395 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**745 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 27.3s |  |
| 2 | `action_to_integer` | 28 | 0.9s |  |
| 3 | `add` | 28 | 0.9s |  |
| 4 | `add2` | 354 | 1.1s | [1](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 0.9s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 0.3s |  |
| 7 | `add_swf5` | 28 | 0.3s |  |
| 8 | `allow_networking_import_assets` | 4 | 18.9s |  |
| 9 | `allow_networking_import_assets2` | 4 | 0.9s |  |
| 10 | `amf0_array_matrix` | 50 | 1.0s |  |
| 11 | `amf0_serde_suite` | 144 | 1.3s |  |
| 12 | `amf0_utf8_probe` | 14 | 1.0s |  |
| 13 | `amf_array_indices` | 32 | 1.0s |  |
| 14 | `amf_array_serialization` | 10 | 1.0s |  |
| 15 | `amf_serialize_typed_objects` | 6 | 1.2s |  |
| 16 | `amf_sharedobject_strict_array_serialization` | 3 | 1.0s |  |
| 17 | `amf_strict_array_serialization` | 7 | 1.0s |  |
| 18 | `amf_swf6_case_insensitive_typed_objects` | 6 | 0.9s |  |
| 19 | `amf_swf6_serialize_typed_objects` | 6 | 0.9s |  |
| 20 | `amf_swf8_case_sensitive_typed_objects` | 6 | 0.9s |  |
| 21 | `arguments` | 127 | 0.9s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 22 | `array_call_method` | 9 | 0.9s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 23 | `array_concat` | 98 | 0.9s |  |
| 24 | `array_constructor` | 53 | 1.1s |  |
| 25 | `array_enumerate` | 4 | 0.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 26 | `array_length` | 42 | 1.0s |  |
| 27 | `array_properties` | 36 | 0.9s |  |
| 28 | `array_prototyping` | 12 | 33.8s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 29 | `array_reverse` | 226 | 1.6s |  |
| 30 | `array_shift` | 216 | 1.5s |  |
| 31 | `array_slice` | 34 | 1.5s |  |
| 32 | `array_sort` | 161 | 2.4s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 33 | `array_sort_random` | 443 | 1.6s | [2](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 34 | `array_splice` | 207 | 1.7s |  |
| 35 | `array_trivial` | 209 | 1.6s |  |
| 36 | `array_truncation_non_canonical_keys` | 37 | 1.5s |  |
| 37 | `array_unshift` | 146 | 1.5s |  |
| 38 | `as1_constructor_v6` | 35 | 1.4s |  |
| 39 | `as1_constructor_v7` | 35 | 0.5s |  |
| 40 | `as2_oop` | 13 | 1.7s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 41 | `as2_super_and_this_v6` | 97 | 1.8s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 42 | `as2_super_and_this_v8` | 85 | 1.5s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 43 | `as2_super_via_manual_prototype` | 40 | 1.9s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 44 | `as_broadcaster` | 312 | 2.5s | [3](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 45 | `as_set_prop_flags` | 79 | 1.7s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 46 | `as_set_prop_flags_version` | 31 | 1.4s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 47 | `as_set_prop_flags_version_swf5` | 1 | 1.4s |  |
| 48 | `as_set_prop_flags_version_swf6` | 1 | 1.4s |  |
| 49 | `as_set_prop_flags_version_swf7` | 1 | 0.5s |  |
| 50 | `as_set_prop_flags_version_swf8` | 1 | 1.4s |  |
| 51 | `as_set_prop_flags_version_swf9` | 1 | 0.6s |  |
| 52 | `as_setup_error` | 52 | 1.6s |  |
| 53 | `as_transformed_flag` | 20 | 24.0s |  |
| 54 | `asfunction` | 11 | 34.1s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) |
| 55 | `asnative` | 34 | 1.6s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 56 | `asnew` | 34 | 24.2s | [4](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 57 | `assetnative` | 81 | 1.8s |  |
| 58 | `assetnative_ids` | 10 | 1.6s |  |
| 59 | `assetnativeaccessor` | 81 | 1.7s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 60 | `assetnativeaccessor_ids` | 21 | 1.6s | [5](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) |
| 61 | `attach_movie` | 59 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 62 | `attach_movie_stop` | 3 | 24.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 63 | `bad_placeobject_clipaction` | 2 | 1.5s |  |
| 64 | `bad_swf_tag_past_eof` | 0 | 1.4s |  |
| 65 | `bitand` | 1058 | 4.8s |  |
| 66 | `bitmap_data` | 1126 | 4.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 67 | `bitmap_data_colortransform` | 0 | 2.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 68 | `bitmap_data_compare` | 40 | 1.8s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 69 | `bitmap_data_copypixels` | 17 | 24.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 70 | `bitmap_data_draw_cliprect` | 13 | 24.6s |  |
| 71 | `bitmap_data_draw_return_value` | 9 | 1.6s |  |
| 72 | `bitmap_data_draw_string_target` | 40 | 1.6s |  |
| 73 | `bitmap_data_fillrect` | 0 | 1.7s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 74 | `bitmap_data_hittest` | 132 | 2.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 75 | `bitmap_data_max_size_swf10` | 12 | 1.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 76 | `bitmap_data_max_size_swf9` | 10 | 1.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 77 | `bitmap_data_noise` | 631 | 26.6s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 78 | `bitmap_data_perlinnoise` | 0 | 18.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 79 | `bitmap_data_pixeldissolve` | 1075 | 18.9s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 80 | `bitmap_data_pixeldissolve_image` | 0 | 18.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 81 | `bitmap_data_thorough/colorTransform` | 279 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 82 | `bitmap_data_thorough/compare` | 69 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 83 | `bitmap_data_thorough/constructor` | 313 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 84 | `bitmap_data_thorough/copyChannel` | 2715 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 85 | `bitmap_data_thorough/fillRect` | 342 | 1.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 86 | `bitmap_data_thorough/floodFill` | 867 | 1.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 87 | `bitmap_data_thorough/getColorBoundsRect` | 285 | 1.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 88 | `bitmap_data_thorough/getPixel` | 141 | 1.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 89 | `bitmap_data_thorough/getPixel32` | 141 | 1.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 90 | `bitmap_data_thorough/hitTest` | 519 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 91 | `bitmap_data_thorough/merge` | 1203 | 1.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 92 | `bitmap_data_thorough/noise` | 1518 | 1.3s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 93 | `bitmap_data_thorough/scroll` | 384 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 94 | `bitmap_data_thorough/setPixel` | 531 | 1.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 95 | `bitmap_data_thorough/setPixel32` | 531 | 1.2s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 96 | `bitmap_data_thorough/threshold` | 1308 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 97 | `bitmap_data_threshold` | 176 | 1.3s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 98 | `bitmap_filters` | 548 | 2.0s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [8](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTER_CLONE_PLAN.md) [9](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_MCFILTERS_PLAN.md) [10](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_FILTERS_PLAN.md) [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 99 | `bitmapdata_applyfilter_colormatrix` | 0 | 28.1s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [14](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAPDATA_RENDERING_PLAN.md) |
| 100 | `bitmapdata_channels` | 19 | 18.5s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) |
| 101 | `bitmapdata_copypixels_self` | 612 | 1.1s |  |
| 102 | `bitmapdata_hittest_default_threshold` | 4 | 0.9s |  |
| 103 | `bitmapdata_hittest_threshold` | 6 | 0.9s |  |
| 104 | `bitor` | 1058 | 3.2s |  |
| 105 | `biturshift` | 14 | 0.9s |  |
| 106 | `biturshift_swf8` | 14 | 0.7s |  |
| 107 | `bitxor` | 1058 | 3.1s |  |
| 108 | `boxed_primitives` | 24 | 18.6s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 109 | `button_children` | 8 | 1.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 110 | `button_goto` | 4 | 18.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 111 | `button_key_events` | 14 | 1.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 112 | `button_key_events_special` | 45 | 2.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 113 | `button_keypress` | 3 | 1.1s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 114 | `button_keypress_vs_press` | 25 | 1.2s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 115 | `button_keypress_vs_tab` | 20 | 1.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 116 | `button_keypress_vs_textinput` | 4 | 1.0s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 117 | `button_order` | 2 | 0.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 118 | `button_properties_special_cases` | 22 | 18.4s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 119 | `button_v5` | 18 | 0.9s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 120 | `button_v6` | 18 | 0.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 121 | `call` | 62 | 18.4s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 122 | `call_method_empty_name` | 1 | 0.9s |  |
| 123 | `capabilities_resolution` | 8 | 18.2s |  |
| 124 | `catch_references_registers` | 2 | 33.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 125 | `click_block` | 5 | 23.4s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 126 | `clip_constructors` | 8 | 1.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 127 | `clip_event_propagation_order` | 17 | 23.5s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 128 | `clip_events` | 19 | 23.9s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 129 | `clone_sprite_edittext` | 94 | 1.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 130 | `clone_sprite_edittext_dynamic` | 86 | 1.6s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 131 | `clone_sprite_types` | 24 | 1.3s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 132 | `closure_scope` | 7 | 23.6s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 133 | `coerce_to_object_monkeypatch` | 129 | 23.6s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 134 | `coerce_to_primitive_resolve` | 22 | 1.5s | [72](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 135 | `color` | 57 | 1.6s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 136 | `color_transform` | 48 | 1.4s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 137 | `conflicting_instance_names` | 23 | 23.6s |  |
| 138 | `constructor_function` | 2 | 1.2s |  |
| 139 | `context_menu` | 128 | 1.6s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 140 | `context_menu_item` | 96 | 1.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 141 | `context_menu_swf6` | 14 | 1.3s |  |
| 142 | `create_empty_movie_clip` | 3 | 1.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 143 | `cross_movie_root` | 10 | 23.5s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 144 | `custom_clip_methods` | 4 | 1.6s | [24](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 145 | `default_names` | 52 | 1.6s | [26](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 146 | `define_font_glyph_table_order` | 0 | 54.2s |  |
| 147 | `define_font_glyph_table_overlap` | 0 | 0.6s |  |
| 148 | `define_function2` | 8 | 1.2s |  |
| 149 | `define_function2_preload` | 13 | 32.1s |  |
| 150 | `define_function2_preload_order` | 4 | 1.3s |  |
| 151 | `define_function_case_sensitive` | 2 | 22.7s |  |
| 152 | `define_local` | 27 | 1.2s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 153 | `define_local_with_paths` | 54 | 1.3s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 154 | `delete` | 3 | 23.2s |  |
| 155 | `delete2` | 74 | 1.4s |  |
| 156 | `depth_replacement_audio_unloading` | 3 | 23.3s | [27](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) |
| 157 | `device_font_spacing` | 91 | 23.6s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 158 | `displacementmapfilter_mappoint_throw_error` | 13 | 1.4s | [29](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 159 | `display_object_properties` | 2 | 1.4s | [76](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_CXFORM_GPU_PLAN.md) [78](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_TRANSFORM_GPU_PLAN.md) |
| 160 | `divide_swf4` | 107 | 1.3s |  |
| 161 | `do_init_action` | 3 | 1.4s |  |
| 162 | `do_init_action_child` | 12 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 163 | `drag_drop` | 10 | 1.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 164 | `drag_over_from_outside` | 1 | 23.2s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 165 | `drag_over_without_startdrag` | 1 | 1.4s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 166 | `duplicate_movie_clip` | 20 | 1.4s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 167 | `duplicate_movie_clip_drawing` | 2 | 1.2s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 168 | `edittext_align` | 60 | 1.7s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 169 | `edittext_align_trailing_spaces_swf7` | 576 | 23.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 170 | `edittext_align_trailing_spaces_swf8` | 576 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 171 | `edittext_antialiastype` | 296 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 172 | `edittext_asfunction_case_insensitive` | 1 | 1.3s |  |
| 173 | `edittext_autosize` | 71 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 174 | `edittext_autosize_setter` | 20 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 175 | `edittext_bullet` | 30 | 23.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 176 | `edittext_default_format` | 221 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 177 | `edittext_default_format_empty` | 100 | 1.1s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 178 | `edittext_default_format_font_style` | 335 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 179 | `edittext_drag_select` | 9 | 16.6s | [32](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 180 | `edittext_focus_selection` | 2 | 1.1s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 181 | `edittext_font_size` | 45 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 182 | `edittext_hscroll` | 27 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 183 | `edittext_html_align_swf7` | 52 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 184 | `edittext_html_align_swf8` | 52 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 185 | `edittext_html_color` | 114 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 186 | `edittext_html_condensewhite_swf7` | 311 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 187 | `edittext_html_condensewhite_swf8` | 311 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 188 | `edittext_html_duplicate_attributes` | 247 | 1.2s |  |
| 189 | `edittext_html_entity` | 4 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 190 | `edittext_html_roundtrip` | 17 | 1.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 191 | `edittext_html_swf6` | 5377 | 2.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 192 | `edittext_html_swf7` | 5377 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 193 | `edittext_html_swf8` | 5377 | 0.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 194 | `edittext_ime_focus_lost` | 7 | 15.7s | [71](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 195 | `edittext_input` | 1 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 196 | `edittext_input_newlines` | 9 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 197 | `edittext_leading` | 9 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 198 | `edittext_letter_spacing` | 15 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 199 | `edittext_margins` | 25 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 200 | `edittext_newline_stripping` | 64 | 5.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 201 | `edittext_newlines` | 30 | 22.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 202 | `edittext_password` | 5 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 203 | `edittext_password_copy` | 4 | 17.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 204 | `edittext_paste_empty` | 2 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 205 | `edittext_place_caret` | 2 | 16.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 206 | `edittext_programmatic_focus` | 12 | 1.1s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 207 | `edittext_restrict` | 191 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 208 | `edittext_restrict_paste` | 5 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 209 | `edittext_scroll` | 54 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 210 | `edittext_set_text_same` | 70 | 1.3s |  |
| 211 | `edittext_set_text_same_after_edits` | 98 | 1.1s |  |
| 212 | `edittext_stylesheet` | 325 | 1.6s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [89](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 213 | `edittext_tab_focus` | 13 | 1.4s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 214 | `edittext_tab_stops` | 60 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 215 | `edittext_tag_indent` | 31 | 16.2s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [28](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 216 | `edittext_text_height_leading` | 20 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 217 | `edittext_underline` | 40 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 218 | `edittext_width_height` | 103 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 219 | `empty_movieclip_can_attach_movies` | 11 | 1.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 220 | `enumerate` | 64 | 1.1s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 221 | `equals` | 32 | 1.0s |  |
| 222 | `equals2_swf5` | 926 | 2.5s |  |
| 223 | `equals2_swf6` | 926 | 0.3s |  |
| 224 | `equals2_swf7` | 926 | 0.3s |  |
| 225 | `equals_swf4` | 665 | 1.7s |  |
| 226 | `equals_swf4_alt` | 32 | 26.8s |  |
| 227 | `equals_swf5` | 32 | 0.3s |  |
| 228 | `error` | 58 | 0.9s |  |
| 229 | `escape` | 14 | 0.9s |  |
| 230 | `execution_order1` | 5 | 18.2s |  |
| 231 | `execution_order2` | 7 | 18.2s |  |
| 232 | `execution_order3` | 4 | 1.0s |  |
| 233 | `execution_order4` | 12 | 1.2s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 234 | `export_assets` | 3 | 0.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 235 | `extends_chain` | 134 | 1.4s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 236 | `extends_native_type` | 11 | 1.0s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 237 | `external_interface` | 84 | 1.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 238 | `external_interface_escapexml` | 26 | 1.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 239 | `external_interface_jsquotestring` | 21 | 1.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 240 | `external_interface_toas_basic` | 354 | 1.2s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 241 | `external_interface_toxml_array` | 25 | 0.9s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 242 | `external_interface_toxml_basic` | 179 | 1.1s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 243 | `external_interface_unescapexml` | 40 | 1.0s | [35](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) |
| 244 | `file_reference_browse_cancel` | 21 | 1.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 245 | `file_reference_download_cancel` | 7 | 0.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 246 | `file_reference_download_httperror_dns_error` | 13 | 0.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 247 | `file_reference_download_httperror_status_code` | 23 | 0.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 248 | `file_reference_download_success` | 34 | 1.0s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 249 | `file_reference_list_asbroadcaster` | 9 | 0.9s |  |
| 250 | `file_reference_list_browse_cancel` | 4 | 0.9s |  |
| 251 | `file_reference_list_browse_invalid_filters` | 36 | 27.1s |  |
| 252 | `file_reference_list_browse_select` | 7 | 1.2s |  |
| 253 | `file_reference_listeners_per_instance` | 20 | 1.2s |  |
| 254 | `file_reference_upload_httperror_dns_error` | 18 | 1.3s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 255 | `file_reference_upload_httperror_status_code` | 23 | 1.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 256 | `file_reference_upload_request` | 158 | 19.5s |  |
| 257 | `file_reference_upload_success` | 23 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 258 | `focus_keyboard_press` | 60 | 1.6s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 259 | `focus_mouse` | 45 | 1.4s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 260 | `focus_mouse_focusable` | 8 | 19.7s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 261 | `focus_mouse_rollout` | 4 | 1.5s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 262 | `focus_remove` | 33 | 19.2s |  |
| 263 | `focus_root_movie` | 2 | 1.3s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 264 | `focus_visibility_change` | 45 | 1.2s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 265 | `focusrect_focuslost` | 4 | 1.4s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) |
| 266 | `focusrect_mouse_swf8` | 0 | 1.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 267 | `focusrect_mouse_swf9` | 0 | 0.6s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) |
| 268 | `focusrect_property_swf5` | 1237 | 1.8s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 269 | `focusrect_property_swf6` | 1237 | 1.1s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 270 | `focusrect_property_swf7` | 1237 | 0.5s | [39](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) |
| 271 | `focusrect_swf5` | 6 | 19.8s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 272 | `focusrect_swf6` | 42 | 1.7s | [40](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 273 | `form_loader_encoding_1` | 1 | 1.2s |  |
| 274 | `form_loader_encoding_2` | 3 | 18.6s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 275 | `form_loader_encoding_3` | 3 | 1.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 276 | `frame_size_translated_negative` | 21 | 32.5s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 277 | `frame_size_translated_positive` | 21 | 23.2s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) |
| 278 | `function_as_function` | 35 | 23.3s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 279 | `function_base_clip` | 8 | 23.5s |  |
| 280 | `function_base_clip_readded` | 11 | 23.5s |  |
| 281 | `function_base_clip_removed` | 25 | 23.5s |  |
| 282 | `function_suppress_and_preload` | 28 | 23.7s |  |
| 283 | `funky_function_calls` | 56 | 1.4s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 284 | `get_bytes_total` | 4 | 23.2s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 285 | `get_variable_in_scope` | 29 | 1.3s |  |
| 286 | `getproperty` | 28 | 1.3s |  |
| 287 | `getproperty_swf4` | 28 | 0.4s |  |
| 288 | `getproperty_swf5` | 28 | 0.4s |  |
| 289 | `gettextextent` | 56 | 1.4s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 290 | `geturl` | 7 | 24.0s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 291 | `geturl_opcode_target_normalize` | 45 | 23.4s |  |
| 292 | `geturl_target_normalize` | 89 | 23.6s |  |
| 293 | `global_array` | 3 | 1.2s |  |
| 294 | `global_is_bare` | 7 | 1.3s |  |
| 295 | `global_swf5_6_7_8_9` | 1145 | 2.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 296 | `global_swf6_7_8` | 15 | 1.7s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 297 | `globals_swf6` | 304 | 26.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 298 | `globals_swf7` | 304 | 0.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 299 | `globals_swf8` | 304 | 0.6s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 300 | `goto_advance1` | 6 | 18.8s |  |
| 301 | `goto_advance2` | 2 | 1.2s |  |
| 302 | `goto_both_ways1` | 3 | 1.2s |  |
| 303 | `goto_both_ways2` | 3 | 18.5s |  |
| 304 | `goto_execution_order` | 2 | 18.3s |  |
| 305 | `goto_execution_order2` | 2 | 1.2s |  |
| 306 | `goto_frame` | 12 | 1.5s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 307 | `goto_frame2` | 44 | 19.0s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 308 | `goto_frame_number` | 3 | 18.7s |  |
| 309 | `goto_label` | 17 | 18.8s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 310 | `goto_methods` | 40 | 1.3s | [42](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) |
| 311 | `goto_rewind1` | 1 | 1.1s |  |
| 312 | `goto_rewind2` | 3 | 1.1s |  |
| 313 | `goto_rewind3` | 2 | 1.2s |  |
| 314 | `greater_swf6` | 1175 | 3.0s |  |
| 315 | `greater_swf7` | 1175 | 0.4s |  |
| 316 | `greaterthan_swf5` | 1 | 1.1s |  |
| 317 | `greaterthan_swf8` | 1 | 1.1s |  |
| 318 | `has_own_property` | 32 | 1.1s |  |
| 319 | `hitarea_lazy_getter` | 6 | 1.2s |  |
| 320 | `hitarea_remove_sibling` | 4 | 1.2s |  |
| 321 | `hitarea_sweep` | 33 | 34.1s |  |
| 322 | `hittest_lockroot` | 15 | 24.3s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 323 | `hittest_morph` | 70 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [60](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) |
| 324 | `hittest_morph_input` | 1 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 325 | `hittest_winding_rule` | 12 | 24.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 326 | `html_text_img_numeric_attributes` | 3 | 1.5s |  |
| 327 | `html_text_img_parsing_swf5` | 517 | 1.9s |  |
| 328 | `html_text_img_parsing_swf6` | 517 | 0.5s |  |
| 329 | `html_text_img_parsing_swf7` | 517 | 1.9s |  |
| 330 | `html_text_img_parsing_swf8` | 517 | 0.5s |  |
| 331 | `infinite_recursion_function` | 4 | 1.5s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 332 | `infinite_recursion_function_in_setter` | 131 | 1.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 333 | `infinite_recursion_virtual_property` | 67 | 1.4s | [49](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) |
| 334 | `init_array_invalid` | 4 | 23.7s |  |
| 335 | `init_object_invalid` | 4 | 0.3s |  |
| 336 | `init_object_order` | 15 | 1.7s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 337 | `input_dead_keys_windows` | 15 | 1.9s | [50](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) |
| 338 | `instanceof_coercions` | 88 | 2.1s | [102](ruffle-tests/tests/swfs/avm1/_investigation/complete/TYPE_COERCION_ADVANCED_PLAN.md) |
| 339 | `interface_implements_op` | 47 | 2.3s | [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 340 | `is_finite` | 49 | 1.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 341 | `is_finite_swf6` | 49 | 0.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 342 | `is_prototype_of` | 89 | 1.5s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 343 | `issue_1086` | 1 | 1.4s |  |
| 344 | `issue_1104` | 2 | 23.7s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) |
| 345 | `issue_1671` | 0 | 24.0s |  |
| 346 | `issue_1906` | 4 | 1.6s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 347 | `issue_2030` | 4 | 27.5s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 348 | `issue_2084` | 16 | 18.1s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 349 | `issue_2166` | 9 | 0.9s |  |
| 350 | `issue_2870` | 3 | 18.1s | [53](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) |
| 351 | `issue_3169` | 2 | 1.0s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 352 | `issue_3446` | 1 | 0.9s |  |
| 353 | `issue_3522` | 2 | 18.0s |  |
| 354 | `issue_4377` | 2 | 0.9s |  |
| 355 | `issue_710` | 4 | 0.9s |  |
| 356 | `issue_768` | 3 | 0.8s | [51](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) |
| 357 | `issue_9327` | 2 | 18.0s |  |
| 358 | `issue_9885` | 2 | 0.9s |  |
| 359 | `key_isToggled` | 9 | 0.9s |  |
| 360 | `lazy_prototype_shared` | 8 | 1.0s |  |
| 361 | `lessthan` | 41 | 0.9s |  |
| 362 | `lessthan2_swf5` | 1226 | 2.5s |  |
| 363 | `lessthan2_swf6` | 1226 | 0.3s |  |
| 364 | `lessthan2_swf7` | 1226 | 0.3s |  |
| 365 | `lessthan_swf4` | 902 | 1.8s |  |
| 366 | `lessthan_swf4_alt` | 41 | 0.3s |  |
| 367 | `lessthan_swf5` | 41 | 0.3s |  |
| 368 | `load_cancel_via_removemovieclip` | 4 | 0.9s |  |
| 369 | `load_vars` | 35 | 0.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 370 | `loadmovie` | 2 | 1.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 371 | `loadmovie_fail` | 2 | 32.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 372 | `loadmovie_flashvars` | 4 | 23.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 373 | `loadmovie_method` | 2 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 374 | `loadmovie_registerclass` | 30 | 1.6s | [23](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 375 | `loadmovie_replace_root` | 5 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 376 | `loadmovie_var_persistence` | 8 | 1.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 377 | `loadmovienum` | 3 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 378 | `loadmovienum_cross_version_prototype` | 9 | 1.5s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) |
| 379 | `loadvariables` | 2 | 22.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 380 | `loadvariables2` | 8 | 23.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 381 | `loadvariables_method` | 7 | 23.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 382 | `loadvariablesnum` | 2 | 1.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [56](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) |
| 383 | `loadvars_tostring` | 5 | 1.3s |  |
| 384 | `local_to_global` | 49 | 1.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 385 | `localconnection` | 579 | 2.5s | [57](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 386 | `localconnection_properties` | 8 | 1.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 387 | `localconnection_reference_identity` | 5 | 1.2s |  |
| 388 | `localconnection_serialize_function_array_elements` | 20 | 1.3s |  |
| 389 | `localconnection_serialize_inherited_array_indices` | 12 | 1.3s |  |
| 390 | `localconnection_serialize_sparse_array_getters` | 26 | 1.3s |  |
| 391 | `localconnection_serialize_undefined_array_elements` | 24 | 1.3s |  |
| 392 | `localconnection_top_level` | 7 | 22.9s |  |
| 393 | `localconnection_xml` | 14 | 1.3s |  |
| 394 | `localconnection_xml_unavailable` | 23 | 1.3s |  |
| 395 | `lock_root` | 1 | 1.2s |  |
| 396 | `logical_ops_swf4` | 90 | 1.2s |  |
| 397 | `logical_ops_swf8` | 108 | 27.3s |  |
| 398 | `looping` | 6 | 18.6s |  |
| 399 | `looping_child_swf32` | 141 | 20.8s |  |
| 400 | `looping_child_swf5` | 141 | 1.6s |  |
| 401 | `looping_child_swf9` | 141 | 0.5s |  |
| 402 | `looping_real_1_declared_1` | 1 | 1.1s |  |
| 403 | `looping_real_1_declared_2` | 1 | 0.3s |  |
| 404 | `looping_real_2_declared_1` | 5 | 1.1s |  |
| 405 | `looping_real_2_declared_2` | 5 | 0.4s |  |
| 406 | `mask_reapply` | 0 | 19.0s | [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 407 | `mask_with_drawing` | 0 | 19.1s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 408 | `math_min_max` | 101 | 1.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 409 | `math_swf6` | 530 | 19.2s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 410 | `math_swf7` | 530 | 0.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 411 | `math_swf8` | 530 | 0.4s | [59](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) |
| 412 | `matrix` | 810 | 2.5s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 413 | `mcl_as_broadcaster` | 12 | 1.2s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 414 | `mcl_events_swf_version` | 232 | 2.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 415 | `mcl_getprogress` | 30 | 19.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 416 | `mcl_loadclip` | 149 | 19.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 417 | `mcl_loadclip_properties` | 6 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 418 | `mcl_loadclip_replace_root` | 1 | 1.4s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) [75](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) |
| 419 | `mcl_mislabeled_target` | 6 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 420 | `mcl_target_gif87a` | 6 | 1.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 421 | `mcl_target_gif89a` | 6 | 35.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 422 | `mcl_target_jpg` | 6 | 0.6s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 423 | `mcl_target_png` | 6 | 1.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 424 | `mcl_unloadclip` | 5 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 425 | `mouse_events` | 8 | 23.2s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 426 | `mouse_events_visible_enabled` | 12 | 1.9s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 427 | `mouse_hover_events_while_dragging` | 1 | 23.3s | [30](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) |
| 428 | `mouse_listeners` | 67 | 23.3s |  |
| 429 | `mouse_pos` | 665 | 23.4s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 430 | `mouse_pos_with_scale_factor` | 260 | 23.1s | [61](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) |
| 431 | `mouse_wheel_enabled` | 2 | 1.4s |  |
| 432 | `movieclip_begin_gradient_fill` | 0 | 24.0s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 433 | `movieclip_blend_mode_property` | 35 | 1.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 434 | `movieclip_create_text_field` | 90 | 23.4s | [22](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CREATETEXTFIELD_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 435 | `movieclip_default_state` | 69 | 1.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 436 | `movieclip_depth_methods` | 98 | 1.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 437 | `movieclip_focusenabled` | 99 | 1.5s | [41](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 438 | `movieclip_get_instance_at_depth` | 28 | 1.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 439 | `movieclip_getbounds` | 191 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 440 | `movieclip_gettextsnapshot` | 112 | 1.7s | [45](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 441 | `movieclip_hittest` | 92 | 1.5s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 442 | `movieclip_in_removed_button` | 4 | 23.3s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) |
| 443 | `movieclip_init_object` | 5 | 1.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 444 | `movieclip_invalid_get_bounds_1` | 75 | 2.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 445 | `movieclip_invalid_get_bounds_2` | 75 | 1.6s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 446 | `movieclip_invalid_get_bounds_3` | 13 | 28.4s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 447 | `movieclip_invalid_get_bounds_4` | 13 | 1.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 448 | `movieclip_invalid_get_bounds_5` | 11 | 1.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 449 | `movieclip_invalid_get_bounds_6` | 10 | 21.2s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 450 | `movieclip_invalid_get_bounds_7` | 10 | 20.8s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 451 | `movieclip_invalid_get_bounds_8` | 11 | 1.1s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 452 | `movieclip_line_gradient_style` | 0 | 18.5s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) |
| 453 | `movieclip_lockroot` | 29 | 1.2s | [58](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 454 | `movieclip_methods_with_loaded_image` | 4 | 18.3s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 455 | `movieclip_name_from_timeline` | 13 | 0.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 456 | `movieclip_onconstruct` | 20 | 1.0s |  |
| 457 | `movieclip_prototype_extension` | 5 | 0.9s |  |
| 458 | `movieclip_setmask` | 14 | 18.3s | [31](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [77](ruffle-tests/tests/swfs/avm1/_investigation/complete/RUNTIME_SETMASK_PLAN.md) |
| 459 | `movieclip_state_values` | 114 | 1.8s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [55](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 460 | `moviecliploader_flashvars` | 4 | 1.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [63](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) |
| 461 | `mutable_this` | 18 | 0.9s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 462 | `named_shapes` | 14 | 17.9s |  |
| 463 | `nan_scale` | 9 | 0.9s |  |
| 464 | `native_double_construct` | 12 | 18.1s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 465 | `native_objects_swf7` | 115 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 466 | `native_objects_swf8` | 115 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [65](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) |
| 467 | `native_subclasses` | 191 | 1.2s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 468 | `nested_textfields_in_buttons` | 0 | 1.0s |  |
| 469 | `netconnection_close` | 39 | 0.9s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 470 | `netconnection_deserialize_strict_array_undefined` | 17 | 26.1s |  |
| 471 | `netconnection_send_remote` | 50 | 1.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [66](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) |
| 472 | `netconnection_serialize_arrays` | 6 | 0.9s |  |
| 473 | `netstream_play_flv_screen` | 0 | 30.4s | [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 474 | `netstream_seek_flv` | 25 | 18.0s | [38](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 475 | `new_class_prototype_getter` | 6 | 0.9s |  |
| 476 | `new_method_wrap` | 4 | 17.8s |  |
| 477 | `new_object_enumerate` | 7 | 0.8s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) |
| 478 | `new_object_wrap` | 4 | 0.8s |  |
| 479 | `o` | 3 | 0.8s |  |
| 480 | `object_constructor` | 33 | 0.9s |  |
| 481 | `object_function` | 32 | 0.9s |  |
| 482 | `object_properties` | 31 | 1.1s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 483 | `object_prototypes` | 74 | 0.9s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 484 | `object_resolve` | 38 | 18.0s | [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 485 | `object_string_coerce_swf5` | 62 | 0.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 486 | `object_string_coerce_swf6` | 68 | 0.9s | [67](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) |
| 487 | `on_construct` | 25 | 1.0s | [17](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [20](ruffle-tests/tests/swfs/avm1/_investigation/blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 488 | `parse_float` | 74 | 1.0s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 489 | `parse_int` | 64 | 19.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) [70](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 490 | `path_string` | 301 | 1.2s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 491 | `place_and_lookup` | 30 | 1.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 492 | `placeobject_all_event_flags` | 10 | 19.4s |  |
| 493 | `placeobject_occupied_depth` | 6 | 17.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 494 | `point` | 329 | 1.6s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 495 | `primitive_instanceof` | 37 | 36.5s |  |
| 496 | `primitive_type_globals` | 557 | 1.8s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 497 | `printjob_props_swf5` | 45 | 1.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 498 | `printjob_props_swf6` | 45 | 1.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 499 | `printjob_props_swf7` | 45 | 0.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 500 | `property_invalid_base_clip` | 35 | 1.5s |  |
| 501 | `prototype_delete` | 12 | 1.5s |  |
| 502 | `prototype_enumerate` | 5 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 503 | `prototype_properties` | 17 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [73](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 504 | `rectangle` | 629 | 3.3s | [44](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 505 | `recursive_prototypes` | 0 | 1.4s |  |
| 506 | `register_and_init_order` | 231 | 24.6s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 507 | `register_class` | 66 | 2.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 508 | `register_class_return_value` | 16 | 24.1s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 509 | `register_class_swf6` | 37 | 1.9s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 510 | `register_class_with_sound` | 11 | 1.8s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 511 | `register_globals_across_frames` | 15 | 1.6s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 512 | `register_underflow` | 26 | 1.4s | [74](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 513 | `remove_different_level` | 3 | 1.6s |  |
| 514 | `remove_movie_clip` | 29 | 1.7s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 515 | `removed_base_clip_tell_target` | 1 | 24.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 516 | `removed_clip_function_scope` | 12 | 24.2s |  |
| 517 | `removed_clip_halts_script` | 15 | 25.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) |
| 518 | `removed_target_clip_scope` | 35 | 1.8s | [16](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 519 | `resolve_different_root` | 2 | 1.7s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 520 | `rewind_depth` | 30 | 24.1s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 521 | `root_button_mode` | 10 | 34.6s | [15](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) |
| 522 | `root_global_parent` | 6 | 23.2s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 523 | `root_onload` | 1 | 23.2s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 524 | `sandbox_type_local_file` | 1 | 23.2s |  |
| 525 | `sandbox_type_local_network` | 1 | 1.1s |  |
| 526 | `selection` | 454 | 1.7s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 527 | `selection_asbroadcaster` | 9 | 1.4s |  |
| 528 | `selection_handlers` | 27 | 1.5s | [80](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) |
| 529 | `set_interval` | 27 | 1.6s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 530 | `set_property_values/swf5` | 1743 | 0.6s |  |
| 531 | `set_property_values/swf6` | 1743 | 0.6s |  |
| 532 | `set_property_values/swf7` | 1743 | 0.5s |  |
| 533 | `set_target_2_swf5` | 13 | 1.6s |  |
| 534 | `set_target_2_swf6` | 13 | 1.5s |  |
| 535 | `set_target_2_swf7` | 13 | 0.4s |  |
| 536 | `set_variable_scope` | 58 | 1.5s |  |
| 537 | `shared_object_members_swf5` | 32 | 1.5s |  |
| 538 | `shared_object_secure` | 20 | 1.6s |  |
| 539 | `shared_object_serialize_typed_objects` | 1 | 1.5s |  |
| 540 | `shared_stack` | 16 | 23.7s |  |
| 541 | `single_frame` | 1 | 1.3s |  |
| 542 | `slash_syntax` | 14 | 1.5s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 543 | `sound` | 628 | 1.8s | [81](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) |
| 544 | `sound_duration_position_props` | 290 | 1.6s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [82](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_DURATION_POSITION_PLAN.md) |
| 545 | `sound_getters` | 99 | 33.3s |  |
| 546 | `sound_gettransform_props` | 4 | 1.4s |  |
| 547 | `sound_id3` | 633 | 1.6s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 548 | `sound_id3_prop` | 138 | 1.7s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [83](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_ID3_PLAN.md) |
| 549 | `sound_load_multiple_instances` | 19 | 24.7s |  |
| 550 | `sound_load_multiple_remote` | 6 | 1.5s |  |
| 551 | `sound_load_props` | 111 | 1.6s |  |
| 552 | `sound_load_start` | 6 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 553 | `sound_load_start_remote` | 1 | 1.4s |  |
| 554 | `sound_load_stops_when_dereferenced` | 0 | 23.6s |  |
| 555 | `sound_load_streaming_stop_remote` | 3 | 1.4s |  |
| 556 | `sound_mixed_attach_load` | 13 | 23.8s |  |
| 557 | `sound_multiple_load` | 1 | 1.4s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) [84](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_LOADING_PLAN.md) |
| 558 | `sound_nested_clips` | 10 | 1.6s |  |
| 559 | `sound_owner_reference` | 12 | 1.4s |  |
| 560 | `sound_owner_tostring_fail` | 9 | 1.4s |  |
| 561 | `sound_props_swf5` | 68 | 1.5s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 562 | `sound_props_swf6` | 68 | 1.1s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 563 | `sound_setters` | 43 | 1.6s |  |
| 564 | `sound_start_load` | 0 | 1.4s |  |
| 565 | `sound_start_stop` | 44 | 23.5s |  |
| 566 | `sparse_array_truncation_non_canonical_keys` | 43 | 1.7s |  |
| 567 | `stage_display_state` | 16 | 1.4s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 568 | `stage_object_children` | 83 | 1.5s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 569 | `stage_object_enumerate` | 4 | 1.4s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 570 | `stage_object_properties` | 241 | 23.6s | [34](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 571 | `stage_object_properties_get_var` | 5 | 26.3s |  |
| 572 | `stage_object_properties_swf6` | 231 | 18.5s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 573 | `stage_property_representation` | 586 | 0.9s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 574 | `stage_scale_mode` | 39 | 17.7s | [85](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) [86](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) |
| 575 | `strictequals_swf6` | 902 | 2.0s |  |
| 576 | `strictly_equals` | 7 | 0.9s |  |
| 577 | `string_coercion` | 117 | 1.2s | [87](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) |
| 578 | `string_methods` | 285 | 1.3s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 579 | `string_methods_negative_args` | 240 | 18.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 580 | `string_methods_swfv5` | 275 | 1.5s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 581 | `string_ops_swf6` | 95 | 0.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) |
| 582 | `string_paths_basic` | 4 | 0.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 583 | `string_paths_eval` | 4 | 0.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 584 | `string_paths_eval2` | 7 | 18.1s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 585 | `string_paths_hidden` | 54 | 1.0s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 586 | `string_paths_keyevents` | 0 | 0.9s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 587 | `string_paths_other` | 36 | 1.0s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 588 | `string_paths_reference_launder` | 2 | 0.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 589 | `string_paths_timer` | 0 | 0.8s | [103](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) |
| 590 | `string_paths_unload` | 1 | 0.9s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 591 | `string_paths_variable_alias` | 4 | 0.8s | [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 592 | `string_paths_variable_scopes` | 5 | 0.9s | [33](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) [88](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 593 | `string_relational_compare` | 4 | 0.9s | [37](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) |
| 594 | `stylesheet` | 283 | 1.6s |  |
| 595 | `stylesheet_load` | 49 | 1.1s | [48](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) |
| 596 | `stylesheet_transform` | 750 | 1.6s |  |
| 597 | `super_edge_cases` | 39 | 26.8s | [64](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [69](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 598 | `swf4_actions_bool` | 96 | 18.2s |  |
| 599 | `swf4_actions_coercion_order` | 157 | 1.0s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 600 | `swf4_bool` | 4 | 0.9s |  |
| 601 | `swf4_function_calls` | 7 | 0.9s |  |
| 602 | `swf4_vars` | 25 | 0.9s |  |
| 603 | `swf5_encoding` | 3 | 0.9s |  |
| 604 | `swf5_global_funcs` | 232 | 0.9s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 605 | `swf5_no_closure` | 19 | 0.9s | [18](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 606 | `swf5_to_6_cross_call` | 29 | 1.1s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 607 | `swf5_xml_event_handler_context` | 2 | 18.2s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 608 | `swf6_case_insensitive` | 42 | 0.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 609 | `swf6_global_funcs` | 232 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 610 | `swf6_string_as_bool` | 15 | 0.9s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 611 | `swf6_to_5_cross_call` | 29 | 1.0s | [91](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) |
| 612 | `swf7_case_sensitive` | 44 | 0.3s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) |
| 613 | `swf7_global_funcs` | 232 | 0.3s | [46](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) |
| 614 | `tab_ordering_automatic_basic` | 92 | 1.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 615 | `tab_ordering_automatic_order_grid` | 21 | 1.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 616 | `tab_ordering_automatic_order_same_position` | 12 | 1.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 617 | `tab_ordering_children` | 208 | 1.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 618 | `tab_ordering_custom_basic` | 71 | 1.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 619 | `tab_ordering_custom_duplicate_index` | 22 | 1.0s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 620 | `tab_ordering_custom_i32_vs_u32` | 12 | 1.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 621 | `tab_ordering_custom_m1` | 29 | 0.8s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 622 | `tab_ordering_events` | 150 | 1.6s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 623 | `tab_ordering_events_mouse` | 65 | 27.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 624 | `tab_ordering_movieclip_enabled_default` | 462 | 1.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 625 | `tab_ordering_properties` | 293 | 1.2s | [93](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) |
| 626 | `tab_ordering_reverse` | 51 | 1.1s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 627 | `tab_ordering_tabbable` | 47 | 1.2s | [92](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) |
| 628 | `target_clip_removed` | 5 | 18.0s | [79](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 629 | `target_clip_swf5` | 2 | 0.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 630 | `target_clip_swf6` | 2 | 0.7s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 631 | `target_path` | 14 | 0.9s |  |
| 632 | `target_paths/swf4` | 818 | 19.0s |  |
| 633 | `tell_target` | 34 | 1.1s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 634 | `tell_target_invalid` | 5 | 17.9s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 635 | `tell_target_invalid_swf6` | 4 | 0.3s | [94](ruffle-tests/tests/swfs/avm1/_investigation/complete/TELLTARGET_PLAN.md) |
| 636 | `text_blocks_clicks` | 4 | 1.0s | [47](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) |
| 637 | `text_format` | 1146 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 638 | `text_format_display` | 21 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 639 | `text_format_font_max_length` | 2 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 640 | `text_format_get_text_extent_own` | 19 | 1.0s |  |
| 641 | `text_format_get_text_extent_undefined_width` | 10 | 0.9s |  |
| 642 | `text_format_prototype_lazy` | 35 | 1.1s |  |
| 643 | `text_format_rounding_swf7` | 840 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 644 | `text_format_rounding_swf8` | 840 | 0.3s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 645 | `textfield_asbroadcaster` | 14 | 1.0s |  |
| 646 | `textfield_background_color` | 11 | 26.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 647 | `textfield_border_color` | 11 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 648 | `textfield_cache_as_bitmap` | 1 | 1.2s | [6](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 649 | `textfield_get_text_format_args` | 269 | 1.4s |  |
| 650 | `textfield_maxchars` | 3 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 651 | `textfield_properties` | 44 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 652 | `textfield_props_swf6` | 210 | 0.9s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 653 | `textfield_props_swf7` | 210 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 654 | `textfield_props_swf8` | 210 | 0.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 655 | `textfield_set_text_format_args` | 232 | 1.5s |  |
| 656 | `textfield_set_text_format_text_change` | 37 | 2.2s |  |
| 657 | `textfield_text` | 7 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 658 | `textfield_variable` | 81 | 18.8s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 659 | `textsnapshot_available_text` | 20 | 1.4s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 660 | `textsnapshot_findtext` | 44 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 661 | `textsnapshot_gettext` | 55 | 1.5s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 662 | `textsnapshot_props_swf5` | 56 | 1.1s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 663 | `textsnapshot_props_swf6` | 56 | 1.0s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 664 | `textsnapshot_text_order` | 1 | 1.2s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) [96](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) |
| 665 | `this_scoping` | 52 | 18.3s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 666 | `this_swf5` | 41 | 1.1s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 667 | `this_swf6` | 41 | 0.8s | [97](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) |
| 668 | `this_swf7` | 41 | 0.3s | [98](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) |
| 669 | `timeline_function_def` | 7 | 18.4s |  |
| 670 | `timeout` | 0 | 6.1s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 671 | `timer_run_actions` | 18 | 26.5s | [99](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) |
| 672 | `trace` | 8 | 0.9s |  |
| 673 | `transform` | 70 | 1.0s | [19](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 674 | `try_catch_finally` | 118 | 1.0s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 675 | `try_catch_stack` | 16 | 0.9s | [101](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_STACK_PLAN.md) |
| 676 | `try_finally_simple` | 16 | 0.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 677 | `typeof` | 22 | 1.0s |  |
| 678 | `typeof_globals` | 7 | 0.9s |  |
| 679 | `uncaught_exception` | 1 | 0.8s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 680 | `uncaught_exception_bubbled` | 1 | 0.9s | [100](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 681 | `undefined_to_string_swf6` | 4 | 0.9s |  |
| 682 | `unescape` | 43 | 0.9s |  |
| 683 | `unload` | 52 | 17.9s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 684 | `unload_clip_event` | 4 | 17.8s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 685 | `unload_nested_child` | 5 | 18.0s | [62](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 686 | `unloadmovie` | 4 | 1.1s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 687 | `unloadmovie_method` | 3 | 1.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 688 | `unloadmovienum` | 13 | 1.0s | [54](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) [104](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) |
| 689 | `use_hand_cursor` | 8 | 0.9s |  |
| 690 | `variable_args` | 5 | 1.1s |  |
| 691 | `video_prototype_lazy` | 21 | 1.1s |  |
| 692 | `video_prototype_lazy_swf6_child` | 8 | 1.1s |  |
| 693 | `video_width_height` | 19 | 1.0s |  |
| 694 | `virtual_property_recursion_double_swf6` | 11 | 0.9s |  |
| 695 | `virtual_property_recursion_double_swf7` | 523 | 0.9s |  |
| 696 | `virtual_property_recursion_scope` | 11 | 1.0s |  |
| 697 | `virtual_property_recursion_swf7` | 262 | 0.9s |  |
| 698 | `waitforframe` | 7 | 0.9s |  |
| 699 | `waitforframe2` | 16 | 0.9s |  |
| 700 | `watch` | 117 | 1.2s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 701 | `watch_infinite_recursion` | 1 | 0.9s |  |
| 702 | `watch_proto_recursion` | 1 | 0.9s |  |
| 703 | `watch_recursion_double_swf7` | 3118 | 1.0s |  |
| 704 | `watch_recursion_swf7` | 1042 | 0.4s |  |
| 705 | `watch_textfield` | 12 | 1.0s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 706 | `watch_virtual_property` | 60 | 0.9s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 707 | `watch_virtual_property_proto` | 2 | 17.8s | [68](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |
| 708 | `with` | 46 | 0.9s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 709 | `with_return` | 2 | 0.8s |  |
| 710 | `with_variable_scopes` | 43 | 0.9s | [106](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 711 | `xml` | 15 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 712 | `xml_append_child` | 28 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 713 | `xml_append_child_with_parent` | 20 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 714 | `xml_attributes_read` | 4 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 715 | `xml_cdata` | 11 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 716 | `xml_child_nodes_edge_cases` | 4 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 717 | `xml_clone_expandos` | 19 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 718 | `xml_first_last_child` | 8 | 0.8s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 719 | `xml_getbytes` | 17 | 0.9s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 720 | `xml_has_child_nodes` | 3 | 32.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 721 | `xml_idmap` | 21 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 722 | `xml_ignore_comments` | 21 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 723 | `xml_ignore_white` | 34 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 724 | `xml_insert_before` | 20 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 725 | `xml_inspect_createmethods` | 15 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 726 | `xml_inspect_doctype` | 7 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 727 | `xml_inspect_parsexml` | 62 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 728 | `xml_inspect_xmldecl` | 7 | 2.1s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 729 | `xml_load` | 2 | 1.2s | [90](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN.md) [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 730 | `xml_namespaces` | 203 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 731 | `xml_parent_and_child` | 5 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 732 | `xml_remove_node` | 22 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 733 | `xml_reparenting` | 14 | 23.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 734 | `xml_siblings` | 10 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 735 | `xml_socket` | 8 | 1.4s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 736 | `xml_socket_close_in_handler` | 6 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 737 | `xml_socket_connect_null` | 12 | 23.9s |  |
| 738 | `xml_socket_on_data` | 7 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 739 | `xml_socket_segmented` | 29 | 0.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 740 | `xml_status_mismatched_tags` | 63 | 1.2s |  |
| 741 | `xml_stringify_utf16` | 4 | 1.4s |  |
| 742 | `xml_to_string` | 13 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 743 | `xml_to_string_comment` | 1 | 1.2s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 744 | `xml_unescaping` | 23 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |
| 745 | `xmlnode_proto` | 1 | 1.3s | [107](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) |

## Ruffle-Matched Tests

**17 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `asnative_instrument` | 172 | 172 | 1.7s |  |
| 2 | `asnative_sweep` | 73 | 74 | 1.9s |  |
| 3 | `attach_movie_export_not_yet_run` | 1 | 1 | 24.1s |  |
| 4 | `bitmap_data_thorough/copyPixels` | 68 | 68 | 1.4s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 5 | `bitmap_data_thorough/paletteMap` | 68 | 68 | 1.5s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 6 | `bitmap_data_thorough/perlinNoise` | 40 | 445 | 1.6s | [7](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) |
| 7 | `bitmapdata_custom_rectangle` | 27 | 27 | 1.0s |  |
| 8 | `edittext_onscroller` | 8 | 8 | 17.2s |  |
| 9 | `goto_rewind_movieclip_replace` | 1 | 1 | 18.7s |  |
| 10 | `load_cancel_via_unloadclip` | 2 | 2 | 0.9s |  |
| 11 | `load_cancel_via_unloadmovie` | 3 | 3 | 0.8s |  |
| 12 | `target_paths/swf5` | 654 | 654 | 0.3s |  |
| 13 | `target_paths/swf6` | 654 | 654 | 0.3s |  |
| 14 | `textfield_props_swf5` | 2 | 103 | 1.6s | [95](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) |
| 15 | `virtual_property_recursion_swf6` | 3 | 261 | 26.8s |  |
| 16 | `watch_recursion_double_swf6` | 4 | 3109 | 1.0s |  |
| 17 | `watch_recursion_swf6` | 1 | 1039 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `hitarea_remove_owner_drag` | 60.0% | 6 | 10 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `hitarea_remove_owner_drag` | 60.0% | 6/10 | 9 | 10 |  |
| 2 | `set_property_values/swf4` | 19.9% | 346/1743 | 1743 | 1571 |  |
| 3 | `globals_monkeypatch` | 16.0% | 49/306 | 222 | 306 |  |
| 4 | `external_interface_monkeypatch` | 2.9% | 4/139 | 65 | 139 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 1 | 1 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [ASSETNATIVEACCESSOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASSETNATIVEACCESSOR_PLAN.md) | 2 | 2 | 0 |
| 6 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_PLAN.md) | 17 | 17 | 0 |
| 7 | [BITMAP_DATA_THOROUGH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BITMAP_DATA_THOROUGH_PLAN.md) | 19 | 16 | 3 |
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
| 25 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 26 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 1 | 1 | 0 |
| 27 | [DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEPTH_REPLACEMENT_AUDIO_UNLOADING_PLAN.md) | 1 | 1 | 0 |
| 28 | [DEVICE_FONT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEVICE_FONT_RENDERING_PLAN.md) | 2 | 2 | 0 |
| 29 | [DISPLACEMENTMAPFILTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DISPLACEMENTMAPFILTER_PLAN.md) | 1 | 1 | 0 |
| 30 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 4 | 4 | 0 |
| 31 | [DRAWING_API_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/DRAWING_API_RENDERING_PLAN.md) | 4 | 4 | 0 |
| 32 | [EDITTEXT_DRAG_SELECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EDITTEXT_DRAG_SELECT_PLAN.md) | 1 | 1 | 0 |
| 33 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 2 | 2 | 0 |
| 34 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 13 | 13 | 0 |
| 35 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 7 | 7 | 0 |
| 36 | [FILLRECT_COLOR_CONSTANT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FILLRECT_COLOR_CONSTANT_PLAN.md) | 0 | 0 | 0 |
| 37 | [FLASH_CORRECT_REGRESSIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLASH_CORRECT_REGRESSIONS_PLAN.md) | 3 | 3 | 0 |
| 38 | [FLV_PLAYBACK_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FLV_PLAYBACK_PLAN.md) | 2 | 2 | 0 |
| 39 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 4 | 4 | 0 |
| 40 | [FOCUS_RECT_RENDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_RECT_RENDERING_PLAN.md) | 5 | 5 | 0 |
| 41 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 7 | 7 | 0 |
| 42 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 4 | 4 | 0 |
| 43 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 3 | 3 | 0 |
| 44 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 6 | 6 | 0 |
| 45 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 1 | 1 | 0 |
| 46 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GLOBALS_PLAN.md) | 26 | 26 | 0 |
| 47 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 16 | 16 | 0 |
| 48 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 21 | 21 | 0 |
| 49 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 50 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 1 | 1 | 0 |
| 51 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 1 | 1 | 0 |
| 52 | [LOADBITMAP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADBITMAP_PLAN.md) | 0 | 0 | 0 |
| 53 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_MULTI_SWF_PLAN.md) | 2 | 2 | 0 |
| 54 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 45 | 45 | 0 |
| 55 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_REMAINING_PLAN.md) | 4 | 4 | 0 |
| 56 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 4 | 4 | 0 |
| 57 | [LOCALCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOCALCONNECTION_PLAN.md) | 1 | 1 | 0 |
| 58 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 1 | 1 | 0 |
| 59 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 4 | 4 | 0 |
| 60 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 1 | 1 | 0 |
| 61 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 5 | 5 | 0 |
| 62 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 56 | 56 | 0 |
| 63 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 14 | 14 | 0 |
| 64 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 15 | 15 | 0 |
| 65 | [NATIVE_OBJECTS_UPDATED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_OBJECTS_UPDATED_PLAN.md) | 2 | 2 | 0 |
| 66 | [NETCONNECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NETCONNECTION_PLAN.md) | 2 | 2 | 0 |
| 67 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 2 | 2 | 0 |
| 68 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 4 | 4 | 0 |
| 69 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 8 | 0 |
| 70 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 3 | 3 | 0 |
| 71 | [PIXEL_TEXT_LAYOUT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PIXEL_TEXT_LAYOUT_PLAN.md) | 3 | 3 | 0 |
| 72 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 73 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 12 | 0 |
| 74 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 15 | 15 | 0 |
| 75 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 2 | 2 | 0 |
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
| 103 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNCOVERED_SMALL_TESTS_PLAN.md) | 15 | 15 | 0 |
| 104 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 12 | 12 | 0 |
| 105 | [VECTOR_PATH_HITTEST_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/VECTOR_PATH_HITTEST_PLAN.md) | 0 | 0 | 0 |
| 106 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 5 | 5 | 0 |
| 107 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 33 | 33 | 0 |
| | *(tests not in any document)* | 282 | 265 | 17 |
