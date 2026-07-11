# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 13:16 UTC

**Git SHA**: `7e3a3a0148`

**Run Duration**: 79m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1199 |
| Passing | **353** (29.4%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **364** (30.4%) |
| Failing | 835 |
| Total expected lines | 148891 |
| Matching lines | 43788 (29.4%) |
| Mismatched lines | 105103 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 763 | 91.4% |
| Runtime Error | 72 | 8.6% |

## Passing Tests

**353 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.2s |  |
| 2 | `air_hidden_lookup` | 2 | 0.7s |  |
| 3 | `application_domain` | 4 | 1.5s |  |
| 4 | `array_access` | 18 | 1.5s |  |
| 5 | `array_access_interpreter` | 4 | 1.5s |  |
| 6 | `array_access_no_pubns` | 2 | 1.4s |  |
| 7 | `array_concat` | 41 | 1.5s |  |
| 8 | `array_constr` | 10 | 1.5s |  |
| 9 | `array_delete` | 44 | 1.6s |  |
| 10 | `array_enumeration` | 10 | 1.5s |  |
| 11 | `array_enumeration_elements` | 11 | 1.5s |  |
| 12 | `array_every` | 8 | 1.5s |  |
| 13 | `array_filter` | 6 | 1.5s |  |
| 14 | `array_foreach` | 18 | 1.5s |  |
| 15 | `array_hasownproperty` | 11 | 1.5s |  |
| 16 | `array_holes` | 9 | 1.5s |  |
| 17 | `array_index_max` | 84 | 1.2s |  |
| 18 | `array_indexof` | 25 | 1.5s |  |
| 19 | `array_join` | 26 | 1.5s |  |
| 20 | `array_lastindexof` | 29 | 1.5s |  |
| 21 | `array_length` | 14 | 1.5s |  |
| 22 | `array_literal` | 3 | 1.5s |  |
| 23 | `array_map` | 8 | 0.4s |  |
| 24 | `array_pop` | 52 | 1.6s |  |
| 25 | `array_push` | 24 | 1.5s |  |
| 26 | `array_reborrow_bug` | 6 | 1.5s |  |
| 27 | `array_reverse` | 28 | 1.5s |  |
| 28 | `array_shift` | 51 | 1.6s |  |
| 29 | `array_slice` | 39 | 1.5s |  |
| 30 | `array_some` | 8 | 1.5s |  |
| 31 | `array_sort` | 297 | 1.8s |  |
| 32 | `array_sort_fun_swf12` | 2 | 1.5s |  |
| 33 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 34 | `array_sort_random` | 210 | 1.5s |  |
| 35 | `array_sort_swf10_32bit` | 1 | 6.3s |  |
| 36 | `array_sorton` | 545 | 2.0s |  |
| 37 | `array_sparse_ops` | 41 | 1.6s |  |
| 38 | `array_splice` | 133 | 1.7s |  |
| 39 | `array_splice2` | 428 | 1.9s |  |
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
| 50 | `away3d_advanced_shallow_water_demo` | 0 | 64.3s |  |
| 51 | `bitand` | 1058 | 3.9s |  |
| 52 | `bitmapdata_applyfilter_blur` | 0 | 21.4s |  |
| 53 | `bitmapdata_applyfilter_colormatrix` | 0 | 1.8s |  |
| 54 | `bitmapdata_applyfilter_destpoint` | 0 | 20.8s |  |
| 55 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 21.1s |  |
| 56 | `bitmapdata_colortransform` | 0 | 1.8s |  |
| 57 | `bitmapdata_draw` | 0 | 17.2s |  |
| 58 | `bitmapdata_draw_colortransform` | 0 | 1.3s |  |
| 59 | `bitmapdata_draw_filters` | 0 | 17.3s |  |
| 60 | `bitmapdata_draw_masks` | 0 | 1.9s |  |
| 61 | `bitmapdata_draw_rotation` | 0 | 1.2s |  |
| 62 | `bitmapdata_draw_self_via_graphic` | 0 | 1.4s |  |
| 63 | `bitmapdata_draw_stage` | 0 | 17.7s |  |
| 64 | `bitmapdata_drawwithquality` | 0 | 1.6s |  |
| 65 | `bitmapdata_fillrect` | 0 | 1.4s |  |
| 66 | `bitmapdata_filter_sourcerect` | 0 | 18.0s |  |
| 67 | `bitmapdata_opaque` | 0 | 1.3s |  |
| 68 | `bitmapdata_pixeldissolve_image` | 0 | 1.3s |  |
| 69 | `bitmapdata_sync` | 0 | 1.4s |  |
| 70 | `bitnot` | 46 | 1.2s |  |
| 71 | `bitor` | 1058 | 3.0s |  |
| 72 | `bitxor` | 1058 | 3.0s |  |
| 73 | `blend_multiply_alpha` | 0 | 1.3s |  |
| 74 | `blend_scroll` | 0 | 6.5s |  |
| 75 | `boolean_constr` | 32 | 1.6s |  |
| 76 | `boolean_negation` | 30 | 1.6s |  |
| 77 | `boolean_tostring` | 8 | 1.6s |  |
| 78 | `callee_in_initializer` | 6 | 1.5s |  |
| 79 | `callproplex_class` | 1 | 1.6s |  |
| 80 | `catch_class` | 6 | 1.6s |  |
| 81 | `catch_scope_slot` | 7 | 1.7s |  |
| 82 | `class_cast_call` | 14 | 1.6s |  |
| 83 | `class_enumeration` | 4 | 1.6s |  |
| 84 | `class_has_own_property` | 2 | 1.6s |  |
| 85 | `class_init_interpreter_mode` | 1 | 1.5s |  |
| 86 | `class_is` | 32 | 1.6s |  |
| 87 | `class_methods` | 5 | 1.6s |  |
| 88 | `class_object_properties` | 10 | 6.3s |  |
| 89 | `class_singleton` | 18 | 1.6s |  |
| 90 | `class_supercalls_errors` | 35 | 1.7s |  |
| 91 | `class_supercalls_mismatched` | 26 | 1.6s |  |
| 92 | `class_superclass_wrong_order` | 1 | 1.5s |  |
| 93 | `class_to_locale_string` | 2 | 1.5s |  |
| 94 | `class_to_string` | 2 | 1.4s |  |
| 95 | `class_value_of` | 2 | 1.5s |  |
| 96 | `closures` | 12 | 1.5s |  |
| 97 | `coerce_property` | 33 | 1.6s |  |
| 98 | `coerce_return_type` | 40 | 1.6s |  |
| 99 | `coerce_return_type_fail` | 2 | 1.4s |  |
| 100 | `coerce_return_void` | 3 | 1.4s |  |
| 101 | `coerce_string` | 86 | 1.6s |  |
| 102 | `coerce_string_precision` | 28 | 1.5s |  |
| 103 | `construct_errors_swf10` | 8 | 1.5s |  |
| 104 | `constructor_call` | 3 | 1.5s |  |
| 105 | `constructprop_dynamic_primitive` | 7 | 1.6s |  |
| 106 | `control_flow_bool` | 4 | 1.5s |  |
| 107 | `control_flow_stricteq` | 8 | 1.5s |  |
| 108 | `convert_boolean` | 30 | 1.5s |  |
| 109 | `convert_integer` | 90 | 1.6s |  |
| 110 | `convert_number` | 56 | 1.6s |  |
| 111 | `convert_uinteger` | 90 | 1.6s |  |
| 112 | `declocal` | 46 | 1.6s |  |
| 113 | `declocal_i` | 46 | 1.6s |  |
| 114 | `decrement` | 46 | 1.6s |  |
| 115 | `decrement_i` | 46 | 1.6s |  |
| 116 | `default_values` | 7 | 1.6s |  |
| 117 | `displayobject_blendmode` | 0 | 19.9s |  |
| 118 | `displayobject_colortransform_nested` | 0 | 20.1s |  |
| 119 | `displayobject_getbounds_shape` | 0 | 19.9s |  |
| 120 | `displayobject_mask_self_referential` | 0 | 1.5s |  |
| 121 | `displayobject_set_matrix_nested` | 0 | 19.9s |  |
| 122 | `divide` | 1058 | 3.0s |  |
| 123 | `duplicate_defs` | 1 | 0.3s |  |
| 124 | `eager_init` | 1 | 1.2s |  |
| 125 | `equals` | 512 | 2.4s |  |
| 126 | `error_prototype` | 15 | 1.5s |  |
| 127 | `error_stack_trace_debug_swf17` | 0 | 19.4s |  |
| 128 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 129 | `error_stack_trace_release_swf17` | 0 | 0.3s |  |
| 130 | `error_stack_trace_release_swf18` | 0 | 0.2s |  |
| 131 | `es3_inheritance` | 31 | 1.5s |  |
| 132 | `es4_inheritance` | 30 | 1.6s |  |
| 133 | `es4_interfaces` | 30 | 1.6s |  |
| 134 | `es4_method_binding` | 8 | 1.5s |  |
| 135 | `es4_oop_prototypes` | 14 | 1.6s |  |
| 136 | `es4_protected_inheritance` | 6 | 1.5s |  |
| 137 | `event_bubbles` | 2 | 1.5s |  |
| 138 | `event_cancelable` | 2 | 1.4s |  |
| 139 | `event_type` | 1 | 1.5s |  |
| 140 | `eventdispatcher_dispatchevent_this` | 5 | 1.5s |  |
| 141 | `eventdispatcher_haseventlistener` | 25 | 1.5s |  |
| 142 | `falsiness` | 30 | 1.5s |  |
| 143 | `finddef` | 3 | 1.5s |  |
| 144 | `findprop_global_prototype` | 6 | 1.5s |  |
| 145 | `function_call` | 12 | 1.7s |  |
| 146 | `function_call_arguments` | 46 | 1.7s |  |
| 147 | `function_call_arguments_enumerate` | 5 | 1.6s |  |
| 148 | `function_call_coercion` | 108 | 1.8s |  |
| 149 | `function_call_default` | 6 | 1.6s |  |
| 150 | `function_call_rest` | 22 | 1.6s |  |
| 151 | `function_call_types` | 3 | 1.6s |  |
| 152 | `function_call_via_apply` | 11 | 1.6s |  |
| 153 | `function_call_via_call` | 3 | 1.6s |  |
| 154 | `function_display_anonymous` | 7 | 1.6s |  |
| 155 | `function_length` | 6 | 1.6s |  |
| 156 | `function_object` | 2 | 1.6s |  |
| 157 | `function_proto` | 5 | 1.6s |  |
| 158 | `function_to_locale_string` | 4 | 1.6s |  |
| 159 | `function_to_string` | 4 | 1.5s |  |
| 160 | `function_type` | 6 | 1.6s |  |
| 161 | `function_unbound_this` | 51 | 1.7s |  |
| 162 | `function_value_of` | 4 | 1.6s |  |
| 163 | `get_slot_edge_cases` | 1 | 1.5s |  |
| 164 | `getglobalslot` | 1 | 1.5s |  |
| 165 | `getouterscope` | 8 | 1.5s |  |
| 166 | `getter_different_namespace_setter` | 2 | 1.6s |  |
| 167 | `graphics_bitmaps` | 0 | 1.9s |  |
| 168 | `graphics_direct_commands` | 0 | 1.8s |  |
| 169 | `graphics_gradients` | 0 | 1.7s |  |
| 170 | `graphics_gradients_nulls` | 0 | 1.6s |  |
| 171 | `graphics_round_rects` | 0 | 1.6s |  |
| 172 | `graphics_simple_shapes` | 0 | 1.6s |  |
| 173 | `greaterequals` | 512 | 6.0s |  |
| 174 | `greaterthan` | 512 | 1.9s |  |
| 175 | `has_own_property` | 102 | 1.4s |  |
| 176 | `hasownproperty_namespaces` | 2 | 1.1s |  |
| 177 | `hello_world` | 1 | 1.1s |  |
| 178 | `if_eq` | 10 | 1.2s |  |
| 179 | `if_gt` | 1 | 1.2s |  |
| 180 | `if_gte` | 10 | 1.1s |  |
| 181 | `if_lt` | 1 | 0.3s |  |
| 182 | `if_lte` | 10 | 0.3s |  |
| 183 | `if_ne` | 7 | 1.1s |  |
| 184 | `if_stricteq` | 6 | 1.1s |  |
| 185 | `if_strictne` | 11 | 1.2s |  |
| 186 | `in` | 102 | 1.4s |  |
| 187 | `inclocal` | 46 | 1.2s |  |
| 188 | `inclocal_i` | 46 | 1.2s |  |
| 189 | `increment` | 46 | 1.1s |  |
| 190 | `increment_i` | 46 | 1.1s |  |
| 191 | `instanceof` | 58 | 1.3s |  |
| 192 | `int_constr` | 92 | 1.3s |  |
| 193 | `int_edge_cases` | 19 | 1.2s |  |
| 194 | `int_instanceof` | 3 | 1.1s |  |
| 195 | `int_tofixed` | 1215 | 1.1s |  |
| 196 | `int_tostring` | 3375 | 1.3s |  |
| 197 | `interface_namespaces` | 78 | 1.3s |  |
| 198 | `is_finite` | 46 | 1.2s |  |
| 199 | `is_nan` | 46 | 1.1s |  |
| 200 | `is_prototype_of` | 12 | 1.2s |  |
| 201 | `issue_10221` | 2 | 1.1s |  |
| 202 | `issue_14901` | 1 | 1.5s |  |
| 203 | `istype` | 24 | 1.5s |  |
| 204 | `istypelate` | 58 | 1.7s |  |
| 205 | `istypelate_coerce` | 198 | 1.9s |  |
| 206 | `json_errors` | 9 | 19.6s |  |
| 207 | `json_parse` | 21 | 1.5s |  |
| 208 | `json_version_gated` | 1 | 1.4s |  |
| 209 | `lazyinit` | 17 | 1.6s |  |
| 210 | `lessequals` | 512 | 2.4s |  |
| 211 | `lessthan` | 512 | 2.4s |  |
| 212 | `lshift` | 1058 | 3.6s |  |
| 213 | `math` | 497 | 1.7s |  |
| 214 | `modulo` | 1058 | 3.6s |  |
| 215 | `movieclip_stop` | 1 | 19.8s |  |
| 216 | `multiply` | 1058 | 3.9s |  |
| 217 | `negate` | 30 | 1.5s |  |
| 218 | `newactivation_in_script_init` | 3 | 1.2s |  |
| 219 | `newclass_twice` | 3 | 1.2s |  |
| 220 | `nonconflicting_declarations` | 0 | 1.3s |  |
| 221 | `number_autoconv_array_sort_32bit` | 1 | 1.2s |  |
| 222 | `number_constr` | 58 | 1.3s |  |
| 223 | `number_toexponential` | 378 | 1.3s |  |
| 224 | `number_toexponential2` | 35 | 1.2s |  |
| 225 | `number_tofixed` | 378 | 1.2s |  |
| 226 | `number_toprecision` | 350 | 1.3s |  |
| 227 | `obfuscated_class_names` | 3 | 1.3s |  |
| 228 | `object_enumeration` | 10 | 1.2s |  |
| 229 | `object_prototype` | 4 | 1.3s |  |
| 230 | `object_to_locale_string` | 2 | 1.6s |  |
| 231 | `object_to_string` | 2 | 1.4s |  |
| 232 | `object_value_of` | 2 | 1.2s |  |
| 233 | `op_coerce` | 54 | 0.8s |  |
| 234 | `op_coerce_x` | 54 | 1.3s |  |
| 235 | `op_escxattr` | 2 | 1.3s |  |
| 236 | `op_escxelem` | 2 | 1.4s |  |
| 237 | `op_lookupswitch` | 4 | 1.4s |  |
| 238 | `optimize_coerce` | 1 | 1.2s |  |
| 239 | `param_default_value_has_zero_cpool_index` | 1 | 1.6s |  |
| 240 | `parse_float` | 80 | 1.8s |  |
| 241 | `pixelbender_effect_BlurredFocus` | 0 | 23.7s |  |
| 242 | `pixelbender_effect_glassDisplace` | 0 | 6.4s |  |
| 243 | `pixelbender_effect_smudge` | 0 | 4.1s |  |
| 244 | `pixelbender_effect_tintype` | 0 | 3.3s |  |
| 245 | `pixelbender_effect_twirl` | 0 | 4.5s |  |
| 246 | `pixelbender_images` | 0 | 3.2s |  |
| 247 | `primitive_edge_cases` | 1 | 1.1s |  |
| 248 | `property_priority` | 22 | 1.4s |  |
| 249 | `property_priority_three_level` | 6 | 1.2s |  |
| 250 | `propertyisenumerable_namespaces` | 6 | 1.3s |  |
| 251 | `prototype_set_null` | 7 | 1.1s |  |
| 252 | `regexp_constr` | 148 | 1.4s |  |
| 253 | `regexp_exec` | 19 | 1.2s |  |
| 254 | `regexp_extended` | 47 | 1.1s |  |
| 255 | `regexp_multiargs` | 1 | 1.1s |  |
| 256 | `regexp_test` | 27 | 6.5s |  |
| 257 | `regexp_toString` | 10 | 1.6s |  |
| 258 | `resolve_order` | 4 | 1.6s |  |
| 259 | `rng` | 1 | 2.9s |  |
| 260 | `rshift` | 1058 | 4.0s |  |
| 261 | `set_property_is_enumerable` | 85 | 1.9s |  |
| 262 | `slot_disp_id_shared_numbering` | 1 | 24.9s |  |
| 263 | `slots_force_autoassigned` | 1 | 1.6s |  |
| 264 | `sprite_with_frames` | 0 | 20.6s |  |
| 265 | `stage3d_agal_cross_product` | 0 | 2.9s |  |
| 266 | `stage3d_bitmap` | 0 | 23.4s |  |
| 267 | `stage3d_float1_index` | 0 | 21.7s |  |
| 268 | `stage3d_fractal` | 0 | 8.1s |  |
| 269 | `stage3d_ignore_sampler_override` | 0 | 21.1s |  |
| 270 | `stage3d_program_constants_bytearray_be` | 0 | 21.3s |  |
| 271 | `stage3d_program_constants_bytearray_le` | 0 | 3.2s |  |
| 272 | `stage3d_raytrace` | 0 | 20.2s |  |
| 273 | `stage3d_stencil` | 0 | 21.3s |  |
| 274 | `stage3d_texture` | 0 | 6.9s |  |
| 275 | `stage3d_texture_bytearray` | 0 | 3.8s |  |
| 276 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.3s |  |
| 277 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 3.9s |  |
| 278 | `stage3d_triangle` | 0 | 2.8s |  |
| 279 | `stage3d_triangle_bytes4` | 0 | 2.9s |  |
| 280 | `stage3d_triangle_float1` | 0 | 2.9s |  |
| 281 | `stage3d_triangle_index_upload` | 0 | 2.9s |  |
| 282 | `static_var_with_this_in_ctor` | 2 | 1.5s |  |
| 283 | `stored_properties` | 11 | 6.6s |  |
| 284 | `strict_equality` | 34 | 1.7s |  |
| 285 | `string_call` | 13 | 1.7s |  |
| 286 | `string_case` | 23 | 1.7s |  |
| 287 | `string_char_at` | 27 | 1.7s |  |
| 288 | `string_char_code_at` | 28 | 1.6s |  |
| 289 | `string_concat_fromcharcode` | 36 | 1.7s |  |
| 290 | `string_constr` | 25 | 1.7s |  |
| 291 | `string_indexof_lastindexof` | 87 | 1.8s |  |
| 292 | `string_length` | 16 | 1.7s |  |
| 293 | `string_locale_compare` | 39 | 1.8s |  |
| 294 | `string_match` | 51 | 1.8s |  |
| 295 | `string_relational_compare` | 4 | 1.7s |  |
| 296 | `string_replace` | 51 | 1.8s |  |
| 297 | `string_search` | 41 | 1.7s |  |
| 298 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 299 | `string_split` | 29 | 1.8s |  |
| 300 | `string_substr_negative` | 21 | 1.6s |  |
| 301 | `string_substr_weird` | 182 | 1.7s |  |
| 302 | `subtract` | 1058 | 4.3s |  |
| 303 | `super_get_call` | 12 | 1.7s |  |
| 304 | `supercall_two_classobjects` | 2 | 1.7s |  |
| 305 | `swf8` | 1 | 1.4s |  |
| 306 | `symbol_class_root_not_zero` | 1 | 1.6s |  |
| 307 | `symbolclass_invalid_utf8` | 2 | 1.6s |  |
| 308 | `throw` | 3 | 1.6s |  |
| 309 | `truthiness` | 30 | 1.6s |  |
| 310 | `try_catch` | 11 | 1.8s |  |
| 311 | `try_catch_typed` | 12 | 1.7s |  |
| 312 | `typeof` | 30 | 1.7s |  |
| 313 | `uint_constr` | 92 | 1.7s |  |
| 314 | `uint_tofixed` | 1215 | 1.5s |  |
| 315 | `uint_tostring` | 3375 | 1.8s |  |
| 316 | `unchecked_function` | 15 | 1.6s |  |
| 317 | `urshift` | 1058 | 3.9s |  |
| 318 | `vector_class` | 36 | 2.0s |  |
| 319 | `vector_class_call` | 11 | 1.8s |  |
| 320 | `vector_coercion` | 66 | 2.2s |  |
| 321 | `vector_concat` | 90 | 1.9s |  |
| 322 | `vector_constr` | 107 | 1.8s |  |
| 323 | `vector_enumeration` | 5 | 1.6s |  |
| 324 | `vector_every` | 92 | 2.0s |  |
| 325 | `vector_filter` | 95 | 2.0s |  |
| 326 | `vector_holes` | 24 | 1.7s |  |
| 327 | `vector_indexof` | 302 | 2.5s |  |
| 328 | `vector_insertat` | 270 | 2.0s |  |
| 329 | `vector_int_access` | 4 | 1.6s |  |
| 330 | `vector_int_delete` | 11 | 1.6s |  |
| 331 | `vector_join` | 58 | 1.9s |  |
| 332 | `vector_lastindexof` | 302 | 1.6s |  |
| 333 | `vector_legacy` | 10 | 1.6s |  |
| 334 | `vector_map` | 85 | 1.9s |  |
| 335 | `vector_object_final` | 1 | 8.2s |  |
| 336 | `vector_object_toString` | 10 | 0.7s |  |
| 337 | `vector_pushpop` | 255 | 1.3s |  |
| 338 | `vector_reborrow_bug` | 10 | 0.7s |  |
| 339 | `vector_removeat` | 172 | 1.1s |  |
| 340 | `vector_reverse` | 232 | 1.1s |  |
| 341 | `vector_shiftunshift` | 252 | 0.6s |  |
| 342 | `vector_slice` | 331 | 1.2s |  |
| 343 | `vector_sort` | 905 | 2.6s |  |
| 344 | `vector_splice` | 693 | 1.6s |  |
| 345 | `vector_splice_fixed_bug_compat` | 4 | 0.7s |  |
| 346 | `vector_tostring` | 79 | 0.9s |  |
| 347 | `verify_abnormal_loop` | 1 | 0.7s |  |
| 348 | `verify_exception_targets_edge_case` | 1 | 0.7s |  |
| 349 | `verify_lookup_switch_edge_case` | 1 | 0.6s |  |
| 350 | `verify_unreachable_exception` | 2 | 0.6s |  |
| 351 | `versioned_isplaying` | 2 | 0.7s |  |
| 352 | `virtual_properties` | 16 | 0.8s |  |
| 353 | `with` | 4 | 0.7s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 2 | `blend_transform` | 1 | 1 | 1.6s |  |
| 3 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.5s |  |
| 4 | `freestanding_superclass` | 3 | 4 | 1.6s |  |
| 5 | `int_toexponential` | 76 | 76 | 1.3s |  |
| 6 | `int_toprecision` | 441 | 441 | 1.3s |  |
| 7 | `slot_holes_fail` | 1 | 1 | 1.5s |  |
| 8 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.5s |  |
| 9 | `uint_toexponential` | 100 | 100 | 1.7s |  |
| 10 | `uint_toprecision` | 433 | 433 | 1.7s |  |
| 11 | `weird_superinterface_properties` | 1 | 1 | 0.7s |  |

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

**72 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `applicationdomain_getqualifieddefinitionnames` | exit code 1 | 1.4s |  |
| 2 | `array_access_oob_interpreter` | exit code 1 | 1.4s |  |
| 3 | `bitmap_subclass` | exit code 1 | 2.8s |  |
| 4 | `bitmap_subclass_properties` | exit code 1 | 1.9s |  |
| 5 | `bitmapdata_constructor_from_timeline` | exit code 1 | 1.4s |  |
| 6 | `bitmapdata_copychannel` | exit code 1 (output matches) | 19.2s |  |
| 7 | `bitmapdata_draw_cpu_overwrite_gpu` | exit code 1 (output matches) | 17.6s |  |
| 8 | `checkfilter` | exit code 1 | 1.6s |  |
| 9 | `content_element_basic` | exit code 1 | 1.7s |  |
| 10 | `core_exceptions` | exit code 1 | 2.2s |  |
| 11 | `dictionary_access_no_pubns` | exit code 1 | 1.5s |  |
| 12 | `doabc_is_eager` | exit code 1 | 15.3s |  |
| 13 | `domain_memory` | exit code 1 | 1.2s |  |
| 14 | `edittext_always_show_selection` | exit code 1 (output matches) | 16.0s |  |
| 15 | `edittext_at_point_methods_basic` | exit code 1 | 2.1s |  |
| 16 | `edittext_autosize_align` | exit code 1 (output matches) | 15.8s |  |
| 17 | `edittext_autosize_height_dynamic` | exit code 1 | 15.8s |  |
| 18 | `edittext_autosize_height_input` | exit code 1 | 1.3s |  |
| 19 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 2.2s |  |
| 20 | `edittext_autosize_lazy_bounds_visual` | exit code 1 (output matches) | 15.7s |  |
| 21 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 1.4s |  |
| 22 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.3s |  |
| 23 | `edittext_device_transform_layout` | exit code 1 | 1.4s |  |
| 24 | `edittext_empty_text_format` | exit code 1 | 1.3s |  |
| 25 | `edittext_get_char_index_at_point` | exit code 1 | 21.0s |  |
| 26 | `edittext_get_line_index_at_point` | exit code 1 | 21.0s |  |
| 27 | `edittext_get_line_index_of_char` | exit code 1 | 2.8s |  |
| 28 | `edittext_getcharboundaries` | exit code 1 | 2.0s |  |
| 29 | `edittext_getcharboundaries_culling` | exit code 1 | 1.8s |  |
| 30 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.7s |  |
| 31 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.7s |  |
| 32 | `edittext_line_methods` | exit code 1 | 2.6s |  |
| 33 | `edittext_line_metrics` | exit code 1 | 22.1s |  |
| 34 | `edittext_max_scroll_h_basic` | exit code 1 | 1.7s |  |
| 35 | `edittext_max_scroll_v_basic` | exit code 1 | 1.7s |  |
| 36 | `edittext_mouse_selection` | exit code 1 | 21.7s |  |
| 37 | `edittext_wordwrap_word` | exit code 1 | 1.8s |  |
| 38 | `edittext_wrap_breaks` | exit code 1 | 1.9s |  |
| 39 | `error_stack_trace` | exit code 1 | 1.5s |  |
| 40 | `font_enumeratefonts_filter` | exit code 1 | 2.2s |  |
| 41 | `font_enumeratefonts_order` | exit code 1 | 2.4s |  |
| 42 | `graphics_bitmap_fill` | exit code 1 (output matches) | 3.0s |  |
| 43 | `large_preload_from_bytes` | exit code 1 | 1.6s |  |
| 44 | `large_preload_image_from_bytes` | exit code 1 | 1.7s |  |
| 45 | `method_without_body` | exit code 1 | 19.3s |  |
| 46 | `mouse_wheel_events` | exit code 1 | 20.6s |  |
| 47 | `namespace_constr` | exit code 1 | 1.7s |  |
| 48 | `negative_volume_panned` | exit code 1 (output matches) | 1.7s |  |
| 49 | `pixelbender_conversions` | exit code 1 | 2.1s |  |
| 50 | `pixelbender_div` | exit code 1 | 1.9s |  |
| 51 | `pixelbender_input` | exit code 1 | 20.9s |  |
| 52 | `pixelbender_malformed_data` | exit code 1 | 20.6s |  |
| 53 | `pixelbender_parameters` | exit code 1 | 2.0s |  |
| 54 | `pixelbender_parameters_bool` | exit code 1 | 1.9s |  |
| 55 | `pixelbender_parameters_int_vs_bool` | exit code 1 | 1.7s |  |
| 56 | `pixelbender_rsqrt` | exit code 1 | 1.7s |  |
| 57 | `pixelbender_shaderdata_setter` | exit code 1 | 2.5s |  |
| 58 | `pixelbender_vector_output` | exit code 1 | 5.9s |  |
| 59 | `property_priority_scope_cache_order` | exit code 1 | 16.7s |  |
| 60 | `rtqname_not_namespace` | exit code 1 | 1.6s |  |
| 61 | `sound_load_multiple` | exit code 1 | 2.5s |  |
| 62 | `stage3d_blend` | exit code 1 | 21.8s |  |
| 63 | `stage3d_rotating_cube` | exit code 1 (output matches) | 3.3s |  |
| 64 | `stage3d_sampler` | exit code 1 (output matches) | 2.9s |  |
| 65 | `stage3d_sampler_partial_upload` | exit code 1 (output matches) | 2.8s |  |
| 66 | `supercalls_weird` | exit code 1 | 1.6s |  |
| 67 | `symbol_class_binary_data` | exit code 1 | 1.7s |  |
| 68 | `textline_splitting_basic` | exit code 1 | 1.9s |  |
| 69 | `verify_typecheck` | exit code 1 | 0.7s |  |
| 70 | `xml_descendants` | exit code 1 | 1.6s |  |
| 71 | `xml_explicit_use_namespace` | exit code 1 | 1.6s |  |
| 72 | `xml_getdescendants_qname` | exit code 1 | 1.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**763 tests** with output mismatch, sorted by match rate (best first)

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
| 148 | `goto_nested_construct_sibling` | 5.6% | 1/18 | 6 | 18 |  |
| 149 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 150 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 151 | `sound_play` | 5.3% | 1/19 | 1 | 19 |  |
| 152 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 153 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 154 | `get_qualified_class_name` | 5.0% | 1/20 | 1 | 20 |  |
| 155 | `swf_9_goto_in_construct_frame` | 5.0% | 1/20 | 1 | 20 |  |
| 156 | `xml_list_concat` | 5.0% | 1/20 | 1 | 20 |  |
| 157 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 158 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 159 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 160 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 161 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 162 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 163 | `button_nested_frame` | 4.2% | 2/48 | 3 | 48 |  |
| 164 | `bytearray_writeobject` | 4.2% | 1/24 | 1 | 24 |  |
| 165 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 166 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 167 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 168 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 169 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 170 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 171 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 172 | `qname_tostring` | 4.0% | 1/25 | 1 | 25 |  |
| 173 | `amf_custom_obj` | 3.8% | 1/26 | 1 | 26 |  |
| 174 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 175 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 176 | `sound_embeddedprops` | 3.8% | 1/26 | 1 | 26 |  |
| 177 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 178 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 179 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 180 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 181 | `dictionary_primitive_keys` | 3.4% | 1/29 | 1 | 29 |  |
| 182 | `qname_valueof` | 3.4% | 1/29 | 1 | 29 |  |
| 183 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 184 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 185 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 186 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 187 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 188 | `qname_constr` | 3.1% | 1/32 | 1 | 32 |  |
| 189 | `sound_valueof` | 3.0% | 1/33 | 1 | 33 |  |
| 190 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 191 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 192 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 193 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
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
| 315 | `bitmapdata_copypixels` | 0.0% | 0/23 | 0 | 23 |  |
| 316 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 317 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 318 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 319 | `bitmapdata_draw_alpha_erase` | 0.0% | 0/8 | 0 | 8 |  |
| 320 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 321 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 322 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 323 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 324 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 325 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 326 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 327 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 328 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 329 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 330 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 331 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 332 | `bom` | 0.0% | 0/9 | 0 | 9 |  |
| 333 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 334 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 336 | `bytearray` | 0.0% | 0/48 | 0 | 48 |  |
| 337 | `bytearray_compress` | 0.0% | 0/31 | 0 | 31 |  |
| 338 | `bytearray_errors` | 0.0% | 0/24 | 0 | 24 |  |
| 339 | `bytearray_method_serialization` | 0.0% | 0/1 | 0 | 1 |  |
| 340 | `bytearray_oom` | 0.0% | 0/3 | 2 | 3 |  |
| 341 | `bytearray_readobject_amf0` | 0.0% | 0/50 | 0 | 50 |  |
| 342 | `bytearray_readobject_amf3` | 0.0% | 0/53 | 0 | 53 |  |
| 343 | `bytearray_readutf8bytes_with_bom` | 0.0% | 0/16 | 0 | 16 |  |
| 344 | `bytearray_serialization` | 0.0% | 0/3 | 0 | 3 |  |
| 345 | `bytearray_string_null` | 0.0% | 0/19 | 0 | 19 |  |
| 346 | `bytearray_tostring` | 0.0% | 0/15 | 0 | 15 |  |
| 347 | `bytearray_utf16` | 0.0% | 0/8 | 0 | 8 |  |
| 348 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 349 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 350 | `coerce_to_primitive_side_effects` | 0.0% | 0/29 | 0 | 29 |  |
| 351 | `coerce_to_primitive_side_effects_with_nulls` | 0.0% | 0/37 | 0 | 37 |  |
| 352 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 353 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 354 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 355 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 356 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 357 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 358 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 359 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 360 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 361 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 362 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 363 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 364 | `describe_type_basic` | 0.0% | 0/152 | 0 | 152 |  |
| 365 | `describe_type_json` | 0.0% | 0/301 | 0 | 301 |  |
| 366 | `describe_type_metadata` | 0.0% | 0/125 | 0 | 125 |  |
| 367 | `describe_type_native` | 0.0% | 0/23 | 0 | 23 |  |
| 368 | `dictionary_namespaces` | 0.0% | 0/36 | 0 | 36 |  |
| 369 | `dictionary_weak_keys` | 0.0% | 0/2 | 0 | 2 |  |
| 370 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 371 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 372 | `displayobject_hittestpoint_boundary` | 0.0% | 0/65 | 0 | 65 |  |
| 373 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 374 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 375 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 376 | `displayobject_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 377 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 378 | `displayobject_opaque_background` | 0.0% | 0/6 | 0 | 6 |  |
| 379 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 380 | `displayobject_scrollrect` | 0.0% | 0/33 | 0 | 33 |  |
| 381 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 382 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 383 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 384 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 385 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 386 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 387 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 388 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 389 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 390 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 391 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 392 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 393 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 394 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 395 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 396 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 397 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 398 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 399 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 400 | `edittext_getcharboundaries_missing_embedded_font` | 0.0% | 0/7 | 0 | 7 |  |
| 401 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 402 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 403 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 404 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 405 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 406 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 407 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 408 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 409 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 410 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 411 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 412 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 413 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 414 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 415 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 416 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 417 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 418 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 419 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 420 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 421 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 422 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 423 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 424 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 425 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 426 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 427 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 428 | `edittext_tab_stops` | 0.0% | 0/60 | 0 | 60 |  |
| 429 | `edittext_tag_indent` | 0.0% | 0/49 | 0 | 49 |  |
| 430 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 431 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 432 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 433 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 434 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 435 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 436 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 437 | `error_1034_debug_string` | 0.0% | 0/30 | 6 | 30 |  |
| 438 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 439 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 440 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 441 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 442 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 443 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 444 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 445 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 446 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 447 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 448 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 449 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 450 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 451 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 452 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 453 | `flash_xml` | 0.0% | 0/29 | 0 | 29 |  |
| 454 | `flash_xml_cloneNode` | 0.0% | 0/22 | 0 | 22 |  |
| 455 | `flash_xml_namespace` | 0.0% | 0/109 | 0 | 109 |  |
| 456 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 457 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 458 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 459 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 460 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 461 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 462 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 463 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 464 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 465 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 466 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 467 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 468 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 469 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 470 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 471 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 472 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 473 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 474 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 475 | `goto_button_nested_framescript` | 0.0% | 0/28 | 1 | 28 |  |
| 476 | `goto_framescript_queued` | 0.0% | 0/6 | 0 | 6 |  |
| 477 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 478 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 479 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 480 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 481 | `graphics_draw_path` | 0.0% | 0/34 | 0 | 34 |  |
| 482 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 483 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 484 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 485 | `indexing_delete` | 0.0% | 0/75 | 0 | 75 |  |
| 486 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 487 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 488 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 489 | `invalid_utf8` | 0.0% | 0/12 | 0 | 12 |  |
| 490 | `issue_13780` | 0.0% | 0/12 | 0 | 12 |  |
| 491 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 492 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 493 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 494 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 495 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 496 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 497 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 498 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 499 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 500 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 501 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 502 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 503 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 504 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 505 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 506 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 507 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 508 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 509 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 510 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 511 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 512 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 513 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 514 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 515 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 516 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 517 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 518 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 519 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 520 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 521 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 522 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 523 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 524 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 525 | `mask_reapply` | 0.0% | 0/1 | 0 | 1 |  |
| 526 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 527 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 528 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 529 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 530 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 531 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 532 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 533 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 534 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 535 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 536 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 537 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 538 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 539 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 540 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 541 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 542 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 543 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 544 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 545 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 1 | 676 |  |
| 546 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 1 | 2001 |  |
| 547 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 1 | 575 |  |
| 548 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 1 | 562 |  |
| 549 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 1 | 140 |  |
| 550 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 1 | 50 |  |
| 551 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 1 | 144 |  |
| 552 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 553 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 1 | 149 |  |
| 554 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 1 | 48 |  |
| 555 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 1 | 149 |  |
| 556 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 1 | 106 |  |
| 557 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 1 | 44 |  |
| 558 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 1 | 135 |  |
| 559 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 560 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 561 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 562 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 563 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 1 | 9 |  |
| 564 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 1 | 7 |  |
| 565 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 566 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 567 | `namespace_constr_args` | 0.0% | 0/1 | 0 | 1 |  |
| 568 | `namespace_enumeration_order` | 0.0% | 0/7 | 0 | 7 |  |
| 569 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 570 | `net_getClassByAlias` | 0.0% | 0/3 | 2 | 3 |  |
| 571 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 572 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 573 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 574 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 575 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 576 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 577 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 578 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 579 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 580 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 581 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 582 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 583 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 584 | `null_void_types` | 0.0% | 0/8 | 0 | 8 |  |
| 585 | `number_autoconv_amf` | 0.0% | 0/132 | 0 | 132 |  |
| 586 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 587 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 588 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 589 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 590 | `pixelbender_ceil` | 0.0% | 0/77 | 0 | 77 |  |
| 591 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 592 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 593 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 594 | `pixelbender_eof` | 0.0% | 0/7 | 0 | 7 |  |
| 595 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 596 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 597 | `pixelbender_no_out_param` | 0.0% | 0/6 | 0 | 6 |  |
| 598 | `pixelbender_outputs` | 0.0% | 0/13 | 0 | 13 |  |
| 599 | `pixelbender_padding_bytes` | 0.0% | 0/22 | 0 | 22 |  |
| 600 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 0 | 512 |  |
| 601 | `pixelbender_parse_errors` | 0.0% | 0/6 | 0 | 6 |  |
| 602 | `pixelbender_select_kinds` | 0.0% | 0/8 | 0 | 8 |  |
| 603 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 604 | `pixelbender_sign` | 0.0% | 0/60 | 0 | 60 |  |
| 605 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 606 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 607 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 608 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 609 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 610 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 611 | `proxy_callproperty` | 0.0% | 0/24 | 0 | 24 |  |
| 612 | `proxy_deleteproperty` | 0.0% | 0/64 | 0 | 64 |  |
| 613 | `proxy_enumeration` | 0.0% | 0/34 | 0 | 34 |  |
| 614 | `proxy_getproperty` | 0.0% | 0/77 | 0 | 77 |  |
| 615 | `proxy_hasownproperty` | 0.0% | 0/8 | 0 | 8 |  |
| 616 | `proxy_hasproperty` | 0.0% | 0/32 | 0 | 32 |  |
| 617 | `proxy_serialize` | 0.0% | 0/9 | 0 | 9 |  |
| 618 | `proxy_setproperty` | 0.0% | 0/42 | 0 | 42 |  |
| 619 | `qname_as_lazy_name_attribute_multiname` | 0.0% | 0/1 | 0 | 1 |  |
| 620 | `qname_indexing` | 0.0% | 0/23 | 0 | 23 |  |
| 621 | `remove_child_clear_field` | 0.0% | 0/88 | 1 | 88 |  |
| 622 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 623 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 624 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 625 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 626 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 627 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 628 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 629 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 630 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 631 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 632 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 633 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 2 | 45 |  |
| 634 | `simplebutton_childevents_multichild` | 0.0% | 0/152 | 1 | 152 |  |
| 635 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 636 | `simplebutton_childevents_sprite` | 0.0% | 0/13 | 1 | 13 |  |
| 637 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 638 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 639 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 640 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 641 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 642 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 643 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 644 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 645 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 646 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 647 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 648 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 649 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 650 | `sound_rootless` | 0.0% | 0/7 | 0 | 7 |  |
| 651 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 652 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 653 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 654 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 655 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 656 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 657 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 658 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 659 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 660 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 661 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 662 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 663 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 664 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 665 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 666 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 667 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 668 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 669 | `stage_scale_factor` | 0.0% | 0/12 | 0 | 12 |  |
| 670 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 671 | `static_length` | 0.0% | 0/24 | 4 | 24 |  |
| 672 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 673 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 674 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 675 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 676 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 677 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 1 | 6 |  |
| 678 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 679 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 680 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 681 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 682 | `symbol_class_conflict` | 0.0% | 0/4 | 0 | 4 |  |
| 683 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 684 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 685 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 686 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 687 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 688 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 689 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 690 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 691 | `tab_ordering_stage_tab_children_remove_root` | 0.0% | 0/5 | 0 | 5 |  |
| 692 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 693 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 694 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 695 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 696 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 697 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 698 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 699 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 700 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 701 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 702 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 703 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 704 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 705 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 706 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 707 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 708 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 709 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 710 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 711 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 712 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 713 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 714 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 715 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 716 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 717 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 718 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 719 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 720 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 721 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 722 | `xml_abstract_equality` | 0.0% | 0/36 | 0 | 36 |  |
| 723 | `xml_advanced` | 0.0% | 0/52 | 13 | 52 |  |
| 724 | `xml_appendchild` | 0.0% | 0/10 | 1 | 10 |  |
| 725 | `xml_appendchild_swf_v21` | 0.0% | 0/13 | 0 | 13 |  |
| 726 | `xml_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 727 | `xml_attribute` | 0.0% | 0/35 | 0 | 35 |  |
| 728 | `xml_attribute_name` | 0.0% | 0/40 | 0 | 40 |  |
| 729 | `xml_basic` | 0.0% | 0/32 | 0 | 32 |  |
| 730 | `xml_child` | 0.0% | 0/25 | 0 | 25 |  |
| 731 | `xml_childindex` | 0.0% | 0/7 | 0 | 7 |  |
| 732 | `xml_children` | 0.0% | 0/43 | 0 | 43 |  |
| 733 | `xml_class_call` | 0.0% | 0/9 | 0 | 9 |  |
| 734 | `xml_copy` | 0.0% | 0/20 | 0 | 20 |  |
| 735 | `xml_ctor_from_tostring` | 0.0% | 0/23 | 0 | 23 |  |
| 736 | `xml_delete` | 0.0% | 0/114 | 0 | 114 |  |
| 737 | `xml_elements` | 0.0% | 0/6 | 0 | 6 |  |
| 738 | `xml_ignore_white` | 0.0% | 0/6 | 2 | 6 |  |
| 739 | `xml_length` | 0.0% | 0/2 | 0 | 2 |  |
| 740 | `xml_list_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 741 | `xml_list_enumerate` | 0.0% | 0/4 | 2 | 4 |  |
| 742 | `xml_methods_settings` | 0.0% | 0/3 | 0 | 3 |  |
| 743 | `xml_namespace` | 0.0% | 0/39 | 0 | 39 |  |
| 744 | `xml_namespace_methods` | 0.0% | 0/245 | 0 | 245 |  |
| 745 | `xml_namespaced_property` | 0.0% | 0/7 | 0 | 7 |  |
| 746 | `xml_no_namespace` | 0.0% | 0/1 | 0 | 1 |  |
| 747 | `xml_nodekind` | 0.0% | 0/3 | 0 | 3 |  |
| 748 | `xml_normalize` | 0.0% | 0/35 | 0 | 35 |  |
| 749 | `xml_notification_bubbling` | 0.0% | 0/361 | 0 | 361 |  |
| 750 | `xml_parent` | 0.0% | 0/8 | 0 | 8 |  |
| 751 | `xml_set_children` | 0.0% | 0/17 | 0 | 17 |  |
| 752 | `xml_set_name` | 0.0% | 0/34 | 0 | 34 |  |
| 753 | `xml_settings` | 0.0% | 0/6 | 0 | 6 |  |
| 754 | `xml_simple_complex_content` | 0.0% | 0/47 | 0 | 47 |  |
| 755 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
| 756 | `xml_text` | 0.0% | 0/7 | 0 | 7 |  |
| 757 | `xml_tostring` | 0.0% | 0/6 | 6 | 6 |  |
| 758 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 759 | `xml_weird_ignores` | 0.0% | 0/56 | 56 | 54 |  |
| 760 | `xml_wildcard` | 0.0% | 0/11 | 0 | 11 |  |
| 761 | `xmldocument` | 0.0% | 0/254 | 0 | 254 |  |
| 762 | `xmlnode` | 0.0% | 0/3540 | 0 | 3540 |  |
| 763 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
