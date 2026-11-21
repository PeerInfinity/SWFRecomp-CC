# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:32 UTC

**Git SHA**: `c489b84d99`

**Run Duration**: 233m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1335 |
| Passing | **1253** (93.9%) |
| Ruffle-matched | 43 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1296** (97.1%) |
| Failing | 39 |
| Total expected lines | 163943 |
| Matching lines | 158199 (96.5%) |
| Mismatched lines | 5744 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 39 | 100.0% |

## Passing Tests

**1253 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 38.8s |  |
| 2 | `accessibility` | 1 | 6.8s |  |
| 3 | `accessibilityimplementation` | 18 | 23.3s |  |
| 4 | `activation_class` | 6 | 6.8s |  |
| 5 | `add` | 1058 | 14.4s |  |
| 6 | `agal_compiler` | 13 | 9.0s |  |
| 7 | `air_datagram_socket` | 1 | 8.5s |  |
| 8 | `air_hidden_lookup` | 2 | 6.7s |  |
| 9 | `air_ifilepromise` | 1 | 6.6s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 6.8s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.9s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.9s |  |
| 13 | `all_classes/display/swf10` | 2569 | 6.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.0s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.9s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.0s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.9s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.9s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 6.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.9s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.9s |  |
| 22 | `all_classes/errors/swf10` | 140 | 6.8s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.9s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.9s |  |
| 25 | `all_classes/events/swf10` | 1638 | 6.8s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.9s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.9s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.9s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.9s |  |
| 30 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.9s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.9s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.9s |  |
| 34 | `all_classes/xml/swf30` | 116 | 6.8s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.9s |  |
| 36 | `allow_networking` | 72 | 25.2s |  |
| 37 | `amf_array_serialization` | 17 | 7.0s |  |
| 38 | `amf_custom_obj` | 26 | 6.7s |  |
| 39 | `amf_dictionary` | 9 | 6.6s |  |
| 40 | `amf_function` | 46 | 6.6s |  |
| 41 | `amf_invalid_date` | 2 | 6.6s |  |
| 42 | `amf_missing_prop` | 6 | 6.6s |  |
| 43 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 44 | `amf_sealed_class_dynamic_properties` | 16 | 6.7s |  |
| 45 | `amf_setter_error` | 8 | 6.7s |  |
| 46 | `amf_vector` | 40 | 38.4s |  |
| 47 | `amf_xml` | 6 | 6.6s |  |
| 48 | `appdomain_lookup_edge_cases` | 32 | 7.1s |  |
| 49 | `application_domain` | 4 | 6.7s |  |
| 50 | `applicationdomain_getqualifieddefinitionnames` | 9 | 22.6s |  |
| 51 | `applicationdomain_hasdefinition_null` | 2 | 6.6s |  |
| 52 | `array_access` | 18 | 6.8s |  |
| 53 | `array_access_interpreter` | 4 | 6.7s |  |
| 54 | `array_access_no_pubns` | 2 | 6.6s |  |
| 55 | `array_concat` | 41 | 6.7s |  |
| 56 | `array_constr` | 10 | 6.6s |  |
| 57 | `array_delete` | 44 | 6.8s |  |
| 58 | `array_enumeration` | 10 | 6.8s |  |
| 59 | `array_enumeration_elements` | 11 | 6.7s |  |
| 60 | `array_every` | 8 | 6.7s |  |
| 61 | `array_filter` | 6 | 6.7s |  |
| 62 | `array_foreach` | 18 | 6.7s |  |
| 63 | `array_hasownproperty` | 11 | 6.7s |  |
| 64 | `array_holes` | 9 | 6.7s |  |
| 65 | `array_index_max` | 84 | 6.6s |  |
| 66 | `array_indexof` | 25 | 6.7s |  |
| 67 | `array_join` | 26 | 6.8s |  |
| 68 | `array_lastindexof` | 29 | 6.7s |  |
| 69 | `array_length` | 14 | 6.8s |  |
| 70 | `array_literal` | 3 | 6.8s |  |
| 71 | `array_map` | 8 | 6.7s |  |
| 72 | `array_pop` | 52 | 7.0s |  |
| 73 | `array_push` | 24 | 6.8s |  |
| 74 | `array_reborrow_bug` | 6 | 6.7s |  |
| 75 | `array_reverse` | 28 | 6.7s |  |
| 76 | `array_shift` | 51 | 2.4s |  |
| 77 | `array_slice` | 39 | 6.8s |  |
| 78 | `array_some` | 8 | 6.7s |  |
| 79 | `array_sort` | 297 | 7.2s |  |
| 80 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 81 | `array_sort_fun_swf13` | 2 | 0.9s |  |
| 82 | `array_sort_random` | 210 | 6.8s |  |
| 83 | `array_sort_swf10_32bit` | 1 | 6.6s |  |
| 84 | `array_sorton` | 545 | 7.6s |  |
| 85 | `array_sparse_ops` | 41 | 41.0s |  |
| 86 | `array_splice` | 133 | 23.7s |  |
| 87 | `array_splice2` | 428 | 7.7s |  |
| 88 | `array_splice_types` | 48 | 7.5s |  |
| 89 | `array_storage` | 8 | 7.4s |  |
| 90 | `array_tolocalestring` | 9 | 7.5s |  |
| 91 | `array_tostring` | 12 | 7.4s |  |
| 92 | `array_unshift` | 24 | 7.5s |  |
| 93 | `array_valueof` | 9 | 7.4s |  |
| 94 | `array_vector_null_callback` | 10 | 7.4s |  |
| 95 | `astype` | 28 | 7.5s |  |
| 96 | `astypelate` | 24 | 7.6s |  |
| 97 | `astypelate_propagates` | 1 | 7.4s |  |
| 98 | `asymmetric_key_events` | 11 | 7.6s |  |
| 99 | `automation_classes` | 122 | 7.8s |  |
| 100 | `av_classes` | 340 | 7.7s |  |
| 101 | `avm1movie_addcallback_call` | 14 | 7.6s |  |
| 102 | `avm2_catchup_dobj` | 158 | 8.2s |  |
| 103 | `away3d_advanced_shallow_water_demo` | 0 | 89.7s |  |
| 104 | `bevel_filter` | 187 | 8.0s |  |
| 105 | `bitand` | 1058 | 16.4s |  |
| 106 | `bitmap_constr` | 17 | 7.8s |  |
| 107 | `bitmap_data` | 1000 | 16.4s |  |
| 108 | `bitmap_filter_abstract` | 6 | 7.4s |  |
| 109 | `bitmap_pixelsnapping` | 2 | 24.1s |  |
| 110 | `bitmap_properties` | 23 | 7.7s |  |
| 111 | `bitmap_subclass` | 7 | 9.4s |  |
| 112 | `bitmap_subclass_properties` | 9 | 7.9s |  |
| 113 | `bitmap_timeline` | 9 | 7.7s |  |
| 114 | `bitmapdata_accuracy` | 1 | 42.0s |  |
| 115 | `bitmapdata_applyfilter_blur` | 0 | 24.3s |  |
| 116 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.1s |  |
| 117 | `bitmapdata_applyfilter_destpoint` | 0 | 25.8s |  |
| 118 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 24.2s |  |
| 119 | `bitmapdata_applyfilter_identity` | 4 | 23.6s |  |
| 120 | `bitmapdata_clone` | 13 | 7.6s |  |
| 121 | `bitmapdata_colortransform` | 0 | 7.8s |  |
| 122 | `bitmapdata_colortransform_oob` | 2 | 7.4s |  |
| 123 | `bitmapdata_constr` | 22 | 7.5s |  |
| 124 | `bitmapdata_constructor_from_timeline` | 1 | 7.8s |  |
| 125 | `bitmapdata_copychannel` | 0 | 25.4s |  |
| 126 | `bitmapdata_copypixels` | 23 | 24.6s |  |
| 127 | `bitmapdata_copypixels_alpha_combine` | 13 | 7.5s |  |
| 128 | `bitmapdata_copypixels_alpha_merge` | 9 | 51.1s |  |
| 129 | `bitmapdata_copypixels_blend` | 1029 | 10.0s |  |
| 130 | `bitmapdata_copypixels_blend_over` | 1 | 9.5s |  |
| 131 | `bitmapdata_copypixels_self` | 612 | 9.5s |  |
| 132 | `bitmapdata_copypixelstobytearray` | 39 | 9.5s |  |
| 133 | `bitmapdata_dispose` | 7 | 9.6s |  |
| 134 | `bitmapdata_draw` | 0 | 31.6s |  |
| 135 | `bitmapdata_draw_alpha_erase` | 8 | 9.7s |  |
| 136 | `bitmapdata_draw_cab_quality` | 0 | 32.1s |  |
| 137 | `bitmapdata_draw_colortransform` | 0 | 30.4s |  |
| 138 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 30.9s |  |
| 139 | `bitmapdata_draw_filters` | 0 | 30.6s |  |
| 140 | `bitmapdata_draw_masks` | 0 | 9.6s |  |
| 141 | `bitmapdata_draw_rotation` | 0 | 9.7s |  |
| 142 | `bitmapdata_draw_self_via_graphic` | 0 | 9.6s |  |
| 143 | `bitmapdata_draw_stage` | 0 | 30.4s |  |
| 144 | `bitmapdata_drawwithquality` | 0 | 12.7s |  |
| 145 | `bitmapdata_embedded` | 9 | 9.8s |  |
| 146 | `bitmapdata_encode_jpeg_visual` | 0 | 30.7s |  |
| 147 | `bitmapdata_encode_png_roundtrip` | 33 | 9.6s |  |
| 148 | `bitmapdata_encode_png_visual` | 0 | 9.5s |  |
| 149 | `bitmapdata_fillrect` | 0 | 9.6s |  |
| 150 | `bitmapdata_filter_sourcerect` | 0 | 30.6s |  |
| 151 | `bitmapdata_floodfill` | 35 | 9.4s |  |
| 152 | `bitmapdata_getpixels` | 39 | 30.3s |  |
| 153 | `bitmapdata_getvector` | 27 | 3.5s |  |
| 154 | `bitmapdata_histogram` | 59 | 3.5s |  |
| 155 | `bitmapdata_hittest` | 112 | 10.1s |  |
| 156 | `bitmapdata_hittest_threshold` | 18 | 9.6s |  |
| 157 | `bitmapdata_opaque` | 0 | 9.6s |  |
| 158 | `bitmapdata_pixeldissolve` | 1037 | 10.2s |  |
| 159 | `bitmapdata_pixeldissolve_image` | 0 | 9.8s |  |
| 160 | `bitmapdata_rectangle_rounding` | 16 | 9.5s |  |
| 161 | `bitmapdata_setpixels` | 286 | 9.5s |  |
| 162 | `bitmapdata_setvector` | 26 | 9.8s |  |
| 163 | `bitmapdata_sync` | 0 | 30.5s |  |
| 164 | `bitmapdata_threshold` | 176 | 10.2s |  |
| 165 | `bitmapdata_zero_size` | 8 | 9.4s |  |
| 166 | `bitnot` | 46 | 9.5s |  |
| 167 | `bitor` | 1058 | 21.1s |  |
| 168 | `bitxor` | 1058 | 21.0s |  |
| 169 | `blend_mode_null` | 1 | 9.3s |  |
| 170 | `blend_multiply_alpha` | 0 | 9.6s |  |
| 171 | `blend_scroll` | 0 | 9.6s |  |
| 172 | `blend_shader_luma_lighten` | 3 | 39.0s |  |
| 173 | `blur_filter` | 43 | 6.9s |  |
| 174 | `boolean_constr` | 32 | 6.6s |  |
| 175 | `boolean_negation` | 30 | 6.6s |  |
| 176 | `boolean_tostring` | 8 | 6.6s |  |
| 177 | `broadcast_event` | 7 | 6.6s |  |
| 178 | `button_bounds` | 1 | 6.6s |  |
| 179 | `button_hittest` | 2 | 22.5s |  |
| 180 | `button_nested_frame` | 48 | 23.1s |  |
| 181 | `button_nested_frame_simple` | 27 | 6.9s |  |
| 182 | `bytearray` | 48 | 6.7s |  |
| 183 | `bytearray_amf3_shared_references` | 4 | 6.6s |  |
| 184 | `bytearray_bad_symbol_class` | 3 | 6.5s |  |
| 185 | `bytearray_bad_symbol_class_other_movie` | 6 | 7.0s |  |
| 186 | `bytearray_compress` | 31 | 6.6s |  |
| 187 | `bytearray_errors` | 24 | 6.7s |  |
| 188 | `bytearray_insertion_reborrow` | 5 | 6.6s |  |
| 189 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 190 | `bytearray_oom` | 3 | 6.5s |  |
| 191 | `bytearray_readobject_amf0` | 50 | 6.6s |  |
| 192 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 193 | `bytearray_readutf8bytes_with_bom` | 16 | 6.6s |  |
| 194 | `bytearray_serialization` | 3 | 6.5s |  |
| 195 | `bytearray_string_null` | 19 | 6.8s |  |
| 196 | `bytearray_tostring` | 15 | 6.6s |  |
| 197 | `bytearray_utf16` | 8 | 6.5s |  |
| 198 | `bytearray_writeobject` | 24 | 6.5s |  |
| 199 | `callee_in_initializer` | 6 | 6.5s |  |
| 200 | `callproplex_class` | 1 | 6.5s |  |
| 201 | `capabilities_resolution` | 8 | 23.6s |  |
| 202 | `casi32` | 166 | 6.7s |  |
| 203 | `catch_class` | 6 | 6.5s |  |
| 204 | `catch_scope_slot` | 7 | 6.6s |  |
| 205 | `checkfilter` | 4 | 2.2s |  |
| 206 | `class_call` | 32 | 6.8s |  |
| 207 | `class_cast_call` | 14 | 6.6s |  |
| 208 | `class_enumeration` | 4 | 6.6s |  |
| 209 | `class_has_own_property` | 2 | 6.6s |  |
| 210 | `class_init_interpreter_mode` | 1 | 6.5s |  |
| 211 | `class_is` | 32 | 6.7s |  |
| 212 | `class_methods` | 5 | 6.6s |  |
| 213 | `class_object_properties` | 10 | 6.6s |  |
| 214 | `class_singleton` | 18 | 7.8s |  |
| 215 | `class_supercalls_errors` | 35 | 7.9s |  |
| 216 | `class_supercalls_mismatched` | 26 | 7.6s |  |
| 217 | `class_superclass_wrong_order` | 1 | 24.9s |  |
| 218 | `class_to_locale_string` | 2 | 7.8s |  |
| 219 | `class_to_string` | 2 | 7.8s |  |
| 220 | `class_value_of` | 2 | 7.7s |  |
| 221 | `click_block` | 5 | 25.8s |  |
| 222 | `click_invisible` | 3 | 7.9s |  |
| 223 | `closures` | 12 | 7.8s |  |
| 224 | `coerce_return_type` | 40 | 8.0s |  |
| 225 | `coerce_return_type_fail` | 2 | 7.6s |  |
| 226 | `coerce_return_void` | 3 | 7.7s |  |
| 227 | `coerce_string` | 86 | 7.8s |  |
| 228 | `coerce_string_precision` | 28 | 7.7s |  |
| 229 | `coerce_to_primitive_side_effects` | 29 | 7.9s |  |
| 230 | `collator_compare_basic` | 93 | 7.8s |  |
| 231 | `collator_flags` | 111 | 7.8s |  |
| 232 | `collator_locale_ids_windows` | 120 | 8.0s |  |
| 233 | `color_matrix_filter` | 19 | 7.8s |  |
| 234 | `construct_errors_swf10` | 8 | 7.7s |  |
| 235 | `construct_frame_list` | 22 | 24.6s |  |
| 236 | `construct_interface` | 3 | 7.6s |  |
| 237 | `constructor_call` | 3 | 7.5s |  |
| 238 | `constructors_vs_timeline` | 5 | 23.8s |  |
| 239 | `constructprop_dynamic_primitive` | 7 | 7.6s |  |
| 240 | `constructprop_method` | 2 | 7.5s |  |
| 241 | `constructsuper_null` | 2 | 2.9s |  |
| 242 | `content_element_basic` | 50 | 7.8s |  |
| 243 | `context3d_clear_mask` | 4 | 7.4s |  |
| 244 | `context3d_creation` | 9 | 9.4s |  |
| 245 | `control_flow_bool` | 4 | 7.5s |  |
| 246 | `control_flow_stricteq` | 8 | 7.5s |  |
| 247 | `convert_boolean` | 30 | 7.7s |  |
| 248 | `convert_integer` | 90 | 7.7s |  |
| 249 | `convert_number` | 56 | 7.7s |  |
| 250 | `convert_uinteger` | 90 | 7.7s |  |
| 251 | `convolution_filter` | 89 | 7.8s |  |
| 252 | `core_exceptions` | 47 | 8.5s |  |
| 253 | `cpool_index_invalid_bytecode_1` | 6 | 7.5s |  |
| 254 | `cpool_index_invalid_bytecode_2` | 3 | 7.5s |  |
| 255 | `cpool_index_invalid_bytecode_3` | 1 | 7.5s |  |
| 256 | `cross_api_version_call_newer` | 12 | 7.4s |  |
| 257 | `cross_api_version_call_older` | 12 | 7.0s |  |
| 258 | `cryptscore` | 11 | 6.8s |  |
| 259 | `currency_parse_result` | 7 | 6.7s |  |
| 260 | `date` | 30 | 7.2s |  |
| 261 | `date_parse` | 36 | 6.7s |  |
| 262 | `date_set_time_out_of_range` | 62 | 6.7s |  |
| 263 | `declocal` | 46 | 6.8s |  |
| 264 | `declocal_i` | 46 | 6.8s |  |
| 265 | `decode_uri` | 71 | 7.1s |  |
| 266 | `decrement` | 46 | 6.8s |  |
| 267 | `decrement_i` | 46 | 2.3s |  |
| 268 | `default_values` | 7 | 6.7s |  |
| 269 | `delayed_symbolclass` | 28 | 23.2s |  |
| 270 | `describe_type_basic` | 152 | 6.9s |  |
| 271 | `describe_type_json` | 301 | 6.9s |  |
| 272 | `describe_type_metadata` | 125 | 6.8s |  |
| 273 | `describe_type_native` | 23 | 6.7s |  |
| 274 | `dictionary_access` | 62 | 7.0s |  |
| 275 | `dictionary_access_no_pubns` | 2 | 6.7s |  |
| 276 | `dictionary_delete` | 101 | 7.2s |  |
| 277 | `dictionary_foreach` | 42 | 7.0s |  |
| 278 | `dictionary_hasownproperty` | 63 | 7.0s |  |
| 279 | `dictionary_in` | 62 | 7.0s |  |
| 280 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 281 | `dictionary_namespaces` | 36 | 6.8s |  |
| 282 | `dictionary_qname_keys` | 45 | 7.0s |  |
| 283 | `displacement_map_filter` | 61 | 6.8s |  |
| 284 | `displayobject_alpha` | 277 | 6.7s |  |
| 285 | `displayobject_blendmode` | 0 | 26.2s |  |
| 286 | `displayobject_colortransform_nested` | 0 | 23.3s |  |
| 287 | `displayobject_early_init` | 54 | 8.3s |  |
| 288 | `displayobject_filters` | 17 | 7.0s |  |
| 289 | `displayobject_from_enterframe` | 1 | 23.4s |  |
| 290 | `displayobject_getbounds_shape` | 0 | 23.1s |  |
| 291 | `displayobject_getrect` | 16 | 7.0s |  |
| 292 | `displayobject_height` | 6052 | 23.1s |  |
| 293 | `displayobject_hittestobject` | 32 | 6.8s |  |
| 294 | `displayobject_hittestpoint` | 49 | 6.9s |  |
| 295 | `displayobject_hittestpoint_boundary` | 65 | 23.7s |  |
| 296 | `displayobject_hittestpoint_root` | 13 | 7.0s |  |
| 297 | `displayobject_invalid_floats` | 60 | 6.8s |  |
| 298 | `displayobject_invalid_props` | 3 | 6.8s |  |
| 299 | `displayobject_mask` | 3 | 9.9s |  |
| 300 | `displayobject_mask_self_referential` | 0 | 22.6s |  |
| 301 | `displayobject_metaData` | 3 | 6.7s |  |
| 302 | `displayobject_name` | 22 | 23.1s |  |
| 303 | `displayobject_name_from_timeline` | 24 | 6.9s |  |
| 304 | `displayobject_opaque_background` | 6 | 23.2s |  |
| 305 | `displayobject_parent` | 12 | 6.9s |  |
| 306 | `displayobject_root` | 24 | 6.8s |  |
| 307 | `displayobject_rotation` | 1284 | 6.9s |  |
| 308 | `displayobject_scrollrect` | 33 | 7.3s |  |
| 309 | `displayobject_set_matrix_nested` | 0 | 25.0s |  |
| 310 | `displayobject_set_name_loaded` | 3 | 7.0s |  |
| 311 | `displayobject_subclass` | 2 | 6.8s |  |
| 312 | `displayobject_transform` | 89 | 6.9s |  |
| 313 | `displayobject_visible` | 23 | 6.8s |  |
| 314 | `displayobject_width` | 4852 | 23.4s |  |
| 315 | `displayobject_x` | 614 | 6.8s |  |
| 316 | `displayobject_y` | 617 | 6.8s |  |
| 317 | `displayobject_z` | 38 | 23.5s |  |
| 318 | `displayobjectcontainer_addchild` | 32 | 6.8s |  |
| 319 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.7s |  |
| 320 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.0s |  |
| 321 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.9s |  |
| 322 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.0s |  |
| 323 | `displayobjectcontainer_addchildat` | 42 | 6.9s |  |
| 324 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.9s |  |
| 325 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.8s |  |
| 326 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.8s |  |
| 327 | `displayobjectcontainer_contains` | 66 | 23.5s |  |
| 328 | `displayobjectcontainer_getchildat` | 4 | 6.8s |  |
| 329 | `displayobjectcontainer_getchildbyname` | 9 | 6.7s |  |
| 330 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.8s |  |
| 331 | `displayobjectcontainer_getchildindex` | 28 | 6.8s |  |
| 332 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 23.1s |  |
| 333 | `displayobjectcontainer_removechild` | 10 | 6.8s |  |
| 334 | `displayobjectcontainer_removechild_errors` | 4 | 6.8s |  |
| 335 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.0s |  |
| 336 | `displayobjectcontainer_removechildat` | 18 | 6.8s |  |
| 337 | `displayobjectcontainer_removechildren` | 51 | 7.0s |  |
| 338 | `displayobjectcontainer_setchildindex` | 42 | 6.6s |  |
| 339 | `displayobjectcontainer_stopallmovieclips` | 2 | 23.2s |  |
| 340 | `displayobjectcontainer_swapchildren` | 42 | 9.8s |  |
| 341 | `displayobjectcontainer_swapchildrenat` | 42 | 9.6s |  |
| 342 | `displayobjectcontainer_timelineinstance` | 48 | 30.5s |  |
| 343 | `divide` | 1058 | 20.7s |  |
| 344 | `doabc_and_symbolclass_script_init_goto` | 7 | 30.2s |  |
| 345 | `doabc_and_symbolclass_script_init_normal` | 6 | 9.3s |  |
| 346 | `doabc_is_eager` | 1 | 30.0s |  |
| 347 | `documentclass` | 9 | 9.5s |  |
| 348 | `domain_memory` | 133 | 31.1s |  |
| 349 | `drag_drop` | 10 | 9.6s |  |
| 350 | `drop_shadow_filter` | 172 | 9.7s |  |
| 351 | `duplicate_defs` | 1 | 9.2s |  |
| 352 | `eager_init` | 1 | 9.4s |  |
| 353 | `east_asian_justifier_clone` | 8 | 9.4s |  |
| 354 | `edit_text_linkage` | 7 | 9.6s |  |
| 355 | `edittext_align` | 60 | 10.1s |  |
| 356 | `edittext_always_show_selection` | 0 | 34.5s |  |
| 357 | `edittext_antialiastype` | 296 | 9.9s |  |
| 358 | `edittext_at_point_methods_basic` | 16 | 11.0s |  |
| 359 | `edittext_autosize` | 39 | 10.1s |  |
| 360 | `edittext_autosize_align` | 0 | 30.4s |  |
| 361 | `edittext_autosize_height_dynamic` | 60 | 30.8s |  |
| 362 | `edittext_autosize_height_input` | 60 | 9.5s |  |
| 363 | `edittext_autosize_lazy_bounds_events` | 65 | 9.6s |  |
| 364 | `edittext_autosize_lazy_bounds_interactions` | 19 | 9.4s |  |
| 365 | `edittext_autosize_lazy_bounds_props` | 490 | 11.3s |  |
| 366 | `edittext_autosize_lazy_bounds_visual` | 0 | 9.6s |  |
| 367 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 9.6s |  |
| 368 | `edittext_bottom_scroll_v_basic` | 210 | 9.5s |  |
| 369 | `edittext_bounds_scale` | 24 | 30.4s |  |
| 370 | `edittext_bullet` | 30 | 9.7s |  |
| 371 | `edittext_default_format` | 221 | 9.9s |  |
| 372 | `edittext_default_format_empty` | 136 | 9.7s |  |
| 373 | `edittext_empty_text_format` | 7 | 9.5s |  |
| 374 | `edittext_event_link_case_insensitive` | 1 | 9.5s |  |
| 375 | `edittext_focus_selection` | 5 | 9.4s |  |
| 376 | `edittext_font_size` | 45 | 9.8s |  |
| 377 | `edittext_format_empty_font` | 8 | 9.4s |  |
| 378 | `edittext_get_char_index_at_point` | 4 | 32.6s |  |
| 379 | `edittext_get_line_index_at_point` | 2 | 30.5s |  |
| 380 | `edittext_get_line_index_of_char` | 76 | 10.6s |  |
| 381 | `edittext_getcharboundaries` | 172 | 9.9s |  |
| 382 | `edittext_getcharboundaries_missing_glyphs` | 63 | 10.1s |  |
| 383 | `edittext_getcharboundaries_scroll` | 85 | 29.7s |  |
| 384 | `edittext_getlinemetrics` | 146 | 9.7s |  |
| 385 | `edittext_html` | 3101 | 9.8s |  |
| 386 | `edittext_html_condensewhite` | 487 | 9.3s |  |
| 387 | `edittext_html_entity` | 4 | 9.8s |  |
| 388 | `edittext_html_font_size_swf12` | 267 | 9.4s |  |
| 389 | `edittext_html_font_size_swf13` | 273 | 9.0s |  |
| 390 | `edittext_html_roundtrip` | 17 | 9.3s |  |
| 391 | `edittext_ime_focus_lost` | 9 | 29.7s |  |
| 392 | `edittext_input_control` | 12 | 9.4s |  |
| 393 | `edittext_leading` | 9 | 9.8s |  |
| 394 | `edittext_letter_spacing` | 15 | 9.4s |  |
| 395 | `edittext_line_methods` | 294 | 10.9s |  |
| 396 | `edittext_line_metrics` | 11 | 31.2s |  |
| 397 | `edittext_margins` | 25 | 9.6s |  |
| 398 | `edittext_max_scroll_h_basic` | 475 | 9.5s |  |
| 399 | `edittext_max_scroll_v_basic` | 1000 | 9.3s |  |
| 400 | `edittext_mouse_selection` | 363 | 31.0s |  |
| 401 | `edittext_mousedown` | 3 | 9.5s |  |
| 402 | `edittext_mouseenabled` | 26 | 9.2s |  |
| 403 | `edittext_newline_character` | 22 | 9.2s |  |
| 404 | `edittext_newline_stripping` | 64 | 17.5s |  |
| 405 | `edittext_newlines` | 30 | 9.4s |  |
| 406 | `edittext_paragraph_methods` | 257 | 9.4s |  |
| 407 | `edittext_paste_events` | 8 | 9.6s |  |
| 408 | `edittext_paste_maxchars` | 4 | 9.3s |  |
| 409 | `edittext_paste_restrict` | 16 | 9.2s |  |
| 410 | `edittext_restrict` | 191 | 9.3s |  |
| 411 | `edittext_restrict_events` | 22 | 9.2s |  |
| 412 | `edittext_scroll_event` | 37 | 9.6s |  |
| 413 | `edittext_scrollh` | 10 | 9.2s |  |
| 414 | `edittext_selected_text` | 9 | 9.2s |  |
| 415 | `edittext_set_html_same` | 17 | 9.3s |  |
| 416 | `edittext_set_text_vs_html` | 9 | 9.3s |  |
| 417 | `edittext_stylesheet` | 536 | 9.9s |  |
| 418 | `edittext_stylesheet_custom_tag` | 76 | 9.4s |  |
| 419 | `edittext_stylesheet_display` | 272 | 9.4s |  |
| 420 | `edittext_tag_indent` | 49 | 30.2s |  |
| 421 | `edittext_underline` | 40 | 9.7s |  |
| 422 | `edittext_width_height` | 103 | 9.8s |  |
| 423 | `edittext_wordwrap_word` | 150 | 9.5s |  |
| 424 | `edittext_wrap_breaks` | 2375 | 23.8s |  |
| 425 | `element_format_clone` | 44 | 7.0s |  |
| 426 | `element_format_constructor_order` | 64 | 7.0s |  |
| 427 | `element_format_properties` | 235 | 8.0s |  |
| 428 | `empty_bounds` | 1 | 6.8s |  |
| 429 | `encode_uri_surrogate_pair_invalid` | 8 | 6.8s |  |
| 430 | `encode_uri_surrogate_pair_swf11` | 15 | 6.6s |  |
| 431 | `equals` | 512 | 9.5s |  |
| 432 | `error_geterrormessage` | 779 | 6.8s |  |
| 433 | `error_prototype` | 15 | 6.8s |  |
| 434 | `error_stack_trace` | 45 | 6.8s |  |
| 435 | `error_stack_trace_debug_swf17` | 0 | 24.9s |  |
| 436 | `error_stack_trace_debug_swf18` | 0 | 6.5s |  |
| 437 | `error_stack_trace_edge_cases` | 6 | 6.7s |  |
| 438 | `error_stack_trace_release_swf17` | 0 | 2.2s |  |
| 439 | `error_stack_trace_release_swf18` | 0 | 6.5s |  |
| 440 | `error_throwerror` | 103 | 6.8s |  |
| 441 | `error_tostring` | 29 | 6.8s |  |
| 442 | `error_tostring_more` | 86 | 6.7s |  |
| 443 | `es3_inheritance` | 31 | 6.8s |  |
| 444 | `es4_inheritance` | 30 | 6.8s |  |
| 445 | `es4_interfaces` | 30 | 6.7s |  |
| 446 | `es4_method_binding` | 8 | 6.7s |  |
| 447 | `es4_oop_prototypes` | 14 | 6.9s |  |
| 448 | `es4_protected_inheritance` | 6 | 6.7s |  |
| 449 | `escape` | 71 | 6.7s |  |
| 450 | `escape_multi_byte` | 45 | 6.8s |  |
| 451 | `event_bubbles` | 2 | 6.6s |  |
| 452 | `event_cancelable` | 2 | 6.5s |  |
| 453 | `event_clone` | 20 | 6.7s |  |
| 454 | `event_clone_error_redispatch` | 3 | 6.7s |  |
| 455 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 456 | `event_formattostring` | 31 | 6.7s |  |
| 457 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 458 | `event_target_getter` | 5 | 2.2s |  |
| 459 | `event_target_set` | 9 | 6.5s |  |
| 460 | `event_type` | 1 | 6.6s |  |
| 461 | `event_valueof_tostring` | 18 | 6.7s |  |
| 462 | `eventdispatcher_dispatchevent` | 12 | 6.6s |  |
| 463 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.6s |  |
| 464 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.8s |  |
| 465 | `eventdispatcher_dispatchevent_indirect` | 9 | 23.2s |  |
| 466 | `eventdispatcher_dispatchevent_this` | 5 | 6.8s |  |
| 467 | `eventdispatcher_haseventlistener` | 25 | 6.8s |  |
| 468 | `eventdispatcher_interface_invoke` | 1 | 6.7s |  |
| 469 | `eventdispatcher_tostring` | 10 | 6.8s |  |
| 470 | `eventdispatcher_willtrigger` | 25 | 6.7s |  |
| 471 | `external_interface` | 105 | 7.0s |  |
| 472 | `falsiness` | 30 | 6.8s |  |
| 473 | `fast_index_access` | 12 | 7.0s |  |
| 474 | `filefilter_properties` | 4 | 6.8s |  |
| 475 | `filereference_browse_cancel` | 3 | 6.8s |  |
| 476 | `filereference_browse_select` | 9 | 6.8s |  |
| 477 | `filereference_load` | 31 | 6.8s |  |
| 478 | `filereference_save` | 16 | 6.8s |  |
| 479 | `filereference_save_and_browse` | 42 | 6.9s |  |
| 480 | `filereference_save_and_load` | 22 | 6.8s |  |
| 481 | `filereference_uninitialized` | 8 | 6.8s |  |
| 482 | `filereferencelist_browse_cancel` | 6 | 6.7s |  |
| 483 | `filereferencelist_browse_select` | 7 | 6.8s |  |
| 484 | `filter_rewind` | 8 | 23.3s |  |
| 485 | `filters_array_holes` | 25 | 9.6s |  |
| 486 | `finddef` | 3 | 6.8s |  |
| 487 | `findprop_global_prototype` | 6 | 6.8s |  |
| 488 | `flash_media_video_constructor` | 156 | 7.4s |  |
| 489 | `flash_media_video_rotation_probe` | 27 | 6.8s |  |
| 490 | `flash_media_video_setter` | 40 | 7.2s |  |
| 491 | `flash_trace` | 17 | 6.8s |  |
| 492 | `flash_ui_mouse_cursor` | 35 | 7.1s |  |
| 493 | `flash_xml` | 29 | 6.9s |  |
| 494 | `flash_xml_cloneNode` | 22 | 6.8s |  |
| 495 | `flash_xml_namespace` | 109 | 6.7s |  |
| 496 | `flash_xml_removeNode` | 60 | 6.8s |  |
| 497 | `focus_events_code` | 161 | 23.2s |  |
| 498 | `focus_events_key_basic` | 132 | 23.2s |  |
| 499 | `focus_events_key_navigation` | 53 | 23.0s |  |
| 500 | `focus_events_key_same_object` | 26 | 6.8s |  |
| 501 | `focus_events_mixed_avm_edittext` | 49 | 7.3s |  |
| 502 | `focus_events_mixed_key_mouse` | 100 | 22.8s |  |
| 503 | `focus_events_mouse_basic` | 260 | 22.9s |  |
| 504 | `focus_events_mouse_focusable` | 112 | 22.9s |  |
| 505 | `focus_events_mouse_same_object` | 40 | 6.7s |  |
| 506 | `focus_remove` | 20 | 22.8s |  |
| 507 | `focus_root_movie` | 4 | 24.8s |  |
| 508 | `focus_stage` | 1 | 6.7s |  |
| 509 | `focusrect` | 18 | 25.3s |  |
| 510 | `focusrect_focuslost` | 9 | 6.7s |  |
| 511 | `focusrect_property` | 110 | 22.0s |  |
| 512 | `font_description_clone` | 14 | 6.5s |  |
| 513 | `font_embedded` | 24 | 6.9s |  |
| 514 | `font_enumeratefonts` | 41 | 7.0s |  |
| 515 | `font_enumeratefonts_filter` | 4 | 7.0s |  |
| 516 | `font_enumeratefonts_order` | 9 | 7.4s |  |
| 517 | `font_hasglyphs` | 40 | 6.9s |  |
| 518 | `font_registerfont` | 129 | 7.3s |  |
| 519 | `framelabel_constr` | 5 | 6.6s |  |
| 520 | `function_call` | 12 | 2.2s |  |
| 521 | `function_call_arguments` | 46 | 6.6s |  |
| 522 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 523 | `function_call_coercion` | 108 | 6.8s |  |
| 524 | `function_call_default` | 6 | 6.5s |  |
| 525 | `function_call_rest` | 22 | 6.5s |  |
| 526 | `function_call_types` | 3 | 6.5s |  |
| 527 | `function_call_via_apply` | 11 | 6.6s |  |
| 528 | `function_call_via_call` | 3 | 6.5s |  |
| 529 | `function_display_anonymous` | 7 | 2.2s |  |
| 530 | `function_length` | 6 | 6.5s |  |
| 531 | `function_object` | 2 | 6.5s |  |
| 532 | `function_proto` | 5 | 6.5s |  |
| 533 | `function_proto_created` | 61 | 6.6s |  |
| 534 | `function_to_locale_string` | 4 | 6.5s |  |
| 535 | `function_to_string` | 4 | 6.4s |  |
| 536 | `function_type` | 6 | 6.6s |  |
| 537 | `function_unbound_this` | 51 | 6.7s |  |
| 538 | `function_value_of` | 4 | 6.5s |  |
| 539 | `game_input` | 4 | 6.5s |  |
| 540 | `generate_random_bytes` | 3 | 6.6s |  |
| 541 | `geom_transform` | 74 | 22.8s |  |
| 542 | `get_definition_by_name` | 11 | 6.5s |  |
| 543 | `get_qualified_class_name` | 20 | 6.6s |  |
| 544 | `get_qualified_super_class_name` | 18 | 6.5s |  |
| 545 | `get_slot_edge_cases` | 1 | 6.4s |  |
| 546 | `get_timer` | 2 | 2.1s |  |
| 547 | `getglobalslot` | 1 | 6.4s |  |
| 548 | `getouterscope` | 8 | 6.4s |  |
| 549 | `getouterscope_two_classobjects` | 13 | 6.5s |  |
| 550 | `getter_different_namespace_setter` | 2 | 6.4s |  |
| 551 | `glow_filter` | 127 | 6.7s |  |
| 552 | `goto_button_nested_framescript` | 28 | 22.4s |  |
| 553 | `goto_framescript_queued/swf10` | 59 | 23.3s |  |
| 554 | `goto_framescript_queued/swf9` | 52 | 1.0s |  |
| 555 | `goto_framescript_queued_same_frame` | 4 | 23.0s |  |
| 556 | `goto_in_constructframe` | 12 | 23.1s |  |
| 557 | `goto_in_scene_last_frame` | 2 | 22.5s |  |
| 558 | `goto_methods` | 56 | 6.8s |  |
| 559 | `goto_methods_swfver10` | 8 | 6.6s |  |
| 560 | `goto_nested_construct_sibling` | 18 | 7.1s |  |
| 561 | `goto_nested_framescript` | 9 | 6.7s |  |
| 562 | `goto_on_orphan` | 15 | 22.5s |  |
| 563 | `goto_queued_invalid/swf10` | 34 | 22.9s |  |
| 564 | `goto_queued_invalid/swf11` | 43 | 0.9s |  |
| 565 | `goto_queued_invalid/swf9` | 32 | 0.9s |  |
| 566 | `gradient_bevel_filter` | 206 | 6.7s |  |
| 567 | `gradient_glow_filter` | 206 | 6.5s |  |
| 568 | `graphic_linkage` | 9 | 6.7s |  |
| 569 | `graphics_bad_direct_commands` | 5 | 10.0s |  |
| 570 | `graphics_bitmap_fill` | 0 | 24.0s |  |
| 571 | `graphics_bitmaps` | 0 | 6.9s |  |
| 572 | `graphics_direct_commands` | 0 | 6.9s |  |
| 573 | `graphics_draw_triangles` | 98 | 23.6s |  |
| 574 | `graphics_gradients` | 0 | 7.0s |  |
| 575 | `graphics_gradients_nulls` | 0 | 6.7s |  |
| 576 | `graphics_path` | 56 | 6.7s |  |
| 577 | `graphics_round_rects` | 0 | 8.4s |  |
| 578 | `graphics_simple_shapes` | 0 | 6.8s |  |
| 579 | `greaterequals` | 512 | 9.3s |  |
| 580 | `greaterthan` | 512 | 9.2s |  |
| 581 | `has_own_property` | 102 | 7.1s |  |
| 582 | `hasownproperty_namespaces` | 2 | 6.6s |  |
| 583 | `hello_world` | 1 | 6.6s |  |
| 584 | `hittest_morph` | 30 | 6.8s |  |
| 585 | `id3_info` | 8 | 22.6s |  |
| 586 | `if_eq` | 10 | 6.7s |  |
| 587 | `if_gt` | 1 | 6.7s |  |
| 588 | `if_gte` | 10 | 2.3s |  |
| 589 | `if_lt` | 1 | 0.9s |  |
| 590 | `if_lte` | 10 | 6.7s |  |
| 591 | `if_ne` | 7 | 2.3s |  |
| 592 | `if_stricteq` | 6 | 7.5s |  |
| 593 | `if_strictne` | 11 | 7.5s |  |
| 594 | `ime_linux_dead_keys` | 10 | 23.9s |  |
| 595 | `in` | 102 | 7.9s |  |
| 596 | `inclocal` | 46 | 7.5s |  |
| 597 | `inclocal_i` | 46 | 7.5s |  |
| 598 | `increment` | 46 | 7.5s |  |
| 599 | `increment_i` | 46 | 7.5s |  |
| 600 | `indexing_delete` | 75 | 7.5s |  |
| 601 | `indexof_xml` | 10 | 7.5s |  |
| 602 | `init_callee_cached` | 24 | 7.5s |  |
| 603 | `instanceof` | 58 | 7.8s |  |
| 604 | `instantiate_root_character` | 4 | 7.7s |  |
| 605 | `instantiation_on_enter_frame` | 7 | 23.9s |  |
| 606 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.5s |  |
| 607 | `int_constr` | 92 | 7.6s |  |
| 608 | `int_edge_cases` | 19 | 7.5s |  |
| 609 | `int_instanceof` | 3 | 7.4s |  |
| 610 | `int_tofixed` | 1215 | 7.4s |  |
| 611 | `int_toprecision` | 1125 | 7.7s |  |
| 612 | `int_tostring` | 3375 | 7.7s |  |
| 613 | `interactiveobject_enabled` | 25 | 7.9s |  |
| 614 | `interface_namespaces` | 78 | 7.8s |  |
| 615 | `invalid_utf8` | 12 | 7.8s |  |
| 616 | `is_finite` | 46 | 7.8s |  |
| 617 | `is_nan` | 46 | 7.7s |  |
| 618 | `is_prototype_of` | 12 | 7.8s |  |
| 619 | `issue_10221` | 2 | 7.8s |  |
| 620 | `issue_13780` | 12 | 7.5s |  |
| 621 | `issue_14901` | 1 | 7.6s |  |
| 622 | `issue_17675_edittext_paste_maxchars` | 1 | 7.7s |  |
| 623 | `issue_5292` | 5 | 7.6s |  |
| 624 | `issue_8630` | 2 | 7.8s |  |
| 625 | `issue_8630_placeremoveplace` | 15 | 8.0s |  |
| 626 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.6s |  |
| 627 | `issue_8630_scriptremove` | 11 | 7.6s |  |
| 628 | `istype` | 24 | 3.1s |  |
| 629 | `istypelate` | 58 | 8.1s |  |
| 630 | `istypelate_coerce` | 198 | 8.7s |  |
| 631 | `jpeg_loader_context` | 6 | 7.5s |  |
| 632 | `json_errors` | 9 | 24.5s |  |
| 633 | `json_parse` | 21 | 7.5s |  |
| 634 | `json_parse_errors` | 84 | 7.5s |  |
| 635 | `json_stringify` | 12 | 38.4s |  |
| 636 | `json_stringify_function` | 12 | 6.7s |  |
| 637 | `json_stringify_order` | 1 | 6.6s |  |
| 638 | `json_version_gated` | 1 | 6.7s |  |
| 639 | `key_input_80percent` | 1812 | 22.8s |  |
| 640 | `key_input_location` | 126 | 6.8s |  |
| 641 | `key_input_numpad` | 384 | 6.7s |  |
| 642 | `large_preload_from_bytes` | 51 | 9.6s |  |
| 643 | `large_preload_from_url` | 27 | 8.4s |  |
| 644 | `large_preload_image_from_bytes` | 25 | 8.3s |  |
| 645 | `lazyinit` | 17 | 6.7s |  |
| 646 | `lessequals` | 512 | 9.2s |  |
| 647 | `lessthan` | 512 | 9.1s |  |
| 648 | `loader_bitmap_transparency` | 14 | 6.7s |  |
| 649 | `loader_bytes_unknown_content` | 14 | 6.8s |  |
| 650 | `loader_child_getdefinition` | 5 | 6.8s |  |
| 651 | `loader_duplicate_class` | 48 | 8.3s |  |
| 652 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 653 | `loader_duplicate_coerce_new_domain` | 4 | 6.8s |  |
| 654 | `loader_error_in_root_ctor` | 4 | 6.8s |  |
| 655 | `loader_events` | 92 | 10.2s |  |
| 656 | `loader_image` | 8 | 6.9s |  |
| 657 | `loader_jpegxr` | 2 | 24.6s |  |
| 658 | `loader_jpegxr_alpha` | 1 | 22.5s |  |
| 659 | `loader_loadbytes_events` | 30 | 7.2s |  |
| 660 | `loader_loadbytes_invalid_png` | 4 | 6.7s |  |
| 661 | `loader_loadbytes_url` | 12 | 6.9s |  |
| 662 | `loader_loaderurl` | 6 | 7.0s |  |
| 663 | `loader_method` | 85 | 6.7s |  |
| 664 | `loader_noninteractive_try_click_root` | 5 | 23.0s |  |
| 665 | `loader_reuse` | 38 | 6.9s |  |
| 666 | `loader_try_click_root` | 16 | 6.9s |  |
| 667 | `loader_unknown_content` | 24 | 6.8s |  |
| 668 | `loader_unloadandstop_subclass` | 1 | 6.7s |  |
| 669 | `loader_visibility_interactive` | 1 | 6.7s |  |
| 670 | `loaderinfo_child_progress` | 9 | 7.2s |  |
| 671 | `loaderinfo_events` | 7 | 6.7s |  |
| 672 | `loaderinfo_loadurl` | 12 | 6.7s |  |
| 673 | `loaderinfo_more` | 6 | 6.8s |  |
| 674 | `loaderinfo_properties` | 18 | 22.9s |  |
| 675 | `loaderinfo_properties_not_loaded` | 23 | 6.8s |  |
| 676 | `loaderinfo_quine` | 1005 | 38.6s |  |
| 677 | `loaderinfo_root` | 10 | 7.0s |  |
| 678 | `loaderinfo_root_allows` | 2 | 6.8s |  |
| 679 | `localconnection` | 890 | 8.9s |  |
| 680 | `localconnection_send` | 4 | 6.8s |  |
| 681 | `lshift` | 1058 | 14.2s |  |
| 682 | `mask_reapply` | 1 | 23.0s |  |
| 683 | `math` | 497 | 7.1s |  |
| 684 | `matrix` | 338 | 15.2s |  |
| 685 | `matrix3d` | 57 | 23.8s |  |
| 686 | `matrix3d_append` | 16 | 6.9s |  |
| 687 | `matrix3d_append_prepend_scale` | 86 | 6.9s |  |
| 688 | `matrix3d_append_prepend_translation` | 42 | 6.8s |  |
| 689 | `matrix3d_append_rotation` | 23 | 6.9s |  |
| 690 | `matrix3d_compose` | 34 | 7.1s |  |
| 691 | `matrix3d_constructor_clone` | 15 | 6.8s |  |
| 692 | `matrix3d_copy_column` | 83 | 7.1s |  |
| 693 | `matrix3d_copy_from` | 19 | 6.9s |  |
| 694 | `matrix3d_copy_raw_data_from` | 55 | 2.5s |  |
| 695 | `matrix3d_copy_raw_data_to` | 38 | 7.0s |  |
| 696 | `matrix3d_copy_row` | 83 | 6.7s |  |
| 697 | `matrix3d_copy_to_matrix3d` | 19 | 6.9s |  |
| 698 | `matrix3d_determinant` | 182 | 6.9s |  |
| 699 | `matrix3d_interpolate` | 21 | 7.0s |  |
| 700 | `matrix3d_invert` | 18 | 6.8s |  |
| 701 | `matrix3d_position` | 19 | 6.8s |  |
| 702 | `matrix3d_precision` | 28 | 7.0s |  |
| 703 | `matrix3d_prepend` | 16 | 6.7s |  |
| 704 | `matrix3d_raw_data` | 33 | 6.9s |  |
| 705 | `matrix3d_transform_vector` | 52 | 7.1s |  |
| 706 | `matrix3d_transpose` | 5 | 6.8s |  |
| 707 | `method_association` | 5 | 6.8s |  |
| 708 | `method_without_body` | 3 | 23.2s |  |
| 709 | `missing_external_interface` | 10 | 6.9s |  |
| 710 | `modulo` | 1058 | 14.3s |  |
| 711 | `morph_shape` | 2 | 23.2s |  |
| 712 | `mouse_children` | 192 | 23.7s |  |
| 713 | `mouse_click_events` | 90 | 23.2s |  |
| 714 | `mouse_double_click_events` | 188 | 6.9s |  |
| 715 | `mouse_empty_parent` | 4 | 6.8s |  |
| 716 | `mouse_over_while_dragging` | 3 | 7.0s |  |
| 717 | `mouse_pick_avm1_root` | 2 | 51.5s |  |
| 718 | `mouse_pick_button_mode` | 2 | 30.4s |  |
| 719 | `mouse_pick_dobj_mask` | 4 | 10.1s |  |
| 720 | `mouse_pick_loader_avm1` | 42 | 10.1s |  |
| 721 | `mouse_pick_masking` | 7 | 30.4s |  |
| 722 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 30.5s |  |
| 723 | `mouse_pick_non_interactive_dobj_mask` | 3 | 9.7s |  |
| 724 | `mouse_pick_scroll_rect` | 27 | 30.5s |  |
| 725 | `mouse_pick_scroll_rect_button` | 5 | 9.7s |  |
| 726 | `mouse_pick_scroll_rect_loader` | 5 | 10.0s |  |
| 727 | `mouse_pick_text` | 8 | 9.7s |  |
| 728 | `mouse_sibling` | 8 | 9.5s |  |
| 729 | `mouse_wheel_events` | 36 | 31.6s |  |
| 730 | `mouseevent_constr` | 66 | 9.7s |  |
| 731 | `mouseevent_stagexy` | 35 | 9.5s |  |
| 732 | `mouseevent_valueof_tostring` | 28 | 9.5s |  |
| 733 | `movieclip_addframescript` | 3 | 30.3s |  |
| 734 | `movieclip_addframescript_error` | 9 | 9.5s |  |
| 735 | `movieclip_child_property` | 16 | 9.6s |  |
| 736 | `movieclip_constr` | 21 | 9.4s |  |
| 737 | `movieclip_currentlabels` | 17 | 30.1s |  |
| 738 | `movieclip_currentlabels_dupes1` | 46 | 30.4s |  |
| 739 | `movieclip_currentlabels_dupes2` | 30 | 9.6s |  |
| 740 | `movieclip_currentlabels_dupes3` | 67 | 9.5s |  |
| 741 | `movieclip_currentscene` | 12 | 30.2s |  |
| 742 | `movieclip_dispatchevent` | 430 | 9.7s |  |
| 743 | `movieclip_dispatchevent_cancel` | 102 | 9.7s |  |
| 744 | `movieclip_dispatchevent_handlerorder` | 251 | 9.9s |  |
| 745 | `movieclip_dispatchevent_selfadd` | 80 | 9.7s |  |
| 746 | `movieclip_dispatchevent_target` | 899 | 9.8s |  |
| 747 | `movieclip_displayevents` | 96 | 30.9s |  |
| 748 | `movieclip_displayevents_clickgoto` | 676 | 31.1s |  |
| 749 | `movieclip_displayevents_clickgoto2` | 2001 | 10.4s |  |
| 750 | `movieclip_displayevents_clickplay` | 575 | 9.8s |  |
| 751 | `movieclip_displayevents_clicksymbol` | 562 | 9.9s |  |
| 752 | `movieclip_displayevents_constructframegoto` | 140 | 10.1s |  |
| 753 | `movieclip_displayevents_constructframeplay` | 50 | 10.2s |  |
| 754 | `movieclip_displayevents_constructframesymbol` | 144 | 10.0s |  |
| 755 | `movieclip_displayevents_dblhandler` | 21 | 9.6s |  |
| 756 | `movieclip_displayevents_enterframegoto` | 149 | 10.0s |  |
| 757 | `movieclip_displayevents_enterframeplay` | 48 | 9.8s |  |
| 758 | `movieclip_displayevents_enterframesymbol` | 149 | 30.8s |  |
| 759 | `movieclip_displayevents_exitframegoto` | 106 | 9.8s |  |
| 760 | `movieclip_displayevents_exitframeplay` | 44 | 9.7s |  |
| 761 | `movieclip_displayevents_exitframesymbol` | 135 | 39.4s |  |
| 762 | `movieclip_displayevents_looping` | 63 | 23.5s |  |
| 763 | `movieclip_displayevents_stopped` | 113 | 23.3s |  |
| 764 | `movieclip_displayevents_swap` | 96 | 7.0s |  |
| 765 | `movieclip_displayevents_timeline` | 128 | 23.5s |  |
| 766 | `movieclip_drawrect` | 54 | 23.2s |  |
| 767 | `movieclip_frameconstruct_skipped` | 9 | 6.9s |  |
| 768 | `movieclip_goto_during_frame_script` | 15 | 23.0s |  |
| 769 | `movieclip_goto_overwrite` | 14 | 23.1s |  |
| 770 | `movieclip_goto_scene_last_frame_int` | 1 | 23.2s |  |
| 771 | `movieclip_goto_scene_last_frame_label` | 1 | 6.7s |  |
| 772 | `movieclip_gotoandplay` | 15 | 22.9s |  |
| 773 | `movieclip_gotoandstop` | 13 | 6.8s |  |
| 774 | `movieclip_gotoandstop_children` | 4 | 6.8s |  |
| 775 | `movieclip_gotoandstop_framescripts1` | 4 | 6.7s |  |
| 776 | `movieclip_gotoandstop_framescripts2` | 4 | 2.2s |  |
| 777 | `movieclip_gotoandstop_framescripts_self` | 7 | 23.1s |  |
| 778 | `movieclip_gotoandstop_queueing` | 12 | 6.9s |  |
| 779 | `movieclip_hittest` | 67 | 6.9s |  |
| 780 | `movieclip_next_frame` | 2 | 6.8s |  |
| 781 | `movieclip_next_scene` | 6 | 6.8s |  |
| 782 | `movieclip_play` | 3 | 6.7s |  |
| 783 | `movieclip_prev_frame` | 3 | 6.7s |  |
| 784 | `movieclip_prev_scene` | 7 | 6.9s |  |
| 785 | `movieclip_properties` | 79 | 23.2s |  |
| 786 | `movieclip_queued_noop_goto_swf10` | 9 | 6.8s |  |
| 787 | `movieclip_queued_noop_goto_swf9` | 7 | 1.0s |  |
| 788 | `movieclip_scenes` | 11 | 6.7s |  |
| 789 | `movieclip_soundtransform` | 831 | 24.7s |  |
| 790 | `movieclip_stop` | 1 | 6.7s |  |
| 791 | `movieclip_super_is_symbol` | 20 | 7.0s |  |
| 792 | `movieclip_symbol_constr` | 8 | 6.9s |  |
| 793 | `movieclip_text_mousedown` | 1 | 6.8s |  |
| 794 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 795 | `multiply` | 1058 | 14.2s |  |
| 796 | `namespace_constr` | 253 | 7.0s |  |
| 797 | `namespace_constr_args` | 1 | 6.7s |  |
| 798 | `namespace_enumeration_order` | 7 | 23.2s |  |
| 799 | `nan_scale` | 9 | 6.8s |  |
| 800 | `native_menu_basic` | 19 | 8.8s |  |
| 801 | `navigateToURL_target_normalize` | 107 | 25.2s |  |
| 802 | `negate` | 30 | 6.7s |  |
| 803 | `negative_volume_panned` | 0 | 7.0s |  |
| 804 | `nested_iteration` | 11 | 6.7s |  |
| 805 | `net_getClassByAlias` | 3 | 37.7s |  |
| 806 | `net_navigateToURL` | 57 | 24.8s |  |
| 807 | `net_stream_play_options` | 6 | 6.6s |  |
| 808 | `netconnection_call_with_responder` | 6 | 22.6s |  |
| 809 | `netconnection_close` | 55 | 22.6s |  |
| 810 | `netconnection_properties` | 78 | 6.7s |  |
| 811 | `netconnection_send_remote` | 50 | 6.8s |  |
| 812 | `netconnection_serialize_arrays` | 6 | 6.6s |  |
| 813 | `netfilterevent` | 10 | 6.6s |  |
| 814 | `netstream_client` | 10 | 6.7s |  |
| 815 | `netstream_connect` | 7 | 6.6s |  |
| 816 | `netstream_flv_date` | 4 | 6.9s |  |
| 817 | `newactivation_in_script_init` | 3 | 6.6s |  |
| 818 | `newclass_mismatched` | 4 | 6.6s |  |
| 819 | `newclass_twice` | 3 | 6.5s |  |
| 820 | `nonconflicting_declarations` | 0 | 6.6s |  |
| 821 | `null_void_types` | 8 | 6.6s |  |
| 822 | `number_autoconv` | 21 | 6.6s |  |
| 823 | `number_autoconv_amf` | 132 | 6.6s |  |
| 824 | `number_autoconv_array_sort_32bit` | 1 | 6.6s |  |
| 825 | `number_constr` | 58 | 6.7s |  |
| 826 | `number_convert_edge_cases` | 180 | 22.4s |  |
| 827 | `number_toexponential` | 378 | 6.7s |  |
| 828 | `number_toexponential2` | 35 | 6.5s |  |
| 829 | `number_tofixed` | 378 | 6.5s |  |
| 830 | `number_toprecision` | 350 | 6.6s |  |
| 831 | `obfuscated_class_names` | 3 | 6.6s |  |
| 832 | `object_enumeration` | 10 | 6.6s |  |
| 833 | `object_prototype` | 4 | 6.6s |  |
| 834 | `object_to_locale_string` | 2 | 6.6s |  |
| 835 | `object_to_string` | 2 | 6.5s |  |
| 836 | `object_value_of` | 2 | 2.1s |  |
| 837 | `op_coerce` | 54 | 6.6s |  |
| 838 | `op_coerce_x` | 54 | 6.7s |  |
| 839 | `op_escxattr` | 2 | 6.6s |  |
| 840 | `op_escxelem` | 2 | 6.5s |  |
| 841 | `op_lookupswitch` | 4 | 6.5s |  |
| 842 | `optimize_coerce` | 1 | 6.5s |  |
| 843 | `orphan_movie_complex` | 80 | 38.1s |  |
| 844 | `orphan_movie_reorder` | 111 | 22.7s |  |
| 845 | `orphan_removeobject` | 636 | 23.1s |  |
| 846 | `package_namespace` | 7 | 22.5s |  |
| 847 | `param_default_value_has_zero_cpool_index` | 1 | 6.6s |  |
| 848 | `parent_early_access_child` | 16 | 22.6s |  |
| 849 | `parse_float` | 81 | 6.7s |  |
| 850 | `parse_float_swf10` | 81 | 6.5s |  |
| 851 | `parse_int` | 135 | 6.9s |  |
| 852 | `perspective_projection` | 1443 | 22.7s |  |
| 853 | `perspective_projection_basic` | 40 | 6.6s |  |
| 854 | `perspective_projection_center` | 34 | 6.7s |  |
| 855 | `pixelbender_ceil` | 77 | 6.8s |  |
| 856 | `pixelbender_conditional` | 138 | 7.0s |  |
| 857 | `pixelbender_conversions` | 270 | 6.9s |  |
| 858 | `pixelbender_dithering` | 8 | 30.1s |  |
| 859 | `pixelbender_div` | 36 | 6.8s |  |
| 860 | `pixelbender_effect_BlurredFocus` | 0 | 29.1s |  |
| 861 | `pixelbender_effect_glassDisplace` | 0 | 11.5s |  |
| 862 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 25.9s |  |
| 863 | `pixelbender_effect_smudge` | 0 | 9.4s |  |
| 864 | `pixelbender_effect_tintype` | 0 | 8.8s |  |
| 865 | `pixelbender_effect_twirl` | 0 | 10.0s |  |
| 866 | `pixelbender_eof` | 7 | 6.6s |  |
| 867 | `pixelbender_images` | 0 | 8.6s |  |
| 868 | `pixelbender_input` | 103 | 24.7s |  |
| 869 | `pixelbender_logicalnot` | 20 | 6.6s |  |
| 870 | `pixelbender_malformed_data` | 190 | 23.1s |  |
| 871 | `pixelbender_multiple_out_params` | 1 | 6.6s |  |
| 872 | `pixelbender_no_out_param` | 6 | 6.6s |  |
| 873 | `pixelbender_outputs` | 13 | 6.8s |  |
| 874 | `pixelbender_padding_bytes` | 22 | 6.7s |  |
| 875 | `pixelbender_param_qualifier` | 512 | 6.8s |  |
| 876 | `pixelbender_parameters` | 1563 | 7.0s |  |
| 877 | `pixelbender_parameters_bool` | 240 | 6.8s |  |
| 878 | `pixelbender_parameters_int_vs_bool` | 54 | 6.7s |  |
| 879 | `pixelbender_parse_errors` | 6 | 6.6s |  |
| 880 | `pixelbender_rsqrt` | 24 | 6.7s |  |
| 881 | `pixelbender_select_kinds` | 8 | 6.8s |  |
| 882 | `pixelbender_shaderdata` | 49 | 6.6s |  |
| 883 | `pixelbender_shaderdata_setter` | 99 | 7.0s |  |
| 884 | `pixelbender_sign` | 60 | 6.8s |  |
| 885 | `pixelbender_vector_output` | 11 | 6.8s |  |
| 886 | `place_and_lookup/swf10` | 33 | 6.7s |  |
| 887 | `place_and_lookup/swf9` | 33 | 34.0s |  |
| 888 | `place_multiple` | 17 | 20.9s |  |
| 889 | `place_object_replace` | 9 | 20.2s |  |
| 890 | `place_object_replace_2` | 24 | 20.1s |  |
| 891 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 892 | `point` | 132 | 6.8s |  |
| 893 | `primitive_edge_cases` | 1 | 6.4s |  |
| 894 | `primitive_keys` | 54 | 6.6s |  |
| 895 | `primitive_toString` | 277 | 6.7s |  |
| 896 | `primitive_valueOf` | 285 | 6.3s |  |
| 897 | `print_job_options` | 3 | 6.4s |  |
| 898 | `property_is_enumerable` | 114 | 7.4s |  |
| 899 | `property_is_enumerable_reset` | 23 | 6.5s |  |
| 900 | `property_priority` | 22 | 6.7s |  |
| 901 | `property_priority_chained` | 4 | 6.4s |  |
| 902 | `property_priority_definition_names_order` | 2 | 6.7s |  |
| 903 | `property_priority_three_level` | 6 | 6.6s |  |
| 904 | `propertyisenumerable_namespaces` | 6 | 6.5s |  |
| 905 | `prototype_set_null` | 7 | 7.2s |  |
| 906 | `proxy_callproperty` | 24 | 6.7s |  |
| 907 | `proxy_deleteproperty` | 64 | 6.7s |  |
| 908 | `proxy_enumeration` | 34 | 6.5s |  |
| 909 | `proxy_getproperty` | 77 | 6.5s |  |
| 910 | `proxy_hasownproperty` | 8 | 6.5s |  |
| 911 | `proxy_hasproperty` | 32 | 6.6s |  |
| 912 | `proxy_not_overridden` | 54 | 6.6s |  |
| 913 | `proxy_serialize` | 9 | 6.7s |  |
| 914 | `proxy_setproperty` | 42 | 6.6s |  |
| 915 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.6s |  |
| 916 | `qname_constr` | 32 | 6.5s |  |
| 917 | `qname_constr_namespace` | 24 | 6.5s |  |
| 918 | `qname_enumeration` | 9 | 6.4s |  |
| 919 | `qname_indexing` | 23 | 6.4s |  |
| 920 | `qname_tostring` | 25 | 6.5s |  |
| 921 | `qname_valueof` | 29 | 6.8s |  |
| 922 | `rectangle` | 1094 | 7.7s |  |
| 923 | `regexp_constr` | 148 | 6.8s |  |
| 924 | `regexp_exec` | 19 | 6.5s |  |
| 925 | `regexp_extended` | 47 | 6.6s |  |
| 926 | `regexp_multiargs` | 1 | 6.5s |  |
| 927 | `regexp_test` | 27 | 6.7s |  |
| 928 | `regexp_toString` | 10 | 6.6s |  |
| 929 | `register_script_refresh` | 35 | 21.0s |  |
| 930 | `remove_child_clear_field` | 88 | 37.3s |  |
| 931 | `remove_dobj` | 3 | 22.0s |  |
| 932 | `resolve_order` | 4 | 6.4s |  |
| 933 | `responder_null_callbacks` | 1 | 21.8s |  |
| 934 | `rng` | 1 | 7.4s |  |
| 935 | `rootless` | 42 | 6.6s |  |
| 936 | `rshift` | 1058 | 13.4s |  |
| 937 | `rtqname_not_namespace` | 12 | 6.5s |  |
| 938 | `sandbox_type_inherited` | 2 | 6.8s |  |
| 939 | `sandbox_type_local_file` | 1 | 6.4s |  |
| 940 | `sandbox_type_local_network` | 1 | 6.3s |  |
| 941 | `scene_constr` | 8 | 6.6s |  |
| 942 | `scope_optimizations` | 4 | 6.5s |  |
| 943 | `scopes_dont_cache/order-1` | 1 | 21.8s |  |
| 944 | `scopes_dont_cache/order-2` | 1 | 0.7s |  |
| 945 | `security_domain_current` | 2 | 6.4s |  |
| 946 | `selection` | 239 | 7.0s |  |
| 947 | `selection_onsetfocus_mixed_avm` | 5 | 22.2s |  |
| 948 | `set_local_0` | 31 | 6.6s |  |
| 949 | `set_property_is_enumerable` | 85 | 6.9s |  |
| 950 | `shaderparameter_value` | 4 | 6.5s |  |
| 951 | `shape_drawrect` | 54 | 6.6s |  |
| 952 | `shared_object_no_root` | 3 | 6.4s |  |
| 953 | `simplebutton_added_to_stage` | 45 | 22.1s |  |
| 954 | `simplebutton_childevents` | 86 | 22.4s |  |
| 955 | `simplebutton_childevents_nested` | 54 | 6.8s |  |
| 956 | `simplebutton_childevents_sprite` | 13 | 6.7s |  |
| 957 | `simplebutton_childprops` | 144 | 6.7s |  |
| 958 | `simplebutton_childshuffle` | 23 | 6.5s |  |
| 959 | `simplebutton_constr` | 36 | 6.8s |  |
| 960 | `simplebutton_constr_childevents` | 48 | 6.9s |  |
| 961 | `simplebutton_constr_params` | 42 | 6.7s |  |
| 962 | `simplebutton_mouseenabled` | 26 | 6.6s |  |
| 963 | `simplebutton_multi_children` | 19 | 6.7s |  |
| 964 | `simplebutton_soundtransform` | 887 | 23.4s |  |
| 965 | `simplebutton_structure` | 27 | 6.7s |  |
| 966 | `simplebutton_symbolclass` | 68 | 6.9s |  |
| 967 | `slot_disp_id_shared_numbering` | 1 | 21.9s |  |
| 968 | `slots_force_autoassigned` | 1 | 35.9s |  |
| 969 | `socket_after_disconnect` | 1 | 21.0s |  |
| 970 | `socket_close` | 2 | 6.1s |  |
| 971 | `socket_connect` | 4 | 6.2s |  |
| 972 | `socket_errors` | 56 | 5.8s |  |
| 973 | `socket_read_big` | 48 | 5.8s |  |
| 974 | `socket_read_little` | 48 | 1.6s |  |
| 975 | `socket_read_write_object` | 8 | 5.9s |  |
| 976 | `socket_write_big` | 15 | 6.2s |  |
| 977 | `socket_write_little` | 14 | 5.9s |  |
| 978 | `sound_constructor_with_args` | 6 | 5.9s |  |
| 979 | `sound_embeddedprops` | 26 | 5.7s |  |
| 980 | `sound_load_multiple` | 19 | 6.1s |  |
| 981 | `sound_play` | 19 | 5.8s |  |
| 982 | `sound_rootless` | 7 | 5.8s |  |
| 983 | `sound_valueof` | 33 | 6.2s |  |
| 984 | `soundchannel_soundtransform` | 835 | 21.6s |  |
| 985 | `soundchannel_soundtransform_exists` | 5 | 21.2s |  |
| 986 | `soundchannel_stop` | 8 | 21.4s |  |
| 987 | `soundmixer_buffertime` | 5 | 5.8s |  |
| 988 | `soundmixer_soundtransform` | 900 | 6.5s |  |
| 989 | `soundmixer_stopall` | 6 | 21.6s |  |
| 990 | `soundtransform` | 442 | 5.8s |  |
| 991 | `space_justifier_clone` | 12 | 6.5s |  |
| 992 | `sprite_with_frames` | 0 | 24.2s |  |
| 993 | `stage3d_agal_cross_product` | 0 | 6.4s |  |
| 994 | `stage3d_agal_upload_errors` | 66 | 7.3s |  |
| 995 | `stage3d_bitmap` | 0 | 22.2s |  |
| 996 | `stage3d_blend` | 81 | 26.2s |  |
| 997 | `stage3d_context3d_string_args` | 158 | 5.8s |  |
| 998 | `stage3d_errors` | 7 | 6.1s |  |
| 999 | `stage3d_errors_atf` | 3 | 6.6s |  |
| 1000 | `stage3d_errors_swf_29` | 6 | 5.8s |  |
| 1001 | `stage3d_float1_index` | 0 | 21.1s |  |
| 1002 | `stage3d_fractal` | 0 | 22.8s |  |
| 1003 | `stage3d_ignore_sampler_override` | 0 | 21.4s |  |
| 1004 | `stage3d_multistage_triangle` | 3 | 8.2s |  |
| 1005 | `stage3d_program_constants_bytearray_be` | 0 | 22.5s |  |
| 1006 | `stage3d_program_constants_bytearray_le` | 0 | 8.9s |  |
| 1007 | `stage3d_program_constants_invalid_input` | 21 | 5.7s |  |
| 1008 | `stage3d_raytrace` | 0 | 63.8s |  |
| 1009 | `stage3d_rotating_cube` | 0 | 11.6s |  |
| 1010 | `stage3d_sampler` | 0 | 9.2s |  |
| 1011 | `stage3d_sampler_partial_upload` | 0 | 9.1s |  |
| 1012 | `stage3d_stencil` | 0 | 25.5s |  |
| 1013 | `stage3d_texture` | 0 | 13.9s |  |
| 1014 | `stage3d_texture_bytearray` | 0 | 10.0s |  |
| 1015 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.5s |  |
| 1016 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.4s |  |
| 1017 | `stage3d_triangle` | 0 | 9.0s |  |
| 1018 | `stage3d_triangle_bytes4` | 0 | 9.1s |  |
| 1019 | `stage3d_triangle_float1` | 0 | 9.0s |  |
| 1020 | `stage3d_triangle_index_upload` | 0 | 9.0s |  |
| 1021 | `stage3d_x_y` | 22 | 6.7s |  |
| 1022 | `stage_access` | 10 | 6.7s |  |
| 1023 | `stage_display_state` | 6 | 6.6s |  |
| 1024 | `stage_displayobject_properties` | 24 | 6.6s |  |
| 1025 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.7s |  |
| 1026 | `stage_framerate_nan` | 7 | 22.8s |  |
| 1027 | `stage_framerate_negative` | 6 | 6.7s |  |
| 1028 | `stage_framerate_zero` | 6 | 6.7s |  |
| 1029 | `stage_invalidate` | 38 | 6.9s |  |
| 1030 | `stage_loaderinfo_properties` | 24 | 22.8s |  |
| 1031 | `stage_mousechildren` | 2 | 6.6s |  |
| 1032 | `stage_mouseenabled` | 15 | 6.6s |  |
| 1033 | `stage_overriden_setters` | 31 | 6.8s |  |
| 1034 | `stage_properties` | 30 | 6.7s |  |
| 1035 | `stage_properties2` | 213 | 6.9s |  |
| 1036 | `stage_scale_factor` | 12 | 27.0s |  |
| 1037 | `stage_stage3Ds_vector` | 1 | 6.7s |  |
| 1038 | `static_length` | 24 | 6.9s |  |
| 1039 | `static_text` | 3 | 6.9s |  |
| 1040 | `static_var_with_this_in_ctor` | 2 | 6.8s |  |
| 1041 | `statictext_text` | 8 | 6.8s |  |
| 1042 | `stored_properties` | 11 | 6.8s |  |
| 1043 | `strict_equality` | 34 | 6.7s |  |
| 1044 | `string_call` | 13 | 6.7s |  |
| 1045 | `string_case` | 23 | 6.7s |  |
| 1046 | `string_char_at` | 27 | 6.7s |  |
| 1047 | `string_char_code_at` | 28 | 6.6s |  |
| 1048 | `string_concat_fromcharcode` | 37 | 6.7s |  |
| 1049 | `string_constr` | 25 | 6.8s |  |
| 1050 | `string_indexof_lastindexof` | 87 | 6.8s |  |
| 1051 | `string_length` | 16 | 6.7s |  |
| 1052 | `string_locale_compare` | 39 | 51.2s |  |
| 1053 | `string_match` | 51 | 30.1s |  |
| 1054 | `string_relational_compare` | 4 | 9.3s |  |
| 1055 | `string_replace` | 51 | 9.6s |  |
| 1056 | `string_search` | 41 | 9.5s |  |
| 1057 | `string_slice_substr_substring` | 170 | 10.7s |  |
| 1058 | `string_split` | 29 | 9.5s |  |
| 1059 | `string_substr_negative` | 21 | 9.4s |  |
| 1060 | `string_substr_weird` | 182 | 9.3s |  |
| 1061 | `stylesheet` | 221 | 10.2s |  |
| 1062 | `stylesheet_parse_color` | 69 | 9.5s |  |
| 1063 | `stylesheet_transform` | 307 | 9.7s |  |
| 1064 | `sub_super_same_field` | 12 | 3.6s |  |
| 1065 | `subclass_superclass_linked_symbol` | 4 | 10.2s |  |
| 1066 | `subtract` | 1058 | 21.1s |  |
| 1067 | `super_get_call` | 12 | 9.4s |  |
| 1068 | `supercall_two_classobjects` | 2 | 9.5s |  |
| 1069 | `supercalls_coerce` | 8 | 9.5s |  |
| 1070 | `supercalls_weird` | 2 | 9.3s |  |
| 1071 | `superinterface_call` | 20 | 9.4s |  |
| 1072 | `superinterface_instanceof` | 18 | 9.4s |  |
| 1073 | `swf8` | 1 | 9.3s |  |
| 1074 | `swf_10_queued_goto_scripts_construct` | 52 | 30.2s |  |
| 1075 | `swf_9_goto_in_enter_frame` | 17 | 9.5s |  |
| 1076 | `swf_9_goto_in_enter_frame_simple` | 15 | 9.5s |  |
| 1077 | `swf_9_queued_goto_scripts` | 6 | 30.0s |  |
| 1078 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1079 | `swf_9_versioning` | 2 | 9.3s |  |
| 1080 | `swf_wrong_frame_count` | 38 | 9.8s |  |
| 1081 | `swf_wrong_frame_count_isplaying` | 22 | 9.4s |  |
| 1082 | `symbol_class_binary_data` | 8 | 9.4s |  |
| 1083 | `symbol_class_conflict` | 4 | 13.8s |  |
| 1084 | `symbol_class_root_not_zero` | 1 | 9.5s |  |
| 1085 | `symbolclass_invalid_utf8` | 2 | 9.7s |  |
| 1086 | `system_exit` | 3 | 9.3s |  |
| 1087 | `system_setclipboard_null` | 1 | 9.3s |  |
| 1088 | `tab_ordering_arrows` | 998 | 31.3s |  |
| 1089 | `tab_ordering_automatic_advanced` | 184 | 10.2s |  |
| 1090 | `tab_ordering_automatic_basic` | 45 | 9.5s |  |
| 1091 | `tab_ordering_children` | 116 | 9.8s |  |
| 1092 | `tab_ordering_custom_basic` | 34 | 9.4s |  |
| 1093 | `tab_ordering_properties` | 732 | 10.0s |  |
| 1094 | `tab_ordering_stage_tab_children` | 32 | 37.9s |  |
| 1095 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.7s |  |
| 1096 | `tab_ordering_tabbable` | 47 | 6.7s |  |
| 1097 | `tabstop_properties` | 105 | 22.6s |  |
| 1098 | `text_element_basic` | 34 | 6.6s |  |
| 1099 | `text_engine_fontdescription` | 27 | 6.7s |  |
| 1100 | `text_engine_groupelement` | 64 | 7.3s |  |
| 1101 | `text_run` | 7 | 6.5s |  |
| 1102 | `textblock_createline_errors` | 23 | 6.7s |  |
| 1103 | `textblock_createline_fte` | 9 | 22.3s |  |
| 1104 | `textblock_properties` | 118 | 6.9s |  |
| 1105 | `textbox_click` | 37 | 22.6s |  |
| 1106 | `textfield_default_text_format_null` | 20 | 6.7s |  |
| 1107 | `textfield_event` | 66 | 6.9s |  |
| 1108 | `textfield_focusin_event` | 9 | 6.6s |  |
| 1109 | `textfield_input_dead_keys_windows` | 15 | 6.7s |  |
| 1110 | `textfield_input_events` | 25 | 19.2s |  |
| 1111 | `textfield_unload` | 39 | 22.8s |  |
| 1112 | `textformat` | 1134 | 6.7s |  |
| 1113 | `textformat_display` | 14 | 6.5s |  |
| 1114 | `textformat_font_max_length` | 4 | 6.5s |  |
| 1115 | `textjustifier_locale` | 132 | 6.7s |  |
| 1116 | `textline_has_tabs` | 47 | 6.6s |  |
| 1117 | `textline_inapplicable_properties` | 10 | 6.6s |  |
| 1118 | `textline_name` | 1 | 6.5s |  |
| 1119 | `textline_raw_text_length` | 30 | 6.6s |  |
| 1120 | `textline_splitting_basic` | 76 | 6.7s |  |
| 1121 | `textline_throwerror` | 30 | 6.6s |  |
| 1122 | `textline_validity` | 162 | 6.8s |  |
| 1123 | `throw` | 3 | 6.6s |  |
| 1124 | `timeline_scripts` | 3 | 22.5s |  |
| 1125 | `timer` | 90 | 7.6s |  |
| 1126 | `timer_events` | 3 | 6.8s |  |
| 1127 | `timer_finished` | 11 | 6.8s |  |
| 1128 | `timer_invalid_delay` | 30 | 6.7s |  |
| 1129 | `timer_reset` | 8 | 7.0s |  |
| 1130 | `timer_setdelay` | 5 | 6.8s |  |
| 1131 | `trace` | 12 | 54.2s |  |
| 1132 | `truthiness` | 30 | 10.0s |  |
| 1133 | `try_catch` | 11 | 10.3s |  |
| 1134 | `try_catch_typed` | 12 | 10.1s |  |
| 1135 | `typeof` | 30 | 10.1s |  |
| 1136 | `uint_constr` | 92 | 10.2s |  |
| 1137 | `uint_tofixed` | 1215 | 9.9s |  |
| 1138 | `uint_toprecision` | 1125 | 10.2s |  |
| 1139 | `uint_tostring` | 3375 | 10.2s |  |
| 1140 | `uncaught_error_basic` | 2 | 9.8s |  |
| 1141 | `unchecked_function` | 15 | 9.9s |  |
| 1142 | `unescape` | 28 | 9.9s |  |
| 1143 | `url_loader` | 25 | 10.2s |  |
| 1144 | `url_vars` | 27 | 10.1s |  |
| 1145 | `urlrequest` | 18 | 32.7s |  |
| 1146 | `urlstream_basic` | 5 | 10.1s |  |
| 1147 | `urshift` | 1058 | 22.1s |  |
| 1148 | `utils3d` | 7 | 10.1s |  |
| 1149 | `vector3d` | 397 | 15.5s |  |
| 1150 | `vector3d_near_equals` | 80 | 10.2s |  |
| 1151 | `vector_class` | 36 | 10.8s |  |
| 1152 | `vector_class_call` | 11 | 10.4s |  |
| 1153 | `vector_coercion` | 66 | 11.2s |  |
| 1154 | `vector_concat` | 90 | 10.8s |  |
| 1155 | `vector_constr` | 107 | 11.4s |  |
| 1156 | `vector_enumeration` | 5 | 10.2s |  |
| 1157 | `vector_every` | 92 | 11.4s |  |
| 1158 | `vector_filter` | 95 | 11.3s |  |
| 1159 | `vector_holes` | 24 | 10.2s |  |
| 1160 | `vector_indexof` | 302 | 15.8s |  |
| 1161 | `vector_insertat` | 270 | 11.6s |  |
| 1162 | `vector_int_access` | 4 | 10.1s |  |
| 1163 | `vector_int_delete` | 11 | 10.1s |  |
| 1164 | `vector_join` | 58 | 10.6s |  |
| 1165 | `vector_lastindexof` | 302 | 10.1s |  |
| 1166 | `vector_legacy` | 10 | 10.0s |  |
| 1167 | `vector_map` | 85 | 10.9s |  |
| 1168 | `vector_object_final` | 1 | 9.8s |  |
| 1169 | `vector_object_toString` | 10 | 9.9s |  |
| 1170 | `vector_prototype_some` | 125 | 10.2s |  |
| 1171 | `vector_pushpop` | 255 | 38.0s |  |
| 1172 | `vector_reborrow_bug` | 10 | 22.1s |  |
| 1173 | `vector_removeat` | 172 | 6.0s |  |
| 1174 | `vector_reverse` | 232 | 6.1s |  |
| 1175 | `vector_shiftunshift` | 252 | 6.1s |  |
| 1176 | `vector_slice` | 331 | 6.0s |  |
| 1177 | `vector_sort` | 905 | 6.1s |  |
| 1178 | `vector_splice` | 693 | 6.1s |  |
| 1179 | `vector_splice_fixed_bug_compat` | 4 | 6.0s |  |
| 1180 | `vector_tostring` | 79 | 6.0s |  |
| 1181 | `verification` | 8 | 6.0s |  |
| 1182 | `verify_abnormal_loop` | 1 | 6.0s |  |
| 1183 | `verify_dxns_without_flag` | 3 | 6.0s |  |
| 1184 | `verify_exception_target_two_jumps` | 1 | 6.0s |  |
| 1185 | `verify_exception_targets_edge_case` | 1 | 6.0s |  |
| 1186 | `verify_illegal_opcode` | 1 | 1.8s |  |
| 1187 | `verify_jump_to_middle_of_op` | 1 | 6.0s |  |
| 1188 | `verify_lookup_switch_edge_case` | 1 | 6.0s |  |
| 1189 | `verify_method_info_oob` | 1 | 0.8s |  |
| 1190 | `verify_stack` | 5 | 6.0s |  |
| 1191 | `verify_typecheck` | 4 | 6.0s |  |
| 1192 | `verify_unreachable_exception` | 2 | 6.0s |  |
| 1193 | `versioned_isplaying` | 2 | 6.0s |  |
| 1194 | `virtual_properties` | 16 | 6.1s |  |
| 1195 | `with` | 4 | 6.0s |  |
| 1196 | `wrong_arg_count` | 7 | 6.0s |  |
| 1197 | `xml_abstract_equality` | 36 | 6.0s |  |
| 1198 | `xml_advanced` | 52 | 6.0s |  |
| 1199 | `xml_appendchild` | 10 | 6.0s |  |
| 1200 | `xml_appendchild_swf_v21` | 13 | 6.0s |  |
| 1201 | `xml_as_attribute` | 9 | 6.0s |  |
| 1202 | `xml_attribute` | 35 | 6.0s |  |
| 1203 | `xml_attribute_name` | 40 | 6.0s |  |
| 1204 | `xml_basic` | 33 | 6.0s |  |
| 1205 | `xml_child` | 25 | 6.0s |  |
| 1206 | `xml_childindex` | 7 | 6.0s |  |
| 1207 | `xml_children` | 43 | 6.0s |  |
| 1208 | `xml_class_call` | 9 | 6.0s |  |
| 1209 | `xml_contains` | 197 | 6.1s |  |
| 1210 | `xml_copy` | 20 | 39.2s |  |
| 1211 | `xml_ctor_from_tostring` | 23 | 23.4s |  |
| 1212 | `xml_delete` | 114 | 6.9s |  |
| 1213 | `xml_descendants` | 83 | 6.9s |  |
| 1214 | `xml_duplicate_attribute` | 14 | 6.8s |  |
| 1215 | `xml_elements` | 6 | 6.8s |  |
| 1216 | `xml_equals_namespace_check` | 2 | 6.7s |  |
| 1217 | `xml_explicit_use_namespace` | 5 | 6.8s |  |
| 1218 | `xml_getdescendants_qname` | 21 | 6.7s |  |
| 1219 | `xml_has_property_via_in` | 26 | 6.7s |  |
| 1220 | `xml_hasownproperty` | 6 | 6.7s |  |
| 1221 | `xml_ignore_white` | 6 | 6.7s |  |
| 1222 | `xml_length` | 2 | 6.7s |  |
| 1223 | `xml_list_as_attribute` | 9 | 6.7s |  |
| 1224 | `xml_list_concat` | 20 | 6.8s |  |
| 1225 | `xml_list_ctor_errors` | 34 | 6.8s |  |
| 1226 | `xml_list_delete_clear_parent` | 6 | 6.7s |  |
| 1227 | `xml_list_enumerate` | 4 | 6.7s |  |
| 1228 | `xml_many_namespace_declarations` | 2 | 6.8s |  |
| 1229 | `xml_methods_settings` | 3 | 6.8s |  |
| 1230 | `xml_mismatched_tag` | 45 | 6.8s |  |
| 1231 | `xml_namespace` | 39 | 6.8s |  |
| 1232 | `xml_namespace_methods` | 245 | 6.8s |  |
| 1233 | `xml_namespaced_property` | 7 | 6.7s |  |
| 1234 | `xml_no_namespace` | 1 | 6.7s |  |
| 1235 | `xml_nodekind` | 3 | 6.7s |  |
| 1236 | `xml_normalize` | 35 | 6.8s |  |
| 1237 | `xml_notification_bubbling` | 361 | 6.8s |  |
| 1238 | `xml_parent` | 8 | 6.8s |  |
| 1239 | `xml_set_children` | 17 | 6.8s |  |
| 1240 | `xml_set_name` | 34 | 6.7s |  |
| 1241 | `xml_settings` | 6 | 2.2s |  |
| 1242 | `xml_simple_complex_content` | 47 | 6.8s |  |
| 1243 | `xml_socket` | 11 | 7.0s |  |
| 1244 | `xml_text` | 7 | 6.7s |  |
| 1245 | `xml_tostring` | 6 | 6.7s |  |
| 1246 | `xml_tostring_namespace` | 12 | 6.6s |  |
| 1247 | `xml_unescaping` | 23 | 6.8s |  |
| 1248 | `xml_unescaping_nul_char_ref` | 19 | 6.9s |  |
| 1249 | `xml_weird_ignores` | 54 | 6.8s |  |
| 1250 | `xml_wildcard` | 11 | 6.8s |  |
| 1251 | `xmldocument` | 254 | 6.9s |  |
| 1252 | `xmlnode` | 3540 | 7.0s |  |
| 1253 | `zero_frame_clip` | 3 | 7.1s |  |

