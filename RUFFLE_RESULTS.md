# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2ceede96204b`  
**Date:** 2026-07-11 08:30 UTC  
**Total duration:** 3h33m17s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 296 | 1198 | 24.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1331** | **2487** | **53.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 38,554 | 148,815 | 25.9% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **191,137** | **326,765** | **58.5%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 54 | - | 1 |
| avm2 | 823 | 68 | - |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **924** | **68** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm2 | displayobject_rotation | 100% |
| avm2 | displayobject_alpha | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | unescape | 89% |
| avm2 | xml_has_property_via_in | 88% |
| avm2 | interactiveobject_enabled | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | prototype_set_null | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | eventdispatcher_tostring | 80% |
| avm2 | issue_5292 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 298 | - | 38265 | - |

**avm2 — newly passing:** `add`, `air_hidden_lookup`, `array_access`, `array_access_interpreter`, `array_access_no_pubns`, `array_concat`, `array_constr`, `array_delete`, `array_enumeration`, `array_enumeration_elements`, `array_every`, `array_filter`, `array_foreach`, `array_hasownproperty`, `array_holes`, `array_index_max`, `array_indexof`, `array_join`, `array_lastindexof`, `array_length`, `array_literal`, `array_map`, `array_pop`, `array_push`, `array_reborrow_bug`, `array_reverse`, `array_shift`, `array_slice`, `array_some`, `array_sort`, `array_sort_fun_swf12`, `array_sort_fun_swf13`, `array_sort_random`, `array_sort_swf10_32bit`, `array_sorton`, `array_sparse_ops`, `array_splice`, `array_splice2`, `array_splice_types`, `array_storage`, `array_tolocalestring`, `array_tostring`, `array_unshift`, `array_valueof`, `astype`, `astypelate`, `astypelate_propagates`, `away3d_advanced_shallow_water_demo`, `bitand`, `bitmapdata_applyfilter_blur`, `bitmapdata_applyfilter_colormatrix`, `bitmapdata_applyfilter_destpoint`, `bitmapdata_applyfilter_destpoint_edges`, `bitmapdata_colortransform`, `bitmapdata_draw`, `bitmapdata_draw_colortransform`, `bitmapdata_draw_filters`, `bitmapdata_draw_masks`, `bitmapdata_draw_rotation`, `bitmapdata_draw_self_via_graphic`, `bitmapdata_draw_stage`, `bitmapdata_drawwithquality`, `bitmapdata_fillrect`, `bitmapdata_filter_sourcerect`, `bitmapdata_opaque`, `bitmapdata_pixeldissolve_image`, `bitmapdata_sync`, `bitnot`, `bitor`, `bitxor`, `blend_multiply_alpha`, `blend_scroll`, `boolean_constr`, `boolean_negation`, `boolean_tostring`, `callee_in_initializer`, `callproplex_class`, `catch_class`, `catch_scope_slot`, `class_cast_call`, `class_enumeration`, `class_has_own_property`, `class_init_interpreter_mode`, `class_is`, `class_methods`, `class_object_properties`, `class_singleton`, `class_supercalls_errors`, `class_supercalls_mismatched`, `class_superclass_wrong_order`, `class_to_locale_string`, `class_to_string`, `class_value_of`, `closures`, `coerce_property`, `coerce_return_type`, `coerce_return_type_fail`, `coerce_return_void`, `coerce_string`, `coerce_string_precision`, `construct_errors_swf10`, `constructor_call`, `control_flow_bool`, `control_flow_stricteq`, `convert_boolean`, `convert_integer`, `convert_number`, `convert_uinteger`, `declocal`, `declocal_i`, `decrement`, `decrement_i`, `default_values`, `displayobject_blendmode`, `displayobject_colortransform_nested`, `displayobject_getbounds_shape`, `displayobject_mask_self_referential`, `displayobject_set_matrix_nested`, `divide`, `equals`, `error_stack_trace_debug_swf17`, `error_stack_trace_debug_swf18`, `error_stack_trace_release_swf17`, `error_stack_trace_release_swf18`, `es3_inheritance`, `es4_inheritance`, `es4_interfaces`, `es4_method_binding`, `es4_oop_prototypes`, `es4_protected_inheritance`, `falsiness`, `finddef`, `function_call`, `function_call_arguments`, `function_call_arguments_enumerate`, `function_call_coercion`, `function_call_default`, `function_call_rest`, `function_call_types`, `function_call_via_apply`, `function_call_via_call`, `function_display_anonymous`, `function_length`, `function_object`, `function_proto`, `function_to_locale_string`, `function_to_string`, `function_type`, `function_value_of`, `get_slot_edge_cases`, `getglobalslot`, `getouterscope`, `getter_different_namespace_setter`, `graphics_bitmaps`, `graphics_direct_commands`, `graphics_gradients`, `graphics_gradients_nulls`, `graphics_round_rects`, `graphics_simple_shapes`, `greaterequals`, `greaterthan`, `has_own_property`, `hasownproperty_namespaces`, `if_eq`, `if_gt`, `if_gte`, `if_lt`, `if_lte`, `if_ne`, `if_stricteq`, `if_strictne`, `in`, `inclocal`, `inclocal_i`, `increment`, `increment_i`, `instanceof`, `int_constr`, `int_edge_cases`, `int_instanceof`, `int_tofixed`, `int_tostring`, `interface_namespaces`, `is_finite`, `is_nan`, `is_prototype_of`, `issue_10221`, `issue_14901`, `istype`, `istypelate`, `istypelate_coerce`, `json_version_gated`, `lessequals`, `lessthan`, `lshift`, `math`, `modulo`, `movieclip_stop`, `multiply`, `negate`, `negative_volume_panned`, `newactivation_in_script_init`, `newclass_twice`, `number_autoconv_array_sort_32bit`, `number_constr`, `number_toexponential`, `number_toexponential2`, `number_tofixed`, `number_toprecision`, `obfuscated_class_names`, `object_enumeration`, `object_prototype`, `object_to_locale_string`, `object_to_string`, `object_value_of`, `op_coerce`, `op_coerce_x`, `op_escxattr`, `op_escxelem`, `op_lookupswitch`, `optimize_coerce`, `param_default_value_has_zero_cpool_index`, `parse_float`, `pixelbender_effect_BlurredFocus`, `pixelbender_effect_glassDisplace`, `pixelbender_effect_smudge`, `pixelbender_effect_tintype`, `pixelbender_effect_twirl`, `pixelbender_images`, `property_priority`, `property_priority_three_level`, `propertyisenumerable_namespaces`, `rshift`, `set_property_is_enumerable`, `slots_force_autoassigned`, `sprite_with_frames`, `stage3d_agal_cross_product`, `stage3d_bitmap`, `stage3d_float1_index`, `stage3d_fractal`, `stage3d_ignore_sampler_override`, `stage3d_program_constants_bytearray_be`, `stage3d_program_constants_bytearray_le`, `stage3d_raytrace`, `stage3d_stencil`, `stage3d_texture`, `stage3d_texture_bytearray`, `stage3d_texture_bytearray_compressed_alpha`, `stage3d_texture_bytearray_compressed_raw_alpha`, `stage3d_triangle`, `stage3d_triangle_bytes4`, `stage3d_triangle_float1`, `stage3d_triangle_index_upload`, `static_var_with_this_in_ctor`, `stored_properties`, `strict_equality`, `string_call`, `string_case`, `string_char_at`, `string_char_code_at`, `string_concat_fromcharcode`, `string_constr`, `string_indexof_lastindexof`, `string_length`, `string_locale_compare`, `string_relational_compare`, `string_slice_substr_substring`, `string_substr_negative`, `string_substr_weird`, `subtract`, `super_get_call`, `supercall_two_classobjects`, `throw`, `truthiness`, `try_catch_typed`, `typeof`, `uint_constr`, `uint_tofixed`, `uint_tostring`, `unchecked_function`, `urshift`, `verify_abnormal_loop`, `verify_exception_targets_edge_case`, `verify_lookup_switch_edge_case`, `verify_unreachable_exception`, `versioned_isplaying`, `virtual_properties`, `with`

*Comparing `d4bd5b2fad95` → `2ceede96204b`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 51m30s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 4.3s — slowest: `netstream_play_flv_screen` (34.9s)

### avm2

- **Pass:** 296/1198 (24.7%)
- **Duration:** 1h16m00s across 30 shards
- **Lines:** 38,554/148,815 matching (25.9%)
- **Avg test duration:** 3.7s — slowest: `away3d_advanced_shallow_water_demo` (60.3s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 26m23s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.5s — slowest: `MovieClip-v8` (65.7s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 24m58s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 13.4s — slowest: `matrix_test` (105.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m04s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.8s — slowest: `enum` (21.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m04s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 15.2s — slowest: `opcode_guard_test2` (21.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m21s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.0s — slowest: `tags_after_last_showframe` (21.0s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m04s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.1s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (22.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.3s — slowest: `label` (21.3s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 4m59s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.2s — slowest: `lv_cross_swf_version` (21.1s)
