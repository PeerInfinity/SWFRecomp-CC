# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 15:53 UTC

**Git SHA**: `241a84401c`

**Run Duration**: 83m 43s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1200 |
| Passing | **411** (34.2%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **423** (35.2%) |
| Failing | 777 |
| Total expected lines | 148991 |
| Matching lines | 45664 (30.6%) |
| Mismatched lines | 103327 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 714 | 91.9% |
| Runtime Error | 62 | 8.0% |
| Timeout | 1 | 0.1% |

## Passing Tests

**411 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.8s |  |
| 2 | `air_hidden_lookup` | 2 | 0.7s |  |
| 3 | `amf_custom_obj` | 26 | 0.8s |  |
| 4 | `amf_dictionary` | 9 | 0.7s |  |
| 5 | `amf_function` | 46 | 0.7s |  |
| 6 | `amf_invalid_date` | 2 | 0.7s |  |
| 7 | `amf_missing_prop` | 6 | 0.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 6.6s |  |
| 9 | `amf_setter_error` | 8 | 1.5s |  |
| 10 | `amf_vector` | 40 | 1.4s |  |
| 11 | `application_domain` | 4 | 1.9s |  |
| 12 | `array_access` | 18 | 1.8s |  |
| 13 | `array_access_interpreter` | 4 | 1.4s |  |
| 14 | `array_access_no_pubns` | 2 | 1.5s |  |
| 15 | `array_concat` | 41 | 1.6s |  |
| 16 | `array_constr` | 10 | 1.5s |  |
| 17 | `array_delete` | 44 | 1.6s |  |
| 18 | `array_enumeration` | 10 | 1.5s |  |
| 19 | `array_enumeration_elements` | 11 | 1.5s |  |
| 20 | `array_every` | 8 | 1.4s |  |
| 21 | `array_filter` | 6 | 1.5s |  |
| 22 | `array_foreach` | 18 | 1.6s |  |
| 23 | `array_hasownproperty` | 11 | 1.4s |  |
| 24 | `array_holes` | 9 | 1.6s |  |
| 25 | `array_index_max` | 84 | 1.6s |  |
| 26 | `array_indexof` | 25 | 1.4s |  |
| 27 | `array_join` | 26 | 1.5s |  |
| 28 | `array_lastindexof` | 29 | 1.5s |  |
| 29 | `array_length` | 14 | 1.5s |  |
| 30 | `array_literal` | 3 | 1.7s |  |
| 31 | `array_map` | 8 | 0.3s |  |
| 32 | `array_pop` | 52 | 1.5s |  |
| 33 | `array_push` | 24 | 1.4s |  |
| 34 | `array_reborrow_bug` | 6 | 1.5s |  |
| 35 | `array_reverse` | 28 | 1.4s |  |
| 36 | `array_shift` | 51 | 1.9s |  |
| 37 | `array_slice` | 39 | 1.4s |  |
| 38 | `array_some` | 8 | 1.5s |  |
| 39 | `array_sort` | 297 | 1.9s |  |
| 40 | `array_sort_fun_swf12` | 2 | 1.6s |  |
| 41 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 42 | `array_sort_random` | 210 | 1.6s |  |
| 43 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 44 | `array_sorton` | 545 | 2.0s |  |
| 45 | `array_sparse_ops` | 41 | 1.7s |  |
| 46 | `array_splice` | 133 | 1.7s |  |
| 47 | `array_splice2` | 428 | 1.9s |  |
| 48 | `array_splice_types` | 48 | 1.7s |  |
| 49 | `array_storage` | 8 | 1.6s |  |
| 50 | `array_tolocalestring` | 9 | 1.6s |  |
| 51 | `array_tostring` | 12 | 1.6s |  |
| 52 | `array_unshift` | 24 | 1.6s |  |
| 53 | `array_valueof` | 9 | 1.5s |  |
| 54 | `array_vector_null_callback` | 10 | 1.6s |  |
| 55 | `astype` | 28 | 1.6s |  |
| 56 | `astypelate` | 24 | 1.7s |  |
| 57 | `astypelate_propagates` | 1 | 1.5s |  |
| 58 | `away3d_advanced_shallow_water_demo` | 0 | 62.4s |  |
| 59 | `bitand` | 1058 | 3.7s |  |
| 60 | `bitmapdata_applyfilter_blur` | 0 | 20.2s |  |
| 61 | `bitmapdata_applyfilter_colormatrix` | 0 | 1.9s |  |
| 62 | `bitmapdata_applyfilter_destpoint` | 0 | 20.4s |  |
| 63 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.2s |  |
| 64 | `bitmapdata_colortransform` | 0 | 1.8s |  |
| 65 | `bitmapdata_draw` | 0 | 20.5s |  |
| 66 | `bitmapdata_draw_colortransform` | 0 | 1.8s |  |
| 67 | `bitmapdata_draw_filters` | 0 | 20.5s |  |
| 68 | `bitmapdata_draw_masks` | 0 | 1.7s |  |
| 69 | `bitmapdata_draw_rotation` | 0 | 1.7s |  |
| 70 | `bitmapdata_draw_self_via_graphic` | 0 | 1.7s |  |
| 71 | `bitmapdata_draw_stage` | 0 | 20.3s |  |
| 72 | `bitmapdata_drawwithquality` | 0 | 2.0s |  |
| 73 | `bitmapdata_fillrect` | 0 | 1.7s |  |
| 74 | `bitmapdata_filter_sourcerect` | 0 | 20.3s |  |
| 75 | `bitmapdata_opaque` | 0 | 1.7s |  |
| 76 | `bitmapdata_pixeldissolve_image` | 0 | 1.9s |  |
| 77 | `bitmapdata_sync` | 0 | 1.9s |  |
| 78 | `bitnot` | 46 | 1.7s |  |
| 79 | `bitor` | 1058 | 3.9s |  |
| 80 | `bitxor` | 1058 | 3.9s |  |
| 81 | `blend_multiply_alpha` | 0 | 1.8s |  |
| 82 | `blend_scroll` | 0 | 6.3s |  |
| 83 | `boolean_constr` | 32 | 1.6s |  |
| 84 | `boolean_negation` | 30 | 1.6s |  |
| 85 | `boolean_tostring` | 8 | 1.6s |  |
| 86 | `bytearray` | 48 | 1.9s |  |
| 87 | `bytearray_compress` | 31 | 1.7s |  |
| 88 | `bytearray_errors` | 24 | 1.7s |  |
| 89 | `bytearray_method_serialization` | 1 | 1.6s |  |
| 90 | `bytearray_readobject_amf0` | 50 | 0.7s |  |
| 91 | `bytearray_readobject_amf3` | 53 | 1.6s |  |
| 92 | `bytearray_readutf8bytes_with_bom` | 16 | 1.6s |  |
| 93 | `bytearray_serialization` | 3 | 1.6s |  |
| 94 | `bytearray_string_null` | 19 | 1.9s |  |
| 95 | `bytearray_tostring` | 15 | 1.7s |  |
| 96 | `bytearray_utf16` | 8 | 1.6s |  |
| 97 | `bytearray_writeobject` | 24 | 0.6s |  |
| 98 | `callee_in_initializer` | 6 | 1.6s |  |
| 99 | `callproplex_class` | 1 | 1.6s |  |
| 100 | `catch_class` | 6 | 1.6s |  |
| 101 | `catch_scope_slot` | 7 | 1.7s |  |
| 102 | `class_call` | 32 | 1.7s |  |
| 103 | `class_cast_call` | 14 | 1.6s |  |
| 104 | `class_enumeration` | 4 | 1.6s |  |
| 105 | `class_has_own_property` | 2 | 1.6s |  |
| 106 | `class_init_interpreter_mode` | 1 | 1.5s |  |
| 107 | `class_is` | 32 | 1.7s |  |
| 108 | `class_methods` | 5 | 1.6s |  |
| 109 | `class_object_properties` | 10 | 6.4s |  |
| 110 | `class_singleton` | 18 | 1.7s |  |
| 111 | `class_supercalls_errors` | 35 | 1.9s |  |
| 112 | `class_supercalls_mismatched` | 26 | 1.8s |  |
| 113 | `class_superclass_wrong_order` | 1 | 1.6s |  |
| 114 | `class_to_locale_string` | 2 | 1.7s |  |
| 115 | `class_to_string` | 2 | 1.6s |  |
| 116 | `class_value_of` | 2 | 1.6s |  |
| 117 | `closures` | 12 | 1.7s |  |
| 118 | `coerce_property` | 33 | 1.7s |  |
| 119 | `coerce_return_type` | 40 | 1.7s |  |
| 120 | `coerce_return_type_fail` | 2 | 1.6s |  |
| 121 | `coerce_return_void` | 3 | 1.6s |  |
| 122 | `coerce_string` | 86 | 1.7s |  |
| 123 | `coerce_string_precision` | 28 | 1.6s |  |
| 124 | `coerce_to_primitive_side_effects` | 29 | 1.7s |  |
| 125 | `construct_errors_swf10` | 8 | 1.7s |  |
| 126 | `constructor_call` | 3 | 1.7s |  |
| 127 | `constructprop_dynamic_primitive` | 7 | 1.7s |  |
| 128 | `control_flow_bool` | 4 | 1.6s |  |
| 129 | `control_flow_stricteq` | 8 | 1.7s |  |
| 130 | `convert_boolean` | 30 | 1.7s |  |
| 131 | `convert_integer` | 90 | 1.7s |  |
| 132 | `convert_number` | 56 | 1.7s |  |
| 133 | `convert_uinteger` | 90 | 1.8s |  |
| 134 | `declocal` | 46 | 1.7s |  |
| 135 | `declocal_i` | 46 | 1.6s |  |
| 136 | `decrement` | 46 | 1.6s |  |
| 137 | `decrement_i` | 46 | 1.7s |  |
| 138 | `default_values` | 7 | 1.6s |  |
| 139 | `dictionary_access` | 62 | 1.8s |  |
| 140 | `dictionary_access_no_pubns` | 2 | 1.6s |  |
| 141 | `dictionary_delete` | 101 | 1.8s |  |
| 142 | `dictionary_foreach` | 42 | 1.7s |  |
| 143 | `dictionary_hasownproperty` | 63 | 1.8s |  |
| 144 | `dictionary_in` | 62 | 1.7s |  |
| 145 | `dictionary_iter_modify` | 8 | 1.6s |  |
| 146 | `dictionary_namespaces` | 36 | 1.7s |  |
| 147 | `dictionary_primitive_keys` | 29 | 1.6s |  |
| 148 | `displayobject_blendmode` | 0 | 19.7s |  |
| 149 | `displayobject_colortransform_nested` | 0 | 20.0s |  |
| 150 | `displayobject_getbounds_shape` | 0 | 19.8s |  |
| 151 | `displayobject_mask_self_referential` | 0 | 1.7s |  |
| 152 | `displayobject_set_matrix_nested` | 0 | 21.2s |  |
| 153 | `divide` | 1058 | 3.9s |  |
| 154 | `duplicate_defs` | 1 | 0.5s |  |
| 155 | `eager_init` | 1 | 1.7s |  |
| 156 | `equals` | 512 | 2.4s |  |
| 157 | `error_prototype` | 15 | 1.4s |  |
| 158 | `error_stack_trace_debug_swf17` | 0 | 19.7s |  |
| 159 | `error_stack_trace_debug_swf18` | 0 | 0.4s |  |
| 160 | `error_stack_trace_release_swf17` | 0 | 0.3s |  |
| 161 | `error_stack_trace_release_swf18` | 0 | 0.2s |  |
| 162 | `error_tostring` | 29 | 1.4s |  |
| 163 | `es3_inheritance` | 31 | 1.5s |  |
| 164 | `es4_inheritance` | 30 | 1.5s |  |
| 165 | `es4_interfaces` | 30 | 1.5s |  |
| 166 | `es4_method_binding` | 8 | 1.4s |  |
| 167 | `es4_oop_prototypes` | 14 | 1.6s |  |
| 168 | `es4_protected_inheritance` | 6 | 1.4s |  |
| 169 | `event_bubbles` | 2 | 1.4s |  |
| 170 | `event_cancelable` | 2 | 6.4s |  |
| 171 | `event_type` | 1 | 1.7s |  |
| 172 | `eventdispatcher_dispatchevent_this` | 5 | 1.6s |  |
| 173 | `eventdispatcher_haseventlistener` | 25 | 1.7s |  |
| 174 | `falsiness` | 30 | 1.8s |  |
| 175 | `fast_index_access` | 12 | 1.8s |  |
| 176 | `finddef` | 3 | 1.8s |  |
| 177 | `findprop_global_prototype` | 6 | 1.8s |  |
| 178 | `function_call` | 12 | 1.7s |  |
| 179 | `function_call_arguments` | 46 | 1.7s |  |
| 180 | `function_call_arguments_enumerate` | 5 | 1.6s |  |
| 181 | `function_call_coercion` | 108 | 1.8s |  |
| 182 | `function_call_default` | 6 | 1.6s |  |
| 183 | `function_call_rest` | 22 | 1.6s |  |
| 184 | `function_call_types` | 3 | 1.7s |  |
| 185 | `function_call_via_apply` | 11 | 1.7s |  |
| 186 | `function_call_via_call` | 3 | 1.7s |  |
| 187 | `function_display_anonymous` | 7 | 1.6s |  |
| 188 | `function_length` | 6 | 1.6s |  |
| 189 | `function_object` | 2 | 1.6s |  |
| 190 | `function_proto` | 5 | 6.2s |  |
| 191 | `function_to_locale_string` | 4 | 1.6s |  |
| 192 | `function_to_string` | 4 | 1.6s |  |
| 193 | `function_type` | 6 | 1.6s |  |
| 194 | `function_unbound_this` | 51 | 1.7s |  |
| 195 | `function_value_of` | 4 | 1.6s |  |
| 196 | `get_definition_by_name` | 11 | 1.7s |  |
| 197 | `get_qualified_class_name` | 20 | 1.7s |  |
| 198 | `get_slot_edge_cases` | 1 | 1.6s |  |
| 199 | `getglobalslot` | 1 | 1.6s |  |
| 200 | `getouterscope` | 8 | 1.7s |  |
| 201 | `getter_different_namespace_setter` | 2 | 1.7s |  |
| 202 | `graphics_bitmaps` | 0 | 1.9s |  |
| 203 | `graphics_direct_commands` | 0 | 1.8s |  |
| 204 | `graphics_gradients` | 0 | 1.8s |  |
| 205 | `graphics_gradients_nulls` | 0 | 1.7s |  |
| 206 | `graphics_round_rects` | 0 | 1.7s |  |
| 207 | `graphics_simple_shapes` | 0 | 6.4s |  |
| 208 | `greaterequals` | 512 | 2.8s |  |
| 209 | `greaterthan` | 512 | 2.7s |  |
| 210 | `has_own_property` | 102 | 1.9s |  |
| 211 | `hasownproperty_namespaces` | 2 | 1.6s |  |
| 212 | `hello_world` | 1 | 1.6s |  |
| 213 | `if_eq` | 10 | 1.7s |  |
| 214 | `if_gt` | 1 | 1.7s |  |
| 215 | `if_gte` | 10 | 1.7s |  |
| 216 | `if_lt` | 1 | 0.4s |  |
| 217 | `if_lte` | 10 | 0.4s |  |
| 218 | `if_ne` | 7 | 1.7s |  |
| 219 | `if_stricteq` | 6 | 1.7s |  |
| 220 | `if_strictne` | 11 | 1.7s |  |
| 221 | `in` | 102 | 1.9s |  |
| 222 | `inclocal` | 46 | 1.8s |  |
| 223 | `inclocal_i` | 46 | 1.7s |  |
| 224 | `increment` | 46 | 1.7s |  |
| 225 | `increment_i` | 46 | 1.7s |  |
| 226 | `instanceof` | 58 | 1.9s |  |
| 227 | `int_constr` | 92 | 1.8s |  |
| 228 | `int_edge_cases` | 19 | 1.7s |  |
| 229 | `int_instanceof` | 3 | 1.6s |  |
| 230 | `int_tofixed` | 1215 | 1.6s |  |
| 231 | `int_tostring` | 3375 | 1.9s |  |
| 232 | `interface_namespaces` | 78 | 1.8s |  |
| 233 | `is_finite` | 46 | 1.7s |  |
| 234 | `is_nan` | 46 | 1.6s |  |
| 235 | `is_prototype_of` | 12 | 1.7s |  |
| 236 | `issue_10221` | 2 | 6.4s |  |
| 237 | `issue_14901` | 1 | 1.7s |  |
| 238 | `istype` | 24 | 1.8s |  |
| 239 | `istypelate` | 58 | 1.8s |  |
| 240 | `istypelate_coerce` | 198 | 2.0s |  |
| 241 | `json_errors` | 9 | 19.7s |  |
| 242 | `json_parse` | 21 | 1.7s |  |
| 243 | `json_version_gated` | 1 | 1.6s |  |
| 244 | `lazyinit` | 17 | 1.7s |  |
| 245 | `lessequals` | 512 | 2.6s |  |
| 246 | `lessthan` | 512 | 2.5s |  |
| 247 | `lshift` | 1058 | 3.6s |  |
| 248 | `math` | 497 | 1.8s |  |
| 249 | `modulo` | 1058 | 3.8s |  |
| 250 | `movieclip_stop` | 1 | 20.0s |  |
| 251 | `multiply` | 1058 | 3.8s |  |
| 252 | `namespace_constr` | 253 | 2.0s |  |
| 253 | `namespace_constr_args` | 1 | 1.5s |  |
| 254 | `namespace_enumeration_order` | 7 | 1.6s |  |
| 255 | `negate` | 30 | 1.6s |  |
| 256 | `negative_volume_panned` | 0 | 1.7s |  |
| 257 | `nested_iteration` | 11 | 1.7s |  |
| 258 | `net_getClassByAlias` | 3 | 6.4s |  |
| 259 | `newactivation_in_script_init` | 3 | 1.6s |  |
| 260 | `newclass_twice` | 3 | 1.6s |  |
| 261 | `nonconflicting_declarations` | 0 | 1.7s |  |
| 262 | `number_autoconv_amf` | 132 | 1.7s |  |
| 263 | `number_autoconv_array_sort_32bit` | 1 | 1.6s |  |
| 264 | `number_constr` | 58 | 1.7s |  |
| 265 | `number_toexponential` | 378 | 1.7s |  |
| 266 | `number_toexponential2` | 35 | 1.6s |  |
| 267 | `number_tofixed` | 378 | 1.6s |  |
| 268 | `number_toprecision` | 350 | 1.7s |  |
| 269 | `obfuscated_class_names` | 3 | 1.6s |  |
| 270 | `object_enumeration` | 10 | 1.6s |  |
| 271 | `object_prototype` | 4 | 1.7s |  |
| 272 | `object_to_locale_string` | 2 | 1.6s |  |
| 273 | `object_to_string` | 2 | 1.6s |  |
| 274 | `object_value_of` | 2 | 1.5s |  |
| 275 | `op_coerce` | 54 | 1.1s |  |
| 276 | `op_coerce_x` | 54 | 1.7s |  |
| 277 | `op_escxattr` | 2 | 1.7s |  |
| 278 | `op_escxelem` | 2 | 1.6s |  |
| 279 | `op_lookupswitch` | 4 | 1.7s |  |
| 280 | `optimize_coerce` | 1 | 1.6s |  |
| 281 | `param_default_value_has_zero_cpool_index` | 1 | 1.5s |  |
| 282 | `parse_float` | 80 | 1.7s |  |
| 283 | `pixelbender_effect_BlurredFocus` | 0 | 22.3s |  |
| 284 | `pixelbender_effect_glassDisplace` | 0 | 6.0s |  |
| 285 | `pixelbender_effect_smudge` | 0 | 3.9s |  |
| 286 | `pixelbender_effect_tintype` | 0 | 3.2s |  |
| 287 | `pixelbender_effect_twirl` | 0 | 4.3s |  |
| 288 | `pixelbender_images` | 0 | 3.1s |  |
| 289 | `primitive_edge_cases` | 1 | 1.6s |  |
| 290 | `property_priority` | 22 | 2.0s |  |
| 291 | `property_priority_three_level` | 6 | 1.8s |  |
| 292 | `propertyisenumerable_namespaces` | 6 | 1.7s |  |
| 293 | `prototype_set_null` | 7 | 1.6s |  |
| 294 | `proxy_callproperty` | 24 | 1.7s |  |
| 295 | `proxy_deleteproperty` | 64 | 1.8s |  |
| 296 | `proxy_enumeration` | 34 | 1.7s |  |
| 297 | `proxy_getproperty` | 77 | 1.8s |  |
| 298 | `proxy_hasownproperty` | 8 | 1.7s |  |
| 299 | `proxy_hasproperty` | 32 | 1.8s |  |
| 300 | `proxy_serialize` | 9 | 1.7s |  |
| 301 | `proxy_setproperty` | 42 | 1.8s |  |
| 302 | `qname_constr` | 32 | 1.8s |  |
| 303 | `qname_constr_namespace` | 24 | 1.8s |  |
| 304 | `qname_enumeration` | 9 | 1.8s |  |
| 305 | `qname_indexing` | 23 | 1.9s |  |
| 306 | `qname_tostring` | 25 | 1.8s |  |
| 307 | `qname_valueof` | 29 | 1.8s |  |
| 308 | `regexp_constr` | 148 | 2.0s |  |
| 309 | `regexp_exec` | 19 | 1.8s |  |
| 310 | `regexp_extended` | 47 | 1.8s |  |
| 311 | `regexp_multiargs` | 1 | 6.2s |  |
| 312 | `regexp_test` | 27 | 1.7s |  |
| 313 | `regexp_toString` | 10 | 1.6s |  |
| 314 | `resolve_order` | 4 | 1.6s |  |
| 315 | `rng` | 1 | 3.0s |  |
| 316 | `rshift` | 1058 | 3.8s |  |
| 317 | `set_property_is_enumerable` | 85 | 1.8s |  |
| 318 | `slot_disp_id_shared_numbering` | 1 | 19.6s |  |
| 319 | `slots_force_autoassigned` | 1 | 1.6s |  |
| 320 | `sprite_with_frames` | 0 | 1.9s |  |
| 321 | `stage3d_agal_cross_product` | 0 | 2.9s |  |
| 322 | `stage3d_bitmap` | 0 | 22.5s |  |
| 323 | `stage3d_float1_index` | 0 | 25.8s |  |
| 324 | `stage3d_fractal` | 0 | 3.6s |  |
| 325 | `stage3d_ignore_sampler_override` | 0 | 21.1s |  |
| 326 | `stage3d_program_constants_bytearray_be` | 0 | 21.6s |  |
| 327 | `stage3d_program_constants_bytearray_le` | 0 | 3.3s |  |
| 328 | `stage3d_raytrace` | 0 | 20.4s |  |
| 329 | `stage3d_sampler` | 0 | 3.0s |  |
| 330 | `stage3d_sampler_partial_upload` | 0 | 2.9s |  |
| 331 | `stage3d_stencil` | 0 | 21.1s |  |
| 332 | `stage3d_texture` | 0 | 7.0s |  |
| 333 | `stage3d_texture_bytearray` | 0 | 4.0s |  |
| 334 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.4s |  |
| 335 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 4.1s |  |
| 336 | `stage3d_triangle` | 0 | 2.9s |  |
| 337 | `stage3d_triangle_bytes4` | 0 | 3.0s |  |
| 338 | `stage3d_triangle_float1` | 0 | 3.0s |  |
| 339 | `stage3d_triangle_index_upload` | 0 | 2.9s |  |
| 340 | `static_var_with_this_in_ctor` | 2 | 1.6s |  |
| 341 | `stored_properties` | 11 | 1.6s |  |
| 342 | `strict_equality` | 34 | 1.6s |  |
| 343 | `string_call` | 13 | 1.6s |  |
| 344 | `string_case` | 23 | 1.7s |  |
| 345 | `string_char_at` | 27 | 1.6s |  |
| 346 | `string_char_code_at` | 28 | 1.5s |  |
| 347 | `string_concat_fromcharcode` | 36 | 1.6s |  |
| 348 | `string_constr` | 25 | 1.6s |  |
| 349 | `string_indexof_lastindexof` | 87 | 1.7s |  |
| 350 | `string_length` | 16 | 1.6s |  |
| 351 | `string_locale_compare` | 39 | 1.7s |  |
| 352 | `string_match` | 51 | 1.7s |  |
| 353 | `string_relational_compare` | 4 | 1.6s |  |
| 354 | `string_replace` | 51 | 1.7s |  |
| 355 | `string_search` | 41 | 1.7s |  |
| 356 | `string_slice_substr_substring` | 169 | 1.9s |  |
| 357 | `string_split` | 29 | 1.6s |  |
| 358 | `string_substr_negative` | 21 | 1.5s |  |
| 359 | `string_substr_weird` | 182 | 1.6s |  |
| 360 | `subtract` | 1058 | 3.6s |  |
| 361 | `super_get_call` | 12 | 1.6s |  |
| 362 | `supercall_two_classobjects` | 2 | 1.6s |  |
| 363 | `swf8` | 1 | 1.3s |  |
| 364 | `symbol_class_root_not_zero` | 1 | 1.6s |  |
| 365 | `symbolclass_invalid_utf8` | 2 | 1.6s |  |
| 366 | `throw` | 3 | 1.6s |  |
| 367 | `truthiness` | 30 | 1.6s |  |
| 368 | `try_catch` | 11 | 1.7s |  |
| 369 | `try_catch_typed` | 12 | 1.7s |  |
| 370 | `typeof` | 30 | 1.6s |  |
| 371 | `uint_constr` | 92 | 1.7s |  |
| 372 | `uint_tofixed` | 1215 | 1.5s |  |
| 373 | `uint_tostring` | 3375 | 1.8s |  |
| 374 | `unchecked_function` | 15 | 1.6s |  |
| 375 | `urshift` | 1058 | 3.7s |  |
| 376 | `vector_class` | 36 | 1.9s |  |
| 377 | `vector_class_call` | 11 | 1.8s |  |
| 378 | `vector_coercion` | 66 | 2.2s |  |
| 379 | `vector_concat` | 90 | 1.9s |  |
| 380 | `vector_constr` | 107 | 1.8s |  |
| 381 | `vector_enumeration` | 5 | 1.6s |  |
| 382 | `vector_every` | 92 | 2.0s |  |
| 383 | `vector_filter` | 95 | 2.0s |  |
| 384 | `vector_holes` | 24 | 1.7s |  |
| 385 | `vector_indexof` | 302 | 2.5s |  |
| 386 | `vector_insertat` | 270 | 2.0s |  |
| 387 | `vector_int_access` | 4 | 1.6s |  |
| 388 | `vector_int_delete` | 11 | 1.6s |  |
| 389 | `vector_join` | 58 | 1.8s |  |
| 390 | `vector_lastindexof` | 302 | 1.5s |  |
| 391 | `vector_legacy` | 10 | 1.6s |  |
| 392 | `vector_map` | 85 | 7.4s |  |
| 393 | `vector_object_final` | 1 | 1.4s |  |
| 394 | `vector_object_toString` | 10 | 0.7s |  |
| 395 | `vector_pushpop` | 255 | 1.1s |  |
| 396 | `vector_reborrow_bug` | 10 | 0.6s |  |
| 397 | `vector_removeat` | 172 | 1.0s |  |
| 398 | `vector_reverse` | 232 | 1.0s |  |
| 399 | `vector_shiftunshift` | 252 | 0.6s |  |
| 400 | `vector_slice` | 331 | 1.2s |  |
| 401 | `vector_sort` | 905 | 2.5s |  |
| 402 | `vector_splice` | 693 | 1.5s |  |
| 403 | `vector_splice_fixed_bug_compat` | 4 | 0.7s |  |
| 404 | `vector_tostring` | 79 | 0.9s |  |
| 405 | `verify_abnormal_loop` | 1 | 0.6s |  |
| 406 | `verify_exception_targets_edge_case` | 1 | 0.6s |  |
| 407 | `verify_lookup_switch_edge_case` | 1 | 0.6s |  |
| 408 | `verify_unreachable_exception` | 2 | 0.6s |  |
| 409 | `versioned_isplaying` | 2 | 0.6s |  |
| 410 | `virtual_properties` | 16 | 0.7s |  |
| 411 | `with` | 4 | 0.7s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 2 | `blend_transform` | 1 | 1 | 1.7s |  |
| 3 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 1.7s |  |
| 4 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.4s |  |
| 5 | `freestanding_superclass` | 3 | 4 | 1.6s |  |
| 6 | `int_toexponential` | 76 | 76 | 1.8s |  |
| 7 | `int_toprecision` | 441 | 441 | 1.8s |  |
| 8 | `slot_holes_fail` | 1 | 1 | 1.5s |  |
| 9 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.6s |  |
| 10 | `uint_toexponential` | 100 | 100 | 1.7s |  |
| 11 | `uint_toprecision` | 433 | 433 | 1.7s |  |
| 12 | `weird_superinterface_properties` | 1 | 1 | 0.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**38 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271 | 1275 | 4 |  |
| 2 | `displayobject_alpha` | 99.6% | 276 | 277 | 1 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 6 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 7 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 8 | `xml_has_property_via_in` | 88.5% | 23 | 26 | 3 |  |
| 9 | `interactiveobject_enabled` | 88.0% | 22 | 25 | 3 |  |
| 10 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 11 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 12 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 13 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 14 | `event_valueof_tostring` | 77.8% | 14 | 18 | 4 |  |
| 15 | `eventdispatcher_dispatchevent` | 75.0% | 9 | 12 | 3 |  |
| 16 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 17 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 18 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 19 | `number_autoconv` | 71.4% | 15 | 21 | 6 |  |
| 20 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 21 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 22 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 23 | `xml_hasownproperty` | 66.7% | 4 | 6 | 2 |  |
| 24 | `xml_contains` | 66.5% | 131 | 197 | 66 |  |
| 25 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15 | 24 | 9 |  |
| 26 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 27 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 28 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 29 | `date` | 50.0% | 15 | 30 | 15 |  |
| 30 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 31 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 32 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 33 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 34 | `place_object_same_depth_frame` | 50.0% | 1 | 2 | 1 |  |
| 35 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 36 | `subclass_superclass_linked_symbol` | 50.0% | 3 | 6 | 3 |  |
| 37 | `verification` | 50.0% | 4 | 8 | 4 |  |
| 38 | `xml_equals_namespace_check` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**62 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_access_oob_interpreter` | exit code 1 | 1.7s |  |
| 2 | `bitmap_subclass` | exit code 1 | 2.7s |  |
| 3 | `bitmap_subclass_properties` | exit code 1 | 1.9s |  |
| 4 | `bitmapdata_copychannel` | exit code 1 (output matches) | 22.9s |  |
| 5 | `bitmapdata_draw_cpu_overwrite_gpu` | exit code 1 (output matches) | 20.7s |  |
| 6 | `checkfilter` | exit code 1 | 1.6s |  |
| 7 | `content_element_basic` | exit code 1 | 1.9s |  |
| 8 | `core_exceptions` | exit code 1 | 2.3s |  |
| 9 | `doabc_is_eager` | exit code 1 | 19.7s |  |
| 10 | `domain_memory` | exit code 1 | 1.8s |  |
| 11 | `edittext_always_show_selection` | exit code 1 (output matches) | 21.3s |  |
| 12 | `edittext_at_point_methods_basic` | exit code 1 | 3.0s |  |
| 13 | `edittext_autosize_align` | exit code 1 (output matches) | 21.3s |  |
| 14 | `edittext_autosize_height_dynamic` | exit code 1 | 21.5s |  |
| 15 | `edittext_autosize_height_input` | exit code 1 | 2.0s |  |
| 16 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 3.2s |  |
| 17 | `edittext_autosize_lazy_bounds_visual` | exit code 1 (output matches) | 21.1s |  |
| 18 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 2.0s |  |
| 19 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.9s |  |
| 20 | `edittext_device_transform_layout` | exit code 1 | 1.9s |  |
| 21 | `edittext_empty_text_format` | exit code 1 | 1.9s |  |
| 22 | `edittext_get_char_index_at_point` | exit code 1 | 21.2s |  |
| 23 | `edittext_get_line_index_at_point` | exit code 1 | 21.7s |  |
| 24 | `edittext_get_line_index_of_char` | exit code 1 | 3.0s |  |
| 25 | `edittext_getcharboundaries` | exit code 1 | 2.1s |  |
| 26 | `edittext_getcharboundaries_culling` | exit code 1 | 2.1s |  |
| 27 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.9s |  |
| 28 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.9s |  |
| 29 | `edittext_line_methods` | exit code 1 | 2.9s |  |
| 30 | `edittext_line_metrics` | exit code 1 | 23.1s |  |
| 31 | `edittext_max_scroll_h_basic` | exit code 1 | 1.9s |  |
| 32 | `edittext_max_scroll_v_basic` | exit code 1 | 1.9s |  |
| 33 | `edittext_mouse_selection` | exit code 1 | 22.6s |  |
| 34 | `edittext_wordwrap_word` | exit code 1 | 1.7s |  |
| 35 | `edittext_wrap_breaks` | exit code 1 | 1.8s |  |
| 36 | `font_enumeratefonts_filter` | exit code 1 | 2.2s |  |
| 37 | `font_enumeratefonts_order` | exit code 1 | 2.4s |  |
| 38 | `goto_nested_construct_sibling` | exit code 1 | 2.1s |  |
| 39 | `graphics_bitmap_fill` | exit code 1 (output matches) | 3.0s |  |
| 40 | `method_without_body` | exit code 1 | 19.3s |  |
| 41 | `mouse_wheel_events` | exit code 1 | 22.0s |  |
| 42 | `pixelbender_conversions` | exit code 1 | 1.9s |  |
| 43 | `pixelbender_div` | exit code 1 | 1.8s |  |
| 44 | `pixelbender_input` | exit code 1 | 20.1s |  |
| 45 | `pixelbender_malformed_data` | exit code 1 | 20.1s |  |
| 46 | `pixelbender_parameters` | exit code 1 | 1.9s |  |
| 47 | `pixelbender_parameters_bool` | exit code 1 | 1.9s |  |
| 48 | `pixelbender_parameters_int_vs_bool` | exit code 1 | 1.7s |  |
| 49 | `pixelbender_rsqrt` | exit code 1 | 1.7s |  |
| 50 | `pixelbender_shaderdata_setter` | exit code 1 | 2.2s |  |
| 51 | `pixelbender_vector_output` | exit code 1 | 2.0s |  |
| 52 | `property_priority_scope_cache_order` | exit code 1 | 20.0s |  |
| 53 | `qname_as_lazy_name_attribute_multiname` | exit code 1 | 1.7s |  |
| 54 | `rtqname_not_namespace` | exit code 1 | 1.6s |  |
| 55 | `sound_load_multiple` | exit code 1 | 2.5s |  |
| 56 | `stage3d_rotating_cube` | exit code 1 (output matches) | 3.4s |  |
| 57 | `supercalls_weird` | exit code 1 | 1.5s |  |
| 58 | `textline_splitting_basic` | exit code 1 | 1.9s |  |
| 59 | `verify_typecheck` | exit code 1 | 0.7s |  |
| 60 | `xml_descendants` | exit code 1 | 1.7s |  |
| 61 | `xml_explicit_use_namespace` | exit code 1 | 1.7s |  |
| 62 | `xml_getdescendants_qname` | exit code 1 | 1.6s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 31.7s |  |

## All Output Mismatches

**714 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271/1275 | 1275 | 1275 |  |
| 2 | `displayobject_alpha` | 99.6% | 276/277 | 277 | 277 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 6 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 7 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 8 | `xml_has_property_via_in` | 88.5% | 23/26 | 26 | 26 |  |
| 9 | `interactiveobject_enabled` | 88.0% | 22/25 | 25 | 25 |  |
| 10 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 11 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 12 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 13 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 14 | `event_valueof_tostring` | 77.8% | 14/18 | 18 | 18 |  |
| 15 | `eventdispatcher_dispatchevent` | 75.0% | 9/12 | 12 | 12 |  |
| 16 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 17 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 18 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 19 | `number_autoconv` | 71.4% | 15/21 | 16 | 21 |  |
| 20 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 21 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 22 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 23 | `xml_hasownproperty` | 66.7% | 4/6 | 6 | 6 |  |
| 24 | `xml_contains` | 66.5% | 131/197 | 197 | 197 |  |
| 25 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15/24 | 24 | 22 |  |
| 26 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 27 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 28 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 29 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 30 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 31 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 32 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 33 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 34 | `place_object_same_depth_frame` | 50.0% | 1/2 | 2 | 1 |  |
| 35 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 36 | `subclass_superclass_linked_symbol` | 50.0% | 3/6 | 6 | 4 |  |
| 37 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 38 | `xml_equals_namespace_check` | 50.0% | 1/2 | 2 | 2 |  |
| 39 | `xml_mismatched_tag` | 45.9% | 17/37 | 34 | 37 |  |
| 40 | `eventdispatcher_dispatchevent_cancel` | 45.0% | 9/20 | 9 | 20 |  |
| 41 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 42 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 43 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 44 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 45 | `amf_xml` | 33.3% | 2/6 | 6 | 6 |  |
| 46 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 47 | `event_clone_error_redispatch` | 33.3% | 1/3 | 2 | 3 |  |
| 48 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 49 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 50 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 51 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 52 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 53 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 54 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 55 | `function_proto_created` | 31.1% | 19/61 | 19 | 61 |  |
| 56 | `event_clone` | 30.0% | 6/20 | 6 | 20 |  |
| 57 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 58 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 59 | `error_stack_trace` | 28.9% | 13/45 | 27 | 45 |  |
| 60 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 61 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 62 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 63 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 64 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 65 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 66 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 67 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 68 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 69 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 70 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 71 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 72 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 73 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 74 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 75 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 76 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 77 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 78 | `event_clone_on_redispatch` | 20.0% | 2/10 | 8 | 10 |  |
| 79 | `event_target_getter` | 20.0% | 1/5 | 2 | 5 |  |
| 80 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 81 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 82 | `soundmixer_buffertime` | 20.0% | 1/5 | 1 | 5 |  |
| 83 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 84 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 85 | `event_isdefaultprevented` | 16.7% | 2/12 | 2 | 12 |  |
| 86 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 87 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 88 | `soundmixer_stopall` | 16.7% | 1/6 | 1 | 6 |  |
| 89 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 90 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 91 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 92 | `movieclip_gotoandstop` | 15.4% | 2/13 | 2 | 13 |  |
| 93 | `doabc_and_symbolclass_script_init_goto` | 14.3% | 1/7 | 5 | 7 |  |
| 94 | `movieclip_goto_overwrite` | 14.3% | 2/14 | 2 | 14 |  |
| 95 | `movieclip_gotoandstop_framescripts_self` | 14.3% | 1/7 | 1 | 7 |  |
| 96 | `movieclip_prev_scene` | 14.3% | 1/7 | 1 | 7 |  |
| 97 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 98 | `stage_framerate_nan` | 14.3% | 1/7 | 1 | 7 |  |
| 99 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 100 | `movieclip_goto_during_frame_script` | 13.3% | 2/15 | 2 | 15 |  |
| 101 | `movieclip_gotoandplay` | 13.3% | 2/15 | 2 | 15 |  |
| 102 | `stage_mouseenabled` | 13.3% | 2/15 | 2 | 15 |  |
| 103 | `xml_ctor_from_tostring` | 13.0% | 3/23 | 5 | 23 |  |
| 104 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 105 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 106 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 107 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 108 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 109 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 110 | `soundchannel_stop` | 12.5% | 1/8 | 1 | 8 |  |
| 111 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 112 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 113 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 114 | `bitmapdata_embedded` | 11.1% | 1/9 | 1 | 9 |  |
| 115 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 116 | `event_target_set` | 11.1% | 1/9 | 9 | 9 |  |
| 117 | `eventdispatcher_dispatchevent_indirect` | 11.1% | 1/9 | 1 | 9 |  |
| 118 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 119 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 120 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 121 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 122 | `event_formattostring` | 9.7% | 3/31 | 3 | 31 |  |
| 123 | `construct_frame_list` | 9.1% | 2/22 | 2 | 22 |  |
| 124 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 125 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 126 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 127 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 128 | `goto_in_constructframe` | 8.3% | 1/12 | 1 | 12 |  |
| 129 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 130 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 131 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 132 | `xml_tostring_namespace` | 8.3% | 1/12 | 1 | 12 |  |
| 133 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 134 | `bitmapdata_clone` | 7.7% | 1/13 | 1 | 13 |  |
| 135 | `button_nested_frame_simple` | 7.4% | 2/27 | 3 | 27 |  |
| 136 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 137 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 138 | `soundchannel_soundcomplete` | 6.2% | 1/16 | 1 | 16 |  |
| 139 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 140 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 141 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 142 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 143 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 144 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 145 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 146 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 147 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 148 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 149 | `sound_play` | 5.3% | 1/19 | 1 | 19 |  |
| 150 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 151 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 152 | `swf_9_goto_in_construct_frame` | 5.0% | 1/20 | 1 | 20 |  |
| 153 | `xml_list_concat` | 5.0% | 1/20 | 1 | 20 |  |
| 154 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 155 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 156 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 157 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 158 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 159 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 160 | `button_nested_frame` | 4.2% | 2/48 | 3 | 48 |  |
| 161 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 162 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 163 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 164 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 165 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 166 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 167 | `static_length` | 4.2% | 1/24 | 24 | 24 |  |
| 168 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 169 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 170 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 171 | `sound_embeddedprops` | 3.8% | 1/26 | 1 | 26 |  |
| 172 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 173 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 174 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 175 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 176 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 177 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 178 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 179 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 180 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 181 | `sound_valueof` | 3.0% | 1/33 | 1 | 33 |  |
| 182 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 183 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 184 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 185 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 186 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 187 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 188 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 189 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 190 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 191 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 192 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 193 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 194 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 195 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 196 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 197 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 198 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 199 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 200 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 201 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 202 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 203 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 204 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 205 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 206 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 207 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 208 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 209 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 210 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 211 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 212 | `orphan_movie_reorder` | 1.8% | 2/111 | 2 | 111 |  |
| 213 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 214 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 215 | `displayobjectcontainer_addchild_timelinepull1` | 1.7% | 1/60 | 1 | 60 |  |
| 216 | `flash_xml_removeNode` | 1.7% | 1/60 | 1 | 60 |  |
| 217 | `pixelbender_sign` | 1.7% | 1/60 | 1 | 60 |  |
| 218 | `displacement_map_filter` | 1.6% | 1/61 | 1 | 61 |  |
| 219 | `displayobjectcontainer_addchild_timelinepull2` | 1.6% | 1/62 | 1 | 62 |  |
| 220 | `edittext_newline_stripping` | 1.6% | 1/64 | 1 | 64 |  |
| 221 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 222 | `displayobjectcontainer_contains` | 1.5% | 1/66 | 1 | 66 |  |
| 223 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 224 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 225 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 226 | `geom_transform` | 1.4% | 1/74 | 1 | 74 |  |
| 227 | `pixelbender_ceil` | 1.3% | 1/77 | 1 | 77 |  |
| 228 | `simplebutton_childevents` | 1.2% | 1/86 | 1 | 86 |  |
| 229 | `simplebutton_childevents_script_order` | 1.1% | 1/87 | 3 | 87 |  |
| 230 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 231 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 232 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 233 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 234 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 235 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 236 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 237 | `bounds_mode` | 0.7% | 2/269 | 2 | 269 |  |
| 238 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 239 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 240 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 241 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 242 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 243 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 244 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 245 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 246 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 247 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 248 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 249 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 250 | `soundchannel_soundtransform` | 0.1% | 1/835 | 1 | 835 |  |
| 251 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 252 | `soundmixer_soundtransform` | 0.1% | 1/900 | 1 | 900 |  |
| 253 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 254 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 255 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 256 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 257 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 258 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 259 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 263 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 264 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 265 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 266 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 267 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 268 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 269 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 270 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 271 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 272 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 273 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 274 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 275 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 276 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 277 | `all_classes/events/swf10` | 0.0% | 0/1638 | 0 | 1638 |  |
| 278 | `all_classes/events/swf11` | 0.0% | 0/1750 | 0 | 1750 |  |
| 279 | `all_classes/events/swf12` | 0.0% | 0/1814 | 0 | 1814 |  |
| 280 | `all_classes/events/swf30` | 0.0% | 0/2353 | 0 | 2353 |  |
| 281 | `all_classes/events/swf9` | 0.0% | 0/1030 | 0 | 1030 |  |
| 282 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 283 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 284 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 285 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 286 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 287 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 288 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 289 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 290 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 291 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 292 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 293 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 294 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 295 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 296 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 297 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `bitmapdata_copypixels` | 0.0% | 0/23 | 0 | 23 |  |
| 301 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 302 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 303 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 304 | `bitmapdata_draw_alpha_erase` | 0.0% | 0/8 | 0 | 8 |  |
| 305 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 306 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 307 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 308 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 309 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 310 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 311 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 312 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 313 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 314 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 315 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 316 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 317 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 318 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 319 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 320 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 321 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 322 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 323 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 324 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 325 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 326 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 327 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 328 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 329 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 330 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 331 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 332 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 333 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 334 | `describe_type_basic` | 0.0% | 0/152 | 0 | 152 |  |
| 335 | `describe_type_json` | 0.0% | 0/301 | 0 | 301 |  |
| 336 | `describe_type_metadata` | 0.0% | 0/125 | 0 | 125 |  |
| 337 | `describe_type_native` | 0.0% | 0/23 | 0 | 23 |  |
| 338 | `dictionary_weak_keys` | 0.0% | 0/2 | 0 | 2 |  |
| 339 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 340 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `displayobject_hittestpoint_boundary` | 0.0% | 0/65 | 0 | 65 |  |
| 342 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 343 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 344 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 345 | `displayobject_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 346 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 347 | `displayobject_opaque_background` | 0.0% | 0/6 | 0 | 6 |  |
| 348 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 349 | `displayobject_scrollrect` | 0.0% | 0/33 | 0 | 33 |  |
| 350 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 351 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 352 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 353 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 354 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 355 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 357 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 358 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 359 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 360 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 361 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 362 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 363 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 364 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 365 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 366 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 367 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 368 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 369 | `edittext_getcharboundaries_missing_embedded_font` | 0.0% | 0/7 | 0 | 7 |  |
| 370 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 371 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 372 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 373 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 374 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 375 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 376 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 377 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 378 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 379 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 380 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 381 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 382 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 383 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 384 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 385 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 386 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 387 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 388 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 389 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 390 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 391 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 392 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 393 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 394 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 395 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 396 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 397 | `edittext_tab_stops` | 0.0% | 0/60 | 0 | 60 |  |
| 398 | `edittext_tag_indent` | 0.0% | 0/49 | 0 | 49 |  |
| 399 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 400 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 401 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 402 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 403 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 404 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 405 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 406 | `error_1034_debug_string` | 0.0% | 0/30 | 6 | 30 |  |
| 407 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 408 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 409 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 410 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 411 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 412 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 413 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 414 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 415 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 416 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 417 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 418 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 419 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 420 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 421 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 422 | `flash_xml` | 0.0% | 0/29 | 0 | 29 |  |
| 423 | `flash_xml_cloneNode` | 0.0% | 0/22 | 0 | 22 |  |
| 424 | `flash_xml_namespace` | 0.0% | 0/109 | 0 | 109 |  |
| 425 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 426 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 427 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 428 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 429 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 430 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 431 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 432 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 433 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 434 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 435 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 436 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 437 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 438 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 439 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 440 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 441 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 442 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 443 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 444 | `goto_button_nested_framescript` | 0.0% | 0/28 | 1 | 28 |  |
| 445 | `goto_framescript_queued` | 0.0% | 0/6 | 0 | 6 |  |
| 446 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 447 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 448 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 449 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 450 | `graphics_draw_path` | 0.0% | 0/34 | 0 | 34 |  |
| 451 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 452 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 453 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 454 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 455 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 456 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 457 | `issue_13780` | 0.0% | 0/12 | 0 | 12 |  |
| 458 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 459 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 460 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 461 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 462 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 463 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 464 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 465 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 466 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 467 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 468 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 469 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 470 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 471 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 472 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 473 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 474 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 475 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 476 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 477 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 478 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 479 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 480 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 481 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 482 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 483 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 484 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 485 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 486 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 487 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 488 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 489 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 490 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 491 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 492 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 493 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 494 | `mask_reapply` | 0.0% | 0/1 | 0 | 1 |  |
| 495 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 496 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 497 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 498 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 499 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 500 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 501 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 502 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 503 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 504 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 505 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 506 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 507 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 508 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 509 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 510 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 511 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 512 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 513 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 514 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 1 | 676 |  |
| 515 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 1 | 2001 |  |
| 516 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 1 | 575 |  |
| 517 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 1 | 562 |  |
| 518 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 1 | 140 |  |
| 519 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 1 | 50 |  |
| 520 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 1 | 144 |  |
| 521 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 522 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 1 | 149 |  |
| 523 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 1 | 48 |  |
| 524 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 1 | 149 |  |
| 525 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 1 | 106 |  |
| 526 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 1 | 44 |  |
| 527 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 1 | 135 |  |
| 528 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 529 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 530 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 531 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 532 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 1 | 9 |  |
| 533 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 1 | 7 |  |
| 534 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 535 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 536 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 537 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 538 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 539 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 540 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 541 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 542 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 543 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 544 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 545 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 546 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 547 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 548 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 549 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 550 | `null_void_types` | 0.0% | 0/8 | 0 | 8 |  |
| 551 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 552 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 553 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 554 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 555 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 556 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 557 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 558 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 559 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 560 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 561 | `pixelbender_outputs` | 0.0% | 0/13 | 0 | 13 |  |
| 562 | `pixelbender_padding_bytes` | 0.0% | 0/22 | 0 | 22 |  |
| 563 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 0 | 512 |  |
| 564 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 565 | `pixelbender_select_kinds` | 0.0% | 0/8 | 0 | 8 |  |
| 566 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 567 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 568 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 569 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 570 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 571 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 572 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 573 | `remove_child_clear_field` | 0.0% | 0/88 | 1 | 88 |  |
| 574 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 575 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 576 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 577 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 578 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 579 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 580 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 581 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 582 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 583 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 584 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 585 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 2 | 45 |  |
| 586 | `simplebutton_childevents_multichild` | 0.0% | 0/152 | 1 | 152 |  |
| 587 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 588 | `simplebutton_childevents_sprite` | 0.0% | 0/13 | 1 | 13 |  |
| 589 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 590 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 591 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 592 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 593 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 594 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 595 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 596 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 597 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 598 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 599 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 600 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 601 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 602 | `sound_rootless` | 0.0% | 0/7 | 0 | 7 |  |
| 603 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 604 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 605 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 606 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 607 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 608 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 609 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 610 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 611 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 612 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 613 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 614 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 615 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 616 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 617 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 618 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 619 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 620 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 621 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 622 | `stage_scale_factor` | 0.0% | 0/12 | 0 | 12 |  |
| 623 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 624 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 625 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 626 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 627 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 628 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 629 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 1 | 6 |  |
| 630 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 631 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 632 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 633 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 634 | `symbol_class_conflict` | 0.0% | 0/4 | 0 | 4 |  |
| 635 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 636 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 637 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 638 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 639 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 640 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 641 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 642 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 643 | `tab_ordering_stage_tab_children_remove_root` | 0.0% | 0/5 | 0 | 5 |  |
| 644 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 645 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 646 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 647 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 648 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 649 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 650 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 651 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 652 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 653 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 654 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 655 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 656 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 657 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 658 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 659 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 660 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 661 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 662 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 663 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 664 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 665 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 666 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 667 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 668 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 669 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 670 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 671 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 672 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 673 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 674 | `xml_abstract_equality` | 0.0% | 0/36 | 0 | 36 |  |
| 675 | `xml_advanced` | 0.0% | 0/52 | 13 | 52 |  |
| 676 | `xml_appendchild` | 0.0% | 0/10 | 1 | 10 |  |
| 677 | `xml_appendchild_swf_v21` | 0.0% | 0/13 | 0 | 13 |  |
| 678 | `xml_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 679 | `xml_attribute` | 0.0% | 0/35 | 0 | 35 |  |
| 680 | `xml_attribute_name` | 0.0% | 0/40 | 0 | 40 |  |
| 681 | `xml_basic` | 0.0% | 0/32 | 0 | 32 |  |
| 682 | `xml_child` | 0.0% | 0/25 | 0 | 25 |  |
| 683 | `xml_childindex` | 0.0% | 0/7 | 0 | 7 |  |
| 684 | `xml_children` | 0.0% | 0/43 | 0 | 43 |  |
| 685 | `xml_class_call` | 0.0% | 0/9 | 0 | 9 |  |
| 686 | `xml_copy` | 0.0% | 0/20 | 0 | 20 |  |
| 687 | `xml_delete` | 0.0% | 0/114 | 0 | 114 |  |
| 688 | `xml_elements` | 0.0% | 0/6 | 0 | 6 |  |
| 689 | `xml_ignore_white` | 0.0% | 0/6 | 2 | 6 |  |
| 690 | `xml_length` | 0.0% | 0/2 | 0 | 2 |  |
| 691 | `xml_list_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 692 | `xml_list_enumerate` | 0.0% | 0/4 | 2 | 4 |  |
| 693 | `xml_methods_settings` | 0.0% | 0/3 | 3 | 3 |  |
| 694 | `xml_namespace` | 0.0% | 0/39 | 0 | 39 |  |
| 695 | `xml_namespace_methods` | 0.0% | 0/245 | 0 | 245 |  |
| 696 | `xml_namespaced_property` | 0.0% | 0/7 | 0 | 7 |  |
| 697 | `xml_no_namespace` | 0.0% | 0/1 | 0 | 1 |  |
| 698 | `xml_nodekind` | 0.0% | 0/3 | 0 | 3 |  |
| 699 | `xml_normalize` | 0.0% | 0/35 | 0 | 35 |  |
| 700 | `xml_notification_bubbling` | 0.0% | 0/361 | 0 | 361 |  |
| 701 | `xml_parent` | 0.0% | 0/8 | 0 | 8 |  |
| 702 | `xml_set_children` | 0.0% | 0/17 | 0 | 17 |  |
| 703 | `xml_set_name` | 0.0% | 0/34 | 0 | 34 |  |
| 704 | `xml_settings` | 0.0% | 0/6 | 0 | 6 |  |
| 705 | `xml_simple_complex_content` | 0.0% | 0/47 | 0 | 47 |  |
| 706 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
| 707 | `xml_text` | 0.0% | 0/7 | 0 | 7 |  |
| 708 | `xml_tostring` | 0.0% | 0/6 | 6 | 6 |  |
| 709 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 710 | `xml_weird_ignores` | 0.0% | 0/56 | 56 | 54 |  |
| 711 | `xml_wildcard` | 0.0% | 0/11 | 0 | 11 |  |
| 712 | `xmldocument` | 0.0% | 0/254 | 0 | 254 |  |
| 713 | `xmlnode` | 0.0% | 0/3540 | 0 | 3540 |  |
| 714 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
