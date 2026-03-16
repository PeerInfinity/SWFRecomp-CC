# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-16 04:01 UTC

**Git SHA**: `d5fb5371bb`

**Run Duration**: 27m 41s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **91** (91.0%) |
| Failing | 9 |
| Total expected lines | 10513 |
| Matching lines | 8933 (85.0%) |
| Mismatched lines | 1580 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 77.8% |
| Runtime Segfault | 2 | 22.2% |

## Passing Tests

**91 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 20.3s |  |
| 2 | `action_to_integer` | 28 | 21.3s |  |
| 3 | `add` | 28 | 21.8s |  |
| 4 | `add2` | 354 | 21.9s | [1](ruffle-tests/_investigation/complete/add2.md) |
| 5 | `add_property` | 15 | 22.1s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `add_swf4` | 28 | 21.9s |  |
| 7 | `add_swf5` | 28 | 20.8s |  |
| 8 | `arguments` | 127 | 19.3s | [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [45](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) |
| 9 | `array_call_method` | 9 | 22.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 10 | `array_concat` | 98 | 19.7s |  |
| 11 | `array_constructor` | 30 | 21.1s |  |
| 12 | `array_enumerate` | 4 | 20.4s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 13 | `array_length` | 42 | 21.8s |  |
| 14 | `array_properties` | 36 | 22.1s |  |
| 15 | `array_prototyping` | 12 | 20.9s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 16 | `array_slice` | 34 | 21.7s |  |
| 17 | `array_sort` | 161 | 24.2s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 18 | `array_sort_random` | 443 | 19.1s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 19 | `array_splice` | 207 | 19.7s |  |
| 20 | `array_trivial` | 209 | 19.8s |  |
| 21 | `as1_constructor_v6` | 35 | 19.1s |  |
| 22 | `as1_constructor_v7` | 35 | 19.0s |  |
| 23 | `as2_oop` | 13 | 19.6s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 24 | `as2_super_and_this_v6` | 97 | 19.1s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 25 | `as2_super_and_this_v8` | 85 | 20.2s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `as2_super_via_manual_prototype` | 40 | 22.5s | [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) [44](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) |
| 27 | `as_broadcaster` | 41 | 21.0s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 28 | `as_broadcaster_initialize` | 10 | 21.1s |  |
| 29 | `as_broadcaster_undef` | 89 | 20.7s | [3](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) |
| 30 | `as_set_prop_flags` | 79 | 21.0s | [17](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `as_set_prop_flags_version` | 31 | 19.3s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 32 | `as_set_prop_flags_version_swf5` | 1 | 19.6s |  |
| 33 | `as_set_prop_flags_version_swf6` | 1 | 19.5s |  |
| 34 | `as_set_prop_flags_version_swf7` | 1 | 21.8s |  |
| 35 | `as_set_prop_flags_version_swf8` | 1 | 25.7s |  |
| 36 | `as_set_prop_flags_version_swf9` | 1 | 22.8s |  |
| 37 | `as_transformed_flag` | 20 | 20.7s |  |
| 38 | `asnative` | 34 | 19.2s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 39 | `asnew` | 34 | 19.8s | [4](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) |
| 40 | `attach_movie` | 59 | 19.9s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 41 | `attach_movie_stop` | 3 | 20.7s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 42 | `bad_placeobject_clipaction` | 2 | 21.4s |  |
| 43 | `bad_swf_tag_past_eof` | 0 | 22.0s |  |
| 44 | `bitand` | 1058 | 26.4s |  |
| 45 | `bitmap_data` | 1126 | 22.3s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 46 | `bitmap_data_colortransform` | 0 | 19.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 47 | `bitmap_data_compare` | 40 | 19.7s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 48 | `bitmap_data_copypixels` | 17 | 20.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 49 | `bitmap_data_draw_cliprect` | 13 | 20.6s |  |
| 50 | `bitmap_data_fillrect` | 0 | 22.9s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 51 | `bitmap_data_hittest` | 132 | 23.2s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 52 | `bitmap_data_max_size_swf10` | 12 | 23.0s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 53 | `bitmap_data_max_size_swf9` | 10 | 19.6s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 54 | `bitmap_data_noise` | 631 | 18.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 55 | `bitmap_data_perlinnoise` | 0 | 20.5s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 56 | `bitmap_data_pixeldissolve_image` | 0 | 19.4s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 57 | `bitmap_data_threshold` | 176 | 19.1s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 58 | `bitmapdata_applyfilter_colormatrix` | 0 | 19.2s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 59 | `bitmapdata_channels` | 19 | 21.8s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) |
| 60 | `bitor` | 1058 | 23.3s |  |
| 61 | `biturshift` | 14 | 19.1s |  |
| 62 | `biturshift_swf8` | 14 | 19.5s |  |
| 63 | `bitxor` | 1058 | 23.0s |  |
| 64 | `boxed_primitives` | 24 | 19.8s | [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 65 | `button_children` | 8 | 19.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 66 | `button_goto` | 4 | 19.5s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 67 | `button_keypress` | 3 | 19.0s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 68 | `button_order` | 2 | 19.2s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 69 | `button_properties_special_cases` | 22 | 21.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 70 | `button_v5` | 18 | 20.1s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 71 | `button_v6` | 18 | 18.5s | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 72 | `call` | 63 | 19.6s | [7](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) |
| 73 | `call_method_empty_name` | 1 | 22.6s |  |
| 74 | `capabilities_resolution` | 8 | 20.3s |  |
| 75 | `catch_references_registers` | 2 | 19.8s | [67](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) |
| 76 | `clip_constructors` | 8 | 19.6s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [48](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) |
| 77 | `clip_event_propagation_order` | 17 | 20.0s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 78 | `clip_events` | 19 | 21.8s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) [70](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) |
| 79 | `clone_sprite_edittext` | 94 | 21.5s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 80 | `clone_sprite_edittext_dynamic` | 86 | 22.1s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 81 | `clone_sprite_types` | 24 | 21.2s | [8](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |
| 82 | `closure_scope` | 7 | 21.0s | [71](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) |
| 83 | `coerce_to_object_monkeypatch` | 129 | 24.0s | [68](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) |
| 84 | `coerce_to_primitive_resolve` | 17 | 20.2s | [46](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) [47](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) |
| 85 | `color` | 57 | 19.7s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 86 | `color_transform` | 48 | 19.8s | [10](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) |
| 87 | `conflicting_instance_names` | 23 | 20.8s |  |
| 88 | `constructor_function` | 2 | 18.8s |  |
| 89 | `context_menu` | 39 | 20.8s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 90 | `context_menu_item` | 41 | 23.2s | [25](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) |
| 91 | `create_empty_movie_clip` | 3 | 19.1s | [39](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `bitmap_filters` | 20.5s | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [41](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) |
| 2 | `click_block` | 21.3s | [38](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `bitmap_data_pixeldissolve` | 7.6% | 82/1075 | 1055 | 1075 | [5](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) [23](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 2 | `button_key_events` | 6.7% | 1/15 | 15 | 14 | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 3 | `button_keypress_vs_tab` | 4.8% | 1/21 | 21 | 20 | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 4 | `asfunction` | 0.0% | 0/11 | 0 | 11 | [22](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) |
| 5 | `button_key_events_special` | 0.0% | 0/46 | 46 | 45 | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 6 | `button_keypress_vs_press` | 0.0% | 0/26 | 26 | 25 | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |
| 7 | `button_keypress_vs_textinput` | 0.0% | 0/5 | 5 | 4 | [6](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/complete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 4 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/_investigation/complete/ASBROADCASTER_PLAN.md) | 2 | 2 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 2 | 2 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/_investigation/blocked/BITMAP_DATA_PLAN.md) | 16 | 14 | 2 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/_investigation/complete/BUTTON_PLAN.md) | 12 | 7 | 5 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 1 | 1 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 5 | 5 | 0 |
| 9 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 0 | 0 | 0 |
| 10 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/COLOR_OBJECT_PLAN.md) | 2 | 2 | 0 |
| 11 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 0 | 0 | 0 |
| 12 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 0 | 0 | 0 |
| 13 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 14 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 0 | 0 | 0 |
| 15 | [DRAG_DROP_PLAN.md](ruffle-tests/_investigation/complete/DRAG_DROP_PLAN.md) | 0 | 0 | 0 |
| 16 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 0 | 0 | 0 |
| 17 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 2 | 2 | 0 |
| 18 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 0 | 0 | 0 |
| 19 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 0 | 0 | 0 |
| 20 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 0 | 0 | 0 |
| 21 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 0 | 0 | 0 |
| 22 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 1 | 0 | 1 |
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 3 | 2 | 1 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 0 | 0 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/blocked/GLOBALS_PLAN.md) | 3 | 3 | 0 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/blocked/HIT_TESTING_PLAN.md) | 0 | 0 | 0 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 28 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 0 | 0 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 0 | 0 | 0 |
| 30 | [issue_768.md](ruffle-tests/_investigation/complete/issue_768.md) | 0 | 0 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 0 | 0 | 0 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/_investigation/complete/LOADMOVIE_PLAN.md) | 0 | 0 | 0 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 0 | 0 | 0 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/_investigation/complete/LOADVARIABLES_PLAN.md) | 0 | 0 | 0 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/_investigation/complete/LOCKROOT_PLAN.md) | 0 | 0 | 0 |
| 36 | [MATH_PLAN.md](ruffle-tests/_investigation/complete/MATH_PLAN.md) | 0 | 0 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 0 | 0 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 1 | 0 | 1 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIP_PLAN.md) | 9 | 9 | 0 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 0 | 0 | 0 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 5 | 4 | 1 |
| 42 | [object_string_coerce.md](ruffle-tests/_investigation/complete/object_string_coerce.md) | 0 | 0 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/complete/OBJECT_WATCH_PLAN.md) | 0 | 0 | 0 |
| 44 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 4 | 4 | 0 |
| 45 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 1 | 1 | 0 |
| 46 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 1 | 1 | 0 |
| 47 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 5 | 5 | 0 |
| 48 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/complete/REGISTERCLASS_PLAN.md) | 3 | 3 | 0 |
| 49 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 0 | 0 | 0 |
| 50 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 0 | 0 | 0 |
| 51 | [SELECTION_PLAN.md](ruffle-tests/_investigation/complete/SELECTION_PLAN.md) | 0 | 0 | 0 |
| 52 | [SOUND_CLASS_PLAN.md](ruffle-tests/_investigation/complete/SOUND_CLASS_PLAN.md) | 0 | 0 | 0 |
| 53 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 0 | 0 | 0 |
| 54 | [STAGE_PLAN.md](ruffle-tests/_investigation/complete/STAGE_PLAN.md) | 0 | 0 | 0 |
| 55 | [string_coercion.md](ruffle-tests/_investigation/complete/string_coercion.md) | 0 | 0 | 0 |
| 56 | [STRING_PLAN.md](ruffle-tests/_investigation/complete/STRING_PLAN.md) | 0 | 0 | 0 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/_investigation/complete/STYLESHEET_PLAN.md) | 0 | 0 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 0 | 0 | 0 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PLAN.md) | 0 | 0 | 0 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 0 | 0 | 0 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/blocked/TELLTARGET_PLAN.md) | 0 | 0 | 0 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/complete/TEXTFIELD_PLAN.md) | 0 | 0 | 0 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 0 | 0 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/_investigation/complete/THIS_BINDING_PLAN.md) | 0 | 0 | 0 |
| 65 | [this_swf7.md](ruffle-tests/_investigation/complete/this_swf7.md) | 0 | 0 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/_investigation/complete/TIMER_PLAN.md) | 0 | 0 | 0 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 1 | 1 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 1 | 1 | 0 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 0 | 0 | 0 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/complete/UNLOAD_PLAN.md) | 3 | 3 | 0 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/complete/WITH_SCOPE_PLAN.md) | 1 | 1 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/_investigation/complete/XML_PLAN.md) | 0 | 0 | 0 |
| | *(tests not in any document)* | 33 | 33 | 0 |
