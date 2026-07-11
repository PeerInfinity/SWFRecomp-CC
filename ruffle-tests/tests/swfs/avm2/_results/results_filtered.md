# Ruffle Test Results (Filtered)

**Date**: 2026-07-11 15:53 UTC

**Git SHA**: `241a84401c`

**Run Duration**: 83m 43s

**Filtered**: 227 tests ignored out of 1200 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 973 |
| Passing | **349** (35.9%) |
| Failing | 624 |
| Total expected lines | 124555 |
| Matching lines | 41079 (33.0%) |
| Mismatched lines | 83476 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 587 | 94.1% |
| Runtime Error | 37 | 5.9% |

## Passing Tests

**349 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.8s |  |
| 2 | `amf_custom_obj` | 26 | 0.8s |  |
| 3 | `amf_dictionary` | 9 | 0.7s |  |
| 4 | `amf_function` | 46 | 0.7s |  |
| 5 | `amf_invalid_date` | 2 | 0.7s |  |
| 6 | `amf_missing_prop` | 6 | 0.7s |  |
| 7 | `amf_nondynamic_function_prop` | 6 | 6.6s |  |
| 8 | `amf_setter_error` | 8 | 1.5s |  |
| 9 | `amf_vector` | 40 | 1.4s |  |
| 10 | `application_domain` | 4 | 1.9s |  |
| 11 | `array_access` | 18 | 1.8s |  |
| 12 | `array_access_interpreter` | 4 | 1.4s |  |
| 13 | `array_access_no_pubns` | 2 | 1.5s |  |
| 14 | `array_concat` | 41 | 1.6s |  |
| 15 | `array_constr` | 10 | 1.5s |  |
| 16 | `array_delete` | 44 | 1.6s |  |
| 17 | `array_enumeration` | 10 | 1.5s |  |
| 18 | `array_enumeration_elements` | 11 | 1.5s |  |
| 19 | `array_every` | 8 | 1.4s |  |
| 20 | `array_filter` | 6 | 1.5s |  |
| 21 | `array_foreach` | 18 | 1.6s |  |
| 22 | `array_hasownproperty` | 11 | 1.4s |  |
| 23 | `array_holes` | 9 | 1.6s |  |
| 24 | `array_index_max` | 84 | 1.6s |  |
| 25 | `array_indexof` | 25 | 1.4s |  |
| 26 | `array_join` | 26 | 1.5s |  |
| 27 | `array_lastindexof` | 29 | 1.5s |  |
| 28 | `array_length` | 14 | 1.5s |  |
| 29 | `array_literal` | 3 | 1.7s |  |
| 30 | `array_map` | 8 | 0.3s |  |
| 31 | `array_pop` | 52 | 1.5s |  |
| 32 | `array_push` | 24 | 1.4s |  |
| 33 | `array_reborrow_bug` | 6 | 1.5s |  |
| 34 | `array_reverse` | 28 | 1.4s |  |
| 35 | `array_shift` | 51 | 1.9s |  |
| 36 | `array_slice` | 39 | 1.4s |  |
| 37 | `array_some` | 8 | 1.5s |  |
| 38 | `array_sort` | 297 | 1.9s |  |
| 39 | `array_sort_fun_swf12` | 2 | 1.6s |  |
| 40 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 41 | `array_sort_random` | 210 | 1.6s |  |
| 42 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 43 | `array_sorton` | 545 | 2.0s |  |
| 44 | `array_sparse_ops` | 41 | 1.7s |  |
| 45 | `array_splice` | 133 | 1.7s |  |
| 46 | `array_splice2` | 428 | 1.9s |  |
| 47 | `array_splice_types` | 48 | 1.7s |  |
| 48 | `array_storage` | 8 | 1.6s |  |
| 49 | `array_tolocalestring` | 9 | 1.6s |  |
| 50 | `array_tostring` | 12 | 1.6s |  |
| 51 | `array_unshift` | 24 | 1.6s |  |
| 52 | `array_valueof` | 9 | 1.5s |  |
| 53 | `array_vector_null_callback` | 10 | 1.6s |  |
| 54 | `astype` | 28 | 1.6s |  |
| 55 | `astypelate` | 24 | 1.7s |  |
| 56 | `astypelate_propagates` | 1 | 1.5s |  |
| 57 | `bitand` | 1058 | 3.7s |  |
| 58 | `bitnot` | 46 | 1.7s |  |
| 59 | `bitor` | 1058 | 3.9s |  |
| 60 | `bitxor` | 1058 | 3.9s |  |
| 61 | `boolean_constr` | 32 | 1.6s |  |
| 62 | `boolean_negation` | 30 | 1.6s |  |
| 63 | `boolean_tostring` | 8 | 1.6s |  |
| 64 | `bytearray` | 48 | 1.9s |  |
| 65 | `bytearray_compress` | 31 | 1.7s |  |
| 66 | `bytearray_errors` | 24 | 1.7s |  |
| 67 | `bytearray_method_serialization` | 1 | 1.6s |  |
| 68 | `bytearray_readobject_amf0` | 50 | 0.7s |  |
| 69 | `bytearray_readobject_amf3` | 53 | 1.6s |  |
| 70 | `bytearray_readutf8bytes_with_bom` | 16 | 1.6s |  |
| 71 | `bytearray_serialization` | 3 | 1.6s |  |
| 72 | `bytearray_string_null` | 19 | 1.9s |  |
| 73 | `bytearray_tostring` | 15 | 1.7s |  |
| 74 | `bytearray_utf16` | 8 | 1.6s |  |
| 75 | `bytearray_writeobject` | 24 | 0.6s |  |
| 76 | `callee_in_initializer` | 6 | 1.6s |  |
| 77 | `callproplex_class` | 1 | 1.6s |  |
| 78 | `catch_class` | 6 | 1.6s |  |
| 79 | `catch_scope_slot` | 7 | 1.7s |  |
| 80 | `class_call` | 32 | 1.7s |  |
| 81 | `class_cast_call` | 14 | 1.6s |  |
| 82 | `class_enumeration` | 4 | 1.6s |  |
| 83 | `class_has_own_property` | 2 | 1.6s |  |
| 84 | `class_init_interpreter_mode` | 1 | 1.5s |  |
| 85 | `class_is` | 32 | 1.7s |  |
| 86 | `class_methods` | 5 | 1.6s |  |
| 87 | `class_object_properties` | 10 | 6.4s |  |
| 88 | `class_singleton` | 18 | 1.7s |  |
| 89 | `class_supercalls_errors` | 35 | 1.9s |  |
| 90 | `class_supercalls_mismatched` | 26 | 1.8s |  |
| 91 | `class_superclass_wrong_order` | 1 | 1.6s |  |
| 92 | `class_to_locale_string` | 2 | 1.7s |  |
| 93 | `class_to_string` | 2 | 1.6s |  |
| 94 | `class_value_of` | 2 | 1.6s |  |
| 95 | `closures` | 12 | 1.7s |  |
| 96 | `coerce_property` | 33 | 1.7s |  |
| 97 | `coerce_return_type` | 40 | 1.7s |  |
| 98 | `coerce_return_type_fail` | 2 | 1.6s |  |
| 99 | `coerce_return_void` | 3 | 1.6s |  |
| 100 | `coerce_string` | 86 | 1.7s |  |
| 101 | `coerce_string_precision` | 28 | 1.6s |  |
| 102 | `coerce_to_primitive_side_effects` | 29 | 1.7s |  |
| 103 | `construct_errors_swf10` | 8 | 1.7s |  |
| 104 | `constructor_call` | 3 | 1.7s |  |
| 105 | `constructprop_dynamic_primitive` | 7 | 1.7s |  |
| 106 | `control_flow_bool` | 4 | 1.6s |  |
| 107 | `control_flow_stricteq` | 8 | 1.7s |  |
| 108 | `convert_boolean` | 30 | 1.7s |  |
| 109 | `convert_integer` | 90 | 1.7s |  |
| 110 | `convert_number` | 56 | 1.7s |  |
| 111 | `convert_uinteger` | 90 | 1.8s |  |
| 112 | `declocal` | 46 | 1.7s |  |
| 113 | `declocal_i` | 46 | 1.6s |  |
| 114 | `decrement` | 46 | 1.6s |  |
| 115 | `decrement_i` | 46 | 1.7s |  |
| 116 | `default_values` | 7 | 1.6s |  |
| 117 | `dictionary_access` | 62 | 1.8s |  |
| 118 | `dictionary_access_no_pubns` | 2 | 1.6s |  |
| 119 | `dictionary_delete` | 101 | 1.8s |  |
| 120 | `dictionary_foreach` | 42 | 1.7s |  |
| 121 | `dictionary_hasownproperty` | 63 | 1.8s |  |
| 122 | `dictionary_in` | 62 | 1.7s |  |
| 123 | `dictionary_iter_modify` | 8 | 1.6s |  |
| 124 | `dictionary_namespaces` | 36 | 1.7s |  |
| 125 | `dictionary_primitive_keys` | 29 | 1.6s |  |
| 126 | `displayobject_mask_self_referential` | 0 | 1.7s |  |
| 127 | `divide` | 1058 | 3.9s |  |
| 128 | `duplicate_defs` | 1 | 0.5s |  |
| 129 | `eager_init` | 1 | 1.7s |  |
| 130 | `equals` | 512 | 2.4s |  |
| 131 | `error_prototype` | 15 | 1.4s |  |
| 132 | `error_tostring` | 29 | 1.4s |  |
| 133 | `es3_inheritance` | 31 | 1.5s |  |
| 134 | `es4_inheritance` | 30 | 1.5s |  |
| 135 | `es4_interfaces` | 30 | 1.5s |  |
| 136 | `es4_method_binding` | 8 | 1.4s |  |
| 137 | `es4_oop_prototypes` | 14 | 1.6s |  |
| 138 | `es4_protected_inheritance` | 6 | 1.4s |  |
| 139 | `event_bubbles` | 2 | 1.4s |  |
| 140 | `event_cancelable` | 2 | 6.4s |  |
| 141 | `event_type` | 1 | 1.7s |  |
| 142 | `eventdispatcher_dispatchevent_this` | 5 | 1.6s |  |
| 143 | `eventdispatcher_haseventlistener` | 25 | 1.7s |  |
| 144 | `falsiness` | 30 | 1.8s |  |
| 145 | `fast_index_access` | 12 | 1.8s |  |
| 146 | `finddef` | 3 | 1.8s |  |
| 147 | `findprop_global_prototype` | 6 | 1.8s |  |
| 148 | `function_call` | 12 | 1.7s |  |
| 149 | `function_call_arguments` | 46 | 1.7s |  |
| 150 | `function_call_arguments_enumerate` | 5 | 1.6s |  |
| 151 | `function_call_coercion` | 108 | 1.8s |  |
| 152 | `function_call_default` | 6 | 1.6s |  |
| 153 | `function_call_rest` | 22 | 1.6s |  |
| 154 | `function_call_types` | 3 | 1.7s |  |
| 155 | `function_call_via_apply` | 11 | 1.7s |  |
| 156 | `function_call_via_call` | 3 | 1.7s |  |
| 157 | `function_display_anonymous` | 7 | 1.6s |  |
| 158 | `function_length` | 6 | 1.6s |  |
| 159 | `function_object` | 2 | 1.6s |  |
| 160 | `function_proto` | 5 | 6.2s |  |
| 161 | `function_to_locale_string` | 4 | 1.6s |  |
| 162 | `function_to_string` | 4 | 1.6s |  |
| 163 | `function_type` | 6 | 1.6s |  |
| 164 | `function_unbound_this` | 51 | 1.7s |  |
| 165 | `function_value_of` | 4 | 1.6s |  |
| 166 | `get_definition_by_name` | 11 | 1.7s |  |
| 167 | `get_qualified_class_name` | 20 | 1.7s |  |
| 168 | `get_slot_edge_cases` | 1 | 1.6s |  |
| 169 | `getglobalslot` | 1 | 1.6s |  |
| 170 | `getouterscope` | 8 | 1.7s |  |
| 171 | `getter_different_namespace_setter` | 2 | 1.7s |  |
| 172 | `graphics_round_rects` | 0 | 1.7s |  |
| 173 | `greaterequals` | 512 | 2.8s |  |
| 174 | `greaterthan` | 512 | 2.7s |  |
| 175 | `has_own_property` | 102 | 1.9s |  |
| 176 | `hasownproperty_namespaces` | 2 | 1.6s |  |
| 177 | `hello_world` | 1 | 1.6s |  |
| 178 | `if_eq` | 10 | 1.7s |  |
| 179 | `if_gt` | 1 | 1.7s |  |
| 180 | `if_gte` | 10 | 1.7s |  |
| 181 | `if_lt` | 1 | 0.4s |  |
| 182 | `if_lte` | 10 | 0.4s |  |
| 183 | `if_ne` | 7 | 1.7s |  |
| 184 | `if_stricteq` | 6 | 1.7s |  |
| 185 | `if_strictne` | 11 | 1.7s |  |
| 186 | `in` | 102 | 1.9s |  |
| 187 | `inclocal` | 46 | 1.8s |  |
| 188 | `inclocal_i` | 46 | 1.7s |  |
| 189 | `increment` | 46 | 1.7s |  |
| 190 | `increment_i` | 46 | 1.7s |  |
| 191 | `instanceof` | 58 | 1.9s |  |
| 192 | `int_constr` | 92 | 1.8s |  |
| 193 | `int_edge_cases` | 19 | 1.7s |  |
| 194 | `int_instanceof` | 3 | 1.6s |  |
| 195 | `int_tofixed` | 1215 | 1.6s |  |
| 196 | `int_tostring` | 3375 | 1.9s |  |
| 197 | `interface_namespaces` | 78 | 1.8s |  |
| 198 | `is_finite` | 46 | 1.7s |  |
| 199 | `is_nan` | 46 | 1.6s |  |
| 200 | `is_prototype_of` | 12 | 1.7s |  |
| 201 | `issue_10221` | 2 | 6.4s |  |
| 202 | `issue_14901` | 1 | 1.7s |  |
| 203 | `istype` | 24 | 1.8s |  |
| 204 | `istypelate` | 58 | 1.8s |  |
| 205 | `istypelate_coerce` | 198 | 2.0s |  |
| 206 | `json_errors` | 9 | 19.7s |  |
| 207 | `json_parse` | 21 | 1.7s |  |
| 208 | `json_version_gated` | 1 | 1.6s |  |
| 209 | `lazyinit` | 17 | 1.7s |  |
| 210 | `lessequals` | 512 | 2.6s |  |
| 211 | `lessthan` | 512 | 2.5s |  |
| 212 | `lshift` | 1058 | 3.6s |  |
| 213 | `math` | 497 | 1.8s |  |
| 214 | `modulo` | 1058 | 3.8s |  |
| 215 | `movieclip_stop` | 1 | 20.0s |  |
| 216 | `multiply` | 1058 | 3.8s |  |
| 217 | `namespace_constr` | 253 | 2.0s |  |
| 218 | `namespace_constr_args` | 1 | 1.5s |  |
| 219 | `namespace_enumeration_order` | 7 | 1.6s |  |
| 220 | `negate` | 30 | 1.6s |  |
| 221 | `negative_volume_panned` | 0 | 1.7s |  |
| 222 | `nested_iteration` | 11 | 1.7s |  |
| 223 | `net_getClassByAlias` | 3 | 6.4s |  |
| 224 | `newactivation_in_script_init` | 3 | 1.6s |  |
| 225 | `newclass_twice` | 3 | 1.6s |  |
| 226 | `nonconflicting_declarations` | 0 | 1.7s |  |
| 227 | `number_autoconv_amf` | 132 | 1.7s |  |
| 228 | `number_autoconv_array_sort_32bit` | 1 | 1.6s |  |
| 229 | `number_constr` | 58 | 1.7s |  |
| 230 | `number_toexponential` | 378 | 1.7s |  |
| 231 | `number_toexponential2` | 35 | 1.6s |  |
| 232 | `number_tofixed` | 378 | 1.6s |  |
| 233 | `number_toprecision` | 350 | 1.7s |  |
| 234 | `obfuscated_class_names` | 3 | 1.6s |  |
| 235 | `object_enumeration` | 10 | 1.6s |  |
| 236 | `object_prototype` | 4 | 1.7s |  |
| 237 | `object_to_locale_string` | 2 | 1.6s |  |
| 238 | `object_to_string` | 2 | 1.6s |  |
| 239 | `object_value_of` | 2 | 1.5s |  |
| 240 | `op_coerce` | 54 | 1.1s |  |
| 241 | `op_coerce_x` | 54 | 1.7s |  |
| 242 | `op_escxattr` | 2 | 1.7s |  |
| 243 | `op_escxelem` | 2 | 1.6s |  |
| 244 | `op_lookupswitch` | 4 | 1.7s |  |
| 245 | `optimize_coerce` | 1 | 1.6s |  |
| 246 | `param_default_value_has_zero_cpool_index` | 1 | 1.5s |  |
| 247 | `parse_float` | 80 | 1.7s |  |
| 248 | `primitive_edge_cases` | 1 | 1.6s |  |
| 249 | `property_priority` | 22 | 2.0s |  |
| 250 | `property_priority_three_level` | 6 | 1.8s |  |
| 251 | `propertyisenumerable_namespaces` | 6 | 1.7s |  |
| 252 | `prototype_set_null` | 7 | 1.6s |  |
| 253 | `proxy_callproperty` | 24 | 1.7s |  |
| 254 | `proxy_deleteproperty` | 64 | 1.8s |  |
| 255 | `proxy_enumeration` | 34 | 1.7s |  |
| 256 | `proxy_getproperty` | 77 | 1.8s |  |
| 257 | `proxy_hasownproperty` | 8 | 1.7s |  |
| 258 | `proxy_hasproperty` | 32 | 1.8s |  |
| 259 | `proxy_serialize` | 9 | 1.7s |  |
| 260 | `proxy_setproperty` | 42 | 1.8s |  |
| 261 | `qname_constr` | 32 | 1.8s |  |
| 262 | `qname_constr_namespace` | 24 | 1.8s |  |
| 263 | `qname_enumeration` | 9 | 1.8s |  |
| 264 | `qname_indexing` | 23 | 1.9s |  |
| 265 | `qname_tostring` | 25 | 1.8s |  |
| 266 | `qname_valueof` | 29 | 1.8s |  |
| 267 | `regexp_constr` | 148 | 2.0s |  |
| 268 | `regexp_exec` | 19 | 1.8s |  |
| 269 | `regexp_extended` | 47 | 1.8s |  |
| 270 | `regexp_multiargs` | 1 | 6.2s |  |
| 271 | `regexp_test` | 27 | 1.7s |  |
| 272 | `regexp_toString` | 10 | 1.6s |  |
| 273 | `resolve_order` | 4 | 1.6s |  |
| 274 | `rng` | 1 | 3.0s |  |
| 275 | `rshift` | 1058 | 3.8s |  |
| 276 | `set_property_is_enumerable` | 85 | 1.8s |  |
| 277 | `slot_disp_id_shared_numbering` | 1 | 19.6s |  |
| 278 | `slots_force_autoassigned` | 1 | 1.6s |  |
| 279 | `static_var_with_this_in_ctor` | 2 | 1.6s |  |
| 280 | `stored_properties` | 11 | 1.6s |  |
| 281 | `strict_equality` | 34 | 1.6s |  |
| 282 | `string_call` | 13 | 1.6s |  |
| 283 | `string_case` | 23 | 1.7s |  |
| 284 | `string_char_at` | 27 | 1.6s |  |
| 285 | `string_char_code_at` | 28 | 1.5s |  |
| 286 | `string_concat_fromcharcode` | 36 | 1.6s |  |
| 287 | `string_constr` | 25 | 1.6s |  |
| 288 | `string_indexof_lastindexof` | 87 | 1.7s |  |
| 289 | `string_length` | 16 | 1.6s |  |
| 290 | `string_locale_compare` | 39 | 1.7s |  |
| 291 | `string_match` | 51 | 1.7s |  |
| 292 | `string_replace` | 51 | 1.7s |  |
| 293 | `string_search` | 41 | 1.7s |  |
| 294 | `string_slice_substr_substring` | 169 | 1.9s |  |
| 295 | `string_split` | 29 | 1.6s |  |
| 296 | `string_substr_negative` | 21 | 1.5s |  |
| 297 | `string_substr_weird` | 182 | 1.6s |  |
| 298 | `subtract` | 1058 | 3.6s |  |
| 299 | `super_get_call` | 12 | 1.6s |  |
| 300 | `supercall_two_classobjects` | 2 | 1.6s |  |
| 301 | `swf8` | 1 | 1.3s |  |
| 302 | `symbol_class_root_not_zero` | 1 | 1.6s |  |
| 303 | `symbolclass_invalid_utf8` | 2 | 1.6s |  |
| 304 | `throw` | 3 | 1.6s |  |
| 305 | `truthiness` | 30 | 1.6s |  |
| 306 | `try_catch` | 11 | 1.7s |  |
| 307 | `try_catch_typed` | 12 | 1.7s |  |
| 308 | `typeof` | 30 | 1.6s |  |
| 309 | `uint_constr` | 92 | 1.7s |  |
| 310 | `uint_tofixed` | 1215 | 1.5s |  |
| 311 | `uint_tostring` | 3375 | 1.8s |  |
| 312 | `unchecked_function` | 15 | 1.6s |  |
| 313 | `urshift` | 1058 | 3.7s |  |
| 314 | `vector_class` | 36 | 1.9s |  |
| 315 | `vector_class_call` | 11 | 1.8s |  |
| 316 | `vector_coercion` | 66 | 2.2s |  |
| 317 | `vector_concat` | 90 | 1.9s |  |
| 318 | `vector_constr` | 107 | 1.8s |  |
| 319 | `vector_enumeration` | 5 | 1.6s |  |
| 320 | `vector_every` | 92 | 2.0s |  |
| 321 | `vector_filter` | 95 | 2.0s |  |
| 322 | `vector_holes` | 24 | 1.7s |  |
| 323 | `vector_indexof` | 302 | 2.5s |  |
| 324 | `vector_insertat` | 270 | 2.0s |  |
| 325 | `vector_int_access` | 4 | 1.6s |  |
| 326 | `vector_int_delete` | 11 | 1.6s |  |
| 327 | `vector_join` | 58 | 1.8s |  |
| 328 | `vector_lastindexof` | 302 | 1.5s |  |
| 329 | `vector_legacy` | 10 | 1.6s |  |
| 330 | `vector_map` | 85 | 7.4s |  |
| 331 | `vector_object_final` | 1 | 1.4s |  |
| 332 | `vector_object_toString` | 10 | 0.7s |  |
| 333 | `vector_pushpop` | 255 | 1.1s |  |
| 334 | `vector_reborrow_bug` | 10 | 0.6s |  |
| 335 | `vector_removeat` | 172 | 1.0s |  |
| 336 | `vector_reverse` | 232 | 1.0s |  |
| 337 | `vector_shiftunshift` | 252 | 0.6s |  |
| 338 | `vector_slice` | 331 | 1.2s |  |
| 339 | `vector_sort` | 905 | 2.5s |  |
| 340 | `vector_splice` | 693 | 1.5s |  |
| 341 | `vector_splice_fixed_bug_compat` | 4 | 0.7s |  |
| 342 | `vector_tostring` | 79 | 0.9s |  |
| 343 | `verify_abnormal_loop` | 1 | 0.6s |  |
| 344 | `verify_exception_targets_edge_case` | 1 | 0.6s |  |
| 345 | `verify_lookup_switch_edge_case` | 1 | 0.6s |  |
| 346 | `verify_unreachable_exception` | 2 | 0.6s |  |
| 347 | `versioned_isplaying` | 2 | 0.6s |  |
| 348 | `virtual_properties` | 16 | 0.7s |  |
| 349 | `with` | 4 | 0.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**36 tests** within reach

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
| 10 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 11 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 12 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 13 | `event_valueof_tostring` | 77.8% | 14 | 18 | 4 |  |
| 14 | `eventdispatcher_dispatchevent` | 75.0% | 9 | 12 | 3 |  |
| 15 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 16 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 17 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 18 | `number_autoconv` | 71.4% | 15 | 21 | 6 |  |
| 19 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 20 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 21 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 22 | `xml_hasownproperty` | 66.7% | 4 | 6 | 2 |  |
| 23 | `xml_contains` | 66.5% | 131 | 197 | 66 |  |
| 24 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15 | 24 | 9 |  |
| 25 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 26 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 27 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 28 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 29 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 30 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 31 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 32 | `place_object_same_depth_frame` | 50.0% | 1 | 2 | 1 |  |
| 33 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 34 | `subclass_superclass_linked_symbol` | 50.0% | 3 | 6 | 3 |  |
| 35 | `verification` | 50.0% | 4 | 8 | 4 |  |
| 36 | `xml_equals_namespace_check` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**37 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bitmap_subclass` | exit code 1 | 2.7s |  |
| 2 | `checkfilter` | exit code 1 | 1.6s |  |
| 3 | `content_element_basic` | exit code 1 | 1.9s |  |
| 4 | `core_exceptions` | exit code 1 | 2.3s |  |
| 5 | `doabc_is_eager` | exit code 1 | 19.7s |  |
| 6 | `domain_memory` | exit code 1 | 1.8s |  |
| 7 | `edittext_at_point_methods_basic` | exit code 1 | 3.0s |  |
| 8 | `edittext_autosize_height_input` | exit code 1 | 2.0s |  |
| 9 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 3.2s |  |
| 10 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 2.0s |  |
| 11 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.9s |  |
| 12 | `edittext_empty_text_format` | exit code 1 | 1.9s |  |
| 13 | `edittext_get_line_index_of_char` | exit code 1 | 3.0s |  |
| 14 | `edittext_getcharboundaries` | exit code 1 | 2.1s |  |
| 15 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.9s |  |
| 16 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.9s |  |
| 17 | `edittext_line_methods` | exit code 1 | 2.9s |  |
| 18 | `edittext_line_metrics` | exit code 1 | 23.1s |  |
| 19 | `edittext_max_scroll_h_basic` | exit code 1 | 1.9s |  |
| 20 | `edittext_max_scroll_v_basic` | exit code 1 | 1.9s |  |
| 21 | `edittext_mouse_selection` | exit code 1 | 22.6s |  |
| 22 | `edittext_wordwrap_word` | exit code 1 | 1.7s |  |
| 23 | `edittext_wrap_breaks` | exit code 1 | 1.8s |  |
| 24 | `font_enumeratefonts_filter` | exit code 1 | 2.2s |  |
| 25 | `font_enumeratefonts_order` | exit code 1 | 2.4s |  |
| 26 | `goto_nested_construct_sibling` | exit code 1 | 2.1s |  |
| 27 | `method_without_body` | exit code 1 | 19.3s |  |
| 28 | `mouse_wheel_events` | exit code 1 | 22.0s |  |
| 29 | `property_priority_scope_cache_order` | exit code 1 | 20.0s |  |
| 30 | `qname_as_lazy_name_attribute_multiname` | exit code 1 | 1.7s |  |
| 31 | `rtqname_not_namespace` | exit code 1 | 1.6s |  |
| 32 | `supercalls_weird` | exit code 1 | 1.5s |  |
| 33 | `textline_splitting_basic` | exit code 1 | 1.9s |  |
| 34 | `verify_typecheck` | exit code 1 | 0.7s |  |
| 35 | `xml_descendants` | exit code 1 | 1.7s |  |
| 36 | `xml_explicit_use_namespace` | exit code 1 | 1.7s |  |
| 37 | `xml_getdescendants_qname` | exit code 1 | 1.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**587 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 11 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 12 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 13 | `event_valueof_tostring` | 77.8% | 14/18 | 18 | 18 |  |
| 14 | `eventdispatcher_dispatchevent` | 75.0% | 9/12 | 12 | 12 |  |
| 15 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 16 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 17 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 18 | `number_autoconv` | 71.4% | 15/21 | 16 | 21 |  |
| 19 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 20 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 21 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 22 | `xml_hasownproperty` | 66.7% | 4/6 | 6 | 6 |  |
| 23 | `xml_contains` | 66.5% | 131/197 | 197 | 197 |  |
| 24 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15/24 | 24 | 22 |  |
| 25 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 26 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 27 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 28 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 29 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 30 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 31 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 32 | `place_object_same_depth_frame` | 50.0% | 1/2 | 2 | 1 |  |
| 33 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 34 | `subclass_superclass_linked_symbol` | 50.0% | 3/6 | 6 | 4 |  |
| 35 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 36 | `xml_equals_namespace_check` | 50.0% | 1/2 | 2 | 2 |  |
| 37 | `xml_mismatched_tag` | 45.9% | 17/37 | 34 | 37 |  |
| 38 | `eventdispatcher_dispatchevent_cancel` | 45.0% | 9/20 | 9 | 20 |  |
| 39 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 40 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 41 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 42 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 43 | `amf_xml` | 33.3% | 2/6 | 6 | 6 |  |
| 44 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 45 | `event_clone_error_redispatch` | 33.3% | 1/3 | 2 | 3 |  |
| 46 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 48 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 49 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 50 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 51 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 52 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 53 | `function_proto_created` | 31.1% | 19/61 | 19 | 61 |  |
| 54 | `event_clone` | 30.0% | 6/20 | 6 | 20 |  |
| 55 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 56 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 57 | `error_stack_trace` | 28.9% | 13/45 | 27 | 45 |  |
| 58 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 59 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 60 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 61 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 62 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 63 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 64 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 65 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 66 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 67 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 68 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 69 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 70 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 71 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 72 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 73 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 74 | `event_clone_on_redispatch` | 20.0% | 2/10 | 8 | 10 |  |
| 75 | `event_target_getter` | 20.0% | 1/5 | 2 | 5 |  |
| 76 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 77 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 78 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 79 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 80 | `event_isdefaultprevented` | 16.7% | 2/12 | 2 | 12 |  |
| 81 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 82 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 83 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 84 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 85 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 86 | `movieclip_gotoandstop` | 15.4% | 2/13 | 2 | 13 |  |
| 87 | `doabc_and_symbolclass_script_init_goto` | 14.3% | 1/7 | 5 | 7 |  |
| 88 | `movieclip_goto_overwrite` | 14.3% | 2/14 | 2 | 14 |  |
| 89 | `movieclip_gotoandstop_framescripts_self` | 14.3% | 1/7 | 1 | 7 |  |
| 90 | `movieclip_prev_scene` | 14.3% | 1/7 | 1 | 7 |  |
| 91 | `stage_framerate_nan` | 14.3% | 1/7 | 1 | 7 |  |
| 92 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 93 | `movieclip_goto_during_frame_script` | 13.3% | 2/15 | 2 | 15 |  |
| 94 | `movieclip_gotoandplay` | 13.3% | 2/15 | 2 | 15 |  |
| 95 | `stage_mouseenabled` | 13.3% | 2/15 | 2 | 15 |  |
| 96 | `xml_ctor_from_tostring` | 13.0% | 3/23 | 5 | 23 |  |
| 97 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 98 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 99 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 100 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 101 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 102 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 103 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 104 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 105 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 106 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 107 | `event_target_set` | 11.1% | 1/9 | 9 | 9 |  |
| 108 | `eventdispatcher_dispatchevent_indirect` | 11.1% | 1/9 | 1 | 9 |  |
| 109 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 110 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 111 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 112 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 113 | `event_formattostring` | 9.7% | 3/31 | 3 | 31 |  |
| 114 | `construct_frame_list` | 9.1% | 2/22 | 2 | 22 |  |
| 115 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 116 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 117 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 118 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 119 | `goto_in_constructframe` | 8.3% | 1/12 | 1 | 12 |  |
| 120 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 121 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 122 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 123 | `xml_tostring_namespace` | 8.3% | 1/12 | 1 | 12 |  |
| 124 | `button_nested_frame_simple` | 7.4% | 2/27 | 3 | 27 |  |
| 125 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 126 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 127 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 128 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 129 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 130 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 131 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 132 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 133 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 134 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 135 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 136 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 137 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 138 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 139 | `xml_list_concat` | 5.0% | 1/20 | 1 | 20 |  |
| 140 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 141 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 142 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 143 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 144 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 145 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 146 | `button_nested_frame` | 4.2% | 2/48 | 3 | 48 |  |
| 147 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 148 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 149 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 150 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 151 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 152 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 153 | `static_length` | 4.2% | 1/24 | 24 | 24 |  |
| 154 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 155 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 156 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 157 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 158 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 159 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 160 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 161 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 162 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 163 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 164 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 165 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 166 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 167 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 168 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 169 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 170 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 171 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 172 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 173 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 174 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 175 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 176 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 177 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 178 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 179 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 180 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 181 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 182 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 183 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 184 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 185 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 186 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 187 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 188 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 189 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 190 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 191 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 192 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 193 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 194 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 195 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 196 | `orphan_movie_reorder` | 1.8% | 2/111 | 2 | 111 |  |
| 197 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 198 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 199 | `displayobjectcontainer_addchild_timelinepull1` | 1.7% | 1/60 | 1 | 60 |  |
| 200 | `flash_xml_removeNode` | 1.7% | 1/60 | 1 | 60 |  |
| 201 | `displacement_map_filter` | 1.6% | 1/61 | 1 | 61 |  |
| 202 | `displayobjectcontainer_addchild_timelinepull2` | 1.6% | 1/62 | 1 | 62 |  |
| 203 | `edittext_newline_stripping` | 1.6% | 1/64 | 1 | 64 |  |
| 204 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 205 | `displayobjectcontainer_contains` | 1.5% | 1/66 | 1 | 66 |  |
| 206 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 207 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 208 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 209 | `simplebutton_childevents` | 1.2% | 1/86 | 1 | 86 |  |
| 210 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 211 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 212 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 213 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 214 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 215 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 216 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 217 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 218 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 219 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 220 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 221 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 222 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 223 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 224 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 225 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 226 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 227 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 228 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 229 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 230 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 231 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 232 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 233 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 234 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 235 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 236 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 237 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 238 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 239 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 240 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 241 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 242 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 243 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 244 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 245 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 246 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 247 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 248 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 249 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 250 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 251 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 252 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 253 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 254 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 255 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 256 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 257 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 258 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 259 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 260 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 261 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 262 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 263 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 265 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 266 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 267 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 268 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 269 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 270 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 271 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 272 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 273 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 274 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 275 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 276 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 277 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 278 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 279 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 280 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 281 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 282 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 283 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 284 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 285 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 286 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 287 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 288 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 289 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 290 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 291 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 292 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 293 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 294 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 295 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 296 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 297 | `describe_type_basic` | 0.0% | 0/152 | 0 | 152 |  |
| 298 | `describe_type_json` | 0.0% | 0/301 | 0 | 301 |  |
| 299 | `describe_type_metadata` | 0.0% | 0/125 | 0 | 125 |  |
| 300 | `describe_type_native` | 0.0% | 0/23 | 0 | 23 |  |
| 301 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 302 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 304 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 305 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 306 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 307 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 308 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 309 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 310 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 311 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 313 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 315 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 316 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 317 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 318 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 319 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 320 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 321 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 322 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 323 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 324 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 325 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 326 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 327 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 328 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 329 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 330 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 331 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 332 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 333 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 334 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 335 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 336 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 337 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 338 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 339 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 340 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 341 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 342 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 343 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 344 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 345 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 346 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 347 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 348 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 349 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 350 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 351 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 352 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 353 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 354 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 355 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 356 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 357 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 358 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 360 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 361 | `error_1034_debug_string` | 0.0% | 0/30 | 6 | 30 |  |
| 362 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 363 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 364 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 365 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 366 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 367 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 368 | `flash_xml` | 0.0% | 0/29 | 0 | 29 |  |
| 369 | `flash_xml_cloneNode` | 0.0% | 0/22 | 0 | 22 |  |
| 370 | `flash_xml_namespace` | 0.0% | 0/109 | 0 | 109 |  |
| 371 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 372 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 373 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 374 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 375 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 376 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 377 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 378 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 379 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 380 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 381 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 382 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 383 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 384 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 385 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 386 | `goto_button_nested_framescript` | 0.0% | 0/28 | 1 | 28 |  |
| 387 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 388 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 389 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 390 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 391 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 392 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 393 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 394 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 395 | `issue_13780` | 0.0% | 0/12 | 0 | 12 |  |
| 396 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 397 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 398 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 399 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 400 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 401 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 402 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 403 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 404 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 405 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 406 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 407 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 408 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 409 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 410 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 411 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 412 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 413 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 414 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 415 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 416 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 417 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 418 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 419 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 420 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 421 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 422 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 423 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 424 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 425 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 426 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 427 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 428 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 429 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 430 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 431 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 432 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 433 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 434 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 435 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 436 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 437 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 438 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 439 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 440 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 441 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 1 | 676 |  |
| 442 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 1 | 2001 |  |
| 443 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 1 | 575 |  |
| 444 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 1 | 562 |  |
| 445 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 1 | 140 |  |
| 446 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 1 | 50 |  |
| 447 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 1 | 144 |  |
| 448 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 449 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 1 | 149 |  |
| 450 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 1 | 48 |  |
| 451 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 1 | 149 |  |
| 452 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 1 | 106 |  |
| 453 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 1 | 44 |  |
| 454 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 1 | 135 |  |
| 455 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 456 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 457 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 458 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 459 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 1 | 9 |  |
| 460 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 1 | 7 |  |
| 461 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 462 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 463 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 464 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 465 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 466 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 467 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 468 | `null_void_types` | 0.0% | 0/8 | 0 | 8 |  |
| 469 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 470 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 471 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 472 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 473 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 474 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 475 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 476 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 477 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 478 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 479 | `remove_child_clear_field` | 0.0% | 0/88 | 1 | 88 |  |
| 480 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 481 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 482 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 483 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 484 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 485 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 486 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 487 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 488 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 489 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 490 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 2 | 45 |  |
| 491 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 492 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 493 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 494 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 495 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 496 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 497 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 498 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 499 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 500 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 501 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 502 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 503 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 504 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 505 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 506 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 507 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 508 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 509 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 1 | 6 |  |
| 510 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 511 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 512 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 513 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 514 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 515 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 516 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 517 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 518 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 519 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 520 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 521 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 522 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 523 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 524 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 525 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 526 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 527 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 528 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 529 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 530 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 531 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 532 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 533 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 534 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 535 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 536 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 537 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 538 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 539 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 540 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 541 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 542 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 543 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 544 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 545 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 546 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 547 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 548 | `xml_abstract_equality` | 0.0% | 0/36 | 0 | 36 |  |
| 549 | `xml_advanced` | 0.0% | 0/52 | 13 | 52 |  |
| 550 | `xml_appendchild` | 0.0% | 0/10 | 1 | 10 |  |
| 551 | `xml_appendchild_swf_v21` | 0.0% | 0/13 | 0 | 13 |  |
| 552 | `xml_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 553 | `xml_attribute` | 0.0% | 0/35 | 0 | 35 |  |
| 554 | `xml_attribute_name` | 0.0% | 0/40 | 0 | 40 |  |
| 555 | `xml_basic` | 0.0% | 0/32 | 0 | 32 |  |
| 556 | `xml_child` | 0.0% | 0/25 | 0 | 25 |  |
| 557 | `xml_childindex` | 0.0% | 0/7 | 0 | 7 |  |
| 558 | `xml_children` | 0.0% | 0/43 | 0 | 43 |  |
| 559 | `xml_class_call` | 0.0% | 0/9 | 0 | 9 |  |
| 560 | `xml_copy` | 0.0% | 0/20 | 0 | 20 |  |
| 561 | `xml_delete` | 0.0% | 0/114 | 0 | 114 |  |
| 562 | `xml_elements` | 0.0% | 0/6 | 0 | 6 |  |
| 563 | `xml_ignore_white` | 0.0% | 0/6 | 2 | 6 |  |
| 564 | `xml_length` | 0.0% | 0/2 | 0 | 2 |  |
| 565 | `xml_list_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 566 | `xml_list_enumerate` | 0.0% | 0/4 | 2 | 4 |  |
| 567 | `xml_methods_settings` | 0.0% | 0/3 | 3 | 3 |  |
| 568 | `xml_namespace` | 0.0% | 0/39 | 0 | 39 |  |
| 569 | `xml_namespace_methods` | 0.0% | 0/245 | 0 | 245 |  |
| 570 | `xml_namespaced_property` | 0.0% | 0/7 | 0 | 7 |  |
| 571 | `xml_no_namespace` | 0.0% | 0/1 | 0 | 1 |  |
| 572 | `xml_nodekind` | 0.0% | 0/3 | 0 | 3 |  |
| 573 | `xml_normalize` | 0.0% | 0/35 | 0 | 35 |  |
| 574 | `xml_notification_bubbling` | 0.0% | 0/361 | 0 | 361 |  |
| 575 | `xml_parent` | 0.0% | 0/8 | 0 | 8 |  |
| 576 | `xml_set_children` | 0.0% | 0/17 | 0 | 17 |  |
| 577 | `xml_set_name` | 0.0% | 0/34 | 0 | 34 |  |
| 578 | `xml_settings` | 0.0% | 0/6 | 0 | 6 |  |
| 579 | `xml_simple_complex_content` | 0.0% | 0/47 | 0 | 47 |  |
| 580 | `xml_text` | 0.0% | 0/7 | 0 | 7 |  |
| 581 | `xml_tostring` | 0.0% | 0/6 | 6 | 6 |  |
| 582 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 583 | `xml_weird_ignores` | 0.0% | 0/56 | 56 | 54 |  |
| 584 | `xml_wildcard` | 0.0% | 0/11 | 0 | 11 |  |
| 585 | `xmldocument` | 0.0% | 0/254 | 0 | 254 |  |
| 586 | `xmlnode` | 0.0% | 0/3540 | 0 | 3540 |  |
| 587 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
