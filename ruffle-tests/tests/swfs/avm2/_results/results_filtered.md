# Ruffle Test Results (Filtered)

**Date**: 2026-07-11 13:16 UTC

**Git SHA**: `7e3a3a0148`

**Run Duration**: 79m 32s

**Filtered**: 227 tests ignored out of 1199 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 972 |
| Passing | **293** (30.1%) |
| Failing | 679 |
| Total expected lines | 124452 |
| Matching lines | 39242 (31.5%) |
| Mismatched lines | 85210 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 635 | 93.5% |
| Runtime Error | 44 | 6.5% |

## Passing Tests

**293 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.2s |  |
| 2 | `application_domain` | 4 | 1.5s |  |
| 3 | `array_access` | 18 | 1.5s |  |
| 4 | `array_access_interpreter` | 4 | 1.5s |  |
| 5 | `array_access_no_pubns` | 2 | 1.4s |  |
| 6 | `array_concat` | 41 | 1.5s |  |
| 7 | `array_constr` | 10 | 1.5s |  |
| 8 | `array_delete` | 44 | 1.6s |  |
| 9 | `array_enumeration` | 10 | 1.5s |  |
| 10 | `array_enumeration_elements` | 11 | 1.5s |  |
| 11 | `array_every` | 8 | 1.5s |  |
| 12 | `array_filter` | 6 | 1.5s |  |
| 13 | `array_foreach` | 18 | 1.5s |  |
| 14 | `array_hasownproperty` | 11 | 1.5s |  |
| 15 | `array_holes` | 9 | 1.5s |  |
| 16 | `array_index_max` | 84 | 1.2s |  |
| 17 | `array_indexof` | 25 | 1.5s |  |
| 18 | `array_join` | 26 | 1.5s |  |
| 19 | `array_lastindexof` | 29 | 1.5s |  |
| 20 | `array_length` | 14 | 1.5s |  |
| 21 | `array_literal` | 3 | 1.5s |  |
| 22 | `array_map` | 8 | 0.4s |  |
| 23 | `array_pop` | 52 | 1.6s |  |
| 24 | `array_push` | 24 | 1.5s |  |
| 25 | `array_reborrow_bug` | 6 | 1.5s |  |
| 26 | `array_reverse` | 28 | 1.5s |  |
| 27 | `array_shift` | 51 | 1.6s |  |
| 28 | `array_slice` | 39 | 1.5s |  |
| 29 | `array_some` | 8 | 1.5s |  |
| 30 | `array_sort` | 297 | 1.8s |  |
| 31 | `array_sort_fun_swf12` | 2 | 1.5s |  |
| 32 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 33 | `array_sort_random` | 210 | 1.5s |  |
| 34 | `array_sort_swf10_32bit` | 1 | 6.3s |  |
| 35 | `array_sorton` | 545 | 2.0s |  |
| 36 | `array_sparse_ops` | 41 | 1.6s |  |
| 37 | `array_splice` | 133 | 1.7s |  |
| 38 | `array_splice2` | 428 | 1.9s |  |
| 39 | `array_splice_types` | 48 | 1.7s |  |
| 40 | `array_storage` | 8 | 1.6s |  |
| 41 | `array_tolocalestring` | 9 | 1.6s |  |
| 42 | `array_tostring` | 12 | 1.6s |  |
| 43 | `array_unshift` | 24 | 1.6s |  |
| 44 | `array_valueof` | 9 | 1.5s |  |
| 45 | `array_vector_null_callback` | 10 | 1.6s |  |
| 46 | `astype` | 28 | 1.6s |  |
| 47 | `astypelate` | 24 | 1.7s |  |
| 48 | `astypelate_propagates` | 1 | 1.5s |  |
| 49 | `bitand` | 1058 | 3.9s |  |
| 50 | `bitnot` | 46 | 1.2s |  |
| 51 | `bitor` | 1058 | 3.0s |  |
| 52 | `bitxor` | 1058 | 3.0s |  |
| 53 | `boolean_constr` | 32 | 1.6s |  |
| 54 | `boolean_negation` | 30 | 1.6s |  |
| 55 | `boolean_tostring` | 8 | 1.6s |  |
| 56 | `callee_in_initializer` | 6 | 1.5s |  |
| 57 | `callproplex_class` | 1 | 1.6s |  |
| 58 | `catch_class` | 6 | 1.6s |  |
| 59 | `catch_scope_slot` | 7 | 1.7s |  |
| 60 | `class_cast_call` | 14 | 1.6s |  |
| 61 | `class_enumeration` | 4 | 1.6s |  |
| 62 | `class_has_own_property` | 2 | 1.6s |  |
| 63 | `class_init_interpreter_mode` | 1 | 1.5s |  |
| 64 | `class_is` | 32 | 1.6s |  |
| 65 | `class_methods` | 5 | 1.6s |  |
| 66 | `class_object_properties` | 10 | 6.3s |  |
| 67 | `class_singleton` | 18 | 1.6s |  |
| 68 | `class_supercalls_errors` | 35 | 1.7s |  |
| 69 | `class_supercalls_mismatched` | 26 | 1.6s |  |
| 70 | `class_superclass_wrong_order` | 1 | 1.5s |  |
| 71 | `class_to_locale_string` | 2 | 1.5s |  |
| 72 | `class_to_string` | 2 | 1.4s |  |
| 73 | `class_value_of` | 2 | 1.5s |  |
| 74 | `closures` | 12 | 1.5s |  |
| 75 | `coerce_property` | 33 | 1.6s |  |
| 76 | `coerce_return_type` | 40 | 1.6s |  |
| 77 | `coerce_return_type_fail` | 2 | 1.4s |  |
| 78 | `coerce_return_void` | 3 | 1.4s |  |
| 79 | `coerce_string` | 86 | 1.6s |  |
| 80 | `coerce_string_precision` | 28 | 1.5s |  |
| 81 | `construct_errors_swf10` | 8 | 1.5s |  |
| 82 | `constructor_call` | 3 | 1.5s |  |
| 83 | `constructprop_dynamic_primitive` | 7 | 1.6s |  |
| 84 | `control_flow_bool` | 4 | 1.5s |  |
| 85 | `control_flow_stricteq` | 8 | 1.5s |  |
| 86 | `convert_boolean` | 30 | 1.5s |  |
| 87 | `convert_integer` | 90 | 1.6s |  |
| 88 | `convert_number` | 56 | 1.6s |  |
| 89 | `convert_uinteger` | 90 | 1.6s |  |
| 90 | `declocal` | 46 | 1.6s |  |
| 91 | `declocal_i` | 46 | 1.6s |  |
| 92 | `decrement` | 46 | 1.6s |  |
| 93 | `decrement_i` | 46 | 1.6s |  |
| 94 | `default_values` | 7 | 1.6s |  |
| 95 | `displayobject_mask_self_referential` | 0 | 1.5s |  |
| 96 | `divide` | 1058 | 3.0s |  |
| 97 | `duplicate_defs` | 1 | 0.3s |  |
| 98 | `eager_init` | 1 | 1.2s |  |
| 99 | `equals` | 512 | 2.4s |  |
| 100 | `error_prototype` | 15 | 1.5s |  |
| 101 | `es3_inheritance` | 31 | 1.5s |  |
| 102 | `es4_inheritance` | 30 | 1.6s |  |
| 103 | `es4_interfaces` | 30 | 1.6s |  |
| 104 | `es4_method_binding` | 8 | 1.5s |  |
| 105 | `es4_oop_prototypes` | 14 | 1.6s |  |
| 106 | `es4_protected_inheritance` | 6 | 1.5s |  |
| 107 | `event_bubbles` | 2 | 1.5s |  |
| 108 | `event_cancelable` | 2 | 1.4s |  |
| 109 | `event_type` | 1 | 1.5s |  |
| 110 | `eventdispatcher_dispatchevent_this` | 5 | 1.5s |  |
| 111 | `eventdispatcher_haseventlistener` | 25 | 1.5s |  |
| 112 | `falsiness` | 30 | 1.5s |  |
| 113 | `finddef` | 3 | 1.5s |  |
| 114 | `findprop_global_prototype` | 6 | 1.5s |  |
| 115 | `function_call` | 12 | 1.7s |  |
| 116 | `function_call_arguments` | 46 | 1.7s |  |
| 117 | `function_call_arguments_enumerate` | 5 | 1.6s |  |
| 118 | `function_call_coercion` | 108 | 1.8s |  |
| 119 | `function_call_default` | 6 | 1.6s |  |
| 120 | `function_call_rest` | 22 | 1.6s |  |
| 121 | `function_call_types` | 3 | 1.6s |  |
| 122 | `function_call_via_apply` | 11 | 1.6s |  |
| 123 | `function_call_via_call` | 3 | 1.6s |  |
| 124 | `function_display_anonymous` | 7 | 1.6s |  |
| 125 | `function_length` | 6 | 1.6s |  |
| 126 | `function_object` | 2 | 1.6s |  |
| 127 | `function_proto` | 5 | 1.6s |  |
| 128 | `function_to_locale_string` | 4 | 1.6s |  |
| 129 | `function_to_string` | 4 | 1.5s |  |
| 130 | `function_type` | 6 | 1.6s |  |
| 131 | `function_unbound_this` | 51 | 1.7s |  |
| 132 | `function_value_of` | 4 | 1.6s |  |
| 133 | `get_slot_edge_cases` | 1 | 1.5s |  |
| 134 | `getglobalslot` | 1 | 1.5s |  |
| 135 | `getouterscope` | 8 | 1.5s |  |
| 136 | `getter_different_namespace_setter` | 2 | 1.6s |  |
| 137 | `graphics_round_rects` | 0 | 1.6s |  |
| 138 | `greaterequals` | 512 | 6.0s |  |
| 139 | `greaterthan` | 512 | 1.9s |  |
| 140 | `has_own_property` | 102 | 1.4s |  |
| 141 | `hasownproperty_namespaces` | 2 | 1.1s |  |
| 142 | `hello_world` | 1 | 1.1s |  |
| 143 | `if_eq` | 10 | 1.2s |  |
| 144 | `if_gt` | 1 | 1.2s |  |
| 145 | `if_gte` | 10 | 1.1s |  |
| 146 | `if_lt` | 1 | 0.3s |  |
| 147 | `if_lte` | 10 | 0.3s |  |
| 148 | `if_ne` | 7 | 1.1s |  |
| 149 | `if_stricteq` | 6 | 1.1s |  |
| 150 | `if_strictne` | 11 | 1.2s |  |
| 151 | `in` | 102 | 1.4s |  |
| 152 | `inclocal` | 46 | 1.2s |  |
| 153 | `inclocal_i` | 46 | 1.2s |  |
| 154 | `increment` | 46 | 1.1s |  |
| 155 | `increment_i` | 46 | 1.1s |  |
| 156 | `instanceof` | 58 | 1.3s |  |
| 157 | `int_constr` | 92 | 1.3s |  |
| 158 | `int_edge_cases` | 19 | 1.2s |  |
| 159 | `int_instanceof` | 3 | 1.1s |  |
| 160 | `int_tofixed` | 1215 | 1.1s |  |
| 161 | `int_tostring` | 3375 | 1.3s |  |
| 162 | `interface_namespaces` | 78 | 1.3s |  |
| 163 | `is_finite` | 46 | 1.2s |  |
| 164 | `is_nan` | 46 | 1.1s |  |
| 165 | `is_prototype_of` | 12 | 1.2s |  |
| 166 | `issue_10221` | 2 | 1.1s |  |
| 167 | `issue_14901` | 1 | 1.5s |  |
| 168 | `istype` | 24 | 1.5s |  |
| 169 | `istypelate` | 58 | 1.7s |  |
| 170 | `istypelate_coerce` | 198 | 1.9s |  |
| 171 | `json_errors` | 9 | 19.6s |  |
| 172 | `json_parse` | 21 | 1.5s |  |
| 173 | `json_version_gated` | 1 | 1.4s |  |
| 174 | `lazyinit` | 17 | 1.6s |  |
| 175 | `lessequals` | 512 | 2.4s |  |
| 176 | `lessthan` | 512 | 2.4s |  |
| 177 | `lshift` | 1058 | 3.6s |  |
| 178 | `math` | 497 | 1.7s |  |
| 179 | `modulo` | 1058 | 3.6s |  |
| 180 | `movieclip_stop` | 1 | 19.8s |  |
| 181 | `multiply` | 1058 | 3.9s |  |
| 182 | `negate` | 30 | 1.5s |  |
| 183 | `newactivation_in_script_init` | 3 | 1.2s |  |
| 184 | `newclass_twice` | 3 | 1.2s |  |
| 185 | `nonconflicting_declarations` | 0 | 1.3s |  |
| 186 | `number_autoconv_array_sort_32bit` | 1 | 1.2s |  |
| 187 | `number_constr` | 58 | 1.3s |  |
| 188 | `number_toexponential` | 378 | 1.3s |  |
| 189 | `number_toexponential2` | 35 | 1.2s |  |
| 190 | `number_tofixed` | 378 | 1.2s |  |
| 191 | `number_toprecision` | 350 | 1.3s |  |
| 192 | `obfuscated_class_names` | 3 | 1.3s |  |
| 193 | `object_enumeration` | 10 | 1.2s |  |
| 194 | `object_prototype` | 4 | 1.3s |  |
| 195 | `object_to_locale_string` | 2 | 1.6s |  |
| 196 | `object_to_string` | 2 | 1.4s |  |
| 197 | `object_value_of` | 2 | 1.2s |  |
| 198 | `op_coerce` | 54 | 0.8s |  |
| 199 | `op_coerce_x` | 54 | 1.3s |  |
| 200 | `op_escxattr` | 2 | 1.3s |  |
| 201 | `op_escxelem` | 2 | 1.4s |  |
| 202 | `op_lookupswitch` | 4 | 1.4s |  |
| 203 | `optimize_coerce` | 1 | 1.2s |  |
| 204 | `param_default_value_has_zero_cpool_index` | 1 | 1.6s |  |
| 205 | `parse_float` | 80 | 1.8s |  |
| 206 | `primitive_edge_cases` | 1 | 1.1s |  |
| 207 | `property_priority` | 22 | 1.4s |  |
| 208 | `property_priority_three_level` | 6 | 1.2s |  |
| 209 | `propertyisenumerable_namespaces` | 6 | 1.3s |  |
| 210 | `prototype_set_null` | 7 | 1.1s |  |
| 211 | `regexp_constr` | 148 | 1.4s |  |
| 212 | `regexp_exec` | 19 | 1.2s |  |
| 213 | `regexp_extended` | 47 | 1.1s |  |
| 214 | `regexp_multiargs` | 1 | 1.1s |  |
| 215 | `regexp_test` | 27 | 6.5s |  |
| 216 | `regexp_toString` | 10 | 1.6s |  |
| 217 | `resolve_order` | 4 | 1.6s |  |
| 218 | `rng` | 1 | 2.9s |  |
| 219 | `rshift` | 1058 | 4.0s |  |
| 220 | `set_property_is_enumerable` | 85 | 1.9s |  |
| 221 | `slot_disp_id_shared_numbering` | 1 | 24.9s |  |
| 222 | `slots_force_autoassigned` | 1 | 1.6s |  |
| 223 | `static_var_with_this_in_ctor` | 2 | 1.5s |  |
| 224 | `stored_properties` | 11 | 6.6s |  |
| 225 | `strict_equality` | 34 | 1.7s |  |
| 226 | `string_call` | 13 | 1.7s |  |
| 227 | `string_case` | 23 | 1.7s |  |
| 228 | `string_char_at` | 27 | 1.7s |  |
| 229 | `string_char_code_at` | 28 | 1.6s |  |
| 230 | `string_concat_fromcharcode` | 36 | 1.7s |  |
| 231 | `string_constr` | 25 | 1.7s |  |
| 232 | `string_indexof_lastindexof` | 87 | 1.8s |  |
| 233 | `string_length` | 16 | 1.7s |  |
| 234 | `string_locale_compare` | 39 | 1.8s |  |
| 235 | `string_match` | 51 | 1.8s |  |
| 236 | `string_replace` | 51 | 1.8s |  |
| 237 | `string_search` | 41 | 1.7s |  |
| 238 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 239 | `string_split` | 29 | 1.8s |  |
| 240 | `string_substr_negative` | 21 | 1.6s |  |
| 241 | `string_substr_weird` | 182 | 1.7s |  |
| 242 | `subtract` | 1058 | 4.3s |  |
| 243 | `super_get_call` | 12 | 1.7s |  |
| 244 | `supercall_two_classobjects` | 2 | 1.7s |  |
| 245 | `swf8` | 1 | 1.4s |  |
| 246 | `symbol_class_root_not_zero` | 1 | 1.6s |  |
| 247 | `symbolclass_invalid_utf8` | 2 | 1.6s |  |
| 248 | `throw` | 3 | 1.6s |  |
| 249 | `truthiness` | 30 | 1.6s |  |
| 250 | `try_catch` | 11 | 1.8s |  |
| 251 | `try_catch_typed` | 12 | 1.7s |  |
| 252 | `typeof` | 30 | 1.7s |  |
| 253 | `uint_constr` | 92 | 1.7s |  |
| 254 | `uint_tofixed` | 1215 | 1.5s |  |
| 255 | `uint_tostring` | 3375 | 1.8s |  |
| 256 | `unchecked_function` | 15 | 1.6s |  |
| 257 | `urshift` | 1058 | 3.9s |  |
| 258 | `vector_class` | 36 | 2.0s |  |
| 259 | `vector_class_call` | 11 | 1.8s |  |
| 260 | `vector_coercion` | 66 | 2.2s |  |
| 261 | `vector_concat` | 90 | 1.9s |  |
| 262 | `vector_constr` | 107 | 1.8s |  |
| 263 | `vector_enumeration` | 5 | 1.6s |  |
| 264 | `vector_every` | 92 | 2.0s |  |
| 265 | `vector_filter` | 95 | 2.0s |  |
| 266 | `vector_holes` | 24 | 1.7s |  |
| 267 | `vector_indexof` | 302 | 2.5s |  |
| 268 | `vector_insertat` | 270 | 2.0s |  |
| 269 | `vector_int_access` | 4 | 1.6s |  |
| 270 | `vector_int_delete` | 11 | 1.6s |  |
| 271 | `vector_join` | 58 | 1.9s |  |
| 272 | `vector_lastindexof` | 302 | 1.6s |  |
| 273 | `vector_legacy` | 10 | 1.6s |  |
| 274 | `vector_map` | 85 | 1.9s |  |
| 275 | `vector_object_final` | 1 | 8.2s |  |
| 276 | `vector_object_toString` | 10 | 0.7s |  |
| 277 | `vector_pushpop` | 255 | 1.3s |  |
| 278 | `vector_reborrow_bug` | 10 | 0.7s |  |
| 279 | `vector_removeat` | 172 | 1.1s |  |
| 280 | `vector_reverse` | 232 | 1.1s |  |
| 281 | `vector_shiftunshift` | 252 | 0.6s |  |
| 282 | `vector_slice` | 331 | 1.2s |  |
| 283 | `vector_sort` | 905 | 2.6s |  |
| 284 | `vector_splice` | 693 | 1.6s |  |
| 285 | `vector_splice_fixed_bug_compat` | 4 | 0.7s |  |
| 286 | `vector_tostring` | 79 | 0.9s |  |
| 287 | `verify_abnormal_loop` | 1 | 0.7s |  |
| 288 | `verify_exception_targets_edge_case` | 1 | 0.7s |  |
| 289 | `verify_lookup_switch_edge_case` | 1 | 0.6s |  |
| 290 | `verify_unreachable_exception` | 2 | 0.6s |  |
| 291 | `versioned_isplaying` | 2 | 0.7s |  |
| 292 | `virtual_properties` | 16 | 0.8s |  |
| 293 | `with` | 4 | 0.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**37 tests** within reach

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
| 11 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 12 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 13 | `event_valueof_tostring` | 77.8% | 14 | 18 | 4 |  |
| 14 | `eventdispatcher_dispatchevent` | 75.0% | 9 | 12 | 3 |  |
| 15 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 16 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 17 | `number_autoconv` | 71.4% | 15 | 21 | 6 |  |
| 18 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 19 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 20 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 21 | `fast_index_access` | 66.7% | 8 | 12 | 4 |  |
| 22 | `xml_hasownproperty` | 66.7% | 4 | 6 | 2 |  |
| 23 | `xml_contains` | 66.5% | 131 | 197 | 66 |  |
| 24 | `nested_iteration` | 63.6% | 7 | 11 | 4 |  |
| 25 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15 | 24 | 9 |  |
| 26 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 27 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 28 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 29 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 30 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 31 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 32 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 33 | `place_object_same_depth_frame` | 50.0% | 1 | 2 | 1 |  |
| 34 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 35 | `subclass_superclass_linked_symbol` | 50.0% | 3 | 6 | 3 |  |
| 36 | `verification` | 50.0% | 4 | 8 | 4 |  |
| 37 | `xml_equals_namespace_check` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**44 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `applicationdomain_getqualifieddefinitionnames` | exit code 1 | 1.4s |  |
| 2 | `bitmap_subclass` | exit code 1 | 2.8s |  |
| 3 | `bitmapdata_constructor_from_timeline` | exit code 1 | 1.4s |  |
| 4 | `checkfilter` | exit code 1 | 1.6s |  |
| 5 | `content_element_basic` | exit code 1 | 1.7s |  |
| 6 | `core_exceptions` | exit code 1 | 2.2s |  |
| 7 | `dictionary_access_no_pubns` | exit code 1 | 1.5s |  |
| 8 | `doabc_is_eager` | exit code 1 | 15.3s |  |
| 9 | `domain_memory` | exit code 1 | 1.2s |  |
| 10 | `edittext_at_point_methods_basic` | exit code 1 | 2.1s |  |
| 11 | `edittext_autosize_height_input` | exit code 1 | 1.3s |  |
| 12 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 2.2s |  |
| 13 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 1.4s |  |
| 14 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.3s |  |
| 15 | `edittext_empty_text_format` | exit code 1 | 1.3s |  |
| 16 | `edittext_get_line_index_of_char` | exit code 1 | 2.8s |  |
| 17 | `edittext_getcharboundaries` | exit code 1 | 2.0s |  |
| 18 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.7s |  |
| 19 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.7s |  |
| 20 | `edittext_line_methods` | exit code 1 | 2.6s |  |
| 21 | `edittext_line_metrics` | exit code 1 | 22.1s |  |
| 22 | `edittext_max_scroll_h_basic` | exit code 1 | 1.7s |  |
| 23 | `edittext_max_scroll_v_basic` | exit code 1 | 1.7s |  |
| 24 | `edittext_mouse_selection` | exit code 1 | 21.7s |  |
| 25 | `edittext_wordwrap_word` | exit code 1 | 1.8s |  |
| 26 | `edittext_wrap_breaks` | exit code 1 | 1.9s |  |
| 27 | `error_stack_trace` | exit code 1 | 1.5s |  |
| 28 | `font_enumeratefonts_filter` | exit code 1 | 2.2s |  |
| 29 | `font_enumeratefonts_order` | exit code 1 | 2.4s |  |
| 30 | `large_preload_from_bytes` | exit code 1 | 1.6s |  |
| 31 | `large_preload_image_from_bytes` | exit code 1 | 1.7s |  |
| 32 | `method_without_body` | exit code 1 | 19.3s |  |
| 33 | `mouse_wheel_events` | exit code 1 | 20.6s |  |
| 34 | `namespace_constr` | exit code 1 | 1.7s |  |
| 35 | `negative_volume_panned` | exit code 1 (output matches) | 1.7s |  |
| 36 | `property_priority_scope_cache_order` | exit code 1 | 16.7s |  |
| 37 | `rtqname_not_namespace` | exit code 1 | 1.6s |  |
| 38 | `supercalls_weird` | exit code 1 | 1.6s |  |
| 39 | `symbol_class_binary_data` | exit code 1 | 1.7s |  |
| 40 | `textline_splitting_basic` | exit code 1 | 1.9s |  |
| 41 | `verify_typecheck` | exit code 1 | 0.7s |  |
| 42 | `xml_descendants` | exit code 1 | 1.6s |  |
| 43 | `xml_explicit_use_namespace` | exit code 1 | 1.6s |  |
| 44 | `xml_getdescendants_qname` | exit code 1 | 1.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**635 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 12 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 13 | `event_valueof_tostring` | 77.8% | 14/18 | 18 | 18 |  |
| 14 | `eventdispatcher_dispatchevent` | 75.0% | 9/12 | 12 | 12 |  |
| 15 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 16 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 17 | `number_autoconv` | 71.4% | 15/21 | 16 | 21 |  |
| 18 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 19 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 20 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 21 | `fast_index_access` | 66.7% | 8/12 | 8 | 12 |  |
| 22 | `xml_hasownproperty` | 66.7% | 4/6 | 6 | 6 |  |
| 23 | `xml_contains` | 66.5% | 131/197 | 197 | 197 |  |
| 24 | `nested_iteration` | 63.6% | 7/11 | 7 | 11 |  |
| 25 | `eventdispatcher_dispatchevent_handlerorder` | 62.5% | 15/24 | 24 | 22 |  |
| 26 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 27 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 28 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 29 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 30 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 31 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 32 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 33 | `place_object_same_depth_frame` | 50.0% | 1/2 | 2 | 1 |  |
| 34 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 35 | `subclass_superclass_linked_symbol` | 50.0% | 3/6 | 6 | 4 |  |
| 36 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 37 | `xml_equals_namespace_check` | 50.0% | 1/2 | 2 | 2 |  |
| 38 | `xml_mismatched_tag` | 45.9% | 17/37 | 34 | 37 |  |
| 39 | `get_definition_by_name` | 45.5% | 5/11 | 5 | 11 |  |
| 40 | `eventdispatcher_dispatchevent_cancel` | 45.0% | 9/20 | 9 | 20 |  |
| 41 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 42 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 43 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 44 | `dictionary_iter_modify` | 37.5% | 3/8 | 4 | 8 |  |
| 45 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 46 | `event_clone_error_redispatch` | 33.3% | 1/3 | 2 | 3 |  |
| 47 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 48 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 49 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 50 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 51 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 52 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 53 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 54 | `function_proto_created` | 31.1% | 19/61 | 19 | 61 |  |
| 55 | `event_clone` | 30.0% | 6/20 | 6 | 20 |  |
| 56 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 57 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 58 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 59 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 60 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 61 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 62 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 63 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 64 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 65 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 66 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 67 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 68 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 69 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 70 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 71 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 72 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 73 | `event_clone_on_redispatch` | 20.0% | 2/10 | 8 | 10 |  |
| 74 | `event_target_getter` | 20.0% | 1/5 | 2 | 5 |  |
| 75 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 76 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 77 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 78 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 79 | `event_isdefaultprevented` | 16.7% | 2/12 | 2 | 12 |  |
| 80 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 81 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 82 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 83 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 84 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 85 | `class_call` | 15.6% | 5/32 | 5 | 32 |  |
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
| 96 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 97 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 98 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 99 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 100 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 101 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 102 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 103 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 104 | `amf_dictionary` | 11.1% | 1/9 | 1 | 9 |  |
| 105 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 106 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 107 | `event_target_set` | 11.1% | 1/9 | 9 | 9 |  |
| 108 | `eventdispatcher_dispatchevent_indirect` | 11.1% | 1/9 | 1 | 9 |  |
| 109 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 110 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 111 | `qname_enumeration` | 11.1% | 1/9 | 1 | 9 |  |
| 112 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 113 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 114 | `event_formattostring` | 9.7% | 3/31 | 3 | 31 |  |
| 115 | `construct_frame_list` | 9.1% | 2/22 | 2 | 22 |  |
| 116 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 117 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 118 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 119 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 120 | `goto_in_constructframe` | 8.3% | 1/12 | 1 | 12 |  |
| 121 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 122 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 123 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 124 | `qname_constr_namespace` | 8.3% | 2/24 | 2 | 24 |  |
| 125 | `xml_tostring_namespace` | 8.3% | 1/12 | 1 | 12 |  |
| 126 | `button_nested_frame_simple` | 7.4% | 2/27 | 3 | 27 |  |
| 127 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 128 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 129 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 130 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 131 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 132 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 133 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 134 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 135 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 136 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 137 | `goto_nested_construct_sibling` | 5.6% | 1/18 | 6 | 18 |  |
| 138 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 139 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 140 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 141 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 142 | `get_qualified_class_name` | 5.0% | 1/20 | 1 | 20 |  |
| 143 | `xml_list_concat` | 5.0% | 1/20 | 1 | 20 |  |
| 144 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 145 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 146 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 147 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 148 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 149 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 150 | `button_nested_frame` | 4.2% | 2/48 | 3 | 48 |  |
| 151 | `bytearray_writeobject` | 4.2% | 1/24 | 1 | 24 |  |
| 152 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 153 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 154 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 155 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 156 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 157 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 158 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 159 | `qname_tostring` | 4.0% | 1/25 | 1 | 25 |  |
| 160 | `amf_custom_obj` | 3.8% | 1/26 | 1 | 26 |  |
| 161 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 162 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 163 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 164 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 165 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 166 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 167 | `dictionary_primitive_keys` | 3.4% | 1/29 | 1 | 29 |  |
| 168 | `qname_valueof` | 3.4% | 1/29 | 1 | 29 |  |
| 169 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 170 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 171 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 172 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 173 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 174 | `qname_constr` | 3.1% | 1/32 | 1 | 32 |  |
| 175 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 176 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 177 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 178 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 179 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 180 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 181 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 182 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 183 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 184 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 185 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 186 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 187 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 188 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 189 | `dictionary_foreach` | 2.4% | 1/42 | 1 | 42 |  |
| 190 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 191 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 192 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 193 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 194 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 195 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 196 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 197 | `amf_function` | 2.2% | 1/46 | 1 | 46 |  |
| 198 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 199 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 200 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 201 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 202 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 203 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 204 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 205 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 206 | `orphan_movie_reorder` | 1.8% | 2/111 | 2 | 111 |  |
| 207 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 208 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 209 | `displayobjectcontainer_addchild_timelinepull1` | 1.7% | 1/60 | 1 | 60 |  |
| 210 | `flash_xml_removeNode` | 1.7% | 1/60 | 1 | 60 |  |
| 211 | `displacement_map_filter` | 1.6% | 1/61 | 1 | 61 |  |
| 212 | `dictionary_access` | 1.6% | 1/62 | 1 | 62 |  |
| 213 | `dictionary_in` | 1.6% | 1/62 | 1 | 62 |  |
| 214 | `displayobjectcontainer_addchild_timelinepull2` | 1.6% | 1/62 | 1 | 62 |  |
| 215 | `dictionary_hasownproperty` | 1.6% | 1/63 | 1 | 63 |  |
| 216 | `edittext_newline_stripping` | 1.6% | 1/64 | 1 | 64 |  |
| 217 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 218 | `displayobjectcontainer_contains` | 1.5% | 1/66 | 1 | 66 |  |
| 219 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 220 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 221 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 222 | `simplebutton_childevents` | 1.2% | 1/86 | 1 | 86 |  |
| 223 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 224 | `dictionary_delete` | 1.0% | 1/101 | 1 | 101 |  |
| 225 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 226 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 227 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 228 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 229 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 230 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 231 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 232 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 233 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 234 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 235 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 236 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 237 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 238 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 239 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 240 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 241 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 242 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 243 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 244 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 245 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 246 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 247 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 248 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 249 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 251 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 252 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 253 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 254 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 255 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 256 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 257 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 258 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 259 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 260 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 261 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 262 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 263 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 264 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 265 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 266 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 267 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 268 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 269 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 270 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 271 | `amf_invalid_date` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `amf_missing_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 273 | `amf_nondynamic_function_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 274 | `amf_setter_error` | 0.0% | 0/8 | 0 | 8 |  |
| 275 | `amf_vector` | 0.0% | 0/40 | 0 | 40 |  |
| 276 | `amf_xml` | 0.0% | 0/6 | 0 | 6 |  |
| 277 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 278 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 279 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 280 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 281 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 282 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 283 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 284 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 285 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 286 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 287 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 288 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 289 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 290 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 291 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 292 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 293 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 294 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 295 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 296 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 297 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 298 | `bom` | 0.0% | 0/9 | 0 | 9 |  |
| 299 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 300 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 302 | `bytearray` | 0.0% | 0/48 | 0 | 48 |  |
| 303 | `bytearray_compress` | 0.0% | 0/31 | 0 | 31 |  |
| 304 | `bytearray_errors` | 0.0% | 0/24 | 0 | 24 |  |
| 305 | `bytearray_method_serialization` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `bytearray_readobject_amf0` | 0.0% | 0/50 | 0 | 50 |  |
| 307 | `bytearray_readobject_amf3` | 0.0% | 0/53 | 0 | 53 |  |
| 308 | `bytearray_readutf8bytes_with_bom` | 0.0% | 0/16 | 0 | 16 |  |
| 309 | `bytearray_serialization` | 0.0% | 0/3 | 0 | 3 |  |
| 310 | `bytearray_string_null` | 0.0% | 0/19 | 0 | 19 |  |
| 311 | `bytearray_tostring` | 0.0% | 0/15 | 0 | 15 |  |
| 312 | `bytearray_utf16` | 0.0% | 0/8 | 0 | 8 |  |
| 313 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 314 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 315 | `coerce_to_primitive_side_effects` | 0.0% | 0/29 | 0 | 29 |  |
| 316 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 317 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 318 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 319 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 320 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 321 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 322 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 323 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 324 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 325 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 326 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 327 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 328 | `describe_type_basic` | 0.0% | 0/152 | 0 | 152 |  |
| 329 | `describe_type_json` | 0.0% | 0/301 | 0 | 301 |  |
| 330 | `describe_type_metadata` | 0.0% | 0/125 | 0 | 125 |  |
| 331 | `describe_type_native` | 0.0% | 0/23 | 0 | 23 |  |
| 332 | `dictionary_namespaces` | 0.0% | 0/36 | 0 | 36 |  |
| 333 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 334 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 336 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 337 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 338 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 339 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 340 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 341 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 342 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 343 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 344 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 345 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 346 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 347 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 348 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 349 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 350 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 351 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 352 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 353 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 354 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 355 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 356 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 357 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 358 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 359 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 360 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 361 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 362 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 363 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 364 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 365 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 366 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 367 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 368 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 369 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 370 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 371 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 372 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 373 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 374 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 375 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 376 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 377 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 378 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 379 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 380 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 381 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 382 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 383 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 384 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 385 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 386 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 387 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 388 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 389 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 390 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 391 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 392 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 393 | `error_1034_debug_string` | 0.0% | 0/30 | 6 | 30 |  |
| 394 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 395 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 396 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 397 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 398 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 399 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 400 | `flash_xml` | 0.0% | 0/29 | 0 | 29 |  |
| 401 | `flash_xml_cloneNode` | 0.0% | 0/22 | 0 | 22 |  |
| 402 | `flash_xml_namespace` | 0.0% | 0/109 | 0 | 109 |  |
| 403 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 404 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 405 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 406 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 407 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 408 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 409 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 410 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 411 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 412 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 413 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 414 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 415 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 416 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 417 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 418 | `goto_button_nested_framescript` | 0.0% | 0/28 | 1 | 28 |  |
| 419 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 420 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 421 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 422 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 423 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 424 | `indexing_delete` | 0.0% | 0/75 | 0 | 75 |  |
| 425 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 426 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 427 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 428 | `invalid_utf8` | 0.0% | 0/12 | 0 | 12 |  |
| 429 | `issue_13780` | 0.0% | 0/12 | 0 | 12 |  |
| 430 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 431 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 432 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 433 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 434 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 435 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 436 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 437 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 438 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 439 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 440 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 441 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 442 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 443 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 444 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 445 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 446 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 447 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 448 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 449 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 450 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 451 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 452 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 453 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 454 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 455 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 456 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 457 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 458 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 459 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 460 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 461 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 462 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 463 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 464 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 465 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 466 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 467 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 468 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 469 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 470 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 471 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 472 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 473 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 1 | 676 |  |
| 474 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 1 | 2001 |  |
| 475 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 1 | 575 |  |
| 476 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 1 | 562 |  |
| 477 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 1 | 140 |  |
| 478 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 1 | 50 |  |
| 479 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 1 | 144 |  |
| 480 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 481 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 1 | 149 |  |
| 482 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 1 | 48 |  |
| 483 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 1 | 149 |  |
| 484 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 1 | 106 |  |
| 485 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 1 | 44 |  |
| 486 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 1 | 135 |  |
| 487 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 488 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 489 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 490 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 491 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 1 | 9 |  |
| 492 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 1 | 7 |  |
| 493 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 494 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 495 | `namespace_constr_args` | 0.0% | 0/1 | 0 | 1 |  |
| 496 | `namespace_enumeration_order` | 0.0% | 0/7 | 0 | 7 |  |
| 497 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 498 | `net_getClassByAlias` | 0.0% | 0/3 | 2 | 3 |  |
| 499 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 500 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 501 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 502 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 503 | `null_void_types` | 0.0% | 0/8 | 0 | 8 |  |
| 504 | `number_autoconv_amf` | 0.0% | 0/132 | 0 | 132 |  |
| 505 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 506 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 507 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 508 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 509 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 510 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 511 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 512 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 513 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 514 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 515 | `proxy_callproperty` | 0.0% | 0/24 | 0 | 24 |  |
| 516 | `proxy_deleteproperty` | 0.0% | 0/64 | 0 | 64 |  |
| 517 | `proxy_enumeration` | 0.0% | 0/34 | 0 | 34 |  |
| 518 | `proxy_getproperty` | 0.0% | 0/77 | 0 | 77 |  |
| 519 | `proxy_hasownproperty` | 0.0% | 0/8 | 0 | 8 |  |
| 520 | `proxy_hasproperty` | 0.0% | 0/32 | 0 | 32 |  |
| 521 | `proxy_serialize` | 0.0% | 0/9 | 0 | 9 |  |
| 522 | `proxy_setproperty` | 0.0% | 0/42 | 0 | 42 |  |
| 523 | `qname_as_lazy_name_attribute_multiname` | 0.0% | 0/1 | 0 | 1 |  |
| 524 | `qname_indexing` | 0.0% | 0/23 | 0 | 23 |  |
| 525 | `remove_child_clear_field` | 0.0% | 0/88 | 1 | 88 |  |
| 526 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 527 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 528 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 529 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 530 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 531 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 532 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 533 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 534 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 535 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 536 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 2 | 45 |  |
| 537 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 538 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 539 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 540 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 541 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 542 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 543 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 544 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 545 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 546 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 547 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 548 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 549 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 550 | `static_length` | 0.0% | 0/24 | 4 | 24 |  |
| 551 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 552 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 553 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 554 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 555 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 556 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 1 | 6 |  |
| 557 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 558 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 559 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 560 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 561 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 562 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 563 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 564 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 565 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 566 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 567 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 568 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 569 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 570 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 571 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 572 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 573 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 574 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 575 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 576 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 577 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 578 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 579 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 580 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 581 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 582 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 583 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 584 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 585 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 586 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 587 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 588 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 589 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 590 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 591 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 592 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 593 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 594 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 595 | `xml_abstract_equality` | 0.0% | 0/36 | 0 | 36 |  |
| 596 | `xml_advanced` | 0.0% | 0/52 | 13 | 52 |  |
| 597 | `xml_appendchild` | 0.0% | 0/10 | 1 | 10 |  |
| 598 | `xml_appendchild_swf_v21` | 0.0% | 0/13 | 0 | 13 |  |
| 599 | `xml_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 600 | `xml_attribute` | 0.0% | 0/35 | 0 | 35 |  |
| 601 | `xml_attribute_name` | 0.0% | 0/40 | 0 | 40 |  |
| 602 | `xml_basic` | 0.0% | 0/32 | 0 | 32 |  |
| 603 | `xml_child` | 0.0% | 0/25 | 0 | 25 |  |
| 604 | `xml_childindex` | 0.0% | 0/7 | 0 | 7 |  |
| 605 | `xml_children` | 0.0% | 0/43 | 0 | 43 |  |
| 606 | `xml_class_call` | 0.0% | 0/9 | 0 | 9 |  |
| 607 | `xml_copy` | 0.0% | 0/20 | 0 | 20 |  |
| 608 | `xml_ctor_from_tostring` | 0.0% | 0/23 | 0 | 23 |  |
| 609 | `xml_delete` | 0.0% | 0/114 | 0 | 114 |  |
| 610 | `xml_elements` | 0.0% | 0/6 | 0 | 6 |  |
| 611 | `xml_ignore_white` | 0.0% | 0/6 | 2 | 6 |  |
| 612 | `xml_length` | 0.0% | 0/2 | 0 | 2 |  |
| 613 | `xml_list_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 614 | `xml_list_enumerate` | 0.0% | 0/4 | 2 | 4 |  |
| 615 | `xml_methods_settings` | 0.0% | 0/3 | 0 | 3 |  |
| 616 | `xml_namespace` | 0.0% | 0/39 | 0 | 39 |  |
| 617 | `xml_namespace_methods` | 0.0% | 0/245 | 0 | 245 |  |
| 618 | `xml_namespaced_property` | 0.0% | 0/7 | 0 | 7 |  |
| 619 | `xml_no_namespace` | 0.0% | 0/1 | 0 | 1 |  |
| 620 | `xml_nodekind` | 0.0% | 0/3 | 0 | 3 |  |
| 621 | `xml_normalize` | 0.0% | 0/35 | 0 | 35 |  |
| 622 | `xml_notification_bubbling` | 0.0% | 0/361 | 0 | 361 |  |
| 623 | `xml_parent` | 0.0% | 0/8 | 0 | 8 |  |
| 624 | `xml_set_children` | 0.0% | 0/17 | 0 | 17 |  |
| 625 | `xml_set_name` | 0.0% | 0/34 | 0 | 34 |  |
| 626 | `xml_settings` | 0.0% | 0/6 | 0 | 6 |  |
| 627 | `xml_simple_complex_content` | 0.0% | 0/47 | 0 | 47 |  |
| 628 | `xml_text` | 0.0% | 0/7 | 0 | 7 |  |
| 629 | `xml_tostring` | 0.0% | 0/6 | 6 | 6 |  |
| 630 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 631 | `xml_weird_ignores` | 0.0% | 0/56 | 56 | 54 |  |
| 632 | `xml_wildcard` | 0.0% | 0/11 | 0 | 11 |  |
| 633 | `xmldocument` | 0.0% | 0/254 | 0 | 254 |  |
| 634 | `xmlnode` | 0.0% | 0/3540 | 0 | 3540 |  |
| 635 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
