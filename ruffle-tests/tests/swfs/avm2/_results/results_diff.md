# Ruffle Test Results Diff

**Previous:** `d4bd5b2fad95` (2026-07-11T08:19:09.024109+00:00)
**Current:** `2ceede96204b` (2026-07-11T08:30:42.339234+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 8 | 296 | +288 |
| Total | 1198 | 1198 | 0 |
| Pass rate | 0.7% | 24.7% | +24.0% |
| Mismatched lines | 148526 | 110261 | -38265 |
|   Decreased | | | -38265 |

## Newly Passing (288)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `add` | runtime_error | 0/1058 | 1058/1058 |
| `air_hidden_lookup` | runtime_error | 0/2 | 2/2 |
| `array_access` | runtime_error | 0/18 | 18/18 |
| `array_access_interpreter` | runtime_error | 0/4 | 4/4 |
| `array_access_no_pubns` | runtime_error | 0/2 | 2/2 |
| `array_concat` | runtime_error | 0/41 | 41/41 |
| `array_constr` | runtime_error | 1/10 | 10/10 |
| `array_delete` | runtime_error | 0/44 | 44/44 |
| `array_enumeration` | runtime_error | 0/10 | 10/10 |
| `array_enumeration_elements` | runtime_error | 0/11 | 11/11 |
| `array_every` | runtime_error | 0/8 | 8/8 |
| `array_filter` | runtime_error | 0/6 | 6/6 |
| `array_foreach` | runtime_error | 1/18 | 18/18 |
| `array_hasownproperty` | runtime_error | 1/11 | 11/11 |
| `array_holes` | runtime_error | 1/9 | 9/9 |
| `array_index_max` | runtime_error | 0/84 | 84/84 |
| `array_indexof` | runtime_error | 1/25 | 25/25 |
| `array_join` | runtime_error | 1/26 | 26/26 |
| `array_lastindexof` | runtime_error | 1/29 | 29/29 |
| `array_length` | runtime_error | 1/14 | 14/14 |
| `array_literal` | runtime_error | 0/3 | 3/3 |
| `array_map` | runtime_error | 0/8 | 8/8 |
| `array_pop` | runtime_error | 0/52 | 52/52 |
| `array_push` | runtime_error | 0/24 | 24/24 |
| `array_reborrow_bug` | runtime_error | 0/6 | 6/6 |
| `array_reverse` | runtime_error | 0/28 | 28/28 |
| `array_shift` | runtime_error | 0/51 | 51/51 |
| `array_slice` | runtime_error | 0/39 | 39/39 |
| `array_some` | runtime_error | 0/8 | 8/8 |
| `array_sort` | runtime_error | 0/297 | 297/297 |
| `array_sort_fun_swf12` | runtime_error | 0/2 | 2/2 |
| `array_sort_fun_swf13` | runtime_error | 0/2 | 2/2 |
| `array_sort_random` | runtime_error | 0/210 | 210/210 |
| `array_sort_swf10_32bit` | runtime_error | 0/1 | 1/1 |
| `array_sorton` | runtime_error | 0/545 | 545/545 |
| `array_sparse_ops` | runtime_error | 0/41 | 41/41 |
| `array_splice` | runtime_error | 0/133 | 133/133 |
| `array_splice2` | runtime_error | 0/428 | 428/428 |
| `array_splice_types` | runtime_error | 0/48 | 48/48 |
| `array_storage` | runtime_error | 0/8 | 8/8 |
| `array_tolocalestring` | runtime_error | 1/9 | 9/9 |
| `array_tostring` | runtime_error | 1/12 | 12/12 |
| `array_unshift` | runtime_error | 0/24 | 24/24 |
| `array_valueof` | runtime_error | 1/9 | 9/9 |
| `astype` | runtime_error | 0/28 | 28/28 |
| `astypelate` | runtime_error | 0/24 | 24/24 |
| `astypelate_propagates` | runtime_error | 0/1 | 1/1 |
| `away3d_advanced_shallow_water_demo` | runtime_error | 0/0 | 0/0 |
| `bitand` | runtime_error | 0/1058 | 1058/1058 |
| `bitmapdata_applyfilter_blur` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_applyfilter_colormatrix` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_applyfilter_destpoint` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_applyfilter_destpoint_edges` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_colortransform` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_draw` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_draw_colortransform` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_draw_filters` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_draw_masks` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_draw_rotation` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_draw_self_via_graphic` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_draw_stage` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_drawwithquality` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_fillrect` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_filter_sourcerect` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_opaque` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_pixeldissolve_image` | runtime_error | 0/0 | 0/0 |
| `bitmapdata_sync` | runtime_error | 0/0 | 0/0 |
| `bitnot` | runtime_error | 0/46 | 46/46 |
| `bitor` | runtime_error | 0/1058 | 1058/1058 |
| `bitxor` | runtime_error | 0/1058 | 1058/1058 |
| `blend_multiply_alpha` | runtime_error | 0/0 | 0/0 |
| `blend_scroll` | runtime_error | 0/0 | 0/0 |
| `boolean_constr` | runtime_error | 1/32 | 32/32 |
| `boolean_negation` | runtime_error | 0/30 | 30/30 |
| `boolean_tostring` | runtime_error | 1/8 | 8/8 |
| `callee_in_initializer` | runtime_error | 0/6 | 6/6 |
| `callproplex_class` | runtime_error | 0/1 | 1/1 |
| `catch_class` | runtime_error | 0/6 | 6/6 |
| `catch_scope_slot` | runtime_error | 0/7 | 7/7 |
| `class_cast_call` | runtime_error | 1/14 | 14/14 |
| `class_enumeration` | runtime_error | 0/4 | 4/4 |
| `class_has_own_property` | runtime_error | 0/2 | 2/2 |
| `class_init_interpreter_mode` | runtime_error | 0/1 | 1/1 |
| `class_is` | runtime_error | 1/32 | 32/32 |
| `class_methods` | runtime_error | 4/5 | 5/5 |
| `class_object_properties` | runtime_error | 0/10 | 10/10 |
| `class_singleton` | runtime_error | 0/18 | 18/18 |
| `class_supercalls_errors` | runtime_error | 1/35 | 35/35 |
| `class_supercalls_mismatched` | runtime_error | 1/26 | 26/26 |
| `class_superclass_wrong_order` | runtime_error | 0/1 | 1/1 |
| `class_to_locale_string` | runtime_error | 1/2 | 2/2 |
| `class_to_string` | runtime_error | 1/2 | 2/2 |
| `class_value_of` | runtime_error | 1/2 | 2/2 |
| `closures` | runtime_error | 0/12 | 12/12 |
| `coerce_property` | runtime_error | 0/33 | 33/33 |
| `coerce_return_type` | runtime_error | 0/40 | 40/40 |
| `coerce_return_type_fail` | runtime_error | 0/2 | 2/2 |
| `coerce_return_void` | output_mismatch | 1/3 | 3/3 |
| `coerce_string` | runtime_error | 0/86 | 86/86 |
| `coerce_string_precision` | runtime_error | 0/28 | 28/28 |
| `construct_errors_swf10` | runtime_error | 0/8 | 8/8 |
| `constructor_call` | runtime_error | 0/3 | 3/3 |
| `control_flow_bool` | runtime_error | 0/4 | 4/4 |
| `control_flow_stricteq` | runtime_error | 0/8 | 8/8 |
| `convert_boolean` | runtime_error | 0/30 | 30/30 |
| `convert_integer` | runtime_error | 0/90 | 90/90 |
| `convert_number` | runtime_error | 0/56 | 56/56 |
| `convert_uinteger` | runtime_error | 0/90 | 90/90 |
| `declocal` | runtime_error | 0/46 | 46/46 |
| `declocal_i` | runtime_error | 0/46 | 46/46 |
| `decrement` | runtime_error | 0/46 | 46/46 |
| `decrement_i` | runtime_error | 0/46 | 46/46 |
| `default_values` | output_mismatch | 1/7 | 7/7 |
| `displayobject_blendmode` | runtime_error | 0/0 | 0/0 |
| `displayobject_colortransform_nested` | runtime_error | 0/0 | 0/0 |
| `displayobject_getbounds_shape` | runtime_error | 0/0 | 0/0 |
| `displayobject_mask_self_referential` | runtime_error | 0/0 | 0/0 |
| `displayobject_set_matrix_nested` | runtime_error | 0/0 | 0/0 |
| `divide` | runtime_error | 0/1058 | 1058/1058 |
| `equals` | runtime_error | 1/512 | 512/512 |
| `error_stack_trace_debug_swf17` | runtime_error | 0/0 | 0/0 |
| `error_stack_trace_debug_swf18` | runtime_error | 0/0 | 0/0 |
| `error_stack_trace_release_swf17` | runtime_error | 0/0 | 0/0 |
| `error_stack_trace_release_swf18` | runtime_error | 0/0 | 0/0 |
| `es3_inheritance` | runtime_error | 0/31 | 31/31 |
| `es4_inheritance` | runtime_error | 7/30 | 30/30 |
| `es4_interfaces` | runtime_error | 0/30 | 30/30 |
| `es4_method_binding` | runtime_error | 0/8 | 8/8 |
| `es4_oop_prototypes` | runtime_error | 0/14 | 14/14 |
| `es4_protected_inheritance` | runtime_error | 0/6 | 6/6 |
| `falsiness` | runtime_error | 0/30 | 30/30 |
| `finddef` | runtime_error | 0/3 | 3/3 |
| `function_call` | runtime_error | 0/12 | 12/12 |
| `function_call_arguments` | runtime_error | 0/46 | 46/46 |
| `function_call_arguments_enumerate` | runtime_error | 0/5 | 5/5 |
| `function_call_coercion` | runtime_error | 0/108 | 108/108 |
| `function_call_default` | runtime_error | 0/6 | 6/6 |
| `function_call_rest` | runtime_error | 0/22 | 22/22 |
| `function_call_types` | runtime_error | 0/3 | 3/3 |
| `function_call_via_apply` | runtime_error | 0/11 | 11/11 |
| `function_call_via_call` | runtime_error | 0/3 | 3/3 |
| `function_display_anonymous` | runtime_error | 0/7 | 7/7 |
| `function_length` | runtime_error | 0/6 | 6/6 |
| `function_object` | runtime_error | 0/2 | 2/2 |
| `function_proto` | runtime_error | 0/5 | 5/5 |
| `function_to_locale_string` | runtime_error | 0/4 | 4/4 |
| `function_to_string` | runtime_error | 0/4 | 4/4 |
| `function_type` | runtime_error | 0/6 | 6/6 |
| `function_value_of` | runtime_error | 0/4 | 4/4 |
| `get_slot_edge_cases` | runtime_error | 0/1 | 1/1 |
| `getglobalslot` | runtime_error | 0/1 | 1/1 |
| `getouterscope` | runtime_error | 0/8 | 8/8 |
| `getter_different_namespace_setter` | runtime_error | 0/2 | 2/2 |
| `graphics_bitmaps` | runtime_error | 0/0 | 0/0 |
| `graphics_direct_commands` | runtime_error | 0/0 | 0/0 |
| `graphics_gradients` | runtime_error | 0/0 | 0/0 |
| `graphics_gradients_nulls` | runtime_error | 0/0 | 0/0 |
| `graphics_round_rects` | runtime_error | 0/0 | 0/0 |
| `graphics_simple_shapes` | runtime_error | 0/0 | 0/0 |
| `greaterequals` | runtime_error | 1/512 | 512/512 |
| `greaterthan` | runtime_error | 1/512 | 512/512 |
| `has_own_property` | runtime_error | 0/102 | 102/102 |
| `hasownproperty_namespaces` | runtime_error | 1/2 | 2/2 |
| `if_eq` | runtime_error | 0/10 | 10/10 |
| `if_gt` | runtime_error | 0/1 | 1/1 |
| `if_gte` | runtime_error | 0/10 | 10/10 |
| `if_lt` | runtime_error | 0/1 | 1/1 |
| `if_lte` | runtime_error | 0/10 | 10/10 |
| `if_ne` | runtime_error | 0/7 | 7/7 |
| `if_stricteq` | runtime_error | 0/6 | 6/6 |
| `if_strictne` | runtime_error | 0/11 | 11/11 |
| `in` | runtime_error | 0/102 | 102/102 |
| `inclocal` | runtime_error | 0/46 | 46/46 |
| `inclocal_i` | runtime_error | 0/46 | 46/46 |
| `increment` | runtime_error | 0/46 | 46/46 |
| `increment_i` | runtime_error | 0/46 | 46/46 |
| `instanceof` | runtime_error | 0/58 | 58/58 |
| `int_constr` | runtime_error | 1/92 | 92/92 |
| `int_edge_cases` | runtime_error | 0/19 | 19/19 |
| `int_instanceof` | runtime_error | 0/3 | 3/3 |
| `int_tofixed` | runtime_error | 0/1215 | 1215/1215 |
| `int_tostring` | runtime_error | 0/3375 | 3375/3375 |
| `interface_namespaces` | runtime_error | 0/78 | 78/78 |
| `is_finite` | runtime_error | 1/46 | 46/46 |
| `is_nan` | runtime_error | 1/46 | 46/46 |
| `is_prototype_of` | runtime_error | 0/12 | 12/12 |
| `issue_10221` | runtime_error | 0/2 | 2/2 |
| `issue_14901` | runtime_error | 0/1 | 1/1 |
| `istype` | runtime_error | 0/24 | 24/24 |
| `istypelate` | runtime_error | 0/58 | 58/58 |
| `istypelate_coerce` | runtime_error | 2/198 | 198/198 |
| `json_version_gated` | runtime_error | 0/1 | 1/1 |
| `lessequals` | runtime_error | 1/512 | 512/512 |
| `lessthan` | runtime_error | 1/512 | 512/512 |
| `lshift` | runtime_error | 0/1058 | 1058/1058 |
| `math` | runtime_error | 0/497 | 497/497 |
| `modulo` | runtime_error | 0/1058 | 1058/1058 |
| `movieclip_stop` | runtime_error | 1/1 | 1/1 |
| `multiply` | runtime_error | 0/1058 | 1058/1058 |
| `negate` | runtime_error | 0/30 | 30/30 |
| `negative_volume_panned` | runtime_error | 0/0 | 0/0 |
| `newactivation_in_script_init` | runtime_error | 0/3 | 3/3 |
| `newclass_twice` | runtime_error | 0/3 | 3/3 |
| `number_autoconv_array_sort_32bit` | runtime_error | 0/1 | 1/1 |
| `number_constr` | runtime_error | 1/58 | 58/58 |
| `number_toexponential` | runtime_error | 0/378 | 378/378 |
| `number_toexponential2` | runtime_error | 0/35 | 35/35 |
| `number_tofixed` | runtime_error | 0/378 | 378/378 |
| `number_toprecision` | runtime_error | 0/350 | 350/350 |
| `obfuscated_class_names` | runtime_error | 0/3 | 3/3 |
| `object_enumeration` | runtime_error | 0/10 | 10/10 |
| `object_prototype` | runtime_error | 0/4 | 4/4 |
| `object_to_locale_string` | runtime_error | 1/2 | 2/2 |
| `object_to_string` | runtime_error | 1/2 | 2/2 |
| `object_value_of` | runtime_error | 0/2 | 2/2 |
| `op_coerce` | runtime_error | 0/54 | 54/54 |
| `op_coerce_x` | runtime_error | 0/54 | 54/54 |
| `op_escxattr` | runtime_error | 0/2 | 2/2 |
| `op_escxelem` | runtime_error | 0/2 | 2/2 |
| `op_lookupswitch` | runtime_error | 0/4 | 4/4 |
| `optimize_coerce` | runtime_error | 0/1 | 1/1 |
| `param_default_value_has_zero_cpool_index` | runtime_error | 0/1 | 1/1 |
| `parse_float` | runtime_error | 1/80 | 80/80 |
| `pixelbender_effect_BlurredFocus` | runtime_error | 0/0 | 0/0 |
| `pixelbender_effect_glassDisplace` | runtime_error | 0/0 | 0/0 |
| `pixelbender_effect_smudge` | runtime_error | 0/0 | 0/0 |
| `pixelbender_effect_tintype` | runtime_error | 0/0 | 0/0 |
| `pixelbender_effect_twirl` | runtime_error | 0/0 | 0/0 |
| `pixelbender_images` | runtime_error | 0/0 | 0/0 |
| `property_priority` | runtime_error | 0/22 | 22/22 |
| `property_priority_three_level` | runtime_error | 0/6 | 6/6 |
| `propertyisenumerable_namespaces` | runtime_error | 1/6 | 6/6 |
| `rshift` | runtime_error | 0/1058 | 1058/1058 |
| `set_property_is_enumerable` | runtime_error | 0/85 | 85/85 |
| `slots_force_autoassigned` | runtime_error | 0/1 | 1/1 |
| `sprite_with_frames` | runtime_error | 0/0 | 0/0 |
| `stage3d_agal_cross_product` | runtime_error | 0/0 | 0/0 |
| `stage3d_bitmap` | runtime_error | 0/0 | 0/0 |
| `stage3d_float1_index` | runtime_error | 0/0 | 0/0 |
| `stage3d_fractal` | runtime_error | 0/0 | 0/0 |
| `stage3d_ignore_sampler_override` | runtime_error | 0/0 | 0/0 |
| `stage3d_program_constants_bytearray_be` | runtime_error | 0/0 | 0/0 |
| `stage3d_program_constants_bytearray_le` | runtime_error | 0/0 | 0/0 |
| `stage3d_raytrace` | runtime_error | 0/0 | 0/0 |
| `stage3d_stencil` | runtime_error | 0/0 | 0/0 |
| `stage3d_texture` | runtime_error | 0/0 | 0/0 |
| `stage3d_texture_bytearray` | runtime_error | 0/0 | 0/0 |
| `stage3d_texture_bytearray_compressed_alpha` | runtime_error | 0/0 | 0/0 |
| `stage3d_texture_bytearray_compressed_raw_alpha` | runtime_error | 0/0 | 0/0 |
| `stage3d_triangle` | runtime_error | 0/0 | 0/0 |
| `stage3d_triangle_bytes4` | runtime_error | 0/0 | 0/0 |
| `stage3d_triangle_float1` | runtime_error | 0/0 | 0/0 |
| `stage3d_triangle_index_upload` | runtime_error | 0/0 | 0/0 |
| `static_var_with_this_in_ctor` | runtime_error | 0/2 | 2/2 |
| `stored_properties` | runtime_error | 0/11 | 11/11 |
| `strict_equality` | runtime_error | 1/34 | 34/34 |
| `string_call` | runtime_error | 0/13 | 13/13 |
| `string_case` | runtime_error | 2/23 | 23/23 |
| `string_char_at` | runtime_error | 1/27 | 27/27 |
| `string_char_code_at` | runtime_error | 1/28 | 28/28 |
| `string_concat_fromcharcode` | runtime_error | 0/36 | 36/36 |
| `string_constr` | runtime_error | 0/25 | 25/25 |
| `string_indexof_lastindexof` | runtime_error | 1/87 | 87/87 |
| `string_length` | runtime_error | 1/16 | 16/16 |
| `string_locale_compare` | runtime_error | 2/39 | 39/39 |
| `string_relational_compare` | runtime_error | 1/4 | 4/4 |
| `string_slice_substr_substring` | runtime_error | 2/169 | 169/169 |
| `string_substr_negative` | runtime_error | 0/21 | 21/21 |
| `string_substr_weird` | runtime_error | 0/182 | 182/182 |
| `subtract` | runtime_error | 0/1058 | 1058/1058 |
| `super_get_call` | runtime_error | 0/12 | 12/12 |
| `supercall_two_classobjects` | runtime_error | 0/2 | 2/2 |
| `throw` | runtime_error | 0/3 | 3/3 |
| `truthiness` | runtime_error | 0/30 | 30/30 |
| `try_catch_typed` | runtime_error | 0/12 | 12/12 |
| `typeof` | runtime_error | 0/30 | 30/30 |
| `uint_constr` | runtime_error | 1/92 | 92/92 |
| `uint_tofixed` | runtime_error | 0/1215 | 1215/1215 |
| `uint_tostring` | runtime_error | 0/3375 | 3375/3375 |
| `unchecked_function` | runtime_error | 0/15 | 15/15 |
| `urshift` | runtime_error | 0/1058 | 1058/1058 |
| `verify_abnormal_loop` | runtime_error | 0/1 | 1/1 |
| `verify_exception_targets_edge_case` | runtime_error | 0/1 | 1/1 |
| `verify_lookup_switch_edge_case` | runtime_error | 0/1 | 1/1 |
| `verify_unreachable_exception` | runtime_error | 0/2 | 2/2 |
| `versioned_isplaying` | runtime_error | 0/2 | 2/2 |
| `virtual_properties` | runtime_error | 0/16 | 16/16 |
| `with` | runtime_error | 0/4 | 4/4 |

## Status Changed (809)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `abstract_classes` | runtime_error | output_mismatch | 0/132 | 0/132 |
| `accessibility` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `activation_class` | runtime_error | output_mismatch | 0/6 | 3/6 |
| `agal_compiler` | runtime_error | output_mismatch | 0/13 | 1/13 |
| `air_datagram_socket` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `air_ifilepromise` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `all_classes/accessibility/swf10` | runtime_error | output_mismatch | 0/88 | 0/88 |
| `all_classes/accessibility/swf30` | runtime_error | output_mismatch | 0/88 | 0/88 |
| `all_classes/accessibility/swf9` | runtime_error | output_mismatch | 0/73 | 0/73 |
| `all_classes/display/swf10` | runtime_error | output_mismatch | 0/2569 | 0/2569 |
| `all_classes/display/swf11` | runtime_error | output_mismatch | 0/2593 | 0/2593 |
| `all_classes/display/swf12` | runtime_error | output_mismatch | 0/2593 | 0/2593 |
| `all_classes/display/swf13` | runtime_error | output_mismatch | 0/2671 | 0/2671 |
| `all_classes/display/swf30` | runtime_error | output_mismatch | 0/2936 | 0/2936 |
| `all_classes/display/swf9` | runtime_error | output_mismatch | 0/1959 | 0/1959 |
| `all_classes/display3D/swf12` | runtime_error | output_mismatch | 0/61 | 0/61 |
| `all_classes/display3D/swf13` | runtime_error | output_mismatch | 0/326 | 0/326 |
| `all_classes/display3D/swf30` | runtime_error | output_mismatch | 0/412 | 0/412 |
| `all_classes/errors/swf10` | runtime_error | output_mismatch | 0/140 | 0/140 |
| `all_classes/errors/swf30` | runtime_error | output_mismatch | 0/140 | 0/140 |
| `all_classes/errors/swf9` | runtime_error | output_mismatch | 0/121 | 0/121 |
| `all_classes/events/swf10` | runtime_error | output_mismatch | 0/1638 | 0/1638 |
| `all_classes/events/swf11` | runtime_error | output_mismatch | 0/1750 | 0/1750 |
| `all_classes/events/swf12` | runtime_error | output_mismatch | 0/1814 | 0/1814 |
| `all_classes/events/swf30` | runtime_error | output_mismatch | 0/2353 | 0/2353 |
| `all_classes/events/swf9` | runtime_error | output_mismatch | 0/1030 | 0/1030 |
| `all_classes/security/swf11` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `all_classes/security/swf12` | runtime_error | output_mismatch | 0/19 | 0/19 |
| `all_classes/security/swf13` | runtime_error | output_mismatch | 0/53 | 0/53 |
| `all_classes/security/swf30` | runtime_error | output_mismatch | 0/53 | 0/53 |
| `all_classes/xml/swf30` | runtime_error | output_mismatch | 0/116 | 0/116 |
| `all_classes/xml/swf9` | runtime_error | output_mismatch | 0/116 | 0/116 |
| `amf_array_serialization` | runtime_error | output_mismatch | 0/17 | 1/17 |
| `amf_custom_obj` | runtime_error | output_mismatch | 0/26 | 1/26 |
| `amf_dictionary` | runtime_error | output_mismatch | 0/9 | 1/9 |
| `amf_function` | runtime_error | output_mismatch | 0/46 | 0/46 |
| `amf_invalid_date` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `amf_missing_prop` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `amf_nondynamic_function_prop` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `amf_vector` | runtime_error | output_mismatch | 0/40 | 0/40 |
| `amf_xml` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `appdomain_lookup_edge_cases` | runtime_error | output_mismatch | 0/32 | 0/32 |
| `application_domain` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `applicationdomain_hasdefinition_null` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `array_sort_swf10_64bit` | runtime_error | ruffle_matched | 0/1 | 0/1 |
| `asymmetric_key_events` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `audio_computespectrum` | runtime_error | output_mismatch | 0/118 | 0/118 |
| `av_networking_params` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `av_tag_data` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `avm1_root` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `avm2_catchup_dobj` | runtime_error | output_mismatch | 0/158 | 0/158 |
| `bevel_filter` | runtime_error | output_mismatch | 1/187 | 1/187 |
| `bitmap_constr` | runtime_error | output_mismatch | 1/17 | 1/17 |
| `bitmap_data` | runtime_error | output_mismatch | 0/1000 | 0/1000 |
| `bitmap_pixelsnapping` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `bitmap_properties` | runtime_error | output_mismatch | 1/23 | 1/23 |
| `bitmap_timeline` | runtime_error | output_mismatch | 1/9 | 1/9 |
| `bitmapdata_accuracy` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `bitmapdata_clone` | runtime_error | output_mismatch | 1/13 | 1/13 |
| `bitmapdata_colortransform_oob` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `bitmapdata_constr` | runtime_error | output_mismatch | 1/22 | 1/22 |
| `bitmapdata_constructor_from_timeline` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `bitmapdata_copypixels` | runtime_error | output_mismatch | 0/23 | 0/23 |
| `bitmapdata_copypixels_blend_over` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `bitmapdata_copypixelstobytearray` | runtime_error | output_mismatch | 0/39 | 0/39 |
| `bitmapdata_dispose` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `bitmapdata_draw_alpha_erase` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `bitmapdata_embedded` | runtime_error | output_mismatch | 1/9 | 1/9 |
| `bitmapdata_floodfill` | runtime_error | output_mismatch | 0/35 | 0/35 |
| `bitmapdata_getpixels` | runtime_error | output_mismatch | 0/39 | 0/39 |
| `bitmapdata_getvector` | runtime_error | output_mismatch | 0/27 | 0/27 |
| `bitmapdata_histogram` | runtime_error | output_mismatch | 0/59 | 0/59 |
| `bitmapdata_hittest` | runtime_error | output_mismatch | 0/112 | 0/112 |
| `bitmapdata_hittest_threshold` | runtime_error | output_mismatch | 0/18 | 0/18 |
| `bitmapdata_pixeldissolve` | runtime_error | output_mismatch | 0/1037 | 3/1037 |
| `bitmapdata_rectangle_rounding` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `bitmapdata_setpixels` | runtime_error | output_mismatch | 0/286 | 0/286 |
| `bitmapdata_setvector` | runtime_error | output_mismatch | 0/26 | 0/26 |
| `bitmapdata_threshold` | runtime_error | output_mismatch | 0/176 | 0/176 |
| `bitmapdata_zero_size` | runtime_error | output_mismatch | 1/5 | 1/5 |
| `blend_mode_null` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `blend_shader_luma_lighten` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `blend_transform` | runtime_error | ruffle_matched | 0/1 | 0/1 |
| `blur_filter` | runtime_error | output_mismatch | 1/43 | 1/43 |
| `bom` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `bounds_mode` | runtime_error | output_mismatch | 2/269 | 2/269 |
| `broadcast_event` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `button_bounds` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `button_hittest` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `button_nested_frame` | runtime_error | output_mismatch | 2/48 | 2/48 |
| `button_nested_frame_simple` | runtime_error | output_mismatch | 0/27 | 2/27 |
| `bytearray` | runtime_error | output_mismatch | 0/48 | 0/48 |
| `bytearray_compress` | runtime_error | output_mismatch | 0/31 | 0/31 |
| `bytearray_errors` | runtime_error | output_mismatch | 0/24 | 0/24 |
| `bytearray_method_serialization` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `bytearray_oom` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `bytearray_readobject_amf0` | runtime_error | output_mismatch | 0/50 | 0/50 |
| `bytearray_readobject_amf3` | runtime_error | output_mismatch | 0/53 | 0/53 |
| `bytearray_readutf8bytes_with_bom` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `bytearray_serialization` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `bytearray_string_null` | runtime_error | output_mismatch | 0/19 | 0/19 |
| `bytearray_tostring` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `bytearray_utf16` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `bytearray_writeobject` | runtime_error | output_mismatch | 0/24 | 1/24 |
| `capabilities_resolution` | runtime_error | output_mismatch | 0/8 | 1/8 |
| `class_call` | runtime_error | output_mismatch | 0/32 | 1/32 |
| `click_block` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `click_invisible` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `coerce_to_primitive_side_effects` | runtime_error | output_mismatch | 0/29 | 0/29 |
| `coerce_to_primitive_side_effects_with_nulls` | runtime_error | output_mismatch | 0/37 | 0/37 |
| `color_matrix_filter` | runtime_error | output_mismatch | 1/19 | 1/19 |
| `construct_frame_list` | runtime_error | output_mismatch | 0/22 | 1/22 |
| `construct_interface` | runtime_error | output_mismatch | 0/3 | 2/3 |
| `constructprop_dynamic_primitive` | runtime_error | output_mismatch | 0/7 | 5/7 |
| `constructprop_method` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `constructsuper_null` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `context3d_creation` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `convolution_filter` | runtime_error | output_mismatch | 1/89 | 1/89 |
| `cpool_index_invalid_bytecode_1` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `cpool_index_invalid_bytecode_2` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `cpool_index_invalid_bytecode_3` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `cross_api_version_call_newer` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `cross_api_version_call_older` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `cryptscore` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `currency_parse_result` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `date` | runtime_error | output_mismatch | 1/30 | 15/30 |
| `date_parse` | runtime_error | output_mismatch | 0/36 | 2/36 |
| `decode_uri` | runtime_error | output_mismatch | 0/71 | 0/71 |
| `delayed_symbolclass` | runtime_error | output_mismatch | 0/28 | 0/28 |
| `dependent_strings` | runtime_error | output_mismatch | 0/84 | 46/84 |
| `describe_type_basic` | runtime_error | output_mismatch | 0/152 | 0/152 |
| `describe_type_json` | runtime_error | output_mismatch | 0/301 | 0/301 |
| `describe_type_metadata` | runtime_error | output_mismatch | 0/125 | 0/125 |
| `describe_type_native` | runtime_error | output_mismatch | 0/23 | 0/23 |
| `dictionary_access` | runtime_error | output_mismatch | 1/62 | 1/62 |
| `dictionary_delete` | runtime_error | output_mismatch | 1/101 | 1/101 |
| `dictionary_foreach` | runtime_error | output_mismatch | 0/42 | 1/42 |
| `dictionary_hasownproperty` | runtime_error | output_mismatch | 1/63 | 1/63 |
| `dictionary_in` | runtime_error | output_mismatch | 1/62 | 1/62 |
| `dictionary_iter_modify` | runtime_error | output_mismatch | 0/8 | 3/8 |
| `dictionary_namespaces` | runtime_error | output_mismatch | 0/36 | 0/36 |
| `dictionary_primitive_keys` | runtime_error | output_mismatch | 0/29 | 1/29 |
| `dictionary_weak_keys` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `displacement_map_filter` | runtime_error | output_mismatch | 1/61 | 1/61 |
| `displayobject_alpha` | runtime_error | output_mismatch | 1/277 | 276/277 |
| `displayobject_early_init` | runtime_error | output_mismatch | 0/54 | 0/54 |
| `displayobject_filters` | runtime_error | output_mismatch | 0/17 | 1/17 |
| `displayobject_height` | runtime_error | output_mismatch | 1/6052 | 2/6052 |
| `displayobject_hittestobject` | runtime_error | output_mismatch | 1/32 | 1/32 |
| `displayobject_hittestpoint` | runtime_error | output_mismatch | 1/49 | 1/49 |
| `displayobject_hittestpoint_boundary` | runtime_error | output_mismatch | 0/65 | 0/65 |
| `displayobject_hittestpoint_root` | runtime_error | output_mismatch | 0/13 | 0/13 |
| `displayobject_invalid_floats` | runtime_error | output_mismatch | 0/60 | 0/60 |
| `displayobject_invalid_props` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `displayobject_mask` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `displayobject_metaData` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `displayobject_name` | runtime_error | output_mismatch | 1/22 | 1/22 |
| `displayobject_name_from_timeline` | runtime_error | output_mismatch | 0/24 | 3/24 |
| `displayobject_opaque_background` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `displayobject_root` | runtime_error | output_mismatch | 1/24 | 2/24 |
| `displayobject_rotation` | runtime_error | output_mismatch | 1/1275 | 1271/1275 |
| `displayobject_scrollrect` | runtime_error | output_mismatch | 0/33 | 0/33 |
| `displayobject_set_name_loaded` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `displayobject_subclass` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `displayobject_transform` | runtime_error | output_mismatch | 0/89 | 0/89 |
| `displayobject_visible` | runtime_error | output_mismatch | 1/23 | 1/23 |
| `displayobject_width` | runtime_error | output_mismatch | 1/4852 | 2/4852 |
| `displayobject_x` | runtime_error | output_mismatch | 1/614 | 36/614 |
| `displayobject_y` | runtime_error | output_mismatch | 1/617 | 39/617 |
| `displayobjectcontainer_addchild` | runtime_error | output_mismatch | 1/32 | 1/32 |
| `displayobjectcontainer_addchild_lazy_sprite` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `displayobjectcontainer_addchild_timelinepull0` | runtime_error | output_mismatch | 1/58 | 1/58 |
| `displayobjectcontainer_addchild_timelinepull1` | runtime_error | output_mismatch | 1/60 | 1/60 |
| `displayobjectcontainer_addchild_timelinepull2` | runtime_error | output_mismatch | 1/62 | 1/62 |
| `displayobjectcontainer_addchildat` | runtime_error | output_mismatch | 1/42 | 1/42 |
| `displayobjectcontainer_addchildat_timelinelock0` | runtime_error | output_mismatch | 1/34 | 1/34 |
| `displayobjectcontainer_addchildat_timelinelock1` | runtime_error | output_mismatch | 1/34 | 1/34 |
| `displayobjectcontainer_addchildat_timelinelock2` | runtime_error | output_mismatch | 1/34 | 1/34 |
| `displayobjectcontainer_contains` | runtime_error | output_mismatch | 1/66 | 1/66 |
| `displayobjectcontainer_getchildat` | runtime_error | output_mismatch | 1/4 | 1/4 |
| `displayobjectcontainer_getchildbyname` | runtime_error | output_mismatch | 1/9 | 1/9 |
| `displayobjectcontainer_getchildbyname_wrongcase` | runtime_error | output_mismatch | 1/5 | 1/5 |
| `displayobjectcontainer_getchildindex` | runtime_error | output_mismatch | 1/28 | 1/28 |
| `displayobjectcontainer_getobjectsunderpoint` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `displayobjectcontainer_removechild` | runtime_error | output_mismatch | 1/10 | 1/10 |
| `displayobjectcontainer_removechild_errors` | runtime_error | output_mismatch | 0/4 | 2/4 |
| `displayobjectcontainer_removechild_timelinemanip_remove1` | runtime_error | output_mismatch | 1/38 | 1/38 |
| `displayobjectcontainer_removechildat` | runtime_error | output_mismatch | 1/18 | 1/18 |
| `displayobjectcontainer_removechildren` | runtime_error | output_mismatch | 0/51 | 1/51 |
| `displayobjectcontainer_setchildindex` | runtime_error | output_mismatch | 1/42 | 1/42 |
| `displayobjectcontainer_swapchildren` | runtime_error | output_mismatch | 1/42 | 1/42 |
| `displayobjectcontainer_swapchildrenat` | runtime_error | output_mismatch | 1/42 | 1/42 |
| `displayobjectcontainer_timelineinstance` | runtime_error | output_mismatch | 5/48 | 5/48 |
| `doabc_and_symbolclass_script_init_goto` | runtime_error | output_mismatch | 0/7 | 1/7 |
| `doabc_and_symbolclass_script_init_normal` | runtime_error | output_mismatch | 0/6 | 1/6 |
| `documentclass` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `domain_memory` | runtime_error | output_mismatch | 0/133 | 1/133 |
| `drag_drop` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `drop_shadow_filter` | runtime_error | output_mismatch | 1/172 | 1/172 |
| `east_asian_justifier_clone` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `edit_text_linkage` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `edittext_align` | runtime_error | output_mismatch | 0/60 | 0/60 |
| `edittext_antialiastype` | runtime_error | output_mismatch | 0/296 | 1/296 |
| `edittext_autosize` | runtime_error | output_mismatch | 0/39 | 0/39 |
| `edittext_autosize_lazy_bounds_events` | runtime_error | output_mismatch | 0/65 | 0/65 |
| `edittext_autosize_lazy_bounds_interactions` | runtime_error | output_mismatch | 0/19 | 0/19 |
| `edittext_bounds_scale` | runtime_error | output_mismatch | 1/24 | 1/24 |
| `edittext_bullet` | runtime_error | output_mismatch | 0/30 | 0/30 |
| `edittext_default_format` | runtime_error | output_mismatch | 0/221 | 0/221 |
| `edittext_default_format_empty` | runtime_error | output_mismatch | 0/136 | 1/136 |
| `edittext_focus_selection` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `edittext_font_size` | runtime_error | output_mismatch | 0/45 | 0/45 |
| `edittext_format_empty_font` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `edittext_getcharboundaries_missing_embedded_font` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `edittext_getlinemetrics` | runtime_error | output_mismatch | 0/146 | 0/146 |
| `edittext_html` | runtime_error | output_mismatch | 0/3101 | 0/3101 |
| `edittext_html_condensewhite` | runtime_error | output_mismatch | 0/487 | 0/487 |
| `edittext_html_entity` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `edittext_html_font_size_swf12` | runtime_error | output_mismatch | 0/267 | 0/267 |
| `edittext_html_font_size_swf13` | runtime_error | output_mismatch | 0/273 | 0/273 |
| `edittext_html_roundtrip` | runtime_error | output_mismatch | 1/17 | 1/17 |
| `edittext_ime_focus_lost` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `edittext_input_control` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `edittext_leading` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `edittext_letter_spacing` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `edittext_margins` | runtime_error | output_mismatch | 0/25 | 0/25 |
| `edittext_mousedown` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `edittext_mouseenabled` | runtime_error | output_mismatch | 1/26 | 1/26 |
| `edittext_newline_character` | runtime_error | output_mismatch | 0/22 | 0/22 |
| `edittext_newline_stripping` | runtime_error | output_mismatch | 1/64 | 1/64 |
| `edittext_newlines` | runtime_error | output_mismatch | 0/30 | 0/30 |
| `edittext_paragraph_methods` | runtime_error | output_mismatch | 0/257 | 0/257 |
| `edittext_paste_events` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `edittext_paste_maxchars` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `edittext_paste_restrict` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `edittext_restrict` | runtime_error | output_mismatch | 0/191 | 0/191 |
| `edittext_restrict_events` | runtime_error | output_mismatch | 0/22 | 0/22 |
| `edittext_scrollh` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `edittext_selected_text` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `edittext_set_html_same` | runtime_error | output_mismatch | 0/17 | 0/17 |
| `edittext_set_text_vs_html` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `edittext_stylesheet` | runtime_error | output_mismatch | 0/536 | 0/536 |
| `edittext_stylesheet_custom_tag` | runtime_error | output_mismatch | 0/76 | 0/76 |
| `edittext_stylesheet_display` | runtime_error | output_mismatch | 0/272 | 0/272 |
| `edittext_tab_stops` | runtime_error | output_mismatch | 0/60 | 0/60 |
| `edittext_tag_indent` | runtime_error | output_mismatch | 0/49 | 0/49 |
| `edittext_underline` | runtime_error | output_mismatch | 0/40 | 0/40 |
| `edittext_width_height` | runtime_error | output_mismatch | 0/103 | 0/103 |
| `element_format_clone` | runtime_error | output_mismatch | 0/44 | 0/44 |
| `element_format_constructor_order` | runtime_error | output_mismatch | 0/64 | 3/64 |
| `element_format_properties` | runtime_error | output_mismatch | 0/235 | 0/235 |
| `empty_bounds` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `encode_uri_surrogate_pair_invalid` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `encode_uri_surrogate_pair_swf10` | runtime_error | ruffle_matched | 0/15 | 0/15 |
| `encode_uri_surrogate_pair_swf11` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `error_1034_debug_string` | runtime_error | output_mismatch | 0/30 | 0/30 |
| `error_geterrormessage` | runtime_error | output_mismatch | 0/779 | 0/779 |
| `error_stack_trace_edge_cases` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `error_tostring` | runtime_error | output_mismatch | 0/29 | 0/29 |
| `error_tostring_more` | runtime_error | output_mismatch | 0/86 | 0/86 |
| `escape` | runtime_error | output_mismatch | 0/71 | 20/71 |
| `escape_multi_byte` | runtime_error | output_mismatch | 0/45 | 1/45 |
| `event_bubbles` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `event_cancelable` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `event_clone` | runtime_error | output_mismatch | 0/20 | 0/20 |
| `event_clone_error_redispatch` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `event_clone_on_redispatch` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `event_formattostring` | runtime_error | output_mismatch | 0/31 | 0/31 |
| `event_handler_exception` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `event_isdefaultprevented` | runtime_error | output_mismatch | 1/12 | 1/12 |
| `event_target_getter` | runtime_error | output_mismatch | 0/5 | 1/5 |
| `event_type` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `event_valueof_tostring` | runtime_error | output_mismatch | 1/18 | 1/18 |
| `eventdispatcher_dispatchevent` | runtime_error | output_mismatch | 0/12 | 2/12 |
| `eventdispatcher_dispatchevent_cancel` | runtime_error | output_mismatch | 0/20 | 2/20 |
| `eventdispatcher_dispatchevent_handlerorder` | runtime_error | output_mismatch | 0/22 | 2/22 |
| `eventdispatcher_dispatchevent_indirect` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `eventdispatcher_dispatchevent_this` | runtime_error | output_mismatch | 0/5 | 2/5 |
| `eventdispatcher_haseventlistener` | runtime_error | output_mismatch | 1/25 | 3/25 |
| `eventdispatcher_interface_invoke` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `eventdispatcher_tostring` | runtime_error | output_mismatch | 1/10 | 8/10 |
| `eventdispatcher_willtrigger` | runtime_error | output_mismatch | 1/25 | 3/25 |
| `external_interface` | runtime_error | output_mismatch | 0/104 | 1/104 |
| `fast_index_access` | runtime_error | output_mismatch | 0/12 | 4/12 |
| `filefilter_properties` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `filereference_browse_cancel` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `filereference_browse_select` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `filereference_load` | runtime_error | output_mismatch | 0/31 | 0/31 |
| `filereference_save` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `filereference_save_and_browse` | runtime_error | output_mismatch | 0/42 | 0/42 |
| `filereference_save_and_load` | runtime_error | output_mismatch | 0/22 | 0/22 |
| `filereference_uninitialized` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `filereferencelist_browse_cancel` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `filereferencelist_browse_select` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `filter_rewind` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `filters_array_holes` | runtime_error | output_mismatch | 1/25 | 1/25 |
| `flash_media_video_constructor` | runtime_error | output_mismatch | 0/156 | 25/156 |
| `flash_media_video_rotation_probe` | runtime_error | output_mismatch | 0/27 | 1/27 |
| `flash_media_video_setter` | runtime_error | output_mismatch | 0/40 | 1/40 |
| `flash_xml` | runtime_error | output_mismatch | 0/29 | 0/29 |
| `flash_xml_cloneNode` | runtime_error | output_mismatch | 0/22 | 0/22 |
| `flash_xml_namespace` | runtime_error | output_mismatch | 0/109 | 0/109 |
| `flash_xml_removeNode` | runtime_error | output_mismatch | 0/60 | 1/60 |
| `focus_events_code` | runtime_error | output_mismatch | 0/161 | 0/161 |
| `focus_events_key_basic` | runtime_error | output_mismatch | 0/132 | 0/132 |
| `focus_events_key_navigation` | runtime_error | output_mismatch | 0/53 | 0/53 |
| `focus_events_key_same_object` | runtime_error | output_mismatch | 0/26 | 0/26 |
| `focus_events_mixed_avm_edittext` | runtime_error | output_mismatch | 0/49 | 0/49 |
| `focus_events_mixed_key_mouse` | runtime_error | output_mismatch | 0/100 | 0/100 |
| `focus_events_mouse_basic` | runtime_error | output_mismatch | 0/260 | 0/260 |
| `focus_events_mouse_focusable` | runtime_error | output_mismatch | 0/112 | 0/112 |
| `focus_events_mouse_same_object` | runtime_error | output_mismatch | 0/40 | 0/40 |
| `focus_remove` | runtime_error | output_mismatch | 1/20 | 1/20 |
| `focus_root_movie` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `focus_stage` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `focusrect` | runtime_error | output_mismatch | 0/18 | 0/18 |
| `focusrect_focuslost` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `focusrect_property` | runtime_error | output_mismatch | 0/110 | 0/110 |
| `font_description_clone` | runtime_error | output_mismatch | 0/14 | 0/14 |
| `font_embedded` | runtime_error | output_mismatch | 1/24 | 1/24 |
| `font_enumeratefonts` | runtime_error | output_mismatch | 1/41 | 1/41 |
| `font_hasglyphs` | runtime_error | output_mismatch | 1/40 | 1/40 |
| `font_registerfont` | runtime_error | output_mismatch | 1/129 | 1/129 |
| `framelabel_constr` | runtime_error | output_mismatch | 1/5 | 1/5 |
| `freestanding_superclass` | runtime_error | ruffle_matched | 0/4 | 0/4 |
| `function_proto_created` | runtime_error | output_mismatch | 0/61 | 18/61 |
| `function_unbound_this` | runtime_error | output_mismatch | 0/51 | 19/51 |
| `game_input` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `generate_random_bytes` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `geom_transform` | runtime_error | output_mismatch | 0/74 | 1/74 |
| `get_definition_by_name` | runtime_error | output_mismatch | 0/11 | 5/11 |
| `get_qualified_class_name` | runtime_error | output_mismatch | 0/20 | 1/20 |
| `get_qualified_super_class_name` | runtime_error | output_mismatch | 0/18 | 0/18 |
| `get_timer` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `glow_filter` | runtime_error | output_mismatch | 1/127 | 1/127 |
| `goto_button_nested_framescript` | runtime_error | output_mismatch | 0/28 | 0/28 |
| `goto_framescript_queued` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `goto_in_constructframe` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `goto_in_scene_last_frame` | runtime_error | output_mismatch | 1/2 | 1/2 |
| `goto_methods` | runtime_error | output_mismatch | 0/56 | 1/56 |
| `goto_methods_swfver10` | runtime_error | output_mismatch | 1/8 | 1/8 |
| `goto_nested_framescript` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `goto_on_orphan` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `gradient_bevel_filter` | runtime_error | output_mismatch | 1/206 | 1/206 |
| `gradient_glow_filter` | runtime_error | output_mismatch | 1/206 | 1/206 |
| `graphic_linkage` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `graphics_bad_direct_commands` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `graphics_draw_path` | runtime_error | output_mismatch | 0/34 | 0/34 |
| `graphics_draw_triangles` | runtime_error | output_mismatch | 0/98 | 0/98 |
| `hittest_morph` | runtime_error | output_mismatch | 1/30 | 1/30 |
| `id3_info` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `ime_linux_dead_keys` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `indexing_delete` | runtime_error | output_mismatch | 0/75 | 0/75 |
| `instantiate_root_character` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `instantiation_on_enter_frame` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `instantiation_on_enterframe_gotoandstop` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `int_toexponential` | runtime_error | ruffle_matched | 0/1215 | 1139/1215 |
| `int_toprecision` | runtime_error | ruffle_matched | 0/1125 | 684/1125 |
| `interactiveobject_enabled` | runtime_error | output_mismatch | 2/25 | 22/25 |
| `invalid_utf8` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `issue_13780` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `issue_17675_edittext_paste_maxchars` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `issue_5292` | runtime_error | output_mismatch | 0/5 | 4/5 |
| `issue_8630` | runtime_error | output_mismatch | 0/2 | 1/2 |
| `issue_8630_placeremoveplace` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `issue_8630_placeremoveplace_scriptremove` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `issue_8630_scriptremove` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `jpeg_loader_context` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `json_errors` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `json_parse` | runtime_error | output_mismatch | 0/21 | 0/21 |
| `json_stringify` | runtime_error | output_mismatch | 0/14 | 0/14 |
| `key_input_80percent` | runtime_error | output_mismatch | 0/1812 | 0/1812 |
| `key_input_location` | runtime_error | output_mismatch | 0/126 | 0/126 |
| `key_input_numpad` | runtime_error | output_mismatch | 0/384 | 0/384 |
| `large_preload_from_url` | runtime_error | output_mismatch | 0/27 | 0/27 |
| `loader_applicationDomain` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `loader_bitmap_transparency` | runtime_error | output_mismatch | 0/14 | 0/14 |
| `loader_bytes_unknown_content` | runtime_error | output_mismatch | 0/14 | 0/14 |
| `loader_child_getdefinition` | runtime_error | output_mismatch | 0/5 | 2/5 |
| `loader_duplicate_class` | runtime_error | output_mismatch | 0/48 | 2/48 |
| `loader_duplicate_coerce` | runtime_error | output_mismatch | 0/3 | 1/3 |
| `loader_duplicate_coerce_new_domain` | runtime_error | output_mismatch | 0/4 | 1/4 |
| `loader_error_in_root_ctor` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `loader_events` | runtime_error | output_mismatch | 0/92 | 0/92 |
| `loader_image` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `loader_jpegxr` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `loader_jpegxr_alpha` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `loader_load` | runtime_error | output_mismatch | 0/126 | 0/126 |
| `loader_loadbytes_events` | runtime_error | output_mismatch | 0/30 | 0/30 |
| `loader_loadbytes_invalid_png` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `loader_loaderurl` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `loader_method` | runtime_error | output_mismatch | 0/83 | 0/83 |
| `loader_noninteractive_try_click_root` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `loader_reuse` | runtime_error | output_mismatch | 0/38 | 0/38 |
| `loader_try_click_root` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `loader_unknown_content` | runtime_error | output_mismatch | 0/24 | 0/24 |
| `loader_visibility_interactive` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `loaderinfo_events` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `loaderinfo_loadurl` | runtime_error | output_mismatch | 0/12 | 1/12 |
| `loaderinfo_more` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `loaderinfo_properties` | runtime_error | output_mismatch | 1/18 | 1/18 |
| `loaderinfo_properties_not_loaded` | runtime_error | output_mismatch | 0/23 | 0/23 |
| `loaderinfo_quine` | runtime_error | output_mismatch | 1/1005 | 1/1005 |
| `loaderinfo_root` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `loaderinfo_root_allows` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `localconnection` | runtime_error | output_mismatch | 0/890 | 0/890 |
| `localconnection_send` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `mask_reapply` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `matrix` | runtime_error | output_mismatch | 0/338 | 0/338 |
| `matrix3d` | runtime_error | output_mismatch | 0/57 | 0/57 |
| `matrix3d_compose` | runtime_error | output_mismatch | 0/34 | 0/34 |
| `matrix3d_invert` | runtime_error | output_mismatch | 0/18 | 0/18 |
| `method_association` | runtime_error | output_mismatch | 0/5 | 1/5 |
| `missing_external_interface` | runtime_error | output_mismatch | 0/10 | 3/10 |
| `morph_shape` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `mouse_children` | runtime_error | output_mismatch | 0/192 | 0/192 |
| `mouse_click_events` | runtime_error | output_mismatch | 0/90 | 0/90 |
| `mouse_double_click_events` | runtime_error | output_mismatch | 0/188 | 0/188 |
| `mouse_empty_parent` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `mouse_over_while_dragging` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `mouse_pick_avm1_root` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `mouse_pick_dobj_mask` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `mouse_pick_loader_avm1` | runtime_error | output_mismatch | 0/42 | 0/42 |
| `mouse_pick_masking` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `mouse_pick_non_interactive_bitmap_mask` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `mouse_pick_non_interactive_dobj_mask` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `mouse_pick_text` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `mouse_sibling` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `mouseevent_constr` | runtime_error | output_mismatch | 0/66 | 1/66 |
| `mouseevent_stagexy` | runtime_error | output_mismatch | 0/35 | 0/35 |
| `mouseevent_valueof_tostring` | runtime_error | output_mismatch | 0/28 | 1/28 |
| `movieclip_addframescript` | runtime_error | output_mismatch | 0/3 | 1/3 |
| `movieclip_child_property` | runtime_error | output_mismatch | 2/16 | 2/16 |
| `movieclip_constr` | runtime_error | output_mismatch | 2/21 | 6/21 |
| `movieclip_currentlabels` | runtime_error | output_mismatch | 1/17 | 1/17 |
| `movieclip_currentlabels_dupes1` | runtime_error | output_mismatch | 0/46 | 1/46 |
| `movieclip_currentlabels_dupes2` | runtime_error | output_mismatch | 0/30 | 1/30 |
| `movieclip_currentlabels_dupes3` | runtime_error | output_mismatch | 0/67 | 1/67 |
| `movieclip_currentscene` | runtime_error | output_mismatch | 1/12 | 1/12 |
| `movieclip_dispatchevent` | runtime_error | output_mismatch | 2/430 | 2/430 |
| `movieclip_dispatchevent_cancel` | runtime_error | output_mismatch | 2/102 | 2/102 |
| `movieclip_dispatchevent_handlerorder` | runtime_error | output_mismatch | 2/251 | 2/251 |
| `movieclip_dispatchevent_selfadd` | runtime_error | output_mismatch | 2/80 | 2/80 |
| `movieclip_dispatchevent_target` | runtime_error | output_mismatch | 2/899 | 2/899 |
| `movieclip_displayevents` | runtime_error | output_mismatch | 2/96 | 2/96 |
| `movieclip_displayevents_clickgoto` | runtime_error | output_mismatch | 0/676 | 0/676 |
| `movieclip_displayevents_clickgoto2` | runtime_error | output_mismatch | 0/2001 | 0/2001 |
| `movieclip_displayevents_clickplay` | runtime_error | output_mismatch | 0/575 | 0/575 |
| `movieclip_displayevents_clicksymbol` | runtime_error | output_mismatch | 0/562 | 0/562 |
| `movieclip_displayevents_constructframegoto` | runtime_error | output_mismatch | 0/140 | 0/140 |
| `movieclip_displayevents_constructframeplay` | runtime_error | output_mismatch | 0/50 | 0/50 |
| `movieclip_displayevents_constructframesymbol` | runtime_error | output_mismatch | 0/144 | 0/144 |
| `movieclip_displayevents_dblhandler` | runtime_error | output_mismatch | 0/21 | 0/21 |
| `movieclip_displayevents_enterframegoto` | runtime_error | output_mismatch | 0/149 | 0/149 |
| `movieclip_displayevents_enterframeplay` | runtime_error | output_mismatch | 0/48 | 0/48 |
| `movieclip_displayevents_enterframesymbol` | runtime_error | output_mismatch | 0/149 | 0/149 |
| `movieclip_displayevents_exitframegoto` | runtime_error | output_mismatch | 0/106 | 0/106 |
| `movieclip_displayevents_exitframeplay` | runtime_error | output_mismatch | 0/44 | 0/44 |
| `movieclip_displayevents_exitframesymbol` | runtime_error | output_mismatch | 0/135 | 0/135 |
| `movieclip_displayevents_stopped` | runtime_error | output_mismatch | 1/113 | 1/113 |
| `movieclip_displayevents_swap` | runtime_error | output_mismatch | 2/96 | 2/96 |
| `movieclip_displayevents_timeline` | runtime_error | output_mismatch | 0/128 | 0/128 |
| `movieclip_drawrect` | runtime_error | output_mismatch | 2/54 | 2/54 |
| `movieclip_frameconstruct_skipped` | runtime_error | output_mismatch | 0/9 | 1/9 |
| `movieclip_goto_during_frame_script` | runtime_error | output_mismatch | 2/15 | 2/15 |
| `movieclip_goto_overwrite` | runtime_error | output_mismatch | 1/14 | 2/14 |
| `movieclip_goto_scene_last_frame_int` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `movieclip_goto_scene_last_frame_label` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `movieclip_gotoandplay` | runtime_error | output_mismatch | 2/15 | 2/15 |
| `movieclip_gotoandstop` | runtime_error | output_mismatch | 2/13 | 2/13 |
| `movieclip_gotoandstop_children` | runtime_error | output_mismatch | 0/4 | 1/4 |
| `movieclip_gotoandstop_framescripts1` | runtime_error | output_mismatch | 1/4 | 1/4 |
| `movieclip_gotoandstop_framescripts2` | runtime_error | output_mismatch | 1/4 | 1/4 |
| `movieclip_gotoandstop_framescripts_self` | runtime_error | output_mismatch | 1/7 | 1/7 |
| `movieclip_gotoandstop_queueing` | runtime_error | output_mismatch | 2/12 | 2/12 |
| `movieclip_hittest` | runtime_error | output_mismatch | 2/67 | 2/67 |
| `movieclip_next_frame` | runtime_error | output_mismatch | 1/2 | 1/2 |
| `movieclip_next_scene` | runtime_error | output_mismatch | 0/6 | 1/6 |
| `movieclip_prev_scene` | runtime_error | output_mismatch | 1/7 | 1/7 |
| `movieclip_properties` | runtime_error | output_mismatch | 2/79 | 10/79 |
| `movieclip_queued_noop_goto_swf10` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `movieclip_queued_noop_goto_swf9` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `movieclip_scenes` | runtime_error | output_mismatch | 1/11 | 1/11 |
| `movieclip_soundtransform` | runtime_error | output_mismatch | 1/831 | 1/831 |
| `movieclip_super_is_symbol` | runtime_error | output_mismatch | 6/20 | 14/20 |
| `movieclip_symbol_constr` | runtime_error | output_mismatch | 3/8 | 3/8 |
| `movieclip_text_mousedown` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `namespace_constr_args` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `namespace_enumeration_order` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `nan_scale` | runtime_error | output_mismatch | 1/9 | 2/9 |
| `native_menu_basic` | runtime_error | output_mismatch | 0/19 | 0/19 |
| `navigateToURL_target_normalize` | runtime_error | output_mismatch | 0/107 | 1/107 |
| `nested_iteration` | runtime_error | output_mismatch | 0/11 | 7/11 |
| `net_getClassByAlias` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `net_navigateToURL` | runtime_error | output_mismatch | 0/57 | 0/57 |
| `net_stream_play_options` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `netconnection_close` | runtime_error | output_mismatch | 0/55 | 0/55 |
| `netconnection_properties` | runtime_error | output_mismatch | 0/78 | 0/78 |
| `netconnection_send_remote` | runtime_error | output_mismatch | 0/50 | 0/50 |
| `netconnection_serialize_arrays` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `netfilterevent` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `netstream_client` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `netstream_connect` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `netstream_flv_date` | runtime_error | output_mismatch | 0/4 | 1/4 |
| `netstream_play_flv` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `netstream_play_stop_replay` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `netstream_seek_flv` | runtime_error | output_mismatch | 0/49 | 0/49 |
| `newclass_mismatched` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `null_void_types` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `number_autoconv` | runtime_error | output_mismatch | 0/21 | 15/21 |
| `number_autoconv_amf` | runtime_error | output_mismatch | 0/132 | 0/132 |
| `number_tostring` | runtime_error | output_mismatch | 0/1050 | 873/1050 |
| `orphan_movie_complex` | runtime_error | output_mismatch | 0/80 | 0/80 |
| `orphan_movie_reorder` | runtime_error | output_mismatch | 0/111 | 1/111 |
| `orphan_removeobject` | runtime_error | output_mismatch | 0/636 | 0/636 |
| `package_namespace` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `parent_early_access_child` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `parse_float_swf10` | runtime_error | output_mismatch | 1/80 | 78/80 |
| `parse_int` | runtime_error | output_mismatch | 1/134 | 132/134 |
| `perspective_projection` | runtime_error | output_mismatch | 1/1443 | 1/1443 |
| `perspective_projection_basic` | runtime_error | output_mismatch | 0/40 | 1/40 |
| `pixelbender_ceil` | runtime_error | output_mismatch | 0/77 | 0/77 |
| `pixelbender_conditional` | runtime_error | output_mismatch | 0/138 | 0/138 |
| `pixelbender_dithering` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `pixelbender_effect_glassDisplace_shaderfilter` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `pixelbender_eof` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `pixelbender_logicalnot` | runtime_error | output_mismatch | 0/20 | 0/20 |
| `pixelbender_multiple_out_params` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `pixelbender_no_out_param` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `pixelbender_outputs` | runtime_error | output_mismatch | 0/13 | 0/13 |
| `pixelbender_padding_bytes` | runtime_error | output_mismatch | 0/22 | 0/22 |
| `pixelbender_param_qualifier` | runtime_error | output_mismatch | 0/512 | 0/512 |
| `pixelbender_select_kinds` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `pixelbender_shaderdata` | runtime_error | output_mismatch | 0/49 | 0/49 |
| `pixelbender_sign` | runtime_error | output_mismatch | 0/60 | 0/60 |
| `place_and_lookup/swf10` | runtime_error | output_mismatch | 0/33 | 0/33 |
| `place_and_lookup/swf9` | runtime_error | output_mismatch | 0/33 | 0/33 |
| `place_object_replace` | runtime_error | output_mismatch | 1/9 | 1/9 |
| `place_object_replace_2` | runtime_error | output_mismatch | 1/24 | 1/24 |
| `point` | runtime_error | output_mismatch | 2/132 | 12/132 |
| `primitive_edge_cases` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `primitive_toString` | runtime_error | output_mismatch | 1/61 | 43/61 |
| `print_job_options` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `property_is_enumerable` | runtime_error | output_mismatch | 0/114 | 25/114 |
| `property_is_enumerable_reset` | runtime_error | output_mismatch | 0/23 | 0/23 |
| `property_priority_chained` | runtime_error | output_mismatch | 0/4 | 1/4 |
| `property_priority_definition_names_order` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `prototype_set_null` | runtime_error | output_mismatch | 0/7 | 6/7 |
| `proxy_callproperty` | runtime_error | output_mismatch | 0/24 | 0/24 |
| `proxy_deleteproperty` | runtime_error | output_mismatch | 0/64 | 0/64 |
| `proxy_enumeration` | runtime_error | output_mismatch | 0/34 | 0/34 |
| `proxy_getproperty` | runtime_error | output_mismatch | 0/77 | 0/77 |
| `proxy_hasownproperty` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `proxy_hasproperty` | runtime_error | output_mismatch | 0/32 | 0/32 |
| `proxy_serialize` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `proxy_setproperty` | runtime_error | output_mismatch | 0/42 | 0/42 |
| `qname_as_lazy_name_attribute_multiname` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `qname_constr` | runtime_error | output_mismatch | 1/32 | 1/32 |
| `qname_constr_namespace` | runtime_error | output_mismatch | 2/24 | 2/24 |
| `qname_enumeration` | runtime_error | output_mismatch | 1/9 | 1/9 |
| `qname_indexing` | runtime_error | output_mismatch | 0/23 | 0/23 |
| `qname_tostring` | runtime_error | output_mismatch | 1/25 | 1/25 |
| `qname_valueof` | runtime_error | output_mismatch | 1/29 | 1/29 |
| `rectangle` | runtime_error | output_mismatch | 0/1094 | 1/1094 |
| `regexp_constr` | runtime_error | output_mismatch | 0/148 | 1/148 |
| `regexp_exec` | runtime_error | output_mismatch | 1/19 | 1/19 |
| `regexp_extended` | runtime_error | output_mismatch | 0/47 | 1/47 |
| `regexp_multiargs` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `regexp_test` | runtime_error | output_mismatch | 1/27 | 1/27 |
| `regexp_toString` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `register_script_refresh` | runtime_error | output_mismatch | 0/35 | 1/35 |
| `remove_child_clear_field` | runtime_error | output_mismatch | 0/88 | 0/88 |
| `remove_dobj` | runtime_error | output_mismatch | 0/3 | 1/3 |
| `resolve_order` | runtime_error | output_mismatch | 0/4 | 1/4 |
| `responder_null_callbacks` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `rng` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `rootless` | runtime_error | output_mismatch | 0/42 | 0/42 |
| `sandbox_type_inherited` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `sandbox_type_local_file` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `sandbox_type_local_network` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `sandbox_type_remote` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `scene_constr` | runtime_error | output_mismatch | 1/8 | 1/8 |
| `scope_optimizations` | runtime_error | output_mismatch | 2/4 | 3/4 |
| `security_domain_current` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `selection` | runtime_error | output_mismatch | 0/239 | 0/239 |
| `selection_onsetfocus_mixed_avm` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `shaderparameter_value` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `shape_drawrect` | runtime_error | output_mismatch | 1/54 | 1/54 |
| `shared_object_no_root` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `simplebutton_added_to_stage` | runtime_error | output_mismatch | 0/45 | 0/45 |
| `simplebutton_childevents` | runtime_error | output_mismatch | 0/86 | 0/86 |
| `simplebutton_childevents_multichild` | runtime_error | output_mismatch | 0/152 | 0/152 |
| `simplebutton_childevents_nested` | runtime_error | output_mismatch | 0/54 | 0/54 |
| `simplebutton_childevents_script_order` | runtime_error | output_mismatch | 1/87 | 1/87 |
| `simplebutton_childevents_sprite` | runtime_error | output_mismatch | 0/13 | 0/13 |
| `simplebutton_childprops` | runtime_error | output_mismatch | 0/144 | 0/144 |
| `simplebutton_childshuffle` | runtime_error | output_mismatch | 2/23 | 2/23 |
| `simplebutton_constr` | runtime_error | output_mismatch | 1/36 | 1/36 |
| `simplebutton_constr_childevents` | runtime_error | output_mismatch | 1/48 | 1/48 |
| `simplebutton_constr_params` | runtime_error | output_mismatch | 1/42 | 1/42 |
| `simplebutton_mouseenabled` | runtime_error | output_mismatch | 1/26 | 1/26 |
| `simplebutton_multi_children` | runtime_error | output_mismatch | 0/19 | 0/19 |
| `simplebutton_soundtransform` | runtime_error | output_mismatch | 1/887 | 1/887 |
| `simplebutton_structure` | runtime_error | output_mismatch | 0/27 | 0/27 |
| `simplebutton_symbolclass` | runtime_error | output_mismatch | 0/68 | 3/68 |
| `slot_id_exceeds_trait_count` | runtime_error | ruffle_matched | 0/0 | 0/0 |
| `socket_after_disconnect` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `socket_close` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `socket_connect` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `socket_errors` | runtime_error | output_mismatch | 0/56 | 0/56 |
| `socket_read_big` | runtime_error | output_mismatch | 0/48 | 0/48 |
| `socket_read_little` | runtime_error | output_mismatch | 0/48 | 0/48 |
| `socket_read_write_object` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `socket_write_big` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `socket_write_little` | runtime_error | output_mismatch | 0/14 | 0/14 |
| `sound_constructor_with_args` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `sound_embeddedprops` | runtime_error | output_mismatch | 1/26 | 1/26 |
| `sound_play` | runtime_error | output_mismatch | 1/19 | 1/19 |
| `sound_rootless` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `sound_valueof` | runtime_error | output_mismatch | 1/33 | 1/33 |
| `soundchannel_soundcomplete` | runtime_error | output_mismatch | 1/16 | 1/16 |
| `soundchannel_soundtransform` | runtime_error | output_mismatch | 1/835 | 1/835 |
| `soundchannel_soundtransform_exists` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `soundchannel_stop` | runtime_error | output_mismatch | 1/8 | 1/8 |
| `soundmixer_buffertime` | runtime_error | output_mismatch | 1/5 | 1/5 |
| `soundmixer_soundtransform` | runtime_error | output_mismatch | 1/900 | 1/900 |
| `soundmixer_stopall` | runtime_error | output_mismatch | 1/6 | 1/6 |
| `soundtransform` | runtime_error | output_mismatch | 1/442 | 1/442 |
| `space_justifier_clone` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `sprite_dropTarget` | runtime_error | output_mismatch | 0/19 | 0/19 |
| `stage3d_agal_upload_errors` | runtime_error | output_mismatch | 0/66 | 0/66 |
| `stage3d_context3d_string_args` | runtime_error | output_mismatch | 0/158 | 0/158 |
| `stage3d_errors` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `stage3d_errors_atf` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `stage3d_errors_swf_29` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `stage3d_multistage_triangle` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `stage3d_program_constants_invalid_input` | runtime_error | output_mismatch | 0/21 | 0/21 |
| `stage3d_x_y` | runtime_error | output_mismatch | 0/22 | 0/22 |
| `stage_access` | runtime_error | output_mismatch | 2/10 | 3/10 |
| `stage_display_state` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `stage_displayobject_properties` | runtime_error | output_mismatch | 1/24 | 1/24 |
| `stage_domain_getQualifiedDefinitionNames` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `stage_framerate_nan` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `stage_framerate_negative` | runtime_error | output_mismatch | 1/6 | 1/6 |
| `stage_framerate_zero` | runtime_error | output_mismatch | 1/6 | 1/6 |
| `stage_invalidate` | runtime_error | output_mismatch | 0/38 | 0/38 |
| `stage_loaderinfo_properties` | runtime_error | output_mismatch | 1/24 | 1/24 |
| `stage_mousechildren` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `stage_mouseenabled` | runtime_error | output_mismatch | 2/15 | 2/15 |
| `stage_overriden_setters` | runtime_error | output_mismatch | 0/31 | 0/31 |
| `stage_properties` | runtime_error | output_mismatch | 1/30 | 1/30 |
| `stage_properties2` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `stage_scale_factor` | runtime_error | output_mismatch | 0/12 | 0/12 |
| `stage_stage3Ds_vector` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `static_length` | runtime_error | output_mismatch | 0/24 | 0/24 |
| `static_text` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `statictext_text` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `string_match` | runtime_error | output_mismatch | 0/51 | 2/51 |
| `string_replace` | runtime_error | output_mismatch | 0/51 | 1/51 |
| `string_search` | runtime_error | output_mismatch | 0/41 | 2/41 |
| `string_split` | runtime_error | output_mismatch | 0/29 | 10/29 |
| `stylesheet` | runtime_error | output_mismatch | 0/221 | 0/221 |
| `stylesheet_parse_color` | runtime_error | output_mismatch | 0/69 | 1/69 |
| `stylesheet_transform` | runtime_error | output_mismatch | 0/307 | 0/307 |
| `sub_super_same_field` | runtime_error | output_mismatch | 0/12 | 6/12 |
| `supercalls_coerce` | runtime_error | output_mismatch | 0/8 | 1/8 |
| `superinterface_call` | runtime_error | output_mismatch | 0/20 | 15/20 |
| `superinterface_instanceof` | runtime_error | output_mismatch | 0/18 | 4/18 |
| `swf_10_queued_goto_scripts_construct` | runtime_error | output_mismatch | 0/52 | 0/52 |
| `swf_9_goto_in_construct_frame` | runtime_error | output_mismatch | 0/20 | 1/20 |
| `swf_9_goto_in_enter_frame` | runtime_error | output_mismatch | 0/17 | 1/17 |
| `swf_9_goto_in_enter_frame_simple` | runtime_error | output_mismatch | 0/15 | 1/15 |
| `swf_9_queued_goto_scripts` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `swf_9_queued_goto_scripts_construct` | runtime_error | output_mismatch | 0/28 | 0/28 |
| `swf_9_versioning` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `swf_wrong_frame_count` | runtime_error | output_mismatch | 1/38 | 2/38 |
| `swf_wrong_frame_count_isplaying` | runtime_error | output_mismatch | 0/22 | 0/22 |
| `swz` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `system_setclipboard_null` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `tab_ordering_arrows` | runtime_error | output_mismatch | 0/998 | 0/998 |
| `tab_ordering_automatic_advanced` | runtime_error | output_mismatch | 0/184 | 0/184 |
| `tab_ordering_automatic_basic` | runtime_error | output_mismatch | 0/45 | 0/45 |
| `tab_ordering_children` | runtime_error | output_mismatch | 0/116 | 0/116 |
| `tab_ordering_custom_basic` | runtime_error | output_mismatch | 0/34 | 0/34 |
| `tab_ordering_properties` | runtime_error | output_mismatch | 0/732 | 0/732 |
| `tab_ordering_stage_tab_children` | runtime_error | output_mismatch | 0/32 | 0/32 |
| `tab_ordering_stage_tab_children_remove_root` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `tab_ordering_tabbable` | runtime_error | output_mismatch | 0/47 | 0/47 |
| `tabstop_properties` | runtime_error | output_mismatch | 0/105 | 0/105 |
| `text_element_basic` | runtime_error | output_mismatch | 0/34 | 0/34 |
| `text_engine_fontdescription` | runtime_error | output_mismatch | 0/27 | 0/27 |
| `text_engine_groupelement` | runtime_error | output_mismatch | 0/64 | 1/64 |
| `text_run` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `textblock_createline_fte` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `textblock_properties` | runtime_error | output_mismatch | 0/118 | 0/118 |
| `textbox_click` | runtime_error | output_mismatch | 0/37 | 0/37 |
| `textfield_event` | runtime_error | output_mismatch | 0/66 | 0/66 |
| `textfield_focusin_event` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `textfield_input_dead_keys_windows` | runtime_error | output_mismatch | 0/15 | 0/15 |
| `textfield_input_events` | runtime_error | output_mismatch | 0/25 | 0/25 |
| `textfield_unload` | runtime_error | output_mismatch | 1/39 | 1/39 |
| `textformat` | runtime_error | output_mismatch | 0/1134 | 0/1134 |
| `textformat_display` | runtime_error | output_mismatch | 0/14 | 0/14 |
| `textformat_font_max_length` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `textline_inapplicable_properties` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `textline_name` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `textline_validity` | runtime_error | output_mismatch | 0/162 | 0/162 |
| `timer` | runtime_error | output_mismatch | 0/90 | 0/90 |
| `timer_events` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `timer_finished` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `timer_reset` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `timer_setdelay` | runtime_error | output_mismatch | 1/5 | 1/5 |
| `trace` | runtime_error | output_mismatch | 2/12 | 5/12 |
| `try_catch` | runtime_error | output_mismatch | 0/11 | 5/11 |
| `uint_toexponential` | runtime_error | ruffle_matched | 0/1215 | 1115/1215 |
| `uint_toprecision` | runtime_error | ruffle_matched | 0/1125 | 692/1125 |
| `uncaught_errors_stringified` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `unescape` | runtime_error | output_mismatch | 2/28 | 25/28 |
| `url_loader` | runtime_error | output_mismatch | 0/25 | 0/25 |
| `url_vars` | runtime_error | output_mismatch | 0/27 | 0/27 |
| `urlrequest` | runtime_error | output_mismatch | 0/18 | 0/18 |
| `urlstream_basic` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `utils3d` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `vector3d` | runtime_error | output_mismatch | 0/397 | 2/397 |
| `vector_class` | runtime_error | output_mismatch | 0/36 | 0/36 |
| `vector_class_call` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `vector_coercion` | runtime_error | output_mismatch | 0/66 | 1/66 |
| `vector_concat` | runtime_error | output_mismatch | 0/90 | 1/90 |
| `vector_constr` | runtime_error | output_mismatch | 1/107 | 1/107 |
| `vector_enumeration` | runtime_error | output_mismatch | 0/5 | 0/5 |
| `vector_every` | runtime_error | output_mismatch | 0/92 | 1/92 |
| `vector_filter` | runtime_error | output_mismatch | 0/95 | 1/95 |
| `vector_holes` | runtime_error | output_mismatch | 1/24 | 1/24 |
| `vector_indexof` | runtime_error | output_mismatch | 1/302 | 1/302 |
| `vector_insertat` | runtime_error | output_mismatch | 0/270 | 1/270 |
| `vector_int_access` | runtime_error | output_mismatch | 1/4 | 1/4 |
| `vector_int_delete` | runtime_error | output_mismatch | 1/11 | 1/11 |
| `vector_join` | runtime_error | output_mismatch | 0/58 | 1/58 |
| `vector_lastindexof` | runtime_error | output_mismatch | 1/302 | 1/302 |
| `vector_legacy` | runtime_error | output_mismatch | 1/10 | 1/10 |
| `vector_map` | runtime_error | output_mismatch | 0/85 | 1/85 |
| `vector_object_final` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `vector_object_toString` | runtime_error | output_mismatch | 1/10 | 1/10 |
| `vector_pushpop` | runtime_error | output_mismatch | 0/255 | 1/255 |
| `vector_reborrow_bug` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `vector_removeat` | runtime_error | output_mismatch | 0/172 | 1/172 |
| `vector_reverse` | runtime_error | output_mismatch | 0/232 | 1/232 |
| `vector_shiftunshift` | runtime_error | output_mismatch | 0/252 | 1/252 |
| `vector_slice` | runtime_error | output_mismatch | 0/331 | 1/331 |
| `vector_sort` | runtime_error | output_mismatch | 0/905 | 1/905 |
| `vector_splice` | runtime_error | output_mismatch | 0/693 | 1/693 |
| `vector_splice_fixed_bug_compat` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `vector_tostring` | runtime_error | output_mismatch | 0/79 | 1/79 |
| `verification` | runtime_error | output_mismatch | 0/8 | 4/8 |
| `verify_dxns_without_flag` | runtime_error | output_mismatch | 0/3 | 1/3 |
| `verify_exception_target_two_jumps` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `verify_jump_to_middle_of_op` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `verify_stack` | runtime_error | output_mismatch | 0/5 | 2/5 |
| `weird_superinterface_properties` | runtime_error | ruffle_matched | 0/2 | 1/2 |
| `wrong_arg_count` | runtime_error | output_mismatch | 0/7 | 1/7 |
| `xml_abstract_equality` | runtime_error | output_mismatch | 0/36 | 0/36 |
| `xml_advanced` | runtime_error | output_mismatch | 0/52 | 0/52 |
| `xml_appendchild` | runtime_error | output_mismatch | 0/10 | 0/10 |
| `xml_appendchild_swf_v21` | runtime_error | output_mismatch | 0/13 | 0/13 |
| `xml_as_attribute` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `xml_attribute` | runtime_error | output_mismatch | 0/35 | 0/35 |
| `xml_attribute_name` | runtime_error | output_mismatch | 0/40 | 0/40 |
| `xml_basic` | runtime_error | output_mismatch | 0/32 | 0/32 |
| `xml_child` | runtime_error | output_mismatch | 0/25 | 0/25 |
| `xml_childindex` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `xml_children` | runtime_error | output_mismatch | 0/43 | 0/43 |
| `xml_class_call` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `xml_contains` | runtime_error | output_mismatch | 0/197 | 131/197 |
| `xml_copy` | runtime_error | output_mismatch | 0/20 | 0/20 |
| `xml_ctor_from_tostring` | runtime_error | output_mismatch | 0/23 | 0/23 |
| `xml_delete` | runtime_error | output_mismatch | 0/114 | 0/114 |
| `xml_elements` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `xml_equals_namespace_check` | runtime_error | output_mismatch | 0/2 | 1/2 |
| `xml_has_property_via_in` | runtime_error | output_mismatch | 0/26 | 23/26 |
| `xml_hasownproperty` | runtime_error | output_mismatch | 0/6 | 4/6 |
| `xml_ignore_white` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `xml_length` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `xml_list_as_attribute` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `xml_list_concat` | runtime_error | output_mismatch | 0/20 | 1/20 |
| `xml_list_enumerate` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `xml_methods_settings` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `xml_mismatched_tag` | runtime_error | output_mismatch | 0/37 | 17/37 |
| `xml_namespace` | runtime_error | output_mismatch | 0/39 | 0/39 |
| `xml_namespace_methods` | runtime_error | output_mismatch | 0/245 | 0/245 |
| `xml_namespaced_property` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `xml_no_namespace` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `xml_nodekind` | runtime_error | output_mismatch | 0/3 | 0/3 |
| `xml_normalize` | runtime_error | output_mismatch | 0/35 | 0/35 |
| `xml_notification_bubbling` | runtime_error | output_mismatch | 0/361 | 0/361 |
| `xml_parent` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `xml_set_children` | runtime_error | output_mismatch | 0/17 | 0/17 |
| `xml_set_name` | runtime_error | output_mismatch | 0/34 | 0/34 |
| `xml_settings` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `xml_simple_complex_content` | runtime_error | output_mismatch | 0/47 | 0/47 |
| `xml_socket` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `xml_text` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `xml_tostring` | runtime_error | output_mismatch | 0/6 | 0/6 |
| `xml_tostring_namespace` | runtime_error | output_mismatch | 0/12 | 1/12 |
| `xml_unescaping` | runtime_error | output_mismatch | 0/23 | 0/23 |
| `xml_weird_ignores` | runtime_error | output_mismatch | 0/54 | 0/54 |
| `xml_wildcard` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `xmldocument` | runtime_error | output_mismatch | 0/254 | 0/254 |
| `xmlnode` | runtime_error | output_mismatch | 0/3540 | 0/3540 |
| `zero_frame_clip` | runtime_error | output_mismatch | 0/3 | 0/3 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `core_exceptions` | runtime_error | 0/47 | 9/47 | -9 |
| `error_stack_trace` | runtime_error | 0/45 | 9/45 | -9 |
| `rtqname_not_namespace` | runtime_error | 0/12 | 1/12 | -1 |
| `xml_getdescendants_qname` | runtime_error | 0/21 | 1/21 | -1 |
