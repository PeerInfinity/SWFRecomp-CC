# Ruffle Test Results (Filtered)

**Date**: 2026-11-21 17:28 UTC

**Git SHA**: `08709f6584`

**Run Duration**: 203m 13s

**Filtered**: 38 tests ignored out of 1334 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1296 |
| Passing | **1239** (95.6%) |
| Ruffle-matched | 18 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1257** (97.0%) |
| Failing | 39 |
| Total expected lines | 158377 |
| Matching lines | 153717 (97.1%) |
| Mismatched lines | 4660 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 39 | 100.0% |

## Passing Tests

**1239 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 6.7s |  |
| 2 | `accessibility` | 1 | 6.5s |  |
| 3 | `accessibilityimplementation` | 18 | 6.6s |  |
| 4 | `activation_class` | 6 | 6.5s |  |
| 5 | `add` | 1058 | 13.8s |  |
| 6 | `agal_compiler` | 13 | 8.8s |  |
| 7 | `air_datagram_socket` | 1 | 8.3s |  |
| 8 | `air_hidden_lookup` | 2 | 6.6s |  |
| 9 | `air_ifilepromise` | 1 | 6.5s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 6.7s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.9s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.9s |  |
| 13 | `all_classes/display/swf10` | 2569 | 6.7s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.0s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.0s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.0s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.9s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.9s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 6.5s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.9s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.9s |  |
| 22 | `all_classes/errors/swf10` | 140 | 6.6s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.9s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.9s |  |
| 25 | `all_classes/events/swf10` | 1638 | 6.6s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.9s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.9s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.9s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.9s |  |
| 30 | `all_classes/security/swf11` | 3 | 6.6s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.9s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.9s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.9s |  |
| 34 | `all_classes/xml/swf30` | 116 | 6.6s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.9s |  |
| 36 | `amf_array_serialization` | 17 | 24.8s |  |
| 37 | `amf_custom_obj` | 26 | 6.7s |  |
| 38 | `amf_dictionary` | 9 | 6.5s |  |
| 39 | `amf_function` | 46 | 6.6s |  |
| 40 | `amf_invalid_date` | 2 | 6.5s |  |
| 41 | `amf_missing_prop` | 6 | 6.6s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 2.2s |  |
| 43 | `amf_sealed_class_dynamic_properties` | 16 | 6.7s |  |
| 44 | `amf_setter_error` | 8 | 6.7s |  |
| 45 | `amf_vector` | 40 | 6.8s |  |
| 46 | `amf_xml` | 6 | 6.9s |  |
| 47 | `appdomain_lookup_edge_cases` | 32 | 7.0s |  |
| 48 | `application_domain` | 4 | 2.0s |  |
| 49 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.2s |  |
| 50 | `applicationdomain_hasdefinition_null` | 2 | 1.6s |  |
| 51 | `array_access` | 18 | 1.7s |  |
| 52 | `array_access_interpreter` | 4 | 1.7s |  |
| 53 | `array_access_no_pubns` | 2 | 6.4s |  |
| 54 | `array_concat` | 41 | 2.0s |  |
| 55 | `array_constr` | 10 | 6.6s |  |
| 56 | `array_delete` | 44 | 1.6s |  |
| 57 | `array_enumeration` | 10 | 1.7s |  |
| 58 | `array_enumeration_elements` | 11 | 1.9s |  |
| 59 | `array_every` | 8 | 1.8s |  |
| 60 | `array_filter` | 6 | 1.4s |  |
| 61 | `array_foreach` | 18 | 1.5s |  |
| 62 | `array_hasownproperty` | 11 | 1.7s |  |
| 63 | `array_holes` | 9 | 1.7s |  |
| 64 | `array_index_max` | 84 | 1.7s |  |
| 65 | `array_indexof` | 25 | 6.2s |  |
| 66 | `array_join` | 26 | 1.8s |  |
| 67 | `array_lastindexof` | 29 | 1.6s |  |
| 68 | `array_length` | 14 | 6.2s |  |
| 69 | `array_literal` | 3 | 1.5s |  |
| 70 | `array_map` | 8 | 1.4s |  |
| 71 | `array_pop` | 52 | 6.1s |  |
| 72 | `array_push` | 24 | 1.4s |  |
| 73 | `array_reborrow_bug` | 6 | 6.0s |  |
| 74 | `array_reverse` | 28 | 1.7s |  |
| 75 | `array_shift` | 51 | 1.8s |  |
| 76 | `array_slice` | 39 | 1.4s |  |
| 77 | `array_some` | 8 | 1.2s |  |
| 78 | `array_sort` | 297 | 2.1s |  |
| 79 | `array_sort_fun_swf12` | 2 | 1.6s |  |
| 80 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 81 | `array_sort_random` | 210 | 5.9s |  |
| 82 | `array_sort_swf10_32bit` | 1 | 1.6s |  |
| 83 | `array_sorton` | 545 | 1.6s |  |
| 84 | `array_sparse_ops` | 41 | 1.4s |  |
| 85 | `array_splice` | 133 | 0.8s |  |
| 86 | `array_splice2` | 428 | 6.7s |  |
| 87 | `array_splice_types` | 48 | 6.5s |  |
| 88 | `array_storage` | 8 | 6.5s |  |
| 89 | `array_tolocalestring` | 9 | 6.5s |  |
| 90 | `array_tostring` | 12 | 6.5s |  |
| 91 | `array_unshift` | 24 | 6.4s |  |
| 92 | `array_valueof` | 9 | 6.5s |  |
| 93 | `array_vector_null_callback` | 10 | 6.5s |  |
| 94 | `astype` | 28 | 6.6s |  |
| 95 | `astypelate` | 24 | 6.7s |  |
| 96 | `astypelate_propagates` | 1 | 6.5s |  |
| 97 | `asymmetric_key_events` | 11 | 6.8s |  |
| 98 | `automation_classes` | 122 | 2.6s |  |
| 99 | `av_classes` | 340 | 7.0s |  |
| 100 | `avm1movie_addcallback_call` | 14 | 6.8s |  |
| 101 | `avm2_catchup_dobj` | 158 | 7.4s |  |
| 102 | `away3d_advanced_shallow_water_demo` | 0 | 86.2s |  |
| 103 | `bevel_filter` | 187 | 7.0s |  |
| 104 | `bitand` | 1058 | 14.2s |  |
| 105 | `bitmap_constr` | 17 | 6.8s |  |
| 106 | `bitmap_data` | 1000 | 14.1s |  |
| 107 | `bitmap_filter_abstract` | 6 | 6.8s |  |
| 108 | `bitmap_pixelsnapping` | 2 | 23.5s |  |
| 109 | `bitmap_properties` | 23 | 6.7s |  |
| 110 | `bitmap_subclass` | 7 | 8.0s |  |
| 111 | `bitmap_subclass_properties` | 9 | 6.9s |  |
| 112 | `bitmap_timeline` | 9 | 6.9s |  |
| 113 | `bitmapdata_accuracy` | 1 | 50.7s |  |
| 114 | `bitmapdata_applyfilter_blur` | 0 | 23.6s |  |
| 115 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.2s |  |
| 116 | `bitmapdata_applyfilter_destpoint` | 0 | 23.4s |  |
| 117 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 23.7s |  |
| 118 | `bitmapdata_applyfilter_identity` | 4 | 23.3s |  |
| 119 | `bitmapdata_clone` | 13 | 6.9s |  |
| 120 | `bitmapdata_colortransform` | 0 | 7.0s |  |
| 121 | `bitmapdata_colortransform_oob` | 2 | 6.7s |  |
| 122 | `bitmapdata_constr` | 22 | 6.8s |  |
| 123 | `bitmapdata_constructor_from_timeline` | 1 | 7.0s |  |
| 124 | `bitmapdata_copychannel` | 0 | 25.0s |  |
| 125 | `bitmapdata_copypixels` | 23 | 23.8s |  |
| 126 | `bitmapdata_copypixels_alpha_combine` | 13 | 6.8s |  |
| 127 | `bitmapdata_copypixels_alpha_merge` | 9 | 6.7s |  |
| 128 | `bitmapdata_copypixels_blend` | 1029 | 7.0s |  |
| 129 | `bitmapdata_copypixels_blend_over` | 1 | 6.6s |  |
| 130 | `bitmapdata_copypixels_self` | 612 | 6.6s |  |
| 131 | `bitmapdata_copypixelstobytearray` | 39 | 6.6s |  |
| 132 | `bitmapdata_dispose` | 7 | 6.6s |  |
| 133 | `bitmapdata_draw` | 0 | 7.4s |  |
| 134 | `bitmapdata_draw_alpha_erase` | 8 | 6.7s |  |
| 135 | `bitmapdata_draw_cab_quality` | 0 | 23.9s |  |
| 136 | `bitmapdata_draw_colortransform` | 0 | 6.7s |  |
| 137 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 22.8s |  |
| 138 | `bitmapdata_draw_filters` | 0 | 22.8s |  |
| 139 | `bitmapdata_draw_masks` | 0 | 6.7s |  |
| 140 | `bitmapdata_draw_rotation` | 0 | 6.7s |  |
| 141 | `bitmapdata_draw_self_via_graphic` | 0 | 6.6s |  |
| 142 | `bitmapdata_draw_stage` | 0 | 22.7s |  |
| 143 | `bitmapdata_drawwithquality` | 0 | 7.1s |  |
| 144 | `bitmapdata_embedded` | 9 | 6.8s |  |
| 145 | `bitmapdata_fillrect` | 0 | 6.7s |  |
| 146 | `bitmapdata_filter_sourcerect` | 0 | 23.0s |  |
| 147 | `bitmapdata_floodfill` | 35 | 6.5s |  |
| 148 | `bitmapdata_getpixels` | 39 | 22.6s |  |
| 149 | `bitmapdata_getvector` | 27 | 2.2s |  |
| 150 | `bitmapdata_histogram` | 59 | 2.2s |  |
| 151 | `bitmapdata_hittest` | 112 | 7.1s |  |
| 152 | `bitmapdata_hittest_threshold` | 18 | 6.6s |  |
| 153 | `bitmapdata_opaque` | 0 | 6.7s |  |
| 154 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 155 | `bitmapdata_pixeldissolve_image` | 0 | 6.8s |  |
| 156 | `bitmapdata_rectangle_rounding` | 16 | 6.6s |  |
| 157 | `bitmapdata_setpixels` | 286 | 6.7s |  |
| 158 | `bitmapdata_setvector` | 26 | 6.8s |  |
| 159 | `bitmapdata_sync` | 0 | 22.7s |  |
| 160 | `bitmapdata_threshold` | 176 | 7.2s |  |
| 161 | `bitmapdata_zero_size` | 8 | 6.6s |  |
| 162 | `bitnot` | 46 | 6.6s |  |
| 163 | `bitor` | 1058 | 13.8s |  |
| 164 | `bitxor` | 1058 | 13.8s |  |
| 165 | `blend_mode_null` | 1 | 6.5s |  |
| 166 | `blend_multiply_alpha` | 0 | 6.6s |  |
| 167 | `blend_scroll` | 0 | 6.8s |  |
| 168 | `blend_shader_luma_lighten` | 3 | 7.0s |  |
| 169 | `blur_filter` | 43 | 6.8s |  |
| 170 | `boolean_constr` | 32 | 6.5s |  |
| 171 | `boolean_negation` | 30 | 6.5s |  |
| 172 | `boolean_tostring` | 8 | 6.5s |  |
| 173 | `broadcast_event` | 7 | 6.5s |  |
| 174 | `button_bounds` | 1 | 6.5s |  |
| 175 | `button_hittest` | 2 | 22.4s |  |
| 176 | `button_nested_frame` | 48 | 22.9s |  |
| 177 | `button_nested_frame_simple` | 27 | 6.7s |  |
| 178 | `bytearray` | 48 | 6.6s |  |
| 179 | `bytearray_amf3_shared_references` | 4 | 6.4s |  |
| 180 | `bytearray_bad_symbol_class` | 3 | 6.5s |  |
| 181 | `bytearray_bad_symbol_class_other_movie` | 6 | 2.3s |  |
| 182 | `bytearray_compress` | 31 | 6.5s |  |
| 183 | `bytearray_errors` | 24 | 6.6s |  |
| 184 | `bytearray_insertion_reborrow` | 5 | 6.5s |  |
| 185 | `bytearray_method_serialization` | 1 | 6.4s |  |
| 186 | `bytearray_readobject_amf0` | 50 | 6.5s |  |
| 187 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 188 | `bytearray_readutf8bytes_with_bom` | 16 | 6.5s |  |
| 189 | `bytearray_serialization` | 3 | 6.5s |  |
| 190 | `bytearray_string_null` | 19 | 6.7s |  |
| 191 | `bytearray_tostring` | 15 | 6.5s |  |
| 192 | `bytearray_utf16` | 8 | 6.6s |  |
| 193 | `bytearray_writeobject` | 24 | 6.6s |  |
| 194 | `callee_in_initializer` | 6 | 6.6s |  |
| 195 | `callproplex_class` | 1 | 6.6s |  |
| 196 | `capabilities_resolution` | 8 | 23.9s |  |
| 197 | `casi32` | 166 | 6.6s |  |
| 198 | `catch_class` | 6 | 6.5s |  |
| 199 | `catch_scope_slot` | 7 | 6.6s |  |
| 200 | `checkfilter` | 4 | 2.2s |  |
| 201 | `class_call` | 32 | 6.8s |  |
| 202 | `class_cast_call` | 14 | 6.6s |  |
| 203 | `class_enumeration` | 4 | 6.6s |  |
| 204 | `class_has_own_property` | 2 | 6.5s |  |
| 205 | `class_init_interpreter_mode` | 1 | 6.5s |  |
| 206 | `class_is` | 32 | 6.7s |  |
| 207 | `class_methods` | 5 | 6.6s |  |
| 208 | `class_object_properties` | 10 | 6.7s |  |
| 209 | `class_singleton` | 18 | 6.7s |  |
| 210 | `class_supercalls_errors` | 35 | 6.9s |  |
| 211 | `class_supercalls_mismatched` | 26 | 6.7s |  |
| 212 | `class_superclass_wrong_order` | 1 | 6.7s |  |
| 213 | `class_to_locale_string` | 2 | 6.7s |  |
| 214 | `class_to_string` | 2 | 6.7s |  |
| 215 | `class_value_of` | 2 | 6.8s |  |
| 216 | `click_block` | 5 | 23.6s |  |
| 217 | `click_invisible` | 3 | 6.8s |  |
| 218 | `closures` | 12 | 6.7s |  |
| 219 | `coerce_return_type` | 40 | 6.8s |  |
| 220 | `coerce_return_type_fail` | 2 | 6.6s |  |
| 221 | `coerce_return_void` | 3 | 6.6s |  |
| 222 | `coerce_string` | 86 | 6.8s |  |
| 223 | `coerce_string_precision` | 28 | 6.8s |  |
| 224 | `coerce_to_primitive_side_effects` | 29 | 6.9s |  |
| 225 | `collator_compare_basic` | 93 | 6.9s |  |
| 226 | `collator_flags` | 111 | 6.7s |  |
| 227 | `collator_locale_ids_windows` | 120 | 6.9s |  |
| 228 | `color_matrix_filter` | 19 | 6.9s |  |
| 229 | `construct_errors_swf10` | 8 | 6.8s |  |
| 230 | `construct_frame_list` | 22 | 23.4s |  |
| 231 | `construct_interface` | 3 | 6.7s |  |
| 232 | `constructor_call` | 3 | 6.7s |  |
| 233 | `constructors_vs_timeline` | 5 | 23.4s |  |
| 234 | `constructprop_dynamic_primitive` | 7 | 6.8s |  |
| 235 | `constructprop_method` | 2 | 6.7s |  |
| 236 | `constructsuper_null` | 2 | 2.2s |  |
| 237 | `content_element_basic` | 50 | 6.9s |  |
| 238 | `context3d_clear_mask` | 4 | 6.6s |  |
| 239 | `context3d_creation` | 9 | 6.7s |  |
| 240 | `control_flow_bool` | 4 | 6.7s |  |
| 241 | `control_flow_stricteq` | 8 | 6.7s |  |
| 242 | `convert_boolean` | 30 | 6.8s |  |
| 243 | `convert_integer` | 90 | 6.9s |  |
| 244 | `convert_number` | 56 | 6.8s |  |
| 245 | `convert_uinteger` | 90 | 6.9s |  |
| 246 | `convolution_filter` | 89 | 7.0s |  |
| 247 | `core_exceptions` | 47 | 7.8s |  |
| 248 | `cpool_index_invalid_bytecode_1` | 6 | 6.8s |  |
| 249 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 250 | `cpool_index_invalid_bytecode_3` | 1 | 6.8s |  |
| 251 | `cross_api_version_call_newer` | 12 | 7.3s |  |
| 252 | `cross_api_version_call_older` | 12 | 10.1s |  |
| 253 | `cryptscore` | 11 | 9.4s |  |
| 254 | `currency_parse_result` | 7 | 9.2s |  |
| 255 | `date` | 30 | 9.9s |  |
| 256 | `date_parse` | 36 | 9.3s |  |
| 257 | `date_set_time_out_of_range` | 62 | 9.1s |  |
| 258 | `declocal` | 46 | 9.2s |  |
| 259 | `declocal_i` | 46 | 9.2s |  |
| 260 | `decode_uri` | 71 | 9.6s |  |
| 261 | `decrement` | 46 | 9.3s |  |
| 262 | `decrement_i` | 46 | 3.6s |  |
| 263 | `default_values` | 7 | 9.1s |  |
| 264 | `delayed_symbolclass` | 28 | 30.6s |  |
| 265 | `describe_type_basic` | 152 | 9.6s |  |
| 266 | `describe_type_json` | 301 | 9.5s |  |
| 267 | `describe_type_metadata` | 125 | 9.5s |  |
| 268 | `describe_type_native` | 23 | 9.4s |  |
| 269 | `dictionary_access` | 62 | 9.6s |  |
| 270 | `dictionary_access_no_pubns` | 2 | 9.2s |  |
| 271 | `dictionary_delete` | 101 | 9.8s |  |
| 272 | `dictionary_foreach` | 42 | 9.5s |  |
| 273 | `dictionary_hasownproperty` | 63 | 9.5s |  |
| 274 | `dictionary_in` | 62 | 9.6s |  |
| 275 | `dictionary_iter_modify` | 8 | 9.3s |  |
| 276 | `dictionary_namespaces` | 36 | 9.4s |  |
| 277 | `displacement_map_filter` | 61 | 9.4s |  |
| 278 | `displayobject_alpha` | 277 | 9.2s |  |
| 279 | `displayobject_blendmode` | 0 | 30.9s |  |
| 280 | `displayobject_colortransform_nested` | 0 | 31.0s |  |
| 281 | `displayobject_early_init` | 54 | 11.7s |  |
| 282 | `displayobject_filters` | 17 | 9.8s |  |
| 283 | `displayobject_from_enterframe` | 1 | 30.6s |  |
| 284 | `displayobject_getbounds_shape` | 0 | 30.4s |  |
| 285 | `displayobject_getrect` | 16 | 9.7s |  |
| 286 | `displayobject_height` | 6052 | 31.1s |  |
| 287 | `displayobject_hittestobject` | 32 | 9.6s |  |
| 288 | `displayobject_hittestpoint` | 49 | 9.6s |  |
| 289 | `displayobject_hittestpoint_boundary` | 65 | 31.2s |  |
| 290 | `displayobject_hittestpoint_root` | 13 | 9.8s |  |
| 291 | `displayobject_invalid_floats` | 60 | 9.3s |  |
| 292 | `displayobject_invalid_props` | 3 | 9.3s |  |
| 293 | `displayobject_mask` | 3 | 9.9s |  |
| 294 | `displayobject_mask_self_referential` | 0 | 6.9s |  |
| 295 | `displayobject_metaData` | 3 | 6.8s |  |
| 296 | `displayobject_name` | 22 | 7.1s |  |
| 297 | `displayobject_name_from_timeline` | 24 | 7.1s |  |
| 298 | `displayobject_opaque_background` | 6 | 24.1s |  |
| 299 | `displayobject_parent` | 12 | 7.0s |  |
| 300 | `displayobject_root` | 24 | 7.0s |  |
| 301 | `displayobject_rotation` | 1284 | 7.1s |  |
| 302 | `displayobject_scrollrect` | 33 | 7.7s |  |
| 303 | `displayobject_set_matrix_nested` | 0 | 24.1s |  |
| 304 | `displayobject_set_name_loaded` | 3 | 7.2s |  |
| 305 | `displayobject_subclass` | 2 | 6.9s |  |
| 306 | `displayobject_transform` | 89 | 7.0s |  |
| 307 | `displayobject_visible` | 23 | 7.0s |  |
| 308 | `displayobject_width` | 4852 | 24.4s |  |
| 309 | `displayobject_x` | 614 | 7.0s |  |
| 310 | `displayobject_y` | 617 | 7.0s |  |
| 311 | `displayobject_z` | 38 | 24.7s |  |
| 312 | `displayobjectcontainer_addchild` | 32 | 7.1s |  |
| 313 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.9s |  |
| 314 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 315 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.1s |  |
| 316 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 317 | `displayobjectcontainer_addchildat` | 42 | 7.0s |  |
| 318 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.1s |  |
| 319 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.0s |  |
| 320 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.0s |  |
| 321 | `displayobjectcontainer_contains` | 66 | 24.3s |  |
| 322 | `displayobjectcontainer_getchildat` | 4 | 7.0s |  |
| 323 | `displayobjectcontainer_getchildbyname` | 9 | 6.9s |  |
| 324 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.9s |  |
| 325 | `displayobjectcontainer_getchildindex` | 28 | 6.9s |  |
| 326 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 24.0s |  |
| 327 | `displayobjectcontainer_removechild` | 10 | 6.9s |  |
| 328 | `displayobjectcontainer_removechild_errors` | 4 | 6.9s |  |
| 329 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.0s |  |
| 330 | `displayobjectcontainer_removechildat` | 18 | 6.9s |  |
| 331 | `displayobjectcontainer_removechildren` | 51 | 7.1s |  |
| 332 | `displayobjectcontainer_setchildindex` | 42 | 6.8s |  |
| 333 | `displayobjectcontainer_stopallmovieclips` | 2 | 24.4s |  |
| 334 | `displayobjectcontainer_swapchildren` | 42 | 7.1s |  |
| 335 | `displayobjectcontainer_swapchildrenat` | 42 | 8.6s |  |
| 336 | `displayobjectcontainer_timelineinstance` | 48 | 24.9s |  |
| 337 | `divide` | 1058 | 17.0s |  |
| 338 | `doabc_and_symbolclass_script_init_goto` | 7 | 24.4s |  |
| 339 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.7s |  |
| 340 | `doabc_is_eager` | 1 | 24.8s |  |
| 341 | `documentclass` | 9 | 8.1s |  |
| 342 | `domain_memory` | 133 | 8.7s |  |
| 343 | `drag_drop` | 10 | 7.9s |  |
| 344 | `drop_shadow_filter` | 172 | 8.0s |  |
| 345 | `duplicate_defs` | 1 | 7.7s |  |
| 346 | `eager_init` | 1 | 7.5s |  |
| 347 | `east_asian_justifier_clone` | 8 | 7.5s |  |
| 348 | `edit_text_linkage` | 7 | 7.8s |  |
| 349 | `edittext_align` | 60 | 8.5s |  |
| 350 | `edittext_always_show_selection` | 0 | 25.4s |  |
| 351 | `edittext_antialiastype` | 296 | 8.4s |  |
| 352 | `edittext_at_point_methods_basic` | 16 | 9.0s |  |
| 353 | `edittext_autosize` | 39 | 8.1s |  |
| 354 | `edittext_autosize_align` | 0 | 25.0s |  |
| 355 | `edittext_autosize_height_dynamic` | 60 | 24.8s |  |
| 356 | `edittext_autosize_height_input` | 60 | 7.8s |  |
| 357 | `edittext_autosize_lazy_bounds_events` | 65 | 7.9s |  |
| 358 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.6s |  |
| 359 | `edittext_autosize_lazy_bounds_props` | 490 | 9.1s |  |
| 360 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.8s |  |
| 361 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.8s |  |
| 362 | `edittext_bottom_scroll_v_basic` | 210 | 7.9s |  |
| 363 | `edittext_bounds_scale` | 24 | 24.6s |  |
| 364 | `edittext_bullet` | 30 | 7.8s |  |
| 365 | `edittext_default_format` | 221 | 8.0s |  |
| 366 | `edittext_default_format_empty` | 136 | 8.1s |  |
| 367 | `edittext_empty_text_format` | 7 | 8.4s |  |
| 368 | `edittext_focus_selection` | 5 | 7.8s |  |
| 369 | `edittext_font_size` | 45 | 7.8s |  |
| 370 | `edittext_format_empty_font` | 8 | 7.5s |  |
| 371 | `edittext_get_char_index_at_point` | 4 | 26.4s |  |
| 372 | `edittext_get_line_index_at_point` | 2 | 24.5s |  |
| 373 | `edittext_get_line_index_of_char` | 76 | 8.5s |  |
| 374 | `edittext_getcharboundaries` | 172 | 8.1s |  |
| 375 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.7s |  |
| 376 | `edittext_getcharboundaries_scroll` | 85 | 6.6s |  |
| 377 | `edittext_getlinemetrics` | 146 | 6.5s |  |
| 378 | `edittext_html` | 3101 | 6.7s |  |
| 379 | `edittext_html_condensewhite` | 487 | 6.4s |  |
| 380 | `edittext_html_entity` | 4 | 6.6s |  |
| 381 | `edittext_html_font_size_swf12` | 267 | 6.1s |  |
| 382 | `edittext_html_font_size_swf13` | 273 | 6.0s |  |
| 383 | `edittext_html_roundtrip` | 17 | 6.4s |  |
| 384 | `edittext_ime_focus_lost` | 9 | 20.0s |  |
| 385 | `edittext_input_control` | 12 | 6.4s |  |
| 386 | `edittext_leading` | 9 | 6.8s |  |
| 387 | `edittext_letter_spacing` | 15 | 6.7s |  |
| 388 | `edittext_line_methods` | 294 | 7.9s |  |
| 389 | `edittext_line_metrics` | 11 | 22.4s |  |
| 390 | `edittext_margins` | 25 | 6.8s |  |
| 391 | `edittext_max_scroll_h_basic` | 475 | 6.9s |  |
| 392 | `edittext_max_scroll_v_basic` | 1000 | 6.9s |  |
| 393 | `edittext_mouse_selection` | 363 | 22.2s |  |
| 394 | `edittext_mousedown` | 3 | 7.3s |  |
| 395 | `edittext_mouseenabled` | 26 | 7.1s |  |
| 396 | `edittext_newline_character` | 22 | 7.2s |  |
| 397 | `edittext_newline_stripping` | 64 | 13.2s |  |
| 398 | `edittext_newlines` | 30 | 6.7s |  |
| 399 | `edittext_paragraph_methods` | 257 | 6.5s |  |
| 400 | `edittext_paste_events` | 8 | 6.5s |  |
| 401 | `edittext_paste_maxchars` | 4 | 6.4s |  |
| 402 | `edittext_paste_restrict` | 16 | 6.5s |  |
| 403 | `edittext_restrict` | 191 | 6.5s |  |
| 404 | `edittext_restrict_events` | 22 | 7.0s |  |
| 405 | `edittext_scroll_event` | 37 | 6.9s |  |
| 406 | `edittext_scrollh` | 10 | 6.5s |  |
| 407 | `edittext_selected_text` | 9 | 6.6s |  |
| 408 | `edittext_set_html_same` | 17 | 6.7s |  |
| 409 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 410 | `edittext_stylesheet` | 536 | 6.9s |  |
| 411 | `edittext_stylesheet_custom_tag` | 76 | 6.7s |  |
| 412 | `edittext_stylesheet_display` | 272 | 6.9s |  |
| 413 | `edittext_tag_indent` | 49 | 21.5s |  |
| 414 | `edittext_underline` | 40 | 7.0s |  |
| 415 | `edittext_width_height` | 103 | 7.2s |  |
| 416 | `edittext_wordwrap_word` | 150 | 6.8s |  |
| 417 | `edittext_wrap_breaks` | 2375 | 7.2s |  |
| 418 | `element_format_clone` | 44 | 9.8s |  |
| 419 | `element_format_constructor_order` | 64 | 9.8s |  |
| 420 | `element_format_properties` | 235 | 11.0s |  |
| 421 | `empty_bounds` | 1 | 9.4s |  |
| 422 | `encode_uri_surrogate_pair_invalid` | 8 | 9.4s |  |
| 423 | `encode_uri_surrogate_pair_swf11` | 15 | 9.1s |  |
| 424 | `equals` | 512 | 14.2s |  |
| 425 | `error_geterrormessage` | 779 | 9.4s |  |
| 426 | `error_prototype` | 15 | 9.5s |  |
| 427 | `error_stack_trace` | 45 | 9.5s |  |
| 428 | `error_stack_trace_debug_swf17` | 0 | 30.8s |  |
| 429 | `error_stack_trace_debug_swf18` | 0 | 9.4s |  |
| 430 | `error_stack_trace_edge_cases` | 6 | 9.7s |  |
| 431 | `error_stack_trace_release_swf17` | 0 | 3.6s |  |
| 432 | `error_stack_trace_release_swf18` | 0 | 9.2s |  |
| 433 | `error_throwerror` | 103 | 9.5s |  |
| 434 | `error_tostring` | 29 | 9.5s |  |
| 435 | `error_tostring_more` | 86 | 9.4s |  |
| 436 | `es3_inheritance` | 31 | 9.5s |  |
| 437 | `es4_inheritance` | 30 | 9.4s |  |
| 438 | `es4_interfaces` | 30 | 9.5s |  |
| 439 | `es4_method_binding` | 8 | 9.5s |  |
| 440 | `es4_oop_prototypes` | 14 | 9.7s |  |
| 441 | `es4_protected_inheritance` | 6 | 9.4s |  |
| 442 | `escape` | 71 | 9.5s |  |
| 443 | `escape_multi_byte` | 45 | 9.8s |  |
| 444 | `event_bubbles` | 2 | 9.3s |  |
| 445 | `event_cancelable` | 2 | 9.2s |  |
| 446 | `event_clone` | 20 | 9.5s |  |
| 447 | `event_clone_error_redispatch` | 3 | 9.5s |  |
| 448 | `event_clone_on_redispatch` | 10 | 9.6s |  |
| 449 | `event_formattostring` | 31 | 9.6s |  |
| 450 | `event_isdefaultprevented` | 12 | 9.3s |  |
| 451 | `event_target_getter` | 5 | 3.6s |  |
| 452 | `event_target_set` | 9 | 9.3s |  |
| 453 | `event_type` | 1 | 9.2s |  |
| 454 | `event_valueof_tostring` | 18 | 9.4s |  |
| 455 | `eventdispatcher_dispatchevent` | 12 | 3.7s |  |
| 456 | `eventdispatcher_dispatchevent_cancel` | 20 | 9.4s |  |
| 457 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 9.4s |  |
| 458 | `eventdispatcher_dispatchevent_indirect` | 9 | 2.9s |  |
| 459 | `eventdispatcher_dispatchevent_this` | 5 | 7.8s |  |
| 460 | `eventdispatcher_haseventlistener` | 25 | 3.0s |  |
| 461 | `eventdispatcher_interface_invoke` | 1 | 7.5s |  |
| 462 | `eventdispatcher_tostring` | 10 | 7.6s |  |
| 463 | `eventdispatcher_willtrigger` | 25 | 7.4s |  |
| 464 | `external_interface` | 105 | 7.6s |  |
| 465 | `falsiness` | 30 | 10.6s |  |
| 466 | `fast_index_access` | 12 | 7.6s |  |
| 467 | `filefilter_properties` | 4 | 7.4s |  |
| 468 | `filereference_browse_cancel` | 3 | 7.5s |  |
| 469 | `filereference_load` | 31 | 7.6s |  |
| 470 | `filereference_save` | 16 | 7.5s |  |
| 471 | `filereference_save_and_browse` | 42 | 8.3s |  |
| 472 | `filereference_save_and_load` | 22 | 7.7s |  |
| 473 | `filereference_uninitialized` | 8 | 7.5s |  |
| 474 | `filereferencelist_browse_cancel` | 6 | 7.5s |  |
| 475 | `filereferencelist_browse_select` | 7 | 7.3s |  |
| 476 | `filter_rewind` | 8 | 24.4s |  |
| 477 | `filters_array_holes` | 25 | 7.6s |  |
| 478 | `finddef` | 3 | 7.5s |  |
| 479 | `findprop_global_prototype` | 6 | 7.5s |  |
| 480 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 481 | `flash_media_video_rotation_probe` | 27 | 7.5s |  |
| 482 | `flash_media_video_setter` | 40 | 7.9s |  |
| 483 | `flash_trace` | 17 | 7.5s |  |
| 484 | `flash_ui_mouse_cursor` | 35 | 7.8s |  |
| 485 | `flash_xml` | 29 | 7.5s |  |
| 486 | `flash_xml_cloneNode` | 22 | 7.5s |  |
| 487 | `flash_xml_namespace` | 109 | 7.4s |  |
| 488 | `flash_xml_removeNode` | 60 | 7.5s |  |
| 489 | `focus_events_code` | 161 | 24.3s |  |
| 490 | `focus_events_key_basic` | 132 | 26.3s |  |
| 491 | `focus_events_key_navigation` | 53 | 25.8s |  |
| 492 | `focus_events_key_same_object` | 26 | 8.8s |  |
| 493 | `focus_events_mixed_key_mouse` | 100 | 24.3s |  |
| 494 | `focus_events_mouse_basic` | 260 | 24.5s |  |
| 495 | `focus_events_mouse_focusable` | 112 | 24.6s |  |
| 496 | `focus_events_mouse_same_object` | 40 | 7.8s |  |
| 497 | `focus_remove` | 20 | 24.3s |  |
| 498 | `focus_root_movie` | 4 | 24.9s |  |
| 499 | `focus_stage` | 1 | 7.9s |  |
| 500 | `focusrect` | 18 | 8.3s |  |
| 501 | `focusrect_focuslost` | 9 | 30.4s |  |
| 502 | `focusrect_property` | 110 | 9.3s |  |
| 503 | `font_description_clone` | 14 | 9.2s |  |
| 504 | `font_embedded` | 24 | 9.8s |  |
| 505 | `font_enumeratefonts` | 41 | 10.1s |  |
| 506 | `font_enumeratefonts_filter` | 4 | 10.1s |  |
| 507 | `font_enumeratefonts_order` | 9 | 10.8s |  |
| 508 | `font_hasglyphs` | 40 | 9.9s |  |
| 509 | `font_registerfont` | 129 | 10.4s |  |
| 510 | `framelabel_constr` | 5 | 9.4s |  |
| 511 | `function_call` | 12 | 3.5s |  |
| 512 | `function_call_arguments` | 46 | 9.4s |  |
| 513 | `function_call_arguments_enumerate` | 5 | 9.2s |  |
| 514 | `function_call_coercion` | 108 | 9.8s |  |
| 515 | `function_call_default` | 6 | 9.3s |  |
| 516 | `function_call_rest` | 22 | 9.3s |  |
| 517 | `function_call_types` | 3 | 9.3s |  |
| 518 | `function_call_via_apply` | 11 | 9.3s |  |
| 519 | `function_call_via_call` | 3 | 9.2s |  |
| 520 | `function_display_anonymous` | 7 | 3.5s |  |
| 521 | `function_length` | 6 | 9.2s |  |
| 522 | `function_object` | 2 | 9.2s |  |
| 523 | `function_proto` | 5 | 9.2s |  |
| 524 | `function_proto_created` | 61 | 9.3s |  |
| 525 | `function_to_locale_string` | 4 | 9.2s |  |
| 526 | `function_to_string` | 4 | 9.0s |  |
| 527 | `function_type` | 6 | 3.5s |  |
| 528 | `function_unbound_this` | 51 | 9.4s |  |
| 529 | `function_value_of` | 4 | 9.2s |  |
| 530 | `game_input` | 4 | 9.2s |  |
| 531 | `generate_random_bytes` | 3 | 9.2s |  |
| 532 | `geom_transform` | 74 | 31.0s |  |
| 533 | `get_definition_by_name` | 11 | 9.2s |  |
| 534 | `get_qualified_class_name` | 20 | 3.5s |  |
| 535 | `get_qualified_super_class_name` | 18 | 9.3s |  |
| 536 | `get_slot_edge_cases` | 1 | 9.1s |  |
| 537 | `get_timer` | 2 | 3.4s |  |
| 538 | `getglobalslot` | 1 | 9.1s |  |
| 539 | `getouterscope` | 8 | 9.1s |  |
| 540 | `getouterscope_two_classobjects` | 13 | 9.3s |  |
| 541 | `getter_different_namespace_setter` | 2 | 9.1s |  |
| 542 | `glow_filter` | 127 | 9.6s |  |
| 543 | `goto_button_nested_framescript` | 28 | 30.2s |  |
| 544 | `goto_framescript_queued/swf10` | 59 | 30.3s |  |
| 545 | `goto_framescript_queued/swf9` | 52 | 1.0s |  |
| 546 | `goto_framescript_queued_same_frame` | 4 | 6.8s |  |
| 547 | `goto_in_constructframe` | 12 | 7.1s |  |
| 548 | `goto_in_scene_last_frame` | 2 | 23.4s |  |
| 549 | `goto_methods` | 56 | 7.1s |  |
| 550 | `goto_methods_swfver10` | 8 | 2.4s |  |
| 551 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 552 | `goto_nested_framescript` | 9 | 7.0s |  |
| 553 | `goto_on_orphan` | 15 | 7.0s |  |
| 554 | `goto_queued_invalid/swf10` | 34 | 23.6s |  |
| 555 | `goto_queued_invalid/swf11` | 43 | 1.0s |  |
| 556 | `goto_queued_invalid/swf9` | 32 | 1.0s |  |
| 557 | `gradient_bevel_filter` | 206 | 6.8s |  |
| 558 | `gradient_glow_filter` | 206 | 6.7s |  |
| 559 | `graphic_linkage` | 9 | 6.9s |  |
| 560 | `graphics_bad_direct_commands` | 5 | 7.4s |  |
| 561 | `graphics_bitmap_fill` | 0 | 8.5s |  |
| 562 | `graphics_bitmaps` | 0 | 7.2s |  |
| 563 | `graphics_direct_commands` | 0 | 7.1s |  |
| 564 | `graphics_draw_triangles` | 98 | 24.3s |  |
| 565 | `graphics_gradients` | 0 | 7.1s |  |
| 566 | `graphics_gradients_nulls` | 0 | 6.9s |  |
| 567 | `graphics_path` | 56 | 6.8s |  |
| 568 | `graphics_round_rects` | 0 | 6.8s |  |
| 569 | `graphics_simple_shapes` | 0 | 6.9s |  |
| 570 | `greaterequals` | 512 | 9.5s |  |
| 571 | `greaterthan` | 512 | 9.5s |  |
| 572 | `has_own_property` | 102 | 7.2s |  |
| 573 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 574 | `hello_world` | 1 | 6.8s |  |
| 575 | `hittest_morph` | 30 | 2.5s |  |
| 576 | `id3_info` | 8 | 6.9s |  |
| 577 | `if_eq` | 10 | 6.8s |  |
| 578 | `if_gt` | 1 | 6.8s |  |
| 579 | `if_gte` | 10 | 2.3s |  |
| 580 | `if_lt` | 1 | 0.9s |  |
| 581 | `if_lte` | 10 | 6.7s |  |
| 582 | `if_ne` | 7 | 2.4s |  |
| 583 | `if_stricteq` | 6 | 6.7s |  |
| 584 | `if_strictne` | 11 | 9.3s |  |
| 585 | `ime_linux_dead_keys` | 10 | 9.4s |  |
| 586 | `in` | 102 | 10.1s |  |
| 587 | `inclocal` | 46 | 9.4s |  |
| 588 | `inclocal_i` | 46 | 9.3s |  |
| 589 | `increment` | 46 | 9.4s |  |
| 590 | `increment_i` | 46 | 3.4s |  |
| 591 | `indexing_delete` | 75 | 9.3s |  |
| 592 | `indexof_xml` | 10 | 9.5s |  |
| 593 | `init_callee_cached` | 24 | 9.2s |  |
| 594 | `instanceof` | 58 | 9.7s |  |
| 595 | `instantiate_root_character` | 4 | 9.5s |  |
| 596 | `instantiation_on_enter_frame` | 7 | 31.9s |  |
| 597 | `instantiation_on_enterframe_gotoandstop` | 8 | 9.2s |  |
| 598 | `int_constr` | 92 | 9.5s |  |
| 599 | `int_edge_cases` | 19 | 9.2s |  |
| 600 | `int_instanceof` | 3 | 9.1s |  |
| 601 | `int_tofixed` | 1215 | 9.2s |  |
| 602 | `int_toprecision` | 1125 | 9.6s |  |
| 603 | `int_tostring` | 3375 | 9.5s |  |
| 604 | `interactiveobject_enabled` | 25 | 9.1s |  |
| 605 | `interface_namespaces` | 78 | 9.5s |  |
| 606 | `invalid_utf8` | 12 | 9.6s |  |
| 607 | `is_finite` | 46 | 9.5s |  |
| 608 | `is_nan` | 46 | 9.3s |  |
| 609 | `is_prototype_of` | 12 | 9.3s |  |
| 610 | `issue_10221` | 2 | 9.2s |  |
| 611 | `issue_13780` | 12 | 9.1s |  |
| 612 | `issue_14901` | 1 | 9.0s |  |
| 613 | `issue_17675_edittext_paste_maxchars` | 1 | 9.2s |  |
| 614 | `issue_5292` | 5 | 3.2s |  |
| 615 | `issue_8630` | 2 | 9.2s |  |
| 616 | `issue_8630_placeremoveplace` | 15 | 9.5s |  |
| 617 | `issue_8630_placeremoveplace_scriptremove` | 16 | 9.2s |  |
| 618 | `issue_8630_scriptremove` | 11 | 9.2s |  |
| 619 | `istype` | 24 | 3.3s |  |
| 620 | `istypelate` | 58 | 9.5s |  |
| 621 | `istypelate_coerce` | 198 | 10.5s |  |
| 622 | `jpeg_loader_context` | 6 | 9.2s |  |
| 623 | `json_errors` | 9 | 32.5s |  |
| 624 | `json_parse` | 21 | 9.4s |  |
| 625 | `json_parse_errors` | 84 | 9.4s |  |
| 626 | `json_stringify` | 12 | 2.4s |  |
| 627 | `json_stringify_function` | 12 | 6.5s |  |
| 628 | `json_stringify_order` | 1 | 6.5s |  |
| 629 | `json_version_gated` | 1 | 6.5s |  |
| 630 | `key_input_80percent` | 1812 | 6.6s |  |
| 631 | `key_input_location` | 126 | 6.5s |  |
| 632 | `key_input_numpad` | 384 | 2.2s |  |
| 633 | `large_preload_from_bytes` | 51 | 9.4s |  |
| 634 | `large_preload_from_url` | 27 | 8.1s |  |
| 635 | `large_preload_image_from_bytes` | 25 | 8.2s |  |
| 636 | `lazyinit` | 17 | 6.5s |  |
| 637 | `lessequals` | 512 | 9.0s |  |
| 638 | `lessthan` | 512 | 9.0s |  |
| 639 | `loader_bitmap_transparency` | 14 | 6.7s |  |
| 640 | `loader_bytes_unknown_content` | 14 | 6.7s |  |
| 641 | `loader_child_getdefinition` | 5 | 6.7s |  |
| 642 | `loader_duplicate_class` | 48 | 8.0s |  |
| 643 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 644 | `loader_duplicate_coerce_new_domain` | 4 | 6.6s |  |
| 645 | `loader_error_in_root_ctor` | 4 | 6.7s |  |
| 646 | `loader_events` | 92 | 7.2s |  |
| 647 | `loader_image` | 8 | 6.8s |  |
| 648 | `loader_jpegxr` | 2 | 22.8s |  |
| 649 | `loader_jpegxr_alpha` | 1 | 22.6s |  |
| 650 | `loader_loadbytes_events` | 30 | 7.1s |  |
| 651 | `loader_loadbytes_invalid_png` | 4 | 6.7s |  |
| 652 | `loader_loadbytes_url` | 12 | 6.9s |  |
| 653 | `loader_loaderurl` | 6 | 7.0s |  |
| 654 | `loader_method` | 85 | 6.7s |  |
| 655 | `loader_noninteractive_try_click_root` | 5 | 22.9s |  |
| 656 | `loader_reuse` | 38 | 6.8s |  |
| 657 | `loader_try_click_root` | 16 | 6.8s |  |
| 658 | `loader_unknown_content` | 24 | 6.7s |  |
| 659 | `loader_unloadandstop_subclass` | 1 | 6.5s |  |
| 660 | `loader_visibility_interactive` | 1 | 6.6s |  |
| 661 | `loaderinfo_child_progress` | 9 | 6.8s |  |
| 662 | `loaderinfo_events` | 7 | 6.5s |  |
| 663 | `loaderinfo_loadurl` | 12 | 6.5s |  |
| 664 | `loaderinfo_more` | 6 | 6.8s |  |
| 665 | `loaderinfo_properties` | 18 | 6.7s |  |
| 666 | `loaderinfo_properties_not_loaded` | 23 | 6.7s |  |
| 667 | `loaderinfo_quine` | 1005 | 6.8s |  |
| 668 | `loaderinfo_root` | 10 | 6.7s |  |
| 669 | `loaderinfo_root_allows` | 2 | 6.6s |  |
| 670 | `localconnection` | 890 | 8.6s |  |
| 671 | `localconnection_send` | 4 | 6.6s |  |
| 672 | `lshift` | 1058 | 13.8s |  |
| 673 | `mask_reapply` | 1 | 22.9s |  |
| 674 | `math` | 497 | 6.9s |  |
| 675 | `matrix` | 338 | 14.9s |  |
| 676 | `matrix3d` | 57 | 7.3s |  |
| 677 | `matrix3d_append` | 16 | 6.8s |  |
| 678 | `matrix3d_append_prepend_scale` | 86 | 6.7s |  |
| 679 | `matrix3d_append_prepend_translation` | 42 | 6.7s |  |
| 680 | `matrix3d_append_rotation` | 23 | 6.7s |  |
| 681 | `matrix3d_compose` | 34 | 6.8s |  |
| 682 | `matrix3d_constructor_clone` | 15 | 6.7s |  |
| 683 | `matrix3d_copy_column` | 83 | 6.9s |  |
| 684 | `matrix3d_copy_from` | 19 | 6.7s |  |
| 685 | `matrix3d_copy_raw_data_from` | 55 | 2.4s |  |
| 686 | `matrix3d_copy_raw_data_to` | 38 | 6.8s |  |
| 687 | `matrix3d_copy_row` | 83 | 6.5s |  |
| 688 | `matrix3d_copy_to_matrix3d` | 19 | 6.7s |  |
| 689 | `matrix3d_determinant` | 182 | 6.8s |  |
| 690 | `matrix3d_interpolate` | 21 | 6.8s |  |
| 691 | `matrix3d_invert` | 18 | 6.7s |  |
| 692 | `matrix3d_position` | 19 | 6.7s |  |
| 693 | `matrix3d_precision` | 28 | 6.8s |  |
| 694 | `matrix3d_prepend` | 16 | 6.6s |  |
| 695 | `matrix3d_raw_data` | 33 | 6.8s |  |
| 696 | `matrix3d_transform_vector` | 52 | 7.0s |  |
| 697 | `matrix3d_transpose` | 5 | 6.6s |  |
| 698 | `method_association` | 5 | 6.7s |  |
| 699 | `method_without_body` | 3 | 22.8s |  |
| 700 | `missing_external_interface` | 10 | 6.7s |  |
| 701 | `modulo` | 1058 | 13.9s |  |
| 702 | `morph_shape` | 2 | 22.9s |  |
| 703 | `mouse_children` | 192 | 23.4s |  |
| 704 | `mouse_click_events` | 90 | 23.2s |  |
| 705 | `mouse_double_click_events` | 188 | 6.7s |  |
| 706 | `mouse_empty_parent` | 4 | 6.6s |  |
| 707 | `mouse_over_while_dragging` | 3 | 6.8s |  |
| 708 | `mouse_pick_avm1_root` | 2 | 7.0s |  |
| 709 | `mouse_pick_button_mode` | 2 | 6.7s |  |
| 710 | `mouse_pick_dobj_mask` | 4 | 7.0s |  |
| 711 | `mouse_pick_loader_avm1` | 42 | 7.0s |  |
| 712 | `mouse_pick_masking` | 7 | 23.1s |  |
| 713 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 23.1s |  |
| 714 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.8s |  |
| 715 | `mouse_pick_scroll_rect` | 27 | 23.5s |  |
| 716 | `mouse_pick_scroll_rect_button` | 5 | 7.0s |  |
| 717 | `mouse_pick_scroll_rect_loader` | 5 | 7.2s |  |
| 718 | `mouse_pick_text` | 8 | 7.0s |  |
| 719 | `mouse_sibling` | 8 | 6.8s |  |
| 720 | `mouse_wheel_events` | 36 | 24.5s |  |
| 721 | `mouseevent_constr` | 66 | 6.8s |  |
| 722 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 723 | `mouseevent_valueof_tostring` | 28 | 6.9s |  |
| 724 | `movieclip_addframescript` | 3 | 23.5s |  |
| 725 | `movieclip_addframescript_error` | 9 | 6.8s |  |
| 726 | `movieclip_child_property` | 16 | 6.9s |  |
| 727 | `movieclip_constr` | 21 | 6.8s |  |
| 728 | `movieclip_currentlabels` | 17 | 23.5s |  |
| 729 | `movieclip_currentlabels_dupes1` | 46 | 23.6s |  |
| 730 | `movieclip_currentlabels_dupes2` | 30 | 6.8s |  |
| 731 | `movieclip_currentlabels_dupes3` | 67 | 6.9s |  |
| 732 | `movieclip_currentscene` | 12 | 6.8s |  |
| 733 | `movieclip_dispatchevent` | 430 | 6.9s |  |
| 734 | `movieclip_dispatchevent_cancel` | 102 | 7.0s |  |
| 735 | `movieclip_dispatchevent_handlerorder` | 251 | 6.9s |  |
| 736 | `movieclip_dispatchevent_selfadd` | 80 | 6.8s |  |
| 737 | `movieclip_dispatchevent_target` | 899 | 6.9s |  |
| 738 | `movieclip_displayevents` | 96 | 23.2s |  |
| 739 | `movieclip_displayevents_clickgoto` | 676 | 7.2s |  |
| 740 | `movieclip_displayevents_clickgoto2` | 2001 | 7.3s |  |
| 741 | `movieclip_displayevents_clickplay` | 575 | 7.0s |  |
| 742 | `movieclip_displayevents_clicksymbol` | 562 | 7.0s |  |
| 743 | `movieclip_displayevents_constructframegoto` | 140 | 7.0s |  |
| 744 | `movieclip_displayevents_constructframeplay` | 50 | 6.8s |  |
| 745 | `movieclip_displayevents_constructframesymbol` | 144 | 6.9s |  |
| 746 | `movieclip_displayevents_dblhandler` | 21 | 6.7s |  |
| 747 | `movieclip_displayevents_enterframegoto` | 149 | 7.0s |  |
| 748 | `movieclip_displayevents_enterframeplay` | 48 | 6.8s |  |
| 749 | `movieclip_displayevents_enterframesymbol` | 149 | 23.3s |  |
| 750 | `movieclip_displayevents_exitframegoto` | 106 | 6.9s |  |
| 751 | `movieclip_displayevents_exitframeplay` | 44 | 6.9s |  |
| 752 | `movieclip_displayevents_exitframesymbol` | 135 | 22.5s |  |
| 753 | `movieclip_displayevents_looping` | 63 | 22.9s |  |
| 754 | `movieclip_displayevents_stopped` | 113 | 22.8s |  |
| 755 | `movieclip_displayevents_swap` | 96 | 6.7s |  |
| 756 | `movieclip_displayevents_timeline` | 128 | 23.1s |  |
| 757 | `movieclip_drawrect` | 54 | 6.7s |  |
| 758 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 759 | `movieclip_goto_during_frame_script` | 15 | 6.8s |  |
| 760 | `movieclip_goto_overwrite` | 14 | 22.7s |  |
| 761 | `movieclip_goto_scene_last_frame_int` | 1 | 22.6s |  |
| 762 | `movieclip_goto_scene_last_frame_label` | 1 | 6.4s |  |
| 763 | `movieclip_gotoandplay` | 15 | 22.9s |  |
| 764 | `movieclip_gotoandstop` | 13 | 6.6s |  |
| 765 | `movieclip_gotoandstop_children` | 4 | 6.7s |  |
| 766 | `movieclip_gotoandstop_framescripts1` | 4 | 6.6s |  |
| 767 | `movieclip_gotoandstop_framescripts2` | 4 | 2.2s |  |
| 768 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.4s |  |
| 769 | `movieclip_gotoandstop_queueing` | 12 | 6.6s |  |
| 770 | `movieclip_hittest` | 67 | 6.7s |  |
| 771 | `movieclip_next_frame` | 2 | 2.2s |  |
| 772 | `movieclip_next_scene` | 6 | 6.6s |  |
| 773 | `movieclip_play` | 3 | 6.4s |  |
| 774 | `movieclip_prev_frame` | 3 | 6.4s |  |
| 775 | `movieclip_prev_scene` | 7 | 6.6s |  |
| 776 | `movieclip_properties` | 79 | 22.9s |  |
| 777 | `movieclip_queued_noop_goto_swf10` | 9 | 6.6s |  |
| 778 | `movieclip_queued_noop_goto_swf9` | 7 | 0.9s |  |
| 779 | `movieclip_scenes` | 11 | 6.5s |  |
| 780 | `movieclip_soundtransform` | 831 | 24.3s |  |
| 781 | `movieclip_stop` | 1 | 6.5s |  |
| 782 | `movieclip_super_is_symbol` | 20 | 6.8s |  |
| 783 | `movieclip_symbol_constr` | 8 | 6.6s |  |
| 784 | `movieclip_text_mousedown` | 1 | 6.6s |  |
| 785 | `movieclip_willtrigger` | 5 | 6.7s |  |
| 786 | `multiply` | 1058 | 13.7s |  |
| 787 | `namespace_constr` | 253 | 6.8s |  |
| 788 | `namespace_constr_args` | 1 | 6.5s |  |
| 789 | `namespace_enumeration_order` | 7 | 6.6s |  |
| 790 | `nan_scale` | 9 | 6.6s |  |
| 791 | `native_menu_basic` | 19 | 8.6s |  |
| 792 | `navigateToURL_target_normalize` | 107 | 24.6s |  |
| 793 | `negate` | 30 | 6.5s |  |
| 794 | `negative_volume_panned` | 0 | 6.8s |  |
| 795 | `nested_iteration` | 11 | 6.5s |  |
| 796 | `net_getClassByAlias` | 3 | 6.8s |  |
| 797 | `net_navigateToURL` | 57 | 24.8s |  |
| 798 | `net_stream_play_options` | 6 | 6.7s |  |
| 799 | `netconnection_call_with_responder` | 6 | 23.0s |  |
| 800 | `netconnection_close` | 55 | 6.7s |  |
| 801 | `netconnection_properties` | 78 | 6.8s |  |
| 802 | `netconnection_send_remote` | 50 | 6.9s |  |
| 803 | `netconnection_serialize_arrays` | 6 | 6.7s |  |
| 804 | `netfilterevent` | 10 | 6.7s |  |
| 805 | `netstream_client` | 10 | 6.8s |  |
| 806 | `netstream_connect` | 7 | 6.7s |  |
| 807 | `netstream_flv_date` | 4 | 6.9s |  |
| 808 | `newactivation_in_script_init` | 3 | 6.6s |  |
| 809 | `newclass_mismatched` | 4 | 6.7s |  |
| 810 | `newclass_twice` | 3 | 6.6s |  |
| 811 | `nonconflicting_declarations` | 0 | 6.7s |  |
| 812 | `null_void_types` | 8 | 6.7s |  |
| 813 | `number_autoconv` | 21 | 6.7s |  |
| 814 | `number_autoconv_amf` | 132 | 6.7s |  |
| 815 | `number_autoconv_array_sort_32bit` | 1 | 6.6s |  |
| 816 | `number_constr` | 58 | 6.8s |  |
| 817 | `number_convert_edge_cases` | 180 | 23.0s |  |
| 818 | `number_toexponential` | 378 | 6.8s |  |
| 819 | `number_toexponential2` | 35 | 6.6s |  |
| 820 | `number_tofixed` | 378 | 6.6s |  |
| 821 | `number_toprecision` | 350 | 6.7s |  |
| 822 | `obfuscated_class_names` | 3 | 6.7s |  |
| 823 | `object_enumeration` | 10 | 6.7s |  |
| 824 | `object_prototype` | 4 | 6.7s |  |
| 825 | `object_to_locale_string` | 2 | 6.7s |  |
| 826 | `object_to_string` | 2 | 6.7s |  |
| 827 | `object_value_of` | 2 | 2.2s |  |
| 828 | `op_coerce` | 54 | 6.8s |  |
| 829 | `op_coerce_x` | 54 | 6.7s |  |
| 830 | `op_escxattr` | 2 | 6.6s |  |
| 831 | `op_escxelem` | 2 | 6.7s |  |
| 832 | `op_lookupswitch` | 4 | 6.7s |  |
| 833 | `optimize_coerce` | 1 | 6.6s |  |
| 834 | `orphan_movie_complex` | 80 | 7.0s |  |
| 835 | `orphan_movie_reorder` | 111 | 22.9s |  |
| 836 | `orphan_removeobject` | 636 | 23.1s |  |
| 837 | `package_namespace` | 7 | 6.5s |  |
| 838 | `param_default_value_has_zero_cpool_index` | 1 | 6.5s |  |
| 839 | `parent_early_access_child` | 16 | 6.9s |  |
| 840 | `parse_float` | 81 | 6.7s |  |
| 841 | `parse_float_swf10` | 81 | 6.5s |  |
| 842 | `parse_int` | 135 | 6.9s |  |
| 843 | `perspective_projection` | 1443 | 23.2s |  |
| 844 | `perspective_projection_basic` | 40 | 6.7s |  |
| 845 | `pixelbender_ceil` | 77 | 6.8s |  |
| 846 | `pixelbender_conditional` | 138 | 6.9s |  |
| 847 | `pixelbender_conversions` | 270 | 6.8s |  |
| 848 | `pixelbender_dithering` | 8 | 27.0s |  |
| 849 | `pixelbender_div` | 36 | 6.6s |  |
| 850 | `pixelbender_effect_BlurredFocus` | 0 | 29.3s |  |
| 851 | `pixelbender_effect_glassDisplace` | 0 | 11.7s |  |
| 852 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 26.0s |  |
| 853 | `pixelbender_effect_smudge` | 0 | 9.4s |  |
| 854 | `pixelbender_effect_tintype` | 0 | 8.8s |  |
| 855 | `pixelbender_effect_twirl` | 0 | 10.0s |  |
| 856 | `pixelbender_eof` | 7 | 6.6s |  |
| 857 | `pixelbender_images` | 0 | 8.6s |  |
| 858 | `pixelbender_input` | 103 | 23.5s |  |
| 859 | `pixelbender_logicalnot` | 20 | 6.7s |  |
| 860 | `pixelbender_malformed_data` | 190 | 7.4s |  |
| 861 | `pixelbender_multiple_out_params` | 1 | 6.6s |  |
| 862 | `pixelbender_no_out_param` | 6 | 6.6s |  |
| 863 | `pixelbender_outputs` | 13 | 6.8s |  |
| 864 | `pixelbender_padding_bytes` | 22 | 6.7s |  |
| 865 | `pixelbender_param_qualifier` | 512 | 6.8s |  |
| 866 | `pixelbender_parameters` | 1563 | 7.1s |  |
| 867 | `pixelbender_parameters_bool` | 240 | 7.0s |  |
| 868 | `pixelbender_parameters_int_vs_bool` | 54 | 6.8s |  |
| 869 | `pixelbender_parse_errors` | 6 | 6.8s |  |
| 870 | `pixelbender_rsqrt` | 24 | 6.8s |  |
| 871 | `pixelbender_select_kinds` | 8 | 6.8s |  |
| 872 | `pixelbender_shaderdata` | 49 | 6.7s |  |
| 873 | `pixelbender_shaderdata_setter` | 99 | 7.0s |  |
| 874 | `pixelbender_sign` | 60 | 6.9s |  |
| 875 | `pixelbender_vector_output` | 11 | 6.8s |  |
| 876 | `place_and_lookup/swf10` | 33 | 6.7s |  |
| 877 | `place_and_lookup/swf9` | 33 | 6.7s |  |
| 878 | `place_multiple` | 17 | 6.6s |  |
| 879 | `place_object_replace` | 9 | 23.1s |  |
| 880 | `place_object_replace_2` | 24 | 22.9s |  |
| 881 | `place_object_same_depth_frame` | 1 | 6.6s |  |
| 882 | `point` | 132 | 7.0s |  |
| 883 | `primitive_edge_cases` | 1 | 2.2s |  |
| 884 | `primitive_keys` | 54 | 6.6s |  |
| 885 | `primitive_toString` | 277 | 6.8s |  |
| 886 | `primitive_valueOf` | 285 | 6.5s |  |
| 887 | `print_job_options` | 3 | 6.5s |  |
| 888 | `property_is_enumerable` | 114 | 7.5s |  |
| 889 | `property_is_enumerable_reset` | 23 | 6.5s |  |
| 890 | `property_priority` | 22 | 6.8s |  |
| 891 | `property_priority_chained` | 4 | 6.5s |  |
| 892 | `property_priority_definition_names_order` | 2 | 6.8s |  |
| 893 | `property_priority_three_level` | 6 | 6.7s |  |
| 894 | `propertyisenumerable_namespaces` | 6 | 6.5s |  |
| 895 | `prototype_set_null` | 7 | 6.5s |  |
| 896 | `proxy_callproperty` | 24 | 6.6s |  |
| 897 | `proxy_deleteproperty` | 64 | 6.7s |  |
| 898 | `proxy_enumeration` | 34 | 6.6s |  |
| 899 | `proxy_getproperty` | 77 | 6.6s |  |
| 900 | `proxy_hasownproperty` | 8 | 6.6s |  |
| 901 | `proxy_hasproperty` | 32 | 6.7s |  |
| 902 | `proxy_not_overridden` | 54 | 6.6s |  |
| 903 | `proxy_serialize` | 9 | 6.5s |  |
| 904 | `proxy_setproperty` | 42 | 6.6s |  |
| 905 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.5s |  |
| 906 | `qname_constr` | 32 | 6.6s |  |
| 907 | `qname_constr_namespace` | 24 | 6.6s |  |
| 908 | `qname_enumeration` | 9 | 6.5s |  |
| 909 | `qname_indexing` | 23 | 6.6s |  |
| 910 | `qname_tostring` | 25 | 6.6s |  |
| 911 | `qname_valueof` | 29 | 6.6s |  |
| 912 | `rectangle` | 1094 | 7.0s |  |
| 913 | `regexp_constr` | 148 | 6.8s |  |
| 914 | `regexp_exec` | 19 | 6.6s |  |
| 915 | `regexp_extended` | 47 | 6.4s |  |
| 916 | `regexp_multiargs` | 1 | 6.5s |  |
| 917 | `regexp_test` | 27 | 6.5s |  |
| 918 | `regexp_toString` | 10 | 6.5s |  |
| 919 | `register_script_refresh` | 35 | 22.9s |  |
| 920 | `remove_child_clear_field` | 88 | 7.0s |  |
| 921 | `remove_dobj` | 3 | 6.6s |  |
| 922 | `resolve_order` | 4 | 6.5s |  |
| 923 | `responder_null_callbacks` | 1 | 2.1s |  |
| 924 | `rng` | 1 | 7.5s |  |
| 925 | `rootless` | 42 | 6.7s |  |
| 926 | `rshift` | 1058 | 13.7s |  |
| 927 | `rtqname_not_namespace` | 12 | 6.5s |  |
| 928 | `sandbox_type_inherited` | 2 | 6.8s |  |
| 929 | `sandbox_type_local_file` | 1 | 6.5s |  |
| 930 | `sandbox_type_local_network` | 1 | 6.3s |  |
| 931 | `scene_constr` | 8 | 6.7s |  |
| 932 | `scope_optimizations` | 4 | 6.5s |  |
| 933 | `scopes_dont_cache/order-1` | 1 | 22.4s |  |
| 934 | `scopes_dont_cache/order-2` | 1 | 0.7s |  |
| 935 | `security_domain_current` | 2 | 6.5s |  |
| 936 | `selection` | 239 | 7.1s |  |
| 937 | `set_local_0` | 31 | 6.6s |  |
| 938 | `set_property_is_enumerable` | 85 | 6.9s |  |
| 939 | `shaderparameter_value` | 4 | 6.5s |  |
| 940 | `shape_drawrect` | 54 | 6.6s |  |
| 941 | `shared_object_no_root` | 3 | 6.5s |  |
| 942 | `simplebutton_added_to_stage` | 45 | 22.7s |  |
| 943 | `simplebutton_childevents` | 86 | 22.9s |  |
| 944 | `simplebutton_childevents_nested` | 54 | 7.0s |  |
| 945 | `simplebutton_childevents_sprite` | 13 | 6.7s |  |
| 946 | `simplebutton_childprops` | 144 | 6.8s |  |
| 947 | `simplebutton_childshuffle` | 23 | 6.6s |  |
| 948 | `simplebutton_constr` | 36 | 6.9s |  |
| 949 | `simplebutton_constr_childevents` | 48 | 7.0s |  |
| 950 | `simplebutton_constr_params` | 42 | 6.8s |  |
| 951 | `simplebutton_mouseenabled` | 26 | 6.7s |  |
| 952 | `simplebutton_multi_children` | 19 | 6.8s |  |
| 953 | `simplebutton_soundtransform` | 887 | 24.6s |  |
| 954 | `simplebutton_structure` | 27 | 6.8s |  |
| 955 | `simplebutton_symbolclass` | 68 | 2.7s |  |
| 956 | `slot_disp_id_shared_numbering` | 1 | 22.9s |  |
| 957 | `slots_force_autoassigned` | 1 | 6.6s |  |
| 958 | `socket_after_disconnect` | 1 | 6.5s |  |
| 959 | `socket_close` | 2 | 6.5s |  |
| 960 | `socket_connect` | 4 | 6.5s |  |
| 961 | `socket_errors` | 56 | 6.9s |  |
| 962 | `socket_read_big` | 48 | 6.7s |  |
| 963 | `socket_read_little` | 48 | 2.1s |  |
| 964 | `socket_read_write_object` | 8 | 6.6s |  |
| 965 | `socket_write_big` | 15 | 6.8s |  |
| 966 | `socket_write_little` | 14 | 6.6s |  |
| 967 | `sound_constructor_with_args` | 6 | 6.8s |  |
| 968 | `sound_embeddedprops` | 26 | 6.8s |  |
| 969 | `sound_load_multiple` | 19 | 7.7s |  |
| 970 | `sound_play` | 19 | 6.9s |  |
| 971 | `sound_rootless` | 7 | 6.7s |  |
| 972 | `sound_valueof` | 33 | 6.8s |  |
| 973 | `soundchannel_soundtransform` | 835 | 24.8s |  |
| 974 | `soundchannel_soundtransform_exists` | 5 | 18.7s |  |
| 975 | `soundchannel_stop` | 8 | 6.9s |  |
| 976 | `soundmixer_buffertime` | 5 | 6.7s |  |
| 977 | `soundmixer_soundtransform` | 900 | 8.4s |  |
| 978 | `soundmixer_stopall` | 6 | 6.8s |  |
| 979 | `soundtransform` | 442 | 10.5s |  |
| 980 | `space_justifier_clone` | 12 | 2.3s |  |
| 981 | `sprite_with_frames` | 0 | 23.6s |  |
| 982 | `stage3d_agal_cross_product` | 0 | 9.2s |  |
| 983 | `stage3d_agal_upload_errors` | 66 | 9.0s |  |
| 984 | `stage3d_bitmap` | 0 | 27.7s |  |
| 985 | `stage3d_blend` | 81 | 26.2s |  |
| 986 | `stage3d_context3d_string_args` | 158 | 7.8s |  |
| 987 | `stage3d_errors` | 7 | 6.7s |  |
| 988 | `stage3d_errors_atf` | 3 | 7.8s |  |
| 989 | `stage3d_errors_swf_29` | 6 | 6.8s |  |
| 990 | `stage3d_float1_index` | 0 | 25.2s |  |
| 991 | `stage3d_fractal` | 0 | 26.0s |  |
| 992 | `stage3d_ignore_sampler_override` | 0 | 25.6s |  |
| 993 | `stage3d_multistage_triangle` | 3 | 9.2s |  |
| 994 | `stage3d_program_constants_bytearray_be` | 0 | 26.9s |  |
| 995 | `stage3d_program_constants_bytearray_le` | 0 | 9.5s |  |
| 996 | `stage3d_program_constants_invalid_input` | 21 | 7.5s |  |
| 997 | `stage3d_raytrace` | 0 | 30.4s |  |
| 998 | `stage3d_rotating_cube` | 0 | 9.8s |  |
| 999 | `stage3d_sampler` | 0 | 9.2s |  |
| 1000 | `stage3d_sampler_partial_upload` | 0 | 9.2s |  |
| 1001 | `stage3d_stencil` | 0 | 26.5s |  |
| 1002 | `stage3d_texture` | 0 | 14.4s |  |
| 1003 | `stage3d_texture_bytearray` | 0 | 10.4s |  |
| 1004 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.8s |  |
| 1005 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.6s |  |
| 1006 | `stage3d_triangle` | 0 | 9.3s |  |
| 1007 | `stage3d_triangle_bytes4` | 0 | 9.3s |  |
| 1008 | `stage3d_triangle_float1` | 0 | 9.2s |  |
| 1009 | `stage3d_triangle_index_upload` | 0 | 9.2s |  |
| 1010 | `stage3d_x_y` | 22 | 6.9s |  |
| 1011 | `stage_access` | 10 | 6.8s |  |
| 1012 | `stage_display_state` | 6 | 6.7s |  |
| 1013 | `stage_displayobject_properties` | 24 | 2.3s |  |
| 1014 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.8s |  |
| 1015 | `stage_framerate_nan` | 7 | 6.9s |  |
| 1016 | `stage_framerate_negative` | 6 | 6.8s |  |
| 1017 | `stage_framerate_zero` | 6 | 6.8s |  |
| 1018 | `stage_invalidate` | 38 | 7.0s |  |
| 1019 | `stage_loaderinfo_properties` | 24 | 7.0s |  |
| 1020 | `stage_mousechildren` | 2 | 6.8s |  |
| 1021 | `stage_mouseenabled` | 15 | 6.7s |  |
| 1022 | `stage_overriden_setters` | 31 | 7.0s |  |
| 1023 | `stage_properties` | 30 | 6.9s |  |
| 1024 | `stage_properties2` | 213 | 7.1s |  |
| 1025 | `stage_scale_factor` | 12 | 27.9s |  |
| 1026 | `stage_stage3Ds_vector` | 1 | 6.8s |  |
| 1027 | `static_length` | 24 | 6.9s |  |
| 1028 | `static_text` | 3 | 7.0s |  |
| 1029 | `static_var_with_this_in_ctor` | 2 | 6.8s |  |
| 1030 | `statictext_text` | 8 | 6.8s |  |
| 1031 | `stored_properties` | 11 | 6.8s |  |
| 1032 | `strict_equality` | 34 | 6.7s |  |
| 1033 | `string_call` | 13 | 6.7s |  |
| 1034 | `string_case` | 23 | 6.7s |  |
| 1035 | `string_char_at` | 27 | 6.7s |  |
| 1036 | `string_char_code_at` | 28 | 6.6s |  |
| 1037 | `string_concat_fromcharcode` | 37 | 6.7s |  |
| 1038 | `string_constr` | 25 | 6.7s |  |
| 1039 | `string_indexof_lastindexof` | 87 | 6.8s |  |
| 1040 | `string_length` | 16 | 6.6s |  |
| 1041 | `string_locale_compare` | 39 | 6.8s |  |
| 1042 | `string_match` | 51 | 6.8s |  |
| 1043 | `string_relational_compare` | 4 | 2.1s |  |
| 1044 | `string_replace` | 51 | 6.7s |  |
| 1045 | `string_search` | 41 | 6.7s |  |
| 1046 | `string_slice_substr_substring` | 170 | 7.3s |  |
| 1047 | `string_split` | 29 | 6.5s |  |
| 1048 | `string_substr_negative` | 21 | 6.4s |  |
| 1049 | `string_substr_weird` | 182 | 6.4s |  |
| 1050 | `stylesheet` | 221 | 7.1s |  |
| 1051 | `stylesheet_parse_color` | 69 | 6.5s |  |
| 1052 | `stylesheet_transform` | 307 | 6.8s |  |
| 1053 | `sub_super_same_field` | 12 | 2.2s |  |
| 1054 | `subclass_superclass_linked_symbol` | 4 | 6.9s |  |
| 1055 | `subtract` | 1058 | 13.7s |  |
| 1056 | `super_get_call` | 12 | 6.5s |  |
| 1057 | `supercall_two_classobjects` | 2 | 6.5s |  |
| 1058 | `supercalls_coerce` | 8 | 2.2s |  |
| 1059 | `supercalls_weird` | 2 | 6.4s |  |
| 1060 | `superinterface_call` | 20 | 6.5s |  |
| 1061 | `superinterface_instanceof` | 18 | 6.5s |  |
| 1062 | `swf8` | 1 | 6.4s |  |
| 1063 | `swf_10_queued_goto_scripts_construct` | 52 | 6.6s |  |
| 1064 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 1065 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.6s |  |
| 1066 | `swf_9_queued_goto_scripts` | 6 | 6.5s |  |
| 1067 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 1068 | `swf_9_versioning` | 2 | 6.5s |  |
| 1069 | `swf_wrong_frame_count` | 38 | 6.8s |  |
| 1070 | `swf_wrong_frame_count_isplaying` | 22 | 6.5s |  |
| 1071 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 1072 | `symbol_class_conflict` | 4 | 6.8s |  |
| 1073 | `symbol_class_root_not_zero` | 1 | 6.5s |  |
| 1074 | `symbolclass_invalid_utf8` | 2 | 6.5s |  |
| 1075 | `system_exit` | 3 | 6.5s |  |
| 1076 | `system_setclipboard_null` | 1 | 6.5s |  |
| 1077 | `tab_ordering_arrows` | 998 | 23.5s |  |
| 1078 | `tab_ordering_automatic_advanced` | 184 | 7.0s |  |
| 1079 | `tab_ordering_automatic_basic` | 45 | 6.6s |  |
| 1080 | `tab_ordering_children` | 116 | 6.7s |  |
| 1081 | `tab_ordering_custom_basic` | 34 | 6.5s |  |
| 1082 | `tab_ordering_properties` | 732 | 6.8s |  |
| 1083 | `tab_ordering_stage_tab_children` | 32 | 9.4s |  |
| 1084 | `tab_ordering_stage_tab_children_remove_root` | 5 | 9.1s |  |
| 1085 | `tab_ordering_tabbable` | 47 | 9.3s |  |
| 1086 | `tabstop_properties` | 105 | 9.7s |  |
| 1087 | `text_element_basic` | 34 | 9.4s |  |
| 1088 | `text_engine_fontdescription` | 27 | 9.4s |  |
| 1089 | `text_engine_groupelement` | 64 | 10.3s |  |
| 1090 | `text_run` | 7 | 3.5s |  |
| 1091 | `textblock_createline_errors` | 23 | 9.4s |  |
| 1092 | `textblock_createline_fte` | 9 | 29.9s |  |
| 1093 | `textblock_properties` | 118 | 9.8s |  |
| 1094 | `textbox_click` | 37 | 30.3s |  |
| 1095 | `textfield_event` | 66 | 9.6s |  |
| 1096 | `textfield_focusin_event` | 9 | 9.2s |  |
| 1097 | `textfield_input_dead_keys_windows` | 15 | 9.2s |  |
| 1098 | `textfield_input_events` | 25 | 28.1s |  |
| 1099 | `textfield_unload` | 39 | 30.1s |  |
| 1100 | `textformat` | 1134 | 9.2s |  |
| 1101 | `textformat_display` | 14 | 9.3s |  |
| 1102 | `textformat_font_max_length` | 4 | 9.1s |  |
| 1103 | `textjustifier_locale` | 132 | 9.5s |  |
| 1104 | `textline_has_tabs` | 47 | 9.2s |  |
| 1105 | `textline_inapplicable_properties` | 10 | 9.2s |  |
| 1106 | `textline_name` | 1 | 9.1s |  |
| 1107 | `textline_raw_text_length` | 30 | 9.2s |  |
| 1108 | `textline_splitting_basic` | 76 | 9.4s |  |
| 1109 | `textline_throwerror` | 30 | 9.2s |  |
| 1110 | `textline_validity` | 162 | 9.4s |  |
| 1111 | `throw` | 3 | 9.1s |  |
| 1112 | `timeline_scripts` | 3 | 9.2s |  |
| 1113 | `timer` | 90 | 10.6s |  |
| 1114 | `timer_events` | 3 | 9.1s |  |
| 1115 | `timer_finished` | 11 | 9.3s |  |
| 1116 | `timer_invalid_delay` | 30 | 9.2s |  |
| 1117 | `timer_reset` | 8 | 9.6s |  |
| 1118 | `timer_setdelay` | 5 | 9.4s |  |
| 1119 | `trace` | 12 | 6.7s |  |
| 1120 | `truthiness` | 30 | 6.7s |  |
| 1121 | `try_catch` | 11 | 6.8s |  |
| 1122 | `try_catch_typed` | 12 | 6.8s |  |
| 1123 | `typeof` | 30 | 6.8s |  |
| 1124 | `uint_constr` | 92 | 6.8s |  |
| 1125 | `uint_tofixed` | 1215 | 6.6s |  |
| 1126 | `uint_toprecision` | 1125 | 6.9s |  |
| 1127 | `uint_tostring` | 3375 | 6.8s |  |
| 1128 | `uncaught_error_basic` | 2 | 6.6s |  |
| 1129 | `unchecked_function` | 15 | 6.6s |  |
| 1130 | `unescape` | 28 | 6.6s |  |
| 1131 | `url_loader` | 25 | 6.8s |  |
| 1132 | `url_vars` | 27 | 6.8s |  |
| 1133 | `urlrequest` | 18 | 6.6s |  |
| 1134 | `urlstream_basic` | 5 | 6.6s |  |
| 1135 | `urshift` | 1058 | 13.8s |  |
| 1136 | `utils3d` | 7 | 6.6s |  |
| 1137 | `vector3d` | 397 | 9.4s |  |
| 1138 | `vector3d_near_equals` | 80 | 6.7s |  |
| 1139 | `vector_class` | 36 | 7.0s |  |
| 1140 | `vector_class_call` | 11 | 6.7s |  |
| 1141 | `vector_coercion` | 66 | 7.3s |  |
| 1142 | `vector_concat` | 90 | 7.2s |  |
| 1143 | `vector_constr` | 107 | 7.2s |  |
| 1144 | `vector_enumeration` | 5 | 6.5s |  |
| 1145 | `vector_every` | 92 | 7.2s |  |
| 1146 | `vector_filter` | 95 | 7.3s |  |
| 1147 | `vector_holes` | 24 | 6.6s |  |
| 1148 | `vector_indexof` | 302 | 9.5s |  |
| 1149 | `vector_insertat` | 270 | 7.5s |  |
| 1150 | `vector_int_access` | 4 | 6.5s |  |
| 1151 | `vector_int_delete` | 11 | 6.5s |  |
| 1152 | `vector_join` | 58 | 6.9s |  |
| 1153 | `vector_lastindexof` | 302 | 6.4s |  |
| 1154 | `vector_legacy` | 10 | 6.6s |  |
| 1155 | `vector_map` | 85 | 7.1s |  |
| 1156 | `vector_object_final` | 1 | 6.5s |  |
| 1157 | `vector_object_toString` | 10 | 6.5s |  |
| 1158 | `vector_prototype_some` | 125 | 6.7s |  |
| 1159 | `vector_pushpop` | 255 | 11.0s |  |
| 1160 | `vector_reborrow_bug` | 10 | 9.3s |  |
| 1161 | `vector_removeat` | 172 | 10.7s |  |
| 1162 | `vector_reverse` | 232 | 10.8s |  |
| 1163 | `vector_shiftunshift` | 252 | 9.1s |  |
| 1164 | `vector_slice` | 331 | 11.4s |  |
| 1165 | `vector_sort` | 905 | 19.9s |  |
| 1166 | `vector_splice` | 693 | 13.9s |  |
| 1167 | `vector_splice_fixed_bug_compat` | 4 | 9.2s |  |
| 1168 | `vector_tostring` | 79 | 10.0s |  |
| 1169 | `verification` | 8 | 9.3s |  |
| 1170 | `verify_abnormal_loop` | 1 | 9.2s |  |
| 1171 | `verify_dxns_without_flag` | 3 | 9.7s |  |
| 1172 | `verify_exception_target_two_jumps` | 1 | 9.2s |  |
| 1173 | `verify_exception_targets_edge_case` | 1 | 9.2s |  |
| 1174 | `verify_illegal_opcode` | 1 | 3.9s |  |
| 1175 | `verify_jump_to_middle_of_op` | 1 | 9.2s |  |
| 1176 | `verify_lookup_switch_edge_case` | 1 | 9.3s |  |
| 1177 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1178 | `verify_stack` | 5 | 9.3s |  |
| 1179 | `verify_typecheck` | 4 | 9.5s |  |
| 1180 | `verify_unreachable_exception` | 2 | 9.3s |  |
| 1181 | `versioned_isplaying` | 2 | 9.3s |  |
| 1182 | `virtual_properties` | 16 | 9.5s |  |
| 1183 | `with` | 4 | 9.5s |  |
| 1184 | `wrong_arg_count` | 7 | 9.8s |  |
| 1185 | `xml_abstract_equality` | 36 | 9.8s |  |
| 1186 | `xml_advanced` | 52 | 9.6s |  |
| 1187 | `xml_appendchild` | 10 | 9.5s |  |
| 1188 | `xml_appendchild_swf_v21` | 13 | 9.8s |  |
| 1189 | `xml_as_attribute` | 9 | 9.5s |  |
| 1190 | `xml_attribute` | 35 | 9.7s |  |
| 1191 | `xml_attribute_name` | 40 | 9.6s |  |
| 1192 | `xml_basic` | 33 | 9.7s |  |
| 1193 | `xml_child` | 25 | 9.6s |  |
| 1194 | `xml_childindex` | 7 | 3.6s |  |
| 1195 | `xml_children` | 43 | 10.2s |  |
| 1196 | `xml_class_call` | 9 | 9.5s |  |
| 1197 | `xml_contains` | 197 | 9.8s |  |
| 1198 | `xml_copy` | 20 | 8.8s |  |
| 1199 | `xml_ctor_from_tostring` | 23 | 9.0s |  |
| 1200 | `xml_delete` | 114 | 8.7s |  |
| 1201 | `xml_descendants` | 83 | 8.7s |  |
| 1202 | `xml_duplicate_attribute` | 14 | 8.7s |  |
| 1203 | `xml_elements` | 6 | 8.5s |  |
| 1204 | `xml_equals_namespace_check` | 2 | 8.6s |  |
| 1205 | `xml_explicit_use_namespace` | 5 | 8.7s |  |
| 1206 | `xml_getdescendants_qname` | 21 | 8.7s |  |
| 1207 | `xml_has_property_via_in` | 26 | 8.7s |  |
| 1208 | `xml_hasownproperty` | 6 | 8.6s |  |
| 1209 | `xml_ignore_white` | 6 | 8.7s |  |
| 1210 | `xml_length` | 2 | 8.7s |  |
| 1211 | `xml_list_as_attribute` | 9 | 8.7s |  |
| 1212 | `xml_list_concat` | 20 | 8.7s |  |
| 1213 | `xml_list_ctor_errors` | 34 | 8.8s |  |
| 1214 | `xml_list_delete_clear_parent` | 6 | 8.7s |  |
| 1215 | `xml_list_enumerate` | 4 | 8.7s |  |
| 1216 | `xml_methods_settings` | 3 | 8.7s |  |
| 1217 | `xml_mismatched_tag` | 45 | 3.1s |  |
| 1218 | `xml_namespace` | 39 | 3.1s |  |
| 1219 | `xml_namespace_methods` | 245 | 8.9s |  |
| 1220 | `xml_namespaced_property` | 7 | 8.7s |  |
| 1221 | `xml_no_namespace` | 1 | 8.7s |  |
| 1222 | `xml_nodekind` | 3 | 8.7s |  |
| 1223 | `xml_normalize` | 35 | 8.9s |  |
| 1224 | `xml_notification_bubbling` | 361 | 8.8s |  |
| 1225 | `xml_parent` | 8 | 8.8s |  |
| 1226 | `xml_set_children` | 17 | 8.7s |  |
| 1227 | `xml_set_name` | 34 | 8.7s |  |
| 1228 | `xml_settings` | 6 | 3.0s |  |
| 1229 | `xml_simple_complex_content` | 47 | 8.8s |  |
| 1230 | `xml_socket` | 11 | 8.8s |  |
| 1231 | `xml_text` | 7 | 8.8s |  |
| 1232 | `xml_tostring` | 6 | 8.8s |  |
| 1233 | `xml_tostring_namespace` | 12 | 8.6s |  |
| 1234 | `xml_unescaping` | 23 | 3.1s |  |
| 1235 | `xml_weird_ignores` | 54 | 8.9s |  |
| 1236 | `xml_wildcard` | 11 | 3.1s |  |
| 1237 | `xmldocument` | 254 | 8.9s |  |
| 1238 | `xmlnode` | 3540 | 9.1s |  |
| 1239 | `zero_frame_clip` | 3 | 9.1s |  |

