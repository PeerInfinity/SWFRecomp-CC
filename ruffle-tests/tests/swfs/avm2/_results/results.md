# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 13:35 UTC

**Git SHA**: `9a21db6258`

**Run Duration**: 76m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1200 |
| Passing | **354** (29.5%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **365** (30.4%) |
| Failing | 835 |
| Total expected lines | 148994 |
| Matching lines | 43791 (29.4%) |
| Mismatched lines | 105203 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 764 | 91.5% |
| Runtime Error | 71 | 8.5% |

## Passing Tests

**354 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.3s |  |
| 2 | `air_hidden_lookup` | 2 | 0.3s |  |
| 3 | `application_domain` | 4 | 1.5s |  |
| 4 | `array_access` | 18 | 1.6s |  |
| 5 | `array_access_interpreter` | 4 | 1.5s |  |
| 6 | `array_access_no_pubns` | 2 | 1.5s |  |
| 7 | `array_concat` | 41 | 1.6s |  |
| 8 | `array_constr` | 10 | 1.5s |  |
| 9 | `array_delete` | 44 | 1.6s |  |
| 10 | `array_enumeration` | 10 | 1.6s |  |
| 11 | `array_enumeration_elements` | 11 | 1.5s |  |
| 12 | `array_every` | 8 | 1.5s |  |
| 13 | `array_filter` | 6 | 1.5s |  |
| 14 | `array_foreach` | 18 | 1.5s |  |
| 15 | `array_hasownproperty` | 11 | 1.6s |  |
| 16 | `array_holes` | 9 | 1.5s |  |
| 17 | `array_index_max` | 84 | 1.3s |  |
| 18 | `array_indexof` | 25 | 1.6s |  |
| 19 | `array_join` | 26 | 1.6s |  |
| 20 | `array_lastindexof` | 29 | 1.5s |  |
| 21 | `array_length` | 14 | 1.5s |  |
| 22 | `array_literal` | 3 | 1.5s |  |
| 23 | `array_map` | 8 | 0.4s |  |
| 24 | `array_pop` | 52 | 1.6s |  |
| 25 | `array_push` | 24 | 1.5s |  |
| 26 | `array_reborrow_bug` | 6 | 1.5s |  |
| 27 | `array_reverse` | 28 | 1.6s |  |
| 28 | `array_shift` | 51 | 1.6s |  |
| 29 | `array_slice` | 39 | 1.6s |  |
| 30 | `array_some` | 8 | 1.5s |  |
| 31 | `array_sort` | 297 | 1.8s |  |
| 32 | `array_sort_fun_swf12` | 2 | 1.5s |  |
| 33 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 34 | `array_sort_random` | 210 | 1.6s |  |
| 35 | `array_sort_swf10_32bit` | 1 | 1.6s |  |
| 36 | `array_sorton` | 545 | 2.0s |  |
| 37 | `array_sparse_ops` | 41 | 1.6s |  |
| 38 | `array_splice` | 133 | 1.7s |  |
| 39 | `array_splice2` | 428 | 1.8s |  |
| 40 | `array_splice_types` | 48 | 1.7s |  |
| 41 | `array_storage` | 8 | 1.6s |  |
| 42 | `array_tolocalestring` | 9 | 1.6s |  |
| 43 | `array_tostring` | 12 | 1.6s |  |
| 44 | `array_unshift` | 24 | 1.6s |  |
| 45 | `array_valueof` | 9 | 1.5s |  |
| 46 | `array_vector_null_callback` | 10 | 1.6s |  |
| 47 | `astype` | 28 | 1.6s |  |
| 48 | `astypelate` | 24 | 1.7s |  |
| 49 | `astypelate_propagates` | 1 | 1.5s |  |
| 50 | `away3d_advanced_shallow_water_demo` | 0 | 62.0s |  |
| 51 | `bitand` | 1058 | 3.6s |  |
| 52 | `bitmapdata_applyfilter_blur` | 0 | 20.2s |  |
| 53 | `bitmapdata_applyfilter_colormatrix` | 0 | 1.8s |  |
| 54 | `bitmapdata_applyfilter_destpoint` | 0 | 20.0s |  |
| 55 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.2s |  |
| 56 | `bitmapdata_colortransform` | 0 | 1.7s |  |
| 57 | `bitmapdata_draw` | 0 | 21.2s |  |
| 58 | `bitmapdata_draw_colortransform` | 0 | 1.7s |  |
| 59 | `bitmapdata_draw_filters` | 0 | 21.4s |  |
| 60 | `bitmapdata_draw_masks` | 0 | 1.7s |  |
| 61 | `bitmapdata_draw_rotation` | 0 | 1.7s |  |
| 62 | `bitmapdata_draw_self_via_graphic` | 0 | 1.7s |  |
| 63 | `bitmapdata_draw_stage` | 0 | 21.0s |  |
| 64 | `bitmapdata_drawwithquality` | 0 | 1.9s |  |
| 65 | `bitmapdata_fillrect` | 0 | 1.7s |  |
| 66 | `bitmapdata_filter_sourcerect` | 0 | 21.8s |  |
| 67 | `bitmapdata_opaque` | 0 | 1.7s |  |
| 68 | `bitmapdata_pixeldissolve_image` | 0 | 1.8s |  |
| 69 | `bitmapdata_sync` | 0 | 1.8s |  |
| 70 | `bitnot` | 46 | 1.6s |  |
| 71 | `bitor` | 1058 | 4.0s |  |
| 72 | `bitxor` | 1058 | 4.0s |  |
| 73 | `blend_multiply_alpha` | 0 | 1.7s |  |
| 74 | `blend_scroll` | 0 | 1.4s |  |
| 75 | `boolean_constr` | 32 | 1.3s |  |
| 76 | `boolean_negation` | 30 | 1.3s |  |
| 77 | `boolean_tostring` | 8 | 1.3s |  |
| 78 | `callee_in_initializer` | 6 | 1.2s |  |
| 79 | `callproplex_class` | 1 | 1.3s |  |
| 80 | `catch_class` | 6 | 1.3s |  |
| 81 | `catch_scope_slot` | 7 | 1.4s |  |
| 82 | `class_cast_call` | 14 | 1.3s |  |
| 83 | `class_enumeration` | 4 | 1.3s |  |
| 84 | `class_has_own_property` | 2 | 1.3s |  |
| 85 | `class_init_interpreter_mode` | 1 | 1.2s |  |
| 86 | `class_is` | 32 | 1.3s |  |
| 87 | `class_methods` | 5 | 1.3s |  |
| 88 | `class_object_properties` | 10 | 1.9s |  |
| 89 | `class_singleton` | 18 | 1.8s |  |
| 90 | `class_supercalls_errors` | 35 | 1.9s |  |
| 91 | `class_supercalls_mismatched` | 26 | 1.8s |  |
| 92 | `class_superclass_wrong_order` | 1 | 1.6s |  |
| 93 | `class_to_locale_string` | 2 | 1.7s |  |
| 94 | `class_to_string` | 2 | 1.7s |  |
| 95 | `class_value_of` | 2 | 1.7s |  |
| 96 | `closures` | 12 | 1.7s |  |
| 97 | `coerce_property` | 33 | 1.8s |  |
| 98 | `coerce_return_type` | 40 | 1.8s |  |
| 99 | `coerce_return_type_fail` | 2 | 1.7s |  |
| 100 | `coerce_return_void` | 3 | 1.6s |  |
| 101 | `coerce_string` | 86 | 1.8s |  |
| 102 | `coerce_string_precision` | 28 | 1.7s |  |
| 103 | `construct_errors_swf10` | 8 | 1.7s |  |
| 104 | `constructor_call` | 3 | 1.7s |  |
| 105 | `constructprop_dynamic_primitive` | 7 | 1.7s |  |
| 106 | `control_flow_bool` | 4 | 1.6s |  |
| 107 | `control_flow_stricteq` | 8 | 1.6s |  |
| 108 | `convert_boolean` | 30 | 1.6s |  |
| 109 | `convert_integer` | 90 | 1.7s |  |
| 110 | `convert_number` | 56 | 1.8s |  |
| 111 | `convert_uinteger` | 90 | 1.8s |  |
| 112 | `declocal` | 46 | 1.6s |  |
| 113 | `declocal_i` | 46 | 1.6s |  |
| 114 | `decrement` | 46 | 1.6s |  |
| 115 | `decrement_i` | 46 | 1.6s |  |
| 116 | `default_values` | 7 | 1.6s |  |
| 117 | `displayobject_blendmode` | 0 | 20.1s |  |
| 118 | `displayobject_colortransform_nested` | 0 | 20.3s |  |
| 119 | `displayobject_getbounds_shape` | 0 | 20.0s |  |
| 120 | `displayobject_mask_self_referential` | 0 | 1.5s |  |
| 121 | `displayobject_set_matrix_nested` | 0 | 20.5s |  |
| 122 | `divide` | 1058 | 2.6s |  |
| 123 | `duplicate_defs` | 1 | 0.3s |  |
| 124 | `eager_init` | 1 | 1.1s |  |
| 125 | `equals` | 512 | 2.5s |  |
| 126 | `error_prototype` | 15 | 1.5s |  |
| 127 | `error_stack_trace_debug_swf17` | 0 | 19.7s |  |
| 128 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 129 | `error_stack_trace_release_swf17` | 0 | 0.3s |  |
| 130 | `error_stack_trace_release_swf18` | 0 | 0.2s |  |
| 131 | `es3_inheritance` | 31 | 1.6s |  |
| 132 | `es4_inheritance` | 30 | 1.5s |  |
| 133 | `es4_interfaces` | 30 | 1.6s |  |
| 134 | `es4_method_binding` | 8 | 1.6s |  |
| 135 | `es4_oop_prototypes` | 14 | 1.7s |  |
| 136 | `es4_protected_inheritance` | 6 | 1.6s |  |
| 137 | `event_bubbles` | 2 | 1.5s |  |
| 138 | `event_cancelable` | 2 | 1.7s |  |
| 139 | `event_type` | 1 | 1.5s |  |
| 140 | `eventdispatcher_dispatchevent_this` | 5 | 1.5s |  |
| 141 | `eventdispatcher_haseventlistener` | 25 | 1.6s |  |
| 142 | `falsiness` | 30 | 1.5s |  |
| 143 | `finddef` | 3 | 1.5s |  |
| 144 | `findprop_global_prototype` | 6 | 1.6s |  |
| 145 | `function_call` | 12 | 1.5s |  |
| 146 | `function_call_arguments` | 46 | 1.6s |  |
| 147 | `function_call_arguments_enumerate` | 5 | 1.5s |  |
| 148 | `function_call_coercion` | 108 | 1.6s |  |
| 149 | `function_call_default` | 6 | 1.5s |  |
| 150 | `function_call_rest` | 22 | 1.5s |  |
| 151 | `function_call_types` | 3 | 1.4s |  |
| 152 | `function_call_via_apply` | 11 | 1.5s |  |
| 153 | `function_call_via_call` | 3 | 1.4s |  |
| 154 | `function_display_anonymous` | 7 | 1.5s |  |
| 155 | `function_length` | 6 | 1.5s |  |
| 156 | `function_object` | 2 | 1.5s |  |
| 157 | `function_proto` | 5 | 1.6s |  |
| 158 | `function_to_locale_string` | 4 | 1.5s |  |
| 159 | `function_to_string` | 4 | 1.4s |  |
| 160 | `function_type` | 6 | 1.5s |  |
| 161 | `function_unbound_this` | 51 | 1.6s |  |
| 162 | `function_value_of` | 4 | 1.5s |  |
| 163 | `get_slot_edge_cases` | 1 | 1.4s |  |
| 164 | `getglobalslot` | 1 | 1.5s |  |
| 165 | `getouterscope` | 8 | 1.5s |  |
| 166 | `getter_different_namespace_setter` | 2 | 1.5s |  |
| 167 | `graphics_bitmaps` | 0 | 1.8s |  |
| 168 | `graphics_direct_commands` | 0 | 1.7s |  |
| 169 | `graphics_gradients` | 0 | 1.6s |  |
| 170 | `graphics_gradients_nulls` | 0 | 1.6s |  |
| 171 | `graphics_round_rects` | 0 | 1.6s |  |
| 172 | `graphics_simple_shapes` | 0 | 1.7s |  |
| 173 | `greaterequals` | 512 | 2.4s |  |
| 174 | `greaterthan` | 512 | 2.4s |  |
| 175 | `has_own_property` | 102 | 1.7s |  |
| 176 | `hasownproperty_namespaces` | 2 | 1.5s |  |
| 177 | `hello_world` | 1 | 1.5s |  |
| 178 | `if_eq` | 10 | 1.5s |  |
| 179 | `if_gt` | 1 | 1.5s |  |
| 180 | `if_gte` | 10 | 1.5s |  |
| 181 | `if_lt` | 1 | 0.4s |  |
| 182 | `if_lte` | 10 | 0.4s |  |
| 183 | `if_ne` | 7 | 1.5s |  |
| 184 | `if_stricteq` | 6 | 1.5s |  |
| 185 | `if_strictne` | 11 | 1.5s |  |
| 186 | `in` | 102 | 1.7s |  |
| 187 | `inclocal` | 46 | 1.5s |  |
| 188 | `inclocal_i` | 46 | 1.5s |  |
| 189 | `increment` | 46 | 1.6s |  |
| 190 | `increment_i` | 46 | 1.5s |  |
| 191 | `instanceof` | 58 | 1.7s |  |
| 192 | `int_constr` | 92 | 1.6s |  |
| 193 | `int_edge_cases` | 19 | 1.5s |  |
| 194 | `int_instanceof` | 3 | 1.4s |  |
| 195 | `int_tofixed` | 1215 | 1.4s |  |
| 196 | `int_tostring` | 3375 | 1.7s |  |
| 197 | `interface_namespaces` | 78 | 1.6s |  |
| 198 | `is_finite` | 46 | 1.6s |  |
| 199 | `is_nan` | 46 | 1.4s |  |
| 200 | `is_prototype_of` | 12 | 1.5s |  |
| 201 | `issue_10221` | 2 | 1.5s |  |
| 202 | `issue_14901` | 1 | 1.4s |  |
| 203 | `istype` | 24 | 1.4s |  |
| 204 | `istypelate` | 58 | 1.6s |  |
| 205 | `istypelate_coerce` | 198 | 1.8s |  |
| 206 | `json_errors` | 9 | 20.4s |  |
| 207 | `json_parse` | 21 | 1.4s |  |
| 208 | `json_version_gated` | 1 | 1.3s |  |
| 209 | `lazyinit` | 17 | 1.4s |  |
| 210 | `lessequals` | 512 | 2.5s |  |
| 211 | `lessthan` | 512 | 2.5s |  |
| 212 | `lshift` | 1058 | 3.5s |  |
| 213 | `math` | 497 | 1.6s |  |
| 214 | `modulo` | 1058 | 3.6s |  |
| 215 | `movieclip_stop` | 1 | 16.7s |  |
| 216 | `multiply` | 1058 | 2.7s |  |
| 217 | `negate` | 30 | 1.1s |  |
| 218 | `negative_volume_panned` | 0 | 1.2s |  |
| 219 | `newactivation_in_script_init` | 3 | 1.4s |  |
| 220 | `newclass_twice` | 3 | 1.4s |  |
| 221 | `nonconflicting_declarations` | 0 | 1.6s |  |
| 222 | `number_autoconv_array_sort_32bit` | 1 | 1.5s |  |
| 223 | `number_constr` | 58 | 1.6s |  |
| 224 | `number_toexponential` | 378 | 1.6s |  |
| 225 | `number_toexponential2` | 35 | 1.5s |  |
| 226 | `number_tofixed` | 378 | 1.4s |  |
| 227 | `number_toprecision` | 350 | 1.6s |  |
| 228 | `obfuscated_class_names` | 3 | 1.5s |  |
| 229 | `object_enumeration` | 10 | 1.6s |  |
| 230 | `object_prototype` | 4 | 1.5s |  |
| 231 | `object_to_locale_string` | 2 | 1.5s |  |
| 232 | `object_to_string` | 2 | 1.4s |  |
| 233 | `object_value_of` | 2 | 1.4s |  |
| 234 | `op_coerce` | 54 | 0.9s |  |
| 235 | `op_coerce_x` | 54 | 1.6s |  |
| 236 | `op_escxattr` | 2 | 1.5s |  |
| 237 | `op_escxelem` | 2 | 1.5s |  |
| 238 | `op_lookupswitch` | 4 | 1.5s |  |
| 239 | `optimize_coerce` | 1 | 1.4s |  |
| 240 | `param_default_value_has_zero_cpool_index` | 1 | 1.1s |  |
| 241 | `parse_float` | 80 | 1.2s |  |
| 242 | `pixelbender_effect_BlurredFocus` | 0 | 19.7s |  |
| 243 | `pixelbender_effect_glassDisplace` | 0 | 5.2s |  |
| 244 | `pixelbender_effect_smudge` | 0 | 3.2s |  |
| 245 | `pixelbender_effect_tintype` | 0 | 2.8s |  |
| 246 | `pixelbender_effect_twirl` | 0 | 3.7s |  |
| 247 | `pixelbender_images` | 0 | 2.5s |  |
| 248 | `primitive_edge_cases` | 1 | 1.4s |  |
| 249 | `property_priority` | 22 | 1.8s |  |
| 250 | `property_priority_three_level` | 6 | 1.6s |  |
| 251 | `propertyisenumerable_namespaces` | 6 | 1.5s |  |
| 252 | `prototype_set_null` | 7 | 1.5s |  |
| 253 | `regexp_constr` | 148 | 1.8s |  |
| 254 | `regexp_exec` | 19 | 1.5s |  |
| 255 | `regexp_extended` | 47 | 1.5s |  |
| 256 | `regexp_multiargs` | 1 | 1.6s |  |
| 257 | `regexp_test` | 27 | 1.6s |  |
| 258 | `regexp_toString` | 10 | 1.6s |  |
| 259 | `resolve_order` | 4 | 1.5s |  |
| 260 | `rng` | 1 | 2.8s |  |
| 261 | `rshift` | 1058 | 3.7s |  |
| 262 | `set_property_is_enumerable` | 85 | 1.8s |  |
| 263 | `slot_disp_id_shared_numbering` | 1 | 19.2s |  |
| 264 | `slots_force_autoassigned` | 1 | 1.5s |  |
| 265 | `sprite_with_frames` | 0 | 1.8s |  |
| 266 | `stage3d_agal_cross_product` | 0 | 2.7s |  |
| 267 | `stage3d_bitmap` | 0 | 22.1s |  |
| 268 | `stage3d_float1_index` | 0 | 21.9s |  |
| 269 | `stage3d_fractal` | 0 | 3.6s |  |
| 270 | `stage3d_ignore_sampler_override` | 0 | 22.2s |  |
| 271 | `stage3d_program_constants_bytearray_be` | 0 | 23.5s |  |
| 272 | `stage3d_program_constants_bytearray_le` | 0 | 3.5s |  |
| 273 | `stage3d_raytrace` | 0 | 21.0s |  |
| 274 | `stage3d_stencil` | 0 | 21.8s |  |
| 275 | `stage3d_texture` | 0 | 7.0s |  |
| 276 | `stage3d_texture_bytearray` | 0 | 3.9s |  |
| 277 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.4s |  |
| 278 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 4.0s |  |
| 279 | `stage3d_triangle` | 0 | 2.9s |  |
| 280 | `stage3d_triangle_bytes4` | 0 | 3.1s |  |
| 281 | `stage3d_triangle_float1` | 0 | 3.1s |  |
| 282 | `stage3d_triangle_index_upload` | 0 | 3.0s |  |
| 283 | `static_var_with_this_in_ctor` | 2 | 1.6s |  |
| 284 | `stored_properties` | 11 | 1.7s |  |
| 285 | `strict_equality` | 34 | 1.7s |  |
| 286 | `string_call` | 13 | 1.7s |  |
| 287 | `string_case` | 23 | 1.7s |  |
| 288 | `string_char_at` | 27 | 1.7s |  |
| 289 | `string_char_code_at` | 28 | 1.6s |  |
| 290 | `string_concat_fromcharcode` | 36 | 1.7s |  |
| 291 | `string_constr` | 25 | 1.7s |  |
| 292 | `string_indexof_lastindexof` | 87 | 1.8s |  |
| 293 | `string_length` | 16 | 1.7s |  |
| 294 | `string_locale_compare` | 39 | 1.8s |  |
| 295 | `string_match` | 51 | 1.8s |  |
| 296 | `string_relational_compare` | 4 | 1.6s |  |
| 297 | `string_replace` | 51 | 1.8s |  |
| 298 | `string_search` | 41 | 1.7s |  |
| 299 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 300 | `string_split` | 29 | 1.7s |  |
| 301 | `string_substr_negative` | 21 | 1.6s |  |
| 302 | `string_substr_weird` | 182 | 1.6s |  |
| 303 | `subtract` | 1058 | 4.1s |  |
| 304 | `super_get_call` | 12 | 1.7s |  |
| 305 | `supercall_two_classobjects` | 2 | 1.7s |  |
| 306 | `swf8` | 1 | 1.4s |  |
| 307 | `symbol_class_root_not_zero` | 1 | 1.4s |  |
| 308 | `symbolclass_invalid_utf8` | 2 | 1.5s |  |
| 309 | `throw` | 3 | 1.5s |  |
| 310 | `truthiness` | 30 | 1.5s |  |
| 311 | `try_catch` | 11 | 1.6s |  |
| 312 | `try_catch_typed` | 12 | 1.6s |  |
| 313 | `typeof` | 30 | 1.6s |  |
| 314 | `uint_constr` | 92 | 1.6s |  |
| 315 | `uint_tofixed` | 1215 | 1.4s |  |
| 316 | `uint_tostring` | 3375 | 1.7s |  |
| 317 | `unchecked_function` | 15 | 1.5s |  |
| 318 | `urshift` | 1058 | 3.6s |  |
| 319 | `vector_class` | 36 | 1.9s |  |
| 320 | `vector_class_call` | 11 | 1.7s |  |
| 321 | `vector_coercion` | 66 | 2.1s |  |
| 322 | `vector_concat` | 90 | 1.8s |  |
| 323 | `vector_constr` | 107 | 1.7s |  |
| 324 | `vector_enumeration` | 5 | 1.5s |  |
| 325 | `vector_every` | 92 | 1.9s |  |
| 326 | `vector_filter` | 95 | 1.9s |  |
| 327 | `vector_holes` | 24 | 1.6s |  |
| 328 | `vector_indexof` | 302 | 2.4s |  |
| 329 | `vector_insertat` | 270 | 1.9s |  |
| 330 | `vector_int_access` | 4 | 1.5s |  |
| 331 | `vector_int_delete` | 11 | 1.5s |  |
| 332 | `vector_join` | 58 | 1.7s |  |
| 333 | `vector_lastindexof` | 302 | 1.5s |  |
| 334 | `vector_legacy` | 10 | 1.5s |  |
| 335 | `vector_map` | 85 | 2.4s |  |
| 336 | `vector_object_final` | 1 | 1.3s |  |
| 337 | `vector_object_toString` | 10 | 0.6s |  |
| 338 | `vector_pushpop` | 255 | 1.1s |  |
| 339 | `vector_reborrow_bug` | 10 | 0.6s |  |
| 340 | `vector_removeat` | 172 | 1.0s |  |
| 341 | `vector_reverse` | 232 | 1.0s |  |
| 342 | `vector_shiftunshift` | 252 | 0.5s |  |
| 343 | `vector_slice` | 331 | 1.1s |  |
| 344 | `vector_sort` | 905 | 2.4s |  |
| 345 | `vector_splice` | 693 | 1.4s |  |
| 346 | `vector_splice_fixed_bug_compat` | 4 | 0.6s |  |
| 347 | `vector_tostring` | 79 | 0.8s |  |
| 348 | `verify_abnormal_loop` | 1 | 0.5s |  |
| 349 | `verify_exception_targets_edge_case` | 1 | 0.5s |  |
| 350 | `verify_lookup_switch_edge_case` | 1 | 0.5s |  |
| 351 | `verify_unreachable_exception` | 2 | 0.5s |  |
| 352 | `versioned_isplaying` | 2 | 0.5s |  |
| 353 | `virtual_properties` | 16 | 0.6s |  |
| 354 | `with` | 4 | 0.6s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 2 | `blend_transform` | 1 | 1 | 1.3s |  |
| 3 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.5s |  |
| 4 | `freestanding_superclass` | 3 | 4 | 1.4s |  |
| 5 | `int_toexponential` | 76 | 76 | 1.6s |  |
| 6 | `int_toprecision` | 441 | 441 | 1.6s |  |
| 7 | `slot_holes_fail` | 1 | 1 | 1.4s |  |
| 8 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.5s |  |
| 9 | `uint_toexponential` | 100 | 100 | 1.6s |  |
| 10 | `uint_toprecision` | 433 | 433 | 1.6s |  |
| 11 | `weird_superinterface_properties` | 1 | 1 | 0.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**39 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271 | 1275 | 4 |  |
| 2 | `displayobject_alpha` | 99.6% | 276 | 277 | 1 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 5 | `error_tostring` | 93.1% | 27 | 29 | 2 |  |
| 6 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 7 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 8 | `xml_has_property_via_in` | 88.5% | 23 | 26 | 3 |  |
| 9 | `interactiveobject_enabled` | 88.0% | 22 | 25 | 3 |  |
| 10 | `error_tostring_more` | 83.7% | 72 | 86 | 14 |  |
| 11 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 12 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 13 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 14 | `event_valueof_tostring` | 77.8% | 14 | 18 | 4 |  |
| 15 | `eventdispatcher_dispatchevent` | 75.0% | 9 | 12 | 3 |  |
| 16 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 17 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 18 | `number_autoconv` | 71.4% | 15 | 21 | 6 |  |
| 19 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 20 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 21 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 22 | `fast_index_access` | 66.7% | 8 | 12 | 4 |  |
| 23 | `xml_hasownproperty` | 66.7% | 4 | 6 | 2 |  |
| 24 | `xml_contains` | 66.5% | 131 | 197 | 66 |  |
| 25 | `nested_iteration` | 63.6% | 7 | 11 | 4 |  |
| 26 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15 | 24 | 9 |  |
| 27 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 28 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 29 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 30 | `date` | 50.0% | 15 | 30 | 15 |  |
| 31 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 32 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 33 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 34 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 35 | `place_object_same_depth_frame` | 50.0% | 1 | 2 | 1 |  |
| 36 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 37 | `subclass_superclass_linked_symbol` | 50.0% | 3 | 6 | 3 |  |
| 38 | `verification` | 50.0% | 4 | 8 | 4 |  |
| 39 | `xml_equals_namespace_check` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**71 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `applicationdomain_getqualifieddefinitionnames` | exit code 1 | 1.5s |  |
| 2 | `array_access_oob_interpreter` | exit code 1 | 1.4s |  |
| 3 | `bitmap_subclass` | exit code 1 | 2.7s |  |
| 4 | `bitmap_subclass_properties` | exit code 1 | 1.9s |  |
| 5 | `bitmapdata_copychannel` | exit code 1 (output matches) | 23.3s |  |
| 6 | `bitmapdata_draw_cpu_overwrite_gpu` | exit code 1 (output matches) | 21.4s |  |
| 7 | `checkfilter` | exit code 1 | 1.3s |  |
| 8 | `content_element_basic` | exit code 1 | 2.0s |  |
| 9 | `core_exceptions` | exit code 1 | 2.2s |  |
| 10 | `dictionary_access_no_pubns` | exit code 1 | 1.5s |  |
| 11 | `doabc_is_eager` | exit code 1 | 16.2s |  |
| 12 | `domain_memory` | exit code 1 | 1.1s |  |
| 13 | `edittext_always_show_selection` | exit code 1 (output matches) | 16.8s |  |
| 14 | `edittext_at_point_methods_basic` | exit code 1 | 2.0s |  |
| 15 | `edittext_autosize_align` | exit code 1 (output matches) | 16.9s |  |
| 16 | `edittext_autosize_height_dynamic` | exit code 1 | 16.7s |  |
| 17 | `edittext_autosize_height_input` | exit code 1 | 1.2s |  |
| 18 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 2.2s |  |
| 19 | `edittext_autosize_lazy_bounds_visual` | exit code 1 (output matches) | 16.6s |  |
| 20 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 1.4s |  |
| 21 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.2s |  |
| 22 | `edittext_device_transform_layout` | exit code 1 | 1.2s |  |
| 23 | `edittext_empty_text_format` | exit code 1 | 1.1s |  |
| 24 | `edittext_get_char_index_at_point` | exit code 1 | 20.7s |  |
| 25 | `edittext_get_line_index_at_point` | exit code 1 | 20.2s |  |
| 26 | `edittext_get_line_index_of_char` | exit code 1 | 2.8s |  |
| 27 | `edittext_getcharboundaries` | exit code 1 | 1.9s |  |
| 28 | `edittext_getcharboundaries_culling` | exit code 1 | 1.8s |  |
| 29 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.6s |  |
| 30 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.6s |  |
| 31 | `edittext_line_methods` | exit code 1 | 2.6s |  |
| 32 | `edittext_line_metrics` | exit code 1 | 21.7s |  |
| 33 | `edittext_max_scroll_h_basic` | exit code 1 | 1.7s |  |
| 34 | `edittext_max_scroll_v_basic` | exit code 1 | 1.6s |  |
| 35 | `edittext_mouse_selection` | exit code 1 | 21.4s |  |
| 36 | `edittext_wordwrap_word` | exit code 1 | 1.9s |  |
| 37 | `edittext_wrap_breaks` | exit code 1 | 2.0s |  |
| 38 | `error_stack_trace` | exit code 1 | 1.5s |  |
| 39 | `font_enumeratefonts_filter` | exit code 1 | 2.1s |  |
| 40 | `font_enumeratefonts_order` | exit code 1 | 2.2s |  |
| 41 | `goto_nested_construct_sibling` | exit code 1 | 1.9s |  |
| 42 | `graphics_bitmap_fill` | exit code 1 (output matches) | 2.9s |  |
| 43 | `large_preload_from_bytes` | exit code 1 | 1.6s |  |
| 44 | `large_preload_image_from_bytes` | exit code 1 | 1.7s |  |
| 45 | `method_without_body` | exit code 1 | 18.8s |  |
| 46 | `mouse_wheel_events` | exit code 1 | 21.2s |  |
| 47 | `namespace_constr` | exit code 1 | 1.3s |  |
| 48 | `pixelbender_conversions` | exit code 1 | 1.4s |  |
| 49 | `pixelbender_div` | exit code 1 | 1.4s |  |
| 50 | `pixelbender_input` | exit code 1 | 17.8s |  |
| 51 | `pixelbender_malformed_data` | exit code 1 | 17.5s |  |
| 52 | `pixelbender_parameters` | exit code 1 | 1.4s |  |
| 53 | `pixelbender_parameters_bool` | exit code 1 | 1.4s |  |
| 54 | `pixelbender_parameters_int_vs_bool` | exit code 1 | 1.2s |  |
| 55 | `pixelbender_rsqrt` | exit code 1 | 1.2s |  |
| 56 | `pixelbender_shaderdata_setter` | exit code 1 | 3.2s |  |
| 57 | `pixelbender_vector_output` | exit code 1 | 1.8s |  |
| 58 | `property_priority_scope_cache_order` | exit code 1 | 21.6s |  |
| 59 | `rtqname_not_namespace` | exit code 1 | 1.6s |  |
| 60 | `sound_load_multiple` | exit code 1 | 2.4s |  |
| 61 | `stage3d_blend` | exit code 1 | 20.6s |  |
| 62 | `stage3d_rotating_cube` | exit code 1 (output matches) | 3.4s |  |
| 63 | `stage3d_sampler` | exit code 1 (output matches) | 3.0s |  |
| 64 | `stage3d_sampler_partial_upload` | exit code 1 (output matches) | 2.9s |  |
| 65 | `supercalls_weird` | exit code 1 | 1.6s |  |
| 66 | `symbol_class_binary_data` | exit code 1 | 1.6s |  |
| 67 | `textline_splitting_basic` | exit code 1 | 1.8s |  |
| 68 | `verify_typecheck` | exit code 1 | 0.6s |  |
| 69 | `xml_descendants` | exit code 1 | 1.6s |  |
| 70 | `xml_explicit_use_namespace` | exit code 1 | 1.5s |  |
| 71 | `xml_getdescendants_qname` | exit code 1 | 1.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**764 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271/1275 | 1275 | 1275 |  |
| 2 | `displayobject_alpha` | 99.6% | 276/277 | 277 | 277 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 5 | `error_tostring` | 93.1% | 27/29 | 29 | 29 |  |
| 6 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 7 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 8 | `xml_has_property_via_in` | 88.5% | 23/26 | 26 | 26 |  |
| 9 | `interactiveobject_enabled` | 88.0% | 22/25 | 25 | 25 |  |
| 10 | `error_tostring_more` | 83.7% | 72/86 | 86 | 86 |  |
| 11 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 12 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 13 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 14 | `event_valueof_tostring` | 77.8% | 14/18 | 18 | 18 |  |
| 15 | `eventdispatcher_dispatchevent` | 75.0% | 9/12 | 12 | 12 |  |
| 16 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 17 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 18 | `number_autoconv` | 71.4% | 15/21 | 16 | 21 |  |
| 19 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 20 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 21 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 22 | `fast_index_access` | 66.7% | 8/12 | 8 | 12 |  |
| 23 | `xml_hasownproperty` | 66.7% | 4/6 | 6 | 6 |  |
| 24 | `xml_contains` | 66.5% | 131/197 | 197 | 197 |  |
| 25 | `nested_iteration` | 63.6% | 7/11 | 7 | 11 |  |
| 26 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15/24 | 24 | 22 |  |
| 27 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 28 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 29 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 30 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 31 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 32 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 33 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 34 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 35 | `place_object_same_depth_frame` | 50.0% | 1/2 | 2 | 1 |  |
| 36 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 37 | `subclass_superclass_linked_symbol` | 50.0% | 3/6 | 6 | 4 |  |
| 38 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 39 | `xml_equals_namespace_check` | 50.0% | 1/2 | 2 | 2 |  |
| 40 | `xml_mismatched_tag` | 45.9% | 17/37 | 34 | 37 |  |
| 41 | `get_definition_by_name` | 45.5% | 5/11 | 5 | 11 |  |
| 42 | `eventdispatcher_dispatchevent_cancel` | 45.0% | 9/20 | 9 | 20 |  |
| 43 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 44 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 45 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 46 | `dictionary_iter_modify` | 37.5% | 3/8 | 4 | 8 |  |
| 47 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 48 | `event_clone_error_redispatch` | 33.3% | 1/3 | 2 | 3 |  |
| 49 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 50 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 51 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 52 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 53 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 54 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 55 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 56 | `function_proto_created` | 31.1% | 19/61 | 19 | 61 |  |
| 57 | `event_clone` | 30.0% | 6/20 | 6 | 20 |  |
| 58 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 59 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 60 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 61 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 62 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 63 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 64 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 65 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 66 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 67 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 68 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 69 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 70 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 71 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 72 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 73 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 74 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 75 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 76 | `event_clone_on_redispatch` | 20.0% | 2/10 | 8 | 10 |  |
| 77 | `event_target_getter` | 20.0% | 1/5 | 2 | 5 |  |
| 78 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 79 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 80 | `soundmixer_buffertime` | 20.0% | 1/5 | 1 | 5 |  |
| 81 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 82 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 83 | `event_isdefaultprevented` | 16.7% | 2/12 | 2 | 12 |  |
| 84 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 85 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 86 | `soundmixer_stopall` | 16.7% | 1/6 | 1 | 6 |  |
| 87 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 88 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 89 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 90 | `class_call` | 15.6% | 5/32 | 5 | 32 |  |
| 91 | `movieclip_gotoandstop` | 15.4% | 2/13 | 2 | 13 |  |
| 92 | `doabc_and_symbolclass_script_init_goto` | 14.3% | 1/7 | 5 | 7 |  |
| 93 | `movieclip_goto_overwrite` | 14.3% | 2/14 | 2 | 14 |  |
| 94 | `movieclip_gotoandstop_framescripts_self` | 14.3% | 1/7 | 1 | 7 |  |
| 95 | `movieclip_prev_scene` | 14.3% | 1/7 | 1 | 7 |  |
| 96 | `stage_framerate_nan` | 14.3% | 1/7 | 1 | 7 |  |
| 97 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 98 | `movieclip_goto_during_frame_script` | 13.3% | 2/15 | 2 | 15 |  |
| 99 | `movieclip_gotoandplay` | 13.3% | 2/15 | 2 | 15 |  |
| 100 | `stage_mouseenabled` | 13.3% | 2/15 | 2 | 15 |  |
| 101 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 102 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 103 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 104 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 105 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 106 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 107 | `soundchannel_stop` | 12.5% | 1/8 | 1 | 8 |  |
| 108 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 109 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 110 | `amf_dictionary` | 11.1% | 1/9 | 1 | 9 |  |
| 111 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 112 | `bitmapdata_embedded` | 11.1% | 1/9 | 1 | 9 |  |
| 113 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 114 | `event_target_set` | 11.1% | 1/9 | 9 | 9 |  |
| 115 | `eventdispatcher_dispatchevent_indirect` | 11.1% | 1/9 | 1 | 9 |  |
| 116 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 117 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 118 | `qname_enumeration` | 11.1% | 1/9 | 1 | 9 |  |
| 119 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 120 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 121 | `event_formattostring` | 9.7% | 3/31 | 3 | 31 |  |
| 122 | `construct_frame_list` | 9.1% | 2/22 | 2 | 22 |  |
| 123 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 124 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 125 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 126 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 127 | `goto_in_constructframe` | 8.3% | 1/12 | 1 | 12 |  |
| 128 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 129 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 130 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 131 | `qname_constr_namespace` | 8.3% | 2/24 | 2 | 24 |  |
| 132 | `xml_tostring_namespace` | 8.3% | 1/12 | 1 | 12 |  |
| 133 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 134 | `bitmapdata_clone` | 7.7% | 1/13 | 1 | 13 |  |
| 135 | `button_nested_frame_simple` | 7.4% | 2/27 | 3 | 27 |  |
| 136 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 137 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 138 | `soundchannel_soundcomplete` | 6.2% | 1/16 | 1 | 16 |  |
| 139 | `amf_array_serialization` | 5.9% | 1/17 | 1 | 17 |  |
| 140 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 141 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 142 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 143 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 144 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 145 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 146 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 147 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 148 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 149 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 150 | `sound_play` | 5.3% | 1/19 | 1 | 19 |  |
| 151 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 152 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 153 | `get_qualified_class_name` | 5.0% | 1/20 | 1 | 20 |  |
| 154 | `swf_9_goto_in_construct_frame` | 5.0% | 1/20 | 1 | 20 |  |
| 155 | `xml_list_concat` | 5.0% | 1/20 | 1 | 20 |  |
| 156 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 157 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 158 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 159 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 160 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 161 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 162 | `button_nested_frame` | 4.2% | 2/48 | 3 | 48 |  |
| 163 | `bytearray_writeobject` | 4.2% | 1/24 | 1 | 24 |  |
| 164 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 165 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 166 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 167 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 168 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 169 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 170 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 171 | `qname_tostring` | 4.0% | 1/25 | 1 | 25 |  |
| 172 | `amf_custom_obj` | 3.8% | 1/26 | 1 | 26 |  |
| 173 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 174 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 175 | `sound_embeddedprops` | 3.8% | 1/26 | 1 | 26 |  |
| 176 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 177 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 178 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 179 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 180 | `dictionary_primitive_keys` | 3.4% | 1/29 | 1 | 29 |  |
| 181 | `qname_valueof` | 3.4% | 1/29 | 1 | 29 |  |
| 182 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 183 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 184 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 185 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 186 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 187 | `qname_constr` | 3.1% | 1/32 | 1 | 32 |  |
| 188 | `sound_valueof` | 3.0% | 1/33 | 1 | 33 |  |
| 189 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 190 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 191 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 192 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 193 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 194 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 195 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 196 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 197 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 198 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 199 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 200 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 201 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 202 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 203 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 204 | `dictionary_foreach` | 2.4% | 1/42 | 1 | 42 |  |
| 205 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 206 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 207 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 208 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 209 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 210 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 211 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 212 | `amf_function` | 2.2% | 1/46 | 1 | 46 |  |
| 213 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 214 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 215 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 216 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 217 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 218 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 219 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 220 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 221 | `orphan_movie_reorder` | 1.8% | 2/111 | 2 | 111 |  |
| 222 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 223 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 224 | `displayobjectcontainer_addchild_timelinepull1` | 1.7% | 1/60 | 1 | 60 |  |
| 225 | `flash_xml_removeNode` | 1.7% | 1/60 | 1 | 60 |  |
| 226 | `displacement_map_filter` | 1.6% | 1/61 | 1 | 61 |  |
| 227 | `dictionary_access` | 1.6% | 1/62 | 1 | 62 |  |
| 228 | `dictionary_in` | 1.6% | 1/62 | 1 | 62 |  |
| 229 | `displayobjectcontainer_addchild_timelinepull2` | 1.6% | 1/62 | 1 | 62 |  |
| 230 | `dictionary_hasownproperty` | 1.6% | 1/63 | 1 | 63 |  |
| 231 | `edittext_newline_stripping` | 1.6% | 1/64 | 1 | 64 |  |
| 232 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 233 | `displayobjectcontainer_contains` | 1.5% | 1/66 | 1 | 66 |  |
| 234 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 235 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 236 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 237 | `geom_transform` | 1.4% | 1/74 | 1 | 74 |  |
| 238 | `simplebutton_childevents` | 1.2% | 1/86 | 1 | 86 |  |
| 239 | `simplebutton_childevents_script_order` | 1.1% | 1/87 | 3 | 87 |  |
| 240 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 241 | `dictionary_delete` | 1.0% | 1/101 | 1 | 101 |  |
| 242 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 243 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 244 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 245 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 246 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 247 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 248 | `bounds_mode` | 0.7% | 2/269 | 2 | 269 |  |
| 249 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 250 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 251 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 252 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 253 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 254 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 255 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 256 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 257 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 258 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 259 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 260 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 261 | `soundchannel_soundtransform` | 0.1% | 1/835 | 1 | 835 |  |
| 262 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 263 | `soundmixer_soundtransform` | 0.1% | 1/900 | 1 | 900 |  |
| 264 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 265 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 266 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 267 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 268 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 269 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 270 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 271 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 272 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 273 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 274 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 275 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 276 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 277 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 278 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 279 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 280 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 281 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 282 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 283 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 284 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 285 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 286 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 287 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 288 | `all_classes/events/swf10` | 0.0% | 0/1638 | 0 | 1638 |  |
| 289 | `all_classes/events/swf11` | 0.0% | 0/1750 | 0 | 1750 |  |
| 290 | `all_classes/events/swf12` | 0.0% | 0/1814 | 0 | 1814 |  |
| 291 | `all_classes/events/swf30` | 0.0% | 0/2353 | 0 | 2353 |  |
| 292 | `all_classes/events/swf9` | 0.0% | 0/1030 | 0 | 1030 |  |
| 293 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 294 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 295 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 296 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 297 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 298 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 299 | `amf_invalid_date` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `amf_missing_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 301 | `amf_nondynamic_function_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 302 | `amf_setter_error` | 0.0% | 0/8 | 0 | 8 |  |
| 303 | `amf_vector` | 0.0% | 0/40 | 0 | 40 |  |
| 304 | `amf_xml` | 0.0% | 0/6 | 0 | 6 |  |
| 305 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 306 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 307 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 308 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 310 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 311 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 312 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 313 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 314 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 316 | `bitmapdata_copypixels` | 0.0% | 0/23 | 0 | 23 |  |
| 317 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 318 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 319 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 320 | `bitmapdata_draw_alpha_erase` | 0.0% | 0/8 | 0 | 8 |  |
| 321 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 322 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 323 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 324 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 325 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 326 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 327 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 328 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 329 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 330 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 331 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 332 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 333 | `bom` | 0.0% | 0/9 | 0 | 9 |  |
| 334 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 335 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 336 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `bytearray` | 0.0% | 0/48 | 0 | 48 |  |
| 338 | `bytearray_compress` | 0.0% | 0/31 | 0 | 31 |  |
| 339 | `bytearray_errors` | 0.0% | 0/24 | 0 | 24 |  |
| 340 | `bytearray_method_serialization` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `bytearray_oom` | 0.0% | 0/3 | 2 | 3 |  |
| 342 | `bytearray_readobject_amf0` | 0.0% | 0/50 | 0 | 50 |  |
| 343 | `bytearray_readobject_amf3` | 0.0% | 0/53 | 0 | 53 |  |
| 344 | `bytearray_readutf8bytes_with_bom` | 0.0% | 0/16 | 0 | 16 |  |
| 345 | `bytearray_serialization` | 0.0% | 0/3 | 0 | 3 |  |
| 346 | `bytearray_string_null` | 0.0% | 0/19 | 0 | 19 |  |
| 347 | `bytearray_tostring` | 0.0% | 0/15 | 0 | 15 |  |
| 348 | `bytearray_utf16` | 0.0% | 0/8 | 0 | 8 |  |
| 349 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 350 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 351 | `coerce_to_primitive_side_effects` | 0.0% | 0/29 | 0 | 29 |  |
| 352 | `coerce_to_primitive_side_effects_with_nulls` | 0.0% | 0/37 | 0 | 37 |  |
| 353 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 354 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 355 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 356 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 357 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 358 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 359 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 360 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 361 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 362 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 363 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 364 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 365 | `describe_type_basic` | 0.0% | 0/152 | 0 | 152 |  |
| 366 | `describe_type_json` | 0.0% | 0/301 | 0 | 301 |  |
| 367 | `describe_type_metadata` | 0.0% | 0/125 | 0 | 125 |  |
| 368 | `describe_type_native` | 0.0% | 0/23 | 0 | 23 |  |
| 369 | `dictionary_namespaces` | 0.0% | 0/36 | 0 | 36 |  |
| 370 | `dictionary_weak_keys` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 372 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 373 | `displayobject_hittestpoint_boundary` | 0.0% | 0/65 | 0 | 65 |  |
| 374 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 375 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 376 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 377 | `displayobject_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 378 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 379 | `displayobject_opaque_background` | 0.0% | 0/6 | 0 | 6 |  |
| 380 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 381 | `displayobject_scrollrect` | 0.0% | 0/33 | 0 | 33 |  |
| 382 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 383 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 384 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 385 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 386 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 387 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 388 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 389 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 390 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 391 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 392 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 393 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 394 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 395 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 396 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 397 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 398 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 399 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 400 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 401 | `edittext_getcharboundaries_missing_embedded_font` | 0.0% | 0/7 | 0 | 7 |  |
| 402 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 403 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 404 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 405 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 406 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 407 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 408 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 409 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 410 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 411 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 412 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 413 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 414 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 415 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 416 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 417 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 418 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 419 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 420 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 421 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 422 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 423 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 424 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 425 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 426 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 427 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 428 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 429 | `edittext_tab_stops` | 0.0% | 0/60 | 0 | 60 |  |
| 430 | `edittext_tag_indent` | 0.0% | 0/49 | 0 | 49 |  |
| 431 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 432 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 433 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 434 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 435 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 436 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 437 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 438 | `error_1034_debug_string` | 0.0% | 0/30 | 6 | 30 |  |
| 439 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 440 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 441 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 442 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 443 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 444 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 445 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 446 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 447 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 448 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 449 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 450 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 451 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 452 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 453 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 454 | `flash_xml` | 0.0% | 0/29 | 0 | 29 |  |
| 455 | `flash_xml_cloneNode` | 0.0% | 0/22 | 0 | 22 |  |
| 456 | `flash_xml_namespace` | 0.0% | 0/109 | 0 | 109 |  |
| 457 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 458 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 459 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 460 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 461 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 462 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 463 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 464 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 465 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 466 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 467 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 468 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 469 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 470 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 471 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 472 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 473 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 474 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 475 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 476 | `goto_button_nested_framescript` | 0.0% | 0/28 | 1 | 28 |  |
| 477 | `goto_framescript_queued` | 0.0% | 0/6 | 0 | 6 |  |
| 478 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 479 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 480 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 481 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 482 | `graphics_draw_path` | 0.0% | 0/34 | 0 | 34 |  |
| 483 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 484 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 485 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 486 | `indexing_delete` | 0.0% | 0/75 | 0 | 75 |  |
| 487 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 488 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 489 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 490 | `invalid_utf8` | 0.0% | 0/12 | 0 | 12 |  |
| 491 | `issue_13780` | 0.0% | 0/12 | 0 | 12 |  |
| 492 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 493 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 494 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 495 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 496 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 497 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 498 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 499 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 500 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 501 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 502 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 503 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 504 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 505 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 506 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 507 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 508 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 509 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 510 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 511 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 512 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 513 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 514 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 515 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 516 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 517 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 518 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 519 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 520 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 521 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 522 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 523 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 524 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 525 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 526 | `mask_reapply` | 0.0% | 0/1 | 0 | 1 |  |
| 527 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 528 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 529 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 530 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 531 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 532 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 533 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 534 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 535 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 536 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 537 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 538 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 539 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 540 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 541 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 542 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 543 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 544 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 545 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 546 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 1 | 676 |  |
| 547 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 1 | 2001 |  |
| 548 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 1 | 575 |  |
| 549 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 1 | 562 |  |
| 550 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 1 | 140 |  |
| 551 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 1 | 50 |  |
| 552 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 1 | 144 |  |
| 553 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 554 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 1 | 149 |  |
| 555 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 1 | 48 |  |
| 556 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 1 | 149 |  |
| 557 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 1 | 106 |  |
| 558 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 1 | 44 |  |
| 559 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 1 | 135 |  |
| 560 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 561 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 562 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 563 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 564 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 1 | 9 |  |
| 565 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 1 | 7 |  |
| 566 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 567 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 568 | `namespace_constr_args` | 0.0% | 0/1 | 0 | 1 |  |
| 569 | `namespace_enumeration_order` | 0.0% | 0/7 | 0 | 7 |  |
| 570 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 571 | `net_getClassByAlias` | 0.0% | 0/3 | 2 | 3 |  |
| 572 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 573 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 574 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 575 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 576 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 577 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 578 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 579 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 580 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 581 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 582 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 583 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 584 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 585 | `null_void_types` | 0.0% | 0/8 | 0 | 8 |  |
| 586 | `number_autoconv_amf` | 0.0% | 0/132 | 0 | 132 |  |
| 587 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 588 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 589 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 590 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 591 | `pixelbender_ceil` | 0.0% | 0/77 | 0 | 77 |  |
| 592 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 593 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 594 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 595 | `pixelbender_eof` | 0.0% | 0/7 | 0 | 7 |  |
| 596 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 597 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 598 | `pixelbender_no_out_param` | 0.0% | 0/6 | 0 | 6 |  |
| 599 | `pixelbender_outputs` | 0.0% | 0/13 | 0 | 13 |  |
| 600 | `pixelbender_padding_bytes` | 0.0% | 0/22 | 0 | 22 |  |
| 601 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 0 | 512 |  |
| 602 | `pixelbender_parse_errors` | 0.0% | 0/6 | 0 | 6 |  |
| 603 | `pixelbender_select_kinds` | 0.0% | 0/8 | 0 | 8 |  |
| 604 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 605 | `pixelbender_sign` | 0.0% | 0/60 | 0 | 60 |  |
| 606 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 607 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 608 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 609 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 610 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 611 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 612 | `proxy_callproperty` | 0.0% | 0/24 | 0 | 24 |  |
| 613 | `proxy_deleteproperty` | 0.0% | 0/64 | 0 | 64 |  |
| 614 | `proxy_enumeration` | 0.0% | 0/34 | 0 | 34 |  |
| 615 | `proxy_getproperty` | 0.0% | 0/77 | 0 | 77 |  |
| 616 | `proxy_hasownproperty` | 0.0% | 0/8 | 0 | 8 |  |
| 617 | `proxy_hasproperty` | 0.0% | 0/32 | 0 | 32 |  |
| 618 | `proxy_serialize` | 0.0% | 0/9 | 0 | 9 |  |
| 619 | `proxy_setproperty` | 0.0% | 0/42 | 0 | 42 |  |
| 620 | `qname_as_lazy_name_attribute_multiname` | 0.0% | 0/1 | 0 | 1 |  |
| 621 | `qname_indexing` | 0.0% | 0/23 | 0 | 23 |  |
| 622 | `remove_child_clear_field` | 0.0% | 0/88 | 1 | 88 |  |
| 623 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 624 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 625 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 626 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 627 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 628 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 629 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 630 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 631 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 632 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 633 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 634 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 2 | 45 |  |
| 635 | `simplebutton_childevents_multichild` | 0.0% | 0/152 | 1 | 152 |  |
| 636 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 637 | `simplebutton_childevents_sprite` | 0.0% | 0/13 | 1 | 13 |  |
| 638 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 639 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 640 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 641 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 642 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 643 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 644 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 645 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 646 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 647 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 648 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 649 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 650 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 651 | `sound_rootless` | 0.0% | 0/7 | 0 | 7 |  |
| 652 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 653 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 654 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 655 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 656 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 657 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 658 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 659 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 660 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 661 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 662 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 663 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 664 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 665 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 666 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 667 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 668 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 669 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 670 | `stage_scale_factor` | 0.0% | 0/12 | 0 | 12 |  |
| 671 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 672 | `static_length` | 0.0% | 0/24 | 4 | 24 |  |
| 673 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 674 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 675 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 676 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 677 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 678 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 1 | 6 |  |
| 679 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 680 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 681 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 682 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 683 | `symbol_class_conflict` | 0.0% | 0/4 | 0 | 4 |  |
| 684 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 685 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 686 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 687 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 688 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 689 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 690 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 691 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 692 | `tab_ordering_stage_tab_children_remove_root` | 0.0% | 0/5 | 0 | 5 |  |
| 693 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 694 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 695 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 696 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 697 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 698 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 699 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 700 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 701 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 702 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 703 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 704 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 705 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 706 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 707 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 708 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 709 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 710 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 711 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 712 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 713 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 714 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 715 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 716 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 717 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 718 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 719 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 720 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 721 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 722 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 723 | `xml_abstract_equality` | 0.0% | 0/36 | 0 | 36 |  |
| 724 | `xml_advanced` | 0.0% | 0/52 | 13 | 52 |  |
| 725 | `xml_appendchild` | 0.0% | 0/10 | 1 | 10 |  |
| 726 | `xml_appendchild_swf_v21` | 0.0% | 0/13 | 0 | 13 |  |
| 727 | `xml_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 728 | `xml_attribute` | 0.0% | 0/35 | 0 | 35 |  |
| 729 | `xml_attribute_name` | 0.0% | 0/40 | 0 | 40 |  |
| 730 | `xml_basic` | 0.0% | 0/32 | 0 | 32 |  |
| 731 | `xml_child` | 0.0% | 0/25 | 0 | 25 |  |
| 732 | `xml_childindex` | 0.0% | 0/7 | 0 | 7 |  |
| 733 | `xml_children` | 0.0% | 0/43 | 0 | 43 |  |
| 734 | `xml_class_call` | 0.0% | 0/9 | 0 | 9 |  |
| 735 | `xml_copy` | 0.0% | 0/20 | 0 | 20 |  |
| 736 | `xml_ctor_from_tostring` | 0.0% | 0/23 | 0 | 23 |  |
| 737 | `xml_delete` | 0.0% | 0/114 | 0 | 114 |  |
| 738 | `xml_elements` | 0.0% | 0/6 | 0 | 6 |  |
| 739 | `xml_ignore_white` | 0.0% | 0/6 | 2 | 6 |  |
| 740 | `xml_length` | 0.0% | 0/2 | 0 | 2 |  |
| 741 | `xml_list_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 742 | `xml_list_enumerate` | 0.0% | 0/4 | 2 | 4 |  |
| 743 | `xml_methods_settings` | 0.0% | 0/3 | 0 | 3 |  |
| 744 | `xml_namespace` | 0.0% | 0/39 | 0 | 39 |  |
| 745 | `xml_namespace_methods` | 0.0% | 0/245 | 0 | 245 |  |
| 746 | `xml_namespaced_property` | 0.0% | 0/7 | 0 | 7 |  |
| 747 | `xml_no_namespace` | 0.0% | 0/1 | 0 | 1 |  |
| 748 | `xml_nodekind` | 0.0% | 0/3 | 0 | 3 |  |
| 749 | `xml_normalize` | 0.0% | 0/35 | 0 | 35 |  |
| 750 | `xml_notification_bubbling` | 0.0% | 0/361 | 0 | 361 |  |
| 751 | `xml_parent` | 0.0% | 0/8 | 0 | 8 |  |
| 752 | `xml_set_children` | 0.0% | 0/17 | 0 | 17 |  |
| 753 | `xml_set_name` | 0.0% | 0/34 | 0 | 34 |  |
| 754 | `xml_settings` | 0.0% | 0/6 | 0 | 6 |  |
| 755 | `xml_simple_complex_content` | 0.0% | 0/47 | 0 | 47 |  |
| 756 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
| 757 | `xml_text` | 0.0% | 0/7 | 0 | 7 |  |
| 758 | `xml_tostring` | 0.0% | 0/6 | 6 | 6 |  |
| 759 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 760 | `xml_weird_ignores` | 0.0% | 0/56 | 56 | 54 |  |
| 761 | `xml_wildcard` | 0.0% | 0/11 | 0 | 11 |  |
| 762 | `xmldocument` | 0.0% | 0/254 | 0 | 254 |  |
| 763 | `xmlnode` | 0.0% | 0/3540 | 0 | 3540 |  |
| 764 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