## Ruffle-Matched Tests

**43 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 6.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.8s |  |
| 3 | `blend_transform` | 1 | 1 | 6.8s |  |
| 4 | `bounds_mode` | 6 | 6 | 6.9s |  |
| 5 | `coerce_property` | 3 | 3 | 7.9s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.6s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 23.1s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 22.9s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 9.7s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 9.7s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 9.4s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 9.6s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.9s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 6.8s |  |
| 15 | `event_handler_exception` | 3 | 3 | 6.7s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 6.4s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 1.0s |  |
| 18 | `gradient_values_readback` | 12 | 12 | 6.9s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 23.1s |  |
| 20 | `groupelement_text` | 2 | 2 | 6.8s |  |
| 21 | `html_text_img_parsing` | 95 | 95 | 6.8s |  |
| 22 | `int_toexponential` | 76 | 76 | 7.6s |  |
| 23 | `json_parse_numbers` | 4 | 79 | 7.5s |  |
| 24 | `loader_events_2` | 30 | 30 | 7.2s |  |
| 25 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.2s |  |
| 26 | `number_convert_errors` | 706 | 706 | 6.9s |  |
| 27 | `number_to_string` | 104 | 104 | 7.0s |  |
| 28 | `simplebutton_childevents_multichild` | 101 | 101 | 6.7s |  |
| 29 | `simplebutton_childevents_script_order` | 4 | 4 | 6.8s |  |
| 30 | `slot_holes_fail` | 1 | 1 | 6.4s |  |
| 31 | `slot_id_exceeds_trait_count` | 1 | 1 | 6.4s |  |
| 32 | `soundchannel_position` | 74 | 74 | 21.6s |  |
| 33 | `soundchannel_soundcomplete` | 10 | 10 | 6.0s |  |
| 34 | `sprite_dropTarget` | 15 | 15 | 5.9s |  |
| 35 | `swf_9_goto_in_construct_frame` | 12 | 12 | 30.4s |  |
| 36 | `textblock_line_changes` | 44 | 44 | 7.1s |  |
| 37 | `textblock_recreateline` | 137 | 138 | 7.0s |  |
| 38 | `textblock_releaselines` | 4 | 4 | 7.8s |  |
| 39 | `textline_atom_index_at_char_index` | 3 | 3 | 7.3s |  |
| 40 | `uint_toexponential` | 100 | 100 | 10.3s |  |
| 41 | `uncaught_errors_stringified` | 15 | 15 | 10.2s |  |
| 42 | `vector_indexing_cutoffs` | 1 | 1 | 10.3s |  |
| 43 | `weird_superinterface_properties` | 1 | 1 | 6.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**12 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `error_stack_trace_class_names` | 94.1% | 127 | 135 | 8 |  |
| 3 | `array_join_reentrant` | 85.3% | 58 | 68 | 10 |  |
| 4 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 5 | `edittext_set_text_same` | 80.0% | 92 | 115 | 23 |  |
| 6 | `weird_number_bound_methods` | 75.0% | 9 | 12 | 3 |  |
| 7 | `hit_test_scroll_rect` | 69.7% | 69 | 99 | 30 |  |
| 8 | `error_stack_trace_limit` | 69.1% | 600 | 868 | 268 |  |
| 9 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 10 | `edittext_set_text_same_after_edits` | 60.9% | 84 | 138 | 54 |  |
| 11 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 12 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

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
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `error_stack_trace_class_names` | 94.1% | 127/135 | 135 | 135 |  |
| 3 | `array_join_reentrant` | 85.3% | 58/68 | 68 | 68 |  |
| 4 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 5 | `edittext_set_text_same` | 80.0% | 92/115 | 115 | 115 |  |
| 6 | `weird_number_bound_methods` | 75.0% | 9/12 | 12 | 12 |  |
| 7 | `hit_test_scroll_rect` | 69.7% | 69/99 | 99 | 99 |  |
| 8 | `error_stack_trace_limit` | 69.1% | 600/868 | 868 | 674 |  |
| 9 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 10 | `edittext_set_text_same_after_edits` | 60.9% | 84/138 | 138 | 138 |  |
| 11 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 12 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 13 | `primitive_bound_methods` | 45.5% | 5/11 | 11 | 11 |  |
| 14 | `loaderinfo_root_progress` | 42.9% | 3/7 | 6 | 7 |  |
| 15 | `loaderinfo_root_progress_goto` | 40.0% | 4/10 | 6 | 10 |  |
| 16 | `displayobjectcontainer_removechildren_events` | 36.2% | 21/58 | 58 | 56 |  |
| 17 | `stage3d_missing_vertex_stream` | 35.1% | 13/37 | 27 | 37 |  |
| 18 | `amf_xmllist` | 33.3% | 4/12 | 12 | 12 |  |
| 19 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 20 | `displayobjectcontainer_remove_reparent` | 31.2% | 59/189 | 185 | 189 |  |
| 21 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 22 | `bitmapdata_encode` | 17.7% | 26/147 | 31 | 147 |  |
| 23 | `context3d_draw_to_bitmap_data` | 13.3% | 2/15 | 11 | 15 |  |
| 24 | `vector_join_reentrant` | 10.4% | 10/96 | 84 | 96 |  |
| 25 | `array_sort_arguments` | 9.5% | 42/442 | 277 | 442 |  |
| 26 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 27 | `array_constructor` | 9.0% | 21/234 | 181 | 234 |  |
| 28 | `textfield_set_text_format_args` | 9.0% | 81/904 | 638 | 904 |  |
| 29 | `textfield_get_text_format_args` | 8.8% | 50/567 | 447 | 567 |  |
| 30 | `shared_object_get_local_error` | 4.8% | 1/21 | 5 | 21 |  |
| 31 | `worker_terminate` | 1.8% | 1/56 | 3 | 56 |  |
| 32 | `vector_sort_arguments` | 0.3% | 1/355 | 198 | 355 |  |
| 33 | `displayobjectcontainer_remove_reentrant` | 0.0% | 2/27942 | 27942 | 257 |  |
| 34 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 35 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 36 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 37 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 38 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 39 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
