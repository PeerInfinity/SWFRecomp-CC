# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 08:30 UTC

**Git SHA**: `2ceede9620`

**Run Duration**: 76m 0s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1198 |
| Passing | **296** (24.7%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **307** (25.6%) |
| Failing | 891 |
| Total expected lines | 148815 |
| Matching lines | 38554 (25.9%) |
| Mismatched lines | 110261 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 823 | 92.4% |
| Runtime Error | 68 | 7.6% |

## Passing Tests

**296 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.8s |  |
| 2 | `air_hidden_lookup` | 2 | 0.8s |  |
| 3 | `array_access` | 18 | 1.5s |  |
| 4 | `array_access_interpreter` | 4 | 1.4s |  |
| 5 | `array_access_no_pubns` | 2 | 1.4s |  |
| 6 | `array_concat` | 41 | 1.5s |  |
| 7 | `array_constr` | 10 | 1.4s |  |
| 8 | `array_delete` | 44 | 1.5s |  |
| 9 | `array_enumeration` | 10 | 1.4s |  |
| 10 | `array_enumeration_elements` | 11 | 1.4s |  |
| 11 | `array_every` | 8 | 1.4s |  |
| 12 | `array_filter` | 6 | 1.4s |  |
| 13 | `array_foreach` | 18 | 1.4s |  |
| 14 | `array_hasownproperty` | 11 | 1.4s |  |
| 15 | `array_holes` | 9 | 1.4s |  |
| 16 | `array_index_max` | 84 | 1.2s |  |
| 17 | `array_indexof` | 25 | 1.5s |  |
| 18 | `array_join` | 26 | 1.5s |  |
| 19 | `array_lastindexof` | 29 | 1.5s |  |
| 20 | `array_length` | 14 | 1.5s |  |
| 21 | `array_literal` | 3 | 1.4s |  |
| 22 | `array_map` | 8 | 0.4s |  |
| 23 | `array_pop` | 52 | 1.5s |  |
| 24 | `array_push` | 24 | 1.5s |  |
| 25 | `array_reborrow_bug` | 6 | 1.5s |  |
| 26 | `array_reverse` | 28 | 1.5s |  |
| 27 | `array_shift` | 51 | 1.5s |  |
| 28 | `array_slice` | 39 | 1.5s |  |
| 29 | `array_some` | 8 | 1.5s |  |
| 30 | `array_sort` | 297 | 1.7s |  |
| 31 | `array_sort_fun_swf12` | 2 | 1.5s |  |
| 32 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 33 | `array_sort_random` | 210 | 1.5s |  |
| 34 | `array_sort_swf10_32bit` | 1 | 3.6s |  |
| 35 | `array_sorton` | 545 | 1.8s |  |
| 36 | `array_sparse_ops` | 41 | 1.5s |  |
| 37 | `array_splice` | 133 | 1.5s |  |
| 38 | `array_splice2` | 428 | 1.6s |  |
| 39 | `array_splice_types` | 48 | 1.5s |  |
| 40 | `array_storage` | 8 | 1.4s |  |
| 41 | `array_tolocalestring` | 9 | 1.4s |  |
| 42 | `array_tostring` | 12 | 1.4s |  |
| 43 | `array_unshift` | 24 | 1.4s |  |
| 44 | `array_valueof` | 9 | 1.3s |  |
| 45 | `astype` | 28 | 1.4s |  |
| 46 | `astypelate` | 24 | 1.5s |  |
| 47 | `astypelate_propagates` | 1 | 1.3s |  |
| 48 | `away3d_advanced_shallow_water_demo` | 0 | 60.3s |  |
| 49 | `bitand` | 1058 | 3.7s |  |
| 50 | `bitmapdata_applyfilter_blur` | 0 | 20.0s |  |
| 51 | `bitmapdata_applyfilter_colormatrix` | 0 | 1.6s |  |
| 52 | `bitmapdata_applyfilter_destpoint` | 0 | 19.8s |  |
| 53 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 19.8s |  |
| 54 | `bitmapdata_colortransform` | 0 | 1.6s |  |
| 55 | `bitmapdata_draw` | 0 | 20.1s |  |
| 56 | `bitmapdata_draw_colortransform` | 0 | 1.5s |  |
| 57 | `bitmapdata_draw_filters` | 0 | 20.0s |  |
| 58 | `bitmapdata_draw_masks` | 0 | 1.5s |  |
| 59 | `bitmapdata_draw_rotation` | 0 | 1.5s |  |
| 60 | `bitmapdata_draw_self_via_graphic` | 0 | 1.5s |  |
| 61 | `bitmapdata_draw_stage` | 0 | 19.9s |  |
| 62 | `bitmapdata_drawwithquality` | 0 | 1.7s |  |
| 63 | `bitmapdata_fillrect` | 0 | 1.5s |  |
| 64 | `bitmapdata_filter_sourcerect` | 0 | 20.0s |  |
| 65 | `bitmapdata_opaque` | 0 | 1.5s |  |
| 66 | `bitmapdata_pixeldissolve_image` | 0 | 1.6s |  |
| 67 | `bitmapdata_sync` | 0 | 1.6s |  |
| 68 | `bitnot` | 46 | 1.5s |  |
| 69 | `bitor` | 1058 | 3.7s |  |
| 70 | `bitxor` | 1058 | 3.7s |  |
| 71 | `blend_multiply_alpha` | 0 | 1.5s |  |
| 72 | `blend_scroll` | 0 | 3.7s |  |
| 73 | `boolean_constr` | 32 | 1.4s |  |
| 74 | `boolean_negation` | 30 | 1.4s |  |
| 75 | `boolean_tostring` | 8 | 1.3s |  |
| 76 | `callee_in_initializer` | 6 | 1.3s |  |
| 77 | `callproplex_class` | 1 | 1.3s |  |
| 78 | `catch_class` | 6 | 1.4s |  |
| 79 | `catch_scope_slot` | 7 | 1.4s |  |
| 80 | `class_cast_call` | 14 | 1.4s |  |
| 81 | `class_enumeration` | 4 | 1.4s |  |
| 82 | `class_has_own_property` | 2 | 1.3s |  |
| 83 | `class_init_interpreter_mode` | 1 | 1.3s |  |
| 84 | `class_is` | 32 | 1.4s |  |
| 85 | `class_methods` | 5 | 1.4s |  |
| 86 | `class_object_properties` | 10 | 3.3s |  |
| 87 | `class_singleton` | 18 | 1.1s |  |
| 88 | `class_supercalls_errors` | 35 | 1.3s |  |
| 89 | `class_supercalls_mismatched` | 26 | 1.1s |  |
| 90 | `class_superclass_wrong_order` | 1 | 1.0s |  |
| 91 | `class_to_locale_string` | 2 | 1.1s |  |
| 92 | `class_to_string` | 2 | 1.2s |  |
| 93 | `class_value_of` | 2 | 1.1s |  |
| 94 | `closures` | 12 | 1.1s |  |
| 95 | `coerce_property` | 33 | 1.2s |  |
| 96 | `coerce_return_type` | 40 | 1.2s |  |
| 97 | `coerce_return_type_fail` | 2 | 1.0s |  |
| 98 | `coerce_return_void` | 3 | 1.1s |  |
| 99 | `coerce_string` | 86 | 1.1s |  |
| 100 | `coerce_string_precision` | 28 | 1.1s |  |
| 101 | `construct_errors_swf10` | 8 | 1.3s |  |
| 102 | `constructor_call` | 3 | 1.1s |  |
| 103 | `control_flow_bool` | 4 | 1.1s |  |
| 104 | `control_flow_stricteq` | 8 | 1.1s |  |
| 105 | `convert_boolean` | 30 | 1.1s |  |
| 106 | `convert_integer` | 90 | 1.1s |  |
| 107 | `convert_number` | 56 | 1.1s |  |
| 108 | `convert_uinteger` | 90 | 1.1s |  |
| 109 | `declocal` | 46 | 1.4s |  |
| 110 | `declocal_i` | 46 | 1.4s |  |
| 111 | `decrement` | 46 | 1.4s |  |
| 112 | `decrement_i` | 46 | 1.4s |  |
| 113 | `default_values` | 7 | 1.4s |  |
| 114 | `displayobject_blendmode` | 0 | 19.5s |  |
| 115 | `displayobject_colortransform_nested` | 0 | 19.5s |  |
| 116 | `displayobject_getbounds_shape` | 0 | 19.3s |  |
| 117 | `displayobject_mask_self_referential` | 0 | 1.4s |  |
| 118 | `displayobject_set_matrix_nested` | 0 | 19.6s |  |
| 119 | `divide` | 1058 | 3.9s |  |
| 120 | `duplicate_defs` | 1 | 0.4s |  |
| 121 | `eager_init` | 1 | 1.5s |  |
| 122 | `equals` | 512 | 2.4s |  |
| 123 | `error_stack_trace_debug_swf17` | 0 | 20.1s |  |
| 124 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 125 | `error_stack_trace_release_swf17` | 0 | 0.3s |  |
| 126 | `error_stack_trace_release_swf18` | 0 | 0.2s |  |
| 127 | `es3_inheritance` | 31 | 1.4s |  |
| 128 | `es4_inheritance` | 30 | 1.5s |  |
| 129 | `es4_interfaces` | 30 | 1.5s |  |
| 130 | `es4_method_binding` | 8 | 1.4s |  |
| 131 | `es4_oop_prototypes` | 14 | 1.6s |  |
| 132 | `es4_protected_inheritance` | 6 | 1.4s |  |
| 133 | `falsiness` | 30 | 1.5s |  |
| 134 | `finddef` | 3 | 1.4s |  |
| 135 | `function_call` | 12 | 1.3s |  |
| 136 | `function_call_arguments` | 46 | 1.4s |  |
| 137 | `function_call_arguments_enumerate` | 5 | 1.2s |  |
| 138 | `function_call_coercion` | 108 | 1.5s |  |
| 139 | `function_call_default` | 6 | 1.2s |  |
| 140 | `function_call_rest` | 22 | 1.3s |  |
| 141 | `function_call_types` | 3 | 1.2s |  |
| 142 | `function_call_via_apply` | 11 | 1.3s |  |
| 143 | `function_call_via_call` | 3 | 1.2s |  |
| 144 | `function_display_anonymous` | 7 | 1.3s |  |
| 145 | `function_length` | 6 | 1.3s |  |
| 146 | `function_object` | 2 | 1.3s |  |
| 147 | `function_proto` | 5 | 1.2s |  |
| 148 | `function_to_locale_string` | 4 | 1.4s |  |
| 149 | `function_to_string` | 4 | 1.4s |  |
| 150 | `function_type` | 6 | 1.4s |  |
| 151 | `function_value_of` | 4 | 1.4s |  |
| 152 | `get_slot_edge_cases` | 1 | 1.4s |  |
| 153 | `getglobalslot` | 1 | 1.4s |  |
| 154 | `getouterscope` | 8 | 1.4s |  |
| 155 | `getter_different_namespace_setter` | 2 | 1.4s |  |
| 156 | `graphics_bitmaps` | 0 | 1.7s |  |
| 157 | `graphics_direct_commands` | 0 | 1.6s |  |
| 158 | `graphics_gradients` | 0 | 1.6s |  |
| 159 | `graphics_gradients_nulls` | 0 | 1.5s |  |
| 160 | `graphics_round_rects` | 0 | 1.5s |  |
| 161 | `graphics_simple_shapes` | 0 | 1.5s |  |
| 162 | `greaterequals` | 512 | 4.7s |  |
| 163 | `greaterthan` | 512 | 2.3s |  |
| 164 | `has_own_property` | 102 | 1.6s |  |
| 165 | `hasownproperty_namespaces` | 2 | 1.4s |  |
| 166 | `hello_world` | 1 | 1.4s |  |
| 167 | `if_eq` | 10 | 1.4s |  |
| 168 | `if_gt` | 1 | 1.4s |  |
| 169 | `if_gte` | 10 | 1.4s |  |
| 170 | `if_lt` | 1 | 0.4s |  |
| 171 | `if_lte` | 10 | 0.4s |  |
| 172 | `if_ne` | 7 | 1.4s |  |
| 173 | `if_stricteq` | 6 | 1.4s |  |
| 174 | `if_strictne` | 11 | 1.4s |  |
| 175 | `in` | 102 | 1.7s |  |
| 176 | `inclocal` | 46 | 1.5s |  |
| 177 | `inclocal_i` | 46 | 1.5s |  |
| 178 | `increment` | 46 | 1.5s |  |
| 179 | `increment_i` | 46 | 1.5s |  |
| 180 | `instanceof` | 58 | 1.6s |  |
| 181 | `int_constr` | 92 | 1.6s |  |
| 182 | `int_edge_cases` | 19 | 1.5s |  |
| 183 | `int_instanceof` | 3 | 1.4s |  |
| 184 | `int_tofixed` | 1215 | 1.4s |  |
| 185 | `int_tostring` | 3375 | 1.6s |  |
| 186 | `interface_namespaces` | 78 | 1.6s |  |
| 187 | `is_finite` | 46 | 1.5s |  |
| 188 | `is_nan` | 46 | 1.4s |  |
| 189 | `is_prototype_of` | 12 | 1.4s |  |
| 190 | `issue_10221` | 2 | 1.4s |  |
| 191 | `issue_14901` | 1 | 1.1s |  |
| 192 | `istype` | 24 | 1.1s |  |
| 193 | `istypelate` | 58 | 1.2s |  |
| 194 | `istypelate_coerce` | 198 | 1.4s |  |
| 195 | `json_version_gated` | 1 | 1.1s |  |
| 196 | `lazyinit` | 17 | 1.1s |  |
| 197 | `lessequals` | 512 | 1.8s |  |
| 198 | `lessthan` | 512 | 1.8s |  |
| 199 | `lshift` | 1058 | 3.5s |  |
| 200 | `math` | 497 | 1.5s |  |
| 201 | `modulo` | 1058 | 3.5s |  |
| 202 | `movieclip_stop` | 1 | 19.6s |  |
| 203 | `multiply` | 1058 | 3.5s |  |
| 204 | `negate` | 30 | 1.4s |  |
| 205 | `negative_volume_panned` | 0 | 1.5s |  |
| 206 | `newactivation_in_script_init` | 3 | 1.3s |  |
| 207 | `newclass_twice` | 3 | 1.3s |  |
| 208 | `nonconflicting_declarations` | 0 | 1.4s |  |
| 209 | `number_autoconv_array_sort_32bit` | 1 | 1.4s |  |
| 210 | `number_constr` | 58 | 1.5s |  |
| 211 | `number_toexponential` | 378 | 1.5s |  |
| 212 | `number_toexponential2` | 35 | 1.4s |  |
| 213 | `number_tofixed` | 378 | 1.4s |  |
| 214 | `number_toprecision` | 350 | 1.5s |  |
| 215 | `obfuscated_class_names` | 3 | 1.4s |  |
| 216 | `object_enumeration` | 10 | 1.4s |  |
| 217 | `object_prototype` | 4 | 1.5s |  |
| 218 | `object_to_locale_string` | 2 | 1.4s |  |
| 219 | `object_to_string` | 2 | 1.4s |  |
| 220 | `object_value_of` | 2 | 1.2s |  |
| 221 | `op_coerce` | 54 | 0.8s |  |
| 222 | `op_coerce_x` | 54 | 1.5s |  |
| 223 | `op_escxattr` | 2 | 1.4s |  |
| 224 | `op_escxelem` | 2 | 1.4s |  |
| 225 | `op_lookupswitch` | 4 | 1.4s |  |
| 226 | `optimize_coerce` | 1 | 1.3s |  |
| 227 | `param_default_value_has_zero_cpool_index` | 1 | 1.3s |  |
| 228 | `parse_float` | 80 | 1.5s |  |
| 229 | `pixelbender_effect_BlurredFocus` | 0 | 22.7s |  |
| 230 | `pixelbender_effect_glassDisplace` | 0 | 6.3s |  |
| 231 | `pixelbender_effect_smudge` | 0 | 4.0s |  |
| 232 | `pixelbender_effect_tintype` | 0 | 3.1s |  |
| 233 | `pixelbender_effect_twirl` | 0 | 4.4s |  |
| 234 | `pixelbender_images` | 0 | 3.1s |  |
| 235 | `property_priority` | 22 | 1.8s |  |
| 236 | `property_priority_three_level` | 6 | 1.6s |  |
| 237 | `propertyisenumerable_namespaces` | 6 | 1.5s |  |
| 238 | `rshift` | 1058 | 3.2s |  |
| 239 | `set_property_is_enumerable` | 85 | 1.4s |  |
| 240 | `slot_disp_id_shared_numbering` | 1 | 21.8s |  |
| 241 | `slots_force_autoassigned` | 1 | 1.4s |  |
| 242 | `sprite_with_frames` | 0 | 19.3s |  |
| 243 | `stage3d_agal_cross_product` | 0 | 2.5s |  |
| 244 | `stage3d_bitmap` | 0 | 21.7s |  |
| 245 | `stage3d_float1_index` | 0 | 20.3s |  |
| 246 | `stage3d_fractal` | 0 | 24.7s |  |
| 247 | `stage3d_ignore_sampler_override` | 0 | 22.0s |  |
| 248 | `stage3d_program_constants_bytearray_be` | 0 | 22.2s |  |
| 249 | `stage3d_program_constants_bytearray_le` | 0 | 3.0s |  |
| 250 | `stage3d_raytrace` | 0 | 20.4s |  |
| 251 | `stage3d_stencil` | 0 | 22.0s |  |
| 252 | `stage3d_texture` | 0 | 6.0s |  |
| 253 | `stage3d_texture_bytearray` | 0 | 3.7s |  |
| 254 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.2s |  |
| 255 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 3.9s |  |
| 256 | `stage3d_triangle` | 0 | 2.8s |  |
| 257 | `stage3d_triangle_bytes4` | 0 | 2.9s |  |
| 258 | `stage3d_triangle_float1` | 0 | 2.9s |  |
| 259 | `stage3d_triangle_index_upload` | 0 | 2.8s |  |
| 260 | `static_var_with_this_in_ctor` | 2 | 1.5s |  |
| 261 | `stored_properties` | 11 | 4.0s |  |
| 262 | `strict_equality` | 34 | 1.6s |  |
| 263 | `string_call` | 13 | 1.6s |  |
| 264 | `string_case` | 23 | 1.6s |  |
| 265 | `string_char_at` | 27 | 1.7s |  |
| 266 | `string_char_code_at` | 28 | 1.5s |  |
| 267 | `string_concat_fromcharcode` | 36 | 1.6s |  |
| 268 | `string_constr` | 25 | 1.6s |  |
| 269 | `string_indexof_lastindexof` | 87 | 1.6s |  |
| 270 | `string_length` | 16 | 1.6s |  |
| 271 | `string_locale_compare` | 39 | 1.6s |  |
| 272 | `string_relational_compare` | 4 | 1.5s |  |
| 273 | `string_slice_substr_substring` | 169 | 1.9s |  |
| 274 | `string_substr_negative` | 21 | 1.5s |  |
| 275 | `string_substr_weird` | 182 | 1.5s |  |
| 276 | `subtract` | 1058 | 4.7s |  |
| 277 | `super_get_call` | 12 | 1.6s |  |
| 278 | `supercall_two_classobjects` | 2 | 1.6s |  |
| 279 | `swf8` | 1 | 1.3s |  |
| 280 | `symbolclass_invalid_utf8` | 2 | 1.4s |  |
| 281 | `throw` | 3 | 1.5s |  |
| 282 | `truthiness` | 30 | 1.5s |  |
| 283 | `try_catch_typed` | 12 | 1.5s |  |
| 284 | `typeof` | 30 | 1.5s |  |
| 285 | `uint_constr` | 92 | 1.6s |  |
| 286 | `uint_tofixed` | 1215 | 1.4s |  |
| 287 | `uint_tostring` | 3375 | 1.6s |  |
| 288 | `unchecked_function` | 15 | 1.4s |  |
| 289 | `urshift` | 1058 | 3.6s |  |
| 290 | `verify_abnormal_loop` | 1 | 0.4s |  |
| 291 | `verify_exception_targets_edge_case` | 1 | 0.4s |  |
| 292 | `verify_lookup_switch_edge_case` | 1 | 0.4s |  |
| 293 | `verify_unreachable_exception` | 2 | 0.4s |  |
| 294 | `versioned_isplaying` | 2 | 0.4s |  |
| 295 | `virtual_properties` | 16 | 0.5s |  |
| 296 | `with` | 4 | 0.5s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 2 | `blend_transform` | 1 | 1 | 1.4s |  |
| 3 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.4s |  |
| 4 | `freestanding_superclass` | 4 | 4 | 1.2s |  |
| 5 | `int_toexponential` | 76 | 76 | 1.5s |  |
| 6 | `int_toprecision` | 441 | 441 | 1.5s |  |
| 7 | `slot_holes_fail` | 1 | 1 | 1.3s |  |
| 8 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.3s |  |
| 9 | `uint_toexponential` | 100 | 100 | 1.5s |  |
| 10 | `uint_toprecision` | 433 | 433 | 1.5s |  |
| 11 | `weird_superinterface_properties` | 1 | 1 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**31 tests** within reach

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
| 9 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 10 | `eventdispatcher_tostring` | 80.0% | 8 | 10 | 2 |  |
| 11 | `issue_5292` | 80.0% | 4 | 5 | 1 |  |
| 12 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 13 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 14 | `constructprop_dynamic_primitive` | 71.4% | 5 | 7 | 2 |  |
| 15 | `number_autoconv` | 71.4% | 15 | 21 | 6 |  |
| 16 | `primitive_toString` | 70.5% | 43 | 61 | 18 |  |
| 17 | `movieclip_super_is_symbol` | 70.0% | 14 | 20 | 6 |  |
| 18 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 19 | `xml_hasownproperty` | 66.7% | 4 | 6 | 2 |  |
| 20 | `xml_contains` | 66.5% | 131 | 197 | 66 |  |
| 21 | `nested_iteration` | 63.6% | 7 | 11 | 4 |  |
| 22 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 23 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 24 | `date` | 50.0% | 15 | 30 | 15 |  |
| 25 | `displayobjectcontainer_removechild_errors` | 50.0% | 2 | 4 | 2 |  |
| 26 | `goto_in_scene_last_frame` | 50.0% | 1 | 2 | 1 |  |
| 27 | `issue_8630` | 50.0% | 1 | 2 | 1 |  |
| 28 | `movieclip_next_frame` | 50.0% | 1 | 2 | 1 |  |
| 29 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 30 | `verification` | 50.0% | 4 | 8 | 4 |  |
| 31 | `xml_equals_namespace_check` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**68 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `applicationdomain_getqualifieddefinitionnames` | exit code 1 | 1.4s |  |
| 2 | `array_access_oob_interpreter` | exit code 1 | 1.3s |  |
| 3 | `bitmap_subclass` | exit code 1 | 2.5s |  |
| 4 | `bitmap_subclass_properties` | exit code 1 | 1.7s |  |
| 5 | `bitmapdata_copychannel` | exit code 1 (output matches) | 22.1s |  |
| 6 | `bitmapdata_draw_cpu_overwrite_gpu` | exit code 1 (output matches) | 20.3s |  |
| 7 | `checkfilter` | exit code 1 | 1.4s |  |
| 8 | `content_element_basic` | exit code 1 | 1.3s |  |
| 9 | `core_exceptions` | exit code 1 | 1.6s |  |
| 10 | `dictionary_access_no_pubns` | exit code 1 | 1.4s |  |
| 11 | `doabc_is_eager` | exit code 1 | 20.3s |  |
| 12 | `edittext_always_show_selection` | exit code 1 (output matches) | 21.4s |  |
| 13 | `edittext_at_point_methods_basic` | exit code 1 | 2.8s |  |
| 14 | `edittext_autosize_align` | exit code 1 (output matches) | 21.6s |  |
| 15 | `edittext_autosize_height_dynamic` | exit code 1 | 21.6s |  |
| 16 | `edittext_autosize_height_input` | exit code 1 | 1.6s |  |
| 17 | `edittext_autosize_lazy_bounds_props` | exit code 1 | 3.0s |  |
| 18 | `edittext_autosize_lazy_bounds_visual` | exit code 1 (output matches) | 21.6s |  |
| 19 | `edittext_autosize_lazy_bounds_vs_relayout` | exit code 1 | 1.7s |  |
| 20 | `edittext_bottom_scroll_v_basic` | exit code 1 | 1.6s |  |
| 21 | `edittext_device_transform_layout` | exit code 1 | 1.8s |  |
| 22 | `edittext_empty_text_format` | exit code 1 | 1.6s |  |
| 23 | `edittext_get_char_index_at_point` | exit code 1 | 15.8s |  |
| 24 | `edittext_get_line_index_at_point` | exit code 1 | 15.5s |  |
| 25 | `edittext_get_line_index_of_char` | exit code 1 | 2.0s |  |
| 26 | `edittext_getcharboundaries` | exit code 1 | 1.4s |  |
| 27 | `edittext_getcharboundaries_culling` | exit code 1 | 1.3s |  |
| 28 | `edittext_getcharboundaries_missing_glyphs` | exit code 1 | 1.2s |  |
| 29 | `edittext_getcharboundaries_scroll` | exit code 1 | 1.2s |  |
| 30 | `edittext_line_methods` | exit code 1 | 1.9s |  |
| 31 | `edittext_line_metrics` | exit code 1 | 16.5s |  |
| 32 | `edittext_max_scroll_h_basic` | exit code 1 | 1.2s |  |
| 33 | `edittext_max_scroll_v_basic` | exit code 1 | 1.2s |  |
| 34 | `edittext_mouse_selection` | exit code 1 | 16.2s |  |
| 35 | `edittext_wordwrap_word` | exit code 1 | 1.7s |  |
| 36 | `edittext_wrap_breaks` | exit code 1 | 1.8s |  |
| 37 | `error_stack_trace` | exit code 1 | 1.4s |  |
| 38 | `findprop_global_prototype` | exit code 1 | 1.5s |  |
| 39 | `font_enumeratefonts_filter` | exit code 1 | 1.9s |  |
| 40 | `font_enumeratefonts_order` | exit code 1 | 1.9s |  |
| 41 | `graphics_bitmap_fill` | exit code 1 (output matches) | 2.9s |  |
| 42 | `large_preload_from_bytes` | exit code 1 | 1.2s |  |
| 43 | `large_preload_image_from_bytes` | exit code 1 | 1.4s |  |
| 44 | `method_without_body` | exit code 1 | 18.9s |  |
| 45 | `mouse_wheel_events` | exit code 1 | 21.1s |  |
| 46 | `namespace_constr` | exit code 1 | 1.6s |  |
| 47 | `pixelbender_conversions` | exit code 1 | 1.7s |  |
| 48 | `pixelbender_div` | exit code 1 | 1.6s |  |
| 49 | `pixelbender_input` | exit code 1 | 21.4s |  |
| 50 | `pixelbender_malformed_data` | exit code 1 | 20.6s |  |
| 51 | `pixelbender_parameters` | exit code 1 | 1.8s |  |
| 52 | `pixelbender_parameters_bool` | exit code 1 | 1.8s |  |
| 53 | `pixelbender_parameters_int_vs_bool` | exit code 1 | 1.5s |  |
| 54 | `pixelbender_rsqrt` | exit code 1 | 1.5s |  |
| 55 | `pixelbender_shaderdata_setter` | exit code 1 | 2.1s |  |
| 56 | `pixelbender_vector_output` | exit code 1 | 4.1s |  |
| 57 | `property_priority_scope_cache_order` | exit code 1 | 19.9s |  |
| 58 | `rtqname_not_namespace` | exit code 1 | 1.2s |  |
| 59 | `sound_load_multiple` | exit code 1 | 2.3s |  |
| 60 | `stage3d_blend` | exit code 1 | 20.4s |  |
| 61 | `stage3d_rotating_cube` | exit code 1 (output matches) | 3.1s |  |
| 62 | `stage3d_sampler` | exit code 1 (output matches) | 2.8s |  |
| 63 | `stage3d_sampler_partial_upload` | exit code 1 (output matches) | 2.8s |  |
| 64 | `supercalls_weird` | exit code 1 | 1.5s |  |
| 65 | `symbol_class_binary_data` | exit code 1 | 1.5s |  |
| 66 | `xml_descendants` | exit code 1 | 1.5s |  |
| 67 | `xml_explicit_use_namespace` | exit code 1 | 1.6s |  |
| 68 | `xml_getdescendants_qname` | exit code 1 | 1.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**823 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 10 | `eventdispatcher_tostring` | 80.0% | 8/10 | 8 | 10 |  |
| 11 | `issue_5292` | 80.0% | 4/5 | 4 | 5 |  |
| 12 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 13 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 14 | `constructprop_dynamic_primitive` | 71.4% | 5/7 | 7 | 7 |  |
| 15 | `number_autoconv` | 71.4% | 15/21 | 15 | 21 |  |
| 16 | `primitive_toString` | 70.5% | 43/61 | 61 | 61 |  |
| 17 | `movieclip_super_is_symbol` | 70.0% | 14/20 | 20 | 20 |  |
| 18 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 19 | `xml_hasownproperty` | 66.7% | 4/6 | 6 | 6 |  |
| 20 | `xml_contains` | 66.5% | 131/197 | 197 | 197 |  |
| 21 | `nested_iteration` | 63.6% | 7/11 | 7 | 11 |  |
| 22 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 23 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 24 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 25 | `displayobjectcontainer_removechild_errors` | 50.0% | 2/4 | 4 | 4 |  |
| 26 | `goto_in_scene_last_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 27 | `issue_8630` | 50.0% | 1/2 | 1 | 2 |  |
| 28 | `movieclip_next_frame` | 50.0% | 1/2 | 1 | 2 |  |
| 29 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 30 | `verification` | 50.0% | 4/8 | 8 | 8 |  |
| 31 | `xml_equals_namespace_check` | 50.0% | 1/2 | 2 | 2 |  |
| 32 | `xml_mismatched_tag` | 45.9% | 17/37 | 34 | 37 |  |
| 33 | `get_definition_by_name` | 45.5% | 5/11 | 5 | 11 |  |
| 34 | `try_catch` | 45.5% | 5/11 | 11 | 11 |  |
| 35 | `trace` | 41.7% | 5/12 | 10 | 12 |  |
| 36 | `eventdispatcher_dispatchevent_this` | 40.0% | 2/5 | 2 | 5 |  |
| 37 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 38 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 39 | `dictionary_iter_modify` | 37.5% | 3/8 | 4 | 8 |  |
| 40 | `movieclip_symbol_constr` | 37.5% | 3/8 | 3 | 8 |  |
| 41 | `function_unbound_this` | 37.3% | 19/51 | 19 | 51 |  |
| 42 | `string_split` | 34.5% | 10/29 | 10 | 29 |  |
| 43 | `fast_index_access` | 33.3% | 4/12 | 4 | 12 |  |
| 44 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 45 | `movieclip_addframescript` | 33.3% | 1/3 | 1 | 3 |  |
| 46 | `movieclip_play` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `movieclip_prev_frame` | 33.3% | 1/3 | 1 | 3 |  |
| 48 | `remove_dobj` | 33.3% | 1/3 | 1 | 3 |  |
| 49 | `timeline_scripts` | 33.3% | 1/3 | 1 | 3 |  |
| 50 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 51 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 52 | `stage_access` | 30.0% | 3/10 | 5 | 10 |  |
| 53 | `function_proto_created` | 29.5% | 18/61 | 18 | 61 |  |
| 54 | `movieclip_constr` | 28.6% | 6/21 | 10 | 21 |  |
| 55 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 56 | `displayobjectcontainer_getchildat` | 25.0% | 1/4 | 1 | 4 |  |
| 57 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 58 | `movieclip_gotoandstop_children` | 25.0% | 1/4 | 1 | 4 |  |
| 59 | `movieclip_gotoandstop_framescripts1` | 25.0% | 1/4 | 1 | 4 |  |
| 60 | `movieclip_gotoandstop_framescripts2` | 25.0% | 1/4 | 1 | 4 |  |
| 61 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 62 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 63 | `resolve_order` | 25.0% | 1/4 | 1 | 4 |  |
| 64 | `vector_int_access` | 25.0% | 1/4 | 1 | 4 |  |
| 65 | `nan_scale` | 22.2% | 2/9 | 3 | 9 |  |
| 66 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 67 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 68 | `bitmapdata_zero_size` | 20.0% | 1/5 | 1 | 5 |  |
| 69 | `constructors_vs_timeline` | 20.0% | 1/5 | 2 | 5 |  |
| 70 | `displayobjectcontainer_getchildbyname_wrongcase` | 20.0% | 1/5 | 1 | 5 |  |
| 71 | `event_target_getter` | 20.0% | 1/5 | 1 | 5 |  |
| 72 | `framelabel_constr` | 20.0% | 1/5 | 1 | 5 |  |
| 73 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 74 | `soundmixer_buffertime` | 20.0% | 1/5 | 1 | 5 |  |
| 75 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 76 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 4 | 6 |  |
| 77 | `eventdispatcher_dispatchevent` | 16.7% | 2/12 | 2 | 12 |  |
| 78 | `movieclip_gotoandstop_queueing` | 16.7% | 2/12 | 2 | 12 |  |
| 79 | `movieclip_next_scene` | 16.7% | 1/6 | 1 | 6 |  |
| 80 | `soundmixer_stopall` | 16.7% | 1/6 | 1 | 6 |  |
| 81 | `stage_framerate_negative` | 16.7% | 1/6 | 1 | 6 |  |
| 82 | `stage_framerate_zero` | 16.7% | 1/6 | 1 | 6 |  |
| 83 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 84 | `movieclip_gotoandstop` | 15.4% | 2/13 | 2 | 13 |  |
| 85 | `doabc_and_symbolclass_script_init_goto` | 14.3% | 1/7 | 5 | 7 |  |
| 86 | `movieclip_goto_overwrite` | 14.3% | 2/14 | 2 | 14 |  |
| 87 | `movieclip_gotoandstop_framescripts_self` | 14.3% | 1/7 | 1 | 7 |  |
| 88 | `movieclip_prev_scene` | 14.3% | 1/7 | 1 | 7 |  |
| 89 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 90 | `movieclip_goto_during_frame_script` | 13.3% | 2/15 | 2 | 15 |  |
| 91 | `movieclip_gotoandplay` | 13.3% | 2/15 | 2 | 15 |  |
| 92 | `stage_mouseenabled` | 13.3% | 2/15 | 2 | 15 |  |
| 93 | `movieclip_properties` | 12.7% | 10/79 | 19 | 79 |  |
| 94 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 95 | `displayobject_name_from_timeline` | 12.5% | 3/24 | 4 | 24 |  |
| 96 | `goto_methods_swfver10` | 12.5% | 1/8 | 1 | 8 |  |
| 97 | `movieclip_child_property` | 12.5% | 2/16 | 3 | 16 |  |
| 98 | `scene_constr` | 12.5% | 1/8 | 1 | 8 |  |
| 99 | `soundchannel_stop` | 12.5% | 1/8 | 1 | 8 |  |
| 100 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 101 | `eventdispatcher_haseventlistener` | 12.0% | 3/25 | 3 | 25 |  |
| 102 | `eventdispatcher_willtrigger` | 12.0% | 3/25 | 3 | 25 |  |
| 103 | `amf_dictionary` | 11.1% | 1/9 | 1 | 9 |  |
| 104 | `bitmap_timeline` | 11.1% | 1/9 | 1 | 9 |  |
| 105 | `bitmapdata_embedded` | 11.1% | 1/9 | 1 | 9 |  |
| 106 | `displayobjectcontainer_getchildbyname` | 11.1% | 1/9 | 1 | 9 |  |
| 107 | `movieclip_frameconstruct_skipped` | 11.1% | 1/9 | 1 | 9 |  |
| 108 | `place_object_replace` | 11.1% | 1/9 | 1 | 9 |  |
| 109 | `qname_enumeration` | 11.1% | 1/9 | 1 | 9 |  |
| 110 | `displayobjectcontainer_timelineinstance` | 10.4% | 5/48 | 6 | 48 |  |
| 111 | `displayobjectcontainer_removechild` | 10.0% | 1/10 | 1 | 10 |  |
| 112 | `eventdispatcher_dispatchevent_cancel` | 10.0% | 2/20 | 2 | 20 |  |
| 113 | `vector_legacy` | 10.0% | 1/10 | 1 | 10 |  |
| 114 | `vector_object_toString` | 10.0% | 1/10 | 1 | 10 |  |
| 115 | `eventdispatcher_dispatchevent_handlerorder` | 9.1% | 2/22 | 2 | 22 |  |
| 116 | `movieclip_scenes` | 9.1% | 1/11 | 1 | 11 |  |
| 117 | `point` | 9.1% | 12/132 | 16 | 132 |  |
| 118 | `vector_int_delete` | 9.1% | 1/11 | 1 | 11 |  |
| 119 | `simplebutton_childshuffle` | 8.7% | 2/23 | 2 | 23 |  |
| 120 | `displayobject_root` | 8.3% | 2/24 | 4 | 24 |  |
| 121 | `event_isdefaultprevented` | 8.3% | 1/12 | 1 | 12 |  |
| 122 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 123 | `movieclip_currentscene` | 8.3% | 1/12 | 1 | 12 |  |
| 124 | `qname_constr_namespace` | 8.3% | 2/24 | 2 | 24 |  |
| 125 | `xml_tostring_namespace` | 8.3% | 1/12 | 1 | 12 |  |
| 126 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 127 | `bitmapdata_clone` | 7.7% | 1/13 | 1 | 13 |  |
| 128 | `button_nested_frame_simple` | 7.4% | 2/27 | 2 | 27 |  |
| 129 | `swf_9_goto_in_enter_frame_simple` | 6.7% | 1/15 | 1 | 15 |  |
| 130 | `displayobject_y` | 6.3% | 39/617 | 617 | 617 |  |
| 131 | `soundchannel_soundcomplete` | 6.2% | 1/16 | 1 | 16 |  |
| 132 | `amf_array_serialization` | 5.9% | 1/17 | 1 | 17 |  |
| 133 | `bitmap_constr` | 5.9% | 1/17 | 1 | 17 |  |
| 134 | `displayobject_filters` | 5.9% | 1/17 | 1 | 17 |  |
| 135 | `edittext_html_roundtrip` | 5.9% | 1/17 | 1 | 17 |  |
| 136 | `movieclip_currentlabels` | 5.9% | 1/17 | 1 | 17 |  |
| 137 | `swf_9_goto_in_enter_frame` | 5.9% | 1/17 | 1 | 17 |  |
| 138 | `displayobject_x` | 5.9% | 36/614 | 614 | 614 |  |
| 139 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 140 | `displayobjectcontainer_removechildat` | 5.6% | 1/18 | 1 | 18 |  |
| 141 | `event_valueof_tostring` | 5.6% | 1/18 | 1 | 18 |  |
| 142 | `loaderinfo_properties` | 5.6% | 1/18 | 1 | 18 |  |
| 143 | `color_matrix_filter` | 5.3% | 1/19 | 1 | 19 |  |
| 144 | `regexp_exec` | 5.3% | 1/19 | 1 | 19 |  |
| 145 | `sound_play` | 5.3% | 1/19 | 1 | 19 |  |
| 146 | `swf_wrong_frame_count` | 5.3% | 2/38 | 3 | 38 |  |
| 147 | `focus_remove` | 5.0% | 1/20 | 1 | 20 |  |
| 148 | `get_qualified_class_name` | 5.0% | 1/20 | 1 | 20 |  |
| 149 | `swf_9_goto_in_construct_frame` | 5.0% | 1/20 | 1 | 20 |  |
| 150 | `xml_list_concat` | 5.0% | 1/20 | 1 | 20 |  |
| 151 | `string_search` | 4.9% | 2/41 | 2 | 41 |  |
| 152 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 153 | `bitmapdata_constr` | 4.5% | 1/22 | 1 | 22 |  |
| 154 | `construct_frame_list` | 4.5% | 1/22 | 1 | 22 |  |
| 155 | `displayobject_name` | 4.5% | 1/22 | 2 | 22 |  |
| 156 | `simplebutton_symbolclass` | 4.4% | 3/68 | 3 | 68 |  |
| 157 | `bitmap_properties` | 4.3% | 1/23 | 1 | 23 |  |
| 158 | `displayobject_visible` | 4.3% | 1/23 | 2 | 23 |  |
| 159 | `button_nested_frame` | 4.2% | 2/48 | 2 | 48 |  |
| 160 | `bytearray_writeobject` | 4.2% | 1/24 | 1 | 24 |  |
| 161 | `edittext_bounds_scale` | 4.2% | 1/24 | 1 | 24 |  |
| 162 | `font_embedded` | 4.2% | 1/24 | 1 | 24 |  |
| 163 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 164 | `place_object_replace_2` | 4.2% | 1/24 | 1 | 24 |  |
| 165 | `stage_displayobject_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 166 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 1 | 24 |  |
| 167 | `vector_holes` | 4.2% | 1/24 | 1 | 24 |  |
| 168 | `filters_array_holes` | 4.0% | 1/25 | 1 | 25 |  |
| 169 | `qname_tostring` | 4.0% | 1/25 | 1 | 25 |  |
| 170 | `string_match` | 3.9% | 2/51 | 2 | 51 |  |
| 171 | `amf_custom_obj` | 3.8% | 1/26 | 1 | 26 |  |
| 172 | `edittext_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 173 | `simplebutton_mouseenabled` | 3.8% | 1/26 | 1 | 26 |  |
| 174 | `sound_embeddedprops` | 3.8% | 1/26 | 1 | 26 |  |
| 175 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 176 | `movieclip_drawrect` | 3.7% | 2/54 | 2 | 54 |  |
| 177 | `regexp_test` | 3.7% | 1/27 | 1 | 27 |  |
| 178 | `displayobjectcontainer_getchildindex` | 3.6% | 1/28 | 1 | 28 |  |
| 179 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 180 | `dictionary_primitive_keys` | 3.4% | 1/29 | 1 | 29 |  |
| 181 | `qname_valueof` | 3.4% | 1/29 | 1 | 29 |  |
| 182 | `hittest_morph` | 3.3% | 1/30 | 1 | 30 |  |
| 183 | `movieclip_currentlabels_dupes2` | 3.3% | 1/30 | 1 | 30 |  |
| 184 | `stage_properties` | 3.3% | 1/30 | 1 | 30 |  |
| 185 | `class_call` | 3.1% | 1/32 | 1 | 32 |  |
| 186 | `displayobject_hittestobject` | 3.1% | 1/32 | 1 | 32 |  |
| 187 | `displayobjectcontainer_addchild` | 3.1% | 1/32 | 1 | 32 |  |
| 188 | `qname_constr` | 3.1% | 1/32 | 1 | 32 |  |
| 189 | `sound_valueof` | 3.0% | 1/33 | 1 | 33 |  |
| 190 | `movieclip_hittest` | 3.0% | 2/67 | 2 | 67 |  |
| 191 | `displayobjectcontainer_addchildat_timelinelock0` | 2.9% | 1/34 | 1 | 34 |  |
| 192 | `displayobjectcontainer_addchildat_timelinelock1` | 2.9% | 1/34 | 1 | 34 |  |
| 193 | `displayobjectcontainer_addchildat_timelinelock2` | 2.9% | 1/34 | 1 | 34 |  |
| 194 | `register_script_refresh` | 2.9% | 1/35 | 3 | 35 |  |
| 195 | `simplebutton_constr` | 2.8% | 1/36 | 1 | 36 |  |
| 196 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 2.6% | 1/38 | 1 | 38 |  |
| 197 | `textfield_unload` | 2.6% | 1/39 | 1 | 39 |  |
| 198 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 199 | `font_hasglyphs` | 2.5% | 1/40 | 1 | 40 |  |
| 200 | `movieclip_dispatchevent_selfadd` | 2.5% | 2/80 | 2 | 80 |  |
| 201 | `perspective_projection_basic` | 2.5% | 1/40 | 1 | 40 |  |
| 202 | `font_enumeratefonts` | 2.4% | 1/41 | 1 | 41 |  |
| 203 | `dictionary_foreach` | 2.4% | 1/42 | 1 | 42 |  |
| 204 | `displayobjectcontainer_addchildat` | 2.4% | 1/42 | 1 | 42 |  |
| 205 | `displayobjectcontainer_setchildindex` | 2.4% | 1/42 | 1 | 42 |  |
| 206 | `displayobjectcontainer_swapchildren` | 2.4% | 1/42 | 1 | 42 |  |
| 207 | `displayobjectcontainer_swapchildrenat` | 2.4% | 1/42 | 1 | 42 |  |
| 208 | `simplebutton_constr_params` | 2.4% | 1/42 | 1 | 42 |  |
| 209 | `blur_filter` | 2.3% | 1/43 | 1 | 43 |  |
| 210 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 211 | `movieclip_currentlabels_dupes1` | 2.2% | 1/46 | 1 | 46 |  |
| 212 | `regexp_extended` | 2.1% | 1/47 | 1 | 47 |  |
| 213 | `movieclip_displayevents` | 2.1% | 2/96 | 2 | 96 |  |
| 214 | `movieclip_displayevents_swap` | 2.1% | 2/96 | 2 | 96 |  |
| 215 | `simplebutton_constr_childevents` | 2.1% | 1/48 | 1 | 48 |  |
| 216 | `displayobject_hittestpoint` | 2.0% | 1/49 | 1 | 49 |  |
| 217 | `displayobjectcontainer_removechildren` | 2.0% | 1/51 | 1 | 51 |  |
| 218 | `movieclip_dispatchevent_cancel` | 2.0% | 2/102 | 2 | 102 |  |
| 219 | `string_replace` | 2.0% | 1/51 | 1 | 51 |  |
| 220 | `shape_drawrect` | 1.9% | 1/54 | 1 | 54 |  |
| 221 | `goto_methods` | 1.8% | 1/56 | 1 | 56 |  |
| 222 | `displayobjectcontainer_addchild_timelinepull0` | 1.7% | 1/58 | 1 | 58 |  |
| 223 | `vector_join` | 1.7% | 1/58 | 1 | 58 |  |
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
| 235 | `vector_coercion` | 1.5% | 1/66 | 1 | 66 |  |
| 236 | `movieclip_currentlabels_dupes3` | 1.5% | 1/67 | 1 | 67 |  |
| 237 | `stylesheet_parse_color` | 1.4% | 1/69 | 1 | 69 |  |
| 238 | `geom_transform` | 1.4% | 1/74 | 1 | 74 |  |
| 239 | `vector_tostring` | 1.3% | 1/79 | 1 | 79 |  |
| 240 | `vector_map` | 1.2% | 1/85 | 1 | 85 |  |
| 241 | `simplebutton_childevents_script_order` | 1.1% | 1/87 | 1 | 87 |  |
| 242 | `convolution_filter` | 1.1% | 1/89 | 1 | 89 |  |
| 243 | `vector_concat` | 1.1% | 1/90 | 1 | 90 |  |
| 244 | `vector_every` | 1.1% | 1/92 | 1 | 92 |  |
| 245 | `vector_filter` | 1.1% | 1/95 | 1 | 95 |  |
| 246 | `dictionary_delete` | 1.0% | 1/101 | 1 | 101 |  |
| 247 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 248 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 249 | `vector_constr` | 0.9% | 1/107 | 1 | 107 |  |
| 250 | `orphan_movie_reorder` | 0.9% | 1/111 | 1 | 111 |  |
| 251 | `movieclip_displayevents_stopped` | 0.9% | 1/113 | 1 | 113 |  |
| 252 | `movieclip_dispatchevent_handlerorder` | 0.8% | 2/251 | 2 | 251 |  |
| 253 | `glow_filter` | 0.8% | 1/127 | 1 | 127 |  |
| 254 | `font_registerfont` | 0.8% | 1/129 | 1 | 129 |  |
| 255 | `domain_memory` | 0.8% | 1/133 | 1 | 133 |  |
| 256 | `bounds_mode` | 0.7% | 2/269 | 2 | 269 |  |
| 257 | `edittext_default_format_empty` | 0.7% | 1/136 | 1 | 136 |  |
| 258 | `regexp_constr` | 0.7% | 1/148 | 1 | 148 |  |
| 259 | `drop_shadow_filter` | 0.6% | 1/172 | 1 | 172 |  |
| 260 | `vector_removeat` | 0.6% | 1/172 | 1 | 172 |  |
| 261 | `bevel_filter` | 0.5% | 1/187 | 1 | 187 |  |
| 262 | `vector3d` | 0.5% | 2/397 | 2 | 397 |  |
| 263 | `gradient_bevel_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 264 | `gradient_glow_filter` | 0.5% | 1/206 | 1 | 206 |  |
| 265 | `movieclip_dispatchevent` | 0.5% | 2/430 | 2 | 430 |  |
| 266 | `vector_reverse` | 0.4% | 1/232 | 1 | 232 |  |
| 267 | `vector_shiftunshift` | 0.4% | 1/252 | 1 | 252 |  |
| 268 | `vector_pushpop` | 0.4% | 1/255 | 1 | 255 |  |
| 269 | `vector_insertat` | 0.4% | 1/270 | 1 | 270 |  |
| 270 | `edittext_antialiastype` | 0.3% | 1/296 | 1 | 296 |  |
| 271 | `vector_indexof` | 0.3% | 1/302 | 1 | 302 |  |
| 272 | `vector_lastindexof` | 0.3% | 1/302 | 1 | 302 |  |
| 273 | `vector_slice` | 0.3% | 1/331 | 1 | 331 |  |
| 274 | `bitmapdata_pixeldissolve` | 0.3% | 3/1037 | 4 | 1037 |  |
| 275 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 276 | `movieclip_dispatchevent_target` | 0.2% | 2/899 | 2 | 899 |  |
| 277 | `vector_splice` | 0.1% | 1/693 | 1 | 693 |  |
| 278 | `movieclip_soundtransform` | 0.1% | 1/831 | 1 | 831 |  |
| 279 | `soundchannel_soundtransform` | 0.1% | 1/835 | 1 | 835 |  |
| 280 | `simplebutton_soundtransform` | 0.1% | 1/887 | 1 | 887 |  |
| 281 | `soundmixer_soundtransform` | 0.1% | 1/900 | 1 | 900 |  |
| 282 | `vector_sort` | 0.1% | 1/905 | 1 | 905 |  |
| 283 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 284 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 285 | `perspective_projection` | 0.1% | 1/1443 | 1 | 1443 |  |
| 286 | `displayobject_width` | 0.0% | 2/4852 | 4 | 4852 |  |
| 287 | `displayobject_height` | 0.0% | 2/6052 | 4 | 6052 |  |
| 288 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 289 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 291 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 0 | 88 |  |
| 293 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 0 | 88 |  |
| 294 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 0 | 73 |  |
| 295 | `all_classes/display/swf10` | 0.0% | 0/2569 | 0 | 2569 |  |
| 296 | `all_classes/display/swf11` | 0.0% | 0/2593 | 0 | 2593 |  |
| 297 | `all_classes/display/swf12` | 0.0% | 0/2593 | 0 | 2593 |  |
| 298 | `all_classes/display/swf13` | 0.0% | 0/2671 | 0 | 2671 |  |
| 299 | `all_classes/display/swf30` | 0.0% | 0/2936 | 0 | 2936 |  |
| 300 | `all_classes/display/swf9` | 0.0% | 0/1959 | 0 | 1959 |  |
| 301 | `all_classes/display3D/swf12` | 0.0% | 0/61 | 0 | 61 |  |
| 302 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 0 | 326 |  |
| 303 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 0 | 412 |  |
| 304 | `all_classes/errors/swf10` | 0.0% | 0/140 | 0 | 140 |  |
| 305 | `all_classes/errors/swf30` | 0.0% | 0/140 | 0 | 140 |  |
| 306 | `all_classes/errors/swf9` | 0.0% | 0/121 | 0 | 121 |  |
| 307 | `all_classes/events/swf10` | 0.0% | 0/1638 | 0 | 1638 |  |
| 308 | `all_classes/events/swf11` | 0.0% | 0/1750 | 0 | 1750 |  |
| 309 | `all_classes/events/swf12` | 0.0% | 0/1814 | 0 | 1814 |  |
| 310 | `all_classes/events/swf30` | 0.0% | 0/2353 | 0 | 2353 |  |
| 311 | `all_classes/events/swf9` | 0.0% | 0/1030 | 0 | 1030 |  |
| 312 | `all_classes/security/swf11` | 0.0% | 0/3 | 0 | 3 |  |
| 313 | `all_classes/security/swf12` | 0.0% | 0/19 | 0 | 19 |  |
| 314 | `all_classes/security/swf13` | 0.0% | 0/53 | 0 | 53 |  |
| 315 | `all_classes/security/swf30` | 0.0% | 0/53 | 0 | 53 |  |
| 316 | `all_classes/xml/swf30` | 0.0% | 0/116 | 0 | 116 |  |
| 317 | `all_classes/xml/swf9` | 0.0% | 0/116 | 0 | 116 |  |
| 318 | `amf_function` | 0.0% | 0/46 | 0 | 46 |  |
| 319 | `amf_invalid_date` | 0.0% | 0/2 | 0 | 2 |  |
| 320 | `amf_missing_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 321 | `amf_nondynamic_function_prop` | 0.0% | 0/6 | 0 | 6 |  |
| 322 | `amf_setter_error` | 0.0% | 0/8 | 0 | 8 |  |
| 323 | `amf_vector` | 0.0% | 0/40 | 0 | 40 |  |
| 324 | `amf_xml` | 0.0% | 0/6 | 0 | 6 |  |
| 325 | `appdomain_lookup_edge_cases` | 0.0% | 0/32 | 0 | 32 |  |
| 326 | `application_domain` | 0.0% | 0/4 | 2 | 4 |  |
| 327 | `applicationdomain_hasdefinition_null` | 0.0% | 0/2 | 0 | 2 |  |
| 328 | `array_vector_null_callback` | 0.0% | 0/10 | 0 | 10 |  |
| 329 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 330 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 331 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 332 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 333 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 334 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 335 | `bitmap_data` | 0.0% | 0/1000 | 0 | 1000 |  |
| 336 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `bitmapdata_accuracy` | 0.0% | 0/1 | 0 | 1 |  |
| 338 | `bitmapdata_colortransform_oob` | 0.0% | 0/2 | 0 | 2 |  |
| 339 | `bitmapdata_constructor_from_timeline` | 0.0% | 0/1 | 0 | 1 |  |
| 340 | `bitmapdata_copypixels` | 0.0% | 0/23 | 0 | 23 |  |
| 341 | `bitmapdata_copypixels_blend_over` | 0.0% | 0/1 | 0 | 1 |  |
| 342 | `bitmapdata_copypixelstobytearray` | 0.0% | 0/39 | 0 | 39 |  |
| 343 | `bitmapdata_dispose` | 0.0% | 0/7 | 0 | 7 |  |
| 344 | `bitmapdata_draw_alpha_erase` | 0.0% | 0/8 | 0 | 8 |  |
| 345 | `bitmapdata_floodfill` | 0.0% | 0/35 | 0 | 35 |  |
| 346 | `bitmapdata_getpixels` | 0.0% | 0/39 | 0 | 39 |  |
| 347 | `bitmapdata_getvector` | 0.0% | 0/27 | 0 | 27 |  |
| 348 | `bitmapdata_histogram` | 0.0% | 0/59 | 0 | 59 |  |
| 349 | `bitmapdata_hittest` | 0.0% | 0/112 | 0 | 112 |  |
| 350 | `bitmapdata_hittest_threshold` | 0.0% | 0/18 | 0 | 18 |  |
| 351 | `bitmapdata_rectangle_rounding` | 0.0% | 0/16 | 0 | 16 |  |
| 352 | `bitmapdata_setpixels` | 0.0% | 0/286 | 0 | 286 |  |
| 353 | `bitmapdata_setvector` | 0.0% | 0/26 | 0 | 26 |  |
| 354 | `bitmapdata_threshold` | 0.0% | 0/176 | 0 | 176 |  |
| 355 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 356 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 357 | `bom` | 0.0% | 0/9 | 0 | 9 |  |
| 358 | `broadcast_event` | 0.0% | 0/7 | 0 | 7 |  |
| 359 | `button_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 360 | `button_hittest` | 0.0% | 0/2 | 0 | 2 |  |
| 361 | `bytearray` | 0.0% | 0/48 | 0 | 48 |  |
| 362 | `bytearray_compress` | 0.0% | 0/31 | 0 | 31 |  |
| 363 | `bytearray_errors` | 0.0% | 0/24 | 0 | 24 |  |
| 364 | `bytearray_method_serialization` | 0.0% | 0/1 | 0 | 1 |  |
| 365 | `bytearray_oom` | 0.0% | 0/3 | 2 | 3 |  |
| 366 | `bytearray_readobject_amf0` | 0.0% | 0/50 | 0 | 50 |  |
| 367 | `bytearray_readobject_amf3` | 0.0% | 0/53 | 0 | 53 |  |
| 368 | `bytearray_readutf8bytes_with_bom` | 0.0% | 0/16 | 0 | 16 |  |
| 369 | `bytearray_serialization` | 0.0% | 0/3 | 0 | 3 |  |
| 370 | `bytearray_string_null` | 0.0% | 0/19 | 0 | 19 |  |
| 371 | `bytearray_tostring` | 0.0% | 0/15 | 0 | 15 |  |
| 372 | `bytearray_utf16` | 0.0% | 0/8 | 0 | 8 |  |
| 373 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 374 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 375 | `coerce_to_primitive_side_effects` | 0.0% | 0/29 | 0 | 29 |  |
| 376 | `coerce_to_primitive_side_effects_with_nulls` | 0.0% | 0/37 | 0 | 37 |  |
| 377 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 378 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 379 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 380 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 381 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 382 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 383 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 384 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 385 | `cryptscore` | 0.0% | 0/11 | 0 | 11 |  |
| 386 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 387 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 388 | `delayed_symbolclass` | 0.0% | 0/28 | 3 | 28 |  |
| 389 | `describe_type_basic` | 0.0% | 0/152 | 0 | 152 |  |
| 390 | `describe_type_json` | 0.0% | 0/301 | 0 | 301 |  |
| 391 | `describe_type_metadata` | 0.0% | 0/125 | 0 | 125 |  |
| 392 | `describe_type_native` | 0.0% | 0/23 | 0 | 23 |  |
| 393 | `dictionary_namespaces` | 0.0% | 0/36 | 0 | 36 |  |
| 394 | `dictionary_weak_keys` | 0.0% | 0/2 | 0 | 2 |  |
| 395 | `displayobject_early_init` | 0.0% | 0/54 | 1 | 54 |  |
| 396 | `displayobject_from_enterframe` | 0.0% | 0/1 | 0 | 1 |  |
| 397 | `displayobject_hittestpoint_boundary` | 0.0% | 0/65 | 0 | 65 |  |
| 398 | `displayobject_hittestpoint_root` | 0.0% | 0/13 | 0 | 13 |  |
| 399 | `displayobject_invalid_floats` | 0.0% | 0/60 | 0 | 60 |  |
| 400 | `displayobject_invalid_props` | 0.0% | 0/3 | 0 | 3 |  |
| 401 | `displayobject_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 402 | `displayobject_metaData` | 0.0% | 0/3 | 0 | 3 |  |
| 403 | `displayobject_opaque_background` | 0.0% | 0/6 | 0 | 6 |  |
| 404 | `displayobject_parent` | 0.0% | 0/12 | 0 | 12 |  |
| 405 | `displayobject_scrollrect` | 0.0% | 0/33 | 0 | 33 |  |
| 406 | `displayobject_set_name_loaded` | 0.0% | 0/3 | 1 | 3 |  |
| 407 | `displayobject_subclass` | 0.0% | 0/2 | 1 | 2 |  |
| 408 | `displayobject_transform` | 0.0% | 0/89 | 0 | 89 |  |
| 409 | `displayobjectcontainer_addchild_lazy_sprite` | 0.0% | 0/1 | 0 | 1 |  |
| 410 | `displayobjectcontainer_getobjectsunderpoint` | 0.0% | 0/15 | 0 | 15 |  |
| 411 | `displayobjectcontainer_stopallmovieclips` | 0.0% | 0/2 | 0 | 2 |  |
| 412 | `documentclass` | 0.0% | 0/9 | 4 | 9 |  |
| 413 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 414 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 415 | `edit_text_linkage` | 0.0% | 0/7 | 2 | 7 |  |
| 416 | `edittext_align` | 0.0% | 0/60 | 0 | 60 |  |
| 417 | `edittext_autosize` | 0.0% | 0/39 | 0 | 39 |  |
| 418 | `edittext_autosize_lazy_bounds_events` | 0.0% | 0/65 | 0 | 65 |  |
| 419 | `edittext_autosize_lazy_bounds_interactions` | 0.0% | 0/19 | 0 | 19 |  |
| 420 | `edittext_bullet` | 0.0% | 0/30 | 0 | 30 |  |
| 421 | `edittext_default_format` | 0.0% | 0/221 | 0 | 221 |  |
| 422 | `edittext_focus_selection` | 0.0% | 0/5 | 0 | 5 |  |
| 423 | `edittext_font_size` | 0.0% | 0/45 | 0 | 45 |  |
| 424 | `edittext_format_empty_font` | 0.0% | 0/8 | 0 | 8 |  |
| 425 | `edittext_getcharboundaries_missing_embedded_font` | 0.0% | 0/7 | 0 | 7 |  |
| 426 | `edittext_getlinemetrics` | 0.0% | 0/146 | 0 | 146 |  |
| 427 | `edittext_html` | 0.0% | 0/3101 | 0 | 3101 |  |
| 428 | `edittext_html_condensewhite` | 0.0% | 0/487 | 0 | 487 |  |
| 429 | `edittext_html_entity` | 0.0% | 0/4 | 0 | 4 |  |
| 430 | `edittext_html_font_size_swf12` | 0.0% | 0/267 | 0 | 267 |  |
| 431 | `edittext_html_font_size_swf13` | 0.0% | 0/273 | 0 | 273 |  |
| 432 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 0 | 9 |  |
| 433 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 434 | `edittext_leading` | 0.0% | 0/9 | 0 | 9 |  |
| 435 | `edittext_letter_spacing` | 0.0% | 0/15 | 0 | 15 |  |
| 436 | `edittext_margins` | 0.0% | 0/25 | 0 | 25 |  |
| 437 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 438 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 439 | `edittext_newlines` | 0.0% | 0/30 | 0 | 30 |  |
| 440 | `edittext_paragraph_methods` | 0.0% | 0/257 | 0 | 257 |  |
| 441 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 442 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 443 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 444 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 445 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 446 | `edittext_scrollh` | 0.0% | 0/10 | 0 | 10 |  |
| 447 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 448 | `edittext_set_html_same` | 0.0% | 0/17 | 0 | 17 |  |
| 449 | `edittext_set_text_vs_html` | 0.0% | 0/9 | 0 | 9 |  |
| 450 | `edittext_stylesheet` | 0.0% | 0/536 | 0 | 536 |  |
| 451 | `edittext_stylesheet_custom_tag` | 0.0% | 0/76 | 0 | 76 |  |
| 452 | `edittext_stylesheet_display` | 0.0% | 0/272 | 0 | 272 |  |
| 453 | `edittext_tab_stops` | 0.0% | 0/60 | 0 | 60 |  |
| 454 | `edittext_tag_indent` | 0.0% | 0/49 | 0 | 49 |  |
| 455 | `edittext_underline` | 0.0% | 0/40 | 0 | 40 |  |
| 456 | `edittext_width_height` | 0.0% | 0/103 | 0 | 103 |  |
| 457 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 458 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 459 | `empty_bounds` | 0.0% | 0/1 | 0 | 1 |  |
| 460 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 461 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 462 | `error_1034_debug_string` | 0.0% | 0/30 | 0 | 30 |  |
| 463 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 464 | `error_prototype` | 0.0% | 0/15 | 0 | 15 |  |
| 465 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 466 | `error_tostring` | 0.0% | 0/29 | 0 | 29 |  |
| 467 | `error_tostring_more` | 0.0% | 0/86 | 0 | 86 |  |
| 468 | `event_bubbles` | 0.0% | 0/2 | 0 | 2 |  |
| 469 | `event_cancelable` | 0.0% | 0/2 | 0 | 2 |  |
| 470 | `event_clone` | 0.0% | 0/20 | 0 | 20 |  |
| 471 | `event_clone_error_redispatch` | 0.0% | 0/3 | 0 | 3 |  |
| 472 | `event_clone_on_redispatch` | 0.0% | 0/10 | 0 | 10 |  |
| 473 | `event_formattostring` | 0.0% | 0/31 | 0 | 31 |  |
| 474 | `event_handler_exception` | 0.0% | 0/4 | 0 | 4 |  |
| 475 | `event_target_set` | 0.0% | 0/9 | 0 | 9 |  |
| 476 | `event_type` | 0.0% | 0/1 | 0 | 1 |  |
| 477 | `eventdispatcher_dispatchevent_indirect` | 0.0% | 0/9 | 0 | 9 |  |
| 478 | `eventdispatcher_interface_invoke` | 0.0% | 0/1 | 0 | 1 |  |
| 479 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 480 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 481 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 482 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 483 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 484 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 485 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 486 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 487 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 488 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 489 | `filter_rewind` | 0.0% | 0/8 | 0 | 8 |  |
| 490 | `flash_xml` | 0.0% | 0/29 | 0 | 29 |  |
| 491 | `flash_xml_cloneNode` | 0.0% | 0/22 | 0 | 22 |  |
| 492 | `flash_xml_namespace` | 0.0% | 0/109 | 0 | 109 |  |
| 493 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 494 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 495 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 496 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 497 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 498 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 499 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 500 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 501 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 502 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 503 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 504 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 505 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 506 | `focusrect_property` | 0.0% | 0/110 | 0 | 110 |  |
| 507 | `font_description_clone` | 0.0% | 0/14 | 0 | 14 |  |
| 508 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 509 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 510 | `get_qualified_super_class_name` | 0.0% | 0/18 | 0 | 18 |  |
| 511 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 512 | `goto_button_nested_framescript` | 0.0% | 0/28 | 0 | 28 |  |
| 513 | `goto_framescript_queued` | 0.0% | 0/6 | 0 | 6 |  |
| 514 | `goto_in_constructframe` | 0.0% | 0/12 | 0 | 12 |  |
| 515 | `goto_nested_construct_sibling` | 0.0% | 0/18 | 0 | 18 |  |
| 516 | `goto_nested_framescript` | 0.0% | 0/9 | 0 | 9 |  |
| 517 | `goto_on_orphan` | 0.0% | 0/15 | 0 | 15 |  |
| 518 | `graphic_linkage` | 0.0% | 0/9 | 2 | 9 |  |
| 519 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 520 | `graphics_draw_path` | 0.0% | 0/34 | 0 | 34 |  |
| 521 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 522 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 523 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 524 | `indexing_delete` | 0.0% | 0/75 | 0 | 75 |  |
| 525 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 526 | `instantiation_on_enter_frame` | 0.0% | 0/7 | 0 | 7 |  |
| 527 | `instantiation_on_enterframe_gotoandstop` | 0.0% | 0/8 | 0 | 8 |  |
| 528 | `invalid_utf8` | 0.0% | 0/12 | 0 | 12 |  |
| 529 | `issue_13780` | 0.0% | 0/12 | 0 | 12 |  |
| 530 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 531 | `issue_8630_placeremoveplace` | 0.0% | 0/15 | 4 | 15 |  |
| 532 | `issue_8630_placeremoveplace_scriptremove` | 0.0% | 0/16 | 4 | 16 |  |
| 533 | `issue_8630_scriptremove` | 0.0% | 0/11 | 4 | 11 |  |
| 534 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 535 | `json_errors` | 0.0% | 0/10 | 10 | 9 |  |
| 536 | `json_parse` | 0.0% | 0/21 | 0 | 21 |  |
| 537 | `json_stringify` | 0.0% | 0/14 | 0 | 14 |  |
| 538 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 539 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 540 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 541 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 542 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 543 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 544 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 545 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 546 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 547 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 548 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 549 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 550 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 551 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 552 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 553 | `loader_loadbytes_url` | 0.0% | 0/12 | 0 | 12 |  |
| 554 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 555 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 556 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 557 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 558 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 559 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 560 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 561 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 562 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 563 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 564 | `loaderinfo_root` | 0.0% | 0/10 | 2 | 10 |  |
| 565 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 566 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 567 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 568 | `mask_reapply` | 0.0% | 0/1 | 0 | 1 |  |
| 569 | `matrix` | 0.0% | 0/338 | 0 | 338 |  |
| 570 | `matrix3d` | 0.0% | 0/57 | 0 | 57 |  |
| 571 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 572 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 573 | `morph_shape` | 0.0% | 0/2 | 1 | 2 |  |
| 574 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 575 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 576 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 577 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 578 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 579 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 580 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 581 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 582 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 583 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 584 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 585 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 586 | `mouse_pick_text` | 0.0% | 0/8 | 0 | 8 |  |
| 587 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 588 | `mouseevent_stagexy` | 0.0% | 0/35 | 0 | 35 |  |
| 589 | `movieclip_displayevents_clickgoto` | 0.0% | 0/676 | 0 | 676 |  |
| 590 | `movieclip_displayevents_clickgoto2` | 0.0% | 0/2001 | 0 | 2001 |  |
| 591 | `movieclip_displayevents_clickplay` | 0.0% | 0/575 | 0 | 575 |  |
| 592 | `movieclip_displayevents_clicksymbol` | 0.0% | 0/562 | 0 | 562 |  |
| 593 | `movieclip_displayevents_constructframegoto` | 0.0% | 0/140 | 0 | 140 |  |
| 594 | `movieclip_displayevents_constructframeplay` | 0.0% | 0/50 | 0 | 50 |  |
| 595 | `movieclip_displayevents_constructframesymbol` | 0.0% | 0/144 | 0 | 144 |  |
| 596 | `movieclip_displayevents_dblhandler` | 0.0% | 0/21 | 0 | 21 |  |
| 597 | `movieclip_displayevents_enterframegoto` | 0.0% | 0/149 | 0 | 149 |  |
| 598 | `movieclip_displayevents_enterframeplay` | 0.0% | 0/48 | 0 | 48 |  |
| 599 | `movieclip_displayevents_enterframesymbol` | 0.0% | 0/149 | 0 | 149 |  |
| 600 | `movieclip_displayevents_exitframegoto` | 0.0% | 0/106 | 0 | 106 |  |
| 601 | `movieclip_displayevents_exitframeplay` | 0.0% | 0/44 | 0 | 44 |  |
| 602 | `movieclip_displayevents_exitframesymbol` | 0.0% | 0/135 | 0 | 135 |  |
| 603 | `movieclip_displayevents_looping` | 0.0% | 0/63 | 1 | 63 |  |
| 604 | `movieclip_displayevents_timeline` | 0.0% | 0/128 | 0 | 128 |  |
| 605 | `movieclip_goto_scene_last_frame_int` | 0.0% | 0/1 | 0 | 1 |  |
| 606 | `movieclip_goto_scene_last_frame_label` | 0.0% | 0/1 | 0 | 1 |  |
| 607 | `movieclip_queued_noop_goto_swf10` | 0.0% | 0/9 | 0 | 9 |  |
| 608 | `movieclip_queued_noop_goto_swf9` | 0.0% | 0/7 | 0 | 7 |  |
| 609 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 610 | `movieclip_willtrigger` | 0.0% | 0/5 | 0 | 5 |  |
| 611 | `namespace_constr_args` | 0.0% | 0/1 | 0 | 1 |  |
| 612 | `namespace_enumeration_order` | 0.0% | 0/7 | 0 | 7 |  |
| 613 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 614 | `net_getClassByAlias` | 0.0% | 0/3 | 2 | 3 |  |
| 615 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 616 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 617 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 618 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 619 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 620 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 621 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 622 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 623 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 624 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 625 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 626 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 627 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 628 | `null_void_types` | 0.0% | 0/8 | 0 | 8 |  |
| 629 | `number_autoconv_amf` | 0.0% | 0/132 | 0 | 132 |  |
| 630 | `orphan_movie_complex` | 0.0% | 0/80 | 0 | 80 |  |
| 631 | `orphan_removeobject` | 0.0% | 0/636 | 0 | 636 |  |
| 632 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 633 | `parent_early_access_child` | 0.0% | 0/16 | 0 | 16 |  |
| 634 | `pixelbender_ceil` | 0.0% | 0/77 | 0 | 77 |  |
| 635 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 636 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 637 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 638 | `pixelbender_eof` | 0.0% | 0/7 | 0 | 7 |  |
| 639 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 640 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 641 | `pixelbender_no_out_param` | 0.0% | 0/6 | 0 | 6 |  |
| 642 | `pixelbender_outputs` | 0.0% | 0/13 | 0 | 13 |  |
| 643 | `pixelbender_padding_bytes` | 0.0% | 0/22 | 0 | 22 |  |
| 644 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 0 | 512 |  |
| 645 | `pixelbender_parse_errors` | 0.0% | 0/6 | 0 | 6 |  |
| 646 | `pixelbender_select_kinds` | 0.0% | 0/8 | 0 | 8 |  |
| 647 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 648 | `pixelbender_sign` | 0.0% | 0/60 | 0 | 60 |  |
| 649 | `place_and_lookup/swf10` | 0.0% | 0/33 | 6 | 33 |  |
| 650 | `place_and_lookup/swf9` | 0.0% | 0/33 | 6 | 33 |  |
| 651 | `place_multiple` | 0.0% | 0/17 | 0 | 17 |  |
| 652 | `place_object_same_depth_frame` | 0.0% | 0/1 | 0 | 1 |  |
| 653 | `primitive_edge_cases` | 0.0% | 0/1 | 0 | 1 |  |
| 654 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 655 | `property_is_enumerable_reset` | 0.0% | 0/23 | 0 | 23 |  |
| 656 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 657 | `proxy_callproperty` | 0.0% | 0/24 | 0 | 24 |  |
| 658 | `proxy_deleteproperty` | 0.0% | 0/64 | 0 | 64 |  |
| 659 | `proxy_enumeration` | 0.0% | 0/34 | 0 | 34 |  |
| 660 | `proxy_getproperty` | 0.0% | 0/77 | 0 | 77 |  |
| 661 | `proxy_hasownproperty` | 0.0% | 0/8 | 0 | 8 |  |
| 662 | `proxy_hasproperty` | 0.0% | 0/32 | 0 | 32 |  |
| 663 | `proxy_serialize` | 0.0% | 0/9 | 0 | 9 |  |
| 664 | `proxy_setproperty` | 0.0% | 0/42 | 0 | 42 |  |
| 665 | `qname_as_lazy_name_attribute_multiname` | 0.0% | 0/1 | 0 | 1 |  |
| 666 | `qname_indexing` | 0.0% | 0/23 | 0 | 23 |  |
| 667 | `regexp_multiargs` | 0.0% | 0/1 | 0 | 1 |  |
| 668 | `regexp_toString` | 0.0% | 0/10 | 0 | 10 |  |
| 669 | `remove_child_clear_field` | 0.0% | 0/88 | 0 | 88 |  |
| 670 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 671 | `rng` | 0.0% | 0/1 | 0 | 1 |  |
| 672 | `rootless` | 0.0% | 0/42 | 0 | 42 |  |
| 673 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 674 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 675 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 676 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 677 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 678 | `selection` | 0.0% | 0/239 | 0 | 239 |  |
| 679 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 680 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 681 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 682 | `simplebutton_added_to_stage` | 0.0% | 0/45 | 1 | 45 |  |
| 683 | `simplebutton_childevents` | 0.0% | 0/86 | 0 | 86 |  |
| 684 | `simplebutton_childevents_multichild` | 0.0% | 0/152 | 0 | 152 |  |
| 685 | `simplebutton_childevents_nested` | 0.0% | 0/54 | 4 | 54 |  |
| 686 | `simplebutton_childevents_sprite` | 0.0% | 0/13 | 0 | 13 |  |
| 687 | `simplebutton_childprops` | 0.0% | 0/144 | 2 | 144 |  |
| 688 | `simplebutton_multi_children` | 0.0% | 0/19 | 0 | 19 |  |
| 689 | `simplebutton_structure` | 0.0% | 0/27 | 3 | 27 |  |
| 690 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 691 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 692 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 693 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 694 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 695 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 696 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 697 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 698 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 699 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 700 | `sound_rootless` | 0.0% | 0/7 | 0 | 7 |  |
| 701 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 702 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 703 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 704 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 705 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 706 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 707 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 708 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 709 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 710 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 711 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 712 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 713 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 714 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 715 | `stage_framerate_nan` | 0.0% | 0/7 | 0 | 7 |  |
| 716 | `stage_invalidate` | 0.0% | 0/38 | 0 | 38 |  |
| 717 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 718 | `stage_overriden_setters` | 0.0% | 0/31 | 31 | 31 |  |
| 719 | `stage_properties2` | 0.0% | 0/8 | 0 | 8 |  |
| 720 | `stage_scale_factor` | 0.0% | 0/12 | 0 | 12 |  |
| 721 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 722 | `static_length` | 0.0% | 0/24 | 1 | 24 |  |
| 723 | `static_text` | 0.0% | 0/3 | 2 | 3 |  |
| 724 | `statictext_text` | 0.0% | 0/8 | 0 | 8 |  |
| 725 | `stylesheet` | 0.0% | 0/221 | 0 | 221 |  |
| 726 | `stylesheet_transform` | 0.0% | 0/307 | 0 | 307 |  |
| 727 | `subclass_superclass_linked_symbol` | 0.0% | 0/4 | 0 | 4 |  |
| 728 | `swf_10_queued_goto_scripts_construct` | 0.0% | 0/52 | 0 | 52 |  |
| 729 | `swf_9_queued_goto_scripts` | 0.0% | 0/6 | 0 | 6 |  |
| 730 | `swf_9_queued_goto_scripts_construct` | 0.0% | 0/28 | 0 | 28 |  |
| 731 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 732 | `swf_wrong_frame_count_isplaying` | 0.0% | 0/22 | 0 | 22 |  |
| 733 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 734 | `symbol_class_conflict` | 0.0% | 0/4 | 0 | 4 |  |
| 735 | `symbol_class_root_not_zero` | 0.0% | 0/1 | 0 | 1 |  |
| 736 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 737 | `tab_ordering_arrows` | 0.0% | 0/998 | 0 | 998 |  |
| 738 | `tab_ordering_automatic_advanced` | 0.0% | 0/184 | 0 | 184 |  |
| 739 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 740 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 741 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 742 | `tab_ordering_properties` | 0.0% | 0/732 | 0 | 732 |  |
| 743 | `tab_ordering_stage_tab_children` | 0.0% | 0/32 | 0 | 32 |  |
| 744 | `tab_ordering_stage_tab_children_remove_root` | 0.0% | 0/5 | 0 | 5 |  |
| 745 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 746 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 747 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 748 | `text_engine_fontdescription` | 0.0% | 0/27 | 0 | 27 |  |
| 749 | `text_run` | 0.0% | 0/7 | 0 | 7 |  |
| 750 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 751 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 752 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 753 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 754 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 755 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 756 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 757 | `textformat` | 0.0% | 0/1134 | 0 | 1134 |  |
| 758 | `textformat_display` | 0.0% | 0/14 | 0 | 14 |  |
| 759 | `textformat_font_max_length` | 0.0% | 0/4 | 0 | 4 |  |
| 760 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 761 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 762 | `textline_validity` | 0.0% | 0/162 | 0 | 162 |  |
| 763 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 764 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 765 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 766 | `timer_reset` | 0.0% | 0/8 | 0 | 8 |  |
| 767 | `uncaught_errors_stringified` | 0.0% | 0/3 | 0 | 3 |  |
| 768 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 769 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 770 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 771 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 772 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 773 | `vector_class` | 0.0% | 0/36 | 0 | 36 |  |
| 774 | `vector_class_call` | 0.0% | 0/11 | 11 | 11 |  |
| 775 | `vector_enumeration` | 0.0% | 0/5 | 0 | 5 |  |
| 776 | `vector_object_final` | 0.0% | 0/1 | 0 | 1 |  |
| 777 | `vector_reborrow_bug` | 0.0% | 0/10 | 0 | 10 |  |
| 778 | `vector_splice_fixed_bug_compat` | 0.0% | 0/4 | 0 | 4 |  |
| 779 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 780 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 781 | `verify_typecheck` | 0.0% | 0/4 | 0 | 4 |  |
| 782 | `xml_abstract_equality` | 0.0% | 0/36 | 0 | 36 |  |
| 783 | `xml_advanced` | 0.0% | 0/52 | 13 | 52 |  |
| 784 | `xml_appendchild` | 0.0% | 0/10 | 1 | 10 |  |
| 785 | `xml_appendchild_swf_v21` | 0.0% | 0/13 | 0 | 13 |  |
| 786 | `xml_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 787 | `xml_attribute` | 0.0% | 0/35 | 0 | 35 |  |
| 788 | `xml_attribute_name` | 0.0% | 0/40 | 0 | 40 |  |
| 789 | `xml_basic` | 0.0% | 0/32 | 0 | 32 |  |
| 790 | `xml_child` | 0.0% | 0/25 | 0 | 25 |  |
| 791 | `xml_childindex` | 0.0% | 0/7 | 0 | 7 |  |
| 792 | `xml_children` | 0.0% | 0/43 | 0 | 43 |  |
| 793 | `xml_class_call` | 0.0% | 0/9 | 0 | 9 |  |
| 794 | `xml_copy` | 0.0% | 0/20 | 0 | 20 |  |
| 795 | `xml_ctor_from_tostring` | 0.0% | 0/23 | 0 | 23 |  |
| 796 | `xml_delete` | 0.0% | 0/114 | 0 | 114 |  |
| 797 | `xml_elements` | 0.0% | 0/6 | 0 | 6 |  |
| 798 | `xml_ignore_white` | 0.0% | 0/6 | 2 | 6 |  |
| 799 | `xml_length` | 0.0% | 0/2 | 0 | 2 |  |
| 800 | `xml_list_as_attribute` | 0.0% | 0/9 | 1 | 9 |  |
| 801 | `xml_list_enumerate` | 0.0% | 0/4 | 2 | 4 |  |
| 802 | `xml_methods_settings` | 0.0% | 0/3 | 0 | 3 |  |
| 803 | `xml_namespace` | 0.0% | 0/39 | 0 | 39 |  |
| 804 | `xml_namespace_methods` | 0.0% | 0/245 | 0 | 245 |  |
| 805 | `xml_namespaced_property` | 0.0% | 0/7 | 0 | 7 |  |
| 806 | `xml_no_namespace` | 0.0% | 0/1 | 0 | 1 |  |
| 807 | `xml_nodekind` | 0.0% | 0/3 | 0 | 3 |  |
| 808 | `xml_normalize` | 0.0% | 0/35 | 0 | 35 |  |
| 809 | `xml_notification_bubbling` | 0.0% | 0/361 | 0 | 361 |  |
| 810 | `xml_parent` | 0.0% | 0/8 | 0 | 8 |  |
| 811 | `xml_set_children` | 0.0% | 0/17 | 0 | 17 |  |
| 812 | `xml_set_name` | 0.0% | 0/34 | 0 | 34 |  |
| 813 | `xml_settings` | 0.0% | 0/6 | 0 | 6 |  |
| 814 | `xml_simple_complex_content` | 0.0% | 0/47 | 0 | 47 |  |
| 815 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
| 816 | `xml_text` | 0.0% | 0/7 | 0 | 7 |  |
| 817 | `xml_tostring` | 0.0% | 0/6 | 6 | 6 |  |
| 818 | `xml_unescaping` | 0.0% | 0/23 | 0 | 23 |  |
| 819 | `xml_weird_ignores` | 0.0% | 0/56 | 56 | 54 |  |
| 820 | `xml_wildcard` | 0.0% | 0/11 | 0 | 11 |  |
| 821 | `xmldocument` | 0.0% | 0/254 | 0 | 254 |  |
| 822 | `xmlnode` | 0.0% | 0/3540 | 0 | 3540 |  |
| 823 | `zero_frame_clip` | 0.0% | 0/3 | 0 | 3 |  |
