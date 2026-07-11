# Ruffle Test Results (Filtered)

**Date**: 2026-07-11 08:30 UTC

**Git SHA**: `2ceede9620`

**Run Duration**: 76m 0s

**Filtered**: 227 tests ignored out of 1198 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 971 |
| Passing | **236** (24.3%) |
| Failing | 735 |
| Total expected lines | 124376 |
| Matching lines | 34009 (27.3%) |
| Mismatched lines | 90367 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 695 | 94.6% |
| Runtime Error | 40 | 5.4% |

## Passing Tests

**236 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.8s |  |
| 2 | `array_access` | 18 | 1.5s |  |
| 3 | `array_access_interpreter` | 4 | 1.4s |  |
| 4 | `array_access_no_pubns` | 2 | 1.4s |  |
| 5 | `array_concat` | 41 | 1.5s |  |
| 6 | `array_constr` | 10 | 1.4s |  |
| 7 | `array_delete` | 44 | 1.5s |  |
| 8 | `array_enumeration` | 10 | 1.4s |  |
| 9 | `array_enumeration_elements` | 11 | 1.4s |  |
| 10 | `array_every` | 8 | 1.4s |  |
| 11 | `array_filter` | 6 | 1.4s |  |
| 12 | `array_foreach` | 18 | 1.4s |  |
| 13 | `array_hasownproperty` | 11 | 1.4s |  |
| 14 | `array_holes` | 9 | 1.4s |  |
| 15 | `array_index_max` | 84 | 1.2s |  |
| 16 | `array_indexof` | 25 | 1.5s |  |
| 17 | `array_join` | 26 | 1.5s |  |
| 18 | `array_lastindexof` | 29 | 1.5s |  |
| 19 | `array_length` | 14 | 1.5s |  |
| 20 | `array_literal` | 3 | 1.4s |  |
| 21 | `array_map` | 8 | 0.4s |  |
| 22 | `array_pop` | 52 | 1.5s |  |
| 23 | `array_push` | 24 | 1.5s |  |
| 24 | `array_reborrow_bug` | 6 | 1.5s |  |
| 25 | `array_reverse` | 28 | 1.5s |  |
| 26 | `array_shift` | 51 | 1.5s |  |
| 27 | `array_slice` | 39 | 1.5s |  |
| 28 | `array_some` | 8 | 1.5s |  |
| 29 | `array_sort` | 297 | 1.7s |  |
| 30 | `array_sort_fun_swf12` | 2 | 1.5s |  |
| 31 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 32 | `array_sort_random` | 210 | 1.5s |  |
| 33 | `array_sort_swf10_32bit` | 1 | 3.6s |  |
| 34 | `array_sorton` | 545 | 1.8s |  |
| 35 | `array_sparse_ops` | 41 | 1.5s |  |
| 36 | `array_splice` | 133 | 1.5s |  |
| 37 | `array_splice2` | 428 | 1.6s |  |
| 38 | `array_splice_types` | 48 | 1.5s |  |
| 39 | `array_storage` | 8 | 1.4s |  |
| 40 | `array_tolocalestring` | 9 | 1.4s |  |
| 41 | `array_tostring` | 12 | 1.4s |  |
| 42 | `array_unshift` | 24 | 1.4s |  |
| 43 | `array_valueof` | 9 | 1.3s |  |
| 44 | `astype` | 28 | 1.4s |  |
| 45 | `astypelate` | 24 | 1.5s |  |
| 46 | `astypelate_propagates` | 1 | 1.3s |  |
| 47 | `bitand` | 1058 | 3.7s |  |
| 48 | `bitnot` | 46 | 1.5s |  |
| 49 | `bitor` | 1058 | 3.7s |  |
| 50 | `bitxor` | 1058 | 3.7s |  |
| 51 | `boolean_constr` | 32 | 1.4s |  |
| 52 | `boolean_negation` | 30 | 1.4s |  |
| 53 | `boolean_tostring` | 8 | 1.3s |  |
| 54 | `callee_in_initializer` | 6 | 1.3s |  |
| 55 | `callproplex_class` | 1 | 1.3s |  |
| 56 | `catch_class` | 6 | 1.4s |  |
| 57 | `catch_scope_slot` | 7 | 1.4s |  |
| 58 | `class_cast_call` | 14 | 1.4s |  |
| 59 | `class_enumeration` | 4 | 1.4s |  |
| 60 | `class_has_own_property` | 2 | 1.3s |  |
| 61 | `class_init_interpreter_mode` | 1 | 1.3s |  |
| 62 | `class_is` | 32 | 1.4s |  |
| 63 | `class_methods` | 5 | 1.4s |  |
| 64 | `class_object_properties` | 10 | 3.3s |  |
| 65 | `class_singleton` | 18 | 1.1s |  |
| 66 | `class_supercalls_errors` | 35 | 1.3s |  |
| 67 | `class_supercalls_mismatched` | 26 | 1.1s |  |
| 68 | `class_superclass_wrong_order` | 1 | 1.0s |  |
| 69 | `class_to_locale_string` | 2 | 1.1s |  |
| 70 | `class_to_string` | 2 | 1.2s |  |
| 71 | `class_value_of` | 2 | 1.1s |  |
| 72 | `closures` | 12 | 1.1s |  |
| 73 | `coerce_property` | 33 | 1.2s |  |
| 74 | `coerce_return_type` | 40 | 1.2s |  |
| 75 | `coerce_return_type_fail` | 2 | 1.0s |  |
| 76 | `coerce_return_void` | 3 | 1.1s |  |
| 77 | `coerce_string` | 86 | 1.1s |  |
| 78 | `coerce_string_precision` | 28 | 1.1s |  |
| 79 | `construct_errors_swf10` | 8 | 1.3s |  |
| 80 | `constructor_call` | 3 | 1.1s |  |
| 81 | `control_flow_bool` | 4 | 1.1s |  |
| 82 | `control_flow_stricteq` | 8 | 1.1s |  |
| 83 | `convert_boolean` | 30 | 1.1s |  |
| 84 | `convert_integer` | 90 | 1.1s |  |
| 85 | `convert_number` | 56 | 1.1s |  |
| 86 | `convert_uinteger` | 90 | 1.1s |  |
| 87 | `declocal` | 46 | 1.4s |  |
| 88 | `declocal_i` | 46 | 1.4s |  |
| 89 | `decrement` | 46 | 1.4s |  |
| 90 | `decrement_i` | 46 | 1.4s |  |
| 91 | `default_values` | 7 | 1.4s |  |
| 92 | `displayobject_mask_self_referential` | 0 | 1.4s |  |
| 93 | `divide` | 1058 | 3.9s |  |
| 94 | `duplicate_defs` | 1 | 0.4s |  |
| 95 | `eager_init` | 1 | 1.5s |  |
| 96 | `equals` | 512 | 2.4s |  |
| 97 | `es3_inheritance` | 31 | 1.4s |  |
| 98 | `es4_inheritance` | 30 | 1.5s |  |
| 99 | `es4_interfaces` | 30 | 1.5s |  |
| 100 | `es4_method_binding` | 8 | 1.4s |  |
| 101 | `es4_oop_prototypes` | 14 | 1.6s |  |
| 102 | `es4_protected_inheritance` | 6 | 1.4s |  |
| 103 | `falsiness` | 30 | 1.5s |  |
| 104 | `finddef` | 3 | 1.4s |  |
| 105 | `function_call` | 12 | 1.3s |  |
| 106 | `function_call_arguments` | 46 | 1.4s |  |
| 107 | `function_call_arguments_enumerate` | 5 | 1.2s |  |
| 108 | `function_call_coercion` | 108 | 1.5s |  |
| 109 | `function_call_default` | 6 | 1.2s |  |
| 110 | `function_call_rest` | 22 | 1.3s |  |
| 111 | `function_call_types` | 3 | 1.2s |  |
| 112 | `function_call_via_apply` | 11 | 1.3s |  |
| 113 | `function_call_via_call` | 3 | 1.2s |  |
| 114 | `function_display_anonymous` | 7 | 1.3s |  |
| 115 | `function_length` | 6 | 1.3s |  |
| 116 | `function_object` | 2 | 1.3s |  |
| 117 | `function_proto` | 5 | 1.2s |  |
| 118 | `function_to_locale_string` | 4 | 1.4s |  |
| 119 | `function_to_string` | 4 | 1.4s |  |
| 120 | `function_type` | 6 | 1.4s |  |
| 121 | `function_value_of` | 4 | 1.4s |  |
| 122 | `get_slot_edge_cases` | 1 | 1.4s |  |
| 123 | `getglobalslot` | 1 | 1.4s |  |
| 124 | `getouterscope` | 8 | 1.4s |  |
| 125 | `getter_different_namespace_setter` | 2 | 1.4s |  |
| 126 | `graphics_round_rects` | 0 | 1.5s |  |
| 127 | `greaterequals` | 512 | 4.7s |  |
| 128 | `greaterthan` | 512 | 2.3s |  |
| 129 | `has_own_property` | 102 | 1.6s |  |
| 130 | `hasownproperty_namespaces` | 2 | 1.4s |  |
| 131 | `hello_world` | 1 | 1.4s |  |
| 132 | `if_eq` | 10 | 1.4s |  |
| 133 | `if_gt` | 1 | 1.4s |  |
| 134 | `if_gte` | 10 | 1.4s |  |
| 135 | `if_lt` | 1 | 0.4s |  |
| 136 | `if_lte` | 10 | 0.4s |  |
| 137 | `if_ne` | 7 | 1.4s |  |
| 138 | `if_stricteq` | 6 | 1.4s |  |
| 139 | `if_strictne` | 11 | 1.4s |  |
| 140 | `in` | 102 | 1.7s |  |
| 141 | `inclocal` | 46 | 1.5s |  |
| 142 | `inclocal_i` | 46 | 1.5s |  |
| 143 | `increment` | 46 | 1.5s |  |
| 144 | `increment_i` | 46 | 1.5s |  |
| 145 | `instanceof` | 58 | 1.6s |  |
| 146 | `int_constr` | 92 | 1.6s |  |
| 147 | `int_edge_cases` | 19 | 1.5s |  |
| 148 | `int_instanceof` | 3 | 1.4s |  |
| 149 | `int_tofixed` | 1215 | 1.4s |  |
| 150 | `int_tostring` | 3375 | 1.6s |  |
| 151 | `interface_namespaces` | 78 | 1.6s |  |
| 152 | `is_finite` | 46 | 1.5s |  |
| 153 | `is_nan` | 46 | 1.4s |  |
| 154 | `is_prototype_of` | 12 | 1.4s |  |
| 155 | `issue_10221` | 2 | 1.4s |  |
| 156 | `issue_14901` | 1 | 1.1s |  |
| 157 | `istype` | 24 | 1.1s |  |
| 158 | `istypelate` | 58 | 1.2s |  |
| 159 | `istypelate_coerce` | 198 | 1.4s |  |
| 160 | `json_version_gated` | 1 | 1.1s |  |
| 161 | `lazyinit` | 17 | 1.1s |  |
| 162 | `lessequals` | 512 | 1.8s |  |
| 163 | `lessthan` | 512 | 1.8s |  |
| 164 | `lshift` | 1058 | 3.5s |  |
| 165 | `math` | 497 | 1.5s |  |
| 166 | `modulo` | 1058 | 3.5s |  |
| 167 | `movieclip_stop` | 1 | 19.6s |  |
| 168 | `multiply` | 1058 | 3.5s |  |
| 169 | `negate` | 30 | 1.4s |  |
| 170 | `negative_volume_panned` | 0 | 1.5s |  |
| 171 | `newactivation_in_script_init` | 3 | 1.3s |  |
| 172 | `newclass_twice` | 3 | 1.3s |  |
| 173 | `nonconflicting_declarations` | 0 | 1.4s |  |
| 174 | `number_autoconv_array_sort_32bit` | 1 | 1.4s |  |
| 175 | `number_constr` | 58 | 1.5s |  |
| 176 | `number_toexponential` | 378 | 1.5s |  |
| 177 | `number_toexponential2` | 35 | 1.4s |  |
| 178 | `number_tofixed` | 378 | 1.4s |  |
| 179 | `number_toprecision` | 350 | 1.5s |  |
| 180 | `obfuscated_class_names` | 3 | 1.4s |  |
| 181 | `object_enumeration` | 10 | 1.4s |  |
| 182 | `object_prototype` | 4 | 1.5s |  |
| 183 | `object_to_locale_string` | 2 | 1.4s |  |
| 184 | `object_to_string` | 2 | 1.4s |  |
| 185 | `object_value_of` | 2 | 1.2s |  |
| 186 | `op_coerce` | 54 | 0.8s |  |
| 187 | `op_coerce_x` | 54 | 1.5s |  |
| 188 | `op_escxattr` | 2 | 1.4s |  |
| 189 | `op_escxelem` | 2 | 1.4s |  |
| 190 | `op_lookupswitch` | 4 | 1.4s |  |
| 191 | `optimize_coerce` | 1 | 1.3s |  |
| 192 | `param_default_value_has_zero_cpool_index` | 1 | 1.3s |  |
| 193 | `parse_float` | 80 | 1.5s |  |
| 194 | `property_priority` | 22 | 1.8s |  |
| 195 | `property_priority_three_level` | 6 | 1.6s |  |
| 196 | `propertyisenumerable_namespaces` | 6 | 1.5s |  |
| 197 | `rshift` | 1058 | 3.2s |  |
| 198 | `set_property_is_enumerable` | 85 | 1.4s |  |
| 199 | `slot_disp_id_shared_numbering` | 1 | 21.8s |  |
| 200 | `slots_force_autoassigned` | 1 | 1.4s |  |
| 201 | `static_var_with_this_in_ctor` | 2 | 1.5s |  |
| 202 | `stored_properties` | 11 | 4.0s |  |
| 203 | `strict_equality` | 34 | 1.6s |  |
| 204 | `string_call` | 13 | 1.6s |  |
| 205 | `string_case` | 23 | 1.6s |  |
| 206 | `string_char_at` | 27 | 1.7s |  |
| 207 | `string_char_code_at` | 28 | 1.5s |  |
| 208 | `string_concat_fromcharcode` | 36 | 1.6s |  |
| 209 | `string_constr` | 25 | 1.6s |  |
| 210 | `string_indexof_lastindexof` | 87 | 1.6s |  |
| 211 | `string_length` | 16 | 1.6s |  |
| 212 | `string_locale_compare` | 39 | 1.6s |  |
| 213 | `string_slice_substr_substring` | 169 | 1.9s |  |
| 214 | `string_substr_negative` | 21 | 1.5s |  |
| 215 | `string_substr_weird` | 182 | 1.5s |  |
| 216 | `subtract` | 1058 | 4.7s |  |
| 217 | `super_get_call` | 12 | 1.6s |  |
| 218 | `supercall_two_classobjects` | 2 | 1.6s |  |
| 219 | `swf8` | 1 | 1.3s |  |
| 220 | `symbolclass_invalid_utf8` | 2 | 1.4s |  |
| 221 | `throw` | 3 | 1.5s |  |
| 222 | `truthiness` | 30 | 1.5s |  |
| 223 | `try_catch_typed` | 12 | 1.5s |  |
| 224 | `typeof` | 30 | 1.5s |  |
| 225 | `uint_constr` | 92 | 1.6s |  |
| 226 | `uint_tofixed` | 1215 | 1.4s |  |
| 227 | `uint_tostring` | 3375 | 1.6s |  |
| 228 | `unchecked_function` | 15 | 1.4s |  |
| 229 | `urshift` | 1058 | 3.6s |  |
| 230 | `verify_abnormal_loop` | 1 | 0.4s |  |
| 231 | `verify_exception_targets_edge_case` | 1 | 0.4s |  |
| 232 | `verify_lookup_switch_edge_case` | 1 | 0.4s |  |
| 233 | `verify_unreachable_exception` | 2 | 0.4s |  |
| 234 | `versioned_isplaying` | 2 | 0.4s |  |
| 235 | `virtual_properties` | 16 | 0.5s |  |
| 236 | `with` | 4 | 0.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**29 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271 | 1275 | 4 |  |
| 2 | `displayobject_alpha` | 99.6% | 276 | 277 | 1 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 5 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 6 | `xml_has_property_via_in` | 88.5% | 23 | 26 | 3 |  |
| 7 | `interactiveobject_enabled` | 88.0% | 22 | 25 | 3 |  |
| 8 | `prototype_set_null` | 85.7% | 6 | 7 | 1 |  |
| 9 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 10 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 11 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 12 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 13 | `constructprop_dynamic_primitive` | 71.4% | 5 | 7 | 2 |  |
| 14 | `number_autoconv` | 71.4% | 15 | 21 | 6 |  |
| 15 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 16 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 17 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 18 | `xml_hasownproperty` | 66.7% | 4 | 6 | 2 |  |
| 19 | `xml_contains` | 66.5% | 131 | 197 | 66 |  |
| 20 | `nested_iteration` | 63.6% | 7 | 11 | 4 |  |
| 21 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 22 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 23 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 24 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 25 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 26 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 27 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 28 | `verification` | 50.0% | 4 | 8 | 4 |  |
| 29 | `xml_equals_namespace_check` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**40 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `applicationdomain_getqualifieddefinitionnames` | exit code 1 | 1.4s |  |
| 2 | `bitmap_subclass` | exit code 1 | 2.5s |  |
| 3 | `checkfilter` | exit code 1 | 1.4s |  |
| 4 | `content_element_basic` | exit code 1 | 1.3s |  |
| 5 | `core_exceptions` | exit code 1 | 1.6s |  |
| 6 | `dictionary_access_no_pubns` | exit code 1 | 1.4s |  |
| 7 | `doabc_is_eager` | exit code 1 | 20.3s |  |
| 8 | `edittext_at_point_methods_basic` | exit code 1 | 2.8s |  |
| 9 | `edittext_autosize_height_input` | exit code 1 | 1.6s |  |
| 10 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 3.0s |  |
| 11 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 1.7s |  |
| 12 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.6s |  |
| 13 | `edittext_empty_text_format` | exit code 1 | 1.6s |  |
| 14 | `edittext_get_line_index_of_char` | exit code 1 | 2.0s |  |
| 15 | `edittext_getcharboundaries` | exit code 1 | 1.4s |  |
| 16 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.2s |  |
| 17 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.2s |  |
| 18 | `edittext_line_methods` | exit code 1 | 1.9s |  |
| 19 | `edittext_line_metrics` | exit code 1 | 16.5s |  |
| 20 | `edittext_max_scroll_h_basic` | exit code 1 | 1.2s |  |
| 21 | `edittext_max_scroll_v_basic` | exit code 1 | 1.2s |  |
| 22 | `edittext_mouse_selection` | exit code 1 | 16.2s |  |
| 23 | `edittext_wordwrap_word` | exit code 1 | 1.7s |  |
| 24 | `edittext_wrap_breaks` | exit code 1 | 1.8s |  |
| 25 | `error_stack_trace` | exit code 1 | 1.4s |  |
| 26 | `findprop_global_prototype` | exit code 1 | 1.5s |  |
| 27 | `font_enumeratefonts_filter` | exit code 1 | 1.9s |  |
| 28 | `font_enumeratefonts_order` | exit code 1 | 1.9s |  |
| 29 | `large_preload_from_bytes` | exit code 1 | 1.2s |  |
| 30 | `large_preload_image_from_bytes` | exit code 1 | 1.4s |  |
| 31 | `method_without_body` | exit code 1 | 18.9s |  |
| 32 | `mouse_wheel_events` | exit code 1 | 21.1s |  |
| 33 | `namespace_constr` | exit code 1 | 1.6s |  |
| 34 | `property_priority_scope_cache_order` | exit code 1 | 19.9s |  |
| 35 | `rtqname_not_namespace` | exit code 1 | 1.2s |  |
| 36 | `supercalls_weird` | exit code 1 | 1.5s |  |
| 37 | `symbol_class_binary_data` | exit code 1 | 1.5s |  |
| 38 | `xml_descendants` | exit code 1 | 1.5s |  |
| 39 | `xml_explicit_use_namespace` | exit code 1 | 1.6s |  |
| 40 | `xml_getdescendants_qname` | exit code 1 | 1.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**695 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displayobject_rotation` | 99.7% | 1271/1275 | 1275 | 1275 |  |
| 2 | `displayobject_alpha` | 99.6% | 276/277 | 277 | 277 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 5 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 6 | `xml_has_property_via_in` | 88.5% | 23/26 | 26 | 26 |  |
| 7 | `interactiveobject_enabled` | 88.0% | 22/25 | 25 | 25 |  |
| 8 | `prototype_set_null` | 85.7% | 6/7 | 7 | 7 |  |
| 9 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 10 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 11 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 12 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 13 | `constructprop_dynamic_primitive` | 71.4% | 5/7 | 7 | 7 |  |
| 14 | `number_autoconv` | 71.4% | 15/21 | 15 | 21 |  |
| 15 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 16 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 17 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 18 | `xml_hasownproperty` | 66.7% | 4/6 | 6 | 6 |  |
| 19 | `xml_contains` | 66.5% | 131/197 | 197 | 197 |  |
| 20 | `nested_iteration` | 63.6% | 7/11 | 7 | 11 |  |
| 21 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 22 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 23 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 24 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 25 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 26 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 27 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 28 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 29 | `xml_equals_namespace_check` | 50.0% | 1/2 | 2 | 2 |  |
| 30 | `xml_mismatched_tag` | 45.9% | 17/37 | 34 | 37 |  |
| 31 | `get_definition_by_name` | 45.5% | 5/11 | 5 | 11 |  |
| 32 | `try_catch` | 45.5% | 5/11 | 11 | 11 |  |
| 33 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 34 | `eventdispatcher_dispatchevent_this` | 40.0% | 2/5 | 2 | 5 |  |
| 35 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 36 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 37 | `dictionary_iter_modify` | 37.5% | 3/8 | 4 | 8 |  |
| 38 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 39 | `function_unbound_this` | 37.3% | 19/51 | 19 | 51 |  |
| 40 | `string_split` | 34.5% | 10/29 | 10 | 29 |  |
| 41 | `fast_index_access` | 33.3% | 4/12 | 4 | 12 |  |
| 42 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 43 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 44 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 45 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 46 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 48 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 49 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 50 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 51 | `function_proto_created` | 29.5% | 18/61 | 18 | 61 |  |
| 52 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 53 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 54 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 55 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 56 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 57 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 58 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 59 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 60 | `resolve_order` | 25.0% | 1/4 | 1 | 4 |  |
| 61 | `vector_int_access` | 25.0% | 1/4 | 1 | 4 |  |
| 62 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 63 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 64 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 65 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 66 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 67 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 68 | `event_target_getter` | 20.0% | 1/5 | 1 | 5 |  |
| 69 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 70 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 71 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 72 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 73 | `eventdispatcher_dispatchevent` | 16.7% | 2/12 | 2 | 12 |  |
| 74 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 75 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 76 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 77 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 78 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 79 | `movieclip_gotoandstop` | 15.4% | 2/13 | 2 | 13 |  |
| 80 | `doabc_and_symbolclass_script_init_goto` | 14.3% | 1/7 | 5 | 7 |  |
| 81 | `movieclip_goto_overwrite` | 14.3% | 2/14 | 2 | 14 |  |
| 82 | `movieclip_gotoandstop_framescripts_self` | 14.3% | 1/7 | 1 | 7 |  |
| 83 | `movieclip_prev_scene` | 14.3% | 1/7 | 1 | 7 |  |
| 84 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 85 | `movieclip_goto_during_frame_script` | 13.3% | 2/15 | 2 | 15 |  |
| 86 | `movieclip_gotoandplay` | 13.3% | 2/15 | 2 | 15 |  |
| 87 | `stage_mouseenabled` | 13.3% | 2/15 | 2 | 15 |  |
| 88 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 89 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 90 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 91 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 92 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 93 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 94 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 95 | `eventdispatcher_haseventlistener` | 12.0% | 3/25 | 3 | 25 |  |
| 96 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 97 | `amf_dictionary` | 11.1% | 1/9 | 1 | 9 |  |
| 98 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 99 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 100 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 101 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 102 | `qname_enumeration` | 11.1% | 1/9 | 1 | 9 |  |
| 103 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 104 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 105 | `eventdispatcher_dispatchevent_cancel` | 10.0% | 2/20 | 2 | 20 |  |
| 106 | `vector_legacy` | 10.0% | 1/10 | 1 | 10 |  |
| 107 | `vector_object_toString` | 10.0% | 1/10 | 1 | 10 |  |
| 108 | `eventdispatcher_dispatchevent_handlerorder` | 9.1% | 2/22 | 2 | 22 |  |
| 109 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 110 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 111 | `vector_int_delete` | 9.1% | 1/11 | 1 | 11 |  |
| 112 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 113 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 114 | `event_isdefaultprevented` | 8.3% | 1/12 | 1 | 12 |  |
| 115 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 116 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 117 | `qname_constr_namespace` | 8.3% | 2/24 | 2 | 24 |  |
| 118 | `xml_tostring_namespace` | 8.3% | 1/12 | 1 | 12 |  |
| 119 | `button_nested_frame_simple` | 7.4% | 2/27 | 2 | 27 |  |
| 120 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 121 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 122 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 123 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 124 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 125 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 126 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 127 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 128 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 129 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 130 | `event_valueof_tostring` | 5.6% | 1/18 | 1 | 18 |  |
| 131 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 132 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 133 | `regexp_exec` | 5.3% | 1/19 | 1 | 19 |  |
| 134 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 135 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 136 | `get_qualified_class_name` | 5.0% | 1/20 | 1 | 20 |  |
| 137 | `xml_list_concat` | 5.0% | 1/20 | 1 | 20 |  |
| 138 | `string_search` | 4.9% | 2/41 | 2 | 41 |  |
| 139 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 140 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 141 | `construct_frame_list` | 4.5% | 1/22 | 1 | 22 |  |
| 142 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 143 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 144 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 145 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 146 | `button_nested_frame` | 4.2% | 2/48 | 2 | 48 |  |
| 147 | `bytearray_writeobject` | 4.2% | 1/24 | 1 | 24 |  |
| 148 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 149 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 150 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 151 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 152 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 153 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 154 | `vector_holes` | 4.2% | 1/24 | 1 | 24 |  |
| 155 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 156 | `qname_tostring` | 4.0% | 1/25 | 1 | 25 |  |
| 157 | `string_match` | 3.9% | 2/51 | 2 | 51 |  |
| 158 | `amf_custom_obj` | 3.8% | 1/26 | 1 | 26 |  |
| 159 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 160 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 161 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 162 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 163 | `regexp_test` | 3.7% | 1/27 | 1 | 27 |  |
| 164 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 165 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 166 | `dictionary_primitive_keys` | 3.4% | 1/29 | 1 | 29 |  |
| 167 | `qname_valueof` | 3.4% | 1/29 | 1 | 29 |  |
| 168 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 169 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 170 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 171 | `class_call` | 3.1% | 1/32 | 1 | 32 |  |
| 172 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 173 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 174 | `qname_constr` | 3.1% | 1/32 | 1 | 32 |  |
| 175 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 176 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 177 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 178 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 179 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 180 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 181 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 182 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 183 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 184 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 185 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 186 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 187 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 188 | `dictionary_foreach` | 2.4% | 1/42 | 1 | 42 |  |
| 189 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 190 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 191 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 192 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 193 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 194 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 195 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 196 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 197 | `regexp_extended` | 2.1% | 1/47 | 1 | 47 |  |
| 198 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 199 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 200 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 201 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 202 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 203 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 204 | `string_replace` | 2.0% | 1/51 | 1 | 51 |  |
| 205 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 206 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 207 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 208 | `vector_join` | 1.7% | 1/58 | 1 | 58 |  |
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
| 220 | `vector_coercion` | 1.5% | 1/66 | 1 | 66 |  |
| 221 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 222 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 223 | `vector_tostring` | 1.3% | 1/79 | 1 | 79 |  |
| 224 | `vector_map` | 1.2% | 1/85 | 1 | 85 |  |
| 225 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 226 | `vector_concat` | 1.1% | 1/90 | 1 | 90 |  |
| 227 | `vector_every` | 1.1% | 1/92 | 1 | 92 |  |
| 228 | `vector_filter` | 1.1% | 1/95 | 1 | 95 |  |
| 229 | `dictionary_delete` | 1.0% | 1/101 | 1 | 101 |  |
| 230 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 231 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 232 | `vector_constr` | 0.9% | 1/107 | 1 | 107 |  |
| 233 | `orphan_movie_reorder` | 0.9% | 1/111 | 1 | 111 |  |
| 234 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 235 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 236 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 237 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 238 | `domain_memory` | 0.8% | 1/133 | 1 | 133 |  |
| 239 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 240 | `regexp_constr` | 0.7% | 1/148 | 1 | 148 |  |
| 241 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 242 | `vector_removeat` | 0.6% | 1/172 | 1 | 172 |  |
| 243 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 244 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 245 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 246 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 247 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 248 | `vector_reverse` | 0.4% | 1/232 | 1 | 232 |  |
| 249 | `vector_shiftunshift` | 0.4% | 1/252 | 1 | 252 |  |
| 250 | `vector_pushpop` | 0.4% | 1/255 | 1 | 255 |  |
| 251 | `vector_insertat` | 0.4% | 1/270 | 1 | 270 |  |
| 252 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 253 | `vector_indexof` | 0.3% | 1/302 | 1 | 302 |  |
| 254 | `vector_lastindexof` | 0.3% | 1/302 | 1 | 302 |  |
| 255 | `vector_slice` | 0.3% | 1/331 | 1 | 331 |  |
| 256 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 257 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 258 | `vector_splice` | 0.1% | 1/693 | 1 | 693 |  |
| 259 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 260 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 261 | `vector_sort` | 0.1% | 1/905 | 1 | 905 |  |
| 262 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 263 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 264 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 265 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 266 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 267 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 268 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 269 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 270 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 271 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 272 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 273 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 274 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 275 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 276 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 277 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 278 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 279 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 280 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 281 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 282 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 283 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 284 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 285 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 286 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 287 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 288 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 289 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 290 | `amf_function` | 0.0% | 0/46 | 0 | 46 |  |
| 291 | `amf_invalid_date` | 0.0% | 0/2 | 0 | 2 |  |
| 292 | `amf_missing_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 293 | `amf_nondynamic_function_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 294 | `amf_setter_error` | 0.0% | 0/8 | 0 | 8 |  |
| 295 | `amf_vector` | 0.0% | 0/40 | 0 | 40 |  |
| 296 | `amf_xml` | 0.0% | 0/6 | 0 | 6 |  |
| 297 | `appdomain_lookup_edge_cases` | 0.0% | 0/32 | 0 | 32 |  |
| 298 | `application_domain` | 0.0% | 0/4 | 2 | 4 |  |
| 299 | `applicationdomain_hasdefinition_null` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `array_vector_null_callback` | 0.0% | 0/10 | 0 | 10 |  |
| 301 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 302 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 303 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 305 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 306 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 310 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 311 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 312 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 313 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 314 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 315 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 316 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 317 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 318 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 319 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 320 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 321 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 322 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 323 | `bom` | 0.0% | 0/9 | 0 | 9 |  |
| 324 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 325 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 326 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 327 | `bytearray` | 0.0% | 0/48 | 0 | 48 |  |
| 328 | `bytearray_compress` | 0.0% | 0/31 | 0 | 31 |  |
| 329 | `bytearray_errors` | 0.0% | 0/24 | 0 | 24 |  |
| 330 | `bytearray_method_serialization` | 0.0% | 0/1 | 0 | 1 |  |
| 331 | `bytearray_readobject_amf0` | 0.0% | 0/50 | 0 | 50 |  |
| 332 | `bytearray_readobject_amf3` | 0.0% | 0/53 | 0 | 53 |  |
| 333 | `bytearray_readutf8bytes_with_bom` | 0.0% | 0/16 | 0 | 16 |  |
| 334 | `bytearray_serialization` | 0.0% | 0/3 | 0 | 3 |  |
| 335 | `bytearray_string_null` | 0.0% | 0/19 | 0 | 19 |  |
| 336 | `bytearray_tostring` | 0.0% | 0/15 | 0 | 15 |  |
| 337 | `bytearray_utf16` | 0.0% | 0/8 | 0 | 8 |  |
| 338 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 339 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 340 | `coerce_to_primitive_side_effects` | 0.0% | 0/29 | 0 | 29 |  |
| 341 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 342 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 343 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 344 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 345 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 346 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 347 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 348 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 349 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 350 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 351 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 352 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 353 | `describe_type_basic` | 0.0% | 0/152 | 0 | 152 |  |
| 354 | `describe_type_json` | 0.0% | 0/301 | 0 | 301 |  |
| 355 | `describe_type_metadata` | 0.0% | 0/125 | 0 | 125 |  |
| 356 | `describe_type_native` | 0.0% | 0/23 | 0 | 23 |  |
| 357 | `dictionary_namespaces` | 0.0% | 0/36 | 0 | 36 |  |
| 358 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 359 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 360 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 361 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 362 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 363 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 364 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 365 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 366 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 367 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 368 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 369 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 370 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 372 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 373 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 374 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 375 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 376 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 377 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 378 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 379 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 380 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 381 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 382 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 383 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 384 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 385 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 386 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 387 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 388 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 389 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 390 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 391 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 392 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 393 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 394 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 395 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 396 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 397 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 398 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 399 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 400 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 401 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 402 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 403 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 404 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 405 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 406 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 407 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 408 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 409 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 410 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 411 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 412 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 413 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 414 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 415 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 416 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 417 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 418 | `error_1034_debug_string` | 0.0% | 0/30 | 0 | 30 |  |
| 419 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 420 | `error_prototype` | 0.0% | 0/15 | 0 | 15 |  |
| 421 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 422 | `error_tostring` | 0.0% | 0/29 | 0 | 29 |  |
| 423 | `error_tostring_more` | 0.0% | 0/86 | 0 | 86 |  |
| 424 | `event_bubbles` | 0.0% | 0/2 | 0 | 2 |  |
| 425 | `event_cancelable` | 0.0% | 0/2 | 0 | 2 |  |
| 426 | `event_clone` | 0.0% | 0/20 | 0 | 20 |  |
| 427 | `event_clone_error_redispatch` | 0.0% | 0/3 | 0 | 3 |  |
| 428 | `event_clone_on_redispatch` | 0.0% | 0/10 | 0 | 10 |  |
| 429 | `event_formattostring` | 0.0% | 0/31 | 0 | 31 |  |
| 430 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 431 | `event_target_set` | 0.0% | 0/9 | 0 | 9 |  |
| 432 | `event_type` | 0.0% | 0/1 | 0 | 1 |  |
| 433 | `eventdispatcher_dispatchevent_indirect` | 0.0% | 0/9 | 0 | 9 |  |
| 434 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 435 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 436 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 437 | `flash_xml` | 0.0% | 0/29 | 0 | 29 |  |
| 438 | `flash_xml_cloneNode` | 0.0% | 0/22 | 0 | 22 |  |
| 439 | `flash_xml_namespace` | 0.0% | 0/109 | 0 | 109 |  |
| 440 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 441 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 442 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 443 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 444 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 445 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 446 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 447 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 448 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 449 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 450 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 451 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 452 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 453 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 454 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 455 | `goto_button_nested_framescript` | 0.0% | 0/28 | 0 | 28 |  |
| 456 | `goto_in_constructframe` | 0.0% | 0/12 | 0 | 12 |  |
| 457 | `goto_nested_construct_sibling` | 0.0% | 0/18 | 0 | 18 |  |
| 458 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 459 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 460 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 461 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 462 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 463 | `indexing_delete` | 0.0% | 0/75 | 0 | 75 |  |
| 464 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 465 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 466 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 467 | `invalid_utf8` | 0.0% | 0/12 | 0 | 12 |  |
| 468 | `issue_13780` | 0.0% | 0/12 | 0 | 12 |  |
| 469 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 470 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 471 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 472 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 473 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 474 | `json_errors` | 0.0% | 0/10 | 10 | 9 |  |
| 475 | `json_parse` | 0.0% | 0/21 | 0 | 21 |  |
| 476 | `json_stringify` | 0.0% | 0/14 | 0 | 14 |  |
| 477 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 478 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 479 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 480 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 481 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 482 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 483 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 484 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 485 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 486 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 487 | `loader_loadbytes_url` | 0.0% | 0/12 | 0 | 12 |  |
| 488 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 489 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 490 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 491 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 492 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 493 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 494 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 495 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 496 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 497 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 498 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 499 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 500 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 501 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 502 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 503 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 504 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 505 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 506 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 507 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 508 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 509 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 510 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 511 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 512 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 513 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 514 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 515 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 516 | `mouseevent_stagexy` | 0.0% | 0/35 | 0 | 35 |  |
| 517 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 0 | 676 |  |
| 518 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 0 | 2001 |  |
| 519 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 0 | 575 |  |
| 520 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 0 | 562 |  |
| 521 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 0 | 140 |  |
| 522 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 0 | 50 |  |
| 523 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 0 | 144 |  |
| 524 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 525 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 0 | 149 |  |
| 526 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 0 | 48 |  |
| 527 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 0 | 149 |  |
| 528 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 0 | 106 |  |
| 529 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 0 | 44 |  |
| 530 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 0 | 135 |  |
| 531 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 532 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 533 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 534 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 535 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 0 | 9 |  |
| 536 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 0 | 7 |  |
| 537 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 538 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 539 | `namespace_constr_args` | 0.0% | 0/1 | 0 | 1 |  |
| 540 | `namespace_enumeration_order` | 0.0% | 0/7 | 0 | 7 |  |
| 541 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 542 | `net_getClassByAlias` | 0.0% | 0/3 | 2 | 3 |  |
| 543 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 544 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 545 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 546 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 547 | `null_void_types` | 0.0% | 0/8 | 0 | 8 |  |
| 548 | `number_autoconv_amf` | 0.0% | 0/132 | 0 | 132 |  |
| 549 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 550 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 551 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 552 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 553 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 554 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 555 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 556 | `place_object_same_depth_frame` | 0.0% | 0/1 | 0 | 1 |  |
| 557 | `primitive_edge_cases` | 0.0% | 0/1 | 0 | 1 |  |
| 558 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 559 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 560 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 561 | `proxy_callproperty` | 0.0% | 0/24 | 0 | 24 |  |
| 562 | `proxy_deleteproperty` | 0.0% | 0/64 | 0 | 64 |  |
| 563 | `proxy_enumeration` | 0.0% | 0/34 | 0 | 34 |  |
| 564 | `proxy_getproperty` | 0.0% | 0/77 | 0 | 77 |  |
| 565 | `proxy_hasownproperty` | 0.0% | 0/8 | 0 | 8 |  |
| 566 | `proxy_hasproperty` | 0.0% | 0/32 | 0 | 32 |  |
| 567 | `proxy_serialize` | 0.0% | 0/9 | 0 | 9 |  |
| 568 | `proxy_setproperty` | 0.0% | 0/42 | 0 | 42 |  |
| 569 | `qname_as_lazy_name_attribute_multiname` | 0.0% | 0/1 | 0 | 1 |  |
| 570 | `qname_indexing` | 0.0% | 0/23 | 0 | 23 |  |
| 571 | `regexp_multiargs` | 0.0% | 0/1 | 0 | 1 |  |
| 572 | `regexp_toString` | 0.0% | 0/10 | 0 | 10 |  |
| 573 | `remove_child_clear_field` | 0.0% | 0/88 | 0 | 88 |  |
| 574 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 575 | `rng` | 0.0% | 0/1 | 0 | 1 |  |
| 576 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 577 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 578 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 579 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 580 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 581 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 582 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 583 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 584 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 585 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 1 | 45 |  |
| 586 | `simplebutton_childevents` | 0.0% | 0/86 | 0 | 86 |  |
| 587 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 588 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 589 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 590 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 591 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 592 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 593 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 594 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 595 | `stage_framerate_nan` | 0.0% | 0/7 | 0 | 7 |  |
| 596 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 597 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 598 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 599 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 600 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 601 | `static_length` | 0.0% | 0/24 | 1 | 24 |  |
| 602 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 603 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 604 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 605 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 606 | `subclass_superclass_linked_symbol` | 0.0% | 0/4 | 0 | 4 |  |
| 607 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 608 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 0 | 6 |  |
| 609 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 610 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 611 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 612 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 613 | `symbol_class_root_not_zero` | 0.0% | 0/1 | 0 | 1 |  |
| 614 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 615 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 616 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 617 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 618 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 619 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 620 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 621 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 622 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 623 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 624 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 625 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 626 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 627 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 628 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 629 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 630 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 631 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 632 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 633 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 634 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 635 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 636 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 637 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 638 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 639 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 640 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 641 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 642 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 643 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 644 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 645 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 646 | `vector_class` | 0.0% | 0/36 | 0 | 36 |  |
| 647 | `vector_class_call` | 0.0% | 0/11 | 11 | 11 |  |
| 648 | `vector_enumeration` | 0.0% | 0/5 | 0 | 5 |  |
| 649 | `vector_object_final` | 0.0% | 0/1 | 0 | 1 |  |
| 650 | `vector_reborrow_bug` | 0.0% | 0/10 | 0 | 10 |  |
| 651 | `vector_splice_fixed_bug_compat` | 0.0% | 0/4 | 0 | 4 |  |
| 652 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 653 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 654 | `verify_typecheck` | 0.0% | 0/4 | 0 | 4 |  |
| 655 | `xml_abstract_equality` | 0.0% | 0/36 | 0 | 36 |  |
| 656 | `xml_advanced` | 0.0% | 0/52 | 13 | 52 |  |
| 657 | `xml_appendchild` | 0.0% | 0/10 | 1 | 10 |  |
| 658 | `xml_appendchild_swf_v21` | 0.0% | 0/13 | 0 | 13 |  |
| 659 | `xml_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 660 | `xml_attribute` | 0.0% | 0/35 | 0 | 35 |  |
| 661 | `xml_attribute_name` | 0.0% | 0/40 | 0 | 40 |  |
| 662 | `xml_basic` | 0.0% | 0/32 | 0 | 32 |  |
| 663 | `xml_child` | 0.0% | 0/25 | 0 | 25 |  |
| 664 | `xml_childindex` | 0.0% | 0/7 | 0 | 7 |  |
| 665 | `xml_children` | 0.0% | 0/43 | 0 | 43 |  |
| 666 | `xml_class_call` | 0.0% | 0/9 | 0 | 9 |  |
| 667 | `xml_copy` | 0.0% | 0/20 | 0 | 20 |  |
| 668 | `xml_ctor_from_tostring` | 0.0% | 0/23 | 0 | 23 |  |
| 669 | `xml_delete` | 0.0% | 0/114 | 0 | 114 |  |
| 670 | `xml_elements` | 0.0% | 0/6 | 0 | 6 |  |
| 671 | `xml_ignore_white` | 0.0% | 0/6 | 2 | 6 |  |
| 672 | `xml_length` | 0.0% | 0/2 | 0 | 2 |  |
| 673 | `xml_list_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 674 | `xml_list_enumerate` | 0.0% | 0/4 | 2 | 4 |  |
| 675 | `xml_methods_settings` | 0.0% | 0/3 | 0 | 3 |  |
| 676 | `xml_namespace` | 0.0% | 0/39 | 0 | 39 |  |
| 677 | `xml_namespace_methods` | 0.0% | 0/245 | 0 | 245 |  |
| 678 | `xml_namespaced_property` | 0.0% | 0/7 | 0 | 7 |  |
| 679 | `xml_no_namespace` | 0.0% | 0/1 | 0 | 1 |  |
| 680 | `xml_nodekind` | 0.0% | 0/3 | 0 | 3 |  |
| 681 | `xml_normalize` | 0.0% | 0/35 | 0 | 35 |  |
| 682 | `xml_notification_bubbling` | 0.0% | 0/361 | 0 | 361 |  |
| 683 | `xml_parent` | 0.0% | 0/8 | 0 | 8 |  |
| 684 | `xml_set_children` | 0.0% | 0/17 | 0 | 17 |  |
| 685 | `xml_set_name` | 0.0% | 0/34 | 0 | 34 |  |
| 686 | `xml_settings` | 0.0% | 0/6 | 0 | 6 |  |
| 687 | `xml_simple_complex_content` | 0.0% | 0/47 | 0 | 47 |  |
| 688 | `xml_text` | 0.0% | 0/7 | 0 | 7 |  |
| 689 | `xml_tostring` | 0.0% | 0/6 | 6 | 6 |  |
| 690 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 691 | `xml_weird_ignores` | 0.0% | 0/56 | 56 | 54 |  |
| 692 | `xml_wildcard` | 0.0% | 0/11 | 0 | 11 |  |
| 693 | `xmldocument` | 0.0% | 0/254 | 0 | 254 |  |
| 694 | `xmlnode` | 0.0% | 0/3540 | 0 | 3540 |  |
| 695 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
