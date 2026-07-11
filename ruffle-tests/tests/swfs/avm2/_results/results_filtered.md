# Ruffle Test Results (Filtered)

**Date**: 2026-07-11 19:59 UTC

**Git SHA**: `f1d27c50cb`

**Run Duration**: 82m 46s

**Filtered**: 227 tests ignored out of 1201 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 974 |
| Passing | **409** (42.0%) |
| Failing | 565 |
| Total expected lines | 124585 |
| Matching lines | 46821 (37.6%) |
| Mismatched lines | 77764 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 556 | 98.4% |
| Runtime Error | 9 | 1.6% |

## Passing Tests

**409 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.8s |  |
| 2 | `amf_custom_obj` | 26 | 0.8s |  |
| 3 | `amf_dictionary` | 9 | 0.7s |  |
| 4 | `amf_function` | 46 | 0.8s |  |
| 5 | `amf_invalid_date` | 2 | 0.7s |  |
| 6 | `amf_missing_prop` | 6 | 0.7s |  |
| 7 | `amf_nondynamic_function_prop` | 6 | 1.7s |  |
| 8 | `amf_setter_error` | 8 | 8.1s |  |
| 9 | `amf_vector` | 40 | 1.8s |  |
| 10 | `amf_xml` | 6 | 1.7s |  |
| 11 | `application_domain` | 4 | 1.7s |  |
| 12 | `array_access` | 18 | 1.8s |  |
| 13 | `array_access_interpreter` | 4 | 1.7s |  |
| 14 | `array_access_no_pubns` | 2 | 1.7s |  |
| 15 | `array_concat` | 41 | 1.7s |  |
| 16 | `array_constr` | 10 | 1.7s |  |
| 17 | `array_delete` | 44 | 1.8s |  |
| 18 | `array_enumeration` | 10 | 1.7s |  |
| 19 | `array_enumeration_elements` | 11 | 1.7s |  |
| 20 | `array_every` | 8 | 1.7s |  |
| 21 | `array_filter` | 6 | 1.7s |  |
| 22 | `array_foreach` | 18 | 1.7s |  |
| 23 | `array_hasownproperty` | 11 | 1.7s |  |
| 24 | `array_holes` | 9 | 1.7s |  |
| 25 | `array_index_max` | 84 | 1.4s |  |
| 26 | `array_indexof` | 25 | 1.7s |  |
| 27 | `array_join` | 26 | 1.8s |  |
| 28 | `array_lastindexof` | 29 | 1.7s |  |
| 29 | `array_length` | 14 | 1.7s |  |
| 30 | `array_literal` | 3 | 1.7s |  |
| 31 | `array_map` | 8 | 0.4s |  |
| 32 | `array_pop` | 52 | 1.7s |  |
| 33 | `array_push` | 24 | 1.7s |  |
| 34 | `array_reborrow_bug` | 6 | 1.7s |  |
| 35 | `array_reverse` | 28 | 1.7s |  |
| 36 | `array_shift` | 51 | 1.8s |  |
| 37 | `array_slice` | 39 | 1.8s |  |
| 38 | `array_some` | 8 | 1.6s |  |
| 39 | `array_sort` | 297 | 1.9s |  |
| 40 | `array_sort_fun_swf12` | 2 | 1.7s |  |
| 41 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 42 | `array_sort_random` | 210 | 1.7s |  |
| 43 | `array_sort_swf10_32bit` | 1 | 1.6s |  |
| 44 | `array_sorton` | 545 | 2.1s |  |
| 45 | `array_sparse_ops` | 41 | 1.8s |  |
| 46 | `array_splice` | 133 | 1.8s |  |
| 47 | `array_splice2` | 428 | 2.0s |  |
| 48 | `array_splice_types` | 48 | 1.8s |  |
| 49 | `array_storage` | 8 | 1.7s |  |
| 50 | `array_tolocalestring` | 9 | 1.7s |  |
| 51 | `array_tostring` | 12 | 1.7s |  |
| 52 | `array_unshift` | 24 | 1.7s |  |
| 53 | `array_valueof` | 9 | 1.6s |  |
| 54 | `array_vector_null_callback` | 10 | 1.7s |  |
| 55 | `astype` | 28 | 1.8s |  |
| 56 | `astypelate` | 24 | 1.8s |  |
| 57 | `astypelate_propagates` | 1 | 1.7s |  |
| 58 | `bitand` | 1058 | 4.1s |  |
| 59 | `bitnot` | 46 | 1.7s |  |
| 60 | `bitor` | 1058 | 3.7s |  |
| 61 | `bitxor` | 1058 | 3.7s |  |
| 62 | `boolean_constr` | 32 | 1.7s |  |
| 63 | `boolean_negation` | 30 | 1.7s |  |
| 64 | `boolean_tostring` | 8 | 1.6s |  |
| 65 | `bytearray` | 48 | 1.9s |  |
| 66 | `bytearray_compress` | 31 | 1.7s |  |
| 67 | `bytearray_errors` | 24 | 1.8s |  |
| 68 | `bytearray_method_serialization` | 1 | 1.7s |  |
| 69 | `bytearray_readobject_amf0` | 50 | 0.7s |  |
| 70 | `bytearray_readobject_amf3` | 53 | 1.7s |  |
| 71 | `bytearray_readutf8bytes_with_bom` | 16 | 1.7s |  |
| 72 | `bytearray_serialization` | 3 | 1.6s |  |
| 73 | `bytearray_string_null` | 19 | 1.8s |  |
| 74 | `bytearray_tostring` | 15 | 1.7s |  |
| 75 | `bytearray_utf16` | 8 | 1.7s |  |
| 76 | `bytearray_writeobject` | 24 | 0.6s |  |
| 77 | `callee_in_initializer` | 6 | 1.6s |  |
| 78 | `callproplex_class` | 1 | 1.7s |  |
| 79 | `catch_class` | 6 | 1.6s |  |
| 80 | `catch_scope_slot` | 7 | 1.7s |  |
| 81 | `checkfilter` | 4 | 1.6s |  |
| 82 | `class_call` | 32 | 1.7s |  |
| 83 | `class_cast_call` | 14 | 1.6s |  |
| 84 | `class_enumeration` | 4 | 1.7s |  |
| 85 | `class_has_own_property` | 2 | 1.7s |  |
| 86 | `class_init_interpreter_mode` | 1 | 1.6s |  |
| 87 | `class_is` | 32 | 1.7s |  |
| 88 | `class_methods` | 5 | 1.7s |  |
| 89 | `class_object_properties` | 10 | 1.8s |  |
| 90 | `class_singleton` | 18 | 6.7s |  |
| 91 | `class_supercalls_errors` | 35 | 1.6s |  |
| 92 | `class_supercalls_mismatched` | 26 | 1.6s |  |
| 93 | `class_superclass_wrong_order` | 1 | 1.4s |  |
| 94 | `class_to_locale_string` | 2 | 1.4s |  |
| 95 | `class_to_string` | 2 | 1.4s |  |
| 96 | `class_value_of` | 2 | 1.4s |  |
| 97 | `closures` | 12 | 1.5s |  |
| 98 | `coerce_property` | 33 | 1.5s |  |
| 99 | `coerce_return_type` | 40 | 1.7s |  |
| 100 | `coerce_return_type_fail` | 2 | 1.6s |  |
| 101 | `coerce_return_void` | 3 | 1.6s |  |
| 102 | `coerce_string` | 86 | 1.5s |  |
| 103 | `coerce_string_precision` | 28 | 1.4s |  |
| 104 | `coerce_to_primitive_side_effects` | 29 | 1.5s |  |
| 105 | `construct_errors_swf10` | 8 | 1.4s |  |
| 106 | `constructor_call` | 3 | 1.5s |  |
| 107 | `constructprop_dynamic_primitive` | 7 | 1.4s |  |
| 108 | `control_flow_bool` | 4 | 1.6s |  |
| 109 | `control_flow_stricteq` | 8 | 1.5s |  |
| 110 | `convert_boolean` | 30 | 1.4s |  |
| 111 | `convert_integer` | 90 | 1.4s |  |
| 112 | `convert_number` | 56 | 1.4s |  |
| 113 | `convert_uinteger` | 90 | 1.5s |  |
| 114 | `declocal` | 46 | 1.7s |  |
| 115 | `declocal_i` | 46 | 1.6s |  |
| 116 | `decrement` | 46 | 1.6s |  |
| 117 | `decrement_i` | 46 | 1.6s |  |
| 118 | `default_values` | 7 | 1.6s |  |
| 119 | `dictionary_access` | 62 | 1.8s |  |
| 120 | `dictionary_access_no_pubns` | 2 | 1.6s |  |
| 121 | `dictionary_delete` | 101 | 1.8s |  |
| 122 | `dictionary_foreach` | 42 | 1.8s |  |
| 123 | `dictionary_hasownproperty` | 63 | 1.7s |  |
| 124 | `dictionary_in` | 62 | 1.8s |  |
| 125 | `dictionary_iter_modify` | 8 | 1.6s |  |
| 126 | `dictionary_namespaces` | 36 | 1.7s |  |
| 127 | `dictionary_primitive_keys` | 29 | 1.6s |  |
| 128 | `displayobject_mask_self_referential` | 0 | 1.6s |  |
| 129 | `divide` | 1058 | 3.6s |  |
| 130 | `doabc_is_eager` | 1 | 19.1s |  |
| 131 | `duplicate_defs` | 1 | 0.5s |  |
| 132 | `eager_init` | 1 | 1.6s |  |
| 133 | `equals` | 512 | 2.8s |  |
| 134 | `error_prototype` | 15 | 1.7s |  |
| 135 | `error_tostring` | 29 | 1.8s |  |
| 136 | `es3_inheritance` | 31 | 1.8s |  |
| 137 | `es4_inheritance` | 30 | 1.8s |  |
| 138 | `es4_interfaces` | 30 | 1.9s |  |
| 139 | `es4_method_binding` | 8 | 1.8s |  |
| 140 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 141 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 142 | `event_bubbles` | 2 | 1.7s |  |
| 143 | `event_cancelable` | 2 | 1.7s |  |
| 144 | `event_type` | 1 | 1.6s |  |
| 145 | `eventdispatcher_dispatchevent_this` | 5 | 1.7s |  |
| 146 | `eventdispatcher_haseventlistener` | 25 | 1.7s |  |
| 147 | `falsiness` | 30 | 1.7s |  |
| 148 | `fast_index_access` | 12 | 1.9s |  |
| 149 | `finddef` | 3 | 1.7s |  |
| 150 | `findprop_global_prototype` | 6 | 1.7s |  |
| 151 | `flash_xml` | 29 | 1.7s |  |
| 152 | `flash_xml_cloneNode` | 22 | 6.3s |  |
| 153 | `flash_xml_namespace` | 109 | 1.4s |  |
| 154 | `flash_xml_removeNode` | 60 | 1.4s |  |
| 155 | `function_call` | 12 | 1.4s |  |
| 156 | `function_call_arguments` | 46 | 1.4s |  |
| 157 | `function_call_arguments_enumerate` | 5 | 1.3s |  |
| 158 | `function_call_coercion` | 108 | 1.5s |  |
| 159 | `function_call_default` | 6 | 1.4s |  |
| 160 | `function_call_rest` | 22 | 1.5s |  |
| 161 | `function_call_types` | 3 | 1.4s |  |
| 162 | `function_call_via_apply` | 11 | 1.3s |  |
| 163 | `function_call_via_call` | 3 | 1.3s |  |
| 164 | `function_display_anonymous` | 7 | 1.3s |  |
| 165 | `function_length` | 6 | 1.3s |  |
| 166 | `function_object` | 2 | 1.3s |  |
| 167 | `function_proto` | 5 | 1.3s |  |
| 168 | `function_proto_created` | 61 | 8.2s |  |
| 169 | `function_to_locale_string` | 4 | 1.7s |  |
| 170 | `function_to_string` | 4 | 1.7s |  |
| 171 | `function_type` | 6 | 1.8s |  |
| 172 | `function_unbound_this` | 51 | 1.9s |  |
| 173 | `function_value_of` | 4 | 1.7s |  |
| 174 | `get_definition_by_name` | 11 | 1.8s |  |
| 175 | `get_qualified_class_name` | 20 | 1.8s |  |
| 176 | `get_slot_edge_cases` | 1 | 1.7s |  |
| 177 | `getglobalslot` | 1 | 1.7s |  |
| 178 | `getouterscope` | 8 | 1.7s |  |
| 179 | `getter_different_namespace_setter` | 2 | 1.8s |  |
| 180 | `graphics_round_rects` | 0 | 1.8s |  |
| 181 | `greaterequals` | 512 | 9.3s |  |
| 182 | `greaterthan` | 512 | 2.9s |  |
| 183 | `has_own_property` | 102 | 2.0s |  |
| 184 | `hasownproperty_namespaces` | 2 | 1.8s |  |
| 185 | `hello_world` | 1 | 1.8s |  |
| 186 | `if_eq` | 10 | 1.8s |  |
| 187 | `if_gt` | 1 | 1.7s |  |
| 188 | `if_gte` | 10 | 1.7s |  |
| 189 | `if_lt` | 1 | 0.4s |  |
| 190 | `if_lte` | 10 | 0.4s |  |
| 191 | `if_ne` | 7 | 1.7s |  |
| 192 | `if_stricteq` | 6 | 1.7s |  |
| 193 | `if_strictne` | 11 | 1.7s |  |
| 194 | `in` | 102 | 1.9s |  |
| 195 | `inclocal` | 46 | 1.7s |  |
| 196 | `inclocal_i` | 46 | 1.7s |  |
| 197 | `increment` | 46 | 1.8s |  |
| 198 | `increment_i` | 46 | 1.8s |  |
| 199 | `instanceof` | 58 | 1.9s |  |
| 200 | `int_constr` | 92 | 1.8s |  |
| 201 | `int_edge_cases` | 19 | 1.8s |  |
| 202 | `int_instanceof` | 3 | 1.7s |  |
| 203 | `int_tofixed` | 1215 | 1.7s |  |
| 204 | `int_tostring` | 3375 | 1.9s |  |
| 205 | `interface_namespaces` | 78 | 1.8s |  |
| 206 | `is_finite` | 46 | 1.8s |  |
| 207 | `is_nan` | 46 | 1.7s |  |
| 208 | `is_prototype_of` | 12 | 1.7s |  |
| 209 | `issue_10221` | 2 | 1.7s |  |
| 210 | `issue_13780` | 12 | 7.8s |  |
| 211 | `issue_14901` | 1 | 1.7s |  |
| 212 | `istype` | 24 | 1.8s |  |
| 213 | `istypelate` | 58 | 1.9s |  |
| 214 | `istypelate_coerce` | 198 | 2.2s |  |
| 215 | `json_errors` | 9 | 20.5s |  |
| 216 | `json_parse` | 21 | 1.8s |  |
| 217 | `json_version_gated` | 1 | 1.7s |  |
| 218 | `lazyinit` | 17 | 1.7s |  |
| 219 | `lessequals` | 512 | 2.8s |  |
| 220 | `lessthan` | 512 | 2.7s |  |
| 221 | `lshift` | 1058 | 3.7s |  |
| 222 | `math` | 497 | 1.8s |  |
| 223 | `modulo` | 1058 | 3.7s |  |
| 224 | `movieclip_stop` | 1 | 19.6s |  |
| 225 | `multiply` | 1058 | 3.8s |  |
| 226 | `namespace_constr` | 253 | 2.0s |  |
| 227 | `namespace_constr_args` | 1 | 1.6s |  |
| 228 | `namespace_enumeration_order` | 7 | 1.6s |  |
| 229 | `negate` | 30 | 1.7s |  |
| 230 | `negative_volume_panned` | 0 | 1.8s |  |
| 231 | `nested_iteration` | 11 | 1.7s |  |
| 232 | `net_getClassByAlias` | 3 | 1.7s |  |
| 233 | `newactivation_in_script_init` | 3 | 1.6s |  |
| 234 | `newclass_twice` | 3 | 1.6s |  |
| 235 | `nonconflicting_declarations` | 0 | 1.6s |  |
| 236 | `number_autoconv` | 21 | 1.6s |  |
| 237 | `number_autoconv_amf` | 132 | 1.6s |  |
| 238 | `number_autoconv_array_sort_32bit` | 1 | 1.7s |  |
| 239 | `number_constr` | 58 | 1.7s |  |
| 240 | `number_toexponential` | 378 | 1.7s |  |
| 241 | `number_toexponential2` | 35 | 1.6s |  |
| 242 | `number_tofixed` | 378 | 1.6s |  |
| 243 | `number_toprecision` | 350 | 1.7s |  |
| 244 | `obfuscated_class_names` | 3 | 1.6s |  |
| 245 | `object_enumeration` | 10 | 1.6s |  |
| 246 | `object_prototype` | 4 | 1.7s |  |
| 247 | `object_to_locale_string` | 2 | 1.6s |  |
| 248 | `object_to_string` | 2 | 1.6s |  |
| 249 | `object_value_of` | 2 | 1.4s |  |
| 250 | `op_coerce` | 54 | 1.1s |  |
| 251 | `op_coerce_x` | 54 | 1.7s |  |
| 252 | `op_escxattr` | 2 | 1.6s |  |
| 253 | `op_escxelem` | 2 | 1.6s |  |
| 254 | `op_lookupswitch` | 4 | 1.6s |  |
| 255 | `optimize_coerce` | 1 | 1.6s |  |
| 256 | `param_default_value_has_zero_cpool_index` | 1 | 1.3s |  |
| 257 | `parse_float` | 80 | 1.4s |  |
| 258 | `primitive_edge_cases` | 1 | 1.6s |  |
| 259 | `property_priority` | 22 | 2.0s |  |
| 260 | `property_priority_three_level` | 6 | 1.8s |  |
| 261 | `propertyisenumerable_namespaces` | 6 | 1.7s |  |
| 262 | `prototype_set_null` | 7 | 1.7s |  |
| 263 | `proxy_callproperty` | 24 | 1.7s |  |
| 264 | `proxy_deleteproperty` | 64 | 1.8s |  |
| 265 | `proxy_enumeration` | 34 | 1.7s |  |
| 266 | `proxy_getproperty` | 77 | 1.7s |  |
| 267 | `proxy_hasownproperty` | 8 | 1.7s |  |
| 268 | `proxy_hasproperty` | 32 | 1.9s |  |
| 269 | `proxy_serialize` | 9 | 1.7s |  |
| 270 | `proxy_setproperty` | 42 | 1.7s |  |
| 271 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.6s |  |
| 272 | `qname_constr` | 32 | 1.7s |  |
| 273 | `qname_constr_namespace` | 24 | 1.7s |  |
| 274 | `qname_enumeration` | 9 | 1.7s |  |
| 275 | `qname_indexing` | 23 | 1.8s |  |
| 276 | `qname_tostring` | 25 | 1.8s |  |
| 277 | `qname_valueof` | 29 | 1.7s |  |
| 278 | `regexp_constr` | 148 | 1.9s |  |
| 279 | `regexp_exec` | 19 | 1.7s |  |
| 280 | `regexp_extended` | 47 | 1.7s |  |
| 281 | `regexp_multiargs` | 1 | 1.6s |  |
| 282 | `regexp_test` | 27 | 8.1s |  |
| 283 | `regexp_toString` | 10 | 1.8s |  |
| 284 | `resolve_order` | 4 | 1.7s |  |
| 285 | `rng` | 1 | 3.1s |  |
| 286 | `rshift` | 1058 | 3.8s |  |
| 287 | `set_property_is_enumerable` | 85 | 1.9s |  |
| 288 | `slot_disp_id_shared_numbering` | 1 | 26.6s |  |
| 289 | `slots_force_autoassigned` | 1 | 1.7s |  |
| 290 | `static_var_with_this_in_ctor` | 2 | 1.7s |  |
| 291 | `stored_properties` | 11 | 7.8s |  |
| 292 | `strict_equality` | 34 | 1.7s |  |
| 293 | `string_call` | 13 | 1.7s |  |
| 294 | `string_case` | 23 | 1.7s |  |
| 295 | `string_char_at` | 27 | 1.6s |  |
| 296 | `string_char_code_at` | 28 | 1.6s |  |
| 297 | `string_concat_fromcharcode` | 36 | 1.6s |  |
| 298 | `string_constr` | 25 | 1.6s |  |
| 299 | `string_indexof_lastindexof` | 87 | 1.7s |  |
| 300 | `string_length` | 16 | 1.6s |  |
| 301 | `string_locale_compare` | 39 | 1.8s |  |
| 302 | `string_match` | 51 | 1.8s |  |
| 303 | `string_replace` | 51 | 1.8s |  |
| 304 | `string_search` | 41 | 1.7s |  |
| 305 | `string_slice_substr_substring` | 169 | 1.9s |  |
| 306 | `string_split` | 29 | 1.7s |  |
| 307 | `string_substr_negative` | 21 | 1.6s |  |
| 308 | `string_substr_weird` | 182 | 1.6s |  |
| 309 | `subtract` | 1058 | 3.7s |  |
| 310 | `super_get_call` | 12 | 1.7s |  |
| 311 | `supercall_two_classobjects` | 2 | 1.6s |  |
| 312 | `swf8` | 1 | 1.4s |  |
| 313 | `symbol_class_root_not_zero` | 1 | 1.6s |  |
| 314 | `symbolclass_invalid_utf8` | 2 | 1.7s |  |
| 315 | `throw` | 3 | 1.7s |  |
| 316 | `truthiness` | 30 | 1.2s |  |
| 317 | `try_catch` | 11 | 1.3s |  |
| 318 | `try_catch_typed` | 12 | 1.4s |  |
| 319 | `typeof` | 30 | 1.3s |  |
| 320 | `uint_constr` | 92 | 1.3s |  |
| 321 | `uint_tofixed` | 1215 | 1.2s |  |
| 322 | `uint_tostring` | 3375 | 1.4s |  |
| 323 | `unchecked_function` | 15 | 1.3s |  |
| 324 | `urshift` | 1058 | 2.8s |  |
| 325 | `vector_class` | 36 | 1.5s |  |
| 326 | `vector_class_call` | 11 | 1.4s |  |
| 327 | `vector_coercion` | 66 | 2.0s |  |
| 328 | `vector_concat` | 90 | 1.5s |  |
| 329 | `vector_constr` | 107 | 1.5s |  |
| 330 | `vector_enumeration` | 5 | 1.5s |  |
| 331 | `vector_every` | 92 | 1.6s |  |
| 332 | `vector_filter` | 95 | 1.6s |  |
| 333 | `vector_holes` | 24 | 1.3s |  |
| 334 | `vector_indexof` | 302 | 1.9s |  |
| 335 | `vector_insertat` | 270 | 1.6s |  |
| 336 | `vector_int_access` | 4 | 1.2s |  |
| 337 | `vector_int_delete` | 11 | 1.2s |  |
| 338 | `vector_join` | 58 | 1.8s |  |
| 339 | `vector_lastindexof` | 302 | 1.2s |  |
| 340 | `vector_legacy` | 10 | 1.2s |  |
| 341 | `vector_map` | 85 | 8.2s |  |
| 342 | `vector_object_final` | 1 | 1.4s |  |
| 343 | `vector_object_toString` | 10 | 0.7s |  |
| 344 | `vector_pushpop` | 255 | 1.1s |  |
| 345 | `vector_reborrow_bug` | 10 | 0.7s |  |
| 346 | `vector_removeat` | 172 | 1.0s |  |
| 347 | `vector_reverse` | 232 | 1.0s |  |
| 348 | `vector_shiftunshift` | 252 | 0.7s |  |
| 349 | `vector_slice` | 331 | 1.1s |  |
| 350 | `vector_sort` | 905 | 2.3s |  |
| 351 | `vector_splice` | 693 | 1.5s |  |
| 352 | `vector_splice_fixed_bug_compat` | 4 | 0.7s |  |
| 353 | `vector_tostring` | 79 | 0.9s |  |
| 354 | `verify_abnormal_loop` | 1 | 0.7s |  |
| 355 | `verify_exception_targets_edge_case` | 1 | 0.8s |  |
| 356 | `verify_lookup_switch_edge_case` | 1 | 0.7s |  |
| 357 | `verify_unreachable_exception` | 2 | 0.7s |  |
| 358 | `versioned_isplaying` | 2 | 0.7s |  |
| 359 | `virtual_properties` | 16 | 0.7s |  |
| 360 | `with` | 4 | 0.7s |  |
| 361 | `xml_abstract_equality` | 36 | 0.8s |  |
| 362 | `xml_advanced` | 52 | 0.7s |  |
| 363 | `xml_appendchild` | 10 | 0.7s |  |
| 364 | `xml_as_attribute` | 9 | 0.7s |  |
| 365 | `xml_attribute` | 35 | 0.8s |  |
| 366 | `xml_attribute_name` | 40 | 0.7s |  |
| 367 | `xml_basic` | 32 | 0.9s |  |
| 368 | `xml_child` | 25 | 0.7s |  |
| 369 | `xml_childindex` | 7 | 0.7s |  |
| 370 | `xml_children` | 43 | 1.1s |  |
| 371 | `xml_class_call` | 9 | 0.7s |  |
| 372 | `xml_contains` | 197 | 7.1s |  |
| 373 | `xml_copy` | 20 | 1.7s |  |
| 374 | `xml_ctor_from_tostring` | 23 | 2.0s |  |
| 375 | `xml_delete` | 114 | 1.8s |  |
| 376 | `xml_descendants` | 83 | 1.7s |  |
| 377 | `xml_elements` | 6 | 1.6s |  |
| 378 | `xml_equals_namespace_check` | 2 | 1.6s |  |
| 379 | `xml_explicit_use_namespace` | 5 | 1.6s |  |
| 380 | `xml_getdescendants_qname` | 21 | 1.6s |  |
| 381 | `xml_has_property_via_in` | 26 | 1.6s |  |
| 382 | `xml_hasownproperty` | 6 | 1.6s |  |
| 383 | `xml_ignore_white` | 6 | 1.7s |  |
| 384 | `xml_length` | 2 | 1.6s |  |
| 385 | `xml_list_as_attribute` | 9 | 1.0s |  |
| 386 | `xml_list_concat` | 20 | 1.5s |  |
| 387 | `xml_list_enumerate` | 4 | 1.6s |  |
| 388 | `xml_methods_settings` | 3 | 1.6s |  |
| 389 | `xml_mismatched_tag` | 37 | 1.7s |  |
| 390 | `xml_namespace` | 39 | 1.7s |  |
| 391 | `xml_namespace_methods` | 245 | 1.8s |  |
| 392 | `xml_namespaced_property` | 7 | 1.7s |  |
| 393 | `xml_no_namespace` | 1 | 1.6s |  |
| 394 | `xml_nodekind` | 3 | 1.6s |  |
| 395 | `xml_normalize` | 35 | 1.8s |  |
| 396 | `xml_notification_bubbling` | 361 | 1.7s |  |
| 397 | `xml_parent` | 8 | 1.7s |  |
| 398 | `xml_set_children` | 17 | 1.5s |  |
| 399 | `xml_set_name` | 34 | 1.6s |  |
| 400 | `xml_settings` | 6 | 1.6s |  |
| 401 | `xml_simple_complex_content` | 47 | 1.7s |  |
| 402 | `xml_text` | 7 | 1.6s |  |
| 403 | `xml_tostring` | 6 | 1.6s |  |
| 404 | `xml_tostring_namespace` | 12 | 1.6s |  |
| 405 | `xml_unescaping` | 23 | 1.7s |  |
| 406 | `xml_weird_ignores` | 54 | 1.8s |  |
| 407 | `xml_wildcard` | 11 | 1.6s |  |
| 408 | `xmldocument` | 254 | 1.7s |  |
| 409 | `xmlnode` | 3540 | 1.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**33 tests** within reach

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
| 10 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 11 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 12 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 13 | `event_valueof_tostring` | 77.8% | 14 | 18 | 4 |  |
| 14 | `eventdispatcher_dispatchevent` | 75.0% | 9 | 12 | 3 |  |
| 15 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 16 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 17 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 18 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 19 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 20 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 21 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15 | 24 | 9 |  |
| 22 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 23 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 24 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 25 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 26 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 27 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 28 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 29 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 30 | `place_object_same_depth_frame` | 50.0% | 1 | 2 | 1 |  |
| 31 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 32 | `subclass_superclass_linked_symbol` | 50.0% | 3 | 6 | 3 |  |
| 33 | `verification` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