## Ruffle-Matched Tests

**18 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.8s |  |
| 2 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 24.3s |  |
| 3 | `error_1034_debug_string` | 19 | 19 | 9.5s |  |
| 4 | `goto_framescript_queued/swf13` | 3 | 3 | 23.6s |  |
| 5 | `gradient_values_readback` | 12 | 12 | 7.1s |  |
| 6 | `groupelement_text` | 2 | 2 | 7.0s |  |
| 7 | `html_text_img_parsing` | 95 | 95 | 7.0s |  |
| 8 | `json_parse_numbers` | 4 | 79 | 9.4s |  |
| 9 | `loader_events_2` | 30 | 30 | 7.0s |  |
| 10 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.0s |  |
| 11 | `number_convert_errors` | 706 | 706 | 6.9s |  |
| 12 | `number_to_string` | 104 | 104 | 7.1s |  |
| 13 | `textblock_line_changes` | 44 | 44 | 9.9s |  |
| 14 | `textblock_recreateline` | 137 | 138 | 9.8s |  |
| 15 | `textblock_releaselines` | 4 | 4 | 10.9s |  |
| 16 | `textline_atom_index_at_char_index` | 3 | 3 | 10.3s |  |
| 17 | `uncaught_errors_stringified` | 15 | 15 | 6.8s |  |
| 18 | `vector_indexing_cutoffs` | 1 | 1 | 6.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `error_stack_trace_class_names` | 94.1% | 127 | 135 | 8 |  |
| 2 | `array_join_reentrant` | 85.3% | 58 | 68 | 10 |  |
| 3 | `edittext_set_text_same` | 80.0% | 92 | 115 | 23 |  |
| 4 | `filereference_browse_select` | 77.8% | 7 | 9 | 2 |  |
| 5 | `weird_number_bound_methods` | 75.0% | 9 | 12 | 3 |  |
| 6 | `hit_test_scroll_rect` | 69.7% | 69 | 99 | 30 |  |
| 7 | `error_stack_trace_limit` | 69.1% | 600 | 868 | 268 |  |
| 8 | `event_handler_exception` | 63.6% | 7 | 11 | 4 |  |
| 9 | `edittext_set_text_same_after_edits` | 60.9% | 84 | 138 | 54 |  |
| 10 | `dictionary_qname_keys` | 50.9% | 29 | 57 | 28 |  |
| 11 | `xml_many_namespace_declarations` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**39 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `error_stack_trace_class_names` | 94.1% | 127/135 | 135 | 135 |  |
| 2 | `array_join_reentrant` | 85.3% | 58/68 | 68 | 68 |  |
| 3 | `edittext_set_text_same` | 80.0% | 92/115 | 115 | 115 |  |
| 4 | `filereference_browse_select` | 77.8% | 7/9 | 9 | 9 |  |
| 5 | `weird_number_bound_methods` | 75.0% | 9/12 | 12 | 12 |  |
| 6 | `hit_test_scroll_rect` | 69.7% | 69/99 | 99 | 99 |  |
| 7 | `error_stack_trace_limit` | 69.1% | 600/868 | 868 | 674 |  |
| 8 | `event_handler_exception` | 63.6% | 7/11 | 11 | 11 |  |
| 9 | `edittext_set_text_same_after_edits` | 60.9% | 84/138 | 138 | 138 |  |
| 10 | `dictionary_qname_keys` | 50.9% | 29/57 | 57 | 45 |  |
| 11 | `xml_many_namespace_declarations` | 50.0% | 1/2 | 2 | 2 |  |
| 12 | `primitive_bound_methods` | 45.5% | 5/11 | 11 | 11 |  |
| 13 | `loaderinfo_root_progress` | 42.9% | 3/7 | 6 | 7 |  |
| 14 | `loaderinfo_root_progress_goto` | 40.0% | 4/10 | 6 | 10 |  |
| 15 | `displayobjectcontainer_removechildren_events` | 36.2% | 21/58 | 58 | 56 |  |
| 16 | `stage3d_missing_vertex_stream` | 35.1% | 13/37 | 27 | 37 |  |
| 17 | `textfield_default_text_format_null` | 35.0% | 7/20 | 12 | 20 |  |
| 18 | `amf_xmllist` | 33.3% | 4/12 | 12 | 12 |  |
| 19 | `displayobjectcontainer_remove_reparent` | 31.2% | 59/189 | 185 | 189 |  |
| 20 | `focus_events_mixed_avm_edittext` | 24.5% | 12/49 | 47 | 49 |  |
| 21 | `xml_unescaping_nul_char_ref` | 21.1% | 4/19 | 19 | 19 |  |
| 22 | `perspective_projection_center` | 17.6% | 6/34 | 26 | 34 |  |
| 23 | `context3d_draw_to_bitmap_data` | 13.3% | 2/15 | 11 | 15 |  |
| 24 | `vector_join_reentrant` | 10.4% | 10/96 | 84 | 96 |  |
| 25 | `array_sort_arguments` | 9.5% | 42/442 | 277 | 442 |  |
| 26 | `array_constructor` | 9.0% | 21/234 | 181 | 234 |  |
| 27 | `textfield_set_text_format_args` | 9.0% | 81/904 | 638 | 904 |  |
| 28 | `textfield_get_text_format_args` | 8.8% | 50/567 | 447 | 567 |  |
| 29 | `shared_object_get_local_error` | 4.8% | 1/21 | 5 | 21 |  |
| 30 | `bitmapdata_encode_png_roundtrip` | 3.0% | 1/33 | 4 | 33 |  |
| 31 | `worker_terminate` | 1.8% | 1/56 | 3 | 56 |  |
| 32 | `bitmapdata_encode` | 0.7% | 1/147 | 5 | 147 |  |
| 33 | `vector_sort_arguments` | 0.3% | 1/355 | 198 | 355 |  |
| 34 | `displayobjectcontainer_remove_reentrant` | 0.0% | 2/27942 | 27942 | 257 |  |
| 35 | `bitmapdata_encode_jpeg_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 36 | `bitmapdata_encode_png_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 37 | `edittext_event_link_case_insensitive` | 0.0% | 0/1 | 0 | 1 |  |
| 38 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 39 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
