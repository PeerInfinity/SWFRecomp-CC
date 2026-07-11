# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 19:59 UTC

**Git SHA**: `f1d27c50cb`

**Run Duration**: 82m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1201 |
| Passing | **475** (39.6%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **487** (40.5%) |
| Failing | 714 |
| Total expected lines | 149021 |
| Matching lines | 51414 (34.5%) |
| Mismatched lines | 97607 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 699 | 97.9% |
| Runtime Error | 14 | 2.0% |
| Timeout | 1 | 0.1% |

## Passing Tests

**475 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.8s |  |
| 2 | `air_hidden_lookup` | 2 | 0.8s |  |
| 3 | `amf_custom_obj` | 26 | 0.8s |  |
| 4 | `amf_dictionary` | 9 | 0.7s |  |
| 5 | `amf_function` | 46 | 0.8s |  |
| 6 | `amf_invalid_date` | 2 | 0.7s |  |
| 7 | `amf_missing_prop` | 6 | 0.7s |  |
| 8 | `amf_nondynamic_function_prop` | 6 | 1.7s |  |
| 9 | `amf_setter_error` | 8 | 8.1s |  |
| 10 | `amf_vector` | 40 | 1.8s |  |
| 11 | `amf_xml` | 6 | 1.7s |  |
| 12 | `application_domain` | 4 | 1.7s |  |
| 13 | `array_access` | 18 | 1.8s |  |
| 14 | `array_access_interpreter` | 4 | 1.7s |  |
| 15 | `array_access_no_pubns` | 2 | 1.7s |  |
| 16 | `array_concat` | 41 | 1.7s |  |
| 17 | `array_constr` | 10 | 1.7s |  |
| 18 | `array_delete` | 44 | 1.8s |  |
| 19 | `array_enumeration` | 10 | 1.7s |  |
| 20 | `array_enumeration_elements` | 11 | 1.7s |  |
| 21 | `array_every` | 8 | 1.7s |  |
| 22 | `array_filter` | 6 | 1.7s |  |
| 23 | `array_foreach` | 18 | 1.7s |  |
| 24 | `array_hasownproperty` | 11 | 1.7s |  |
| 25 | `array_holes` | 9 | 1.7s |  |
| 26 | `array_index_max` | 84 | 1.4s |  |
| 27 | `array_indexof` | 25 | 1.7s |  |
| 28 | `array_join` | 26 | 1.8s |  |
| 29 | `array_lastindexof` | 29 | 1.7s |  |
| 30 | `array_length` | 14 | 1.7s |  |
| 31 | `array_literal` | 3 | 1.7s |  |
| 32 | `array_map` | 8 | 0.4s |  |
| 33 | `array_pop` | 52 | 1.7s |  |
| 34 | `array_push` | 24 | 1.7s |  |
| 35 | `array_reborrow_bug` | 6 | 1.7s |  |
| 36 | `array_reverse` | 28 | 1.7s |  |
| 37 | `array_shift` | 51 | 1.8s |  |
| 38 | `array_slice` | 39 | 1.8s |  |
| 39 | `array_some` | 8 | 1.6s |  |
| 40 | `array_sort` | 297 | 1.9s |  |
| 41 | `array_sort_fun_swf12` | 2 | 1.7s |  |
| 42 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 43 | `array_sort_random` | 210 | 1.7s |  |
| 44 | `array_sort_swf10_32bit` | 1 | 1.6s |  |
| 45 | `array_sorton` | 545 | 2.1s |  |
| 46 | `array_sparse_ops` | 41 | 1.8s |  |
| 47 | `array_splice` | 133 | 1.8s |  |
| 48 | `array_splice2` | 428 | 2.0s |  |
| 49 | `array_splice_types` | 48 | 1.8s |  |
| 50 | `array_storage` | 8 | 1.7s |  |
| 51 | `array_tolocalestring` | 9 | 1.7s |  |
| 52 | `array_tostring` | 12 | 1.7s |  |
| 53 | `array_unshift` | 24 | 1.7s |  |
| 54 | `array_valueof` | 9 | 1.6s |  |
| 55 | `array_vector_null_callback` | 10 | 1.7s |  |
| 56 | `astype` | 28 | 1.8s |  |
| 57 | `astypelate` | 24 | 1.8s |  |
| 58 | `astypelate_propagates` | 1 | 1.7s |  |
| 59 | `away3d_advanced_shallow_water_demo` | 0 | 63.0s |  |
| 60 | `bitand` | 1058 | 4.1s |  |
| 61 | `bitmapdata_applyfilter_blur` | 0 | 20.7s |  |
| 62 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.0s |  |
| 63 | `bitmapdata_applyfilter_destpoint` | 0 | 20.6s |  |
| 64 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.7s |  |
| 65 | `bitmapdata_colortransform` | 0 | 1.9s |  |
| 66 | `bitmapdata_draw` | 0 | 20.1s |  |
| 67 | `bitmapdata_draw_colortransform` | 0 | 1.7s |  |
| 68 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 20.3s |  |
| 69 | `bitmapdata_draw_filters` | 0 | 19.8s |  |
| 70 | `bitmapdata_draw_masks` | 0 | 1.7s |  |
| 71 | `bitmapdata_draw_rotation` | 0 | 1.7s |  |
| 72 | `bitmapdata_draw_self_via_graphic` | 0 | 1.7s |  |
| 73 | `bitmapdata_draw_stage` | 0 | 19.8s |  |
| 74 | `bitmapdata_drawwithquality` | 0 | 1.9s |  |
| 75 | `bitmapdata_fillrect` | 0 | 1.7s |  |
| 76 | `bitmapdata_filter_sourcerect` | 0 | 20.1s |  |
| 77 | `bitmapdata_opaque` | 0 | 1.7s |  |
| 78 | `bitmapdata_pixeldissolve_image` | 0 | 1.8s |  |
| 79 | `bitmapdata_sync` | 0 | 1.8s |  |
| 80 | `bitnot` | 46 | 1.7s |  |
| 81 | `bitor` | 1058 | 3.7s |  |
| 82 | `bitxor` | 1058 | 3.7s |  |
| 83 | `blend_multiply_alpha` | 0 | 1.7s |  |
| 84 | `blend_scroll` | 0 | 1.7s |  |
| 85 | `boolean_constr` | 32 | 1.7s |  |
| 86 | `boolean_negation` | 30 | 1.7s |  |
| 87 | `boolean_tostring` | 8 | 1.6s |  |
| 88 | `bytearray` | 48 | 1.9s |  |
| 89 | `bytearray_compress` | 31 | 1.7s |  |
| 90 | `bytearray_errors` | 24 | 1.8s |  |
| 91 | `bytearray_method_serialization` | 1 | 1.7s |  |
| 92 | `bytearray_readobject_amf0` | 50 | 0.7s |  |
| 93 | `bytearray_readobject_amf3` | 53 | 1.7s |  |
| 94 | `bytearray_readutf8bytes_with_bom` | 16 | 1.7s |  |
| 95 | `bytearray_serialization` | 3 | 1.6s |  |
| 96 | `bytearray_string_null` | 19 | 1.8s |  |
| 97 | `bytearray_tostring` | 15 | 1.7s |  |
| 98 | `bytearray_utf16` | 8 | 1.7s |  |
| 99 | `bytearray_writeobject` | 24 | 0.6s |  |
| 100 | `callee_in_initializer` | 6 | 1.6s |  |
| 101 | `callproplex_class` | 1 | 1.7s |  |
| 102 | `catch_class` | 6 | 1.6s |  |
| 103 | `catch_scope_slot` | 7 | 1.7s |  |
| 104 | `checkfilter` | 4 | 1.6s |  |
| 105 | `class_call` | 32 | 1.7s |  |
| 106 | `class_cast_call` | 14 | 1.6s |  |
| 107 | `class_enumeration` | 4 | 1.7s |  |
| 108 | `class_has_own_property` | 2 | 1.7s |  |
| 109 | `class_init_interpreter_mode` | 1 | 1.6s |  |
| 110 | `class_is` | 32 | 1.7s |  |
| 111 | `class_methods` | 5 | 1.7s |  |
| 112 | `class_object_properties` | 10 | 1.8s |  |
| 113 | `class_singleton` | 18 | 6.7s |  |
| 114 | `class_supercalls_errors` | 35 | 1.6s |  |
| 115 | `class_supercalls_mismatched` | 26 | 1.6s |  |
| 116 | `class_superclass_wrong_order` | 1 | 1.4s |  |
| 117 | `class_to_locale_string` | 2 | 1.4s |  |
| 118 | `class_to_string` | 2 | 1.4s |  |
| 119 | `class_value_of` | 2 | 1.4s |  |
| 120 | `closures` | 12 | 1.5s |  |
| 121 | `coerce_property` | 33 | 1.5s |  |
| 122 | `coerce_return_type` | 40 | 1.7s |  |
| 123 | `coerce_return_type_fail` | 2 | 1.6s |  |
| 124 | `coerce_return_void` | 3 | 1.6s |  |
| 125 | `coerce_string` | 86 | 1.5s |  |
| 126 | `coerce_string_precision` | 28 | 1.4s |  |
| 127 | `coerce_to_primitive_side_effects` | 29 | 1.5s |  |
| 128 | `construct_errors_swf10` | 8 | 1.4s |  |
| 129 | `constructor_call` | 3 | 1.5s |  |
| 130 | `constructprop_dynamic_primitive` | 7 | 1.4s |  |
| 131 | `control_flow_bool` | 4 | 1.6s |  |
| 132 | `control_flow_stricteq` | 8 | 1.5s |  |
| 133 | `convert_boolean` | 30 | 1.4s |  |
| 134 | `convert_integer` | 90 | 1.4s |  |
| 135 | `convert_number` | 56 | 1.4s |  |
| 136 | `convert_uinteger` | 90 | 1.5s |  |
| 137 | `declocal` | 46 | 1.7s |  |
| 138 | `declocal_i` | 46 | 1.6s |  |
| 139 | `decrement` | 46 | 1.6s |  |
| 140 | `decrement_i` | 46 | 1.6s |  |
| 141 | `default_values` | 7 | 1.6s |  |
| 142 | `dictionary_access` | 62 | 1.8s |  |
| 143 | `dictionary_access_no_pubns` | 2 | 1.6s |  |
| 144 | `dictionary_delete` | 101 | 1.8s |  |
| 145 | `dictionary_foreach` | 42 | 1.8s |  |
| 146 | `dictionary_hasownproperty` | 63 | 1.7s |  |
| 147 | `dictionary_in` | 62 | 1.8s |  |
| 148 | `dictionary_iter_modify` | 8 | 1.6s |  |
| 149 | `dictionary_namespaces` | 36 | 1.7s |  |
| 150 | `dictionary_primitive_keys` | 29 | 1.6s |  |
| 151 | `displayobject_blendmode` | 0 | 19.5s |  |
| 152 | `displayobject_colortransform_nested` | 0 | 19.9s |  |
| 153 | `displayobject_getbounds_shape` | 0 | 19.7s |  |
| 154 | `displayobject_mask_self_referential` | 0 | 1.6s |  |
| 155 | `displayobject_set_matrix_nested` | 0 | 20.4s |  |
| 156 | `divide` | 1058 | 3.6s |  |
| 157 | `doabc_is_eager` | 1 | 19.1s |  |
| 158 | `duplicate_defs` | 1 | 0.5s |  |
| 159 | `eager_init` | 1 | 1.6s |  |
| 160 | `edittext_always_show_selection` | 0 | 20.2s |  |
| 161 | `edittext_autosize_align` | 0 | 19.8s |  |
| 162 | `edittext_autosize_lazy_bounds_visual` | 0 | 19.6s |  |
| 163 | `equals` | 512 | 2.8s |  |
| 164 | `error_prototype` | 15 | 1.7s |  |
| 165 | `error_stack_trace_debug_swf17` | 0 | 21.3s |  |
| 166 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 167 | `error_stack_trace_release_swf17` | 0 | 0.4s |  |
| 168 | `error_stack_trace_release_swf18` | 0 | 0.3s |  |
| 169 | `error_tostring` | 29 | 1.8s |  |
| 170 | `es3_inheritance` | 31 | 1.8s |  |
| 171 | `es4_inheritance` | 30 | 1.8s |  |
| 172 | `es4_interfaces` | 30 | 1.9s |  |
| 173 | `es4_method_binding` | 8 | 1.8s |  |
| 174 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 175 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 176 | `event_bubbles` | 2 | 1.7s |  |
| 177 | `event_cancelable` | 2 | 1.7s |  |
| 178 | `event_type` | 1 | 1.6s |  |
| 179 | `eventdispatcher_dispatchevent_this` | 5 | 1.7s |  |
| 180 | `eventdispatcher_haseventlistener` | 25 | 1.7s |  |
| 181 | `falsiness` | 30 | 1.7s |  |
| 182 | `fast_index_access` | 12 | 1.9s |  |
| 183 | `finddef` | 3 | 1.7s |  |
| 184 | `findprop_global_prototype` | 6 | 1.7s |  |
| 185 | `flash_xml` | 29 | 1.7s |  |
| 186 | `flash_xml_cloneNode` | 22 | 6.3s |  |
| 187 | `flash_xml_namespace` | 109 | 1.4s |  |
| 188 | `flash_xml_removeNode` | 60 | 1.4s |  |
| 189 | `function_call` | 12 | 1.4s |  |
| 190 | `function_call_arguments` | 46 | 1.4s |  |
| 191 | `function_call_arguments_enumerate` | 5 | 1.3s |  |
| 192 | `function_call_coercion` | 108 | 1.5s |  |
| 193 | `function_call_default` | 6 | 1.4s |  |
| 194 | `function_call_rest` | 22 | 1.5s |  |
| 195 | `function_call_types` | 3 | 1.4s |  |
| 196 | `function_call_via_apply` | 11 | 1.3s |  |
| 197 | `function_call_via_call` | 3 | 1.3s |  |
| 198 | `function_display_anonymous` | 7 | 1.3s |  |
| 199 | `function_length` | 6 | 1.3s |  |
| 200 | `function_object` | 2 | 1.3s |  |
| 201 | `function_proto` | 5 | 1.3s |  |
| 202 | `function_proto_created` | 61 | 8.2s |  |
| 203 | `function_to_locale_string` | 4 | 1.7s |  |
| 204 | `function_to_string` | 4 | 1.7s |  |
| 205 | `function_type` | 6 | 1.8s |  |
| 206 | `function_unbound_this` | 51 | 1.9s |  |
| 207 | `function_value_of` | 4 | 1.7s |  |
| 208 | `get_definition_by_name` | 11 | 1.8s |  |
| 209 | `get_qualified_class_name` | 20 | 1.8s |  |
| 210 | `get_slot_edge_cases` | 1 | 1.7s |  |
| 211 | `getglobalslot` | 1 | 1.7s |  |
| 212 | `getouterscope` | 8 | 1.7s |  |
| 213 | `getter_different_namespace_setter` | 2 | 1.8s |  |
| 214 | `graphics_bitmaps` | 0 | 2.0s |  |
| 215 | `graphics_direct_commands` | 0 | 1.9s |  |
| 216 | `graphics_gradients` | 0 | 1.9s |  |
| 217 | `graphics_gradients_nulls` | 0 | 1.8s |  |
| 218 | `graphics_round_rects` | 0 | 1.8s |  |
| 219 | `graphics_simple_shapes` | 0 | 1.8s |  |
| 220 | `greaterequals` | 512 | 9.3s |  |
| 221 | `greaterthan` | 512 | 2.9s |  |
| 222 | `has_own_property` | 102 | 2.0s |  |
| 223 | `hasownproperty_namespaces` | 2 | 1.8s |  |
| 224 | `hello_world` | 1 | 1.8s |  |
| 225 | `if_eq` | 10 | 1.8s |  |
| 226 | `if_gt` | 1 | 1.7s |  |
| 227 | `if_gte` | 10 | 1.7s |  |
| 228 | `if_lt` | 1 | 0.4s |  |
| 229 | `if_lte` | 10 | 0.4s |  |
| 230 | `if_ne` | 7 | 1.7s |  |
| 231 | `if_stricteq` | 6 | 1.7s |  |
| 232 | `if_strictne` | 11 | 1.7s |  |
| 233 | `in` | 102 | 1.9s |  |
| 234 | `inclocal` | 46 | 1.7s |  |
| 235 | `inclocal_i` | 46 | 1.7s |  |
| 236 | `increment` | 46 | 1.8s |  |
| 237 | `increment_i` | 46 | 1.8s |  |
| 238 | `instanceof` | 58 | 1.9s |  |
| 239 | `int_constr` | 92 | 1.8s |  |
| 240 | `int_edge_cases` | 19 | 1.8s |  |
| 241 | `int_instanceof` | 3 | 1.7s |  |
| 242 | `int_tofixed` | 1215 | 1.7s |  |
| 243 | `int_tostring` | 3375 | 1.9s |  |
| 244 | `interface_namespaces` | 78 | 1.8s |  |
| 245 | `is_finite` | 46 | 1.8s |  |
| 246 | `is_nan` | 46 | 1.7s |  |
| 247 | `is_prototype_of` | 12 | 1.7s |  |
| 248 | `issue_10221` | 2 | 1.7s |  |
| 249 | `issue_13780` | 12 | 7.8s |  |
| 250 | `issue_14901` | 1 | 1.7s |  |
| 251 | `istype` | 24 | 1.8s |  |
| 252 | `istypelate` | 58 | 1.9s |  |
| 253 | `istypelate_coerce` | 198 | 2.2s |  |
| 254 | `json_errors` | 9 | 20.5s |  |
| 255 | `json_parse` | 21 | 1.8s |  |
| 256 | `json_version_gated` | 1 | 1.7s |  |
| 257 | `lazyinit` | 17 | 1.7s |  |
| 258 | `lessequals` | 512 | 2.8s |  |
| 259 | `lessthan` | 512 | 2.7s |  |
| 260 | `lshift` | 1058 | 3.7s |  |
| 261 | `math` | 497 | 1.8s |  |
| 262 | `modulo` | 1058 | 3.7s |  |
| 263 | `movieclip_stop` | 1 | 19.6s |  |
| 264 | `multiply` | 1058 | 3.8s |  |
| 265 | `namespace_constr` | 253 | 2.0s |  |
| 266 | `namespace_constr_args` | 1 | 1.6s |  |
| 267 | `namespace_enumeration_order` | 7 | 1.6s |  |
| 268 | `negate` | 30 | 1.7s |  |
| 269 | `negative_volume_panned` | 0 | 1.8s |  |
| 270 | `nested_iteration` | 11 | 1.7s |  |
| 271 | `net_getClassByAlias` | 3 | 1.7s |  |
| 272 | `newactivation_in_script_init` | 3 | 1.6s |  |
| 273 | `newclass_twice` | 3 | 1.6s |  |
| 274 | `nonconflicting_declarations` | 0 | 1.6s |  |
| 275 | `number_autoconv` | 21 | 1.6s |  |
| 276 | `number_autoconv_amf` | 132 | 1.6s |  |
| 277 | `number_autoconv_array_sort_32bit` | 1 | 1.7s |  |
| 278 | `number_constr` | 58 | 1.7s |  |
| 279 | `number_toexponential` | 378 | 1.7s |  |
| 280 | `number_toexponential2` | 35 | 1.6s |  |
| 281 | `number_tofixed` | 378 | 1.6s |  |
| 282 | `number_toprecision` | 350 | 1.7s |  |
| 283 | `obfuscated_class_names` | 3 | 1.6s |  |
| 284 | `object_enumeration` | 10 | 1.6s |  |
| 285 | `object_prototype` | 4 | 1.7s |  |
| 286 | `object_to_locale_string` | 2 | 1.6s |  |
| 287 | `object_to_string` | 2 | 1.6s |  |
| 288 | `object_value_of` | 2 | 1.4s |  |
| 289 | `op_coerce` | 54 | 1.1s |  |
| 290 | `op_coerce_x` | 54 | 1.7s |  |
| 291 | `op_escxattr` | 2 | 1.6s |  |
| 292 | `op_escxelem` | 2 | 1.6s |  |
| 293 | `op_lookupswitch` | 4 | 1.6s |  |
| 294 | `optimize_coerce` | 1 | 1.6s |  |
| 295 | `param_default_value_has_zero_cpool_index` | 1 | 1.3s |  |
| 296 | `parse_float` | 80 | 1.4s |  |
| 297 | `pixelbender_effect_BlurredFocus` | 0 | 17.8s |  |
| 298 | `pixelbender_effect_glassDisplace` | 0 | 5.0s |  |
| 299 | `pixelbender_effect_smudge` | 0 | 3.1s |  |
| 300 | `pixelbender_effect_tintype` | 0 | 2.7s |  |
| 301 | `pixelbender_effect_twirl` | 0 | 3.5s |  |
| 302 | `pixelbender_images` | 0 | 2.6s |  |
| 303 | `primitive_edge_cases` | 1 | 1.6s |  |
| 304 | `property_priority` | 22 | 2.0s |  |
| 305 | `property_priority_three_level` | 6 | 1.8s |  |
| 306 | `propertyisenumerable_namespaces` | 6 | 1.7s |  |
| 307 | `prototype_set_null` | 7 | 1.7s |  |
| 308 | `proxy_callproperty` | 24 | 1.7s |  |
| 309 | `proxy_deleteproperty` | 64 | 1.8s |  |
| 310 | `proxy_enumeration` | 34 | 1.7s |  |
| 311 | `proxy_getproperty` | 77 | 1.7s |  |
| 312 | `proxy_hasownproperty` | 8 | 1.7s |  |
| 313 | `proxy_hasproperty` | 32 | 1.9s |  |
| 314 | `proxy_serialize` | 9 | 1.7s |  |
| 315 | `proxy_setproperty` | 42 | 1.7s |  |
| 316 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.6s |  |
| 317 | `qname_constr` | 32 | 1.7s |  |
| 318 | `qname_constr_namespace` | 24 | 1.7s |  |
| 319 | `qname_enumeration` | 9 | 1.7s |  |
| 320 | `qname_indexing` | 23 | 1.8s |  |
| 321 | `qname_tostring` | 25 | 1.8s |  |
| 322 | `qname_valueof` | 29 | 1.7s |  |
| 323 | `regexp_constr` | 148 | 1.9s |  |
| 324 | `regexp_exec` | 19 | 1.7s |  |
| 325 | `regexp_extended` | 47 | 1.7s |  |
| 326 | `regexp_multiargs` | 1 | 1.6s |  |
| 327 | `regexp_test` | 27 | 8.1s |  |
| 328 | `regexp_toString` | 10 | 1.8s |  |
| 329 | `resolve_order` | 4 | 1.7s |  |
| 330 | `rng` | 1 | 3.1s |  |
| 331 | `rshift` | 1058 | 3.8s |  |
| 332 | `set_property_is_enumerable` | 85 | 1.9s |  |
| 333 | `slot_disp_id_shared_numbering` | 1 | 26.6s |  |
| 334 | `slots_force_autoassigned` | 1 | 1.7s |  |
| 335 | `sprite_with_frames` | 0 | 20.4s |  |
| 336 | `stage3d_agal_cross_product` | 0 | 2.9s |  |
| 337 | `stage3d_bitmap` | 0 | 22.8s |  |
| 338 | `stage3d_float1_index` | 0 | 21.1s |  |
| 339 | `stage3d_fractal` | 0 | 10.5s |  |
| 340 | `stage3d_ignore_sampler_override` | 0 | 23.0s |  |
| 341 | `stage3d_program_constants_bytearray_be` | 0 | 23.9s |  |
| 342 | `stage3d_program_constants_bytearray_le` | 0 | 3.7s |  |
| 343 | `stage3d_raytrace` | 0 | 21.8s |  |
| 344 | `stage3d_sampler` | 0 | 3.4s |  |
| 345 | `stage3d_sampler_partial_upload` | 0 | 3.4s |  |
| 346 | `stage3d_stencil` | 0 | 23.4s |  |
| 347 | `stage3d_texture` | 0 | 7.4s |  |
| 348 | `stage3d_texture_bytearray` | 0 | 4.2s |  |
| 349 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.8s |  |
| 350 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 4.4s |  |
| 351 | `stage3d_triangle` | 0 | 3.4s |  |
| 352 | `stage3d_triangle_bytes4` | 0 | 3.3s |  |
| 353 | `stage3d_triangle_float1` | 0 | 3.3s |  |
| 354 | `stage3d_triangle_index_upload` | 0 | 3.1s |  |
| 355 | `static_var_with_this_in_ctor` | 2 | 1.7s |  |
| 356 | `stored_properties` | 11 | 7.8s |  |
| 357 | `strict_equality` | 34 | 1.7s |  |
| 358 | `string_call` | 13 | 1.7s |  |
| 359 | `string_case` | 23 | 1.7s |  |
| 360 | `string_char_at` | 27 | 1.6s |  |
| 361 | `string_char_code_at` | 28 | 1.6s |  |
| 362 | `string_concat_fromcharcode` | 36 | 1.6s |  |
| 363 | `string_constr` | 25 | 1.6s |  |
| 364 | `string_indexof_lastindexof` | 87 | 1.7s |  |
| 365 | `string_length` | 16 | 1.6s |  |
| 366 | `string_locale_compare` | 39 | 1.8s |  |
| 367 | `string_match` | 51 | 1.8s |  |
| 368 | `string_relational_compare` | 4 | 1.6s |  |
| 369 | `string_replace` | 51 | 1.8s |  |
| 370 | `string_search` | 41 | 1.7s |  |
| 371 | `string_slice_substr_substring` | 169 | 1.9s |  |
| 372 | `string_split` | 29 | 1.7s |  |
| 373 | `string_substr_negative` | 21 | 1.6s |  |
| 374 | `string_substr_weird` | 182 | 1.6s |  |
| 375 | `subtract` | 1058 | 3.7s |  |
| 376 | `super_get_call` | 12 | 1.7s |  |
| 377 | `supercall_two_classobjects` | 2 | 1.6s |  |
| 378 | `swf8` | 1 | 1.4s |  |
| 379 | `symbol_class_root_not_zero` | 1 | 1.6s |  |
| 380 | `symbolclass_invalid_utf8` | 2 | 1.7s |  |
| 381 | `throw` | 3 | 1.7s |  |
| 382 | `truthiness` | 30 | 1.2s |  |
| 383 | `try_catch` | 11 | 1.3s |  |
| 384 | `try_catch_typed` | 12 | 1.4s |  |
| 385 | `typeof` | 30 | 1.3s |  |
| 386 | `uint_constr` | 92 | 1.3s |  |
| 387 | `uint_tofixed` | 1215 | 1.2s |  |
| 388 | `uint_tostring` | 3375 | 1.4s |  |
| 389 | `unchecked_function` | 15 | 1.3s |  |
| 390 | `urshift` | 1058 | 2.8s |  |
| 391 | `vector_class` | 36 | 1.5s |  |
| 392 | `vector_class_call` | 11 | 1.4s |  |
| 393 | `vector_coercion` | 66 | 2.0s |  |
| 394 | `vector_concat` | 90 | 1.5s |  |
| 395 | `vector_constr` | 107 | 1.5s |  |
| 396 | `vector_enumeration` | 5 | 1.5s |  |
| 397 | `vector_every` | 92 | 1.6s |  |
| 398 | `vector_filter` | 95 | 1.6s |  |
| 399 | `vector_holes` | 24 | 1.3s |  |
| 400 | `vector_indexof` | 302 | 1.9s |  |
| 401 | `vector_insertat` | 270 | 1.6s |  |
| 402 | `vector_int_access` | 4 | 1.2s |  |
| 403 | `vector_int_delete` | 11 | 1.2s |  |
| 404 | `vector_join` | 58 | 1.8s |  |
| 405 | `vector_lastindexof` | 302 | 1.2s |  |
| 406 | `vector_legacy` | 10 | 1.2s |  |
| 407 | `vector_map` | 85 | 8.2s |  |
| 408 | `vector_object_final` | 1 | 1.4s |  |
| 409 | `vector_object_toString` | 10 | 0.7s |  |
| 410 | `vector_pushpop` | 255 | 1.1s |  |
| 411 | `vector_reborrow_bug` | 10 | 0.7s |  |
| 412 | `vector_removeat` | 172 | 1.0s |  |
| 413 | `vector_reverse` | 232 | 1.0s |  |
| 414 | `vector_shiftunshift` | 252 | 0.7s |  |
| 415 | `vector_slice` | 331 | 1.1s |  |
| 416 | `vector_sort` | 905 | 2.3s |  |
| 417 | `vector_splice` | 693 | 1.5s |  |
| 418 | `vector_splice_fixed_bug_compat` | 4 | 0.7s |  |
| 419 | `vector_tostring` | 79 | 0.9s |  |
| 420 | `verify_abnormal_loop` | 1 | 0.7s |  |
| 421 | `verify_exception_targets_edge_case` | 1 | 0.8s |  |
| 422 | `verify_lookup_switch_edge_case` | 1 | 0.7s |  |
| 423 | `verify_unreachable_exception` | 2 | 0.7s |  |
| 424 | `versioned_isplaying` | 2 | 0.7s |  |
| 425 | `virtual_properties` | 16 | 0.7s |  |
| 426 | `with` | 4 | 0.7s |  |
| 427 | `xml_abstract_equality` | 36 | 0.8s |  |
| 428 | `xml_advanced` | 52 | 0.7s |  |
| 429 | `xml_appendchild` | 10 | 0.7s |  |
| 430 | `xml_as_attribute` | 9 | 0.7s |  |
| 431 | `xml_attribute` | 35 | 0.8s |  |
| 432 | `xml_attribute_name` | 40 | 0.7s |  |
| 433 | `xml_basic` | 32 | 0.9s |  |
| 434 | `xml_child` | 25 | 0.7s |  |
| 435 | `xml_childindex` | 7 | 0.7s |  |
| 436 | `xml_children` | 43 | 1.1s |  |
| 437 | `xml_class_call` | 9 | 0.7s |  |
| 438 | `xml_contains` | 197 | 7.1s |  |
| 439 | `xml_copy` | 20 | 1.7s |  |
| 440 | `xml_ctor_from_tostring` | 23 | 2.0s |  |
| 441 | `xml_delete` | 114 | 1.8s |  |
| 442 | `xml_descendants` | 83 | 1.7s |  |
| 443 | `xml_elements` | 6 | 1.6s |  |
| 444 | `xml_equals_namespace_check` | 2 | 1.6s |  |
| 445 | `xml_explicit_use_namespace` | 5 | 1.6s |  |
| 446 | `xml_getdescendants_qname` | 21 | 1.6s |  |
| 447 | `xml_has_property_via_in` | 26 | 1.6s |  |
| 448 | `xml_hasownproperty` | 6 | 1.6s |  |
| 449 | `xml_ignore_white` | 6 | 1.7s |  |
| 450 | `xml_length` | 2 | 1.6s |  |
| 451 | `xml_list_as_attribute` | 9 | 1.0s |  |
| 452 | `xml_list_concat` | 20 | 1.5s |  |
| 453 | `xml_list_enumerate` | 4 | 1.6s |  |
| 454 | `xml_methods_settings` | 3 | 1.6s |  |
| 455 | `xml_mismatched_tag` | 37 | 1.7s |  |
| 456 | `xml_namespace` | 39 | 1.7s |  |
| 457 | `xml_namespace_methods` | 245 | 1.8s |  |
| 458 | `xml_namespaced_property` | 7 | 1.7s |  |
| 459 | `xml_no_namespace` | 1 | 1.6s |  |
| 460 | `xml_nodekind` | 3 | 1.6s |  |
| 461 | `xml_normalize` | 35 | 1.8s |  |
| 462 | `xml_notification_bubbling` | 361 | 1.7s |  |
| 463 | `xml_parent` | 8 | 1.7s |  |
| 464 | `xml_set_children` | 17 | 1.5s |  |
| 465 | `xml_set_name` | 34 | 1.6s |  |
| 466 | `xml_settings` | 6 | 1.6s |  |
| 467 | `xml_simple_complex_content` | 47 | 1.7s |  |
| 468 | `xml_text` | 7 | 1.6s |  |
| 469 | `xml_tostring` | 6 | 1.6s |  |
| 470 | `xml_tostring_namespace` | 12 | 1.6s |  |
| 471 | `xml_unescaping` | 23 | 1.7s |  |
| 472 | `xml_weird_ignores` | 54 | 1.8s |  |
| 473 | `xml_wildcard` | 11 | 1.6s |  |
| 474 | `xmldocument` | 254 | 1.7s |  |
| 475 | `xmlnode` | 3540 | 1.8s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_sort_swf10_64bit` | 1 | 1 | 8.0s |  |
| 2 | `blend_transform` | 1 | 1 | 1.8s |  |
| 3 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 1.4s |  |
| 4 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.7s |  |
| 5 | `freestanding_superclass` | 3 | 4 | 1.4s |  |
| 6 | `int_toexponential` | 76 | 76 | 1.9s |  |
| 7 | `int_toprecision` | 441 | 441 | 1.9s |  |
| 8 | `slot_holes_fail` | 1 | 1 | 1.6s |  |
| 9 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.6s |  |
| 10 | `uint_toexponential` | 100 | 100 | 1.3s |  |
| 11 | `uint_toprecision` | 433 | 433 | 1.3s |  |
| 12 | `weird_superinterface_properties` | 1 | 1 | 1.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**35 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271 | 1275 | 4 |  |
| 2 | `displayobject_alpha` | 99.6% | 276 | 277 | 1 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 6 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 7 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 8 | `interactiveobject_enabled` | 88.0% | 22 | 25 | 3 |  |
| 9 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 10 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 11 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 12 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 13 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 14 | `event_valueof_tostring` | 77.8% | 14 | 18 | 4 |  |
| 15 | `eventdispatcher_dispatchevent` | 75.0% | 9 | 12 | 3 |  |
| 16 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 17 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 18 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 19 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 20 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 21 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 22 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15 | 24 | 9 |  |
| 23 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 24 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 25 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 26 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 27 | `date` | 50.0% | 15 | 30 | 15 |  |
| 28 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 29 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 30 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 31 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 32 | `place_object_same_depth_frame` | 50.0% | 1 | 2 | 1 |  |
| 33 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 34 | `subclass_superclass_linked_symbol` | 50.0% | 3 | 6 | 3 |  |
| 35 | `verification` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

**14 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_access_oob_interpreter` | exit code 1 | 1.6s |  |
| 2 | `bitmap_subclass` | exit code 1 | 2.9s |  |
| 3 | `bitmap_subclass_properties` | exit code 1 | 2.1s |  |
| 4 | `bitmapdata_copychannel` | exit code 1 (output matches) | 21.8s |  |
| 5 | `content_element_basic` | exit code 1 | 1.5s |  |
| 6 | `domain_memory` | exit code 1 | 1.6s |  |
| 7 | `goto_nested_construct_sibling` | exit code 1 | 2.1s |  |
| 8 | `graphics_bitmap_fill` | exit code 1 (output matches) | 3.1s |  |
| 9 | `method_without_body` | exit code 1 | 19.0s |  |
| 10 | `null_void_types` | exit code 1 | 1.6s |  |
| 11 | `rtqname_not_namespace` | exit code 1 | 1.7s |  |
| 12 | `stage3d_rotating_cube` | exit code 1 (output matches) | 3.7s |  |
| 13 | `supercalls_weird` | exit code 1 | 1.6s |  |
| 14 | `verify_typecheck` | exit code 1 | 0.7s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 31.7s |  |

## All Output Mismatches

**699 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271/1275 | 1275 | 1275 |  |
| 2 | `displayobject_alpha` | 99.6% | 276/277 | 277 | 277 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 6 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 7 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 8 | `interactiveobject_enabled` | 88.0% | 22/25 | 25 | 25 |  |
| 9 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 10 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 11 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 12 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 13 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 14 | `event_valueof_tostring` | 77.8% | 14/18 | 18 | 18 |  |
| 15 | `eventdispatcher_dispatchevent` | 75.0% | 9/12 | 12 | 12 |  |
| 16 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 17 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 18 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 19 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 20 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 21 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 22 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15/24 | 24 | 22 |  |
| 23 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 24 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 25 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 26 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 27 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 28 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 29 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 30 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 31 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 32 | `place_object_same_depth_frame` | 50.0% | 1/2 | 2 | 1 |  |
| 33 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 34 | `subclass_superclass_linked_symbol` | 50.0% | 3/6 | 6 | 4 |  |
| 35 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 36 | `eventdispatcher_dispatchevent_cancel` | 45.0% | 9/20 | 9 | 20 |  |
| 37 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 38 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 39 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 40 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 41 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 42 | `event_clone_error_redispatch` | 33.3% | 1/3 | 2 | 3 |  |
| 43 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 44 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 45 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 46 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 48 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 49 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 50 | `event_clone` | 30.0% | 6/20 | 6 | 20 |  |
| 51 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 52 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 53 | `error_stack_trace` | 28.9% | 13/45 | 27 | 45 |  |
| 54 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 55 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 56 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 57 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 58 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 59 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 60 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 61 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 62 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 63 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 64 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 65 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 66 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 67 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 68 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 69 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 70 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 71 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 72 | `event_clone_on_redispatch` | 20.0% | 2/10 | 8 | 10 |  |
| 73 | `event_target_getter` | 20.0% | 1/5 | 2 | 5 |  |
| 74 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 75 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 76 | `soundmixer_buffertime` | 20.0% | 1/5 | 1 | 5 |  |
| 77 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 78 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 79 | `event_isdefaultprevented` | 16.7% | 2/12 | 2 | 12 |  |
| 80 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 81 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 82 | `soundmixer_stopall` | 16.7% | 1/6 | 1 | 6 |  |
| 83 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 84 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 85 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 86 | `movieclip_gotoandstop` | 15.4% | 2/13 | 2 | 13 |  |
| 87 | `doabc_and_symbolclass_script_init_goto` | 14.3% | 1/7 | 5 | 7 |  |
| 88 | `movieclip_goto_overwrite` | 14.3% | 2/14 | 2 | 14 |  |
| 89 | `movieclip_gotoandstop_framescripts_self` | 14.3% | 1/7 | 1 | 7 |  |
| 90 | `movieclip_prev_scene` | 14.3% | 1/7 | 1 | 7 |  |
| 91 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 92 | `stage_framerate_nan` | 14.3% | 1/7 | 1 | 7 |  |
| 93 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 94 | `movieclip_goto_during_frame_script` | 13.3% | 2/15 | 2 | 15 |  |
| 95 | `movieclip_gotoandplay` | 13.3% | 2/15 | 2 | 15 |  |
| 96 | `stage_mouseenabled` | 13.3% | 2/15 | 2 | 15 |  |
| 97 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 98 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 99 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 100 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 101 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 102 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 103 | `soundchannel_stop` | 12.5% | 1/8 | 1 | 8 |  |
| 104 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 105 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 106 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 107 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 108 | `bitmapdata_embedded` | 11.1% | 1/9 | 1 | 9 |  |
| 109 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 110 | `event_target_set` | 11.1% | 1/9 | 9 | 9 |  |
| 111 | `eventdispatcher_dispatchevent_indirect` | 11.1% | 1/9 | 1 | 9 |  |
| 112 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 113 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 114 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 115 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 116 | `event_formattostring` | 9.7% | 3/31 | 3 | 31 |  |
| 117 | `construct_frame_list` | 9.1% | 2/22 | 2 | 22 |  |
| 118 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 119 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 120 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 121 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 122 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 123 | `goto_in_constructframe` | 8.3% | 1/12 | 1 | 12 |  |
| 124 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 125 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 126 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 127 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 128 | `bitmapdata_clone` | 7.7% | 1/13 | 1 | 13 |  |
| 129 | `button_nested_frame_simple` | 7.4% | 2/27 | 3 | 27 |  |
| 130 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 131 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 132 | `soundchannel_soundcomplete` | 6.2% | 1/16 | 1 | 16 |  |
| 133 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 134 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 135 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 136 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 137 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 138 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 139 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 140 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 141 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 142 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 143 | `sound_play` | 5.3% | 1/19 | 1 | 19 |  |
| 144 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 145 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 146 | `swf_9_goto_in_construct_frame` | 5.0% | 1/20 | 1 | 20 |  |
| 147 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 148 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 149 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 150 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 151 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 152 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 153 | `button_nested_frame` | 4.2% | 2/48 | 3 | 48 |  |
| 154 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 155 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 156 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 157 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 158 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 159 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 160 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 161 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 162 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 163 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 164 | `sound_embeddedprops` | 3.8% | 1/26 | 1 | 26 |  |
| 165 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 166 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 167 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 168 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 169 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 170 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 171 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 172 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 173 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 174 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 175 | `sound_valueof` | 3.0% | 1/33 | 1 | 33 |  |
| 176 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 177 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 178 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 179 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 180 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 181 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 182 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 183 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 184 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 185 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 186 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 187 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 188 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 189 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 190 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 191 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 192 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 193 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 194 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 195 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 196 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 197 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 198 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 199 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 200 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 201 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 202 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 203 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 204 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 205 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 206 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 207 | `orphan_movie_reorder` | 1.8% | 2/111 | 2 | 111 |  |
| 208 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 209 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 210 | `displayobjectcontainer_addchild_timelinepull1` | 1.7% | 1/60 | 1 | 60 |  |
| 211 | `pixelbender_sign` | 1.7% | 1/60 | 1 | 60 |  |
| 212 | `displacement_map_filter` | 1.6% | 1/61 | 1 | 61 |  |
| 213 | `displayobjectcontainer_addchild_timelinepull2` | 1.6% | 1/62 | 1 | 62 |  |
| 214 | `edittext_newline_stripping` | 1.6% | 1/64 | 1 | 64 |  |
| 215 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 216 | `displayobjectcontainer_contains` | 1.5% | 1/66 | 1 | 66 |  |
| 217 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 218 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 219 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 220 | `geom_transform` | 1.4% | 1/74 | 1 | 74 |  |
| 221 | `pixelbender_ceil` | 1.3% | 1/77 | 1 | 77 |  |
| 222 | `simplebutton_childevents` | 1.2% | 1/86 | 1 | 86 |  |
| 223 | `simplebutton_childevents_script_order` | 1.1% | 1/87 | 3 | 87 |  |
| 224 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 225 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 226 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 227 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 228 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 229 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 230 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 231 | `bounds_mode` | 0.7% | 2/269 | 2 | 269 |  |
| 232 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 233 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 234 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 235 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 236 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 237 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 238 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 239 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 240 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 241 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 242 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 243 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 244 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 245 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 246 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 247 | `soundchannel_soundtransform` | 0.1% | 1/835 | 1 | 835 |  |
| 248 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 249 | `soundmixer_soundtransform` | 0.1% | 1/900 | 1 | 900 |  |
| 250 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 251 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 252 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 253 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 254 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 255 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 256 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 257 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 258 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 259 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 261 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 262 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 263 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 264 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 265 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 266 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 267 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 268 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 269 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 270 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 271 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 272 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 273 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 274 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 275 | `all_classes/events/swf10` | 0.0% | 0/1638 | 0 | 1638 |  |
| 276 | `all_classes/events/swf11` | 0.0% | 0/1750 | 0 | 1750 |  |
| 277 | `all_classes/events/swf12` | 0.0% | 0/1814 | 0 | 1814 |  |
| 278 | `all_classes/events/swf30` | 0.0% | 0/2353 | 0 | 2353 |  |
| 279 | `all_classes/events/swf9` | 0.0% | 0/1030 | 0 | 1030 |  |
| 280 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 281 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 282 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 283 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 284 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 285 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 286 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 287 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 288 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 289 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 290 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 292 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 293 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 294 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 295 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 296 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 297 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `bitmapdata_copypixels` | 0.0% | 0/23 | 0 | 23 |  |
| 299 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 301 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 302 | `bitmapdata_draw_alpha_erase` | 0.0% | 0/8 | 0 | 8 |  |
| 303 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 304 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 305 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 306 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 307 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 308 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 309 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 310 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 311 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 312 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 313 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 314 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 315 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 316 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 317 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 319 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 320 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 321 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 322 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 323 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 324 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 325 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 326 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 327 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 328 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 329 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 330 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 331 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 332 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 333 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 334 | `dictionary_weak_keys` | 0.0% | 0/2 | 0 | 2 |  |
| 335 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 336 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 337 | `displayobject_hittestpoint_boundary` | 0.0% | 0/65 | 0 | 65 |  |
| 338 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 339 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 340 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 341 | `displayobject_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 342 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 343 | `displayobject_opaque_background` | 0.0% | 0/6 | 0 | 6 |  |
| 344 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 345 | `displayobject_scrollrect` | 0.0% | 0/33 | 0 | 33 |  |
| 346 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 347 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 348 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 349 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 350 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 351 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 352 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 353 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 354 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 355 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 356 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 357 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 358 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 359 | `edittext_autosize_height_dynamic` | 0.0% | 0/60 | 0 | 60 |  |
| 360 | `edittext_autosize_height_input` | 0.0% | 0/60 | 0 | 60 |  |
| 361 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 362 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 363 | `edittext_autosize_lazy_bounds_props` | 0.0% | 0/490 | 0 | 490 |  |
| 364 | `edittext_autosize_lazy_bounds_vs_relayout` | 0.0% | 0/106 | 0 | 106 |  |
| 365 | `edittext_bottom_scroll_v_basic` | 0.0% | 0/210 | 0 | 210 |  |
| 366 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 367 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 368 | `edittext_device_transform_layout` | 0.0% | 0/288 | 0 | 288 |  |
| 369 | `edittext_empty_text_format` | 0.0% | 0/7 | 0 | 7 |  |
| 370 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 371 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 372 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 373 | `edittext_get_char_index_at_point` | 0.0% | 0/4 | 0 | 4 |  |
| 374 | `edittext_get_line_index_at_point` | 0.0% | 0/2 | 0 | 2 |  |
| 375 | `edittext_get_line_index_of_char` | 0.0% | 0/76 | 0 | 76 |  |
| 376 | `edittext_getcharboundaries` | 0.0% | 0/172 | 0 | 172 |  |
| 377 | `edittext_getcharboundaries_culling` | 0.0% | 0/305 | 0 | 305 |  |
| 378 | `edittext_getcharboundaries_missing_embedded_font` | 0.0% | 0/7 | 0 | 7 |  |
| 379 | `edittext_getcharboundaries_missing_glyphs` | 0.0% | 0/63 | 0 | 63 |  |
| 380 | `edittext_getcharboundaries_scroll` | 0.0% | 0/85 | 0 | 85 |  |
| 381 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 382 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 383 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 384 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 385 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 386 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 387 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 388 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 389 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 390 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 391 | `edittext_line_methods` | 0.0% | 0/294 | 0 | 294 |  |
| 392 | `edittext_line_metrics` | 0.0% | 0/11 | 0 | 11 |  |
| 393 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 394 | `edittext_max_scroll_h_basic` | 0.0% | 0/475 | 0 | 475 |  |
| 395 | `edittext_max_scroll_v_basic` | 0.0% | 0/1000 | 0 | 1000 |  |
| 396 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 397 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 398 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 399 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 400 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 401 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 402 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 403 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 404 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 405 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 406 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 407 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 408 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 409 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 410 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 411 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 412 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 413 | `edittext_tab_stops` | 0.0% | 0/60 | 0 | 60 |  |
| 414 | `edittext_tag_indent` | 0.0% | 0/49 | 0 | 49 |  |
| 415 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 416 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 417 | `edittext_wordwrap_word` | 0.0% | 0/150 | 0 | 150 |  |
| 418 | `edittext_wrap_breaks` | 0.0% | 0/2375 | 0 | 2375 |  |
| 419 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 420 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 421 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 422 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 423 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 424 | `error_1034_debug_string` | 0.0% | 0/30 | 6 | 30 |  |
| 425 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 426 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 427 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 428 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 429 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 430 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 431 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 432 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 433 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 434 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 435 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 436 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 437 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 438 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 439 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 440 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 441 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 442 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 443 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 444 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 445 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 446 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 447 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 448 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 449 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 450 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 451 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 452 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 453 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 454 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 455 | `font_enumeratefonts_filter` | 0.0% | 0/4 | 0 | 4 |  |
| 456 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 457 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 458 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 459 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 460 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 461 | `goto_button_nested_framescript` | 0.0% | 0/28 | 1 | 28 |  |
| 462 | `goto_framescript_queued` | 0.0% | 0/6 | 0 | 6 |  |
| 463 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 464 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 465 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 466 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 467 | `graphics_draw_path` | 0.0% | 0/34 | 0 | 34 |  |
| 468 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 469 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 470 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 471 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 472 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 473 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 474 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 475 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 476 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 477 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 478 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 479 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 480 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 481 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 482 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 483 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 484 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 485 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 486 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 487 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 488 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 489 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 490 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 491 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 492 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 493 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 494 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 495 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 496 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 497 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 498 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 499 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 500 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 501 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 502 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 503 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 504 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 505 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 506 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 507 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 508 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 509 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 510 | `mask_reapply` | 0.0% | 0/1 | 0 | 1 |  |
| 511 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 512 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 513 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 514 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 515 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 516 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 517 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 518 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 519 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 520 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 521 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 522 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 523 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 524 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 525 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 526 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 527 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 528 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 529 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 530 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 531 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 1 | 676 |  |
| 532 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 1 | 2001 |  |
| 533 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 1 | 575 |  |
| 534 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 1 | 562 |  |
| 535 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 1 | 140 |  |
| 536 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 1 | 50 |  |
| 537 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 1 | 144 |  |
| 538 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 539 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 1 | 149 |  |
| 540 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 1 | 48 |  |
| 541 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 1 | 149 |  |
| 542 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 1 | 106 |  |
| 543 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 1 | 44 |  |
| 544 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 1 | 135 |  |
| 545 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 546 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 547 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 548 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 549 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 1 | 9 |  |
| 550 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 1 | 7 |  |
| 551 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 552 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 553 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 554 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 555 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 556 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 557 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 558 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 559 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 560 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 561 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 562 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 563 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 564 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 565 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 566 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 567 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 568 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 569 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 570 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 571 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 572 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 573 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 574 | `pixelbender_input` | 0.0% | 0/103 | 0 | 103 |  |
| 575 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 576 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 577 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 578 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 579 | `pixelbender_outputs` | 0.0% | 0/13 | 0 | 13 |  |
| 580 | `pixelbender_padding_bytes` | 0.0% | 0/22 | 0 | 22 |  |
| 581 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 0 | 512 |  |
| 582 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 583 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 584 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 585 | `pixelbender_select_kinds` | 0.0% | 0/8 | 0 | 8 |  |
| 586 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 587 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 588 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 589 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 590 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 591 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 592 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 593 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 594 | `remove_child_clear_field` | 0.0% | 0/88 | 1 | 88 |  |
| 595 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 596 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 597 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 598 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 599 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 600 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 601 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 602 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 603 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 604 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 605 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 606 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 2 | 45 |  |
| 607 | `simplebutton_childevents_multichild` | 0.0% | 0/152 | 1 | 152 |  |
| 608 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 609 | `simplebutton_childevents_sprite` | 0.0% | 0/13 | 1 | 13 |  |
| 610 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 611 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 612 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 613 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 614 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 615 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 616 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 617 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 618 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 619 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 620 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 621 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 622 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 623 | `sound_load_multiple` | 0.0% | 0/19 | 0 | 19 |  |
| 624 | `sound_rootless` | 0.0% | 0/7 | 0 | 7 |  |
| 625 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 626 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 627 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 628 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 629 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 630 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 631 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 632 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 633 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 634 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 635 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 636 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 637 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 638 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 639 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 640 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 641 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 642 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 643 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 644 | `stage_scale_factor` | 0.0% | 0/12 | 0 | 12 |  |
| 645 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 646 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 647 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 648 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 649 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 650 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 651 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 1 | 6 |  |
| 652 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 653 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 654 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 655 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 656 | `symbol_class_conflict` | 0.0% | 0/4 | 0 | 4 |  |
| 657 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 658 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 659 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 660 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 661 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 662 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 663 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 664 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 665 | `tab_ordering_stage_tab_children_remove_root` | 0.0% | 0/5 | 0 | 5 |  |
| 666 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 667 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 668 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 669 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 670 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 671 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 672 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 673 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 674 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 675 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 676 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 677 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 678 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 679 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 680 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 681 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 682 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 683 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 684 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 685 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 686 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 687 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 688 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 689 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 690 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 691 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 692 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 693 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 694 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 695 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 696 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 697 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 698 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
| 699 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