**9 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bitmap_subclass` | exit code 1 | 2.9s |  |
| 2 | `content_element_basic` | exit code 1 | 1.5s |  |
| 3 | `domain_memory` | exit code 1 | 1.6s |  |
| 4 | `goto_nested_construct_sibling` | exit code 1 | 2.1s |  |
| 5 | `method_without_body` | exit code 1 | 19.0s |  |
| 6 | `null_void_types` | exit code 1 | 1.6s |  |
| 7 | `rtqname_not_namespace` | exit code 1 | 1.7s |  |
| 8 | `supercalls_weird` | exit code 1 | 1.6s |  |
| 9 | `verify_typecheck` | exit code 1 | 0.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**556 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 11 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 12 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 13 | `event_valueof_tostring` | 77.8% | 14/18 | 18 | 18 |  |
| 14 | `eventdispatcher_dispatchevent` | 75.0% | 9/12 | 12 | 12 |  |
| 15 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 16 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 17 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 18 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 19 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 20 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 21 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15/24 | 24 | 22 |  |
| 22 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 23 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 24 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 25 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 26 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 27 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 28 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 29 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 30 | `place_object_same_depth_frame` | 50.0% | 1/2 | 2 | 1 |  |
| 31 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 32 | `subclass_superclass_linked_symbol` | 50.0% | 3/6 | 6 | 4 |  |
| 33 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 34 | `eventdispatcher_dispatchevent_cancel` | 45.0% | 9/20 | 9 | 20 |  |
| 35 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 36 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 37 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 38 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 39 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 40 | `event_clone_error_redispatch` | 33.3% | 1/3 | 2 | 3 |  |
| 41 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 42 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 43 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 44 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 45 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 46 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 48 | `event_clone` | 30.0% | 6/20 | 6 | 20 |  |
| 49 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 50 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 51 | `error_stack_trace` | 28.9% | 13/45 | 27 | 45 |  |
| 52 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 53 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 54 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 55 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 56 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 57 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 58 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 59 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 60 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 61 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 62 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 63 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 64 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 65 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 66 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 67 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 68 | `event_clone_on_redispatch` | 20.0% | 2/10 | 8 | 10 |  |
| 69 | `event_target_getter` | 20.0% | 1/5 | 2 | 5 |  |
| 70 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 71 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 72 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 73 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 74 | `event_isdefaultprevented` | 16.7% | 2/12 | 2 | 12 |  |
| 75 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 76 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 77 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 78 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 79 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 80 | `movieclip_gotoandstop` | 15.4% | 2/13 | 2 | 13 |  |
| 81 | `doabc_and_symbolclass_script_init_goto` | 14.3% | 1/7 | 5 | 7 |  |
| 82 | `movieclip_goto_overwrite` | 14.3% | 2/14 | 2 | 14 |  |
| 83 | `movieclip_gotoandstop_framescripts_self` | 14.3% | 1/7 | 1 | 7 |  |
| 84 | `movieclip_prev_scene` | 14.3% | 1/7 | 1 | 7 |  |
| 85 | `stage_framerate_nan` | 14.3% | 1/7 | 1 | 7 |  |
| 86 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 87 | `movieclip_goto_during_frame_script` | 13.3% | 2/15 | 2 | 15 |  |
| 88 | `movieclip_gotoandplay` | 13.3% | 2/15 | 2 | 15 |  |
| 89 | `stage_mouseenabled` | 13.3% | 2/15 | 2 | 15 |  |
| 90 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 91 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 92 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 93 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 94 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 95 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 96 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 97 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 98 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 99 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 100 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 101 | `event_target_set` | 11.1% | 1/9 | 9 | 9 |  |
| 102 | `eventdispatcher_dispatchevent_indirect` | 11.1% | 1/9 | 1 | 9 |  |
| 103 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 104 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 105 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 106 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 107 | `event_formattostring` | 9.7% | 3/31 | 3 | 31 |  |
| 108 | `construct_frame_list` | 9.1% | 2/22 | 2 | 22 |  |
| 109 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 110 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 111 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 112 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 113 | `goto_in_constructframe` | 8.3% | 1/12 | 1 | 12 |  |
| 114 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 115 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 116 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 117 | `button_nested_frame_simple` | 7.4% | 2/27 | 3 | 27 |  |
| 118 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 119 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 120 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 121 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 122 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 123 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 124 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 125 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 126 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 127 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 128 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 129 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 130 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 131 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 132 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 133 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 134 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 135 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 136 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 137 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 138 | `button_nested_frame` | 4.2% | 2/48 | 3 | 48 |  |
| 139 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 140 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 141 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 142 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 143 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 144 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 145 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 146 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 147 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 148 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 149 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 150 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 151 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 152 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 153 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 154 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 155 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 156 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 157 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 158 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 159 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 160 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 161 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 162 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 163 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 164 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 165 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 166 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 167 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 168 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 169 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 170 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 171 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 172 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 173 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 174 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 175 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 176 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 177 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 178 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 179 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 180 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 181 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 182 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 183 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 184 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 185 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 186 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 187 | `orphan_movie_reorder` | 1.8% | 2/111 | 2 | 111 |  |
| 188 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 189 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 190 | `displayobjectcontainer_addchild_timelinepull1` | 1.7% | 1/60 | 1 | 60 |  |
| 191 | `displacement_map_filter` | 1.6% | 1/61 | 1 | 61 |  |
| 192 | `displayobjectcontainer_addchild_timelinepull2` | 1.6% | 1/62 | 1 | 62 |  |
| 193 | `edittext_newline_stripping` | 1.6% | 1/64 | 1 | 64 |  |
| 194 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 195 | `displayobjectcontainer_contains` | 1.5% | 1/66 | 1 | 66 |  |
| 196 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 197 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 198 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 199 | `simplebutton_childevents` | 1.2% | 1/86 | 1 | 86 |  |
| 200 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 201 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 202 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 203 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 204 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 205 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 206 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 207 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 208 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 209 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 210 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 211 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 212 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 213 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 214 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 215 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 216 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 217 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 218 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 219 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 220 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 221 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 222 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 223 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 224 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 225 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 226 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 227 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 228 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 229 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 230 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 231 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 232 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 233 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 234 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 235 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 236 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 237 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 238 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 239 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 240 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 241 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 242 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 243 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 244 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 245 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 246 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 247 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 248 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 249 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 250 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 251 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 252 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 254 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 255 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 256 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 257 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 258 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 259 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 260 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 261 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 262 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 263 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 264 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 265 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 266 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 267 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 268 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 269 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 270 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 271 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 272 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 273 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 274 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 275 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 276 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 277 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 279 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 280 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 281 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 282 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 283 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 284 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 285 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 286 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 287 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 288 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 289 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 290 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 291 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 292 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 293 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 294 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 295 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 296 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 297 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 298 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 299 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 300 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 301 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 302 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 303 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 305 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 306 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 307 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 308 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 309 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 310 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 311 | `edittext_autosize_height_input` | 0.0% | 0/60 | 0 | 60 |  |
| 312 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 313 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 314 | `edittext_autosize_lazy_bounds_props` | 0.0% | 0/490 | 0 | 490 |  |
| 315 | `edittext_autosize_lazy_bounds_vs_relayout` | 0.0% | 0/106 | 0 | 106 |  |
| 316 | `edittext_bottom_scroll_v_basic` | 0.0% | 0/210 | 0 | 210 |  |
| 317 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 318 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 319 | `edittext_empty_text_format` | 0.0% | 0/7 | 0 | 7 |  |
| 320 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 321 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 322 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 323 | `edittext_get_line_index_of_char` | 0.0% | 0/76 | 0 | 76 |  |
| 324 | `edittext_getcharboundaries` | 0.0% | 0/172 | 0 | 172 |  |
| 325 | `edittext_getcharboundaries_missing_glyphs` | 0.0% | 0/63 | 0 | 63 |  |
| 326 | `edittext_getcharboundaries_scroll` | 0.0% | 0/85 | 0 | 85 |  |
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
| 337 | `edittext_line_methods` | 0.0% | 0/294 | 0 | 294 |  |
| 338 | `edittext_line_metrics` | 0.0% | 0/11 | 0 | 11 |  |
| 339 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 340 | `edittext_max_scroll_h_basic` | 0.0% | 0/475 | 0 | 475 |  |
| 341 | `edittext_max_scroll_v_basic` | 0.0% | 0/1000 | 0 | 1000 |  |
| 342 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 343 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 344 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 345 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 346 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 347 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 348 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 349 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 350 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 351 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 352 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 353 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 354 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 355 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 356 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 357 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 358 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 359 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 360 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 361 | `edittext_wordwrap_word` | 0.0% | 0/150 | 0 | 150 |  |
| 362 | `edittext_wrap_breaks` | 0.0% | 0/2375 | 0 | 2375 |  |
| 363 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 364 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 365 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 366 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 367 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 368 | `error_1034_debug_string` | 0.0% | 0/30 | 6 | 30 |  |
| 369 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 370 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 371 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 372 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 373 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 374 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 375 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 376 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 377 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 378 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 379 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 380 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 381 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 382 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 383 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 384 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 385 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 386 | `font_enumeratefonts_filter` | 0.0% | 0/4 | 0 | 4 |  |
| 387 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 388 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 389 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 390 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 391 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 392 | `goto_button_nested_framescript` | 0.0% | 0/28 | 1 | 28 |  |
| 393 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 394 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 395 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 396 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 397 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 398 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 399 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 400 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 401 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 402 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 403 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 404 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 405 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 406 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 407 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 408 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 409 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 410 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 411 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 412 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 413 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 414 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 415 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 416 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 417 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 418 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 419 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 420 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 421 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 422 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 423 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 424 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 425 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 426 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 427 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 428 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 429 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 430 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 431 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 432 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 433 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 434 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 435 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 436 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 437 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 438 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 439 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 440 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 441 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 442 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 443 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 444 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 445 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 446 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 447 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 1 | 676 |  |
| 448 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 1 | 2001 |  |
| 449 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 1 | 575 |  |
| 450 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 1 | 562 |  |
| 451 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 1 | 140 |  |
| 452 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 1 | 50 |  |
| 453 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 1 | 144 |  |
| 454 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 455 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 1 | 149 |  |
| 456 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 1 | 48 |  |
| 457 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 1 | 149 |  |
| 458 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 1 | 106 |  |
| 459 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 1 | 44 |  |
| 460 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 1 | 135 |  |
| 461 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 462 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 463 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 464 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 465 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 1 | 9 |  |
| 466 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 1 | 7 |  |
| 467 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 468 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 469 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 470 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 471 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 472 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 473 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 474 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 475 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 476 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 477 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 478 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 479 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 480 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 481 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 482 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 483 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 484 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 485 | `remove_child_clear_field` | 0.0% | 0/88 | 1 | 88 |  |
| 486 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 487 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 488 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 489 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 490 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 491 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 492 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 493 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 494 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 495 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 496 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 2 | 45 |  |
| 497 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 498 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 499 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 500 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 501 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 502 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 503 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 504 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 505 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 506 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 507 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 508 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 509 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 510 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 511 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 512 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 513 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 514 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 515 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 1 | 6 |  |
| 516 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 517 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 518 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 519 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 520 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 521 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 522 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 523 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 524 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 525 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 526 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 527 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 528 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 529 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 530 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 531 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 532 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 533 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 534 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 535 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 536 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 537 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 538 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 539 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 540 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 541 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 542 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 543 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 544 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 545 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 546 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 547 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 548 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 549 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 550 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 551 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 552 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 553 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 554 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 555 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 556 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
